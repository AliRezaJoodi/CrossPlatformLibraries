#ifndef AJ_BUS_TYPE_INCLUDED
#define AJ_BUS_TYPE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f4xx.h>

//********************************************************
typedef enum {
	AJ_BUS_CLOCK_DISABLE = 0U,
	AJ_BUS_CLOCK_ENABLE  = 1U
} aj_bus_clock_state_t;

//********************************************************
typedef enum {
	#if defined(RCC_AHB1ENR_GPIOAEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOA = RCC_AHB1ENR_GPIOAEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOBEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOB = RCC_AHB1ENR_GPIOBEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOCEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOC = RCC_AHB1ENR_GPIOCEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIODEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOD = RCC_AHB1ENR_GPIODEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOEEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOE = RCC_AHB1ENR_GPIOEEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOFEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOF = RCC_AHB1ENR_GPIOFEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOGEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOG = RCC_AHB1ENR_GPIOGEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOHEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOH = RCC_AHB1ENR_GPIOHEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOIEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOI = RCC_AHB1ENR_GPIOIEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOJEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOJ = RCC_AHB1ENR_GPIOJEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_GPIOKEN_Msk)
		AJ_BUS_AHB1_CLOCK_GPIOK = RCC_AHB1ENR_GPIOKEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_CRCEN_Msk)
		AJ_BUS_AHB1_CLOCK_CRC = RCC_AHB1ENR_CRCEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_BKPSRAMEN_Msk)
		AJ_BUS_AHB1_CLOCK_BKPSRAM = RCC_AHB1ENR_BKPSRAMEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_CCMDATARAMEN_Msk)
		AJ_BUS_AHB1_CLOCK_CCMDATARAM = RCC_AHB1ENR_CCMDATARAMEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_DMA1EN_Msk)
		AJ_BUS_AHB1_CLOCK_DMA1 = RCC_AHB1ENR_DMA1EN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_DMA2EN_Msk)
		AJ_BUS_AHB1_CLOCK_DMA2 = RCC_AHB1ENR_DMA2EN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_DMA2DEN_Msk)
		AJ_BUS_AHB1_CLOCK_DMA2D = RCC_AHB1ENR_DMA2DEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_ETHMACEN_Msk)
		AJ_BUS_AHB1_CLOCK_ETHMAC = RCC_AHB1ENR_ETHMACEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_ETHMACTXEN_Msk)
		AJ_BUS_AHB1_CLOCK_ETHMACTX = RCC_AHB1ENR_ETHMACTXEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_ETHMACRXEN_Msk)
		AJ_BUS_AHB1_CLOCK_ETHMACRX = RCC_AHB1ENR_ETHMACRXEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_ETHMACPTPEN_Msk)
		AJ_BUS_AHB1_CLOCK_ETHMACPTP = RCC_AHB1ENR_ETHMACPTPEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_OTGHSEN_Msk)
		AJ_BUS_AHB1_CLOCK_OTGHS = RCC_AHB1ENR_OTGHSEN_Msk,
	#endif

	#if defined(RCC_AHB1ENR_OTGHSULPIEN_Msk)
		AJ_BUS_AHB1_CLOCK_OTGHSULPI = RCC_AHB1ENR_OTGHSULPIEN_Msk,
	#endif

	AJ_BUS_AHB1_CLOCK_ALL = 0xFFFFFFFFU
} aj_bus_ahb1_clock_mask_t;

//********************************************************
typedef enum {
	#if defined(RCC_AHB1RSTR_GPIOARST_Msk)
		AJ_BUS_AHB1_RESET_GPIOA = RCC_AHB1RSTR_GPIOARST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOBRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOB = RCC_AHB1RSTR_GPIOBRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOCRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOC = RCC_AHB1RSTR_GPIOCRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIODRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOD = RCC_AHB1RSTR_GPIODRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOERST_Msk)
		AJ_BUS_AHB1_RESET_GPIOE = RCC_AHB1RSTR_GPIOERST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOFRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOF = RCC_AHB1RSTR_GPIOFRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOGRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOG = RCC_AHB1RSTR_GPIOGRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOHRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOH = RCC_AHB1RSTR_GPIOHRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOIRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOI = RCC_AHB1RSTR_GPIOIRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOJRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOJ = RCC_AHB1RSTR_GPIOJRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_GPIOKRST_Msk)
		AJ_BUS_AHB1_RESET_GPIOK = RCC_AHB1RSTR_GPIOKRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_CRCRST_Msk)
		AJ_BUS_AHB1_RESET_CRC = RCC_AHB1RSTR_CRCRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_DMA1RST_Msk)
		AJ_BUS_AHB1_RESET_DMA1 = RCC_AHB1RSTR_DMA1RST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_DMA2RST_Msk)
		AJ_BUS_AHB1_RESET_DMA2 = RCC_AHB1RSTR_DMA2RST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_DMA2DRST_Msk)
		AJ_BUS_AHB1_RESET_DMA2D = RCC_AHB1RSTR_DMA2DRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_ETHMACRST_Msk)
		AJ_BUS_AHB1_RESET_ETHMAC = RCC_AHB1RSTR_ETHMACRST_Msk,
	#endif

	#if defined(RCC_AHB1RSTR_OTGHRST_Msk)
		AJ_BUS_AHB1_RESET_OTGHS = RCC_AHB1RSTR_OTGHRST_Msk,
	#endif

	AJ_BUS_AHB1_RESET_ALL = 0xFFFFFFFFU
} aj_bus_ahb1_reset_mask_t;

//********************************************************
/* LP: Low Power */
typedef enum {
	#if defined(RCC_AHB1LPENR_GPIOALPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOA = RCC_AHB1LPENR_GPIOALPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOBLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOB = RCC_AHB1LPENR_GPIOBLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOCLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOC = RCC_AHB1LPENR_GPIOCLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIODLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOD = RCC_AHB1LPENR_GPIODLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOELPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOE = RCC_AHB1LPENR_GPIOELPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOFLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOF = RCC_AHB1LPENR_GPIOFLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOGLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOG = RCC_AHB1LPENR_GPIOGLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOHLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOH = RCC_AHB1LPENR_GPIOHLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOILPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOI = RCC_AHB1LPENR_GPIOILPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOJLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOJ = RCC_AHB1LPENR_GPIOJLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_GPIOKLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_GPIOK = RCC_AHB1LPENR_GPIOKLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_CRCLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_CRC = RCC_AHB1LPENR_CRCLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_FLITFLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_FLITF = RCC_AHB1LPENR_FLITFLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_SRAM1LPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_SRAM1 = RCC_AHB1LPENR_SRAM1LPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_SRAM2LPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_SRAM2 = RCC_AHB1LPENR_SRAM2LPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_BKPSRAMLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_BKPSRAM = RCC_AHB1LPENR_BKPSRAMLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_SRAM3LPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_SRAM3 = RCC_AHB1LPENR_SRAM3LPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_DMA1LPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_DMA1 = RCC_AHB1LPENR_DMA1LPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_DMA2LPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_DMA2 = RCC_AHB1LPENR_DMA2LPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_DMA2DLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_DMA2D = RCC_AHB1LPENR_DMA2DLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_ETHMACLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_ETHMAC = RCC_AHB1LPENR_ETHMACLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_ETHMACTXLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_ETHMACTX = RCC_AHB1LPENR_ETHMACTXLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_ETHMACRXLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_ETHMACRX = RCC_AHB1LPENR_ETHMACRXLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_ETHMACPTPLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_ETHMACPTP = RCC_AHB1LPENR_ETHMACPTPLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_OTGHSLPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_OTGHS = RCC_AHB1LPENR_OTGHSLPEN_Msk,
	#endif

	#if defined(RCC_AHB1LPENR_OTGHSULPILPEN_Msk)
		AJ_BUS_AHB1_CLOCK_LP_OTGHSULPI = RCC_AHB1LPENR_OTGHSULPILPEN_Msk,
	#endif

	AJ_BUS_AHB1_CLOCK_LP_ALL = 0xFFFFFFFFU
} aj_bus_ahb1_clock_lp_mask_t;


#if defined(RCC_AHB2_SUPPORT)
//********************************************************
typedef enum {
	#if defined(RCC_AHB2ENR_DCMIEN_Msk)
		AJ_BUS_AHB2_CLOCK_DCMI = RCC_AHB2ENR_DCMIEN_Msk,
	#endif

	#if defined(RCC_AHB2ENR_CRYPEN_Msk)
		AJ_BUS_AHB2_CLOCK_CRYP = RCC_AHB2ENR_CRYPEN_Msk,
	#endif

	#if defined(RCC_AHB2ENR_AESEN_Msk)
		AJ_BUS_AHB2_CLOCK_AES = RCC_AHB2ENR_AESEN_Msk,
	#endif

	#if defined(RCC_AHB2ENR_HASHEN_Msk)
		AJ_BUS_AHB2_CLOCK_HASH = RCC_AHB2ENR_HASHEN_Msk,
	#endif

	#if defined(RCC_AHB2ENR_RNGEN_Msk)
		AJ_BUS_AHB2_CLOCK_RNG = RCC_AHB2ENR_RNGEN_Msk,
	#endif

	#if defined(RCC_AHB2ENR_OTGFSEN_Msk)
		AJ_BUS_AHB2_CLOCK_OTGFS = RCC_AHB2ENR_OTGFSEN_Msk,
	#endif

	AJ_BUS_AHB2_CLOCK_ALL = 0xFFFFFFFFU
} aj_bus_ahb2_clock_mask_t;

//********************************************************
typedef enum {
	#if defined(RCC_AHB2RSTR_DCMIRST_Msk)
		AJ_BUS_AHB2_RESET_DCMI = RCC_AHB2RSTR_DCMIRST_Msk,
	#endif

	#if defined(RCC_AHB2RSTR_CRYPRST_Msk)
		AJ_BUS_AHB2_RESET_CRYP = RCC_AHB2RSTR_CRYPRST_Msk,
	#endif

	#if defined(RCC_AHB2RSTR_AESRST_Msk)
		AJ_BUS_AHB2_RESET_AES = RCC_AHB2RSTR_AESRST_Msk,
	#endif

	#if defined(RCC_AHB2RSTR_HASHRST_Msk)
		AJ_BUS_AHB2_RESET_HASH = RCC_AHB2RSTR_HASHRST_Msk,
	#endif

	#if defined(RCC_AHB2RSTR_RNGRST_Msk)
		AJ_BUS_AHB2_RESET_RNG = RCC_AHB2RSTR_RNGRST_Msk,
	#endif

	#if defined(RCC_AHB2RSTR_OTGFSRST_Msk)
		AJ_BUS_AHB2_RESET_OTGFS = RCC_AHB2RSTR_OTGFSRST_Msk,
	#endif

	AJ_BUS_AHB2_RESET_ALL = 0xFFFFFFFFU
} aj_bus_ahb2_reset_mask_t;

//********************************************************
typedef enum {
	#if defined(RCC_AHB2LPENR_DCMILPEN_Msk)
		AJ_BUS_AHB2_CLOCK_LP_DCMI = RCC_AHB2LPENR_DCMILPEN_Msk,
	#endif

	#if defined(RCC_AHB2LPENR_CRYPLPEN_Msk)
		AJ_BUS_AHB2_CLOCK_LP_CRYP = RCC_AHB2LPENR_CRYPLPEN_Msk,
	#endif

	#if defined(RCC_AHB2LPENR_AESLPEN_Msk)
		AJ_BUS_AHB2_CLOCK_LP_AES = RCC_AHB2LPENR_AESLPEN_Msk,
	#endif

	#if defined(RCC_AHB2LPENR_HASHLPEN_Msk)
		AJ_BUS_AHB2_CLOCK_LP_HASH = RCC_AHB2LPENR_HASHLPEN_Msk,
	#endif

	#if defined(RCC_AHB2LPENR_RNGLPEN_Msk)
		AJ_BUS_AHB2_CLOCK_LP_RNG = RCC_AHB2LPENR_RNGLPEN_Msk,
	#endif

	#if defined(RCC_AHB2LPENR_OTGFSLPEN_Msk)
		AJ_BUS_AHB2_CLOCK_LP_OTGFS = RCC_AHB2LPENR_OTGFSLPEN_Msk,
	#endif

	AJ_BUS_AHB2_CLOCK_LP_ALL = 0xFFFFFFFFU
} aj_bus_ahb2_clock_lp_mask_t;
#endif	/* RCC_AHB2_SUPPORT */


#if defined(RCC_AHB3_SUPPORT)
//********************************************************
typedef enum {
	#if defined(RCC_AHB3ENR_FSMCEN_Msk)
		AJ_BUS_AHB3_CLOCK_FSMC = RCC_AHB3ENR_FSMCEN_Msk,
	#endif

	#if defined(RCC_AHB3ENR_FMCEN_Msk)
		AJ_BUS_AHB3_CLOCK_FMC = RCC_AHB3ENR_FMCEN_Msk,
	#endif

	#if defined(RCC_AHB3ENR_QSPIEN_Msk)
		AJ_BUS_AHB3_CLOCK_QSPI = RCC_AHB3ENR_QSPIEN_Msk,
	#endif

	AJ_BUS_AHB3_CLOCK_ALL = 0xFFFFFFFFU
} aj_bus_ahb3_clock_mask_t;

//********************************************************
typedef enum {
	#if defined(RCC_AHB3RSTR_FSMCRST_Msk)
		AJ_BUS_AHB3_RESET_FSMC = RCC_AHB3RSTR_FSMCRST_Msk,
	#endif

	#if defined(RCC_AHB3RSTR_FMCRST_Msk)
		AJ_BUS_AHB3_RESET_FMC = RCC_AHB3RSTR_FMCRST_Msk,
	#endif

	#if defined(RCC_AHB3RSTR_QSPI RST_Msk)
		AJ_BUS_AHB3_RESET_QSPI = RCC_AHB3RSTR_QSPIRST_Msk,
	#endif

	AJ_BUS_AHB3_RESET_ALL = 0xFFFFFFFFU
} aj_bus_ahb3_reset_mask_t;

//********************************************************
typedef enum {
	#if defined(RCC_AHB3LPENR_FSMCLPEN_Msk)
		AJ_BUS_AHB3_CLOCK_LP_FSMC = RCC_AHB3LPENR_FSMCLPEN_Msk,
	#endif

	#if defined(RCC_AHB3LPENR_FMCLPEN_Msk)
		AJ_BUS_AHB3_CLOCK_LP_FMC = RCC_AHB3LPENR_FMCLPEN_Msk,
	#endif

	#if defined(RCC_AHB3LPENR_QSPILPEN_Msk)
		AJ_BUS_AHB3_CLOCK_LP_QSPI = RCC_AHB3LPENR_QSPILPEN_Msk,
	#endif

	AJ_BUS_AHB3_CLOCK_LP_ALL = 0xFFFFFFFFU
} aj_bus_ahb3_clock_lp_mask_t;

#endif	/* RCC_AHB3_SUPPORT */


//********************************************************
typedef enum {
	AJ_BUS_APB1_CLOCK_ALL = 0xFFFFFFFFU
} aj_bus_apb1_clock_mask_t;	

//********************************************************
typedef enum {
	AJ_BUS_APB1_RESET_ALL = 0xFFFFFFFFU
} aj_bus_apb1_reset_mask_t;	

//********************************************************
typedef enum {
	AJ_BUS_APB1_CLOCK_LP_ALL = 0xFFFFFFFFU
} aj_bus_apb1_clock_lp_mask_t;	


//********************************************************
typedef enum {
	AJ_BUS_APB2_CLOCK_ALL = 0xFFFFFFFFU
} aj_bus_apb2_clock_mask_t;	

//********************************************************
typedef enum {
	AJ_BUS_APB2_RESET_ALL = 0xFFFFFFFFU
} aj_bus_apb2_reset_mask_t;

//********************************************************
typedef enum {
	AJ_BUS_APB2_CLOCK_LP_ALL = 0xFFFFFFFFU
} aj_bus_apb2_clock_lp_mask_t;

#ifdef __cplusplus
}
#endif

#endif  /* AJ_BUS_TYPE_INCLUDED */