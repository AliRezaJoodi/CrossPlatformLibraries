// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"   /* Project-level overrides */
#include "timebase.h"
#include "buzzer_port.h"
#include "buzzer.h"

#if (BUZZER_ACTIVE == 1U)
    #define Buzzer_TurnOff()    Buzzer_Pin_Clear()
    #define Buzzer_TurnOn()     Buzzer_Pin_Set()
#else
    #define Buzzer_TurnOff()    Buzzer_Pin_Set()
    #define Buzzer_TurnOn()     Buzzer_Pin_Clear()
#endif

static timebase_t buzzer_tick_last = 0U;
static timebase_t buzzer_duration = 0U;
static uint8_t buzzer_status = 0U;

void Buzzer_Init(void){
    buzzer_tick_last = 0U;
    buzzer_duration = 0U;
    buzzer_status = 0U;

    Buzzer_Pin_ConfigOutput();
    Buzzer_TurnOff();
}

void Buzzer_Start(uint32_t duration){
    buzzer_tick_last = TimeBase_GetTicks();
    buzzer_duration = duration;
    buzzer_status = 1U;
    Buzzer_TurnOn();
}

void Buzzer_Refresh(void){
    if (buzzer_status == 0U){
        return;
    }

    if (TimeBase_CheckElapsed(buzzer_tick_last, buzzer_duration) == 1){
        buzzer_duration = 0U;
        buzzer_status = 0U;
        Buzzer_TurnOff();
    }
}