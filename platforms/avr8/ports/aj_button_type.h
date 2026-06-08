#ifndef aj_button_tYPE_INCLUDED
#define aj_button_tYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_timebase_type.h"

/** @brief Defines whether a pressed button reads as logic low or high. */
typedef enum{
    AJ_BUTTON_ACTIVE_LOW  = 0U,
    AJ_BUTTON_ACTIVE_HIGH = 1U

} aj_button_active_t;

/** @brief Configures the pull resistor mode for a button pin. */
typedef enum{
    AJ_BUTTON_PULL_NONE = 0U,   /**< No pull resistor */
    AJ_BUTTON_PULL_UP   = 1U,   /**< No pull resistor */
    AJ_BUTTON_PULL_DOWN = 2U    /**< Internal pull-down enabled */
} aj_button_pull_t;

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
    //const uint8_t       index;    /**< Pin index number */
    const uint8_t       mask;
} aj_button_pin_t;

/**
 * @brief Static configuration of a button.
 *
 * This structure defines two compile-time configuration parameters:
 *
 *   pressed : Selects the active logic level of the button using
 *             @ref aj_button_active_t
 *             - AJ_BUTTON_ACTIVE_LOW  : Button is pressed when pin reads LOW
 *             - AJ_BUTTON_ACTIVE_HIGH : Button is pressed when pin reads HIGH
 *
 *   pull    : Selects the internal pull resistor configuration using
 *             @ref aj_button_pull_t
 *             - AJ_BUTTON_PULL_NONE : No internal pull resistor
 *             - AJ_BUTTON_PULL_UP   : Internal pull-up enabled
 *             - AJ_BUTTON_PULL_DOWN : Internal pull-down enabled
 *
 * All values are constant after initialization.
 */
typedef struct {
    const aj_button_active_t  pressed;  /**< Active level of the button */
    const aj_button_pull_t     pull;     /**< Pull configuration for the button pin */
} aj_button_config_t;

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
    const aj_button_pin_t       hw;      /**< Pin mapping and hardware references */
    const aj_button_config_t    config;   /**< Static configuration (active level & pull) */
    aj_timebase_t               tick_last;
    uint8_t                     state;    /**< Current stable state */
} aj_button_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    Button_t buttonIncr = {
 *        .hw = {
 *            .ddr   = &AJ_BUTTON_DDR,
 *            .port  = &AJ_BUTTON_PORT,
 *            .pin   = &AJ_BUTTON_PIN,
 *            .mask  = AJ_BUTTON_MASK
 *        },
 *        .config = {
 *            .pressed = AJ_AJ_BUTTON_ACTIVE_LOW,
 *            .pull    = AJ_BUTTON_PULL_NONE
 *        },
 *        .last_tick   = 0,
 *        .state = 0
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif  /* aj_button_tYPE_INCLUDED */
