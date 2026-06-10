/**
 * @file    average_config.h
 * @brief   Configuration header for the lightweight averaging library.
 *
 * This file defines user-overridable macros to configure the behavior of
 * the averaging functions in average.h/average.c.
 *
 * Key points:
 * - AJ_AVERAGE_COUNT defines the number of samples used for block or moving averages.
 * - Valid range: 1 .. 255 (uint8_t limit). Values outside this range will generate a compile-time error.
 * - If AJ_AVERAGE_COUNT is a power of two (e.g., 2, 4, 8, 16, 32...), division operations
 *   in the library are optimized to simple bit shifts, reducing CPU cycles.
 * - Users can override AJ_AVERAGE_COUNT before including this header.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_AVERAGE_CONFIG_INCLUDED
#define AJ_AVERAGE_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"   /**< Include user-overridable macros. */

#ifndef AJ_AVERAGE_CONFIG
#define AJ_AVERAGE_CONFIG
    #define AJ_AVERAGE_COUNT     16     // 0 < valid value < 256

    #warning "AJ_AVERAGE_CONFIG is not defined; default configuration will be used."
#endif

#if (AJ_AVERAGE_COUNT < 1U)
    #error "AJ_AVERAGE_COUNT must be > 0"
#elif (AJ_AVERAGE_COUNT > 255U)
    #error "AJ_AVERAGE_COUNT must be <= 255 (uint8_t limit)"
#endif

#ifdef __cplusplus
}
#endif

#endif
