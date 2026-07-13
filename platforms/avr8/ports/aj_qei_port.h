#ifndef AJ_QEI_PORT_INCLUDED
#define AJ_QEI_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_qei_config.h"
#include "aj_qei_type.h"

//*************************************************
static inline void AJ_QEI_A_ConfigAsInput(const aj_qei_t *qei){
    AJ_BitReg_ClearBit_Mask(qei->chA.ddr, qei->chA.mask);
}

static inline void AJ_QEI_A_ConfigAsPullNone(const aj_qei_t *qei){
    AJ_BitReg_ClearBit_Mask(qei->chA.port, qei->chA.mask);
}

static inline void AJ_QEI_A_ConfigAsPullUp(const aj_qei_t *qei){
    AJ_BitReg_SetBit_Mask(qei->chA.port, qei->chA.mask);
}

//*************************************************
static inline void AJ_QEI_B_ConfigAsInput(const aj_qei_t *qei){
    AJ_BitReg_ClearBit_Mask(qei->chB.ddr, qei->chB.mask);
}

static inline void AJ_QEI_B_ConfigAsPullNone(const aj_qei_t *qei){
    AJ_BitReg_ClearBit_Mask(qei->chB.port, qei->chB.mask);
}

static inline void AJ_QEI_B_ConfigAsPullUp(const aj_qei_t *qei){
    AJ_BitReg_SetBit_Mask(qei->chB.port, qei->chB.mask);
}

//*************************************************
#if (AJ_QEI_AB_CLOSED == 0U)
    static inline uint8_t AJ_QEI_A_Read(const aj_qei_t *qei){
        return AJ_BitReg_IsBitSet_Mask(qei->chA.pin, qei->chA.mask);
    }

    static inline uint8_t AJ_QEI_B_Read(const aj_qei_t *qei){
        return AJ_BitReg_IsBitSet_Mask(qei->chB.pin, qei->chB.mask);
    }
#else
    static inline uint8_t AJ_QEI_AB_Read(const aj_qei_t *qei){
        return AJ_BitReg_Get2Bits_Position(qei->chA.pin, qei->chA.pos);
    }
#endif

//*************************************************
#if (AJ_QEI_Z_USED == 0U)
static inline void AJ_QEI_Z_ConfigAsInput(const aj_qei_t *qei){
    AJ_BitReg_ClearBit_Mask(qei->chZ.ddr, qei->chZ.mask);
}

static inline void AJ_QEI_Z_ConfigAsPullNone(const aj_qei_t *qei){
    AJ_BitReg_ClearBit_Mask(qei->chZ.port, qei->chZ.mask);
}

static inline void AJ_QEI_Z_ConfigAsPullUp(const aj_qei_t *qei){
    AJ_BitReg_SetBit_Mask(qei->chZ.port, qei->chZ.mask);
}
#endif


#ifdef __cplusplus
}
#endif

#endif
