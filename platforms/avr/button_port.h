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
#include "utils/bit.h"
#include "button_hw.h"
#include "button_types.h"

#define BUTTON_DELAY_US(VALUE)      DELAY_US(VALUE)

/**
 * @brief Configure button GPIO pin.
 *
 * This function configures the hardware pin of the given button
 * as input and sets the pull resistor mode according to the
 * button configuration.
 *
 * The Data Direction Register (DDR) bit is cleared to select input mode.
 * Then, based on the configured input mode:
 *  - BUTTON_MODE_FLOATING  : pull resistor disabled
 *  - BUTTON_MODE_PULLUP    : internal pull-up enabled
 *  - BUTTON_MODE_PULLDOWN  : handled as floating on MCUs without pull-down support
 *
 * @param btn Pointer to Button_t object.
 */
static inline void Button_ConfigPin(Button_t *btn){
    CLEAR_BIT(*btn->btn.ddr, btn->btn.index);

    switch(btn->config.pull) {
        case BUTTON_MODE_FLOATING:
            CLEAR_BIT(*btn->btn.port, btn->btn.index);
            break;
        case BUTTON_MODE_PULLUP:
            SET_BIT(*btn->btn.port, btn->btn.index);
            break;
        default:
            CLEAR_BIT(*btn->btn.port, btn->btn.index);
    }
}

/**
 * @brief Read current logic level of the button pin.
 *
 * @param btn Pointer to Button_t object.
 * @return 0 if logic low, 1 if logic high.
 */
static inline uint8_t Button_GetPin(Button_t *btn){
    return GET_BIT(*btn->btn.pin, btn->btn.index);
}

#ifdef __cplusplus
}
#endif

#endif
