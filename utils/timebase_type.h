// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef TIMEBASE_TYPE_INCLUDED
#define TIMEBASE_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "timebase_config.h"

#if defined(TIMEBASE_REG32_U32) || defined(TIMEBASE_REG8_U32)
    typedef uint32_t timebase_t;
#elif defined(TIMEBASE_REG8_U16)
    typedef uint16_t timebase_t;
#elif defined(TIMEBASE_REG8_U8)
    typedef uint8_t timebase_t;
#else
    typedef uint32_t timebase_t;
#endif

#ifdef __cplusplus
}
#endif

#endif  /* TIMEBASE_TYPE_INCLUDED */
