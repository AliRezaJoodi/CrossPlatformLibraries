// GitHub Account: GitHub.com/AliRezaJoodi

#include "mcp3202_port.h"
#include "mcp3202.h"

//#define CS_IDLE                    1U
//#define CS_ACTIVE                  0U

/********************************************************/
void MCP3202_Init(MCP3202_t *mcp){
    MCP3202_CS_ConfigAsOutput(mcp);
    //MCP3202_CS_Write(mcp, CS_IDLE);
    MCP3202_CS_SetIdle(mcp);
}

/********************************************************/
uint16_t MCP3202_GetCounts(MCP3202_t *mcp, MCP3202_Channel_t ch){
    uint8_t data1 = 0x01U;
    uint8_t data2 = 0x00U;

    switch (ch){
        case MCP3202_CH0:
            data2 = 0x80U;
            break;
        case MCP3202_CH1:
            data2 = 0xC0U;
            break;
        case MCP3202_CH0CH1:
            data2 = 0x00U;
            break;
        case MCP3202_CH1CH0:
            data2 = 0x40U;
            break;
        default:
            return 0xFFFF;
    }

    //MCP3202_CS_Write(mcp, CS_ACTIVE);
    MCP3202_CS_SetActive(mcp);
    MCP3202_SPI_Transfer(data1);
    data1 = MCP3202_SPI_Transfer(data2);    // Get MSB
    data2 = MCP3202_SPI_Transfer(0xFF);     // Get LSB
    //MCP3202_CS_Write(mcp, CS_IDLE);
    MCP3202_CS_SetIdle(mcp);

    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
}
