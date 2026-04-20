// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef TEMPERATURE_CONVERTER_INCLUDED
#define TEMPERATURE_CONVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

static inline float Temp_ConvertKtoC(float value){
    return (value - 273.15f);
}

static inline float Temp_ConvertKtoF(float value){
    return (((value - 273.15f) * 1.8f) + 32.0f);
}

static inline float Temp_ConvertCtoK(float value){
    return (value + 273.15f);
}

static inline float Temp_ConvertCtoF(float value){
    return ((value * 1.8f) + 32.0f);
}

static inline float Temp_ConvertFtoC(float value){
    return ((value - 32.0f) * 0.5555556f);
}

static inline float Temp_ConvertFtoK(float value){
    return (((value - 32.0f) * 0.5555556f) + 273.15f);
}

#ifdef __cplusplus
}
#endif

#endif
