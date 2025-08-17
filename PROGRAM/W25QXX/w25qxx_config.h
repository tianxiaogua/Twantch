#ifndef __W25QXX_CONFIG_H__
#define __W25QXX_CONFIG_H__
#include "driver_usart.h"
#include "driver_tool.h"
#define _W25QXX_SPI                   hspi1
#define _W25QXX_CS_GPIO               FLASH_CS_GPIO_Port
#define _W25QXX_CS_PIN                FLASH_CS_Pin
#define _W25QXX_USE_FREERTOS          0
#define _W25QXX_DEBUG                 1
#define _w25Qxx_print                 GUA_LOGW

#define W25Q128_DEFINE                0x17EF





#endif
// 参考：https://www.cnblogs.com/kdsj/p/15371137.html

