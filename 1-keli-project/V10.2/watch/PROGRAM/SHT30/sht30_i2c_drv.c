#include "sht30_i2c_drv.h"
#include "i2c.h"

/**
 * @brief	向SHT30发送一条指令(16bit)
 * @param	cmd —— SHT30指令（在SHT30_MODE中枚举定义）
 * @retval	成功返回HAL_OK
*/
static uint8_t	SHT30_Send_Cmd(SHT30_CMD cmd)
{
    uint8_t cmd_buffer[2];
    cmd_buffer[0] = cmd >> 8;
    cmd_buffer[1] = cmd;
    return HAL_I2C_Master_Transmit(&hi2c2, SHT30_ADDR_WRITE, (uint8_t*) cmd_buffer, 2, HAL_MAX_DELAY);
}


/**
 * @brief	从SHT30读取一次数据
 * @param	dat —— 存储读取数据的地址（6个字节数组）
 * @retval	成功 —— 返回HAL_OK
*/
uint8_t SHT30_Read_Dat(uint8_t* dat)
{
	SHT30_Send_Cmd(READOUT_FOR_PERIODIC_MODE);
	return HAL_I2C_Master_Receive(&hi2c2, SHT30_ADDR_READ, dat, 6, HAL_MAX_DELAY);
}



/**
 * @brief	复位SHT30
 * @param	none
 * @retval	none
*/
void SHT30_Reset(void)
{
    SHT30_Send_Cmd(SOFT_RESET_CMD);
    HAL_Delay(20);
}


/**
 * @brief	初始化SHT30
 * @param	none
 * @retval	成功返回HAL_OK
 * @note	周期测量模式
*/
uint8_t SHT30_Init(void)
{
    return SHT30_Send_Cmd(MEDIUM_2_CMD);
}



/**
在数据手册中可知，SHT30分别在温度数据和湿度数据之后发送了8-CRC校验码，确保了数据可靠性。
CRC-8校验程序如下
*/
uint8_t CheckCrc8(uint8_t* const message, uint8_t initial_value)
{
    uint8_t  remainder;	    //余数
    uint8_t  i = 0, j = 0;  //循环变量

    /* 初始化 */
    remainder = initial_value;

    for(j = 0; j < 2;j++)
    {
        remainder ^= message[j];

        /* 从最高位开始依次计算  */
        for (i = 0; i < 8; i++)
        {
            if (remainder & 0x80)
            {
                remainder = (remainder << 1)^CRC8_POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
    }

    /* 返回计算的CRC码 */
    return remainder;
}



/**
 * @brief	将SHT30接收的6个字节数据进行CRC校验，并转换为温度值和湿度值
 * @param	dat  —— 存储接收数据的地址（6个字节数组）
 * @retval	校验成功  —— 返回0
 * 			校验失败  —— 返回1，并设置温度值和湿度值为0
*/
uint8_t SHT30_Dat_To_Float(uint8_t* const dat, float* temperature, float* humidity)
{
	uint16_t recv_temperature = 0;
	uint16_t recv_humidity = 0;
	
	/* 校验温度数据和湿度数据是否接收正确 */
	if(CheckCrc8(dat, 0xFF) != dat[2] || CheckCrc8(&dat[3], 0xFF) != dat[5])
		return 1;
	
	/* 转换温度数据 */
	recv_temperature = ((uint16_t)dat[0]<<8)|dat[1];
	*temperature = -45 + 175*((float)recv_temperature/65535);
	
	/* 转换湿度数据 */
	recv_humidity = ((uint16_t)dat[3]<<8)|dat[4];
	*humidity = 100 * ((float)recv_humidity / 65535);
	
	return 0;
}




