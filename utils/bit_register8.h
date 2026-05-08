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

// Note: This branchless bit-mask technique may not work correctly with CodeVisionAVR due to compiler optimization issues.
//static inline void WriteBitMask_Reg8(volatile uint8_t *reg, uint8_t mask, uint8_t status){
//    *reg = (uint8_t)((*reg & ~mask) | ((-!!status) & mask));
//}

//***********************************************************************
static inline void WriteBit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x01U << pos)) |
            ((status & 0x01U) << pos)
           );
}

static inline void Write2Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x03U << pos)) |
            ((status & 0x03U) << pos)
           );
}

static inline void Write3Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x07U << pos)) |
            ((status & 0x07U) << pos)
           );
}

static inline void Write4Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x0FU << pos)) |
            ((status & 0x0FU) << pos)
           );
}

static inline void Write5Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x1FU << pos)) |
            ((status & 0x1FU) << pos)
           );
}

static inline void Write6Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x3FU << pos)) |
            ((status & 0x3FU) << pos)
           );
}

static inline void Write7Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x7FU << pos)) |
            ((status & 0x7FU) << pos)
           );
}

static inline void WritePort_Reg8(volatile uint8_t *reg, uint8_t value){
    *reg = value;
}

//***********************************************************************
static inline uint8_t ReadBitMask_Reg8(volatile uint8_t *reg, uint8_t mask){
    return (uint8_t)((*reg & mask) != 0U);
}

static inline uint8_t ReadBit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x01U);
}

static inline uint8_t Read2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x03U);
}

static inline uint8_t Read3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x07U);
}

static inline uint8_t Read4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x0FU);
}

static inline uint8_t Get5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x1FU);
}

static inline uint8_t Read6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x3FU);
}

static inline uint8_t Read7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x7FU);
}

#ifdef __cplusplus
}
#endif

#endif
