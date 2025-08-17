#ifndef USART_DEVICE_H
#define USART_DEVICE_H
#include "main.h"
#include "stdio.h"
#include "usart.h"


// 打印输出参考：https://blog.csdn.net/KindBitch/article/details/122443446?spm=1001.2014.3001.5506
//调试打印开关

// 参考 https://blog.csdn.net/dayancn/article/details/80021273
#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__) // 只打印单文件相对路径，避免文件字符路径较长，但是会导致strrchr 多次处理延时

#define __DEBUG 1
#if __DEBUG == 1
#define GUA_LOGN              debug_out
#define GUA_LOGI(format, ...) debug_out("\033[32m["__FILE__":%d] "format"", __LINE__, ##__VA_ARGS__)
#define GUA_LOGW(format, ...) debug_out("\033[33m["__FILE__":%d] "format"", __LINE__, ##__VA_ARGS__)
#define GUA_LOGE(format, ...) debug_out("\033[31m["__FILE__":%d] "format"", __LINE__, ##__VA_ARGS__)
#elif __DEBUG == 2
#define GUA_LOGI(format, ...) debug_out("\033[32m%s:%d "format"", __FILENAME__, __LINE__, ##__VA_ARGS__)
#define GUA_LOGW(format, ...) debug_out("\033[33m%s:%d "format"", __FILENAME__, __LINE__, ##__VA_ARGS__)
#define GUA_LOGE(format, ...) debug_out("\033[31m%s:%d "format"", __FILENAME__, __LINE__, ##__VA_ARGS__)
#elif __DEBUG == 3
#define GUA_LOGI(format, ...) printf("\033[32m["__FILE__" Line: %d] %s: "format"\033[32;0m\n", __LINE__, __func__, ##__VA_ARGS__)
#define GUA_LOGW(format, ...) printf("\033[33m["__FILE__" Line: %d] %s: "format"\033[32;0m\n", __LINE__, __func__, ##__VA_ARGS__)
#define GUA_LOGE(format, ...) printf("\033[31m["__FILE__" Line: %d] %s: "format"\033[32;0m\n", __LINE__, __func__, ##__VA_ARGS__)
#elif __DEBUG == 4
#define GUA_LOGI(format, ...) printf("\033[32m["__FILE__" Line: %d] "format"\033[32;0m\n", __LINE__, ##__VA_ARGS__)
#define GUA_LOGW(format, ...) printf("\033[33m["__FILE__" Line: %d] "format"\033[32;0m\n", __LINE__, ##__VA_ARGS__)
#define GUA_LOGE(format, ...) printf("\033[31m["__FILE__" Line: %d] "format"\033[32;0m\n", __LINE__, ##__VA_ARGS__)
#elif __DEBUG == 5
#define GUA_LOGI(format, ...) printf("\033[32m["__FILE__": %d] "format"\033[32;0m\r\n", __LINE__, ##__VA_ARGS__)
#define GUA_LOGW(format, ...) printf("\033[33m["__FILE__": %d] "format"\033[32;0m\r\n", __LINE__, ##__VA_ARGS__)
#define GUA_LOGE(format, ...) printf("\033[31m["__FILE__": %d] "format"\033[32;0m\r\n", __LINE__, ##__VA_ARGS__)
#else
#define GUA_LOGI(format, ...) DEBUG_ERROR("\033[32m["__FILE__": %d] "format"\033[32;0m", __LINE__, ##__VA_ARGS__)
#define GUA_LOGW(format, ...) DEBUG_ERROR("\033[33m["__FILE__": %d] "format"\033[32;0m", __LINE__, ##__VA_ARGS__)
#define GUA_LOGE(format, ...) DEBUG_ERROR("\033[31m["__FILE__": %d] "format"\033[32;0m", __LINE__, ##__VA_ARGS__)

#endif



int fputc(int ch, FILE *f);
/*****************************************************************************
* @file   usart_device.c
* @brief  初始化串口和串口DMA中断
* @author Tianxiaogua
* @date   2023-04
****************************************************************************/
void strat_usart_interupt(void);

/*****************************************************************************
 * @file   usart_device.c
 * @brief  ͨDMA发送数据
 * @author Tianxiaogua
 * @date   2023-04
 ****************************************************************************/
void usart_driver_Transmit(uint8_t *buf, uint32_t len);
void usart2_driver_Transmit(uint8_t *buf, uint32_t len);

void debug_init(int32_t SoftVersion, int32_t HardVersion, char  *BuildDataStr , char *BuildTimeStr);
void debug_out(const char* fmt, ...);

#endif

