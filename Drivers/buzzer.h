// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef BUZZER_INCLUDED
#define BUZZER_INCLUDED

#include <stdint.h>
#include "buzzer_port.h"

void Buzzer_Init(void);
void Buzzer_Active(uint16_t value);
void Buzzer_Refresh(void);

void Buzzer_MakeBeep_UpOrDownSound(void);
void Buzzer_MakeBeep_SetSound(void);
void Buzzer_MakeBeep_ErrorSound(void);

#endif
