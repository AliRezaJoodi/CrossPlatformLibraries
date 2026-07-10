/**
 * @brief   Configuration definitions for button handling.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_BUTTON_CONFIG_INCLUDED
#define AJ_BUTTON_CONFIG_INCLUDED

#include "hardware.h"   /* Project-level overrides */

/** @brief Default configuration (can be overridden). */
#ifndef AJ_BUTTON_CONFIG
#define AJ_BUTTON_CONFIG
    #define AJ_BUTTON_TICK_TRIGGER          30U
    #define AJ_BUTTON_TICK_AUTO_REPEAT      200U

    #warning "AJ_BUTTON_CONFIG is not defined; default configuration will be used."
#endif


#endif  /* AJ_BUTTON_CONFIG_INCLUDED */
