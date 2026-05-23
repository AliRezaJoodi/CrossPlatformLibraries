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
    #define BUTTON_TIME_TRIGGER         30U
    #define BUTTON_TIME_AUTO_REPEAT     200U

    #warning "BUTTON_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef BUTTON_HARDWARE_EXTRA
#define BUTTON_HARDWARE_EXTRA
    #define BUTTON_DDR                  DDRB
    #define BUTTON_PIN                  PINB
    #define BUTTON_PORT                 PORTB
    #define BUTTON_BIT                  0U
    #define BUTTON_MASK                 (1U << BUTTON_BIT)
#endif

#endif  /* BUTTON_HW_INCLUDED */
