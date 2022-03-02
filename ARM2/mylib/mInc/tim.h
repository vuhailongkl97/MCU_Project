#ifndef __TIM_H__
#define __TIM_H__

void mTIM_Base_SetConfig(u32_t arr , u32_t psc );
void tim_start(u32_t tim);
void TIM_SlaveConfigSynchronization();
void config_ext_clk2();
void input_capture_config(u32_t tim , u32_t fillter);
#endif