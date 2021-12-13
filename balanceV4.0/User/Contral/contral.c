#include "./Oled/oled.h"
#include "./Dmp/inv_mpu.h"
#include "./Exti/exti.h"
#include "./Contral/contral.h"
#include "./Gpioout/gpioout.h"
#include "./Dmp/inv_mpu.h"
#include "./Mpu6050/mpu6050.h"
#include "./Encoder/encoder.h"

/**************************************************************************
函数功能：所有的控制代码都在这里面
         5ms定时中断由MPU6050的INT引脚触发
         严格保证采样和数据处理的时间同步	
				 在MPU6050的采样频率设置中，设置成100HZ，即可保证6050的数据是10ms更新一次。
				 读者可在imv_mpu.h文件第26行的宏定义进行修改(#define DEFAULT_MPU_HZ  (100))
**************************************************************************/
float stand_up_KP = 300;			//小车直立环参数设置
float stand_up_KD = 1.9;


void EXTI9_5_IRQHandler(void)
{
	if(PBin(5)    == 0)
	{
		EXTI->PR=1<<5;         								    //清除LINE5上的中断标志位
		mpu_dmp_get_data(&pitch,&roll,&yaw);			//得到欧拉角（姿态角）
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);  //得到陀螺仪的数据
//		OLED_Num2(0,7,Encoder_Left);				  //显示右边电机的编码器值
//		OLED_Num2(8,7,Encoder_Right);					//显示左边电机的编码器值
		OLED_Float(4,56,pitch,3);
	}
}

/**************************************************************************
函数功能：速度PI控制
入口参数：电机编码器的值
返回  值：速度控制PWM
作    者：stubborn
**************************************************************************/
int stand_up(float Angle,float Mechanical_balance,float Gyro)
{
	float bias;
	int balance;
  bias = Angle - Mechanical_balance;
	balance = stand_up_KP * bias + stand_up_KD * Gyro;
	return balance;
}



