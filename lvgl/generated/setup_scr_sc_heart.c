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


void setup_scr_sc_heart(lv_ui *ui){

	//Write codes sc_heart
	ui->sc_heart = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_heart, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_main_main_default
	static lv_style_t style_sc_heart_main_main_default;
	if (style_sc_heart_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_main_main_default);
	else
		lv_style_init(&style_sc_heart_main_main_default);
	lv_style_set_bg_color(&style_sc_heart_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_heart_main_main_default, 255);
	lv_obj_add_style(ui->sc_heart, &style_sc_heart_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_1
	ui->sc_heart_label_1 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_1, 14, 11);
	lv_obj_set_size(ui->sc_heart_label_1, 134, 23);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_1, "heart:92BMP");
	lv_label_set_long_mode(ui->sc_heart_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_1_main_main_default
	static lv_style_t style_sc_heart_label_1_main_main_default;
	if (style_sc_heart_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_1_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_1_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_sc_heart_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_1_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_sc_heart_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_1, &style_sc_heart_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_2
	ui->sc_heart_label_2 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_2, 1, 42);
	lv_obj_set_size(ui->sc_heart_label_2, 40, 20);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_2, "175");
	lv_label_set_long_mode(ui->sc_heart_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_2_main_main_default
	static lv_style_t style_sc_heart_label_2_main_main_default;
	if (style_sc_heart_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_2_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_2_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_2_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_2, &style_sc_heart_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_5
	ui->sc_heart_label_5 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_5, 11, 205);
	lv_obj_set_size(ui->sc_heart_label_5, 31, 20);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_5, "75");
	lv_label_set_long_mode(ui->sc_heart_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_5_main_main_default
	static lv_style_t style_sc_heart_label_5_main_main_default;
	if (style_sc_heart_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_5_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_5_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_5_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_5_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_5, &style_sc_heart_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_chart_1
	ui->sc_heart_chart_1 = lv_chart_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_chart_1, 35, 44);
	lv_obj_set_size(ui->sc_heart_chart_1, 129, 230);
	lv_obj_set_scrollbar_mode(ui->sc_heart_chart_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_chart_1_main_main_default
	static lv_style_t style_sc_heart_chart_1_main_main_default;
	if (style_sc_heart_chart_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_chart_1_main_main_default);
	else
		lv_style_init(&style_sc_heart_chart_1_main_main_default);
	lv_style_set_radius(&style_sc_heart_chart_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sc_heart_chart_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_chart_1_main_main_default, 0);
	lv_style_set_border_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_sc_heart_chart_1_main_main_default, 1);
	lv_style_set_border_opa(&style_sc_heart_chart_1_main_main_default, 0);
	lv_style_set_line_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xe8, 0xe8, 0xe8));
	lv_style_set_line_width(&style_sc_heart_chart_1_main_main_default, 2);
	lv_style_set_line_opa(&style_sc_heart_chart_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_heart_chart_1, &style_sc_heart_chart_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_chart_set_type(ui->sc_heart_chart_1, LV_CHART_TYPE_LINE);
	lv_chart_set_range(ui->sc_heart_chart_1,LV_CHART_AXIS_PRIMARY_Y, 0, 170);
	lv_chart_set_div_line_count(ui->sc_heart_chart_1, 5, 0);
	lv_chart_set_point_count(ui->sc_heart_chart_1, 5);
	lv_chart_series_t * sc_heart_chart_1_0 = lv_chart_add_series(ui->sc_heart_chart_1, lv_color_make(0xff, 0x00, 0x00), LV_CHART_AXIS_PRIMARY_Y);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 1);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 20);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 30);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 40);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 5);

	//Write codes sc_heart_label_3
	ui->sc_heart_label_3 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_3, 1, 84);
	lv_obj_set_size(ui->sc_heart_label_3, 40, 20);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_3, "150");
	lv_label_set_long_mode(ui->sc_heart_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_3_main_main_default
	static lv_style_t style_sc_heart_label_3_main_main_default;
	if (style_sc_heart_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_3_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_3_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_3_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_3, &style_sc_heart_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_4
	ui->sc_heart_label_4 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_4, 1, 150);
	lv_obj_set_size(ui->sc_heart_label_4, 40, 32);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_4, "100");
	lv_label_set_long_mode(ui->sc_heart_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_4_main_main_default
	static lv_style_t style_sc_heart_label_4_main_main_default;
	if (style_sc_heart_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_4_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_4_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_4_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_4, &style_sc_heart_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_6
	ui->sc_heart_label_6 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_6, -29, 256);
	lv_obj_set_size(ui->sc_heart_label_6, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_6, "50");
	lv_label_set_long_mode(ui->sc_heart_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_6_main_main_default
	static lv_style_t style_sc_heart_label_6_main_main_default;
	if (style_sc_heart_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_6_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_6_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_6_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_6_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_6, &style_sc_heart_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_7
	ui->sc_heart_label_7 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_7, 11, 277);
	lv_obj_set_size(ui->sc_heart_label_7, 49, 20);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_7, "00:00");
	lv_label_set_long_mode(ui->sc_heart_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_7_main_main_default
	static lv_style_t style_sc_heart_label_7_main_main_default;
	if (style_sc_heart_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_7_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_7_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_7_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_7, &style_sc_heart_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_8
	ui->sc_heart_label_8 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_8, 111, 274);
	lv_obj_set_size(ui->sc_heart_label_8, 53, 17);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_8, "24:00");
	lv_label_set_long_mode(ui->sc_heart_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_8_main_main_default
	static lv_style_t style_sc_heart_label_8_main_main_default;
	if (style_sc_heart_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_8_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_8_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_8_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_8_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_8, &style_sc_heart_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_9
	ui->sc_heart_label_9 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_9, 7, 297);
	lv_obj_set_size(ui->sc_heart_label_9, 157, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_9, "MAX:67 MIN:66");
	lv_label_set_long_mode(ui->sc_heart_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_9_main_main_default
	static lv_style_t style_sc_heart_label_9_main_main_default;
	if (style_sc_heart_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_9_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_9_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_9_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_sc_heart_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_9_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_9, &style_sc_heart_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}