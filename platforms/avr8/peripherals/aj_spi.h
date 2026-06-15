/**
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_SPI_INCLUDED
#define AJ_SPI_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_spi_config.h"

/**
 * @brief   Send and receive a byte via SPI
 *
 * @param   data    Byte to transmit
 * @return  Received byte from SPI
 *
 * @note    The SPI peripheral must be configured and enabled
 *          before calling this function.
 */
static inline uint8_t AJ_SPI_Transceive(const uint8_t data){
    uint16_t timeout = AJ_SPI_TIMEOUT;  /* Software timeout counter */

    SPDR = data;                        /* Start SPI transfer */

    while (!(SPSR & (1U << SPIF))) {    /* Wait for transfer complete */
        if (--timeout == 0U){           /* Check timeout expiration */
            return AJ_SPI_ERROR;        /* Return error value */
        }
    }

    return SPDR;                        /* Return received data */
}

#ifdef __cplusplus
}
#endif

#endif  /* AJ_SPI_INCLUDED */