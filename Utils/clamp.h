// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef CLAMP_INCLUDED
#define CLAMP_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

static inline float Clamp_0To100(float value){
    if (value < 0.0f) {
        return 0.0f;
    }
    else if (value > 100.0f) {
        return 100.0f;
    }
    return value;
}

static inline void Clamp_0To100_ByRef(float* value){
    if ((*value) < 0.0f) {
        (*value) = 0.0f;
    }
    else if ((*value) > 100.0f) {
        (*value) = 100.0f;
    }
}

static inline float Clamp_0To5V(float value){
    if (value < 0.0f) {
        return 0.0f;
    }
    else if (value > 5.0f) {
        return 5.0f;
    }
    return value;
}

static inline void Clamp_0To5V_ByRef(float* value){
    if ((*value) < 0.0f) {
        (*value) = 0.0f;
    }
    else if ((*value) > 5.0f) {
        (*value) = 5.0f;
    }
}

static inline float Clamp_1To5V(float value){
    if (value < 1.0f) {
        return 1.0f;
    }
    else if (value > 5.0f) {
        return 5.0f;
    }
    return value;
}

static inline void Clamp_1To5V_ByRef(float* value){
    if ((*value) < 1.0f) {
        (*value) = 1.0f;
    }
    else if ((*value) > 5.0f) {
        (*value) = 5.0f;
    }
}

static inline uint16_t Clamp_0To1023(uint16_t value){
    if (value < 1023) {
        return (uint16_t)value;
    }
    else {
        return 1023;
    }
}

static inline void Clamp_0To1023_ByRef(uint16_t* value){
    if ((*value) < 1023) {
        (*value) = (*value);
    }
    else {
        (*value) = 1023;
    }
}

#ifdef __cplusplus
}
#endif

#endif
