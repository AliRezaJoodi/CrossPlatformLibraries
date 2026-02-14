// GitHub Account: GitHub.com/AliRezaJoodi

#include "button.h"

//*************************************************
void Button_Config(Button_t *btn){
    Button_ConfigPin(btn);

    btn->state = 0;
    btn->counter = 0;
}

////*************************************************
//void Button_SetPullUp(Button_t *btn, uint8_t enable){
//    WRITE_BIT(*btn->hw_port, btn->hw_bit, enable);
//}

//*************************************************
uint8_t Button_GetSingleClick(Button_t *btn){
    if ( Button_GetPin(btn) != Button_GetActiveStatus(btn) ){
        if(btn->state == 1){
            Button_Delay();
            if ( Button_GetPin(btn) != Button_GetActiveStatus(btn) ){
                btn->state = 0;
            } 
        }
    }
    else{
        if(btn->state == 0){
            Button_Delay();
            if ( Button_GetPin(btn) == Button_GetActiveStatus(btn) ){
                btn->state = 1;
                return 1;
            }
        }
    }

    return 0;
}

//*************************************************
uint8_t Button_GetAutoRepeat_NonBlocking(Button_t *btn){
    if (Button_GetPin(btn) == Button_GetActiveStatus(btn)){
        btn->counter++;

        if (btn->counter >= BUTTON_AUTO_REPEAT_LAG){
            btn->counter = 0;
            return 1;
        }
    }
    else{
        btn->counter = 0;
    }

    return 0;
}

//*************************************************
uint8_t Button_GetLongPress_NonBlocking(Button_t *btn){
    if (Button_GetPin(btn) == Button_GetActiveStatus(btn)){
        if (btn->counter < BUTTON_LONG_PRESS_LAG)
            btn->counter++;

        if ((btn->counter >= BUTTON_LONG_PRESS_LAG) && (btn->state == 0)){
            btn->state = 1;
            return 1;
        }
    }
    else{
        btn->counter = 0;
        btn->state = 0;
    }

    return 0;
}