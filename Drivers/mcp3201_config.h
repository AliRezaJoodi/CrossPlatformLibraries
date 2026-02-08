#ifndef MCP3201_CONFIG_INCLUDED
#define MCP3201_CONFIG_INCLUDED

#include "hardware.h"  // Default hardware macros can be overridden by the user

#ifndef MCP3201_CONFIG
#define MCP3201_CONFIG    
    #define MCP3201_VREF        5000U     //mv
     
    #warning "MCP3201_CONFIG is not defined; default configuration will be used."
#endif

#endif

