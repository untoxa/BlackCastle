#include <gbdk/platform.h>

#include "global.h"

#if defined(NINTENDO)

void lcd_isr(void) {
    if (game_state == GS_LEVEL) {
        while(STAT_REG & STATF_LCD);
        move_bkg(scroll_pos,0);
        SHOW_SPRITES;
        if (shake != 0) {
            shake--;
            if((shake & 1) == 1) {
                scroll_bkg(0,1);
            } else {
                scroll_bkg(0,-1);
            }
        }
    }
}

void vbl_isr(void) {
    if (game_state == GS_LEVEL) {
        move_bkg(0,0);
        HIDE_SPRITES;
    }
}

#elif defined(SEGA)

static uint8_t scroll_target = 0;
void vbl_isr(void) {
    if (_shadow_OAM_OFF) return;
    if (game_state == GS_LEVEL) {
        if (shake) {
            shake--;
            scroll_target = (shake & 1) ? -(scroll_pos + 1) : -(scroll_pos - 1);
        } else {
            scroll_target = -scroll_pos;
        }
#ifdef GAMEGEAR
        VDP_CMD = 0, VDP_CMD = VDP_RSCX;
        switch (++level_ani & 7) {
            case 0:
                set_bkg_data(13,1,candle_tiles + 16);
                break;
            case 2:
                set_bkg_data(13,1,candle_tiles);
                break;
        }
        while (VCOUNTER != 39);
#endif
        VDP_CMD = scroll_target, VDP_CMD = VDP_RSCX;
    }
}

void lcd_isr(void) {
}

#elif defined(NINTENDO_NES)

void vbl_isr(void) {
    if (game_state == GS_LEVEL) {
        move_bkg(0,0);
        HIDE_SPRITES;
        if (shake != 0) {
            shake--;
            if( (shake & 1) == 1 ) {
                scroll_pos_with_shake = (UBYTE)scroll_pos + 1;
            } else {
                scroll_pos_with_shake = (UBYTE)scroll_pos - 1;
            }
        } else {
            scroll_pos_with_shake = (UBYTE)scroll_pos;
        }
    } else {
        scroll_pos_with_shake = (UBYTE)scroll_pos;
    }
}

void lcd_isr(void) {
    // Write directly to hardware scroll registers (only first write will have an effect)
    PPUSCROLL = scroll_pos_with_shake;
    PPUSCROLL = 0; // 2nd write (dummy)
    if( game_state == GS_LEVEL ) {
        //move_bkg(scroll_pos,0);
        // Write directly to hardware register PPUMASK instead of shadow register
        PPUMASK = shadow_PPUMASK | PPUMASK_SHOW_SPR;
    }
}

extern uint8_t _lcd_scanline;

#endif

void main(void)
{
    DISPLAY_OFF;
    HIDE_SPRITES;
#if defined(NINTENDO)
    HIDE_WIN;
#endif
    HIDE_BKG;
    SPRITES_8x16;

#if defined(NINTENDO)
    BGP_REG = 0x00;

    CRITICAL {
        LYC_REG = 0x0F;
        STAT_REG = STATF_LYC;
        add_LCD(lcd_isr);
        add_VBL(vbl_isr);
    }
    set_interrupts (VBL_IFLAG | LCD_IFLAG);
#elif defined(SEGA)
    __WRITE_VDP_REG(VDP_R2, R2_MAP_0x3800); __WRITE_VDP_REG(VDP_R5, R5_SAT_0x3F00);
    set_sprite_palette_entry(0,4, RGB8(255, 255, 255));
    CRITICAL {
        add_VBL(vbl_isr);
    }
    set_interrupts (VBL_IFLAG);
    __WRITE_VDP_REG(VDP_R0, __READ_VDP_REG(VDP_R0) | R0_HSCRL_INH | R0_LCB);
#elif defined(NINTENDO_NES)
    add_VBL(vbl_isr);
    set_sprite_palette_entry(0,2, RGB8(255, 255, 255));
    _lcd_scanline = 8 * (2 + VIEWPORT_Y_OFS);
#endif
    init_sound();

    high_score = 0;
    game_state = GS_TITLE;

    while(TRUE) (state_handlers[game_state])();
}