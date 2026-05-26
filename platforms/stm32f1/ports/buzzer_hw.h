#ifndef BUZZER_HW_INCLUDED
#define BUZZER_HW_INCLUDED

#include "hardware.h"   /* Project-level overrides */

#ifndef BUZZER_HARDWARE
#define BUZZER_HARDWARE
    #define BUZZER_ACTIVE       1U
    #define BUZZER_COUNT1       75U
    #define BUZZER_COUNT2       200U

    #define BUZZER_GPIO         GPIOC
    #define BUZZER_BIT          13U
    #define BUZZER_MASK         (1U << BUZZER_BIT)

    #warning "BUZZER_HARDWARE is not defined; default configuration will be used."
#endif

#endif  /* BUZZER_HW_INCLUDED */

