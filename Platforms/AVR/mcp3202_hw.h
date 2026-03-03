#ifndef MCP3202_HW_INCLUDED
#define MCP3202_HW_INCLUDED

#include "compiler_port.h"

#ifndef MCP3202_HARDWARE_EXTRA
#define MCP3202_HARDWARE_EXTRA
    #define MCP3202_CS_DDR      DDRB.4
    #define MCP3202_CS_PORT     PORTB.4
    #define MCP3202_CS_PIN      PINB.4
#endif

#endif
