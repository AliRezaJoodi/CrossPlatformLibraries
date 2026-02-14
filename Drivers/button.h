// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BUTTON_INCLUDED
#define BUTTON_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "utility_bit.h"

#include "button_config.h"
#include "button_port.h"

void Button_Config(Button_t *btn);
//void Button_SetPullUp(Button_t *btn, uint8_t enable);
uint8_t Button_GetSingleClick(Button_t *btn);
uint8_t Button_GetAutoRepeat_NonBlocking(Button_t *btn);
uint8_t Button_GetLongPress_NonBlocking(Button_t *btn);

#ifdef __cplusplus
}
#endif

#endif
