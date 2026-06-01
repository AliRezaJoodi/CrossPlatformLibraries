// GitHub Account:     GitHub.com/AliRezaJoodi
// Quadrature Encoder Interface

#ifndef QEI_INCLUDED
#define QEI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "qei_type.h"
#include "qei_port.h"

static const int8_t qei_table[16] = {
    0, -1, 1, 0,
    1, 0, 0, -1,
    -1, 0, 0, 1,
    0, 1, -1, 0
};

void QEI_Init(QEI_t *qei);

static inline void QEI_Update(QEI_t *qei){
    uint8_t phase , index;

    #if (QEI_AB_CLOSED == 0U)
    phase = (uint8_t)(
            QEI_B_Read(qei) << 1 |
            QEI_A_Read(qei)
            );
    #else
    phase = (uint8_t)(QEI_AB_Read(qei));
    #endif

    index = (uint8_t)(
            (qei->last << 2) | phase
            );

    qei->count += qei_table[index];

    qei->last = phase;
}

static inline int32_t QEI_GetCount(QEI_t *qei){
    return qei->count;
}

static inline void QEI_ResetCount(QEI_t *qei){
    qei->count = 0;
}

#if (QEI_Z == 1U)
static inline void QEI_SetIndexFlag(QEI_t *qei){
    qei->flag = 1;
}

static inline void QEI_ClearIndexFlag(QEI_t *qei){
    qei->flag = 0;
}

static inline uint8_t QEI_GetIndexFlag(const QEI_t *qei){
    return qei->flag;
}
#endif

#ifdef __cplusplus
}
#endif

#endif
