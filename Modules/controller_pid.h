// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef CONTROLLER_PID_INCLUDED
#define CONTROLLER_PID_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef CONTROLLER_PID_HARDWARE
#define CONTROLLER_PID_HARDWARE
    #define KP 5 //(0.5 * 10.23) // 5.115
    #define KI 0 //(0.000005 * 10.23) // 0.00005115
    #define KD 10 //(0.1 * 10.23)    // 1.023
#endif

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

typedef struct {
    const int32_t kp;
    const int32_t ki;
    const int32_t kd;

    const int32_t output_min;
    const int32_t output_max;
    const PID_Scale_t scale;
    const int32_t dt;

    int32_t value_i;
    int32_t error_last;

    int32_t sp;
    int32_t pv;
} CtrlPID_t;

int32_t Ctrl_PID_Update2(CtrlPID_t *p);
//float Ctrl_PID_Update(float sp, float pv);

#ifdef __cplusplus
}
#endif

#endif
