#include "all_lib.h"

void mTIM_Base_SetConfig(u32_t arr , u32_t psc ){
	u32_t temp_reg;
	/* Set the Time Base configuration */
	/* 1.Select the Counter Mode CR1*/ 
	 
	 /* Set TIM Time Base Unit parameters ---------------------------------------*/
	// dem suon len 
	temp_reg = read_reg(mTIM_CR1(mTIM2), ~(0x07u<<4));
	temp_reg |=  0u<< 4;
	write_reg(mTIM_CR1(mTIM2) , temp_reg);
	
	//ckd ClockDivision / 1
	temp_reg = read_reg(mTIM_CR1(mTIM2) , ~(3u << 8));
	write_reg(mTIM_CR1(mTIM2) , temp_reg);
	
	
	/* Set the Auto-reload value   */
	write_reg(mTIM_ARR(mTIM2) , arr);	
	
	/* Set the Prescaler value  */
	write_reg(mTIM_PSC(mTIM2) , psc);	

	/* Generate an update event to reload the Prescaler 
	and the repetition counter(only for TIM1 and TIM8) value immediately */
	temp_reg = read_reg(mTIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(mTIM_EGR(mTIM2) , temp_reg);	
}
void tim_start(u32_t tim){
	
	u32_t temp_reg;
	  /* Enable the Peripheral cr1 cen*/
	 temp_reg = read_reg(mTIM_CR1(tim) , ~1u);
	 temp_reg |=1u;
	 write_reg(mTIM_CR1(tim) , temp_reg);
	
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
void config_ext_clk2(){
	u32_t temp_reg;
	// 1.Configure channel 2 to detect rising edges on the TI2 input
	temp_reg = read_reg(mTIM_CCMR1(mTIM2) , ~3u);
	temp_reg |= 1u;
	write_reg(mTIM_CCMR1(mTIM2) , temp_reg);
	
	//2.Configure the input filter duration by writing the IC1F[3:0] bits in the TIMx_CCMR1
	temp_reg = read_reg(mTIM_CCMR1(mTIM2) , ~(0xFU << 4));
	temp_reg |= (3u<<4);
	write_reg(mTIM_CCMR1(mTIM2) , temp_reg);
	
	
	//3. Select rising edge polarity by writing CC1P=0 and CC1NP=0 in the mTIM_CCER
	temp_reg = read_reg(mTIM_CCER(mTIM2) , ~0xFU);
	write_reg(mTIM_CCER(mTIM2) , temp_reg);

	// 4. Select the external clock mode1 by writing SMS=111 in the TIMx_SMCR register.
	temp_reg = read_reg(mTIM_SMCR(mTIM2) , ~(7u << 0));
	temp_reg |= 7U;
	write_reg(mTIM_SMCR(mTIM2) , temp_reg);
	
	// 5.Select TI1 as the input source by writing TS=101 in the TIMx_SMCR register
	temp_reg = read_reg(mTIM_SMCR(mTIM2) , ~(7u << 4));
	temp_reg |= (5U <<4);
	write_reg(mTIM_SMCR(mTIM2) , temp_reg);
	
	//6.update event
	temp_reg = read_reg(mTIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(mTIM_EGR(mTIM2) , temp_reg);
	
	temp_reg = read_reg(mTIM_CR1(mTIM2) , ~(1u << 0));
	temp_reg |=(1U<<0);
	write_reg(mTIM_CR1(mTIM2) , temp_reg);
}
// config on tim2 , PA0
void input_capture_config(u32_t tim , u32_t filler ){
	u32_t temp_reg;
	// Select the active input:01: CC1 channel is configured as input, IC1 is mapped on TI1.
	temp_reg = read_reg(mTIM_CCMR1(tim), ~3u);
	//01: CC1 channel is configured as input, IC1 is mapped on TI1.
	temp_reg |= 1u;
	
	// IC1F Input capture 1 filter
	temp_reg |= (filler << 4);
	write_reg(mTIM_CCMR1(tim) , temp_reg);
	
	
	// Select the edge of the active transition on the TI1 channel by writing the CC1P and
	// CC1NP bits to 00 in the mTIM_CCER register (rising edge in this case).
	temp_reg = read_reg(mTIM_CCER(tim) , ~0xFU);
	write_reg(mTIM_CCER(tim) , temp_reg);
	
	// Program the input prescaler. In our example, we wish the capture to be performed at
	// each valid transition, so the prescaler is disabled (write IC1PS bits to 00 in the
	// TIMx_CCMR1 register).
	
	temp_reg = read_reg(mTIM_CCMR1(tim) , ~(3u << 2));
	write_reg(mTIM_CCMR1(tim) , temp_reg);
	
	// Enable capture from the counter into the capture register by setting the CC1E bit in the
	// mTIM_CCER register.
	
	temp_reg = read_reg(mTIM_CCER(tim) , ~(3u << 2));
	temp_reg |=1U;
	write_reg(mTIM_CCER(tim) , temp_reg);
	
	
	// If needed, enable the related interrupt request by setting the CC1IE bit in the
	// TIMx_DIER register, and/or the DMA request by setting the CC1DE bit in the
	// TIMx_DIER register
	
	// An interrupt is generated depending on the CC1IE bit.
	temp_reg = read_reg(mTIM_DIER(tim) , ~(1u << 1));
	temp_reg |=(1U<<1);
	write_reg(mTIM_DIER(tim) , temp_reg);

}





