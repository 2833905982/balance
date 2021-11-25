/**
  ******************************************************************************
  * @file    main.c
  * @author  商俊辉
  * @version V1.0
  * @date    2021-11-11
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "./Key/key.h"
#include "./led/bsp_led.h"
#include "./Usart3/usart3.h"
#include "./Usart1/bsp_usart1.h"
#include "./SysTick/bsp_SysTick.h"



/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	LED_GPIO_Config();	 	/* LED 端口初始化 */
	KEY_Init();           //按键初始化
	uart3_init(9600);     //初始化串口3
	USART1_Config();				//初始化串口1

	while (1)
	{
		LED1(0);
	}
}

