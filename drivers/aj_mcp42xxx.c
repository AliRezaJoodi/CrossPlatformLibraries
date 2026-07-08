// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_mcp42xxx_hw.h"
#include "aj_mcp42xxx_type.h"
#include "aj_mcp42xxx_port.h"
#include "aj_mcp42xxx.h"

#define AJ_MCP42XXX_CMD_WRITE_POT0      0x11U
#define AJ_MCP42XXX_CMD_WRITE_POT1      0x12U
#define AJ_MCP42XXX_CMD_WRITE_ALL       0x13U
#define AJ_MCP42XXX_CMD_SHUTDOWN_POT0   0x21U
#define AJ_MCP42XXX_CMD_SHUTDOWN_POT1   0x22U
#define AJ_MCP42XXX_CMD_SHUTDOWN_ALL    0x23U

//*************************************************************
void AJ_MCP42xxx_Init(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_CS_ConfigAsOutput(mcp);
    AJ_MCP42xxx_CS_SetIdle(mcp);

    #if (AJ_MCP42XXX_SHDN_USED == 1U)
        AJ_MCP42xxx_SHDN_ConfigAsOutput(mcp);
        AJ_MCP42xxx_SHDN_SetIdle(mcp);
    #endif

    #if (AJ_MCP42XXX_RS_USED == 1U)
        AJ_MCP42xxx_RS_ConfigAsOutput(mcp);
        AJ_MCP42xxx_RS_SetIdle(mcp);
    #endif
}

//*************************************************************
void AJ_MCP42xxx_WritePot0(aj_mcp42xxx_t *mcp, uint8_t count){
    AJ_MCP42xxx_CS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);

    AJ_MCP42xxx_SPI_TxRx(AJ_MCP42XXX_CMD_WRITE_POT0);
    AJ_MCP42xxx_SPI_TxRx(count);

    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP42xxx_WritePot1(aj_mcp42xxx_t *mcp, uint8_t count){
    AJ_MCP42xxx_CS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);

    AJ_MCP42xxx_SPI_TxRx(AJ_MCP42XXX_CMD_WRITE_POT1);
    AJ_MCP42xxx_SPI_TxRx(count);

    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP42xxx_WriteAll(aj_mcp42xxx_t *mcp, uint8_t count){
    AJ_MCP42xxx_CS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);

    AJ_MCP42xxx_SPI_TxRx(AJ_MCP42XXX_CMD_WRITE_ALL);
    AJ_MCP42xxx_SPI_TxRx(count);

    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP42xxx_ShutdownPot0(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_CS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);

    AJ_MCP42xxx_SPI_TxRx(AJ_MCP42XXX_CMD_SHUTDOWN_POT0);
    AJ_MCP42xxx_SPI_TxRx(0x00U);

    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP42xxx_ShutdownPot1(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_CS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);

    AJ_MCP42xxx_SPI_TxRx(AJ_MCP42XXX_CMD_SHUTDOWN_POT1);
    AJ_MCP42xxx_SPI_TxRx(0x00U);

    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP42xxx_ShutdownAll(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_CS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);

    AJ_MCP42xxx_SPI_TxRx(AJ_MCP42XXX_CMD_SHUTDOWN_ALL);
    AJ_MCP42xxx_SPI_TxRx(0x00U);

    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_CS_SetIdle(mcp);
}

#if (AJ_MCP42XXX_SHDN_USED == 1U)
void AJ_MCP42xxx_ForceShutdown(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_SHDN_SetActive(mcp);
}

void AJ_MCP42xxx_ReleaseShutdown(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_SHDN_SetIdle(mcp);
}
#endif

#if (AJ_MCP42XXX_RS_USED == 1U)
void AJ_MCP42xxx_HardwareReset(aj_mcp42xxx_t *mcp){
    AJ_MCP42xxx_RS_SetActive(mcp);
    AJ_MCP42XXX_DELAY_US(1);
    AJ_MCP42xxx_RS_SetIdle(mcp);
}
#endif





