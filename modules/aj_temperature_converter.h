/**
 * @brief  Temperature unit conversion utilities.
 *         Provides helper functions to convert between Celsius,
 *         Fahrenheit, and Kelvin temperature units.
 *
 * @note
 * Float-based temperature conversion.
 * May consume significant CPU cycles on MCUs without FPU.
 * Use sparingly, preferably only for occasional display updates.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_TEMPERATURE_CONVERTER_INCLUDED
#define AJ_TEMPERATURE_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

static inline float AJ_Temp_ConvertKtoC(float value){
    return (value - 273.15f);
}

static inline float AJ_Temp_ConvertKtoF(float value){
    return (((value - 273.15f) * 1.8f) + 32.0f);
}

static inline float AJ_Temp_ConvertCtoK(float value){
    return (value + 273.15f);
}

static inline float AJ_Temp_ConvertCtoF(float value){
    return ((value * 1.8f) + 32.0f);
}

static inline float AJ_Temp_ConvertFtoC(float value){
    return ((value - 32.0f) * 0.5555556f);
}

static inline float AJ_Temp_ConvertFtoK(float value){
    return (((value - 32.0f) * 0.5555556f) + 273.15f);
}

#ifdef __cplusplus
}
#endif

#endif
