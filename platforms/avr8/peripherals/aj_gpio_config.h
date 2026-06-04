// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef AJ_GPIO_CONFIG_INCLUDED
#define AJ_GPIO_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"

#ifndef AJ_GPIO_CONFIG
#define AJ_GPIO_CONFIG
    #define AJ_MCU_SUPPORT_PORTA    1U
    #define AJ_MCU_SUPPORT_PORTB    1U
    #define AJ_MCU_SUPPORT_PORTC    1U
    #define AJ_MCU_SUPPORT_PORTD    1U
    #define AJ_MCU_SUPPORT_PORTE    0U
    #define AJ_MCU_SUPPORT_PORTF    0U

	#warning "AJ_GPIO_CONFIG is not defined; default configuration will be used."
#endif

#ifdef __cplusplus
}
#endif

#endif  /* AJ_GPIO_CONFIG_INCLUDED */
