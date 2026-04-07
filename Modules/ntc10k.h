/*
 * NTC10K Thermistor Conversion Library
 * ------------------------------------
 * Converts thermistor resistance (Ohm) to temperature (°C)
 * using a lookup table for a 10K NTC thermistor (B=3950).
 *
 * Temperature range:
 *   -25°C to +125°C
 *
 * Resolution:
 *   1°C
 *
 * Two conversion algorithms are provided:
 *
 * 1) NTC10K_ConvertOhmToTemp()
 *    Uses binary search on the lookup table.
 *    Deterministic execution time.
 *
 * 2) NTC10K_ConvertOhmToTemp_LastIndex()
 *    Optimized algorithm using last index tracking.
 *    Faster when temperature changes slowly between samples.
 *
 * Input:
 *   Thermistor resistance in Ohms.
 *
 * Output:
 *   Temperature in degrees Celsius.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef NTC10K_INCLUDED
#define NTC10K_INCLUDED

#include <stdint.h>

/*
 * Convert thermistor resistance to temperature.
 *
 * Algorithm:
 *   Binary search on the NTC lookup table.
 *
 * Characteristics:
 *   - Deterministic execution time
 *   - No dependency on previous measurements
 *   - Suitable for random measurements
 *
 * Parameter:
 *   ohm  -> Thermistor resistance in Ohms
 *
 * Return:
 *   Temperature in degrees Celsius (-25°C to +125°C)
 */
int16_t NTC10K_ConvertOhmToTemp(uint32_t ohm);

/*
 * Convert thermistor resistance to temperature using last index tracking.
 *
 * Algorithm:
 *   Starts searching from the previous table index instead of the beginning.
 *   This significantly reduces search iterations when temperature changes slowly.
 *
 * Characteristics:
 *   - Faster than binary search for continuous sampling
 *   - Ideal for real-time temperature monitoring
 *   - Uses static internal state (last index)
 *
 * Parameter:
 *   ohm  -> Thermistor resistance in Ohms
 *
 * Return:
 *   Temperature in degrees Celsius (-25°C to +125°C)
 */
int16_t NTC10K_ConvertOhmToTemp_LastIndex(uint32_t ohm);

#endif
