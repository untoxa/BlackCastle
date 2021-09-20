#include <gbdk/platform.h>

#include "global.h"

#if defined(NINTENDO)
void lcd_isr()
{
	if( game_state == GS_LEVEL )
	{
		while( STAT_REG & 3 );
		move_bkg(scroll_pos,0);		
		SHOW_SPRITES;
		if( shake != 0 )
		{
			shake--;
			if( (shake & 1) == 1 )
			{
				scroll_bkg(0,1);
			} else {
				scroll_bkg(0,-1);
			}
		}
	}
}

void vbl_isr()
{
	if( game_state == GS_LEVEL )
	{
		move_bkg(0,0);
		HIDE_SPRITES;
	}
}
#elif defined(SEGA)
void vbl_isr()
{
	if (_shadow_OAM_OFF) return;
	if( game_state == GS_LEVEL )
	{
		if( shake != 0 )
		{
			shake--;
			if( (shake & 1) == 1 )
			{
				VDP_CMD = -(scroll_pos + 1); VDP_CMD = VDP_RSCX;
			} else {
				VDP_CMD = -scroll_pos - 1; VDP_CMD = VDP_RSCX;
			}
		} else {
			VDP_CMD = -scroll_pos; VDP_CMD = VDP_RSCX;
		}
	}
}
#endif

void main()
{	
	DISPLAY_OFF;
	HIDE_SPRITES;
	HIDE_WIN;
	HIDE_BKG;
	
	SPRITES_8x16;

#if defined(NINTENDO)
	BGP_REG = 0x00;

	CRITICAL {
		LYC_REG = 0x0F;
		STAT_REG = 0x40;
		add_LCD(lcd_isr);
		add_VBL(vbl_isr);
		set_interrupts( VBL_IFLAG | LCD_IFLAG );
	}
#elif defined(SEGA)
	set_sprite_palette_entry(0,4, RGB8(255, 255, 255));
	CRITICAL {
		add_VBL(vbl_isr);
		set_interrupts( VBL_IFLAG | LCD_IFLAG );
	}
	__WRITE_VDP_REG(VDP_R0, __READ_VDP_REG(VDP_R0) | R0_HSCRL_INH | R0_LCB);
#endif
	init_sound();
	
	high_score = 0;
	game_state = GS_TITLE;
	
	while(TRUE) (state_handlers[game_state])();
}