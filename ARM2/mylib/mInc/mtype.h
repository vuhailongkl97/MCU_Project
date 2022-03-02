
#ifndef __MTYPE_H__
#define __MTYPE_H__

typedef unsigned int u32_t;
typedef unsigned char u8_t;

typedef struct{
	u32_t  mpin;
	u32_t  moder;
	u32_t  type;
	u32_t  pull;
	u32_t  speed;
	u32_t  alternate;
}mGPIO_TypeDef;


#endif
