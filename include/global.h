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
#include "unapack.h"

#if defined(SEGA)
    #if defined(GAMEGEAR)
        #define VIEWPORT_HEIGHT DEVICE_SCREEN_HEIGHT
        #define VIEWPORT_WIDTH DEVICE_SCREEN_WIDTH
        #define VIEWPORT_X_OFS 0
        #define SPRITE_OFS_X (DEVICE_SPRITE_PX_OFFSET_X - 8)
        #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16)
    #elif defined(MASTERSYSTEM)
        #define VIEWPORT_HEIGHT 18
        #define VIEWPORT_WIDTH (DEVICE_SCREEN_WIDTH - 1)
        #define VIEWPORT_X_OFS 1
        #define SPRITE_OFS_X DEVICE_SPRITE_PX_OFFSET_X
        #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16)
    #endif
    #define RAND_SOURCE sys_time
#elif defined(NINTENDO)
    #define VIEWPORT_HEIGHT DEVICE_SCREEN_HEIGHT
    #define VIEWPORT_WIDTH DEVICE_SCREEN_WIDTH
    #define VIEWPORT_X_OFS 0
    #define SPRITE_OFS_X (DEVICE_SPRITE_PX_OFFSET_X - 8)
    #define SPRITE_OFS_Y (DEVICE_SPRITE_PX_OFFSET_Y - 16)
    #define RAND_SOURCE DIV_REG
#endif

#define UPDATE_KEYS()	old_input = input; input = joypad()
#define KEY_PRESSED(K)	(input & (K))
#define KEY_DEBOUNCE(K) ((input & (K)) && (old_input & (K)))
#define KEY_TICKED(K)   ((input & (K)) && !(old_input & (K)))
#define KEY_RELEASED(K) ((old_input & (K)) && !(input & (K)))

#define SET_BANK(N)		SWITCH_ROM(N); old_bank = bank; bank = N
#define RESTORE_BANK()	SWITCH_ROM(old_bank); bank = old_bank

#define GS_TITLE				0
#define GS_LEVEL				1
#define GS_END					2
		
#define FALSE					0
#define TRUE					1

#define ST_PLAYER_IDLE0			0
#define ST_PLAYER_IDLE1			2
#define ST_PLAYER_JUMP0			4
#define ST_PLAYER_JUMP1			6
#define ST_PLAYER_WALK0			8
#define ST_PLAYER_WALK1			10
#define ST_PLAYER_WALK2			12
#define ST_PLAYER_WALK3			14
#define ST_PLAYER_WALK4			16
#define ST_PLAYER_WALK5			18
#define ST_PLAYER_ATCK0			20
#define ST_PLAYER_ATCK1			22
#define ST_PLAYER_DROP0			24
#define ST_PLAYER_DROP1			26
#define ST_PLAYER_SWORD			28
#define ST_PLAYER_AXE0			30
#define ST_PLAYER_AXE1			32
#define ST_PLAYER_AXE2			34
#define ST_PLAYER_AXE3			36
#define ST_PLAYER_MACE0			38
#define ST_PLAYER_MACE1			40
#define ST_PLAYER_MACE2			42
#define ST_PLAYER_MACE3			44
#define ST_CRYSTAL				46
#define ST_HEART				48
#define ST_STONE				50
#define ST_PLATFORM				52
#define ST_MONSTER_SHOT			54
#define ST_EXPLOSION0			56
#define ST_EXPLOSION1			58
#define ST_EXPLOSION2			60
#define ST_EXPLOSION3			62
#define ST_EXPLOSION4			64
#define ST_EXPLOSION5			66
#define ST_KNIGHT0				68
#define ST_KNIGHT1				70
#define ST_KNIGHT2				72
#define ST_KNIGHT3				74
#define ST_BAT0					76
#define ST_BAT1					78
#define ST_BAT2					80
#define ST_BAT3					82
#define ST_DEAMON0				84
#define ST_DEAMON1				86
#define ST_DEAMON2				88			
#define ST_DEAMON3				90
#define ST_SPIDER0				92
#define ST_SPIDER1				94
#define ST_SPIDER2				96
#define ST_SPIDER3				98
#define ST_SKELETON0			100
#define ST_SKELETON1			102
#define ST_SKELETON2			104
#define ST_SKELETON3			106
#define ST_SKELETON4			108
#define ST_SKELETON5			110
#define ST_SKELETON6			112
#define ST_SKELETON7			114
#define ST_BOSS_BAT0			116
#define ST_BOSS_BAT1			118
#define ST_BOSS_BAT2			120
#define ST_BOSS_BAT3			122
#define ST_BOSS_BAT4			124
#define ST_BOSS_BAT5			126
#define ST_BOSS_MINOTAUR0		128
#define ST_BOSS_MINOTAUR1		130
#define ST_BOSS_MINOTAUR2		132
#define ST_BOSS_MINOTAUR3		134
#define ST_BOSS_MINOTAUR4		136
#define ST_BOSS_MINOTAUR5		138
#define ST_BOSS_MINOTAUR6		140
#define ST_BOSS_MINOTAUR7		142
#define ST_BOSS_MINOTAUR8		144
#define ST_BOSS_MINOTAUR9		146
#define ST_BOSS_MINOTAUR10		148
#define ST_BOSS_MINOTAUR11		150
#define ST_BOSS_REAPER0			152
#define ST_BOSS_REAPER1			154
#define ST_BOSS_REAPER2			156
#define ST_BOSS_REAPER3			158
#define ST_BOSS_REAPER4			160
#define ST_BOSS_REAPER5			162
#define ST_BOSS_REAPER6			164
#define ST_BOSS_REAPER7			166
#define ST_GAME_OVER0			168
#define ST_GAME_OVER1			170
#define ST_GAME_OVER2			172
#define ST_GAME_OVER3			174
#define ST_LAST					176
    	
#define OBJ_CRYSTAL				0
#define OBJ_HEART				1
#define OBJ_SWORD				2
#define OBJ_AXE					3
#define OBJ_MACE				4
#define OBJ_FALLING_PLATFORM	5
#define OBJ_UPDOWN_PLATFORM		6
#define OBJ_LEFTRIGHT_PLATFORM	7
#define OBJ_KNIGHT				8
#define OBJ_BAT					9
#define OBJ_REAPER				10
#define OBJ_SPIDER				11
#define OBJ_SKELETON			12

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
extern UBYTE tile_cnt;
extern UBYTE tile_pos;
extern UBYTE shake;

//buffer
extern UBYTE buf[4096];

//level
extern const unsigned char *level_data;
extern UBYTE level_pos;
extern UBYTE level_ani;
extern UBYTE level_maj;
extern UBYTE level_min;
extern UBYTE level_len;

//high score
extern UWORD high_score;

//functions
void enter_title();
void enter_level();
void enter_end();

#endif