#ifndef AJ_MCP41XXX_42XXX_CONFIG_INCLUDED
#define AJ_MCP41XXX_42XXX_CONFIG_INCLUDED


#include "hardware.h"   /**< Project-level overrides */

/*
 * Optional hardware control pins.
 *
 * Set the related support macro to 1U if the pin is controlled by this driver.
 * Set it to 0U if the pin is not controlled by this driver.
 *
 * Note:
 * SHDN and RS are active-low pins. If support for either pin is disabled,
 * the corresponding physical pin must be kept at the inactive high level
 * and must not be left floating. Use an external pull-up resistor when the
 * pin is not driven by the MCU.
 */
#ifndef AJ_MCP41XXX_42XXX_CONFIG
#define AJ_MCP41XXX_42XXX_CONFIG
    #define AJ_MCP41XXX_42XXX_POT1_SUPPORTED    1U      /**< 0: Single channel, 1: Dual channel supported. */
    #define AJ_MCP41XXX_42XXX_SHDN_USED         1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCP41XXX_42XXX_RS_USED           1U      /**< 0: Not used, 1: Used. */

    #warning "AJ_MCP41XXX_42XXX_CONFIG is not defined; default configuration will be used."
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_MCP41XXX_42XXX_POT1_SUPPORTED != 0U) && (AJ_MCP41XXX_42XXX_POT1_SUPPORTED != 1U))
    #error "AJ_MCP41XXX_42XXX_POT1_SUPPORTED must be 0U or 1U."
#endif

#if ((AJ_MCP41XXX_42XXX_SHDN_USED != 0U) && (AJ_MCP41XXX_42XXX_SHDN_USED != 1U))
    #error "AJ_MCP41XXX_42XXX_SHDN_USED must be 0U or 1U."
#endif

#if ((AJ_MCP41XXX_42XXX_RS_USED != 0U) && (AJ_MCP41XXX_42XXX_RS_USED != 1U))
    #error "AJ_MCP41XXX_42XXX_RS_USED must be 0U or 1U."
#endif

#if ((AJ_MCP41XXX_42XXX_POT1_SUPPORTED == 0U) && \
     (AJ_MCP41XXX_42XXX_SHDN_USED != 0U))
    #error "When AJ_MCP41XXX_42XXX_POT1_SUPPORTED is 0U, AJ_MCP41XXX_42XXX_SHDN_USED must also be 0U."
#endif

#if ((AJ_MCP41XXX_42XXX_POT1_SUPPORTED == 0U) && \
     (AJ_MCP41XXX_42XXX_RS_USED != 0U))
    #error "When AJ_MCP41XXX_42XXX_POT1_SUPPORTED is 0U, AJ_MCP41XXX_42XXX_RS_USED must also be 0U."
#endif


#endif
