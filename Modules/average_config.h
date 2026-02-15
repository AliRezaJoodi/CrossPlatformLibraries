#ifndef AVERAGE_CONFIG_INCLUDED
#define AVERAGE_CONFIG_INCLUDED

/** @brief Include user-overridable macros. */
#include "hardware.h"

#ifndef AVERAGE_CONFIG
#define AVERAGE_CONFIG    
    #define AVERAGE_COUNT     10     // <256 
    
    #warning "AVERAGE_CONFIG is not defined; default configuration will be used."  
#endif

#endif
