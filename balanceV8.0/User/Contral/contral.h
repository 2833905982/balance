#ifndef __CONTRAL_H
#define __CONTRAL_H

#include "stm32f10x.h"

/*******定义全局变量，便于得到数据的输出值*********/
extern float Voltage;										  	//电压值变量
extern float pitch,roll,yaw;								//计算出来的欧拉角（姿态角）
extern short aacx,aacy,aacz;								//加速度传感器原始数据
extern short gyrox,gyroy,gyroz;					    //陀螺仪原始数据
extern int 	Moto1,Moto2;						    //计算出来的最终赋给电机的PWM
extern int   Encoder_Left,Encoder_Right;         		 //左右编码器的脉冲计数


void EXTI9_5_IRQHandler(void);
int stand_up(float Angle,float Mechanical_balance,float Gyro);
int velocity(int encoder_left,int encoder_right);


#endif /** __CONTRAL_H **/

