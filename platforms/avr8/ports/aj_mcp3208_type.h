#ifndef AJ_MCP3208_TYPE_INCLUDED
#define AJ_MCP3208_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Defines MCP3208 Channels.
 */
typedef enum {
    AJ_MCP3208_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    AJ_MCP3208_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    AJ_MCP3208_CH2         = 2U,   /**< CH2(IN+), GND(IN-)*/
    AJ_MCP3208_CH3         = 3U,   /**< CH3(IN+), GND(IN-)*/
    AJ_MCP3208_CH4         = 4U,   /**< CH4(IN+), GND(IN-)*/
    AJ_MCP3208_CH5         = 5U,   /**< CH5(IN+), GND(IN-)*/
    AJ_MCP3208_CH6         = 6U,   /**< CH6(IN+), GND(IN-)*/
    AJ_MCP3208_CH7         = 7U,   /**< CH7(IN+), GND(IN-)*/
    AJ_MCP3208_CH0CH1      = 8U,   /**< CH0(IN+), CH1(IN-)*/
    AJ_MCP3208_CH1CH0      = 9U,   /**< CH1(IN+), CH0(IN-)*/
    AJ_MCP3208_CH2CH3      = 10U,  /**< CH2(IN+), CH3(IN-)*/
    AJ_MCP3208_CH3CH2      = 11U,  /**< CH3(IN+), CH2(IN-)*/
    AJ_MCP3208_CH4CH5      = 12U,  /**< CH4(IN+), CH5(IN-)*/
    AJ_MCP3208_CH5CH4      = 13U,  /**< CH5(IN+), CH4(IN-)*/
    AJ_MCP3208_CH6CH7      = 14U,  /**< CH6(IN+), CH7(IN-)*/
    AJ_MCP3208_CH7CH6      = 15U   /**< CH7(IN+), CH6(IN-)*/
} aj_mcp3208_channel_t;

/**
 * @brief   GPIO representation for a single MCP3208 pin
 *
 * This struct maps a microcontroller pin for use by the MCP3208 driver.
 * It contains pointers to the DDR and PORT registers, and the bit index
 * of the pin within those registers.
 *
 * @note    All pointers must point to valid registers before use.
 */
typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    //const uint8_t     index;    /**< Bit position within DDR/PORT (0..7) */
    const uint8_t     mask;
} aj_mcp3208_pin_t;

/**
 * @brief   MCP3208 instance structure
 *
 * Contains all pins used by a single MCP3201 device.
 */
typedef struct {
    const aj_mcp3208_pin_t cs;       /**< Chip Select pin */
} aj_mcp3208_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    static const aj_mcp3208_t mcp1 = {
 *        .cs = {
 *            .ddr   = &AJ_MCP3208_CS_DDR,
 *            .port  = &AJ_MCP3208_CS_PORT,
 *            .mask = AJ_MCP3208_CS_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
