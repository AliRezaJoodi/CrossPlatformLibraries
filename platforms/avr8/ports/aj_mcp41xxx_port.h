#ifndef AJ_MCP41XXX_PORT_INCLUDED
#define AJ_MCP41XXX_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler_port.h"
#include "aj_bit_reg.h"
#include "aj_mcp41xxx_hw.h"
#include "aj_mcp41xxx_type.h"
#include "aj_spi.h"

#define AJ_MCP41XXX_DELAY_US(us)    AJ_DELAY_US(us)

/**
 * @brief Initialize MCP41xxx CS pin (output)
 *
 * @param   mcp     Pointer to the MCP41xxx instance
 */
static inline void AJ_MCP41xxx_CS_ConfigAsOutput(const aj_mcp41xxx_t *mcp){
    AJ_BitReg_SetBits_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Select the MCP41xxx device by driving CS low.
 * @param mcp Pointer to the MCP41xxx instance.
 */
static inline void AJ_MCP41xxx_CS_SetActive(const aj_mcp41xxx_t *mcp){
    AJ_BitReg_ClearBits_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deselect the MCP41xxx device by driving CS high.
 * @param mcp Pointer to the MCP41xxx instance.
 */
static inline void AJ_MCP41xxx_CS_SetIdle(const aj_mcp41xxx_t *mcp){
    AJ_BitReg_SetBits_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI for MCP41xxx
 *
 * @param   data    Byte to transmit
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline void AJ_MCP41xxx_SPI_Transfer(const uint8_t data){
    AJ_SPI_Transceive(data);
}

#ifdef __cplusplus
}
#endif

#endif
