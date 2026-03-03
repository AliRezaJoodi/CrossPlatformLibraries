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

#define MCP3202_CH0         0U
#define MCP3202_CH1         1U
#define MCP3202_CH0CH1      2U
#define MCP3202_CH1CH0      3U

void MCP3202_Init(MCP3202_t *mcp);
float MCP3202_GetSingleEndedADC(MCP3202_t *mcp, char ch);
float MCP3202_GetDifferentialADC(MCP3202_t *mcp, char ch);

#ifdef __cplusplus
}
#endif

#endif

