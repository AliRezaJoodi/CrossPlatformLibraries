#ifndef AJ_AVERAGE_TYPE_INCLUDED
#define AJ_AVERAGE_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "aj_average_config.h"

/**
 * @brief Structure for block averaging.
 *        Maintains sum and count of samples, and stores the current average.
 */
typedef struct {
    uint32_t sum;       /**< Accumulated sum of samples */
    uint16_t average;   /**< Current block average */
    uint8_t count;      /**< Number of samples added */
} aj_average_block_t;

/**
 * @brief Structure for moving average using a circular buffer.
 *        Maintains a buffer of recent samples, current index, accumulated sum, and full flag.
 */
typedef struct {
    uint32_t sum;                   /**< Accumulated sum of samples */
    uint16_t buf[AJ_AVERAGE_COUNT]; /**< Circular buffer of recent samples */
    uint8_t  index;                 /**< Current index in the circular buffer */
    uint8_t  full;                  /**< Flag indicating buffer is fully populated */
} aj_average_moving_t;

#ifdef __cplusplus
}
#endif

#endif
