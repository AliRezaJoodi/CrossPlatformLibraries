// GitHub Account:     GitHub.com/AliRezaJoodi
// Quadrature Encoder Interface

#ifndef QEI_INCLUDED
#define QEI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bit_register8.h"
#include "qei_types.h"
#include "qei_port.h"

static const int8_t qei_table[16] = {
    0, -1, 1, 0,
    1, 0, 0, -1,
    -1, 0, 0, 1,
    0, 1, -1, 0
};

void QEI_Init(QEI_t *qei);

static inline void qei_update(QEI_t *qei){
    uint8_t phase , index;

    phase = (uint8_t)(
                GetBit_Reg8(&QEI_A_PIN, QEI_A_BIT) << 1 |
                GetBit_Reg8(&QEI_B_PIN, QEI_B_BIT)
                );

    index = (uint8_t)(
            (qei->last << 2) | phase
            );

    qei->count += qei_table[index];

    qei->last = phase;
}

#ifdef __cplusplus
}
#endif

#endif
