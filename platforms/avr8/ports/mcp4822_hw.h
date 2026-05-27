#ifndef MCP4822_HW_INCLUDED
#define MCP4822_HW_INCLUDED

#include "hardware.h"       /**< Project-level overrides */

#ifndef MCP4822_HARDWARE
#define MCP4822_HARDWARE
    #define MCP4822_TIMEOUT         1000U

    #warning "MCP4822_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef MCP4822_HARDWARE_EXTRA
#define MCP4822_HARDWARE_EXTRA
    #define MCP4822_CS_DDR          DDRB
    #define MCP4822_CS_PORT         PORTB
    #define MCP4822_CS_BIT          3U
    #define MCP4822_CS_MASK         (1U << MCP4822_CS_BIT)

    #define MCP4822_LDAC_DDR        DDRB
    #define MCP4822_LDAC_PORT       PORTB
    #define MCP4822_LDAC_BIT        2U
    #define MCP4822_LDAC_MASK       (1U << MCP4822_LDAC_BIT)

    //#warning "MCP4822_HARDWARE_EXTRA is not defined; default configuration will be used."
#endif

#endif
