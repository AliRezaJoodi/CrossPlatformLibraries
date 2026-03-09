// GitHub Account: GitHub.com/AliRezaJoodi
// This library use of the SPI interfacing
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First

#include <utility.h>

#ifndef MCP4822_INCLUDED
#define MCP4822_INCLUDED

#include <stdint.h>
#include "mcp4822_port.h"

#define MCP4822_OUTPUT_A    0U
#define MCP4822_OUTPUT_B    1U

#define MCP4822_GAIN_1X     1U
#define MCP4822_GAIN_2X     0U

void MCP4822_SetOutput_(char ch, float volt);
void MCP4822_ShutDown(char ch);
void _MCP4822_WriteCommand(unsigned int data);

void MCP4822_Init(void);
void MCP4822_SetOutput(uint8_t ch, uint8_t gain, uint16_t data);

#endif

