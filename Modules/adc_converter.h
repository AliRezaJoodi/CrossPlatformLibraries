/*
 * @brief Linear scale conversion utilities for analog values.
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

static inline uint16_t ADC_Convert_12Bit5V_mV(uint16_t counts){
    return ((uint32_t)counts * 5000UL) >> 12;
}

static inline uint16_t ADC_Convert_12Bit4V096_mV(uint16_t counts){
    return counts * 1U;
}

static inline uint32_t ADC_Convert_12Bit3V3_uV(uint16_t counts){
    return ((uint32_t)counts * 825000UL) >> 10;
}

//static inline float ADC_Convert_12Bit3V3_mV(uint16_t counts){
//    return (float)counts * 0.8056640625f;
//}

static inline uint32_t ADC_Convert_12Bit2V048_uV(uint16_t counts){
    return (uint32_t)counts * 500UL;
}

//static inline float ADC_Convert_12Bit2V048_mV(uint16_t counts){
//    return (float)counts * 0.5f;
//}

static inline uint16_t ADC_Convert_10Bit5V_mV(uint16_t counts){
    return (uint16_t)(((uint32_t)counts * 1250U) >> 8);
}

static inline uint16_t ADC_Convert_10Bit4V096_mV(uint16_t counts){
    return counts << 2;
}

static inline uint16_t ADC_Convert_10Bit2V56_mV(uint16_t counts){
    return (uint16_t)((counts * 5U) >> 1);
}

static inline uint16_t ADC_Convert_10Bit2V048_mV(uint16_t counts){
    return counts << 1;
}

static inline uint16_t ADC_Convert_8Bit5V_mV(uint8_t counts) {
    return ((uint32_t)counts * 5000U) >> 8;
}

static inline uint16_t ADC_Convert_8Bit2V56_mV(uint8_t counts) {
    return (uint16_t)counts * 10U;
}

#ifdef __cplusplus
}
#endif

#endif
