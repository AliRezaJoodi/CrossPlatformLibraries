#ifndef AJ_TARGET_INCLUDED
#define AJ_TARGET_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"

#ifndef AJ_TARGET_CONFIG
#define AJ_TARGET_CONFIG
    #define AJ_TARGET_MCU_BITS          32U      /*!< Supported: 8, 16, 32 */
    #define AJ_TARGET_TICK_BITS         32U      /*!< Supported: 8, 16, 32 */

    #warning "AJ_TARGET_CONFIG is not defined; default configuration will be used."
#endif

#if (AJ_TARGET_MCU_BITS != 8U)  && \
    (AJ_TARGET_MCU_BITS != 16U) && \
    (AJ_TARGET_MCU_BITS != 32U)

    #error "AJ_TARGET_MCU_BITS must be 8U, 16U, or 32U."
#endif

#if (AJ_TARGET_TICK_BITS != 8U)  && \
    (AJ_TARGET_TICK_BITS != 16U) && \
    (AJ_TARGET_TICK_BITS != 32U)

    #error "AJ_TARGET_TICK_BITS must be 8U, 16U, or 32U."
#endif


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TARGET_INCLUDED */