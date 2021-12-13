#include "./Oled/oled.h"
#include "./Dmp/inv_mpu.h"
#include "./Exti/exti.h"
#include "./Contral/contral.h"
#include "./Gpioout/gpioout.h"
#include "./Dmp/inv_mpu.h"
#include "./Mpu6050/mpu6050.h"
#include "./Encoder/encoder.h"

/**************************************************************************
�������ܣ����еĿ��ƴ��붼��������
         5ms��ʱ�ж���MPU6050��INT���Ŵ���
         �ϸ�֤���������ݴ����ʱ��ͬ��	
				 ��MPU6050�Ĳ���Ƶ�������У����ó�100HZ�����ɱ�֤6050��������10ms����һ�Ρ�
				 ���߿���imv_mpu.h�ļ���26�еĺ궨������޸�(#define DEFAULT_MPU_HZ  (100))
**************************************************************************/
float stand_up_KP = 300;			//С��ֱ������������
float stand_up_KD = 1.9;


void EXTI9_5_IRQHandler(void)
{
	if(PBin(5)    == 0)
	{
		EXTI->PR=1<<5;         								    //���LINE5�ϵ��жϱ�־λ
		mpu_dmp_get_data(&pitch,&roll,&yaw);			//�õ�ŷ���ǣ���̬�ǣ�
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);  //�õ������ǵ�����
//		OLED_Num2(0,7,Encoder_Left);				  //��ʾ�ұߵ���ı�����ֵ
//		OLED_Num2(8,7,Encoder_Right);					//��ʾ��ߵ���ı�����ֵ
		OLED_Float(4,56,pitch,3);
	}
}

/**************************************************************************
�������ܣ��ٶ�PI����
��ڲ����������������ֵ
����  ֵ���ٶȿ���PWM
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



