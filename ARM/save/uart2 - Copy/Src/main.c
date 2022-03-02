#include "project.h"


char times = 0;

void delay( u32_t timeout){
	
	u32_t t1 , t2;
	for( t1 = 0 ; t1 < timeout ; t1 ++)
		for( t2 = 0 ; t2 < 0xFFF ; t2 ++)
			asm(" nop");

}
//clock setup 100mhz for processor
void config_pin(){
	mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  GPIO_PIN(12)| GPIO_PIN(13) | GPIO_PIN(14) | GPIO_PIN(15);
	GPIO_Init.moder = GPIO_MODER_OUTPUT;
	GPIO_Init.type = PUSH_PULL;
	GPIO_Init.pull  = NO_PULL;
	GPIO_Init.speed = FAST_SPEED;
	
	init_pin(GPIOD , &GPIO_Init); 
}
//clock setup 100mhz for processor
int main(void)
{	//using hse
	//void system_init( div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb,u32_t div_apb1 , u32_t div_apb2);
	system_init( 8, 200, PLLP_DIV4 , SRC_PLL, AHB_DIV1 ,APB_DIV2  , APB_DIV1);
	rcc_enableclk();
	
	config_pin();	
	init_interrupt();

    while(1)
    {


    }

}
