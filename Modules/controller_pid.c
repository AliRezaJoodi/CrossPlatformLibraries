// GitHub Account:  GitHub.com/AliRezaJoodi

#include "hardware.h"
#include "controller_pid.h"

int32_t Ctrl_PID_Update2(CtrlPID_t *p){
    int32_t error;
    int32_t p_term;
    int32_t i_term;
    int32_t d_term;
    int32_t output;

    // Calculate error
    error = p->sp - p->pv;

    // Proportional term
    p_term = (error * p->kp) >> p->scale;

    // Integral term accumulation (with dt)
    p->i_sum += ((error << p->dt) >> 10);
    i_term = (p->i_sum * p->ki) >>  p->scale;

    // Anti-windup: limit integral term
//    if (value_i2 > p->output_max) {value_i2 = p->output_max;}
//    else if (value_i2 < p->output_min) {value_i2 = p->output_min;}

    // Derivative term (with dt)
    d_term = ((((error - p->error_last) << 10) >> p->dt) * p->kd) >> p->scale;

    // Store current error for next iteration
    p->error_last = error;

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

//int32_t Ctrl_PID_Update2_(CtrlPID_t *p){
//    int32_t error;
//    int32_t value_p;
//    int32_t value_d;
//    int32_t output;
//
//    // Calculate error
//    error = p->sp - p->pv;
//
//    // Proportional term
//    value_p = (p->kp * error) >> p->scale;
//
//    // Integral term accumulation
//    p->value_i += (p->ki * error) >> p->scale;
//
//    // Anti-windup: limit integral term
//    if (p->value_i > p->output_max) p->value_i = p->output_max;
//    if (p->value_i < p->output_min) p->value_i = p->output_min;
//
//    // Derivative term
//    value_d = (p->kd * (error - p->error_last)) >> p->scale;
//
//    // Store current error for next iteration
//    p->error_last = error;
//
//    // Compute PID output
//    output = value_p + p->value_i + value_d;
//    if (output > p->output_max) {output = p->output_max;}
//    if (output < p->output_min) {output = p->output_min;}
//
//    return output;
//}

////******************************************
//float Ctrl_PID_Update(float sp, float pv){
//    float error = 0;
//    static float error_last = 0;
//    float value_p = 0;
//    static float value_i = 0;
//    float value_d = 0;
//    float value_pid = 0;
//
//    error = sp - pv;
//    value_p = KP * error;
//    value_i += KI * error;
//    value_d = KD * (error - error_last);
//    error_last = error;
//    value_pid = value_p + value_i + value_d;
//
//    return value_pid;
//}

