#ifndef __CLOCK_H__
#define __CLOCK_H__
#include "main.h"

void rcc_enableclk();
void system_init(u32_t div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb,u32_t div_apb1 , u32_t div_apb2);


#endif
