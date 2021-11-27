/**
  ******************************************************************************
  * @file    main.c
  * @author  商俊辉
  * @version V1.0
  * @date    2021-11-24
  * @brief   输出PWM，采用高级定时器1 A8  A11(未测试)
  * 		 PWM输入捕获，实现读取编码器的值，获取小车的速度（已测试）
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 
#include "stm32f10x.h"
#include "./Key/key.h"
#include "./PWM/PWM.h" 
#include "./Oled/oled.h"
#include "./Delay/delay.h"
#include "./led/bsp_led.h"
#include "./Usart3/usart3.h"
#include "./encoder/encoder.h"
#include "./Usart1/bsp_usart1.h"
#include "./GeneralTim3/GeneralTim3.h"


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
	GENERAL_TIM3_Init(); 	//初始化通用定时器3
	ADVANCE_TIM1_Init();  //初始化高级定时器1
	Encoder_Init_TIM2();  //初始化编码器1    左轮
	Encoder_Init_TIM4();  //初始化编码器2    右轮
	OLED_Init();					//OLED初始化
	OLED_Clear();					//清屏
	
	while(1)
	{
//		OLED_ShowString(0,0,"woyouyigemengxiang",12);
		OLED_ShowCHinese(0,0,1);
		Delay_ms(50);
		
		OLED_Num2(4,6,Read_Encoder(2));					//显示右边电机的编码器值
		OLED_Num2(14,6,-Read_Encoder(4));					//显示左边电机的编码器值
		LED1(1);
		Delay_ms(500);
		LED1(0);
		Delay_ms(500);
	}
}

