#pragma bank 3

#include <gbdk/platform.h>

#include "global.h"

#include "music_data.h"

inline UBYTE translete_env(UBYTE env) {
#ifdef MEGADUCK
    return ((UBYTE)(env << 4) | (UBYTE)(env >> 4));
#else
    return env;
#endif
}

const UWORD frequency[] =
{
    44, 156, 262, 363, 457, 547, 631, 710, 786, 854, 923, 986,
    1046, 1102, 1155, 1205, 1253, 1297, 1339, 1379, 1417, 1452, 1486, 1517,
    1546, 1575, 1602, 1627, 1650, 1673, 1694, 1714, 1732, 1750, 1767, 1783,
    1798, 1812, 1825, 1837, 1849, 1860, 1871, 1881, 1890, 1899, 1907, 1915,
    1923, 1930, 1936, 1943, 1949, 1954, 1959, 1964, 1969, 1974, 1978, 1982,
    1985, 1988, 1992, 1995, 1998, 2001, 2004, 2006, 2009, 2011, 2013, 2015,
    0
};

//wave channel
const unsigned char inst_ch3[] = {0x34,0x45,0x56,0x67,0x89,0x9A,0xAB,0xBC,0x34,0x45,0x56,0x67,0x89,0x9A,0xAB,0xBC};

volatile unsigned char __at (0xFF30) wave[16];

UBYTE music_play;

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
    UBYTE i;

    //sound init
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    for( i = 0; i != 16; i++ )
    {
        wave[i] = inst_ch3[i];
    }
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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            /*
            for( i = 0; i != 16; i++ )
            {
                wave[i] = data_ch3[i];
            }*/

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
            music_cnt_ch1 = *music_ptr_ch1;
            music_ptr_ch1++;
            freq = frequency[*music_ptr_ch1];
            music_ptr_ch1++;

            if( sound_cnt_ch1 == 0 )
            {
                if( freq == 0 )
                {
                    NR10_REG = 0;
                    NR11_REG = 0;
                    NR12_REG = 0;
                    NR13_REG = 0;
                    NR14_REG = 0;
                } else {
                    NR10_REG = 0;
                    NR11_REG = inst_ch1;
                    NR12_REG = translete_env(vol_ch1);
                    NR13_REG = freq & 0x00FF;
                    NR14_REG = 0x80 | ((freq >> 8) & 0x0007);
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
                NR21_REG = 0;
                NR22_REG = 0;
                NR23_REG = 0;
                NR24_REG = 0;
            } else {
                NR21_REG = inst_ch2;
                NR22_REG = translete_env(vol_ch2);
                NR23_REG = freq & 0x00FF;
                NR24_REG = 0x80 | ((freq >> 8) & 0x0007);
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
            music_cnt_ch3 = *music_ptr_ch3;
            music_ptr_ch3++;
            freq = frequency[*music_ptr_ch3];
            music_ptr_ch3++;

            if( freq == 0 )
            {
                NR30_REG = 0;
                NR31_REG = 0;
                NR32_REG = 0;
                NR33_REG = 0;
                NR34_REG = 0;
            } else {
                NR30_REG = 0x80;
                NR31_REG = 0xFF;
                NR32_REG = translete_env(0x20);
                NR33_REG = freq & 0x00FF;
                NR34_REG = 0x80 | ((freq >> 8) & 0x0007);
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
                    NR41_REG = 0;
                    NR42_REG = 0;
                    NR43_REG = 0;
                    NR44_REG = 0;
                } else {
                    NR41_REG = 0xFF;
                    NR42_REG = translete_env(0x90);
                    NR43_REG = translete_env(cwd);
                    NR44_REG = 0x80;
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
    NR12_REG = 0;
    NR14_REG = 0;

    NR22_REG = 0;
    NR24_REG = 0;

    NR32_REG = 0;
    NR34_REG = 0;

    NR42_REG = 0;
    NR44_REG = 0;

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
