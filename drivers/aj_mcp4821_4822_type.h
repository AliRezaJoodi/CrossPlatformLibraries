#ifndef AJ_MCP4821_4822_TYPE_INCLUDED
#define AJ_MCP4821_4822_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp4821_4822_config.h"
#include "aj_mcp4821_4822_type_platform.h"

typedef enum {
    AJ_MCP4821_4822_CH_A = 0U,

    #if (AJ_MCP4821_4822_CHB_SUPPORTED == 1U)
        AJ_MCP4821_4822_CH_B = 1U
    #endif
} aj_mcp4821_4822_ch_t;

typedef enum {
    AJ_MCP4821_4822_FS_4V096 = 0U,   /**< Full-Scale: 4.096V */
    AJ_MCP4821_4822_FS_2V048 = 1U    /**< Full-Scale: 2.048V */
} aj_mcp4821_4822_scale_t;

/**
 * @brief   MCP4821_4822 device handle
 *
 * Represents a single MCP4821_4822 device with its control pins.
 * Contains CS and LDAC pin descriptors.
 *
 * @see Example section above
 */
typedef struct {
    const aj_mcp4821_4822_pin_t cs;
    const aj_mcp4821_4822_pin_t ldac;

    #if (AJ_MCP4821_4822_SHDN_USED == 1U)
        const aj_mcp4821_4822_pin_t shdn;
    #endif
} aj_mcp4821_4822_t;

/**
 * @example
 * Example: initializing a structure for AVR8
 *
 * @code
 *    static const aj_MCP4821_4822_t dac1 = {
 *        .cs = {
 *            .ddr   = &AJ_MCP4821_4822_CS_DDR,
 *            .port  = &AJ_MCP4821_4822_CS_PORT,
 *            .mask  =  AJ_MCP4821_4822_CS_MASK
 *        },
 *        .ldac = {
 *            .ddr   = &AJ_MCP4821_4822_LDAC_DDR,
 *            .port  = &AJ_MCP4821_4822_LDAC_PORT,
 *            .mask  =  AJ_MCP4821_4822_LDAC_MASK
 *        }
 *    };
 * @endcode
 */


#ifdef __cplusplus
}
#endif

#endif
