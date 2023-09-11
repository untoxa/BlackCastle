#pragma bank 6

#include "global.h"
#include "data.h"

#include <gbdk/incbin.h>

INCBIN(level1_tiles, "res/level1_tiles.chr")
INCBIN_EXTERN(level1_tiles)

INCBIN(level1_1_map, "res/level_1_1_map_meta.bin")
INCBIN_EXTERN(level1_1_map)

INCBIN(level1_2_map, "res/level_1_2_map_meta.bin")
INCBIN_EXTERN(level1_2_map)

INCBIN(level1_3_map, "res/level_1_3_map_meta.bin")
INCBIN_EXTERN(level1_3_map)

INCBIN(level1_4_map, "res/level_1_4_map_meta.bin")
INCBIN_EXTERN(level1_4_map)

INCBIN(level1_meta_lookup_tl, "res/level1_meta_lookup_tl.bin")
INCBIN_EXTERN(level1_meta_lookup_tl)
INCBIN(level1_meta_lookup_tr, "res/level1_meta_lookup_tr.bin")
INCBIN_EXTERN(level1_meta_lookup_tr)
INCBIN(level1_meta_lookup_bl, "res/level1_meta_lookup_bl.bin")
INCBIN_EXTERN(level1_meta_lookup_bl)
INCBIN(level1_meta_lookup_br, "res/level1_meta_lookup_br.bin")
INCBIN_EXTERN(level1_meta_lookup_br)
