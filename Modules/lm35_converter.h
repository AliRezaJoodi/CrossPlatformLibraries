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

#ifndef LM35_INCLUDED
#define LM35_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

static inline float LM35_ConvertMilliVoltToTemp(float volt_mv){
    return (volt_mv * 0.1f);
}

static inline float LM35_ConvertVoltToTemp(float volt_v){
    return (volt_v * 1000 * 0.1f);
}

#ifdef __cplusplus
}
#endif

#endif
