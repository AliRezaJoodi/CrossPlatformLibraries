#ifndef AJ_TYPE_INCLUDED
#define AJ_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "aj_target.h"

#if AJ_TARGET_MCU_BITS == 32U
    typedef uint32_t aj_uint_t;
    typedef volatile uint32_t aj_volatile_uint_t;
    typedef const volatile uint32_t aj_const_volatile_uint_t;
#elif AJ_TARGET_MCU_BITS == 16U
    typedef uint16_t aj_uint_t;
    typedef volatile uint16_t aj_volatile_uint_t;
    typedef const volatile uint16_t aj_const_volatile_uint_t;
#elif AJ_TARGET_MCU_BITS == 8U
    typedef uint8_t aj_uint_t;
    typedef volatile uint8_t aj_volatile_uint_t;
    #if defined(__CODEVISIONAVR__)
        typedef volatile uint8_t aj_const_volatile_uint_t;
    #else
        typedef const volatile uint8_t aj_const_volatile_uint_t;
    #endif
#endif

typedef enum {
	AJ_BIT_CLEAR = 0U,
	AJ_BIT_SET   = 1U
} aj_bit_state_t;

typedef enum {
	AJ_OPERATION_DISABLE = 0U,
	AJ_OPERATION_ENABLE  = 1U
} aj_operation_state_t;

typedef enum {
	AJ_POWER_OFF = 0U,
	AJ_POWER_ON  = 1U
} aj_power_state_t;

typedef enum {
	AJ_LINE_ASSERTED = 0U,
	AJ_LINE_IDLE     = 1U
} aj_line_state_t;

typedef enum {
	AJ_SPI_CS_SELECT   = 0U,
	AJ_SPI_CS_DESELECT = 1U
} aj_spi_cs_state_t;

typedef enum {
	AJ_VALIDITY_INVALID = 0U,
	AJ_VALIDITY_VALID   = 1U
} aj_validity_state_t;

typedef enum {
	AJ_CONFIG_SUCCESS = 0U,
	AJ_CONFIG_FAILURE = 1U
} aj_config_state_t;

typedef enum {
	AJ_RESULT_SUCCESS = 0U,
	AJ_RESULT_FAILURE = 1U
} aj_result_state_t;

typedef enum {
	AJ_TEST_PASS = 0U,
	AJ_TEST_FAIL = 1U
} aj_test_state_t;


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TYPE_INCLUDED */