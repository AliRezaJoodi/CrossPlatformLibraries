// GitHub Account:  GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "controller_pid.h"

// ********************************************
int32_t Ctrl_PID_Update(CtrlPID_t *p){
    int32_t error;
    int32_t p_term;
    int32_t i_term, i_max, i_min, buf;
    int32_t d_term;
    int32_t output;

    // Calculate error
    error = p->sp - p->pv;

    // Proportional term
    p_term = (p->kp * error);
    p_term = p_term >> p->scale;

    // Derivative term (with dt)
    d_term = p->kd * (((error - p->error_last) << 10) >> p->dt);
    d_term = d_term >> p->scale;
    p->error_last = error;  // Store current error for next iteration

    // Integral term accumulation (with dt)
    buf = p->i_sum + ((error << p->dt) >> 10);

    i_term = p->ki * buf;
    i_term = i_term >> p->scale;

    // Anti-windup: limit integral term
    i_max = p->output_max - p_term - d_term;
    i_min = p->output_min - p_term - d_term;

    if (i_term > i_max){
        i_term = i_max;
    }
    else if (i_term < i_min){
        i_term = i_min;
    }
    else{
        p->i_sum = buf;
    }

    // Compute PID output
    output = p_term + i_term + d_term;

    // Output clamp
    if (output > p->output_max) {
        output = p->output_max;
    }
    else if (output < p->output_min) {
        output = p->output_min;
    }

    return output;
}

// ********************************************
void Ctrl_PID_Reset(CtrlPID_t *p){
    p->error_last = 0;
    p->i_sum = 0;
}


