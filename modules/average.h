/**
 * @file    average.h
 * @brief   Lightweight averaging library for embedded systems.
 *          Provides block and moving averages specifically for uint16_t values,
 *          with optional optimized division for power-of-two sample counts.
 *          Suitable for fast loops and ADC filtering.
 *
 * @note    Uses AVERAGE_COUNT macro from average_config.h
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AVERAGE_INCLUDED
#define AVERAGE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "average_config.h"

/**
 * @brief Structure for block averaging.
 *        Maintains sum and count of samples, and stores the current average.
 */
typedef struct {
    uint32_t sum;       /**< Accumulated sum of samples */
    uint8_t count;      /**< Number of samples added */
    uint16_t average;   /**< Current block average */
} AverageBlock_t;

/**
 * @brief Structure for moving average using a circular buffer.
 *        Maintains a buffer of recent samples, current index, accumulated sum, and full flag.
 */
typedef struct {
    uint16_t buf[AVERAGE_COUNT];    /**< Circular buffer of recent samples */
    uint8_t  index;                 /**< Current index in the circular buffer */
    uint32_t sum;                   /**< Accumulated sum of samples */
    uint8_t  full;                  /**< Flag indicating buffer is fully populated */
} AverageMoving_t;

/**
 * @brief Updates block average with a new value and returns the current average.
 *        Resets internal sum after AVERAGE_COUNT samples.
 *
 * @param value New sample to add
 * @param avg Pointer to AverageBlock_t structure
 * @return Current block average
 */
uint16_t Average_BlockUpdate(uint16_t value, AverageBlock_t *avg);

/**
 * @brief Updates moving average using a circular buffer and returns the current average.
 *        Handles startup phase with fewer samples and uses optimized division when buffer is full.
 *
 * @param value New sample to add
 * @param avg Pointer to AverageMoving_t structure
 * @return Current moving average
 */
uint16_t Average_MovingUpdate(uint16_t value, AverageMoving_t *avg);

#ifdef __cplusplus
}
#endif

#endif
