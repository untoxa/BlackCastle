#pragma bank 255

#include <gbdk/platform.h>

#include "global.h"
#include "monster.h"

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

void update_monster_shot(void) BANKED
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
            pos = BUFPOS(tile_x, tile_y);
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
            if( monster_x[i] > ENEMY_SPAWN_POS_X )
            {
                monster_x[i] += monster_dir[i];
            } else {
                tile_x = ((monster_x[i] + 11 + scroll_pos) >> 3) - 1;
                tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
                tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
            
                pos1 = BUFPOS(tile_x, tile_y1);
                pos2 = BUFPOS(tile_x, tile_y2);
            
                tile1 = buf[pos1];
                tile2 = buf[pos2];
            
                if( (tile1 < 16) || (tile2 >= 16) )
                {
                    monster_dir[i] = -1;
                } 
                monster_x[i] += monster_dir[i];
            }
        } else {
            if( monster_x[i] > ENEMY_SPAWN_POS_X )
            {
                monster_x[i] += monster_dir[i];
            } else {
                tile_x = ((monster_x[i] + 4 + scroll_pos) >> 3) - 1;
                tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
                tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
                
                pos1 = BUFPOS(tile_x, tile_y1);
                pos2 = BUFPOS(tile_x, tile_y2);
                
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
        if( monster_ani[i] & 16 )
        {
            set_sprite_tile(monster_spr0[i],ST_KNIGHT0);
            set_sprite_tile(monster_spr1[i],ST_KNIGHT1);
        } else {
            set_sprite_tile(monster_spr0[i],ST_KNIGHT2);
            set_sprite_tile(monster_spr1[i],ST_KNIGHT3);
        }
        set_sprite_flip(monster_spr0[i],0);
        set_sprite_flip(monster_spr1[i],0);
    } else {
        if( monster_ani[i] & 16 )
        {
            set_sprite_tile(monster_spr0[i],ST_KNIGHT1);
            set_sprite_tile(monster_spr1[i],ST_KNIGHT0);
        } else {
            set_sprite_tile(monster_spr0[i],ST_KNIGHT3);
            set_sprite_tile(monster_spr1[i],ST_KNIGHT2);
        }
        set_sprite_flip(monster_spr0[i],S_FLIPX);
        set_sprite_flip(monster_spr1[i],S_FLIPX);
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
        pos = BUFPOS(tile_x, tile_y);
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
                if( monster_x[i] > ENEMY_SPAWN_POS_X )
                {
                    monster_x[i] += monster_dir[i];
                } else {
                    tile_x = ((monster_x[i] + 11 + scroll_pos) >> 3) - 1;
                    tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
                    tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
                
                    pos1 = BUFPOS(tile_x, tile_y1);
                    pos2 = BUFPOS(tile_x, tile_y2);
                
                    tile1 = buf[pos1];
                    tile2 = buf[pos2];
                
                    if( (tile1 < 16) || (tile2 >= 16) )
                    {
                        monster_dir[i] = -1;
                    } 
                    monster_x[i] += monster_dir[i];
                }
            } else {
                if( monster_x[i] > ENEMY_SPAWN_POS_X )
                {
                    monster_x[i] += monster_dir[i];
                } else {
                    tile_x = ((monster_x[i] + 4 + scroll_pos) >> 3) - 1;
                    tile_y1 = ((monster_y[i] + 16) >> 3) - 2;
                    tile_y2 = ((monster_y[i] + 14) >> 3) - 2;
                    
                    pos1 = BUFPOS(tile_x, tile_y1);
                    pos2 = BUFPOS(tile_x, tile_y2);
                    
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
            if( monster_ani[i] & 16 )
            {
                set_sprite_tile(monster_spr0[i],ST_SKELETON0);
                set_sprite_tile(monster_spr1[i],ST_SKELETON1);
            } else {
                set_sprite_tile(monster_spr0[i],ST_SKELETON2);
                set_sprite_tile(monster_spr1[i],ST_SKELETON3);
            }
            set_sprite_flip(monster_spr0[i],0);
            set_sprite_flip(monster_spr1[i],0);
        } else {
            if( monster_ani[i] & 16 )
            {
                set_sprite_tile(monster_spr0[i],ST_SKELETON1);
                set_sprite_tile(monster_spr1[i],ST_SKELETON0);
            } else {
                set_sprite_tile(monster_spr0[i],ST_SKELETON3);
                set_sprite_tile(monster_spr1[i],ST_SKELETON2);
            }
            set_sprite_flip(monster_spr0[i],S_FLIPX);
            set_sprite_flip(monster_spr1[i],S_FLIPX);
        }
    } else {
        if( monster_dir[i] == 1 )
        {
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
            set_sprite_flip(monster_spr0[i],0);
            set_sprite_flip(monster_spr1[i],0);
        } else {
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
            set_sprite_flip(monster_spr0[i],S_FLIPX);
            set_sprite_flip(monster_spr1[i],S_FLIPX);
        }
        monster_lif[i] = 8;
        monster_cnt[i]--;
    }
}

void update_monster(void) BANKED
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