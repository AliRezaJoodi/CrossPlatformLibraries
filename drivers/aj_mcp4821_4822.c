#include "aj_mcp4821_4822_config.h"
#include "aj_mcp4821_4822_type.h"
#include "aj_mcp4821_4822_port.h"
#include "aj_mcp4821_4822.h"

#define MCP4822_ENABLE      1U
#define MCP4822_DISABLE     0U

//********************************************************
void AJ_MCP4822_Init(aj_mcp4822_t *dac){
    AJ_MCP4822_CS_ConfigAsOutput(dac);
    AJ_MCP4822_CS_SetIdle(dac);

    AJ_MCP4822_LDAC_ConfigAsOutput(dac);
    AJ_MCP4822_LDAC_SetIdle(dac);
}

//********************************************************
void AJ_MCP4822_WriteChannel(aj_mcp4822_t *dac, aj_mcp4822_channel_t ch, aj_mcp4822_scale_t fs, uint16_t count){
    uint8_t msb =   ((ch & 0x01U) << 7)     |
                    ((fs & 0x01U) << 5)     |
                    (MCP4822_ENABLE << 4)   |
                    (uint8_t)((count >> 8) & 0x0F);

    uint8_t lsb =   (uint8_t)(count & 0x00FF);

    AJ_MCP4822_CS_SetActive(dac);
    AJ_MCP3208_SPI_TxRx(msb);
    AJ_MCP3208_SPI_TxRx(lsb);
    AJ_MCP4822_CS_SetIdle(dac);
    AJ_MCP4822_DELAY_US(1);    /**< Minimum Setup Time = 40ns */

    AJ_MCP4822_LDAC_SetActive(dac);
    AJ_MCP4822_DELAY_US(1);    /**< Minimum Pulse Width = 100ns */
    AJ_MCP4822_LDAC_SetIdle(dac);
}

//********************************************************
void AJ_MCP4822_ShutdownChannel(aj_mcp4822_t *dac, aj_mcp4822_channel_t ch){
    uint8_t msb =   ((ch & 0x01U) << 7)     |
                    (MCP4822_DISABLE << 4);

    AJ_MCP4822_CS_SetActive(dac);
    AJ_MCP3208_SPI_TxRx(msb);
    AJ_MCP3208_SPI_TxRx(0xFFU);
    AJ_MCP4822_CS_SetIdle(dac);
    AJ_MCP4822_DELAY_US(1);    /**< Minimum Setup Time = 40ns */

    AJ_MCP4822_LDAC_SetActive(dac);
    AJ_MCP4822_DELAY_US(1);    /**< Minimum Pulse Width = 100ns */
    AJ_MCP4822_LDAC_SetIdle(dac);
}
