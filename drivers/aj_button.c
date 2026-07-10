// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_button_config.h"
#include "aj_button_type.h"
#include "aj_button_port.h"
#include "aj_button.h"

//*************************************************
void AJ_Button_Init(aj_button_t *btn){
    AJ_Button_Pin_ConfigAsInput(btn);

    switch(btn->pull) {
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

    btn->status = 0;
    btn->tick_last = 0;
}

//*************************************************
uint8_t AJ_Button_GetTrigger(aj_button_t *btn, aj_button_tick_t tick_now) {
    if (AJ_Button_Pin_Read(btn) == btn->pressed) {
        if (btn->status == 0) {
            btn->status = 1;
            btn->tick_last = tick_now;
        }
        else if (btn->status == 1) {
            if ((aj_button_tick_t)(tick_now - btn->tick_last) >= AJ_BUTTON_TICK_TRIGGER) {
                btn->status = 2;
                return 1;
            }
        }
    }
    else {
        btn->status = 0;
    }

    return 0;
}

//*************************************************
uint8_t AJ_Button_GetAutoRepeat(aj_button_t *btn, aj_button_tick_t tick_now) {
    if (AJ_Button_Pin_Read(btn) == btn->pressed) {
        if (btn->status == 0) {
            btn->status = 1;
            btn->tick_last = tick_now;
        }
        else if (btn->status == 1) {
            if ((aj_button_tick_t)(tick_now - btn->tick_last) >= AJ_BUTTON_TICK_AUTO_REPEAT) {
                btn->tick_last = tick_now;
                return 1;
            }
        }
    }
    else {
        btn->status = 0;
    }

    return 0;
}