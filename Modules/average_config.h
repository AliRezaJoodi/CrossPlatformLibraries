/**
 * @file    average_config.h
 * @brief   Configuration header for the lightweight averaging library.
 *
 * This file defines user-overridable macros to configure the behavior of
 * the averaging functions in average.h/average.c.
 *
 * Key points:
 * - AVERAGE_COUNT defines the number of samples used for block or moving averages.
 * - Valid range: 1 .. 255 (uint8_t limit). Values outside this range will generate a compile-time error.
 * - If AVERAGE_COUNT is a power of two (e.g., 2, 4, 8, 16, 32...), division operations
 *   in the library are optimized to simple bit shifts, reducing CPU cycles.
 * - Users can override AVERAGE_COUNT before including this header.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AVERAGE_CONFIG_INCLUDED
#define AVERAGE_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Include user-overridable macros. */
#include "hardware.h"

#ifndef AVERAGE_CONFIG
#define AVERAGE_CONFIG
    #define AVERAGE_COUNT     16     // 0 < valid value < 256

    #warning "AVERAGE_CONFIG is not defined; default configuration will be used."
#endif

#if (AVERAGE_COUNT == 0)
    #error "AVERAGE_COUNT must be > 0"
#elif (AVERAGE_COUNT > 255)
    #error "AVERAGE_COUNT must be <= 255 (uint8_t limit)"
#endif

#ifdef __cplusplus
}
#endif

#endif
