#include "./Oled/oled.h"
#include "./Dmp/inv_mpu.h"
#include "./Exti/exti.h"
#include "./Contral/contral.h"
#include "./Gpioout/gpioout.h"
#include "./Dmp/inv_mpu.h"
#include "./Mpu6050/mpu6050.h"
#include "./Encoder/encoder.h"
#include "./Motor/motor.h"

/**************************************************************************
函数功能：所有的控制代码都在这里面
         5ms定时中断由MPU6050的INT引脚触发
         严格保证采样和数据处理的时间同步	
				 在MPU6050的采样频率设置中，设置成100HZ，即可保证6050的数据是10ms更新一次。
				 读者可在imv_mpu.h文件第26行的宏定义进行修改(#define DEFAULT_MPU_HZ  (100))
**************************************************************************/
float stand_up_KP = 510;			//小车直立环参数设置最大·为·850   510
float stand_up_KD = -1.2;     //0.12还不错       0.072           -1.2

float velocity_KP = -100;
float velocity_KI = -0.2;

float Mechanical_balance = 0;  

int balance_pwm,velocity_pwm;


void EXTI9_5_IRQHandler(void)
{
	if(PBin(5)  == 0)
	{
		EXTI->PR=1<<5;         								    //清除LINE5上的中断标志位
		mpu_dmp_get_data(&pitch,&roll,&yaw);			//得到欧拉角（姿态角）
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);  //得到陀螺仪的数据
		OLED_Num2(0,7,Encoder_Left);				  //显示右边电机的编码器值
		OLED_Num2(6,7,Encoder_Right);					//显示左边电机的编码器值
		OLED_Float(4,56,pitch,3);
		Encoder_Right = -Read_Encoder(4);
		Encoder_Left =  Read_Encoder(2);
		balance_pwm = stand_up(pitch,Mechanical_balance,gyroy);
		velocity_pwm = velocity(Encoder_Left,Encoder_Right);
		OLED_Num2(12,7,velocity_pwm);	
		Moto1 = balance_pwm - velocity_pwm;
		Moto2 = balance_pwm - velocity_pwm;
			
		Set_Pwm(Moto1,Moto2);
	}
}

/**************************************************************************
函数功能：直立PD控制
入口参数：角度、机械平衡角度（机械中值）、角速度
返回  值：直立控制PWM
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

/**************************************************************************
函数功能：速度PI控制
入口参数：电机编码器的值
返回  值：速度控制PWM
作    者：stubborn
**************************************************************************/
int velocity(int encoder_left,int encoder_right)
{  
    static float Velocity,Encoder_Least,Encoder;
	  static float Encoder_Integral;

		Encoder_Least =(Encoder_Left+Encoder_Right)-0;                    //===获取最新速度偏差==测量速度（左右编码器之和）-目标速度（此处为零） 
		Encoder *= 0.8;		                                                //===一阶低通滤波器       
		Encoder += Encoder_Least*0.2;	                                    //===一阶低通滤波器    
		Encoder_Integral +=Encoder;                                       //===积分出位移 积分时间：10ms
		if(Encoder_Integral>10000)  	Encoder_Integral=10000;             //===积分限幅
		if(Encoder_Integral<-10000)		Encoder_Integral=-10000;            //===积分限幅	
		Velocity=Encoder*velocity_KP+Encoder_Integral*velocity_KI;        //===速度控制	
	  if(pitch<-40||pitch>40) 			Encoder_Integral=0;     						//===电机关闭后清除积分
	  return Velocity;
}

