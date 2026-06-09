/*
 * @brief Linear scale conversion utilities for analog values.
 *
 * @warning
 * These functions use floating-point operations (float).
 * On MCUs without a hardware FPU (e.g., most 8-bit AVR devices),
 * floating-point arithmetic is implemented in software and may:
 *  - Consume significantly more CPU cycles
 *  - Increase flash memory usage
 *  - Increase temporary stack usage
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_CONVERTER_SCALE_INCLUDED
#define AJ_CONVERTER_SCALE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline float AJ_Convert_0to100_0to5V(float value) {
    return value * 0.05f;
}

static inline float AJ_Convert_0to100_1to5V(float value) {
    return (value * 0.04f) + 1.0f;
}

static inline float AJ_Convert_0to100_0to3V3(float value) {
    return value * 0.033f;
}

static inline uint16_t AJ_Convert_0to100_0to1024(float value) {
    uint16_t data = value * 10.24f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint8_t AJ_Convert_0to100_0to256(float value) {
    uint8_t data = value * 2.56f;
    return data;
}

#ifdef __cplusplus
}
#endif

#endif
