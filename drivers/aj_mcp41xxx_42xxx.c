// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_mcp41xxx_42xxx_config.h"
#include "aj_mcp41xxx_42xxx_type.h"
#include "aj_mcp41xxx_42xxx_port.h"
#include "aj_mcp41xxx_42xxx.h"

#define AJ_MCP41XXX_42XXX_CMD_WRITE         (0x01U << 4U)
#define AJ_MCP41XXX_42XXX_CMD_SHUTDOWN      (0x02U << 4U)

//*************************************************************
void AJ_MCP41xxx_42xxx_Init(aj_mcp41xxx_42xxx_t *mcp){
    AJ_MCP41xxx_42xxx_CS_ConfigAsOutput(mcp);
    AJ_MCP41xxx_42xxx_CS_SetIdle(mcp);

    #if (AJ_MCP41XXX_42XXX_SHDN_USED == 1U)
        AJ_MCP41xxx_42xxx_SHDN_ConfigAsOutput(mcp);
        AJ_MCP41xxx_42xxx_SHDN_SetIdle(mcp);
    #endif

    #if (AJ_MCP41XXX_42XXX_RS_USED == 1U)
        AJ_MCP41xxx_42xxx_RS_ConfigAsOutput(mcp);
        AJ_MCP41xxx_42xxx_RS_SetIdle(mcp);
    #endif
}

//*************************************************************
void AJ_MCP41xxx_42xxx_WriteCount(aj_mcp41xxx_42xxx_t *mcp, aj_mcp41xxx_42xxx_ch_t ch, uint8_t count){
    AJ_MCP41xxx_42xxx_CS_SetActive(mcp);
    AJ_MCP41XXX_42XXX_DELAY_US(1);

    AJ_MCP41xxx_42xxx_SPI_TxRx(AJ_MCP41XXX_42XXX_CMD_WRITE | (uint8_t)ch);
    AJ_MCP41xxx_42xxx_SPI_TxRx(count);

    AJ_MCP41XXX_42XXX_DELAY_US(1);
    AJ_MCP41xxx_42xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP41xxx_42xxx_Shutdown(aj_mcp41xxx_42xxx_t *mcp, aj_mcp41xxx_42xxx_ch_t ch){
    AJ_MCP41xxx_42xxx_CS_SetActive(mcp);
    AJ_MCP41XXX_42XXX_DELAY_US(1);

    AJ_MCP41xxx_42xxx_SPI_TxRx(AJ_MCP41XXX_42XXX_CMD_SHUTDOWN | (uint8_t)ch);
    AJ_MCP41xxx_42xxx_SPI_TxRx(0x00U);

    AJ_MCP41XXX_42XXX_DELAY_US(1);
    AJ_MCP41xxx_42xxx_CS_SetIdle(mcp);
}
