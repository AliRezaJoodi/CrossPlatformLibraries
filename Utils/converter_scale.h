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

static inline float Convert_0to100_0to5V(float value) {
    return value * 0.05f;
}

static inline float Convert_0to100_1to5V(float value) {
    return (value * 0.04f) + 1.0f;
}

static inline float Convert_0to100_0to3V3(float value) {
    return value * 0.033f;
}

static inline uint16_t Convert_0to4096mV_12BitCount(float mv) {
    uint16_t data = mv * 1.0f;
    if (data > 4095U) {data = 4095U;}
    return data;
}

static inline uint16_t Convert_0to4V096_12BitCount(float voltage) {
    uint16_t data = voltage * 1000.0f;
    if (data > 4095U) {data = 4095U;}
    return data;
}

static inline uint16_t Convert_0to2048mV_12BitCount(float mv) {
    uint16_t data = mv * 2.0f;
    if (data > 4095U) {data = 4095U;}
    return data;
}

static inline uint16_t Convert_0to2V048_12BitCount(float voltage) {
    uint16_t data = voltage * 2000.0f;
    if (data > 4095U) {data = 4095U;}
    return data;
}

static inline uint16_t Convert_0to5000mV_10BitCount(float mv) {
    uint16_t data = mv * 0.2048f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint16_t Convert_0to5V_10BitCount(float voltage) {
    uint16_t data = voltage * 204.8f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint16_t Convert_0to3300mV_10BitCount(float mv) {
    uint16_t data = mv * 0.310303030f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint16_t Convert_0to3V3_10BitCount(float voltage) {
    uint16_t data = voltage * 310.303030f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint16_t Convert_0to100_10BitCount(float value) {
    uint16_t data = value * 10.24f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint8_t Convert_0to5V_8BitCount(float voltage) {
    uint8_t data = voltage * 51.2f;
    return data;
}

static inline uint8_t Convert_0to3V3_8BitCount(float voltage) {
    uint8_t data = voltage * 77.575757f;
    return data;
}

static inline uint8_t Convert_0to100_8BitCount(float value) {
    uint8_t data = value * 2.56f;
    return data;
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
