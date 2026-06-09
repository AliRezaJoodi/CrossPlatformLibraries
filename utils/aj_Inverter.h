// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_INVERTER_INCLUDED
#define AJ_INVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline float AJ_Invert_0To100(float value){
    return 100.0f - value;
}

static inline float AJ_Invert_0To5V(float value){
    return (5.0f - value);
}

static inline float AJ_Invert_1To5V(float value){
    return (6.0f - value);
}

static inline float AJ_Invert_0To3V3(float value){
    return (3.3f - value);
}

static inline uint16_t AJ_Invert_0To1023(uint16_t value){
    return (uint16_t)(1023U - value);
}

static inline uint8_t AJ_Invert_0To255(uint8_t value){
    return (uint8_t)(255U - value);
}

#ifdef __cplusplus
}
#endif

#endif
