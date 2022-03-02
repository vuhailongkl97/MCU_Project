#include "project.h"

// 1. Configure the timers to use the TIx pin as input:
// a) Select the pin to be used by writing CCxS bits in the TIMx_CCMR1 register.
// b) Select the polarity of the input:
// For the STM32F100/101/102/103/105/107 lines: by writing CCxP in the
// mTIM_CCER register to select the rising or the falling edge;
// For the other series & lines: by writing CCxP and CCxNP in the mTIM_CCER
// register to select the rising/falling edge, or both edges (a) .
// c) Enable corresponding channel by setting the CCEx bit in the mTIM_CCER register.
// 2. Select the timer TIx as the trigger input source by writing TS bits in the TIMx_SMCR
// register.
// 3. Select the external clock mode1 by writing SMS=111 in the TIMx_SMCR register.
void config_ext_clk1(){
	u32_t temp_reg;
	// 1.Configure channel 2 to detect rising edges on the TI2 input
	temp_reg = read_reg(mTIM_CCMR1(mTIM2) , ~3u);
	temp_reg |= 1u;
	write_reg(mTIM_CCMR1(mTIM2) , temp_reg);
	
	//2.Configure the input filter duration by writing the IC1F[3:0] bits in the TIMx_CCMR1
	temp_reg = read_reg(mTIM_CCMR1(mTIM2) , ~(0xFU << 4));
	temp_reg |= (3u<<4);
	write_reg(mTIM_CCMR1(mTIM2) , temp_reg);
	
	
	//3. Select rising edge polarity by writing CC1P=0 and CC1NP=0 in the mTIM_CCER
	temp_reg = read_reg(mTIM_CCER(mTIM2) , ~0xFU);
	write_reg(mTIM_CCER(mTIM2) , temp_reg);

	// 4. Select the external clock mode1 by writing SMS=111 in the TIMx_SMCR register.
	temp_reg = read_reg(mTIM_SMCR(mTIM2) , ~(7u << 0));
	temp_reg |= 7U;
	write_reg(mTIM_SMCR(mTIM2) , temp_reg);
	
	// 5.Select TI1 as the input source by writing TS=101 in the TIMx_SMCR register
	temp_reg = read_reg(mTIM_SMCR(mTIM2) , ~(7u << 4));
	temp_reg |= (5U <<4);
	write_reg(mTIM_SMCR(mTIM2) , temp_reg);
	
	//6.update event
	temp_reg = read_reg(mTIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(mTIM_EGR(mTIM2) , temp_reg);
	
		temp_reg = read_reg(mTIM_CR1(mTIM2) , ~(1u << 0));
	temp_reg |=(1U<<0);
	write_reg(mTIM_CR1(mTIM2) , temp_reg);

	
}
void input_capture_config(){
	u32_t temp_reg;
	// Select the active input:01: CC1 channel is configured as input, IC1 is mapped on TI1.
	temp_reg = read_reg(mTIM_CCMR1(mTIM2), ~3u);
	//01: CC1 channel is configured as input, IC1 is mapped on TI1.
	temp_reg |= 1u;
	
	// IC1F Input capture 1 filter
	temp_reg |= (15u << 4);
	write_reg(mTIM_CCMR1(mTIM2) , temp_reg);
	
	
	// Select the edge of the active transition on the TI1 channel by writing the CC1P and
	// CC1NP bits to 00 in the mTIM_CCER register (rising edge in this case).
	temp_reg = read_reg(mTIM_CCER(mTIM2) , ~0xFU);
	write_reg(mTIM_CCER(mTIM4) , temp_reg);
	
	// Program the input prescaler. In our example, we wish the capture to be performed at
	// each valid transition, so the prescaler is disabled (write IC1PS bits to 00 in the
	// TIMx_CCMR1 register).
	
	temp_reg = read_reg(mTIM_CCMR1(mTIM2) , ~(3u << 2));
	write_reg(mTIM_CCMR1(mTIM4) , temp_reg);
	
	// Enable capture from the counter into the capture register by setting the CC1E bit in the
	// mTIM_CCER register.
	
	temp_reg = read_reg(mTIM_CCER(mTIM2) , ~(3u << 2));
	temp_reg |=1U;
	write_reg(mTIM_CCER(mTIM4) , temp_reg);
	
	
	// If needed, enable the related interrupt request by setting the CC1IE bit in the
	// TIMx_DIER register, and/or the DMA request by setting the CC1DE bit in the
	// TIMx_DIER register
	
	// An interrupt is generated depending on the CC1IE bit.
	temp_reg = read_reg(mTIM_DIER(mTIM2) , ~(1u << 1));
	temp_reg |=(1U<<1);
	write_reg(mTIM_DIER(mTIM4) , temp_reg);
	

	
	

}

//confgig tim 4 with output compare on pd12 13 14 15 16 
void tim4_pwm_config(){
// 1. Configure the output pin:
// a) Select the output mode by writing CCS bits in CCMRx register.
	u32_t temp_reg;
	// 1.Configure channel 4 to detect rising edges on the TI2 input
	temp_reg = read_reg(mTIM_CCMR2(mTIM4) , ~( 3u << 8));
	write_reg(mTIM_CCMR2(mTIM4) , temp_reg);
	
// b) Select the polarity by writing the CCxP bit in CCER register.
	temp_reg = read_reg(mTIM_CCER(mTIM4) , ~(0xFU <<12));
	write_reg(mTIM_CCER(mTIM4) , temp_reg);


// 2. Select the PWM mode (PWM1 or PWM2) by writing OCxM bits in CCMRx register.
	temp_reg = read_reg(mTIM_CCMR2(mTIM4) , ~(7U << 12));
	temp_reg |= (6u <<12);
	write_reg(mTIM_CCMR2(mTIM4) , temp_reg);
	
	temp_reg = read_reg(mTIM_CCMR2(mTIM4) , ~(7U << 4));
	temp_reg |= (6u <<4);
	write_reg(mTIM_CCMR2(mTIM4) , temp_reg);
	

// 3. Program the period and the duty cycle respectively in ARR and CCRx registers.
	
	temp_reg = 400u;
	write_reg(mTIM_ARR(mTIM4) , temp_reg);
	
	temp_reg = 200;
	write_reg(mTIM_CCR1(mTIM4) , temp_reg);
	
// 4. Set the preload bit in CCMRx register and the ARPE bit in the CR1 register.
	temp_reg = read_reg(mTIM_CCMR2(mTIM4) , ~(1u << 11));
	temp_reg |= (1u << 11);
	write_reg(mTIM_CCMR2(mTIM4) , temp_reg);
	
	//channel 3
	temp_reg = read_reg(mTIM_CCMR2(mTIM4) , ~(1u << 3));
	temp_reg |= (1u << 3);
	write_reg(mTIM_CCMR2(mTIM4) , temp_reg);
	
	temp_reg = read_reg(mTIM_CR1(mTIM4) , ~(1u<<7));
	temp_reg |= (1u<<7);
	write_reg(mTIM_CR1(mTIM4) , temp_reg);
	
	temp_reg = read_reg(mTIM_EGR(mTIM4) , ~1u);
	temp_reg |= 1u;
	write_reg(mTIM_EGR(mTIM4) , temp_reg);	
	
	

// 5. Select the counting mode:
// a) PWM edge-aligned mode: the counter must be configured up-counting or down-
// counting.

// using edge-aligned mode by default
	
// b) PWM center aligned mode: the counter mode must be center aligned counting
// mode (CMS bits different from '00').

		

// 6. Enable the capture compare.
	temp_reg = read_reg(mTIM_CCER(mTIM4) , ~(1u <<12));
	temp_reg |= (1u <<12);
	write_reg(mTIM_CCER(mTIM4) , temp_reg);
	
	temp_reg = read_reg(mTIM_CCER(mTIM4) , ~(1u <<8));
	temp_reg |= (1u <<8);
	write_reg(mTIM_CCER(mTIM4) , temp_reg);
	
// 7. Enable the counter.
}

























