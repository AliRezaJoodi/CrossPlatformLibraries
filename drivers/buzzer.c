// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "buzzer_port.h"
#include "buzzer.h"

#if (BUZZER_ACTIVE == 1U)
    #define Buzzer_TurnOff()    Buzzer_Pin_Clear()
    #define Buzzer_TurnOn()     Buzzer_Pin_Set()
#else
    #define Buzzer_TurnOff()    Buzzer_Pin_Set()
    #define Buzzer_TurnOn()     Buzzer_Pin_Clear()
#endif

static uint32_t buzzer_count = 0;

//********************************************************
void Buzzer_Init(void){
    Buzzer_Pin_ConfigOutput();
    Buzzer_TurnOff();
}

//********************************************************
void Buzzer_Start(uint32_t cycles){
    buzzer_count = cycles;
    Buzzer_TurnOn();
}

//********************************************************
void Buzzer_Refresh(void){
    if (buzzer_count > 0) {
        -- buzzer_count;
    }
    else{
        Buzzer_TurnOff();
    }
}
