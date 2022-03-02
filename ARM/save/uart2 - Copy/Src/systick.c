#include "project.h"


void timer2_init(){
	
	unsigned int temp_reg ;
	//__HAL_RCC_TIM2_CLK_ENABLE
	
	temp_reg = read_reg(RCC_APB1ENR , ~1u);
	temp_reg |= 1u;
	write_reg(RCC_APB1ENR , temp_reg );
	
	//vos
	//PWR_CR , 14 15
	temp_reg = read_reg(PWR_CR , ~(3u << 14));
	temp_reg |= (2u << 14);
	write_reg(PWR_CR , temp_reg);
	
	// /* mTIM2 interrupt Init */
	// HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);//28
	
	// priority pos 28 in table vector interrupt
	temp_reg = read_reg(NVIC_IPR(7) , ~0xFFu);
	// bit 6 , 7 is set priority
	temp_reg |= (1u << 6);
	write_reg(NVIC_IPR(7) , temp_reg );
	
	
	
	// HAL_NVIC_EnableIRQ(TIM2_IRQn);
	temp_reg = read_reg(NVIC_ISER(0) , ~(1u <<28));
	temp_reg |= (1u << 28);
	write_reg(NVIC_ISER(0) , temp_reg );
				  
	// TIM_Base_SetConfig
		// disable tim2

	temp_reg = read_reg(TIM_CR1(mTIM2) , ~1u);
	write_reg(TIM_CR1(mTIM2) ,temp_reg);
	
	//counter mode 
	
	
	temp_reg = read_reg(TIM_CR1(mTIM2) , ~(7u << 4));
	write_reg(TIM_CR1(mTIM2) ,temp_reg);
	
	
	
	//  Clock division
	
	temp_reg = read_reg(TIM_CR1(mTIM2) , ~( 3u << 8));
	write_reg(TIM_CR1(mTIM2) ,temp_reg);
	
	// /* Set the Auto-reload value */
	// TIMx->ARR = (uint32_t)Structure->Period ;
	//TIM_ARR 1999 GHI FULL
	write_reg(TIM_ARR(mTIM2) , 1999u);
	
	
	
	// /* Set the Prescaler value */
	// TIMx->PSC = (uint32_t)Structure->Prescaler;
	// 50000 ,,TIM_PSC  15 BIT DAU 
	write_reg(TIM_PSC(mTIM2) , 50000u);
	
	/* Generate an update event to reload the Prescaler 
     and the repetition counter(only for TIM1 and TIM8) value immediately */
	 
	// TIMx->EGR = TIM_EGR_UG;
	// TIMx_EGR ,  BIT 0  >> 1 
	
	temp_reg = read_reg(TIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(TIM_EGR(mTIM2) , temp_reg);
	
	/* Reset the SMS, TS, ECE, ETPS and ETRF bits */
	
	
	temp_reg = ( (7u << 0) |  (7u << 4) |( 0xF << 8 )| (4u << 12) | (1 << 14) |(1 << 15));
 
	write_reg(TIM_SMCR(mTIM2), ~temp_reg);
	
	/* Disable slave mode to clock the prescaler directly with the internal clock */
	//		  htim->Instance->SMCR &= ~TIM_SMCR_SMS;
	
	temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u << 0));
	
	write_reg( TIM_SMCR(mTIM2), temp_reg);
	
	/* Reset the MMS Bits */
	/* Select the TRGO source */
	// htim->Instance->CR2 &= ~TIM_CR2_MMS;
	// htim->Instance->CR2 |= sMasterConfig->MasterOutputTrigger;TIM_TRGO_RESET , 0x00000000U
	
	temp_reg = read_reg(TIM_CR2(mTIM2), ~(7u << 4));
	temp_reg |= (0u << 4);
	write_reg(TIM_CR2(mTIM2) , temp_reg);
	
	
	temp_reg = read_reg(TIM_SMCR(mTIM2), ~(1u << 7));
	write_reg(TIM_SMCR(mTIM2) , temp_reg);
	

	//enable global interrupts
	asm("cpsie i") ;
	

}


void timer2_start(unsigned int value){
	
	unsigned int temp_reg;

   /* Enable the TIM Update interrupt */
  // __HAL_TIM_ENABLE_IT(htim, TIM_IT_UPDATE);
  
  //TIMx_DIER ,bit 0 >> 1
  temp_reg = read_reg(TIM_DIER(mTIM2) , ~(0x1u<<0));
  temp_reg |= (0x1u <<0);
  write_reg(TIM_DIER(mTIM2) , temp_reg);
  
  /* Enable the Peripheral */
  // __HAL_TIM_ENABLE(htim);
  // TIM_CR1 ,CEN BIT  0 , >> 1 
  temp_reg = read_reg(TIM_CR1(mTIM2) , ~1u);
  temp_reg |= 1u;
  write_reg(TIM_CR1(mTIM2) , temp_reg);
      
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	