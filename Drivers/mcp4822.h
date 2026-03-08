// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <spi.h>
#include <utility.h>

#ifndef MCP4822_INCLUDED
#define MCP4822_INCLUDED

#include <stdint.h>
#include "mcp4822_port.h"

void MCP4822_Config(void);
void MCP4822_SetOutput(char ch, float volt);
void MCP4822_ShutDown(char ch);

void _MCP4822_WriteCommand(unsigned int data);

#endif

