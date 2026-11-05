// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_buzzer_port.h"
#include "aj_buzzer_type.h"
#include "aj_buzzer_config.h"
#include "aj_buzzer.h"

static aj_buzzer_t buzzer_tick = 0U;
static uint8_t buzzer_active = 0U;

void AJ_Buzzer_Init(void){
    buzzer_tick = 0U;
    buzzer_active = 0U;

    AJ_Buzzer_ConfigPinAsOutput();
    AJ_Buzzer_TurnOff();
}

void AJ_Buzzer_Start(aj_buzzer_t duration){
    buzzer_tick = duration;
    buzzer_active = 1U;
    AJ_Buzzer_TurnOn();
}

void AJ_Buzzer_Handler(void){
    if (buzzer_active == 0U){
        return;
    }

    if (buzzer_tick > 0U){
        buzzer_tick--;
    }

    if (buzzer_tick == 0U){
        buzzer_active = 0U;
        AJ_Buzzer_TurnOff();
    }
}