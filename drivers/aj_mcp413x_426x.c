// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_bit_u8.h"
#include "aj_mcp413x_426x_hw.h"
#include "aj_mcp413x_426x_type.h"
#include "aj_mcp413x_426x_port.h"
#include "aj_mcp413x_426x.h"

//#define AJ_MCP42XXX_CMD_WRITE_POT0      0x11U
//#define AJ_MCP42XXX_CMD_WRITE_POT1      0x12U
//#define AJ_MCP42XXX_CMD_WRITE_ALL       0x13U
//#define AJ_MCP42XXX_CMD_SHUTDOWN_POT0   0x21U
//#define AJ_MCP42XXX_CMD_SHUTDOWN_POT1   0x22U
//#define AJ_MCP42XXX_CMD_SHUTDOWN_ALL    0x23U

/* Command field (C1:C0) */
//#define AJ_MCP413X_426X_CMD_WRITE       0x00U
//#define AJ_MCP413X_426X_CMD_INCREMENT   0x01U
//#define AJ_MCP413X_426X_CMD_DECREMENT   0x02U
//#define AJ_MCP413X_426X_CMD_READ        0x03U

///* Memory addresses */
//#define AJ_MCP413X_426X_ADDR_WIPER0     0x00U
//#define AJ_MCP413X_426X_ADDR_WIPER1     0x01U
//#define AJ_MCP413X_426X_ADDR_TCON       0x04U
//#define AJ_MCP413X_426X_ADDR_STATUS     0x05U

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
void AJ_MCP413x_426x_Init(aj_mcp413x_426x_t *mcp){
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
void AJ_MCP413x_426x_WritePot0(aj_mcp413x_426x_t *mcp, uint8_t count){
    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_WIPER0 | AJ_MCP413X_426X_CMD_WRITE);
    AJ_MCP413x_426x_SPI_Tx(count);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

//*************************************************************
void AJ_MCP413x_426x_WritePot1(aj_mcp413x_426x_t *mcp, uint8_t count){
    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_WIPER1 | AJ_MCP413X_426X_CMD_WRITE);
    AJ_MCP413x_426x_SPI_Tx(count);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

static uint8_t ReadTerminalControl(aj_mcp413x_426x_t *mcp){
    uint8_t tcon;

    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_READ);
    tcon = AJ_MCP413x_426x_SPI_Rx();

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);

    return tcon;
}

static void WriteTerminalControl(aj_mcp413x_426x_t *mcp, uint8_t tcon){
    AJ_MCP413x_426x_CS_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);

    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_WRITE);
    AJ_MCP413x_426x_SPI_Tx(tcon);

    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

void AJ_MCP413x_426x_EnableTerminalControl(aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask){
    uint8_t tcon = ReadTerminalControl(mcp);

//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_READ);
//    tcon = AJ_MCP413x_426x_SPI_Rx();
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);

    tcon = AJ_BitU8_SetBit_Mask(tcon, (uint8_t)mask);

    WriteTerminalControl(mcp, tcon);
//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_WRITE);
//    AJ_MCP413x_426x_SPI_Tx(tcon);
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

void AJ_MCP413x_426x_DisableTerminalControl(aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask){
    uint8_t tcon = ReadTerminalControl(mcp);

//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_READ);
//    tcon = AJ_MCP413x_426x_SPI_Rx();
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);

    tcon = AJ_BitU8_ClearBit_Mask(tcon, (uint8_t)mask);

    WriteTerminalControl(mcp, tcon);

//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP413X_426X_ADDR_TCON | AJ_MCP413X_426X_CMD_WRITE);
//    AJ_MCP413x_426x_SPI_Tx(tcon);
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);
}

uint8_t AJ_MCP413x_426x_IsTerminalControlEnabled(aj_mcp413x_426x_t *mcp, aj_mcp413x_426x_tcon_t mask){
    uint8_t tcon = ReadTerminalControl(mcp);

    return AJ_BitU8_IsBitSet_Mask(tcon, (uint8_t)mask);
}

//*************************************************************
//void AJ_MCP413x_426x_ShutdownPot0(aj_mcp413x_426x_t *mcp){
//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP42XXX_CMD_SHUTDOWN_POT0);
//    AJ_MCP413x_426x_SPI_Tx(0x00U);
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);
//}

//*************************************************************
//void AJ_MCP413x_426x_ShutdownPot1(aj_mcp413x_426x_t *mcp){
//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP42XXX_CMD_SHUTDOWN_POT1);
//    AJ_MCP413x_426x_SPI_Tx(0x00U);
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);
//}

//*************************************************************
//void AJ_MCP413x_426x_ShutdownAll(aj_mcp413x_426x_t *mcp){
//    AJ_MCP413x_426x_CS_SetActive(mcp);
//    AJ_MCP413X_426X_DELAY_US(1);
//
//    AJ_MCP413x_426x_SPI_Tx(AJ_MCP42XXX_CMD_SHUTDOWN_ALL);
//    AJ_MCP413x_426x_SPI_Tx(0x00U);
//
//    AJ_MCP413X_426X_DELAY_US(1);
//    AJ_MCP413x_426x_CS_SetIdle(mcp);
//}

#if (AJ_MCP413X_426X_SHDN_USED == 1U)
void AJ_MCP413x_426x_ForceShutdown(aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_SHDN_SetActive(mcp);
}

void AJ_MCP413x_426x_ReleaseShutdown(aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_SHDN_SetIdle(mcp);
}
#endif

#if (AJ_MCP413X_426X_WP_USED == 1U)
void AJ_MCP413x_426x_HardwareReset(aj_mcp413x_426x_t *mcp){
    AJ_MCP413x_426x_WP_SetActive(mcp);
    AJ_MCP413X_426X_DELAY_US(1);
    AJ_MCP413x_426x_WP_SetIdle(mcp);
}
#endif





