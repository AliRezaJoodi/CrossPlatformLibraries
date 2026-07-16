// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_bit_u8.h"
#include "aj_mcp413x_426x_config.h"
#include "aj_mcp413x_426x_type.h"
#include "aj_mcp413x_426x_port.h"
#include "aj_mcp413x_426x.h"

/* Address field (AD3:AD0) - Shifted by 4 bits */
#define AJ_MCP413X_426X_ADDR_WIPER0     (0x00U << 4)
#define AJ_MCP413X_426X_ADDR_WIPER1     (0x01U << 4)
#define AJ_MCP413X_426X_ADDR_TCON       (0x04U << 4)
#define AJ_MCP413X_426X_ADDR_STATUS     (0x05U << 4)

/* Command field (C1:C0) - Shifted by 2 bits */
#define AJ_MCP413X_426X_CMD_WRITE       (0x00U << 2)
#define AJ_MCP413X_426X_CMD_INCREMENT   (0x01U << 2)
#define AJ_MCP413X_426X_CMD_DECREMENT   (0x02U << 2)
#define AJ_MCP413X_426X_CMD_READ        (0x03U << 2)

//*************************************************************
void AJ_MCP413x_426x_Init(const aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_CS_ConfigAsOutput(mcp);
    AJ_MCP413x_426x_CS_SetIdle(mcp);

    #if (AJ_MCP413X_426X_SHDN_USED == 1U)
        AJ_MCP413x_426x_SHDN_ConfigAsOutput(mcp);
        AJ_MCP413x_426x_SHDN_SetIdle(mcp);
    #endif

    #if (AJ_MCP413X_426X_WP_USED == 1U)
        AJ_MCP413x_426x_WP_ConfigAsOutput(mcp);
        AJ_MCP413x_426x_WP_SetIdle(mcp);
    #endif
}

//*************************************************************
void AJ_MCP413x_426x_WriteCount_Pot0(const aj_mcp413x_426x_t *mcp, uint8_t count){
    #if (AJ_MCP413X_426X_BITS == 7U)
    if(count > 127U){
        count = 127U;
    }
    #endif

    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_TxRx(AJ_MCP413X_426X_ADDR_WIPER0 | AJ_MCP413X_426X_CMD_WRITE);
    AJ_MCP413x_426x_SPI_TxRx(count);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

#if (AJ_MCP413X_426X_P1_SUPPORTED == 1U)
void AJ_MCP413x_426x_WriteCount_Pot1(const aj_mcp413x_426x_t *mcp, uint8_t count){
    #if (AJ_MCP413X_426X_BITS == 7U)
    if(count > 127U){
        count = 127U;
    }
    #endif

    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_TxRx(AJ_MCP413X_426X_ADDR_WIPER1 | AJ_MCP413X_426X_CMD_WRITE);
    AJ_MCP413x_426x_SPI_TxRx(count);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);
}
#endif

//*************************************************************
static uint8_t ReadTerminalControl(const aj_mcp413x_426x_t *mcp){
    uint8_t tcon;

    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_TxRx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_READ);
    tcon = AJ_MCP413x_426x_SPI_TxRx(0x00U);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);

    return tcon;
}

static void WriteTerminalControl(const aj_mcp413x_426x_t *mcp, uint8_t tcon){
    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_TxRx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_WRITE);
    AJ_MCP413x_426x_SPI_TxRx(tcon);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP413x_426x_EnableTerminalControl(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_terminal_t mask){
    uint8_t tcon = ReadTerminalControl(mcp);

    tcon = AJ_BitU8_SetBit_Mask(tcon, (uint8_t)mask);
    WriteTerminalControl(mcp, tcon);
}

void AJ_MCP413x_426x_DisableTerminalControl(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_terminal_t mask){
    uint8_t tcon = ReadTerminalControl(mcp);

    tcon = AJ_BitU8_ClearBit_Mask(tcon, (uint8_t)mask);
    WriteTerminalControl(mcp, tcon);
}

uint8_t AJ_MCP413x_426x_IsTerminalControlEnabled(const aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_terminal_t mask){
    uint8_t tcon = ReadTerminalControl(mcp);

    return AJ_BitU8_IsBitSet_Mask(tcon, (uint8_t)mask);
}

//*************************************************************
#if (AJ_MCP413X_426X_SHDN_USED == 1U)
void AJ_MCP413x_426x_ForceShutdown(const aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_SHDN_SetActive(mcp);
}

void AJ_MCP413x_426x_ReleaseShutdown(const aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_SHDN_SetIdle(mcp);
}
#endif

//*************************************************************
#if (AJ_MCP413X_426X_WP_USED == 1U)
void AJ_MCP413x_426x_EnableWriteProtect(const aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_WP_SetActive(mcp);
}

void AJ_MCP413x_426x_DisableWriteProtect(const aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_WP_SetIdle(mcp);
}
#endif






