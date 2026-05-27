#ifndef BUZZER_PORT_INCLUDED
#define BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "bit_register8.h"
#include "buzzer_hw.h"

static inline void Buzzer_Pin_ConfigAsOutput(void){
    SetBitMask_Reg8(&BUZZER_DDR, BUZZER_MASK);
}

static inline void Buzzer_Pin_Set(void){
    SetBitMask_Reg8(&BUZZER_PORT, BUZZER_MASK);
}

static inline void Buzzer_Pin_Clear(void){
    ClearBitMask_Reg8(&BUZZER_PORT, BUZZER_MASK);
}

#ifdef __cplusplus
}
#endif

#endif  /* BUZZER_PORT_INCLUDED */
