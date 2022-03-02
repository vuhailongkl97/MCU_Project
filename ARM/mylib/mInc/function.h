#ifndef __FUNC_H__
#define __FUNC_H__

#define write_reg(addrs , value )    *((unsigned long  int * )(addrs))  = value
#define read_reg(addrs , mask )		 *((unsigned long  int * )(addrs))  & mask
#define set_bit(addr , bit)  (*((unsigned long *)(addr)) |= bit)
#define clear_bit(addr , bit)  (*((unsigned long *)(addr)) &= (~bit) )
#define read_bit(addr , bit)  (*((unsigned long *)(addr)) & bit )
#define clear_reg(addr )  (*((unsigned long *)(addr)) = 0u )

#define	enable_rcc_gpioa() (set_bit(mRCC_AHB1ENR , 1U ))
#define	enable_rcc_gpiob() (set_bit(mRCC_AHB1ENR , 2U ))
#define	enable_rcc_gpioc() (set_bit(mRCC_AHB1ENR , 4U ))
#define	enable_rcc_gpiod() (set_bit(mRCC_AHB1ENR , 8U ))
#define	enable_rcc_gpioe() (set_bit(mRCC_AHB1ENR , (1U<<4) ))
#define	enable_rcc_gpioh() (set_bit(mRCC_AHB1ENR , ( 1U << 7) ))



#define	enable_rcc_tim2() (set_bit(mRCC_APB1ENR , ( 1U << 0) ))
#define	enable_rcc_tim3() (set_bit(mRCC_APB1ENR , ( 1U << 1) ))
#define	enable_rcc_tim4() (set_bit(mRCC_APB1ENR , ( 1U << 2) ))
#define	enable_rcc_tim5() (set_bit(mRCC_APB1ENR , ( 1U << 3) ))

#endif