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
�������ܣ����еĿ��ƴ��붼��������
         5ms��ʱ�ж���MPU6050��INT���Ŵ���
         �ϸ�֤���������ݴ����ʱ��ͬ��	
				 ��MPU6050�Ĳ���Ƶ�������У����ó�100HZ�����ɱ�֤6050��������10ms����һ�Ρ�
				 ���߿���imv_mpu.h�ļ���26�еĺ궨������޸�(#define DEFAULT_MPU_HZ  (100))
**************************************************************************/
float stand_up_KP = 510;			//С��ֱ���������������Ϊ��850   510
float stand_up_KD = -1.2;     //0.12������       0.072           -1.2

float velocity_KP = -100;
float velocity_KI = -0.2;

float Mechanical_balance = 0;  

int balance_pwm,velocity_pwm;


void EXTI9_5_IRQHandler(void)
{
	if(PBin(5)  == 0)
	{
		EXTI->PR=1<<5;         								    //���LINE5�ϵ��жϱ�־λ
		mpu_dmp_get_data(&pitch,&roll,&yaw);			//�õ�ŷ���ǣ���̬�ǣ�
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);  //�õ������ǵ�����
		OLED_Num2(0,7,Encoder_Left);				  //��ʾ�ұߵ���ı�����ֵ
		OLED_Num2(6,7,Encoder_Right);					//��ʾ��ߵ���ı�����ֵ
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
�������ܣ�ֱ��PD����
��ڲ������Ƕȡ���еƽ��Ƕȣ���е��ֵ�������ٶ�
����  ֵ��ֱ������PWM
��    �ߣ�stubborn
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
�������ܣ��ٶ�PI����
��ڲ����������������ֵ
����  ֵ���ٶȿ���PWM
��    �ߣ�stubborn
**************************************************************************/
int velocity(int encoder_left,int encoder_right)
{  
    static float Velocity,Encoder_Least,Encoder;
	  static float Encoder_Integral;

		Encoder_Least =(Encoder_Left+Encoder_Right)-0;                    //===��ȡ�����ٶ�ƫ��==�����ٶȣ����ұ�����֮�ͣ�-Ŀ���ٶȣ��˴�Ϊ�㣩 
		Encoder *= 0.8;		                                                //===һ�׵�ͨ�˲���       
		Encoder += Encoder_Least*0.2;	                                    //===һ�׵�ͨ�˲���    
		Encoder_Integral +=Encoder;                                       //===���ֳ�λ�� ����ʱ�䣺10ms
		if(Encoder_Integral>10000)  	Encoder_Integral=10000;             //===�����޷�
		if(Encoder_Integral<-10000)		Encoder_Integral=-10000;            //===�����޷�	
		Velocity=Encoder*velocity_KP+Encoder_Integral*velocity_KI;        //===�ٶȿ���	
	  if(pitch<-40||pitch>40) 			Encoder_Integral=0;     						//===����رպ��������
	  return Velocity;
}

