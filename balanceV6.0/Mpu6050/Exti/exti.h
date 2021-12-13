#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"

//Ex_NVIC_Config专用定义
#define GPIO_A 0
#define GPIO_B 1
#define GPIO_C 2
#define GPIO_D 3
#define GPIO_E 4
#define GPIO_F 5
#define GPIO_G 6 


#define INT PBin(5)               //PB5连接到MPU6050的中断引脚
void MPU6050_EXTI_Init(void);     //外部中断初始化		 
void NVIC_Configuration(void);		//初始化NVIC向量组


#endif  /** __EXTI_H **/
