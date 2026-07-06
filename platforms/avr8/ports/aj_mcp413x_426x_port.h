#ifndef AJ_MCP413X_426X_PORT_INCLUDED
#define AJ_MCP413X_426X_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_mcp413x_426x_hw.h"
#include "aj_mcp413x_426x_type.h"
#include "aj_spi.h"

#define AJ_MCP413X_426X_DELAY_US(us)    AJ_DELAY_US(us)

/**
 * @brief Initialize MCP42xxx CS pin (output)
 *
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_CS_ConfigAsOutput(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Select the MCP42xxx device by driving CS low.
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_CS_SetActive(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deselect the MCP42xxx device by driving CS high.
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_CS_SetIdle(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.port, mcp->cs.mask);
}

#if (AJ_MCP413X_426X_SHDN_USED == 1U)
/**
 * @brief Initialize MCP42xxx SHDN pin (output)
 *
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_SHDN_ConfigAsOutput(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->shdn.ddr, mcp->shdn.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_SHDN_SetActive(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->shdn.port, mcp->shdn.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_SHDN_SetIdle(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->shdn.port, mcp->shdn.mask);
}
#endif

#if (AJ_MCP413X_426X_WP_USED == 1U)
/**
 * @brief Initialize MCP42xxx SHDN pin (output)
 *
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_WP_ConfigAsOutput(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->wp.ddr, mcp->wp.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_WP_SetActive(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->wp.port, mcp->wp.mask);
}

/**
 * @brief
 * @param mcp Pointer to the MCP42xxx instance.
 */
static inline void AJ_MCP413x_426x_WP_SetIdle(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->wp.port, mcp->wp.mask);
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
static inline void AJ_MCP413x_426x_SPI_Tx(const uint8_t data){
    AJ_SPI_Tx(data);
}

static inline uint8_t AJ_MCP413x_426x_SPI_Rx(void){
    return AJ_SPI_Rx();
}

#ifdef __cplusplus
}
#endif

#endif
