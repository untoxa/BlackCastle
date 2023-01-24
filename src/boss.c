#pragma bank 2

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

void update_boss_bat()
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

void update_boss_minotaur()
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
    
    pos = (tile_x << 4) + tile_y;
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

void update_boss_reaper()
{
    UBYTE i,dmg;
    
    if( (boss_ani & 15) == 0 )
    {
        i = rand() & 3;
        switch( i )
        {
            case 0:
                boss_dir = rand() & 3;
                break;
            case 1:
                if( boss_x < player_x )
                {
                    boss_dir = 0;
                } else {
                    boss_dir = 1;
                }
                if( (boss_y + 8) < player_y )
                {
                    boss_dir += 2;
                }
                break;
            case 2:
                boss_dir = rand() & 3;
                if( (boss_y + 8) < player_y )
                {
                    boss_dir |= 0x02;
                } else {
                    boss_dir &= 0xFD;
                }
                break;
            default:
                boss_dir = 4;
                break;  
        }
        
        if( boss_dir != 4 )
        {
            if( boss_x <= 16 )
            {
                boss_dir &= 0xFE;
            }
            if( boss_x >= 144 )
            {
                boss_dir |= 0x01;
            }
            if( boss_y <= 60 )
            {
                boss_dir |= 0x02;   
            }
            if( boss_y >= 108 )
            {
                boss_dir &= 0xFD;
            }
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
        set_sprite_tile(boss_spr0,ST_BOSS_REAPER0);
        set_sprite_tile(boss_spr1,ST_BOSS_REAPER1);
        set_sprite_tile(boss_spr2,ST_BOSS_REAPER2);
        set_sprite_tile(boss_spr3,ST_BOSS_REAPER3);
    } else {
        set_sprite_tile(boss_spr0,ST_BOSS_REAPER4);
        set_sprite_tile(boss_spr1,ST_BOSS_REAPER5);
        set_sprite_tile(boss_spr2,ST_BOSS_REAPER6);
        set_sprite_tile(boss_spr3,ST_BOSS_REAPER7);
    }
    
    if( boss_cnt != 0 )
    {
        boss_cnt--;
    } else {
        new_monster_shot( boss_x + 4, boss_y + 6);
        boss_cnt = (rand() & 7) + 1;
        boss_cnt = boss_cnt << 4;
    }
    
    if(((player_x + 10) >= boss_x) && (player_x <= (boss_x + 10)))
    {
        if(((player_y + 11) >= boss_y) && (player_y <= (boss_y + 19)))
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
            if(((player_shot_x[i] + 3) >= boss_x) && (player_shot_x[i] <= (boss_x + 10)))
            {
                if(((player_shot_y[i] + 2) >= boss_y) && (player_shot_y[i] <= (boss_y + 15)))
                {
                    //dmg = player_shot_typ[i] + 2;
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

void update_boss() BANKED
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
