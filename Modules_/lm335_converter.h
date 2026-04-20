/**
 * @brief   LM335 temperature sensor conversion utilities
 *
 * @details
 * LM335 outputs a voltage linearly proportional to absolute temperature
 * in Kelvin (10 mV per 1 K).
 *
 * Formula:
 *  - Temperature (K) = Voltage (mV) × 0.1
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef LM335_CONVERTER_INCLUDED
#define LM335_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

static inline float LM335_ConvertMilliVoltToTemp(float mv){
    return (mv * 0.1f);
}

static inline float LM335_ConvertVoltToTemp(float voltage){
    return (voltage * 1000 * 0.1f);
}

#ifdef __cplusplus
}
#endif

#endif
