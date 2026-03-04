// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"       /**< Project-level overrides */
#include "mcp3204.h"

/********************************************************/
void MCP3204_Init(MCP3204_t *mcp){
    MCP3204_CS_InitPin(mcp);
    MCP3204_CS_WritePin(mcp, 1);    // Idle bus
}

/********************************************************/
uint16_t MCP3204_GetCounts(MCP3204_t *mcp, uint8_t ch){
    uint8_t data1 = 0x00U;
    uint8_t data2 = 0x00U;

    switch (ch){
        case MCP3204_CH0:
            data1 = 0x06U;
            data2 = 0x00U;
            break;
        case MCP3204_CH1:
            data1 = 0x06U;
            data2 = 0x40U;
            break;
        case MCP3204_CH2:
            data1 = 0x06U;
            data2 = 0x80U;
            break;
        case MCP3204_CH3:
            data1 = 0x06U;
            data2 = 0xC0U;
            break;
        case MCP3204_CH0CH1:
            data1 = 0x04U;
            data2 = 0x00U;
            break;
        case MCP3204_CH1CH0:
            data1 = 0x04U;
            data2 = 0x40U;
            break;
        case MCP3204_CH2CH3:
            data1 = 0x04U;
            data2 = 0x80U;
            break;
        case MCP3204_CH3CH2:
            data1 = 0x04U;
            data2 = 0xC0U;
            break;
        default:
            return 0xFFFF;
    }

    MCP3204_CS_WritePin(mcp, 0);
    MCP3204_SPI_Transfer(data1);
    data1 = MCP3204_SPI_Transfer(data2);    // Get MSB
    data2 = MCP3204_SPI_Transfer(0xFF);     // Get LSB
    MCP3204_CS_WritePin(mcp, 1);

    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
}
