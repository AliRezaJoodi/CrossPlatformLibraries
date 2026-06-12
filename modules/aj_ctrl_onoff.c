// GitHub Account:  GitHub.com/AliRezaJoodi

#include <stdint.h>
#include "aj_ctrl_onoff.h"

//******************************************
aj_ctrl_onof_cmd_t AJ_Ctrl_OnOff_Update(const aj_ctrl_onoff_t *params){
    int32_t half = params->hysteresis >> 1;

    if(params->pv <= (params->sp - half)){
        return AJ_CTRL_ONOFF_LOW;
    }
    else if(params->pv >= (params->sp + half)){
        return AJ_CTRL_ONOFF_HIGH;
    }

    return AJ_CTRL_ONOFF_NONE;
}
