#ifndef QEI_PORT_INCLUDED
#define QEI_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "bit_register8.h"
#include "qei_hw.h"
#include "qei_types.h"

//*************************************************
static inline void QEI_A_ConfigInput(const QEI_t *qei){
    ClearBitMask_Reg8(qei->chA.ddr, qei->chA.mask);
}

static inline void QEI_A_ConfigPullNone(const QEI_t *qei){
    ClearBitMask_Reg8(qei->chA.port, qei->chA.mask);
}

static inline void QEI_A_ConfigPullUp(const QEI_t *qei){
    SetBitMask_Reg8(qei->chA.port, qei->chA.mask);
}

//*************************************************
static inline void QEI_B_ConfigInput(const QEI_t *qei){
    ClearBitMask_Reg8(qei->chB.ddr, qei->chB.mask);
}

static inline void QEI_B_ConfigPullNone(const QEI_t *qei){
    ClearBitMask_Reg8(qei->chB.port, qei->chB.mask);
}

static inline void QEI_B_ConfigPullUp(const QEI_t *qei){
    SetBitMask_Reg8(qei->chB.port, qei->chB.mask);
}

//*************************************************
#if (QEI_AB_CLOSED == 0U)
static inline uint8_t QEI_A_Read(const QEI_t *qei){
    return IsBitMaskSet_Reg8(qei->chA.pin, qei->chA.mask);
}

static inline uint8_t QEI_B_Read(const QEI_t *qei){
    return IsBitMaskSet_Reg8(qei->chB.pin, qei->chB.mask);
}

#else
static inline uint8_t QEI_AB_Read(const QEI_t *qei){
    return Get2Bit_Reg8(qei->chA.pin, qei->chA.index);
}
#endif

#ifdef __cplusplus
}
#endif

#endif
