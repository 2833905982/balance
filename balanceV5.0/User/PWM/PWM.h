#ifndef __ADVANCETIME1_H
#define __ADVANCETIME1_H


#include "stm32f10x.h"


/************�߼���ʱ��TIM�������壬ֻ��TIM1��TIM8************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������ʹ�ø߼����ƶ�ʱ��TIM1

#define            ADVANCE_TIM1                   TIM1
#define            ADVANCE_TIM1_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM1_CLK               RCC_APB2Periph_TIM1
// PWM �źŵ�Ƶ�� F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define            ADVANCE_TIM1_PERIOD            7199
#define            ADVANCE_TIM1_PSC               0
#define            ADVANCE_TIM1_PULSE             0

#define            ADVANCE_TIM1_IRQ               TIM1_UP_IRQn
#define            ADVANCE_TIM1_IRQHandler        TIM1_UP_IRQHandler

// TIM1 ����Ƚ�ͨ��
#define            ADVANCE_TIM1_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM1_CH1_PORT          GPIOA
#define            ADVANCE_TIM1_CH1_PIN           GPIO_Pin_8

// TIM1 ����Ƚ�ͨ���Ļ���ͨ��
#define            ADVANCE_TIM1_CH1N_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            ADVANCE_TIM1_CH1N_PORT          GPIOB
#define            ADVANCE_TIM1_CH1N_PIN           GPIO_Pin_13

// TIM1 ����Ƚ�ͨ����ɲ��ͨ��
#define            ADVANCE_TIM1_BKIN_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            ADVANCE_TIM1_BKIN_PORT          GPIOB
#define            ADVANCE_TIM1_BKIN_PIN           GPIO_Pin_12

/**************************��������********************************/

void ADVANCE_TIM1_Init(void);


#endif	/* __BSP_ADVANCETIME_H */


