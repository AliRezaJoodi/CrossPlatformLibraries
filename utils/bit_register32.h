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

//static inline void Set2Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0x03UL << pos));
//}
//
//static inline void Set3Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0x07UL << pos));
//}
//
//static inline void Set4Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0x0FUL << pos));
//}
//
//static inline void Set5Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0x1FUL << pos));
//}
//
//static inline void Set6Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0x3FUL << pos));
//}
//
//static inline void Set7Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0x7FUL << pos));
//}
//
//static inline void Set8Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg | (0xFFUL << pos));
//}

//***********************************************************************
static inline void ClearBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
    *reg = (uint32_t)(*reg & (~mask));
}

static inline void ClearBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    *reg = (uint32_t)(*reg & ~(0x01UL << pos));
}

//static inline void Clear2Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0x03UL << pos));
//}
//
//static inline void Clear3Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0x07UL << pos));
//}
//
//static inline void Clear4Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0x0FUL << pos));
//}
//
//static inline void Clear5Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0x1FUL << pos));
//}
//
//static inline void Clear6Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0x3FUL << pos));
//}
//
//static inline void Clear7Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0x7FUL << pos));
//}
//
//static inline void Clear8Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg & ~(0xFFUL << pos));
//}

//***********************************************************************
static inline void ToggleBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
    *reg = (uint32_t)(*reg ^ mask);
}

static inline void ToggleBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    *reg = (uint32_t)(*reg ^ (0x01UL << pos));
}

static inline void TogglePort_Reg32(volatile uint32_t *reg){
    *reg = (uint32_t)(*reg ^ 0xFFFFFFFFUL);
}

//static inline void Toggle2Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0x03UL << pos));
//}
//
//static inline void Toggle3Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0x07UL << pos));
//}
//
//static inline void Toggle4Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0x0FUL << pos));
//}
//
//static inline void Toggle5Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0x1FUL << pos));
//}
//
//static inline void Toggle6Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0x3FUL << pos));
//}
//
//static inline void Toggle7Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0x7FUL << pos));
//}
//
//static inline void Toggle8Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
//    *reg = (uint32_t)(*reg ^ (0xFFUL << pos));
//}

// Note: This branchless bit-mask technique may not work correctly with CodeVisionAVR due to compiler optimization issues.
//static inline void WriteBitMask_Reg32(volatile uint32_t *reg, uint32_t mask, uint32_t status){
//    *reg = (uint32_t)((*reg & ~mask) | ((-!!status) & mask));
//}

//***********************************************************************
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
static inline uint32_t ReadBitMask_Reg32(volatile uint32_t *reg, uint32_t mask){
    return (uint32_t)(((*reg) & mask) != 0UL);
}

static inline uint32_t ReadBit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x01UL);
}

static inline uint32_t Get2Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x03UL);
}

static inline uint32_t Get3Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x07UL);
}

static inline uint32_t Get4Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x0FUL);
}

static inline uint32_t Get5Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x1FUL);
}

static inline uint32_t Get6Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x3FUL);
}

static inline uint32_t Get7Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0x7FUL);
}

static inline uint32_t Get8Bit_Reg32(volatile uint32_t *reg, uint32_t pos){
    return (uint32_t)((*reg >> pos) & 0xFFU);
}

#ifdef __cplusplus
}
#endif

#endif
