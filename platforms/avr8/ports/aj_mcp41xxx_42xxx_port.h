#ifndef AJ_MCP42XXX_PORT_INCLUDED
#define AJ_MCP42XXX_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_mcp41xxx_42xxx_hw.h"
#include "aj_mcp41xxx_42xxx_type.h"
#include "aj_spi.h"

#define AJ_MCP42XXX_DELAY_US(us)    AJ_DELAY_US(us)

/**
 * @brief Initialize MCP42xxx CS pin (output)
 *
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_CS_ConfigAsOutput(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Select the MCP42xxx device by driving CS low.
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_CS_SetActive(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deselect the MCP42xxx device by driving CS high.
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_CS_SetIdle(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.port, mcp->cs.mask);
}

#if (AJ_MCP42XXX_SHDN_USED == 1U)
/**
 * @brief Initialize MCP42xxx SHDN pin (output)
 *
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_SHDN_ConfigAsOutput(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->shdn.ddr, mcp->shdn.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_SHDN_SetActive(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->shdn.port, mcp->shdn.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_SHDN_SetIdle(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->shdn.port, mcp->shdn.mask);
}
#endif

#if (AJ_MCP42XXX_RS_USED == 1U)
/**
 * @brief Initialize MCP42xxx SHDN pin (output)
 *
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_RS_ConfigAsOutput(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->rs.ddr, mcp->rs.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_RS_SetActive(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->rs.port, mcp->rs.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP42xxx_RS_SetIdle(const aj_mcp42xxx_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->rs.port, mcp->rs.mask);
}
#endif

/**
 * @brief   Send and receive a byte via SPI for MCP42xxx
 *
 * @param   data    Byte to transmit
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline void AJ_MCP42xxx_SPI_TxRx(const uint8_t data){
    AJ_SPI_TxRx(data);
}

#ifdef __cplusplus
}
#endif

#endif
