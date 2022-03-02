#include "project.h"

void uart_pin_init();

void uart_init(u32_t  fclk ,unsigned  int oversampling ,u32_t baudrate ){
	
	u32_t temp_reg ,brr_baud;
	float  ftemp  = (1000000.0* fclk) / (baudrate* oversampling);
	u32_t     DIV_Mantissa  = (u32_t )ftemp;
    float    f_DIV_Fraction = (ftemp - DIV_Mantissa)*oversampling;
	u32_t   DIV_Fraction = (u32_t) f_DIV_Fraction;
	brr_baud =  ( DIV_Mantissa <<4 ) | DIV_Fraction;
	
	uart_pin_init();
	
	//ENABLE UART1
	temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1<<13));
	temp_reg |= (1<<13);
    write_reg(mUSART_CR1(mUSART1), temp_reg);	

		// data 8bit 	
	temp_reg = read_reg(mUSART_CR1(mUSART1) ,~(1 <<12));
	write_reg(mUSART_CR1(mUSART1) , temp_reg);
	
	// 1 stop 
	temp_reg = read_reg(mUSART_CR2(mUSART1) ,~(3 <<12));
	temp_reg |= (0 << 12);
	write_reg(mUSART_CR2(mUSART1) , temp_reg);		

	//no  parity 
	temp_reg = read_reg(mUSART_CR1(mUSART1) ,~(1 <<10));
	write_reg(mUSART_CR1(mUSART1) , temp_reg);
	
	
	/* Clear CTSE and RTSE bits */
	temp_reg = read_reg(mUSART_CR1(mUSART1) ,~(3 <<8));
	write_reg(mUSART_CR1(mUSART1) , temp_reg);	
	 
	//no  sampleing
	temp_reg = read_reg(mUSART_CR1(mUSART1) ,~(1 <<15));
	write_reg(mUSART_CR1(mUSART1) , temp_reg);
		
	//setup baudrate
	write_reg(mUSART_BRR(mUSART1) , brr_baud);
		
	
	/* Tx Enable */
    temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1<<3));
    temp_reg |= (1 << 3);
    write_reg(mUSART_CR1(mUSART1), temp_reg);

    /* Rx Enable */
    temp_reg = read_reg(mUSART_CR1(mUSART1), ~(1<<2));
    temp_reg |= (1<<2);
    write_reg(mUSART_CR1(mUSART1), temp_reg);
	

}
char usart_send_byte(unsigned char data){
	
	u32_t temp_reg ;
	// kiem tra TDR san sang nhan du lieu moi hay chua
	temp_reg = read_reg(mUSART_SR(mUSART1) , (1 << 7));
	if( temp_reg != 0){
		// bat dau truyen 
		write_reg(mUSART_DR(mUSART1) , (u32_t)data);
		
		return 1;
	}
	return 0;
	
}
char usart_send_string( char *str){
	
		while(*str){
			if(usart_send_byte(*str))
				str++;
		}
	return 0;
}
// using pb7rx pb6 tx
void uart_pin_init(){
	u32_t temp_reg;
	
		//enable clock for uart
	temp_reg = read_reg(mRCC_APB2ENR, ~(1u << 4));
    temp_reg |= (1 << 4);
    write_reg(mRCC_APB2ENR, temp_reg);
	
		// Pb7 -RX
	temp_reg = read_reg(mGPIO_MODER(mGPIOB) , ~(3u << 14 ));
	temp_reg  = temp_reg | (mGPIO_MODER_ALT << 14);
	write_reg(mGPIO_MODER(mGPIOB) , temp_reg );
	
	temp_reg = read_reg(mGPIO_PUPDR(mGPIOB) , ~(3u << 14 ));
	temp_reg  = temp_reg | (mPULL_UP << 14);
	write_reg(mGPIO_PUPDR(mGPIOB) , temp_reg );
	
	
	temp_reg = read_reg(mGPIO_AFRL(mGPIOB) , ~(0x0Fu << 28 ));
	temp_reg  = temp_reg | (7u << 28);
	write_reg(mGPIO_AFRL(mGPIOB) , temp_reg );

	//Pb6 - TX
	
	temp_reg = read_reg(mGPIO_MODER(mGPIOB) , ~(3u << 12 ));
	temp_reg  = temp_reg | (mGPIO_MODER_ALT << 12);
	write_reg(mGPIO_MODER(mGPIOB) , temp_reg );
	
	temp_reg = read_reg(mGPIO_PUPDR(mGPIOB) , ~(3u << 12 ));
	temp_reg  = temp_reg | (mPULL_UP << 12);
	write_reg(mGPIO_PUPDR(mGPIOB) , temp_reg );
	
	temp_reg = read_reg(mGPIO_AFRL(mGPIOB) , ~(0x0Fu << 24 ));
	temp_reg  = temp_reg | (7u << 24);
	write_reg(mGPIO_AFRL(mGPIOB) , temp_reg );
	
}
void usart_dma_en(){
	u32_t temp_reg = read_reg(mUSART_CR3(mUSART1) ,~(1 <<6));
	temp_reg |= (1 << 6);
	write_reg(mUSART_CR3(mUSART1) , temp_reg);		
}























