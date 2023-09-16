#pragma bank 1

#include <gbdk/platform.h>

#include "global.h"

//sprites
UBYTE spr_act[MAX_SPRITES];

//item
UBYTE item_count;
UBYTE item_act[MAX_ITEM];
UBYTE item_x[MAX_ITEM];
UBYTE item_y[MAX_ITEM];
UBYTE item_spr[MAX_ITEM];
UBYTE item_typ[MAX_ITEM];
BYTE item_vel[MAX_ITEM];

//platform
UBYTE platform_count;
UBYTE platform_act[MAX_PLATFORM];
UBYTE platform_x[MAX_PLATFORM];
UBYTE platform_y[MAX_PLATFORM];
UBYTE platform_spr0[MAX_PLATFORM];
UBYTE platform_spr1[MAX_PLATFORM];
UBYTE platform_typ[MAX_PLATFORM];
BYTE platform_dir[MAX_PLATFORM];
UBYTE platform_pos[MAX_PLATFORM];
BYTE platform_vel[MAX_PLATFORM];

//explosion
UBYTE explosion_count;
UBYTE explosion_act[MAX_EXPLOSION];
UBYTE explosion_x[MAX_EXPLOSION];
UBYTE explosion_y[MAX_EXPLOSION];
UBYTE explosion_spr0[MAX_EXPLOSION];
UBYTE explosion_spr1[MAX_EXPLOSION];
UBYTE explosion_ani[MAX_EXPLOSION];

//stone
UBYTE stone_count;
UBYTE stone_act[MAX_STONE];
UBYTE stone_x[MAX_STONE];
UBYTE stone_y[MAX_STONE];
UBYTE stone_spr[MAX_STONE];
BYTE stone_dir[MAX_STONE];
BYTE stone_vel[MAX_STONE];

UBYTE get_sprite(void) NONBANKED
{
    UBYTE i;

    for( i = 0; i != MAX_SPRITES; i++ )
    {
        if( spr_act[i] == FALSE )
        {
            spr_act[i] = TRUE;
            return i;
        }
    }
    return i;
}

void clear_sprite(UBYTE i) NONBANKED
{
    if( i < MAX_SPRITES )
    {
        set_sprite_prop(i,0);
        hide_sprite(i);
        spr_act[i] = FALSE;
    }
}

void clear_sprites(UBYTE starting_index) NONBANKED
{
    UBYTE i;
    for( i = starting_index; i != MAX_SPRITES; i++ )
    {
        clear_sprite(i);
    }
}

void clear_all_objects(void) NONBANKED
{
    UBYTE i;

    //player_shot
    for( i = 0; i != MAX_PLAYER_SHOT; i++ )
    {
        player_shot_act[i] = FALSE;
    }

    //monster
    for( i = 0; i != MAX_MONSTER; i++ )
    {
        monster_act[i] = FALSE;
    }

    //monster shot
    monster_shot_count = 0;
    for( i = 0; i != MAX_MONSTER_SHOT; i++ )
    {
        monster_shot_act[i] = FALSE;
    }

    //item
    item_count = 0;
    for( i = 0; i != MAX_ITEM; i++ )
    {
        item_act[i] = FALSE;
    }

    //platfrom
    platform_count = 0;
    for( i = 0; i != MAX_PLATFORM; i++ )
    {
        platform_act[i] = FALSE;
    }

    //explosion
    explosion_count = 0;
    for( i = 0; i != MAX_EXPLOSION; i++ )
    {
        explosion_act[i] = FALSE;
    }

    //stone
    stone_count = 0;
    for( i = 0; i != MAX_STONE; i++ )
    {
        stone_act[i] = FALSE;
    }

    //boss
    boss_act = FALSE;
}

void new_item(UBYTE x, UBYTE y, UBYTE type) BANKED
{
    UBYTE i;

    for( i = 0; i != MAX_ITEM; i++ )
    {
        if( item_act[i] == FALSE )
        {
            item_count++;
            item_act[i] = TRUE;
            item_spr[i] = get_sprite();
            switch( type )
            {
                case IT_CRYSTAL:
                    set_sprite_tile(item_spr[i],ST_CRYSTAL);
                    break;
                case IT_HEART:
                    set_sprite_tile(item_spr[i],ST_HEART);
                    break;
                case IT_SWORD:
                    set_sprite_tile(item_spr[i],ST_PLAYER_SWORD);
                    break;
                case IT_AXE:
                    set_sprite_tile(item_spr[i],ST_PLAYER_AXE0);
                    break;
                case IT_MACE:
                    set_sprite_tile(item_spr[i],ST_PLAYER_MACE0);
                    break;
            }
            item_x[i] = x;
            item_y[i] = y;
            item_typ[i] = type;
            item_vel[i] = 0;
            break;
        }
    }
}

void update_item(void) BANKED
{
    UBYTE tile_x, tile_y;
    UBYTE tile;
    UWORD pos;
    UBYTE i;

    for( i = 0; i != MAX_ITEM; i++ )
    {
        if( item_act[i] == TRUE )
        {
            item_x[i] += -scroll;

            if( item_vel[i] != 25 )
            {
                item_vel[i]++;
            }
            item_y[i] += (item_vel[i] >> 3);

            tile_x = ((item_x[i] + 4 + scroll_pos) >> 3) - 1;
            tile_y = ((item_y[i] + 8) >> 3) - 2;
            pos = BUFPOS(tile_x, tile_y);
            tile = buf[pos];

            if( tile >= 16 )
            {
                item_y[i] = (tile_y + 1) << 3;
            }

            if( ((player_x + 11) >= item_x[i]) && ((player_x - 3) <= item_x[i] ))
            {
                if( ((player_y + 10) >= item_y[i]) && (player_y <= (item_y[i] + 7)) )
                {
                    switch( item_typ[i] )
                    {
                        case IT_CRYSTAL:
                            set_sound(SND_CRYSTAL);
                            add_score(5);
                            break;
                        case IT_HEART:
                            set_sound(SND_HEART);
                            if( player_lif != 4 )
                            {
                                player_lif++;
                                update_hud(HUD_LIFE);
                            }
                            break;
                        case IT_SWORD:
                        case IT_AXE:
                        case IT_MACE:
                            player_sht = item_typ[i] - 2;
                            set_sound(SND_WEAPON);
                            update_hud(HUD_WEAPON);
                            break;

                    }
                    item_count--;
                    item_act[i] = FALSE;
                    clear_sprite( item_spr[i] );
                }
            }

            if( item_x[i] == 240 )
            {
                item_count--;
                item_act[i] = FALSE;
                clear_sprite( item_spr[i] );
            }
        }
    }
}

void new_platform(UBYTE x, UBYTE y, UBYTE type) BANKED
{
    UBYTE i;

    for( i = 0; i != MAX_PLATFORM; i++ )
    {
        if( platform_act[i] == FALSE )
        {
            platform_count++;
            platform_act[i] = TRUE;
            platform_spr0[i] = get_sprite();
            platform_spr1[i] = get_sprite();
            set_sprite_tile(platform_spr0[i],ST_PLATFORM);
            set_sprite_tile(platform_spr1[i],ST_PLATFORM);
            platform_x[i] = x;
            platform_y[i] = y;
            platform_typ[i] = type;
            switch( type )
            {
                case PT_FALLING_PLATFORM:
                    platform_dir[i] = 0;
                    platform_vel[i] = 0;
                    break;
                case PT_UPDOWN_PLATFORM:
                    platform_dir[i] = 1;
                    platform_pos[i] = platform_y[i];
                    platform_vel[i] = 0;
                    break;
                case PT_LEFTRIGHT_PLATFORM:
                    platform_dir[i] = -1;
                    platform_pos[i] = 32;
                    platform_vel[i] = 0;
                    platform_x[i]--;
                    break;
            }
            break;
        }
    }
}

void update_platform(void) BANKED
{
    UBYTE i,j;

    j = 255;
    for( i = 0; i != MAX_PLATFORM; i++ )
    {
        if( platform_act[i] == TRUE )
        {
            platform_x[i] += -scroll;

            switch( platform_typ[i] )
            {
                case PT_FALLING_PLATFORM:
                    if( platform_dir[i] == 1 )
                    {
                        if( platform_vel[i] != 25 )
                        {
                            platform_vel[i]++;
                        }
                        platform_y[i] += (platform_vel[i] >> 3);
                    }
                    break;
                case PT_UPDOWN_PLATFORM:
                    platform_vel[i]++;
                    if( (platform_vel[i] & 1) == 0 )
                    {
                        platform_y[i] += platform_dir[i];

                        if( platform_y[i] == (platform_pos[i] + 28) )
                        {
                            platform_dir[i] = -1;
                        }
                        if( platform_y[i] == platform_pos[i] )
                        {
                            platform_dir[i] = 1;
                        }
                    }
                    break;
                case PT_LEFTRIGHT_PLATFORM:
                    platform_vel[i]++;

                    if( (platform_vel[i] & 1) == 0 )
                    {
                        if( platform_dir[i] == 1 )
                        {
                            platform_pos[i]++;
                            if( platform_pos[i] == 32 )
                            {
                                platform_dir[i] = -1;
                            }
                        } else {
                            platform_pos[i]--;
                            if( platform_pos[i] == 0 )
                            {
                                platform_dir[i] = 1;
                            }
                        }
                        platform_x[i] += platform_dir[i];
                    }
                    break;
            }

            if( player_vel >= 0 )
            {
                if( ((player_x + 11) > platform_x[i]) && ((player_x + 4) < (platform_x[i] + 15)) )
                {
                    if( ((player_y + 16) > platform_y[i]) && ((player_y + 16) < (platform_y[i] + 5)) )
                    {
                        player_y = platform_y[i] - 16;
                        player_jmp = 0;
                        player_vel = 25;
                        if( platform_typ[i] == PT_FALLING_PLATFORM )
                        {
                            platform_dir[i] = 1;
                        }
                        if( platform_typ[i] == PT_LEFTRIGHT_PLATFORM )
                        {
                            if( (platform_vel[i] & 1) == 0 )
                            {
                                if( platform_dir[i] == 1 )
                                {
                                    if( player_x == 80 )
                                    {
                                        j = i;
                                        platform_x[i]--;
                                    } else {
                                        player_x++;
                                    }
                                } else {
                                    if( player_x != 5 )
                                    {
                                        player_x--;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if( ((platform_x[i] > ENEMY_SPAWN_POS_X) && (platform_x[i] < 216))|| (platform_y[i] >= 176) )
            {
                platform_count--;
                platform_act[i] = FALSE;
                clear_sprite( platform_spr0[i] );
                clear_sprite( platform_spr1[i] );
            }
        }
    }

    if( j != 255 )
    {
        scroll++;
        for( i = 0; i != MAX_PLATFORM; i++ )
        {
            if( platform_act[i] == TRUE )
            {
                if( i != j )
                {
                    platform_x[i]--;
                }
            }
        }
    }
}

void new_explosion(UBYTE x, UBYTE y) BANKED
{
    UBYTE i;

    for( i = 0; i != MAX_EXPLOSION; i++ )
    {
        if( explosion_act[i] == FALSE )
        {
            explosion_count++;
            explosion_act[i] = TRUE;
            explosion_x[i] = x;
            explosion_y[i] = y;
            explosion_spr0[i] = get_sprite();
            explosion_spr1[i] = get_sprite();
            set_sprite_tile(explosion_spr0[i],ST_EXPLOSION0);
            set_sprite_tile(explosion_spr1[i],ST_EXPLOSION1);
            explosion_ani[i] = 0;
            set_sound(SND_EXPLOSION);
            break;
        }
    }
}

void update_explosion(void) BANKED
{
    UBYTE i;

    for( i = 0; i != MAX_EXPLOSION; i++ )
    {
        if( explosion_act[i] == TRUE )
        {
            explosion_x[i] += -scroll;

            explosion_ani[i]++;
            if( explosion_ani[i] == 5 )
            {
                set_sprite_tile(explosion_spr0[i],ST_EXPLOSION2);
                set_sprite_tile(explosion_spr1[i],ST_EXPLOSION3);
            }
            if( explosion_ani[i] == 10 )
            {
                set_sprite_tile(explosion_spr0[i],ST_EXPLOSION4);
                set_sprite_tile(explosion_spr1[i],ST_EXPLOSION5);
            }
            if( explosion_ani[i] == 15 )
            {
                explosion_count--;
                explosion_act[i] = FALSE;
                clear_sprite(explosion_spr0[i]);
                clear_sprite(explosion_spr1[i]);
            }
        }
    }
}

void new_stone(UBYTE x, UBYTE y, BYTE dir) BANKED
{
    UBYTE i;
    BYTE j;

    j = -10;
    if( dir > 0 )
    {
        dir = -1;
    } else {
        dir = 1;
    }
    for( i = 0; i != MAX_STONE; i++ )
    {
        if( stone_act[i] == TRUE )
        {
            clear_sprite(stone_spr[i]);
        }
        stone_count++;
        stone_act[i] = TRUE;
        stone_x[i] = x;
        stone_y[i] = y;
        stone_spr[i] = get_sprite();
        set_sprite_tile(stone_spr[i],ST_STONE);
        stone_dir[i] = dir;
        stone_vel[i] = j;
        j += 5;
    }
}

void update_stone(void) BANKED
{
    UBYTE i;

    for( i = 0; i != MAX_STONE; i++ )
    {
        if( stone_act[i] == TRUE )
        {
            stone_x[i] += -scroll;
            stone_x[i] += stone_dir[i];

            stone_y[i] += (stone_vel[i] >> 3);
            if( stone_vel[i] != 25 )
            {
                stone_vel[i]++;
            }

            if( stone_y[i] > 160 )
            {
                stone_count--;
                stone_act[i] = FALSE;
                clear_sprite(stone_spr[i]);
            }
        }
    }
}
