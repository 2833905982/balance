/**
  ******************************************************************************
  * @file    main.c
  * @author  商俊辉
  * @version V1.0
  * @date    2021-11-24
  * @brief   输出PWM，采用高级定时器1 A8  A11(未测试)
  * 		 		 PWM输入捕获，实现读取编码器的值，获取小车的速度（已测试）
	*          陀螺仪MPU6050,实现获取小车的的状态
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
#include "./Mpu6050/mpu6050.h"
#include "./encoder/encoder.h"
#include "./Gpioout/gpioout.h"
#include "./Usart1/bsp_usart1.h"
#include "./GeneralTim3/GeneralTim3.h"
#include "./Dmp/inv_mpu_dmp_motion_driver.h"

/*******定义全局变量，便于得到数据的输出值*********/
float Voltage;											//电压值变量
float pitch,rool,yaw;								//计算出来的欧拉角（姿态角）
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
	LED_GPIO_Config();	 		/* LED 端口初始化 */
	KEY_Init();          	 	//按键初始化
	uart3_init(9600);     	//初始化串口3
	USART1_Config();				//初始化串口1
	GENERAL_TIM3_Init(); 		//初始化通用定时器3
	ADVANCE_TIM1_Init();  	//初始化高级定时器1
	Encoder_Init_TIM2(); 	 	//初始化编码器1    左轮
	Encoder_Init_TIM4();  	//初始化编码器2    右轮
	MPU_Init();							//初始化MPU6050
	mpu_dmp_init();					//将MPU6050设置为DMP模式
	OLED_Init();						//OLED初始化
	OLED_Clear();						//清屏
	
	while(1)
	{
		OLED_ShowString(0,0,"woyouyigemengxiang",8);
		for(int i = 0; i<= 5 ; i++)
		{
			OLED_ShowCHinese(15*i+16,4,i);
		}
		Delay_ms(50);
		
		OLED_Num2(0,7,Encoder_Left);				  //显示右边电机的编码器值
		OLED_Num2(8,7,Encoder_Right);					//显示左边电机的编码器值
		OLED_Num2(16,7,pitch);
		LED1(1);
		Delay_ms(500);
		LED1(0);
		Delay_ms(500);
	}
}

