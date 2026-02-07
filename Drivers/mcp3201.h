// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef _MCP3201_INCLUDED
#define _MCP3201_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <mcp3201_hw.h>
#include <mcp3201_port.h>

void MCP3201_Config(MCP3201_t *mcp);
uint16_t MCP3201_GetCounts(MCP3201_t *mcp);
float MCP3201_GetMilliVolt(MCP3201_t *mcp);
float MCP3201_ConvertCountsToMilliVolt(uint16_t counts);

#ifdef __cplusplus
}
#endif

#endif

