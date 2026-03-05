// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"       /**< Project-level overrides */
#include "mcp3208.h"

/********************************************************/
void MCP3208_Init(MCP3208_t *mcp){
    MCP3208_CS_InitPin(mcp);
    MCP3208_CS_WritePin(mcp, 1);    // Idle bus
}

/********************************************************/
uint16_t MCP3208_GetCounts(MCP3208_t *mcp, uint8_t ch){
    uint8_t data1 = 0x00U;
    uint8_t data2 = 0x00U;

    switch (ch){
        case MCP3208_CH0:
            data1 = 0x06U;
            data2 = 0x00U;
            break;
        case MCP3208_CH1:
            data1 = 0x06U;
            data2 = 0x40U;
            break;
        case MCP3208_CH2:
            data1 = 0x06U;
            data2 = 0x80U;
            break;
        case MCP3208_CH3:
            data1 = 0x06U;
            data2 = 0xC0U;
            break;
        case MCP3208_CH4:
            data1 = 0x07U;
            data2 = 0x00U;
            break;
        case MCP3208_CH5:
            data1 = 0x07U;
            data2 = 0x40U;
            break;
        case MCP3208_CH6:
            data1 = 0x07U;
            data2 = 0x80U;
            break;
        case MCP3208_CH7:
            data1 = 0x07U;
            data2 = 0xC0U;
            break;
        case MCP3208_CH0CH1:
            data1 = 0x04U;
            data2 = 0x00U;
            break;
        case MCP3208_CH1CH0:
            data1 = 0x04U;
            data2 = 0x40U;
            break;
        case MCP3208_CH2CH3:
            data1 = 0x04U;
            data2 = 0x80U;
            break;
        case MCP3208_CH3CH2:
            data1 = 0x04U;
            data2 = 0xC0U;
            break;
        case MCP3208_CH4CH5:
            data1 = 0x05U;
            data2 = 0x00U;
            break;
        case MCP3208_CH5CH4:
            data1 = 0x05U;
            data2 = 0x40U;
            break;
        case MCP3208_CH6CH7:
            data1 = 0x05U;
            data2 = 0x80U;
            break;
        case MCP3208_CH7CH6:
            data1 = 0x05U;
            data2 = 0xC0U;
            break;
        default:
            return 0xFFFF;
    }

    MCP3208_CS_WritePin(mcp, 0);
    MCP3208_SPI_Transfer(data1);
    data1 = MCP3208_SPI_Transfer(data2);    // Get MSB
    data2 = MCP3208_SPI_Transfer(0xFF);     // Get LSB
    MCP3208_CS_WritePin(mcp, 1);

    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
}
