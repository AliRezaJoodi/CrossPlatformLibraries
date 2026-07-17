#ifndef AJ_MCP3204_3208_TYPE_INCLUDED
#define AJ_MCP3204_3208_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_mcp3204_3208_config.h"
#include "aj_mcp3204_3208_type_platform.h"

//#define AJ_MCP3204_3208_CH0_          ((1U << 10U) | (1U << 9U) | (0U << 8U) | (0U << 7U) | (0U << 6U))

/**
 * MCP320x SPI command bits (MSB-first):
 *   Start Bit  : always 1
 *   SGL/DIFF   : 1 = single-ended, 0 = differential
 *   D2         : channel select bit 2
 *   D1         : channel select bit 1
 *   D0         : channel select bit 0
 */
typedef enum {
    AJ_MCP3204_3208_CH0     = ((1U << 4U) | (1U << 3U) | (0U << 2U) | (0U << 1U) | (0U << 0U)),   /**< CH0, GND(IN-) */
    AJ_MCP3204_3208_CH1     = ((1U << 4U) | (1U << 3U) | (0U << 2U) | (0U << 1U) | (1U << 0U)),   /**< CH1, GND(IN-) */
    AJ_MCP3204_3208_CH2     = ((1U << 4U) | (1U << 3U) | (0U << 2U) | (1U << 1U) | (0U << 0U)),   /**< CH2, GND(IN-) */
    AJ_MCP3204_3208_CH3     = ((1U << 4U) | (1U << 3U) | (0U << 2U) | (1U << 1U) | (1U << 0U)),   /**< CH3, GND(IN-) */

    #if (AJ_MCP3204_3208_CHANNELS == 8U)
        AJ_MCP3204_3208_CH4     = ((1U << 4U) | (1U << 3U) | (1U << 2U) | (0U << 1U) | (0U << 0U)),   /**< CH4, GND(IN-) */
        AJ_MCP3204_3208_CH5     = ((1U << 4U) | (1U << 3U) | (1U << 2U) | (0U << 1U) | (1U << 0U)),   /**< CH5, GND(IN-) */
        AJ_MCP3204_3208_CH6     = ((1U << 4U) | (1U << 3U) | (1U << 2U) | (1U << 1U) | (0U << 0U)),   /**< CH6, GND(IN-) */
        AJ_MCP3204_3208_CH7     = ((1U << 4U) | (1U << 3U) | (1U << 2U) | (1U << 1U) | (1U << 0U)),   /**< CH7, GND(IN-) */
    #endif

    AJ_MCP3204_3208_CH0CH1  = ((1U << 4U) | (0U << 3U) | (0U << 2U) | (0U << 1U) | (0U << 0U)),   /**< CH0(IN+), CH1(IN-) */
    AJ_MCP3204_3208_CH1CH0  = ((1U << 4U) | (0U << 3U) | (0U << 2U) | (0U << 1U) | (1U << 0U)),   /**< CH0(IN-), CH1(IN+) */
    AJ_MCP3204_3208_CH2CH3  = ((1U << 4U) | (0U << 3U) | (0U << 2U) | (1U << 1U) | (0U << 0U)),   /**< CH2(IN+), CH3(IN-) */
    AJ_MCP3204_3208_CH3CH2  = ((1U << 4U) | (0U << 3U) | (0U << 2U) | (1U << 1U) | (1U << 0U)),   /**< CH2(IN-), CH3(IN+) */

    #if (AJ_MCP3204_3208_CHANNELS == 8U)
        AJ_MCP3204_3208_CH4CH5  = ((1U << 4U) | (0U << 3U) | (1U << 2U) | (0U << 1U) | (0U << 0U)),   /**< CH4(IN+), CH5(IN-) */
        AJ_MCP3204_3208_CH5CH4  = ((1U << 4U) | (0U << 3U) | (1U << 2U) | (0U << 1U) | (1U << 0U)),   /**< CH4(IN-), CH5(IN+) */
        AJ_MCP3204_3208_CH6CH7  = ((1U << 4U) | (0U << 3U) | (1U << 2U) | (1U << 1U) | (0U << 0U)),   /**< CH6(IN+), CH7(IN-) */
        AJ_MCP3204_3208_CH7CH6  = ((1U << 4U) | (0U << 3U) | (1U << 2U) | (1U << 1U) | (1U << 0U))    /**< CH6(IN-), CH7(IN+) */
    #endif
} aj_mcp3204_3208_ch_t;

/**
 * @brief Defines MCP3204_3208 Channels.
 */
//typedef enum {
//    AJ_MCP3204_3208_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH2         = 2U,   /**< CH2(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH3         = 3U,   /**< CH3(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH4         = 4U,   /**< CH4(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH5         = 5U,   /**< CH5(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH6         = 6U,   /**< CH6(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH7         = 7U,   /**< CH7(IN+), GND(IN-)*/
//    AJ_MCP3204_3208_CH0CH1      = 8U,   /**< CH0(IN+), CH1(IN-)*/
//    AJ_MCP3204_3208_CH1CH0      = 9U,   /**< CH1(IN+), CH0(IN-)*/
//    AJ_MCP3204_3208_CH2CH3      = 10U,  /**< CH2(IN+), CH3(IN-)*/
//    AJ_MCP3204_3208_CH3CH2      = 11U,  /**< CH3(IN+), CH2(IN-)*/
//    AJ_MCP3204_3208_CH4CH5      = 12U,  /**< CH4(IN+), CH5(IN-)*/
//    AJ_MCP3204_3208_CH5CH4      = 13U,  /**< CH5(IN+), CH4(IN-)*/
//    AJ_MCP3204_3208_CH6CH7      = 14U,  /**< CH6(IN+), CH7(IN-)*/
//    AJ_MCP3204_3208_CH7CH6      = 15U   /**< CH7(IN+), CH6(IN-)*/
//} aj_mcp3204_3208_ch_t;

/**
 * @brief   MCP3204_3208 instance structure
 *
 * Contains all pins used by a single MCP3201 device.
 */
typedef struct {
    const aj_mcp3204_3208_pin_t cs;       /**< Chip Select pin */
} aj_mcp3204_3208_t;

/**
 * @example
 * Example: initializing a structure for AVR8
 *
 * @code
 *    static const aj_mcp3204_3208_t mcp1 = {
 *        .cs = {
 *            .ddr   = &AJ_MCP3204_3208_CS_DDR,
 *            .port  = &AJ_MCP3204_3208_CS_PORT,
 *            .mask = AJ_MCP3204_3208_CS_MASK
 *        }
 *    };
 * @endcode
 */


#ifdef __cplusplus
}
#endif

#endif
