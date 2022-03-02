#include "project.h"
extern TaskHandle_t pxTask ;



void USART1_IRQHandler(){
	

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


void DebugMon_Handler(void)
{
}


void mNVIC_SetPriority(IRQn_Type ipr , u32_t pri){
	// stm32f4 su dung 4 bit cao 
	pri = pri << 4;
	// chia 4 .. stm32f4 chi dung 4 bit priority	 
	u32_t addr_ipr = (mNVIC_IPR(( (u32_t)ipr >> 2u ))) ; 
	u32_t temp_reg = read_reg(addr_ipr, ~0u);
	// tinh 1 trong 4 vi tri 
	temp_reg |=  ( (u32_t)pri  << (4 * (ipr >> 4 ))) ;
	write_reg(addr_ipr, temp_reg);
	 
}
void mNVIC_EnableIRQ(IRQn_Type irq){
	// iser /32 ,%32
	u32_t addr_irq = mNVIC_ISER( ((u32_t)irq >> 5u) )  ;
	
	u32_t temp_reg = read_reg(addr_irq , ~0u);
	temp_reg |=  (u32_t)(1UL << ((u32_t)irq & 0x1Fu )) ;
	write_reg(addr_irq, temp_reg);
	
}






















