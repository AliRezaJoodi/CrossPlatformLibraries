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

/* Convert millivolts to 12-bit DAC counts (Vref = 4.096V) */
static inline uint16_t DAC_ConvertMilliVoltToCount_12Bit4V096(uint16_t mv) {
    if (mv > 4095U) {mv = 4095U;}
    return mv;
}

/* Convert microvolts to 12-bit DAC counts (Vref = 2.048V) */
static inline uint16_t DAC_ConvertMicroVoltToCount_12Bit2V048(uint32_t uv) {
    uint32_t out = ((uv >> 2) * 4195U) >> 19;
    if (out > 4095U) {out = 4095U;}
    return (uint16_t)out;
}

/* Convert millivolts to 10-bit DAC counts (Vref = 5V) */
static inline uint16_t DAC_ConvertMilliVoltToCount_10Bit5V(uint16_t mv) {
    uint32_t out = ((uint32_t)mv * 13435U) >> 16;
    if (out > 1023U) {out = 1023U;}
    return (uint16_t)out;
}

/* Convert millivolts to 10-bit DAC counts (Vref = 3.3V) */
static inline uint16_t DAC_ConvertMilliVoltToCount_10Bit3V3(uint16_t mv) {
    //uint32_t data = (uint32_t)mv * 1024U / 3300U;
    uint32_t data = ((uint32_t)mv * 1270U) >> 12;
    if (data > 1023U) {data = 1023U;}
    return data;
}

/* Convert millivolts to 8-bit DAC counts (Vref = 5V) */
static inline uint8_t DAC_ConvertMilliVoltToCount_8Bit5V(uint16_t mv) {
    uint32_t data = ((uint32_t)mv * 3354U) >> 16;
    if (data > 255U){data = 255U;}
    return data;
}

/* Convert millivolts to 8-bit DAC counts (Vref = 3.3V) */
static inline uint8_t DAC_ConvertMilliVoltToCount_8Bit3V3(uint16_t mv) {
    uint32_t data = ((uint32_t)mv * 5082U) >> 16;
    if (data > 255U){data = 255U;}
    return data;
}

#ifdef __cplusplus
}
#endif

#endif
