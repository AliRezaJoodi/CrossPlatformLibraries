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

#ifndef AJ_CHANGE_U16_INCLUDED
#define AJ_CHANGE_U16_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define AJ_CHANGE_U16_NO    0U
#define AJ_CHANGE_U16_YES   1U

typedef struct{
    uint16_t previous;
} aj_change_u16_t;


/**
 * @brief Checks if a 16-bit value has changed (exact comparison).
 *
 * Compares the input value with the value stored inside the change
 * object. If the value has changed, the stored value is updated and
 * the function returns 1. Otherwise, it returns 0.
 *
 * @param obj    Pointer to the change detection object that stores
 *               the previous value.
 * @param value  Current 16-bit value to check.
 *
 * @return
 *         - 1 : Value has changed (stored value updated)
 *         - 0 : No change detected
 */
 uint8_t AJ_ChangeU16_Exact(aj_change_u16_t *obj, uint16_t value);

/**
 * @brief Checks if a 16-bit value has changed by at least a given threshold.
 *
 * Computes the absolute difference between the input value and the
 * value stored inside the change object. If the difference is greater
 * than or equal to the specified threshold, the stored value is updated
 * and the function returns 1. Otherwise, it returns 0.
 *
 * @param obj        Pointer to the change detection object.
 * @param value      Current 16-bit value to check.
 * @param threshold  Minimum difference required to detect a change.
 *
 * @return
 *         - 1 : Difference >= threshold (stored value updated)
 *         - 0 : Difference < threshold
 */
uint8_t AJ_ChangeU16_Threshold(aj_change_u16_t *obj, uint16_t value, uint16_t threshold);

#ifdef __cplusplus
}
#endif

#endif
