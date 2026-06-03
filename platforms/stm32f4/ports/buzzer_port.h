#ifndef BUZZER_PORT_INCLUDED
#define BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_gpio.h"
#include "buzzer_hw.h"

static inline void Buzzer_Pin_ConfigAsOutput(void){
	AJ_GPIO_ConfigDirection(BUZZER_GPIO, BUZZER_PIN, AJ_GPIO_MODE_OUTPUT);
	AJ_GPIO_ConfigOutputType(BUZZER_GPIO, BUZZER_PIN, AJ_GPIO_OUTPUT_PUSHPULL);
	AJ_GPIO_ConfigOutputSpeed(BUZZER_GPIO, BUZZER_PIN, AJ_GPIO_SPEED_2MHZ);
}

static inline void Buzzer_Pin_Set(void){
	AJ_GPIO_SetPins_Mask(BUZZER_GPIO, BUZZER_MASK);
}

static inline void Buzzer_Pin_Clear(void){
	AJ_GPIO_ClearPins_Mask(BUZZER_GPIO, BUZZER_MASK);
}

#ifdef __cplusplus
}
#endif

#endif  /* BUZZER_PORT_INCLUDED */
