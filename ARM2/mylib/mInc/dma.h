#ifndef __DMA_H__
#define __DMA_H__


void config_dma(u32_t dma , u32_t stream ,u32_t channel , u32_t dir , u32_t circular  , u32_t pinc \
          , u32_t minc , u32_t psize , u32_t msize , u32_t priority   );
void mDMA_start(u32_t dma , u32_t stream , u32_t adr_mem , u32_t adr_per);


#endif
