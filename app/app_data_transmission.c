#include "app_data_transmission.h"
#include "file_operate.h"
#include "module_ymodem.h"
#include "device_storage.h"
#include "driver_usart.h"
#include "driver_gpio.h"
#include "driver_delay.h"
#include "ff.h"
#include "diskio.h"
#include "w25qxx.h"

typedef struct
{
    int8 init_flag;
    FIL	file_fd;
    char filename[16];
} DATA_TRANS;

DATA_TRANS *p_data_trans = NULL;

int32 app_sys_init(void)
{
    strat_usart_interupt();

    /*外输初始化完进入主循环前*/
    //检测SPI与W25Q128通信是否正常
		GUA_LOGI("Reset,ID:0x%x\r\n", BSP_W25Qx_Read_ID());
    // BSP_W25Qx_Erase_Chip();

    Mount_FatFs(); //挂载文件系统

    FatFs_GetDiskInfo(); //获取磁盘信息
    FatFs_ScanDir("0:/");

    return REV_OK;
}




static FRESULT app_trans_append_or_create_binary(const char* filename, const uint8_t* data, uint32_t size) {
    FRESULT res;
    UINT bytesWritten;

    if (filename ==NULL || strlen(filename) == 0) {
        return REV_ERR;
    }

    if (p_data_trans->init_flag == 0) {
        // 尝试打开文件以检查是否存在
        res = f_open(&p_data_trans->file_fd, filename, FA_READ);
        if (res == FR_OK) {
            f_close(&p_data_trans->file_fd);
            FatFs_DeleteFile((TCHAR *)filename);
            delay_ms(200);
        }
        f_close(&p_data_trans->file_fd);

        // 文件不存在，创建新二进制文件
        res = f_open(&p_data_trans->file_fd, filename, FA_WRITE | FA_CREATE_ALWAYS);
        if (res != FR_OK) {
            return res;
        }
    }
    p_data_trans->init_flag = 1;

     // 写入二进制数据
    res = f_write(&p_data_trans->file_fd, data, size, &bytesWritten);
    return (res == FR_OK && bytesWritten == size) ? FR_OK : FR_DISK_ERR;
}

char afilename[16] = {0};

int32 app_trans_save_file_data(const char* filename, uint8 *data, uint32 size)
{
    FRESULT res;
    strcpy(afilename, filename);
    res =  app_trans_append_or_create_binary(filename, data, size);
    if (res != FR_OK) {
        return REV_ERR;
    }
    return REV_OK;
}

int32 app_trans_start_service()
{
    int32 rev;

    if (p_data_trans == NULL) {
        p_data_trans = (DATA_TRANS *) malloc(sizeof(DATA_TRANS));
        if (p_data_trans == NULL) {
            return REV_ERR;
        }
        memset(p_data_trans, 0, sizeof(DATA_TRANS));
    }

    init_ymodem();
    rev = start_ymodem_serve(app_trans_save_file_data);
    deinit_ymodem();
    app_trans_reset_service();
    GUA_LOGI("ymodem_handel ok\r\n");

    free(p_data_trans);
    p_data_trans = NULL;

    return rev;
}

int32 app_trans_reset_service(void)
{
    p_data_trans->init_flag = 0;
    f_close(&p_data_trans->file_fd);

    free(p_data_trans);
    p_data_trans = NULL;

	return REV_OK;
}
