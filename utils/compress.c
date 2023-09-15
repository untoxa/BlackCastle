#include <stdio.h>

const unsigned short int colorTable[4][4][2] = {
	{{0, 0}, {0, 1}, {2, 2}, {3, 2}},
	{{0, 1}, {0, 0}, {2, 2}, {3, 2}},
	{{0, 1}, {2, 2}, {0, 0}, {3, 2}},
	{{0, 1}, {2, 2}, {3, 2}, {0, 0}}}; //codes used to represent colors and how many bits those codes need

const unsigned short int pixelTable[4][3][2] = {
	{{0, 0}, {0, 0}, {0, 0}},
	{{0, 1}, {0, 0}, {0, 0}},
	{{0, 2}, {1, 2}, {0, 0}},
	{{0, 2}, {2, 3}, {3, 3}}}; //codes used to represent compressed pixels and how many bits those codes need

FILE *file; //pointer used to read and write files
unsigned char bitBuffer = 0x01; //buffer that holds bits until they can be written to the output file
unsigned char tiles[512][8][8]; //buffer that will hold the data to be encoded
unsigned short int tileCount; //number of tiles to encode
unsigned short int lengths[512]; //list of selected lengths for the blocks

//writes a single bit to the bit buffer
void writeBit(unsigned short int data)
{
	//if the next bit completes a byte
	if (bitBuffer & 0x80)
	{
		//shift the bit in and output the byte
		bitBuffer = (bitBuffer << 1) | (data != 0);
		fputc(bitBuffer, file);
		
		//empty the bit buffer
		bitBuffer = 0x01;
	}
	else
	{
		//just shift the bit in
		bitBuffer = (bitBuffer << 1) | (data != 0);
	}
}

//writes a number of bits to the bit buffer
void writeBits(unsigned short int data, unsigned char count)
{
	unsigned short int mask = 0x8000 >> (16 - count); //mask used to read bits
	
	//while there are bits left
	while (mask)
	{
		//write the bit and move the mask to the next position
		writeBit(data & mask);
		mask >>= 1;
	}
}

//outputs any bits that may still be in the bit buffer
void flushBits()
{
	//while the buffer isn't empty
	while (bitBuffer != 0x01)
	{
		//write a dummy bit
		writeBit(0);
	}
}

//reads the tiles from the file and converts them to a format that's easier to work with
void readTiles()
{
	unsigned short int tile; //used to loop through the tiles
	unsigned char x, y; //coordinates of the pixels of a tile
	unsigned char buffer[16]; //holds the raw tile being converted

	//repeat for each tile
	for (tile = 0; tile < tileCount; tile++)
	{
		//read a whole tile from the file
		fread(buffer, 1, 16, file);
		
		//decode the pixels of the tile
		for (y = 0; y < 8; y++)
		{
			for (x = 0; x < 8; x++)
			{
				tiles[tile][y][x] = 0;
				tiles[tile][y][x] = (tiles[tile][y][x] << 1) | ((buffer[8 + y] & 0x80) != 0);
				tiles[tile][y][x] = (tiles[tile][y][x] << 1) | ((buffer[0 + y] & 0x80) != 0);
				buffer[0 + y] <<= 1;
				buffer[8 + y] <<= 1;
			}
		}
	}
}

//resets all the block lengths to the smallest possible value
void resetLengths()
{
	unsigned short int start;
	
	for (start = 0; start < tileCount; start++)
	{
		lengths[start] = 1;
	}
}

//compresses a group of tiles and returns the number of bits necessary to represent it
unsigned int compressBlock(unsigned short int start, unsigned short int length, unsigned char save)
{
	unsigned char counts[4]; //number of colors that follow each color
	unsigned short int frequencies[4][4]; //how many times each color follows each color
	unsigned char positions[4][4]; //relative indices of the colors that follow each color
	unsigned char color, nextColor; //color of the current pixel and color of the next pixel
	unsigned short int tile; //used to loop through the tiles
	unsigned char x, y; //coordinates of the pixels of a tile
	unsigned int cost = 0; //number of bits necessary to encode the block
	unsigned char position; //used to assign the positions of the colors that follow each color
	unsigned char frequent; //most frequent color when 3 colors
	unsigned char row[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //fake row of pixels to act as the previous row
	
	//repeat for each possible color
	for (color = 0; color < 4; color++)
	{
		//indicate that no color follows the current one
		counts[color] = 0;
		
		//clear the number of times each color follows the current one
		frequencies[color][0] = 0;
		frequencies[color][1] = 0;
		frequencies[color][2] = 0;
		frequencies[color][3] = 0;
		
		//clear the list of positions using an invalid value
		positions[color][0] = 3;
		positions[color][1] = 3;
		positions[color][2] = 3;
		positions[color][3] = 3;
	}
	
	//populate the tables based on the specified group of tiles
	for (tile = start; tile < start + length; tile++)
	{
		for (y = 0; y < 8; y++)
		{
			for (x = 0; x < 7; x++)
			{
				//get the pair of pixels
				color = tiles[tile][y][x];
				nextColor = tiles[tile][y][x + 1];
				
				//if the two pixels are different
				if (nextColor != color)
				{
					//if this is the first time the next color follows the current one
					if (frequencies[color][nextColor] == 0)
					{
						//increase the number of colors that can follow the current one
						counts[color]++;
					}
					
					//increase the number of times the next color follows the current one
					frequencies[color][nextColor]++;
				}
			}
		}
	}
	
	//put the colors in the correct order
	for (color = 0; color < 4; color++)
	{
		//start from the first position
		position = 0;
		
		//use an invalid color index
		frequent = 0xff;
		
		//if 3 colors follow the current one
		if (counts[color] == 3)
		{
			//assume color 0 is the most frequent one
			frequent = 0;
			
			//find the most frequent color
			for (nextColor = 0; nextColor < 4; nextColor++)
			{
				if (frequencies[color][nextColor] > frequencies[color][frequent])
				{
					frequent = nextColor;
				}
			}
			
			//make the most frequent color the first one in the list
			positions[color][frequent] = position++;
		}
		
		//set the positions based on the indices of the colors
		for (nextColor = 0; nextColor < 4; nextColor++)
		{
			//if the color is used
			if (frequencies[color][nextColor])
			{
				//if this is not the most frequent color
				if (nextColor != frequent)
				{
					//make it the next one in the list
					positions[color][nextColor] = position++;
				}
			}
		}
	}
	
	//if the block doesn't start on the first tile
	if (start != 0)
	{
		//add the cost of the flag that indicates the start of a block
		cost++;
		
		//if this is for real
		if (save)
		{	
			//indicate that a new block is starting
			writeBit(1);
		}
	}
	
	//output the decompression tables
	for (color = 3; color < 255; color--)
	{
		//add the cost of indicating how many colors follow the current one
		cost += 2;
		
		//if this is for real
		if (save)
		{
			//indicate how many colors follow the current one
			writeBits(counts[color], 2);
		}
		
		//use an invalid color index
		frequent = 0xff;
		
		//if 1 or 3 colors can follow the current one
		if ((counts[color] == 1) || (counts[color] == 3))
		{
			//look for the most frequent color
			for (nextColor = 0; nextColor < 4; nextColor++)
			{
				//if this is the most frequent color
				if (positions[color][nextColor] == 0)
				{
					//select the color that has to be written
					frequent = nextColor;
				}
			}
		}
		else
		{
			//if 2 colors can follow the current one
			if (counts[color] == 2)
			{
				//look for the color that is not used
				for (nextColor = 0; nextColor < 4; nextColor++)
				{
					//if this is the color that is not used
					if ((nextColor != color) && (positions[color][nextColor] > 2))
					{
						//select the color that has to be written
						frequent = nextColor;
					}
				}
			}
		}
		
		//if there are colors that follow the current one
		if (frequent < 4)
		{
			//add the cost of representing the color
			cost += colorTable[color][frequent][1];
			
			//if this is for real
			if (save)
			{
				//output the color
				writeBits(colorTable[color][frequent][0], colorTable[color][frequent][1]);
			}
		}
	}
	
	//compress the specified group of tiles
	for (tile = start; tile < start + length; tile++)
	{
		//if this isn't the first tile of the group
		if (tile != start)
		{
			//add the cost of the flag that indicates that a tile follows
			cost++;
			
			//if this is for real
			if (save)
			{	
				//indicate that a tile follows
				writeBit(0);
			}
		}
		
		for (y = 0; y < 8; y++)
		{
			//add the cost of the flag that indicates if the row is repeating or not
			cost++;
			
			//if this row is equal to the previous one
			if ((tiles[tile][y][0] == row[0]) &&
				(tiles[tile][y][1] == row[1]) &&
				(tiles[tile][y][2] == row[2]) &&
				(tiles[tile][y][3] == row[3]) &&
				(tiles[tile][y][4] == row[4]) &&
				(tiles[tile][y][5] == row[5]) &&
				(tiles[tile][y][6] == row[6]) &&
				(tiles[tile][y][7] == row[7]))
			{
				//if this is for real
				if (save)
				{
					//indicate the repetition of the row
					writeBit(1);
				}
			}
			else
			{
				//if this is for real
				if (save)
				{
					//indicate that the row is not repeating
					writeBit(0);
				}
				
				//get the color of the first pixel of the row
				color = tiles[tile][y][0];
				
				//start saving the row
				row[0] = color;
				
				//add the cost of indicating the color of the first pixel of the row
				cost += 2;
				
				//if this is for real
				if (save)
				{
					//output the color of the pixel
					writeBits(color, 2);
				}
				
				//process the row
				for (x = 1; x < 8; x++)
				{
					//if the color can be followed by any other color
					if (counts[color] > 0)
					{
						//get the color of the next pixel
						nextColor = tiles[tile][y][x];
						
						//if the next color is the same as the current one
						if (nextColor == color)
						{
							//add the cost of encoding the repeated pixel
							cost++;
							
							//if this is for real
							if (save)
							{
								//output the repeated pixel
								writeBit(1);
							}
						}
						else
						{
							//add the cost of writing the compressed pixel
							cost += pixelTable[counts[color]][positions[color][nextColor]][1];
							
							//if this is for real
							if (save)
							{
								//output the compressed pixel
								writeBits(pixelTable[counts[color]][positions[color][nextColor]][0], pixelTable[counts[color]][positions[color][nextColor]][1]);
							}
						}
						
						//make the next pixel the current one
						color = nextColor;
					}
					
					//keep saving the row
					row[x] = color;
				}
			}
		}
	}
	
	//return the cost of encoding the block
	return cost;
}

//adjusts the lengths of the blocks for better compression
unsigned int adjustLengths()
{
	unsigned short int start0, length0; //position and length of the first block of the pair
	unsigned short int start1, length1; //position and length of the second block of the pair
	unsigned short int bestLength0, bestLength1; //best lengths found for each block of the pair
	unsigned int cost, bestCost; //temporary cost and the smallest cost found
	unsigned int totalCost = 0; //total size of the encoded data
	
	//start from the first block
	start0 = 0;
	
	//while there are still blocks left
	while (start0 < tileCount)
	{
		//give a length of 0 to the first block of the pair
		length0 = 0;
		
		//make the second block as long as the 2 original ones
		start1 = start0;
		length1 = lengths[start1];
		if (start1 + length1 < tileCount) length1 += lengths[start1 + length1];
		
		//pretend that the best cost is really high
		bestCost = -1;
		
		//while the length of the second block doesn't wrap around
		while (length1 < tileCount)
		{
			//clear the cost of encoding the blocks
			cost = 0;
			
			//calculate the cost of encoding the blocks using the current lengths
			if (length0 != 0) cost += compressBlock(start0, length0, 0);
			if (length1 != 0) cost += compressBlock(start1, length1, 0);
			
			//if the cost is smaller than the smallest one
			if (cost < bestCost)
			{
				//make it the new smallest cost
				bestCost = cost;
				
				//remember the combination of lengths that resulted in the smallest cost
				bestLength0 = length0;
				bestLength1 = length1;
			}
			
			//make the first block longer and the second one shorter
			length0++;
			start1++;
			length1--;
		}
		
		//set the new lengths of the blocks
		lengths[start0] = bestLength0;
		if (bestLength1 != 0) lengths[start0 + lengths[start0]] = bestLength1;
		
		//add the cost of the first block to the total
		totalCost += compressBlock(start0, lengths[start0], 0);
		
		//advance to the next block
		start0 += lengths[start0];
	}
	
	//return the cost of encoding all the blocks using the selected lengths
	return totalCost;
}

//uses a simple method for deciding the lengths of the blocks
void parseSimple()
{
	float oldRatio, newRatio; //compression ratios of the previous and current blocks
	unsigned short int start, length; //starting position of the block and it's length
	
	//start from the first tile
	start = 0;
	
	//while there are tiles to compress
	while (start < tileCount)
	{
		//start with the shortest block possible
		length = 1;
		
		//fake a bad compression ratio for the previous attempt
		oldRatio = 0.0;
		newRatio = 0.0;
		
		//while there are still blocks and the compression ratio isn't getting worse
		while ((start + length <= tileCount) && (newRatio >= oldRatio))
		{
			//make the current compression ratio the previous one
			oldRatio = newRatio;
			
			//calculate the compression ratio using the current length
			newRatio = (float)(length * 128) / (float)compressBlock(start, length, 0);
			
			//make the block larger if the compression ratio didn't get worse
			if (newRatio >= oldRatio) length++;
		}
		
		//indicate the best length
		lengths[start] = length - 1;
		
		//skip over the compressed tiles
		start += lengths[start];
	}
}

//uses a method that adjusts the lengths of the blocks gradually
void parseBetter()
{
	unsigned int oldCost; //cost after the previous adjustment
	unsigned int newCost; //cost after the current adjustment
	
	//initialize the costs
	oldCost = -1;
	newCost = adjustLengths();
	
	//while the cost is decreasing
	while (newCost < oldCost )
	{
		//keep adjusting the lengths
		oldCost = newCost;
		newCost = adjustLengths();
	}
}

/*
//uses the same block lengths used by the compressed tileset from Bee52 (will crash if a file with a different number of tiles is provided)
void parseBee52()
{
	const unsigned short int beeLengths[] = {6, 14, 7, 2, 4, 2, 10, 7, 1, 4, 2, 2, 3, 1, 8, 1, 3, 1, 4, 1, 6, 3, 1, 1, 1, 15, 2, 3, 6, 24, 6, 6};
	unsigned short int start = 0;
	unsigned short int index = 0;
	
	while (start < tileCount)
	{
		lengths[start] = beeLengths[index];
		
		start += lengths[start];
		
		index++;
	}
}
*/

//outputs the compressed blocks using the lengths specified for them
void writeFile()
{
	unsigned short int start = 0; //start of the block to compress
	
	//indicate how many tiles are compressed
	writeBits(tileCount, 8);
	
	//repeat while there are tiles left to compress
	while (start < tileCount)
	{
		//output the compressed tiles
		compressBlock(start, lengths[start], 1);
		
		//move on to the next block
		start += lengths[start];
	}
	
	//make sure all bits are written to the file
	flushBits();
}

//entry point
int main(int argc, char *argv[])
{	
	//if the names of the files waren't supplied
	if (argc < 3)
	{
		//report the error and exit
		printf("\nPlease inform the source and destination files.\n");
		return 1;
	}
	
	//if the file can't be opened
	if ((file = fopen(argv[1], "rb")) == NULL)
	{
		//report the error and exit
		printf("\nCan't open the file \"%s\".\n", argv[1]);
		return 1;
	}
	
	//if the size of the file is not a multiple of 16
	if ((filelength(fileno(file)) % 16) != 0)
	{
		//close the file, report the error and exit
		fclose(file);
		printf("\nThe size of the file is not a multiple of 16.\n");
		return 1;
	}
	else
	{
		//calculate the number of tiles in the file
		tileCount = filelength(fileno(file)) / 16;
	}
	
	//if the file is empty
	if (tileCount == 0)
	{
		//close the file, report the error and exit
		fclose(file);
		printf("\nThe specified file is empty.\n");
		return 1;
	}

	//if the file contains too many tiles
	if (tileCount > 512)
	{
		//close the file, report the error and exit
		fclose(file);
		printf("\nThe specified file contains too many tiles.\n");
		return 1;
	}

	//read the tiles from the source file
	readTiles();
	
	//close the source file
	fclose(file);
	
	//if the output file can't be opened
	if ((file = fopen(argv[2], "wb")) == NULL)
	{
		//report the error and exit
		printf("\nCan't output to the file \"%s\".\n", argv[2]);
		return 1;
	}
	
	//compress the tiles
	resetLengths();
	parseBetter();
	writeFile();
	
	//close the output file
	fclose(file);
	
	//indicate that all the work is done
	printf("\nDone! The file \"%s\" has been written.\n", argv[2]);
	
	//terminate the program
	return 0;
}