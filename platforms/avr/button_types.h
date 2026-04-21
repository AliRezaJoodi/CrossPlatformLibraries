#ifndef BUTTON_TYPES_INCLUDED
#define BUTTON_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** @brief Defines whether a pressed button reads as logic low or high. */
typedef enum{
    BUTTON_ACTIVE_LOW  = 0U,
    BUTTON_ACTIVE_HIGH = 1U

} Button_ActiveLevel_t;

/** @brief Configures the pull resistor mode for a button pin. */
typedef enum{
    BUTTON_MODE_FLOATING = (0U << 1),   /**< No pull resistor */
    BUTTON_MODE_PULLUP   = (1U << 1),   /**< No pull resistor */
    BUTTON_MODE_PULLDOWN = (2U << 1)    /**< Internal pull-down enabled */

} Button_PullMode_t;

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
    const Button_ActiveLevel_t  pressed;  /**< Active level of the button */
    const Button_PullMode_t     pull;     /**< Pull configuration for the button pin */
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
 * Example: initializing a structure
 *
 * @code
 *    Button_t buttonIncr = {
 *        .btn = {
 *            .ddr   = &BUTTON_DDR,
 *            .port  = &BUTTON_PORT,
 *            .pin   = &BUTTON_PIN,
 *            .index = BUTTON_BIT
 *        },
 *        .config = {
 *            .pressed = BUTTON_ACTIVE_LOW,
 *            .pull    = BUTTON_MODE_FLOATING
 *        },
 *        .state   = 0,
 *        .counter = 0
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
