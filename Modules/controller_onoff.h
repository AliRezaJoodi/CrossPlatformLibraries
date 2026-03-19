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
    CTRL_ONOFF_ERROR        /**< Invalid parameters */
} CtrlCmd_t;

/**
 * @brief ON/OFF controller with hysteresis.
 *
 * Determines the relation of the process value (pv) to the setpoint (sp)
 * using a symmetric hysteresis band.
 *
 * Thresholds:
 *   lower = sp - (hysteresis / 2)
 *   upper = sp + (hysteresis / 2)
 *
 * @param pv           Current process value
 * @param sp           Setpoint value
 * @param hysteresis   Total hysteresis band width
 *
 * @return CtrlCmd_t
 *         - CTRL_ONOFF_LOW   : pv < lower threshold
 *         - CTRL_ONOFF_HIGH  : pv > upper threshold
 *         - CTRL_ONOFF_NONE  : pv within band
 *         - CTRL_ONOFF_ERROR : invalid input parameters
 */
CtrlCmd_t Controller_OnOff(uint16_t pv, uint16_t sp, uint16_t hysteresis);

#ifdef __cplusplus
}
#endif

#endif

