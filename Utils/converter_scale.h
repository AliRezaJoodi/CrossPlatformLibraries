/*
 * @brief Linear scale conversion utilities for ADC values.
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

static inline uint16_t Convert_0to100_0to1023(float value) {
    return (uint16_t)(value * 10.23f);
}

static inline uint8_t Convert_0to100_0to255(float value) {
    return (uint8_t)(value * 2.55f);
}

static inline float Convert_0to100_0to5V(float value) {
    return value * 0.05f;
}

static inline float Convert_0to100_1to5V(float value) {
    return (value * 0.04f) + 1.0f;
}

static inline float Convert_0to100_0to3V3(float value) {
    return value * 0.033f;
}

static inline uint16_t Convert_0to5V_0to1023(float voltage) {
    return (uint16_t)(voltage * 204.6f);  // 1023/5
}

static inline uint8_t Convert_0to5V_0to255(float voltage) {
    return (uint8_t)(voltage * 51.0f);
}

static inline uint16_t Convert_0to3V3_0to1023(float voltage) {
    return (uint16_t)(voltage * 310.0f);
}

static inline uint8_t Convert_0to3V3_0to255(float voltage) {
    return (uint8_t)(voltage * 77.2727f);
}

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
