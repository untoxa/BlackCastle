#!/usr/bin/env python3
import sys
from optparse import OptionParser
from PIL import Image

def hexdump(b, w=32):
    print("\n".join(b[i:i + w].hex() for i in range(0, len(b), w)))

def render_to_texels(data, map, mapwidth=16, transpose = True):
    if map == None:
        mapwidth = -(-len(data) // 16)
        map = bytearray([i for i in range(mapwidth)])
        numrows = 1
    else:
        numrows = -(-len(map) // mapwidth)
            
    rowbytes = 16 * mapwidth
    texels = bytearray()
    for i in range(numrows):
        rowdata = bytes()

        for j in range(mapwidth):
            if transpose:
                tileofs = map[j * numrows + i] * 16
            else:
                tileofs = map[i * mapwidth + j] * 16
            rowdata = rowdata + data[tileofs:tileofs+16]
        
        plane0 = b''.join(rowdata[i::16] for i in range(0, 16, 2))
        plane1 = b''.join(rowdata[i::16] for i in range(1, 17, 2))
        for p0, p1 in zip(plane0, plane1):
            texels.extend(
                ((p0 >> x) & 1) | (((p1 >> x) & 1) << 1)
                for x in range(7, -1, -1)
            )
    im = Image.new('P', (8 * mapwidth, 8 * numrows))
    im.putdata(texels)
    im.putpalette(b'\xC0\xFF\x5F\x80\xBF\x5F\x40\x7F\x5F\x00\x3F\x5F')
    return im

def main(argv=None):
    parser = OptionParser("Usage: gbtiles2png.py [options] TILES.2BPP")
    parser.add_option("-o", '--out',        dest='outfilename',                                        help='output file name')
    parser.add_option("-m", '--map',        dest='mapfilename',                                        help='map file')
    parser.add_option("-w", '--width',      dest='mapwidth',                           default=16,     help='map file width')
    parser.add_option("-t", '--transpose',  dest='transpose',    action="store_true", default=False,  help='transpose tile map')

    (options, args) = parser.parse_args()

    if len(args) == 0:
        parser.print_help()
        parser.error("Input file name required\n")        

    infilename = args[0]
    mapfilename = options.mapfilename
    mapwidth = int(options.mapwidth)

    outfilename = options.outfilename

    with open(infilename, "rb") as infp:
        romdata = infp.read()
    if mapfilename:
        with open(mapfilename, "rb") as inmp:
            mapdata = inmp.read()
    else:
        mapdata = None
    tiles = render_to_texels(romdata, mapdata, mapwidth, options.transpose)
    if outfilename:
        tiles.save(outfilename)
    else:
        tiles.show()

if __name__=='__main__':
    main()
