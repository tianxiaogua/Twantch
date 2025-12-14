/*
 * Copyright 2025 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_sc_weather(lv_ui *ui){

	//Write codes sc_weather
	ui->sc_weather = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_weather, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_main_main_default
	static lv_style_t style_sc_weather_main_main_default;
	if (style_sc_weather_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_main_main_default);
	else
		lv_style_init(&style_sc_weather_main_main_default);
	lv_style_set_bg_color(&style_sc_weather_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_weather_main_main_default, 255);
	lv_obj_add_style(ui->sc_weather, &style_sc_weather_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_label_1
	ui->sc_weather_label_1 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_1, 12, 111);
	lv_obj_set_size(ui->sc_weather_label_1, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_1, "");
	lv_label_set_long_mode(ui->sc_weather_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_1_main_main_default
	static lv_style_t style_sc_weather_label_1_main_main_default;
	if (style_sc_weather_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_1_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_1_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_weather_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_sc_weather_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_1, &style_sc_weather_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_label_2
	ui->sc_weather_label_2 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_2, 36, 10);
	lv_obj_set_size(ui->sc_weather_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_2, "滨江区");
	lv_label_set_long_mode(ui->sc_weather_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_2_main_main_default
	static lv_style_t style_sc_weather_label_2_main_main_default;
	if (style_sc_weather_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_2_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_2_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_weather_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_weather_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_weather_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_2, &style_sc_weather_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_img_1
	ui->sc_weather_img_1 = lv_img_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_img_1, 44, 58);
	lv_obj_set_size(ui->sc_weather_img_1, 85, 79);
	lv_obj_set_scrollbar_mode(ui->sc_weather_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_img_1_main_main_default
	static lv_style_t style_sc_weather_img_1_main_main_default;
	if (style_sc_weather_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_img_1_main_main_default);
	else
		lv_style_init(&style_sc_weather_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_weather_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_weather_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_weather_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_weather_img_1, &style_sc_weather_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_weather_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_weather_img_1,&_bigCloud_85x79);
	lv_img_set_pivot(ui->sc_weather_img_1, 0,0);
	lv_img_set_angle(ui->sc_weather_img_1, 0);

	//Write codes sc_weather_label_3
	ui->sc_weather_label_3 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_3, 36, 153);
	lv_obj_set_size(ui->sc_weather_label_3, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_3, "大雨");
	lv_label_set_long_mode(ui->sc_weather_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_3_main_main_default
	static lv_style_t style_sc_weather_label_3_main_main_default;
	if (style_sc_weather_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_3_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_3_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_weather_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_weather_label_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_weather_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_3, &style_sc_weather_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_label_4
	ui->sc_weather_label_4 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_4, 22, 197);
	lv_obj_set_size(ui->sc_weather_label_4, 129, 23);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_4, "23℃/12℃");
	lv_label_set_long_mode(ui->sc_weather_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_4_main_main_default
	static lv_style_t style_sc_weather_label_4_main_main_default;
	if (style_sc_weather_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_4_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_4_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_weather_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_weather_label_4_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_sc_weather_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_4, &style_sc_weather_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_label_5
	ui->sc_weather_label_5 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_5, 22, 226);
	lv_obj_set_size(ui->sc_weather_label_5, 123, 32);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_5, "空气质量优");
	lv_label_set_long_mode(ui->sc_weather_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_5_main_main_default
	static lv_style_t style_sc_weather_label_5_main_main_default;
	if (style_sc_weather_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_5_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_5_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_weather_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_5_main_main_default, lv_color_make(0x05, 0xff, 0x16));
	lv_style_set_text_font(&style_sc_weather_label_5_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_weather_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_5_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_5, &style_sc_weather_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_label_6
	ui->sc_weather_label_6 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_6, 22, 258);
	lv_obj_set_size(ui->sc_weather_label_6, 136, 32);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_6, "2025-07-12");
	lv_label_set_long_mode(ui->sc_weather_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_6_main_main_default
	static lv_style_t style_sc_weather_label_6_main_main_default;
	if (style_sc_weather_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_6_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_6_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sc_weather_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_weather_label_6_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_sc_weather_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_6_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_6, &style_sc_weather_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_weather_label_7
	ui->sc_weather_label_7 = lv_label_create(ui->sc_weather);
	lv_obj_set_pos(ui->sc_weather_label_7, 36, 282);
	lv_obj_set_size(ui->sc_weather_label_7, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_weather_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_weather_label_7, "12:30");
	lv_label_set_long_mode(ui->sc_weather_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_weather_label_7_main_main_default
	static lv_style_t style_sc_weather_label_7_main_main_default;
	if (style_sc_weather_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_weather_label_7_main_main_default);
	else
		lv_style_init(&style_sc_weather_label_7_main_main_default);
	lv_style_set_radius(&style_sc_weather_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_weather_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_weather_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_weather_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_weather_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_sc_weather_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_weather_label_7_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_sc_weather_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_weather_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_weather_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_weather_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_weather_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_weather_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_weather_label_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_weather_label_7, &style_sc_weather_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}