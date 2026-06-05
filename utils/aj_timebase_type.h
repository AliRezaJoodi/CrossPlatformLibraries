// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_TIMEBASE_TYPE_INCLUDED
#define AJ_TIMEBASE_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_timebase_config.h"

#if defined(AJ_TIMEBASE_REG32_U32) || defined(AJ_TIMEBASE_REG8_U32)
    typedef uint32_t aj_timebase_t;
#elif defined(AJ_TIMEBASE_REG8_U16)
    typedef uint16_t aj_timebase_t;
#elif defined(AJ_TIMEBASE_REG8_U8)
    typedef uint8_t aj_timebase_t;
#else
    typedef uint32_t aj_timebase_t;
#endif

#ifdef __cplusplus
}
#endif

#endif  /* AJ_TIMEBASE_TYPE_INCLUDED */
