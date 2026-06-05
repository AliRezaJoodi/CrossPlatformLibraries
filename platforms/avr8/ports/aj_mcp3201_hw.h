#ifndef AJ_MCP3201_HW_INCLUDED
#define AJ_MCP3201_HW_INCLUDED

#include "hardware.h"   /**< Project-level overrides */

#ifndef AJ_MCP3201_HARDWARE
#define AJ_MCP3201_HARDWARE
    #define AJ_MCP3201_TIMEOUT         1000U

    #warning "AJ_MCP3201_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef AJ_MCP3201_HARDWARE_EXTRA
#define AJ_MCP3201_HARDWARE_EXTRA
    #define AJ_MCP3201_CS_DDR          DDRB
    #define AJ_MCP3201_CS_PORT         PORTB
    #define AJ_MCP3201_CS_POS          4U
    #define AJ_MCP3201_CS_MASK         (1U << AJ_MCP3201_CS_POS)
#endif

#endif
