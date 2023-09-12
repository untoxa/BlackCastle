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
    switch( type )
    {
        case HUD_WEAPON:
            switch (player_sht) {
                case 0:
                    set_bkg_tiles(VIEWPORT_X_OFS + 12,VIEWPORT_Y_OFS,1,2,&hud_data[0]);
                    set_bkg_tiles(VIEWPORT_X_OFS + 13,VIEWPORT_Y_OFS,1,2,&hud_data[2]);
                    break;
                case 1:
                    set_bkg_tiles(VIEWPORT_X_OFS + 12,VIEWPORT_Y_OFS,1,2,&hud_data[4]);
                    set_bkg_tiles(VIEWPORT_X_OFS + 13,VIEWPORT_Y_OFS,1,2,&hud_data[6]);
                    break;
                case 2:
                    set_bkg_tiles(VIEWPORT_X_OFS + 12,VIEWPORT_Y_OFS,1,2,&hud_data[8]);
                    set_bkg_tiles(VIEWPORT_X_OFS + 13,VIEWPORT_Y_OFS,1,2,&hud_data[10]);
                    break;
            }
            break;
        case HUD_LIFE:
            for (UBYTE i = 0; i != 4; i++)
            {
                set_bkg_tiles(VIEWPORT_X_OFS + 7 + i, 1 + VIEWPORT_Y_OFS, 1, 1, (i < player_lif) ? &hud_data[12] : &hud_data[13]);
            }
            break;
        case HUD_SCORE:
            for (UBYTE i = 0; i != 4; i++)
            {
                UBYTE j = (player_score >> (i << 2)) & 0x0F;
                set_bkg_tiles(VIEWPORT_X_OFS + 3 - i, 1 + VIEWPORT_Y_OFS, 1, 1, &hud_data[14 + j]);
            }
            break;
        case HUD_LEVEL:
            set_bkg_tiles(VIEWPORT_X_OFS + 15, 1 + VIEWPORT_Y_OFS, 1, 1, &hud_data[14 + level_maj]);
            set_bkg_tiles(VIEWPORT_X_OFS + 17, 1 + VIEWPORT_Y_OFS, 1, 1, &hud_data[14 + level_min]);
            break;
    }
}
