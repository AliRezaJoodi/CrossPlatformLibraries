#ifndef AJ_MCP413X_426X_CONFIG_INCLUDED
#define AJ_MCP413X_426X_CONFIG_INCLUDED

#include "hardware.h"   /**< Project-level overrides */

/**
 * @brief   Default fallback configuration for the MCP413x/426x driver.
 * Override these definitions in hardware.h.
 */
#ifndef AJ_MCP413X_426X_CONFIG
#define AJ_MCP413X_426X_CONFIG
    #define AJ_MCP413X_426X_BITS            8U      /**< 7 or 8 bits resolution. */
    #define AJ_MCP413X_426X_P1_SUPPORTED    1U      /**< 0: Single channel, 1: Dual channel supported. */
    #define AJ_MCP413X_426X_P0A_SUPPORTED   1U      /**< 0: P0A not present/used, 1: Supported. */
    #define AJ_MCP413X_426X_P1A_SUPPORTED   1U      /**< 0: P1A not present/used, 1: Supported. */
    #define AJ_MCP413X_426X_SHDN_USED       1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCP413X_426X_WP_USED         1U      /**< 0: Not used, 1: Used. */

    #warning "AJ_MCP413X_426X_CONFIG is not defined; default configuration will be used."
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_MCP413X_426X_BITS != 7U) && (AJ_MCP413X_426X_BITS != 8U))
    #error "AJ_MCP413X_426X_BITS must be 7U or 8U."
#endif

#if ((AJ_MCP413X_426X_P1_SUPPORTED != 0U) && (AJ_MCP413X_426X_P1_SUPPORTED != 1U))
    #error "AJ_MCP413X_426X_P1_SUPPORTED must be 0U or 1U."
#endif

#if ((AJ_MCP413X_426X_P0A_SUPPORTED != 0U) && (AJ_MCP413X_426X_P0A_SUPPORTED != 1U))
    #error "AJ_MCP413X_426X_P0A_SUPPORTED must be 0U or 1U."
#endif

#if ((AJ_MCP413X_426X_P1A_SUPPORTED != 0U) && (AJ_MCP413X_426X_P1A_SUPPORTED != 1U))
    #error "AJ_MCP413X_426X_P1A_SUPPORTED must be 0U or 1U."
#endif

#if ((AJ_MCP413X_426X_SHDN_USED != 0U) && (AJ_MCP413X_426X_SHDN_USED != 1U))
    #error "AJ_MCP413X_426X_SHDN_USED must be 0U or 1U."
#endif

#if ((AJ_MCP413X_426X_WP_USED != 0U) && (AJ_MCP413X_426X_WP_USED != 1U))
    #error "AJ_MCP413X_426X_WP_USED must be 0U or 1U."
#endif

#if (AJ_MCP413X_426X_P1_SUPPORTED == 0U) && (AJ_MCP413X_426X_P1A_SUPPORTED == 1U)
    #undef AJ_MCP413X_426X_P1A_SUPPORTED
    #define AJ_MCP413X_426X_P1A_SUPPORTED 0U
    #warning "AJ_MCP413X_426X_P1A_SUPPORTED was forced to 0U because AJ_MCP413X_426X_P1_SUPPORTED is 0U."
#endif


#endif
