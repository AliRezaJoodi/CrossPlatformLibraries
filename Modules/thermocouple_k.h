// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef THERMOCOUPLE_INCLUDED
#define THERMOCOUPLE_INCLUDED

#include <stdint.h>

#ifndef TC_HARDWARE
#define TC_HARDWARE
    #define TC_CH           0
    #define TC_GAIN         1/90
#endif


#define TC_K_TEMP_MIN     -270
#define TC_K_TEMP_MAX     1370
#define TC_K_ERROR        -1000

int TC_ConvertMilliVoltToTemp(float mv);
float TC_ConvertTempToMilliVolt(int temp);

int32_t TC_ConvertMicroVoltToTemp(int32_t uv);
int32_t TC_ConvertTempToMicroVolt(int32_t uv);

#endif

