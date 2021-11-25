/**
  ******************************************************************************
  * @file    main.c
  * @author  商俊辉
  * @version V1.0
  * @date    2021-11-11
  * @brief   解决延时函数问题，实现GPIO输入输出，延时，OLED显示
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 
#include "stm32f10x.h"
#include "./Key/key.h"
#include "./Oled/bmp.h"
#include "./Oled/oled.h"
#include "./Delay/delay.h"
#include "./led/bsp_led.h"
#include "./Usart3/usart3.h"
#include "./Usart1/bsp_usart1.h"


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
	USART1_Config();			//初始化串口1
	OLED_Init();					//OLED初始化
	OLED_Clear();					//清屏
	while(1)
	{
//		OLED_ShowString(0,0,"woyouyigemengxiang",12);
		OLED_ShowCHinese(0,0,1);
		OLED_DrawBMP(0,0,128,64,bmp);
		Delay_ms(50);
		
		LED1(1);
		Delay_ms(500);
		LED1(0);
		Delay_ms(500);
	}
}

