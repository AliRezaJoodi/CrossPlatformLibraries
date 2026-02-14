// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef BUTTON_CONFIG_INCLUDED
#define BUTTON_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @note Default hardware macros can be overridden by the user.
 */ 
#include "hardware.h"

typedef enum {
    BUTTON_ACTIVE_LOW   = 0U,
    BUTTON_ACTIVE_HIGH  = 1U
} ButtonActiveLevel_t;

typedef enum {
    BUTTON_MODE_FLOATING   = 0U << 1,
    BUTTON_MODE_PULLUP     = 1U << 1,
    BUTTON_MODE_PULLDOWN   = 2U << 1
} ButtonInputMode_t;

#define Button_GetActiveStatus(btn)     ((btn)->config & 0x01)
#define Button_GetPullStatus(btn)       (((btn)->config >> 1) & 0x03)

#ifndef BUTTON_CONFIG
#define BUTTON_CONFIG
    #define BUTTON_SINGLE_CLICK_LAG     30U          // Single Click Lag, Value: 0~65535, Unit: ms  
    #define BUTTON_AUTO_REPEAT_LAG      500U         // Auto Repeat Lag, Value: 0~65535
    #define BUTTON_LONG_PRESS_LAG       10000U       // Long Press Lag, Value: 0~65535
     
    #warning "BUTTON_HARDWARE is not defined; default configuration will be used."
#endif

#ifdef __cplusplus
}
#endif

#endif
