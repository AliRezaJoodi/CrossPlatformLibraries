// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_PWR_TYPE_INCLUDED
#define AJ_PWR_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

/******************************************************************************/
/* PVD level selection                                                        */
/******************************************************************************/
/**
 * @brief PVD voltage threshold selected by the PLS[2:0] bits in PWR_CR.
 *        Values match the hardware field values.
 */
typedef enum{
	AJ_PWR_PVD_2V2 = 0U,	/**< PVD threshold 2.2 V */
	AJ_PWR_PVD_2V3 = 1U,	/**< PVD threshold 2.3 V */
	AJ_PWR_PVD_2V4 = 2U,	/**< PVD threshold 2.4 V */
	AJ_PWR_PVD_2V5 = 3U,	/**< PVD threshold 2.5 V */
	AJ_PWR_PVD_2V6 = 4U,	/**< PVD threshold 2.6 V */
	AJ_PWR_PVD_2V7 = 5U,	/**< PVD threshold 2.7 V */
	AJ_PWR_PVD_2V8 = 6U,	/**< PVD threshold 2.8 V */
	AJ_PWR_PVD_2V9 = 7U	/**< PVD threshold 2.9 V */
} aj_pwr_pvd_level_t;

/******************************************************************************/
/* Flag clear selection                                                       */
/******************************************************************************/
/**
 * @brief Flag(s) to clear in PWR_CR. Values are the clear bits of PWR_CR and
 *        can be combined with the bitwise OR operator.
 */
typedef enum{
	AJ_PWR_FLAG_CLEAR_STANDBY = PWR_CR_CSBF_Msk,	/**< Standby flag (SBF) */
	AJ_PWR_FLAG_CLEAR_WAKEUP  = PWR_CR_CWUF_Msk	/**< Wakeup flag (WUF) */
} aj_pwr_flag_clear_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_PWR_TYPE_INCLUDED */
