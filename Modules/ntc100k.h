// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef NTC100K_INCLUDED
#define NTC100K_INCLUDED

#include <stdint.h>

#ifndef NTC100K_HARDWARE
#define NTC100K_HARDWARE
    #define VREF_MV         5000
    #warning "NTC100K_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef NTC100K_HARDWARE_EXTERA
#define NTC100K_HARDWARE_EXTERA
    #define NTC100K_RESISTOR        100000UL    //ohm
    #define NTC100K_CH              0
    #warning "NTC100K_HARDWARE_EXTERA is not defined; default configuration will be used."
#endif

uint32_t NTC100K_ConvertMilliVoltToOhm(uint16_t mv, uint32_t res);
//float NTC100K_ConvertMilliVoltToOhm_(float mv, uint32_t res);
float NTC100K_ConvertOhmToTemp(float ohm);
int16_t NTC100K_ConvertOhmToTemp_(uint32_t ohm);

#endif
