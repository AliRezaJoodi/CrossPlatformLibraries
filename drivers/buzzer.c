// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"
#include "buzzer_port.h"
#include "drivers/buzzer.h"

static uint16_t buzzer_count = 0;

//********************************************************
void Buzzer_Init(void){
    Buzzer_Pin_ConfigOutput();
    Buzzer_Pin_Write(!BUZZER_ACTIVE);
}

//********************************************************
void Buzzer_Active(uint16_t value){
    buzzer_count = value;
    Buzzer_Pin_Write(BUZZER_ACTIVE);
}

//********************************************************
void Buzzer_Refresh(void){
    if (buzzer_count > 0) {
        --buzzer_count;
    }
    else{
        Buzzer_Pin_Write(!BUZZER_ACTIVE);
    }
}

//*******************************************************
void Buzzer_MakeBeep_UpDown(void){
    Buzzer_Pin_Write(BUZZER_ACTIVE);
    BUZZER_DELAY_MS(80);
    Buzzer_Pin_Write(!BUZZER_ACTIVE);
}

//*******************************************************
void Buzzer_MakeBeep_Set(void){
    Buzzer_Pin_Write(BUZZER_ACTIVE);
    BUZZER_DELAY_MS(200);
    Buzzer_Pin_Write(!BUZZER_ACTIVE);
}

//*******************************************************
void Buzzer_MakeBeep_Error(void){
    Buzzer_Pin_Write(BUZZER_ACTIVE);
    BUZZER_DELAY_MS(500);
    Buzzer_Pin_Write(!BUZZER_ACTIVE);
}

