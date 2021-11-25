/**
  ******************************************************************************
  * @file    main.c
  * @author  商俊辉
  * @version V1.0
  * @date    2021-11-11
  * @brief   测试按键
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

#include "./Key/key.h"
#include "./SysTick/bsp_SysTick.h"

 
 
/**************************************************************************
函数功能：按键初始化
入口参数：无
返回  值：无 
**************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //使能PC端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	           //端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //上拉输入
	GPIO_Init(GPIOC, &GPIO_InitStructure);					      //根据设定参数初始化GPIOC
} 

u8 Key_Scan(void)
{
	u8 keyval1 = 0;
	if(key1 == 0)						//按键按下时
	{
		Delay_ms(20);					//延时消抖
		while(key1 == 0);
		if(key1 == 1)					//按键抬起时
		{
			keyval1 = 1; 
		}
	}
	return keyval1;
}

