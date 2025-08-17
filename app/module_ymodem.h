#ifndef MODEL_YMODEM_H
#define MODEL_YMODEM_H


#include "main.h"
#include "usart.h"
#include "stdio.h"
#include "driver_tool.h"

#define	SOH	0x01
#define STX	0x02
#define ACK	0x06
#define NAK	0x15
#define EOT	0x04
#define C1	0x43

typedef int32 (*storage_data_cb)(const char* filename, uint8 *data, uint32 size);
typedef int32 (*ymodem_handel_cb)(storage_data_cb callback);


int32 init_ymodem(void);
int32 deinit_ymodem(void);
int32 start_ymodem_serve(storage_data_cb callback);


#endif
