

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include "project.h"



extern volatile unsigned char rx_data;
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

void TIM2_IRQHandler();
void mNVIC_SetPriority(IRQn_Type irq , u32_t pri);
void mNVIC_EnableIRQ(IRQn_Type irq);
void init_interrupt();



#ifdef __cplusplus

#endif

#endif /* __STM32F4xx_IT_H */

