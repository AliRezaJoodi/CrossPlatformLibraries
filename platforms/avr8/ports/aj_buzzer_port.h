#ifndef AJ_BUZZER_PORT_INCLUDED
#define AJ_BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_buzzer_hw.h"

static inline void AJ_Buzzer_Pin_ConfigAsOutput(void){
    AJ_BitReg_SetBit_Mask(&AJ_BUZZER_DDR, AJ_BUZZER_MASK);
}

static inline void AJ_Buzzer_Pin_Set(void){
    AJ_BitReg_SetBit_Mask(&AJ_BUZZER_PORT, AJ_BUZZER_MASK);
}

static inline void AJ_Buzzer_Pin_Clear(void){
    AJ_BitReg_ClearBit_Mask(&AJ_BUZZER_PORT, AJ_BUZZER_MASK);
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUZZER_PORT_INCLUDED */
