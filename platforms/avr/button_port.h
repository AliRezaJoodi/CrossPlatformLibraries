/**
 * @file    button_port.h
 * @brief   GPIO and hardware support for button handling.
 *
 * This header provides structures and inline functions for
 * configuring and reading buttons, including:
 *  - Button hardware configuration (Button_HW_t)
 *  - Button object (Button_t)
 *  - Pin configuration and debounce delay functions
 *
 * Inline functions are provided for fast access in AVR MCUs.
 * The header is portable and can be adapted to other microcontrollers.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef BUTTON_PORT_INCLUDED
#define BUTTON_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "compiler_port.h"
#include "utils/bit_register.h"
#include "button_hw.h"
#include "button_types.h"

#define BUTTON_DELAY_US(VALUE)      DELAY_US(VALUE)

static inline void Button_Pin_SetInput(Button_t *btn){
    ClearBit_Reg8(btn->hw.ddr, btn->hw.index);
}

static inline void Button_Pin_SetPull(Button_t *btn, Button_PullMode_t mode){
    switch(mode) {
        case BUTTON_MODE_PULLUP:
            SetBit_Reg8(btn->hw.port, btn->hw.index);
            break;
        default:
            ClearBit_Reg8(btn->hw.port, btn->hw.index);
    }
}

static inline uint8_t Button_Pin_Read(const Button_t *btn){
    return ReadBit_Reg8(btn->hw.pin, btn->hw.index);
}

#ifdef __cplusplus
}
#endif

#endif
