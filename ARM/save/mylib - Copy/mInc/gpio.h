#ifndef __GPIO_H__
#define __GPIO_H__
#include "all_lib.h"
void led_on(unsigned long mPORT ,unsigned int pin);
void led_off(unsigned long mPORT ,unsigned int pin);
void GPIO_TongglePin(unsigned long mPORT, unsigned int pin);
void init_pin(unsigned int mgpio_port , mGPIO_TypeDef *gpio_nit);

void delay (unsigned int );	

#endif
