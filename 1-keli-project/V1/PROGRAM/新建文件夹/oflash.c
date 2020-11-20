
#include "oflash.h"

#include <stdio.h>
#include <string.h> //使用到了memcpy
#include "main.h"

void Onchip_Flash_Test(void)
{
	int i;
	uint32_t PageError = 0;
	
	FLASH_EraseInitTypeDef FlashSet;
	
	HAL_StatusTypeDef status;
	
	uint32_t addr = 0x0803F800;
	uint32_t data_buf[LEN];
	
	/* 读取Flash内容 */
	memcpy(data_buf, (uint32_t*)addr, sizeof(uint32_t)*LEN);
	printf("read before erase:\r\n\t");
	for(i = 0;i < LEN;i++)
	{
		printf("0x%08x ", data_buf[i]);
	}
	printf("\r\n");
	
	/* 写入新的数据 */
	//擦除最后一页
	FlashSet.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashSet.Banks = FLASH_BANK_1;
	FlashSet.Sector = 127;
	FlashSet.NbSectors = 1;
	//解锁Flash操作
	HAL_FLASH_Unlock();
	status = HAL_FLASHEx_Erase(&FlashSet, &PageError);
	HAL_FLASH_Lock();
	if(status != HAL_OK)
	{
		printf("erase fail, PageError = %d\r\n", PageError);
	}
	printf("erase success\r\n");
	
	
	/* 读取Flash内容 */
	memcpy(data_buf, (uint32_t*)addr, sizeof(uint32_t)*LEN);
	printf("read after erase:\r\n\t");
	for(i = 0;i < LEN;i++)
	{
		printf("0x%08x ", data_buf[i]);
	}
	printf("\r\n");

	//写入Flash内容
	HAL_FLASH_Unlock();
	for (i = 0; i < LEN * sizeof(uint32_t); i+=8)
	{
			//一个字是32位，一次写入两个字，64位，8个字节
			status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, addr + i, (uint64_t)i);
			if(status != HAL_OK)
			{
				break;
			}
	}
	HAL_FLASH_Lock();
	if(i < LEN)
	{
		printf("write fail\r\n");
	}
	else
	{
		printf("write success\r\n");
	}

	/* 读取Flash内容 */
	addr = 0x0803F800;
	memcpy(data_buf, (uint32_t*)addr, sizeof(uint32_t)*LEN);
	printf("read after write:\r\n\t");
	for(i = 0;i < LEN;i++)
	{
		printf("0x%08x ", data_buf[i]);
	}
	printf("\r\n");
	
}

