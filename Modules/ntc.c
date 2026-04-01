// GitHub Account: GitHub.com/AliRezaJoodi

#include "ntc.h"

//********************************************************
float Thermistor_ConvertVoltToOhm_PullUp(float volt){
    float ohm=0;

    ohm=(VCC-volt)/(volt/RESISTOR);
    return ohm;
}

