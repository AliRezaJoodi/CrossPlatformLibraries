/**
 * @brief   LM35 temperature sensor conversion utilities
 *
 * @details
 * LM35 outputs a voltage linearly proportional to temperature
 * in degrees Celsius (10 mV per 1 °C).
 *
 * Formula:
 *  - Temperature (°C) = Voltage (mV) × 0.1
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_LM35_CONVERTER_INCLUDED
#define AJ_LM35_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline float AJ_LM35_ConvertMilliVoltToTemp(float mv){
    return (mv * 0.1f);
}

static inline float AJ_LM35_ConvertVoltToTemp(float voltage){
    return (voltage * 1000 * 0.1f);
}

#ifdef __cplusplus
}
#endif

#endif
