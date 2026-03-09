
#include "hardware.h"       /**< Project-level overrides */
#include "mcp4822.h"

#define MCP4822_ENABLE      1U
#define MCP4822_DISABLE     0U

//********************************************************
void MCP4822_Init(MCP4822_t *dac){
    MCP4822_CS_InitPin(dac);
    MCP4822_CS_WritePin(dac, 1);    // Idle bus

    MCP4822_LDAC_InitPin(dac);
    MCP4822_LDAC_WritePin(dac, 1);  // Idle bus
}

//********************************************************
void MCP4822_SetOutput(MCP4822_t *dac, uint8_t ch, uint8_t gain, uint16_t value){
    uint8_t msb =   ((ch & 0x01U) << 7)     |
                    ((gain & 0x01U) << 5)   |
                    (MCP4822_ENABLE << 4)   |
                    (uint8_t)((value >> 8) & 0x0F);

    uint8_t lsb =   (uint8_t)(value & 0x00FF);

    MCP4822_CS_WritePin(dac, 0);
    MCP3208_SPI_Transfer(msb);
    MCP3208_SPI_Transfer(lsb);
    MCP4822_CS_WritePin(dac, 1);
    MCP4822_DELAY_US(1);    /**< Minimum Setup Time = 40ns */

    MCP4822_LDAC_WritePin(dac, 0);
    MCP4822_DELAY_US(1);    /**< Minimum Pulse Width = 100ns */
    MCP4822_LDAC_WritePin(dac, 1);
}

//********************************************************
void MCP4822_DisableOutput(MCP4822_t *dac, uint8_t ch){
    uint8_t msb =   ((ch & 0x01U) << 7)     |
                    (MCP4822_DISABLE << 4);

    MCP4822_CS_WritePin(dac, 0);
    MCP3208_SPI_Transfer(msb);
    MCP3208_SPI_Transfer(0xFFU);
    MCP4822_CS_WritePin(dac, 1);
    MCP4822_DELAY_US(1);    /**< Minimum Setup Time = 40ns */

    MCP4822_LDAC_WritePin(dac, 0);
    MCP4822_DELAY_US(1);    /**< Minimum Pulse Width = 100ns */
    MCP4822_LDAC_WritePin(dac, 1);
}
