#ifndef driver_key_c
#define driver_key_c
#include "driver_tool.h"
#include "driver_usart.h"



//设计扫描为10ms定时
#define KEY_CYCLE

#ifdef KEY_CYCLE
//设计扫描为10ms定时
// #define	KEY_TIME_IDLE		40		//按键动作空闲时间
// #define	KEY_TIME_CONTINUS	50		//按键动作持续时间
// #define	KEY_TIME_OUT		200	    //按键超时
#define	KEY_TIME_IDLE		25		//按键动作空闲时间
#define	KEY_TIME_CONTINUS	30		//按键动作持续时间
#define	KEY_TIME_OUT		200	    //按键超时
#endif

//事件类型
#define EVENT_NONE_CLICK	0x00	//无动作
#define EVENT_SHORT_CLICK	0x01	//短按
#define EVENT_DOUBLE_CLICK	0x02	//连击
#define EVENT_LONG_CLICK	0x03	//长按

//按键状态
#define KEY_STATE_IDLE		0x00	//空闲
#define KEY_STATE_PRESS		0x01	//按下
#define KEY_STATE_RELEASE	0x02	//松开




typedef enum {
	KEY_EVENT_UP_ID = 0,
	KEY_EVENT_DOWN_ID,
	KEY_EVENT_ENTER_ID,
}KEY_EVENT_ID;

typedef enum {
	KEY_TYPE_NONE = 0,
	KEY_TYPE_CENTER,
	KEY_TYPE_UP,
	KEY_TYPE_DOWN,
	KEY_TYPE_UP_LONG,
	KEY_TYPE_DOWN_LONG,
}KEY_TYPE;


typedef void (*key_callback)(KEY_EVENT_ID id);

typedef struct{
	struct{
		uint8 check		    :1;		//查询标志
		uint8 key_state	    :2;		//单次按键动作【0：无动作/1：按下/2：松开】
		uint8 once_event	:1;		//一次完整按键事件，置1时可以进行事件识别，必须手动清零
		uint8 press_time	:1;		//单次按键动作持续时间【0：短按/1：长按】
	}flag;

	uint8 event_current_type	:4;	//当前按键事件类型【00：无动作】【01：短按】【10：连击】【11：长按】
	uint8 event_previous_type	:4;	//之前按键事件类型，需手动更新

	uint8	press_cnt;				//按下次数，复位值为1，最大连击次数为256次

	uint16 time_idle;				//按键空闲时间计数器
	uint16 time_continus;			//按键动作持续时间计数器

	uint8 histery_key;
}KEY_PROCESS_TypeDef;

typedef struct
{
	KEY_TYPE key_valye; // 长按 连按 一次
	key_callback callback;
}KEY_DATA;



void key_Process(KEY_PROCESS_TypeDef *key);
void key_config_init(KEY_PROCESS_TypeDef *key);
uint8 key_scan(KEY_PROCESS_TypeDef *key);

int32 key_queue_init(key_callback callback);
int32 key_queue_set(KEY_DATA *data);
int32 key_queue_get(KEY_DATA *data);

#endif


