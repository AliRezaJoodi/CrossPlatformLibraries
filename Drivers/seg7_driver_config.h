#ifndef SEG7_DRIVER_CONFIG_INCLUDED
#define SEG7_DRIVER_CONFIG_INCLUDED

#include "hardware.h"

#ifndef SEG7_DRIVER_CONFIG
#define SEG7_DRIVER_CONFIG
    #define SEG7_DIGITS_COUNT       8
    #define SEG7_DIGITS_ACTIVATE    1
    #define SEG7_SEGMENTS_ACTIVATE  0

    #warning "SEG7_DRIVER_CONFIG is not defined; default configuration will be used."
#endif

#endif
