/**
 * @file ntc100k.h
 * @brief NTC 100K Thermistor Temperature Conversion Library
 *
 * @details
 * Converts thermistor resistance (Ohm) to temperature (°C)
 *
 * Temperature Range:
 * -55°C to +300°C
 *
 * Input:
 * Thermistor resistance in Ohms
 *
 * Output:
 * Temperature in degrees Celsius (int16_t)
 *
 * Notes:
 * - Hardware independent
 * - ADC to resistance conversion must be done outside this library
 * - Uses integer arithmetic (no floating point)
 *
 * Author: AliReza Joodi
 * GitHub: https://github.com/AliRezaJoodi
 */

#ifndef NTC100K_INCLUDED
#define NTC100K_INCLUDED

#include <stdint.h>

#define NTC100K_TEMP_MIN    -55
#define NTC100K_TEMP_MAX    300
#define NTC100K_ERROR       -100

/**
 * @brief Convert thermistor resistance to temperature
 *
 * @param ohm
 * Thermistor resistance in Ohms
 *
 * @return
 * Temperature in degrees Celsius
 */
int16_t NTC100K_ConvertOhmToTemp(uint32_t ohm);

#endif
