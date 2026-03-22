// GitHub Account:  GitHub.com/AliRezaJoodi

#include "controller_pid.h"

int32_t Ctrl_PID_Update2(CtrlPID_t *p){
    int32_t error;
    int32_t value_p;
    int32_t value_d;
    int32_t output;

    // Calculate error
    error = p->sp - p->pv;

    // Proportional term
    value_p = (int32_t)((p->kp * error) >> p->scale);

    // Integral term accumulation
    p->value_i += (int32_t)((p->ki * error) >> p->scale);

    // Anti-windup: limit integral term
    if (p->value_i > p->max_i) p->value_i = p->max_i;
    if (p->value_i < p->min_i) p->value_i = p->min_i;

    // Derivative term
    value_d = (int32_t)((p->kd * (error - p->error_last)) >> p->scale);

    // Store current error for next iteration
    p->error_last = error;

    // Compute PID output
    output = value_p + p->value_i + value_d;

    return output;
}

//******************************************
float Ctrl_PID_Update(float sp, float pv){
    float error = 0;
    static float error_last = 0;
    float value_p = 0;
    static float value_i = 0;
    float value_d = 0;
    float value_pid = 0;

    error = sp - pv;
    value_p = KP * error;
    value_i += KI * error;
    value_d = KD * (error - error_last);
    error_last = error;
    value_pid = value_p + value_i + value_d;

    return value_pid;
}

