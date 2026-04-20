// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BIT_REGISTER_INCLUDED
#define BIT_REGISTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline void Set_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg | (1U << pos));
}

static inline void Clear_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg & ~(1U << pos));
}

static inline void Toggle_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    *reg = (uint8_t)(*reg ^ (1U << pos));
}

static inline void Write_Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(1U << pos)) |
            ((status & 1U) << pos)
           );
}

static inline uint8_t Get_Bit_Reg8(volatile uint8_t *reg, uint8_t pos){
    return (uint8_t)((*reg >> pos) & 0x01U);
}

#ifdef __cplusplus
}
#endif

#endif
