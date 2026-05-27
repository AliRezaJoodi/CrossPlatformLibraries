#ifndef BUZZER_PORT_INCLUDED
#define BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "gpio.h"
#include "buzzer_hw.h"

static inline void Buzzer_Pin_ConfigAsOutput(void){
	GPIO_ConfigDirection(BUZZER_GPIO, BUZZER_PIN, GPIO_MODE_OUTPUT_2MHz);
	GPIO_ConfigOutputType(BUZZER_GPIO, BUZZER_PIN, GPIO_OUTPUT_GP_PUSHPULL);
}

static inline void Buzzer_Pin_Set(void){
	GPIO_SetPinMask(BUZZER_GPIO, BUZZER_MASK);
}

static inline void Buzzer_Pin_Clear(void){
	GPIO_ClearPinMask(BUZZER_GPIO, BUZZER_MASK);
}

#ifdef __cplusplus
}
#endif

#endif  /* BUZZER_PORT_INCLUDED */
