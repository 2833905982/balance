/***********************************************************************************

***********************************************************************************/  
#ifndef _DELAY_H_
#define _DELAY_H_

#include "stm32f10x.h"

//#define Delay_ms(x) Delay_us(x*1000)

void Delay_us(uint32_t time);
void Delay_ms(uint32_t time);

#endif /***_DELAY_H_**/

