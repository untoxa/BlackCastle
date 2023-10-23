#pragma bank 1

#include <gbdk/platform.h>

#include "global.h"
#include "music_data.h"

#define SILENT 0
#define PIANO 1
#define BASS 2
#define SNARE_NOISE_SOLO 3
#define KICK_NOISE_SOLO 4

extern const UWORD frequency[];
extern const UBYTE instruments_releases[];
extern const UBYTE *instruments_volumes[];

UBYTE music_play = FALSE;

const unsigned char *music_data_ch1;
const unsigned char *music_ptr_ch1;
UBYTE music_cnt_ch1;
UBYTE music_inst_cnt_ch1;
UBYTE inst_ch1;
UBYTE vol_ch1;
UBYTE* instruments_ch1;
UBYTE instruments_index_ch1;

const unsigned char *music_data_ch2;
const unsigned char *music_ptr_ch2;
UBYTE music_cnt_ch2;
UBYTE music_inst_cnt_ch2;
UBYTE inst_ch2;
UBYTE vol_ch2;
UBYTE* instruments_ch2;
UBYTE instruments_index_ch2;

const unsigned char *music_data_ch3;
const unsigned char *music_ptr_ch3;
UBYTE music_cnt_ch3;
UBYTE music_inst_cnt_ch3;
UBYTE inst_ch3;
UBYTE* instruments_ch3;
UBYTE instruments_index_ch3;

const unsigned char *music_data_ch4;
const unsigned char *music_ptr_ch4;
UBYTE music_cnt_ch4;
UBYTE music_inst_cnt_ch4;
UBYTE inst_ch4;
UBYTE* instruments_ch4;
UBYTE instruments_index_ch4;



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
            music_inst_cnt_ch1 = 0;
            instruments_ch1 = title_music_lead_instruments;
            instruments_index_ch1 = 0;

            music_data_ch2 = title_music_bass;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            music_inst_cnt_ch2 = 0;
            instruments_ch2 = title_music_bass_instruments;
            instruments_index_ch2 = 0;

            music_data_ch3 = title_music_rythm;
            music_ptr_ch3 = music_data_ch3;
            music_cnt_ch3 = 0;
            music_inst_cnt_ch3 = 0;
            instruments_ch3 = title_music_tone3_instruments;
            instruments_index_ch3 = 0;

            music_data_ch4 = title_music_rythm;
            music_ptr_ch4 = music_data_ch4;
            music_cnt_ch4 = 0;
            music_inst_cnt_ch4 = 0;
            instruments_ch4 = title_music_rythm_instruments;
            instruments_index_ch4 = 0;
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
            music_inst_cnt_ch1 = 0;
            instruments_ch1 = title_music_lead_instruments;
            instruments_index_ch1 = 0;

            music_data_ch2 = level1_music_bass;
            music_ptr_ch2 = music_data_ch2;
            music_cnt_ch2 = 0;
            music_inst_cnt_ch2 = 0;
            instruments_ch2 = title_music_bass_instruments;
            instruments_index_ch2 = 0;

            music_data_ch3 = level1_music_rythm;
            music_ptr_ch3 = music_data_ch3;
            music_cnt_ch3 = 0;
            music_inst_cnt_ch3 = 0;
            instruments_ch3 = title_music_tone3_instruments;
            instruments_index_ch3 = 0;

            music_data_ch4 = level1_music_rythm;
            music_ptr_ch4 = music_data_ch4;
            music_cnt_ch4 = 0;
            music_inst_cnt_ch4 = 0;
            instruments_ch4 = title_music_rythm_instruments;
            instruments_index_ch4 = 0;
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
                        music_inst_cnt_ch1 = 0;
                        inst_ch1 = instruments_ch1[instruments_index_ch1];
                        if(inst_ch1 == SILENT) {
                                instruments_index_ch1 = 0;
                                inst_ch1 = instruments_ch1[instruments_index_ch1];
                        }
                        instruments_index_ch1++;
                        PSG = PSG_LATCH | PSG_CH0 | PSG_VOLUME | instruments_volumes[inst_ch1][music_inst_cnt_ch1];
                        PSG = PSG_LATCH | PSG_CH0 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
                }
            }

            if( *music_ptr_ch1 == 0 )
            {
                music_ptr_ch1 = music_data_ch1;
                instruments_index_ch1 = 0;
            }
        } else {
                if(music_inst_cnt_ch1 < instruments_releases[inst_ch1])
                        music_inst_cnt_ch1++;
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
                music_inst_cnt_ch2 = 0;
                inst_ch2 = instruments_ch2[instruments_index_ch2];
                if(inst_ch2 == SILENT) {
                        instruments_index_ch2 = 0;
                        inst_ch2 = instruments_ch2[instruments_index_ch2];
                }
                instruments_index_ch2++;
                PSG = PSG_LATCH | PSG_CH1 | PSG_VOLUME | instruments_volumes[inst_ch2][music_inst_cnt_ch2];
                PSG = PSG_LATCH | PSG_CH1 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
            }

            if( *music_ptr_ch2 == 0 )
            {
                music_ptr_ch2 = music_data_ch2;
                instruments_index_ch2 = 0;
            }
        } else {
                if(music_inst_cnt_ch2 < instruments_releases[inst_ch2])
                        music_inst_cnt_ch2++;
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
                music_inst_cnt_ch3 = 0;
                inst_ch3 = instruments_ch3[instruments_index_ch3];
                if(inst_ch3 == SILENT) {
                        instruments_index_ch3 = 0;
                        inst_ch3 = instruments_ch3[instruments_index_ch3];
                }
                instruments_index_ch3++;
                PSG = PSG_LATCH | PSG_CH2 | PSG_VOLUME | instruments_volumes[inst_ch3][music_inst_cnt_ch3];
                PSG = PSG_LATCH | PSG_CH2 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
            }

            if( *music_ptr_ch3 == 0 )
            {
                music_ptr_ch3 = music_data_ch3;
                instruments_index_ch3 = 0;
            }
        } else {
                if(music_inst_cnt_ch3 < instruments_releases[inst_ch3])
                        music_inst_cnt_ch3++;
        }
        music_cnt_ch3--;

        //channel4
        if( music_cnt_ch4 == 0 )
        {
            music_cnt_ch4 = *music_ptr_ch4++;
            cwd = *music_ptr_ch4++;
            if( sound_cnt_ch4 == 0 )
            {
                if(cwd) {
                    music_inst_cnt_ch4 = 0;
                    inst_ch4 = instruments_ch4[instruments_index_ch4];
                    if(inst_ch4 == SILENT) {
                        instruments_index_ch4 = 0;
                        inst_ch4 = instruments_ch4[instruments_index_ch4];
                    }
                    instruments_index_ch4++;
                    PSG = PSG_LATCH | PSG_CH3 | PSG_VOLUME | instruments_volumes[inst_ch4][music_inst_cnt_ch4];
                    PSG = PSG_LATCH | PSG_CH3 | ((UBYTE)0b00000111); //tone 3 value
                }
            } 
            if( *music_ptr_ch4 == 0 )
            {
                music_ptr_ch4 = music_data_ch4;
                instruments_index_ch4 = 0;
            }
        } else {
                if(music_inst_cnt_ch4 < instruments_releases[inst_ch4])
                        music_inst_cnt_ch4++;
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
