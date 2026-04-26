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
    BUTTON_PULL_NONE = 0U,   /**< No pull resistor */
    BUTTON_PULL_UP   = 1U,   /**< No pull resistor */
    BUTTON_PULL_DOWN = 2U    /**< Internal pull-down enabled */
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
 * @brief Static configuration of a button.
 *
 * This structure defines two compile-time configuration parameters:
 *
 *   pressed : Selects the active logic level of the button using
 *             @ref Button_ActiveLevel_t
 *             - BUTTON_ACTIVE_LOW  : Button is pressed when pin reads LOW
 *             - BUTTON_ACTIVE_HIGH : Button is pressed when pin reads HIGH
 *
 *   pull    : Selects the internal pull resistor configuration using
 *             @ref Button_PullMode_t
 *             - BUTTON_PULL_NONE : No internal pull resistor
 *             - BUTTON_PULL_UP   : Internal pull-up enabled
 *             - BUTTON_PULL_DOWN : Internal pull-down enabled
 *
 * All values are constant after initialization.
 */
typedef struct {
    const Button_ActiveLevel_t  pressed;  /**< Active level of the button */
    const Button_PullMode_t     pull;     /**< Pull configuration for the button pin */
} Button_Config_t;

/**
 * @brief Button object.
 *
 * This structure holds all information required to handle a button.
 *
 * Members:
 *   hw      : Hardware mapping (registers and pin index). Set once at init.
 *   config  : Static configuration (active level and pull resistor).
 *   state   : Current stable button state after debouncing.
 *   counter : Internal debounce timing counter.
 */
typedef struct{
    const Button_Pin_t      hw;      /**< Pin mapping and hardware references */
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
 *        .hw = {
 *            .ddr   = &BUTTON_DDR,
 *            .port  = &BUTTON_PORT,
 *            .pin   = &BUTTON_PIN,
 *            .index = BUTTON_BIT
 *        },
 *        .config = {
 *            .pressed = BUTTON_ACTIVE_LOW,
 *            .pull    = BUTTON_PULL_NONE
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
