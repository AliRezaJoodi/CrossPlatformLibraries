#ifndef AJ_BUTTON_TYPE_INCLUDED
#define AJ_BUTTON_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_target.h"
#include "aj_button_type_platform.h"

#if (AJ_TARGET_TICK_BITS == 32U)
    typedef uint32_t aj_button_tick_t;
#elif (AJ_TARGET_TICK_BITS == 16U)
    typedef uint16_t aj_button_tick_t;
#elif (AJ_TARGET_TICK_BITS == 8U)
    typedef uint8_t aj_button_tick_t;
#else
    typedef uint32_t aj_button_tick_t;
#endif

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

typedef struct{
    const aj_button_pin_t       hw;         /**< Pin mapping and hardware references */
    const aj_button_active_t    pressed;  /**< Active level of the button */
    const aj_button_pull_t      pull;     /**< Pull configuration for the button pin */
    aj_button_tick_t            tick_last;
    uint8_t                     status;      /**< Current stable state */
} aj_button_t;

/**
 * @example
 * Example: initializing a structure for AVR8
 *
 * @code
 *     aj_button_t buttonIncr = {
 *         .hw = {
 *             .ddr   = &AJ_BUTTON_DDR,
 *             .port  = &AJ_BUTTON_PORT,
 *             .pin   = &AJ_BUTTON_PIN,
 *             .mask  = AJ_BUTTON_MASK
 *         },
 *         .pressed = AJ_BUTTON_ACTIVE_LOW,
 *         .pull    = AJ_BUTTON_PULL_NONE,
 *         .tick_last = 0,
 *         .status   = 0
 *     };
 * @endcode
 */


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUTTON_TYPE_INCLUDED */
