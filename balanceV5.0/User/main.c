/**
  ******************************************************************************
  * @file    main.c
  * @author  商俊辉
  * @version V1.0
  * @date    2021-12-06
  * @brief   输出PWM，采用高级定时器1 A8  A11(未测试)
  * 		 		 PWM输入捕获，实现读取编码器的值，获取小车的速度（已测试）
	*          陀螺仪MPU6050,实现获取小车的的状态(已测试)
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

#include "./stm32f10x.h"
#include "./Key/key.h"
#include "./PWM/PWM.h" 
#include "./Oled/oled.h"
#include "./Exti/exti.h"
#include "./Delay/delay.h"
#include "./Usart3/usart3.h"
#include "./Dmp/inv_mpu.h"
#include "./Mpuiic/mpuiic.h"
#include "./Contral/contral.h"
#include "./Mpu6050/mpu6050.h"
#include "./Encoder/encoder.h"
#include "./Gpioout/gpioout.h"
#include "./Usart1/bsp_usart1.h"
#include "./GeneralTim3/GeneralTim3.h"
#include "./Dmp/inv_mpu_dmp_motion_driver.h"
#include <string.h> 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*******定义全局变量，便于得到数据的输出值*********/
float Voltage;											//电压值变量
float pitch,roll,yaw;								//计算出来的欧拉角（姿态角）
short aacx,aacy,aacz;								//加速度传感器原始数据
short gyrox,gyroy,gyroz;						//陀螺仪原始数据

/*******************************/


/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	LED_GPIO_Config();	 		/* LED 端口初始化 */
	KEY_Init();          	 	//按键初始化
	uart3_init(9600);     	//初始化串口3
	USART1_Config();				//初始化串口1
	GENERAL_TIM3_Init(); 		//初始化通用定时器3
	ADVANCE_TIM1_Init();  	//初始化高级定时器1
	Encoder_Init_TIM2(); 	 	//初始化编码器1    左轮
	Encoder_Init_TIM4();  	//初始化编码器2    右轮
	NVIC_Configuration();   //初始化NVIC向量组
	OLED_Init();						//OLED初始化
	OLED_Clear();						//清屏
	MPU_Init();							//初始化MPU6050
	mpu_dmp_init();					//将MPU6050设置为DMP模式
	MPU6050_EXTI_Init();		//初始化MPU6050中断，每10毫秒触发一次
	
	while(1)
	{
		LED1(1);
		Delay_ms(500);
		LED1(0);
		Delay_ms(500);
	}
}
//		OLED_Num2(0,7,Encoder_Left);				  //显示右边电机的编码器值
//		OLED_Num2(8,7,Encoder_Right);					//显示左边电机的编码器值
//		OLED_Num2(16,7,pitch);

//		OLED_Float(10,70,pitch,3);

//		OLED_ShowString(0,0,"woyouyigemengxiang",8);
//		for(int i = 0; i<= 5 ; i++)
//		{
//			OLED_ShowCHinese(15*i+16,4,i);
//		}
//		Delay_ms(50);
//		OLED_Num2(6,7,A);		
//		OLED_Num2(10,7,B);		
//		OLED_Num2(16,7,C);
//		OLED_Num2(0,7,D);		
//		MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
//		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);  //得到陀螺仪的数据
//		mpu_dmp_get_data(&pitch,&roll,&yaw);			//得到欧拉角（姿态角）
//		if(yaw<0)		
//		{
//			OLED_ShowString(48,4,"-",12); 
//			OLED_Float(4,56,-yaw,3);
//		}	
//		else	
//		{
//			OLED_ShowString(48,4,"+",12); 
//			OLED_Float(4,56,yaw,3);			
//		}

//		OLED_Num2(0,7,E);
//		printf("E=%d\r\n",E);
//		printf("aacx=%d\r\n",aacx);

