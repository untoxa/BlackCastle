#pragma bank 3

#include <gbdk/platform.h>

#include "global.h"

#include "music_data.h"
#include "music.h"

inline UBYTE translete_env(UBYTE env) {
#ifdef MEGADUCK
    return ((UBYTE)(env << 4) | (UBYTE)(env >> 4));
#else
	return env;
#endif
}

const UWORD frequency[] =
{ 
  0x7f1,0x77f,0x713,0x6ad,0x64d,0x5f3,0x59d,0x54c,0x500,0x4b8,0x474,0x434,
  0x3f8,0x3bf,0x389,0x356,0x326,0x2f9,0x2ce,0x2a6,0x280,0x25c,0x23a,0x21a,
  0x1fb,0x1df,0x1c4,0x1ab,0x193,0x17c,0x167,0x152,0x13f,0x12d,0x11c,0x10c,
  0x0fd,0x0ef,0x0e1,0x0d5,0x0c9,0x0bd,0x0b3,0x0a9,0x09f,0x096,0x08e,0x086,
  0x07e,0x077,0x070,0x06a,0x064,0x05e,0x059,0x054,0x04f,0x04b,0x046,0x042,
  0x03f,0x03b,0x038,0x034,0x031,0x02f,0x02c,0x029,0x027,0x025,0x023,0x021,
  0x000
};

UBYTE music_play;

const unsigned char *music_data_ch1;
const unsigned char *music_ptr_ch1;
UBYTE music_cnt_ch1;
UBYTE inst_ch1;
UBYTE vol_ch1;
UBYTE vol_ch1_t;
UBYTE env_ch1;
UBYTE tim_ch1;
UBYTE len_ch1;

const unsigned char *music_data_ch2;
const unsigned char *music_ptr_ch2;
UBYTE music_cnt_ch2;
UBYTE inst_ch2;
UBYTE vol_ch2;
UBYTE env_ch2;
UBYTE tim_ch2;
UBYTE len_ch2;

UBYTE shadow4000;

const unsigned char *music_data_ch3;
const unsigned char *music_ptr_ch3;
UBYTE music_cnt_ch3;

const unsigned char *music_data_ch4;
const unsigned char *music_ptr_ch4;
UBYTE music_cnt_ch4;

UBYTE env_ch4;
UBYTE vol_ch4;
UBYTE vol_ch4;
UBYTE tim_ch4;
UBYTE len_ch4;

void init_sound(void) BANKED
{
	//sound init
	_SND4015 = 0x0F; // Enable all 4 channels
}

void set_music(UBYTE song) BANKED
{
	music_play = TRUE;
		
	switch( song )
	{
		case TITLE_MUSIC:
			music_data_ch1 = title_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x80;
			vol_ch1 = 0x92;
						
			music_data_ch2 = title_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0x00;
			vol_ch2 = 0x70;

			music_data_ch3 = title_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = title_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
		case GAME_OVER_MUSIC:
			music_data_ch1 = game_over_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x40;
			vol_ch1 = 0x92;
			
			music_data_ch2 = game_over_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0x80;
			vol_ch2 = 0x70;

			music_data_ch3 = game_over_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = game_over_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
		case BOSS_MUSIC:
			music_data_ch1 = boss_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x00;
			vol_ch1 = 0x91;
			
			music_data_ch2 = boss_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0xC0;
			vol_ch2 = 0x70;

			music_data_ch3 = boss_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = boss_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
		case LEVEL1_MUSIC:
			music_data_ch1 = level1_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x80;
			vol_ch1 = 0x92;
			
			music_data_ch2 = level1_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0x40;
			vol_ch2 = 0x70;

			music_data_ch3 = level1_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = level1_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
		case LEVEL2_MUSIC:
			music_data_ch1 = level2_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x80;
			vol_ch1 = 0x92;
			
			music_data_ch2 = level2_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0x00;
			vol_ch2 = 0x70;

			music_data_ch3 = level2_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = level2_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
		case LEVEL3_MUSIC:
			music_data_ch1 = level3_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x80;
			vol_ch1 = 0x92;
			
			music_data_ch2 = level3_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0x40;
			vol_ch2 = 0x70;

			music_data_ch3 = level3_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = level3_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
		case END_MUSIC:
			music_data_ch1 = end_music_lead;
			music_ptr_ch1 = music_data_ch1;
			music_cnt_ch1 = 0;
			inst_ch1 = 0x80;
			vol_ch1 = 0x92;
			
			music_data_ch2 = end_music_lead;
			music_ptr_ch2 = music_data_ch2;
			music_cnt_ch2 = 0;
			inst_ch2 = 0xC0;
			vol_ch2 = 0x70;

			music_data_ch3 = end_music_bass;
			music_ptr_ch3 = music_data_ch3;
			music_cnt_ch3 = 0;
			
			music_data_ch4 = end_music_rythm;
			music_ptr_ch4 = music_data_ch4;
			music_cnt_ch4 = 0;
			break;
	}
}

//
// Emulates the GameBoy's hardware volume envelope on the NES.
// Calling this at 60Hz will be close-enough to the
// 64Hz update rate the GB hardware envelope updates at.
//
inline void emulate_gb_volume_envelope(void)
{
    // Emulate GB hardware envelope with code
    if(tim_ch1 && --tim_ch1 == 0)
    {
        tim_ch1 = vol_ch1_t & 0x7;
        if(env_ch1)
            env_ch1 -= 1;
    }
    if(tim_ch2 && --tim_ch2 == 0)
    {
        tim_ch2 = vol_ch2 & 0x7;
        if(env_ch2)
            env_ch2 -= 1;
    }
    if(tim_ch4 && --tim_ch4 == 0)
    {
        tim_ch4 = vol_ch4 & 0x7;
        if(env_ch4)
            env_ch4 -= 1;
    }
    // Emulate GB length counter with code
    if(len_ch1 && --len_ch1 == 0)
    {
        env_ch1 = vol_ch1_t >> 4;
    }
    if(len_ch2 && --len_ch2 == 0)
    {
        env_ch2 = vol_ch2 >> 4;
    }
    _SND4000 = env_ch1 | (shadow4000 & 0xF0);
    _SND4004 = env_ch2 | 0x30 | (inst_ch2 & 0xC0);
    _SND400C = env_ch4 | 0x30;
}

void play_music(void) BANKED
{
	UWORD freq;
	UBYTE cwd;
	
	if( music_play == TRUE )
	{
		//channel1
		if( music_cnt_ch1 == 0 )
		{	
			music_cnt_ch1 = *music_ptr_ch1;
			music_ptr_ch1++;
			freq = frequency[*music_ptr_ch1];
			music_ptr_ch1++;
			
			if( sound_cnt_ch1 == 0 )
			{
				if( freq == 0 )
				{
                    env_ch1 = 0;
                    _SND4000 = 0x10;
                    _SND4001 = 0x08;    // Disable sweep
				} else {
                    env_ch1 = vol_ch1 >> 4;
                    tim_ch1 = vol_ch1 & 0x7;
                    vol_ch1_t = vol_ch1;
                    shadow4000 = env_ch1 | 0x30 | (inst_ch1 & 0xC0);
                    _SND4000 = shadow4000;
                    _SND4001 = 0x08;
                    _SND4002 = freq & 0xFF;
                    _SND4003 = ((freq >> 8) & 0x0007);
                    len_ch1 = (inst_ch1 & 0x3F) >> 2;
				}
			}
						
			if( *music_ptr_ch1 == 0 )
			{
				music_ptr_ch1 = music_data_ch1;
			}
		} 
		music_cnt_ch1--;
		
		//channel2
		if( music_cnt_ch2 == 0 )
		{	
			music_cnt_ch2 = *music_ptr_ch2;
			music_ptr_ch2++;
			freq = frequency[*music_ptr_ch2];
			music_ptr_ch2++;
			
			if( freq == 0 )
			{
                env_ch2 = 0;                
                _SND4004 = 0x10;
                //_SND4007 = 0x00;
			} else {
                env_ch2 = vol_ch2 >> 4;
                tim_ch2 = vol_ch2 & 0x7;
                _SND4004 = env_ch2 | 0x30 | (inst_ch2 & 0xC0);
                _SND4005 = 0x7F;
                _SND4006 = freq & 0xFF;
                _SND4007 = ((freq >> 8) & 0x0007);
                len_ch2 = (inst_ch2 & 0x3F) >> 3;
			}
			
			if( *music_ptr_ch2 == 0 )
			{
				music_ptr_ch2 = music_data_ch2;
			}
		} 
		music_cnt_ch2--;
		
		//channel3
		//if( music_cnt_ch3 == 0 )
			if( music_cnt_ch3 < 4 )
			{
                _SND4008 = 0x00;
            }
        if( music_cnt_ch3 == 0 )
		{	
			music_cnt_ch3 = *music_ptr_ch3;
			music_ptr_ch3++;
			freq = frequency[*music_ptr_ch3] << 1;
			music_ptr_ch3++;
			
			if( freq == 0 )
			{
                _SND4008 = 0x00;
			} else {
                _SND4008 = 0xFF;
                _SND400A = freq & 0xFF;
                _SND400B = ((freq >> 8) & 0x0007);
			}
				
			if( *music_ptr_ch3 == 0 )
			{
				music_ptr_ch3 = music_data_ch3;
			}	
		} 
		music_cnt_ch3--;	
			
		//channel4
		if( music_cnt_ch4 == 0 )
		{	
			music_cnt_ch4 = *music_ptr_ch4;
			music_ptr_ch4++;
			cwd = *music_ptr_ch4;
			music_ptr_ch4++;
			if( sound_cnt_ch4 == 0 )
			{
				if( cwd == 0 )
				{
                    env_ch4 = 0;                
                    _SND4004 = 0x10;
				} else {
                    vol_ch4 = 0x90;
                    env_ch4 = vol_ch4 >> 4;
                    tim_ch4 = 0x90 & 0x7;
                    _SND400C = env_ch4 | 0x30;
                    _SND400E = cwd;
                    _SND400F = 0xFF;
				}
			}
			if( *music_ptr_ch4 == 0 )
			{
				music_ptr_ch4 = music_data_ch4;
			}	
		} 
		music_cnt_ch4--;	
	}
    emulate_gb_volume_envelope();
}

void stop_music(void) BANKED
{
    shadow4000 = 0x10;
    _SND4000 = shadow4000;
    _SND4004 = 0x10;
    _SND4008 = 0x00;
    _SND400C = 0x10;
	music_play = FALSE;
}

void restart_music(void) BANKED
{
	music_play = TRUE;
	
	music_cnt_ch1 = 0;
	music_cnt_ch2 = 0;
	music_cnt_ch3 = 0;
	music_cnt_ch4 = 0;	
	
	music_ptr_ch1 = music_data_ch1;
	music_ptr_ch2 = music_data_ch2;
	music_ptr_ch3 = music_data_ch3;
	music_ptr_ch4 = music_data_ch4;
}
