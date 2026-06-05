// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_TIMEBASE_CONFIG_INCLUDED
#define AJ_TIMEBASE_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"

/*
 * Choose ONLY ONE configuration below:
 * - AJ_TIMEBASE_REG8_U8    (8-bit registers, 8-bit counter)
 * - AJ_TIMEBASE_REG8_U16   (8-bit registers, 16-bit counter)
 * - AJ_TIMEBASE_REG8_U32   (8-bit registers, 32-bit counter)
 * - AJ_TIMEBASE_REG32_U32  (32-bit registers, 32-bit counter)
 */
#ifndef AJ_TIMEBASE_CONFIG
#define AJ_TIMEBASE_CONFIG
    #define AJ_TIMEBASE_REG32_U32

	#warning "AJ_TIMEBASE_CONFIG is not defined; default configuration will be used."
#endif

#if !defined(AJ_TIMEBASE_REG32_U32) && \
    !defined(AJ_TIMEBASE_REG8_U32)  && \
    !defined(AJ_TIMEBASE_REG8_U16)  && \
    !defined(AJ_TIMEBASE_REG8_U8)

    #error "None of the TIMEBASE configurations are defined!"
#endif


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TIMEBASE_CONFIG_INCLUDED */
