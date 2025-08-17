#include "bt24.h"
#include "driver_tool.h"
#include "main.h"
#include "usart.h"
#include "driver_usart.h"
#include "driver_delay.h"

// #define FACTORY_INIT
#define BT24_RECV_TIME_OUT 200 // 单位毫秒

#define BT24_AT_REST "Power On"
#define BT24_AT_NOTI "AT+NOTI"
#define BT24_AT_CONNECTED "OK+CONN"

static void bt24_rest(void)
{
    uint32 temp = 0;

    GUA_LOGI("rest bt23\r\n");
    HAL_GPIO_WritePin(BLE_REST_GPIO_Port, BLE_REST_Pin, GPIO_PIN_SET);
    delay_ms(100);
    HAL_GPIO_WritePin(BLE_REST_GPIO_Port, BLE_REST_Pin, GPIO_PIN_RESET);
    delay_ms(100);

    while (1) {
        if (Rx2_Flag) {  // Receive flag
            Rx2_Flag=0;	// clean flag
            HAL_UART_Transmit(&huart1, Rx2_Buf, Rx2_Len, 0xFFFF);

            if(strstr((char *)Rx2_Buf, BT24_AT_REST)!=NULL) {
                break;
            } else {
                GUA_LOGE("not found!\n");
            }
        }
        delay_ms(1);
        temp++;
        if (temp > BT24_RECV_TIME_OUT) {
            GUA_LOGI("wait rest timeout...");
            break;;
        }
    }
}


#ifdef FACTORY_INIT
// 设置连接蓝牙通知状态
static void bt24_set_note_connect(int8 set_data)
{
    uint32 temp = 0;
    char str[32] = {0};

    sprintf(str, "%s%s", BT24_AT_NOTI, set_data);
    HAL_UART_Transmit(&huart2, (const uint8 *)str, strlen(str), 0xFFFF);
    HAL_UART_Transmit(&huart1, (const uint8 *)str, strlen(str), 0xFFFF);

    temp = 0;
    while (1) {
        if(Rx2_Flag){  // Receive flag
			Rx2_Flag=0;	// clean flag
            HAL_UART_Transmit(&huart1, Rx2_Buf, Rx2_Len, 0xFFFF);
            if(strstr((char *)Rx2_Buf,"OK")!=NULL) {
                break;
            } else {
                GUA_LOGE("not found!\n");
            }
        }
        delay_ms(1);
        temp++;
        if (temp > BT24_RECV_TIME_OUT) {
            GUA_LOGI("wait timeout...");
            return -1;
        }
    }
}
#endif

static int32 bt24_wait_connect(void)
{
    uint32 temp = 0;

    while (1) {
        if(Rx2_Flag){  // Receive flag
            Rx2_Flag=0;	// clean flag
            HAL_UART_Transmit_DMA(&huart1, Rx2_Buf, Rx2_Len);
            if(strstr((char *)Rx2_Buf, BT24_AT_CONNECTED)!=NULL) {
                break;
            } else {
                GUA_LOGE("not found!\n");
            }
        }
        delay_ms(1);
        temp++;
        if (temp > BT24_RECV_TIME_OUT) {
            GUA_LOGI("wait timeout...");
            return REV_ERR;
        }
    }

    return REV_OK;
}

int32 init_bt24(void)
{
    uint32 temp = 0;

    bt24_rest();
    bt24_wait_connect();

    while (1) {
        if(Rx_Flag){  // Receive flag
            Rx_Flag=0;	// clean flag
            HAL_UART_Transmit_DMA(&huart2, Rx_Buf, Rx_Len);
        }

        if(Rx2_Flag){  // Receive flag
            Rx2_Flag=0;	// clean flag
            HAL_UART_Transmit_DMA(&huart1, Rx2_Buf, Rx2_Len);
        }
    }
}