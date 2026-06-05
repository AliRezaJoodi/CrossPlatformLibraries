// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_timebase.h"
#include "aj_buzzer_port.h"
#include "aj_buzzer.h"

static aj_timebase_t buzzer_tick_last = 0U;
static aj_timebase_t buzzer_duration = 0U;
static uint8_t buzzer_status = 0U;

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
    buzzer_tick_last = 0U;
    buzzer_duration = 0U;
    buzzer_status = 0U;

    AJ_Buzzer_Pin_ConfigAsOutput();
    AJ_Buzzer_TurnOff();
}

void AJ_Buzzer_Start(aj_timebase_t tick_now, aj_timebase_t duration){
    buzzer_tick_last = tick_now;
    buzzer_duration = duration;
    buzzer_status = 1U;
    AJ_Buzzer_TurnOn();
}

void AJ_Buzzer_Refresh(aj_timebase_t tick_now){
    if (buzzer_status == 0U){
        return;
    }

    if (AJ_TimeBase_HasElapsed(tick_now, buzzer_tick_last, buzzer_duration)){
        buzzer_duration = 0U;
        buzzer_status = 0U;
        AJ_Buzzer_TurnOff();
    }
}