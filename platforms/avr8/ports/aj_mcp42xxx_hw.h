#ifndef AJ_MCP42XXX_HW_INCLUDED
#define AJ_MCP42XXX_HW_INCLUDED

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
#ifndef AJ_MCP42XXX_HARDWARE
#define AJ_MCP42XXX_HARDWARE
    #define AJ_MCP42XXX_SUPPORT_PIN_SHDN    1U      /**< 0: Not used, 1: Used. */
    #define AJ_MCP42XXX_SUPPORT_PIN_RS      1U      /**< 0: Not used, 1: Used. */

    #warning "AJ_MCP42XXX_HARDWARE is not defined; default configuration will be used."
#endif

#ifndef AJ_MCP42XXX_HARDWARE_EXTRA
#define AJ_MCP42XXX_HARDWARE_EXTRA
    #define AJ_MCP42XXX_CS_DDR          DDRB
    #define AJ_MCP42XXX_CS_PORT         PORTB
    #define AJ_MCP42XXX_CS_POS          4U
    #define AJ_MCP42XXX_CS_MASK         (1U << AJ_MCP42XXX_CS_POS)

    #if (AJ_MCP42XXX_SUPPORT_PIN_SHDN == 1U)
        #define AJ_MCP42XXX_SHDN_DDR        DDRB
        #define AJ_MCP42XXX_SHDN_PORT       PORTB
        #define AJ_MCP42XXX_SHDN_POS        3U
        #define AJ_MCP42XXX_SHDN_MASK       (1U << AJ_MCP42XXX_SHDN_POS)
    #endif

    #if (AJ_MCP42XXX_SUPPORT_PIN_RS == 1U)
        #define AJ_MCP42XXX_RS_DDR          DDRB
        #define AJ_MCP42XXX_RS_PORT         PORTB
        #define AJ_MCP42XXX_RS_POS          2U
        #define AJ_MCP42XXX_RS_MASK         (1U << AJ_MCP42XXX_RS_POS)
    #endif
#endif

#endif
