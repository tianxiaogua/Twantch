#include "W25Qxx.h"
#include "driver_usart.h"
#include <string.h>
#include "driver_delay.h"
#include "driver_tool.h"
#include "w25qxx_config.h"

 /**********************************************************************************
  * 函数功能: 模块初始化
  */
uint8 BSP_W25Qx_Init(void)
{
	BSP_W25Qx_Reset();
	return BSP_W25Qx_GetStatus();
}


static void	BSP_W25Qx_Reset(void)
{
	uint8 cmd[2] = {RESET_ENABLE_CMD,RESET_MEMORY_CMD};

	W25Qx_Enable();
	/* Send the reset command */
	HAL_SPI_Transmit(&hspi1, cmd, 2, W25Qx_TIMEOUT_VALUE);
	W25Qx_Disable();

}

 /**********************************************************************************
  * 函数功能: 获取设备状态
  */
static uint8 BSP_W25Qx_GetStatus(void)
{
	uint8 cmd[] = {READ_STATUS_REG1_CMD};
	uint8 status;

	W25Qx_Enable();
	/* Send the read status command */
	HAL_SPI_Transmit(&hspi1, cmd, 1, W25Qx_TIMEOUT_VALUE);
	/* Reception of the data */
	HAL_SPI_Receive(&hspi1,&status, 1, W25Qx_TIMEOUT_VALUE);
	W25Qx_Disable();

	/* Check the value of the register */
  if((status & W25Q128FV_FSR_BUSY) != 0)
  {
    return W25Qx_BUSY;
  }
	else
	{
		return W25Qx_OK;
	}
}

 /**********************************************************************************
  * 函数功能: 写使能
  */
uint8 BSP_W25Qx_WriteEnable(void)
{
	uint8 cmd[] = {WRITE_ENABLE_CMD};
	uint32 tickstart = HAL_GetTick();

	/*Select the FLASH: Chip Select low */
	W25Qx_Enable();
	/* Send the read ID command */
	HAL_SPI_Transmit(&hspi1, cmd, 1, W25Qx_TIMEOUT_VALUE);
	/*Deselect the FLASH: Chip Select high */
	W25Qx_Disable();

	/* Wait the end of Flash writing */
	while(BSP_W25Qx_GetStatus() == W25Qx_BUSY);
	{
		/* Check for the Timeout */
    if((HAL_GetTick() - tickstart) > W25Qx_TIMEOUT_VALUE)
    {
			return W25Qx_TIMEOUT;
    }
	}

	return W25Qx_OK;
}

 /**********************************************************************************
  * 函数功能: 获取设备ID
  */
uint16 BSP_W25Qx_Read_ID(void)
{
	uint16 ID = 0;

	uint8 cmd[4] = {READ_ID_CMD,0x00,0x00,0x00};

	W25Qx_Enable();
	/* Send the read ID command */
	HAL_SPI_Transmit(&hspi1, cmd, 4, W25Qx_TIMEOUT_VALUE);
	/* Reception of the data */
	HAL_SPI_Receive(&hspi1, (uint8 *)&ID, 2, W25Qx_TIMEOUT_VALUE);
	W25Qx_Disable();
	return ID;
}

 /**********************************************************************************
  * 函数功能: 读数据
  * 输入参数: 缓存数组指针、读地址、字节数
  */
uint8 BSP_W25Qx_Read(uint8* pData, uint32 ReadAddr, uint32 Size)
{
	uint8 cmd[4];

	/* Configure the command */
	cmd[0] = READ_CMD;
	cmd[1] = (uint8)(ReadAddr >> 16);
	cmd[2] = (uint8)(ReadAddr >> 8);
	cmd[3] = (uint8)(ReadAddr);

	W25Qx_Enable();
	/* Send the read ID command */
	HAL_SPI_Transmit(&hspi1, cmd, 4, W25Qx_TIMEOUT_VALUE);
	/* Reception of the data */
	if (HAL_SPI_Receive(&hspi1, pData,Size,W25Qx_TIMEOUT_VALUE) != HAL_OK)
  {
    return W25Qx_ERROR;
  }
	W25Qx_Disable();
	return W25Qx_OK;
}

 /**********************************************************************************
  * 函数功能: 写数据
  * 输入参数: 缓存数组指针、写地址、字节数
  */
uint8 BSP_W25Qx_Write(uint8* pData, uint32 WriteAddr, uint32 Size)
{
	uint8 cmd[4];
	uint32 end_addr, current_size, current_addr;
	uint32 tickstart = HAL_GetTick();

	/* Calculation of the size between the write address and the end of the page */
  current_addr = 0;

  while (current_addr <= WriteAddr)
  {
    current_addr += W25Q128FV_PAGE_SIZE;
  }
  current_size = current_addr - WriteAddr;

  /* Check if the size of the data is less than the remaining place in the page */
  if (current_size > Size)
  {
    current_size = Size;
  }

  /* Initialize the adress variables */
  current_addr = WriteAddr;
  end_addr = WriteAddr + Size;

  /* Perform the write page by page */
  do
  {
		/* Configure the command */
		cmd[0] = PAGE_PROG_CMD;
		cmd[1] = (uint8)(current_addr >> 16);
		cmd[2] = (uint8)(current_addr >> 8);
		cmd[3] = (uint8)(current_addr);

		/* Enable write operations */
		BSP_W25Qx_WriteEnable();

		W25Qx_Enable();
		/* Send the command */
		if (HAL_SPI_Transmit(&hspi1,cmd, 4, W25Qx_TIMEOUT_VALUE) != HAL_OK)
		{
			return W25Qx_ERROR;
		}

		/* Transmission of the data */
		if (HAL_SPI_Transmit(&hspi1, pData,current_size, W25Qx_TIMEOUT_VALUE) != HAL_OK)
		{
			return W25Qx_ERROR;
		}
		W25Qx_Disable();

    	/* Wait the end of Flash writing */
		while(BSP_W25Qx_GetStatus() == W25Qx_BUSY); {
			/* Check for the Timeout */
			if((HAL_GetTick() - tickstart) > W25Qx_TIMEOUT_VALUE)
			{
				return W25Qx_TIMEOUT;
			}
		}

    /* Update the address and size variables for next page programming */
    current_addr += current_size;
    pData += current_size;
    current_size = ((current_addr + W25Q128FV_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : W25Q128FV_PAGE_SIZE;
  } while (current_addr < end_addr);


	return W25Qx_OK;
}

 /**********************************************************************************
  * 函数功能: 扇区擦除
  * 输入参数: 地址
  * W25Q64的擦除最小单位为扇区（4KB），擦除命令为0x20，需发送24位地
  */
uint8 BSP_W25Qx_Erase_Sector(uint32 Address)
{
	uint8 cmd[4];
	uint32 tickstart = HAL_GetTick();
	cmd[0] = SECTOR_ERASE_CMD;
	cmd[1] = (uint8)(Address >> 16);
	cmd[2] = (uint8)(Address >> 8);
	cmd[3] = (uint8)(Address);

	/* Enable write operations */
	BSP_W25Qx_WriteEnable();

	/*Select the FLASH: Chip Select low */
	W25Qx_Enable();
	/* Send the read ID command */
	HAL_SPI_Transmit(&hspi1, cmd, 4, W25Qx_TIMEOUT_VALUE);
	/*Deselect the FLASH: Chip Select high */
	W25Qx_Disable();

	/* Wait the end of Flash writing */
	while(BSP_W25Qx_GetStatus() == W25Qx_BUSY);
	{
		/* Check for the Timeout */
    if((HAL_GetTick() - tickstart) > W25Q128FV_SECTOR_ERASE_MAX_TIME)
    {
			return W25Qx_TIMEOUT;
    }
	}
	return W25Qx_OK;
}

 /**********************************************************************************
  * 函数功能: 芯片擦除
  */
uint8 BSP_W25Qx_Erase_Chip(void)
{
	uint8 cmd[4];
	uint32 tickstart = HAL_GetTick();
	cmd[0] = CHIP_ERASE_CMD;
	GUA_LOGW("BSP_W25Qx: full earse chip\r\n");
	/* Enable write operations */
	BSP_W25Qx_WriteEnable();

	/*Select the FLASH: Chip Select low */
	W25Qx_Enable();
	/* Send the read ID command */
	HAL_SPI_Transmit(&hspi1, cmd, 1, W25Qx_TIMEOUT_VALUE);
	/*Deselect the FLASH: Chip Select high */
	W25Qx_Disable();

	/* Wait the end of Flash writing */
	while(BSP_W25Qx_GetStatus() != W25Qx_BUSY);
	{
		/* Check for the Timeout */
		if((HAL_GetTick() - tickstart) > W25Q128FV_BULK_ERASE_MAX_TIME)
		{
			GUA_LOGE("BSP_W25Qx: full earse chip error!\r\n");
			return W25Qx_TIMEOUT;
		}
	}
	GUA_LOGW("BSP_W25Qx: full earse chip ok\r\n");

	return W25Qx_OK;
}






void test_flash(void)
{
	uint8 wData[0x100];   //写缓存数组
	uint8 rData[0x100];   //读缓存数组
	uint16 ID;          //设备ID缓存数组
	uint32 i;


	GUA_LOGW("\r\n SPI-W25Qxx Example \r\n\r\n");

	/*-Step1- 验证设备ID  ************************************************Step1*/
	BSP_W25Qx_Init();
	ID = BSP_W25Qx_Read_ID();

    //第一位厂商ID固定0xEF,第二位设备ID根据容量不同,具体为：
     //W25Q16为0x14、32为0x15、40为0x12、64为0x16、80为0x13、128为0x17
	if(ID == W25Q128_DEFINE) {
		GUA_LOGI("w25Q128 support [0x%04x]\r\n", ID);
	} else {
		GUA_LOGW("W25Qxx ID is : [0x%04x]\r\n", ID);
	}
	/*-Step2- 擦除块  ************************************************Step2*/
	if(BSP_W25Qx_Erase_Sector(0) == W25Qx_OK)
		GUA_LOGW(" QSPI Erase Block OK!\r\n");
	else
		GUA_LOGW("something wrong in Step2\r\n");
	/*-Step3- 写数据  ************************************************Step3*/
	for(i =0;i<0x100;i ++)
	{
			wData[i] = i;
            rData[i] = 0;
	}

	if(BSP_W25Qx_Write(wData,0x00,0x100)== W25Qx_OK)
		GUA_LOGW(" QSPI Write OK!\r\n");
	else
		GUA_LOGW("something wrong in Step3\r\n");
    /*-Step4- 读数据  ************************************************Step4*/
	if(BSP_W25Qx_Read(rData,0x00,0x100)== W25Qx_OK)
		GUA_LOGW(" QSPI Read ok\r\n\r\n");
	else
		GUA_LOGW("something wrong in Step4\r\n");

	GUA_LOGW("QSPI Read Data : \r\n");
	for(i =0;i<0x100;i++) {

		GUA_LOGW("0x%02X\r\n",rData[i]);

		if (wData[i] != rData[i]) {
			GUA_LOGW(" W25Q64FV QuadSPI Test False : wData[%d], rData[%d]\r\n", wData[i], rData[i]);
		}
		// delay_ms(50);
	}

	GUA_LOGW("\r\n\r\n");
	GUA_LOGW(" W25Q64FV QuadSPI Test OK\r\n");
	/*-Step5- 数据对比  ************************************************Step5*/
}


