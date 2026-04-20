// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_REGISTER_INCLUDED
#define BIT_REGISTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//***********************************************************************
static inline void Set_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x01U << pos));
}

static inline void Set_2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x03U << pos));
}

static inline void Set_3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x07U << pos));
}

static inline void Set_4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x0FU << pos));
}

static inline void Set_5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x1FU << pos));
}

static inline void Set_6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x3FU << pos));
}

static inline void Set_7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0x7FU << pos));
}

static inline void Set_8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (0xFFU << pos));
}

//***********************************************************************
static inline void Clear_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x01U << pos));
}

static inline void Clear_2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x03U << pos));
}

static inline void Clear_3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x07U << pos));
}

static inline void Clear_4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x0FU << pos));
}

static inline void Clear_5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x1FU << pos));
}

static inline void Clear_6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x3FU << pos));
}

static inline void Clear_7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0x7FU << pos));
}

static inline void Clear_8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(0xFFU << pos));
}

//***********************************************************************
static inline void Toggle_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x01U << pos));
}

static inline void Toggle_2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x03U << pos));
}

static inline void Toggle_3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x07U << pos));
}

static inline void Toggle_4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x0FU << pos));
}

static inline void Toggle_5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x1FU << pos));
}

static inline void Toggle_6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x3FU << pos));
}

static inline void Toggle_7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0x7FU << pos));
}

static inline void Toggle_8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (0xFFU << pos));
}

//***********************************************************************
static inline void Write_Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x01U << pos)) |
            ((status & 0x01U) << pos)
           );
}

static inline void Write_2Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x03U << pos)) |
            ((status & 0x03U) << pos)
           );
}

static inline void Write_3Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x07U << pos)) |
            ((status & 0x07U) << pos)
           );
}

static inline void Write_4Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x0FU << pos)) |
            ((status & 0x0FU) << pos)
           );
}

static inline void Write_5Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x1FU << pos)) |
            ((status & 0x1FU) << pos)
           );
}

static inline void Write_6Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x3FU << pos)) |
            ((status & 0x3FU) << pos)
           );
}

static inline void Write_7Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0x7FU << pos)) |
            ((status & 0x7FU) << pos)
           );
}

static inline void Write_8Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(0xFFU << pos)) |
            ((status & 0xFFU) << pos)
           );
}

//***********************************************************************
static inline uint8_t Get_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x01U);
}

static inline uint8_t Get_2Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x03U);
}

static inline uint8_t Get_3Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x07U);
}

static inline uint8_t Get_4Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x0FU);
}

static inline uint8_t Get_5Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x1FU);
}

static inline uint8_t Get_6Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x3FU);
}

static inline uint8_t Get_7Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x7FU);
}

static inline uint8_t Get_8Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0xFFU);
}

#ifdef __cplusplus
}
#endif

#endif
