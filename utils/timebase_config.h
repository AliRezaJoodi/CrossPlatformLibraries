// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef TIMEBASE_CONFIG_INCLUDED
#define TIMEBASE_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"

/*
 * Choose ONLY ONE configuration below:
 * - TIMEBASE_REG8_U8    (8-bit registers, 8-bit counter)
 * - TIMEBASE_REG8_U16   (8-bit registers, 16-bit counter)
 * - TIMEBASE_REG8_U32   (8-bit registers, 32-bit counter)
 * - TIMEBASE_REG32_U32  (32-bit registers, 32-bit counter)
 */
#ifndef TIMEBASE_CONFIG
#define TIMEBASE_CONFIG
    #define TIMEBASE_REG32_U32

	#warning "TIMEBASE_CONFIG is not defined; default configuration will be used."
#endif

#if !defined(TIMEBASE_REG32_U32) && \
    !defined(TIMEBASE_REG8_U32)  && \
    !defined(TIMEBASE_REG8_U16)  && \
    !defined(TIMEBASE_REG8_U8)

    #error "None of the TIMEBASE configurations are defined!"
#endif


#ifdef __cplusplus
}
#endif

#endif  /* TIMEBASE_CONFIG_INCLUDED */
