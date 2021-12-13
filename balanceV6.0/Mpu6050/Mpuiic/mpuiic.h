#ifndef __MPUIIC_H
#define __MPUIIC_H


#include "stm32f10x.h"


//IO方向设置
#define MPU_SDA_IN()   {GPIOB->CRL&=0XFFFF0FFF;GPIOB->CRL|=8<<12;}
#define MPU_SDA_OUT()  {GPIOB->CRL&=0XFFFF0FFF;GPIOB->CRL|=3<<12;}


//#define SDA_IN()  {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=8<<4;}
//#define SDA_OUT() {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=3<<4;}

//IO操作函数	 
#define MPU_IIC_SCL     PBout(4) //SCL
#define MPU_IIC_SDA     PBout(3) //SDA	
#define MPU_READ_SDA   	PBin(3) //SDA	

//#define IIC_SCL    PBout(8) //SCL
//#define IIC_SDA    PBout(9) //SDA	 
//#define READ_SDA   PBin(9)  //输入SDA 

/*******定义全局变量，便于得到数据的输出值*********/
extern float Voltage;											//电压值变量
extern float pitch,roll,yaw;								//计算出来的欧拉角（姿态角）
extern short aacx,aacy,aacz;								//加速度传感器原始数据
extern short gyrox,gyroy,gyroz;						//陀螺仪原始数据


//IIC所有操作函数
void MPU_IIC_Delay(void);				//MPU IIC延时函数
void MPU_IIC_Init(void);                //初始化IIC的IO口				 
void MPU_IIC_Start(void);				//发送IIC开始信号
void MPU_IIC_Stop(void);	  			//发送IIC停止信号
void MPU_IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 MPU_IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 MPU_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void MPU_IIC_Ack(void);					//IIC发送ACK信号
void MPU_IIC_NAck(void);				//IIC不发送ACK信号

void IMPU_IC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 MPU_IIC_Read_One_Byte(u8 daddr,u8 addr);	  


#endif /**__MPUIIC_H  **/

