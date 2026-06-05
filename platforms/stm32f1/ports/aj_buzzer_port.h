#ifndef AJ_BUZZER_PORT_INCLUDED
#define AJ_BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_gpio.h"
#include "aj_buzzer_hw.h"

static inline void AJ_Buzzer_Pin_ConfigAsOutput(void){
	AJ_GPIO_ConfigDirection(AJ_BUZZER_GPIO, AJ_BUZZER_PIN, AJ_GPIO_MODE_OUTPUT_2MHz);
	AJ_GPIO_ConfigOutputType(AJ_BUZZER_GPIO, AJ_BUZZER_PIN, AJ_GPIO_OUTPUT_GP_PUSHPULL);
}

static inline void AJ_Buzzer_Pin_Set(void){
	AJ_GPIO_SetPins_Mask(AJ_BUZZER_GPIO, AJ_BUZZER_MASK);
}

static inline void AJ_Buzzer_Pin_Clear(void){
	AJ_GPIO_ClearPins_Mask(AJ_BUZZER_GPIO, AJ_BUZZER_MASK);
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUZZER_PORT_INCLUDED */
