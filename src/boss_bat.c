#pragma bank 255

#include <gbdk/platform.h>

#include "global.h"
#include "boss.h"

BANKREF(boss_bat_dummyvar)
const uint8_t boss_bat_dummyvar = 1;

void update_boss_bat(void)
{
    UBYTE i,dmg;
    
    if( (boss_ani & 15) == 0 )
    {
        if( (rand() & 3) == 0 )
        {
            boss_dir = rand() & 3;
        } else {
            if( (boss_x + 4) < player_x )
            {
                boss_dir = 0;
            } else {
                boss_dir = 1;
            }
            if( boss_y < player_y )
            {
                boss_dir += 2;
            }
        }
        if( boss_x <= 12 )
        {
            boss_dir &= 0xFE;
        }
        if( boss_x >= 140 )
        {
            boss_dir |= 0x01;
        }
        if( boss_y <= 56 )
        {
            boss_dir |= 0x02;   
        }
        if( boss_y >= 120 )
        {
            boss_dir &= 0xFD;
        }
    }
        
    if( (boss_ani & 1) == 0 )
    {           
        
        switch( boss_dir )
        {
            case 0:
                boss_x++;
                boss_y--;
                break;
            case 1:
                boss_x--;
                boss_y--;
                break;
            case 2:
                boss_x++;
                boss_y++;
                break;
            case 3:
                boss_x--;
                boss_y++;
                break;
        }
    }
    
    if( boss_ani & 8 )
    {
        set_sprite_tile(boss_spr0,ST_BOSS_BAT0);
        set_sprite_tile(boss_spr1,ST_BOSS_BAT1);
        set_sprite_tile(boss_spr2,ST_BOSS_BAT2);
    } else {
        set_sprite_tile(boss_spr0,ST_BOSS_BAT3);
        set_sprite_tile(boss_spr1,ST_BOSS_BAT4);
        set_sprite_tile(boss_spr2,ST_BOSS_BAT5);
    }
    
    if(((player_x + 10) >= boss_x) && (player_x <= (boss_x + 18)))
    {
        if(((player_y + 11) >= boss_y) && (player_y <= (boss_y + 11)))
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
                if(((player_shot_y[i] + 2) >= boss_y) && (player_shot_y[i] <= (boss_y + 11)))
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
