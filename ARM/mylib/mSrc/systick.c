#include "all_lib.h"

void systick_init(){
	unsigned int temp_reg;
	
	// disable systick
	temp_reg = read_reg(mSYST_CSR , ~(1<<0));
	write_reg(mSYST_CSR , temp_reg);
	
	// lua chon source clock  clock processor
	temp_reg = read_reg(mSYST_CSR , ~(1<<2));
	temp_reg |= (0x01u << 2 );
	write_reg(mSYST_CSR , temp_reg);
	
	// reset value in cureent value register
	write_reg(mSYST_CVR , 0u);
}
void systick_start(unsigned int value){
	
	unsigned int temp_reg;
	
	// ghi gia tri cho reload value register
	write_reg(mSYST_RVR , value);
	
	// write for current value reload register
	write_reg(mSYST_CVR , 0u);
	
	// enable systick 
	temp_reg = read_reg(mSYST_CSR , ~(1<<0));
	temp_reg |= 0x01 ;
	write_reg(mSYST_CSR , temp_reg);


}
// get COUNTFLAG;
unsigned int  get_state_systick(){

		unsigned int temp_reg = read_reg(mSYST_CSR , (1 <<16));
		temp_reg =  temp_reg >> 16;
		return temp_reg;
}	
void delay_ms_systick(unsigned int value){
	value += value;
	while( value --){
		// 0.5ms . clock = 100mhz 
			systick_start(0xC34FU);
			while( 0 == get_state_systick());
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	