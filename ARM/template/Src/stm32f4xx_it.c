#include "project.h"
u32_t t1 , t2, t;
void TIM2_IRQHandler(){
	volatile u32_t temp_reg ; 
	
	GPIO_TongglePin(mGPIOD , (mGPIO_PIN(12)|mGPIO_PIN(13)|mGPIO_PIN(14) | mGPIO_PIN(15)) );

	// che do tan so CC1OF
	temp_reg = read_reg((mTIM_SR(mTIM2)) , (1U << 9));

	if(temp_reg == (1u << 9)){
		t2 = read_reg(mTIM_CCR1(mTIM2),~0u );
		if(t2 < t1 ){
			t = (t2 - t1 ) + 0xFFFFFFFF ;
		}
		else {
			t = t2 - t1;
		}
		temp_reg = read_reg(mTIM_SR(mTIM2) , ~(1u<< 9));
		write_reg(mTIM_SR(mTIM2) , temp_reg);
		t1 = t2  = 0 ;

	}
	else {
		t1  = read_reg(mTIM_CCR1(mTIM2) , ~0u);
	}
    write_reg(mNVIC_ICPR , (1 << 28) );
	
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






















