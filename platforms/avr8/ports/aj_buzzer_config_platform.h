#ifndef AJ_BUZZER_CONFIG_PLATFORM_INCLUDED
#define AJ_BUZZER_CONFIG_PLATFORM_INCLUDED

#include "hardware.h"   /* Project-level overrides */

#ifndef AJ_BUZZER_CONFIG_PLATFORM
#define AJ_BUZZER_CONFIG_PLATFORM
    #define AJ_BUZZER_DDR          DDRB
    #define AJ_BUZZER_PORT         PORTB
    #define AJ_BUZZER_POS          1U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)

    #warning "AJ_BUZZER_CONFIG_PLATFORM is not defined; default configuration will be used."
#endif

#endif  /* AJ_BUZZER_CONFIG_PLATFORM */

