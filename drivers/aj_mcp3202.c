// GitHub Account: GitHub.com/AliRezaJoodi

#include "aj_mcp3202_type.h"
#include "aj_mcp3202_port.h"
#include "aj_mcp3202.h"

#define MCP3202_CMD_CH0         ((1U << 7U) | (0U << 6U))     /**< CH0(IN+), GND(IN-)*/
#define MCP3202_CMD_CH1         ((1U << 7U) | (1U << 6U))     /**< CH1(IN+), GND(IN-)*/
#define MCP3202_CMD_CH0CH1      ((0U << 7U) | (0U << 6U))     /**< CH0(IN+), CH1(IN-)*/
#define MCP3202_CMD_CH1CH0      ((0U << 7U) | (1U << 6U))     /**< CH1(IN+), CH0(IN-)*/

#define MCP3202_CMD_START       0x01U
#define MCP3202_CMD_DUMMY       0xFFU

/********************************************************/
void AJ_MCP3202_Init(aj_mcp3202_t *mcp){
    AJ_MCP3202_CS_ConfigAsOutput(mcp);
    AJ_MCP3202_CS_SetIdle(mcp);
}

/********************************************************/
static uint16_t AJ_MCP3202_ReadRaw(aj_mcp3202_t *mcp, uint8_t ch){
    uint8_t msb, lsb;

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_DELAY_US(1);

    AJ_MCP3202_SPI_TxRx(MCP3202_CMD_START);
    msb = AJ_MCP3202_SPI_TxRx(ch);
    lsb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);

    AJ_MCP3202_DELAY_US(1);
    AJ_MCP3202_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x000FU) << 8U ) |
            (uint16_t)lsb
            );
}

uint16_t AJ_MCP3202_ReadRaw_Ch0(aj_mcp3202_t *mcp){
    return AJ_MCP3202_ReadRaw(mcp, MCP3202_CMD_CH0);
}

uint16_t AJ_MCP3202_ReadRaw_Ch1(aj_mcp3202_t *mcp){
    return AJ_MCP3202_ReadRaw(mcp, MCP3202_CMD_CH1);
}

uint16_t AJ_MCP3202_ReadRaw_Ch0Ch1(aj_mcp3202_t *mcp){
    return AJ_MCP3202_ReadRaw(mcp, MCP3202_CMD_CH0CH1);
}

uint16_t AJ_MCP3202_ReadRaw_Ch1Ch0(aj_mcp3202_t *mcp){
    return AJ_MCP3202_ReadRaw(mcp, MCP3202_CMD_CH1CH0);
}