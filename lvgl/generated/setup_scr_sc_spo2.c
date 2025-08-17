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


void setup_scr_sc_spo2(lv_ui *ui){

	//Write codes sc_spo2
	ui->sc_spo2 = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_spo2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_main_main_default
	static lv_style_t style_sc_spo2_main_main_default;
	if (style_sc_spo2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_main_main_default);
	else
		lv_style_init(&style_sc_spo2_main_main_default);
	lv_style_set_bg_color(&style_sc_spo2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_spo2_main_main_default, 255);
	lv_obj_add_style(ui->sc_spo2, &style_sc_spo2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_chart_1
	ui->sc_spo2_chart_1 = lv_chart_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_chart_1, 30, 33);
	lv_obj_set_size(ui->sc_spo2_chart_1, 106, 141);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_chart_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_chart_1_main_main_default
	static lv_style_t style_sc_spo2_chart_1_main_main_default;
	if (style_sc_spo2_chart_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_chart_1_main_main_default);
	else
		lv_style_init(&style_sc_spo2_chart_1_main_main_default);
	lv_style_set_radius(&style_sc_spo2_chart_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_chart_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sc_spo2_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sc_spo2_chart_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_chart_1_main_main_default, 255);
	lv_style_set_border_color(&style_sc_spo2_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_sc_spo2_chart_1_main_main_default, 0);
	lv_style_set_border_opa(&style_sc_spo2_chart_1_main_main_default, 201);
	lv_style_set_line_color(&style_sc_spo2_chart_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_sc_spo2_chart_1_main_main_default, 1);
	lv_style_set_line_opa(&style_sc_spo2_chart_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_spo2_chart_1, &style_sc_spo2_chart_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_chart_set_type(ui->sc_spo2_chart_1, LV_CHART_TYPE_LINE);
	lv_chart_set_range(ui->sc_spo2_chart_1,LV_CHART_AXIS_PRIMARY_Y, 0, 100);
	lv_chart_set_div_line_count(ui->sc_spo2_chart_1, 3, 0);
	lv_chart_set_point_count(ui->sc_spo2_chart_1, 24);
	lv_chart_series_t * sc_spo2_chart_1_0 = lv_chart_add_series(ui->sc_spo2_chart_1, lv_color_make(0x0a, 0xff, 0x12), LV_CHART_AXIS_PRIMARY_Y);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 70);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 60);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 76);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 70);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 80);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);
	lv_chart_set_next_value(ui->sc_spo2_chart_1, sc_spo2_chart_1_0, 72);

	//Write codes sc_spo2_label_1
	ui->sc_spo2_label_1 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_1, -6, 27);
	lv_obj_set_size(ui->sc_spo2_label_1, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_1, "100%");
	lv_label_set_long_mode(ui->sc_spo2_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_1_main_main_default
	static lv_style_t style_sc_spo2_label_1_main_main_default;
	if (style_sc_spo2_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_1_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_1_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_1_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_1, &style_sc_spo2_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_7
	ui->sc_spo2_label_7 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_7, -7, 158);
	lv_obj_set_size(ui->sc_spo2_label_7, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_7, "90%");
	lv_label_set_long_mode(ui->sc_spo2_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_7_main_main_default
	static lv_style_t style_sc_spo2_label_7_main_main_default;
	if (style_sc_spo2_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_7_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_7_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_7_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_7_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_7, &style_sc_spo2_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_10
	ui->sc_spo2_label_10 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_10, 10, 174);
	lv_obj_set_size(ui->sc_spo2_label_10, 50, 16);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_10, "00:00");
	lv_label_set_long_mode(ui->sc_spo2_label_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_10_main_main_default
	static lv_style_t style_sc_spo2_label_10_main_main_default;
	if (style_sc_spo2_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_10_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_10_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_10_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_10_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_10_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_10_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_10, &style_sc_spo2_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_9
	ui->sc_spo2_label_9 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_9, 0, 206);
	lv_obj_set_size(ui->sc_spo2_label_9, 135, 16);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_9, "MAX:99 MIN:99");
	lv_label_set_long_mode(ui->sc_spo2_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_9_main_main_default
	static lv_style_t style_sc_spo2_label_9_main_main_default;
	if (style_sc_spo2_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_9_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_9_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_9_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_spo2_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_9_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_9, &style_sc_spo2_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_4
	ui->sc_spo2_label_4 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_4, -7, 89);
	lv_obj_set_size(ui->sc_spo2_label_4, 42, 16);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_4, "95%");
	lv_label_set_long_mode(ui->sc_spo2_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_4_main_main_default
	static lv_style_t style_sc_spo2_label_4_main_main_default;
	if (style_sc_spo2_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_4_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_4_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_4_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_4_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_4, &style_sc_spo2_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_11
	ui->sc_spo2_label_11 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_11, 80, 174);
	lv_obj_set_size(ui->sc_spo2_label_11, 49, 16);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_11, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_11, "24:00");
	lv_label_set_long_mode(ui->sc_spo2_label_11, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_11_main_main_default
	static lv_style_t style_sc_spo2_label_11_main_main_default;
	if (style_sc_spo2_label_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_11_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_11_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_11_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_11_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_11_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_11_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_11_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_11_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_11_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_11_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_11_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_11_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_11_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_11_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_11, &style_sc_spo2_label_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_12
	ui->sc_spo2_label_12 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_12, 0, 3);
	lv_obj_set_size(ui->sc_spo2_label_12, 45, 18);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_12, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_12, "SpO2");
	lv_label_set_long_mode(ui->sc_spo2_label_12, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_12_main_main_default
	static lv_style_t style_sc_spo2_label_12_main_main_default;
	if (style_sc_spo2_label_12_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_12_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_12_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_12_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_12_main_main_default, lv_color_make(0xf2, 0x5f, 0x5f));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_12_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_12_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_12_main_main_default, 255);
	lv_style_set_text_color(&style_sc_spo2_label_12_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_12_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_12_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_12_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_12_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_12_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_12_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_12_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_12_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_12, &style_sc_spo2_label_12_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_spo2_label_13
	ui->sc_spo2_label_13 = lv_label_create(ui->sc_spo2);
	lv_obj_set_pos(ui->sc_spo2_label_13, 52, 4);
	lv_obj_set_size(ui->sc_spo2_label_13, 30, 17);
	lv_obj_set_scrollbar_mode(ui->sc_spo2_label_13, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_spo2_label_13, "99%");
	lv_label_set_long_mode(ui->sc_spo2_label_13, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_spo2_label_13_main_main_default
	static lv_style_t style_sc_spo2_label_13_main_main_default;
	if (style_sc_spo2_label_13_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_spo2_label_13_main_main_default);
	else
		lv_style_init(&style_sc_spo2_label_13_main_main_default);
	lv_style_set_radius(&style_sc_spo2_label_13_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_spo2_label_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_spo2_label_13_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_spo2_label_13_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_spo2_label_13_main_main_default, 0);
	lv_style_set_text_color(&style_sc_spo2_label_13_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_spo2_label_13_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_spo2_label_13_main_main_default, 1);
	lv_style_set_text_line_space(&style_sc_spo2_label_13_main_main_default, 0);
	lv_style_set_text_align(&style_sc_spo2_label_13_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_spo2_label_13_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_spo2_label_13_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_spo2_label_13_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_spo2_label_13_main_main_default, 0);
	lv_obj_add_style(ui->sc_spo2_label_13, &style_sc_spo2_label_13_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}