// GitHub Account: GitHub.com/AliRezaJoodi

#include "aj_mcp3202_type.h"
#include "aj_mcp3202_port.h"
#include "aj_mcp3202.h"

#define MCP3202_CMD_START       0x01U
#define MCP3202_CMD_CH0         ((1U << 7U) | (0U << 6U))
#define MCP3202_CMD_CH1         ((1U << 7U) | (1U << 6U))
#define MCP3202_CMD_CH0CH1      ((0U << 7U) | (0U << 6U))
#define MCP3202_CMD_CH1CH0      ((0U << 7U) | (1U << 6U))
#define MCP3202_CMD_DUMMY       0xFFU

/********************************************************/
void AJ_MCP3202_Init(aj_mcp3202_t *mcp){
    AJ_MCP3202_CS_ConfigAsOutput(mcp);
    AJ_MCP3202_CS_SetIdle(mcp);
}

/********************************************************/
uint16_t AJ_MCP3202_ReadRaw(aj_mcp3202_t *mcp, aj_mcp3202_channel_t ch){
    uint8_t data1 = 0x01U;
    uint8_t data2 = 0x00U;

    switch (ch){
        case AJ_MCP3202_CH0:
            data2 = MCP3202_CMD_CH0;
            break;
        case AJ_MCP3202_CH1:
            data2 = MCP3202_CMD_CH1;
            break;
        case AJ_MCP3202_CH0CH1:
            data2 = MCP3202_CMD_CH0CH1;
            break;
        case AJ_MCP3202_CH1CH0:
            data2 = MCP3202_CMD_CH1CH0;
            break;
        default:
            return 0xFFFF;
    }

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_SPI_TxRx(data1);
    data1 = AJ_MCP3202_SPI_TxRx(data2);                 // Get MSB
    data2 = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);     // Get LSB
    AJ_MCP3202_CS_SetIdle(mcp);

    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
}

uint16_t AJ_MCP3202_ReadRaw_Ch0(aj_mcp3202_t *mcp){
    uint8_t msb, lsb;

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_SPI_TxRx(MCP3202_CMD_START);
    msb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_CH0);
    lsb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);
    AJ_MCP3202_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x000FU) << 8U ) |
            (uint16_t)lsb
            );
}

uint16_t AJ_MCP3202_ReadRaw_Ch1(aj_mcp3202_t *mcp){
    uint8_t msb, lsb;

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_SPI_TxRx(MCP3202_CMD_START);
    msb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_CH1);
    lsb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);
    AJ_MCP3202_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x000FU) << 8U ) |
            (uint16_t)lsb
            );
}

uint16_t AJ_MCP3202_ReadRaw_Ch0Ch1(aj_mcp3202_t *mcp){
    uint8_t msb, lsb;

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_SPI_TxRx(MCP3202_CMD_START);
    msb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_CH0CH1);
    lsb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);
    AJ_MCP3202_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x000FU) << 8U ) |
            (uint16_t)lsb
            );
}

uint16_t AJ_MCP3202_ReadRaw_Ch1Ch0(aj_mcp3202_t *mcp){
    uint8_t msb, lsb;

    AJ_MCP3202_CS_SetActive(mcp);
    AJ_MCP3202_SPI_TxRx(MCP3202_CMD_START);
    msb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_CH1CH0);
    lsb = AJ_MCP3202_SPI_TxRx(MCP3202_CMD_DUMMY);
    AJ_MCP3202_CS_SetIdle(mcp);

    return  ((uint16_t)
            (((uint16_t)msb & 0x000FU) << 8U ) |
            (uint16_t)lsb
            );
}
