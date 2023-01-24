#include <gbdk/platform.h>

#include "global.h"

const unsigned char shot_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0x92,0x53,0x80},
    {0x01,0xFF,0xB2,0x50,0x80}
};

const unsigned char crystal_sound[][6] =
{
    {0x01,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF1,0x9F,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0xDB,0x87}
};

const unsigned char heart_sound[][6] =
{
    {0x01,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x17,0x80,0xF1,0x40,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x17,0x80,0xF1,0x30,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x17,0x80,0xF1,0x20,0x87}
};

const unsigned char hit_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF1,0x57,0x80},
    {0x01,0xFF,0xF1,0x45,0x80},
    {0x01,0xFF,0xF1,0x34,0x80}
};


const unsigned char explosion_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF1,0x54,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x57,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x37,0x80},
    {0x01,0xFF,0xF2,0x35,0x80},
    {0x01,0xFF,0xF2,0x34,0x80}
};

const unsigned char weapon_sound[][6] =
{
    {0x01,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x34,0x80,0xF2,0x0A,0x86}
};

const unsigned char start_sound[][6] =
{
    {0x01,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0x80,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0xB0,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0x80,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0xB0,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0x80,0x87},
    {0x00,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x80,0xF2,0x50,0x87}
};

const unsigned char damage_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF2,0x57,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x44,0x80},
    {0x01,0xFF,0xF2,0x57,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x44,0x80},
    {0x01,0xFF,0xF2,0x39,0x80},
    {0x01,0xFF,0xF2,0x37,0x80},
    {0x01,0xFF,0xF2,0x35,0x80}
};

const unsigned char dead_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF2,0x57,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x44,0x80},
    {0x01,0xFF,0xF2,0x37,0x80},
    {0x01,0xFF,0xF2,0x35,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x57,0x80},
    {0x01,0xFF,0xF2,0x39,0x80},
    {0x01,0xFF,0xF2,0x37,0x80},
    {0x01,0xFF,0xF2,0x35,0x80}
};

const unsigned char pause_sound[][6] =
{
    {0x01,0x00,0x00,0x00,0x00,0x00},
    {0x01,0x00,0x8F,0x91,0x1C,0x87},
    {0x01,0x00,0x8F,0x91,0xCC,0x86},
    {0x01,0x00,0x8F,0xA1,0x7C,0x86},
    {0x01,0x00,0x8F,0x91,0x1C,0x87},
    {0x01,0x00,0x8F,0x91,0xCC,0x86},
    {0x01,0x00,0x8F,0xA1,0x7C,0x86},
    {0x01,0x00,0x8F,0x91,0x1C,0x87},
    {0x01,0x00,0x8F,0x91,0xCC,0x86},
    {0x01,0x00,0x8F,0xA1,0x7C,0x86}
};

const unsigned char break_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF1,0x54,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x57,0x80},
    {0x01,0xFF,0xF2,0x45,0x80},
    {0x01,0xFF,0xF2,0x37,0x80},
    {0x01,0xFF,0xF2,0x35,0x80},
    {0x01,0xFF,0xF2,0x34,0x80}
};

const unsigned char shake_sound[][5] =
{
    {0x01,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF3,0x57,0x80},
    {0x01,0xFF,0xF3,0x37,0x80},
    {0x01,0xFF,0xF3,0x35,0x80},
    {0x00,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF3,0x57,0x80},
    {0x01,0xFF,0xF3,0x37,0x80},
    {0x01,0xFF,0xF3,0x35,0x80},
    {0x00,0x00,0x00,0x00,0x00},
    {0x01,0xFF,0xF3,0x57,0x80},
    {0x01,0xFF,0xF3,0x37,0x80},
    {0x01,0xFF,0xF3,0x35,0x80}
};

const unsigned char candle_tiles[] =
{
  0x00,0x00,0x10,0x00,0x10,0x00,0x28,0x00,
  0x28,0x00,0x10,0x00,0x7C,0x00,0x44,0x00,
  0x00,0x00,0x00,0x00,0x10,0x00,0x10,0x00,
  0x38,0x00,0x10,0x00,0x7C,0x00,0x44,0x00
};

const unsigned char title_numbers[] = 
{
    0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,0xB0
};

const unsigned char hud_data[] =
{
  //weapon
  0x47,0x49,0x48,0x4A,0x4B,0x4D,0x4C,0x4E,0x4F,0x51,0x50,0x52,
  //life
  0x46,0x20,
  //numbers
  0x3B,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x43,0x44 
};

//sound
UBYTE sound_cnt_ch1;
UBYTE sound_typ_ch1;

UBYTE sound_cnt_ch4;
UBYTE sound_typ_ch4;

//sprites
UBYTE spr_act[MAX_SPRITES];

//item
UBYTE item_act[MAX_ITEM];
UBYTE item_x[MAX_ITEM];
UBYTE item_y[MAX_ITEM];
UBYTE item_spr[MAX_ITEM];
UBYTE item_typ[MAX_ITEM];
BYTE item_vel[MAX_ITEM];

//platform
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
UBYTE explosion_act[MAX_EXPLOSION];
UBYTE explosion_x[MAX_EXPLOSION];
UBYTE explosion_y[MAX_EXPLOSION];
UBYTE explosion_spr0[MAX_EXPLOSION];
UBYTE explosion_spr1[MAX_EXPLOSION];
UBYTE explosion_ani[MAX_EXPLOSION];

//stone
UBYTE stone_act[MAX_STONE];
UBYTE stone_x[MAX_STONE];
UBYTE stone_y[MAX_STONE];
UBYTE stone_spr[MAX_STONE];
BYTE stone_dir[MAX_STONE];
BYTE stone_vel[MAX_STONE];

void set_sound(UBYTE sound)
{
#if defined(NINTENDO)
    switch( sound )
    {
        case SND_SHOT:
            if( sound_cnt_ch4 == 0 )
            {
                sound_cnt_ch4 = (sizeof(shot_sound)) / 5;
                sound_typ_ch4 = SND_SHOT;
            }
            break;
        case SND_CRYSTAL:
            sound_cnt_ch1 = (sizeof(crystal_sound)) / 6;
            sound_typ_ch1 = SND_CRYSTAL;
            break;
        case SND_HEART:
            sound_cnt_ch1 = (sizeof(heart_sound)) / 6;
            sound_typ_ch1 = SND_HEART;
            break;
        case SND_HIT:
            sound_cnt_ch4 = (sizeof(hit_sound)) / 5;
            sound_typ_ch4 = SND_HIT;
            break;
        case SND_EXPLOSION:
            sound_cnt_ch4 = (sizeof(explosion_sound)) / 5;
            sound_typ_ch4 = SND_EXPLOSION;
            break;
        case SND_WEAPON:
            sound_cnt_ch1 = (sizeof(weapon_sound)) / 6;
            sound_typ_ch1 = SND_WEAPON;
            break;
        case SND_START:
            sound_cnt_ch1 = (sizeof(start_sound)) / 6;
            sound_typ_ch1 = SND_START;
            break;
        case SND_DAMAGE:
            sound_cnt_ch4 = (sizeof(damage_sound)) / 5;
            sound_typ_ch4 = SND_DAMAGE;
            break;
        case SND_DEAD:
            sound_cnt_ch4 = (sizeof(dead_sound)) / 5;
            sound_typ_ch4 = SND_DEAD;
            break;
        case SND_PAUSE:
            sound_cnt_ch1 = (sizeof(pause_sound)) / 6;
            sound_typ_ch1 = SND_PAUSE;
            break;
        case SND_BREAK:
            sound_cnt_ch4 = (sizeof(break_sound)) / 5;
            sound_typ_ch4 = SND_BREAK;
            break;
        case SND_SHAKE:
            sound_cnt_ch4 = (sizeof(shake_sound)) / 5;
            sound_typ_ch4 = SND_SHAKE;
            break;
    }
#else
    sound;
#endif
}

void play_sound()
{
#if defined(NINTENDO)
    if( sound_cnt_ch4 != 0 )
    {
        sound_cnt_ch4--;
        switch( sound_typ_ch4 )
        {
            case SND_SHOT:
                if( shot_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = shot_sound[sound_cnt_ch4][1];
                    NR42_REG = shot_sound[sound_cnt_ch4][2];
                    NR43_REG = shot_sound[sound_cnt_ch4][3];
                    NR44_REG = shot_sound[sound_cnt_ch4][4];
                }
                break;
            case SND_HIT:
                if( hit_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = hit_sound[sound_cnt_ch4][1];
                    NR42_REG = hit_sound[sound_cnt_ch4][2];
                    NR43_REG = hit_sound[sound_cnt_ch4][3];
                    NR44_REG = hit_sound[sound_cnt_ch4][4];
                }
                break;
            case SND_EXPLOSION:
                if( explosion_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = explosion_sound[sound_cnt_ch4][1];
                    NR42_REG = explosion_sound[sound_cnt_ch4][2];
                    NR43_REG = explosion_sound[sound_cnt_ch4][3];
                    NR44_REG = explosion_sound[sound_cnt_ch4][4];
                }
                break;
            case SND_DAMAGE:
                if( damage_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = damage_sound[sound_cnt_ch4][1];
                    NR42_REG = damage_sound[sound_cnt_ch4][2];
                    NR43_REG = damage_sound[sound_cnt_ch4][3];
                    NR44_REG = damage_sound[sound_cnt_ch4][4];
                }
                break;
            case SND_DEAD:
                if( dead_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = dead_sound[sound_cnt_ch4][1];
                    NR42_REG = dead_sound[sound_cnt_ch4][2];
                    NR43_REG = dead_sound[sound_cnt_ch4][3];
                    NR44_REG = dead_sound[sound_cnt_ch4][4];
                }
                break;
            case SND_BREAK:
                if( break_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = break_sound[sound_cnt_ch4][1];
                    NR42_REG = break_sound[sound_cnt_ch4][2];
                    NR43_REG = break_sound[sound_cnt_ch4][3];
                    NR44_REG = break_sound[sound_cnt_ch4][4];
                }
                break;
            case SND_SHAKE:
                if( shake_sound[sound_cnt_ch4][0] == 1 )
                {
                    NR41_REG = shake_sound[sound_cnt_ch4][1];
                    NR42_REG = shake_sound[sound_cnt_ch4][2];
                    NR43_REG = shake_sound[sound_cnt_ch4][3];
                    NR44_REG = shake_sound[sound_cnt_ch4][4];
                }
                break;
        }
    }
    if( sound_cnt_ch1 != 0 )
    {
        sound_cnt_ch1--;
        switch( sound_typ_ch1 )
        {
            case SND_CRYSTAL:
                if( crystal_sound[sound_cnt_ch1][0] == 1 )
                {
                    NR10_REG = crystal_sound[sound_cnt_ch1][1];
                    NR11_REG = crystal_sound[sound_cnt_ch1][2];
                    NR12_REG = crystal_sound[sound_cnt_ch1][3];
                    NR13_REG = crystal_sound[sound_cnt_ch1][4];
                    NR14_REG = crystal_sound[sound_cnt_ch1][5];
                }
                break;
            case SND_HEART:
                if( heart_sound[sound_cnt_ch1][0] == 1 )
                {
                    NR10_REG = heart_sound[sound_cnt_ch1][1];
                    NR11_REG = heart_sound[sound_cnt_ch1][2];
                    NR12_REG = heart_sound[sound_cnt_ch1][3];
                    NR13_REG = heart_sound[sound_cnt_ch1][4];
                    NR14_REG = heart_sound[sound_cnt_ch1][5];
                }
                break;
            case SND_WEAPON:
                if( weapon_sound[sound_cnt_ch1][0] == 1 )
                {
                    NR10_REG = weapon_sound[sound_cnt_ch1][1];
                    NR11_REG = weapon_sound[sound_cnt_ch1][2];
                    NR12_REG = weapon_sound[sound_cnt_ch1][3];
                    NR13_REG = weapon_sound[sound_cnt_ch1][4];
                    NR14_REG = weapon_sound[sound_cnt_ch1][5];
                }
                break;
            case SND_START:
                if( start_sound[sound_cnt_ch1][0] == 1 )
                {
                    NR10_REG = start_sound[sound_cnt_ch1][1];
                    NR11_REG = start_sound[sound_cnt_ch1][2];
                    NR12_REG = start_sound[sound_cnt_ch1][3];
                    NR13_REG = start_sound[sound_cnt_ch1][4];
                    NR14_REG = start_sound[sound_cnt_ch1][5];
                }
                break;
            case SND_PAUSE:
                if( pause_sound[sound_cnt_ch1][0] == 1 )
                {
                    NR10_REG = pause_sound[sound_cnt_ch1][1];
                    NR11_REG = pause_sound[sound_cnt_ch1][2];
                    NR12_REG = pause_sound[sound_cnt_ch1][3];
                    NR13_REG = pause_sound[sound_cnt_ch1][4];
                    NR14_REG = pause_sound[sound_cnt_ch1][5];
                }
                break;
        }
    }
#endif
}

void fade_from_white()
{
#if defined(NINTENDO)
    UBYTE i,j;
    
    for(i = 0; i != 4; i++ )
    {
        if( i == 0 )
        {
            BGP_REG = 0x00;
            OBP0_REG = 0x00;
        }
        if( i == 1 )
        {
            BGP_REG = 0x40;
            OBP0_REG = 0x40;
        }
        if( i == 2 )
        {
            BGP_REG = 0x90;
            OBP0_REG = 0x80;
        }
        if( i == 3 )
        {
            BGP_REG = 0xE4;
            OBP0_REG = 0xC4;
        }
        for(j = 0; j != 4; j++ )
        {
            play_sound();
            wait_vbl_done();
        }
    }
#endif
}

void fade_to_white()
{
#if defined(NINTENDO)
    UBYTE i,j;
    
    for(i = 0; i != 4; i++ )
    {
        if( i == 0 )
        {
            BGP_REG = 0xE4;
            OBP0_REG = 0xC4;
        }
        if( i == 1 )
        {
            BGP_REG = 0x90;
            OBP0_REG = 0x80;
        }
        if( i == 2 )
        {
            BGP_REG = 0x40;
            OBP0_REG = 0x40;
        }
        if( i == 3 )
        {
            BGP_REG = 0x00;
            OBP0_REG = 0x00;
        }
        for(j = 0; j != 4; j++ )
        {
            play_sound();
            wait_vbl_done();
        }
    }
#endif
}

UBYTE get_sprite()
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

void clear_sprite(UBYTE i)
{   
    if( i < MAX_SPRITES )
    {
        set_sprite_prop(i,0);
        hide_sprite(i);
        spr_act[i] = FALSE;
    }
}

void clear_all()
{
    UBYTE i;
    
    //sprites
    for( i = 0; i != MAX_SPRITES; i++ )
    {
        clear_sprite(i);
    }
        
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
    for( i = 0; i != MAX_MONSTER_SHOT; i++ )
    {
        monster_shot_act[i] = FALSE;
    }
    
    //item
    for( i = 0; i != MAX_ITEM; i++ )
    {
        item_act[i] = FALSE;
    }
    
    //platfrom
    for( i = 0; i != MAX_PLATFORM; i++ )
    {
        platform_act[i] = FALSE;
    }
    
    //explosion
    for( i = 0; i != MAX_EXPLOSION; i++ )
    {
        explosion_act[i] = FALSE;
    }
    
    //stone
    for( i = 0; i != MAX_STONE; i++ )
    {
        stone_act[i] = FALSE;
    }
    
    //boss
    boss_act = FALSE;   
}

void new_item(UBYTE x, UBYTE y, UBYTE type)
{
    UBYTE i;
    
    for( i = 0; i != MAX_ITEM; i++ )
    {
        if( item_act[i] == FALSE )
        {
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

void update_item()
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
            pos = (tile_x << 4) + tile_y;
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
                    item_act[i] = 0;
                    clear_sprite( item_spr[i] );
                }
            }
            
            if( item_x[i] == 240 )
            {
                item_act[i] = 0;
                clear_sprite( item_spr[i] );
            }
        }
    }   
}

void new_platform(UBYTE x, UBYTE y, UBYTE type)
{
    UBYTE i;
    
    for( i = 0; i != MAX_PLATFORM; i++ )
    {
        if( platform_act[i] == FALSE )
        {
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

void update_platform()
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
            
            if( ((platform_x[i] > 176) && (platform_x[i] < 216))|| (platform_y[i] >= 176) )
            {
                platform_act[i] = 0;
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

void new_explosion(UBYTE x, UBYTE y)
{
    UBYTE i;
    
    for( i = 0; i != MAX_EXPLOSION; i++ )
    {
        if( explosion_act[i] == FALSE )
        {
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

void update_explosion()
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
                explosion_act[i] = FALSE;
                clear_sprite(explosion_spr0[i]);
                clear_sprite(explosion_spr1[i]);
            }
        }
    }       
}

void new_stone(UBYTE x, UBYTE y, BYTE dir)
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

void update_stone()
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
                stone_act[i] = FALSE;
                clear_sprite(stone_spr[i]);
            }
        }
    }
}

void add_score(UBYTE value)
{
    static UWORD t;
    
    t = (player_score & 0x000F) + (value & 0x0F);
    if( t > 9 )
    {
        player_score += (value & 0x0F) + 6;
    } else {
        player_score += (value & 0x0F);
    }
    
    t = (player_score & 0x00F0) + (value & 0xF0);
    if( t > 0x90 )
    {
        player_score += (value & 0xF0) + 0x60;
    } else {
        player_score += (value & 0xF0);
    }
    
    t = player_score & 0x0F00;
    if( t > 0x900 )
    {
        player_score += 0x600;
    }

    update_hud(HUD_SCORE);
}

void update_hud(UBYTE type)
{
    UBYTE i,j;
    
    switch( type )
    {
        case HUD_WEAPON:
            if( player_sht == 0 )
            {
                set_bkg_tiles(VIEWPORT_X_OFS + 12,0,1,2,&hud_data[0]);
                set_bkg_tiles(VIEWPORT_X_OFS + 13,0,1,2,&hud_data[2]);
            }
            if( player_sht == 1 )
            {
                set_bkg_tiles(VIEWPORT_X_OFS + 12,0,1,2,&hud_data[4]);
                set_bkg_tiles(VIEWPORT_X_OFS + 13,0,1,2,&hud_data[6]);
            }
            if( player_sht == 2 )
            {
                set_bkg_tiles(VIEWPORT_X_OFS + 12,0,1,2,&hud_data[8]);
                set_bkg_tiles(VIEWPORT_X_OFS + 13,0,1,2,&hud_data[10]);
            }
            break;
        case HUD_LIFE:
            for( i = 0; i != 4; i++ )
            {
                if( i <= (player_lif-1) )
                {
                    set_bkg_tiles(VIEWPORT_X_OFS + 7+i,1,1,1,&hud_data[12]);
                } else {
                    set_bkg_tiles(VIEWPORT_X_OFS + 7+i,1,1,1,&hud_data[13]);
                }
            }
            break;
        case HUD_SCORE:
            for( i = 0; i != 4; i++ )
            {
                j = (player_score >> (i<<2)) & 0x0F;
                set_bkg_tiles(VIEWPORT_X_OFS + 3-i,1,1,1,&hud_data[14+j]);  
            }
            break;
        case HUD_LEVEL:
            set_bkg_tiles(VIEWPORT_X_OFS + 15,1,1,1,&hud_data[14+level_maj]);
            set_bkg_tiles(VIEWPORT_X_OFS + 17,1,1,1,&hud_data[14+level_min]);
            break;
    }
}
