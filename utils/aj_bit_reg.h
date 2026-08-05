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
 * -----------------------------------------------------------------------------
 * REQUIREMENT: Configuration Override
 * -----------------------------------------------------------------------------
 * The default macros are declared in the following headers:
 * - `aj_target.h`
 *
 * To customize these configurations, override them inside the central project
 * hardware configuration file:
 * - `hardware.h`
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
#include "aj_target.h"
#include "aj_ctz.h"

#if AJ_TARGET_MCU_BITS == 32U
    typedef uint32_t AJ_BitReg_t;
    #define AJ_BITREG_CTZ(mask)    AJ_CTZ_u32((mask))
#elif AJ_TARGET_MCU_BITS == 16U
    typedef uint16_t AJ_BitReg_t;
    #define AJ_BITREG_CTZ(mask)    AJ_CTZ_u16((mask))
#elif AJ_TARGET_MCU_BITS == 8U
    typedef uint8_t AJ_BitReg_t;
    #define AJ_BITREG_CTZ(mask)    AJ_CTZ_u8((mask))
#endif

//***********************************************************************
static inline void AJ_BitReg_SetBit_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    *reg = (AJ_BitReg_t)(*reg | mask);
}

static inline void AJ_BitReg_SetBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    *reg = (AJ_BitReg_t)(*reg | (0x01U << pos));
}

//***********************************************************************
static inline void AJ_BitReg_ClearBit_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    *reg = (AJ_BitReg_t)(*reg & (~mask));
}

static inline void AJ_BitReg_ClearBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    *reg = (AJ_BitReg_t)(*reg & ~(0x01U << pos));
}

//***********************************************************************
static inline void AJ_BitReg_ToggleBit_Mask(volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
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
    uint8_t shift = AJ_BITREG_CTZ(mask);

    *reg =  (AJ_BitReg_t)(
            (*reg & ~mask) |
            ((value << shift) & mask)
            );
}

/**
 * @param pos    Start bit position of the field.
 * @param width  Number of bits in the field.
 * @param value  Field value to be written.
 *
 * @note  The following conditions must be satisfied depending on register size:
 *
 *        For 8-bit registers:
 *        - pos = 0 to 7
 *        - width = 1 to 7
 *        - pos + width <= 8
 *
 *        For 16-bit registers:
 *        - pos = 0 to 15
 *        - width = 1 to 15
 *        - pos + width <= 16
 *
 *        For 32-bit registers:
 *        - pos = 0 to 31
 *        - width = 1 to 31
 *        - pos + width <= 32
 */
static inline void AJ_BitReg_WriteField_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, uint8_t width, AJ_BitReg_t value){
    AJ_BitReg_t mask = (AJ_BitReg_t)(((1U << width) - 1U) << pos);

    *reg = (AJ_BitReg_t)(
            (*reg & ~mask) |
            ((value << pos) & mask)
           );
}

static inline void AJ_BitReg_WriteBit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t status){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x01U << pos)) |
            ((status & 0x01U) << pos)
           );
}

static inline void AJ_BitReg_Write2Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x03U << pos)) |
            ((field & 0x03U) << pos)
           );
}

static inline void AJ_BitReg_Write3Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x07U << pos)) |
            ((field & 0x07U) << pos)
           );
}

static inline void AJ_BitReg_Write4Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x0FU << pos)) |
            ((field & 0x0FU) << pos)
           );
}

static inline void AJ_BitReg_Write5Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x1FU << pos)) |
            ((field & 0x1FU) << pos)
           );
}

static inline void AJ_BitReg_Write6Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x3FU << pos)) |
            ((field & 0x3FU) << pos)
           );
}

static inline void AJ_BitReg_Write7Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
    *reg = (AJ_BitReg_t)(
            (*reg & ~(0x7FU << pos)) |
            ((field & 0x7FU) << pos)
           );
}

static inline void AJ_BitReg_Write8Bit_Position(volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, AJ_BitReg_t field){
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
static inline AJ_BitReg_t AJ_BitReg_GetField_Mask(const volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    uint8_t shift = AJ_BITREG_CTZ(mask);

    return (AJ_BitReg_t)((*reg & mask) >> shift);
}

/* mask must not be 0 */
static inline uint8_t AJ_BitReg_IsBitSet_Mask(const volatile AJ_BitReg_t *reg, AJ_BitReg_t mask){
    return (uint8_t)(((*reg) & mask) == mask);
}

/**
 * @param pos    Start bit position of the field.
 * @param width  Number of bits in the field.
 * @note  The following conditions must be satisfied depending on register size:
 *
 *        For 8-bit registers:
 *        - pos = 0 to 7
 *        - width = 1 to 7
 *        - pos + width <= 8
 *
 *        For 16-bit registers:
 *        - pos = 0 to 15
 *        - width = 1 to 15
 *        - pos + width <= 16
 *
 *        For 32-bit registers:
 *        - pos = 0 to 31
 *        - width = 1 to 31
 *        - pos + width <= 32
 */
static inline AJ_BitReg_t AJ_BitReg_GetField_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos, uint8_t width){
    return (AJ_BitReg_t)((*reg >> pos) & ((1U << width) - 1U));
}

static inline uint8_t AJ_BitReg_IsBitSet_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((((*reg) >> pos) & 0x01U) != 0U);
}

static inline uint8_t AJ_BitReg_GetBit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x01U);
}

static inline uint8_t AJ_BitReg_Get2Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x03U);
}

static inline uint8_t AJ_BitReg_Get3Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x07U);
}

static inline uint8_t AJ_BitReg_Get4Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x0FU);
}

static inline uint8_t AJ_BitReg_Get5Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x1FU);
}

static inline uint8_t AJ_BitReg_Get6Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x3FU);
}

static inline uint8_t AJ_BitReg_Get7Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0x7FU);
}

static inline uint8_t AJ_BitReg_Get8Bit_Position(const volatile AJ_BitReg_t *reg, AJ_BitReg_t pos){
    return (uint8_t)((*reg >> pos) & 0xFFU);
}


#ifdef __cplusplus
}
#endif

#endif
