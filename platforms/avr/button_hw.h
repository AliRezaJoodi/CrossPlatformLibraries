/**
 * @brief   Configuration definitions for button handling.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef BUTTON_HW_INCLUDED
#define BUTTON_HW_INCLUDED

/** @brief Default configuration (can be overridden). */
#ifndef BUTTON_HARDWARE
#define BUTTON_HARDWARE
    #define BUTTON_SINGLE_CLICK_LAG     30U         /**< Single Click Lag, Value: 0~65535, Unit: ms */
    #define BUTTON_AUTO_REPEAT_LAG      500U        /**< Auto Repeat Lag, Value: 0~65535 */
    #define BUTTON_LONG_PRESS_LAG       10000U      /**< Long Press Lag, Value: 0~65535 */

    #warning "BUTTON_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef BUTTON_HARDWARE_EXTRA
#define BUTTON_HARDWARE_EXTRA
    #define BUTTON_DDR          DDRB
    #define BUTTON_PIN          PINB
    #define BUTTON_PORT         PORTB
    #define BUTTON_BIT          0U
#endif

#endif
