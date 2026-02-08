// GitHub Account: GitHub.com/AliRezaJoodi

#include <mcp3201.h>

#define MCP3201_PIN_INPUT       0U
#define MCP3201_PIN_OUTPUT      1U

#define MCP3201_RESOLUTION      4096U     //12-Bit

static const float  MCP3201_GAIN = (float)(MCP3201_VREF) / (float)(MCP3201_RESOLUTION);

//********************************************************
void MCP3201_Config(MCP3201_t *mcp){
    MCP3201_CS_ConfigPin(mcp, MCP3201_PIN_OUTPUT); 
    MCP3201_CS_WritePin(mcp, 1);    // Idle bus   
}

//********************************************************
uint16_t MCP3201_GetCounts(MCP3201_t *mcp){
    uint16_t value = 0;
    uint8_t msb = 0;
    uint8_t lsb = 0;
    
    MCP3201_CS_WritePin(mcp, 0);
    msb = MCP3201_SPI_Transfer(0xFF); 
    lsb = MCP3201_SPI_Transfer(0xFF);
    MCP3201_CS_WritePin(mcp, 1);
    
    msb = msb & 0x1FU;
    lsb = lsb & 0xFEU; 
    value = ( (uint16_t)msb << 8U ) | lsb;
    value = value >> 1U;
       
    return value;
}

//********************************************************
float MCP3201_GetMilliVolt(MCP3201_t *mcp){
    uint16_t counts = 0;

    counts = MCP3201_GetCounts(mcp);   
    return (float)(counts) * MCP3201_GAIN;
}

//********************************************************
float MCP3201_ConvertCountsToMilliVolt(uint16_t counts){
    if (counts >= MCP3201_RESOLUTION){
        counts = MCP3201_RESOLUTION - 1;
    }
    
    return (float)(counts) * MCP3201_GAIN;
}


