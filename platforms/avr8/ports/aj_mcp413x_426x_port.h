#ifndef AJ_MCP413X_426X_PORT_INCLUDED
#define AJ_MCP413X_426X_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_mcp413x_426x_config.h"
#include "aj_mcp413x_426x_config_platform.h"
#include "aj_mcp413x_426x_type.h"
#include "aj_spi.h"

#define AJ_MCP413X_426X_DELAY_US(us)    AJ_DELAY_US(us)

static inline void AJ_MCP413x_426x_CS_ConfigAsOutput(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.ddr, mcp->cs.mask);
}

static inline void AJ_MCP413x_426x_CS_SetActive(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->cs.port, mcp->cs.mask);
}

static inline void AJ_MCP413x_426x_CS_SetIdle(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.port, mcp->cs.mask);
}

#if (AJ_MCP413X_426X_SHDN_USED == 1U)
static inline void AJ_MCP413x_426x_SHDN_ConfigAsOutput(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->shdn.ddr, mcp->shdn.mask);
}

static inline void AJ_MCP413x_426x_SHDN_SetActive(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->shdn.port, mcp->shdn.mask);
}

static inline void AJ_MCP413x_426x_SHDN_SetIdle(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->shdn.port, mcp->shdn.mask);
}
#endif

#if (AJ_MCP413X_426X_WP_USED == 1U)
static inline void AJ_MCP413x_426x_WP_ConfigAsOutput(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->wp.ddr, mcp->wp.mask);
}

static inline void AJ_MCP413x_426x_WP_SetActive(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->wp.port, mcp->wp.mask);
}

static inline void AJ_MCP413x_426x_WP_SetIdle(const aj_mcp413x_426x_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->wp.port, mcp->wp.mask);
}
#endif

static inline uint8_t AJ_MCP413x_426x_SPI_TxRx(const uint8_t data){
    return AJ_SPI_TxRx(data);
}

#ifdef __cplusplus
}
#endif

#endif
