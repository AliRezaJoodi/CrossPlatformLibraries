#ifndef AJ_MCP3204_3208_CONFIG_INCLUDED
#define AJ_MCP3204_3208_CONFIG_INCLUDED


#include "hardware.h"       /**< Project-level overrides */

#ifndef AJ_MCP3204_3208_CONFIG
#define AJ_MCP3204_3208_CONFIG
    #define AJ_MCP3204_3208_CHANNELS        8U      /**< 4 or 8 bits resolution. */

    #warning "AJ_MCP3204_3208_CHS is not defined; default configuration will be used."
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_MCP3204_3208_CHANNELS != 4U) && (AJ_MCP3204_3208_CHANNELS != 8U))
    #error "AJ_MCP3204_3208_CONFIG must be 4U or 8U."
#endif


#endif
