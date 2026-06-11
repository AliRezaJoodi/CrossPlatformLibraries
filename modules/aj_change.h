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

#ifndef AJ_CHANGE_INCLUDED
#define AJ_CHANGE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define AJ_CHANGE_NO    0U
#define AJ_CHANGE_YES   1U

typedef struct{
    uint16_t previous;
} aj_change_t;


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
uint8_t AJ_Change_Exact(aj_change_t *obj, uint16_t value);

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
uint8_t AJ_Change_Threshold(aj_change_t *obj, uint16_t value, uint16_t threshold);

#ifdef __cplusplus
}
#endif

#endif
