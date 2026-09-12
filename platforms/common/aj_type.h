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
	AJ_CLEAR = 0U,
	AJ_SET   = 1U
} aj_bit_state_t;

typedef enum {
	AJ_DISABLE = 0U,
	AJ_ENABLE  = 1U
} aj_operation_state_t;

typedef enum {
	AJ_OFF = 0U,
	AJ_ON  = 1U
} aj_power_state_t;

typedef enum {
	AJ_ASSERTED = 0U,
	AJ_IDLE     = 1U
} aj_line_state_t;

typedef enum {
	AJ_SELECT   = 0U,
	AJ_DESELECT = 1U
} aj_spi_cs_state_t;

typedef enum {
	AJ_INVALID = 0U,
	AJ_VALID   = 1U
} aj_validity_state_t;

typedef enum {
	AJ_SUCCESS = 0U,
	AJ_FAILURE = 1U
} aj_result_state_t;

typedef enum {
	AJ_PASS = 0U,
	AJ_FAIL = 1U
} aj_test_state_t;


#ifdef __cplusplus
}
#endif

#endif  /* AJ_TYPE_INCLUDED */