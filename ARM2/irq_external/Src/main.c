#include "project.h"
#include "string.h"
#include <stdlib.h>
void rcc_enableclk(){
	enable_rcc_gpioh();
	enable_rcc_gpioa();
	enable_rcc_gpiod();
}
void config_pin()
{
	mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  mGPIO_PIN(15) | mGPIO_PIN(14)|mGPIO_PIN(13)|mGPIO_PIN(12);
	GPIO_Init.moder = mGPIO_MODER_OUTPUT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	init_pin(mGPIOD , &GPIO_Init);
	
	GPIO_Init.mpin  =  mGPIO_PIN(0);
	GPIO_Init.moder = mGPIO_MODER_INPUT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	init_pin(mGPIOA, &GPIO_Init);
	
}
void config_irq_ext(){
	u32_t temp_reg;
	
	// get bit 0-3 
	temp_reg = read_reg(mEXTI_IMR, ~(0x01));
	temp_reg |= (1 << 0);
	write_reg(mEXTI_IMR , temp_reg);
	
	//2 chon suong falling 
	temp_reg = read_reg(mEXTI_FTSR, ~(0x01));
	temp_reg |= (1 << 0);
	write_reg(mEXTI_FTSR , temp_reg);
	
	//3. cau hinh tren syscfg bit 0-3 >> 0000 . ngat ngoai tren pa0 
	//mSYSCFG_EXTICR1
	temp_reg = read_reg(mSYSCFG_EXTICR1 , ~(0x0Fu));
	temp_reg |= 0 <<0 ; 
	write_reg(mSYSCFG_EXTICR1 , temp_reg);
	
	
	// 4 . cau hinh nvic 
    // setup group priority 
	// PRIGROUP 3 bit trong AIRCR
	// SCB_AIRCR [8:10]
	// 111 
	temp_reg = read_reg(SCB_AIRCR , ~(7u << 8 ) );
	temp_reg &= ~(0xFFFF << 16);
	// de co the ghi vao thanh ghi nay SCB_AIRCR
	temp_reg |= (0x5FA<< 16);
	
	// set group priority 
	temp_reg |= (7u << 8);
	write_reg( SCB_AIRCR , temp_reg);
	

    // set priority 0 (highest)
	temp_reg = read_reg(mNVIC_IPR(0) , ~(0xff));
	temp_reg |= 0 << 0;
	write_reg(mNVIC_IPR(0) , temp_reg);
   
	//enable interrupt 
	//mNVIC_ISER(0) &=~(1<<0) ;
	temp_reg = read_reg(mNVIC_ISER(0) , ~( 1 <<6));
	temp_reg |= (1 << 6 );
	write_reg( mNVIC_ISER(0) , temp_reg);
	
	
}
//clock config 100mhz 
int main(void)
{
	//100mhz
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	systick_init();
	config_pin();
	config_irq_ext();

    while(1)
    {
		GPIO_TongglePin(mGPIOD,mGPIO_PIN(15));
		delay_ms_systick(1000);
		
    }

}