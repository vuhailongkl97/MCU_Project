
#include "project.h"
#include "string.h"
#include <stdlib.h>
TaskHandle_t pxTask = NULL;
TaskHandle_t pxTask_receive = NULL;
char ok = 1 ; 

void USART1_IRQHandler(){
	
	volatile u32_t temp ;
	volatile unsigned char rx_data;
	u32_t temp_reg;
	BaseType_t xHigherPriorityTaskWoken  = pdFALSE;
	
   	GPIO_TongglePin(mGPIOD , mGPIO_PIN(12));
    temp = read_reg(mUSART_SR(mUSART1), 1 << 6);
	
	if (0 != temp) /* Tx - TC flag */
    {
		temp_reg = read_reg(mUSART_SR(mUSART1) , ~(1u << 6));
		temp_reg |= (0u << 6);
        write_reg(mUSART_SR(mUSART1), temp_reg);
		
		if( ok == 0){ 
			vTaskNotifyGiveFromISR(pxTask_receive , &xHigherPriorityTaskWoken);
			portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
		}
		
    }
	temp = read_reg(mUSART_SR(mUSART1), 1 << 5);
	
    if (0 != temp)  /* Rx - RXNE flag */
    {
		rx_data = read_reg(mUSART_DR(mUSART1) , 0x000000FF);
		
	    vTaskNotifyGiveFromISR(pxTask , &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
    }

}


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
void idle_task(void * pvParameters ){

	u32_t mpin;
	while(1){
		mpin = *(u32_t *)(pvParameters);
		GPIO_TongglePin(mGPIOD , mGPIO_PIN(mpin));
		  //xTaskNotifyGive(pxTask);
		//xTaskNotify(pxTask,  123 , eSetValueWithoutOverwrite);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
	
	
}
void notify_take_task(void *pvParameters ){
	volatile u32_t    ulEventToProcess ; 
	unsigned char rx_data;

		ulEventToProcess = ulTaskNotifyTake(pdTRUE , pdMS_TO_TICKS(110));
		
		if( ulEventToProcess != 0){
				rx_data = read_reg(mUSART_DR(mUSART1) , 0x000000FF);
				usart_send_byte((unsigned char)rx_data);
				GPIO_TongglePin(mGPIOD , mGPIO_PIN(13));
	}
}
void vUart_Send(char c){
	ulTaskNotifyTake(pdTRUE , 0);
	usart_send_byte(c);
	
	// block time = 100 ticks
	ulTaskNotifyTake(pdTRUE , 100);
	
}
void test_task_send(void *pvParameters){
	
	unsigned char c  = 65 ; 
	// lan dau tien ngat xay ra khong phai la do truyen du lieu
	ok = 0 ;
	while(1){
		
		vUart_Send(c);
		c += 1 ;
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	
}

u32_t mpin12 = 12;
u32_t mpin13 = 13;
u32_t mpin14 = 14;
u32_t mpin15 = 15;

int main(void)
{

	//100mhz
	system_init( 8, 200, mPLLP_DIV4 , mSRC_PLL, mAHB_DIV1 ,mAPB_DIV2  , mAPB_DIV1);
	rcc_enableclk();
	config_pin();
	uart_init(100 , 16 , 9600);
	init_interrupt();
	//usart_send_string("hello from mcu");
	xTaskCreate(idle_task , "idle_task" , 128 ,&mpin12 ,  1 , NULL);
	xTaskCreate(notify_take_task , "task_receive" , 128 ,NULL ,  2 , &pxTask);
	xTaskCreate(test_task_send , "task_send" , 128 ,NULL ,  2 , &pxTask_receive);
	
	vTaskStartScheduler();

    while(1)
    {
	
    }

}