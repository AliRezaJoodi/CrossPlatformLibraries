// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef NTC_INCLUDED
#define NTC_INCLUDED

#include <stdint.h>

#ifndef NTC_HARDWARE
#define NTC_HARDWARE
    #define VREF_MV         5000
    #warning "NTC_HARDWARE is not defined; default configuration will be used."
#endif

//Pull-Up NTC
/*
VCC
NTC
RESISTOR
GND
*/

float NTC_ConvertMilliVoltToOhm(float mv, uint32_t res);
//float Thermistor_ConvertVoltToOhm_PullUp(float volt);

#endif
