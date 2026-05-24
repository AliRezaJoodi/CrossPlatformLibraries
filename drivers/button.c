// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"   /* Project-level overrides */
#include "timebase.h"
#include "button_types.h"
#include "button_port.h"
#include "button.h"

//*************************************************
void Button_Init(Button_t *btn){
    Button_Pin_ConfigInput(btn);

    switch(btn->config.pull) {
        case BUTTON_PULL_NONE:
            Button_Pin_ConfigPullNone(btn);
            break;
        case BUTTON_PULL_UP:
            Button_Pin_ConfigPullUp(btn);
            break;
        case BUTTON_PULL_DOWN:
            Button_Pin_ConfigPullDown(btn);
            break;
        default:
            Button_Pin_ConfigPullNone(btn);
    }

    btn->state = 0;
    btn->last_tick = 0;
}

//*************************************************
uint8_t Button_GetTrigger(Button_t *btn) {
    uint32_t current_tick;

    if (Button_Pin_Read(btn) == btn->config.pressed) {
        if (btn->state == 0) {
            btn->state = 1;
            btn->last_tick = TimeBase_GetTicks();
        }
        else if (btn->state == 1) {
            current_tick = TimeBase_GetTicks();
            if ((uint32_t)(current_tick - btn->last_tick) >= BUTTON_TIME_TRIGGER) {
                btn->state = 2;
                return 1;
            }
        }
    }
    else {
        btn->state = 0;
    }

    return 0;
}

//*************************************************
uint8_t Button_GetAutoRepeat(Button_t *btn) {
    uint32_t current_tick;

    if (Button_Pin_Read(btn) == btn->config.pressed) {
        if (btn->state == 0) {
            btn->state = 1;
            btn->last_tick = TimeBase_GetTicks();
        }
        else if (btn->state == 1) {
            current_tick = TimeBase_GetTicks();
            if ((uint32_t)(current_tick - btn->last_tick) >= BUTTON_TIME_TRIGGER) {
                btn->last_tick = current_tick;
                return 1;
            }
        }
    }
    else {
        btn->state = 0;
    }

    return 0;
}