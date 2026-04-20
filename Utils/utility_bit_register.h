// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef UTILITY_BIT_REGISTER_INCLUDED
#define UTILITY_BIT_REGISTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline void Write_Bit_Reg8(volatile uint8_t *reg, uint8_t pos, uint8_t status){
    *reg = (uint8_t)(
            (*reg & ~(1U << pos)) |
            ((status & 1U) << pos)
           );
}

#ifdef __cplusplus
}
#endif

#endif
