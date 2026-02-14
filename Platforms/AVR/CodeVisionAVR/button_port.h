// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BUTTON_PORT_INCLUDED
#define BUTTON_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <io.h>
#include <delay.h>

#include "button_config.h"

typedef struct{
    volatile uint8_t    *hw_ddr;
    volatile uint8_t    *hw_pin;
    volatile uint8_t    *hw_port;
    uint8_t             hw_bit;
    uint8_t             config;
    uint8_t             state;
    uint16_t            counter;
} Button_t;


static inline void Button_ConfigPin(Button_t *btn){    
    CLEAR_BIT(*btn->hw_ddr, btn->hw_bit);
    
    switch( Button_GetPullStatus(btn) ) {
        case BUTTON_MODE_FLOATING:
            CLEAR_BIT(*btn->hw_port, btn->hw_bit);
            break;
        case BUTTON_MODE_PULLUP:
            SET_BIT(*btn->hw_port, btn->hw_bit);
            break;
        default:
            CLEAR_BIT(*btn->hw_port, btn->hw_bit);
    }
}

static inline uint8_t Button_GetPin(Button_t *btn){
    return GET_BIT(*btn->hw_pin, btn->hw_bit); 
}

static inline void Button_Delay(){
    delay_ms(BUTTON_SINGLE_CLICK_LAG);
}

#ifdef __cplusplus
}
#endif

#endif
