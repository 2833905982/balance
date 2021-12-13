#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f10x.h"

//Ex_NVIC_Configר�ö���
#define GPIO_A 0
#define GPIO_B 1
#define GPIO_C 2
#define GPIO_D 3
#define GPIO_E 4
#define GPIO_F 5
#define GPIO_G 6 


#define INT PBin(5)               //PB5���ӵ�MPU6050���ж�����
void MPU6050_EXTI_Init(void);     //�ⲿ�жϳ�ʼ��		 
void NVIC_Configuration(void);		//��ʼ��NVIC������


#endif  /** __EXTI_H **/
