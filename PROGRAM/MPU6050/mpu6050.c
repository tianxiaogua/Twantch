#include "mpu6050.h"
#include "i2c.h"
#include "usart.h"
#include "stdio.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//MPU6050 驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/9
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

//初始化MPU6050
//返回值:0,成功
//    其他,错误代码
u8 MPU_Init(void)
{
	u8 res;

	MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X80);	//复位MPU6050
  HAL_Delay(100);

	MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X00);	//唤醒MPU6050

	MPU_Set_Gyro_Fsr(3);					//陀螺仪传感器,±2000dps

	MPU_Set_Accel_Fsr(0);					//加速度传感器,±2g

	MPU_Set_Rate(50);						//设置采样率50Hz

	MPU_Write_Byte(MPU_INT_EN_REG,0X00);	//关闭所有中断

	MPU_Write_Byte(MPU_USER_CTRL_REG,0X00);	//I2C主模式关闭

	MPU_Write_Byte(MPU_FIFO_EN_REG,0X00);	//关闭FIFO

	MPU_Write_Byte(MPU_INTBP_CFG_REG,0X80);	//INT引脚低电平有效

	res=MPU_Read_Byte(MPU_DEVICE_ID_REG);

	if(res==MPU_ADDR)//器件ID正确
	{
		MPU_Write_Byte(MPU_PWR_MGMT1_REG,0X01);	//设置CLKSEL,PLL X轴为参考
		MPU_Write_Byte(MPU_PWR_MGMT2_REG,0X00);	//加速度与陀螺仪都工作
		MPU_Set_Rate(50);						//设置采样率为50Hz
 	}
	else
		return 1;

	return 0;
}



//设置MPU6050陀螺仪传感器满量程范围
//fsr:0,±250dps;1,±500dps;2,±1000dps;3,±2000dps
//返回值:0,设置成功
//    其他,设置失败
u8 MPU_Set_Gyro_Fsr(u8 fsr)
{
	return MPU_Write_Byte(MPU_GYRO_CFG_REG,fsr<<3);//设置陀螺仪满量程范围
}



//设置MPU6050加速度传感器满量程范围
//fsr:0,±2g;1,±4g;2,±8g;3,±16g
//返回值:0,设置成功
//    其他,设置失败
u8 MPU_Set_Accel_Fsr(u8 fsr)
{
	return MPU_Write_Byte(MPU_ACCEL_CFG_REG,fsr<<3);//设置加速度传感器满量程范围
}



//设置MPU6050的数字低通滤波器
//lpf:数字低通滤波频率(Hz)
//返回值:0,设置成功
//    其他,设置失败
u8 MPU_Set_LPF(u16 lpf)
{
	u8 data=0;
	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6;
	return MPU_Write_Byte(MPU_CFG_REG,data);//设置数字低通滤波器
}



//设置MPU6050的采样率(假定Fs=1KHz)
//rate:4~1000(Hz)
//返回值:0,设置成功
//    其他,设置失败
u8 MPU_Set_Rate(u16 rate)
{
	u8 data;
	if(rate>1000)rate=1000;
	if(rate<4)rate=4;
	data=1000/rate-1;
	data=MPU_Write_Byte(MPU_SAMPLE_RATE_REG,data);	//设置数字低通滤波器
 	return MPU_Set_LPF(rate/2);	//自动设置LPF为采样率的一半
}


//得到温度值
//返回值:温度值(扩大了100倍)
short MPU_Get_Temperature(void)
{
    u8 buf[2];
    short raw;
	float temp;
	MPU_Read_Len(MPU_ADDR,MPU_TEMP_OUTH_REG,2,buf);
    raw=((u16)buf[0]<<8)|buf[1];
    temp=36.53+((double)raw)/340;
    return temp*100;;
}



//得到陀螺仪值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码
u8 MPU_Get_Gyroscope(short *gx,short *gy,short *gz)
{
    u8 buf[6],res;
	res=MPU_Read_Len(MPU_ADDR,MPU_GYRO_XOUTH_REG,6,buf);
	if(res==0)
	{
		*gx=((u16)buf[0]<<8)|buf[1];
		*gy=((u16)buf[2]<<8)|buf[3];
		*gz=((u16)buf[4]<<8)|buf[5];
	}
    return res;;
}



//得到加速度值(原始值)
//gx,gy,gz:陀螺仪x,y,z轴的原始读数(带符号)
//返回值:0,成功
//    其他,错误代码dmp_read_fifo
u8 MPU_Get_Accelerometer(short *ax,short *ay,short *az)
{
    u8 buf[6],res;
	res=MPU_Read_Len(MPU_ADDR,MPU_ACCEL_XOUTH_REG,6,buf);
	if(res==0)
	{
		*ax=((u16)buf[0]<<8)|buf[1];
		*ay=((u16)buf[2]<<8)|buf[3];
		*az=((u16)buf[4]<<8)|buf[5];
	}
    return res;;
}



//IIC连续写
//addr:器件地址
//reg:寄存器地址
//len:写入长度
//buf:数据区
//返回值:0,正常
//    其他,错误代码
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{

	HAL_I2C_Mem_Write(&hi2c1, ((addr<<1)|0), reg, 1, (unsigned char *)buf, len, HAL_MAX_DELAY);
	return 0;
}



//IIC连续读
//addr:器件地址
//reg:要读取的寄存器地址
//len:要读取的长度
//buf:读取到的数据存储区
//返回值:0,正常
//    其他,错误代码
u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf)
{

	HAL_I2C_Mem_Read(&hi2c1, ((addr<<1)|1), reg, 1, (unsigned char *)buf, len, HAL_MAX_DELAY);
	return 0;
}



//IIC写一个字节
//reg:寄存器地址
//data:数据
//返回值:0,正常
//    其他,错误代码
u8 MPU_Write_Byte(u8 reg,u8 data)
{

	HAL_I2C_Mem_Write(&hi2c1, (MPU_ADDR<<1)|0, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
	return 0;
}



//IIC读一个字节
//reg:寄存器地址
//返回值:读到的数据
u8 MPU_Read_Byte(u8 reg)
{
	u8 res;

	HAL_I2C_Mem_Read(&hi2c1, (MPU_ADDR<<1)|1, reg, I2C_MEMADD_SIZE_8BIT, &res, 1, HAL_MAX_DELAY);
	return res;
}



////////////////////////////////////////////////////////////////////////////////////////////

double ACX,ACY,ACZ; //加速度

//读取 加速度原始数据
void read_acc(void)
{
	unsigned char  accbuff[6]={0};  //MPU_ACCEL_XOUTH_REG 加速度

	short aacx,aacy,aacz; //加速度

	short  lingmin=16384;//灵敏度 16384

	//读取加速度3轴高低位数据
	HAL_I2C_Mem_Read(&hi2c1, 0xD0, MPU_ACCEL_XOUTH_REG, 1, accbuff, 6, HAL_MAX_DELAY);

	aacx=((short)(accbuff[0]<<8))|accbuff[1];

	aacy=((short)(accbuff[2]<<8))|accbuff[3];

	aacz=((short)(accbuff[4]<<8))|accbuff[5];

	ACX = (float)(aacx)/lingmin;

	ACY = (float)(aacy)/lingmin;

	ACZ = (float)(aacz)/lingmin;

//	GUA_LOGI("%.1f\r\n",ACX);
}




