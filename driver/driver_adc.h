#ifndef driver_adc_h
#define driver_adc_h
#include "driver_tool.h"

/*
	https://zhuanlan.zhihu.com/p/355109203
*/

#define LOW_POWER_VOLTAGE 3.5

//获取电压
float get_voltage(uint32 channel);
int32 adc_get_battery(void);

#endif
