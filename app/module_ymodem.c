#include "usart.h"
#include "module_ymodem.h"
#include "driver_tool.h"
#include "driver_delay.h"
#include "driver_usart.h"

#define y_debug_out           GUA_LOGE
#define YMODEM_RECV_TIMEOUT  2000
#define YMODEM_ORDER_STEUP   "rb -E"
#define YMODEM_ORDER_C1      0x43
#define YMODEM_ORDER_ACK     0x06
#define YMODEM_ORDER_EOT     0x04
#define	YMODEM_ORDER_SOH	0x01  // 128字节数据包
#define	YMODEM_ORDER_STX	0x02  // 1024字节数据包
#define	YMODEM_ORDER_NAK	0x15
#define	YMODEM_ORDER_CAN	0x18
#define STX	0x02
#define YMODEM_DATA_LEN_128 128
#define YMODEM_DATA_LEN_1024 1024


typedef enum {
    YMODEM_BEGIN = 0,
    YMODEM_SETUP,
	YMODEM_RECV_DATA,
	YMODEM_RECV_END,
	YMODEM_RECV_DISCONNECT,
} YMODEM_STEP;



typedef struct
{
	uint16 ymodel_status;
	uint8 recv_buf[Rx_Max];
	char filename[16];
	uint32 ymodem_data_len;
	uint8 tar_header;
	ymodem_handel_cb callback;
} YMODEM_CTL;

YMODEM_CTL *p_ymodem_ctl = NULL;

//直接计算法计算crc
uint16 do_crc(uint8 *ptr, int len)
{
    uint32 i;
    uint16 crc = 0x0000;

    while(len--)
    {
        crc ^= (uint16)(*ptr++) << 8;
        for (i = 0; i < 8; ++i)
        {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc <<= 1;
        }
    }

    return crc;
}



static int32 recv_usart_data(uint8 *buffer, uint32 buffer_len)
{
	// memset(buffer, 0, buffer_len);
	if(Rx_Flag) {
		Rx_Flag=0;	// 清除串口中断的标志
		memcpy(buffer, Rx_Buf, Rx_Len);
		return REV_OK;
	}
	return REV_ERR;
}


static int32 send_usart_order(uint8 order)//发送指令
{
	return HAL_UART_Transmit_DMA(&huart1, &order, 1);
}


// https://blog.csdn.net/u012028275/article/details/112067463
// CRC16-XMODEM校验（x16+x12+x5+1）的高八位和低八位
static int32 ymodem_setup(uint8 *buffer, uint32 buffer_len, uint32 timeout)
{
	int32 i = 0;

	while (1) {
		if (recv_usart_data(buffer, buffer_len) == REV_OK) {
            if(strstr((char *)buffer, YMODEM_ORDER_STEUP) != NULL) {
                return REV_OK;
            } else {
                return REV_ERR;
            }
        }

		i++;
		if (i > timeout) {
			// y_debug_out("ymodem steup timeout!\r\n");
			return REV_ERR;
		}
        delay_ms(1);
	}
}


static int32 ymodem_recv_first_frame(uint8 *buffer, uint32 buffer_len, uint32 timeout)
{
	int32 i = 0;

	while (1) {
		if (recv_usart_data(buffer, buffer_len) == REV_OK) {
            return buffer[0];
        }

		i++;
		if (i > timeout) {
			y_debug_out("ymodem steup timeout!\r\n");
			return REV_ERR;
		}
        delay_ms(1);
	}
}


static int32 ymodem_dmessage_first_frame(uint8 *buffer, uint32 buffer_len, uint8 *file_name)
{
//	int32 temp = 0;
	uint16 crc_rev = 0;

	crc_rev = do_crc(buffer+3, buffer_len); // CRC检验只校验数据部分，即除去前三位
	if (((crc_rev >> 8) & 0xFF) != buffer[131] || (crc_rev & 0xFF) != buffer[132]) {
		y_debug_out("ymodem crc erroe! [0x%04x][0x%02x][%02x] [0x%02x][0x%02x]\r\n",
			crc_rev, ((crc_rev >> 8) & 0xFF), (crc_rev & 0xFF), buffer[131] , buffer[132]);
		y_debug_out("\r\n");
		for (int i=0; i<16; i++) {
			y_debug_out("%02x \r\n", buffer[i]);
			// y_debug_out("%d: 0x%02x\r\n", i, buffer[i]);
		}

		return REV_ERR;
	}

	strcpy((char *)file_name, (char *)(buffer+3));
	// while (1) {
	// 	GUA_LOGI("file_name: [%s] %d\r\n", file_name, buffer_len);
	// 	for (int i=0; i<buffer_len; i++) {
	// 		GUA_LOGI("0x%02x\r\n", buffer[i]);
	// 	}
	// 	delay_ms(2000);
	// }

	return REV_OK;
}


static int32 ymodem_recv_data_frame(uint8 *buffer, uint32 buffer_len,  uint32 timeout, uint32 tar_len)
{
	int32 i = 0;
	uint16 crc_rev = 0;

	while (1) {
		if (recv_usart_data(buffer, buffer_len) == REV_OK) {
			crc_rev = do_crc(buffer+3, tar_len); // CRC检验只校验数据部分，即除去前三位
			if (((crc_rev >> 8) & 0xFF) != buffer[131] || (crc_rev & 0xFF) != buffer[132]) {
				y_debug_out("ymodem crc erroe! [0x%04x][0x%02x][%02x] [0x%02x][0x%02x]\r\n",
					crc_rev, ((crc_rev >> 8) & 0xFF), (crc_rev & 0xFF), buffer[131] , buffer[132]);
				y_debug_out("\r\n");
				for (int i=0; i<Rx_Max; i++) {
					y_debug_out("%02x ", buffer[i]);
					// y_debug_out("%d: 0x%02x\r\n", i, buffer[i]);
				}
				y_debug_out("\r\n");

				return REV_ERR;
			}


			return buffer[0];
        }

		i++;
		if (i > timeout) {
			y_debug_out("ymodem steup timeout!\r\n");
			return REV_ERR;
		}
        delay_ms(1);
	}
}





static int32 ymodem_recv_end_frame(uint8 *buffer, uint32 buffer_len, uint32 timeout, uint8 tar_header)
{
	int32 i = 0;

	while (1) {
		if (recv_usart_data(buffer, buffer_len) == REV_OK) {
            if(buffer[0] == tar_header) {
                return REV_OK;
            } else {
                return REV_ERR;
            }
        }

		i++;
		if (i > timeout) {
			y_debug_out("ymodem steup timeout!\r\n");
			return REV_ERR;
		}
        delay_ms(1);
	}
}


static int32 ymodem_disconnect(uint8 *buffer, uint32 buffer_len, uint32 timeout, uint8 tar_header)
{
	int32 i = 0;

	while (1) {
		if (recv_usart_data(buffer, buffer_len) == REV_OK) {
            if(buffer[0] == tar_header) {
                return REV_OK;
            } else {
				y_debug_out("ymodem error! ymodem_disconnect[0x%02x]!\r\n", buffer[0]);
                return REV_ERR;
            }
        }

		i++;
		if (i > timeout) {
			y_debug_out("ymodem steup timeout!\r\n");
			return REV_ERR;
		}
        delay_ms(1);
	}
}



// 参考：https://zhuanlan.zhihu.com/p/654782539
static int32 ymodem_handel(storage_data_cb callback)
{
	int32 rev = 0;
	int32 flag = 0;
	uint16 i = 0;

	while (1) {
		switch (p_ymodem_ctl->ymodel_status) {
			case YMODEM_BEGIN: {
					rev = ymodem_setup(p_ymodem_ctl->recv_buf, Rx_Max, YMODEM_RECV_TIMEOUT);
					if (rev == REV_OK) {
						p_ymodem_ctl->ymodel_status = YMODEM_SETUP;
					}

					send_usart_order(YMODEM_ORDER_C1);
					delay_ms(1);
					break;
				}


			case YMODEM_SETUP: {
					rev = ymodem_recv_first_frame(p_ymodem_ctl->recv_buf, Rx_Max, YMODEM_RECV_TIMEOUT);
					if (rev == YMODEM_ORDER_SOH) {
						p_ymodem_ctl->tar_header = YMODEM_ORDER_SOH;
						p_ymodem_ctl->ymodem_data_len = YMODEM_DATA_LEN_128;

					} else if (rev == YMODEM_ORDER_STX) {
						p_ymodem_ctl->tar_header = YMODEM_ORDER_STX;
						p_ymodem_ctl->ymodem_data_len = YMODEM_DATA_LEN_1024;

					} else if (rev == 0) {
						delay_ms(1);
						break;
					} else {
						y_debug_out("ymodem_recv_first_frame error[%d]\r\n", rev);
						return REV_ERR;
					}


					rev = ymodem_dmessage_first_frame(p_ymodem_ctl->recv_buf, p_ymodem_ctl->ymodem_data_len, p_ymodem_ctl->filename);
					if (rev != REV_OK) {
						y_debug_out("ymodem_dmessage_first_frame error\r\n");
						return REV_ERR;
					}

					p_ymodem_ctl->ymodel_status = YMODEM_RECV_DATA;
					send_usart_order(YMODEM_ORDER_ACK);
					break;
				}

			case YMODEM_RECV_DATA: {
					rev = ymodem_recv_data_frame(p_ymodem_ctl->recv_buf, Rx_Max, YMODEM_RECV_TIMEOUT, p_ymodem_ctl->ymodem_data_len);
					if (rev == p_ymodem_ctl->tar_header) {
						// rev = strong_recv_data(callback, start_address, p_ymodem_ctl->recv_buf+3, p_ymodem_ctl->ymodem_data_len);
						rev = callback(p_ymodem_ctl->filename, p_ymodem_ctl->recv_buf+3, p_ymodem_ctl->ymodem_data_len);
						if (rev != REV_OK) {
							while (i<20) {
								i++;
								y_debug_out("ymodem recv data error\r\n");
								delay_ms(100);

							}
							y_debug_out("ymodem recv data error\r\n");
							// return REV_ERR;
						}
						delay_ms(1);
						send_usart_order(YMODEM_ORDER_ACK);

					} else if (rev ==YMODEM_ORDER_EOT) { //数据结束帧
						p_ymodem_ctl->ymodel_status = YMODEM_RECV_END;
						delay_ms(1);
						send_usart_order(YMODEM_ORDER_NAK);

					} else {
						send_usart_order(YMODEM_ORDER_CAN);
						i = 0;
						while (i<20) {
							i++;
							y_debug_out("ymodem recv data error???[%x]\r\n", p_ymodem_ctl->recv_buf[0]);
							delay_ms(100);
						}
						y_debug_out("ymodem recv data error\r\n");
						return REV_ERR;
					}

					break;
				}

			case YMODEM_RECV_END: {
					rev = ymodem_recv_end_frame(p_ymodem_ctl->recv_buf, Rx_Max, YMODEM_RECV_TIMEOUT, YMODEM_ORDER_EOT);
					if (rev != REV_OK) {
						y_debug_out("ymodem_recv_end_frame error\r\n");
						return REV_ERR;
					}

					send_usart_order(YMODEM_ORDER_ACK);
					delay_ms(1);
					if (recv_usart_data(p_ymodem_ctl->recv_buf, Rx_Max) == REV_OK) {
						// y_debug_out("ymodem_disconnect error[0x%02x]\r\n", p_ymodem_ctl->recv_buf[0]);
					}
					send_usart_order(YMODEM_ORDER_C1);
					p_ymodem_ctl->ymodel_status = YMODEM_RECV_DISCONNECT;
				}


			case YMODEM_RECV_DISCONNECT: {
					rev = ymodem_disconnect(p_ymodem_ctl->recv_buf, Rx_Max, YMODEM_RECV_TIMEOUT, p_ymodem_ctl->tar_header);
					if (rev != REV_OK) {
						y_debug_out("ymodem_disconnect error\r\n");
						return REV_ERR;
					}

					send_usart_order(YMODEM_ORDER_ACK);
					y_debug_out("ymodem recv successful\r\n");
					flag = 1;
					break;
				}

			default:
				break;
		}

		if (flag == 1) {
			break;
		}
	}

	return REV_OK;
}

int32 init_ymodem(void)
{
	if (p_ymodem_ctl == NULL) {
		p_ymodem_ctl = (YMODEM_CTL *) malloc(sizeof(YMODEM_CTL));
		if (p_ymodem_ctl == NULL) {
			y_debug_out("malloc error\r\n");
			return REV_ERR;
		}
		memset(p_ymodem_ctl, 0, sizeof(YMODEM_CTL));
	}
	p_ymodem_ctl->callback = ymodem_handel;
}


int32 deinit_ymodem(void)
{
	free(p_ymodem_ctl);
	p_ymodem_ctl = NULL;
}

int32 start_ymodem_serve(storage_data_cb callback)
{
	return p_ymodem_ctl->callback(callback);
}