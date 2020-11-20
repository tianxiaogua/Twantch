#ifndef _mpu6050Driver_H_
#define _mpu6050Driver_H_

#include "main.h"
#include "dma.h"
#include "i2c.h"

#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include <math.h>
#define ADDRESS_W 0xD0   //写地址 0x68
#define ADDRESS_R 0xD1   //读地址  0x69
#define MPU_PWR_MGMT1_REG		0X6B	//电源管理寄存器1
#define MPU_GYRO_CFG_REG		0X1B	//陀螺仪配置寄存器
#define MPU_ACCEL_CFG_REG		0X1C	//加速度计配置寄存器
#define MPU_SAMPLE_RATE_REG		0X19	//陀螺仪采样频率分频器
#define MPU_INT_EN_REG			0X38	//中断使能寄存器
#define MPU_USER_CTRL_REG		0X6A	//用户控制寄存器
#define MPU_FIFO_EN_REG			0X23	//FIFO使能寄存器
#define MPU_INTBP_CFG_REG		0X37	//中断/旁路设置寄存器
#define MPU_DEVICE_ID_REG		0X75	//器件ID寄存器
#define MPU_PWR_MGMT2_REG		0X6C	//电源管理寄存器2 
#define MPU_CFG_REG				0X1A	//配置寄存器 低通滤波器配置寄存器
#define MPU_TEMP_OUTH_REG		0X41	//温度值高八位寄存器
#define MPU_TEMP_OUTL_REG		0X42	//温度值低8位寄存器

#define MPU_ACCEL_XOUTH_REG		0X3B	//加速度值,X轴高8位寄存器
#define MPU_ACCEL_XOUTL_REG		0X3C	//加速度值,X轴低8位寄存器
#define MPU_ACCEL_YOUTH_REG		0X3D	//加速度值,Y轴高8位寄存器
#define MPU_ACCEL_YOUTL_REG		0X3E	//加速度值,Y轴低8位寄存器
#define MPU_ACCEL_ZOUTH_REG		0X3F	//加速度值,Z轴高8位寄存器
#define MPU_ACCEL_ZOUTL_REG		0X40	//加速度值,Z轴低8位寄存器

#define MPU_GYRO_XOUTH_REG		0X43	//陀螺仪值,X轴高8位寄存器
#define MPU_GYRO_XOUTL_REG		0X44	//陀螺仪值,X轴低8位寄存器
#define MPU_GYRO_YOUTH_REG		0X45	//陀螺仪值,Y轴高8位寄存器
#define MPU_GYRO_YOUTL_REG		0X46	//陀螺仪值,Y轴低8位寄存器
#define MPU_GYRO_ZOUTH_REG		0X47	//陀螺仪值,Z轴高8位寄存器
#define MPU_GYRO_ZOUTL_REG		0X48	//陀螺仪值,Z轴低8位寄存器
//定义输出速度
#define DEFAULT_MPU_HZ  (100)		//100Hz

//q30格式,long转float时的除数.
#define q30  1073741824.0f


void MPU_6050_Init(void);
unsigned char  MPU_Set_LPF(unsigned short lpf);
//DMP库需要的函数
unsigned char HAL_i2c_write(unsigned char slave_addr, unsigned char reg_addr, unsigned char length, unsigned char const *data);
unsigned char HAL_i2c_read(unsigned char slave_addr, unsigned char reg_addr, unsigned char length, unsigned char const *data);
//读取 温度传感器   陀螺仪  加速度数据
void read_all(void);
//陀螺仪方向控制
unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);
//方向转换
unsigned short inv_row_2_scale(const signed char *row);
//MPU6050自测试
//返回值:0,正常
//    其他,失败
unsigned char run_self_test(void);
//mpu6050,dmp初始化
//返回值:0,正常
//    其他,失败
unsigned char mpu_dmp_init(void);
//得到dmp处理后的数据(注意,本函数需要比较多堆栈,局部变量有点多)
//pitch:俯仰角 精度:0.1°   范围:-90.0° <---> +90.0°
//roll:横滚角  精度:0.1°   范围:-180.0°<---> +180.0°
//yaw:航向角   精度:0.1°   范围:-180.0°<---> +180.0°
//返回值:0,正常
//    其他,失败
unsigned char mpu_dmp_get_data(float *pitch,float *roll,float *yaw);

//读取 加速度原始数据
extern double ACX,ACY,ACZ; //加速度
void read_acc(void);
#endif

