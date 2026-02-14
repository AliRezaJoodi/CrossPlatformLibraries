// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BUTTON_PORT_INCLUDED
#define BUTTON_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <io.h>
#include <delay.h>

typedef struct{
    volatile uint8_t    *hw_ddr;
    volatile uint8_t    *hw_pin;
    volatile uint8_t    *hw_port;
    uint8_t             hw_bit;
    uint8_t             config;
    uint8_t             state;
    uint16_t            counter;
} Button_t;
/*
Example in main code:
Button_t button_incr = {
    .btn_ddr  = &BUTTON1_DDR,
    .hw_pin  = &BUTTON1_PIN,
    .hw_port = &BUTTON1_PORT,
    .btn_bit  = BUTTON1_BIT,
    .status   = 0,
    .counter  = 0
};
*/

#define Button_GetPullStatus(btn)     (((btn)->config >> 1) & 0x03)

//static inline uint8_t Button_GetPullStatus(Button_t *btn){
//    return ((btn->config >> 1) & 0x03);
//}

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

static inline void Button_Delay_ms(uint8_t value){
}

#ifdef __cplusplus
}
#endif

#endif
