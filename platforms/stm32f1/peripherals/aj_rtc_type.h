// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_RTC_TYPE_INCLUDED
#define AJ_RTC_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

/******************************************************************************/
/* Status register (RTC_CRL)                                                  */
/******************************************************************************/
/**
 * @brief RTC read-only flags (RTOFF) and flags readable by software.
 */
typedef enum{
	AJ_RTC_FLAG_R_SECF  = RTC_CRL_SECF_Msk,  /*< Second flag */
	AJ_RTC_FLAG_R_ALRF  = RTC_CRL_ALRF_Msk,  /*< Alarm flag */
	AJ_RTC_FLAG_R_OWF   = RTC_CRL_OWF_Msk,   /*< Overflow flag */
	AJ_RTC_FLAG_R_RSF   = RTC_CRL_RSF_Msk,   /*< Registers synchronized flag */
	AJ_RTC_FLAG_R_RTOFF = RTC_CRL_RTOFF_Msk  /*< RTC operation OFF */
} aj_rtc_flag_r_t;

/**
 * @brief RTC flags cleared by software (by writing them to 0).
 *        RTOFF is not listed here because it is read-only.
 */
typedef enum{
	AJ_RTC_FLAG_W0_SECF = RTC_CRL_SECF_Msk,  /*< Second flag */
	AJ_RTC_FLAG_W0_ALRF = RTC_CRL_ALRF_Msk,  /*< Alarm flag */
	AJ_RTC_FLAG_W0_OWF  = RTC_CRL_OWF_Msk,   /*< Overflow flag */
	AJ_RTC_FLAG_W0_RSF  = RTC_CRL_RSF_Msk    /*< Registers synchronized flag */
} aj_rtc_flag_w0_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_RTC_TYPE_INCLUDED */