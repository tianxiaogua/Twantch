#ifndef __APP_H
#define __APP_H



/*******************************************
* @function: 	游戏
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.25
*******************************************/

void APP_GAME(void);
	

extern unsigned char Sound_switch;

/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/
void clock_function(void);


/*******************************************
* @function: 	闹钟的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/
void light_function(void);
	

/*******************************************
* @function: 	设置的功能
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.3
*******************************************/
void setting_function(void);
	
	
	
/*******************************************
* @function: 	后台对闹钟和陀螺仪的计步器进行检测
* @input:			无
* @return:		无
* @author:		田小花
* @time:			2020.10.5
*******************************************/
void Background_detection(unsigned char switch_value);



#endif


