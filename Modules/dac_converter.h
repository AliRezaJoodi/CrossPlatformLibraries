/*
 * @brief Linear scale conversion utilities for analog values.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef DAC_CONVERTER_INCLUDED
#define DAC_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline uint16_t DAC_Convert_12Bit4V096_mV(uint16_t mv) {
    if (mv > 4095U) {mv = 4095U;}
    return mv;
}

//static inline uint16_t Convert_0to4096mV_12BitCount(float mv) {
//    uint16_t data = mv * 1.0f;
//    if (data > 4095U) {data = 4095U;}
//    return data;
//}

//static inline uint16_t Convert_0to4V096_12BitCount(float voltage) {
//    uint16_t data = voltage * 1000.0f;
//    if (data > 4095U) {data = 4095U;}
//    return data;
//}

static inline uint16_t DAC_Convert_12Bit2V048_uV(uint32_t uv) {
    //uint32_t data = uv / 500U;
    uint32_t data = ((uv >> 2) * 4195U) >> 19;
    if (data > 4095U) {data = 4095U;}
    return (uint16_t)data;
}

//static inline uint16_t DAC_Convert_12Bit2V048_mV(float mv) {
//    uint16_t data = mv * 2.0f;
//    if (data > 4095U) {data = 4095U;}
//    return data;
//}

//static inline uint16_t Convert_0to2V048_12BitCount(float voltage) {
//    uint16_t data = voltage * 2000.0f;
//    if (data > 4095U) {data = 4095U;}
//    return data;
//}

static inline uint16_t DAC_Convert_10Bit5V_mV(uint16_t mv) {
    uint32_t data = (uint32_t)mv * 1024U / 5000U;
    if (data > 1023U) {data = 1023U;}
    return data;
}

static inline uint16_t DAC_Convert_10Bit5V_mV_(float mv) {
    uint16_t data = mv * 0.2048f;
    if (data > 1023U) {data = 1023U;}
    return data;
}

//static inline uint16_t Convert_0to5V_10BitCount(float voltage) {
//    uint16_t data = voltage * 204.8f;
//    if (data > 1023U) {data = 1023U;}
//    return data;
//}

static inline uint16_t DAC_Convert_10Bit3V3_mV(uint16_t mv) {
    //uint32_t data = (uint32_t)mv * 1024U / 3300U;
    uint32_t data = ((uint32_t)mv * 1270U) >> 12;
    if (data > 1023U) {data = 1023U;}
    return data;
}

//static inline uint16_t DAC_Convert_10Bit3V3_mV_(float mv) {
//    uint16_t data = mv * 0.310303030f;
//    if (data > 1023U) {data = 1023U;}
//    return data;
//}

//static inline uint16_t Convert_0to3V3_10BitCount(float voltage) {
//    uint16_t data = voltage * 310.303030f;
//    if (data > 1023U) {data = 1023U;}
//    return data;
//}

static inline uint8_t DAC_Convert_8Bit5V_mV(uint16_t mv) {
//    uint32_t data = (uint32_t)mv * 256U / 5000U;
    uint32_t data = ((uint32_t)mv * 3354U) >> 16;
    if (data > 255U){data = 255U;}
    return data;
}

//static inline uint8_t DAC_Convert_8Bit5V_mV_(float voltage) {
//    uint8_t data = voltage * 0.0512f;
//    return data;
//}

static inline uint8_t DAC_Convert_8Bit3V3_mV(uint16_t mv) {
    //uint32_t data = (uint32_t)mv * 256U / 3300U;
    uint32_t data = ((uint32_t)mv * 5082U) >> 16;
    if (data > 255U){data = 255U;}
    return data;
}

//static inline uint8_t DAC_Convert_8Bit3V3_mV_(float voltage) {
//    uint8_t data = voltage * 0.077575757f;
//    return data;
//}

#ifdef __cplusplus
}
#endif

#endif
