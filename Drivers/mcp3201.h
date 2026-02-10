// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#ifndef MCP3201_INCLUDED
#define MCP3201_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define MCP3201_PIN_INPUT       0U
#define MCP3201_PIN_OUTPUT      1U

#include <mcp3201_port.h>
#include <mcp3201_config.h>

void MCP3201_Config(MCP3201_t *mcp);
uint16_t MCP3201_GetCounts(MCP3201_t *mcp);
float MCP3201_GetMilliVolt(MCP3201_t *mcp);
float MCP3201_ConvertCountsToMilliVolt(uint16_t counts);

#ifdef __cplusplus
}
#endif

#endif

