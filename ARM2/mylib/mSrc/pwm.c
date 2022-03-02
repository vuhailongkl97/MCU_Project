#include "all_lib.h"

void set_duty_tim(u32_t tim , u32_t duty , u32_t channel){
	//test for channel 1 
	switch(channel)
	{		
		case 1:
			write_reg(mTIM_CCR1(tim) , duty);
			break;	
		case 2:
			write_reg(mTIM_CCR2(tim) , duty);
			break;
		
		case 3:
			write_reg(mTIM_CCR3(tim) , duty);
			break;		
		case 4:
			write_reg(mTIM_CCR4(tim) , duty);
			break;
	}
}