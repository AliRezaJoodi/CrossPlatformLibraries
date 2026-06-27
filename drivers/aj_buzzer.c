// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_buzzer_port.h"
#include "aj_buzzer_type.h"
#include "aj_buzzer.h"

static aj_buzzer_t tick_last = 0U;
static aj_buzzer_t tick_duration = 0U;
static uint8_t buzzer_active = 0U;

void AJ_Buzzer_TurnOff(void){
    #if (AJ_BUZZER_ACTIVE == 1U)
        AJ_Buzzer_Pin_Clear();
    #else
        AJ_Buzzer_Pin_Set();
    #endif
}

void AJ_Buzzer_TurnOn(void){
    #if (AJ_BUZZER_ACTIVE == 1U)
        AJ_Buzzer_Pin_Set();
    #else
        AJ_Buzzer_Pin_Clear();
    #endif
}

void AJ_Buzzer_Init(void){
    tick_last = 0U;
    tick_duration = 0U;
    buzzer_active = 0U;

    AJ_Buzzer_Pin_ConfigAsOutput();
    AJ_Buzzer_TurnOff();
}

void AJ_Buzzer_Start(aj_buzzer_t tick_now, aj_buzzer_t duration){
    tick_last = tick_now;
    tick_duration = duration;
    buzzer_active = 1U;
    AJ_Buzzer_TurnOn();
}

void AJ_Buzzer_Refresh(aj_buzzer_t tick_now){
    if (buzzer_active == 0U){
        return;
    }

    if ((aj_buzzer_t)(tick_now - tick_last) >= tick_duration){
        tick_last = 0U;
        tick_duration = 0U;
        buzzer_active = 0U;
        AJ_Buzzer_TurnOff();
    }
}