#include<regx52.h>
#include "Uartmode1.h"
#include <string.h>

void xuatketqua(unsigned int high , int i){
	unsigned int h =high  ,j = 0 , temp =100;
	while(temp  != 1 ){
			temp = 1; 
			for( j = 1 	; j <= i ; j++) temp *= 10;
			UART_WRITE((h/temp)%10 +'0');			
			i--;
	}
	UART_WRITE_STR(" ms\r\n");
}
unsigned int heso = 0;
void InitTimer(){
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	ET0 = 1;	
	EA = 1;
	TH0 = 0xFB;
	TL0  =0xC3;
}
void chon(char a[] , int n ){
	int min , j , i;
	for(  i = 0 ; i < n ; i++)
	{
		min = i ; 
		for( j = i+1 ; j < n ; j ++){
			if(a[min] > a[j]) min = j ; 
		}
		if( min != i ){
			char temp = a[i];
			a[i] = a[min];
			a[min] =temp;
		}
	}	
}
void  noibot(char a[] , int n ){
	unsigned int i , j ; 
	for ( i = 0 ; i < n-1  ; i ++){
		for ( j =n-1 ; j >i ; j --){
			if(a[j] < a[j-1]){
				char temp = a[j];
			 	a[j] =a[j-1];
			 	a[j-1] = temp;
			}
		}
	}
}
void quickSort(char *a, int l, int r)
{
   
    int key = a[(l+r)/2];
    int i = l, j = r;
  
    while(i <= j)
    {
        
        while (a[i] < key) { i++;  }
    
        while (a[j] > key) { j--;  }
        if(i <= j)
        {
            if (i < j)
            {
                char temp  = a[i];
				a[i] = a[j];
				a[j] = temp;
            }
            i++;
            j--;
        }
    }
    //bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
    if (l < j) quickSort(a, l, j);   // lam lai voi mang a[l]....a[j]
    if (i < r) quickSort(a, i, r); // lam lai voi mang a[i]....a[r]
}

void chen(char a[] , int n ){
	unsigned int i , j ;
	for (  i = 1; i < n ; i++){
		for( j = i ; j >0 ; j--){
			if(a[j] < a[j-1]){
				char temp = a[j];
				a[j]=a[j-1];
				a[j-1] =temp;
			}
		}
	}
}
void main(){
 	 unsigned int i  = 0 , size = 100; 
	// 1 xung dem mat 1.085us
	//1 lan overflow mat 71ms

  code 	char arr[] = {1,26,28,82,6,44,30,53,50,99,91,63,40,74,36,92,50,69,36,82,68,99,74,16,73,15,80,5,54,79,51,30,84,50
	,86,81,18,3,60,99,41,25,93,93,1,36,52,57,91,63,69,42,53,43,87,16,69,33,82,16,31,23,66,29,5,38,17,51,86,39
	,71,19,32,36,28,13,52,98,65,55,29,32,44,59,13,77,94,84,31,94,22,61,3,83,48,32,24,35,59 ,69 };
	char temp[100];
	strncpy(temp , arr , size);
	UART_INIT();
	InitTimer();
	UART_WRITE_STR("SX CHON  :");
	TH0 =0xFB;TL0 = 0xC3;
	TR0 = 1 ;					 
	chon(temp , size);
	TR0 = 0;
	xuatketqua(heso, 5);


	UART_WRITE_STR("SX NOI BOT  :");
	heso = 0;
	TH0 =0xFB;TL0 = 0xC3;
	TR0 = 1 ;				 
	strncpy(temp , arr , size);
	noibot(temp , size);
	TR0 = 0 ;
	xuatketqua(heso, 5);

	UART_WRITE_STR("SX CHEN  :");
	heso = 0 ;
    TH0 =0xFB;TL0 = 0xC3;
	TR0 = 1 ;				 
	strncpy(temp , arr , 100);
	chen(temp , size);
	TR0 = 0 ;
	xuatketqua(heso, 5);

	UART_WRITE_STR("SX QuickSort  :");
	heso = 0 ;
	TH0 =0xFB;TL0 = 0xC3;
	TR0 = 1 ;				 
	strncpy(temp , arr , 100);
	quickSort(temp , 0 , size-1 );
	TR0 = 0 ;
	xuatketqua(heso, 5);

    while(1){	
  }	
}
// do chinh xac 1ms;
void overFlowTimer0() interrupt 1{
	TR0 = 0 ; 
	TH0 =0xFB;
	TL0 = 0xC3;
	heso ++;
	TR0  = 1 ; 
} 