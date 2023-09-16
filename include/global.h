#ifndef _GLOBAL
#define _GLOBAL

#include <gbdk/platform.h>

#include "data.h"
#include "rand.h"
#include "player.h"
#include "monster.h"
#include "boss.h"
#include "misc.h"
#include "music.h"

#if defined(SEGA)
    #if defined(GAMEGEAR)
        #define VIEWPORT_HEIGHT DEVICE_SCREEN_HEIGHT
        #define VIEWPORT_WIDTH DEVICE_SCREEN_WIDTH
        #define VIEWPORT_X_OFS 0
        #define VIEWPORT_Y_OFS 0
        #define SPRITE_OFS_X (DEVICE_SPRITE_PX_OFFSET_X - 8)
        #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16)
    #elif defined(MASTERSYSTEM)
        #define VIEWPORT_HEIGHT 18
        #define VIEWPORT_WIDTH 20
        #define VIEWPORT_X_OFS 6
        #define VIEWPORT_Y_OFS 0
        #define SPRITE_OFS_X (DEVICE_SPRITE_PX_OFFSET_X + 6 * 8 - 8)
        #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16)
        #define CLIP_SPRITES_X
        #define CLIP_SPRITES_Y
    #endif
    #define RAND_SOURCE sys_time
#elif defined(NINTENDO_NES)
    #define VIEWPORT_HEIGHT 18
    #define VIEWPORT_WIDTH 20
    #define VIEWPORT_X_OFS 6
    #define VIEWPORT_Y_OFS 6
    #define SPRITE_OFS_X (DEVICE_SPRITE_PX_OFFSET_X - 8) + 8*VIEWPORT_X_OFS
    #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16) + 8*VIEWPORT_Y_OFS
    #define RAND_SOURCE 0xa27e
    #define CLIP_SPRITES_X
    #define CLIP_SPRITES_Y
#elif defined(NINTENDO)
    #define VIEWPORT_HEIGHT DEVICE_SCREEN_HEIGHT
    #define VIEWPORT_WIDTH DEVICE_SCREEN_WIDTH
    #define VIEWPORT_X_OFS 0
    #define VIEWPORT_Y_OFS 0
    #define SPRITE_OFS_X (DEVICE_SPRITE_PX_OFFSET_X - 8)
    #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16)
    #define RAND_SOURCE DIV_REG
#endif

// How many columns of map to preload into buf past the right of the screen
#define BUF_PRELOAD_WIDTH 8

#define UPDATE_KEYS()   old_input = input; input = joypad()
#define KEY_PRESSED(K)  (input & (K))
#define KEY_DEBOUNCE(K) ((input & (K)) && (old_input & (K)))
#define KEY_TICKED(K)   ((input & (K)) && !(old_input & (K)))
#define KEY_RELEASED(K) ((old_input & (K)) && !(input & (K)))

#define SET_BANK(N)     old_bank = _current_bank, SWITCH_ROM(N)
#define RESTORE_BANK()  SWITCH_ROM(old_bank)

#define GS_TITLE                0
#define GS_LEVEL                1
#define GS_END                  2

#define FALSE                   0
#define TRUE                    1

#define ST_OFFSET               1u
// Player, items, weapons and explosion
#define ST_PLAYER_IDLE0         0u + ST_OFFSET
#define ST_PLAYER_IDLE1         2u + ST_OFFSET
#define ST_PLAYER_JUMP0         4u + ST_OFFSET
#define ST_PLAYER_JUMP1         6u + ST_OFFSET
#define ST_PLAYER_WALK0         8u + ST_OFFSET
#define ST_PLAYER_WALK1         10u + ST_OFFSET
#define ST_PLAYER_WALK2         12u + ST_OFFSET
#define ST_PLAYER_WALK3         14u + ST_OFFSET
#define ST_PLAYER_WALK4         16u + ST_OFFSET
#define ST_PLAYER_WALK5         18u + ST_OFFSET
#define ST_PLAYER_ATCK0         20u + ST_OFFSET
#define ST_PLAYER_ATCK1         22u + ST_OFFSET
#define ST_PLAYER_DROP0         24u + ST_OFFSET
#define ST_PLAYER_DROP1         26u + ST_OFFSET
#define ST_PLAYER_SWORD         28u + ST_OFFSET
#define ST_PLAYER_AXE0          30u + ST_OFFSET
#define ST_PLAYER_AXE1          32u + ST_OFFSET
#define ST_PLAYER_AXE2          34u + ST_OFFSET
#define ST_PLAYER_AXE3          36u + ST_OFFSET
#define ST_PLAYER_MACE0         38u + ST_OFFSET
#define ST_PLAYER_MACE1         40u + ST_OFFSET
#define ST_PLAYER_MACE2         42u + ST_OFFSET
#define ST_PLAYER_MACE3         44u + ST_OFFSET
#define ST_LAST                 46u + ST_OFFSET
// Flippable monster tiles
#define ST_KNIGHT0              46u + ST_OFFSET
#define ST_KNIGHT1              48u + ST_OFFSET
#define ST_KNIGHT2              50u + ST_OFFSET
#define ST_KNIGHT3              52u + ST_OFFSET
#define ST_SKELETON0            54u  + ST_OFFSET
#define ST_SKELETON1            56u  + ST_OFFSET
#define ST_SKELETON2            58u  + ST_OFFSET
#define ST_SKELETON3            60u  + ST_OFFSET
#define ST_SKELETON4            62u  + ST_OFFSET
#define ST_SKELETON5            64u  + ST_OFFSET
#define ST_SKELETON6            66u  + ST_OFFSET
#define ST_SKELETON7            68u  + ST_OFFSET
#define ST_NUM_FLIP             70u
// Non-flippable monster tiles
#define ST_BAT0                 144u + ST_OFFSET
#define ST_BAT1                 146u + ST_OFFSET
#define ST_BAT2                 148u + ST_OFFSET
#define ST_BAT3                 150u + ST_OFFSET
#define ST_DEAMON0              152u + ST_OFFSET
#define ST_DEAMON1              154u + ST_OFFSET
#define ST_DEAMON2              156u + ST_OFFSET
#define ST_DEAMON3              158u + ST_OFFSET
#define ST_SPIDER0              160u + ST_OFFSET
#define ST_SPIDER1              162u + ST_OFFSET
#define ST_SPIDER2              164u + ST_OFFSET
#define ST_SPIDER3              166u + ST_OFFSET
// Items/Explosions/etc (non-flippable)
#define ST_CRYSTAL              168u + ST_OFFSET
#define ST_HEART                170u + ST_OFFSET
#define ST_STONE                172u + ST_OFFSET
#define ST_PLATFORM             174u + ST_OFFSET
#define ST_MONSTER_SHOT         176u + ST_OFFSET
#define ST_EXPLOSION0           178u + ST_OFFSET
#define ST_EXPLOSION1           180u + ST_OFFSET
#define ST_EXPLOSION2           182u + ST_OFFSET
#define ST_EXPLOSION3           184u + ST_OFFSET
#define ST_EXPLOSION4           186u + ST_OFFSET
#define ST_EXPLOSION5           188u + ST_OFFSET
#define ST_NUM_NOFLIP           46u
// "GAME OVER" tiles are uploaded after hiding all other sprites - can reuse tiles
#define ST_GAME_OVER0           0u + ST_OFFSET
#define ST_GAME_OVER1           2u + ST_OFFSET
#define ST_GAME_OVER2           4u + ST_OFFSET
#define ST_GAME_OVER3           6u + ST_OFFSET
#define ST_GAME_OVER_NUM_TILES  8u
// Boss tiles (overlap with monster tiles)
#define ST_BOSS_BAT0            116u + ST_OFFSET
#define ST_BOSS_BAT1            118u + ST_OFFSET
#define ST_BOSS_BAT2            120u + ST_OFFSET
#define ST_BOSS_BAT3            122u + ST_OFFSET
#define ST_BOSS_BAT4            124u + ST_OFFSET
#define ST_BOSS_BAT5            126u + ST_OFFSET
#define ST_BOSS_MINOTAUR0       128u + ST_OFFSET
#define ST_BOSS_MINOTAUR1       130u + ST_OFFSET
#define ST_BOSS_MINOTAUR2       132u + ST_OFFSET
#define ST_BOSS_MINOTAUR3       134u + ST_OFFSET
#define ST_BOSS_MINOTAUR4       136u + ST_OFFSET
#define ST_BOSS_MINOTAUR5       138u + ST_OFFSET
#define ST_BOSS_MINOTAUR6       140u + ST_OFFSET
#define ST_BOSS_MINOTAUR7       142u + ST_OFFSET
#define ST_BOSS_MINOTAUR8       144u + ST_OFFSET
#define ST_BOSS_MINOTAUR9       146u + ST_OFFSET
#define ST_BOSS_MINOTAUR10      148u + ST_OFFSET
#define ST_BOSS_MINOTAUR11      150u + ST_OFFSET
#define ST_BOSS_REAPER0         152u + ST_OFFSET
#define ST_BOSS_REAPER1         154u + ST_OFFSET
#define ST_BOSS_REAPER2         156u + ST_OFFSET
#define ST_BOSS_REAPER3         158u + ST_OFFSET
#define ST_BOSS_REAPER4         160u + ST_OFFSET
#define ST_BOSS_REAPER5         162u + ST_OFFSET
#define ST_BOSS_REAPER6         164u + ST_OFFSET
#define ST_BOSS_REAPER7         166u + ST_OFFSET
#define ST_NUM_BOSS             52u
// Used for masking left/right and bottom of window on SMS/NES
#define SPRITE_MASK_TILE_INDEX  0xBEu
// Font tile indices for start of letters / numbers. Used for end text
#define FONT_TILE_INDEX_A       0x21
#define FONT_TILE_INDEX_0       0x3B

#define OBJ_CRYSTAL             0
#define OBJ_HEART               1
#define OBJ_SWORD               2
#define OBJ_AXE                 3
#define OBJ_MACE                4
#define OBJ_FALLING_PLATFORM    5
#define OBJ_UPDOWN_PLATFORM     6
#define OBJ_LEFTRIGHT_PLATFORM  7
#define OBJ_KNIGHT              8
#define OBJ_BAT                 9
#define OBJ_REAPER              10
#define OBJ_SPIDER              11
#define OBJ_SKELETON            12

//game state
extern UBYTE game_state;

//input
extern UBYTE input;
extern UBYTE old_input;

//bank
extern UBYTE bank;
extern UBYTE old_bank;

//background
extern BYTE scroll;
extern UWORD scroll_pos;
extern UBYTE scroll_pos_with_shake;
extern UBYTE tile_cnt;
extern UBYTE tile_pos;
extern UBYTE shake;

// Rolling buffer of 32 columns of level data
extern UBYTE buf[512];
#define BUFPOS(X, Y) (((X & 0x1F) << 4) + Y)
#define MAPPOS(X, Y) ((X << 4) + Y)

//level
extern const unsigned char *level_data;
extern UBYTE level_pos;
extern UBYTE level_ani;
extern UBYTE level_maj;
extern UBYTE level_min;
extern UBYTE level_len;

//high score
extern UWORD high_score;

// Global map pointer and map bank, used by update_column
extern UBYTE* g_meta_lookup_tl;
extern UBYTE* g_meta_lookup_tr;
extern UBYTE* g_meta_lookup_bl;
extern UBYTE* g_meta_lookup_br;
extern UBYTE* g_current_map;
extern UBYTE g_current_map_bank;

//functions
void enter_title(void);
void enter_level(void);
void enter_end(void);

typedef void (*state_handler_t)(void);
extern const state_handler_t state_handlers[];

// level structures

typedef struct level_minor_t {
    UBYTE bank_map;
    UBYTE * map;
    UBYTE * data;
    UBYTE len;
    UBYTE music;
    UBYTE boss_x, boss_y, boss_typ;
} level_minor_t;

typedef struct level_t {
    UBYTE bank_tiles;
    UBYTE * tiles;
    UBYTE bank_sprites;
    UBYTE * sprites;
    UBYTE bank_sprites_noflip;
    UBYTE * sprites_noflip;
    UBYTE bank_sprites_bosses;
    UBYTE * sprites_bosses;
    UBYTE bank_hud;
    UBYTE * hud_tiles;
    UBYTE * hud_map;
    UBYTE * meta_lookup_tl;
    UBYTE * meta_lookup_tr;
    UBYTE * meta_lookup_bl;
    UBYTE * meta_lookup_br;
    level_minor_t minor[4];
} level_t;


BANKREF_EXTERN(title_tiles)
BANKREF_EXTERN(title_map)
BANKREF_EXTERN(sprite_tiles)
BANKREF_EXTERN(sprite_tiles_noflip)
BANKREF_EXTERN(sprite_tiles_bosses)
BANKREF_EXTERN(hud_tiles)
BANKREF_EXTERN(hud_map)
BANKREF_EXTERN(level1_tiles)
BANKREF_EXTERN(level1_1_map)
BANKREF_EXTERN(level1_2_map)
BANKREF_EXTERN(level1_3_map)
BANKREF_EXTERN(level1_4_map)
BANKREF_EXTERN(level2_tiles)
BANKREF_EXTERN(level2_1_map)
BANKREF_EXTERN(level2_2_map)
BANKREF_EXTERN(level2_3_map)
BANKREF_EXTERN(level2_4_map)
BANKREF_EXTERN(level3_tiles)
BANKREF_EXTERN(level3_1_map)
BANKREF_EXTERN(level3_2_map)
BANKREF_EXTERN(level3_3_map)
BANKREF_EXTERN(level3_4_map)
BANKREF_EXTERN(end_map)
BANKREF_EXTERN(monster_data)

#define ENEMY_SPAWN_POS_X 176
#define ENEMY_SPAWN_POS_TILE_X (ENEMY_SPAWN_POS_X >> 3)

inline void update_screen_column_from_buf(UBYTE pos)
{
    UBYTE i = pos & (DEVICE_SCREEN_BUFFER_WIDTH - 1);
    UWORD w = pos << 4;
    UWORD wmod = w & 0x1F0;
    set_bkg_tiles((VIEWPORT_X_OFS + i) & (DEVICE_SCREEN_BUFFER_WIDTH - 1),
                  VIEWPORT_Y_OFS + 2,
                  1,
                  16,
                  &buf[wmod]);
}

void move_sprite_clip(uint8_t nb, uint8_t x, uint8_t y);

inline void set_sprite_flip(uint8_t nb, uint8_t flip)
{
#if defined(SEGA)
    uint8_t tile = shadow_OAM[0x41+(nb << 1)];
    if(tile < (ST_NUM_FLIP+1) && flip)
        shadow_OAM[0x41+(nb << 1)] = tile + ST_NUM_FLIP;
    else if(tile >= (ST_NUM_FLIP+1) && !flip)
        shadow_OAM[0x41+(nb << 1)] = tile - ST_NUM_FLIP;
#else
    set_sprite_prop(nb, flip);
#endif
}

#if defined(SEGA)
void set_sprite_data_flipx(uint8_t first_tile, uint8_t nb_tiles, const uint8_t *data);
#endif

#define QUOTED_STRING(s) #s
#if defined(NINTENDO_NES)
void set_bkg_data_tokumaru(uint8_t first_tile, uint8_t nb_tiles, const uint8_t *data);
void set_sprite_data_tokumaru(uint8_t first_tile, uint8_t nb_tiles, const uint8_t *data);
#define SET_BKG_CHR(FIRST_TILE, NB_TILES, DATA) set_bkg_data_tokumaru(FIRST_TILE, NB_TILES, DATA)
#define SET_SPRITE_CHR(FIRST_TILE, NB_TILES, DATA) set_sprite_data_tokumaru(FIRST_TILE, NB_TILES, DATA)
#define INCBIN_CHR(name, filename) INCBIN(name, QUOTED_STRING(filename.tkc))
#else
#define SET_BKG_CHR(FIRST_TILE, NB_TILES, DATA) set_bkg_data(FIRST_TILE, NB_TILES, DATA)
#define SET_SPRITE_CHR(FIRST_TILE, NB_TILES, DATA) set_sprite_data(FIRST_TILE, NB_TILES, DATA)
#define INCBIN_CHR(name, filename) INCBIN(name, QUOTED_STRING(filename.chr))
#endif


#endif
