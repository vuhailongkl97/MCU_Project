
#include "project.h"
#include "string.h"
#include <stdlib.h>
#include "semphr.h"
TaskHandle_t pxTask = NULL;
TaskHandle_t pxTask_receive = NULL;
SemaphoreHandle_t semaHandle  = NULL;


void vApplicationIdleHook( void ){
}

void vApplicationStackOverflowHook(){
	while(1)
	{
	}
}
void vApplicationMallocFailedHook(){
	while(1)
	{	
	}
}
void rcc_enableclk(){
	enable_rcc_gpioh();
	enable_rcc_gpiod();
	// for pb6 Rx , PB7 TX
	enable_rcc_gpiob();
}
void init_interrupt( ){
	
	unsigned int temp_reg;
	/* usart1 */

    /* Tx interrupt */
    temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1 << 6));
    temp_reg |= (1 << 6);
    write_reg(mUSART_CR1(mUSART1), temp_reg);

    /* Rx interrupt - RXNEIE */
    temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1 << 5));
    temp_reg |= (1 << 5);
    write_reg(mUSART_CR1(mUSART1), temp_reg);
	
	//temp_reg = read_reg(SCB_AIRCR , ~0u);
	temp_reg = (0x5FAu << 16);
	write_reg(SCB_AIRCR , temp_reg);
	
	temp_reg = read_reg(SCB_AIRCR , ~(0xFu << 8));
	temp_reg |= (3u << 8);
	write_reg(SCB_AIRCR , temp_reg);
	
	
    
	mNVIC_SetPriority((USART1_IRQn) ,5);
	mNVIC_EnableIRQ(USART1_IRQn);

    asm("cpsie i") ;	
	
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
	
	
	// TIM2  EXTERNAL INPUT
	GPIO_Init.mpin  =  mGPIO_PIN(0);
	GPIO_Init.moder = mGPIO_MODER_ALT;
	GPIO_Init.type = mPUSH_PULL;
	GPIO_Init.pull  = mNO_PULL;
	GPIO_Init.speed = mFAST_SPEED;
	GPIO_Init.alternate = 1;
	init_pin(mGPIOA , &GPIO_Init); 
}
void lowerTaskAsPeriodic(){

	while(1){
		
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(12));
		
		vTaskDelay(pdMS_TO_TICKS(500));
	}
	
	
}
void midleTaskAsDeferTask(){
	BaseType_t semaValue = pdFALSE;
	while(1){
		semaValue = xSemaphoreTake(semaHandle , pdMS_TO_TICKS(50));
		if(semaValue == pdPASS)
		{
			GPIO_TongglePin(mGPIOD , mGPIO_PIN(13));
		}
	}
}
void highTaskAsInterrupt(){

	while(1){
		xSemaphoreGive(semaHandle);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

// create  3 task 
// task1 priority lowpriority
// task3 high priority as an interrupt
// task2 priority only lower task2 as defer task 

// cu sau 500ms xay ra ngat 1 lan( task2 running)
// khi do task3 se chuyen nhiem vu cua minh cho task 2 xu ly 
// task1  bi pre-emp

int main(void)
{

	//100mhz
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	config_pin();
	init_interrupt();
	// CREATE SEMAPHORE BINARY  
	semaHandle  = xSemaphoreCreateBinary();
	//failure create semaphore binary 
	while(!semaHandle)
	{
	}
	// successfull create semaphore binary 
	xTaskCreate(lowerTaskAsPeriodic , "idle_task1" , 128 ,NULL ,  1 , NULL);
	xTaskCreate(midleTaskAsDeferTask ,"idle_task2" , 128 ,NULL ,  2 , NULL);
	xTaskCreate(highTaskAsInterrupt , "idle_task3" , 128 ,NULL ,  3 , NULL);
	vTaskStartScheduler();

    while(1)
    {
	
    }

}