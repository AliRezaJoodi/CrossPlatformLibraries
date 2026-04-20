#ifndef BUZZER_PORT_INCLUDED
#define BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utility_bit.h"
#include "buzzer_hw.h"

#define BUZZER_DELAY_MS(VALUE)          DELAY_MS(VALUE)

/***************************************/
static inline void Buzzer_InitPin(void){
    SET_BIT(BUZZER_DDR, BUZZER_BIT);
    WRITE_BIT(BUZZER_PORT, BUZZER_BIT, !BUZZER_ACTIVE);
}

/***************************************/
static inline void Buzzer_WritePin(uint8_t status){
    WRITE_BIT(BUZZER_PORT, BUZZER_BIT, status);
}

#ifdef __cplusplus
}
#endif

#endif
