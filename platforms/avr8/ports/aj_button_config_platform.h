/**
 * @brief   Configuration definitions for button handling.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUTTON_CONFIG_PLATFORM_INCLUDED
#define AJ_BUTTON_CONFIG_PLATFORM_INCLUDED

#include "hardware.h"   /* Project-level overrides */

#ifndef AJ_BUTTON_CONFIG_PLATFORM_EXTRA
#define AJ_BUTTON_CONFIG_PLATFORM_EXTRA
    #define AJ_BUTTON_DDR                   DDRB
    #define AJ_BUTTON_PIN                   PINB
    #define AJ_BUTTON_PORT                  PORTB
    #define AJ_BUTTON_POS                   0U
    #define AJ_BUTTON_MASK                  (1U << AJ_BUTTON_POS)
#endif

#endif  /* AJ_BUTTON_CONFIG_PLATFORM_INCLUDED */
