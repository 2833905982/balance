#ifndef __CONTRAL_H
#define __CONTRAL_H

#include "stm32f10x.h"

/*******����ȫ�ֱ��������ڵõ����ݵ����ֵ*********/
extern float Voltage;											//��ѹֵ����
extern float pitch,roll,yaw;								//���������ŷ���ǣ���̬�ǣ�
extern short aacx,aacy,aacz;								//���ٶȴ�����ԭʼ����
extern short gyrox,gyroy,gyroz;						//������ԭʼ����


void EXTI9_5_IRQHandler(void);

#endif /** __CONTRAL_H **/

