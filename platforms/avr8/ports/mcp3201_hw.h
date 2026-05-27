#ifndef MCP3201_HW_INCLUDED
#define MCP3201_HW_INCLUDED

#include "hardware.h"   /**< Project-level overrides */

#ifndef MCP3201_HARDWARE
#define MCP3201_HARDWARE
    #define MCP3201_TIMEOUT         1000U

    #warning "MCP3201_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP3201_HARDWARE_EXTRA
#define MCP3201_HARDWARE_EXTRA
    #define MCP3201_TIMEOUT         1000U

    #define MCP3201_CS_DDR          DDRB
    #define MCP3201_CS_PORT         PORTB
    #define MCP3201_CS_BIT          4U
    #define MCP3201_CS_MASK         (1U << MCP3201_CS_BIT)
#endif

#endif
