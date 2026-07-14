// GitHub Account: GitHub.com/AliRezaJoodi

#include "aj_mcp3202_type.h"
#include "aj_mcp3202_port.h"
#include "aj_mcp3202.h"

#define MCP3202_CMD_START       0x01U
#define MCP3202_CMD_DUMMY       0xFFU

/********************************************************/
void AJ_MCP3202_Init(aj_mcp3202_t *mcp){
    AJ_MCP3202_CS_ConfigAsOutput(mcp);
    AJ_MCP3202_CS_SetIdle(mcp);
}

/********************************************************/
uint16_t AJ_MCP3202_ReadRaw(aj_mcp3202_t *mcp, aj_mcp3202_channel_t channel){
    uint8_t msb, lsb;

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_SPI_TxRx(MCP3202_CMD_START);
    msb = AJ_MCP3202_SPI_TxRx(channel);
    lsb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);
    AJ_MCP3202_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x000FU) << 8U ) |
            (uint16_t)lsb
            );
}