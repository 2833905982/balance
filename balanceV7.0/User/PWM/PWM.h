#ifndef __PWM_H
#define __PWM_H


#include "stm32f10x.h"
#include "stm32f10x_tim.h"

/************�߼���ʱ��TIM�������壬ֻ��TIM1��TIM8************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������ʹ�ø߼����ƶ�ʱ��TIM1

#define            ADVANCE_TIM1                   TIM1
#define            ADVANCE_TIM1_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM1_CLK               RCC_APB2Periph_TIM1
// PWM �źŵ�Ƶ�� F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define            ADVANCE_TIM1_PERIOD            7199
#define            ADVANCE_TIM1_PSC               0
#define            ADVANCE_TIM1_PULSE             4

#define            ADVANCE_TIM1_IRQ               TIM1_UP_IRQn
#define            ADVANCE_TIM1_IRQHandler        TIM1_UP_IRQHandler

// TIM1 ����Ƚ�ͨ��
#define            ADVANCE_TIM1_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM1_CH1_PORT          GPIOA
#define            ADVANCE_TIM1_CH1_PIN           GPIO_Pin_8

// TIM1 ����Ƚ�ͨ��
#define            ADVANCE_TIM1_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM1_CH4_PORT          GPIOA
#define            ADVANCE_TIM1_CH4_PIN           GPIO_Pin_11



/**************************��������********************************/

void ADVANCE_TIM1_Init(void);


#endif	/* __PWM_H */


