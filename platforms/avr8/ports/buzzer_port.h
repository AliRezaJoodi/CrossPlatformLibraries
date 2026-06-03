#ifndef BUZZER_PORT_INCLUDED
#define BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "aj_bit_reg.h"
#include "buzzer_hw.h"

static inline void Buzzer_Pin_ConfigAsOutput(void){
    AJ_BitReg_SetBits_Mask(&BUZZER_DDR, BUZZER_MASK);
}

static inline void Buzzer_Pin_Set(void){
    AJ_BitReg_SetBits_Mask(&BUZZER_PORT, BUZZER_MASK);
}

static inline void Buzzer_Pin_Clear(void){
    AJ_BitReg_ClearBits_Mask(&BUZZER_PORT, BUZZER_MASK);
}

#ifdef __cplusplus
}
#endif

#endif  /* BUZZER_PORT_INCLUDED */
