// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_mcp41xxx_type.h"
#include "aj_mcp41xxx_port.h"
#include "aj_mcp41xxx.h"

#define AJ_MCP41010_CMD_WRITE       0x11U
#define AJ_MCP41010_CMD_SHUTDOWN    0x21U

//*************************************************************
void AJ_MCP41xxx_Init(aj_mcp41xxx_t *mcp){
    AJ_MCP41xxx_CS_ConfigAsOutput(mcp);
    AJ_MCP41xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP41xxx_Write(aj_mcp41xxx_t *mcp, uint8_t count){
    AJ_MCP41xxx_CS_SetActive(mcp);
    AJ_MCP41XXX_DELAY_US(1);

    AJ_MCP41xxx_SPI_TxRx(AJ_MCP41010_CMD_WRITE);
    AJ_MCP41xxx_SPI_TxRx(count);

    AJ_MCP41XXX_DELAY_US(1);
    AJ_MCP41xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP41xxx_Shutdown(aj_mcp41xxx_t *mcp){
    AJ_MCP41xxx_CS_SetActive(mcp);
    AJ_MCP41XXX_DELAY_US(1);

    AJ_MCP41xxx_SPI_TxRx(AJ_MCP41010_CMD_SHUTDOWN);
    AJ_MCP41xxx_SPI_TxRx(0x00U);

    AJ_MCP41XXX_DELAY_US(1);
    AJ_MCP41xxx_CS_SetIdle(mcp);
}


