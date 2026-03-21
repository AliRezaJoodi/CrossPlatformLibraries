// GitHub Account:  GitHub.com/AliRezaJoodi

#include "controller_onoff.h"

//******************************************
Ctrl_OnOff_Cmd_t Controller_OnOff(const Ctrl_OnOff_t *params){
    int32_t half = params->hysteresis >> 1;

    if(params->pv <= (params->sp - half)){
        return CTRL_ONOFF_LOW;
    }
    else if(params->pv >= (params->sp + half)){
        return CTRL_ONOFF_HIGH;
    }

    return CTRL_ONOFF_NONE;
}
