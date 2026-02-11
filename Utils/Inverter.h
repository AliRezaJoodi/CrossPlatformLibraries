// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef INVERTER_INCLUDED
#define INVERTER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline float Invert_0To100(float value){
    return 100.0f - value;
}

static inline void Invert_0To100_ByRef(float* value){
    (*value) = (100.0f - (*value));
}

static inline float Invert_0To5V(float value){
    return (5.0f - value);
}

static inline void Invert_0To5V_ByRef(float* value){
    (*value) = (5.0f - (*value));
}

static inline float Invert_1To5V(float value){
    return (6.0f - value);
}

static inline void Invert_1To5V_ByRef(float* value){
    (*value) = (6.0f - (*value));
}

static inline float Invert_0To3V3(float value){
    return (3.3f - value);
}

static inline void Invert_0To3V3_ByRef(float* value){
    (*value) = (3.3f - (*value));
}

static inline uint16_t Invert_0To1023(uint16_t value){
    return (uint16_t)(1023U - value);
}

static inline void Invert_0To1023_ByRef(uint16_t* value){
    (*value) = (uint16_t)(1023U - (*value));
}

static inline uint8_t Invert_0To255(uint8_t value){
    return (uint8_t)(255U - value);
}

static inline void Invert_0To255_ByRef(uint8_t* value){
    (*value) = (uint8_t)(255U - (*value));
}

#ifdef __cplusplus
}
#endif

#endif
