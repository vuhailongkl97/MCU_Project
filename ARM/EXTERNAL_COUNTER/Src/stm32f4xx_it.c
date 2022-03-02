#include "project.h"

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





















