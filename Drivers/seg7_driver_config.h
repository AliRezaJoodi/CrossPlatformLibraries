#ifndef SEG7_DRIVER_CONFIG_INCLUDED
#define SEG7_DRIVER_CONFIG_INCLUDED

#include "hardware.h"

#ifndef SEG7_DRIVER_CONFIG
    #define SEG7_DRIVER_CONFIG

    //#define SEG7_DISPLAYLAG          5 //Display Lag
    #define SEG7_ACTIVATE_DIGIT      1
    #define SEG7_ACTIVATE_SEGMENT    0

    #warning "SEG7_DRIVER_CONFIG is not defined; default configuration will be used."
#endif

#endif
