// GitHub Account: GitHub.com/AliRezaJoodi
/* Precondition: mask != 0. No runtime validation is performed. */

#ifndef AJ_BIT_REG_INCLUDED
#define AJ_BIT_REG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_bit_reg_config.h"

#if defined(AJ_BIT_REG_32BIT)
    typedef uint32_t AJ_BitReg_t;
#elif defined(AJ_BIT_REG_8BIT)
    typedef uint8_t AJ_BitReg_t;
#else
    #error "One AJ_BIT_REG_CONFIG option must be selected."
#endif

//***********************************************************************
static inline void AJ_BitReg_SetBits_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    *reg = (AJ_BitReg_t)(*reg | mask);
}

static inline void AJ_BitReg_SetBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    *reg = (AJ_BitReg_t)(*reg | (0x01U << pos));
}

//***********************************************************************
static inline void AJ_BitReg_ClearBits_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    *reg = (AJ_BitReg_t)(*reg & (~mask));
}

static inline void AJ_BitReg_ClearBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    *reg = (AJ_BitReg_t)(*reg & ~(0x01U << pos));
}

//***********************************************************************
static inline void AJ_BitReg_ToggleBits_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    *reg = (AJ_BitReg_t)(*reg ^ mask);
}

static inline void AJ_BitReg_ToggleBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    *reg = (AJ_BitReg_t)(*reg ^ (0x01U << pos));
}

//***********************************************************************
/* Precondition:
 * - mask must be non-zero
 * - mask should describe one contiguous bit-field
 */
static inline void AJ_BitReg_WriteField_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask, AJ_BitReg_t value){
    #if defined(__GNUC__) || defined(__clang__)
        if (mask == 0U){return;}

        *reg =  (AJ_BitReg_t)(
                (*reg & ~mask) |
                ((value << __builtin_ctz(mask)) & mask)
                );
    #else
        uint8_t shift = 0U;
        AJ_BitReg_t temp  = mask;

        if (mask == 0U){return;}

        while((temp & 0x01U) == 0U){
            temp >>= 1U;
            ++shift;
        }

        *reg =  (AJ_BitReg_t)(
                (*reg & ~mask) |
                ((value << shift) & mask)
                );
    #endif
}

static inline void AJ_BitReg_WriteBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t status){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x01U << pos)) |
            ((status & 0x01U) << pos)
           );
}

static inline void AJ_BitReg_Write2Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x03U << pos)) |
            ((value & 0x03U) << pos)
           );
}

static inline void AJ_BitReg_Write3Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x07U << pos)) |
            ((value & 0x07U) << pos)
           );
}

static inline void AJ_BitReg_Write4Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x0FU << pos)) |
            ((value & 0x0FU) << pos)
           );
}

static inline void AJ_BitReg_Write5Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x1FU << pos)) |
            ((value & 0x1FU) << pos)
           );
}

static inline void AJ_BitReg_Write6Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x3FU << pos)) |
            ((value & 0x3FU) << pos)
           );
}

static inline void AJ_BitReg_Write7Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x7FU << pos)) |
            ((value & 0x7FU) << pos)
           );
}

static inline void AJ_BitReg_Write8Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t value){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0xFFU << pos)) |
            ((value & 0xFFU) << pos)
           );
}

//***********************************************************************
/* mask must not be 0 */
static inline AJ_BitReg_t AJ_BitReg_GetField_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    #if defined(__GNUC__) || defined(__clang__)
        if(mask == 0U){return 0U;}

        return (AJ_BitReg_t)((*reg & mask) >> __builtin_ctz(mask));
    #else
        uint8_t shift = 0U;
        AJ_BitReg_t scan = mask;

        if(mask == 0U){return 0U;}

        while((scan & 1U) == 0U){
            scan >>= 1U;
            ++shift;
        }

        return (AJ_BitReg_t)((*reg & mask) >> shift);
    #endif
}

/* mask must not be 0 */
static inline uint8_t AJ_BitReg_AreBitsSet_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    return (uint8_t)(((*reg) & mask) == mask);
}

/* mask must not be 0 */
static inline uint8_t AJ_BitReg_IsAnyBitSet_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    return (uint8_t)(((*reg) & mask) != 0U);
}

static inline uint8_t AJ_BitReg_IsBitSet_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x01U);
}

static inline uint8_t AJ_BitReg_Get2Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x03U);
}

static inline uint8_t AJ_BitReg_Get3Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x07U);
}

static inline uint8_t AJ_BitReg_Get4Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x0FU);
}

static inline uint8_t AJ_BitReg_Get5Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x1FU);
}

static inline uint8_t AJ_BitReg_Get6Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x3FU);
}

static inline uint8_t AJ_BitReg_Get7Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x7FU);
}

static inline uint8_t AJ_BitReg_Get8Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0xFFU);
}

#ifdef __cplusplus
}
#endif

#endif
