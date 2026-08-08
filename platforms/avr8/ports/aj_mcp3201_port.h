// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_MCP3201_PORT_INCLUDED
#define AJ_MCP3201_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_spi.h"
#include "aj_mcp3201_type.h"

#define AJ_MCP3201_DELAY_US(us)    AJ_DELAY_US(us)

/**
 * @brief Initialize MCP3201 CS pin (output)
 * @param   mcp     Pointer to the MCP3201 instance
 */
static inline void AJ_MCP3201_CS_ConfigAsOutput(aj_mcp3201_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Select the MCP3201 device by driving CS low.
 * @param mcp Pointer to the MCP3201 instance.
 */
static inline void AJ_MCP3201_CS_SetActive(aj_mcp3201_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deselect the MCP3201 device by driving CS high.
 * @param mcp Pointer to the MCP3201 instance.
 */
static inline void AJ_MCP3201_CS_SetIdle(aj_mcp3201_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI for MCP3201
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t AJ_MCP3201_SPI_TxRx(uint8_t data){
    return AJ_SPI_TxRx(data);     /* Return received data */
}


#ifdef __cplusplus
}
#endif

#endif
