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
#include <utility.h>
#include "mcp3202_port.h"

#ifndef MCP3202_HARDWARE
#define MCP3202_HARDWARE
    #define MCP3202_CS_DDR      DDRB.4
    #define MCP3202_CS_PORT     PORTB.4
    #define MCP3202_CS_PIN      PINB.4

    #define MCP3202_VREF        5000     //mv
#endif

void MCP3202_Config(void);
float MCP3202_GetSingleEndedADC(char ch);
float MCP3202_GetDifferentialADC(char ch);

#ifdef __cplusplus
}
#endif

#endif

