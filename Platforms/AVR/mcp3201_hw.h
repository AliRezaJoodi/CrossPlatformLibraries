#ifndef MCP3201_HW_INCLUDED
#define MCP3201_HW_INCLUDED

#include "compiler_port.h"

#ifndef MCP3201_HARDWARE_EXTRA
#define MCP3201_HARDWARE_EXTRA
    #define MCP3201_CS_DDR          DDRB
    #define MCP3201_CS_PORT         PORTB
    #define MCP3201_CS_BIT          4
#endif

#endif
