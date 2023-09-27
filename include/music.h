#ifndef _MUSIC
#define _MUSIC

#define TITLE_MUSIC     0
#define GAME_OVER_MUSIC 1
#define BOSS_MUSIC      2
#define LEVEL1_MUSIC    3
#define LEVEL2_MUSIC    4
#define LEVEL3_MUSIC    5
#define END_MUSIC       6

void init_sound(void) BANKED;
void set_sound(UBYTE sound) NONBANKED;
void play_sound(void) NONBANKED;
void set_music(UBYTE song) BANKED;
void play_music(void) BANKED;
void stop_music(void) BANKED;
void restart_music(void) BANKED;

//
// NES and GB both use hardware frequency sweep for some SFX - but with different values
//
// Sound effects use 9 different noise pitches.
// These won't map exactly between GB and NES, but this naming convention provides a decent approximation.
#if defined(NINTENDO)
#define WEAPON_SWEEP    0x34
#define HEART_SWEEP     0x17

#define NOISE_HIGHEST   0x31
#define NOISE_HIGHER    0x50
#define NOISE_HIGH      0x34
#define NOISE_MID_HIGH  0x35
#define NOISE_MID       0x37
#define NOISE_MID_LOW   0x44
#define NOISE_LOW       0x53
#define NOISE_LOWER     0x54
#define NOISE_LOWEST    0x57

#define NOISE_LOOPED    0x08

#elif defined(NINTENDO_NES)
#define WEAPON_SWEEP    0x41
#define HEART_SWEEP     0x14

#define NOISE_HIGHEST   0x4
#define NOISE_HIGHER    0x5
#define NOISE_HIGH      0x8
#define NOISE_MID_HIGH  0x9
#define NOISE_MID       0xA
#define NOISE_MID_LOW   0xB
#define NOISE_LOW       0xC
#define NOISE_LOWER     0xD
#define NOISE_LOWEST    0xE

#define NOISE_LOOPED    0x80
#elif defined(SEGA)
#define WEAPON_SWEEP    0x2
#define HEART_SWEEP     0x2

#define NOISE_HIGHEST   0x0
#define NOISE_HIGHER    0x0
#define NOISE_HIGH      0x0
#define NOISE_MID_HIGH  0x1
#define NOISE_MID       0x1
#define NOISE_MID_LOW   0x1
#define NOISE_LOW       0x2
#define NOISE_LOWER     0x2
#define NOISE_LOWEST    0x2

#define NOISE_LOOPED    0x4
#else
#define WEAPON_SWEEP    0x00
#define HEART_SWEEP     0x00

#define NOISE_HIGHEST   0x0
#define NOISE_HIGHER    0x0
#define NOISE_HIGH      0x0
#define NOISE_MID_HIGH  0x0
#define NOISE_MID       0x0
#define NOISE_MID_LOW   0x0
#define NOISE_LOW       0x0
#define NOISE_LOWER     0x0
#define NOISE_LOWEST    0x0

#define NOISE_LOOPED    0x00

#endif

enum notes
{
	C3, Db3, D3, Eb3, E3, F3, Gb3, G3, Ab3, A3, Bb3, B3,
	C4, Db4, D4, Eb4, E4, F4, Gb4, G4, Ab4, A4, Bb4, B4,
	C5, Db5, D5, Eb5, E5, F5, Gb5, G5, Ab5, A5, Bb5, B5,
	C6, Db6, D6, Eb6, E6, F6, Gb6, G6, Ab6, A6, Bb6, B6,
	C7, Db7, D7, Eb7, E7, F7, Gb7, G7, Ab7, A7, Bb7, B7,
	C8, Db8, D8, Eb8, E8, F8, Gb8, G8, Ab8, A8, Bb8, B8,
	BRK
};

#ifdef NINTENDO_NES
__REG(0x4000) _SND4000;
__REG(0x4001) _SND4001;
__REG(0x4002) _SND4002;
__REG(0x4003) _SND4003;
__REG(0x4004) _SND4004;
__REG(0x4005) _SND4005;
__REG(0x4006) _SND4006;
__REG(0x4007) _SND4007;
__REG(0x4008) _SND4008;
__REG(0x4009) _SND4009;
__REG(0x400A) _SND400A;
__REG(0x400B) _SND400B;
__REG(0x400C) _SND400C;
__REG(0x400D) _SND400D;
__REG(0x400E) _SND400E;
__REG(0x400F) _SND400F;
__REG(0x4010) _SND4010;
__REG(0x4011) _SND4011;
__REG(0x4012) _SND4012;
__REG(0x4013) _SND4013;
__REG(0x4015) _SND4015;
#endif

#endif