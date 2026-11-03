
#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_type.h"
#include "aj_flash.h"

aj_result_state_t AJ_Flash_InitLatency(uint32_t core_clock_hz){
	if ((core_clock_hz == 0U) || (core_clock_hz > 72000000U)){
		return AJ_FAILURE;
	}

	if (core_clock_hz <= 24000000U){
		AJ_Flash_ConfigureLatency(AJ_FLASH_LATENCY_0);
	}
	else if (core_clock_hz <= 48000000U){
		AJ_Flash_ConfigureLatency(AJ_FLASH_LATENCY_1);
	}
	else{
		AJ_Flash_ConfigureLatency(AJ_FLASH_LATENCY_2);
	}

	return AJ_SUCCESS;
}