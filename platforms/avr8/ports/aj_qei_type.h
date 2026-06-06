#ifndef AJ_QEI_TYPE_INCLUDED
#define AJ_QEI_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_qei_hw.h"

typedef struct {
    volatile uint8_t    *ddr;       /**< Data Direction Register */
    volatile uint8_t    *port;      /**< Port register */
    volatile uint8_t    *pin;       /**< Pin register */
    const uint8_t       pos;        /**< Pin position */
    const uint8_t       mask;
} aj_QEI_Pin_t;

typedef struct {
    const aj_QEI_Pin_t     chA;
    const aj_QEI_Pin_t     chB;

    #if (AJ_QEI_Z == 1U)
    const aj_QEI_Pin_t     chZ;
    #endif

    uint32_t            count;
    uint8_t             last;

    #if (AJ_QEI_Z == 1U)
    uint8_t             flag;
    #endif
} aj_QEI_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * aj_QEI_t qei = {
 *     .chA = {
 *         .ddr   = &AJ_QEI_A_DDR,
 *         .port  = &AJ_QEI_A_PORT,
 *         .pin   = &AJ_QEI_A_PIN,
 *         .index = AJ_QEI_A_POS,
 *         .mask  = AJ_QEI_A_MASK
 *     },
 *     .chB = {
 *         .ddr   = &AJ_QEI_B_DDR,
 *         .port  = &AJ_QEI_B_PORT,
 *         .pin   = &AJ_QEI_B_PIN,
 *         .index = AJ_QEI_B_POS,
 *         .mask  = AJ_QEI_B_MASK
 *     },
 *     .count = 0U,
 *     .last  = 0U
 * };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
