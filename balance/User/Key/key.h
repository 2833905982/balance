#ifndef __KEY_H
#define __KEY_H	 

#include "stm32f10x.h"


 /**************************************************************************
  * @file    Key.h
  * @author  商俊辉
  * @version V1.0
  * @date    2021-11-11
  * @brief   测试按键
 
**************************************************************************/

#define KEY PCin(15)
#define key1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)

void KEY_Init(void);          //按键初始化
u8 KEY_Scan(void);          //按键扫描


#endif  /* __KEY_H */


