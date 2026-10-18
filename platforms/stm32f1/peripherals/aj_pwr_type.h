// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_PWR_TYPE_INCLUDED
#define AJ_PWR_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

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

/**
 * @brief Flag(s) to clear in PWR_CR. Values are the clear bits of PWR_CR and
 *        can be combined with the bitwise OR operator.
 */
typedef enum{
	AJ_PWR_FLAG_CLEAR_STANDBY = PWR_CR_CSBF_Msk,	/**< Standby flag (SBF) */
	AJ_PWR_FLAG_CLEAR_WAKEUP  = PWR_CR_CWUF_Msk	/**< Wakeup flag (WUF) */
} aj_pwr_flag_clear_t;

/**
 * @brief Low-power mode entered when the CPU enters deepsleep, set by the
 *        PDDS and LPDS bits in PWR_CR. Values are the combined field value.
 */
typedef enum{
	AJ_PWR_DEEPSLEEP_STOP_MODE           = 0U,	/**< PDDS=0, LPDS=0: Stop mode, regulator on */
	AJ_PWR_DEEPSLEEP_STOP_LOW_POWER_MODE = 1U,	/**< PDDS=0, LPDS=1: Stop mode, regulator low-power */
	AJ_PWR_DEEPSLEEP_STANDBY_MODE        = 2U	/**< PDDS=1: Standby mode (LPDS is don't care) */
} aj_pwr_deepsleep_t;

/**
 * @brief Readable status flags in PWR_CSR. Values are the flag bits of
 *        PWR_CSR and can be combined with the bitwise OR operator.
 */
typedef enum{
	AJ_PWR_FLAG_PVDO    = PWR_CSR_PVDO_Msk,	/**< PVD output (valid only if PVD enabled) */
	AJ_PWR_FLAG_STANDBY = PWR_CSR_SBF_Msk,	/**< Standby flag (SBF) */
	AJ_PWR_FLAG_WAKEUP  = PWR_CSR_WUF_Msk	/**< Wakeup flag (WUF) */
} aj_pwr_flag_status_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_PWR_TYPE_INCLUDED */
