#ifndef FILE_OPERATE_H
#define FILE_OPERATE_H

#include "main.h"
#include "FatFs.h"
#include "stdio.h"

/*定义自己的存储设备*/

/*用户存储设备扇区字节数*/
#define User_Sector 4096
/*用户存储设备FatFS对象*/
#define User_FatFs 	USERFatFS
/*用户存储设备卷路径*/
#define User_SDPath USERPath
/*用户存储设备初始化类型*/
#define User_FatType FM_FAT

/*函数声明*/
void Mount_FatFs(void);
void FatFs_GetDiskInfo(void);
void FatFs_ScanDir(const TCHAR* PathName);
uint32_t FatFs_ReadTXTFile(TCHAR *filename, uint8_t *buf);
void FatFs_WriteTXTFile(TCHAR *filename,uint16_t year, uint8_t month, uint8_t day);
void FatFs_GetFileInfo(TCHAR *filename);
void FatFs_DeleteFile(TCHAR *filename);
void FatFs_PrintfFileDate(WORD date, WORD time);

#endif
