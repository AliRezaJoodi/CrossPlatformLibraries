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

#ifndef CONTROLLER_ONOFF_INCLUDED
#define CONTROLLER_ONOFF_INCLUDED

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
    CTRL_ONOFF_NONE = 0,    /**< Value is within hysteresis band (no action) */
    CTRL_ONOFF_LOW,         /**< Value is below lower threshold */
    CTRL_ONOFF_HIGH,        /**< Value is above upper threshold */
} Ctrl_OnOff_Cmd_t;

typedef struct {
    int32_t pv;         /**< Current process value */
    int32_t sp;         /**< Setpoint value*/
    int32_t hysteresis; /**< Hysteresis range */
} Ctrl_OnOff_t;

/**
 * @example
 * Example: initializing a structure
 *
 * @code
 * Ctrl_OnOff_t oven = {
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
 *   - If pv <= lower : returns CTRL_ONOFF_LOW
 *   - If pv >= upper : returns CTRL_ONOFF_HIGH
 *   - Otherwise      : returns CTRL_ONOFF_NONE
 *
 * @param[in] params  Pointer to control parameters:
 *                    - pv         : Current process value
 *                    - sp         : Setpoint value
 *                    - hysteresis : Total hysteresis band width
 *
 * @return CtrlCmd_t
 *         - CTRL_ONOFF_LOW   : Process value is below lower threshold
 *         - CTRL_ONOFF_HIGH  : Process value is above upper threshold
 *         - CTRL_ONOFF_NONE  : Process value is within hysteresis band
 */
Ctrl_OnOff_Cmd_t Controller_OnOff(const Ctrl_OnOff_t *params);

#ifdef __cplusplus
}
#endif

#endif

