/**
  ******************************************************************************
  * @file    main.c
  * @author  �̿���
  * @version V1.0
  * @date    2021-11-11
  * @brief   ����led
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
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	LED_GPIO_Config();	 	/* LED �˿ڳ�ʼ�� */
	KEY_Init();           //������ʼ��
	uart3_init(9600);     //��ʼ������3
	USART1_Config();				//��ʼ������1

	while (1)
	{
		LED1(0);
	}
}

