#pragma bank 255

#include "global.h"
#include "data.h"

#include <gbdk/incbin.h>

INCBIN(level2_tiles, "res/level2_tiles.chr")
INCBIN_EXTERN(level2_tiles)

INCBIN(level2_1_map, "res/level_2_1_map_meta.bin")
INCBIN_EXTERN(level2_1_map)

INCBIN(level2_2_map, "res/level_2_2_map_meta.bin")
INCBIN_EXTERN(level2_2_map)

INCBIN(level2_3_map, "res/level_2_3_map_meta.bin")
INCBIN_EXTERN(level2_3_map)

INCBIN(level2_4_map, "res/level_2_4_map_meta.bin")
INCBIN_EXTERN(level2_4_map)

INCBIN(level2_meta_lookup_tl, "res/level2_meta_lookup_tl.bin")
INCBIN_EXTERN(level2_meta_lookup_tl)
INCBIN(level2_meta_lookup_tr, "res/level2_meta_lookup_tr.bin")
INCBIN_EXTERN(level2_meta_lookup_tr)
INCBIN(level2_meta_lookup_bl, "res/level2_meta_lookup_bl.bin")
INCBIN_EXTERN(level2_meta_lookup_bl)
INCBIN(level2_meta_lookup_br, "res/level2_meta_lookup_br.bin")
INCBIN_EXTERN(level2_meta_lookup_br)
