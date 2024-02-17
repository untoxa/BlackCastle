#ifndef _AUDIO_HARDWARE_H
#define _AUDIO_HARDWARE_H

inline uint8_t translate_envelope(uint8_t value) {
    #ifdef MEGADUCK
        // Mega Duck has nybbles swapped for NR12, NR22, NR42 audio envelope registers
        return ((uint8_t)(value << 4) | (uint8_t)(value >> 4));
    #else
        return value;
    #endif
}

inline uint8_t translate_frequency(uint8_t value) {
    #ifdef MEGADUCK
        // Mega Duck has nybbles swapped for NR43 frequency & randomness audio register
        return ((uint8_t)(value << 4) | (uint8_t)(value >> 4));
    #else
        return value;
    #endif
}

inline uint8_t translate_volume(uint8_t value) {
    #ifdef MEGADUCK
        // Mega Duck has bit values changed for NR32 volume register
        // To translate the volume: New Volume = ((0x00 - Volume) & 0x60)
        // GB: Bits:6..5 : 00 = mute, 01 = 100%, 10 = 50%, 11 = 25%
        // MD: Bits:6..5 : 00 = mute, 11 = 100%, 10 = 50%, 01 = 25%
        return ((~(uint8_t)value) + 0x20u) & (uint8_t)0x60u;
    #else
        return value;
    #endif
}

#endif