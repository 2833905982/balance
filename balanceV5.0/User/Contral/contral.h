#ifndef __CONTRAL_H
#define __CONTRAL_H

#include "stm32f10x.h"

/*******定义全局变量，便于得到数据的输出值*********/
extern float Voltage;											//电压值变量
extern float pitch,roll,yaw;								//计算出来的欧拉角（姿态角）
extern short aacx,aacy,aacz;								//加速度传感器原始数据
extern short gyrox,gyroy,gyroz;						//陀螺仪原始数据


void EXTI9_5_IRQHandler(void);

#endif /** __CONTRAL_H **/

