// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef CONVERTER_TEMPERATURE_INCLUDED
#define CONVERTER_TEMPERATURE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

static inline float ConvertTemp_KtoC(float value){
    return (value - 273.15f);
}

static inline float ConvertTemp_KtoF(float value){
    return (((value - 273.15f) * 1.8f) + 32.0f);
}

static inline float ConvertTemp_CtoK(float value){
    return (value + 273.15f);
}

static inline float ConvertTemp_CtoF(float value){
    return ((value * 1.8f) + 32.0f);
}

static inline float ConvertTemp_FtoC(float value){
    return ((value - 32.0f) * 0.5555556f);
}

static inline float ConvertTemp_FtoK(float value){
    return (((value - 32.0f) * 0.5555556f) + 273.15f);
}

#ifdef __cplusplus
}
#endif

#endif
