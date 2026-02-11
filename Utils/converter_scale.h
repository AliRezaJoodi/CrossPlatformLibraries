// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef Convert_SCALE_INCLUDED
#define Convert_SCALE_INCLUDED

#include <stdint.h>

static inline float Clamp_0To100(float value){
    if(value < 0.0f) {return 0.0f;}
    else if(value > 100.0f) {return 100.0f;}
    return value;
}

static inline float Invert_0To100(float value){
    return 100.0f - value;
}

static inline uint16_t Convert_0to100_0to1023(float value){
    return (uint16_t)(value * 10.23f);
}

static inline uint8_t Convert_0to100_0to255(float value){
    return (uint8_t)(value * 2.55f);
}

static inline float Convert_0to100_0to5V(float value){
    return value * 0.05f;
}

static inline float Convert_0to100_1to5V(float value){
    return (value * 0.04f) + 1.0f;
}

static inline float Convert_0to100_0to3V3(float value){
    return value * 0.033f;
}

static inline uint16_t Convert_0to5V_0to1023(float voltage){
    return (uint16_t)(voltage * 204.6f);  // 1023/5
}

static inline uint8_t Convert_0to5V_0to255(float voltage){
    return (uint8_t)(voltage * 51.0f);
}

static inline uint16_t Convert_0to3V3_0to1023(float voltage){
    return (uint16_t)(voltage * 310.0f);
}

static inline uint8_t Convert_0to3V3_0to255(float voltage){
    return (uint8_t)(voltage * 77.2727f);
}

static inline float Convert_0to1023_0to5V(uint16_t counts){
    return (float)counts * 0.0048875855f;
}

static inline float Convert_0to255_0to5V(uint8_t counts){
    return (float)counts * 0.019607843f;
}

static inline float Convert_0to1023_0to2V56(uint16_t counts){
    return (float)counts * 0.002502444f;
}

static inline float Convert_0to255_0to2V56(uint8_t counts){
    return (float)counts * 0.010039194f;
}

#endif
