#ifndef __SYSTICK_H_
#define __SYSTICK_H_

void systick_init();
void systick_start(unsigned int value);
unsigned int get_state_systick();
void delay_ms_systick(unsigned int value);

#endif
