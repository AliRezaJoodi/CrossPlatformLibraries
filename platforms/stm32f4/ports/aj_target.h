/**
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: Default Configuration
 * -----------------------------------------------------------------------------
 * The default macros are declared in the following headers:
 * - `aj_target.h`
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: User Configuration Override
 * -----------------------------------------------------------------------------
 * This library's default configuration can be customized via the central
 * project hardware configuration file, which MUST be present alongside your
 * project source files. Override the macros inside it:
 * - `hardware.h`
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_TARGET_INCLUDED
#define AJ_TARGET_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include "hardware.h"

#define AJ_TARGET_MCU_BITS              32U
#define AJ_TARGET_TICK_BITS             32U

#ifndef AJ_TARGET_CONFIG
#define AJ_TARGET_CONFIG
    #define AJ_TARGET_CORE_CLOCK_HZ             16000000U    /*!< Core clock (HCLK) in Hz */

    #warning "AJ_TARGET_CONFIG is not defined; default configuration will be used."
#endif


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TARGET_INCLUDED */