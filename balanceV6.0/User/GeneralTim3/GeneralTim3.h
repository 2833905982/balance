#ifndef __GENERALTIME3_H
#define __GENERALTIME3_H


#include "stm32f10x.h"


/* Time base configuration */		 
/* PWM�źŵ�ƽ����ֵ */
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+71)/72M)*(1+19999)=20000us	
//u16 CCR4_Val =499;500us,0�� 
//u16 CCR4_Val =999;1000us,45�� 
//u16 CCR4_Val =1499;1500us,90��
//u16 CCR4_Val =1999;2000us,135�� 
//u16 CCR4_Val =2499;2500us,180�� 

/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM3

#define            GENERAL_TIM3                   TIM3
#define            GENERAL_TIM3_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM3_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM3_Period            20000-1
#define            GENERAL_TIM3_Prescaler         71              /*  ���� PWM   ���Ĺ�ʽ 72M/( 10*72 )=100KHZ �� ռ �� �� Ϊ GENERAL_TIM_CCR1/��GENERAL_TIM_PERIOD+1�� = 50%��*/
// TIM3 ����Ƚ�ͨ��1
#define            GENERAL_TIM3_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH1_PORT          GPIOA
#define            GENERAL_TIM3_CH1_PIN           GPIO_Pin_6

// TIM3 ����Ƚ�ͨ��2
#define            GENERAL_TIM3_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH2_PORT          GPIOA
#define            GENERAL_TIM3_CH2_PIN           GPIO_Pin_7

// TIM3 ����Ƚ�ͨ��3
#define            GENERAL_TIM3_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH3_PORT          GPIOB
#define            GENERAL_TIM3_CH3_PIN           GPIO_Pin_0

// TIM3 ����Ƚ�ͨ��4
#define            GENERAL_TIM3_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH4_PORT          GPIOB
#define            GENERAL_TIM3_CH4_PIN           GPIO_Pin_1

/**************************��������********************************/

void GENERAL_TIM3_Mode_Config(void);
void GENERAL_TIM3_GPIO_Config(void);
void GENERAL_TIM3_Init(void);

#endif	/* __BSP_GENERALTIME3_H */


