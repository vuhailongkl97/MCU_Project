#ifndef _UARTMODE1_H_
#define  _UARTMODE1_H_
#include<regx52.h>


#define FREQ_OSC  11059200ul
#define BAUD  9600

void UART_WRITE(char ); //  GUI 1 KY TU 
void UART_WRITE_STR(char * );	// GUI 1 CHUOI

void UART_INIT();			   // KHOI TAO UART (NHAN REN , TI GUI) 



#endif