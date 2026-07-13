#ifndef AJ_QEI_TYPE_INCLUDED
#define AJ_QEI_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_qei_config.h"
#include "aj_qei_type_platform.h"

typedef struct {
    const aj_qei_pin_t     chA;
    const aj_qei_pin_t     chB;

    #if (AJ_QEI_Z_USED == 1U)
    const aj_qei_pin_t     chZ;
    #endif

    uint32_t            count;
    uint8_t             last;

    #if (AJ_QEI_Z_USED == 1U)
    uint8_t             flag;
    #endif
} aj_qei_t;

/**
 * @example
 * Example: initializing a structure for AVR8
 *
 * @code
 * aj_qei_t qei = {
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
