// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef GPIO_CONFIG_INCLUDED
#define GPIO_CONFIG_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "hardware.h"

#ifndef GPIO_CONFIG
#define GPIO_CONFIG
    #define MCU_SUPPORT_PORTA    1U
    #define MCU_SUPPORT_PORTB    1U
    #define MCU_SUPPORT_PORTC    1U
    #define MCU_SUPPORT_PORTD    1U
    #define MCU_SUPPORT_PORTE    0U
    #define MCU_SUPPORT_PORTF    0U

	#warning "GPIO_CONFIG is not defined; default configuration will be used."
#endif

#ifdef __cplusplus
}
#endif

#endif  /* GPIO_CONFIG_INCLUDED */
