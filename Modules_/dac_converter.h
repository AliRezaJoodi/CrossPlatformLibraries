/*
 * @brief   linear scaling utilities for analog signal conversions.
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

/**
 * Convert millivolts to 12-bit DAC counts (Vref = 4.096V)
 * Formula: code = mv * (4096 / 4096) = mv
 */
static inline uint16_t DAC_ConvertMilliVoltToCount_12Bit4V096(uint16_t mv) {
    if (mv > 4095U) {mv = 4095U;}
    return mv;
}

/**
 * Convert microvolts to 12-bit DAC counts (Vref = 2.048V)
 * Formula: code = uv * (4096 / 2048000)
 */
static inline uint16_t DAC_ConvertMicroVoltToCount_12Bit2V048(uint32_t uv) {
    uint32_t out = ((uv >> 2) * 4195U) >> 19;
    if (out > 4095U) {out = 4095U;}
    return (uint16_t)out;
}

/**
 * Convert millivolts to 10-bit DAC counts (Vref = 5.000V)
 * Formula: code = mv * (1024 / 5000)
 */
static inline uint16_t DAC_ConvertMilliVoltToCount_10Bit5V(uint16_t mv) {
    uint32_t out = ((uint32_t)mv * 13435U) >> 16;
    if (out > 1023U) {out = 1023U;}
    return (uint16_t)out;
}

/**
 * Convert millivolts to 10-bit DAC counts (Vref = 4.096V)
 * Formula: code = mv * (1024 / 4096) = mv * 0.25
 */
static inline uint16_t DAC_ConvertMilliVoltToCount_10Bit4V096(uint16_t mv){
    uint32_t out = (uint32_t)mv >> 2;
    if (out > 1023U) {out = 1023U;}
    return (uint16_t)out;
}

/**
 * Convert millivolts to 10-bit DAC counts (Vref = 3.300V)
 * Formula: code = mv * (1024 / 3300)
 */
static inline uint16_t DAC_ConvertMilliVoltToCount_10Bit3V3(uint16_t mv) {
    uint32_t data = ((uint32_t)mv * 1270U) >> 12;
    if (data > 1023U) {data = 1023U;}
    return data;
}

/**
 * Convert millivolts to 10-bit DAC counts (Vref = 2.048V)
 * Formula: code = mv * (1024 / 2048) = mv * 0.5
 */
static inline uint16_t DAC_ConvertMilliVoltToCount_10Bit2V048(uint16_t mv){
    uint32_t out = (uint32_t)mv >> 1;
    if (out > 1023U) {out = 1023U;}
    return (uint16_t)out;
}

/**
 * Convert millivolts to 8-bit DAC counts (Vref = 5.000V)
 * Formula: code = mv * (256 / 5000)
 */
static inline uint8_t DAC_ConvertMilliVoltToCount_8Bit5V(uint16_t mv) {
    uint32_t data = ((uint32_t)mv * 3354U) >> 16;
    if (data > 255U){data = 255U;}
    return data;
}

/**
 * Convert millivolts to 8-bit DAC counts (Vref = 3.300V)
 * Formula: code = mv * (256 / 3300)
 */
static inline uint8_t DAC_ConvertMilliVoltToCount_8Bit3V3(uint16_t mv) {
    uint32_t data = ((uint32_t)mv * 5082U) >> 16;
    if (data > 255U){data = 255U;}
    return data;
}

#ifdef __cplusplus
}
#endif

#endif
