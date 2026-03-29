/**
 * @brief   Fixed-point PID controller library header.
 *
 * This library provides a platform-independent PID controller
 * implementation using integer math (fixed-point, Q-format).
 * Includes proportional, integral, derivative terms with anti-windup
 * and configurable sampling intervals.
 *
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */

#ifndef CONTROLLER_PID_INCLUDED
#define CONTROLLER_PID_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @enum PID_Scale_t
 * @brief Fixed-point scaling factors for PID gains.
 *
 * Each enum value represents a power-of-two scale used for converting
 * floating-point gains to integer representation:
 *   Fixed-point value = float_value * 2^scale
 *
 * Use in combination with PID_FLOAT_TO_Q macro.
 */
typedef enum {
    PID_SCALE_1       = 0,   /**< 2^0 */
    PID_SCALE_2       = 1,   /**< 2^1 */
    PID_SCALE_4       = 2,   /**< 2^2 */
    PID_SCALE_8       = 3,   /**< 2^3 */
    PID_SCALE_16      = 4,   /**< 2^4 */
    PID_SCALE_32      = 5,   /**< 2^5 */
    PID_SCALE_64      = 6,   /**< 2^6 */
    PID_SCALE_128     = 7,   /**< 2^7 */
    PID_SCALE_256     = 8,   /**< 2^8 */
    PID_SCALE_512     = 9,   /**< 2^9 */
    PID_SCALE_1024    = 10,  /**< 2^10 */
    PID_SCALE_2048    = 11,  /**< 2^11 */
    PID_SCALE_4096    = 12,  /**< 2^12 */
    PID_SCALE_8192    = 13,  /**< 2^13 */
    PID_SCALE_16384   = 14,  /**< 2^14 */
    PID_SCALE_32768   = 15,  /**< 2^15 */
    PID_SCALE_65536   = 16,  /**< 2^16 */
    PID_SCALE_131072  = 17   /**< 2^17 */
} PID_Scale_t;

/**
 * @enum PID_Dt_t
 * @brief Discrete sampling interval exponents (ms).
 *
 * Each value represents a power-of-two multiple of 1 ms:
 *   Actual dt in ms = 2^DT
 */
typedef enum {
    PID_DT_1MS    = 0,   /**< 2^0 ms */
    PID_DT_2MS    = 1,   /**< 2^1 ms */
    PID_DT_4MS    = 2,   /**< 2^2 ms */
    PID_DT_8MS    = 3,   /**< 2^3 ms */
    PID_DT_16MS   = 4,   /**< 2^4 ms */
    PID_DT_32MS   = 5,   /**< 2^5 ms */
    PID_DT_64MS   = 6,   /**< 2^6 ms */
    PID_DT_128MS  = 7,   /**< 2^7 ms */
    PID_DT_256MS  = 8,   /**< 2^8 ms */
    PID_DT_512MS  = 9    /**< 2^9 ms */
} PID_Dt_t;

/**
 * @struct CtrlPID_t
 * @brief PID controller instance (configuration + runtime state)
 *
 * This struct contains both the fixed configuration parameters (const)
 * and runtime variables for a single PID loop.
 */
typedef struct {
    const int32_t kp;
    const int32_t ki;
    const int32_t kd;

    const int32_t output_min;
    const int32_t output_max;
    const PID_Scale_t scale;
    const PID_Dt_t dt;

    int32_t i_sum;
    int32_t error_last;

    int32_t sp;
    int32_t pv;
} CtrlPID_t;

/**
 * @brief Default scaling factor used for PID_FLOAT_TO_Q macro
 *
 * Override CONTROLLER_PID_HARDWARE_EXTERA in your project if needed.
 */
#ifndef CONTROLLER_PID_HARDWARE_EXTERA
#define CONTROLLER_PID_HARDWARE_EXTERA
    #define PID_SCALE PID_SCALE_1024

    //#warning "CONTROLLER_PID_HARDWARE_EXTERA is not defined; default configuration will be used."
#endif

/**
 * @brief Convert floating-point PID gain to fixed-point Q-format.
 *
 * @param x       Floating-point gain
 * @param scale   PID_Scale_t exponent (2^scale multiplier)
 * @return        Fixed-point int32_t representation (rounded)
 *
 * @note  Useful for initializing PID_Config_t constants.
 */
#define PID_FLOAT_TO_Q(x, scale)    ((int32_t)((x) * (float)(1UL << (scale)) + 0.5f))

/**
 * @brief Update PID controller output.
 *
 * Performs proportional, integral, derivative calculation with:
 *   - Integral accumulation with dt scaling
 *   - Anti-windup (limits integral term based on output saturation)
 *   - Saturated PID output
 *
 * @param p   Pointer to CtrlPID_t instance
 * @return    int32_t Saturated PID output
 *
 * @note    Call this function periodically according to the PID loop rate.
 */
int32_t Ctrl_PID_Update(CtrlPID_t *pid);

/**
 * @brief Reset PID controller runtime state.
 *
 * Sets the integral accumulator and last error to zero.
 * Does NOT modify configuration parameters (kp, ki, kd, etc.).
 *
 * @param p Pointer to the PID controller instance
 */
void Ctrl_PID_Reset(CtrlPID_t *pid);

#ifdef __cplusplus
}
#endif

#endif  // CONTROLLER_PID_INCLUDED

