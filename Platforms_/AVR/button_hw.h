/**
 * @brief   Configuration definitions for button handling.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef BUTTON_HW_INCLUDED
#define BUTTON_HW_INCLUDED

#ifndef BUTTON_HARDWARE_EXTRA
#define BUTTON_HARDWARE_EXTRA
    #define BUTTON_DDR          DDRB
    #define BUTTON_PIN          PINB
    #define BUTTON_PORT         PORTB
    #define BUTTON_BIT          0
#endif

#endif
