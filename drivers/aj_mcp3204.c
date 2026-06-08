// GitHub Account: GitHub.com/AliRezaJoodi

#include "aj_mcp3204_type.h"
#include "aj_mcp3204_port.h"
#include "aj_mcp3204.h"

/********************************************************/
void AJ_MCP3204_Init(aj_mcp3204_t *mcp){
    AJ_MCP3204_CS_ConfigAsOutput(mcp);
    AJ_MCP3204_CS_SetIdle(mcp);
}

/********************************************************/
uint16_t AJ_MCP3204_GetCounts(aj_mcp3204_t *mcp, aj_mcp3204_channel_t ch){
    uint8_t data1 = 0x00U;
    uint8_t data2 = 0x00U;

    switch (ch){
        case AJ_MCP3204_CH0:
            data1 = 0x06U;
            data2 = 0x00U;
            break;
        case AJ_MCP3204_CH1:
            data1 = 0x06U;
            data2 = 0x40U;
            break;
        case AJ_MCP3204_CH2:
            data1 = 0x06U;
            data2 = 0x80U;
            break;
        case AJ_MCP3204_CH3:
            data1 = 0x06U;
            data2 = 0xC0U;
            break;
        case AJ_MCP3204_CH0CH1:
            data1 = 0x04U;
            data2 = 0x00U;
            break;
        case AJ_MCP3204_CH1CH0:
            data1 = 0x04U;
            data2 = 0x40U;
            break;
        case AJ_MCP3204_CH2CH3:
            data1 = 0x04U;
            data2 = 0x80U;
            break;
        case AJ_MCP3204_CH3CH2:
            data1 = 0x04U;
            data2 = 0xC0U;
            break;
        default:
            return 0xFFFF;
    }

    AJ_MCP3204_CS_SetActive(mcp);
    AJ_MCP3204_SPI_Transfer(data1);
    data1 = AJ_MCP3204_SPI_Transfer(data2);    // Get MSB
    data2 = AJ_MCP3204_SPI_Transfer(0xFF);     // Get LSB
    AJ_MCP3204_CS_SetIdle(mcp);

    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
}
