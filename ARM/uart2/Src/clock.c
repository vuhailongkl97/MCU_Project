#include "project.h"



// cau hinh max speed rcc
void system_init(u32_t div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb , u32_t div_apb1 , u32_t div_apb2){
	
  volatile u32_t temp_reg;
  volatile u32_t timeout;
  
  		//enable FPU
	temp_reg = read_reg(FPU_CPACR, ~0u);
	temp_reg |= (0xF <<20);
	write_reg(FPU_CPACR , temp_reg) ; 
  
 
  /* Disable all interrupts */
   write_reg(RCC_CIR, 0x00000000U);


   // __HAL_RCC_SYSCFG_CLK_ENABLE();
   write_reg(RCC_APB2ENR , (1u <<14 ));
   
   //  __HAL_RCC_PWR_CLK_ENABLE();  	
   write_reg(RCC_APB1ENR , (1u <<28 ));
   
   //__HAL_PWR_VOLTAGESCALING_ONFIG(PWR_REGULATOR_VOLTAGE_SCALE1); for using clock <= 100mhz 
   temp_reg = read_reg(PWR_CR , ~(3u << 14 ));
   temp_reg |= (3u << 14);
   write_reg( PWR_CR , temp_reg);
   
   //HSE clock bypass
   	temp_reg = read_reg(RCC_CR, ~(1u << 18 ));
	temp_reg |= (0u << 18);
    write_reg(RCC_CR, temp_reg);
	
	
	//bat hse
	temp_reg = read_reg(RCC_CR, ~(1u << 16 ));
	temp_reg |= (1u << 16);
    write_reg(RCC_CR, temp_reg);
	
	timeout = 0xFF;
    do {
       
        timeout--;
    } while ((0 == (read_reg(RCC_CR, (1u << 17)))) && (timeout > 0));
	
	
    
	/* Disable the main PLL. */
    temp_reg = read_reg(RCC_CR, ~(1 << 24));
    write_reg(RCC_CR, temp_reg);
	
	/* Wait till PLL is disable */
    timeout = 0xFFF;
    do {
        timeout--;
    } while ((0 != (read_reg(RCC_CR, (1 << 25)))) && (timeout > 0));
	
	// can thiet lap ko se doc sai dia chi lenh , du lieu FLASH_LATENCY_2
	write_reg(FLASH_ACR , 0x03u);
	

	
    temp_reg = read_reg(RCC_PLLCFGR, ~(0x01 << 22));
    temp_reg |= (1u <<22);
    write_reg(RCC_PLLCFGR, temp_reg);
	

    	
	
	
    temp_reg = read_reg(RCC_PLLCFGR, ~0x3Fu);
    temp_reg |= div_m;
    write_reg(RCC_PLLCFGR, temp_reg);
    
	// nhan *N   *100
    temp_reg = read_reg(RCC_PLLCFGR, ~(0x1FFu << 6));
    temp_reg |= (mul_n << 6);
    write_reg(RCC_PLLCFGR, temp_reg);
	
	// chia /P  /2

    temp_reg = read_reg(RCC_PLLCFGR, ~(0x3u<< 16));
    temp_reg |= (div_p << 16);
    write_reg(RCC_PLLCFGR, temp_reg);
	
	
	/* Enable the main PLL. */
    temp_reg = read_reg(RCC_CR, ~(1 << 24));
    temp_reg |= (1 << 24);
    write_reg(RCC_CR, temp_reg);
	
	/* Wait till PLL is ready */
    timeout = 0xFFFF;
    do {
        timeout--;
    } while ((0 == (read_reg(RCC_CR, (1 << 25)))) && (timeout > 0));
	

	//  chia 1 
    temp_reg = read_reg(RCC_CFGR, ~(0xFu << 4));
	temp_reg |= ( div_ahb << 4);
    write_reg(RCC_CFGR, temp_reg);	
	
	 /* APB1 prescaler */
	// chia toi da
    temp_reg = read_reg(RCC_CFGR, ~(0x07u << 10));
	temp_reg |= (APB_DIV16 << 10);
    write_reg(RCC_CFGR, temp_reg);
	// APB2 giong APB1
	temp_reg = read_reg(RCC_CFGR, ~(0x07u << 13));
	temp_reg |= (APB_DIV16 << 13);
    write_reg(RCC_CFGR, temp_reg);
	

	//select source
    temp_reg = read_reg(RCC_CFGR, ~(0x3u << 0));
    temp_reg |= (system_source << 0);
    write_reg(RCC_CFGR, temp_reg);
    
    // /* Wait till System clock switch is ready */
    timeout = 0xFFFFFF;
    do {
        timeout--;
    } while (((system_source << 2) != ( read_reg(RCC_CFGR, (0x3 << 2)))) && (timeout > 0));
	
	
    /* APB1 prescaler */
	//  apb1 chia 2
    temp_reg = read_reg(RCC_CFGR, ~(7u << 10));
	temp_reg |=  (div_apb1 << 10);
    write_reg(RCC_CFGR, temp_reg);
	
	
	// apb2 chia 1
	temp_reg = read_reg(RCC_CFGR, ~(7u << 13));
	temp_reg |=  (div_apb2 << 10);
    write_reg(RCC_CFGR, temp_reg);
	

}
void rcc_enableclk(){
	u32_t temp_reg;
	
	// enable port h
	temp_reg = read_reg(RCC_AHB1ENR , ~(1 <<7));
	temp_reg  = temp_reg | (1 << 7 );
	write_reg(RCC_AHB1ENR , temp_reg );	

	//port d 
	temp_reg = read_reg(RCC_AHB1ENR , ~(1 <<3));
	temp_reg  = temp_reg | (1 << 3 );
	write_reg(RCC_AHB1ENR , temp_reg );
	
	//port b
	temp_reg = read_reg(RCC_AHB1ENR , ~(1 <<1));
	temp_reg  = temp_reg | (1 << 1 );
	write_reg(RCC_AHB1ENR , temp_reg );
  
}