#pragma bank 255

#include <gbdk/platform.h>

#include "global.h"
#include "boss.h"

BANKREF(boss_minotaur_dummyvar)
const uint8_t boss_minotaur_dummyvar = 1;

void update_boss_minotaur(void)
{
    UBYTE tile_x, tile_y, tile;
    UWORD pos;
    UBYTE i,dmg;
    
    if( (boss_cnt == 0) && (boss_jmp == 0) )
    {
        boss_jmp = 1;
        boss_vel = -20;     
    }
    
    if( boss_jmp == 1 )
    {
        boss_x += boss_dir;
    }
    
    if( boss_vel != 22 )
    {
        boss_vel++;
    }
    
    boss_y += (boss_vel >> 3);
    tile_x = ((boss_x + 12) >> 3) - 1;
    tile_y = ((boss_y + 23) >> 3) - 2;
    
    pos = BUFPOS(tile_x, tile_y);
    tile = buf[pos];
    
    if( tile < 15 )
    {
        boss_y += (boss_vel >> 3);
    } else {
        boss_y = (tile_y << 3) - 7;
        boss_jmp = 0;
        boss_vel = 22;
        if( boss_cnt == 0 )
        {
            boss_cnt = (rand() & 3) + 3;
            boss_cnt = boss_cnt << 4;
            
            if( boss_x == 76 )
            {
                boss_dir = (rand() & 3) - 1;
                if( boss_dir == 2 )
                {
                    if( player_x < boss_x )
                    {
                        boss_dir = -1;
                    } else {
                        boss_dir = 1;
                    }
                }
            } else if ( boss_x > 76 ) {
                boss_dir = -1;
            } else {
                boss_dir = 1;
            }
            
            shake = 8;
            set_sound(SND_SHAKE);
            
        } else {
            boss_cnt--;
        }
    }
    
    if( boss_ani & 16 )
    {
        set_sprite_tile(boss_spr0,ST_BOSS_MINOTAUR0);
        set_sprite_tile(boss_spr1,ST_BOSS_MINOTAUR1);
        set_sprite_tile(boss_spr2,ST_BOSS_MINOTAUR2);
        set_sprite_tile(boss_spr3,ST_BOSS_MINOTAUR3);
        set_sprite_tile(boss_spr4,ST_BOSS_MINOTAUR4);
        set_sprite_tile(boss_spr5,ST_BOSS_MINOTAUR5);
    } else {
        set_sprite_tile(boss_spr0,ST_BOSS_MINOTAUR6);
        set_sprite_tile(boss_spr1,ST_BOSS_MINOTAUR7);
        set_sprite_tile(boss_spr2,ST_BOSS_MINOTAUR8);
        set_sprite_tile(boss_spr3,ST_BOSS_MINOTAUR9);
        set_sprite_tile(boss_spr4,ST_BOSS_MINOTAUR10);
        set_sprite_tile(boss_spr5,ST_BOSS_MINOTAUR11);
    }
    
    if( (shake != 0) && ( player_dmg == 0) && (player_jmp == 0))
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
    
    if(((player_x + 10) >= boss_x) && (player_x <= (boss_x + 18)))
    {
        if(((player_y + 11) >= boss_y) && (player_y <= (boss_y + 18)))
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
    
    for( i = 0; i != MAX_PLAYER_SHOT; i++ )
    {
        if( player_shot_act[i] == TRUE )
        {
            if(((player_shot_x[i] + 3) >= boss_x) && (player_shot_x[i] <= (boss_x + 18)))
            {
                if(((player_shot_y[i] + 2) >= boss_y) && (player_shot_y[i] <= (boss_y + 18)))
                {
                    if( player_shot_typ[i] == PST_MACE )
                    {
                        dmg = 4;
                    } else {
                        dmg = 3;
                    }
                    
                    if( boss_lif > dmg )
                    {
                        boss_lif -= dmg;
                        boss_dmg = 3;
                        set_sound(SND_HIT);
                    } else {
                        boss_state = BS_END;
                        boss_dmg = 145;
                    }
                    
                    player_shot_act[i] = FALSE;
                    clear_sprite(player_shot_spr[i]);
                }
            }
        }
    }
}
