// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef CONTROLLER_PID_INCLUDED
#define CONTROLLER_PID_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

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

#ifndef CONTROLLER_PID_HARDWARE_EXTERA
#define CONTROLLER_PID_HARDWARE_EXTERA
    #define PID_SCALE PID_SCALE_1024

    //#warning "CONTROLLER_PID_HARDWARE_EXTERA is not defined; default configuration will be used."
#endif

#define PID_FLOAT_TO_Q(x, scale)    ((int32_t)((x) * (float)(1UL << (scale)) + 0.5f))

int32_t Ctrl_PID_Update(CtrlPID_t *p);

#ifdef __cplusplus
}
#endif

#endif
