// GitHub Account: GitHub.com/AliRezaJoodi

#include "aj_mcp3201_type.h"
#include "aj_mcp3201_port.h"
#include "aj_mcp3201.h"

#define MCP3201_CMD_DUMMY       0xFFU

/*********************************************/
void AJ_MCP3201_Init(aj_mcp3201_t *mcp){
    AJ_MCP3201_CS_ConfigAsOutput(mcp);
    AJ_MCP3201_CS_SetIdle(mcp);
}

/*********************************************/
uint16_t AJ_MCP3201_ReadRaw(aj_mcp3201_t *mcp){
    uint8_t msb, lsb;

    AJ_MCP3201_CS_SetActive(mcp);
    AJ_MCP3201_DELAY_US(1);

    msb = AJ_MCP3201_SPI_TxRx(MCP3201_CMD_DUMMY);
    lsb = AJ_MCP3201_SPI_TxRx(MCP3201_CMD_DUMMY);

    AJ_MCP3201_DELAY_US(1);
    AJ_MCP3201_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x001FU) << 7U) |
            ((uint16_t)lsb >> 1U)
            );
}



