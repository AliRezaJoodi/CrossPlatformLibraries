// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef TIMEBASE_INCLUDED
#define TIMEBASE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "timebase_config.h"

void TimeBase_CountTicks(void);

#if defined(TIMEBASE_REG32_U32) || defined(TIMEBASE_REG8_U32)
    uint32_t TimeBase_GetTicks(void);
#elif defined(TIMEBASE_REG8_U8)
    uint8_t TimeBase_GetTicks(void);
#else
    #error "None TIMEBASE configurations defined!"
#endif

#ifdef __cplusplus
}
#endif

#endif  /* TIMEBASE_INCLUDED */

