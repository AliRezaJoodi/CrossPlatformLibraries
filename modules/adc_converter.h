/*
 * @brief Linear scale conversion utilities for analog values.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef ADC_CONVERTER_INCLUDED
#define ADC_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * Convert 12-bit ADC raw to millivolts (Vref = 5V)
 * Formula: mv = raw * (5000 / 4096)
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_12Bit5V(uint16_t raw){
    return (uint16_t)(((uint32_t)raw * 5000UL) >> 12);
}

/**
 * Convert 12-bit ADC raw to millivolts (Vref = 4.096V)
 * Formula: mv = raw * (4096 / 4096) = raw
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_12Bit4V096(uint16_t raw){
    return raw;
}

/**
 * Convert 12-bit ADC raw to microvolts (Vref = 3.3V)
 * Formula: uV = raw * (3300000 / 4096)
 */
static inline uint32_t ADC_ConvertRawToMicroVolt_12Bit3V3(uint16_t raw){
    //return (uint32_t)(((uint64_t)raw * 3300000UL) >> 12);
    return ((uint32_t)raw * 825000UL) >> 10;
}

/**
 * Convert 12-bit ADC raw to microvolts (Vref = 2.048V)
 * Formula: uV = raw * (2048000 / 4096) = raw * 500
 */
static inline uint32_t ADC_ConvertRawToMicroVolt_12Bit2V048(uint16_t raw){
    return (uint32_t)raw * 500UL;
}

/**
 * Convert 10-bit ADC raw to millivolts (Vref = 5V)
 * Formula: mv = raw * (5000 / 1024)
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_10Bit5V(uint16_t raw){
    return (uint16_t)(((uint32_t)raw * 5000U) >> 10);
}

/**
 * Convert 10-bit ADC raw to millivolts (Vref = 4.096V)
 * Formula: mv = raw * (4096 / 1024) = raw * 4
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_10Bit4V096(uint16_t raw){
    return raw << 2;
}

/**
 * Convert 10-bit ADC raw to millivolts (Vref = 2.56V)
 * Formula: mv = raw * (2560 / 1024) = raw * 2.5
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_10Bit2V56(uint16_t raw){
    return (raw * 5U) >> 1;
}

/**
 * Convert 10-bit ADC raw to millivolts (Vref = 2.048V)
 * Formula: mv = raw * (2048 / 1024) = raw * 2
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_10Bit2V048(uint16_t raw){
    return raw << 1;
}

/**
 * Convert 8-bit ADC raw to millivolts (Vref = 5V)
 * Formula: mv = raw * (5000 / 256)
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_8Bit5V(uint8_t raw) {
    return (uint16_t)(((uint32_t)raw * 5000U) >> 8);
}

/**
 * Convert 8-bit ADC raw to millivolts (Vref = 2.56V)
 * Formula: mv = raw * (2560 / 256) = raw * 10
 */
static inline uint16_t ADC_ConvertRawToMilliVolt_8Bit2V56(uint8_t raw) {
    return (uint16_t)raw * 10U;
}

#ifdef __cplusplus
}
#endif

#endif
