#ifndef __STATE_H__
#define __STATE_H__


#define ENABLE  1U
#define DISABLE 0U

///////////// GPIO //////////
#if 1 
#define mPUSH_PULL  0u
#define mOPEN_DRAIN 1u


#define mNO_PULL 	0u
#define mPULL_UP 	1u
#define mPULL_DOWN   2u

#define mLOW_SPEED   	0u
#define mMEDIUM_SPEED   1u
#define mFAST_SPEED   	2u
#define mHIGH_SPEED   	3u

#define mGPIO_PIN(n)     (1 << n)

#define mGPIO_MODER_INPUT    0x00
#define mGPIO_MODER_OUTPUT   0x01
#define mGPIO_MODER_ALT  	 0x02
#define mGPIO_MODER_ANALOG   0x03
#endif
/////////////  RCC //////////////
#if 1
// /M *N /P
// M , N khong can tinh ( nhu thap phan )

#define mPLLP_DIV2 0u
#define mPLLP_DIV4 1u
#define mPLLP_DIV6 2u
#define mPLLP_DIV8 3u

//APBx
#define mAPB_DIV1  0u
#define mAPB_DIV2  4u
#define mAPB_DIV4  5u
#define mAPB_DIV8  6u
#define mAPB_DIV16 7u

// AHB pmrescaler
#define mAHB_DIV1  	0u
#define mAHB_DIV2  	8u
#define mAHB_DIV4  	9u
#define mAHB_DIV8  	10u
#define mAHB_DIV16	11u
#define mAHB_DIV64 	12u
#define mAHB_DIV128	13u
#define mAHB_DIV256 	14u
#define mAHB_DIV512 	15u

#define mSRC_HSI 0u
#define mSRC_HSE 1u
#define mSRC_PLL 2u
#endif
//////////////////// DMA////////////////
#if 1 
#define DMA_P2M 0U
#define DMA_M2P 1U
#define DMA_M2M 0U


#define DMA_FIX 0U
#define DMA_INC 1U


#define DMA_SIZE_BYTE  0U
#define DMA_SIZE_HWORD 1U
#define DMA_SIZE_WORD  2U


#define DMA_PL_LOW    0U
#define DMA_PL_MEDIUM 1U
#define DMA_PL_HIGH   2U
#define DMA_PL_VHIGH  3U
#endif

#endif