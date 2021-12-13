#ifndef __CONTRAL_H
#define __CONTRAL_H

#include "stm32f10x.h"

/*******����ȫ�ֱ��������ڵõ����ݵ����ֵ*********/
extern float Voltage;										  	//��ѹֵ����
extern float pitch,roll,yaw;								//���������ŷ���ǣ���̬�ǣ�
extern short aacx,aacy,aacz;								//���ٶȴ�����ԭʼ����
extern short gyrox,gyroy,gyroz;					    //������ԭʼ����
extern int 	Moto1,Moto2;						    //������������ո��������PWM
extern int   Encoder_Left,Encoder_Right;         		 //���ұ��������������


void EXTI9_5_IRQHandler(void);
int stand_up(float Angle,float Mechanical_balance,float Gyro);
int velocity(int encoder_left,int encoder_right);


#endif /** __CONTRAL_H **/

