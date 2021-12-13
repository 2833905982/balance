#ifndef __MOTOR_H
#define __MOTOR_H


#include "stm32f10x.h"


#define PWMA   TIM1->CCR1  //PA8


#define AIN2(n)   PBout(15) = n
#define AIN1(n)   PBout(14) = n
#define BIN1(n)   PBout(13) = n
#define BIN2(n)   PBout(12) = n

#define PWMB   TIM1->CCR4  //PA11
 
void Motor_Init(void);
void Set_Pwm(int moto1,int moto2);
int myabs(int a);
	

#endif /** __MOTOR_H **/


