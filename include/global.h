#ifndef _GLOBAL
#define _GLOBAL

#include <gbdk/platform.h>

#include "data.h"
#include "data2.h"
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

#define SET_BANK(N)     SWITCH_ROM(N); old_bank = bank; bank = N
#define RESTORE_BANK()  SWITCH_ROM(old_bank); bank = old_bank

#define GS_TITLE                0
#define GS_LEVEL                1
#define GS_END                  2
        
#define FALSE                   0
#define TRUE                    1

#define ST_OFFSET               1

#define ST_PLAYER_IDLE0         0 + ST_OFFSET
#define ST_PLAYER_IDLE1         2 + ST_OFFSET
#define ST_PLAYER_JUMP0         4 + ST_OFFSET
#define ST_PLAYER_JUMP1         6 + ST_OFFSET
#define ST_PLAYER_WALK0         8 + ST_OFFSET
#define ST_PLAYER_WALK1         10 + ST_OFFSET
#define ST_PLAYER_WALK2         12 + ST_OFFSET
#define ST_PLAYER_WALK3         14 + ST_OFFSET
#define ST_PLAYER_WALK4         16 + ST_OFFSET
#define ST_PLAYER_WALK5         18 + ST_OFFSET
#define ST_PLAYER_ATCK0         20 + ST_OFFSET
#define ST_PLAYER_ATCK1         22 + ST_OFFSET
#define ST_PLAYER_DROP0         24 + ST_OFFSET
#define ST_PLAYER_DROP1         26 + ST_OFFSET
#define ST_PLAYER_SWORD         28 + ST_OFFSET
#define ST_PLAYER_AXE0          30 + ST_OFFSET
#define ST_PLAYER_AXE1          32 + ST_OFFSET
#define ST_PLAYER_AXE2          34 + ST_OFFSET
#define ST_PLAYER_AXE3          36 + ST_OFFSET
#define ST_PLAYER_MACE0         38 + ST_OFFSET
#define ST_PLAYER_MACE1         40 + ST_OFFSET
#define ST_PLAYER_MACE2         42 + ST_OFFSET
#define ST_PLAYER_MACE3         44 + ST_OFFSET
#define ST_CRYSTAL              46 + ST_OFFSET
#define ST_HEART                48 + ST_OFFSET
#define ST_STONE                50 + ST_OFFSET
#define ST_PLATFORM             52 + ST_OFFSET
#define ST_MONSTER_SHOT         54 + ST_OFFSET
#define ST_EXPLOSION0           56 + ST_OFFSET
#define ST_EXPLOSION1           58 + ST_OFFSET
#define ST_EXPLOSION2           60 + ST_OFFSET
#define ST_EXPLOSION3           62 + ST_OFFSET
#define ST_EXPLOSION4           64 + ST_OFFSET
#define ST_EXPLOSION5           66 + ST_OFFSET
#define ST_KNIGHT0              68 + ST_OFFSET
#define ST_KNIGHT1              70 + ST_OFFSET
#define ST_KNIGHT2              72 + ST_OFFSET
#define ST_KNIGHT3              74 + ST_OFFSET
#define ST_BAT0                 76 + ST_OFFSET
#define ST_BAT1                 78 + ST_OFFSET
#define ST_BAT2                 80 + ST_OFFSET
#define ST_BAT3                 82 + ST_OFFSET
#define ST_DEAMON0              84 + ST_OFFSET
#define ST_DEAMON1              86 + ST_OFFSET
#define ST_DEAMON2              88 + ST_OFFSET
#define ST_DEAMON3              90 + ST_OFFSET
#define ST_SPIDER0              92 + ST_OFFSET
#define ST_SPIDER1              94 + ST_OFFSET
#define ST_SPIDER2              96 + ST_OFFSET
#define ST_SPIDER3              98 + ST_OFFSET
#define ST_SKELETON0            100 + ST_OFFSET
#define ST_SKELETON1            102 + ST_OFFSET
#define ST_SKELETON2            104 + ST_OFFSET
#define ST_SKELETON3            106 + ST_OFFSET
#define ST_SKELETON4            108 + ST_OFFSET
#define ST_SKELETON5            110 + ST_OFFSET
#define ST_SKELETON6            112 + ST_OFFSET
#define ST_SKELETON7            114 + ST_OFFSET
#define ST_BOSS_BAT0            116 + ST_OFFSET
#define ST_BOSS_BAT1            118 + ST_OFFSET
#define ST_BOSS_BAT2            120 + ST_OFFSET
#define ST_BOSS_BAT3            122 + ST_OFFSET
#define ST_BOSS_BAT4            124 + ST_OFFSET
#define ST_BOSS_BAT5            126 + ST_OFFSET
#define ST_BOSS_MINOTAUR0       128 + ST_OFFSET
#define ST_BOSS_MINOTAUR1       130 + ST_OFFSET
#define ST_BOSS_MINOTAUR2       132 + ST_OFFSET
#define ST_BOSS_MINOTAUR3       134 + ST_OFFSET
#define ST_BOSS_MINOTAUR4       136 + ST_OFFSET
#define ST_BOSS_MINOTAUR5       138 + ST_OFFSET
#define ST_BOSS_MINOTAUR6       140 + ST_OFFSET
#define ST_BOSS_MINOTAUR7       142 + ST_OFFSET
#define ST_BOSS_MINOTAUR8       144 + ST_OFFSET
#define ST_BOSS_MINOTAUR9       146 + ST_OFFSET
#define ST_BOSS_MINOTAUR10      148 + ST_OFFSET
#define ST_BOSS_MINOTAUR11      150 + ST_OFFSET
#define ST_BOSS_REAPER0         152 + ST_OFFSET
#define ST_BOSS_REAPER1         154 + ST_OFFSET
#define ST_BOSS_REAPER2         156 + ST_OFFSET
#define ST_BOSS_REAPER3         158 + ST_OFFSET
#define ST_BOSS_REAPER4         160 + ST_OFFSET
#define ST_BOSS_REAPER5         162 + ST_OFFSET
#define ST_BOSS_REAPER6         164 + ST_OFFSET
#define ST_BOSS_REAPER7         166 + ST_OFFSET
#define ST_GAME_OVER0           168 + ST_OFFSET
#define ST_GAME_OVER1           170 + ST_OFFSET
#define ST_GAME_OVER2           172 + ST_OFFSET
#define ST_GAME_OVER3           174 + ST_OFFSET
#define ST_LAST                 176 + ST_OFFSET
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
    UBYTE bank_hud;
    UBYTE * hud_tiles;
    UBYTE * hud_map;
    level_minor_t minor[4];
} level_t;


BANKREF_EXTERN(title_tiles)
BANKREF_EXTERN(title_map)
BANKREF_EXTERN(sprite_tiles)
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

#define ENEMY_SPAWN_POS_X 176
#define ENEMY_SPAWN_POS_TILE_X (ENEMY_SPAWN_POS_X >> 3)

inline void update_column(UBYTE pos)
{
    UBYTE j;
    UBYTE i = (tile_pos + VIEWPORT_WIDTH + 0) & (DEVICE_SCREEN_BUFFER_WIDTH - 1);
    UWORD w = (pos + VIEWPORT_WIDTH + BUF_PRELOAD_WIDTH) << 4;
    UWORD wmod = w & 0x1F0;
    SET_BANK(g_current_map_bank);
    for(j = 0; j < 16; j++)
        buf[wmod+j] = g_current_map[w+j];
    w = (pos + VIEWPORT_WIDTH + 0) << 4;
    wmod = w & 0x1F0;
    set_bkg_tiles((VIEWPORT_X_OFS + i) & (DEVICE_SCREEN_BUFFER_WIDTH - 1),
                  VIEWPORT_Y_OFS + 2,
                  1,
                  16,
                  &buf[wmod]);
    RESTORE_BANK();
}

void move_sprite_clip(uint8_t nb, uint8_t x, uint8_t y);

#endif
