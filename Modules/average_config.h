#ifndef AVERAGE_CONFIG_INCLUDED
#define AVERAGE_CONFIG_INCLUDED

#include "hardware.h"   // Default hardware macros can be overridden by the user

#ifndef AVERAGE_CONFIG
#define AVERAGE_CONFIG    
    #define AVERAGE_COUNT     10     // <256 
    
    #warning "AVERAGE_CONFIG is not defined; default configuration will be used."  
#endif

#endif
