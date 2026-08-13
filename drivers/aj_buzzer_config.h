#ifndef AJ_BUZZER_CONFIG_INCLUDED
#define AJ_BUZZER_CONFIG_INCLUDED

#include "hardware.h"   /* Project-level overrides */

#ifndef AJ_BUZZER_CONFIG
#define AJ_BUZZER_CONFIG
    #define AJ_BUZZER_ACTIVE       1U		/* 0U or 1U */
    #define AJ_BUZZER_COUNT1       75U
    #define AJ_BUZZER_COUNT2       200U

    #warning "AJ_BUZZER_CONFIG is not defined; default configuration will be used."
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_BUZZER_ACTIVE != 0U) && (AJ_BUZZER_ACTIVE != 1U))
    #error "AJ_BUZZER_ACTIVE must be 0U or 1U."
#endif

#endif  /* AJ_BUZZER_CONFIG_INCLUDED */

