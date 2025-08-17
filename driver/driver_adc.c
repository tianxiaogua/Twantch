#include "driver_adc.h"
#include "adc.h"
#include "usart.h"
#include "gpio.h"
#include "driver_tool.h"

//uint32_t driver_adc()
//{
//	HAL_ADC_Start(&hadc1);    //启动ADC转换
//	HAL_ADC_PollForConversion(&hadc1,1); //等待转换完成，10ms表示超时时间
//	uint32_t AD_Value = HAL_ADC_GetValue(&hadc1);  //读取ADC转换数据（12位数据）
//	//GUA_LOGI("ADC1_IN1 ADC value: %d\r\n",AD_Value);
//	float Vol_Value = AD_Value*(3.3/4096);  //AD值乘以分辨率即为电压值
//	//GUA_LOGI("ADC1_IN1 VOL value: %.2fV\r\n",Vol_Value);
//	return 1;
//}


////获取电压
//float ADC_Read(uint32 channel)
//{
//	HAL_ADC_Start(&hadc1);    //启动ADC转换
//	HAL_ADC_PollForConversion(&hadc1,channel); //等待转换完成，10ms表示超时时间
//	uint32_t AD_Value = HAL_ADC_GetValue(&hadc1);  //读取ADC转换数据（12位数据）
//	//("V:%03f\r\n", AD_Value*(3.3/4096));
//	float Vol_Value = AD_Value*(3.3/4096);  //AD值乘以分辨率即为电压值
//	return Vol_Value;
//}

//float get_voltage(uint32_t Channel)
//{
//	ADC_ChannelConfTypeDef sConfig = {0};
//	sConfig.Channel = Channel;                                         /* 通道 */
//	sConfig.Rank = ADC_REGULAR_RANK_1;
//	sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;                  /* 采样时间 */
//	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
//	{
//		Error_Handler();
//	}
//	HAL_ADC_Start(&hadc1);
//	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
//	uint16_t AD_Value = (uint16_t)HAL_ADC_GetValue(&hadc1);

//	// GUA_LOGI("Channel:%d AD_Value %d V:%.3f\r\n",Channel, AD_Value, AD_Value*(3.3/4096));
//	float Vol_Value = AD_Value*(3.3/4096);  //AD值乘以分辨率即为电压值

//	return Vol_Value;

//}


#define ARRAY_DIM(a) (sizeof(a) / sizeof((a)[0]))
static int toPercentage(int voltage)
{
	int i = 0;
	int16 Battery_Level_Percent_Table[11] = {3000, 3650, 3700, 3740, 3760, 3795, 3840, 3910, 3980, 4070, 4150};
	if(voltage < Battery_Level_Percent_Table[0])
		return 0;

	for(i=0; i<ARRAY_DIM(Battery_Level_Percent_Table); i++){
		if(voltage < Battery_Level_Percent_Table[i])
			return i*10 - (10UL * (int)(Battery_Level_Percent_Table[i] - voltage)) /
			(int)(Battery_Level_Percent_Table[i] - Battery_Level_Percent_Table[i-1]);;
	}
	return 100;
}


int32 adc_get_battery(void)
{
	uint16_t ADC_Value_BATTERY;

	HAL_ADC_Start(&hadc1);  //打开ADC1

	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY); //

	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
	{
		ADC_Value_BATTERY = HAL_ADC_GetValue(&hadc1); //读取ADC值存放在ADC_Value_BATTERY中

		return toPercentage(2*ADC_Value_BATTERY*3.3f/4096*1000);
	}

	return REV_ERR;
}
