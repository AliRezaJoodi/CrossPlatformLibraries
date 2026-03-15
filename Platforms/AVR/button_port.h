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
#include "button_hw.h"

#define BUTTON_DELAY_US(VALUE)      DELAY_US(VALUE)

/**
 * @brief Hardware configuration for a button.
 *
 * This structure holds the hardware registers and pin index
 * for a button. It is used inside the Button_t structure.
 */
typedef struct {
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
    volatile uint8_t    *pin;      /**< Pin register */
    const uint8_t       index;    /**< Pin index number */
} Button_Pin_t;

/**
 * @brief Configuration for a button.
 *
 * This struct defines the static configuration of a button.
 * It specifies the **active logic level** and the **internal pull resistor setup**.
 * These values are constant and set at initialization.
 */
typedef struct {
    const uint8_t   pressed;  /**< Active level of the button */
    const uint8_t   pull;     /**< Pull configuration for the button pin */
} Button_Config_t;

/**
 * @brief Button object structure.
 *
 * This structure represents a button and contains all necessary
 * information for handling its state and configuration.
 *
 * Members:
 *   btn     : Pin mapping and hardware references for the button.
 *             Contains DDR, PORT, PIN registers and pin index.
 *             This is constant and set at initialization.
 *   config  : Static configuration of the button.
 *             Specifies the active logic level and pull resistor setup.
 *             - pressed : defines when the button is considered pressed
 *                 - BUTTON_ACTIVE_LOW  : pressed when pin is LOW
 *                 - BUTTON_ACTIVE_HIGH : pressed when pin is HIGH
 *             - pull    : internal resistor configuration
 *                 - BUTTON_MODE_FLOATING : no internal resistor
 *                 - BUTTON_MODE_PULLUP   : enable internal pull-up resistor
 *                 - BUTTON_MODE_PULLDOWN : enable internal pull-down resistor
 *
 *   state   : Current stable state of the button (updated by debounce logic).
 *   counter : Internal counter used for timing and debouncing.
 */
typedef struct{
    const Button_Pin_t      btn;      /**< Pin mapping and hardware references */
    const Button_Config_t   config;   /**< Static configuration (active level & pull) */
    uint8_t                 state;    /**< Current stable state */
    uint16_t                counter;  /**< Internal timing counter for debounce */
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
 *    Button_t buttonIncr = {
 *        .btn = {
 *            .ddr   = &BUTTON1_DDR,
 *            .port  = &BUTTON1_PORT,
 *            .pin   = &BUTTON1_PIN,
 *            .index = BUTTON1_BIT
 *        },
 *        .config = {
 *            .pressed = BUTTON_ACTIVE_LOW,
 *            .pull     = BUTTON_MODE_FLOATING
 *        },
 *        .state   = 0,
 *        .counter = 0
 *    };
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
