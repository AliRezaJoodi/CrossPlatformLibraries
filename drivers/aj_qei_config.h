#ifndef AJ_QEI_CONFIG_INCLUDED
#define AJ_QEI_CONFIG_INCLUDED

#include "hardware.h"   /* Project-level overrides */

#ifndef AJ_QEI_CONFIG
#define AJ_QEI_CONFIG
    #define AJ_QEI_PULL_UP              0U  /**< Internal pull-up resistor (0: disabled, 1: enabled) */
    #define AJ_QEI_AB_CLOSED            0U  /**< Channels A and B are on adjacent bits of the same port (0: disabled, 1: enabled) */
    #define AJ_QEI_Z_USED               0U

    #warning "AJ_QEI_CONFIG is not defined; default configuration will be used."
#endif

/******************************************************************************/
/* Compile-time configuration validation and normalization                    */
/******************************************************************************/
#if ((AJ_QEI_PULL_UP != 0U) && (AJ_QEI_PULL_UP != 1U))
    #error "AJ_QEI_PULL_UP must be 0U or 1U."
#endif

#if ((AJ_QEI_AB_CLOSED != 0U) && (AJ_QEI_AB_CLOSED != 1U))
    #error "AJ_QEI_AB_CLOSED must be 0U or 1U."
#endif

#if ((AJ_QEI_Z_USED != 0U) && (AJ_QEI_Z_USED != 1U))
    #error "AJ_QEI_Z_USED must be 0U or 1U."
#endif


#endif
