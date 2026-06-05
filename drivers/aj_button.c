// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_timebase.h"
#include "aj_button_type.h"
#include "aj_button_port.h"
#include "aj_button.h"

//*************************************************
void AJ_Button_Init(aj_Button_t *btn){
    AJ_Button_Pin_ConfigAsInput(btn);

    switch(btn->config.pull) {
        case AJ_BUTTON_PULL_NONE:
            AJ_Button_Pin_ConfigAsPullNone(btn);
            break;
        case AJ_BUTTON_PULL_UP:
            AJ_Button_Pin_ConfigAsPullUp(btn);
            break;
        case AJ_BUTTON_PULL_DOWN:
            AJ_Button_Pin_ConfigAsPullDown(btn);
            break;
        default:
            AJ_Button_Pin_ConfigAsPullNone(btn);
    }

    btn->state = 0;
    btn->tick_last = 0;
}

//*************************************************
uint8_t AJ_Button_GetTrigger(aj_Button_t *btn, aj_timebase_t now) {
    if (AJ_Button_Pin_Read(btn) == btn->config.pressed) {
        if (btn->state == 0) {
            btn->state = 1;
            btn->tick_last = now;
        }
        else if (btn->state == 1) {
            if (AJ_TimeBase_HasElapsed(now, btn->tick_last, AJ_BUTTON_TIME_TRIGGER)) {
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
uint8_t AJ_Button_GetAutoRepeat(aj_Button_t *btn, aj_timebase_t now) {
    if (AJ_Button_Pin_Read(btn) == btn->config.pressed) {
        if (btn->state == 0) {
            btn->state = 1;
            btn->tick_last = now;
        }
        else if (btn->state == 1) {
            if (AJ_TimeBase_HasElapsed(now, btn->tick_last, AJ_BUTTON_TIME_AUTO_REPEAT) == 1) {
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