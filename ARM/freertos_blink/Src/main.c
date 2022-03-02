
#include "project.h"
#include "string.h"
#include <stdlib.h>
TaskHandle_t pxTask = NULL;

void vApplicationIdleHook( void ){
}

void vApplicationStackOverflowHook(){
	while(1){
		
	}
}
void vApplicationMallocFailedHook(){
	while(1){
		
	}
}
void rcc_enableclk(){
	enable_rcc_gpioh();
	enable_rcc_gpiod();
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
void task1(void * pvParameters ){
	
	u32_t mpin;
	TickType_t xlastWakeTime = xTaskGetTickCount();
	while(1){
		mpin = *(u32_t *)(pvParameters);
	
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(mpin));
		//vTaskDelay(pdMS_TO_TICKS(200));
		vTaskDelayUntil(&xlastWakeTime, (200));
	}
}

void task2(void * pvParameters ){
	UBaseType_t uxPriority ;
	uxPriority = uxTaskPriorityGet(NULL);
	while(1){
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(12));
		vTaskPrioritySet(pxTask , (uxPriority +1));
		vTaskDelay(pdMS_TO_TICKS(100));
		//increment  priority of task3 ;
	}
}
void task3(void * pvParameters ){
	UBaseType_t uxPriority;
	uxPriority = uxTaskPriorityGet(NULL);
	while(1){
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(14));
		vTaskPrioritySet(NULL , (uxPriority -2));
		vTaskDelay(pdMS_TO_TICKS(200));

	}
}

void simple_task(void *pvParameters){
	while(1){		
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(15));
		vTaskDelay(pdMS_TO_TICKS(100));
	}
	
}
void task_test_delete(void *pvParameters){
	while(1){
		
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(15));
		vTaskDelay(pdMS_TO_TICKS(100));
		vTaskDelete(NULL);
	}
	
}
u32_t mpin13 = 13;
u32_t mpin12 = 12;
u32_t mpin14 = 14;
u32_t mpin15 = 15;
//clock config 100mhz 
#define TEST_VDELETE 
// #define TEST_PRIORITY 
int main(void)
{

	//100mhz
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	config_pin();
	
	#ifdef TEST_PRIORITY
	xTaskCreate(task2 , "task1" , 128 , &mpin13 , 2 ,NULL);	
	xTaskCreate(task3 , "tpriority" , 128 , &mpin15 , 1 , &pxTask);
	#endif 
	
	#ifdef TEST_VDELETE
	xTaskCreate(simple_task , "simpletask" , 128 , &mpin15 , 1 , &pxTask);
	xTaskCreate(task_test_delete , "tdelete2" , 128 , &mpin15 , 1 , &pxTask);
	#endif
	
	vTaskStartScheduler();

    while(1)
    {
	
    }

}