#ifndef MCP3202_HW_INCLUDED
#define MCP3202_HW_INCLUDED

#include "compiler_port.h"

#ifndef MCP3202_HARDWARE_EXTRA
#define MCP3202_HARDWARE_EXTRA
    #define MCP3202_CS_DDR          DDRB
    #define MCP3202_CS_PORT         PORTB
    #define MCP3202_CS_BIT          4
#endif

#endif
