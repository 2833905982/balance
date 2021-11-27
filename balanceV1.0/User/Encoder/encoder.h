#ifndef __ENCODER_H
#define __ENCODER_H


#include "stm32f10x.h"

/* Time base configuration */		 
/* PWM�źŵ�ƽ����ֵ */
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+71)/72M)*(1+19999)=20000us	
//u16 CCR4_Val =499;500us,0�� 
//u16 CCR4_Val =999;1000us,45�� 
//u16 CCR4_Val =1499;1500us,90��
//u16 CCR4_Val =1999;2000us,135�� 
//u16 CCR4_Val =2499;2500us,180�� 
/**********
��ʱ���ж�ʱ��ļ���

STM32F103ZET6��TIM3ʱ����72M��Ԥ��ƵΪ7199����ʱ���Զ���װ��ֵΪ4999������Ԥ��Ƶ��ʱ��Ƶ��Ϊ72000000/(7199+1) = 10K����ʱ����0������4999��һ��5000��������500ms��

arr����ʱ���Զ���װ��ֵ

psc��Ԥ��Ƶϵ��

clk��ʱ��Ƶ��  72000000

Tout:��ʱ�����ʱ�䣨�ж�ʱ�䣩

Tout = (arr+1)*(psc+1)/clk
***********/


#define ENCODER_TIM_PERIOD (u16)(65535)   //103�Ķ�ʱ����16λ 2��16�η������65536
void Encoder_Init_TIM2(void);
void Encoder_Init_TIM4(void);
int Read_Encoder(u8 TIMX);
void TIM4_IRQHandler(void);
void TIM2_IRQHandler(void);

#endif	/* __ENCODER_H */


