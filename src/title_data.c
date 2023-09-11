#pragma bank 255

#include "global.h"
#include "data.h"

#include <gbdk/incbin.h>

INCBIN(title_tiles, "res/title_bg.chr")
INCBIN_EXTERN(title_tiles)

INCBIN(title_map, "res/title_map.bin")
INCBIN_EXTERN(title_map)
