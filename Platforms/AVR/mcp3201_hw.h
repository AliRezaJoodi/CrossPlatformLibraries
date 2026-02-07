#ifndef MCP3201_HW_INCLUDED
#define MCP3201_HW_INCLUDED


/**
 * @note Default hardware macros can be overridden by the user.
 */ 
#include "hardware.h"

#ifndef MCP3201_HARDWARE
#define MCP3201_HARDWARE    
    #define MCP3201_VREF        5000U     //mv
     
    #warning "MCP3201_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP3201_HARDWARE_EXTRA
#define MCP3201_HARDWARE_EXTRA
    #define MCP3201_CS1_DDR      DDRB
    #define MCP3201_CS1_PORT     PORTB
    #define MCP3201_CS1_BIT      4U 
         
    #warning "MCP3201_HARDWARE_EXTRA is not defined; default configuration will be used."
#endif


#endif
