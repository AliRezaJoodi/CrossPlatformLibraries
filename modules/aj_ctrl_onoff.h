/**
 * @brief   Simple ON/OFF controller with hysteresis.
 *
 * This module provides a basic ON/OFF control algorithm with hysteresis.
 * It compares the process value (pv) with the setpoint (sp) and determines
 * whether the value is below, above, or within the hysteresis band.
 *
 * The hysteresis value represents the total band width (not half).
 *
 * This module is platform-independent and can be used for heating,
 * cooling, or any threshold-based control system.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef AJ_CTRL_ONOFF_INCLUDED
#define AJ_CTRL_ONOFF_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Controller output command.
 *
 * Represents the position of the process value relative to the setpoint.
 */
typedef enum {
    AJ_CTRL_ONOFF_NONE = 0,    /**< Value is within hysteresis band (no action) */
    AJ_CTRL_ONOFF_LOW,         /**< Value is below lower threshold */
    AJ_CTRL_ONOFF_HIGH,        /**< Value is above upper threshold */
} aj_ctrl_onof_cmd_t;

typedef struct {
    int32_t sp;         /**< Setpoint value*/
    int32_t hysteresis; /**< Hysteresis range */
    int32_t pv;         /**< Current process value */
} aj_ctrl_onoff_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * aj_ctrl_onoff_t oven = {
 *     .pv = 0,
 *     .sp = 250,
 *     .hysteresis = 10
 * };
 * @endcode
 */

/**
 * @brief ON/OFF controller with symmetric hysteresis.
 *
 * This function evaluates the relationship between the process value (pv)
 * and the setpoint (sp) using a symmetric hysteresis band.
 *
 * The switching thresholds are defined as:
 *   lower = sp - (hysteresis / 2)
 *   upper = sp + (hysteresis / 2)
 *
 * Behavior:
 *   - If pv <= lower : returns AJ_CTRL_ONOFF_LOW
 *   - If pv >= upper : returns AJ_CTRL_ONOFF_HIGH
 *   - Otherwise      : returns AJ_CTRL_ONOFF_NONE
 *
 * @param[in] params  Pointer to control parameters:
 *                    - pv         : Current process value
 *                    - sp         : Setpoint value
 *                    - hysteresis : Total hysteresis band width
 *
 * @return aj_ctrl_onof_cmd_t
 *         - AJ_CTRL_ONOFF_LOW   : Process value is below lower threshold
 *         - AJ_CTRL_ONOFF_HIGH  : Process value is above upper threshold
 *         - AJ_CTRL_ONOFF_NONE  : Process value is within hysteresis band
 */
aj_ctrl_onof_cmd_t AJ_Ctrl_OnOff_Update(const aj_ctrl_onoff_t *params);

#ifdef __cplusplus
}
#endif

#endif

