#include "aj_flash.h"

#define AJ_FLASH_TIMEOUT    1000U

aj_result_state_t AJ_Flash_InitLatency(uint32_t sysclk_hz){
    uint32_t latency;
    uint16_t timeout = AJ_FLASH_TIMEOUT;

    if ((sysclk_hz == 0U) || (sysclk_hz > 72000000U)){
        return AJ_FAILURE;
    }

    if (sysclk_hz <= 24000000U){
        latency = AJ_FLASH_LATENCY_0;
    }
    else if (sysclk_hz <= 48000000U){
        latency = AJ_FLASH_LATENCY_1;
    }
    else{
        latency = AJ_FLASH_LATENCY_2;
    }

    AJ_Flash_ConfigureLatency(latency);

    while (AJ_Flash_GetLatency() != latency){
        if (--timeout == 0U){
            return AJ_FAILURE;
        }
    }

    return AJ_SUCCESS;
}