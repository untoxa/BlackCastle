#pragma bank 255

#include <gbdk/platform.h>
#include "music.h"

static const palette_color_t palettes[4][4] =
{ {0x30, 0x30, 0x30, 0x30},
  {0x30, 0x30, 0x30, 0x10},
  {0x30, 0x30, 0x10, 0x00},
  {0x30, 0x10, 0x00, 0x1D} };

void fade_from_white(void) BANKED
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
        set_sprite_palette(0, 4, palettes[i]);
        set_sprite_palette_entry(0,2, RGB8(255, 255, 255));
        for(j = 0; j != 4; j++ )
        {
            play_sound();
            wait_vbl_done();
        }
    }
#endif
}

void fade_to_white(void) BANKED
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
        set_sprite_palette(0, 4, palettes[3-i]);
        set_sprite_palette_entry(0,2, RGB8(255, 255, 255));
        for(j = 0; j != 4; j++ )
        {
            play_sound();
            wait_vbl_done();
        }
    }
#endif
}
