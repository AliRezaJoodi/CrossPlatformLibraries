// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_timebase.h"
#include "button_type.h"
#include "button_port.h"
#include "button.h"

//*************************************************
void Button_Init(Button_t *btn){
    Button_Pin_ConfigAsInput(btn);

    switch(btn->config.pull) {
        case BUTTON_PULL_NONE:
            Button_Pin_ConfigAsPullNone(btn);
            break;
        case BUTTON_PULL_UP:
            Button_Pin_ConfigAsPullUp(btn);
            break;
        case BUTTON_PULL_DOWN:
            Button_Pin_ConfigAsPullDown(btn);
            break;
        default:
            Button_Pin_ConfigAsPullNone(btn);
    }

    btn->state = 0;
    btn->tick_last = 0;
}

//*************************************************
uint8_t Button_GetTrigger(Button_t *btn, aj_timebase_t now) {
    if (Button_Pin_Read(btn) == btn->config.pressed) {
        if (btn->state == 0) {
            btn->state = 1;
            btn->tick_last = now;
        }
        else if (btn->state == 1) {
            if (AJ_TimeBase_HasElapsed(now, btn->tick_last, BUTTON_TIME_TRIGGER)) {
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
uint8_t Button_GetAutoRepeat(Button_t *btn, aj_timebase_t now) {
    if (Button_Pin_Read(btn) == btn->config.pressed) {
        if (btn->state == 0) {
            btn->state = 1;
            btn->tick_last = now;
        }
        else if (btn->state == 1) {
            if (AJ_TimeBase_HasElapsed(now, btn->tick_last, BUTTON_TIME_AUTO_REPEAT) == 1) {
                btn->tick_last = now;
                return 1;
            }
        }
    }
    else {
        btn->state = 0;
    }

    return 0;
}