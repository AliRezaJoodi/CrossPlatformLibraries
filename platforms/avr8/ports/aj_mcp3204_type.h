#ifndef AJ_MCP3204_TYPE_INCLUDED
#define AJ_MCP3204_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Defines MCP3204 Channels.
 */
typedef enum {
    AJ_MCP3204_CH0         = 0U,   /**< CH0(IN+), GND(IN-)*/
    AJ_MCP3204_CH1         = 1U,   /**< CH1(IN+), GND(IN-)*/
    AJ_MCP3204_CH2         = 2U,   /**< CH2(IN+), GND(IN-)*/
    AJ_MCP3204_CH3         = 3U,   /**< CH3(IN+), GND(IN-)*/
    AJ_MCP3204_CH0CH1      = 4U,   /**< CH0(IN+), CH1(IN-)*/
    AJ_MCP3204_CH1CH0      = 5U,   /**< CH1(IN+), CH0(IN-)*/
    AJ_MCP3204_CH2CH3      = 6U,   /**< CH2(IN+), CH3(IN-)*/
    AJ_MCP3204_CH3CH2      = 7U    /**< CH3(IN+), CH2(IN-)*/
} aj_MCP3204_Channel_t;

/**
 * @brief   GPIO representation for a single MCP3204 pin
 *
 * This struct maps a microcontroller pin for use by the MCP3204 driver.
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
} aj_MCP3204_Pin_t;

/**
 * @brief   MCP3204 instance structure
 *
 * Contains all pins used by a single MCP3201 device.
 */
typedef struct {
    const aj_MCP3204_Pin_t cs;       /**< Chip Select pin */
} aj_MCP3204_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 *    static const aj_MCP3204_t mcp1 = {
 *        .cs = {
 *            .ddr   = &AJ_MCP3204_CS_DDR,
 *            .port  = &AJ_MCP3204_CS_PORT,
 *            .mask = AJ_MCP3204_CS_MASK
 *        }
 *    };
 * @endcode
 */

#ifdef __cplusplus
}
#endif

#endif
