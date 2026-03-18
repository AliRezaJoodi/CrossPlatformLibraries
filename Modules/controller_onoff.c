// GitHub Account:  GitHub.com/AliRezaJoodi

#include "controller_onoff.h"

//******************************************
uint8_t Controller_OnOff(uint16_t pv, uint16_t sp, uint16_t hys){
    if(sp < hys){
        return 3;   // error
    }

    if(pv < (sp - hys)){
        return 1;
    }
    else if(pv > (sp + hys)){
        return 2;
    }

    return 0;
}
