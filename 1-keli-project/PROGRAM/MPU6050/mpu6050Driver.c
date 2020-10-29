#include "mpu6050Driver.h"
#include "stdio.h"
static signed char gyro_orientation[9] = { 1, 0, 0,
                                           0, 1, 0,
                                           0, 0, 1};

																					 void MPU_6050_Init(void)
{
	HAL_StatusTypeDef status;
	HAL_I2C_StateTypeDef flag;
	unsigned char pdata;
	//检查设备是否准备好  地址   检查 次数 超时时间  
	status=HAL_I2C_IsDeviceReady(&hi2c1, ADDRESS_W, 10, HAL_MAX_DELAY);
	printf("status is %d\n",status);
	//检查总线是否准备好
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	//发送写寄存器命令
	pdata=0x80; //复位MPU
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_PWR_MGMT1_REG, 1, &pdata, 1, HAL_MAX_DELAY); //写0x80复位
	status=HAL_I2C_IsDeviceReady(&hi2c1, ADDRESS_W, 10, HAL_MAX_DELAY);
	printf("status is %d\n",status);
	
	HAL_Delay(500);  //复位后需要等待一段时间 等待芯片复位完成 
	
	//检查总线是否准备好
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	//唤醒MPU
	pdata=0x01; // 7位 1 重启  6位睡眠模式1 睡眠 2 唤醒   3位 为u你懂传感器0 开启    0-2位 时钟选择  01 PLL使用XZ轴陀螺作为参数
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_PWR_MGMT1_REG, 1, &pdata, 1, HAL_MAX_DELAY); //写0x80复位
	//设陀螺仪 寄存器  2000  3
	pdata=3<<3; //设置3 为量程2000  右移3位 到对应的 3 4 位寄存器中
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_GYRO_CFG_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	//设置加速度传感器量程 2g
	pdata=0; 
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_ACCEL_CFG_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	//陀螺仪采样分频设置
	pdata=19; //1000/50-1  这个还需要查资料查看  原因 和计算方法
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_SAMPLE_RATE_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	//关闭所有中断
	pdata=0;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_INT_EN_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	//I2C 主模式的 外接磁力传感器接口关闭
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_USER_CTRL_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	//关闭FIFO 
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_FIFO_EN_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	//中断旁路设置 低电平有效
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0X80;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_INTBP_CFG_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	//设置低通滤波器
	MPU_Set_LPF(50/2);
	//读器件ID  默认是 0x68 
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=MPU_DEVICE_ID_REG;
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_R, MPU_DEVICE_ID_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	printf("ID is %X \n",pdata);
	//使能 陀螺仪 和加速度 工作
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0;
	HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_PWR_MGMT2_REG, 1, &pdata, 1, HAL_MAX_DELAY);
//寄存器输出调试观看
/*
	//读取寄存器1 
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0;
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_R, MPU_PWR_MGMT1_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	printf("0x6B REG1 %02X \n",pdata);
	//读取温度传感器
	HAL_Delay(500);
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0xff;
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_R, MPU_TEMP_OUTH_REG, 1, &pdata, 1, HAL_MAX_DELAY); 
	printf("hight bit %02X \n",pdata);
	HAL_Delay(500);
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	pdata=0xff;
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_R, MPU_TEMP_OUTH_REG+1, 1, &pdata, 1, HAL_MAX_DELAY); 
	printf("low bit %02X \n",pdata);
*/
}
//设置MPU6050的数字低通滤波器
//lpf:数字低通滤波频率(Hz)
//返回值:0,设置成功
//    其他,设置失败 
unsigned char  MPU_Set_LPF(unsigned short lpf)
{
	unsigned char data=0;
	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6; 
	
	return HAL_I2C_Mem_Write(&hi2c1, ADDRESS_W, MPU_CFG_REG, 1, &data, 1, HAL_MAX_DELAY); 
		//MPU_Write_Byte(MPU_CFG_REG,data);//设置数字低通滤波器  
}

//读取 温度传感器   陀螺仪  加速度原始数据
void read_all(void)
{
	HAL_StatusTypeDef status;
	HAL_I2C_StateTypeDef flag;
	unsigned char tem[2]={0};
	unsigned char  accbuff[6]={0};  //MPU_ACCEL_XOUTH_REG 加速度 
	unsigned char tuoluo[6]={0};
	short aacx,aacy,aacz; //加速度
	short tolx,toly,tolz;
	 short raw;
	float temp;
	short  lingmin=16384;//灵敏度 16384 
	float tuol=16.4f;
	flag=HAL_I2C_GetState(&hi2c1);
	printf("flag %X \n",flag);
	status=HAL_I2C_Mem_Read(&hi2c1, ADDRESS_W, MPU_TEMP_OUTH_REG, 1, tem, 2, HAL_MAX_DELAY); 
	printf("status %02X \n",status);
	raw=((unsigned short)tem[0]<<8)|tem[1];  
	printf("%d %d \n",tem[0],tem[1]);
	temp=36.53+((double)raw)/340;  
	printf("%3.3f C\n",temp);
	//读取加速度3轴高低位数据
	status=HAL_I2C_Mem_Read(&hi2c1, ADDRESS_W, MPU_ACCEL_XOUTH_REG, 1, accbuff, 6, HAL_MAX_DELAY); 
	aacx=((short)(accbuff[0]<<8))|accbuff[1];
	aacy=((short)(accbuff[2]<<8))|accbuff[3];
	aacz=((short)(accbuff[4]<<8))|accbuff[5];
	
	printf("acc is  x %d y %d z %d   x%.1f g,y%.1f g,z%.1f g\t",aacx,aacy,aacz,
																																	(float)(aacx)/lingmin,
																																	(float)(aacy)/lingmin,
																																	(float)(aacz)/lingmin																																		
																																	);
	//读取陀螺仪3轴  MPU_GYRO_XOUTH_REG
	status=HAL_I2C_Mem_Read(&hi2c1, ADDRESS_W, MPU_GYRO_XOUTH_REG, 1, tuoluo, 6, HAL_MAX_DELAY); 
	tolx=((unsigned short)(tuoluo[0]<<8))|tuoluo[1];
	toly=((unsigned short)(tuoluo[2]<<8))|tuoluo[3];
	tolz=((unsigned short)(tuoluo[4]<<8))|tuoluo[5];		
	printf("tuoluo is  x %d y %d z %d   x%.1f ,y%.1f ,z%.1f \n",tolx,toly,tolz,
																																	(float)(tolx)/tuol,
																																	(float)(toly)/tuol,
																																	(float)(tolz)/tuol																																		
																																	);		

} 
//定义融合DMP库的函数  
unsigned char HAL_i2c_write(unsigned char slave_addr, unsigned char reg_addr, unsigned char length, unsigned char const *data)
{
	//printf("flag %X \n",HAL_I2C_GetState(&hi2c1));
	HAL_I2C_GetState(&hi2c1);
	//DMP库驱动  slave_addr 地址是0x68 发送时需要左移1位最后一位或上读写位
	HAL_I2C_Mem_Write(&hi2c1, ((slave_addr<<1)|0), reg_addr, 1, (unsigned char *)data, length, HAL_MAX_DELAY);
	return 0;
}
unsigned char HAL_i2c_read(unsigned char slave_addr, unsigned char reg_addr, unsigned char length, unsigned char const *data)
{
	//printf("flag %X \n",HAL_I2C_GetState(&hi2c1));
	HAL_I2C_GetState(&hi2c1);
	//DMP库驱动  slave_addr 地址是0x68 发送时需要左移1位最后一位或上读写位
	HAL_I2C_Mem_Read(&hi2c1, ((slave_addr<<1)|1), reg_addr, 1, (unsigned char *)data, length, HAL_MAX_DELAY);
	return 0;
}
//mpu6050,dmp初始化
//返回值:0,正常
//    其他,失败
unsigned char mpu_dmp_init(void)
{
	unsigned char res=0;
	//IIC_Init(); 		//初始化IIC总线
	if(mpu_init()==0)	//初始化MPU6050
	{	 
		res=mpu_set_sensors(INV_XYZ_GYRO|INV_XYZ_ACCEL);//设置所需要的传感器
		if(res)return 1; 
		res=mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);//设置FIFO
		if(res)return 2; 
		res=mpu_set_sample_rate(DEFAULT_MPU_HZ);	//设置采样率
		if(res)return 3; 
		res=dmp_load_motion_driver_firmware();		//加载dmp固件
		if(res)return 4; 
		res=dmp_set_orientation(inv_orientation_matrix_to_scalar(gyro_orientation));//设置陀螺仪方向
		if(res)return 5; 
		res=dmp_enable_feature(DMP_FEATURE_6X_LP_QUAT|DMP_FEATURE_TAP|	//设置dmp功能
		    DMP_FEATURE_ANDROID_ORIENT|DMP_FEATURE_SEND_RAW_ACCEL|DMP_FEATURE_SEND_CAL_GYRO|
		    DMP_FEATURE_GYRO_CAL);
		if(res)return 6; 
		res=dmp_set_fifo_rate(DEFAULT_MPU_HZ);	//设置DMP输出速率(最大不超过200Hz)
		if(res)return 7;   
		res=run_self_test();		//自检
		if(res)return 8;    
		res=mpu_set_dmp_state(1);	//使能DMP
		if(res)return 9;     
	}
	return 0;
}
//陀螺仪方向控制
unsigned short inv_orientation_matrix_to_scalar(
    const signed char *mtx)
{
    unsigned short scalar; 
    /*
       XYZ  010_001_000 Identity Matrix
       XZY  001_010_000
       YXZ  010_000_001
       YZX  000_010_001
       ZXY  001_000_010
       ZYX  000_001_010
     */

    scalar = inv_row_2_scale(mtx);
    scalar |= inv_row_2_scale(mtx + 3) << 3;
    scalar |= inv_row_2_scale(mtx + 6) << 6;


    return scalar;
}
//方向转换
unsigned short inv_row_2_scale(const signed char *row)
{
    unsigned short b;

    if (row[0] > 0)
        b = 0;
    else if (row[0] < 0)
        b = 4;
    else if (row[1] > 0)
        b = 1;
    else if (row[1] < 0)
        b = 5;
    else if (row[2] > 0)
        b = 2;
    else if (row[2] < 0)
        b = 6;
    else
        b = 7;      // error
    return b;
}
//MPU6050自测试
//返回值:0,正常
//    其他,失败
unsigned char run_self_test(void)
{
	int result;
	//char test_packet[4] = {0};
	long gyro[3], accel[3]; 
	result = mpu_run_self_test(gyro, accel);
	if (result == 0x3) 
	{
		/* Test passed. We can trust the gyro data here, so let's push it down
		* to the DMP.
		*/
		float sens;
		unsigned short accel_sens;
		mpu_get_gyro_sens(&sens);
		gyro[0] = (long)(gyro[0] * sens);
		gyro[1] = (long)(gyro[1] * sens);
		gyro[2] = (long)(gyro[2] * sens);
		dmp_set_gyro_bias(gyro);
		mpu_get_accel_sens(&accel_sens);
		accel[0] *= accel_sens;
		accel[1] *= accel_sens;
		accel[2] *= accel_sens;
		dmp_set_accel_bias(accel);
		return 0;
	}else return 1;
}
//得到dmp处理后的数据(注意,本函数需要比较多堆栈,局部变量有点多)
//pitch:俯仰角 精度:0.1°   范围:-90.0° <---> +90.0°
//roll:横滚角  精度:0.1°   范围:-180.0°<---> +180.0°
//yaw:航向角   精度:0.1°   范围:-180.0°<---> +180.0°
//返回值:0,正常
//    其他,失败
unsigned char mpu_dmp_get_data(float *pitch,float *roll,float *yaw)
{
	float q0=1.0f,q1=0.0f,q2=0.0f,q3=0.0f;
	unsigned long sensor_timestamp;
	short gyro[3], accel[3], sensors;
	unsigned char more;
	long quat[4]; 
	if(dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,&more))return 1;	 
	/* Gyro and accel data are written to the FIFO by the DMP in chip frame and hardware units.
	 * This behavior is convenient because it keeps the gyro and accel outputs of dmp_read_fifo and mpu_read_fifo consistent.
	**/
	/*if (sensors & INV_XYZ_GYRO )
	send_packet(PACKET_TYPE_GYRO, gyro);
	if (sensors & INV_XYZ_ACCEL)
	send_packet(PACKET_TYPE_ACCEL, accel); */
	/* Unlike gyro and accel, quaternions are written to the FIFO in the body frame, q30.
	 * The orientation is set by the scalar passed to dmp_set_orientation during initialization. 
	**/
	if(sensors&INV_WXYZ_QUAT) 
	{
		q0 = quat[0] / q30;	//q30格式转换为浮点数
		q1 = quat[1] / q30;
		q2 = quat[2] / q30;
		q3 = quat[3] / q30; 
		//计算得到俯仰角/横滚角/航向角
		*pitch = asin(-2 * q1 * q3 + 2 * q0* q2)* 57.3;	// pitch
		*roll  = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2* q2 + 1)* 57.3;	// roll
		*yaw   = atan2(2*(q1*q2 + q0*q3),q0*q0+q1*q1-q2*q2-q3*q3) * 57.3;	//yaw
	}else return 2;
	return 0;
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
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_W, MPU_ACCEL_XOUTH_REG, 1, accbuff, 6, HAL_MAX_DELAY); 
	
	aacx=((short)(accbuff[0]<<8))|accbuff[1];
	
	aacy=((short)(accbuff[2]<<8))|accbuff[3];
	
	aacz=((short)(accbuff[4]<<8))|accbuff[5];

	ACX = (float)(aacx)/lingmin;
	
	ACY = (float)(aacy)/lingmin;
	
	ACZ = (float)(aacz)/lingmin;
	
//	printf("%.1f\r\n",ACX);																														
} 










































