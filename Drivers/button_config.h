/**
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

/** @brief Default configuration (can be overridden). */
#ifndef BUTTON_CONFIG
#define BUTTON_CONFIG
    #define BUTTON_SINGLE_CLICK_LAG     30U         /**< Single Click Lag, Value: 0~65535, Unit: ms */
    #define BUTTON_AUTO_REPEAT_LAG      500U        /**< Auto Repeat Lag, Value: 0~65535 */
    #define BUTTON_LONG_PRESS_LAG       10000U      /**< Long Press Lag, Value: 0~65535 */

    #warning "BUTTON_CONFIG is not defined; default configuration will be used."
#endif

#endif
