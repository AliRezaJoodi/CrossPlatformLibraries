// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_BUZZER_TYPE_INCLUDED
#define AJ_BUZZER_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_target.h"

#if (AJ_TARGET_TICK_BITS == 32U)
    typedef uint32_t aj_buzzer_t;
#elif (AJ_TARGET_TICK_BITS == 16U)
    typedef uint16_t aj_buzzer_t;
#elif (AJ_TARGET_TICK_BITS == 8U)
    typedef uint8_t aj_buzzer_t;
#else
    typedef uint32_t aj_buzzer_t;
#endif


#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUZZER_TYPE_INCLUDED */
