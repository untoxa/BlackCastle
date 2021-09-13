#include <gbdk/platform.h>

#include "global.h"

//game state
UBYTE game_state;

//input
UBYTE input = 0;
UBYTE old_input;

//bank
UBYTE bank = 1;
UBYTE old_bank;

//background
BYTE scroll;
UWORD scroll_pos;
UBYTE tile_cnt;
UBYTE tile_pos;
UBYTE shake;

//buffer
UBYTE buf[4096];

//level
const unsigned char *level_data;
UBYTE level_pos;
UBYTE level_ani;
UBYTE level_maj;
UBYTE level_min;
UBYTE level_len;

//game over
UBYTE game_over_spr0;
UBYTE game_over_spr1;
UBYTE game_over_spr2;
UBYTE game_over_spr3;

//high score
UWORD high_score;

void init_title()
{
	UBYTE i,j;
	UWORD w;
	
	SET_BANK(1);
	
	clear_all();
	fill_bkg_rect(DEVICE_SCREEN_X_OFFSET, DEVICE_SCREEN_Y_OFFSET, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);
	
	sound_cnt_ch1 = 0;
	sound_cnt_ch4 = 0;
	
	//player
	player_sht = PST_SWORD;
	//player_sht = PST_AXE;
	//player_sht = PST_MACE;
	player_lif = 4;
	player_score = 0;
	
	//level
	level_maj = 1;
	level_min = 1;
	
	//background
	UNAPACK(title_tiles, buf);
	set_bkg_data(0,177,buf);
	
	UNAPACK(title_map, buf);
	w = 0;
	for( i = 0; i != 20; i++ )
	{
		set_bkg_tiles(VIEWPORT_X_OFS + i,0,1,18,&buf[w]);
		w += 18;
	}
	move_bkg(0,0);
	
	//set high score
	for( i = 0; i != 4; i++ )
	{
		j = (high_score >> (i<<2)) & 0x0F;
		set_bkg_tiles(VIEWPORT_X_OFS + 10-i,17,1,1,&title_numbers[j]);	
	}
	
}

void enter_title()
{
	UBYTE i;
	
	init_title();
	
	set_music(TITLE_MUSIC);
	
	SHOW_BKG;
	DISPLAY_ON;
	
	fade_from_white();
	
	while( game_state == GS_TITLE )
	{
		UPDATE_KEYS();	
		
		if( KEY_TICKED(J_START) )
		{
			stop_music();
			set_sound(SND_START);
			
			for( i = 0; i != 4; i++ )
			{
				play_sound();
				wait_vbl_done();
			}
			
			fade_to_white();
			DISPLAY_OFF;
			game_state = GS_LEVEL;
		}
		
		play_music();
		wait_vbl_done();
	}	
}

void init_level()
{
	UBYTE i;
	UWORD w;
	
	SET_BANK(1);

	fill_bkg_rect(DEVICE_SCREEN_X_OFFSET, DEVICE_SCREEN_Y_OFFSET, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);

	//sprites
	UNAPACK(sprite_tiles, buf);
#ifdef SEGA
	set_2bpp_palette(COMPAT_PALETTE(0,1,4,3));
#endif
	set_sprite_data(0,ST_LAST,buf);
	
	clear_all();
	
	//player
	player_x = 32;
	player_y = 112;
	player_ani = 0;
	player_dir = 1;
	player_vel = 0;
	player_jmp = 0;
	player_att = 0;
	player_dmg = 0;
	player_prp = 0;
	
	player_spr0 = get_sprite();
	player_spr1 = get_sprite();
	
	set_sprite_tile(player_spr0,ST_PLAYER_IDLE0);
	set_sprite_tile(player_spr1,ST_PLAYER_IDLE1);
	
	move_sprite(player_spr0,	SPRITE_OFS_X + player_x,	SPRITE_OFS_Y + player_y+16);
	move_sprite(player_spr1,	SPRITE_OFS_X + player_x+8,	SPRITE_OFS_Y + player_y+16);
	
	//hud
	UNAPACK(hud_tiles,buf);
#ifdef SEGA
	set_2bpp_palette(COMPAT_PALETTE(0,1,2,3));
#endif
	set_bkg_data(32,51,buf);
	w = 0;
	for( i = 0; i != 20; i++ )
	{
		set_bkg_tiles(VIEWPORT_X_OFS + i,0,1,2,&hud_map[w]);
		w += 2;
	}
	update_hud(HUD_LIFE);
	update_hud(HUD_SCORE);
	update_hud(HUD_WEAPON);
	update_hud(HUD_LEVEL);
	
	//set level data
	if( level_maj == 1 )
	{
		UNAPACK(level1_tiles, buf);
		set_bkg_data(0,32,buf);
		
		switch( level_min )
		{
			case 1:
				UNAPACK(level1_1_map, buf);
				level_data = level1_1_data;
				level_len = 236;
				
				set_music(LEVEL1_MUSIC);
				break;
			case 2:
				//for( w = 0; w != 4096; w++ )
				//{
				//	buf[w] = level1_2_map[w];
				//}
				UNAPACK(level1_2_map, buf);
				level_data = level1_2_data;
				level_len = 236;
				
				set_music(LEVEL1_MUSIC);
				break;
			case 3:
				UNAPACK(level1_3_map, buf);
				level_data = level1_3_data;
				level_len = 236;
				
				set_music(LEVEL1_MUSIC);
				break;
			case 4:
				UNAPACK(level1_4_map, buf);
				level_data = 0;
				level_len = 0;
				
				new_boss(76,72,BT_BAT);
			
				set_music(BOSS_MUSIC);
				break;	
		}	
	}
	else if( level_maj == 2 )
	{
		UNAPACK(level2_tiles, buf);
		set_bkg_data(0,32,buf);
		switch( level_min )
		{
			case 1:
				UNAPACK(level2_1_map, buf);
				level_data = level2_1_data;
				level_len = 236;
			
				set_music(LEVEL2_MUSIC);
				break;
			case 2:
				UNAPACK(level2_2_map, buf);
				level_data = level2_2_data;
				level_len = 236;
				
				set_music(LEVEL2_MUSIC);
				break;
			case 3:
				UNAPACK(level2_3_map, buf);
				level_data = level2_3_data;
				level_len = 236;
				
				set_music(LEVEL2_MUSIC);
				break;
			case 4:
				UNAPACK(level2_4_map, buf);
				level_data = 0;
				level_len = 0;
			
				new_boss(76,105,BT_MINOTAUR);
				
				set_music(BOSS_MUSIC);
				break;
			
		}
	}
	else if( level_maj == 3 )
	{
		SET_BANK(3);
		UNAPACK(level3_tiles, buf);
		set_bkg_data(0,32,buf);
		
		switch( level_min )
		{
			case 1:
				UNAPACK(level3_1_map, buf);
				level_data = level3_1_data;
				level_len = 236;
				
				set_music(LEVEL3_MUSIC);
				break;
			case 2:
				UNAPACK(level3_2_map, buf);
				level_data = level3_2_data;
				level_len = 236;
				
				set_music(LEVEL3_MUSIC);
				break;
			case 3:
				UNAPACK(level3_3_map, buf);
				level_data = level3_3_data;
				level_len = 236;
				
				set_music(LEVEL3_MUSIC);
				break;
			case 4:
				UNAPACK(level3_4_map, buf);
				level_data = 0;
				level_len = 0;
				
				new_boss(80,76,BT_REAPER);
				
				set_music(BOSS_MUSIC);
				break;
		}
	}
	
	//background
	w = 0;
	for( i = 0; i != 22; i++ )
	{
		set_bkg_tiles(VIEWPORT_X_OFS + i,2,1,16,&buf[w]);
		w += 16;
	}
	move_bkg(0,0);
	scroll_pos = 0;
	scroll = 0;
	tile_cnt = 0;
	tile_pos = 0;
	shake = 0;
	
	//level
	level_pos = 0;
	level_ani = 0;
}

void update_level()
{
	UBYTE i,j,type,y;
	UWORD w;
	
	scroll = 0;
	
	SET_BANK(2);
	update_player();
	update_platform();
	
	update_player_shot();
	update_item();
	update_monster();
	
	update_boss();
	
	update_monster_shot();
	update_explosion();
	update_stone();

	//candel
	level_ani++;
	if( (level_ani & 8) == 0 )
	{
		set_bkg_data(13,1,candle_tiles);
	} else {
		set_bkg_data(13,1,candle_tiles + 16);
	}
	
	//update level
	if( scroll != 0 )
	{
		scroll_pos += scroll;
		tile_cnt += scroll;
		if( (tile_cnt & 8) == 8 )
		{
			tile_cnt -= 8;
			tile_pos++;
			i = (tile_pos + 21) & 31;
			w = (tile_pos + 21) << 4;
			
			if(	 tile_pos < 235 )
			{	
				set_bkg_tiles(VIEWPORT_X_OFS + i,2,1,16,&buf[w]);
			}
#ifdef MASTERSYSTEM
			fill_bkg_rect((tile_pos & 31),2,1,16,0);
#endif
			if( level_min != 4 )
			{
				i = tile_pos + 21;
				j = level_data[level_pos];
				while( i == j )
				{
					y = level_data[++level_pos];
					type = level_data[++level_pos];
					
					switch( type )
					{
						case OBJ_CRYSTAL:
							new_item( 176, (y + 2) << 3, IT_CRYSTAL );
							break;
						case OBJ_HEART: 
							new_item( 176, (y + 2) << 3, IT_HEART );
							break;
						case OBJ_SWORD: 
							new_item( 176, (y + 2) << 3, IT_SWORD );
							break;
						case OBJ_AXE:
							new_item( 176, (y + 2) << 3, IT_AXE );
							break;
						case OBJ_MACE:
							new_item( 176, (y + 2) << 3, IT_MACE );
							break;	
						case OBJ_FALLING_PLATFORM: 
							new_platform( 176, (y + 2) << 3, PT_FALLING_PLATFORM );
							break;
						case OBJ_UPDOWN_PLATFORM:
							new_platform( 176, (y + 2) << 3, PT_UPDOWN_PLATFORM );
							break;
						case OBJ_LEFTRIGHT_PLATFORM:
							new_platform( 176, (y + 2) << 3, PT_LEFTRIGHT_PLATFORM );
							break;
						case OBJ_KNIGHT: 
							new_monster( 176, (y + 2) << 3, MT_KNIGHT );
							break;
						case OBJ_BAT: 
							new_monster( 176, (y + 2) << 3, MT_BAT );
							break;
						case OBJ_REAPER: 
							new_monster( 176, (y + 2) << 3, MT_REAPER );
							break;
						case OBJ_SPIDER: 
							new_monster( 176, (y + 2) << 3, MT_SPIDER );
							break;
						case OBJ_SKELETON: 
							new_monster( 176, (y + 2) << 3, MT_SKELETON );
							break;
					}
					
					j = level_data[++level_pos];
				}
			}
		}
	}
}

void draw_level()
{
	UBYTE i;
	
	//player
	if( (player_dmg & 2) == 0 )
	{
		move_sprite(player_spr0,	SPRITE_OFS_X + player_x,	SPRITE_OFS_Y + player_y + 16);
		move_sprite(player_spr1,	SPRITE_OFS_X + player_x+8,	SPRITE_OFS_Y + player_y + 16);
	} else {
		hide_sprite(player_spr0);
		hide_sprite(player_spr1);		
	}
	if( player_dmg != 0 )
	{
		player_dmg--;
	}
	
	//player shot
	for( i = 0; i != MAX_PLAYER_SHOT; i++ )
	{
		if( player_shot_act[i] == TRUE )
		{
			move_sprite(player_shot_spr[i],	SPRITE_OFS_X + player_shot_x[i],	SPRITE_OFS_Y + player_shot_y[i] + 16);
		}
	}
	
	//item
	for( i = 0; i != MAX_ITEM; i++ )
	{
		if( item_act[i] == TRUE )
		{
			move_sprite(item_spr[i],	SPRITE_OFS_X + item_x[i],	SPRITE_OFS_Y + item_y[i] + 16);
		}
	}
	
	//platform
	for( i = 0; i != MAX_PLATFORM; i++ )
	{
		if( platform_act[i] == TRUE )
		{
			move_sprite(platform_spr0[i],	SPRITE_OFS_X + platform_x[i],	SPRITE_OFS_Y + platform_y[i] + 16);
			move_sprite(platform_spr1[i],	SPRITE_OFS_X + platform_x[i]+8,	SPRITE_OFS_Y + platform_y[i] + 16);
		}
	}
	
	//monster
	for( i = 0; i != MAX_MONSTER; i++ )
	{
		if( monster_act[i] == TRUE )
		{
			if( (monster_dmg[i] & 2) == 0 )
			{
				move_sprite(monster_spr0[i],	SPRITE_OFS_X + monster_x[i],		SPRITE_OFS_Y + monster_y[i] + 16);
				move_sprite(monster_spr1[i],	SPRITE_OFS_X + monster_x[i] + 8,	SPRITE_OFS_Y + monster_y[i] + 16);
			} else {
				hide_sprite(monster_spr0[i]);
				hide_sprite(monster_spr1[i]);
			}
		}
	}
	
	//boss
	if( boss_act == TRUE )
	{
		if( (boss_dmg & 2) == 0 )
		{
			switch( boss_typ )
			{
				case BT_BAT:
					move_sprite(boss_spr0,	SPRITE_OFS_X + boss_x,		SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr1,	SPRITE_OFS_X + boss_x + 8,	SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr2,	SPRITE_OFS_X + boss_x + 16,	SPRITE_OFS_Y + boss_y + 16);
					break;
				case BT_MINOTAUR:
					move_sprite(boss_spr0,	SPRITE_OFS_X + boss_x,		SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr1,	SPRITE_OFS_X + boss_x + 8,	SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr2,	SPRITE_OFS_X + boss_x + 16,	SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr3,	SPRITE_OFS_X + boss_x,		SPRITE_OFS_Y + boss_y + 32);
					move_sprite(boss_spr4,	SPRITE_OFS_X + boss_x + 8,	SPRITE_OFS_Y + boss_y + 32);
					move_sprite(boss_spr5,	SPRITE_OFS_X + boss_x + 16,	SPRITE_OFS_Y + boss_y + 32);
					break;
				case BT_REAPER:
					move_sprite(boss_spr0,	SPRITE_OFS_X + boss_x,		SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr1,	SPRITE_OFS_X + boss_x + 8,	SPRITE_OFS_Y + boss_y + 16);
					move_sprite(boss_spr2,	SPRITE_OFS_X + boss_x,		SPRITE_OFS_Y + boss_y + 32);
					move_sprite(boss_spr3,	SPRITE_OFS_X + boss_x + 8,	SPRITE_OFS_Y + boss_y + 32);
					break;
			}
				
			
		} else {
			switch( boss_typ )
			{
				case BT_BAT:
					hide_sprite(boss_spr0);
					hide_sprite(boss_spr1);
					hide_sprite(boss_spr2);
					break;
				case BT_MINOTAUR:
					hide_sprite(boss_spr0);
					hide_sprite(boss_spr1);
					hide_sprite(boss_spr2);
					hide_sprite(boss_spr3);
					hide_sprite(boss_spr4);
					hide_sprite(boss_spr5);
					break;
				case BT_REAPER:
					hide_sprite(boss_spr0);
					hide_sprite(boss_spr1);
					hide_sprite(boss_spr2);
					hide_sprite(boss_spr3);
					break;
			}
		}
	}
	
	//monster shot
	for( i = 0; i != MAX_MONSTER_SHOT; i++ )
	{
		if( monster_shot_act[i] == TRUE )
		{
			move_sprite(monster_shot_spr[i],	SPRITE_OFS_X + monster_shot_x[i],	SPRITE_OFS_Y + monster_shot_y[i] + 16);
		}
	}
	
	//explosion
	for( i = 0; i != MAX_EXPLOSION; i++ )
	{
		if( explosion_act[i] == TRUE )
		{
			move_sprite(explosion_spr0[i],	SPRITE_OFS_X + explosion_x[i],		SPRITE_OFS_Y + explosion_y[i] + 16);
			move_sprite(explosion_spr1[i],	SPRITE_OFS_X + explosion_x[i]+8,	SPRITE_OFS_Y + explosion_y[i] + 16);
		}
	}
	
	//stone
	for( i = 0; i != MAX_STONE; i++ )
	{
		if( stone_act[i] == TRUE )
		{
			move_sprite(stone_spr[i],	SPRITE_OFS_X + stone_x[i],	SPRITE_OFS_Y + stone_y[i] + 16);
		}
	}
}

void enter_level()
{
	UBYTE i;
	
	initrand(RAND_SOURCE);
	init_level();
	
	//SHOW_SPRITES;
	DISPLAY_ON;
	
	fade_from_white();
	
	while( game_state == GS_LEVEL )
	{
		UPDATE_KEYS();	
		
		update_level();
		draw_level();
		
		play_sound();
		
		play_music();
		
#ifndef MASTERSYSTEM
		//pause
		if(KEY_TICKED(J_START))
		{
			stop_music();
			set_sound(SND_PAUSE);
			do
			{
				UPDATE_KEYS();
				play_sound();
				wait_vbl_done();	
			} while(!KEY_TICKED(J_START));
			restart_music();
		}
#endif
		//next level
		if( (level_min != 4) && (player_x > 160) )
		{
			stop_music();
			fade_to_white();
			DISPLAY_OFF;
			level_min++;
			break;
		}
		
		//boss defeated
		if( (level_min == 4) && (boss_act == FALSE) )
		{
			stop_music();
			for( i = 0; i != 64; i++ )
			{
				wait_vbl_done();
			}
			while( player_lif != 4 )
			{
				player_lif++;
				update_hud(HUD_LIFE);
				set_sound(SND_HEART);
				for( i = 0; i != 24; i++ )
				{
					play_sound();
					wait_vbl_done();
				}
			}
			
			for( i = 0; i != 64; i++ )
			{
				wait_vbl_done();
			}
			
			fade_to_white();
			DISPLAY_OFF;
			level_maj++;
			level_min = 1;
			if( level_maj == 4 )
			{
				game_state = GS_END;
			}
			break;
		}
		
		//game over
		if( player_lif == 0 )
		{
			stop_music();
			player_vel = -20;
			while( player_y < 144 )
			{
				if( player_dir == 1 )
				{
					set_sprite_tile(player_spr0,ST_PLAYER_DROP0);
					set_sprite_tile(player_spr1,ST_PLAYER_DROP1);
				} else {
					set_sprite_tile(player_spr0,ST_PLAYER_DROP1);
					set_sprite_tile(player_spr1,ST_PLAYER_DROP0);
				}
				
				if( player_vel != 25 )
				{
					player_vel++;
				}
				player_y += (player_vel >> 3);
				
				move_sprite(player_spr0,	SPRITE_OFS_X + player_x,	SPRITE_OFS_Y + player_y + 16);
				move_sprite(player_spr1,	SPRITE_OFS_X + player_x+8,	SPRITE_OFS_Y + player_y + 16);
				
				play_sound();
				
				wait_vbl_done();
			}
			
			for( i = 0; i != 64; i++ )
			{
				wait_vbl_done();
			}
			
			clear_all();
			
			//gameover sprite
			game_over_spr0 = get_sprite();
			game_over_spr1 = get_sprite();
			game_over_spr2 = get_sprite();
			game_over_spr3 = get_sprite();
			
			set_sprite_tile(game_over_spr0,ST_GAME_OVER0);
			set_sprite_tile(game_over_spr1,ST_GAME_OVER1);
			set_sprite_tile(game_over_spr2,ST_GAME_OVER2);
			set_sprite_tile(game_over_spr3,ST_GAME_OVER3);
			
			move_sprite(game_over_spr0,	SPRITE_OFS_X + 72,	SPRITE_OFS_Y + 88);
			move_sprite(game_over_spr1,	SPRITE_OFS_X + 80,	SPRITE_OFS_Y + 88);
			move_sprite(game_over_spr2,	SPRITE_OFS_X + 88,	SPRITE_OFS_Y + 88);
			move_sprite(game_over_spr3,	SPRITE_OFS_X + 96,	SPRITE_OFS_Y + 88);
			
			set_music(GAME_OVER_MUSIC);
			
			while(!KEY_TICKED(J_START))
			{
				UPDATE_KEYS();
				play_music();
				wait_vbl_done();	
			}
			stop_music();
			
			if( player_score > high_score )
			{
				high_score = player_score;
			}
			
			fade_to_white();
			DISPLAY_OFF;
			game_state = GS_TITLE;
		}
		
		wait_vbl_done();
	}
}

void enter_end()
{
	UBYTE i,j;
	UWORD w;
	
	SET_BANK(1);

	clear_all();
	fill_bkg_rect(DEVICE_SCREEN_X_OFFSET, DEVICE_SCREEN_Y_OFFSET, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);
	
	w = 0;
	for( i = 0; i != 20; i++ )
	{
		set_bkg_tiles(VIEWPORT_X_OFS + i,0,1,18,&end_map[w]);
		w += 18;
	}
	move_bkg(0,0);
	
	//set score
	for( i = 0; i != 4; i++ )
	{
		j = (player_score >> (i<<2)) & 0x0F;
		set_bkg_tiles(VIEWPORT_X_OFS + 10-i,14,1,1,&hud_data[14+j]);	
	}
	
	if( player_score > high_score )
	{
		high_score = player_score;
	}
	
	set_music(END_MUSIC);
	
	SHOW_BKG;
	DISPLAY_ON;
	
	fade_from_white();
	
	while( game_state == GS_END )
	{
		UPDATE_KEYS();	
		
		if( KEY_TICKED(J_START) )
		{
			stop_music();
			
			fade_to_white();
			DISPLAY_OFF;
			game_state = GS_TITLE;
		}
		
		play_music();
		wait_vbl_done();
	}	
}

