#pragma bank 255

#include "global.h"
#include "data.h"

#include <gbdk/incbin.h>

INCBIN(level3_tiles, "res/level3_tiles.chr")
INCBIN_EXTERN(level3_tiles)

INCBIN(level3_1_map, "res/level_3_1_map_meta.bin")
INCBIN_EXTERN(level3_1_map)

INCBIN(level3_2_map, "res/level_3_2_map_meta.bin")
INCBIN_EXTERN(level3_2_map)

INCBIN(level3_3_map, "res/level_3_3_map_meta.bin")
INCBIN_EXTERN(level3_3_map)

INCBIN(level3_4_map, "res/level_3_4_map_meta.bin")
INCBIN_EXTERN(level3_4_map)

INCBIN(level3_meta_lookup_tl, "res/level3_meta_lookup_tl.bin")
INCBIN_EXTERN(level3_meta_lookup_tl)
INCBIN(level3_meta_lookup_tr, "res/level3_meta_lookup_tr.bin")
INCBIN_EXTERN(level3_meta_lookup_tr)
INCBIN(level3_meta_lookup_bl, "res/level3_meta_lookup_bl.bin")
INCBIN_EXTERN(level3_meta_lookup_bl)
INCBIN(level3_meta_lookup_br, "res/level3_meta_lookup_br.bin")
INCBIN_EXTERN(level3_meta_lookup_br)
// End map re-uses meta-lookups from level3, so should live here
INCBIN(end_map, "res/end_map_no_text_meta.bin")
INCBIN_EXTERN(end_map)