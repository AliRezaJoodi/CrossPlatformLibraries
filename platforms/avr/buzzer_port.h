#ifndef BUZZER_PORT_INCLUDED
#define BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "buzzer_hw.h"

#define BUZZER_DELAY_MS(VALUE)          DELAY_MS(VALUE)

static inline void Buzzer_Pin_SetOutput(void){
    SetBit_Reg8(&BUZZER_DDR, BUZZER_BIT);
}

static inline void Buzzer_Pin_Write(uint8_t status){
    WriteBit_Reg8(&BUZZER_PORT, BUZZER_BIT, status);
}

#ifdef __cplusplus
}
#endif

#endif
