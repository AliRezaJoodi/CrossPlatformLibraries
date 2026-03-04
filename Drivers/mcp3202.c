// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"       /**< Project-level overrides */
#include "mcp3202.h"

/********************************************************/
void MCP3202_Init(MCP3202_t *mcp){
    MCP3202_CS_InitPin(mcp);
    MCP3202_CS_WritePin(mcp, 1);    // Idle bus
}

/********************************************************/
uint16_t MCP3202_GetCounts(MCP3202_t *mcp, uint8_t ch){
    uint8_t data1 = 0x01U;
    uint8_t data2 = 0x00U;

    switch (ch){
        case MCP3202_CH0:
            data2 = write_2bit_u8(data2, 6, 0x02U);
            break;
        case MCP3202_CH1:
            data2 = write_2bit_u8(data2, 6, 0x03U);
            break;
        case MCP3202_CH0CH1:
            data2 = write_2bit_u8(data2, 6, 0x00U);
            break;
        case MCP3202_CH1CH0:
            data2 = write_2bit_u8(data2, 6, 0x01U);
            break;
        default:
            return 0xFFFF;
    }

    MCP3202_CS_WritePin(mcp, 0);
    MCP3202_SPI_Transfer(data1);
    data1 = MCP3202_SPI_Transfer(data2);    // Get MSB
    data2 = MCP3202_SPI_Transfer(0xFF);     // Get LSB
    MCP3202_CS_WritePin(mcp, 1);

    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
}
