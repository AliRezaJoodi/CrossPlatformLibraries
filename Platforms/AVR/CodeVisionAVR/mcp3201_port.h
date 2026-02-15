/**
 * @file    mcp3201_port.h
 * @brief   SPI usage and recommended configuration for MCP3201
 *
 * @note
 * This library does NOT configure the SPI peripheral automatically.
 * The user must initialize the SPI interface according to the requirements
 * of the MCP3201 device.
 *
 * Recommended SPI settings for MCP3201:
 *   - SPI Mode: Master
 *   - Clock Phase (CPHA): 0 (Cycle Start)
 *   - Clock Polarity (CPOL): 0 (Low)
 *   - Data Order: MSB First
 *   - SPI Clock: <= 2 MHz (example value)
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

#ifndef MCP3201_PORT_INCLUDED
#define MCP3201_PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <io.h>
#include <spi.h>

#include "utility_bit.h"

/**
 * @brief   GPIO representation for a single MCP3201 pin
 *
 * This struct maps a microcontroller pin for use by the MCP3201 driver.
 * It contains pointers to the DDR and PORT registers, and the bit index
 * of the pin within those registers.
 *
 * @note    All pointers must point to valid registers before use.
 */
typedef struct {
    volatile uint8_t *ddr;      /**< Data Direction Register for this pin */
    volatile uint8_t *port;     /**< PORT register for this pin */
    uint8_t           index;    /**< Bit position within DDR/PORT (0..7) */
} MCP3201_Pin_t;

/**
 * @brief   MCP3201 instance structure
 *
 * Contains all pins used by a single MCP3201 device.
 */
typedef struct {
    MCP3201_Pin_t cs;       /**< Chip Select pin */
} MCP3201_t;

/**
 * @example
 * Example: defining pin macros
 *
 * @code
 * #define MCP3201_CS1_DDR   DDRB
 * #define MCP3201_CS1_PORT  PORTB
 * #define MCP3201_CS1_BIT   4U
 * @endcode
 *
 * Example: initializing a structure
 *
 * @code
 * MCP3201_t mcp1;
 * mcp1.cs.ddr   = &MCP3201_CS1_DDR;
 * mcp1.cs.port  = &MCP3201_CS1_PORT;
 * mcp1.cs.index =  MCP3201_CS1_BIT;
 * @endcode
 */

/**
 * @brief Initialize MCP3201 CS pin (output, idle high)
 *
 * @param   mcp     Pointer to the MCP3201 instance
 */
static inline void MCP3201_CS_InitPin(MCP3201_t *mcp){
    SET_BIT( *(mcp->cs.ddr), mcp->cs.index );
    SET_BIT( *(mcp->cs.port), mcp->cs.index );
}

/**
 * @brief   Set the CS pin level for MCP3201
 *
 * @param   mcp     Pointer to the MCP3201 instance
 * @param   status  Logic level to set
 *                  - 0: Pull CS low (select chip)
 *                  - 1: Pull CS high (deselect / idle)
 *
 * @note    The CS pin must be initialized with MCP3201_CS_Init() before use.
 */
static inline void MCP3201_CS_WritePin(MCP3201_t *mcp, uint8_t status){
    WRITE_BIT( *(mcp->cs.port), mcp->cs.index, status );
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
static inline uint8_t MCP3201_SPI_Transfer(uint8_t data){
    return spi(data);
}

#ifdef __cplusplus
}
#endif

#endif
