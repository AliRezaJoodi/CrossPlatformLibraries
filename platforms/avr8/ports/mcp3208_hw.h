#ifndef MCP3208_HW_INCLUDED
#define MCP3208_HW_INCLUDED

#include "hardware.h"       /**< Project-level overrides */

#ifndef MCP3208_HARDWARE
#define MCP3208_HARDWARE
    #define MCP3208_TIMEOUT         1000U

    #warning "MCP3208_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP3208_HARDWARE_EXTRA
#define MCP3208_HARDWARE_EXTRA
    #define MCP3208_CS_DDR          DDRB
    #define MCP3208_CS_PORT         PORTB
    #define MCP3208_CS_BIT          4U
    #define MCP3208_CS_MASK         (1U << MCP3208_CS_BIT)
#endif

#endif
