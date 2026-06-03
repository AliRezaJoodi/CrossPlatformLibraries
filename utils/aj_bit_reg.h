/**
 * @brief Bit manipulation utilities for memory-mapped registers.
 *
 * This header provides a set of inline utility functions for performing bitwise
 * operations on registers of configurable width (8, 16, or 32-bit).
 *
 * @section usage_constraints Usage Constraints & Safety
 *
 * @subsection mask_reqs Mask-based Operations
 * - @b Non-zero: All functions utilizing a `mask` parameter require the mask to be non-zero.
 * - @b Contiguity: For field-based operations (e.g., WriteField), the mask @b must describe
 *   exactly one contiguous bit-field. Using non-contiguous masks will lead to
 *   undefined behavior or incorrect bit shifts.
 *
 * @subsection pos_reqs Position-based Operations
 * - The `pos` parameter is 0-indexed and must strictly adhere to the range of the
 *   configured register width (`AJ_BitReg_t`):
 *   - 8-bit  register: 0 to 7
 *   - 16-bit register: 0 to 15
 *   - 32-bit register: 0 to 31
 * - Providing a position outside this range will result in undefined behavior or
 *   invalid memory access logic.
 *
 * @note Ensure that `aj_bit_reg_config.h` is configured correctly before using this library.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BIT_REG_INCLUDED
#define AJ_BIT_REG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_ctz.h"
#include "aj_bit_reg_config.h"

#if defined(AJ_BIT_REG_32BIT)
    typedef uint32_t AJ_BitReg_t;
#elif defined(AJ_BIT_REG_16BIT)
    typedef uint16_t AJ_BitReg_t;
#elif defined(AJ_BIT_REG_8BIT)
    typedef uint8_t AJ_BitReg_t;
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
 static inline void AJ_BitReg_WriteField_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask, AJ_BitReg_t field){
    uint8_t shift;

    #if defined(AJ_BIT_REG_32BIT)
        shift = AJ_CTZ_u32(mask);
    #elif defined(AJ_BIT_REG_16BIT)
        shift = AJ_CTZ_u16(mask);
    #elif defined(AJ_BIT_REG_8BIT)
        shift = AJ_CTZ_u8(mask);
    #endif

    *reg =  (AJ_BitReg_t)(
            (*reg & ~mask) |
            ((field << shift) & mask)
            );
}

static inline void AJ_BitReg_WriteBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t status){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x01U << pos)) |
            ((status & 0x01U) << pos)
           );
}

static inline void AJ_BitReg_Write2Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x03U << pos)) |
            ((field & 0x03U) << pos)
           );
}

static inline void AJ_BitReg_Write3Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x07U << pos)) |
            ((field & 0x07U) << pos)
           );
}

static inline void AJ_BitReg_Write4Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x0FU << pos)) |
            ((field & 0x0FU) << pos)
           );
}

static inline void AJ_BitReg_Write5Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x1FU << pos)) |
            ((field & 0x1FU) << pos)
           );
}

static inline void AJ_BitReg_Write6Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x3FU << pos)) |
            ((field & 0x3FU) << pos)
           );
}

static inline void AJ_BitReg_Write7Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x7FU << pos)) |
            ((field & 0x7FU) << pos)
           );
}

static inline void AJ_BitReg_Write8Bits_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0xFFU << pos)) |
            ((field & 0xFFU) << pos)
           );
}

//***********************************************************************
/* Precondition:
 * - mask must be non-zero
 * - mask should describe one contiguous bit-field
 */
static inline AJ_BitReg_t AJ_BitReg_GetField_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    uint8_t shift;

    #if defined(AJ_BIT_REG_32BIT)
        shift = AJ_CTZ_u32(mask);
    #elif defined(AJ_BIT_REG_16BIT)
        shift = AJ_CTZ_u16(mask);
    #elif defined(AJ_BIT_REG_8BIT)
        shift = AJ_CTZ_u8(mask);
    #endif

    return (AJ_BitReg_t)((*reg & mask) >> shift);
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
    return (uint8_t)((((*reg) >> pos) & 0x01U) != 0U);
}

static inline uint8_t AJ_BitReg_GetBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
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
