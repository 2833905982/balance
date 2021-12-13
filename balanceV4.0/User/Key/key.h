#ifndef __KEY_H
#define __KEY_H	 

#include "stm32f10x.h"


 /**************************************************************************
  * @file    Key.h
  * @author  �̿���
  * @version V1.0
  * @date    2021-11-11
  * @brief   ���԰���
 
**************************************************************************/

#define KEY PCin(15)
#define key1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)

void KEY_Init(void);          //������ʼ��
u8 KEY_Scan(void);          //����ɨ��


#endif  /* __KEY_H */


