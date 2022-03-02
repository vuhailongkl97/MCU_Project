#include "project.h"
#include "string.h"
#include <stdlib.h>
char times = 0;
void rcc_enableclk(){
	//for dma2stream 2
	u32_t temp_reg = read_reg( mRCC_AHB1ENR , ~(1u << 22) );
	temp_reg |= (1 << 22);
	write_reg(mRCC_AHB1ENR , temp_reg);
	
	// enable port h
	enable_rcc_gpioh();
	
	// for usart
	enable_rcc_gpiob();
	//PORT D . for 4 led	
	enable_rcc_gpiod();

}
void config_pin()
{
	mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  mGPIO_PIN(15) | mGPIO_PIN(14);
	GPIO_Init.moder = mGPIO_MODER_ALT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	GPIO_Init.alternate = 2; 
	init_pin(mGPIOD , &GPIO_Init);
	
	GPIO_Init.mpin  =  mGPIO_PIN(12)| mGPIO_PIN(13) | mGPIO_PIN(14) | mGPIO_PIN(15);
	GPIO_Init.moder = mGPIO_MODER_OUTPUT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	
	init_pin(mGPIOD , &GPIO_Init); 
}

//clock config 100mhz 
int main(void)
{	
	// use hse
	//void system_init( div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb,u32_t div_apb1 , u32_t div_apb2);
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	systick_init();
	config_pin();
	// void config_dma(u32 dma , u8_t stream ,u8_t channel , u8_t dir , u8_t circular  , u8_t pinc 
          // , u8_t minc , u8_t psize , u8t msize , u8_t priority   );
	config_dma(mDMA2 , 2 , 4 , DMA_P2M , ENABLE , DMA_INC , DMA_FIX ,DMA_SIZE_BYTE , DMA_SIZE_BYTE , DMA_PL_LOW );
	uart_init(100, 16 , 9600);
	mDMA_start( mDMA2 , 2u , (u32_t )&rx_data ,mUSART_DR(mUSART1)  );
	usart_dma_en();
	init_interrupt();
	usart_send_string("HELLO FROM MCU STM32 !!!");

	
    while(1)
    {
	
    }

}