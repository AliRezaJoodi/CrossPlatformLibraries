/**
 * @brief Bit manipulation utilities for 32-bit values.
 *
 * This header provides a set of static inline utility functions for common
 * bitwise operations on uint32_t values, including single-bit access,
 * multi-bit field access, and mask-based field manipulation.
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
 *   one contiguous bit-field. Non-contiguous masks may produce incorrect results.
 *
 * @subsection pos_reqs Position-based Operations
 * - The `pos` parameter is zero-based.
 * - Valid bit positions for uint32_t are in the range 0 to 31.
 * - Providing a position outside this range results in undefined behavior.
 *
 * @subsection field_reqs Field Values
 * - For write operations, only the least significant bits required by the target
 *   field width are used.
 * - Any higher bits in the input field value are ignored.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BIT_U32_INCLUDED
#define AJ_BIT_U32_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_ctz.h"

//***********************************************************************
static inline uint32_t AJ_BitU32_SetBits_Mask(uint32_t value, uint32_t mask){
    return (uint32_t)(value | (mask));
}

static inline uint32_t AJ_BitU32_SetBit_Position(uint32_t value, uint8_t pos){
    return (uint32_t)(value | (0x01UL << pos));
}

//***********************************************************************
static inline uint32_t AJ_BitU32_ClearBit_Mask(uint32_t value, uint32_t mask){
    return (uint32_t)(value & ~(mask));
}

static inline uint32_t AJ_BitU32_ClearBit_Position(uint32_t value, uint8_t pos){
    return (uint32_t)(value & ~(0x01UL << pos));
}

//***********************************************************************
static inline uint32_t AJ_BitU32_ToggleBits_Mask(uint32_t value, uint32_t mask){
    return (uint32_t)(value ^ (mask));
}

static inline uint32_t AJ_BitU32_ToggleBit_Position(uint32_t value, uint8_t pos){
    return (uint32_t)(value ^ (0x01UL << pos));
}

//***********************************************************************
/* Precondition:
 * - mask must be non-zero
 * - mask should describe one contiguous bit-field
 */
 static inline uint32_t AJ_BitU32_WriteField_Mask(uint32_t value, uint32_t mask, uint32_t field){
    uint8_t shift = AJ_CTZ_u32(mask);

    return  (uint32_t)(
            (value & ~mask) |
            ((field << shift) & mask)
            );
}

static inline uint32_t AJ_BitU32_WriteBit_Position(uint32_t value, uint8_t pos, uint32_t status){
    return (uint32_t)(
            (value & ~(1UL << pos)) |
            ((status & 1UL) << pos)
            );
}

static inline uint32_t AJ_BitU32_Write2Bits_Position(uint32_t value, uint8_t pos, uint32_t field){
    return (uint32_t)(
            (value & ~(0x03UL << pos)) |
            ((field & 0x03UL) << pos)
            );
}

static inline uint32_t AJ_BitU32_Write3Bits_Position(uint32_t value, uint8_t pos, uint32_t field){
    return (uint32_t)(
            (value & ~(0x07UL << pos)) |
            ((field & 0x07UL) << pos)
            );
}

static inline uint32_t AJ_BitU32_Write4Bits_Position(uint32_t value, uint8_t pos, uint32_t field){
    return (uint32_t)(
            (value & ~(0x0FUL << pos)) |
            ((field & 0x0FUL) << pos)
            );
}

//***********************************************************************
/* Precondition:
 * - mask must be non-zero
 * - mask should describe one contiguous bit-field
 */
static inline uint32_t AJ_BitU32_GetField_Mask(uint32_t value, uint32_t mask){
    uint8_t shift = AJ_CTZ_u32(mask);
    return (uint32_t)((value & mask) >> shift);
}
static inline uint8_t AJ_BitU32_AreBitsSet_Mask(uint32_t value, uint32_t mask){
    return (uint8_t)((value & mask) == mask);
}

static inline uint8_t AJ_BitU32_IsAnyBitSet_Mask(uint32_t value, uint32_t mask){
    return (uint8_t)((value & mask) != 0UL);
}

static inline uint8_t AJ_BitU32_IsBitSet_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x01UL);
}

static inline uint8_t AJ_BitU32_Get2Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x03UL);
}

static inline uint8_t AJ_BitU32_Get3Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x07UL);
}

static inline uint8_t AJ_BitU32_Get4Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x0FUL);
}

static inline uint8_t AJ_BitU32_Get5Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x1FUL);
}

static inline uint8_t AJ_BitU32_Get6Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x3FUL);
}

static inline uint8_t AJ_BitU32_Get7Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x7FUL);
}

static inline uint8_t AJ_BitU32_Get8Bits_Position(uint32_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0xFFUL);
}

#ifdef __cplusplus
}
#endif

#endif


