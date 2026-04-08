// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef TC_INCLUDED
#define TC_INCLUDED

#ifndef TC_HARDWARE
#define TC_HARDWARE
    #define TC_CH           0
    #define TC_GAIN         1/90
#endif

int TC_ConvertMilliVoltToTemp(float mv);
float TC_ConvertTempToMilliVolt(int temp);

#endif

