#ifndef __UNAPACK_H_INCLUDE
#define __UNAPACK_H_INCLUDE

#include <gbdk/platform.h>

#if defined(NINTENDO)
void UNAPACK(const unsigned char * sour, unsigned char * dest) OLDCALL;
#elif defined(SEGA)
void UNAPACK(const unsigned char * sour, unsigned char * dest) Z88DK_CALLEE;
#endif

#endif