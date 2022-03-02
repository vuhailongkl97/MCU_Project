
#include "project.h"

volatile unsigned int led_state = 0;
volatile unsigned char rx_data = 0;



void TIM2_IRQHandler(){
 	unsigned temp_reg;

	GPIO_TongglePin(mGPIOD , (mGPIO_PIN(12)) );
	//capture
	if(read_reg(mTIM_SR(mTIM2) , 2u) ){
		GPIO_TongglePin(mGPIOD , (mGPIO_PIN(14)) );
		//clear flag 
		write_reg(mTIM_SR(mTIM2) , 0u);	
	}
	
    // clear interrupt flag
	temp_reg = read_reg(mTIM_SR(mTIM2) , ~(0x1u<<0));
    write_reg(mTIM_SR(mTIM2) , temp_reg);
    write_reg(mNVIC_ICPR , (1 << 28) );

}

void EXTI1_IRQHandler(){
	
}
void EXTI0_IRQHandler(){
	unsigned int temp_reg;
	
	GPIO_TongglePin(mGPIOD , mGPIO_PIN(15));
	
	// xoa co ngat 
	temp_reg = (1 <<0) ;
	write_reg(mEXTI_PR , temp_reg );
	write_reg(mNVIC_ICPR , (1 << 6) );
	
}
void DMA2_Stream2_IRQHandler(){
	
		usart_send_byte(rx_data);
		//clear flag 
		write_reg(mDMA_LIFCR(mDMA2) , (1U << 21));

}
void USART1_IRQHandler(void)
{
    volatile unsigned int temp;
	unsigned  int temp_reg;
    
    temp = read_reg(mUSART_SR(mUSART1), 1 << 6);
    if (0 != temp) /* Tx - TC flag */
    {
		// clear flag tc
		temp_reg = read_reg(mUSART_SR(mUSART1) , ~(1u << 6));
		temp_reg |= (0u << 6);
        write_reg(mUSART_SR(mUSART1), temp_reg);
		
    }

}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }

}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}
void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
}
void mNVIC_SetPriority(IRQn_Type ipr , u32_t pri){
	// chia 4 .. stm32f4 chi dung 4 bit priority	 
	u32_t addr_ipr = (mNVIC_IPR(( (u32_t)ipr >> 2u ))) ;
	u32_t temp_reg = read_reg(addr_ipr, ~0u);
	temp_reg |=  ( ((u32_t)pri  & 0xFFu ) << 4u ) ;
	write_reg(addr_ipr, temp_reg);
	 
}
void mNVIC_EnableIRQ(IRQn_Type irq){
	// iser /32 ,%32
	u32_t addr_irq = mNVIC_ISER( ((u32_t)irq >> 5u) )  ;
	
	u32_t temp_reg = read_reg(addr_irq , ~0u);
	temp_reg |=  (u32_t)(1UL << ((u32_t)irq & 0x1Fu )) ;
	write_reg(addr_irq, temp_reg);
	
}
void init_interrupt( ){
	
	unsigned int temp_reg;
//mEXTI_IMR enable 2 interrupt EXTI0 , EXTI1
	temp_reg = read_reg(mEXTI_IMR , ~(0x03<< 0));
	temp_reg  = temp_reg | (0x03<< 0 );
	write_reg(mEXTI_IMR , temp_reg );
	
	
	/////////////////////////////
	//raising for button1 
	temp_reg = read_reg(mEXTI_RTSR , ~(1<< 0));
	temp_reg  = temp_reg | (1<< 0 );
	write_reg(mEXTI_RTSR , temp_reg );
	
	// raising for button1
	temp_reg = read_reg(mEXTI_RTSR , ~(1u<< 1));
	temp_reg  = temp_reg | (1u << 1 );
	write_reg(mEXTI_RTSR , temp_reg );
	
	/////////////////////////////
// syscfg
	
	//FOR EXTI0
	temp_reg = read_reg(mSYSCFG_EXTICR1 , ~(0x0F<< 0));
	temp_reg  = temp_reg | (0 << 0 );
	write_reg(mSYSCFG_EXTICR1 , temp_reg );
	
	//FOR EXTI1
	temp_reg = read_reg(mSYSCFG_EXTICR1 , ~(0x0F<< 4));
	temp_reg  = temp_reg | (0 << 4 );
	write_reg(mSYSCFG_EXTICR1 , temp_reg );
	
	//////////////////////////////
	
//NVIC	
	mNVIC_SetPriority(EXTI0_IRQn , 15);
	mNVIC_SetPriority(EXTI1_IRQn , 15);
	
	mNVIC_EnableIRQ(EXTI0_IRQn);
	mNVIC_EnableIRQ(EXTI1_IRQn);

//  	NEW FOR DMA	
	mNVIC_SetPriority(DMA2_Stream2_IRQn , 15);
	
	mNVIC_EnableIRQ(DMA2_Stream2_IRQn);	
	
	
	
	//////////////////////////////
	/* usart1 */

    /* Tx interrupt */
    temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1 << 6));
    temp_reg |= (1 << 6);
    write_reg(mUSART_CR1(mUSART1), temp_reg);

    /* Rx interrupt - RXNEIE */
    temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1 << 5));
    temp_reg |= (1 << 5);
    write_reg(mUSART_CR1(mUSART1), temp_reg);
    
	mNVIC_SetPriority(USART1_IRQn , 10);
	mNVIC_EnableIRQ(USART1_IRQn);

    asm("cpsie i") ;	
	
}




















