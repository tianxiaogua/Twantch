/*
 * Copyright 2025 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *sc_main;
	bool sc_main_del;
	lv_obj_t *sc_main_img_1;
	lv_obj_t *sc_main_img_2;
	lv_obj_t *sc_main_img_num_0;
	lv_obj_t *sc_main_img_num_1;
	lv_obj_t *sc_main_img_num_2;
	lv_obj_t *sc_main_img_num_3;
	lv_obj_t *sc_main_bar_battery;
	lv_obj_t *sc_menu;
	bool sc_menu_del;
	lv_obj_t *sc_menu_img_1;
	lv_obj_t *sc_menu_img_2;
	lv_obj_t *sc_menu_img_3;
	lv_obj_t *sc_menu_img_4;
	lv_obj_t *sc_menu_img_5;
	lv_obj_t *sc_menu_img_6;
	lv_obj_t *sc_menu_img_7;
	lv_obj_t *sc_menu_img_8;
	lv_obj_t *sc_menu_img_9;
	lv_obj_t *sc_menu_label_3;
	lv_obj_t *sc_menu_label_4;
	lv_obj_t *sc_menu_label_5;
	lv_obj_t *sc_menu_label_6;
	lv_obj_t *sc_menu_label_7;
	lv_obj_t *sc_menu_label_8;
	lv_obj_t *sc_menu_label_9;
	lv_obj_t *sc_menu_label_1;
	lv_obj_t *sc_menu_label_2;
	lv_obj_t *sc_second;
	bool sc_second_del;
	lv_obj_t *sc_second_img_1;
	lv_obj_t *sc_second_img_2;
	lv_obj_t *sc_second_label_1;
	lv_obj_t *sc_second_label_2;
	lv_obj_t *sc_second_img_3;
	lv_obj_t *sc_second_img_4;
	lv_obj_t *sc_clock;
	bool sc_clock_del;
	lv_obj_t *sc_clock_label_1;
	lv_obj_t *sc_clock_label_2;
	lv_obj_t *sc_clock_btn_2;
	lv_obj_t *sc_clock_btn_2_label;
	lv_obj_t *sc_clock_btn_3;
	lv_obj_t *sc_clock_btn_3_label;
	lv_obj_t *sc_heart;
	bool sc_heart_del;
	lv_obj_t *sc_heart_label_1;
	lv_obj_t *sc_heart_label_2;
	lv_obj_t *sc_heart_label_5;
	lv_obj_t *sc_heart_chart_1;
	lv_obj_t *sc_heart_label_3;
	lv_obj_t *sc_heart_label_4;
	lv_obj_t *sc_heart_label_6;
	lv_obj_t *sc_heart_label_7;
	lv_obj_t *sc_heart_label_8;
	lv_obj_t *sc_heart_label_9;
	lv_obj_t *sc_spo2;
	bool sc_spo2_del;
	lv_obj_t *sc_spo2_label_1;
	lv_obj_t *sc_spo2_label_2;
	lv_obj_t *sc_spo2_label_5;
	lv_obj_t *sc_spo2_chart_1;
	lv_obj_t *sc_spo2_label_3;
	lv_obj_t *sc_spo2_label_4;
	lv_obj_t *sc_spo2_label_6;
	lv_obj_t *sc_spo2_label_7;
	lv_obj_t *sc_spo2_label_8;
	lv_obj_t *sc_light;
	bool sc_light_del;
	lv_obj_t *sc_light_img_1;
	lv_obj_t *sc_weather;
	bool sc_weather_del;
	lv_obj_t *sc_weather_label_1;
	lv_obj_t *sc_weather_label_2;
	lv_obj_t *sc_weather_img_1;
	lv_obj_t *sc_weather_label_3;
	lv_obj_t *sc_weather_label_4;
	lv_obj_t *sc_weather_label_5;
	lv_obj_t *sc_weather_label_6;
	lv_obj_t *sc_weather_label_7;
	lv_obj_t *sc_sport;
	bool sc_sport_del;
	lv_obj_t *sc_sport_label_1;
	lv_obj_t *sc_sport_img_1;
	lv_obj_t *sc_sport_bar_1;
	lv_obj_t *sc_sport_label_2;
	lv_obj_t *sc_sport_img_2;
	lv_obj_t *sc_sport_label_3;
	lv_obj_t *sc_sport_bar_2;
	lv_obj_t *sc_sport_label_4;
	lv_obj_t *sc_sport_img_3;
	lv_obj_t *sc_sport_label_5;
	lv_obj_t *sc_sport_bar_3;
	lv_obj_t *sc_sport_label_6;
	lv_obj_t *sc_message;
	bool sc_message_del;
	lv_obj_t *sc_message_img_1;
	lv_obj_t *sc_message_label_1;
	lv_obj_t *sc_message_label_2;
	lv_obj_t *sc_message_line_1;
	lv_obj_t *sc_message_img_2;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_img_1;
	lv_obj_t *screen_1_img_2;
	lv_obj_t *screen_1_img_8;
	lv_obj_t *screen_1_img_7;
	lv_obj_t *screen_1_img_6;
	lv_obj_t *screen_1_img_5;
	lv_obj_t *screen_1_img_4;
	lv_obj_t *screen_1_img_3;
	lv_obj_t *screen_1_img_9;
	lv_obj_t *screen_1_img_10;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_sc_main(lv_ui *ui);
void setup_scr_sc_menu(lv_ui *ui);
void setup_scr_sc_second(lv_ui *ui);
void setup_scr_sc_clock(lv_ui *ui);
void setup_scr_sc_heart(lv_ui *ui);
void setup_scr_sc_spo2(lv_ui *ui);
void setup_scr_sc_light(lv_ui *ui);
void setup_scr_sc_weather(lv_ui *ui);
void setup_scr_sc_sport(lv_ui *ui);
void setup_scr_sc_message(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
LV_IMG_DECLARE(_ICO11_81x80);
LV_IMG_DECLARE(_NUM7_29x78);
LV_IMG_DECLARE(_ICO1_81x80);
LV_IMG_DECLARE(_bigCloud_85x79);
LV_IMG_DECLARE(_ICO8_81x80);
LV_IMG_DECLARE(_set_122x44);
LV_IMG_DECLARE(_NUM0_29x78);
LV_IMG_DECLARE(_rng_42x41);
LV_IMG_DECLARE(_NUM9_29x78);
LV_IMG_DECLARE(_NUM4_29x78);
LV_IMG_DECLARE(_ICO4_81x80);
LV_IMG_DECLARE(_ICO6_81x80);
LV_IMG_DECLARE(_NUM3_29x78);
LV_IMG_DECLARE(_NUM6_29x78);
LV_IMG_DECLARE(_delete_37x34);
LV_IMG_DECLARE(_NUM1_29x78);
LV_IMG_DECLARE(_ICO2_81x80);
LV_IMG_DECLARE(_NUM8_29x78);
LV_IMG_DECLARE(_set_123x44);
LV_IMG_DECLARE(_time_30x30);
LV_IMG_DECLARE(_2_172x320);
LV_IMG_DECLARE(_ICO7_81x80);
LV_IMG_DECLARE(_reset_35x33);
LV_IMG_DECLARE(_light_52x65);
LV_IMG_DECLARE(_calorie_30x30);
LV_IMG_DECLARE(_1_142x166);
LV_IMG_DECLARE(_NUM5_29x78);
LV_IMG_DECLARE(_step_30x30);
LV_IMG_DECLARE(_sey_start_34x32);
LV_IMG_DECLARE(_ICO12_81x80);
LV_IMG_DECLARE(_NUM2_29x78);
LV_IMG_DECLARE(_ICO5_81x80);

#ifdef __cplusplus
}
#endif
#endif