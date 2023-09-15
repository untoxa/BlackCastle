#pragma bank 255

#include "global.h"
#include "data.h"

#include <gbdk/incbin.h>

INCBIN_CHR(title_tiles, res/title_bg_nofont)
INCBIN_EXTERN(title_tiles)

INCBIN(title_map, "res/title_map.bin")
INCBIN_EXTERN(title_map)
