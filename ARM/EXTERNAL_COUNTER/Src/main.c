#include "project.h"
#include "string.h"
#include <stdlib.h>
void rcc_enableclk(){
	
	enable_rcc_gpioh();
	enable_rcc_gpioa();
	enable_rcc_tim2();

}
void config_pin()
{
	mGPIO_TypeDef GPIO_Init;
	
	// TIM2  EXTERNAL INPUT
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
	//100mhz
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	systick_init();
	config_pin();
	// ARR = 100 , PSC = 0 
	mTIM_Base_SetConfig(100, 0 );
	config_ext_clk2();
	tim_start(mTIM2);


    while(1)
    {
	
    }

}