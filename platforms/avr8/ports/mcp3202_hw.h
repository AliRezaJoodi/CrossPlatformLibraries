#ifndef MCP3202_HW_INCLUDED
#define MCP3202_HW_INCLUDED

#include "hardware.h"       /**< Project-level overrides */

#ifndef MCP3202_HARDWARE
#define MCP3202_HARDWARE
    #define MCP3202_TIMEOUT         1000U

    #warning "MCP3202_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP3202_HARDWARE_EXTRA
#define MCP3202_HARDWARE_EXTRA
    #define MCP3202_CS_DDR          DDRB
    #define MCP3202_CS_PORT         PORTB
    #define MCP3202_CS_BIT          4U
    #define MCP3202_CS_MASK         (1U << MCP3202_CS_BIT)
#endif

#endif
