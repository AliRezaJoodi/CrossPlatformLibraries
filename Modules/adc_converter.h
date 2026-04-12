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
 * Convert 12-bit ADC counts to millivolts (Vref = 5V)
 * Formula: mv = counts * (5000 / 4096)
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_12Bit5V(uint16_t counts){
    return (uint16_t)(((uint32_t)counts * 5000UL) >> 12);
}

/**
 * Convert 12-bit ADC counts to millivolts (Vref = 4.096V)
 * Formula: mv = counts * (4096 / 4096) = counts
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_12Bit4V096(uint16_t counts){
    return counts;
}

/**
 * Convert 12-bit ADC counts to microvolts (Vref = 3.3V)
 * Formula: uV = counts * (3300000 / 4096)
 */
static inline uint32_t ADC_ConvertCountToMicroVolt_12Bit3V3(uint16_t counts){
    //return (uint32_t)(((uint64_t)counts * 3300000UL) >> 12);
    return ((uint32_t)counts * 825000UL) >> 10;
}

/**
 * Convert 12-bit ADC counts to microvolts (Vref = 2.048V)
 * Formula: uV = counts * (2048000 / 4096) = counts * 500
 */
static inline uint32_t ADC_ConvertCountToMicroVolt_12Bit2V048(uint16_t counts){
    return (uint32_t)counts * 500UL;
}

/**
 * Convert 10-bit ADC counts to millivolts (Vref = 5V)
 * Formula: mv = counts * (5000 / 1024)
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit5V(uint16_t counts){
    return (uint16_t)(((uint32_t)counts * 5000U) >> 10);
}

/**
 * Convert 10-bit ADC counts to millivolts (Vref = 4.096V)
 * Formula: mv = counts * (4096 / 1024) = counts * 4
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit4V096(uint16_t counts){
    return counts << 2;
}

/**
 * Convert 10-bit ADC counts to millivolts (Vref = 2.56V)
 * Formula: mv = counts * (2560 / 1024) = counts * 2.5
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit2V56(uint16_t counts){
    return (counts * 5U) >> 1;
}

/**
 * Convert 10-bit ADC counts to millivolts (Vref = 2.048V)
 * Formula: mv = counts * (2048 / 1024) = counts * 2
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit2V048(uint16_t counts){
    return counts << 1;
}

/**
 * Convert 8-bit ADC counts to millivolts (Vref = 5V)
 * Formula: mv = counts * (5000 / 256)
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_8Bit5V(uint8_t counts) {
    return (uint16_t)(((uint32_t)counts * 5000U) >> 8);
}

/**
 * Convert 8-bit ADC counts to millivolts (Vref = 2.56V)
 * Formula: mv = counts * (2560 / 256) = counts * 10
 */
static inline uint16_t ADC_ConvertCountToMilliVolt_8Bit2V56(uint8_t counts) {
    return (uint16_t)counts * 10U;
}

#ifdef __cplusplus
}
#endif

#endif
