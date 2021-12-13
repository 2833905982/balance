#ifndef __GENERALTIME3_H
#define __GENERALTIME3_H


#include "stm32f10x.h"


/* Time base configuration */		 
/* PWM信号电平跳变值 */
//((1+TIM_Prescaler )/72M)*(1+TIM_Period )=((1+71)/72M)*(1+19999)=20000us	
//u16 CCR4_Val =499;500us,0度 
//u16 CCR4_Val =999;1000us,45度 
//u16 CCR4_Val =1499;1500us,90度
//u16 CCR4_Val =1999;2000us,135度 
//u16 CCR4_Val =2499;2500us,180度 

/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

#define            GENERAL_TIM3                   TIM3
#define            GENERAL_TIM3_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM3_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM3_Period            20000-1
#define            GENERAL_TIM3_Prescaler         71              /*  计算 PWM   波的公式 72M/( 10*72 )=100KHZ ， 占 空 比 为 GENERAL_TIM_CCR1/（GENERAL_TIM_PERIOD+1） = 50%。*/
// TIM3 输出比较通道1
#define            GENERAL_TIM3_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH1_PORT          GPIOA
#define            GENERAL_TIM3_CH1_PIN           GPIO_Pin_6

// TIM3 输出比较通道2
#define            GENERAL_TIM3_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH2_PORT          GPIOA
#define            GENERAL_TIM3_CH2_PIN           GPIO_Pin_7

// TIM3 输出比较通道3
#define            GENERAL_TIM3_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH3_PORT          GPIOB
#define            GENERAL_TIM3_CH3_PIN           GPIO_Pin_0

// TIM3 输出比较通道4
#define            GENERAL_TIM3_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH4_PORT          GPIOB
#define            GENERAL_TIM3_CH4_PIN           GPIO_Pin_1

/**************************函数声明********************************/

void GENERAL_TIM3_Mode_Config(void);
void GENERAL_TIM3_GPIO_Config(void);
void GENERAL_TIM3_Init(void);

#endif	/* __BSP_GENERALTIME3_H */


