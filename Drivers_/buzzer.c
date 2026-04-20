// GitHub Account:  GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "buzzer.h"

static uint16_t buzzer_count = 0;

//********************************************************
void Buzzer_Init(void){
    Buzzer_InitPin();
}

//********************************************************
void Buzzer_Active(uint16_t value){
    buzzer_count = value;
    Buzzer_WritePin(BUZZER_ACTIVE);
}

//********************************************************
void Buzzer_Refresh(void){
    if (buzzer_count > 0) {
        -- buzzer_count;
    }
    else{
        Buzzer_WritePin(!BUZZER_ACTIVE);
    }
}

//*******************************************************
void Buzzer_MakeBeep_UpDown(void){
    Buzzer_WritePin(BUZZER_ACTIVE);
    BUZZER_DELAY_MS(80);
    Buzzer_WritePin(!BUZZER_ACTIVE);
}

//*******************************************************
void Buzzer_MakeBeep_Set(void){
    Buzzer_WritePin(BUZZER_ACTIVE);
    BUZZER_DELAY_MS(200);
    Buzzer_WritePin(!BUZZER_ACTIVE);
}

//*******************************************************
void Buzzer_MakeBeep_Error(void){
    Buzzer_WritePin(BUZZER_ACTIVE);
    BUZZER_DELAY_MS(500);
    Buzzer_WritePin(!BUZZER_ACTIVE);
}

