#ifndef AJ_BIT_REVERSE_INCLUDED
#define AJ_BIT_REVERSE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline uint32_t AJ_Bit_Reverse_u32(uint32_t x){
    x = ((x >> 16) & 0x0000FFFFUL) | ((x & 0x0000FFFFUL) << 16);
    x = ((x >> 8)  & 0x00FF00FFUL) | ((x & 0x00FF00FFUL) << 8);
    x = ((x >> 4)  & 0x0F0F0F0FUL) | ((x & 0x0F0F0F0FUL) << 4);
    x = ((x >> 2)  & 0x33333333UL) | ((x & 0x33333333UL) << 2);
    x = ((x >> 1)  & 0x55555555UL) | ((x & 0x55555555UL) << 1);

    return x;
}

static inline uint8_t AJ_Bit_Reflect_u8(uint8_t x){
    x = (uint8_t)((x >> 4) | (x << 4));
    x = (uint8_t)(((x & 0xCCU) >> 2) | ((x & 0x33U) << 2));
    x = (uint8_t)(((x & 0xAAU) >> 1) | ((x & 0x55U) << 1));

    return x;
}

#ifdef __cplusplus
}
#endif

#endif

