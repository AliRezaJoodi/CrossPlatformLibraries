
#include "hardware.h"       /**< Project-level overrides */
#include "mcp4822_port.h"
#include "drivers/mcp4822.h"

#define MCP4822_ENABLE      1U
#define MCP4822_DISABLE     0U

//#define CS_IDLE             1U
//#define CS_ACTIVE           0U

//#define LDAC_IDLE           1U
//#define LDAC_ACTIVE         0U

//********************************************************
void MCP4822_Init(MCP4822_t *dac){
    MCP4822_CS_ConfigOutput(dac);
    //MCP4822_CS_Write(dac, CS_IDLE);
    MCP4822_CS_Set(dac);

    MCP4822_LDAC_ConfigOutput(dac);
    //MCP4822_LDAC_Write(dac, LDAC_IDLE);
    MCP4822_LDAC_Set(dac);
}

//********************************************************
void MCP4822_SetOutput(MCP4822_t *dac, MCP4822_Channel_t ch, MCP4822_Gain_t gain, uint16_t value){
    uint8_t msb =   ((ch & 0x01U) << 7)     |
                    ((gain & 0x01U) << 5)   |
                    (MCP4822_ENABLE << 4)   |
                    (uint8_t)((value >> 8) & 0x0F);

    uint8_t lsb =   (uint8_t)(value & 0x00FF);

    //MCP4822_CS_Write(dac, CS_ACTIVE);
    MCP4822_CS_Clear(dac);
    MCP3208_SPI_Transfer(msb);
    MCP3208_SPI_Transfer(lsb);
    //MCP4822_CS_Write(dac, CS_IDLE);
    MCP4822_CS_Set(dac);
    MCP4822_DELAY_US(1);    /**< Minimum Setup Time = 40ns */

    //MCP4822_LDAC_Write(dac, LDAC_ACTIVE);
    MCP4822_LDAC_Clear(dac);
    MCP4822_DELAY_US(1);    /**< Minimum Pulse Width = 100ns */
    //MCP4822_LDAC_Write(dac, LDAC_IDLE);
    MCP4822_LDAC_Set(dac);
}

//********************************************************
void MCP4822_DisableOutput(MCP4822_t *dac, MCP4822_Channel_t ch){
    uint8_t msb =   ((ch & 0x01U) << 7)     |
                    (MCP4822_DISABLE << 4);

    //MCP4822_CS_Write(dac, CS_ACTIVE);
    MCP4822_CS_Clear(dac);
    MCP3208_SPI_Transfer(msb);
    MCP3208_SPI_Transfer(0xFFU);
    //MCP4822_CS_Write(dac, CS_IDLE);
    MCP4822_CS_Set(dac);
    MCP4822_DELAY_US(1);    /**< Minimum Setup Time = 40ns */

    //MCP4822_LDAC_Write(dac, LDAC_ACTIVE);
    MCP4822_LDAC_Clear(dac);
    MCP4822_DELAY_US(1);    /**< Minimum Pulse Width = 100ns */
    //MCP4822_LDAC_Write(dac, LDAC_IDLE);
    MCP4822_LDAC_Set(dac);
}
