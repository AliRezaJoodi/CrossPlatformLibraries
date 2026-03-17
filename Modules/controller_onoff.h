// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef CONTROLLER_ONOFF_INCLUDED
#define CONTROLLER_ONOFF_INCLUDED

#ifndef CONTROLLER_ONOFF_HARDWARE
#define CONTROLLER_ONOFF_HARDWARE
    #define HEATER_ACTIVE         1
    #define COOLER_ACTIVE         1
#endif

char Controller_OnOff_Heater(float sp,float pv, float hystersis);
char Controller_OnOff2_Heater(float sp,float pv, float hystersis);
char Controller_OnOff_Cooler(float sp,float pv, float hystersis);
char Controller_OnOff2_Cooler(float sp,float pv, float hystersis);

#endif
