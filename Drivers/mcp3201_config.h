#ifndef MCP3201_CONFIG_INCLUDED
#define MCP3201_CONFIG_INCLUDED

/** @brief Include user-overridable macros. */
#include "hardware.h"

/** @brief Default configuration (can be overridden). */
#ifndef MCP3201_CONFIG
#define MCP3201_CONFIG
    #define MCP3201_VREF        5000U     /**< Ref Voltage (mv) */

    #warning "MCP3201_CONFIG is not defined; default configuration will be used."
#endif

#endif

