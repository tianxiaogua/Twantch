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

	//Write codes sc_heart_chart_1
	ui->sc_heart_chart_1 = lv_chart_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_chart_1, 29, 35);
	lv_obj_set_size(ui->sc_heart_chart_1, 104, 164);
	lv_obj_set_scrollbar_mode(ui->sc_heart_chart_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_chart_1_main_main_default
	static lv_style_t style_sc_heart_chart_1_main_main_default;
	if (style_sc_heart_chart_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_chart_1_main_main_default);
	else
		lv_style_init(&style_sc_heart_chart_1_main_main_default);
	lv_style_set_radius(&style_sc_heart_chart_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sc_heart_chart_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_chart_1_main_main_default, 255);
	lv_style_set_border_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_sc_heart_chart_1_main_main_default, 0);
	lv_style_set_border_opa(&style_sc_heart_chart_1_main_main_default, 201);
	lv_style_set_line_color(&style_sc_heart_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_sc_heart_chart_1_main_main_default, 1);
	lv_style_set_line_opa(&style_sc_heart_chart_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_heart_chart_1, &style_sc_heart_chart_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_chart_set_type(ui->sc_heart_chart_1, LV_CHART_TYPE_LINE);
	lv_chart_set_range(ui->sc_heart_chart_1,LV_CHART_AXIS_PRIMARY_Y, 0, 100);
	lv_chart_set_div_line_count(ui->sc_heart_chart_1, 5, 0);
	lv_chart_set_point_count(ui->sc_heart_chart_1, 24);
	lv_chart_series_t * sc_heart_chart_1_0 = lv_chart_add_series(ui->sc_heart_chart_1, lv_color_make(0xff, 0x0a, 0x0a), LV_CHART_AXIS_PRIMARY_Y);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 70);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 60);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 76);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 70);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_heart_chart_1, sc_heart_chart_1_0, 72);

	//Write codes sc_heart_label_1
	ui->sc_heart_label_1 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_1, -8, 29);
	lv_obj_set_size(ui->sc_heart_label_1, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_1, "175");
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
	lv_style_set_bg_opa(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_1_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_1, &style_sc_heart_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_2
	ui->sc_heart_label_2 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_2, -7, 64);
	lv_obj_set_size(ui->sc_heart_label_2, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_2, "150");
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
	lv_style_set_text_font(&style_sc_heart_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_2_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_2, &style_sc_heart_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_3
	ui->sc_heart_label_3 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_3, -7, 146);
	lv_obj_set_size(ui->sc_heart_label_3, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_3, "75");
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
	lv_style_set_text_font(&style_sc_heart_label_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_3_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_3, &style_sc_heart_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_7
	ui->sc_heart_label_7 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_7, -7, 184);
	lv_obj_set_size(ui->sc_heart_label_7, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_7, "50");
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
	lv_style_set_text_font(&style_sc_heart_label_7_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_7_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_7, &style_sc_heart_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_10
	ui->sc_heart_label_10 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_10, 4, 199);
	lv_obj_set_size(ui->sc_heart_label_10, 55, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_10, "00:00");
	lv_label_set_long_mode(ui->sc_heart_label_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_10_main_main_default
	static lv_style_t style_sc_heart_label_10_main_main_default;
	if (style_sc_heart_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_10_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_10_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_10_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_10_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_10_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_10_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_10, &style_sc_heart_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_8
	ui->sc_heart_label_8 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_8, 4, 4);
	lv_obj_set_size(ui->sc_heart_label_8, 127, 20);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_8, "Heart: 87BMP");
	lv_label_set_long_mode(ui->sc_heart_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_8_main_main_default
	static lv_style_t style_sc_heart_label_8_main_main_default;
	if (style_sc_heart_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_8_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_8_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0x5f, 0x5c, 0xff));
	lv_style_set_bg_grad_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_8_main_main_default, 255);
	lv_style_set_shadow_width(&style_sc_heart_label_8_main_main_default, 2);
	lv_style_set_shadow_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_shadow_opa(&style_sc_heart_label_8_main_main_default, 99);
	lv_style_set_shadow_spread(&style_sc_heart_label_8_main_main_default, 2);
	lv_style_set_shadow_ofs_x(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_8_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_8_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_8_main_main_default, 1);
	lv_style_set_pad_right(&style_sc_heart_label_8_main_main_default, 1);
	lv_style_set_pad_top(&style_sc_heart_label_8_main_main_default, 1);
	lv_style_set_pad_bottom(&style_sc_heart_label_8_main_main_default, 1);
	lv_obj_add_style(ui->sc_heart_label_8, &style_sc_heart_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_9
	ui->sc_heart_label_9 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_9, -1, 220);
	lv_obj_set_size(ui->sc_heart_label_9, 135, 22);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_9, "MAX:76 MIN:66");
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
	lv_style_set_text_font(&style_sc_heart_label_9_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_9_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_9, &style_sc_heart_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_4
	ui->sc_heart_label_4 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_4, -8, 104);
	lv_obj_set_size(ui->sc_heart_label_4, 42, 16);
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
	lv_style_set_text_font(&style_sc_heart_label_4_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_4_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_4, &style_sc_heart_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_heart_label_11
	ui->sc_heart_label_11 = lv_label_create(ui->sc_heart);
	lv_obj_set_pos(ui->sc_heart_label_11, 84, 199);
	lv_obj_set_size(ui->sc_heart_label_11, 50, 16);
	lv_obj_set_scrollbar_mode(ui->sc_heart_label_11, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_heart_label_11, "24:00");
	lv_label_set_long_mode(ui->sc_heart_label_11, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_heart_label_11_main_main_default
	static lv_style_t style_sc_heart_label_11_main_main_default;
	if (style_sc_heart_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_heart_label_11_main_main_default);
	else
		lv_style_init(&style_sc_heart_label_11_main_main_default);
	lv_style_set_radius(&style_sc_heart_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_heart_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_heart_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_heart_label_11_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_heart_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_sc_heart_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_heart_label_11_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_heart_label_11_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_heart_label_11_main_main_default, 0);
	lv_style_set_text_align(&style_sc_heart_label_11_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_heart_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_heart_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_heart_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_heart_label_11_main_main_default, 0);
	lv_obj_add_style(ui->sc_heart_label_11, &style_sc_heart_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}