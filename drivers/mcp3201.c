// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"   /**< Project-level overrides */
#include "mcp3201_port.h"
#include "drivers/mcp3201.h"

#define CS_IDLE                    1U
#define CS_ACTIVE                  0U

/*********************************************/
void MCP3201_Init(MCP3201_t *mcp){
    MCP3201_CS_SetOutput(mcp);
    MCP3201_CS_Write(mcp, CS_IDLE);
}

/*********************************************/
uint16_t MCP3201_GetCounts(MCP3201_t *mcp){
    uint16_t value = 0;
    uint8_t msb = 0, lsb = 0;

    MCP3201_CS_Write(mcp, CS_ACTIVE);
    msb = MCP3201_SPI_Transfer(0xFF);
    lsb = MCP3201_SPI_Transfer(0xFF);
    MCP3201_CS_Write(mcp, CS_IDLE);

    msb = msb & 0x1FU;
    lsb = lsb & 0xFEU;
    value = ((uint16_t)msb << 8U) | lsb;
    value = value >> 1U;

    return value;
}



