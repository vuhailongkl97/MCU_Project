
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
#if 1 
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


#define mGPIOA (BASE_ADDR + 0x00u) 
#define mGPIOB (BASE_ADDR + 0x400u)
#define mGPIOC (BASE_ADDR + 0x800u)
#define mGPIOD (BASE_ADDR + 0xC00u)
#define mGPIOE (BASE_ADDR + 0x1000u)
#define mGPIOH (BASE_ADDR + 0x1C00u)


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
#define NVIC_ISER(x) (0xE000E100u + (4*x) )
#define NVIC_ICER 0XE000E180u
#define NVIC_ISPR 0XE000E200u
#define NVIC_ICPR 0XE000E280u
#define NVIC_IPR(x) (0xE000E400 + (4*x) )



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
#define mPWR 0x40007000u
#define PWR_CR (mPWR + 0x00u)


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
#if 1
void init_pin(u32_t mgpio_port , mGPIO_TypeDef *gpio_init){

	u32_t temp_reg, gpio_pin = 0, addr_alternate;
	unsigned int i = 0 ;
	
	for ( i = 0 ; i < 16 ; i ++){
		
		gpio_pin = (gpio_init->mpin) & (1u << i );
	//*Configure GPIO MODER pin
		if( gpio_pin != 0){
			//moder
			temp_reg = read_reg(GPIO_MODER(mgpio_port) ,~(3u << (i *2)));
			temp_reg |= (( gpio_init->moder) << (2 * i)); 
			write_reg(GPIO_MODER(mgpio_port) , temp_reg);

			//opendrain or opensource
			temp_reg = read_reg(GPIO_OTYPER(mgpio_port) , ~(1u << i ));
			temp_reg |= ((gpio_init->type) << i);
			write_reg(GPIO_OTYPER(mgpio_port) , temp_reg);

			//pull type
			temp_reg = read_reg(GPIO_PUPDR(mgpio_port) ,~(3u << (i *2)));
			temp_reg |= (( gpio_init->pull) << (2 * i)); 
			write_reg(GPIO_PUPDR(mgpio_port) , temp_reg );

			//speed
			temp_reg = read_reg(GPIO_OSPEEDR(mgpio_port) ,~(3u << (i *2)));
			temp_reg |= (( gpio_init->speed) << (2 * i)); 
			write_reg(GPIO_OSPEEDR(mgpio_port) , temp_reg );
			
			// alternate

			
			if(i  < 8 )
				addr_alternate = GPIO_AFRL(mgpio_port);
			else 
				addr_alternate = GPIO_AFRH(mgpio_port);

			// %8  ra vi tri 
			temp_reg = read_reg(addr_alternate ,~(0xFu << ( (i&0x7U) *4)));
			temp_reg |= gpio_init->alternate;
			write_reg(addr_alternate , temp_reg);
			
		}		
	}
}
void mNVIC_SetPriority(IRQn_Type ipr , u32_t pri){
	// chia 4 .. stm32f4 chi dung 4 bit priority	 
	unsigned int addr_ipr = (NVIC_IPR( ((u32_t)ipr >> 2u) )) ;
	u32_t temp_reg = read_reg(addr_ipr, ~0u);
	temp_reg |=  ( ((u32_t)pri  & 0xFFu ) << 4u ) ;
	write_reg(addr_ipr, temp_reg);
	 
}
void mNVIC_EnableIRQ(IRQn_Type irq){
	// iser /32 ,%32
	unsigned int addr_irq = NVIC_ISER( ((u32_t)irq >> 5u) )  ;
	
	u32_t temp_reg = read_reg(addr_irq , ~0u);
	temp_reg |=  (u32_t)(1UL << ((u32_t)irq & 0x1Fu )) ;
	write_reg(addr_irq, temp_reg);
	
}

void counter2_config(){
	unsigned int temp_reg , tmpccer ,tmpccmr1 ;

	/* Peripheral clock enable */
	temp_reg = read_reg(RCC_APB1ENR , ~0u);
	temp_reg |= (1u << 0 );
	write_reg(RCC_APB1ENR , temp_reg);
	htim2.Instance = TIM2;

	
		mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  GPIO_PIN(0);
	GPIO_Init.moder = GPIO_MODER_ALT;
	GPIO_Init.type = PUSH_PULL;
	GPIO_Init.pull  = NO_PULL;
	GPIO_Init.speed = FAST_SPEED;
	//af1
	GPIO_Init.alternate = 1; 
	
	init_pin(mGPIOA , &GPIO_Init);
	
//	HAL_NVIC_SetPriority(TIM2_IRQn , 0 , 0);
//	HAL_NVIC_EnableIRQ(TIM2_IRQn );
//	
//	GPIO_InitTypeDef GPIO_InitStruct;

//    GPIO_InitStruct.Pin = GPIO_PIN_0;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	mNVIC_SetPriority(TIM2_IRQn, 0);
	mNVIC_EnableIRQ(TIM2_IRQn);
	
//////////////////////	HAL_TIM_Base_MspInit(&htim2);
	
	
	/* Set TIM Time Base Unit parameters ---------------------------------------*/
	//dir =0, cms = 0
	temp_reg = read_reg(TIM_CR1(mTIM2), ~(0x07u<<4));
	temp_reg |=  0u<< 4;
	write_reg(TIM_CR1(mTIM2) , temp_reg);
	
	//ckd ClockDivision / 1
	temp_reg = read_reg(TIM_CR1(mTIM2) , ~(3u << 8));
	write_reg(TIM_CR1(mTIM2) , temp_reg);
	
	
	/* Set the Auto-reload value  = 10 */
	//temp_reg = read_reg(TIM_ARR(mTIM2) , ~0u);
	temp_reg = 10u;
	write_reg(TIM_ARR(mTIM2) , temp_reg);	
	
	/* Set the Prescaler value */
	//temp_reg = read_reg(TIM_PSC(mTIM2) , ~0u);
	temp_reg = 0u;
	write_reg(TIM_PSC(mTIM2) , temp_reg);	


	/* Generate an update event to reload the Prescaler 
	and the repetition counter(only for TIM1 and TIM8) value immediately */
	
	temp_reg = read_reg(TIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(TIM_EGR(mTIM2) , temp_reg);	
	
	  /* Set the Time Base configuration */
				/* Set the Input Trigger source */
				temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u <<4));
				temp_reg |= (5u <<4);
				write_reg(TIM_SMCR(mTIM2) , temp_reg);	
				
				/* Set the slave mode */
				temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u <<0));
				temp_reg |= 7u;
				write_reg(TIM_SMCR(mTIM2) , temp_reg);
	
   	/* Configure the trigger prescaler, filter, and polarity */  
					  
						tmpccer = read_reg(TIMx_CCER(mTIM2) , ~(1u <<0));
						
						tmpccmr1 = read_reg(TIM_CCMR1(mTIM2) , ~0U);
						
					  
					  
		  // /* Set the filter */
		  
		  tmpccmr1   &= ~(0xFu << 4);
		  tmpccmr1   |= (15u << 4);
		  
		  // /* Select the Polarity and set the CC1E Bit */
		  // tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
		  // tmpccer |= TIM_ICPolarity;
		  
		  tmpccer  &= ~(1u <<0 | 1u << 3);
		  
		  tmpccer |= 0u;
		  write_reg(TIMx_CCER(mTIM2) , tmpccer);
		  write_reg(TIM_CCMR1(mTIM2) , tmpccmr1);



			// /* Disable Trigger Interrupt */		
			// __HAL_TIM_DISABLE_IT(htim, TIM_IT_TRIGGER); bit6 dier. TIE: Trigger interrupt enable
			
			temp_reg = read_reg(TIM_DIER(mTIM2) , ~(1u << 6));
			//temp_reg |= (1u << 6);
			write_reg(TIM_DIER(mTIM2) , temp_reg);
			

			// /* Disable Trigger DMA request */
			// __HAL_TIM_DISABLE_DMA(htim, TIM_DMA_TRIGGER);
			temp_reg = read_reg(TIM_DIER(mTIM2) , ~(1u << 14));
			write_reg(TIM_DIER(mTIM2) , temp_reg);			

			
			
			
		// HAL_TIMEx_MasterConfigSynchronization	
		// /* Reset the MMS Bits */
		// htim->Instance->CR2 &= ~TIM_CR2_MMS;

		// /* Select the TRGO source */
		// htim->Instance->CR2 |= sMasterConfig->MasterOutputTrigger;
		temp_reg  = read_reg(TIM_CR2(mTIM2) , ~(7u << 4));
		write_reg(TIM_CR2(mTIM2) , temp_reg);
		
		// /* Set or Reset the MSM Bit */
		// htim->Instance->SMCR |= sMasterConfig->MasterSlaveMode;
		temp_reg  = read_reg(TIM_SMCR(mTIM2) , ~(1u << 7));
		write_reg(TIM_SMCR(mTIM2) , temp_reg);
}
#endif
int main(){
	HAL_Init();
  SystemClock_Config();
	MX_GPIO_Init();
  counter2_config();
	counter2_start();
	
	
	
	while(1);
	return 0;
}

