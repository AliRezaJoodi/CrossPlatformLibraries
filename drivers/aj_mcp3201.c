// GitHub Account: GitHub.com/AliRezaJoodi
#include "aj_mcp3201_type.h"
#include "aj_mcp3201_port.h"
#include "aj_mcp3201.h"

/*********************************************/
void AJ_MCP3201_Init(aj_mcp3201_t *mcp){
    AJ_MCP3201_CS_ConfigAsOutput(mcp);
    AJ_MCP3201_CS_SetIdle(mcp);
}

/*********************************************/
uint16_t AJ_MCP3201_ReadRaw(aj_mcp3201_t *mcp){
    uint16_t value = 0;
    uint8_t msb = 0, lsb = 0;

    AJ_MCP3201_CS_SetActive(mcp);
    msb = AJ_MCP3201_SPI_Transceive(0xFF);
    lsb = AJ_MCP3201_SPI_Transceive(0xFF);
    AJ_MCP3201_CS_SetIdle(mcp);

    msb = msb & 0x1FU;
    lsb = lsb & 0xFEU;
    value = ((uint16_t)msb << 8U) | lsb;
    value = value >> 1U;

    return value;
}



