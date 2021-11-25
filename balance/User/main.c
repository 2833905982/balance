/**
  ******************************************************************************
  * @file    main.c
  * @author  �̿���
  * @version V1.0
  * @date    2021-11-11
  * @brief   �����ʱ�������⣬ʵ��GPIO�����������ʱ��OLED��ʾ
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
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	LED_GPIO_Config();	 	/* LED �˿ڳ�ʼ�� */
	KEY_Init();           //������ʼ��
	uart3_init(9600);     //��ʼ������3
	USART1_Config();			//��ʼ������1
	OLED_Init();					//OLED��ʼ��
	OLED_Clear();					//����
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

