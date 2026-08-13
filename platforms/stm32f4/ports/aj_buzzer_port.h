#ifndef AJ_BUZZER_PORT_INCLUDED
#define AJ_BUZZER_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_gpio.h"
#include "aj_buzzer_config_platform.h"

static inline void AJ_Buzzer_ConfigPinAsOutput(void){
	AJ_GPIO_ConfigDirection(AJ_BUZZER_GPIO, AJ_BUZZER_POS, AJ_GPIO_MODE_OUTPUT);
	AJ_GPIO_ConfigOutputType(AJ_BUZZER_GPIO, AJ_BUZZER_POS, AJ_GPIO_OUTPUT_PUSHPULL);
	AJ_GPIO_ConfigOutputSpeed(AJ_BUZZER_GPIO, AJ_BUZZER_POS, AJ_GPIO_SPEED_2MHZ);
}

//static inline void AJ_Buzzer_Pin_Set(void){
//	AJ_GPIO_SetPin_Mask(AJ_BUZZER_GPIO, AJ_BUZZER_MASK);
//}
//
//static inline void AJ_Buzzer_Pin_Clear(void){
//	AJ_GPIO_ClearPin_Mask(AJ_BUZZER_GPIO, AJ_BUZZER_MASK);
//}

static inline void AJ_Buzzer_WritePin(uint8_t state){
	AJ_GPIO_WritePin_Position(AJ_BUZZER_GPIO, AJ_BUZZER_POS, state);
}


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUZZER_PORT_INCLUDED */
