/*
 * @brief   Byte utility helpers
 *          Simple MSB/LSB extraction and composition
 *          (endianness-independent)
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BYTE_INCLUDED
#define AJ_BYTE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline uint8_t AJ_GetMsb(uint16_t value){
    return (uint8_t)((value >> 8U) & 0xFFU);
}

static inline uint8_t AJ_GetLsb(uint16_t value){
    return (uint8_t)(value & 0xFFU);
}

static inline uint16_t AJ_MakeU16(uint8_t msb, uint8_t lsb){
    return ((uint16_t)(msb) << 8U) | (uint16_t)(lsb);
}

static inline uint16_t AJ_SwapU16(uint16_t x){
    return (uint16_t)((x >> 8) | (x << 8));
}

#ifdef __cplusplus
}
#endif

#endif
