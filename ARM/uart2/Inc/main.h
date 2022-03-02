
#ifndef __MAIN_H__
#define __MAIN_H__


#define write_reg(addrs , value )    *((unsigned long  int * )(addrs))  = value
#define read_reg(addrs , mask )		 *((unsigned long  int * )(addrs))  & mask
typedef unsigned int u32_t;
typedef struct{
	u32_t  mpin;
	u32_t  moder;
	u32_t  type;
	u32_t  pull;
	u32_t  speed;
	u32_t  alternate;
}mGPIO_TypeDef;

///////////////   BASE_ADDR      ///////////////
#define BASE_ADDR 0x40020000u


#define GPIOA (BASE_ADDR +  0x200u) 
#define GPIOB (BASE_ADDR + 0x400u)
#define GPIOC (BASE_ADDR + 0x800u)
#define GPIOD (BASE_ADDR + 0xC00u)
#define GPIOE (BASE_ADDR + 0x1000u)
#define GPIOH (BASE_ADDR + 0x1C00u)


#define GPIO_MODER(GPIO)   (GPIO + 0x00u)
#define GPIO_OTYPER(GPIO)  (GPIO + 0x04u)
#define GPIO_OSPEEDR(GPIO) (GPIO + 0x08u)
#define GPIO_PUPDR(GPIO)   (GPIO + 0x0Cu)
#define GPIO_IDR(GPIO)     (GPIO + 0x10u)
#define GPIO_ODR(GPIO)     (GPIO + 0x14u)
#define GPIO_BSRR(GPIO)    (GPIO+ 0x18u)
#define GPIO_AFRL(GPIO)    (GPIO + 0x20u)
#define GPIO_AFRH(GPIO)    (GPIO + 0x24u)

///////////////   MODE PIN       ///////////////
#define GPIO_MODER_INPUT    0x00
#define GPIO_MODER_OUTPUT   0x01
#define GPIO_MODER_ALT  	0x02
#define GPIO_MODER_ANALOG   0x03


#define PUSH_PULL  0u
#define OPEN_DRAIN 1u


#define NO_PULL 	0u
#define PULL_UP 	1u
#define PULL_DOWN   2u

#define LOW_SPEED   	0u
#define MEDIUM_SPEED   	1u
#define FAST_SPEED   	2u
#define HIGH_SPEED   	3u

#define GPIO_PIN(n)     (1 << n)


/////////////////// RCC /////////////////////////

#define BASE_RCC		 0x40023800u  
#define RCC_CR          (BASE_RCC + 0x00u)
#define RCC_PLLCFGR     (BASE_RCC + 0x04u)
#define RCC_CFGR        (BASE_RCC + 0x08u)
#define RCC_CIR         (BASE_RCC + 0x0Cu)
#define RCC_AHB1ENR     (BASE_RCC + 0x30u)
#define RCC_APB2ENR		(BASE_RCC + 0x44u)
#define RCC_APB1ENR		(BASE_RCC + 0x40u)


// /M *N /P
// M , N khong can tinh ( nhu thap phan )

#define PLLP_DIV2 0u
#define PLLP_DIV4 1u
#define PLLP_DIV6 2u
#define PLLP_DIV8 3u

//APBx
#define APB_DIV1  0u
#define APB_DIV2  4u
#define APB_DIV4  5u
#define APB_DIV8  6u
#define APB_DIV16 7u

// AHB prescaler
#define AHB_DIV1  	0u
#define AHB_DIV2  	8u
#define AHB_DIV4  	9u
#define AHB_DIV8  	10u
#define AHB_DIV16	11u
#define AHB_DIV64 	12u
#define AHB_DIV128	13u
#define AHB_DIV256 	14u
#define AHB_DIV512 	15u

#define SRC_HSI 0u
#define SRC_HSE 1u
#define SRC_PLL 2u






//  EXTI
#define BASE_EXTI 0x40013C00u
#define EXTI_IMR     (BASE_EXTI + 0x00u)
#define EXTI_EMR     (BASE_EXTI + 0x04u)
#define EXTI_RTSR     (BASE_EXTI + 0x08u)
#define EXTI_FTSR     (BASE_EXTI + 0x0Cu)
#define EXTI_PR     (BASE_EXTI + 0x14u)

///////////   SYSCFG   /////////////////
#define BASE_SYSCFG 0x40013800u
#define SYSCFG_EXTICR1 (BASE_SYSCFG +  0x08u)

////////////////////////////////////////////


/////////////////////NVIC  /////////////////
#define NVIC_ISER(x) (0xE000E100u + (4*x))
#define NVIC_ICER 0XE000E180u
#define NVIC_ISPR 0XE000E200u
#define NVIC_ICPR 0XE000E280u
#define NVIC_IPR(x) (0xE000E400 + (4*x))



////////////////////////////////////////////
#define BASE_ADDR_UART   0x40011000u  
#define USART_SR      (BASE_ADDR_UART + 0x00u)
#define USART_DR      (BASE_ADDR_UART + 0x04u)
#define USART_BRR     (BASE_ADDR_UART + 0x08u)
#define USART_CR1     (BASE_ADDR_UART + 0x0Cu)
#define USART_CR2     (BASE_ADDR_UART + 0x10u)
#define USART_CR3     (BASE_ADDR_UART + 0x14u)
#define USART_GTPR    (BASE_ADDR_UART + 0x18u)


//flash
#define BASE_FLASH 0x40023C00u
#define FLASH_ACR ( BASE_FLASH +0x00u) 

// systick 
#define SYST_CSR 0xE000E010
#define SYST_RVR 0xE000E014
#define SYST_CVR 0xE000E018
#define SYST_CALIB 0xE000E01C

//POWWER
#define PWR 0x40007000u
#define PWR_CR (PWR + 0x00u)


// mTIM2
#define  mTIM2   0x40000000u



#define TIM_CR1(x)    ( x + 0u )
#define TIM_CR2(x)    ( x + 4u )
#define TIM_SMCR(x)   ( x + 8u )
#define TIM_DIER(x)   ( x + 12u )
#define TIM_SR(x)     ( x + 16u )
#define TIM_EGR(x)    ( x + 20u )
#define TIM_CCMR1(x)  ( x + 24u )
#define TIM_CCMR2(x)  ( x + 28u )
#define TIMx_CCER(x)  ( x + 32u )
#define TIM_CNT(x)    ( x + 36u )
#define TIM_PSC(x)    ( x + 40u )
#define TIM_ARR(x)    ( x + 44u )
#define TIM_CCR1(x)   ( x + 52u )
#define TIM_CCR2(x)   ( x + 56u )
#define TIM_CCR3(x)   ( x + 60u )
#define TIM_CCR4(x)   ( x + 64u )
#define TIM_DCR(x)    ( x + 72u )
#define TIM_DMAR(x)   ( x + 76u )
#define TIM2_OR     ( mTIM2 + 80u )


//FPU Float Pointing Uinit
#define FPU_CPACR  0xE000ED88  
#define FPU_FPCCR  0xE000EF34   
#define FPU_FPCAR  0xE000EF38 
#define FPU_FPDSCR 0xE000EF3C  




#endif