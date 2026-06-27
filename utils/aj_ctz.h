/**
 * @brief   Count Trailing Zeros (CTZ) helpers for fixed-width unsigned integers.
 *
 * This header provides small, header-only CTZ routines with:
 *  - Well-defined sentinel return values for zero input
 *  - Fast paths using GCC/Clang builtins when available
 *  - Portable fallback loops for other compilers
 *
 * @note    For mask == 0, functions return a width-specific error code:
 *          - AJ_CTZ_U8_ERROR  (= 8)
 *          - AJ_CTZ_U16_ERROR (= 16)
 *          - AJ_CTZ_U32_ERROR (= 32)
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_CTZ_INCLUDED
#define AJ_CTZ_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

#define AJ_CTZ_U8_ERROR     8u
#define AJ_CTZ_U16_ERROR    16u
#define AJ_CTZ_U32_ERROR    32u

//****************************************************
static inline uint8_t AJ_CTZ_u32(uint32_t mask){
    uint8_t ctz = 0U;

    if (mask == 0UL){
        return (uint8_t)AJ_CTZ_U32_ERROR;
    }

    #if defined(__GNUC__) || defined(__clang__)
        ctz = (uint8_t)__builtin_ctzl((unsigned long)mask);
    #else
        while ((mask & 1UL) == 0UL) {
            mask >>= 1U;
            ++ctz;
        }
    #endif

    return ctz;
}

//****************************************************
static inline uint8_t AJ_CTZ_u16(uint16_t mask){
    uint8_t ctz = 0U;

    if (mask == 0U){
        return (uint8_t)AJ_CTZ_U16_ERROR;
    }

#if defined(__GNUC__) || defined(__clang__)
    ctz = (uint8_t)__builtin_ctz((unsigned int)mask);
#else
    while ((mask & 1U) == 0U) {
        mask >>= 1U;
        ++ctz;
    }
#endif

    return ctz;
}

//****************************************************
static inline uint8_t AJ_CTZ_u8(uint8_t mask){
    uint8_t ctz = 0U;

    if (mask == 0U){
        return (uint8_t)AJ_CTZ_U8_ERROR;
    }

    #if defined(__GNUC__) || defined(__clang__)
        ctz = (uint8_t)__builtin_ctz((unsigned int)mask);
    #else
        while ((mask & 1U) == 0U) {
            mask >>= 1U;
            ++ctz;
        }
    #endif

    return ctz;
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_CTZ_INCLUDED */