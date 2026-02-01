/** \file max30102.c ******************************************************
*
* Project: MAXREFDES117#
* Filename: max30102.cpp
* Description: This module is an embedded controller driver for the MAX30102
*
*
* --------------------------------------------------------------------
*
* This code follows the following naming conventions:
*
* char              ch_pmod_value
* char (array)      s_pmod_s_string[16]
* float             f_pmod_value
* int32_t           n_pmod_value
* int32_t (array)   an_pmod_value[16]
* int16_t           w_pmod_value
* int16_t (array)   aw_pmod_value[16]
* uint16_t          uw_pmod_value
* uint16_t (array)  auw_pmod_value[16]
* uint8_t           uch_pmod_value
* uint8_t (array)   auch_pmod_buffer[16]
* uint32_t          un_pmod_value
* int32_t *         pn_pmod_value
*
* ------------------------------------------------------------------------- */
/*******************************************************************************
* Copyright (C) 2016 Maxim Integrated Products, Inc., All Rights Reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*******************************************************************************
*/
//#include "mbed.h"
#include "MAX30102.h"
#include "i2c.h"


int32_t maxim_max30102_write_reg(uint8_t uch_addr, uint8_t uch_data)
{
	HAL_I2C_GetState(&hi2c1);
	//DMP库驱动  slave_addr 地址 发送时需要左移1位最后一位或上读写位
	return HAL_I2C_Mem_Write(&hi2c1, I2C_WRITE_ADDR, uch_addr, 1, &uch_data, 1, HAL_MAX_DELAY);
}

int32_t maxim_max30102_read_reg(uint8_t uch_addr, uint8_t *puch_data)
{
	HAL_I2C_GetState(&hi2c1);
	//DMP库驱动  slave_addr 地址 发送时需要左移1位最后一位或上读写位
	return HAL_I2C_Mem_Read(&hi2c1, I2C_READ_ADDR, uch_addr, 1, puch_data, 1, HAL_MAX_DELAY);
}

int32_t maxim_max30102_init()
{
  int32_t rev = 0;

  // 1. 配置中断使能寄存器1
  rev = maxim_max30102_write_reg(REG_INTR_ENABLE_1, 0xc0);
  if (rev != 0) // INTR setting 1 failed
  {
    return rev;
  }

  // 2. 配置中断使能寄存器2
  rev = maxim_max30102_write_reg(REG_INTR_ENABLE_2, 0x00);
  if (rev != 0) // INTR setting 2 failed
  {
    return rev;
  }

  // 3. 配置FIFO写指针
  rev = maxim_max30102_write_reg(REG_FIFO_WR_PTR, 0x00);  // FIFO_WR_PTR[4:0]
  if (rev != 0) // FIFO write pointer setting failed
  {
    return rev;
  }

  // 4. 配置溢出计数器
  rev = maxim_max30102_write_reg(REG_OVF_COUNTER, 0x00);  // OVF_COUNTER[4:0]
  if (rev != 0) // Overflow counter setting failed
  {
    return rev;
  }

  // 5. 配置FIFO读指针
  rev = maxim_max30102_write_reg(REG_FIFO_RD_PTR, 0x00);  // FIFO_RD_PTR[4:0]
  if (rev != 0) // FIFO read pointer setting failed
  {
    return rev;
  }

  // 6. 配置FIFO参数
  rev = maxim_max30102_write_reg(REG_FIFO_CONFIG, 0x0f);  // sample avg = 1, fifo rollover=false, fifo almost full = 17
  if (rev != 0) // FIFO config setting failed
  {
    return rev;
  }

  // 7. 配置工作模式
  rev = maxim_max30102_write_reg(REG_MODE_CONFIG, 0x03);   // 0x02 for Red only, 0x03 for SpO2 mode 0x07 multimode LED
  if (rev != 0) // Mode config setting failed
  {
    return rev;
  }

  // 8. 配置SpO2参数
  rev = maxim_max30102_write_reg(REG_SPO2_CONFIG, 0x27);  // SPO2_ADC range = 4096nA, SPO2 sample rate (100 Hz), LED pulseWidth (400uS)
  if (rev != 0) // SpO2 config setting failed
  {
    return rev;
  }

  // 9. 配置LED1电流（~7mA）
  rev = maxim_max30102_write_reg(REG_LED1_PA, 0x24);
  if (rev != 0) // LED1 power setting failed
  {
    return rev;
  }

  // 10. 配置LED2电流（~7mA）
  rev = maxim_max30102_write_reg(REG_LED2_PA, 0x24);
  if (rev != 0) // LED2 power setting failed
  {
    return rev;
  }

  // 11. 配置Pilot LED电流（~25mA）
  rev = maxim_max30102_write_reg(REG_PILOT_PA, 0x7f);
  if (rev != 0) // Pilot LED power setting failed
  {
    return rev;
  }

  // 所有配置成功，返回0（统一错误码风格：0表示成功）
  return 0;
}


int32_t maxim_max30102_read_fifo(uint32_t *pun_red_led, uint32_t *pun_ir_led)
{
    // 1. 参数合法性检查（防止空指针访问，提升健壮性）
    if ((pun_red_led == NULL) || (pun_ir_led == NULL))
    {
        return -1;  // 返回特定错误码标识空指针错误
    }

    // 2. 初始化局部变量和输出参数
    uint32_t un_temp = 0;
    uint8_t uch_temp = 0;  // 统一变量类型为 uint8_t（符合寄存器数据宽度）
    uint8_t ach_i2c_data[6] = {0};  // 初始化数组，避免垃圾数据干扰
    *pun_red_led = 0;
    *pun_ir_led = 0;

    // 3. 读取并清除中断状态寄存器（清除挂起的中断标志）
    maxim_max30102_read_reg(REG_INTR_STATUS_1, &uch_temp);
    maxim_max30102_read_reg(REG_INTR_STATUS_2, &uch_temp);

    // 4. I2C读取FIFO数据（6字节：3字节红光 + 3字节红外光）
    // 先检查I2C总线状态（仅作状态查询，不阻塞，提升驱动可靠性）
    if (HAL_I2C_GetState(&hi2c1) == HAL_I2C_STATE_ERROR)
    {
        return -2;  // 返回特定错误码标识I2C总线错误
    }

    // 读取FIFO数据寄存器，获取6字节采样数据
    // 注：slave_addr 地址左移1位或上读写位，已在 I2C_READ_ADDR 中定义
    HAL_StatusTypeDef i2c_ret = HAL_I2C_Mem_Read(&hi2c1,
                                                 I2C_READ_ADDR,
                                                 REG_FIFO_DATA,
                                                 I2C_MEMADD_SIZE_8BIT,  // 明确地址宽度为8位（替代原1，提升可读性）
                                                 ach_i2c_data,
                                                 6,
                                                 HAL_MAX_DELAY);

    // 检查I2C读取是否成功
    if (i2c_ret != HAL_OK)
    {
        return -3;  // 返回特定错误码标识I2C读取失败
    }

    // 5. 解析3字节红光数据（组合为24位值，掩码保留有效位[17:0]）
    un_temp = (uint32_t)ach_i2c_data[0];
    un_temp <<= 16;
    *pun_red_led += un_temp;

    un_temp = (uint32_t)ach_i2c_data[1];
    un_temp <<= 8;
    *pun_red_led += un_temp;

    un_temp = (uint32_t)ach_i2c_data[2];
    *pun_red_led += un_temp;

    // 6. 解析3字节红外光数据（组合为24位值，掩码保留有效位[17:0]）
    un_temp = (uint32_t)ach_i2c_data[3];
    un_temp <<= 16;
    *pun_ir_led += un_temp;

    un_temp = (uint32_t)ach_i2c_data[4];
    un_temp <<= 8;
    *pun_ir_led += un_temp;

    un_temp = (uint32_t)ach_i2c_data[5];
    *pun_ir_led += un_temp;

    // 7. 掩码操作：保留低18位有效数据，屏蔽高6位[23:18]
    *pun_red_led &= 0x0003FFFF;
    *pun_ir_led &= 0x0003FFFF;

    // 8. 所有操作成功完成
    return 0;
}


int32_t maxim_max30102_reset()
{
    return maxim_max30102_write_reg(REG_MODE_CONFIG,0x40);
}
