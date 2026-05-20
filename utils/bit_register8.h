// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_REGISTER8_INCLUDED
#define BIT_REGISTER8_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//***********************************************************************
static inline void SetBitMask_Reg8(volatile uint8_t *reg, uint8_t mask){
    *reg = (uint8_t)(*reg | mask);
}

static inline void SetBit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x01U << pos));
}

//static inline void Set2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0x03U << pos));
//}
//
//static inline void Set3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0x07U << pos));
//}
//
//static inline void Set4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0x0FU << pos));
//}
//
//static inline void Set5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0x1FU << pos));
//}
//
//static inline void Set6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0x3FU << pos));
//}
//
//static inline void Set7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0x7FU << pos));
//}
//
//static inline void Set8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg | (0xFFU << pos));
//}

//***********************************************************************
static inline void ClearBitMask_Reg8(volatile uint8_t *reg, uint8_t mask){
    *reg = (uint8_t)(*reg & (~mask));
}

static inline void ClearBit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x01U << pos));
}

//static inline void Clear2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0x03U << pos));
//}
//
//static inline void Clear3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0x07U << pos));
//}
//
//static inline void Clear4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0x0FU << pos));
//}
//
//static inline void Clear5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0x1FU << pos));
//}
//
//static inline void Clear6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0x3FU << pos));
//}
//
//static inline void Clear7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0x7FU << pos));
//}
//
//static inline void Clear8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg & ~(0xFFU << pos));
//}

//***********************************************************************
static inline void ToggleBitMask_Reg8(volatile uint8_t *reg, uint8_t mask){
    *reg = (uint8_t)(*reg ^ mask);
}

static inline void ToggleBit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x01U << pos));
}

static inline void TogglePort_Reg8(volatile uint8_t *reg){
    *reg = (uint8_t)(*reg ^ 0xFFU);
}

//static inline void Toggle2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0x03U << pos));
//}
//
//static inline void Toggle3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0x07U << pos));
//}
//
//static inline void Toggle4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0x0FU << pos));
//}
//
//static inline void Toggle5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0x1FU << pos));
//}
//
//static inline void Toggle6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0x3FU << pos));
//}
//
//static inline void Toggle7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0x7FU << pos));
//}
//
//static inline void Toggle8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
//    *reg = (uint8_t)(*reg ^ (0xFFU << pos));
//}

/* mask must not be 0 */
static inline void WriteBitField_Reg8(volatile uint8_t *reg, uint8_t mask, uint8_t value){
#if defined(__GNUC__) || defined(__clang__)
    if (mask == 0U){return;}

    *reg =  (uint8_t)(
            (*reg & ~mask) |
            ((value << __builtin_ctz(mask)) & mask)
            );
#else
    uint8_t shift = 0U;
    uint8_t temp = mask;

    if (mask == 0U){return;}

    while((temp & 0x01U) == 0U){
        temp >>= 1;
        ++shift;
    }

    *reg =  (uint8_t)(
            (*reg & ~mask) |
            ((value << shift) & mask)
            );
#endif
}

//***********************************************************************
static inline void WriteBit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg =  (uint8_t)(
            (*reg & ~(0x01U << pos)) |
            ((value & 0x01U) << pos)
            );
}

static inline void Write2Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg = (uint8_t)(
            (*reg & ~(0x03U << pos)) |
            ((value & 0x03U) << pos)
           );
}

static inline void Write3Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg = (uint8_t)(
            (*reg & ~(0x07U << pos)) |
            ((value & 0x07U) << pos)
           );
}

static inline void Write4Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg = (uint8_t)(
            (*reg & ~(0x0FU << pos)) |
            ((value & 0x0FU) << pos)
           );
}

static inline void Write5Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg = (uint8_t)(
            (*reg & ~(0x1FU << pos)) |
            ((value & 0x1FU) << pos)
           );
}

static inline void Write6Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg = (uint8_t)(
            (*reg & ~(0x3FU << pos)) |
            ((value & 0x3FU) << pos)
           );
}

static inline void Write7Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t value){
    *reg = (uint8_t)(
            (*reg & ~(0x7FU << pos)) |
            ((value & 0x7FU) << pos)
           );
}

static inline void WritePort_Reg8(volatile uint8_t *reg, uint8_t value){
    *reg = value;
}

//***********************************************************************
/* mask must not be 0 */
static inline uint8_t GetBitField_Reg8(volatile uint8_t *reg, uint8_t mask){
#if defined(__GNUC__) || defined(__clang__)
    if(mask == 0U){return 0U;}
    return (uint8_t)((*reg & mask) >> __builtin_ctz(mask));
#else
    uint8_t shift = 0U;
    uint8_t fieldMask = mask;

    if(mask == 0U){return 0U;}

    while((fieldMask & 1U) == 0U){
        fieldMask >>= 1;
        ++shift;
    }

    return (uint8_t)((*reg & mask) >> shift);
#endif
}

static inline uint8_t IsBitMaskSet_Reg8(volatile uint8_t *reg, uint8_t mask){
    return (uint8_t)((*reg & mask) != 0U);
}

static inline uint8_t GetBit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x01U);
}

static inline uint8_t Get2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x03U);
}

static inline uint8_t Get3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x07U);
}

static inline uint8_t Get4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x0FU);
}

static inline uint8_t Get5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x1FU);
}

static inline uint8_t Get6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x3FU);
}

static inline uint8_t Get7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x7FU);
}

#ifdef __cplusplus
}
#endif

#endif
