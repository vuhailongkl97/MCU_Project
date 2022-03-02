#include<regx52.h>
 
#include "Uartmode1.h"


void UART_WRITE(char c){
	while(TI == 0); // wait flag co the truyen tiep du lieu
	TI = 0;			// reset ti 
	SBUF = c;		 // truyen du lieu tren sbuf
}
void UART_INIT(){

// sm 0 sm1 , ren thuoc thanh ghi Scon
	SCON = 0x50;
//	SM0 = 0;
//	SM1 = 1;	 // che do uart mode 1
//	REN = 1; //  CHO PHEP NHAN DU LIEU
	TMOD &= 0x0F;// xoa 4 bit dau
	TMOD |= 0x20;	  // CHE DO HOAT DONG 8 BIT TU DONG NAP LAI
	if(BAUD == 9600)
 	TH1 = 0xFD;		// THONG sO TAO BAUD 9600
	else if(BAUD == 1200)
	TH1 = 0xE6; //  THONG SO TAO 1200 BAUD


	TR1 = 1;   //TIME1 CHAY TAO TOC DO BAUD
	TI = 1; // SAN SANG GUI DU LIEU cho lan dau tien chuong trinh chay

} 

void UART_WRITE_STR(char * str){
	unsigned char i = 0;
	while(str[i] != 0){
		UART_WRITE(str[i]);
		i++;
	}
}