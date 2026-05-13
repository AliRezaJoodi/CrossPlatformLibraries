// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_REGISTER32_INCLUDED
#define BIT_REGISTER32_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//***********************************************************************
static inline void SetBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
    *reg = (uint32_t)(*reg | mask);
}

static inline void SetBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    *reg = (uint32_t)(*reg | (0x01UL << pos));
}

//***********************************************************************
static inline void ClearBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
    *reg = (uint32_t)(*reg & (~mask));
}

static inline void ClearBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    *reg = (uint32_t)(*reg & ~(0x01UL << pos));
}

//***********************************************************************
static inline void ToggleBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
    *reg = (uint32_t)(*reg ^ mask);
}

static inline void ToggleBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    *reg = (uint32_t)(*reg ^ (0x01UL << pos));
}

//***********************************************************************
/* mask must not be 0 */
static inline void WriteField_Reg32(volatile uint32_t *reg, uint32_t mask, uint32_t value){
#if defined(__GNUC__) || defined(__clang__)
    if (mask == 0U){return;}

    *reg = 	(*reg & ~mask) |
						((value << __builtin_ctz(mask)) & mask);
#else
    uint32_t shift = 0U;
    uint32_t temp  = mask;

    if (mask == 0U){return;}

    while((temp & 0x01U) == 0U){
        temp >>= 1U;
        ++shift;
    }

    *reg =
        (*reg & ~mask) |
        ((value << shift) & mask);
#endif
}

static inline void WriteBit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x01UL << pos)) |
            ((status & 0x01UL) << pos)
           );
}

static inline void Write2Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x03UL << pos)) |
            ((status & 0x03UL) << pos)
           );
}

static inline void Write3Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x07UL << pos)) |
            ((status & 0x07UL) << pos)
           );
}

static inline void Write4Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x0FUL << pos)) |
            ((status & 0x0FUL) << pos)
           );
}

static inline void Write5Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x1FUL << pos)) |
            ((status & 0x1FUL) << pos)
           );
}

static inline void Write6Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x3FUL << pos)) |
            ((status & 0x3FUL) << pos)
           );
}

static inline void Write7Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0x7FUL << pos)) |
            ((status & 0x7FUL) << pos)
           );
}

static inline void Write8Bit_Reg32(volatile uint32_t *reg, uint32_t pos, uint32_t status){
    *reg = (uint32_t)(
            (*reg & ~(0xFFUL << pos)) |
            ((status & 0xFFUL) << pos)
           );
}

//***********************************************************************
/* mask must not be 0 */
static inline uint32_t GetField_Reg32(volatile uint32_t *reg, uint32_t mask){
#if defined(__GNUC__) || defined(__clang__)
    if(mask == 0U){return 0U;}

    return (uint32_t)((*reg & mask) >> __builtin_ctz(mask));
#else
    uint32_t shift     = 0U;
    uint32_t fieldMask = mask;

    if(mask == 0U){return 0U;}

    while((fieldMask & 1U) == 0U){
        fieldMask >>= 1U;
        ++shift;
    }

    return (uint32_t)((*reg & mask) >> shift);
#endif
}

//static inline uint8_t IsSetBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
//    return (uint8_t)(((*reg) & mask) != 0UL);
//}

static inline uint8_t GetBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x01UL);
}

static inline uint8_t Get2Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x03UL);
}

static inline uint8_t Get3Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x07UL);
}

static inline uint8_t Get4Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x0FUL);
}

static inline uint8_t Get5Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x1FUL);
}

static inline uint8_t Get6Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x3FUL);
}

static inline uint8_t Get7Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0x7FUL);
}

static inline uint8_t Get8Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint8_t)((*reg >> pos) & 0xFFU);
}

#ifdef __cplusplus
}
#endif

#endif
