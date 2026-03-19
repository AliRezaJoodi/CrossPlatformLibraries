// GitHub Account:  GitHub.com/AliRezaJoodi

#include "controller_onoff.h"

//******************************************
CtrlCmd_t Controller_OnOff(uint16_t pv, uint16_t sp, uint16_t hysteresis){
    uint16_t half = hysteresis >> 1;

    if(sp < half){
        return CTRL_ONOFF_ERROR;
    }

    if(pv < (sp - half)){
        return CTRL_ONOFF_LOW;
    }
    else if(pv > (sp + half)){
        return CTRL_ONOFF_HIGH;
    }

    return CTRL_ONOFF_NONE;
}
