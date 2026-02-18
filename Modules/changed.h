/**
 * @brief   Lightweight change-detection utilities for uint16_t values.
 *
 * This header provides small and efficient inline functions for detecting
 * exact or threshold-based changes in 16-bit values. Designed for
 * resource-constrained embedded systems.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef CHANGED_INCLUDED
#define CHANGED_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Checks if a 16-bit value has changed (exact comparison).
 *
 * Compares the input value with the previously stored value.
 * If the value has changed, the stored value is updated and
 * the function returns 1. Otherwise, it returns 0.
 *
 * @param value      Current 16-bit value to check.
 * @param previous   Pointer to the previously stored value.
 *
 * @return
 *         - 1 : Value has changed (previous updated)
 *         - 0 : No change detected
 */
static inline uint8_t Changed_Exact(uint16_t value, uint16_t *previous){
    if (value == *previous){
        return 0;
    }

    *previous = value;
    return 1;
}

/**
 * @brief Checks if a 16-bit value has changed by at least a given threshold.
 *
 * Computes the absolute difference between the input value and the
 * previously stored value. If the difference is greater than or equal
 * to the specified threshold, the stored value is updated and the
 * function returns 1. Otherwise, it returns 0.
 *
 * @param value      Current 16-bit value.
 * @param previous   Pointer to previously stored value.
 * @param threshold  Minimum required difference to detect a change.
 *
 * @return 1 if the difference is >= threshold, 0 otherwise.
 */
static inline uint8_t Changed_Threshold(uint16_t value, uint16_t *previous, uint16_t threshold){
    uint16_t prev = *previous;
    uint16_t diff = 0;

    if (value > prev){
        diff = value - prev;
    }
    else {
        diff = prev - value;
    }

    if (diff < threshold){
        return 0;
    }

    *previous = value;
    return 1;
}

#ifdef __cplusplus
}
#endif

#endif
