// GitHub Account: GitHub.com/AliRezaJoodi

#include "hardware.h"       /**< Project-level overrides */
#include "mcp3202.h"

#define _MCP3202_RESOLUTION     4096     //12-Bit
#define _MCP3202_GAIN           MCP3202_VREF/_MCP3202_RESOLUTION

#define _SINGLE_CHANNEL         1
#define _DIFF_CHANNEL           0

//********************************************************
void MCP3202_Init(MCP3202_t *mcp){
    MCP3202_CS_InitPin(mcp);
    MCP3202_CS_WritePin(mcp, 1);    // Idle bus
}

//********************************************************
unsigned int _MCP3202_Communication(MCP3202_t *mcp, char data1, char data2){
    unsigned int value = 0;
    unsigned char msb = 0;
    unsigned char lsb = 0;

    MCP3202_CS_WritePin(mcp, 0);
    MCP3202_SPI_Transfer(data1);
    msb = MCP3202_SPI_Transfer(data2);
    lsb = MCP3202_SPI_Transfer(0xFF);
    MCP3202_CS_WritePin(mcp, 1);

    msb = msb & 0b00001111;
    value = ( (uint16_t)msb << 8U ) | lsb;

    return value;
}

//********************************************************
float MCP3202_GetSingleEndedADC(MCP3202_t *mcp, char ch){
    char data1 = 0;
    char data2 = 0;
    unsigned int value_int=0;
    float mv = 0;
    char type = _SINGLE_CHANNEL;

    if(ch > MCP3202_CH1){return 0;}

    data1 = 0b00000001;
    data2 = (type << 7) | (ch << 6);

    value_int = _MCP3202_Communication(mcp, data1, data2);
    mv = value_int;
    mv = mv * _MCP3202_GAIN;

    return mv;
}

//********************************************************
float MCP3202_GetDifferentialADC(MCP3202_t *mcp, char ch){
    char data1 = 0;
    char data2 = 0;
    unsigned int value_int = 0;
    float mv = 0;
    char type = _DIFF_CHANNEL;

    switch (ch){
        case MCP3202_CH0CH1:
            ch = 0b00000000;
            break;
        case MCP3202_CH1CH0:
            ch = 0b00000001;
            break;
        default:
            return 0;
    }

    data1 = 0b00000001;
    data2 = (type<<7) | (ch<<6);

    value_int = _MCP3202_Communication(mcp, data1, data2);
    mv = value_int;
    mv = mv * _MCP3202_GAIN;

    return mv;
}


