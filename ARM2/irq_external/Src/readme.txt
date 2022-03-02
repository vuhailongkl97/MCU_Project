0. cau hinh IO 
	input , no_pull
	
1 mask register  để cho phép ngắt ngoài được phép hoạt động và sinh ra interrupt 
	mEXTI_IMR 

2 chon suong , falling/rising  chọn sườn cho ngắt 
	//falling 
	mEXTI_FTSR 
	
3. cau hinh tren syscfg mỗi field 4 bit ngat ngoai tren pa0 

	mSYSCFG_EXTICRx
	
4 . cau hinh nvic 
    setup group priority 
	PRIGROUP 3 bit in  AIRCR register ( SCB_AIRCR [8:10]) 
    set priority >> 111 // chon tat ca 4 bit cho sub priority 
   
    Enable interrupt 
		mNVIC_ISER(x) &=~(1<< pos_vector_irq) ;
 
  note : To write to this register, you must write 0x5FA to the VECTKEY field of SCB_AIRCR, 
  otherwise the processor ignores the write.
 
  pos_vector_irq : xem trong bang vector ngat 
  
5. xu ly ngat 
ten ham ngat xem trong  file startup_stm32f411xe.s
void EXTI0_IRQHandler(void)
{
	// process with event 
	
	// clear pendding
	mEXTI_PR 	: cờ ngắt ngoài  
	mNVIC_ICPR	: cờ ngắt trong core
}
