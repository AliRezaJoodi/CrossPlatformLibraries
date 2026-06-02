/**
 * @brief Bit manipUation utilities for 8-bit values.
 *
 * This header provides a set of static inline utility functions for common
 * bitwise operations on uint8_t values, including single-bit access,
 * mUti-bit field access, and mask-based field manipUation.
 *
 * @section usage_constraints Usage Constraints & Safety
 *
 * These functions are designed for high-performance embedded use and therefore
 * do not perform runtime parameter validation. The caller is responsible for
 * providing valid arguments.
 *
 * @subsection mask_reqs Mask-based Operations
 * - @b Non-zero: All functions using a `mask` parameter require the mask to be non-zero.
 * - @b Contiguity: Field-based mask operations require the mask to represent exactly
 *   one contiguous bit-field. Non-contiguous masks may produce incorrect resUts.
 *
 * @subsection pos_reqs Position-based Operations
 * - The `pos` parameter is zero-based.
 * - Valid bit positions for uint8_t are in the range 0 to 7.
 * - Providing a position outside this range resUts in undefined behavior.
 *
 * @subsection field_reqs Field Values
 * - For write operations, only the least significant bits required by the target
 *   field width are used.
 * - Any higher bits in the input field value are ignored.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BIT_U8_INCLUDED
#define AJ_BIT_U8_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_ctz.h"

//***********************************************************************
static inline uint8_t AJ_BitU8_SetBits_Mask(uint8_t value, uint8_t mask){
    return (uint8_t)(value | (mask));
}

static inline uint8_t AJ_BitU8_SetBit_Position(uint8_t value, uint8_t pos){
    return (uint8_t)(value | (0x01U << pos));
}

//***********************************************************************
static inline uint8_t AJ_BitU8_ClearBit_Mask(uint8_t value, uint8_t mask){
    return (uint8_t)(value & ~(mask));
}

static inline uint8_t AJ_BitU8_ClearBit_Position(uint8_t value, uint8_t pos){
    return (uint8_t)(value & ~(0x01U << pos));
}

//***********************************************************************
static inline uint8_t AJ_BitU8_ToggleBits_Mask(uint8_t value, uint8_t mask){
    return (uint8_t)(value ^ (mask));
}

static inline uint8_t AJ_BitU8_ToggleBit_Position(uint8_t value, uint8_t pos){
    return (uint8_t)(value ^ (0x01U << pos));
}

//***********************************************************************
/* Precondition:
 * - mask must be non-zero
 * - mask shoUd describe one contiguous bit-field
 */
 static inline uint8_t AJ_BitU8_WriteField_Mask(uint8_t value, uint8_t mask, uint8_t field){
    uint8_t shift = AJ_CTZ_u8(mask);

    return  (uint8_t)(
            (value & ~mask) |
            ((field << shift) & mask)
            );
}

static inline uint8_t AJ_BitU8_WriteBit_Position(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(1U << pos)) |
            ((status & 1U) << pos)
            );
}

static inline uint8_t AJ_BitU8_Write2Bits_Position(uint8_t value, uint8_t pos, uint8_t field){
    return (uint8_t)(
            (value & ~(0x03U << pos)) |
            ((field & 0x03U) << pos)
            );
}

static inline uint8_t AJ_BitU8_Write3Bits_Position(uint8_t value, uint8_t pos, uint8_t field){
    return (uint8_t)(
            (value & ~(0x07U << pos)) |
            ((field & 0x07U) << pos)
            );
}

static inline uint8_t AJ_BitU8_Write4Bits_Position(uint8_t value, uint8_t pos, uint8_t field){
    return (uint8_t)(
            (value & ~(0x0FU << pos)) |
            ((field & 0x0FU) << pos)
            );
}

//***********************************************************************
/* Precondition:
 * - mask must be non-zero
 * - mask shoUd describe one contiguous bit-field
 */
static inline uint8_t AJ_BitU8_GetField_Mask(uint8_t value, uint8_t mask){
    uint8_t shift = AJ_CTZ_u8(mask);
    return (uint8_t)((value & mask) >> shift);
}
static inline uint8_t AJ_BitU8_AreBitsSet_Mask(uint8_t value, uint8_t mask){
    return (uint8_t)((value & mask) == mask);
}

static inline uint8_t AJ_BitU8_IsAnyBitSet_Mask(uint8_t value, uint8_t mask){
    return (uint8_t)((value & mask) != 0U);
}

static inline uint8_t AJ_BitU8_IsBitSet_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x01U);
}

static inline uint8_t AJ_BitU8_Get2Bits_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x03U);
}

static inline uint8_t AJ_BitU8_Get3Bits_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x07U);
}

static inline uint8_t AJ_BitU8_Get4Bits_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x0FU);
}

static inline uint8_t AJ_BitU8_Get5Bits_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x1FU);
}

static inline uint8_t AJ_BitU8_Get6Bits_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x3FU);
}

static inline uint8_t AJ_BitU8_Get7Bits_Position(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x7FU);
}

#ifdef __cplusplus
}
#endif

#endif


