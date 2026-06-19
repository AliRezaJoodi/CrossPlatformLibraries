#ifndef AJ_BUZZER_HW_INCLUDED
#define AJ_BUZZER_HW_INCLUDED

#include "hardware.h"   /* Project-level overrides */

#ifndef AJ_BUZZER_HARDWARE
#define AJ_BUZZER_HARDWARE
    #define AJ_BUZZER_ACTIVE       1U
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       200U

    #define AJ_BUZZER_GPIO         GPIOC
    #define AJ_BUZZER_POS          13U
    #define AJ_BUZZER_MASK         (1U << AJ_BUZZER_POS)

    #warning "AJ_BUZZER_HARDWARE is not defined; default configuration will be used."
#endif

#endif  /* AJ_BUZZER_HW_INCLUDED */

