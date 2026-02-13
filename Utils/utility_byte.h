/*
 * @brief   Byte utility helpers
 *          Simple MSB/LSB extraction and composition
 *          (endianness-independent)
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef UTILITY_BYTE_INCLUDED
#define UTILITY_BYTE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline uint8_t GetMsb(uint16_t value){
    return (uint8_t)((value >> 8U) & 0xFFU);
}

static inline uint8_t GetLsb(uint16_t value){
    return (uint8_t)(value & 0xFFU);
}

static inline uint16_t MakeU16(uint8_t msb, uint8_t lsb){
    return ((uint16_t)(msb) << 8U) | (uint16_t)(lsb);
}

#ifdef __cplusplus
}
#endif

#endif
