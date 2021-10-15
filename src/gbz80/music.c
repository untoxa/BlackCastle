#pragma bank 3

#include <gbdk/platform.h>

#include "global.h"

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

//const unsigned char data_ch3[] = {0x34,0x45,0x56,0x67,0x89,0x9A,0xAB,0xBC,0x34,0x45,0x56,0x67,0x89,0x9A,0xAB,0xBC};

const unsigned char title_music_lead[] =
{
	18,E5,2,BRK,18,A4,2,BRK,18,E5,2,BRK,18,A4,2,BRK,18,F5,2,BRK,18,A4,2,BRK,18,E5,2,BRK,18,A4,2,BRK,
	18,D5,2,BRK,18,G4,2,BRK,18,D5,2,BRK,18,G4,2,BRK,18,E5,2,BRK,18,G4,2,BRK,18,D5,2,BRK,18,G4,2,BRK,
	18,C5,2,BRK,18,F4,2,BRK,18,C5,2,BRK,18,F4,2,BRK,18,D5,2,BRK,18,F4,2,BRK,18,C5,2,BRK,18,F4,2,BRK,
	18,B4,2,BRK,18,E4,2,BRK,18,B4,2,BRK,18,E4,2,BRK,18,C5,2,BRK,18,E4,2,BRK,18,D5,2,BRK,18,E4,2,BRK,
	0
};

const unsigned char title_music_bass[] =
{
	158,A3,2,BRK,158,G3,2,BRK,158,F3,2,BRK,158,E3,2,BRK,
	0
};

const unsigned char title_music_rythm[] =
{
	
	1,0x4B,1,0x5F,78,0x00,1,0x4B,1,0x58,58,0x00,1,0x4B,1,0x58,18,0x00,
	0
};

const unsigned char game_over_music_lead[] =
{
	18,A4,2,BRK,18,B4,2,BRK,18,C5,2,BRK,18,A4,2,BRK,18,D5,2,BRK,18,C5,2,BRK,18,B4,2,BRK,18,C5,2,BRK,158,B4,2,BRK,
	18,G4,2,BRK,18,A4,2,BRK,18,B4,2,BRK,18,G4,2,BRK,18,C5,2,BRK,18,B4,2,BRK,18,A4,2,BRK,18,G4,2,BRK,158,A4,2,BRK,
	0
};


const unsigned char game_over_music_bass[] =
{
	58,A3,2,BRK,18,A3,2,BRK,58,D3,2,BRK,18,D3,2,BRK,58,G3,2,BRK,18,G3,2,BRK,58,G3,2,BRK,18,G3,2,BRK,
	58,E3,2,BRK,18,E3,2,BRK,58,C3,2,BRK,18,C3,2,BRK,58,A3,2,BRK,18,A3,2,BRK,58,A3,2,BRK,18,A3,2,BRK,
	0
};

const unsigned char game_over_music_rythm[] =
{
	1,0x4B,1,0x5F,78,0x00,1,0x4B,1,0x58,78,0x00,1,0x4B,1,0x5F,78,0x00,1,0x4B,1,0x58,38,0x00,1,0x4B,1,0x5F,38,0x00,
	0
};

const unsigned char boss_music_lead[] =
{
	166,A4,2,BRK,10,A4,2,BRK,10,B4,2,BRK,
	166,C5,2,BRK,10,D5,2,BRK,10,C5,2,BRK,
	70,B4,2,BRK,22,A4,2,BRK,46,G4,2,BRK,22,A4,2,BRK,22,B4,2,BRK,
	190,A4,2,BRK,
	0
};

const unsigned char boss_music_bass[] =
{
	10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,
	10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,
	10,F3,2,BRK,10,F3,2,BRK,10,C3,2,BRK,10,E3,2,BRK,10,F3,2,BRK,10,F3,2,BRK,10,C3,2,BRK,10,E3,2,BRK,
	10,F3,2,BRK,10,F3,2,BRK,10,C3,2,BRK,10,E3,2,BRK,10,F3,2,BRK,10,F3,2,BRK,10,C3,2,BRK,10,E3,2,BRK,
	10,G3,2,BRK,10,G3,2,BRK,10,D3,2,BRK,10,F3,2,BRK,10,G3,2,BRK,10,G3,2,BRK,10,D3,2,BRK,10,F3,2,BRK,
	10,E3,2,BRK,10,E3,2,BRK,10,B3,2,BRK,10,G3,2,BRK,10,E3,2,BRK,10,E3,2,BRK,10,B3,2,BRK,10,G3,2,BRK,
	10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,
	10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,10,A3,2,BRK,10,A3,2,BRK,10,E3,2,BRK,10,G3,2,BRK,
	0
};

const unsigned char boss_music_rythm[] =
{
	1,0x4B,1,0x5F,22,0x00,1,0x4B,1,0x58,10,0x00,1,0x4B,1,0x5F,22,0x00,1,0x4B,1,0x5F,10,0x00,1,0x4B,1,0x58,10,0x00,1,0x4B,1,0x5F,10,0x00,
	0
};

const unsigned char level1_music_lead[] =
{
	//A
	14,A4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,62,C5,2,BRK,14,A4,2,BRK,
	14,B4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,62,B4,2,BRK,14,B4,2,BRK,
	30,F5,2,BRK,30,F5,2,BRK,14,F5,2,BRK,14,F5,2,BRK,14,G5,2,BRK,
	62,E5,2,BRK,14,D5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,14,C5,2,BRK,14,B4,2,BRK,
	14,A4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,62,C5,2,BRK,14,A4,2,BRK,
	14,B4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,62,B4,2,BRK,14,B4,2,BRK,
	30,A4,2,BRK,30,A4,2,BRK,14,A4,2,BRK,14,A4,2,BRK,14,C5,2,BRK,
	62,B4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,14,B4,2,BRK,14,A4,2,BRK,
	//B
	16,BRK,14,F5,2,BRK,14,F5,2,BRK,14,E5,2,BRK,14,F5,2,BRK,14,G5,2,BRK,14,F5,2,BRK,14,E5,2,BRK,
	126,D5,2,BRK,
	16,BRK,14,E5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,14,E5,2,BRK,14,F5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,
	126,C5,2,BRK,
	14,B4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,62,D5,2,BRK,14,B4,2,BRK,
	14,C5,2,BRK,14,C5,2,BRK,14,D5,2,BRK,62,E5,2,BRK,14,E5,2,BRK,
	30,F5,2,BRK,30,F5,2,BRK,14,F5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,
	62,E5,2,BRK,14,D5,2,BRK,14,E5,2,BRK,14,F5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,
	//A
	14,A4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,62,C5,2,BRK,14,A4,2,BRK,
	14,B4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,62,B4,2,BRK,14,B4,2,BRK,
	30,F5,2,BRK,30,F5,2,BRK,14,F5,2,BRK,14,F5,2,BRK,14,G5,2,BRK,
	62,E5,2,BRK,14,D5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,14,C5,2,BRK,14,B4,2,BRK,
	14,A4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,62,C5,2,BRK,14,A4,2,BRK,
	14,B4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,62,B4,2,BRK,14,B4,2,BRK,
	30,A4,2,BRK,30,A4,2,BRK,14,A4,2,BRK,14,A4,2,BRK,14,C5,2,BRK,
	62,B4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,14,B4,2,BRK,14,A4,2,BRK,
	//C
	16,BRK,14,A4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,14,D5,2,BRK,14,C5,2,BRK,14,B4,2,BRK,14,A4,2,BRK,
	126,B4,2,BRK,
	16,BRK,14,G4,2,BRK,14,A4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,14,B4,2,BRK,14,A4,2,BRK,14,G4,2,BRK,
	126,A4,2,BRK,
	16,BRK,14,E5,2,BRK,14,C5,2,BRK,14,A4,2,BRK,14,B4,2,BRK,14,C5,2,BRK,14,D5,2,BRK,14,E5,2,BRK,
	126,D5,2,BRK,
	16,BRK,14,C5,2,BRK,14,D5,2,BRK,14,E5,2,BRK,14,D5,2,BRK,14,C5,2,BRK,14,B4,2,BRK,14,G4,2,BRK,
	126,A4,2,BRK,
	0
};

const unsigned char level1_music_bass[] =
{
	//A
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,E3,2,BRK,14,E3,2,BRK,16,BRK,14,E3,2,BRK,30,E3,2,BRK,14,E3,2,BRK,14,E3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,E3,2,BRK,14,E3,2,BRK,16,BRK,14,E3,2,BRK,30,E3,2,BRK,14,E3,2,BRK,14,E3,2,BRK,
	//B
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,E3,2,BRK,14,E3,2,BRK,16,BRK,14,E3,2,BRK,30,E3,2,BRK,14,E3,2,BRK,14,E3,2,BRK,
	//A
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,E3,2,BRK,14,E3,2,BRK,16,BRK,14,E3,2,BRK,30,E3,2,BRK,14,E3,2,BRK,14,E3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,E3,2,BRK,14,E3,2,BRK,16,BRK,14,E3,2,BRK,30,E3,2,BRK,14,E3,2,BRK,14,E3,2,BRK,
	//C
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	14,G3,2,BRK,14,G3,2,BRK,16,BRK,14,G3,2,BRK,30,G3,2,BRK,14,G3,2,BRK,14,G3,2,BRK,
	14,F3,2,BRK,14,F3,2,BRK,16,BRK,14,F3,2,BRK,30,F3,2,BRK,14,F3,2,BRK,14,F3,2,BRK,
	14,A3,2,BRK,14,A3,2,BRK,16,BRK,14,A3,2,BRK,30,A3,2,BRK,14,A3,2,BRK,14,A3,2,BRK,
	0
};

const unsigned char level1_music_rythm[] =
{
	
	1,0x4B,1,0x5F,30,0x00,1,0x4B,1,0x58,46,0x00,1,0x4B,1,0x5F,14,0x00,1,0x4B,1,0x58,14,0x00,1,0x4B,1,0x5F,14,0x00,
	0
};

const unsigned char level2_music_lead[] =
{
	//A
	16,E5,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,34,C5,2,BRK,16,A4,2,BRK,
	16,B4,2,BRK,16,B4,2,BRK,16,G4,2,BRK,88,E4,2,BRK,
	16,E5,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,34,C5,2,BRK,16,A4,2,BRK,
	88,B4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,
	//B
	16,F5,2,BRK,16,F5,2,BRK,16,F5,2,BRK,16,E5,2,BRK,52,D5,2,BRK,16,D5,2,BRK,
	16,E5,2,BRK,16,E5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,52,C5,2,BRK,16,C5,2,BRK,
	16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,G4,2,BRK,
	88,A4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,
	16,F5,2,BRK,16,F5,2,BRK,16,F5,2,BRK,16,E5,2,BRK,52,D5,2,BRK,16,D5,2,BRK,
	16,E5,2,BRK,16,E5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,52,C5,2,BRK,16,C5,2,BRK,
	16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,G4,2,BRK,
	142,A4,2,BRK,
	//A
	16,E5,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,34,C5,2,BRK,16,A4,2,BRK,
	16,B4,2,BRK,16,B4,2,BRK,16,G4,2,BRK,88,E4,2,BRK,
	16,E5,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,34,C5,2,BRK,16,A4,2,BRK,
	88,B4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,
	//B
	16,F5,2,BRK,16,F5,2,BRK,16,F5,2,BRK,16,E5,2,BRK,52,D5,2,BRK,16,D5,2,BRK,
	16,E5,2,BRK,16,E5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,52,C5,2,BRK,16,C5,2,BRK,
	16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,G4,2,BRK,
	88,A4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,
	16,F5,2,BRK,16,F5,2,BRK,16,F5,2,BRK,16,E5,2,BRK,52,D5,2,BRK,16,D5,2,BRK,
	16,E5,2,BRK,16,E5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,52,C5,2,BRK,16,C5,2,BRK,
	16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,G4,2,BRK,
	142,A4,2,BRK,
	//C
	16,C5,2,BRK,16,A4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,A4,2,BRK,
	142,B4,2,BRK,
	16,B4,2,BRK,16,G4,2,BRK,16,A4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,A4,2,BRK,16,G4,2,BRK,
	142,A4,2,BRK,
	16,C5,2,BRK,16,A4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,D5,2,BRK,16,E5,2,BRK,16,D5,2,BRK,16,C5,2,BRK,
	142,B4,2,BRK,
	16,B4,2,BRK,16,G4,2,BRK,16,A4,2,BRK,16,B4,2,BRK,16,C5,2,BRK,16,B4,2,BRK,16,A4,2,BRK,16,G4,2,BRK,
	142,A4,2,BRK,
	0
};

const unsigned char level2_music_bass[] =
{
	//A
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	//B
	16,F3,2,BRK,16,F3,20,BRK,16,F3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,F3,2,BRK,16,F3,20,BRK,16,F3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	//A
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	//B
	16,F3,2,BRK,16,F3,20,BRK,16,F3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,F3,2,BRK,16,F3,20,BRK,16,F3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,E3,2,BRK,16,E3,20,BRK,16,E3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	//C
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,16,G3,2,BRK,16,G3,20,BRK,16,G3,2,BRK,
	16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,16,A3,2,BRK,16,A3,20,BRK,16,A3,2,BRK,
	0
};

const unsigned char level2_music_rythm[] =
{
	1,0x4B,1,0x5F,34,0x00,1,0x4B,1,0x58,34,0x00,1,0x4B,1,0x5F,16,0x00,1,0x4B,1,0x5F,16,0x00,1,0x4B,1,0x58,34,0x00,
	0
};

const unsigned char level3_music_lead[] =
{
	//A
	32,A4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,15,B4,2,BRK,32,A4,2,BRK,
	15,B4,2,BRK,15,C5,2,BRK,15,B4,2,BRK,83,G4,2,BRK,
	32,G4,2,BRK,15,G4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,A4,2,BRK,15,G4,2,BRK,15,B4,2,BRK,
	134,A4,2,BRK,
	32,A4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,15,B4,2,BRK,32,A4,2,BRK,
	15,D5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,83,G4,2,BRK,
	32,B4,2,BRK,15,B4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,
	83,A4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,
	//B
	32,D5,2,BRK,15,A4,2,BRK,15,A4,2,BRK,32,D5,2,BRK,15,D5,2,BRK,15,E5,2,BRK,
	15,D5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,83,C5,2,BRK,
	32,C5,2,BRK,15,G4,2,BRK,15,G4,2,BRK,32,C5,2,BRK,15,C5,2,BRK,15,D5,2,BRK,
	83,B4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,
	32,D5,2,BRK,15,A4,2,BRK,15,A4,2,BRK,32,D5,2,BRK,15,D5,2,BRK,15,E5,2,BRK,
	15,D5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,83,C5,2,BRK,
	32,C5,2,BRK,15,C5,2,BRK,15,C5,2,BRK,32,E5,2,BRK,15,D5,2,BRK,15,C5,2,BRK,
	83,B4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,
	//C
	83,D5,2,BRK,15,D5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,
	83,C5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,15,A4,2,BRK,
	83,B4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,15,B4,2,BRK,
	83,A4,2,BRK,15,A4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,
	83,D5,2,BRK,15,D5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,
	83,C5,2,BRK,15,C5,2,BRK,15,B4,2,BRK,15,A4,2,BRK,
	83,G4,2,BRK,15,G4,2,BRK,15,B4,2,BRK,15,C5,2,BRK,
	134,A4,2,BRK,
	0
};

const unsigned char level3_music_bass[] =
{
	//A
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	//B
	15,D3,2,BRK,32,D3,2,BRK,15,D3,2,BRK,15,D3,2,BRK,17,BRK,15,D3,2,BRK,15,D3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,C3,2,BRK,32,C3,2,BRK,15,C3,2,BRK,15,C3,2,BRK,17,BRK,15,C3,2,BRK,15,C3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,D3,2,BRK,32,D3,2,BRK,15,D3,2,BRK,15,D3,2,BRK,17,BRK,15,D3,2,BRK,15,D3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,C3,2,BRK,32,C3,2,BRK,15,C3,2,BRK,15,C3,2,BRK,17,BRK,15,C3,2,BRK,15,C3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	//C
	15,D3,2,BRK,32,D3,2,BRK,15,D3,2,BRK,15,D3,2,BRK,17,BRK,15,D3,2,BRK,15,D3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,D3,2,BRK,32,D3,2,BRK,15,D3,2,BRK,15,D3,2,BRK,17,BRK,15,D3,2,BRK,15,D3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	15,G3,2,BRK,32,G3,2,BRK,15,G3,2,BRK,15,G3,2,BRK,17,BRK,15,G3,2,BRK,15,G3,2,BRK,
	15,A3,2,BRK,32,A3,2,BRK,15,A3,2,BRK,15,A3,2,BRK,17,BRK,15,A3,2,BRK,15,A3,2,BRK,
	0
};

const unsigned char level3_music_rythm[] =
{
	1,0x4B,1,0x5F,15,0x00,1,0x4B,1,0x5F,15,0x00,1,0x4B,1,0x58,49,0x00,1,0x4B,1,0x5F,15,0x00,1,0x4B,1,0x58,15,0x00,1,0x4B,1,0x5F,15,0x00,
	0
};

const unsigned char end_music_lead[] =
{
	//A
	28,C5,2,BRK,8,C5,2,BRK,8,E5,2,BRK,8,F5,2,BRK,
	28,G5,2,BRK,8,G5,2,BRK,8,F5,2,BRK,8,E5,2,BRK,
	28,F5,2,BRK,8,F5,2,BRK,8,G5,2,BRK,8,A5,2,BRK,
	28,G5,2,BRK,28,D5,2,BRK,
	28,C5,2,BRK,8,C5,2,BRK,8,E5,2,BRK,8,F5,2,BRK,
	28,G5,2,BRK,8,G5,2,BRK,8,F5,2,BRK,8,E5,2,BRK,
	28,F5,2,BRK,8,F5,2,BRK,8,G5,2,BRK,8,A5,2,BRK,
	58,G5,2,BRK,
	28,C5,2,BRK,8,C5,2,BRK,8,E5,2,BRK,8,F5,2,BRK,
	28,G5,2,BRK,8,G5,2,BRK,8,F5,2,BRK,8,E5,2,BRK,
	28,F5,2,BRK,8,F5,2,BRK,8,G5,2,BRK,8,A5,2,BRK,
	28,G5,2,BRK,28,D5,2,BRK,
	28,C5,2,BRK,8,C5,2,BRK,8,E5,2,BRK,8,F5,2,BRK,
	28,G5,2,BRK,8,G5,2,BRK,8,F5,2,BRK,8,E5,2,BRK,
	28,F5,2,BRK,8,F5,2,BRK,8,G5,2,BRK,8,A5,2,BRK,
	58,G5,2,BRK,
	//B
	28,A5,2,BRK,8,E5,2,BRK,8,E5,2,BRK,8,E5,2,BRK,
	28,C5,2,BRK,8,C6,2,BRK,8,B5,2,BRK,8,A5,2,BRK,
	28,G5,2,BRK,8,D5,2,BRK,8,D5,2,BRK,8,D5,2,BRK,
	58,B4,2,BRK,
	28,F5,2,BRK,8,C5,2,BRK,8,C5,2,BRK,8,C5,2,BRK,
	28,A4,2,BRK,8,F5,2,BRK,8,E5,2,BRK,8,D5,2,BRK,
	28,E5,2,BRK,8,E5,2,BRK,8,F5,2,BRK,8,D5,2,BRK,
	58,E5,2,BRK,
	28,A5,2,BRK,8,E5,2,BRK,8,E5,2,BRK,8,E5,2,BRK,
	28,C6,2,BRK,8,C6,2,BRK,8,B5,2,BRK,8,A5,2,BRK,
	28,G5,2,BRK,8,D5,2,BRK,8,D5,2,BRK,8,D5,2,BRK,
	58,B4,2,BRK,
	28,F5,2,BRK,8,C5,2,BRK,8,C5,2,BRK,8,C5,2,BRK,
	28,F5,2,BRK,8,F5,2,BRK,8,E5,2,BRK,8,D5,2,BRK,
	28,E5,2,BRK,8,E5,2,BRK,8,F5,2,BRK,8,D5,2,BRK,
	58,E5,2,BRK,
	
	0
};

const unsigned char end_music_bass[] =
{
	//A
	28,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,8,C3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	//B
	28,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,
	28,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,
	28,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,
	28,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,
	28,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,8,A3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,8,G3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,8,F3,2,BRK,
	28,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,
	28,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,8,E3,2,BRK,
	0
};

const unsigned char end_music_rythm[] =
{
	
	1,0x4B,1,0x5F,28,0x00,1,0x4B,1,0x58,8,0x00,1,0x4B,1,0x58,8,0x00,1,0x4B,1,0x58,8,0x00,
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

void init_sound() BANKED
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

void play_music() BANKED
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
					NR12_REG = vol_ch1;
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
				NR22_REG = vol_ch2;
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
				NR32_REG = 0x20;
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
					NR42_REG = 0x90;
					NR43_REG = cwd;
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

void stop_music() BANKED
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

void restart_music() BANKED
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
