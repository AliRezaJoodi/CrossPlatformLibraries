// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_VALUE32_INCLUDED
#define BIT_VALUE32_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//***********************************************************************
static inline uint32_t SetBitMask_u32(uint32_t value, uint32_t mask){
    return (uint32_t)(value | (mask));
}

static inline uint32_t SetBit_u32(uint32_t value, uint32_t pos){
    return (uint32_t)(value | (0x01UL << pos));
}

//static inline uint32_t Set2Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0x03UL) << pos));
//}
//
//static inline uint32_t Set3Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0x07UL) << pos));
//}
//
//static inline uint32_t Set4Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0x0FUL) << pos));
//}
//
//static inline uint32_t Set5Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0x1FUL) << pos));
//}
//
//static inline uint32_t Set6Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0x3FUL) << pos));
//}
//
//static inline uint32_t Set7Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0x7FUL) << pos));
//}
//
//static inline uint32_t Set8Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value | ((0xFFUL) << pos));
//}

//***********************************************************************
static inline uint32_t ClearBitMask_u32(uint32_t value, uint32_t mask){
    return (uint32_t)(value & ~(mask));
}

static inline uint32_t ClearBit_u32(uint32_t value, uint32_t pos){
    return (uint32_t)(value & ~(0x01UL << pos));
}

//static inline uint32_t Clear2Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0x03UL) << pos));
//}
//
//static inline uint32_t Clear3Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0x07UL) << pos));
//}
//
//static inline uint32_t Clear4Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0x0FUL) << pos));
//}
//
//static inline uint32_t Clear5Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0x1FUL) << pos));
//}
//
//static inline uint32_t Clear6Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0x3FUL) << pos));
//}
//
//static inline uint32_t Clear7Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0x7FUL) << pos));
//}
//
//static inline uint32_t Clear8Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value & ~((0xFFUL) << pos));
//}

//***********************************************************************
static inline uint32_t ToggleBitMask_u32(uint32_t value, uint32_t mask){
    return (uint32_t)(value ^ (mask));
}

static inline uint32_t ToggleBit_u32(uint32_t value, uint32_t pos){
    return (uint32_t)(value ^ (0x01UL << pos));
}

//static inline uint32_t Toggle2Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0x03UL) << pos));
//}
//
//static inline uint32_t Toggle3Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0x07UL) << pos));
//}
//
//static inline uint32_t Toggle4Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0x0FUL) << pos));
//}
//
//static inline uint32_t Toggle5Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0x1FUL) << pos));
//}
//
//static inline uint32_t Toggle6Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0x3FUL) << pos));
//}
//
//static inline uint32_t Toggle7Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0x7FUL) << pos));
//}
//
//static inline uint32_t Toggle8Bit_u32(uint32_t value, uint32_t pos){
//    return (uint32_t)(value ^ ((0xFFUL) << pos));
//}

//***********************************************************************
static inline uint32_t WriteBit_u32(uint32_t value, uint32_t pos, uint32_t status){
    return (uint32_t)(
            (value & ~(1UL << pos)) |
            ((status & 1UL) << pos)
            );
}

static inline uint32_t Write2Bit_u32(uint32_t value, uint32_t pos, uint32_t status){
    return (uint32_t)(
            (value & ~(0x03UL << pos)) |
            ((status & 0x03UL) << pos)
            );
}

static inline uint32_t Write3Bit_u32(uint32_t value, uint32_t pos, uint32_t status){
    return (uint32_t)(
            (value & ~(0x07UL << pos)) |
            ((status & 0x07UL) << pos)
            );
}

static inline uint32_t Write4Bit_u32(uint32_t value, uint32_t pos, uint32_t status){
    return (uint32_t)(
            (value & ~(0x0FUL << pos)) |
            ((status & 0x0FUL) << pos)
            );
}

//***********************************************************************
static inline uint32_t GetBitMask_u32(uint32_t value, uint32_t mask){
    return (uint32_t)((value & mask) != 0UL);
}

//***********************************************************************
static inline uint32_t GetBit_u32(uint32_t value, uint32_t pos){
    return (uint32_t)((value >> pos) & 0x01UL);
}

//***********************************************************************
static inline uint32_t Reflect_u32(uint32_t x){
    x = (uint32_t)((x >> 4) | (x << 4));
    x = (uint32_t)(((x & 0xCCUL) >> 2) | ((x & 0x33UL) << 2));
    x = (uint32_t)(((x & 0xAAUL) >> 1) | ((x & 0x55UL) << 1));

    return x;
}

#ifdef __cplusplus
}
#endif

#endif


