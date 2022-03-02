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
	
	
	/* Set the Auto-reload value  = 10 */
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
	  //__HAL_TIM_ENABLE(htim);
	 temp_reg = read_reg(mTIM_CR1(tim) , ~1u);
	 temp_reg |=1u;
	 write_reg(mTIM_CR1(tim) , temp_reg);
	
}