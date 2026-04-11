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

/* Convert 12-bit ADC counts (Vref=5V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_12Bit5V(uint16_t counts){
    return (uint16_t)(((uint32_t)counts * 5000UL) >> 12);
}

/* Convert 12-bit ADC counts (Vref=4.096V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_12Bit4V096(uint16_t counts){
    return counts;
}

/* Convert 12-bit ADC counts (Vref=3.3V) to microvolts */
static inline uint32_t ADC_ConvertCountToMicroVolt_12Bit3V3(uint16_t counts){
    //return (uint32_t)(((uint64_t)counts * 3300000UL) >> 12);
    return ((uint32_t)counts * 825000UL) >> 10;
}

/* Convert 12-bit ADC counts (Vref=2.048V) to microvolts */
static inline uint32_t ADC_ConvertCountToMicroVolt_12Bit2V048(uint16_t counts){
    return (uint32_t)counts * 500UL;
}

/* Convert 10-bit ADC counts (Vref=5V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit5V(uint16_t counts){
    return (uint16_t)(((uint32_t)counts * 5000U) >> 10);
}

/* Convert 10-bit ADC counts (Vref=4.096V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit4V096(uint16_t counts){
    return counts << 2;
}

/* Convert 10-bit ADC counts (Vref=2.56V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit2V56(uint16_t counts){
    //return (uint16_t)(((uint32_t)counts * 2560U) >> 10);
    return (counts * 5U) >> 1;
}

/* Convert 10-bit ADC counts (Vref=2.048V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_10Bit2V048(uint16_t counts){
    return counts << 1;
}

/* Convert 8-bit ADC counts (Vref=5V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_8Bit5V(uint8_t counts) {
    return (uint16_t)(((uint32_t)counts * 5000U) >> 8);
}

/* Convert 8-bit ADC counts (Vref=2.560V) to millivolts */
static inline uint16_t ADC_ConvertCountToMilliVolt_8Bit2V56(uint8_t counts) {
    return (uint16_t)counts * 10U;
}

#ifdef __cplusplus
}
#endif

#endif
