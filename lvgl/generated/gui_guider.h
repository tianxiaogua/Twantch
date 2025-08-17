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
	lv_obj_t *sc_main_sc_main_lable_bar_battery;
	lv_obj_t *sc_main_sc_main_img1;
	lv_obj_t *sc_main_img_num_0;
	lv_obj_t *sc_main_img_num_1;
	lv_obj_t *sc_main_img_num_2;
	lv_obj_t *sc_main_img_num_3;
	lv_obj_t *sc_menu;
	bool sc_menu_del;
	lv_obj_t *sc_menu_img_menu_1;
	lv_obj_t *sc_menu_img_menu_10;
	lv_obj_t *sc_menu_img_menu_9;
	lv_obj_t *sc_menu_label_menu_4;
	lv_obj_t *sc_menu_label_menu_6;
	lv_obj_t *sc_menu_label_menu_7;
	lv_obj_t *sc_menu_label_menu_8;
	lv_obj_t *sc_menu_label_menu_9;
	lv_obj_t *sc_menu_label_menu_10;
	lv_obj_t *sc_menu_img_menu_7;
	lv_obj_t *sc_menu_label_menu_5;
	lv_obj_t *sc_menu_img_menu_6;
	lv_obj_t *sc_menu_label_menu_1;
	lv_obj_t *sc_menu_label_menu_2;
	lv_obj_t *sc_menu_label_menu_3;
	lv_obj_t *sc_menu_img_menu_2;
	lv_obj_t *sc_menu_img_menu_3;
	lv_obj_t *sc_menu_img_menu_4;
	lv_obj_t *sc_menu_img_menu_5;
	lv_obj_t *sc_menu_img_menu_8;
	lv_obj_t *sc_timer;
	bool sc_timer_del;
	lv_obj_t *sc_timer_label_1;
	lv_obj_t *sc_timer_img_1;
	lv_obj_t *sc_timer_img_2;
	lv_obj_t *sc_timer_label_2;
	lv_obj_t *sc_timer_img_3;
	lv_obj_t *sc_timer_img_4;
	lv_obj_t *sc_message2;
	bool sc_message2_del;
	lv_obj_t *sc_message2_img_2;
	lv_obj_t *sc_message2_cont_1;
	lv_obj_t *sc_message2_label_3;
	lv_obj_t *sc_message2_label_2;
	lv_obj_t *sc_message2_img_3;
	lv_obj_t *sc_message2_line_1;
	lv_obj_t *scr_message;
	bool scr_message_del;
	lv_obj_t *scr_message_img_1;
	lv_obj_t *scr_message_label_1;
	lv_obj_t *sc_light;
	bool sc_light_del;
	lv_obj_t *sc_sport;
	bool sc_sport_del;
	lv_obj_t *sc_sport_bar_1;
	lv_obj_t *sc_sport_bar_2;
	lv_obj_t *sc_sport_img_1;
	lv_obj_t *sc_sport_img_2;
	lv_obj_t *sc_sport_img_3;
	lv_obj_t *sc_sport_label_1;
	lv_obj_t *sc_sport_label_3;
	lv_obj_t *sc_sport_label_5;
	lv_obj_t *sc_sport_label_7;
	lv_obj_t *sc_sport_label_6;
	lv_obj_t *sc_sport_label_2;
	lv_obj_t *sc_sport_label_8;
	lv_obj_t *sc_sport_label_9;
	lv_obj_t *sc_sport_label_4;
	lv_obj_t *sc_sport_bar_3;
	lv_obj_t *sc_weather;
	bool sc_weather_del;
	lv_obj_t *sc_weather_label_1;
	lv_obj_t *sc_weather_img_1;
	lv_obj_t *sc_weather_label_2;
	lv_obj_t *sc_weather_label_3;
	lv_obj_t *sc_weather_label_4;
	lv_obj_t *sc_weather_label_5;
	lv_obj_t *sc_weather_label_6;
	lv_obj_t *sc_spo2;
	bool sc_spo2_del;
	lv_obj_t *sc_spo2_chart_1;
	lv_obj_t *sc_spo2_label_1;
	lv_obj_t *sc_spo2_label_7;
	lv_obj_t *sc_spo2_label_10;
	lv_obj_t *sc_spo2_label_9;
	lv_obj_t *sc_spo2_label_4;
	lv_obj_t *sc_spo2_label_11;
	lv_obj_t *sc_spo2_label_12;
	lv_obj_t *sc_spo2_label_13;
	lv_obj_t *sc_heart;
	bool sc_heart_del;
	lv_obj_t *sc_heart_chart_1;
	lv_obj_t *sc_heart_label_1;
	lv_obj_t *sc_heart_label_2;
	lv_obj_t *sc_heart_label_3;
	lv_obj_t *sc_heart_label_7;
	lv_obj_t *sc_heart_label_10;
	lv_obj_t *sc_heart_label_8;
	lv_obj_t *sc_heart_label_9;
	lv_obj_t *sc_heart_label_4;
	lv_obj_t *sc_heart_label_11;
	lv_obj_t *demo;
	bool demo_del;
	lv_obj_t *demo_img_1;
	lv_obj_t *demo_img_2;
	lv_obj_t *demo_img_3;
	lv_obj_t *demo_img_4;
	lv_obj_t *demo_img_5;
	lv_obj_t *demo_img_6;
	lv_obj_t *demo_img_7;
	lv_obj_t *demo_img_8;
	lv_obj_t *demo_img_9;
	lv_obj_t *demo_img_10;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_sc_main(lv_ui *ui);
void setup_scr_sc_menu(lv_ui *ui);
void setup_scr_sc_timer(lv_ui *ui);
void setup_scr_sc_message2(lv_ui *ui);
void setup_scr_scr_message(lv_ui *ui);
void setup_scr_sc_light(lv_ui *ui);
void setup_scr_sc_sport(lv_ui *ui);
void setup_scr_sc_weather(lv_ui *ui);
void setup_scr_sc_spo2(lv_ui *ui);
void setup_scr_sc_heart(lv_ui *ui);
void setup_scr_demo(lv_ui *ui);
LV_IMG_DECLARE(_NUM1_25x60);
LV_IMG_DECLARE(_1_102x122);
LV_IMG_DECLARE(_step_20x23);
LV_IMG_DECLARE(_time_20x20);
LV_IMG_DECLARE(_NUM8_25x60);
LV_IMG_DECLARE(_NUM6_25x60);
LV_IMG_DECLARE(_ICO1_60x60);
LV_IMG_DECLARE(_ICO6_60x60);
LV_IMG_DECLARE(_NUM4_25x60);
LV_IMG_DECLARE(_ICO4_60x60);
LV_IMG_DECLARE(_2_135x240);
LV_IMG_DECLARE(_second_60x60);
LV_IMG_DECLARE(_NUM2_25x60);
LV_IMG_DECLARE(_ioc_sport_60x60);
LV_IMG_DECLARE(_set_116x38);
LV_IMG_DECLARE(_NUM7_25x60);
LV_IMG_DECLARE(_ICO7_60x60);
LV_IMG_DECLARE(_timer_60x60);
LV_IMG_DECLARE(_rng_30x30);
LV_IMG_DECLARE(_NUM0_25x60);
LV_IMG_DECLARE(_NUM5_25x60);
LV_IMG_DECLARE(_NUM9_25x60);
LV_IMG_DECLARE(_ICO2_60x60);
LV_IMG_DECLARE(_message_60x60);
LV_IMG_DECLARE(_ICO5_60x60);
LV_IMG_DECLARE(_reset2_31x28);
LV_IMG_DECLARE(_ICO3_60x60);
LV_IMG_DECLARE(_delete_30x30);
LV_IMG_DECLARE(_NUM3_25x60);
LV_IMG_DECLARE(_calorie_20x20);
LV_IMG_DECLARE(_sey_start_30x30);
LV_IMG_DECLARE(_bigCloud_60x60);

#ifdef __cplusplus
}
#endif
#endif