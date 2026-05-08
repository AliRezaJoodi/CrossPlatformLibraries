// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_VALUE8_INCLUDED
#define BIT_VALUE8_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//***********************************************************************
static inline uint8_t SetBitMask_u8(uint8_t value, uint8_t mask){
    return (uint8_t)(value | (mask));
}

static inline uint8_t SetBit_u8(uint8_t value, uint8_t pos){
    return (uint8_t)(value | (0x01U << pos));
}

//static inline uint8_t Set2Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0x03U) << pos));
//}
//
//static inline uint8_t Set3Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0x07U) << pos));
//}
//
//static inline uint8_t Set4Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0x0FU) << pos));
//}
//
//static inline uint8_t Set5Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0x1FU) << pos));
//}
//
//static inline uint8_t Set6Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0x3FU) << pos));
//}
//
//static inline uint8_t Set7Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0x7FU) << pos));
//}
//
//static inline uint8_t Set8Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value | ((0xFFU) << pos));
//}

//***********************************************************************
static inline uint8_t ClearBitMask_u8(uint8_t value, uint8_t mask){
    return (uint8_t)(value & ~(mask));
}

static inline uint8_t ClearBit_u8(uint8_t value, uint8_t pos){
    return (uint8_t)(value & ~(0x01U << pos));
}

//static inline uint8_t Clear2Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0x03U) << pos));
//}
//
//static inline uint8_t Clear3Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0x07U) << pos));
//}
//
//static inline uint8_t Clear4Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0x0FU) << pos));
//}
//
//static inline uint8_t Clear5Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0x1FU) << pos));
//}
//
//static inline uint8_t Clear6Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0x3FU) << pos));
//}
//
//static inline uint8_t Clear7Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0x7FU) << pos));
//}
//
//static inline uint8_t Clear8Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value & ~((0xFFU) << pos));
//}

//***********************************************************************
static inline uint8_t ToggleBitMask_u8(uint8_t value, uint8_t mask){
    return (uint8_t)(value ^ (mask));
}

static inline uint8_t ToggleBit_u8(uint8_t value, uint8_t pos){
    return (uint8_t)(value ^ (0x01U << pos));
}

//static inline uint8_t Toggle2Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0x03U) << pos));
//}
//
//static inline uint8_t Toggle3Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0x07U) << pos));
//}
//
//static inline uint8_t Toggle4Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0x0FU) << pos));
//}
//
//static inline uint8_t Toggle5Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0x1FU) << pos));
//}
//
//static inline uint8_t Toggle6Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0x3FU) << pos));
//}
//
//static inline uint8_t Toggle7Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0x7FU) << pos));
//}
//
//static inline uint8_t Toggle8Bit_u8(uint8_t value, uint8_t pos){
//    return (uint8_t)(value ^ ((0xFFU) << pos));
//}

//***********************************************************************
static inline uint8_t WriteBit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x01U << pos)) |
            ((status & 0x01U) << pos)
            );
}

static inline uint8_t Write2Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x03U << pos)) |
            ((status & 0x03U) << pos)
            );
}

static inline uint8_t Write3Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x07U << pos)) |
            ((status & 0x07U) << pos)
            );
}

static inline uint8_t Write4Bit_u8(uint8_t value, uint8_t pos, uint8_t status){
    return (uint8_t)(
            (value & ~(0x0FU << pos)) |
            ((status & 0x0FU) << pos)
            );
}

//***********************************************************************
static inline uint8_t GetBitMask_u8(uint8_t value, uint8_t mask){
    return (uint8_t)((value & mask) != 0U);
}

//***********************************************************************
static inline uint8_t GetBit_u8(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x01U);
}

static inline uint8_t Get2Bit_u8(uint8_t value, uint8_t pos){
    return (uint8_t)((value >> pos) & 0x03U);
}

//***********************************************************************
static inline uint8_t Reflect_u8(uint8_t x){
    x = (uint8_t)((x >> 4) | (x << 4));
    x = (uint8_t)(((x & 0xCCU) >> 2) | ((x & 0x33U) << 2));
    x = (uint8_t)(((x & 0xAAU) >> 1) | ((x & 0x55U) << 1));

    return x;
}

#ifdef __cplusplus
}
#endif

#endif


