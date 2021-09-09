#pragma bank 2

#include <gbdk/platform.h>

#include "global.h"
#include "monster.h"

const unsigned char level1_1_data[] =
{
	22,10,OBJ_KNIGHT,	
	33,8,OBJ_BAT,	
	36,9,OBJ_BAT,	
	49,8,OBJ_KNIGHT,	
	68,5,OBJ_AXE,	
	80,11,OBJ_BAT,	
	82,11,OBJ_BAT,	
	87,9,OBJ_UPDOWN_PLATFORM, 
	90,0,OBJ_CRYSTAL,	
	92,0,OBJ_HEART,	
	94,0,OBJ_CRYSTAL,	
	96,7,OBJ_KNIGHT,	
	101,9,OBJ_UPDOWN_PLATFORM, 
	116,7,OBJ_REAPER, 
	125,7,OBJ_UPDOWN_PLATFORM, 
	139,5,OBJ_KNIGHT,	
	154,0,OBJ_CRYSTAL,	
	156,0,OBJ_MACE, 
	163,6,OBJ_BAT,	
	166,7,OBJ_BAT,	
	185,9,OBJ_REAPER, 
	193,6,OBJ_BAT,	
	194,8,OBJ_BAT,	
	196,9,OBJ_BAT,
	207,6,OBJ_BAT,
	210,7,OBJ_BAT,
	228,10,OBJ_KNIGHT,	
	238,7,OBJ_BAT,
	240,9,OBJ_BAT,		
	0
};

const unsigned char level1_2_data[] =
{
	27,10,OBJ_KNIGHT,
	36,6,OBJ_BAT,
	38,7,OBJ_BAT,
	57,12,OBJ_KNIGHT,
	57,3,OBJ_BAT,
	61,3,OBJ_BAT,
	70,5,OBJ_SWORD,
	72,5,OBJ_HEART,
	81,9,OBJ_UPDOWN_PLATFORM,
	89,6,OBJ_BAT,
	92,5,OBJ_BAT,
	97,9,OBJ_UPDOWN_PLATFORM,
	105,7,OBJ_KNIGHT,
	113,9,OBJ_UPDOWN_PLATFORM,
	123,13,OBJ_HEART,
	124,6,OBJ_BAT,
	125,13,OBJ_CRYSTAL,
	127,6,OBJ_BAT,
	142,12,OBJ_KNIGHT,
	148,3,OBJ_REAPER,
	152,5,OBJ_CRYSTAL,
	154,5,OBJ_CRYSTAL,
	156,5,OBJ_CRYSTAL,
	175,7,OBJ_BAT,
	178,6,OBJ_BAT,
	186,12,OBJ_KNIGHT,
	204,4,OBJ_KNIGHT,
	213,11,OBJ_BAT,
	216,11,OBJ_BAT,
	217,5,OBJ_AXE,
	241,6,OBJ_REAPER,
	0
};

const unsigned char level1_3_data[] =
{
	22,8,OBJ_KNIGHT,
	27,10,OBJ_UPDOWN_PLATFORM,
	28,5,OBJ_BAT,
	30,7,OBJ_BAT,
	33,9,OBJ_CRYSTAL,
	35,9,OBJ_SWORD,
	42,10,OBJ_KNIGHT,
	52,6,OBJ_BAT,
	54,8,OBJ_BAT,
	61,6,OBJ_UPDOWN_PLATFORM,
	73,4,OBJ_KNIGHT,
	92,6,OBJ_UPDOWN_PLATFORM,
	97,3,OBJ_REAPER,
	115,7,OBJ_BAT,
	116,5,OBJ_BAT,
	131,10,OBJ_KNIGHT,
	135,10,OBJ_KNIGHT,
	146,10,OBJ_UPDOWN_PLATFORM,
	151,0,OBJ_CRYSTAL,
	151,10,OBJ_UPDOWN_PLATFORM,
	153,0,OBJ_HEART,
	155,0,OBJ_CRYSTAL,
	156,10,OBJ_UPDOWN_PLATFORM,
	163,9,OBJ_AXE,
	170,7,OBJ_BAT,
	173,7,OBJ_BAT,
	187,6,OBJ_REAPER,
	205,3,OBJ_KNIGHT,
	212,11,OBJ_BAT,
	214,3,OBJ_KNIGHT,
	215,10,OBJ_BAT,
	221,4,OBJ_MACE,
	241,8,OBJ_REAPER,
	0
};

const unsigned char level2_1_data[] =
{
	22,10,OBJ_KNIGHT,
	26,10,OBJ_KNIGHT,
	36,2,OBJ_SPIDER,
	51,8,OBJ_BAT,
	54,9,OBJ_BAT,
	64,8,OBJ_BAT,
	67,9,OBJ_BAT,
	79,8,OBJ_REAPER,
	83,6,OBJ_UPDOWN_PLATFORM,
	94,4,OBJ_KNIGHT,
	97,12,OBJ_KNIGHT,
	101,6,OBJ_FALLING_PLATFORM,
	107,5,OBJ_SWORD,
	109,5,OBJ_HEART,
	122,4,OBJ_SPIDER,
	128,4,OBJ_SPIDER,
	134,4,OBJ_SPIDER,
	150,12,OBJ_KNIGHT,
	150,5,OBJ_CRYSTAL,
	152,5,OBJ_AXE,
	154,5,OBJ_CRYSTAL,
	171,10,OBJ_UPDOWN_PLATFORM,
	176,10,OBJ_UPDOWN_PLATFORM,
	181,7,OBJ_REAPER,
	185,2,OBJ_SPIDER,
	192,10,OBJ_UPDOWN_PLATFORM,
	200,0,OBJ_CRYSTAL,
	202,0,OBJ_HEART,
	203,7,OBJ_BAT,
	206,7,OBJ_BAT,
	224,12,OBJ_KNIGHT,
	228,12,OBJ_KNIGHT,
	229,3,OBJ_REAPER,
	243,4,OBJ_SPIDER,
	0
};

const unsigned char level2_2_data[] =
{
	22,6,OBJ_BAT,
	25,6,OBJ_BAT,
	36,10,OBJ_KNIGHT,
	44,2,OBJ_SPIDER,
	54,2,OBJ_SPIDER,
	63,11,OBJ_SWORD,
	65,11,OBJ_CRYSTAL,
	70,6,OBJ_UPDOWN_PLATFORM,
	85,12,OBJ_KNIGHT,
	87,6,OBJ_FALLING_PLATFORM,
	92,6,OBJ_FALLING_PLATFORM,
	100,4,OBJ_KNIGHT,
	110,11,OBJ_BAT,
	112,3,OBJ_CRYSTAL,
	113,11,OBJ_BAT,
	114,3,OBJ_MACE,
	116,3,OBJ_HEART,
	128,8,OBJ_KNIGHT,
	136,2,OBJ_SPIDER,
	148,7,OBJ_REAPER,
	160,7,OBJ_BAT,
	163,7,OBJ_BAT,
	165,12,OBJ_FALLING_PLATFORM,
	170,12,OBJ_FALLING_PLATFORM,
	177,2,OBJ_SPIDER,
	184,12,OBJ_FALLING_PLATFORM,
	189,12,OBJ_FALLING_PLATFORM,
	207,8,OBJ_REAPER,
	214,4,OBJ_SPIDER,
	229,9,OBJ_CRYSTAL,
	231,9,OBJ_AXE,
	239,10,OBJ_KNIGHT,
	0
};

const unsigned char level2_3_data[] =
{
	22,9,OBJ_BAT,
	25,9,OBJ_BAT,
	32,12,OBJ_FALLING_PLATFORM,
	39,2,OBJ_SPIDER,
	43,2,OBJ_SPIDER,
	50,12,OBJ_FALLING_PLATFORM,
	71,9,OBJ_REAPER,
	76,10,OBJ_KNIGHT,
	84,4,OBJ_SPIDER,
	88,4,OBJ_SPIDER,
	106,5,OBJ_BAT,
	109,4,OBJ_BAT,
	123,6,OBJ_KNIGHT,
	137,10,OBJ_KNIGHT,
	141,0,OBJ_CRYSTAL,
	143,0,OBJ_HEART,
	145,0,OBJ_MACE,
	147,4,OBJ_SPIDER,
	169,9,OBJ_REAPER,
	179,12,OBJ_FALLING_PLATFORM,
	189,10,OBJ_KNIGHT,
	195,12,OBJ_FALLING_PLATFORM,
	206,9,OBJ_BAT,
	208,7,OBJ_BAT,
	221,4,OBJ_SPIDER,
	229,4,OBJ_SPIDER,
	237,4,OBJ_SPIDER,
	0
};

const unsigned char level3_1_data[] =
{
	31,4,OBJ_BAT,
	33,3,OBJ_BAT,
	43,10,OBJ_KNIGHT,
	57,4,OBJ_REAPER,
	63,8,OBJ_LEFTRIGHT_PLATFORM,		
	76,6,OBJ_SKELETON,
	83,11,OBJ_SWORD,
	85,11,OBJ_CRYSTAL,
	95,2,OBJ_SPIDER,
	99,2,OBJ_SPIDER,
	113,7,OBJ_REAPER,
	122,13,OBJ_CRYSTAL,
	124,13,OBJ_HEART,
	126,13,OBJ_MACE,
	129,4,OBJ_SKELETON,
	151,7,OBJ_REAPER,
	155,2,OBJ_SPIDER,
	164,10,OBJ_SKELETON,
	178,4,OBJ_BAT,
	181,4,OBJ_BAT,
	191,8,OBJ_LEFTRIGHT_PLATFORM,
	200,6,OBJ_SKELETON,
	206,8,OBJ_UPDOWN_PLATFORM,
	219,4,OBJ_REAPER,
	226,0,OBJ_CRYSTAL,
	228,0,OBJ_HEART,
	230,0,OBJ_CRYSTAL,
	230,6,OBJ_BAT,
	232,8,OBJ_BAT,
	234,7,OBJ_BAT,
	248,12,OBJ_KNIGHT,	
	0
};

const unsigned char level3_2_data[] =
{
	22,8,OBJ_BAT,
	25,9,OBJ_BAT,
	26,7,OBJ_BAT,
	34,8,OBJ_UPDOWN_PLATFORM,
	43,6,OBJ_KNIGHT,
	50,8,OBJ_UPDOWN_PLATFORM,
	58,4,OBJ_SPIDER,
	69,8,OBJ_SKELETON,
	89,4,OBJ_REAPER,
	98,8,OBJ_LEFTRIGHT_PLATFORM,
	110,4,OBJ_BAT,
	113,5,OBJ_BAT,
	118,10,OBJ_SKELETON,
	121,0,OBJ_HEART,
	122,4,OBJ_SPIDER,
	123,0,OBJ_CRYSTAL,
	132,9,OBJ_AXE,
	134,9,OBJ_CRYSTAL,
	141,7,OBJ_REAPER,
	150,2,OBJ_SPIDER,
	160,10,OBJ_KNIGHT,
	171,6,OBJ_SKELETON,
	176,8,OBJ_FALLING_PLATFORM,
	187,4,OBJ_REAPER,
	192,2,OBJ_SPIDER,
	214,8,OBJ_LEFTRIGHT_PLATFORM,
	223,13,OBJ_HEART,
	225,13,OBJ_CRYSTAL,
	229,5,OBJ_BAT,
	231,3,OBJ_BAT,
	234,4,OBJ_BAT,
	0
};

const unsigned char level3_3_data[] =
{
	25,2,OBJ_SPIDER,
	35,6,OBJ_UPDOWN_PLATFORM,
	40,12,OBJ_KNIGHT,
	51,3,OBJ_BAT,
	53,12,OBJ_SKELETON,
	54,3,OBJ_BAT,
	60,6,OBJ_FALLING_PLATFORM,
	65,6,OBJ_FALLING_PLATFORM,
	70,6,OBJ_FALLING_PLATFORM,
	75,11,OBJ_BAT,
	76,5,OBJ_CRYSTAL,
	78,5,OBJ_MACE,
	78,11,OBJ_BAT,
	95,8,OBJ_KNIGHT,
	101,7,OBJ_REAPER,
	110,4,OBJ_SPIDER,
	118,4,OBJ_SPIDER,
	129,8,OBJ_REAPER,
	136,6,OBJ_SKELETON,
	144,8,OBJ_LEFTRIGHT_PLATFORM,
	153,8,OBJ_LEFTRIGHT_PLATFORM,
	177,11,OBJ_REAPER,
	179,5,OBJ_CRYSTAL,
	181,5,OBJ_AXE,
	183,5,OBJ_CRYSTAL,
	199,10,OBJ_SKELETON,
	202,0,OBJ_HEART,
	204,0,OBJ_CRYSTAL,
	204,7,OBJ_BAT,
	207,7,OBJ_BAT,
	222,10,OBJ_LEFTRIGHT_PLATFORM,
	227,7,OBJ_BAT,
	229,6,OBJ_BAT,
	234,8,OBJ_SKELETON,
	241,2,OBJ_SPIDER,
	0
};

//monster
UBYTE monster_act[MAX_MONSTER];
UBYTE monster_x[MAX_MONSTER];
UBYTE monster_y[MAX_MONSTER];
UBYTE monster_spr0[MAX_MONSTER];
UBYTE monster_spr1[MAX_MONSTER];
UBYTE monster_typ[MAX_MONSTER];
BYTE monster_dir[MAX_MONSTER];
UBYTE monster_ani[MAX_MONSTER];
UBYTE monster_dmg[MAX_MONSTER];
UBYTE monster_lif[MAX_MONSTER];
UBYTE monster_cnt[MAX_MONSTER];
UBYTE monster_pos[MAX_MONSTER];

//monster shot
UBYTE monster_shot_act[MAX_MONSTER_SHOT];
UBYTE monster_shot_x[MAX_MONSTER_SHOT];
UBYTE monster_shot_y[MAX_MONSTER_SHOT];
UBYTE monster_shot_spr[MAX_MONSTER_SHOT];
BYTE monster_shot_dir[MAX_MONSTER_SHOT];

void new_monster(UBYTE x, UBYTE y, UBYTE type) BANKED
{
	UBYTE i;
	
	for( i = 0; i != MAX_MONSTER; i++ )
	{
		if( monster_act[i] == FALSE )
		{
			monster_act[i] = TRUE;
			monster_x[i] = x;
			monster_y[i] = y; 
			monster_spr0[i] = get_sprite();
			monster_spr1[i] = get_sprite();
			switch( type )
			{
				case MT_KNIGHT: 
					monster_lif[i] = 16;
					monster_dir[i] = -1;
					break;
				case MT_BAT:
					monster_lif[i] = 3;
					monster_pos[i] = y - 8;
					break;	
				case MT_REAPER: 
					monster_lif[i] = 12;
					monster_pos[i] = y - 8;
					monster_cnt[i] = (rand() & 3) + 2;
					monster_cnt[i] = monster_cnt[i] << 5;
					break;
				case MT_SPIDER:
					monster_lif[i] = 8;
					monster_dir[i] = 0;
					monster_cnt[i] = y;
					break;
				case MT_SKELETON:
					monster_lif[i] = 10;
					monster_dir[i] = -1;
					monster_cnt[i] = 0;
					break;
			}
			monster_typ[i] = type;
			monster_ani[i] = 0;
			monster_dmg[i] = 0;
			break;
		}
	}
}

void new_monster_shot(UBYTE x, UBYTE y) BANKED
{
	UBYTE i;
	
	for( i = 0; i != MAX_MONSTER_SHOT; i++ )
	{
		if( monster_shot_act[i] == FALSE )
		{
			monster_shot_act[i] = TRUE;
			monster_shot_x[i] = x; 
			monster_shot_y[i] = y; 
			monster_shot_spr[i] = get_sprite();
			set_sprite_tile(monster_shot_spr[i],ST_MONSTER_SHOT);
			if(player_x < x )
			{
				monster_shot_dir[i] = -2;
			} else {
				monster_shot_dir[i] = 2;
			}
			break;
		}
	}	
}

void update_monster_shot() BANKED
{
	UBYTE tile_x,tile_y;
	UBYTE tile;
	UWORD pos;
	UBYTE i;
	
	//monster shot
	for( i = 0; i != MAX_MONSTER_SHOT; i++ )
	{
		if( monster_shot_act[i] == TRUE )
		{
			monster_shot_x[i] += -scroll;
			monster_shot_x[i] += monster_shot_dir[i];
			
			tile_x = ((monster_shot_x[i] + 4 + scroll_pos) >> 3) - 1;
			tile_y = ((monster_shot_y[i] + 3) >> 3) - 2;
			pos = (tile_x << 4) + tile_y;
			tile = buf[pos];
			
			if( (monster_shot_x[i] > 168) || (tile >= 16) )
			{
				monster_shot_act[i] = FALSE;
				clear_sprite(monster_shot_spr[i]);
			} else {
				if(((monster_shot_x[i] + 3) >= player_x) && (monster_shot_x[i] <= (player_x + 10)))
				{
					if(((monster_shot_y[i] + 2) >= player_y) && (monster_shot_y[i] <= (player_y + 11)))
					{
						if( player_dmg == 0 )
						{
							player_dmg = 64;
				
							player_lif--;
							update_hud(HUD_LIFE);
							
							if( player_lif != 0 )
							{
								set_sound(SND_DAMAGE);
							} else {
								set_sound(SND_DEAD);
							}
						}
						
						monster_shot_act[i] = FALSE;
						clear_sprite(monster_shot_spr[i]);
						break;
					}
				}
			}
		}
	}	
}

void update_knight( UBYTE i )
{
	UBYTE tile_x;
	UBYTE tile_y1,tile_y2;
	UWORD pos1,pos2;
	UBYTE tile1, tile2;
	
	if( (monster_ani[i] & 7) == 0 )
	{
		if( monster_dir[i] == 1 )
		{
			if( monster_x[i] > 176 )
			{
				monster_x[i] += monster_dir[i];
			} else {
				tile_x = ((monster_x[i] + 11 + scroll_pos) >> 3) - 1;
				tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
				tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
			
				pos1 = (tile_x << 4) + tile_y1;
				pos2 = (tile_x << 4) + tile_y2;
			
				tile1 = buf[pos1];
				tile2 = buf[pos2];
			
				if( (tile1 < 16) || (tile2 >= 16) )
				{
					monster_dir[i] = -1;
				} 
				monster_x[i] += monster_dir[i];
			}
		} else {
			if( monster_x[i] > 176 )
			{
				monster_x[i] += monster_dir[i];
			} else {
				tile_x = ((monster_x[i] + 4 + scroll_pos) >> 3) - 1;
				tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
				tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
				
				pos1 = (tile_x << 4) + tile_y1;
				pos2 = (tile_x << 4) + tile_y2;
				
				tile1 = buf[pos1];
				tile2 = buf[pos2];
				
				if( (tile1 < 16) || (tile2 >= 16) )
				{
					monster_dir[i] = 1;
				} 
				monster_x[i] += monster_dir[i];
			}
		}
	}	

	if( monster_dir[i] == 1 )
	{
		set_sprite_prop(monster_spr0[i],0);
		set_sprite_prop(monster_spr1[i],0);
		if( monster_ani[i] & 16 )
		{
			set_sprite_tile(monster_spr0[i],ST_KNIGHT0);
			set_sprite_tile(monster_spr1[i],ST_KNIGHT1);
		} else {
			set_sprite_tile(monster_spr0[i],ST_KNIGHT2);
			set_sprite_tile(monster_spr1[i],ST_KNIGHT3);
		}
	} else {
		set_sprite_prop(monster_spr0[i],S_FLIPX);
		set_sprite_prop(monster_spr1[i],S_FLIPX);
		if( monster_ani[i] & 16 )
		{
			set_sprite_tile(monster_spr0[i],ST_KNIGHT1);
			set_sprite_tile(monster_spr1[i],ST_KNIGHT0);
		} else {
			set_sprite_tile(monster_spr0[i],ST_KNIGHT3);
			set_sprite_tile(monster_spr1[i],ST_KNIGHT2);
		}
	}
}

void update_bat( UBYTE i )
{	
	if( (monster_ani[i] & 15) == 0 )
	{
		monster_dir[i] = rand() & 7;
		if( monster_x[i] > 152 )
		{
			monster_dir[i] = 0;
		}
		if( monster_y[i] == monster_pos[i] )
		{
			monster_dir[i] = 7;
		}
		if( monster_y[i] == (monster_pos[i] + 16) )
		{
			monster_dir[i] = 1;
		}
	}
	
	if( (monster_ani[i] & 1) == 0 )
	{
		switch( monster_dir[i] )
		{
			case 0:
				monster_x[i]--;
				break;
			case 1:
				monster_x[i]--;
				monster_y[i]--;
				break;
			case 2:
				monster_y[i]--;
				break;
			case 3:
				monster_x[i]++;
				monster_y[i]--;
				break;
			case 4:
				monster_x[i]++;
				break;
			case 5:
				monster_x[i]++;
				monster_y[i]++;
				break;
			case 6:
				monster_y[i]++;
				break;
			case 7:
				monster_x[i]--;
				monster_y[i]++;
				break;
		}
	}
	
	if( monster_ani[i] & 8 )
	{
		set_sprite_tile(monster_spr0[i],ST_BAT0);
		set_sprite_tile(monster_spr1[i],ST_BAT1);
	} else {
		set_sprite_tile(monster_spr0[i],ST_BAT2);
		set_sprite_tile(monster_spr1[i],ST_BAT3);
	}
}

void update_reaper( UBYTE i )
{
	if( (monster_ani[i] & 15) == 0 )
	{
		monster_dir[i] = rand() & 7;
		if( monster_x[i] > 152 )
		{
			monster_dir[i] = 0;
		}
		if( monster_y[i] == monster_pos[i] )
		{
			monster_dir[i] = 3;
		}
		if( monster_y[i] == (monster_pos[i] + 16) )
		{
			monster_dir[i] = 0;
		}
	}
	
	if( (monster_ani[i] & 1) == 0 )
	{
		switch( monster_dir[i] )
		{
			case 0:
				monster_x[i]--;
				monster_y[i]--;
				break;
			case 1:
				monster_x[i]++;
				monster_y[i]--;
				break;
			case 2:
				monster_x[i]++;
				monster_y[i]++;
				break;
			case 3:
				monster_x[i]--;
				monster_y[i]++;
				break;
		}
	}
	
	if( monster_cnt[i] != 0 )
	{
		monster_cnt[i]--;
	} else {
		new_monster_shot( monster_x[i] + 4, monster_y[i] + 6);
		monster_cnt[i] = (rand() & 3) + 2;
		monster_cnt[i] = monster_cnt[i] << 5;
	}	
	
	if( monster_ani[i] & 8 )
	{
		set_sprite_tile(monster_spr0[i],ST_DEAMON0);
		set_sprite_tile(monster_spr1[i],ST_DEAMON1);
	} else {
		set_sprite_tile(monster_spr0[i],ST_DEAMON2);
		set_sprite_tile(monster_spr1[i],ST_DEAMON3);
	}
}

void update_spider( UBYTE i )
{
	UBYTE tile_x,tile_y;
	UBYTE tile;
	UWORD pos;
	
	if( ((player_x + 16) >= monster_x[i]) && (player_x <= (monster_x[i] + 16)) )
	{
		if( monster_dir[i] == 0 )
		{
			monster_dir[i] = 2;
		}
	}
	
	if( monster_dir[i] == 2 )
	{
		monster_y[i] += monster_dir[i];
		
		tile_x = ((monster_x[i] + 4 + scroll_pos) >> 3) - 1;
		tile_y = ((monster_y[i] + 16) >> 3) - 2;
		pos = (tile_x << 4) + tile_y;
		tile = buf[pos];
		if( tile >= 16 )
		{
			monster_dir[i] = -1;
		}	
	} else {
		if( (monster_ani[i] & 1) == 0 )
		{
			monster_y[i] += monster_dir[i];
		}
		
		if( monster_y[i] == monster_cnt[i] )
		{
			monster_dir[i] = 0;
		}
	}
	
	if( monster_ani[i] & 16 )
	{
		set_sprite_tile(monster_spr0[i],ST_SPIDER0);
		set_sprite_tile(monster_spr1[i],ST_SPIDER1);
	} else {
		set_sprite_tile(monster_spr0[i],ST_SPIDER2);
		set_sprite_tile(monster_spr1[i],ST_SPIDER3);
	}
}

void update_skeleton( UBYTE i )
{
	UBYTE tile_x;
	UBYTE tile_y1,tile_y2;
	UWORD pos1,pos2;
	UBYTE tile1, tile2;
		
	if( monster_cnt[i] == 0 )
	{
		if( (monster_ani[i] & 7) == 0 )
		{
			if( monster_dir[i] == 1 )
			{
				if( monster_x[i] > 176 )
				{
					monster_x[i] += monster_dir[i];
				} else {
					tile_x = ((monster_x[i] + 11 + scroll_pos) >> 3) - 1;
					tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
					tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
				
					pos1 = (tile_x << 4) + tile_y1;
					pos2 = (tile_x << 4) + tile_y2;
				
					tile1 = buf[pos1];
					tile2 = buf[pos2];
				
					if( (tile1 < 16) || (tile2 >= 16) )
					{
						monster_dir[i] = -1;
					} 
					monster_x[i] += monster_dir[i];
				}
			} else {
				if( monster_x[i] > 176 )
				{
					monster_x[i] += monster_dir[i];
				} else {
					tile_x = ((monster_x[i] + 4 + scroll_pos) >> 3) - 1;
					tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
					tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
					
					pos1 = (tile_x << 4) + tile_y1;
					pos2 = (tile_x << 4) + tile_y2;
					
					tile1 = buf[pos1];
					tile2 = buf[pos2];
					
					if( (tile1 < 16) || (tile2 >= 16) )
					{
						monster_dir[i] = 1;
					} 
					monster_x[i] += monster_dir[i];
				}
			}
		}
		
		if( monster_dir[i] == 1 )
		{
			set_sprite_prop(monster_spr0[i],0);
			set_sprite_prop(monster_spr1[i],0);
			if( monster_ani[i] & 16 )
			{
				set_sprite_tile(monster_spr0[i],ST_SKELETON0);
				set_sprite_tile(monster_spr1[i],ST_SKELETON1);
			} else {
				set_sprite_tile(monster_spr0[i],ST_SKELETON2);
				set_sprite_tile(monster_spr1[i],ST_SKELETON3);
			}
		} else {
			set_sprite_prop(monster_spr0[i],S_FLIPX);
			set_sprite_prop(monster_spr1[i],S_FLIPX);
			if( monster_ani[i] & 16 )
			{
				set_sprite_tile(monster_spr0[i],ST_SKELETON1);
				set_sprite_tile(monster_spr1[i],ST_SKELETON0);
			} else {
				set_sprite_tile(monster_spr0[i],ST_SKELETON3);
				set_sprite_tile(monster_spr1[i],ST_SKELETON2);
			}
		}
	} else {
		if( monster_dir[i] == 1 )
		{
			set_sprite_prop(monster_spr0[i],0);
			set_sprite_prop(monster_spr1[i],0);
			if( (monster_cnt[i] == 128) || (monster_cnt[i] == 6) )
			{
				set_sprite_tile(monster_spr0[i],ST_SKELETON4);
				set_sprite_tile(monster_spr1[i],ST_SKELETON5);
			} 
			if( monster_cnt[i] == 122 )
			{	
				set_sprite_tile(monster_spr0[i],ST_SKELETON6);
				set_sprite_tile(monster_spr1[i],ST_SKELETON7);
			}
		} else {
			set_sprite_prop(monster_spr0[i],S_FLIPX);
			set_sprite_prop(monster_spr1[i],S_FLIPX);
			if( (monster_cnt[i] == 128) || (monster_cnt[i] == 6) )
			{
				set_sprite_tile(monster_spr0[i],ST_SKELETON5);
				set_sprite_tile(monster_spr1[i],ST_SKELETON4);
			} 
			if( monster_cnt[i] == 122 )
			{	
				set_sprite_tile(monster_spr0[i],ST_SKELETON7);
				set_sprite_tile(monster_spr1[i],ST_SKELETON6);
			}
		}
		monster_lif[i] = 8;
		monster_cnt[i]--;
	}
}

void update_monster() BANKED
{
	UBYTE i,j;
	UBYTE dmg;
	
	//monster
	for( i = 0; i != MAX_MONSTER; i++ )
	{
		if( monster_act[i] == TRUE )
		{
			monster_x[i] += -scroll;
						
			switch( monster_typ[i] )
			{
				case MT_KNIGHT:
					update_knight(i);
					break;
				case MT_BAT:
					update_bat(i);
					break;
				case MT_REAPER:
					update_reaper(i);
					break;
				case MT_SPIDER:
					update_spider(i);
					break;
				case MT_SKELETON:
					update_skeleton(i);
					break;
			}
			
			if( (monster_typ[i] != MT_SKELETON) || (monster_cnt[i] == 0) )
			{
				if(((player_x + 10) >= monster_x[i]) && (player_x <= (monster_x[i] + 10)))
				{
					if(((player_y + 11) >= monster_y[i]) && (player_y <= (monster_y[i] + 11)))
					{
						if( player_dmg == 0 )
						{
							player_dmg = 64;
				
							player_lif--;
							update_hud(HUD_LIFE);
							
							if( player_lif != 0 )
							{
								set_sound(SND_DAMAGE);
							} else {
								set_sound(SND_DEAD);
							}
						}
					}
				}
			
				for( j = 0; j != MAX_PLAYER_SHOT; j++ )
				{
					if( player_shot_act[j] == TRUE )
					{
						if(((player_shot_x[j] + 3) >= monster_x[i]) && (player_shot_x[j] <= (monster_x[i] + 10)))
						{
							if(((player_shot_y[j] + 2) >= monster_y[i]) && (player_shot_y[j] <= (monster_y[i] + 11)))
							{
								//dmg = player_shot_typ[i] + 2;
								if( player_shot_typ[i] == PST_MACE )
								{
									dmg = 4;
								} else {
									dmg = 3;
								}
																
								if( monster_lif[i] > dmg )
								{
									monster_lif[i] -= dmg;
									monster_dmg[i] = 3;
									set_sound(SND_HIT);
								} else {
									if( monster_typ[i] != MT_SKELETON )
									{
										new_explosion( monster_x[i],monster_y[i] );
										monster_act[i] = FALSE;
										clear_sprite(monster_spr0[i]);
										clear_sprite(monster_spr1[i]);
										
										switch( monster_typ[i] )
										{
											case MT_KNIGHT:
												add_score(2);
												break;
											case MT_REAPER:
												add_score(4);
												break;
											case MT_SPIDER:
												add_score(3);
												break;
											default:
												add_score(1);
												break;
										}
									} else {
										monster_cnt[i] = 128;
										set_sound(SND_BREAK);
									}
								}
								
								player_shot_act[j] = FALSE;
								clear_sprite(player_shot_spr[j]);
								break;
							}
						}
					}
				}
			}
			
			monster_ani[i]++;
			
			if( monster_dmg[i] != 0 )
			{
				monster_dmg[i]--;
			}
			
			if( (monster_x[i] <= 240) && (monster_x[i] >= 184))
			{
				monster_act[i] = 0;
				clear_sprite( monster_spr0[i] );
				clear_sprite( monster_spr1[i] );
			}
		}
	}
}