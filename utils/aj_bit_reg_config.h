// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_BIT_REG_CONFIG_INCLUDED
#define AJ_BIT_REG_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"

/*
 * Choose ONLY ONE configuration below:
 * - AJ_BIT_REG_8BIT    (8-bit registers)
 * - AJ_BIT_REG_16BIT    (8-bit registers)
 * - AJ_BIT_REG_32BIT   (32-bit registers)
 */
#ifndef AJ_BIT_REG_CONFIG
#define AJ_BIT_REG_CONFIG
    #define AJ_BIT_REG_32BIT

    #warning "AJ_BIT_REG_CONFIG is not defined; default configuration will be used."
#endif

#if !defined(AJ_BIT_REG_8BIT) && \
    !defined(AJ_BIT_REG_16BIT) && \
    !defined(AJ_BIT_REG_32BIT)

    #error "A valid AJ_BIT_REG_CONFIG option must be selected."
#endif

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BIT_REG_CONFIG_INCLUDED */
