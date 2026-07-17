// GitHub Account: GitHub.com/AliRezaJoodi

#include "aj_mcp3204_3208_type.h"
#include "aj_mcp3204_3208_port.h"
#include "aj_mcp3204_3208.h"

/********************************************************/
void AJ_MCP3204_3208_Init(aj_mcp3204_3208_t *mcp){
    AJ_MCP3204_3208_CS_ConfigAsOutput(mcp);
    AJ_MCP3204_3208_CS_SetIdle(mcp);
}

/********************************************************/
uint16_t AJ_MCP3204_3208_ReadRaw(aj_mcp3204_3208_t *mcp, aj_mcp3204_3208_ch_t ch){
    uint8_t msb = (uint8_t)(ch >>2U);
    uint8_t lsb = (uint8_t)((ch & 0x0003U) << 6);

    AJ_MCP3204_3208_CS_SetActive (mcp);
    AJ_MCP3204_3208_DELAY_US(1);

    AJ_MCP3204_3208_SPI_TxRx(msb);
    msb = AJ_MCP3204_3208_SPI_TxRx(lsb);        // Get MSB
    lsb = AJ_MCP3204_3208_SPI_TxRx(0xFF);       // Get LSB

    AJ_MCP3204_3208_DELAY_US(1);
    AJ_MCP3204_3208_CS_SetIdle(mcp);

    return ( ((uint16_t)(msb & 0x0FU) << 8U) | lsb );
}
