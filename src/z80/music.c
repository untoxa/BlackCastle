#pragma bank 1

#include <gbdk/platform.h>

#include "global.h"
#include "music_data.h"

extern const UWORD frequency[];

UBYTE music_play = FALSE;

const unsigned char *music_data_ch1;
const unsigned char *music_ptr_ch1;
UBYTE music_cnt_ch1;
UBYTE inst_ch1;
UBYTE vol_ch1;

const unsigned char *music_data_ch2;
const unsigned char *music_ptr_ch2;
UBYTE music_cnt_ch2;
UBYTE inst_ch2;
UBYTE vol_ch2;

const unsigned char *music_data_ch3;
const unsigned char *music_ptr_ch3;
UBYTE music_cnt_ch3;

const unsigned char *music_data_ch4;
const unsigned char *music_ptr_ch4;
UBYTE music_cnt_ch4;

void init_sound(void) BANKED
{
    PSG = PSG_LATCH | PSG_CH0, PSG = 0;
    PSG = PSG_LATCH | PSG_CH1, PSG = 0;
    PSG = PSG_LATCH | PSG_CH2, PSG = 0;
    PSG = PSG_LATCH | PSG_CH3, PSG = 0;
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
            vol_ch1 = 0x01;

            music_data_ch2 = title_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0x00;
            vol_ch2 = 0x04;

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
            vol_ch1 = 0x01;

            music_data_ch2 = game_over_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0x80;
            vol_ch2 = 0x04;

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
            vol_ch1 = 0x01;

            music_data_ch2 = boss_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0xC0;
            vol_ch2 = 0x04;

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
            vol_ch1 = 0x01;

            music_data_ch2 = level1_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0x40;
            vol_ch2 = 0x04;

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
            vol_ch1 = 0x01;

            music_data_ch2 = level2_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0x00;
            vol_ch2 = 0x04;

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
            vol_ch1 = 0x01;

            music_data_ch2 = level3_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0x40;
            vol_ch2 = 0x04;

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
            vol_ch1 = 0x01;

            music_data_ch2 = end_music_lead;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            inst_ch2 = 0xC0;
            vol_ch2 = 0x04;

            music_data_ch3 = end_music_bass;
            music_ptr_ch3 = music_data_ch3;
            music_cnt_ch3 = 0;

            music_data_ch4 = end_music_rythm;
            music_ptr_ch4 = music_data_ch4;
            music_cnt_ch4 = 0;
            break;
    }
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
            music_cnt_ch1 = *music_ptr_ch1++;
            freq = frequency[*music_ptr_ch1++];

            if( sound_cnt_ch1 == 0 )
            {
                if( freq == 0 )
                {
                    PSG = PSG_LATCH | PSG_CH0, PSG = 0;
                } else {
                    PSG = PSG_LATCH | PSG_CH0 | PSG_VOLUME | vol_ch1;
                    PSG = PSG_LATCH | PSG_CH0 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
//                    PSG = PSG_LATCH | PSG_CH0 | ((freq >> 8) & 0x07), PSG = (UBYTE)freq;
//                    NR11_REG = inst_ch1;
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
            music_cnt_ch2 = *music_ptr_ch2++;
            freq = frequency[*music_ptr_ch2++];

            if( freq == 0 )
            {
                PSG = PSG_LATCH | PSG_CH1, PSG = 0;
            } else {
                PSG = PSG_LATCH | PSG_CH1 | PSG_VOLUME | vol_ch2;
                PSG = PSG_LATCH | PSG_CH1 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
//                NR21_REG = inst_ch2;
            }

            if( *music_ptr_ch2 == 0 )
            {
                music_ptr_ch2 = music_data_ch2;
            }
        }
        music_cnt_ch2--;

        //channel3
        if( music_cnt_ch3 == 0 )
        {
            music_cnt_ch3 = *music_ptr_ch3++;
            freq = frequency[*music_ptr_ch3++];

            if( freq == 0 )
            {
                PSG = PSG_LATCH | PSG_CH2, PSG = 0;
            } else {
//                NR30_REG = 0x80;
//                NR31_REG = 0xFF;
//                NR32_REG = translate_volume(0x20);
//                NR33_REG = freq & 0x00FF;
//                NR34_REG = 0x80 | ((freq >> 8) & 0x0007);
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
            music_cnt_ch4 = *music_ptr_ch4++;
            cwd = *music_ptr_ch4++;
            if( sound_cnt_ch4 == 0 )
            {
                if( cwd == 0 )
                {
                    PSG = PSG_LATCH | PSG_CH3, PSG = 0;
                } else {
//                    NR41_REG = 0xFF;
//                    NR42_REG = translate_envelope(0x90);
//                    NR43_REG = translate_frequency(cwd);
//                    NR44_REG = 0x80;
                }
            }
            if( *music_ptr_ch4 == 0 )
            {
                music_ptr_ch4 = music_data_ch4;
            }
        }
        music_cnt_ch4--;
    }
}

void stop_music(void) BANKED
{
    music_play = FALSE;

    PSG = PSG_LATCH | PSG_CH0 | PSG_VOLUME | 0x0f;
    PSG = PSG_LATCH | PSG_CH1 | PSG_VOLUME | 0x0f;
    PSG = PSG_LATCH | PSG_CH2 | PSG_VOLUME | 0x0f;
    PSG = PSG_LATCH | PSG_CH3 | PSG_VOLUME | 0x0f;
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
