// GitHub Account:  GitHub.com/AliRezaJoodi

#include "compiler_port.h"
#include "gpio_config.h"
#include "gpio_type.h"
#include "gpio.h"

#if (MCU_SUPPORT_PORTA == 1U)
    GPIO_PortReg_t GPIOA = {
        .pin  = &PINA,
        .ddr  = &DDRA,
        .port = &PORTA
    };
#endif

#if (MCU_SUPPORT_PORTB == 1U)
    GPIO_PortReg_t GPIOB = {
        .pin   = &PINB,
        .ddr   = &DDRB,
        .port  = &PORTB
    };
#endif

#if (MCU_SUPPORT_PORTC == 1U)
    GPIO_PortReg_t GPIOC = {
        .pin   = &PINC,
        .ddr   = &DDRC,
        .port  = &PORTC
    };
#endif

#if (MCU_SUPPORT_PORTD == 1U)
    GPIO_PortReg_t GPIOD = {
        .pin   = &PIND,
        .ddr   = &DDRD,
        .port  = &PORTD
    };
#endif

#if (MCU_SUPPORT_PORTE == 1U)
    GPIO_PortReg_t GPIOE = {
        .pin   = &PINE,
        .ddr   = &DDRE,
        .port  = &PORTE
    };
#endif

#if (MCU_SUPPORT_PORTF == 1U)
    GPIO_PortReg_t GPIOF = {
        .pin   = &PINF,
        .ddr   = &DDRF,
        .port  = &PORTF
    };
#endif

