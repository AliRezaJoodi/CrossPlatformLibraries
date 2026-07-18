#ifndef AJ_MCP4821_4822_CONFIG_INCLUDED
#define AJ_MCP4821_4822_CONFIG_INCLUDED


#include "hardware.h"       /**< Project-level overrides */

#ifndef AJ_MCP4821_4822_CONFIG
#define AJ_MCP4821_4822_CONFIG
    #define AJ_MCP4821_4822_CHB_SUPPORTED   1U      /**< 0: Single channel, 1: Dual channel supported. */
    #define AJ_MCP4821_4822_SHDN_USED       1U      /**< 0: Not used, 1: Used. */

    #warning "AJ_MCP4821_4822_CONFIG is not defined; default configuration will be used."
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_MCP4821_4822_CHB_SUPPORTED != 0U) && (AJ_MCP4821_4822_CHB_SUPPORTED != 1U))
    #error "AJ_MCP4821_4822_CHB_SUPPORTED must be 0U or 1U."
#endif

#if ((AJ_MCP4821_4822_SHDN_USED != 0U) && (AJ_MCP4821_4822_SHDN_USED != 1U))
    #error "AJ_MCP4821_4822_SHDN_USED must be 0U or 1U."
#endif


#endif
