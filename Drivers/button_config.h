/**
 * @file    button_config.h
 * @brief   Configuration definitions and enums for button handling.
 *
 * This header defines the button input modes, active level flags,
 * and timing constants for single click, auto repeat, and long press.
 * Default hardware macros can be overridden by the user.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef BUTTON_CONFIG_INCLUDED
#define BUTTON_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Defines whether a pressed button reads as logic low or high. */
#define BUTTON_ACTIVE_LOW   0U
#define BUTTON_ACTIVE_HIGH  1U

/** @brief Configures the pull resistor mode for a button pin. */
#define BUTTON_MODE_FLOATING   (0U << 1)    /**< No pull resistor */
#define BUTTON_MODE_PULLUP     (1U << 1)    /**< Internal pull-up enabled */
#define BUTTON_MODE_PULLDOWN   (2U << 1)    /**< Internal pull-down enabled */

/** @brief Default configuration (can be overridden). */
#ifndef BUTTON_CONFIG
#define BUTTON_CONFIG
    #define BUTTON_SINGLE_CLICK_LAG     30U         /**< Single Click Lag, Value: 0~65535, Unit: ms */
    #define BUTTON_AUTO_REPEAT_LAG      500U        /**< Auto Repeat Lag, Value: 0~65535 */
    #define BUTTON_LONG_PRESS_LAG       10000U      /**< Long Press Lag, Value: 0~65535 */

    #warning "BUTTON_CONFIG is not defined; default configuration will be used."
#endif

#ifdef __cplusplus
}
#endif

#endif
