#ifndef __ADVANCETIME1_H
#define __ADVANCETIME1_H


#include "stm32f10x.h"


/************高级定时器TIM参数定义，只限TIM1和TIM8************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 这里我们使用高级控制定时器TIM1

#define            ADVANCE_TIM1                   TIM1
#define            ADVANCE_TIM1_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM1_CLK               RCC_APB2Periph_TIM1
// PWM 信号的频率 F = TIM_CLK/{(ARR+1)*(PSC+1)}
#define            ADVANCE_TIM1_PERIOD            7199
#define            ADVANCE_TIM1_PSC               0
#define            ADVANCE_TIM1_PULSE             0

#define            ADVANCE_TIM1_IRQ               TIM1_UP_IRQn
#define            ADVANCE_TIM1_IRQHandler        TIM1_UP_IRQHandler

// TIM1 输出比较通道
#define            ADVANCE_TIM1_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM1_CH1_PORT          GPIOA
#define            ADVANCE_TIM1_CH1_PIN           GPIO_Pin_8

// TIM1 输出比较通道的互补通道
#define            ADVANCE_TIM1_CH1N_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            ADVANCE_TIM1_CH1N_PORT          GPIOB
#define            ADVANCE_TIM1_CH1N_PIN           GPIO_Pin_13

// TIM1 输出比较通道的刹车通道
#define            ADVANCE_TIM1_BKIN_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            ADVANCE_TIM1_BKIN_PORT          GPIOB
#define            ADVANCE_TIM1_BKIN_PIN           GPIO_Pin_12

/**************************函数声明********************************/

void ADVANCE_TIM1_Init(void);


#endif	/* __BSP_ADVANCETIME_H */


