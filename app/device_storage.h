#ifndef DEVICE_STORAGE_H
#define DEVICE_STORAGE_H

#include "driver_tool.h"

#define STORAGE_WORD_STOCK    0x00000000  // 字库 word stock

int32 device_storage_init(void);

int32 device_storage_continuou_4096_write(uint32 start_address, uint8 *buffer);

int32 device_storage_read(uint32 start_address, uint8 *buffer, uint32 buf_len);

#endif

