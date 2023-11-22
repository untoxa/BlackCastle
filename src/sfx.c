#include <gbdk/platform.h>

#include "global.h"
#include "music.h"
#include "sfx_data.h"
#include "audio_hardware.h"

//sound
UBYTE sound_cnt_ch1;
UBYTE sound_typ_ch1;

UBYTE sound_cnt_ch4;
UBYTE sound_typ_ch4;

extern UBYTE inst_ch1;
extern UBYTE vol_ch1_t;
extern UBYTE env_ch1;
extern UBYTE tim_ch1;
extern UBYTE len_ch1;

extern UBYTE inst_ch4;
extern UBYTE vol_ch4;
extern UBYTE env_ch4;
extern UBYTE tim_ch4;
extern UBYTE len_ch4;

extern UBYTE shadow4000;

#if defined(NINTENDO)

extern const UWORD frequency[];

inline void set_ch1_regs(uint8_t nr10, uint8_t nr11, uint8_t nr12, uint8_t note, uint8_t nr14)
{
    UWORD freq = frequency[note];
    NR10_REG = nr10;
    NR11_REG = nr11;
    NR12_REG = translate_envelope(nr12);
    NR13_REG = freq & 0xFF;
    NR14_REG = nr14 | (freq >> 8);
}

inline void set_ch4_regs(uint8_t nr41, uint8_t nr42, uint8_t tone, uint8_t nr44)
{
    NR41_REG = nr41;
    NR42_REG = translate_envelope(nr42);
    NR43_REG = translate_frequency(tone);
    NR44_REG = nr44;
}

#elif defined(NINTENDO_NES)

extern const UWORD frequency[];

inline void set_ch1_regs(uint8_t nr10, uint8_t nr11, uint8_t nr12, uint8_t note, uint8_t nr14)
{
    nr14;
    UWORD freq = frequency[note];
    shadow4000 = (nr11 & 0xC0) | (nr12 >> 4) | 0x30;
    env_ch1 = nr12 >> 4;
    vol_ch1_t = nr12;
    tim_ch1 = nr12 & 0x7;
    _SND4000 = env_ch1 | (shadow4000 & 0xF0);
    _SND4001 = 0x7F;
    _SND4002 = freq & 0xFF;
    _SND4003 = ((freq >> 8) & 0x0007);
    len_ch1 = (nr11 & 0x3F) >> 2;
    
    uint8_t sweep_period = nr10 & 0x70;
    uint8_t sweep_n = nr10 & 0x07;
    uint8_t sweep_dir = nr10 & 0x08;
    if(sweep_period != 0)
        _SND4001 = 0x80 | (sweep_period - 0x10) | (sweep_dir ^ 0x08) | sweep_n;
    else
        _SND4001 = 0x08;    // Disable sweep
}

inline void set_ch4_regs(uint8_t nr41, uint8_t nr42, uint8_t tone, uint8_t nr44)
{
    nr44;
    env_ch4 = nr42 >> 4;
    vol_ch4 = nr42;
    tim_ch4 = nr42 & 0x7;
    _SND400C = env_ch1 | 0x30 | (inst_ch1 & 0xC0);
    _SND400D = 0x7F;
    _SND400E = tone;
    len_ch1 = (nr41 & 0x3F) >> 2;    
}
#elif defined(SEGA)

extern const UWORD frequency[];

inline void set_ch1_regs(uint8_t sweep, uint8_t duty_cycle, uint8_t envelope, uint8_t note, uint8_t period)
{
    UWORD freq = frequency[note];
    UBYTE volume = 0;//16 - (envelope >> 4);
    PSG = PSG_LATCH | PSG_CH0 | PSG_VOLUME | volume;
    PSG = PSG_LATCH | PSG_CH0 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
}

inline void set_ch4_regs(uint8_t timer, uint8_t envelope, uint8_t tone, uint8_t control)
{
    UWORD freq = frequency[tone];
    UBYTE volume = 0;//16 - (envelope >> 4);
    PSG = PSG_LATCH | PSG_CH2 | PSG_VOLUME | volume;
    PSG = PSG_LATCH | PSG_CH3 | PSG_VOLUME | volume;
    PSG = PSG_LATCH | PSG_CH2 | ((UBYTE)freq & 0b00001111), PSG = ((UBYTE)(freq >> 4) & 0b00111111);
    PSG = PSG_LATCH | PSG_CH3 | ((UBYTE)0b00000111);
}

#endif


void play_sound(void) NONBANKED
{
#if defined(NINTENDO) || defined(NINTENDO_NES) || defined(SEGA)
    SET_BANK(BANK(sfx_data));
    if( sound_cnt_ch4 != 0 )
    {
        sound_cnt_ch4--;
        switch( sound_typ_ch4 )
        {
            case SND_SHOT:
                if( shot_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(shot_sound[sound_cnt_ch4][1],
                                 shot_sound[sound_cnt_ch4][2],
                                 shot_sound[sound_cnt_ch4][3],
                                 shot_sound[sound_cnt_ch4][4]);
                }
                break;
            case SND_HIT:
                if( hit_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(hit_sound[sound_cnt_ch4][1],
                                 hit_sound[sound_cnt_ch4][2],
                                 hit_sound[sound_cnt_ch4][3],
                                 hit_sound[sound_cnt_ch4][4]);
                }
                break;
            case SND_EXPLOSION:
                if( explosion_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(explosion_sound[sound_cnt_ch4][1],
                                 explosion_sound[sound_cnt_ch4][2],
                                 explosion_sound[sound_cnt_ch4][3],
                                 explosion_sound[sound_cnt_ch4][4]);
                }
                break;
            case SND_DAMAGE:
                if( damage_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(damage_sound[sound_cnt_ch4][1],
                                 damage_sound[sound_cnt_ch4][2],
                                 damage_sound[sound_cnt_ch4][3],
                                 damage_sound[sound_cnt_ch4][4]);
                }
                break;
            case SND_DEAD:
                if( dead_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(dead_sound[sound_cnt_ch4][1],
                                 dead_sound[sound_cnt_ch4][2],
                                 dead_sound[sound_cnt_ch4][3],
                                 dead_sound[sound_cnt_ch4][4]);
                }
                break;
            case SND_BREAK:
                if( break_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(break_sound[sound_cnt_ch4][1],
                                 break_sound[sound_cnt_ch4][2],
                                 break_sound[sound_cnt_ch4][3],
                                 break_sound[sound_cnt_ch4][4]);
                }
                break;
            case SND_SHAKE:
                if( shake_sound[sound_cnt_ch4][0] == 1 )
                {
                    set_ch4_regs(shake_sound[sound_cnt_ch4][1],
                                 shake_sound[sound_cnt_ch4][2],
                                 shake_sound[sound_cnt_ch4][3],
                                 shake_sound[sound_cnt_ch4][4]);
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
                    set_ch1_regs(crystal_sound[sound_cnt_ch1][1],
                                 crystal_sound[sound_cnt_ch1][2],
                                 crystal_sound[sound_cnt_ch1][3],
                                 crystal_sound[sound_cnt_ch1][4],
                                 crystal_sound[sound_cnt_ch1][5]);
                }
                break;
            case SND_HEART:
                if( heart_sound[sound_cnt_ch1][0] == 1 )
                {
                    set_ch1_regs(heart_sound[sound_cnt_ch1][1],
                                 heart_sound[sound_cnt_ch1][2],
                                 heart_sound[sound_cnt_ch1][3],
                                 heart_sound[sound_cnt_ch1][4],
                                 heart_sound[sound_cnt_ch1][5]);
                }
                break;
            case SND_WEAPON:
                if( weapon_sound[sound_cnt_ch1][0] == 1 )
                {
                    set_ch1_regs(weapon_sound[sound_cnt_ch1][1],
                                 weapon_sound[sound_cnt_ch1][2],
                                 weapon_sound[sound_cnt_ch1][3],
                                 weapon_sound[sound_cnt_ch1][4],
                                 weapon_sound[sound_cnt_ch1][5]);
                }
                break;
            case SND_START:
                if( start_sound[sound_cnt_ch1][0] == 1 )
                {
                    set_ch1_regs(start_sound[sound_cnt_ch1][1],
                                 start_sound[sound_cnt_ch1][2],
                                 start_sound[sound_cnt_ch1][3],
                                 start_sound[sound_cnt_ch1][4],
                                 start_sound[sound_cnt_ch1][5]);
                }
                break;
            case SND_PAUSE:
                if( pause_sound[sound_cnt_ch1][0] == 1 )
                {
                    set_ch1_regs(pause_sound[sound_cnt_ch1][1],
                                 pause_sound[sound_cnt_ch1][2],
                                 pause_sound[sound_cnt_ch1][3],
                                 pause_sound[sound_cnt_ch1][4],
                                 pause_sound[sound_cnt_ch1][5]);
                }
                break;
        }
    }
    RESTORE_BANK();
#endif
}
