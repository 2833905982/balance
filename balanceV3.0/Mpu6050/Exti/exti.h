#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"



#define INT PBin(5)               //PB5连接到MPU6050的中断引脚
void MPU6050_EXTI_Init(void);     //外部中断初始化		 



#endif  /** __EXTI_H **/
