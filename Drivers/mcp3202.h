// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef MCP3202_INCLUDED
#define MCP3202_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <spi.h>
#include "utility_bit.h"
#include "mcp3202_port.h"

#define MCP3202_CH0         0U  /**< CH0(IN+), GND(IN-)*/
#define MCP3202_CH1         1U  /**< CH1(IN+), GND(IN-)*/
#define MCP3202_CH0CH1      2U  /**< CH0(IN+), CH1(IN-)*/
#define MCP3202_CH1CH0      3U  /**< CH1(IN+), CH0(IN-)*/

void MCP3202_Init(MCP3202_t *mcp);
uint16_t MCP3202_GetCounts(MCP3202_t *mcp, uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif

