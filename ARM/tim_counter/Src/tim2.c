#include "project.h"

void counter2_config(){	
	TIM_Base_Init();
	config_ext_clk1();
	// mTIM_Base_SetConfig(10u , 0u);
	// TIM_SlaveConfigSynchronization();
	// TIMEx_MasterConfigSynchronization();
		
}
void TIM_Base_Init(){
	/* Init the low level hardware :CLOCK , GPIO, NVIC */
    //HAL_TIM_Base_MspInit(htim);
	//1.enable clock 
	//2.config gpio
	//3.set priority & enable interrupt
	mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  mGPIO_PIN(0);
	GPIO_Init.moder = mGPIO_MODER_ALT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	GPIO_Init.alternate = 1; 
		
	/* Peripheral clock enable tim 4*/
	enable_rcc_tim2();
	
	init_pin(mGPIOA , &GPIO_Init);
	mNVIC_SetPriority(TIM2_IRQn, 0);
	mNVIC_EnableIRQ(TIM2_IRQn);
	

}

void TIM_SlaveConfigSynchronization(){
	u32_t temp_reg , tmpccer , tmpccmr1;
	//TIM_SlaveTimer_SetConfig(htim, sSlaveConfig);
    /* Set the Time Base configuration */
		/* Set the Input Trigger source */
		temp_reg = read_reg(mTIM_SMCR(mTIM2) , ~(7u <<4));
		temp_reg |= (5u <<4);
		write_reg(mTIM_SMCR(mTIM2) , temp_reg);	
		
		/* Set the slave mode */
		temp_reg = read_reg(mTIM_SMCR(mTIM2) , ~(7u <<0));
		temp_reg |= 7u;
		write_reg(mTIM_SMCR(mTIM2) , temp_reg);
	
    	/* Configure the trigger prescaler, filter, and polarity */  
					  
			tmpccer = read_reg(mTIM_CCER(mTIM2) , ~(1u <<0));
			tmpccmr1 = read_reg(mTIM_CCMR1(mTIM2) , ~0U);

			/* Set the filter */

			tmpccmr1   &= ~(0xFu << 4);
			tmpccmr1   |= (15u << 4);

			// /* Select the Polarity and set the CC1E Bit */
			// tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
			// tmpccer |= TIM_ICPolarity;
			tmpccer  &= ~(1u <<0 | 1u << 3);
			tmpccer |= 0u;
			
			write_reg(mTIM_CCER(mTIM2) , tmpccer);
			write_reg(mTIM_CCMR1(mTIM2) , tmpccmr1);
							
			// /* Disable Trigger Interrupt */		
			temp_reg = read_reg(mTIM_DIER(mTIM2) , ~(1u << 6));
			write_reg(mTIM_DIER(mTIM2) , temp_reg);
			

			// /* Disable Trigger DMA request */
			temp_reg = read_reg(mTIM_DIER(mTIM2) , ~(1u << 14));
			write_reg(mTIM_DIER(mTIM2) , temp_reg);			

	
}
void TIMEx_MasterConfigSynchronization(){
		u32_t temp_reg;
	  /* Reset the MMS Bits */
		 /* Select the TRGO source */
		temp_reg  = read_reg(mTIM_CR2(mTIM2) , ~(7u << 4));
		write_reg(mTIM_CR2(mTIM2) , temp_reg);
		
		// /* Set or Reset the MSM Bit */
		// htim->Instance->SMCR |= sMasterConfig->MasterSlaveMode;
		temp_reg  = read_reg(mTIM_SMCR(mTIM2) , ~(1u << 7));
		write_reg(mTIM_SMCR(mTIM2) , temp_reg);
}



















