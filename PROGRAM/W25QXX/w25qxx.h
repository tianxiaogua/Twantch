#ifndef __W25Qxx_H
#define __W25Qxx_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "driver_tool.h"

#define W25Q128FV_FLASH_SIZE                  0x1000000 /* 128 MBits => 16MBytes */
#define W25Q128FV_SECTOR_SIZE                 0x10000   /* 256 sectors of 64KBytes */
#define W25Q128FV_SUBSECTOR_SIZE              0x1000    /* 4096 subsectors of 4kBytes */
#define W25Q128FV_PAGE_SIZE                   0x100     /* 65536 pages of 256 bytes */

#define W25Q128FV_DUMMY_CYCLES_READ           4
#define W25Q128FV_DUMMY_CYCLES_READ_QUAD      10

#define W25Q128FV_BULK_ERASE_MAX_TIME         250000
#define W25Q128FV_SECTOR_ERASE_MAX_TIME       3000
#define W25Q128FV_SUBSECTOR_ERASE_MAX_TIME    800
#define W25Qx_TIMEOUT_VALUE 1000

/* Reset Operations */
#define RESET_ENABLE_CMD                     0x66
#define RESET_MEMORY_CMD                     0x99

#define ENTER_QPI_MODE_CMD                   0x38
#define EXIT_QPI_MODE_CMD                    0xFF

/* Identification Operations */
#define READ_ID_CMD                          0x90
#define DUAL_READ_ID_CMD                     0x92
#define QUAD_READ_ID_CMD                     0x94
#define READ_JEDEC_ID_CMD                    0x9F

/* Read Operations */
#define READ_CMD                             0x03
#define FAST_READ_CMD                        0x0B
#define DUAL_OUT_FAST_READ_CMD               0x3B
#define DUAL_INOUT_FAST_READ_CMD             0xBB
#define QUAD_OUT_FAST_READ_CMD               0x6B
#define QUAD_INOUT_FAST_READ_CMD             0xEB

/* Write Operations */
#define WRITE_ENABLE_CMD                     0x06
#define WRITE_DISABLE_CMD                    0x04

/* Register Operations */
#define READ_STATUS_REG1_CMD                  0x05
#define READ_STATUS_REG2_CMD                  0x35
#define READ_STATUS_REG3_CMD                  0x15

#define WRITE_STATUS_REG1_CMD                 0x01
#define WRITE_STATUS_REG2_CMD                 0x31
#define WRITE_STATUS_REG3_CMD                 0x11


/* Program Operations */
#define PAGE_PROG_CMD                        0x02
#define QUAD_INPUT_PAGE_PROG_CMD             0x32


/* Erase Operations */
#define SECTOR_ERASE_CMD                     0x20
#define CHIP_ERASE_CMD                       0xC7

#define PROG_ERASE_RESUME_CMD                0x7A
#define PROG_ERASE_SUSPEND_CMD               0x75


/* Flag Status Register */
#define W25Q128FV_FSR_BUSY                    ((uint8)0x01)    /*!< busy */
#define W25Q128FV_FSR_WREN                    ((uint8)0x02)    /*!< write enable */
#define W25Q128FV_FSR_QE                      ((uint8)0x02)    /*!< quad enable */


#define W25Qx_Enable() 			HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET)
#define W25Qx_Disable() 		HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET)

#define W25Qx_OK            ((uint8)0x00)
#define W25Qx_ERROR         ((uint8)0x01)
#define W25Qx_BUSY          ((uint8)0x02)
#define W25Qx_TIMEOUT		((uint8)0x03)


uint8 BSP_W25Qx_Init(void);

static void	BSP_W25Qx_Reset(void);

static uint8 BSP_W25Qx_GetStatus(void);
uint8 BSP_W25Qx_WriteEnable(void);

uint16 BSP_W25Qx_Read_ID(void);

uint8 BSP_W25Qx_Read(uint8* pData, uint32 ReadAddr, uint32 Size);
uint8 BSP_W25Qx_Write(uint8* pData, uint32 WriteAddr, uint32 Size);

uint8 BSP_W25Qx_Erase_Sector(uint32 Address);

uint8 BSP_W25Qx_Erase_Chip(void);

void test_flash(void);
void FatfsTest(void);  //FLASH 虚拟U盘测试函数，进行初始化及文件读写操作，在user.diskio.c中定义

#endif

