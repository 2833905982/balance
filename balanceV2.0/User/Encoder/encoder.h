#ifndef __ENCODER_H
#define __ENCODER_H


#include "stm32f10x.h"

/* Time base configuration */		 
/* PWM信号电平跳变值 */
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+71)/72M)*(1+19999)=20000us	
//u16 CCR4_Val =499;500us,0度 
//u16 CCR4_Val =999;1000us,45度 
//u16 CCR4_Val =1499;1500us,90度
//u16 CCR4_Val =1999;2000us,135度 
//u16 CCR4_Val =2499;2500us,180度 
/**********
定时器中断时间的计算

STM32F103ZET6的TIM3时钟是72M，预分频为7199，定时器自动重装载值为4999，经过预分频后，时钟频率为72000000/(7199+1) = 10K，定时器从0计数到4999，一共5000个数，即500ms。

arr：定时器自动重装载值

psc：预分频系数

clk：时钟频率  72000000

Tout:定时器溢出时间（中断时间）

Tout = (arr+1)*(psc+1)/clk
***********/


#define ENCODER_TIM_PERIOD (u16)(65535)   //103的定时器是16位 2的16次方最大是65536
void Encoder_Init_TIM2(void);
void Encoder_Init_TIM4(void);
int Read_Encoder(u8 TIMX);
void TIM4_IRQHandler(void);
void TIM2_IRQHandler(void);

#endif	/* __ENCODER_H */


