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

static inline uint32_t ADC_Convert_12Bit5V_uV(uint16_t counts){
    return ((uint32_t)counts * 78125UL) >> 6;
}

static inline float ADC_Convert_12Bit5V_mV(uint16_t counts){
    return (float)counts * 1.220703125f;
}

static inline uint16_t ADC_Convert_12Bit4V096_mV(uint16_t counts){
    return counts * 1U;
}

static inline uint32_t ADC_Convert_12Bit2V048_uV(uint16_t counts){
    return (uint32_t)counts * 500U;
}

static inline float ADC_Convert_12Bit2V048_mV(uint16_t counts){
    return (float)counts * 0.5f;
}

static inline uint32_t ADC_Convert_12Bit3V3_uV(uint16_t counts){
    return ((uint32_t)counts * 825000UL) >> 10;
}

static inline float ADC_Convert_12Bit3V3_mV(uint16_t counts){
    return (float)counts * 0.8056640625f;
}

//static inline uint32_t ADC_Convert_10Bit5V_uV(uint16_t counts){
//    return ((uint32_t)counts * 19531UL) >> 2;
//}

static inline uint16_t ADC_Convert_10Bit5V_mV(uint16_t counts){
    return (uint16_t)(((uint32_t)counts * 1250U) >> 8);
}

//static inline float ADC_Convert_10Bit5V_mV_f32(uint16_t counts){
//    return (float)counts * 4.8828125f;
//}

static inline uint16_t ADC_Convert_10Bit4V096_mV(uint16_t counts){
    return counts << 2;
}

//static inline uint32_t ADC_Convert_10Bit2V56_uV(uint16_t counts){
//    return ((uint32_t)counts * 2500UL);
//}

static inline uint16_t ADC_Convert_10Bit2V56_mV(uint16_t counts){
    return (uint16_t)((counts * 5U) >> 1);
}

//static inline float ADC_Convert_10Bit2V56_mV_(uint16_t counts){
//    return (float)counts * 2.5f;
//}

static inline uint16_t ADC_Convert_10Bit2V048_mV(uint16_t counts){
    return counts << 1;
}

static inline uint16_t ADC_Convert_8Bit5V_mV(uint8_t counts) {
    return ((uint32_t)counts * 5000U) >> 8;
    //return ((uint32_t)counts * 625U) >> 5;

}

static inline float Convert_0to255_0to5V(uint8_t counts) {
    return (float)counts * 19.53125f;
}

static inline float Convert_0to255_0to2V56(uint8_t counts) {
    return (float)counts * 0.010039194f;
}

#ifdef __cplusplus
}
#endif

#endif
