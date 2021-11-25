/**
  ******************************************************************************
  * @file    main.c
  * @author  �̿���
  * @version V1.0
  * @date    2021-11-11
  * @brief   ���԰���
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

#include "./Key/key.h"
#include "./SysTick/bsp_SysTick.h"

 
 
/**************************************************************************
�������ܣ�������ʼ��
��ڲ�������
����  ֵ���� 
**************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //ʹ��PC�˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	           //�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         //��������
	GPIO_Init(GPIOC, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOC
} 

u8 Key_Scan(void)
{
	u8 keyval1 = 0;
	if(key1 == 0)						//��������ʱ
	{
		Delay_ms(20);					//��ʱ����
		while(key1 == 0);
		if(key1 == 1)					//����̧��ʱ
		{
			keyval1 = 1; 
		}
	}
	return keyval1;
}

