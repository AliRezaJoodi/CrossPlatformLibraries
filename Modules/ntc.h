// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef NTC_INCLUDED
#define NTC_INCLUDED

#ifndef NTC_HARDWARE
#define NTC_HARDWARE
    #define VCC     	        5
    #define RESISTOR      	    1500    //ohm
    #define THERMISTOR_CH       0
#endif


//Pull-Up NTC
/*
VCC
NTC
RESISTOR
GND
*/

float Thermistor_ConvertVoltToOhm_PullUp(float volt);

#endif
