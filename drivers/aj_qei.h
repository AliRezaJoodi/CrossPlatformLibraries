// GitHub Account:     GitHub.com/AliRezaJoodi
// Quadrature Encoder Interface

#ifndef AJ_QEI_INCLUDED
#define AJ_QEI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_qei_type.h"
#include "aj_qei_port.h"

static const int8_t qei_table[16] = {
    0, -1, 1, 0,
    1, 0, 0, -1,
    -1, 0, 0, 1,
    0, 1, -1, 0
};

void AJ_QEI_Init(aj_QEI_t *qei);

static inline void AJ_QEI_Update(aj_QEI_t *qei){
    uint8_t phase , index;

    #if (AJ_QEI_AB_CLOSED == 0U)
    phase = (uint8_t)(
            AJ_QEI_B_Read(qei) << 1 |
            AJ_QEI_A_Read(qei)
            );
    #else
    phase = (uint8_t)(AJ_QEI_AB_Read(qei));
    #endif

    index = (uint8_t)(
            (qei->last << 2) | phase
            );

    qei->count += qei_table[index];

    qei->last = phase;
}

static inline int32_t AJ_QEI_GetCount(aj_QEI_t *qei){
    return qei->count;
}

static inline void AJ_QEI_ResetCount(aj_QEI_t *qei){
    qei->count = 0;
}

#if (AJ_QEI_Z == 1U)
static inline void AJ_QEI_SetIndexFlag(aj_QEI_t *qei){
    qei->flag = 1;
}

static inline void AJ_QEI_ClearIndexFlag(aj_QEI_t *qei){
    qei->flag = 0;
}

static inline uint8_t AJ_QEI_GetIndexFlag(const aj_QEI_t *qei){
    return qei->flag;
}
#endif

#ifdef __cplusplus
}
#endif

#endif
