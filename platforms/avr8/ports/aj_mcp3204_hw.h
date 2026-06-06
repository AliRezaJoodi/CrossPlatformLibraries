#ifndef AJ_MCP3204_HW_INCLUDED
#define AJ_MCP3204_HW_INCLUDED

#include "hardware.h"       /**< Project-level overrides */

#ifndef AJ_MCP3204_HARDWARE
#define AJ_MCP3204_HARDWARE
    #define AJ_MCP3204_TIMEOUT         1000U

    #warning "AJ_MCP3204_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef AJ_MCP3204_HARDWARE_EXTRA
#define AJ_MCP3204_HARDWARE_EXTRA
    #define AJ_MCP3204_CS_DDR           DDRB
    #define AJ_MCP3204_CS_PORT          PORTB
    #define AJ_MCP3204_CS_POS           4U
    #define AJ_MCP3204_CS_MASK          (1U << AJ_MCP3204_CS_POS)
#endif

#endif
