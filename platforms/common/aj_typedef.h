#ifndef AJ_TYPEDEF_INCLUDED
#define AJ_TYPEDEF_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "aj_target.h"

#if AJ_TARGET_MCU_BITS == 32U
    typedef uint32_t aj_uint_t;
    typedef volatile uint32_t aj_volatile_uint_t;
    typedef const volatile uint32_t aj_const_volatile_uint_t;
#elif AJ_TARGET_MCU_BITS == 16U
    typedef uint16_t aj_uint_t;
    typedef volatile uint16_t aj_volatile_uint_t;
    typedef const volatile uint16_t aj_const_volatile_uint_t;
#elif AJ_TARGET_MCU_BITS == 8U
    typedef uint8_t aj_uint_t;
    typedef volatile uint8_t aj_volatile_uint_t;
    #if defined(__CODEVISIONAVR__)
        typedef volatile uint8_t aj_const_volatile_uint_t;
    #else
        typedef const volatile uint8_t aj_const_volatile_uint_t;
    #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  /* AJ_TYPEDEF_INCLUDED */