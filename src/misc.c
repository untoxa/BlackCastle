#include <gbdk/platform.h>

#include "global.h"

const unsigned char scroll_seam_hide_tile[] =
{
    0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
    0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
    0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
    0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF
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


//sprites
extern UBYTE spr_act[MAX_SPRITES];

//item
extern UBYTE item_act[MAX_ITEM];
extern UBYTE item_x[MAX_ITEM];
extern UBYTE item_y[MAX_ITEM];
extern UBYTE item_spr[MAX_ITEM];
extern UBYTE item_typ[MAX_ITEM];
extern BYTE item_vel[MAX_ITEM];

//platform
extern UBYTE platform_act[MAX_PLATFORM];
extern UBYTE platform_x[MAX_PLATFORM];
extern UBYTE platform_y[MAX_PLATFORM];
extern UBYTE platform_spr0[MAX_PLATFORM];
extern UBYTE platform_spr1[MAX_PLATFORM];
extern UBYTE platform_typ[MAX_PLATFORM];
extern BYTE platform_dir[MAX_PLATFORM];
extern UBYTE platform_pos[MAX_PLATFORM];
extern BYTE platform_vel[MAX_PLATFORM];

//explosion
extern UBYTE explosion_act[MAX_EXPLOSION];
extern UBYTE explosion_x[MAX_EXPLOSION];
extern UBYTE explosion_y[MAX_EXPLOSION];
extern UBYTE explosion_spr0[MAX_EXPLOSION];
extern UBYTE explosion_spr1[MAX_EXPLOSION];
extern UBYTE explosion_ani[MAX_EXPLOSION];

//stone
extern UBYTE stone_act[MAX_STONE];
extern UBYTE stone_x[MAX_STONE];
extern UBYTE stone_y[MAX_STONE];
extern UBYTE stone_spr[MAX_STONE];
extern BYTE stone_dir[MAX_STONE];
extern BYTE stone_vel[MAX_STONE];


const palette_color_t palettes[4][4] =
{ {0x30, 0x30, 0x30, 0x30},
  {0x30, 0x30, 0x30, 0x10},
  {0x30, 0x30, 0x10, 0x00},
  {0x30, 0x10, 0x00, 0x1D} };

void fade_from_white(void)
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
#elif !defined(SEGA)
    UBYTE i,j;

    for(i = 0; i != 4; i++ )
    {
        set_bkg_palette(0, 4, palettes[i]);
        set_sprite_palette(4, 4, palettes[i]);
        set_sprite_palette_entry(0,2, RGB8(255, 255, 255));
        for(j = 0; j != 4; j++ )
        {
            play_sound();
            wait_vbl_done();
        }
    }
#endif
}

void fade_to_white(void)
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
#elif !defined(SEGA)
    UBYTE i,j;

    for(i = 0; i != 4; i++ )
    {
        set_bkg_palette(0, 4, palettes[3-i]);
        set_sprite_palette(4, 4, palettes[3-i]);
        set_sprite_palette_entry(0,2, RGB8(255, 255, 255));
        for(j = 0; j != 4; j++ )
        {
            play_sound();
            wait_vbl_done();
        }
    }
#endif
}

UBYTE get_sprite(void)
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
                set_bkg_tiles(VIEWPORT_X_OFS + 12,VIEWPORT_Y_OFS,1,2,&hud_data[0]);
                set_bkg_tiles(VIEWPORT_X_OFS + 13,VIEWPORT_Y_OFS,1,2,&hud_data[2]);
            }
            if( player_sht == 1 )
            {
                set_bkg_tiles(VIEWPORT_X_OFS + 12,VIEWPORT_Y_OFS,1,2,&hud_data[4]);
                set_bkg_tiles(VIEWPORT_X_OFS + 13,VIEWPORT_Y_OFS,1,2,&hud_data[6]);
            }
            if( player_sht == 2 )
            {
                set_bkg_tiles(VIEWPORT_X_OFS + 12,VIEWPORT_Y_OFS,1,2,&hud_data[8]);
                set_bkg_tiles(VIEWPORT_X_OFS + 13,VIEWPORT_Y_OFS,1,2,&hud_data[10]);
            }
            break;
        case HUD_LIFE:
            for( i = 0; i != 4; i++ )
            {
                if( i <= (player_lif-1) )
                {
                    set_bkg_tiles(VIEWPORT_X_OFS + 7+i,1 + VIEWPORT_Y_OFS,1,1,&hud_data[12]);
                } else {
                    set_bkg_tiles(VIEWPORT_X_OFS + 7+i,1 + VIEWPORT_Y_OFS,1,1,&hud_data[13]);
                }
            }
            break;
        case HUD_SCORE:
            for( i = 0; i != 4; i++ )
            {
                j = (player_score >> (i<<2)) & 0x0F;
                set_bkg_tiles(VIEWPORT_X_OFS + 3-i,1 + VIEWPORT_Y_OFS,1,1,&hud_data[14+j]);
            }
            break;
        case HUD_LEVEL:
            set_bkg_tiles(VIEWPORT_X_OFS + 15,1 + VIEWPORT_Y_OFS,1,1,&hud_data[14+level_maj]);
            set_bkg_tiles(VIEWPORT_X_OFS + 17,1 + VIEWPORT_Y_OFS,1,1,&hud_data[14+level_min]);
            break;
    }
}
