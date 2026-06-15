/**
 * @brief   SPI usage and recommended configuration for MCP3201
 *
 * @note
 * This library does NOT configure the SPI peripheral automatically.
 * The user must initialize the SPI interface according to the requirements
 * of the MCP3201 device.
 *
 * @warning
 * Ensure the SPI peripheral is configured before calling any MCP3201 functions.
 * Using incorrect SPI settings may result in incorrect ADC readings.
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
 *     DDRB.4 = 1; PORTB.4 = 0;    // CS (SS)
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

#ifndef AJ_MCP3201_PORT_INCLUDED
#define AJ_MCP3201_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_compiler_port.h"
#include "aj_bit_reg.h"
#include "aj_mcp3201_hw.h"
#include "aj_mcp3201_type.h"
#include "aj_spi.h"

/**
 * @brief Initialize MCP3201 CS pin (output)
 *
 * @param   mcp     Pointer to the MCP3201 instance
 */
static inline void AJ_MCP3201_CS_ConfigAsOutput(const aj_mcp3201_t *mcp){
    AJ_BitReg_SetBits_Mask(mcp->cs.ddr, mcp->cs.mask);
}

/**
 * @brief Select the MCP3201 device by driving CS low.
 * @param mcp Pointer to the MCP3201 instance.
 */
static inline void AJ_MCP3201_CS_SetActive(const aj_mcp3201_t *mcp){
    AJ_BitReg_ClearBits_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief Deselect the MCP3201 device by driving CS high.
 * @param mcp Pointer to the MCP3201 instance.
 */
static inline void AJ_MCP3201_CS_SetIdle(const aj_mcp3201_t *mcp){
    AJ_BitReg_SetBits_Mask(mcp->cs.port, mcp->cs.mask);
}

/**
 * @brief   Send and receive a byte via SPI for MCP3201
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t AJ_MCP3201_SPI_Transceive(const uint8_t data){
    return AJ_SPI_Transceive(data);     /* Return received data */
}

#ifdef __cplusplus
}
#endif

#endif
