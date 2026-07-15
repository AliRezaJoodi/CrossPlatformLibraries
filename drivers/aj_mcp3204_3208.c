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
uint16_t AJ_MCP3204_3208_ReadRaw(aj_mcp3204_3208_t *mcp, aj_mcp3204_3208_channel_t ch){
    uint8_t msb = (uint8_t)(ch >>2U);
    uint8_t lsb = (uint8_t)((ch & 0x0003U) << 6);

    AJ_MCP3204_3208_CS_SetActive (mcp);
    AJ_MCP3204_3208_SPI_TxRx(msb);
    msb = AJ_MCP3204_3208_SPI_TxRx(lsb);        // Get MSB
    lsb = AJ_MCP3204_3208_SPI_TxRx(0xFF);       // Get LSB
    AJ_MCP3204_3208_CS_SetIdle(mcp);

    return ( ((uint16_t)(msb & 0x0FU) << 8U) | lsb );
}

/********************************************************/
//uint16_t AJ_MCP3204_3208_ReadRaw_(aj_mcp3204_3208_t *mcp, aj_mcp3204_3208_channel_t ch){
//    uint8_t data1 = 0x00U;
//    uint8_t data2 = 0x00U;
//
//    switch (ch){
//        case AJ_MCP3204_3208_CH0:
//            data1 = 0x06U;
//            data2 = 0x00U;
//            break;
//        case AJ_MCP3204_3208_CH1:
//            data1 = 0x06U;
//            data2 = 0x40U;
//            break;
//        case AJ_MCP3204_3208_CH2:
//            data1 = 0x06U;
//            data2 = 0x80U;
//            break;
//        case AJ_MCP3204_3208_CH3:
//            data1 = 0x06U;
//            data2 = 0xC0U;
//            break;
//        case AJ_MCP3204_3208_CH4:
//            data1 = 0x07U;
//            data2 = 0x00U;
//            break;
//        case AJ_MCP3204_3208_CH5:
//            data1 = 0x07U;
//            data2 = 0x40U;
//            break;
//        case AJ_MCP3204_3208_CH6:
//            data1 = 0x07U;
//            data2 = 0x80U;
//            break;
//        case AJ_MCP3204_3208_CH7:
//            data1 = 0x07U;
//            data2 = 0xC0U;
//            break;
//        case AJ_MCP3204_3208_CH0CH1:
//            data1 = 0x04U;
//            data2 = 0x00U;
//            break;
//        case AJ_MCP3204_3208_CH1CH0:
//            data1 = 0x04U;
//            data2 = 0x40U;
//            break;
//        case AJ_MCP3204_3208_CH2CH3:
//            data1 = 0x04U;
//            data2 = 0x80U;
//            break;
//        case AJ_MCP3204_3208_CH3CH2:
//            data1 = 0x04U;
//            data2 = 0xC0U;
//            break;
//        case AJ_MCP3204_3208_CH4CH5:
//            data1 = 0x05U;
//            data2 = 0x00U;
//            break;
//        case AJ_MCP3204_3208_CH5CH4:
//            data1 = 0x05U;
//            data2 = 0x40U;
//            break;
//        case AJ_MCP3204_3208_CH6CH7:
//            data1 = 0x05U;
//            data2 = 0x80U;
//            break;
//        case AJ_MCP3204_3208_CH7CH6:
//            data1 = 0x05U;
//            data2 = 0xC0U;
//            break;
//        default:
//            return 0xFFFF;
//    }
//
//    AJ_MCP3204_3208_CS_SetActive (mcp);
//    AJ_MCP3204_3208_SPI_TxRx(data1);
//    data1 = AJ_MCP3204_3208_SPI_TxRx(data2);    // Get MSB
//    data2 = AJ_MCP3204_3208_SPI_TxRx(0xFF);     // Get LSB
//    AJ_MCP3204_3208_CS_SetIdle(mcp);
//
//    return ( ((uint16_t)(data1 & 0x0FU) << 8U) | data2 );
//}
