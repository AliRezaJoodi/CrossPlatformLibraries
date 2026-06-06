#ifndef AJ_QEI_PORT_INCLUDED
#define AJ_QEI_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler_port.h"
#include "aj_bit_reg.h"
#include "aj_qei_hw.h"
#include "aj_qei_type.h"

//*************************************************
static inline void AJ_QEI_A_ConfigAsInput(const aj_QEI_t *qei){
    AJ_BitReg_ClearBits_Mask(qei->chA.ddr, qei->chA.mask);
}

static inline void AJ_QEI_A_ConfigAsPullNone(const aj_QEI_t *qei){
    AJ_BitReg_ClearBits_Mask(qei->chA.port, qei->chA.mask);
}

static inline void AJ_QEI_A_ConfigAsPullUp(const aj_QEI_t *qei){
    AJ_BitReg_SetBits_Mask(qei->chA.port, qei->chA.mask);
}

//*************************************************
static inline void AJ_QEI_B_ConfigAsInput(const aj_QEI_t *qei){
    AJ_BitReg_ClearBits_Mask(qei->chB.ddr, qei->chB.mask);
}

static inline void AJ_QEI_B_ConfigAsPullNone(const aj_QEI_t *qei){
    AJ_BitReg_ClearBits_Mask(qei->chB.port, qei->chB.mask);
}

static inline void AJ_QEI_B_ConfigAsPullUp(const aj_QEI_t *qei){
    AJ_BitReg_SetBits_Mask(qei->chB.port, qei->chB.mask);
}

//*************************************************
#if (AJ_QEI_AB_CLOSED == 0U)
static inline uint8_t AJ_QEI_A_Read(const aj_QEI_t *qei){
    return AJ_BitReg_AreBitsSet_Mask(qei->chA.pin, qei->chA.mask);
}

static inline uint8_t AJ_QEI_B_Read(const aj_QEI_t *qei){
    return AJ_BitReg_AreBitsSet_Mask(qei->chB.pin, qei->chB.mask);
}

#else
static inline uint8_t AJ_QEI_AB_Read(const aj_QEI_t *qei){
    return AJ_BitReg_Get2Bits_Position(qei->chA.pin, qei->chA.pos);
}
#endif

#ifdef __cplusplus
}
#endif

#endif
