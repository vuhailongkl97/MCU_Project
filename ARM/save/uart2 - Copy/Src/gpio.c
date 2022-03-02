
#include "project.h"

void init_pin(u32_t mgpio_port , mGPIO_TypeDef *gpio_init){

	u32_t temp_reg, gpio_pin = 0;
	unsigned int i = 0 ;
	
	for ( i = 0 ; i < 16 ; i ++){
		
		gpio_pin = (gpio_init->mpin) & (1u << i );
	//*Configure GPIO MODER pin
		if( gpio_pin != 0){
			//moder
			temp_reg = read_reg(GPIO_MODER(mgpio_port) ,~(3u << (i *2)));
			temp_reg |= (( gpio_init->moder) << (2 * i)); 
			write_reg(GPIO_MODER(mgpio_port) , temp_reg);

			//opendrain or opensource
			temp_reg = read_reg(GPIO_OTYPER(mgpio_port) , ~(1u << i ));
			temp_reg |= ((gpio_init->type) << i);
			write_reg(GPIO_OTYPER(mgpio_port) , temp_reg);

			//pull type
			temp_reg = read_reg(GPIO_PUPDR(mgpio_port) ,~(3u << (i *2)));
			temp_reg |= (( gpio_init->pull) << (2 * i)); 
			write_reg(GPIO_PUPDR(mgpio_port) , temp_reg );

			//speed
			temp_reg = read_reg(GPIO_OSPEEDR(mgpio_port) ,~(3u << (i *2)));
			temp_reg |= (( gpio_init->speed) << (2 * i)); 
			write_reg(GPIO_OSPEEDR(mgpio_port) , temp_reg );
			
			// alternate
		     
		}		
	}
}

void led_on(unsigned long mPORT , unsigned int pin){
	write_reg(  GPIO_BSRR(mPORT) ,  pin);
}
void led_off(unsigned long mPORT  ,unsigned int  pin){
	write_reg(	GPIO_BSRR(mPORT) ,   pin << 16);
}
void GPIO_TongglePin( unsigned long mPORT , unsigned int pin){
	// temp_reg1 get bit[8:0]; temp_reg2 get bit[15:8] of ODR
	unsigned int temp_reg1 = read_reg(GPIO_ODR(mPORT) , ~(0xFFu));
	unsigned int temp_reg2 = read_reg(GPIO_ODR(mPORT) , ~(0xFF00u));
	
	temp_reg1 = (temp_reg2 << 16) | temp_reg1;
	temp_reg1 = ~temp_reg1;
	write_reg(GPIO_BSRR(mPORT) , temp_reg1);
	
}


