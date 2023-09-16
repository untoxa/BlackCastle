#pragma bank 255

#include <gbdk/platform.h>

#include "global.h"
#include "boss.h"

//boss
UBYTE boss_act;
UBYTE boss_x;
UBYTE boss_y;
UBYTE boss_spr0;
UBYTE boss_spr1;
UBYTE boss_spr2;
UBYTE boss_spr3;
UBYTE boss_spr4;
UBYTE boss_spr5;
UBYTE boss_typ;
BYTE boss_dir;
BYTE boss_vel;
UBYTE boss_jmp;
UBYTE boss_ani;
UBYTE boss_dmg;
UBYTE boss_lif;
UBYTE boss_cnt;
UBYTE boss_state;

void new_boss(UBYTE x, UBYTE y, UBYTE type) BANKED
{
    if( boss_act == FALSE )
    {
        boss_act = TRUE;
        boss_x = x;
        boss_y = y; 
        switch( type )
        {
            case BT_BAT:
                boss_lif = 40;
                boss_spr0 = get_sprite();
                boss_spr1 = get_sprite();
                boss_spr2 = get_sprite();
                set_sprite_tile(boss_spr0,ST_BOSS_BAT0);
                set_sprite_tile(boss_spr1,ST_BOSS_BAT1);
                set_sprite_tile(boss_spr2,ST_BOSS_BAT2);
                break;
            case BT_MINOTAUR:
                boss_lif = 70;
                boss_cnt = (rand() & 3) + 3;
                boss_cnt = boss_cnt << 4;
                boss_vel = 25;
                boss_jmp = 0;
                boss_dir = 0;
                boss_spr0 = get_sprite();
                boss_spr1 = get_sprite();
                boss_spr2 = get_sprite();
                boss_spr3 = get_sprite();
                boss_spr4 = get_sprite();
                boss_spr5 = get_sprite();
                set_sprite_tile(boss_spr0,ST_BOSS_MINOTAUR0);
                set_sprite_tile(boss_spr1,ST_BOSS_MINOTAUR1);
                set_sprite_tile(boss_spr2,ST_BOSS_MINOTAUR2);
                set_sprite_tile(boss_spr3,ST_BOSS_MINOTAUR3);
                set_sprite_tile(boss_spr4,ST_BOSS_MINOTAUR4);
                set_sprite_tile(boss_spr5,ST_BOSS_MINOTAUR5);
                break;
            case BT_REAPER:
                boss_lif = 90;
                boss_cnt = (rand() & 7) + 1;
                boss_cnt = boss_cnt << 4;
                boss_spr0 = get_sprite();
                boss_spr1 = get_sprite();
                boss_spr2 = get_sprite();
                boss_spr3 = get_sprite();
                set_sprite_tile(boss_spr0,ST_BOSS_REAPER0);
                set_sprite_tile(boss_spr1,ST_BOSS_REAPER1);
                set_sprite_tile(boss_spr2,ST_BOSS_REAPER2);
                set_sprite_tile(boss_spr3,ST_BOSS_REAPER3);
                break;
        }
        boss_typ = type;
        boss_ani = 0;
        boss_dmg = 128;
        boss_state = BS_START;
    }   
}

void update_boss(void) BANKED
{
    BYTE x,y;
    
    if( boss_act == TRUE )
    {
        switch( boss_state )
        {
            case BS_START:
                if( boss_dmg == 1 )
                {
                    boss_state = BS_FIGHT;
                }
                break;
            case BS_FIGHT:
                switch( boss_typ )
                {
                    case BT_BAT:
                        update_boss_bat();
                        break;
                    case BT_MINOTAUR:
                        update_boss_minotaur();
                        break;
                    case BT_REAPER:
                        update_boss_reaper();
                        break;
                }
                break;
            case BS_END:
                if( boss_dmg == 0 )
                {
                    boss_act = FALSE;
                    switch( boss_typ )
                    {
                        case BT_BAT:
                            clear_sprite(boss_spr0);
                            clear_sprite(boss_spr1);
                            clear_sprite(boss_spr2);
                            break;
                        case BT_MINOTAUR:
                            clear_sprite(boss_spr0);
                            clear_sprite(boss_spr1);
                            clear_sprite(boss_spr2);
                            clear_sprite(boss_spr3);
                            clear_sprite(boss_spr4);
                            clear_sprite(boss_spr5);
                            break;
                        case BT_REAPER:
                            clear_sprite(boss_spr0);
                            clear_sprite(boss_spr1);
                            clear_sprite(boss_spr2);
                            clear_sprite(boss_spr3);
                            break;
                    }
                    
                    add_score(0x20);                
                } else {
                    if( (boss_dmg & 15) == 0 )
                    {
                        x = rand() & 3;
                        if( x == 3 )
                        {
                            x = 1;
                        }
                        x = (x << 3) - 4;
                        y = rand() & 3;
                        if( y == 3 ) 
                        {
                            y = 1;
                        }
                        y = (y << 2) - 4;
                        new_explosion( boss_x + x, boss_y + y);
                    }
                }
                break;
        }
        
        boss_ani++;
        if( boss_dmg != 0 )
        {
            boss_dmg--;
        }
    }
}
