/**
 * @file    average.h
 * @brief   Lightweight averaging library for embedded systems.
 *          Provides block and moving averages specifically for uint16_t values,
 *          with optional optimized division for power-of-two sample counts.
 *          Suitable for fast loops and ADC filtering.
 *
 * @note    Uses AJ_AVERAGE_COUNT macro from average_config.h
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_AVERAGE_INCLUDED
#define AJ_AVERAGE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_average_type.h"

/**
 * @brief Updates block average with a new value and returns the current average.
 *        Resets internal sum after AJ_AVERAGE_COUNT samples.
 *
 * @param value New sample to add
 * @param avg Pointer to aj_average_block_t structure
 * @return Current block average
 */
uint16_t AJ_Average_BlockUpdate(uint16_t value, aj_average_block_t *avg);

/**
 * @brief Updates moving average using a circular buffer and returns the current average.
 *        Handles startup phase with fewer samples and uses optimized division when buffer is full.
 *
 * @param value New sample to add
 * @param avg Pointer to aj_average_moving_t structure
 * @return Current moving average
 */
uint16_t AJ_Average_MovingUpdate(uint16_t value, aj_average_moving_t *avg);

#ifdef __cplusplus
}
#endif

#endif
