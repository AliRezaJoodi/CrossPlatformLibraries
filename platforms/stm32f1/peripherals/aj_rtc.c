// GitHub Account: GitHub.com/AliRezaJoodi

#include <stdint.h>
#include <stm32f1xx.h>
#include "aj_type.h"
#include "aj_rtc_type.h"
#include "aj_rtc.h"

#define AJ_RTC_TIMEOUT  1000U

/******************************************************************************/
/* Time counter registers (RTC_CNTL + RTC_CNTH)                               */
/******************************************************************************/
uint32_t AJ_RTC_ReadCounter(void){
  uint16_t high1 = 0U, high2 = 0U, low = 0U;

  do{
    high1 = RTC->CNTH & RTC_CNTH_RTC_CNT;
    low   = RTC->CNTL & RTC_CNTL_RTC_CNT;
    high2 = RTC->CNTH & RTC_CNTH_RTC_CNT;
  }while(high1 != high2);

  return (((uint32_t) high2 << 16U) | low);
}

void AJ_RTC_WriteCounter(uint32_t value){
  RTC->CNTH = (value >> 16U);
  RTC->CNTL = (value & 0xFFFFU);
}

/******************************************************************************/
/* Alarm registers (RTC_ALRL + RTC_ALRH)                                      */
/******************************************************************************/
uint32_t AJ_RTC_ReadAlarm(void){
  uint16_t high1 = 0U, high2 = 0U, low = 0U;

  do{
    high1 = RTC->ALRH & RTC_ALRH_RTC_ALR;
    low   = RTC->ALRL & RTC_ALRL_RTC_ALR;
    high2 = RTC->ALRH & RTC_ALRH_RTC_ALR;
  }while(high1 != high2);

  return (((uint32_t) high2 << 16U) | low);
}

void AJ_RTC_WriteAlarm(uint32_t value){
  RTC->ALRH = (value >> 16U);
  RTC->ALRL = (value & 0xFFFFU);
}

/******************************************************************************/
/* Prescaler load registers (RTC_PRLL + RTC_PRLH)                             */
/******************************************************************************/
uint32_t AJ_RTC_ReadPrescaler(void){
  uint16_t high1 = 0U, high2 = 0U, low = 0U;

  do{
    high1 = RTC->PRLH & RTC_PRLH_PRL_Msk;
    low   = RTC->PRLL & RTC_PRLL_PRL_Msk;
    high2 = RTC->PRLH & RTC_PRLH_PRL_Msk;
  }while(high1 != high2);

  return (((uint32_t) high2 << 16U) | low);
}

void AJ_RTC_WritePrescaler(uint32_t value){
  RTC->PRLH = ((value >> 16U) & RTC_PRLH_PRL_Msk);
  RTC->PRLL = (value & RTC_PRLL_PRL_Msk);
}

/******************************************************************************/
/* Config mode (RTC_CRL_CNF)                                                  */
/******************************************************************************/
aj_config_state_t AJ_RTC_EnterConfigMode(void){
  uint32_t timeout = AJ_RTC_TIMEOUT;

  /* Wait until the last write operation has terminated (RTOFF=1). */
  while((timeout != 0U) && (AJ_RTC_IsFlagActive(AJ_RTC_FLAG_R_RTOFF) != 1U)){
    timeout--;
  }

  if(timeout == 0U){return AJ_CONFIG_FAILURE;}

  /* Enter config mode: freeze the RTC registers for the next write. */
  AJ_BitReg_SetBit_Mask(&(RTC->CRL), RTC_CRL_CNF_Msk);

  return AJ_CONFIG_SUCCESS;
}

aj_config_state_t AJ_RTC_ExitConfigMode(void){
  uint32_t timeout = AJ_RTC_TIMEOUT;

  /* Exit config mode: apply the pending writes. */
  AJ_BitReg_ClearBit_Mask(&(RTC->CRL), RTC_CRL_CNF_Msk);

  /* Wait until the update sequence has terminated (RTOFF=1). */
  while((timeout != 0U) && (AJ_RTC_IsFlagActive(AJ_RTC_FLAG_R_RTOFF) != 1U)){
    timeout--;
  }

  if(timeout == 0U){
    return AJ_CONFIG_FAILURE;
  }

  return AJ_CONFIG_SUCCESS;
}

aj_result_state_t AJ_RTC_Synchronize(void){
  uint32_t timeout = AJ_RTC_TIMEOUT;

  /* Clear the register synchronized flag and wait until it is set again. */
  AJ_RTC_ClearFlag(AJ_RTC_FLAG_W0_RSF);

  while((timeout != 0U) && (AJ_RTC_IsFlagActive(AJ_RTC_FLAG_R_RSF) != 1U)){
    timeout--;
  }

  if(timeout == 0U){return AJ_RESULT_FAILURE;}

  return AJ_RESULT_SUCCESS;
}