// GitHub Account:  GitHub.com/AliRezaJoodi

#include "compiler_port.h"
#include "aj_gpio_config.h"
#include "aj_gpio_type.h"
#include "aj_gpio.h"

#if (AJ_MCU_SUPPORT_PORTA == 1U)
    AJ_GPIO_PortReg_t GPIOA = {
        .pin  = &PINA,
        .ddr  = &DDRA,
        .port = &PORTA
    };
#endif

#if (AJ_MCU_SUPPORT_PORTB == 1U)
    AJ_GPIO_PortReg_t GPIOB = {
        .pin   = &PINB,
        .ddr   = &DDRB,
        .port  = &PORTB
    };
#endif

#if (AJ_MCU_SUPPORT_PORTC == 1U)
    AJ_GPIO_PortReg_t GPIOC = {
        .pin   = &PINC,
        .ddr   = &DDRC,
        .port  = &PORTC
    };
#endif

#if (AJ_MCU_SUPPORT_PORTD == 1U)
    AJ_GPIO_PortReg_t GPIOD = {
        .pin   = &PIND,
        .ddr   = &DDRD,
        .port  = &PORTD
    };
#endif

#if (AJ_MCU_SUPPORT_PORTE == 1U)
    AJ_GPIO_PortReg_t GPIOE = {
        .pin   = &PINE,
        .ddr   = &DDRE,
        .port  = &PORTE
    };
#endif

#if (AJ_MCU_SUPPORT_PORTF == 1U)
    AJ_GPIO_PortReg_t GPIOF = {
        .pin   = &PINF,
        .ddr   = &DDRF,
        .port  = &PORTF
    };
#endif

