import sys
import os

import array

class RawTileFormat:
    def __init__(self):
        pass

RawFormats = dict()

RawFormats['NES'] = RawTileFormat()
RawFormats['NES'].width = 8
RawFormats['NES'].height = 8
RawFormats['NES'].stride = 128
RawFormats['NES'].bitsOffs = [[], []]
RawFormats['NES'].bitsOffs[0] = [7, 6, 5, 4, 3, 2, 1, 0,
                                 15, 14, 13, 12, 11, 10, 9, 8,
                                 23, 22, 21, 20, 19, 18, 17, 16,
                                 31, 30, 29, 28, 27, 26, 25, 24,
                                 39, 38, 37, 36, 35, 34, 33, 32,
                                 47, 46, 45, 44, 43, 42, 41, 40,
                                 55, 54, 53, 52, 51, 50, 49, 48,
                                 63, 62, 61, 60, 59, 58, 57, 56]
RawFormats['NES'].bitsOffs[1] = [71, 70, 69, 68, 67, 66, 65, 64,
                                 79, 78, 77, 76, 75, 74, 73, 72,
                                 87, 86, 85, 84, 83, 82, 81, 80,
                                 95, 94, 93, 92, 91, 90, 89, 88,
                                 103, 102, 101, 100, 99, 98, 97, 96,
                                 111, 110, 109, 108, 107, 106, 105, 104,
                                 119, 118, 117, 116, 115, 114, 113, 112,
                                 127, 126, 125, 124, 123, 122, 121, 120]

RawFormats['GB'] = RawTileFormat()
RawFormats['GB'].width = 8
RawFormats['GB'].height = 8
RawFormats['GB'].stride = 128
RawFormats['GB'].bitsOffs = [[], []]
RawFormats['GB'].bitsOffs[0] = [7, 6, 5, 4, 3, 2, 1, 0,
                                23, 22, 21, 20, 19, 18, 17, 16,
                                39, 38, 37, 36, 35, 34, 33, 32,
                                55, 54, 53, 52, 51, 50, 49, 48,
                                71, 70, 69, 68, 67, 66, 65, 64,
                                87, 86, 85, 84, 83, 82, 81, 80,
                                103, 102, 101, 100, 99, 98, 97, 96,
                                119, 118, 117, 116, 115, 114, 113, 112]
RawFormats['GB'].bitsOffs[1] = [15, 14, 13, 12, 11, 10, 9, 8,
                                31, 30, 29, 28, 27, 26, 25, 24,
                                47, 46, 45, 44, 43, 42, 41, 40,
                                63, 62, 61, 60, 59, 58, 57, 56,
                                79, 78, 77, 76, 75, 74, 73, 72,
                                95, 94, 93, 92, 91, 90, 89, 88,
                                111, 110, 109, 108, 107, 106, 105, 104,
                                127, 126, 125, 124, 123, 122, 121, 120]

RawFormats['SMS'] = RawTileFormat()
RawFormats['SMS'].width = 8
RawFormats['SMS'].height = 8
RawFormats['SMS'].stride = 256
RawFormats['SMS'].bitsOffs = [[], [], [], []]
RawFormats['SMS'].bitsOffs[0] = [7, 6, 5, 4, 3, 2, 1, 0,
                                 15, 14, 13, 12, 11, 10, 9, 8,
                                 23, 22, 21, 20, 19, 18, 17, 16,
                                 31, 30, 29, 28, 27, 26, 25, 24,
                                 39, 38, 37, 36, 35, 34, 33, 32,
                                 47, 46, 45, 44, 43, 42, 41, 40,
                                 55, 54, 53, 52, 51, 50, 49, 48,
                                 63, 62, 61, 60, 59, 58, 57, 56]
RawFormats['SMS'].bitsOffs[1] = [71, 70, 69, 68, 67, 66, 65, 64,
                                 79, 78, 77, 76, 75, 74, 73, 72,
                                 87, 86, 85, 84, 83, 82, 81, 80,
                                 95, 94, 93, 92, 91, 90, 89, 88,
                                 103, 102, 101, 100, 99, 98, 97, 96,
                                 111, 110, 109, 108, 107, 106, 105, 104,
                                 119, 118, 117, 116, 115, 114, 113, 112,
                                 127, 126, 125, 124, 123, 122, 121, 120]
RawFormats['SMS'].bitsOffs[2] = [135, 134, 133, 132, 131, 130, 129, 128,
                                 143, 142, 141, 140, 139, 138, 137, 136,
                                 151, 150, 149, 148, 147, 146, 145, 144,
                                 159, 158, 157, 156, 155, 154, 153, 152,
                                 167, 166, 165, 164, 163, 162, 161, 160,
                                 175, 174, 173, 172, 171, 170, 169, 168,
                                 183, 182, 181, 180, 179, 178, 177, 176,
                                 191, 190, 189, 188, 187, 186, 185, 184]
RawFormats['SMS'].bitsOffs[3] = [199, 198, 197, 196, 195, 194, 193, 192,
                                 207, 206, 205, 204, 203, 202, 201, 200,
                                 215, 214, 213, 212, 211, 210, 209, 208,
                                 223, 222, 221, 220, 219, 218, 217, 216,
                                 231, 230, 229, 228, 227, 226, 225, 224,
                                 239, 238, 237, 236, 235, 234, 233, 232,
                                 247, 246, 245, 244, 243, 242, 241, 240,
                                 255, 254, 253, 252, 251, 250, 249, 248]

def readTiles(filename, numTiles, tileFormat, fileOffset=0):
    byteData = array.array('B', [])
    byteData.fromfile(open(filename, 'rb'), os.path.getsize(filename))
    # Autodetect numTiles if zero
    if numTiles == 0:
        tileSizeBits = max([max(bitsOffs) for bitsOffs in tileFormat.bitsOffs]) + 1
        assert(tileSizeBits % 8 == 0)
        tileSize = tileSizeBits // 8
        numTiles = len(byteData) // tileSize
    tileDataSrc = array.array('B', [0] * numTiles * tileFormat.stride)

    # Expand to 1 entry per bit
    for i in range(len(tileDataSrc)):
        tileDataSrc[i] = (byteData[fileOffset + int(i / 8)] >> int(i % 8)) & 1

    tileDataDst = array.array('B', [0] * tileFormat.width * tileFormat.height * numTiles)
    for i in range(numTiles):
        for y in range(tileFormat.height):
            for x in range(tileFormat.width):
                c = 0
                for n in range(len(tileFormat.bitsOffs)):
                    c |= tileDataSrc[i * tileFormat.stride + tileFormat.bitsOffs[n][y * tileFormat.width + x]] << n
                tileDataDst[i * tileFormat.width * tileFormat.height + y * tileFormat.width + x] = c
    return tileDataDst, numTiles, tileFormat.width, tileFormat.height


def writeTiles(filename, tileData, numTiles, tileFormat):
    tileWidth, tileHeight = tileFormat.width, tileFormat.height
    rawData = array.array('B', [0] * ((numTiles * tileFormat.stride) // 8))
    with open(filename, "wb") as f:
        for i in range(numTiles):
            for y in range(tileHeight):
                for x in range(tileWidth):
                    color = tileData[tileWidth * tileHeight * i + tileWidth * y + x]
                    for bitIndex, bitsOffs in enumerate(tileFormat.bitsOffs):
                        bitsOffs = bitsOffs[y * tileWidth + x]
                        bytePos = int(tileFormat.stride * i + bitsOffs) >> 3
                        bitPos = int(tileFormat.stride * i + bitsOffs) & 7
                        rawData[bytePos] |= ((color >> bitIndex) & 1) << bitPos
        rawData.tofile(f)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} gb_tiles.chr nes_tiles.chr")
        sys.exit(0)
    in_filename = sys.argv[1]
    out_filename = sys.argv[2]
    nes2gb_mode = "nes2gb" in sys.argv[0]
    tileData, numTiles, w, h = readTiles(in_filename, 0, RawFormats['NES'] if nes2gb_mode else RawFormats['GB'])
    assert(w == 8 and h == 8)
    writeTiles(out_filename, tileData, numTiles, RawFormats['GB'] if nes2gb_mode else RawFormats['NES'])
