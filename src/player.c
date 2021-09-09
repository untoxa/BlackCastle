#pragma bank 2

#include <gbdk/platform.h>

#include "global.h"
#include "player.h"

//player
UBYTE player_x;
UBYTE player_y;
UBYTE player_spr0;
UBYTE player_spr1;
UBYTE player_ani;
BYTE player_dir;
BYTE player_vel;
UBYTE player_jmp;
UBYTE player_att;
UBYTE player_sht;
UBYTE player_dmg;
UBYTE player_lif;
UBYTE player_prp;
UWORD player_score;

//player shot
UBYTE player_shot_act[MAX_PLAYER_SHOT];
UBYTE player_shot_x[MAX_PLAYER_SHOT];
UBYTE player_shot_y[MAX_PLAYER_SHOT];
UBYTE player_shot_spr[MAX_PLAYER_SHOT];
UBYTE player_shot_typ[MAX_PLAYER_SHOT];
BYTE player_shot_dir[MAX_PLAYER_SHOT];
BYTE player_shot_vel[MAX_PLAYER_SHOT];
UBYTE player_shot_ani[MAX_PLAYER_SHOT];

void new_player_shot()
{
	UBYTE i;
	
	for( i = 0; i != MAX_PLAYER_SHOT; i++ )
	{
		if( player_shot_act[i] == FALSE )
		{
			player_shot_act[i] = TRUE;
			player_shot_spr[i] = get_sprite();
			player_shot_typ[i] = player_sht;
			player_shot_x[i] = player_x + 4;
			player_shot_y[i] = player_y + 6;
			
			if( player_sht == PST_SWORD )
			{
				set_sprite_tile(player_shot_spr[i],ST_PLAYER_SWORD);
				player_shot_dir[i] = 3;
			}
			else if( player_sht == PST_AXE )
			{
				set_sprite_tile(player_shot_spr[i],ST_PLAYER_AXE0);
				player_shot_vel[i] = -12;
				player_shot_dir[i] = 2;
				player_shot_ani[i] = 0;
			}
			else if( player_sht == PST_MACE )
			{
				set_sprite_tile(player_shot_spr[i],ST_PLAYER_MACE0);
				player_shot_vel[i] = -8;
				player_shot_dir[i] = 2;
				player_shot_ani[i] = 0;
			}
			
			if( player_dir == -1 )
			{
				set_sprite_prop(player_shot_spr[i],S_FLIPX);
				player_shot_dir[i] = -player_shot_dir[i];
			}
			
			set_sound(SND_SHOT);
			break;
		}
	}
}

void update_player_shot() BANKED
{
	UBYTE tile_x, tile_y;
	UBYTE tile;
	UBYTE i;
	UWORD pos;
	
	for( i = 0; i != MAX_PLAYER_SHOT; i++ )
	{
		if( player_shot_act[i] == TRUE )
		{
			player_shot_x[i] += -scroll;
			player_shot_x[i] += player_shot_dir[i];
			
			if( player_shot_typ[i] == PST_AXE )
			{
				player_shot_y[i] += (player_shot_vel[i] >> 3);
				
				if( player_shot_vel[i] != 25 )
				{
					player_shot_vel[i]++;
				}
				
				player_shot_ani[i]++;
				if( (player_shot_ani[i] & 12) == 0 )
				{
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_AXE0);
				} else if( (player_shot_ani[i] & 12) == 4 ) 
				{
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_AXE1);
				} else if( (player_shot_ani[i] & 12) == 8 ) 
				{
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_AXE2);
				} else {
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_AXE3);
				}
			} else if( player_shot_typ[i] == PST_MACE ) 
			{
				player_shot_y[i] += (player_shot_vel[i] >> 3);
				
				if( player_shot_vel[i] != 25 )
				{
					player_shot_vel[i]++;
				}
				
				player_shot_ani[i]++;
				if( (player_shot_ani[i] & 12) == 0 )
				{
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_MACE0);
				} else if( (player_shot_ani[i] & 12) == 4 ) 
				{
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_MACE1);
				} else if( (player_shot_ani[i] & 12) == 8 ) 
				{
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_MACE2);
				} else {
					set_sprite_tile(player_shot_spr[i],ST_PLAYER_MACE3);
				}
			}
			
			tile_x = ((player_shot_x[i] + 4 + scroll_pos) >> 3) - 1;
			tile_y = ((player_shot_y[i] + 3) >> 3) - 2;
			pos = (tile_x << 4) + tile_y;
			if( tile_y > 15 )
			{
				tile = 0;
			} else {
				tile = buf[pos];
			}
			/*
			if( (player_shot_x[i] > 168) || (tile >= 16) )
			{
				player_shot_act[i] = FALSE;
				clear_sprite(player_shot_spr[i]);
				
				if( (tile == 19) || (tile == 20) )
				{
					buf[pos] = 0;
					set_bkg_tiles(VIEWPORT_X_OFS + tile_x & 31,tile_y + 2,1,1,&buf[pos]);
					tile_x = ((tile_x + 1) << 3) - scroll_pos;
					tile_y = (tile_y + 2) << 3;
					new_stone(tile_x,tile_y,player_shot_dir[i]);
					new_item(tile_x,tile_y,tile-19);
					set_sound(SND_EXPLOSION);
				}
			}*/
			if( player_shot_x[i] > 168 )
			{
				player_shot_act[i] = FALSE;
				clear_sprite(player_shot_spr[i]);
			} else {
				if( tile >= 16 )
				{
					player_shot_act[i] = FALSE;
					clear_sprite(player_shot_spr[i]);
					if( (tile == 19) || (tile == 20) )
					{
						buf[pos] = 0;
						set_bkg_tiles(VIEWPORT_X_OFS + tile_x & 31,tile_y + 2,1,1,&buf[pos]);
						tile_x = ((tile_x + 1) << 3) - scroll_pos;
						tile_y = (tile_y + 2) << 3;
						new_stone(tile_x,tile_y,player_shot_dir[i]);
						new_item(tile_x,tile_y,tile-19);
						set_sound(SND_EXPLOSION);
					}
				}
			}
			
		}
	}	
}

void update_player() BANKED
{
	UBYTE tile_x1,tile_x2;
	UBYTE tile_y1,tile_y2;
	UBYTE tile1,tile2,tile3,tile4;
	UWORD pos1,pos2,pos3,pos4;

	//player
	if( KEY_DEBOUNCE(J_RIGHT) )
	{
		player_dir = 1;
		
		tile_x1 = ((player_x + 12 + scroll_pos) >> 3) - 1;
		tile_y1 = (player_y >> 3) - 2;
		tile_y2 = ((player_y + 15) >> 3) - 2;
		//tile_y3 = ((player_y + 8) >> 3) - 2;
		pos1 = (tile_x1 << 4) + tile_y1;
		pos2 = (tile_x1 << 4) + tile_y2;
		//pos3 = (tile_x1 << 4) + tile_y3;
		
		if( tile_y1 > 15 )
		{
			tile1 = 0;
		} else {
			tile1 = buf[pos1];
		}
		if( tile_y2 > 15 )
		{
			tile2 = 0;
		} else {
			tile2 = buf[pos2];
		}
		/*
		if( tile_y3 > 15 )
		{
			tile3 = 0;
		} else {
			tile3 = buf[pos3];
		}*/
		
		if( (tile1 < 19) && (tile2 < 19) /*&& (tile3 < 19)*/)			//16
		{
			if( (player_x == 80) && (scroll_pos < (level_len << 3)) )
			{
				scroll++;
			} else {
				if( level_min == 4 )
				{
					if( player_x != 155 )
					{
						player_x++;
					}
				} else {
					player_x++;
				}
			}
		}
		
		player_ani++;
		if( player_ani >= 10 )
		{
			player_ani = 1;
		}
		
		if( player_ani == 1 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_WALK0);
			set_sprite_tile(player_spr1,ST_PLAYER_WALK1);
		} else if( player_ani == 4 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_WALK2);
			set_sprite_tile(player_spr1,ST_PLAYER_WALK3);
		} else if( player_ani == 7 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_WALK4);
			set_sprite_tile(player_spr1,ST_PLAYER_WALK5);
		}
		player_prp &= ~S_FLIPX;
		//set_sprite_prop(player_spr0,0);
		//set_sprite_prop(player_spr1,0);
	} 
	else if( KEY_DEBOUNCE(J_LEFT) ) 
	{
		player_dir = -1;
		
		tile_x1 = ((player_x + 3 + scroll_pos) >> 3) - 1;
		tile_y1 = (player_y >> 3) - 2;
		tile_y2 = ((player_y + 15) >> 3) - 2;
		//tile_y3 = ((player_y + 8) >> 3) - 2;
		pos1 = (tile_x1 << 4) + tile_y1;
		pos2 = (tile_x1 << 4) + tile_y2;
		//pos3 = (tile_x1 << 4) + tile_y3;
		
		if( tile_y1 > 15 )
		{
			tile1 = 0;
		} else {
			tile1 = buf[pos1];
		}
		if( tile_y2 > 15 )
		{
			tile2 = 0;
		} else {
			tile2 = buf[pos2];
		}
		/*if( tile_y3 > 15 )
		{
			tile3 = 0;
		} else {
			tile3 = buf[pos3];
		}*/
		
		if( (tile1 < 19) && (tile2 < 19) /*&& (tile3 < 19)*/)		//16
		{
			if( player_x != 5 )
			{
				player_x--;
			}
		}
		
		player_ani++;
		if( player_ani >= 10 )
		{
			player_ani = 1;
		}
		
		if( player_ani == 1 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_WALK1);
			set_sprite_tile(player_spr1,ST_PLAYER_WALK0);
		} else if( player_ani == 4 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_WALK3);
			set_sprite_tile(player_spr1,ST_PLAYER_WALK2);
		} else if( player_ani == 7 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_WALK5);
			set_sprite_tile(player_spr1,ST_PLAYER_WALK4);
		}
		player_prp |= S_FLIPX;
		//set_sprite_prop(player_spr0,S_FLIPX);
		//set_sprite_prop(player_spr1,S_FLIPX);
	} else {
		player_ani = 0;
		if( player_dir == 1 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_IDLE0);
			set_sprite_tile(player_spr1,ST_PLAYER_IDLE1);
		} else {
			set_sprite_tile(player_spr0,ST_PLAYER_IDLE1);
			set_sprite_tile(player_spr1,ST_PLAYER_IDLE0);
		}
	}
	
	if( player_vel != 25 )
	{
		player_vel++;
	}
	
	if( player_jmp == 0 )
	{
		if( KEY_TICKED(J_A) )
		{
			player_jmp = 1;
			player_vel = -20;
		}
	} else {
		if( (!KEY_PRESSED(J_A)) && (player_vel < -5) )
		{
			player_vel = -5;
		}
		
		if( player_dir == 1 )
		{
			set_sprite_tile(player_spr0,ST_PLAYER_JUMP0);
			set_sprite_tile(player_spr1,ST_PLAYER_JUMP1);
		} else {
			set_sprite_tile(player_spr0,ST_PLAYER_JUMP1);
			set_sprite_tile(player_spr1,ST_PLAYER_JUMP0);
		}	
	}
	
	if( KEY_TICKED(J_B) && (player_att == 0) )
	{
		new_player_shot();
		player_att = 4;
	}
	if( player_att != 0 )
	{
		if( (player_jmp == 0) && (player_ani == 0))
		{			
			if( player_dir == 1 )
			{
				set_sprite_tile(player_spr0,ST_PLAYER_ATCK0);
				set_sprite_tile(player_spr1,ST_PLAYER_ATCK1);
			} else {
				set_sprite_tile(player_spr0,ST_PLAYER_ATCK1);
				set_sprite_tile(player_spr1,ST_PLAYER_ATCK0);
			}
		}
		player_att--;
	}
	
	tile_y1 = ((player_y - 1 + (player_vel >> 3)) >> 3) - 2;
	tile_y2 = ((player_y + 16 + (player_vel >> 3)) >> 3) - 2;
	tile_x1 = ((player_x + 4 + scroll_pos) >> 3) - 1;
	tile_x2 = ((player_x + 11 + scroll_pos) >> 3) - 1;
	
	pos1 = (tile_x1 << 4) + tile_y1;
	pos2 = (tile_x2 << 4) + tile_y1;
	pos3 = (tile_x1 << 4) + tile_y2;
	pos4 = (tile_x2 << 4) + tile_y2;
	
	if( tile_y1 > 15 )
	{
		tile1 = 0;
		tile2 = 0;
	} else {
		tile1 = buf[pos1];
		tile2 = buf[pos2];
	}
	
	if( tile_y2 > 15 )
	{
		tile3 = 0;
		tile4 = 0;
	} else {
		tile3 = buf[pos3];
		tile4 = buf[pos4];
	}
	
	if( player_vel >= 0 )
	{
		if( ((tile3 < 19) && (tile4 < 19) && (tile3 != 15) && (tile4 != 15)) || ((player_y & 7) > 3) )
		{
			player_jmp = 1;
			player_y += (player_vel >> 3);	
		} else {
			player_y = tile_y2 << 3;
			player_jmp = 0;
			player_vel = 25;
			if( (tile3 == 31) && (tile4 == 31) && (player_dmg == 0) )
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
	} else {
		if( (tile1 < 19) && (tile2 < 19) )		//16
		{
			player_y += (player_vel >> 3);
		} else {
			player_vel = -player_vel;
			player_y = (tile_y1 + 3) << 3;
		}
	}

	player_prp &= ~S_PRIORITY;
	if( (tile1 >= 16) && (tile1 <= 18 ) )
	{
		player_prp |= S_PRIORITY;
	}
	if( (tile2 >= 16) && (tile2 <= 18 ) )
	{
		player_prp |= S_PRIORITY;
	}
	if( (tile3 >= 16) && (tile3 <= 18 ) )
	{
		player_prp |= S_PRIORITY;
	}
	if( (tile4 >= 16) && (tile4 <= 18 ) )
	{
		player_prp |= S_PRIORITY;
	}

	set_sprite_prop(player_spr0,player_prp);
	set_sprite_prop(player_spr1,player_prp);
	
	
	/*
	if( player_vel >= 0 )
	{
		tile_y = ((player_y + 16 + (player_vel >> 3)) >> 3) - 2;
		tile_x1 = ((player_x + 4 + scroll_pos) >> 3) - 1;
		tile_x2 = ((player_x + 11 + scroll_pos) >> 3) - 1;
		
		pos1 = (tile_x1 << 4) + tile_y;
		pos2 = (tile_x2 << 4) + tile_y;
		
		if( tile_y > 15 )
		{
			tile1 = 0;
			tile2 = 0;
		} else {
			tile1 = buf[pos1];
			tile2 = buf[pos2];
		}
		
		if( ((tile1 < 19) && (tile2 < 19) && (tile1 != 15) && (tile2 != 15)) || ((player_y & 7) > 3) )
		{
			player_jmp = 1;
			player_y += (player_vel >> 3);	
		} else {
			player_y = tile_y << 3;
			player_jmp = 0;
			player_vel = 25;
			if( (tile1 == 31) && (tile2 == 31) && (player_dmg == 0) )
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
	} else {
		tile_y = ((player_y - 1 + (player_vel >> 3)) >> 3) - 2;
		tile_x1 = ((player_x + 4 + scroll_pos) >> 3) - 1;
		tile_x2 = ((player_x + 11 + scroll_pos) >> 3) - 1;
		
		pos1 = (tile_x1 << 4) + tile_y;
		pos2 = (tile_x2 << 4) + tile_y;
		
		if( tile_y > 15 )
		{
			tile1 = 0;
			tile2 = 0;
		} else {
			tile1 = buf[pos1];
			tile2 = buf[pos2];
		}
		
		if( (tile1 < 19) && (tile2 < 19) )		//16
		{
			player_y += (player_vel >> 3);
		} else {
			player_vel = -player_vel;
			player_y = (tile_y + 3) << 3;
		}
	}*/
}