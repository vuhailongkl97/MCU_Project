#include "project.h"
#include "string.h"
#include <stdlib.h>
#define USE_HSE


char times = 0;

void rcc_enableclk(){
	
	enable_rcc_gpioa();
	
	// enable port h
	enable_rcc_gpioh();
	//PORT D . for 4 led	
	enable_rcc_gpiod();
	// timer4
	enable_rcc_tim4();
}
// void config_pin()
// {
	// mGPIO_TypeDef GPIO_Init;
	// GPIO_Init.mpin  =  mGPIO_PIN(15) | mGPIO_PIN(14);
	// GPIO_Init.moder = mGPIO_MODER_ALT;
	// GPIO_Init.type = mPUSH_PULL;
	// GPIO_Init.pull  = mNO_PULL;
	// GPIO_Init.speed = mFAST_SPEED;
	// GPIO_Init.alternate = 2; 
	// init_pin(mGPIOD , &GPIO_Init);
// }
void config_pin()
{
	mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  mGPIO_PIN(0);
	GPIO_Init.moder = mGPIO_MODER_ALT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	GPIO_Init.alternate = 1; 
	init_pin(mGPIOA , &GPIO_Init);
}

//clock config 100mhz 
int main(void)
{	
	unsigned int duty4 = 200 ,duty3 = 0, fade = 4;
	// use hse
	//void system_init( div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb,u32_t div_apb1 , u32_t div_apb2);
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	systick_init();
	
	//counter2_config();
	enable_rcc_tim2();
	config_ext_clk1();
	config_pin();
	// tim4_pwm_config();
	// write_reg(mTIM_PSC(mTIM4) , 20);
	// tim_start(mTIM4);
	
	
    while(1)
    {
		// set_duty_tim(mTIM4,duty4 , 4 );
		// set_duty_tim(mTIM4,duty3 , 3 );
		// duty4 += fade;
		// duty3 = 400 - duty4;
		// if(duty4  == 400  || duty4 == 0 )
			// fade = -fade;
		 // delay_ms_systick(20);
		
    }

}