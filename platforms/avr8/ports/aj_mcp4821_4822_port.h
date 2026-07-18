/**
 * @brief   SPI usage and recommended configuration for MCP4822
 *
 * @warning
 * Ensure the SPI peripheral is configured before calling any MCP4822 functions.
 * Using incorrect SPI settings may result in incorrect DAC.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

/**
 * @example
 * Example SPI configuration for CodeVision AVR (ATmega32A):
 *
 * @code
 * void SPI_Config(void) {
 *     // Pin directions
 *     DDRB.5 = 1; PORTB.5 = 0;    // MOSI
 *     DDRB.6 = 0; PORTB.6 = 0;    // MISO
 *     DDRB.7 = 1; PORTB.7 = 0;    // SCK
 *
 *     // SPI initialization
 *     // SPCR - SPI Control Register:
 *     //   SPIE  = 0 -> SPI interrupt disabled
 *     //   SPE   = 1 -> SPI enabled
 *     //   DORD  = 0 -> MSB first
 *     //   MSTR  = 1 -> Master mode
 *     //   CPOL  = 0 -> Clock idle low
 *     //   CPHA  = 0 -> Sample on leading edge (Cycle Start)
 *     //   SPR1, SPR0 = 0 -> Clock rate f_osc/4
 *     // SPSR - SPI Status Register:
 *     //   SPI2X = 0 -> No double speed
 *     SPCR = (0<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR)
 *          | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
 *     SPSR = (0<<SPI2X);
 * }
 * @endcode
 */

#ifndef AJ_MCP4822_PORT_INCLUDED
#define AJ_MCP4822_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_compiler.h"
#include "aj_bit_reg.h"
#include "aj_spi.h"
#include "aj_mcp4821_4822_config_platform.h"
#include "aj_mcp4821_4822_type.h"

#define AJ_MCP4822_DELAY_US(us) AJ_DELAY_US(us)

/**
 * @brief   Initialize MCP4822 CS pin
 * Sets the CS pin as output state.
 *
 * @param[in] mcp   Pointer to MCP4822 device handle
 */
static inline void AJ_MCP4822_CS_ConfigAsOutput(const aj_mcp4822_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Assert CS (active state).
 * Drives the CS pin to its active level (low).
 *
 * @param[in] mcp  Pointer to MCP4822 device handle
 */
static inline void AJ_MCP4822_CS_SetActive(const aj_mcp4822_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deassert CS (idle state).
 * Drives the CS pin to its idle level (high).
 *
 * @param[in] mcp  Pointer to MCP4822 device handle
 */
static inline void AJ_MCP4822_CS_SetIdle(const aj_mcp4822_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Initialize MCP4822 LDAC pin
 * Sets the LDAC pin as output state.
 *
 * @param[in] mcp   Pointer to MCP4822 device handle
 */
static inline void AJ_MCP4822_LDAC_ConfigAsOutput(const aj_mcp4822_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->ldac.ddr, mcp->ldac.mask);
}

/**
 * @brief Assert LDAC (active state).
 * Drives the LDAC pin to its active level (low) to latch DAC input data
 * to the output register.
 *
 * @param[in] mcp  Pointer to MCP4822 device handle
 */
static inline void AJ_MCP4822_LDAC_SetActive(const aj_mcp4822_t *mcp){
    AJ_BitReg_ClearBit_Mask(mcp->ldac.port, mcp->ldac.mask);
}

/**
 * @brief Deassert LDAC (idle state).
 * Drives the LDAC pin to its idle level (high).
 *
 * @param[in] mcp  Pointer to MCP4822 device handle
 */
static inline void AJ_MCP4822_LDAC_SetIdle(const aj_mcp4822_t *mcp){
    AJ_BitReg_SetBit_Mask(mcp->ldac.port, mcp->ldac.mask);
}

/**
 * @brief   Send a single byte via SPI
 *
 * Transmits a byte to the MCP4822 over SPI and waits for completion.
 * Returns 0 on success or 1 if timeout occurs.
 *
 * @param[in] data   Byte to transmit
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline void AJ_MCP3208_SPI_TxRx(uint8_t data){
    AJ_SPI_TxRx(data);
}


#ifdef __cplusplus
}
#endif

#endif
