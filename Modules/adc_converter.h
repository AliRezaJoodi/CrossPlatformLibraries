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

#ifndef CONVERTER_SCALE_INCLUDED
#define CONVERTER_SCALE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline float Convert_0to4095_0to5V(uint16_t counts){
    return (float)counts * 0.0012210012f;
}

static inline float Convert_0to4095_0to5000mV(uint16_t counts){
    return (float)counts * 1.2210012f;
}

static inline float Convert_0to4095_0to3V3(uint16_t counts){
    return (float)counts * 0.0008058608f;
}

static inline float Convert_0to4095_0to3300mV(uint16_t counts){
    return (float)counts * 0.8058608f;
}

static inline float Convert_0to1023_0to5V(uint16_t counts) {
    return (float)counts * 0.0048875855f;
}

static inline float Convert_0to1023_0to2V56(uint16_t counts) {
    return (float)counts * 0.002502444f;
}

static inline float Convert_0to255_0to5V(uint8_t counts) {
    return (float)counts * 0.019607843f;
}

static inline float Convert_0to255_0to2V56(uint8_t counts) {
    return (float)counts * 0.010039194f;
}

#ifdef __cplusplus
}
#endif

#endif
