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
#include "button_config.h"

/**
 * @brief Hardware configuration for a button.
 *
 * This structure holds the hardware registers and pin index
 * for a button. It is used inside the Button_t structure.
 */
typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register */
    volatile uint8_t *port;     /**< Port register */
    volatile uint8_t *pin;      /**< Pin register */
    uint8_t           index;    /**< Pin index number */
} Button_HW_t;

/**
 * @brief Button object structure.
 *
 * This structure contains the hardware configuration (hw),
 * configuration flags, current stable state, and internal
 * counter for timing and debounce.
 *
 * The 'config' field uses bits to set the active level and input mode:
 *      - bit 0: active level
 *      - bits 1-2: input mode
 * See "button_config.h" for enum definitions.
 *
 * @see Example section below.
 */
typedef struct{
    Button_HW_t     hw;         /**< Hardware configuration */
    uint8_t         config;     /**< Button configuration flags */
    uint8_t         state;      /**< Current stable state */
    uint16_t        counter;    /**< Internal timing counter */
} Button_t;

/**
 * @example
 * Example: defining pin macros
 *
 * @code
 * #define BUTTON1_DDR   DDRB
 * #define BUTTON1_PIN   PINB
 * #define BUTTON1_PORT  PORTB
 * #define BUTTON1_BIT   0
 * @endcode
 *
 * Example: initializing a structure
 *
 * @code
 * Button_t buttonIncr;
 * buttonIncr.hw.ddr   = &BUTTON1_DDR;
 * buttonIncr.hw.port  = &BUTTON1_PORT;
 * buttonIncr.hw.pin   = &BUTTON1_PIN;
 * buttonIncr.hw.index = BUTTON1_BIT;
 * buttonIncr.config   = BUTTON_MODE_FLOATING | BUTTON_ACTIVE_LOW;
 * buttonIncr.state    = 0;
 * buttonIncr.counter  = 0;
 * @endcode
 */

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
    CLEAR_BIT(*btn->hw.ddr, btn->hw.index);

    switch( Button_GetPullStatus(btn) ) {
        case BUTTON_MODE_FLOATING:
            CLEAR_BIT(*btn->hw.port, btn->hw.index);
            break;
        case BUTTON_MODE_PULLUP:
            SET_BIT(*btn->hw.port, btn->hw.index);
            break;
        default:
            CLEAR_BIT(*btn->hw.port, btn->hw.index);
    }
}

/**
 * @brief Read current logic level of the button pin.
 *
 * @param btn Pointer to Button_t object.
 * @return 0 if logic low, 1 if logic high.
 */
static inline uint8_t Button_GetPin(Button_t *btn){
    return GET_BIT(*btn->hw.pin, btn->hw.index);
}

/**
 * @brief Delay for single-click debounce.
 *
 * Uses the configured single-click lag time to create
 * a small delay for button debouncing.
 */
static inline void Button_Delay(){
    DELAY_MS(BUTTON_SINGLE_CLICK_LAG);
}

#ifdef __cplusplus
}
#endif

#endif
