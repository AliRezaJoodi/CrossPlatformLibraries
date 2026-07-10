#ifndef AJ_BUTTON_TYPE_PLATFORM_INCLUDED
#define AJ_BUTTON_TYPE_PLATFORM_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/**
 * @brief Hardware configuration for a button.
 *
 * This structure holds the hardware registers and pin index
 * for a button. It is used inside the Button_t structure.
 */
typedef struct {
    volatile uint8_t    *ddr;      /**< Data Direction Register */
    volatile uint8_t    *port;     /**< Port register */
    volatile uint8_t    *pin;      /**< Pin register */
    const uint8_t       mask;
} aj_button_pin_t;



#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUTTON_TYPE_PLATFORM_INCLUDED */
