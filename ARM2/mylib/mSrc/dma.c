#include "all_lib.h"

extern volatile unsigned char rx_data;
void config_dma(u32_t dma , u32_t stream ,u32_t channel , u32_t dir , u32_t circular  , u32_t pinc \
          , u32_t minc , u32_t psize , u32_t msize , u32_t pl   )
{
	
	u32_t temp_reg , timeout = 0xFFF;
	temp_reg = read_reg(mDMA_SxCR(dma , stream ), 1u);
	write_reg(mDMA_SxCR(dma , stream ) , temp_reg);
	
	//wait for disable
	do{
		timeout --;
	}while(0!= (read_reg(mDMA_SxCR(dma , stream ) , 1u)));
	//1 byte receive
	write_reg(mDMA_SxNDTR(dma , stream) , 1u );
	temp_reg = read_reg(mDMA_SxCR(dma , stream) , ~0U);
	
	temp_reg |= ((dir << 6 ) | (circular << 8) | (pinc  << 9) | (minc << 10 ) |(psize << 11) \
	| (msize << 13)| (pl << 16 ) | (channel << 25 )| (0xFu << 1 ));
	// 0xFu bat co bao loi 
	
	write_reg(mDMA_SxCR(dma , stream) , temp_reg );
	
}
void mDMA_start(u32_t dma , u32_t stream , u32_t adr_mem , u32_t adr_per){
	
	u32_t temp_reg , timeout; 
		//ADRRESS OF peripheral
	write_reg(mDMA_SxPAR(dma , stream) ,  adr_per );
	
	//adress memory
	write_reg(mDMA_SxM0AR(dma , stream) ,adr_mem );
	
	//	ACTIVE DMA
	temp_reg = read_reg(mDMA_SxCR(dma , stream) , ~1U);
	temp_reg |= 1u;
	write_reg(mDMA_SxCR(dma , stream) , temp_reg);
	
	timeout = 0xFFF;
	do{
		timeout --;
	}while(0 == (read_reg(mDMA_SxCR(dma , stream ) , 1u)));
	
}