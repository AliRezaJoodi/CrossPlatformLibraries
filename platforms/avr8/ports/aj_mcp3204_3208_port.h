// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_MCP3204_3208_PORT_INCLUDED
#define AJ_MCP3204_3208_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_spi.h"
#include "aj_mcp3204_3208_type.h"

/**
 * @brief Initialize MCP3204_3208 CS pin (output, idle high)
 *
 * @param   mcp     Pointer to the MCP3204_3208 instance
 */
static inline void AJ_MCP3204_3208_CS_ConfigAsOutput(const aj_mcp3204_3208_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Select the MCP3204_3208 device by driving CS low.
 * @param mcp Pointer to the MCP3204_3208 instance.
 */
static inline void AJ_MCP3204_3208_CS_SetActive (const aj_mcp3204_3208_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deselect the MCP3204_3208 device by driving CS high.
 * @param mcp Pointer to the MCP3204_3208 instance.
 */
static inline void AJ_MCP3204_3208_CS_SetIdle(const aj_mcp3204_3208_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI for MCP3204_3208
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t AJ_MCP3204_3208_SPI_TxRx(const uint8_t data){
    return AJ_SPI_TxRx(data);     /* Return received data */
}


#ifdef __cplusplus
}
#endif

#endif

