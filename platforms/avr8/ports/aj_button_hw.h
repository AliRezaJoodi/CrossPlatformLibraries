/**
 * @brief   Configuration definitions for button handling.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUTTON_HW_INCLUDED
#define AJ_BUTTON_HW_INCLUDED

#include "hardware.h"   /* Project-level overrides */

/** @brief Default configuration (can be overridden). */
#ifndef AJ_BUTTON_HARDWARE
#define AJ_BUTTON_HARDWARE
    #define AJ_BUTTON_TICK_TRIGGER         30U
    #define AJ_BUTTON_TICK_AUTO_REPEAT     200U

    #warning "AJ_BUTTON_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef AJ_BUTTON_HARDWARE_EXTRA
#define AJ_BUTTON_HARDWARE_EXTRA
    #define AJ_BUTTON_DDR                  DDRB
    #define AJ_BUTTON_PIN                  PINB
    #define AJ_BUTTON_PORT                 PORTB
    #define AJ_BUTTON_POS                  0U
    #define AJ_BUTTON_MASK                 (1U << AJ_BUTTON_POS)
#endif

#endif  /* AJ_BUTTON_HW_INCLUDED */
