// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "ntc.h"

//********************************************************
float NTC_ConvertMilliVoltToOhm(float mv, uint32_t res){
    float ohm = 0;
    ohm = (mv * res) / (VREF_MV - mv);
    return ohm;
}

////********************************************************
//float Thermistor_ConvertVoltToOhm_PullUp(float volt){
//    float ohm=0;
//
//    ohm=(VCC-volt)/(volt/RESISTOR);
//    return ohm;
//}

