#include "driver_pwm.h"

/*PWM计算方式
1、在Configuration中设置预分频系数为72-1，自动重装值为500-1，
2、则PWM的输出频率为72000000/72/500=2000Hz。
3、根据需要配置PWM有效极性

常见配置：
2Hz LED
72000000/7200/5000=2Hz

100Hz传感器检测频率
72000000/7200/100=100Hz
*/

/*******************************************************************************
 * @file   motor_control.c
 * @brief  初始化其他电机控制部分的PWM定时器
 * @author Tianxiaogua
 * @date   2023-04
 ******************************************************************************/
void init_PWM()
{
	// HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	// HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	// HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);    //修改占空比
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);    //修改占空比

	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_4, 1000);

//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
//
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);    //修改占空比
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0);    //修改占空比
}

/*******************************************************************************
 * @file   motor_control.c
 * @brief  设置PMW占空比
 * @author Tianxiaogua
 * @date   2023-04
 ******************************************************************************/
void set_pwm_channel_1(uint16_t duty)
{
	// if(duty>3600) duty = 3600;
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, duty);
}
void set_pwm_channel_2(uint16_t duty)
{
//	if(duty>3600) duty = 3600;
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, duty);
}
void set_pwm_channel_3(uint16_t duty)
{
//	if(duty>3600) duty = 3600;
	// __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, duty);
}

/*******************************************************************************
 * @file   motor_control.c
 * @brief  设置PMW占空比
 * @author Tianxiaogua
 * @date   2023-04
 ******************************************************************************/
void set_pwm_channel_1_2(uint16_t duty)
{
	if(duty>3600) duty = 3600;
//	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, duty);
}
void set_pwm_channel_2_2(uint16_t duty)
{
	if(duty>3600) duty = 3600;
//	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, duty);
}
void set_pwm_channel_3_2(uint16_t duty)
{
	if(duty>3600) duty = 3600;
//	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, duty);
}

void set_pwm_channel_2_1(uint16_t duty)
{
	// if(duty>3600) duty = 3600;
	// __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
}

void beep(uint16_t status)
{
	if(status){
		set_pwm_channel_1(150);
		HAL_Delay(50);
		set_pwm_channel_1(50);
		HAL_Delay(100);
		set_pwm_channel_1(0);
	}
	else {
		set_pwm_channel_1(0);
	}
}

