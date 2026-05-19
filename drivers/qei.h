// GitHub Account:     GitHub.com/AliRezaJoodi
// Quadrature Encoder Interface

#ifndef QEI_INCLUDED
#define QEI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bit_register8.h"
#include "qei_hw.h"

static const int8_t qei_table[16] = {
  0, -1,  1,  0,
  1,  0,  0,  -1,
 -1,  0,  0,  1,
  0,  1,  -1, 0
};

int32_t qei_count = 0;
static uint8_t prev_state = 0;

static inline void qei_update(void){
    uint8_t current , index;

    current = (uint8_t)(
                GetBit_Reg8(&QEI_A_PIN, QEI_A_BIT) << 1 |
                GetBit_Reg8(&QEI_B_PIN, QEI_B_BIT)
                );

    index = (uint8_t)(
            (prev_state << 2) | current
            );

    qei_count += qei_table[index];

    prev_state = current;
}

#ifdef __cplusplus
}
#endif

#endif
