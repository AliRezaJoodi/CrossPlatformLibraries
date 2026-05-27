#ifndef MCP3204_HW_INCLUDED
#define MCP3204_HW_INCLUDED

#include "hardware.h"       /**< Project-level overrides */

#ifndef MCP3204_HARDWARE
#define MCP3204_HARDWARE
    #define MCP3204_TIMEOUT         1000U

    #warning "MCP3204_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP3204_HARDWARE_EXTRA
#define MCP3204_HARDWARE_EXTRA
    #define MCP3204_CS_DDR          DDRB
    #define MCP3204_CS_PORT         PORTB
    #define MCP3204_CS_BIT          4U
    #define MCP3204_CS_MASK         (1U << MCP3204_CS_BIT)
#endif

#endif
