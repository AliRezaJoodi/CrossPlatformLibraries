// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_VALUE_INCLUDED
#define BIT_VALUE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline uint8_t Write_Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(1U << pos)) |
            ((status & 1U) << pos)
            );
}

static inline uint16_t Write_Bit_u16(uint16_t value, uint8_t pos, uint8_t status){
    return (uint16_t)(
            (value & ~(1U << pos)) |
            ((status & 1U) << pos)
            );
}

static inline uint32_t Write_Bit_u32(uint32_t value, uint8_t pos, uint8_t status){
    return (uint32_t)(
            (value & ~(1UL << pos)) |
            ((status & 1UL) << pos)
            );
}

static inline uint8_t Write_2Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x03U << pos)) |
            ((status & 0x03U) << pos)
            );
}

static inline uint8_t Write_3Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x07U << pos)) |
            ((status & 0x07U) << pos)
            );
}

static inline uint8_t Write_4Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x0FU << pos)) |
            ((status & 0x0FU) << pos)
            );
}

static inline uint8_t Reflect_u8(uint8_t x){
    x = (uint8_t)((x >> 4) | (x << 4));
    x = (uint8_t)(((x & 0xCCU) >> 2) | ((x & 0x33U) << 2));
    x = (uint8_t)(((x & 0xAAU) >> 1) | ((x & 0x55U) << 1));

    return x;
}

#ifdef __cplusplus
}
#endif

#endif


