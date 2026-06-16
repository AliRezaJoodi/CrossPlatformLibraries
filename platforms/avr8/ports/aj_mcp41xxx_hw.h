#ifndef AJ_MCP41XXX_HW_INCLUDED
#define AJ_MCP41XXX_HW_INCLUDED

#include "hardware.h"   /**< Project-level overrides */

#ifndef AJ_MCP41XXX_HARDWARE_EXTRA
#define AJ_MCP41XXX_HARDWARE_EXTRA
    #define AJ_MCP41XXX_CS_DDR          DDRB
    #define AJ_MCP41XXX_CS_PORT         PORTB
    #define AJ_MCP41XXX_CS_POS          4U
    #define AJ_MCP41XXX_CS_MASK         (1U << AJ_MCP41XXX_CS_POS)
#endif

#endif
