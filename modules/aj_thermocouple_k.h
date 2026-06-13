/******************************************************************************
 * @brief     Type-K Thermocouple Conversion Library
 *
 * @details
 * This module provides conversion functions between temperature (°C)
 * and thermocouple voltage (µV) for Type-K thermocouples.
 *
 * The implementation uses a lookup table with 10°C resolution derived
 * from NIST ITS-90 thermocouple reference data.
 *
 * To achieve high performance on embedded systems, the conversion uses:
 *  - Integer arithmetic (no floating point operations)
 *  - Lookup table search
 *  - Linear interpolation between table entries
 *
 * Supported temperature range:
 *      -270°C  to  +1370°C
 *
 * Voltage values in the table are expressed in microvolts (µV).
 *
 * This implementation is designed for resource-constrained embedded
 * systems where floating-point operations may be slow or unavailable.
 *
 * Algorithm summary:
 *
 *  Temperature to Voltage
 *      Direct lookup + linear interpolation
 *
 *  Voltage to Temperature
 *      Table search + linear interpolation
 *
 * Notes:
 *  - All calculations use integer math.
 *  - Lookup table step size is 10°C.
 *  - Values outside the supported range are clamped to the nearest
 *    valid table value.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 ******************************************************************************/

#ifndef AJ_THERMOCOUPLE_K_INCLUDED
#define AJ_THERMOCOUPLE_K_INCLUDED

#include <stdint.h>

#define AJ_TC_K_TEMP_MIN     -270
#define AJ_TC_K_TEMP_MAX     1370
#define AJ_TC_K_ERROR        1371

/**
 * @brief Convert Type-K thermocouple voltage to temperature.
 *
 * @param uv
 * Thermocouple voltage in microvolts (µV).
 *
 * @return
 * Temperature in degrees Celsius.
 */
int16_t AJ_TC_K_ConvertMicroVoltToTemp(int32_t uv);

/**
 * @brief Convert temperature to Type-K thermocouple voltage.
 *
 * @param temp
 * Temperature in degrees Celsius.
 *
 * @return
 * Thermocouple voltage in microvolts (µV).
 */
int32_t AJ_TC_K_ConvertTempToMicroVolt(int16_t temp);

#endif

