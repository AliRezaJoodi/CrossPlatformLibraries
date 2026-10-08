// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef AJ_EXTI_TYPE_INCLUDED
#define AJ_EXTI_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#include <stm32f1xx.h>

/******************************************************************************/
/* Line mask                                                                  */
/******************************************************************************/
/**
 * @brief EXTI line mask (one bit per line) usable with every EXTI register
 *        (IMR, EMR, RTSR, FTSR, SWIER, PR).
 *        Lines 16-31 are declared only when the selected device defines them.
 */
typedef enum{
	AJ_EXTI_LINE_0  = EXTI_IMR_IM0,   /*< Extended line 0 */
	AJ_EXTI_LINE_1  = EXTI_IMR_IM1,   /*< Extended line 1 */
	AJ_EXTI_LINE_2  = EXTI_IMR_IM2,   /*< Extended line 2 */
	AJ_EXTI_LINE_3  = EXTI_IMR_IM3,   /*< Extended line 3 */
	AJ_EXTI_LINE_4  = EXTI_IMR_IM4,   /*< Extended line 4 */
	AJ_EXTI_LINE_5  = EXTI_IMR_IM5,   /*< Extended line 5 */
	AJ_EXTI_LINE_6  = EXTI_IMR_IM6,   /*< Extended line 6 */
	AJ_EXTI_LINE_7  = EXTI_IMR_IM7,   /*< Extended line 7 */
	AJ_EXTI_LINE_8  = EXTI_IMR_IM8,   /*< Extended line 8 */
	AJ_EXTI_LINE_9  = EXTI_IMR_IM9,   /*< Extended line 9 */
	AJ_EXTI_LINE_10 = EXTI_IMR_IM10,  /*< Extended line 10 */
	AJ_EXTI_LINE_11 = EXTI_IMR_IM11,  /*< Extended line 11 */
	AJ_EXTI_LINE_12 = EXTI_IMR_IM12,  /*< Extended line 12 */
	AJ_EXTI_LINE_13 = EXTI_IMR_IM13,  /*< Extended line 13 */
	AJ_EXTI_LINE_14 = EXTI_IMR_IM14,  /*< Extended line 14 */
	AJ_EXTI_LINE_15 = EXTI_IMR_IM15,  /*< Extended line 15 */

	#if defined(EXTI_IMR_IM16)
		AJ_EXTI_LINE_16 = EXTI_IMR_IM16,  /*< Extended line 16 */
	#endif

	#if defined(EXTI_IMR_IM17)
		AJ_EXTI_LINE_17 = EXTI_IMR_IM17,  /*< Extended line 17 */
	#endif

	#if defined(EXTI_IMR_IM18)
		AJ_EXTI_LINE_18 = EXTI_IMR_IM18,  /*< Extended line 18 */
	#endif

	#if defined(EXTI_IMR_IM19)
		AJ_EXTI_LINE_19 = EXTI_IMR_IM19,  /*< Extended line 19 */
	#endif

	#if defined(EXTI_IMR_IM20)
		AJ_EXTI_LINE_20 = EXTI_IMR_IM20,  /*< Extended line 20 */
	#endif

	#if defined(EXTI_IMR_IM21)
		AJ_EXTI_LINE_21 = EXTI_IMR_IM21,  /*< Extended line 21 */
	#endif

	#if defined(EXTI_IMR_IM22)
		AJ_EXTI_LINE_22 = EXTI_IMR_IM22,  /*< Extended line 22 */
	#endif

	#if defined(EXTI_IMR_IM23)
		AJ_EXTI_LINE_23 = EXTI_IMR_IM23,  /*< Extended line 23 */
	#endif

	#if defined(EXTI_IMR_IM24)
		AJ_EXTI_LINE_24 = EXTI_IMR_IM24,  /*< Extended line 24 */
	#endif

	#if defined(EXTI_IMR_IM25)
		AJ_EXTI_LINE_25 = EXTI_IMR_IM25,  /*< Extended line 25 */
	#endif

	#if defined(EXTI_IMR_IM26)
		AJ_EXTI_LINE_26 = EXTI_IMR_IM26,  /*< Extended line 26 */
	#endif

	#if defined(EXTI_IMR_IM27)
		AJ_EXTI_LINE_27 = EXTI_IMR_IM27,  /*< Extended line 27 */
	#endif

	#if defined(EXTI_IMR_IM28)
		AJ_EXTI_LINE_28 = EXTI_IMR_IM28,  /*< Extended line 28 */
	#endif

	#if defined(EXTI_IMR_IM29)
		AJ_EXTI_LINE_29 = EXTI_IMR_IM29,  /*< Extended line 29 */
	#endif

	#if defined(EXTI_IMR_IM30)
		AJ_EXTI_LINE_30 = EXTI_IMR_IM30,  /*< Extended line 30 */
	#endif

	#if defined(EXTI_IMR_IM31)
		AJ_EXTI_LINE_31 = EXTI_IMR_IM31,  /*< Extended line 31 */
	#endif

	AJ_EXTI_LINE_ALL = 0xFFFFFFFFU    /*< All extended lines */
} aj_exti_line_mask_t;


#ifdef __cplusplus
}
#endif

#endif	/* AJ_EXTI_TYPE_INCLUDED */
