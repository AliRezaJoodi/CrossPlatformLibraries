// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>

#include "hardware.h"
#include "aj_ctrl_pid.h"

// ********************************************
int32_t AJ_Ctrl_PID_Update(aj_ctrl_pid_t *pid){
    int32_t error;
    int32_t p_term;
    int32_t i_term, i_max, i_min, buf;
    int32_t d_term;
    int32_t output;

    // Calculate error
    error = pid->sp - pid->pv;

    // Proportional term
    p_term = (pid->kp * error);
    p_term = p_term >> pid->scale;

    // Derivative term (with dt)
    d_term = pid->kd * (((error - pid->error_last) << 10) >> pid->dt);
    d_term = d_term >> pid->scale;
    pid->error_last = error;  // Store current error for next iteration

    // Integral term accumulation (with dt)
    buf = pid->i_sum + ((error << pid->dt) >> 10);

    i_term = pid->ki * buf;
    i_term = i_term >> pid->scale;

    // Anti-windup: limit integral term
    i_max = pid->output_max - p_term - d_term;
    i_min = pid->output_min - p_term - d_term;

    if (i_term > i_max){
        i_term = i_max;
    }
    else if (i_term < i_min){
        i_term = i_min;
    }
    else{
        pid->i_sum = buf;
    }

    // Compute PID output
    output = p_term + i_term + d_term;

    // Output clamp
    if (output > pid->output_max) {
        output = pid->output_max;
    }
    else if (output < pid->output_min) {
        output = pid->output_min;
    }

    return output;
}

// ********************************************
void AJ_Ctrl_PID_Reset(aj_ctrl_pid_t *pid){
    pid->error_last = 0;
    pid->i_sum = 0;
}


