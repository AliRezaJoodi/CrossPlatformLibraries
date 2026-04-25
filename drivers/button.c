// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "hardware.h"   /* Project-level overrides */
#include "button_types.h"
#include "button_port.h"
#include "drivers/button.h"

//*************************************************
void Button_Init(Button_t *btn){
    Button_Pin_SetInput(btn);
    Button_Pin_SetPull(btn, btn->config.pull);

    btn->state = 0;
    btn->counter = 0;
}

//*************************************************
uint8_t Button_GetSingleClick(Button_t *btn){
    if (Button_Pin_Read(btn) == btn->config.pressed){
        if (btn->state == 0){
            BUTTON_DELAY_US(BUTTON_SINGLE_CLICK_LAG);
            if (Button_Pin_Read(btn) == btn->config.pressed){
                btn->state = 1;
                return 1;
            }
        }
    }
    else {
        if(btn->state == 1){
            BUTTON_DELAY_US(BUTTON_SINGLE_CLICK_LAG);
            if (Button_Pin_Read(btn) != btn->config.pressed){
                btn->state = 0;
            }
        }
    }

    return 0;
}

//*************************************************
uint8_t Button_GetAutoRepeat_NonBlocking(Button_t *btn){
    if (Button_Pin_Read(btn) == btn->config.pressed){
        btn->counter++;
        if (btn->counter >= BUTTON_AUTO_REPEAT_LAG){
            btn->counter = 0;
            return 1;
        }
    }
    else {
        btn->counter = 0;
    }

    return 0;
}

//*************************************************
uint8_t Button_GetLongPress_NonBlocking(Button_t *btn){
    if (Button_Pin_Read(btn) == btn->config.pressed){
        if (btn->counter < BUTTON_LONG_PRESS_LAG){
            btn->counter++;
        }

        if ((btn->counter >= BUTTON_LONG_PRESS_LAG) && (btn->state == 0)){
            btn->state = 1;
            return 1;
        }
    }
    else {
        btn->counter = 0;
        btn->state = 0;
    }

    return 0;
}