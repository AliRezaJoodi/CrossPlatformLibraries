/**
 * @brief   Driver interface for the MAX6675 thermocouple-to-digital converter.
 *
 * @details
 * This file provides the public API for interfacing with the MAX6675
 * thermocouple converter using an SPI communication interface.
 *
 * The MAX6675 performs cold-junction compensation and converts the
 * thermocouple voltage from a Type-K thermocouple into a digital value.
 * The device outputs a 16-bit serial frame from which a 12-bit raw
 * temperature value is extracted.
 *
 * The returned value from the driver is the raw temperature code.
 * This value represents temperature with a resolution of:
 *      12-bit, 0.25°C per LSB
 * Temperature can be calculated as:
 *      Temperature (°C) = Raw_Value × 0.25
 *
 * Example:
 *      If the thermocouple temperature is 100°C,
 *      the raw value returned by the driver will be:
 *          Raw = 100 / 0.25 = 400
 *
 * @note
 * This driver does not configure the SPI peripheral.
 * The user application must configure SPI before using this driver.
 * The MAX6675 serial interface must be configured with:
 * - SPI mode 1 (CPOL = 0, CPHA = 1)
 * - Data order: MSB first
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_MAX6675_INCLUDED
#define AJ_MAX6675_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_max6675_hw.h"      /**< refer to main.c*/
#include "aj_max6675_type.h"

/** Initializes the MAX6675 driver and related control pins. */
void AJ_MAX6675_Init(aj_max6675_t *max);

/**
 * @brief   Reads the 12-bit raw temperature value from the MAX6675.
 *
 * @details
 * Returns the raw temperature code with a resolution of 0.25°C per LSB.
 *
 * @param   max Pointer to the MAX6675 driver instance.
 * @return  Raw temperature value, or 0 if the thermocouple is not connected.
 */
uint16_t AJ_MAX6675_ReadRaw(aj_max6675_t *max);

#ifdef __cplusplus
}
#endif

#endif