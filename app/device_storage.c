#include "device_storage.h"
#include "w25qxx.h"
#include "w25qxx_config.h"
#include "driver_usart.h"

#define s_debug_error GUA_LOGE
#define PAGE_LEN 0x1000

typedef struct
{
    uint32 seek_address;
}CTL_CONTIN_WRITE;

CTL_CONTIN_WRITE g_contin_write = {0};

int32 device_storage_init(void)
{
    uint16 ID;

    if (BSP_W25Qx_Init() != W25Qx_OK) {
        s_debug_error("storange init error!\r\n");
        return REV_ERR;
    }

    ID = BSP_W25Qx_Read_ID();
    if(ID != W25Q128_DEFINE) {
        s_debug_error("storange not support! ID is [0x%04x]\r\n", ID);
        return REV_ERR;
    }

    return REV_OK;
}


// 写入4096 1个扇区数据
int32 device_storage_continuou_4096_write(uint32 start_address, uint8 *buffer)
{
    uint32 i=0;

    // 整块写必须满足从扇区起始地址开始写数据
    if ((start_address % PAGE_LEN) != 0) { // 0xFFF = 二进制 111111111111（低12位）
        s_debug_error("address error! start_address[0x%08x]`4096 = %d\r\n", start_address, start_address % PAGE_LEN);
        return REV_ERR;
    }

    if(BSP_W25Qx_Erase_Sector(start_address) != W25Qx_OK) {
        s_debug_error("Erase_Block error!\r\n");
        return REV_ERR;
    }

    if(BSP_W25Qx_Write(buffer, start_address, PAGE_LEN)!= W25Qx_OK) {
        s_debug_error("storage write data error\r\n");
        return REV_ERR;
    }


    return REV_OK;
}


int32 device_storage_read(uint32 start_address, uint8 *buffer, uint32 buf_len)
{
    if(BSP_W25Qx_Read(buffer, start_address, buf_len) != W25Qx_OK) {
        s_debug_error("QSPI Read ERROR\r\n");
        return REV_ERR;
    }
    return REV_OK;
}
