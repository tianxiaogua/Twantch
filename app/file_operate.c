#include "file_operate.h"
#include "driver_usart.h"
#include <stdlib.h>

//定义用于格式化的工作区缓存
BYTE *workBuffer;

/*挂载FatFs文件系统*/
void Mount_FatFs(void)
{
	//挂载文件系统
	FRESULT retUSER = f_mount(&User_FatFs, User_SDPath, 1);
	//发生错误
	if(retUSER != FR_OK)
	{
		//没有文件系统，需要格式化
		if(retUSER == FR_NO_FILESYSTEM)
		{
			GUA_LOGW("There is no file system. Start formatting\r\n");
			//创建文件系统
			workBuffer = (BYTE *)malloc(4*User_Sector);
			retUSER = f_mkfs(User_SDPath, User_FatType, 0, workBuffer, 4*User_Sector);
			if(retUSER != FR_OK) { //格式化失败
				GUA_LOGE("Formatting failed. Error code = %d\r\n", retUSER);
			}

			else { //格式化成功
				GUA_LOGI("Formatting successful, starting to remount.\r\n");
				//有文件系统后重新挂载
				retUSER = f_mount(&User_FatFs, User_SDPath, 1);
				//挂载失败
				if(retUSER != FR_OK) {
					GUA_LOGE("An error occurred. Error code = %d\r\n", retUSER);
				} else{ //挂载成功
					GUA_LOGI("*** The file system has been successfully mounted ***\r\n");
				}
			}
		}
		//不是没有文件系统，而是发生其他错误
		else {
			GUA_LOGE("Other errors occurred, error code = %d\r\n", retUSER);
		}
	}
	//有文件系统直接挂在成功
	else {
		GUA_LOGI("The file system has been successfully mounted\r\n");
	}
}

/*获取磁盘信息并在LCD上显示*/
void FatFs_GetDiskInfo(void)
{
    FATFS *fs;
	//定义剩余簇个数变量
    DWORD fre_clust;
	//获取剩余簇个数
    FRESULT res = f_getfree("0:", &fre_clust, &fs);
	//获取失败
    if(res != FR_OK)
    {
        GUA_LOGE("f_getfree() error\r\n");
        return;
    }
    GUA_LOGI("\r\n*** FAT disk info ***\r\n");

	//总的扇区个数
    DWORD tot_sect = (fs->n_fatent - 2) * fs->csize;

	//剩余的扇区个数 = 剩余簇个数 * 每个簇的扇区个数
    DWORD fre_sect = fre_clust * fs->csize;

	//对于SD卡和U盘, _MIN_SS=512字节
#if  _MAX_SS == _MIN_SS
    //SD卡的_MIN_SS固定为512，右移11位相当于除以2048
	//剩余空间大小，单位：MB，用于SD卡，U盘
    DWORD freespace= (fre_sect>>11);
		//总空间大小，单位：MB，用于SD卡，U盘
    DWORD totalSpace= (tot_sect>>11);
#else
	//Flash存储器，小容量
	//剩余空间大小，单位：KB
    DWORD freespace= (fre_sect*fs->ssize)>>10;
	//总空间大小，单位：KB
    DWORD totalSpace= (tot_sect*fs->ssize)>>10;
#endif

	//FAT类型
    GUA_LOGI("FAT type = %d\r\n",fs->fs_type);
    GUA_LOGI("[1=FAT12,2=FAT16,3=FAT32,4=exFAT]\r\n");

	//扇区大小，单位字节
	//SD卡固定512字节
#if  _MAX_SS == _MIN_SS
    GUA_LOGI("Sector size(bytes) = %d\r\n", _MIN_SS);
#else
	//FLASH存储器
    GUA_LOGI("Sector size(bytes) = %d\r\n", fs->ssize);
#endif

    GUA_LOGI("Cluster size(sectors) = %d\r\n", fs->csize);
    GUA_LOGI("Total cluster count = %ld\r\n", fs->n_fatent-2);
    GUA_LOGI("Total sector count = %ld\r\n", tot_sect);

	//总空间
#if  _MAX_SS == _MIN_SS
    GUA_LOGI("Total space(MB) = %ld\r\n", totalSpace);
#else
    GUA_LOGI("Total space(KB) = %ld\r\n", totalSpace);
#endif

	//空闲簇数量
    GUA_LOGI("Free cluster count = %ld\r\n",fre_clust);
	//空闲扇区数量
    GUA_LOGI("Free sector count = %ld\r\n", fre_sect);

	//空闲空间
#if  _MAX_SS == _MIN_SS
    GUA_LOGI("Free space(MB) = %ld\r\n", freespace);
#else
    GUA_LOGI("Free space(KB) = %ld\r\n", freespace);
#endif

    GUA_LOGI("Get FAT disk info OK\r\n");
}

/*创建文本文件*/
FIL	test_file;
void FatFs_WriteTXTFile(TCHAR *filename,uint16_t year, uint8_t month, uint8_t day)
{
	// GUA_LOGI("*** Creating TXT file: %s ***\r\n", filename);

	// FRESULT res = f_open(&test_file, filename, FA_CREATE_ALWAYS | FA_WRITE);
	// //打开/创建文件成功
	// if(res == FR_OK)
	// {
	// 	//字符串必须有换行符"\n"
	// 	TCHAR str[]="Line1: Hello, FatFs***\n";
	// 	//不会写入结束符"\0"
	// 	f_puts(str, &test_file);
	// 	GUA_LOGI("Write file OK\r\n");
	// }
	// else
	// {
	// 	GUA_LOGE("Open file error, error code: %d\r\n", res);
	// }
	// //使用完毕关闭文件
	// f_close(&test_file);
}
FIL	file_fd;
/*读取一个文本文件的内容*/
uint32_t FatFs_ReadTXTFile(TCHAR *filename, uint8_t *buf)
{

	uint32_t fileSize = 0;
	UINT bytes_read;

	GUA_LOGI("read file [%s]\r\n", filename);

	FRESULT res = f_open(&file_fd, filename, FA_READ); //以只读方式打开文件
	if(res == FR_OK) {
		fileSize = f_size(&file_fd);
		GUA_LOGI("f_read [%d]\r\n", fileSize);

		buf = (uint8_t *)malloc(64800);
		if (buf == NULL) {
			GUA_LOGE("malloc error\r\n");
			return -1;
		}
		GUA_LOGI("open file [%s] ok\r\n", filename);

		// 读取文件内容
		res = f_read(&file_fd, (void* )(buf+4), fileSize, &bytes_read);
		if (res != FR_OK || bytes_read != fileSize) {
			free(buf);
			buf = NULL;
			f_close(&file_fd);
			GUA_LOGE("File read error\r\n");
			return -1;
		}
		GUA_LOGI("read file [%s] [%d]ok\r\n", bytes_read);

	} else if(res == FR_NO_FILE) {
		GUA_LOGE("File does not exist\r\n");
	} else {
		GUA_LOGE("f_open() error, error code: %d\r\n", res);
	}

	f_close(&file_fd);

	return fileSize;
}


/*扫描和显示指定目录下的文件和目录*/
void FatFs_ScanDir(const TCHAR* PathName)
{
	DIR dir;					//目录对象
	FILINFO fno;				//文件信息
	FIL file_fd;
	uint32_t fileSize;
	FRESULT res = f_opendir(&dir, PathName);
	if(res != FR_OK) {
		f_closedir(&dir);
		GUA_LOGE("f_opendir() error,error code: %d\r\n", res);
		return;
	}

	GUA_LOGI("All entries in dir: %s\r\n", PathName);
	while(1) {
		res = f_readdir(&dir, &fno);

		if(res != FR_OK || fno.fname[0] == 0) //文件名为空表示没有多的项可读了
			break;
		if(fno.fattrib & AM_DIR){ //如果是一个目录
			GUA_LOGI("DIR: %s\r\n", fno.fname);
		} else {
			res = f_open(&file_fd, fno.fname, FA_READ);
			if (res == FR_OK) {
				fileSize = f_size(&file_fd);
				f_close(&file_fd);
				GUA_LOGI("FILE: %s %d Byte\r\n",fno.fname, fileSize);
			}
		}
	}

	f_closedir(&dir);
}


/*获取一个文件的文件信息*/
void FatFs_GetFileInfo(TCHAR *filename)
{
	FILINFO fno;
	FRESULT fr = f_stat(filename, &fno);
	if(fr == FR_OK)
	{
		GUA_LOGI("File size(bytes) = %ld\r\n", fno.fsize);
		GUA_LOGI("File attribute = 0x%x\r\n", fno.fattrib);
		GUA_LOGI("File Name = %s\r\n", fno.fname);
		GUA_LOGI("File data = %d/%d/%d\r\n", ((fno.fdate>>9)&0x7F)+1980, (fno.fdate>>5)&0xF, fno.fdate&0x1F);
		GUA_LOGI("File time = %d:%d:%d\r\n", (fno.ftime>>11)&0x1F, (fno.ftime>>5)&0x3F, fno.ftime&0x1F);
	}

	else if (fr == FR_NO_FILE) //如果没有该文件
		GUA_LOGE("File does not exist\r\n");
	else
		GUA_LOGE("f_stat() error, error code: %d\r\n", fr);
}


/*删除文件*/
void FatFs_DeleteFile(TCHAR *filename)
{
	FIL	file;
	//打开文件
	FRESULT res = f_open(&file, filename, FA_OPEN_EXISTING);
	if(res == FR_OK) {
		f_close(&file);
	}

	//删除文件
	res = f_unlink(filename);
	if(res != FR_OK) {
		GUA_LOGE("delete error![%d]\r\n", res);
	}
}
