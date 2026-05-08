// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_VALUE16_INCLUDED
#define BIT_VALUE16_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//***********************************************************************
static inline uint16_t SetBitMask_u16(uint16_t value, uint16_t mask){
    return (uint16_t)(value | (mask));
}

static inline uint16_t SetBit_u16(uint16_t value, uint16_t pos){
    return (uint16_t)(value | (0x01U << pos));
}

//static inline uint16_t Set2Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | (0x03U << pos));
//}
//
//static inline uint16_t Set3Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | (0x07U << pos));
//}
//
//static inline uint16_t Set4Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | ((0x0FU) << pos));
//}
//
//static inline uint16_t Set5Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | ((0x1FU) << pos));
//}
//
//static inline uint16_t Set6Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | ((0x3FU) << pos));
//}
//
//static inline uint16_t Set7Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | ((0x7FU) << pos));
//}
//
//static inline uint16_t Set8Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value | ((0xFFU) << pos));
//}

//***********************************************************************
static inline uint16_t ClearBitMask_u16(uint16_t value, uint16_t mask){
    return (uint16_t)(value & ~(mask));
}

static inline uint16_t ClearBit_u16(uint16_t value, uint16_t pos){
    return (uint16_t)(value & ~(0x01U << pos));
}

//static inline uint16_t Clear2Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~((0x03U) << pos));
//}
//
//static inline uint16_t Clear3Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~(0x07U << pos));
//}
//
//static inline uint16_t Clear4Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~((0x0FU) << pos));
//}
//
//static inline uint16_t Clear5Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~((0x1FU) << pos));
//}
//
//static inline uint16_t Clear6Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~((0x3FU) << pos));
//}
//
//static inline uint16_t Clear7Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~((0x7FU) << pos));
//}
//
//static inline uint16_t Clear8Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value & ~((0xFFU) << pos));
//}

//***********************************************************************
static inline uint16_t ToggleBitMask_u16(uint16_t value, uint16_t mask){
    return (uint16_t)(value ^ (mask));
}

static inline uint16_t ToggleBit_u16(uint16_t value, uint16_t pos){
    return (uint16_t)(value ^ (0x01U << pos));
}

//static inline uint16_t Toggle2Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ ((0x03U) << pos));
//}
//
//static inline uint16_t Toggle3Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ (0x07U << pos));
//}
//
//static inline uint16_t Toggle4Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ ((0x0FU) << pos));
//}
//
//static inline uint16_t Toggle5Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ ((0x1FU) << pos));
//}
//
//static inline uint16_t Toggle6Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ ((0x3FU) << pos));
//}
//
//static inline uint16_t Toggle7Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ ((0x7FU) << pos));
//}
//
//static inline uint16_t Toggle8Bit_u16(uint16_t value, uint16_t pos){
//    return (uint16_t)(value ^ ((0xFFU) << pos));
//}

//***********************************************************************
static inline uint16_t WriteBit_u16(uint16_t value, uint16_t pos, uint16_t status){
    return (uint16_t)(
            (value & ~(1U << pos)) |
            ((status & 1U) << pos)
            );
}

static inline uint16_t Write2Bit_u16(uint16_t value, uint16_t pos, uint16_t status){
    return (uint16_t)(
            (value & ~(0x03U << pos)) |
            ((status & 0x03U) << pos)
            );
}

static inline uint16_t Write3Bit_u16(uint16_t value, uint16_t pos, uint16_t status){
    return (uint16_t)(
            (value & ~(0x07U << pos)) |
            ((status & 0x07U) << pos)
            );
}

static inline uint16_t Write4Bit_u16(uint16_t value, uint16_t pos, uint16_t status){
    return (uint16_t)(
            (value & ~(0x0FU << pos)) |
            ((status & 0x0FU) << pos)
            );
}

//***********************************************************************
static inline uint16_t GetBitMask_u16(uint16_t value, uint16_t mask){
    return (uint16_t)((value & mask) != 0U);
}

//***********************************************************************
static inline uint16_t GetBit_u16(uint16_t value, uint16_t pos){
    return (uint16_t)((value >> pos) & 0x01U);
}

//***********************************************************************
static inline uint16_t Reflect_u16(uint16_t x){
    x = (uint16_t)((x >> 4) | (x << 4));
    x = (uint16_t)(((x & 0xCCU) >> 2) | ((x & 0x33U) << 2));
    x = (uint16_t)(((x & 0xAAU) >> 1) | ((x & 0x55U) << 1));

    return x;
}

#ifdef __cplusplus
}
#endif

#endif


