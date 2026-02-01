
#include "stdio.h"

#include "app.h"

#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "rtc.h"

#include "lcd.h"
#include "lcd_init.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mpu6050.h"
#include "sht30_i2c_drv.h"
#include "algorithm.h"
#include "MAX30102.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "gui_guider.h"           // Gui Guider 生成的界面和控件的声明
#include "events_init.h"          // Gui Guider 生成的初始化事件、回调函数

#include "driver_key.h"
#include "driver_usart.h"
#include "driver_gpio.h"
#include "driver_delay.h"
#include "driver_adc.h"
#include "driver_pwm.h"

#include "app_data_transmission.h"
#include "app_menu.h"
#include "file_operate.h"

#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mpu6050.h"

#define SoftVersion     0x000011      //software version, please use table seperata "#define" and "SoftVersion" and "//software version"
#define HardVersion     0x000021      //hardware version, please use table seperata "#define" and "HardVersion" and "//hardware version"
#define APP_JUMP_DELAY  (80)         // 界面跳转动画
char BuildDataStr[] = __DATE__;         //Build date
char BuildTimeStr[] = __TIME__;         //Build time


typedef enum {
    SCREEN_JUMP_MAIN   = 0,
    SCREEN_JUMP_MENU   = 1,
    SCREEN_JUMP_RATE   = 2,
    SCREEN_JUMP_SPO2   = 3,
    SCREEN_JUMP_SPORT  = 4,
    SCREEN_JUMP_CLOCK  = 5,
    SCREEN_JUMP_SECOND = 6,
    SCREEN_JUMP_SET    = 7,
    SCREEN_JUMP_LIGHT  = 8,
    SCREEN_JUMP_WEAT   = 9,
    SCREEN_JUMP_MSG    = 10,

    SCREEN_JUMP_MAX,
} SCREEN_JUMP;

typedef struct
{
    int32 histery_key;
    int32 key_status;
    KEY_PROCESS_TypeDef key_info;
}KEY_MANAGE;

typedef struct
{
    lv_ui  guider_ui; // 声明 界面对象
    uint8 screen_init; // 初始化状态
    RTC_DateTypeDef rtc_date;
    RTC_TimeTypeDef rtc_time;
    RTC_DateTypeDef rtc_date_his;
    RTC_TimeTypeDef rtc_time_his;
    uint16 battery_percent;
    uint16 battery_percent_his;
    SCREEN_JUMP screen_jump_id;
    uint16 menu_jump;
}DISPLAY_MANAGE;

DISPLAY_MANAGE g_dis = {0};

static int32 app_change_display_time(lv_obj_t * obj, uint8 time);
static int32 app_updata_time(lv_ui *ui, uint8 hour, uint8 minutes);

int32 data[] = {123,122,22,154,14,13,124,124,233,23,11,44,22,44,22,4,77,5,6,12,43,44,134,123};

static void app_screen_update_table(lv_obj_t * obj, int32 *data, int32 count)
{
    lv_chart_set_point_count(obj, count);
    lv_chart_series_t * sc_chart = lv_chart_add_series(obj, lv_color_make(0xff, 0x00, 0x00), LV_CHART_AXIS_PRIMARY_Y);

    for (size_t i = 0; i < count; i++) {
        lv_chart_set_next_value(obj, sc_chart, data[i]);
    }
}


static void app_screen_update_sport(lv_ui *ui)
{
    // 步数
    lv_label_set_text(ui->sc_sport_label_2, "12");
    lv_bar_set_value(ui->sc_sport_bar_1, 19, LV_ANIM_ON);

    // 热量消耗
    lv_label_set_text(ui->sc_sport_label_4, "999K");
    lv_bar_set_value(ui->sc_sport_bar_2, 80, LV_ANIM_ON);

    // 活动时长
    lv_label_set_text(ui->sc_sport_label_6, "10min");
    lv_bar_set_value(ui->sc_sport_bar_3, 100, LV_ANIM_ON);
}

// 示例：在某个函数中更新时间
static uint8_t hour = 1;
static uint8_t min = 1;
static void update_hour_clock_label(void)
{
    char buf[16];
    hour = (hour % 24) + 1; // 简单递增
    snprintf(buf, sizeof(buf), "%d时", hour);
    lv_label_set_text(g_dis.guider_ui.sc_clock_label_2, buf);
}

static void update_min_clock_label(void)
{
    char buf[16];
    min = (min % 24) + 1; // 简单递增
    snprintf(buf, sizeof(buf), "%d分", min);
    lv_label_set_text(g_dis.guider_ui.sc_clock_label_2, buf);
}


static void update_ready_clock_label(void)
{
    char buf[16];
    snprintf(buf, sizeof(buf), "%02d:%02d", hour, min);
    lv_label_set_text(g_dis.guider_ui.sc_clock_label_2, buf);
}

typedef enum {
    CLOCK_FLAG_HOUR = 0, // 设置小时
    CLOCK_FLAG_MINUS = 1, // 设置分钟
    CLOCK_FLAG_READY = 2 // 设置完成
} MENU_CLOCK_JUMP;

static int32 clock_flag = CLOCK_FLAG_HOUR;


static void app_go_to_menu(void)
{
    KEY_DATA key_data;
    key_data.key_valye = KEY_TYPE_CENTER;
    key_queue_set(&key_data); // 手动更新按键事件
    GUA_LOGW("screen jump menu\r\n");
    setup_scr_sc_menu(&g_dis.guider_ui);
    app_menu_lvgl_setup(&g_dis.guider_ui, g_dis.guider_ui.sc_menu);
    lv_scr_load_anim(g_dis.guider_ui.sc_menu, LV_SCR_LOAD_ANIM_MOVE_RIGHT, APP_JUMP_DELAY, 0, true);
    g_dis.screen_jump_id = SCREEN_JUMP_MENU;
}

// 闹钟设置初始化界面
static void app_init_time_clock(void)
{
    switch (clock_flag) {
        case CLOCK_FLAG_HOUR: {
            update_hour_clock_label();
            break;
        }
        case CLOCK_FLAG_MINUS: {
            update_min_clock_label();
            break;
        }
        case CLOCK_FLAG_READY: {
            update_ready_clock_label();
            break;
        }
    }
}

static void app_set_time_clock(int32 key_type, int32 key_event)
{
    switch (clock_flag) {
        case CLOCK_FLAG_HOUR: {
            if (key_type != KEY_EVENT_ENTER_ID) { // 如果是上下按钮
                if (key_event == KEY_TYPE_UP || key_event == KEY_TYPE_UP_LONG) {
                    update_hour_clock_label();
                    GUA_LOGW("SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK\r\n");
                } else if (key_event == KEY_TYPE_DOWN || key_event == KEY_TYPE_DOWN_LONG) {
                    update_hour_clock_label();
                    GUA_LOGW("SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK?????\r\n");
                }
                break;
            } else {
                if (key_event == EVENT_SHORT_CLICK) {
                    // 跳转到修改分钟
                    clock_flag = CLOCK_FLAG_MINUS;
                    update_min_clock_label();
                } else if (key_event == EVENT_LONG_CLICK) {
                    // 删除时间
                    update_hour_clock_label(); // 时钟数字清除
                } else if (key_event == EVENT_DOUBLE_CLICK) {
                    // 退出跳转到主界面
                    app_go_to_menu();
                }
            }
        }
        break;

        case CLOCK_FLAG_MINUS: {
            if (key_type != KEY_EVENT_ENTER_ID) { // 如果是上下按钮
                if (key_event == KEY_TYPE_UP || key_event == KEY_TYPE_UP_LONG) {
                    update_min_clock_label();
                    GUA_LOGW("SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK\r\n");
                } else if (key_event == KEY_TYPE_DOWN || key_event == KEY_TYPE_DOWN_LONG) {
                    update_min_clock_label();
                    GUA_LOGW("SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK SCREEN_JUMP_CLOCK?????\r\n");
                }
                break;
            } else {
                if (key_event == EVENT_SHORT_CLICK) {
                    // 跳转到准备就绪
                    clock_flag = CLOCK_FLAG_READY;
                    update_ready_clock_label();
                } else if (key_event == EVENT_LONG_CLICK) {
                    // 删除时间 跳转到调整时钟界面
                    clock_flag = CLOCK_FLAG_HOUR;
                    update_hour_clock_label();
                } else if (key_event == EVENT_DOUBLE_CLICK) {
                    // 退出跳转到主界面
                    app_go_to_menu();
                }
            }
        }
        break;

        case CLOCK_FLAG_READY: {
            if (key_type == KEY_EVENT_ENTER_ID) { // 如果是enter按钮
                if (key_event == EVENT_LONG_CLICK) {
                    // 删除时间 跳转到调整时钟界面
                    clock_flag = CLOCK_FLAG_HOUR;
                    update_hour_clock_label();
                } else if (key_event == EVENT_DOUBLE_CLICK) {
                    // 退出跳转到主界面
                    clock_flag = CLOCK_FLAG_READY;
                    app_go_to_menu();
                }
            }
        }
        default:
            break;
    }
}

// 菜单界面跳转接口
static void app_jump_menu(int32 key_type, int32 key_event)
{
    if (key_type == KEY_EVENT_ENTER_ID) {
        if (key_event == EVENT_DOUBLE_CLICK) {
            GUA_LOGI("screen jump main\r\n");
            setup_scr_sc_main(&g_dis.guider_ui);
            lv_scr_load_anim(g_dis.guider_ui.sc_main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, APP_JUMP_DELAY, 0, true);
            app_updata_time(&g_dis.guider_ui, g_dis.rtc_time.Minutes, g_dis.rtc_time.Seconds); // 更新显示时间
            g_dis.screen_jump_id = SCREEN_JUMP_MAIN;
        } else if (key_event == EVENT_SHORT_CLICK) {
            int32 jump_id = app_menu_lvgl_get_id();
            GUA_LOGW("get menu jump id[%d]\r\n", jump_id);
            switch (jump_id) {
                case SCREEN_MENU_RATE: {
                    GUA_LOGW("screen display rate\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_RATE;
                    setup_scr_sc_heart(&g_dis.guider_ui);
                    app_screen_update_table(g_dis.guider_ui.sc_heart_chart_1, data, 24);
                    lv_scr_load_anim(g_dis.guider_ui.sc_heart, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);

                    break;
                }

                case SCREEN_MENU_SPO2: {
                    GUA_LOGW("screen display oxy\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_SPO2;
                    setup_scr_sc_spo2(&g_dis.guider_ui);
                    app_screen_update_table(g_dis.guider_ui.sc_spo2_chart_1, data, 24);
                    lv_scr_load_anim(g_dis.guider_ui.sc_spo2, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    break;
                }

                case SCREEN_MENU_SPORT: {
                    GUA_LOGW("screen display sport\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_SPORT;
                    setup_scr_sc_sport(&g_dis.guider_ui);
                    app_screen_update_sport(&g_dis.guider_ui);
                    lv_scr_load_anim(g_dis.guider_ui.sc_sport, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    break;
                }

                case SCREEN_MENU_CLOCK: {
                    GUA_LOGW("screen display clock\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_CLOCK;
                    setup_scr_sc_clock(&g_dis.guider_ui);
                    lv_scr_load_anim(g_dis.guider_ui.sc_clock, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    app_init_time_clock();
                    break;
                }

                case SCREEN_MENU_SECOND: {
                    GUA_LOGW("screen display second\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_SECOND;
                    setup_scr_sc_second(&g_dis.guider_ui);
                    lv_scr_load_anim(g_dis.guider_ui.sc_second, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    break;
                }

                case SCREEN_MENU_SET: {
                    GUA_LOGW("screen display setting\r\n");
                    break;
                }

                case SCREEN_MENU_LIGHT: {
                    GUA_LOGW("screen display light\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_LIGHT;
                    setup_scr_sc_light(&g_dis.guider_ui);
                    lv_scr_load_anim(g_dis.guider_ui.sc_light, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    break;
                }

                case SCREEN_MENU_WEAT: {
                    GUA_LOGW("screen display sport\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_WEAT;
                    setup_scr_sc_weather(&g_dis.guider_ui);
                    lv_scr_load_anim(g_dis.guider_ui.sc_weather, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    break;
                }

                case SCREEN_MENU_MSG: {
                    GUA_LOGW("screen display message\r\n");
                    g_dis.screen_jump_id = SCREEN_JUMP_MSG;
                    setup_scr_sc_message(&g_dis.guider_ui);
                    lv_scr_load_anim(g_dis.guider_ui.sc_message, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    break;
                }
            }
        }
    }
}

static void app_screen_jump_id(int32 key_type, int32 key_event)
{
    switch (g_dis.screen_jump_id) {

        // 桌面主界面
        case SCREEN_JUMP_MAIN: {
            if (key_type == KEY_EVENT_ENTER_ID) {
                if (key_event == EVENT_SHORT_CLICK) {
                    // 跳转到菜单界面
                    GUA_LOGW("screen jump menu\r\n");
                    setup_scr_sc_menu(&g_dis.guider_ui);
                    app_menu_lvgl_setup(&g_dis.guider_ui, g_dis.guider_ui.sc_menu);
                    lv_scr_load_anim(g_dis.guider_ui.sc_menu, LV_SCR_LOAD_ANIM_MOVE_LEFT, APP_JUMP_DELAY, 0, true);
                    g_dis.screen_jump_id = SCREEN_JUMP_MENU;
                }
            }
            break;
        }

        // 菜单界面处理状态机
        case SCREEN_JUMP_MENU: {
            app_jump_menu(key_type, key_event);
            break;
        }

        // 其他子功能界面处理状态机
        // 心率界面处理
        case SCREEN_JUMP_RATE : {
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 血氧处理界面
        case SCREEN_JUMP_SPO2 :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 运动处理界面
        case SCREEN_JUMP_SPORT :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 闹钟
        case SCREEN_JUMP_CLOCK : {
            app_set_time_clock(key_type, key_event);
            break;
        }

        // 秒表
        case SCREEN_JUMP_SECOND :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 设置界面
        case SCREEN_JUMP_SET :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 手电筒
        case SCREEN_JUMP_LIGHT :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 天气
        case SCREEN_JUMP_WEAT :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        // 消息
        case SCREEN_JUMP_MSG :{
            if (key_type == KEY_EVENT_ENTER_ID && key_event == EVENT_DOUBLE_CLICK) {
                app_go_to_menu();
            }
            break;
        }

        default :
            break;
    }
}


static void app_uesr_key_callback(KEY_EVENT_ID id)
{
    GUA_LOGI("key evevt id[%d]\r\n", id);
    switch(id) {
        case KEY_EVENT_UP_ID : {
            app_menu_lvgl_set_event_key(KEY_TYPE_UP);
            break;
        }
        case KEY_EVENT_DOWN_ID : {
            app_menu_lvgl_set_event_key(KEY_TYPE_DOWN);
            break;
        }
        case KEY_EVENT_ENTER_ID : {
            app_menu_lvgl_set_event_key(KEY_TYPE_CENTER);
            break;
        }
        default :
            GUA_LOGE("user key callback input error! id[%d]\r\n", id);
    }
}


static int32 app_extract_digits(uint8 num, uint8 *tens, uint8 *ones) {
    if (num <= 0 || num > 99) {  // 处理无效输入（0、负数或超过两位数）
        *tens = 0;
        *ones = 0;
    } else {
        *tens = num / 10;   // 十位数字
        *ones = num % 10;   // 个位数字
    }
    return 0;
}


static int32 app_change_display_time(lv_obj_t * obj, uint8 time)
{
    if (obj == NULL) {
        return REV_ERR;
    }
    switch (time) {
       case 0: lv_img_set_src(obj, &_NUM0_29x78);  break;// 更新为新的图片资源
       case 1: lv_img_set_src(obj, &_NUM1_29x78);  break;// 更新为新的图片资源
       case 2: lv_img_set_src(obj, &_NUM2_29x78);  break;// 更新为新的图片资源
       case 3: lv_img_set_src(obj, &_NUM3_29x78);  break;// 更新为新的图片资源
       case 4: lv_img_set_src(obj, &_NUM4_29x78);  break;// 更新为新的图片资源
       case 5: lv_img_set_src(obj, &_NUM5_29x78);  break;// 更新为新的图片资源
       case 6: lv_img_set_src(obj, &_NUM6_29x78);  break;// 更新为新的图片资源
       case 7: lv_img_set_src(obj, &_NUM7_29x78);  break;// 更新为新的图片资源
       case 8: lv_img_set_src(obj, &_NUM8_29x78);  break;// 更新为新的图片资源
       case 9: lv_img_set_src(obj, &_NUM9_29x78);  break;// 更新为新的图片资源
        default:
            break;
    }
    lv_obj_invalidate(obj);  // 强制重绘图片
	return 0;
}


static int32 app_updata_time(lv_ui *ui, uint8 hour, uint8 minutes)
{
    uint8 tenx = 0, ones = 0;

    if (ui == NULL) {
        return REV_ERR;
    }

    app_extract_digits(hour, &tenx, &ones);
    app_change_display_time(ui->sc_main_img_num_0, tenx);
    app_change_display_time(ui->sc_main_img_num_1, ones);

    app_extract_digits(minutes, &tenx, &ones);
    app_change_display_time(ui->sc_main_img_num_2, tenx);
    app_change_display_time(ui->sc_main_img_num_3, ones);

    return REV_OK;
}


static void app_updata_system_message()
{
    char clock_str[8] = {0};

    if (g_dis.screen_init != REV_FINISH) {
        GUA_LOGE("wait lvgl not init\r\n");
        return;
    }

     /*时间获取部分*/
    HAL_RTC_WaitForSynchro(&hrtc);  // 等待同步完成
    HAL_RTC_GetTime(&hrtc, &g_dis.rtc_time, RTC_FORMAT_BIN); // 必须先调用获取时间接口，否则时间会不更新
	HAL_RTC_GetDate(&hrtc, &g_dis.rtc_date, RTC_FORMAT_BIN); // 获取日期

    if ((g_dis.rtc_time.Seconds != g_dis.rtc_time_his.Seconds) && (g_dis.screen_jump_id == SCREEN_JUMP_MAIN)) {
        sprintf(clock_str, "%02d:%02d", g_dis.rtc_time.Minutes, g_dis.rtc_time.Seconds);
        app_updata_time(&g_dis.guider_ui, g_dis.rtc_time.Minutes, g_dis.rtc_time.Seconds);
        GUA_LOGI("get_time %d:%d:%d\r\n",
            g_dis.rtc_time.Hours, g_dis.rtc_time.Minutes, g_dis.rtc_time.Seconds);
            g_dis.rtc_time_his.Seconds = g_dis.rtc_time.Seconds;

        if (g_dis.battery_percent_his != g_dis.battery_percent) {
            g_dis.battery_percent_his = g_dis.battery_percent;
            GUA_LOGI("battery precent updata[%02d]\r\n", g_dis.battery_percent);
            lv_bar_set_value(g_dis.guider_ui.sc_main_bar_battery, g_dis.battery_percent, LV_ANIM_OFF);  // 带动画（默认1000ms）
        }
    }

    g_dis.battery_percent = adc_get_battery();
    g_dis.battery_percent = 80;
}



#define MAX_BRIGHTNESS 255
uint32_t aun_ir_buffer[500]; //IR LED sensor data
int32_t n_ir_buffer_length = 200;    //data length
uint32_t aun_red_buffer[500];    //Red LED sensor data
int32_t n_sp02 = 98; //SPO2 value
int8_t ch_spo2_valid;   //indicator to show if the SP02 calculation is valid
int32_t n_heart_rate = 90;   //heart rate value ÐÄÂÊÖµ
int8_t  ch_hr_valid;    //indicator to show if the heart rate calculation is
uint8_t uch_dummy;
uint8_t hreat_buffer[10] = {90,90,90,90,90,90,90,90,90,90};
uint8_t O2_buffer[10] = {98,98,98,98,98,98,98,98,98,98};

int32_t get_herat(void)
{

	uint32_t un_min = 0x3FFFF, un_max = 0, un_prev_data;
	int i;
	int32_t n_brightness = 0;
	float f_temp;
    int32_t rev = 0;

	rev = maxim_max30102_reset(); //resets the MAX30102
    if (rev != REV_OK) {
        GUA_LOGE("iic error!\r\n");
        // return REV_ERR;
    }

	rev = maxim_max30102_read_reg(0,&uch_dummy); // read and clear status register
    if (rev != REV_OK) {
        GUA_LOGE("iic error!\r\n");
        // return REV_ERR;
    }

	rev = maxim_max30102_init();  //initializes the MAX30102
    if (rev != REV_OK) {
        GUA_LOGE("iic error!\r\n");
        // return REV_ERR;
    }
	GUA_LOGI("max30102 ok uch_dummy:%d\r\n", uch_dummy);

	for(i = 0; i < 500; i ++) {
		while(HAL_GPIO_ReadPin(MAX30103_INT_GPIO_Port,MAX30103_INT_Pin) == 1) {};

		rev = maxim_max30102_read_fifo((aun_red_buffer+i), (aun_ir_buffer+i));  //
        if (rev != REV_OK) {
            GUA_LOGE("max30102 read fifo error!\r\n");
            return REV_ERR;
        }

		if(un_min>aun_red_buffer[i]) // 最大值
			un_min=aun_red_buffer[i];

		if(un_max<aun_red_buffer[i]) // 最小值
			un_max=aun_red_buffer[i];

        if (i % 100 == 0) {
            GUA_LOGN("D:%d,%d\r\n", aun_red_buffer[i], aun_ir_buffer[i]);
        }
	}
    //根据样本计算饱和度
	maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);
	GUA_LOGI("n_sp02:%d ch_spo2_valid:%d n_heart_rate:%d ch_hr_valid:%d\r\n", n_sp02, ch_spo2_valid, n_heart_rate, ch_hr_valid);

    for (;;) {
        i=0;
        un_min=0x3FFFF;
        un_max=0;

        // 将前100组样本转储到内存中，并将最后400组样本移到顶部
        for(i=100;i<500;i++)
        {
            aun_red_buffer[i-100]=aun_red_buffer[i];
            aun_ir_buffer[i-100]=aun_ir_buffer[i];

            //update the signal min and max
            if(un_min>aun_red_buffer[i])
            un_min=aun_red_buffer[i];
            if(un_max<aun_red_buffer[i])
            un_max=aun_red_buffer[i];
        }

        // 在计算心率前取100组样本。
        for(i=400;i<500;i++) {
            un_prev_data=aun_red_buffer[i-1];
            while(HAL_GPIO_ReadPin(MAX30103_INT_GPIO_Port,MAX30103_INT_Pin) == 1) {};
            maxim_max30102_read_fifo((aun_red_buffer+i), (aun_ir_buffer+i));

            if(aun_red_buffer[i]>un_prev_data)//just to determine the brightness of LED according to the deviation of adjacent two AD data
            {
                f_temp=aun_red_buffer[i]-un_prev_data;
                f_temp/=(un_max-un_min);
                f_temp*=MAX_BRIGHTNESS;
                n_brightness-=(int)f_temp;
                if(n_brightness<0)
                    n_brightness=0;
            } else {
                f_temp=un_prev_data-aun_red_buffer[i];
                f_temp/=(un_max-un_min);
                f_temp*=MAX_BRIGHTNESS;
                n_brightness+=(int)f_temp;
                if(n_brightness>MAX_BRIGHTNESS)
                    n_brightness=MAX_BRIGHTNESS;
            }

            if (i % 100 == 0) {
                GUA_LOGN("D:%d,%d,%d\r\n", aun_red_buffer[i], aun_ir_buffer[i], n_brightness);
            }
        }

        maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid);

        GUA_LOGI("n_sp02:%d ch_spo2_valid:%d n_heart_rate:%d ch_hr_valid:%d\r\n", n_sp02, ch_spo2_valid, n_heart_rate, ch_hr_valid);
    }
    return REV_OK;
}

static uint8 app_get_key_value(KEY_MANAGE *ctl, int32 key)
{
    if (key) { // 硬件按键按下
        if (ctl->histery_key != key) {
            ctl->key_info.flag.key_state = KEY_STATE_PRESS;
            ctl->key_info.flag.check = 1;
            ctl->key_info.time_continus = 0;		//按键持续时间置零，准备开始计时
            ctl->histery_key = key;
        }
    } else {
        if (ctl->histery_key != key) {
            ctl->key_info.flag.key_state = KEY_STATE_RELEASE;	//松开
            ctl->key_info.flag.check = 1;
            ctl->key_info.time_idle = 0;			//按键空闲时间置零，准备开始计时
            ctl->histery_key = key;
        }
    }
    key_Process(&ctl->key_info);
    return key_scan(&ctl->key_info);
}


void app_watch_lv_tick_inc(void)
{
    lv_tick_inc(1); // 1毫秒调用周期
}

// noemal优先级
static void app_device_init(void)
{
    GUA_LOGI("mpu inti\r\n");
    MPU_Init();
    while(mpu_dmp_init()) {
        GUA_LOGE("error\r\n");
        HAL_Delay(10);
    }
    GUA_LOGI("mpu inti ok\r\n");
}

void app_watch_screen_task(void)
{
	lv_init();  // LVGL初始化
	lv_port_disp_init(); // 显示初始化
	lv_port_indev_init(); // 设备输入初始化

    delay_ms(100);
    GUA_LOGI("init lvgl\r\n");
    setup_ui(&g_dis.guider_ui);           // 初始化 UI
    events_init(&g_dis.guider_ui);       // 初始化 事件
    GUA_LOGI("init lvgl ok\r\n");
    g_dis.screen_init = REV_FINISH;
    GUA_LOGI("start main task\r\n");

	while (1) {
		delay_ms(1);
		lv_task_handler();
	}
}


// 优先级最高
void app_watch_base_task(void)
{
    int32 key = 0;
    KEY_DATA key_data;
    uint32 time = 0;
    KEY_MANAGE key_center; // 中心按钮
    KEY_MANAGE key_up; // 上按钮
    KEY_MANAGE key_down; // 下按钮

    mcu_power_set_ctol(1);

    key_config_init(&key_center.key_info);
    key_config_init(&key_up.key_info);
    key_config_init(&key_down.key_info);

    init_PWM();

    HAL_TIM_Base_Start_IT(&htim5); // 1ms LVGL界面滴答中断

    debug_init(SoftVersion, HardVersion, BuildDataStr, BuildTimeStr);

    init_key_gpio();



    LCD_Init();
    GUA_LOGI("init sys\r\n");
    app_sys_init();
    GUA_LOGI("init sys ok\r\n");
    key_queue_init(app_uesr_key_callback);

    g_dis.rtc_time_his.Seconds = 100;
    app_updata_system_message();

    GUA_LOGI("watch base task begin\r\n");

    shake_short();
    // app_trans_start_service();

    // while (1) {
    //     GUA_LOGI("watch base task ...\r\n");
	// 	delay_ms(1000);
    // }

    // FatfsTest();
    // storage();
    // test_flash();


    while (1) {
        key = HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
        key_data.key_valye = app_get_key_value(&key_center, key);
        if (key_data.key_valye == EVENT_SHORT_CLICK){
            key_data.key_valye = KEY_TYPE_CENTER;
            get_herat(); // 测试
            key_queue_set(&key_data);
        }
        app_screen_jump_id(KEY_EVENT_ENTER_ID, key_data.key_valye); // enter按键控制界面跳转

        key = HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
        key_data.key_valye = app_get_key_value(&key_up, key);
        if (key_data.key_valye == EVENT_SHORT_CLICK){
            key_data.key_valye = KEY_TYPE_UP;
            key_queue_set(&key_data);
        } else if (key_data.key_valye == EVENT_LONG_CLICK){ // 长按
            key_data.key_valye = KEY_TYPE_UP_LONG;
            key_queue_set(&key_data);
        }
        app_screen_jump_id(KEY_EVENT_UP_ID, key_data.key_valye);

        key = HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin);
        key_data.key_valye = app_get_key_value(&key_down, key);
        if (key_data.key_valye == EVENT_SHORT_CLICK){
            key_data.key_valye = KEY_TYPE_DOWN;
            key_queue_set(&key_data);
        } else if (key_data.key_valye == EVENT_LONG_CLICK){ // 长按
            key_data.key_valye = KEY_TYPE_DOWN_LONG;
            key_queue_set(&key_data);
        }
        app_screen_jump_id(KEY_EVENT_DOWN_ID, key_data.key_valye);

        time ++;
        if (time > 10) {
            time = 0;
            app_updata_system_message();
        }

#ifdef KEY_CYCLE
        delay_ms(10);
#endif
    }

}


// 优先级最低 用于获取传感器数据
void app_watch_background_task(void)
{
    unsigned long STEPS;

    // app_device_init();

    for (;;) {
        delay_ms(1000);
        // dmp_get_pedometer_step_count(&STEPS); // 计步器获取到步数
    }
}










