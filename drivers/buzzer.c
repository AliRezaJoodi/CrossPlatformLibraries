// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "timebase.h"
#include "buzzer_port.h"
#include "buzzer.h"

static timebase_t buzzer_tick_last = 0U;
static timebase_t buzzer_duration = 0U;
static uint8_t buzzer_status = 0U;

void Buzzer_TurnOff(void){
    #if (BUZZER_ACTIVE == 1U)
        Buzzer_Pin_Clear();
    #else
        Buzzer_Pin_Set();
    #endif
}

void Buzzer_TurnOn(void){
    #if (BUZZER_ACTIVE == 1U)
        Buzzer_Pin_Set();
    #else
        Buzzer_Pin_Clear();
    #endif
}

void Buzzer_Init(void){
    buzzer_tick_last = 0U;
    buzzer_duration = 0U;
    buzzer_status = 0U;

    Buzzer_Pin_ConfigAsOutput();
    Buzzer_TurnOff();
}

void Buzzer_Start(timebase_t tick_now, timebase_t duration){
    buzzer_tick_last = tick_now;
    buzzer_duration = duration;
    buzzer_status = 1U;
    Buzzer_TurnOn();
}

void Buzzer_Refresh(timebase_t tick_now){
    if (buzzer_status == 0U){
        return;
    }

    if (TimeBase_HasElapsed(tick_now, buzzer_tick_last, buzzer_duration)){
        buzzer_duration = 0U;
        buzzer_status = 0U;
        Buzzer_TurnOff();
    }
}