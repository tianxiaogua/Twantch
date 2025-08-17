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


void setup_scr_sc_menu(lv_ui *ui){

	//Write codes sc_menu
	ui->sc_menu = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_main_main_default
	static lv_style_t style_sc_menu_main_main_default;
	if (style_sc_menu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_main_main_default);
	else
		lv_style_init(&style_sc_menu_main_main_default);
	lv_style_set_bg_color(&style_sc_menu_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_menu_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu, &style_sc_menu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_img_menu_1
	ui->sc_menu_img_menu_1 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_1, 42, 9);
	lv_obj_set_size(ui->sc_menu_img_menu_1, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_1_main_main_default
	static lv_style_t style_sc_menu_img_menu_1_main_main_default;
	if (style_sc_menu_img_menu_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_1_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_1, &style_sc_menu_img_menu_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_1,&_ICO5_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_1, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_1, 0);

	//Write codes sc_menu_img_menu_10
	ui->sc_menu_img_menu_10 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_10, 37, 850);
	lv_obj_set_size(ui->sc_menu_img_menu_10, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_10_main_main_default
	static lv_style_t style_sc_menu_img_menu_10_main_main_default;
	if (style_sc_menu_img_menu_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_10_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_10_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_10_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_10_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_10, &style_sc_menu_img_menu_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_10,&_ICO4_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_10, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_10, 0);

	//Write codes sc_menu_img_menu_9
	ui->sc_menu_img_menu_9 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_9, 38, 759);
	lv_obj_set_size(ui->sc_menu_img_menu_9, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_9_main_main_default
	static lv_style_t style_sc_menu_img_menu_9_main_main_default;
	if (style_sc_menu_img_menu_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_9_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_9_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_9_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_9_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_9, &style_sc_menu_img_menu_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_9,&_ICO1_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_9, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_9, 0);

	//Write codes sc_menu_label_menu_4
	ui->sc_menu_label_menu_4 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_4, 32, 359);
	lv_obj_set_size(ui->sc_menu_label_menu_4, 70, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_4, "闹钟");
	lv_label_set_long_mode(ui->sc_menu_label_menu_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_4_main_main_default
	static lv_style_t style_sc_menu_label_menu_4_main_main_default;
	if (style_sc_menu_label_menu_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_4_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_4_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_4_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_4, &style_sc_menu_label_menu_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_6
	ui->sc_menu_label_menu_6 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_6, 32.5, 537);
	lv_obj_set_size(ui->sc_menu_label_menu_6, 70, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_6, "秒表");
	lv_label_set_long_mode(ui->sc_menu_label_menu_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_6_main_main_default
	static lv_style_t style_sc_menu_label_menu_6_main_main_default;
	if (style_sc_menu_label_menu_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_6_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_6_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_6_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_6_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_6, &style_sc_menu_label_menu_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_7
	ui->sc_menu_label_menu_7 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_7, 32.5, 631);
	lv_obj_set_size(ui->sc_menu_label_menu_7, 70, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_7, "设置");
	lv_label_set_long_mode(ui->sc_menu_label_menu_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_7_main_main_default
	static lv_style_t style_sc_menu_label_menu_7_main_main_default;
	if (style_sc_menu_label_menu_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_7_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_7_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_7_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_7, &style_sc_menu_label_menu_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_8
	ui->sc_menu_label_menu_8 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_8, 25, 726);
	lv_obj_set_size(ui->sc_menu_label_menu_8, 85, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_8, "手电筒");
	lv_label_set_long_mode(ui->sc_menu_label_menu_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_8_main_main_default
	static lv_style_t style_sc_menu_label_menu_8_main_main_default;
	if (style_sc_menu_label_menu_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_8_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_8_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_8_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_8_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_8, &style_sc_menu_label_menu_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_9
	ui->sc_menu_label_menu_9 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_9, 25, 824);
	lv_obj_set_size(ui->sc_menu_label_menu_9, 85, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_9, "天气");
	lv_label_set_long_mode(ui->sc_menu_label_menu_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_9_main_main_default
	static lv_style_t style_sc_menu_label_menu_9_main_main_default;
	if (style_sc_menu_label_menu_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_9_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_9_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_9_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_9_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_9, &style_sc_menu_label_menu_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_10
	ui->sc_menu_label_menu_10 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_10, 25, 910);
	lv_obj_set_size(ui->sc_menu_label_menu_10, 85, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_10, "消息");
	lv_label_set_long_mode(ui->sc_menu_label_menu_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_10_main_main_default
	static lv_style_t style_sc_menu_label_menu_10_main_main_default;
	if (style_sc_menu_label_menu_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_10_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_10_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_10_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_10_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_10_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_10, &style_sc_menu_label_menu_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_img_menu_7
	ui->sc_menu_img_menu_7 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_7, 37.5, 563);
	lv_obj_set_size(ui->sc_menu_img_menu_7, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_7_main_main_default
	static lv_style_t style_sc_menu_img_menu_7_main_main_default;
	if (style_sc_menu_img_menu_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_7_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_7_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_7_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_7_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_7, &style_sc_menu_img_menu_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_7,&_ICO2_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_7, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_7, 0);

	//Write codes sc_menu_label_menu_5
	ui->sc_menu_label_menu_5 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_5, 32.5, 452);
	lv_obj_set_size(ui->sc_menu_label_menu_5, 70, 26);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_5, "定时");
	lv_label_set_long_mode(ui->sc_menu_label_menu_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_5_main_main_default
	static lv_style_t style_sc_menu_label_menu_5_main_main_default;
	if (style_sc_menu_label_menu_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_5_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_5_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_5_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_5_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_5, &style_sc_menu_label_menu_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_img_menu_6
	ui->sc_menu_img_menu_6 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_6, 37.5, 478);
	lv_obj_set_size(ui->sc_menu_img_menu_6, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_6_main_main_default
	static lv_style_t style_sc_menu_img_menu_6_main_main_default;
	if (style_sc_menu_img_menu_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_6_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_6_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_6_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_6_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_6, &style_sc_menu_img_menu_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_6,&_second_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_6, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_6, 0);

	//Write codes sc_menu_label_menu_1
	ui->sc_menu_label_menu_1 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_1, 42, 69);
	lv_obj_set_size(ui->sc_menu_label_menu_1, 62, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_1, "心率");
	lv_label_set_long_mode(ui->sc_menu_label_menu_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_1_main_main_default
	static lv_style_t style_sc_menu_label_menu_1_main_main_default;
	if (style_sc_menu_label_menu_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_1_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_1_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_sc_menu_label_menu_1_main_main_default, 1);
	lv_style_set_shadow_color(&style_sc_menu_label_menu_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_shadow_opa(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_shadow_spread(&style_sc_menu_label_menu_1_main_main_default, 1);
	lv_style_set_shadow_ofs_x(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_1, &style_sc_menu_label_menu_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_2
	ui->sc_menu_label_menu_2 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_2, 0, 171);
	lv_obj_set_size(ui->sc_menu_label_menu_2, 135, 24);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_2, "血氧");
	lv_label_set_long_mode(ui->sc_menu_label_menu_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_2_main_main_default
	static lv_style_t style_sc_menu_label_menu_2_main_main_default;
	if (style_sc_menu_label_menu_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_2_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_2_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_2, &style_sc_menu_label_menu_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_menu_3
	ui->sc_menu_label_menu_3 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_menu_3, 8, 265);
	lv_obj_set_size(ui->sc_menu_label_menu_3, 119, 24);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_menu_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_menu_3, "运动");
	lv_label_set_long_mode(ui->sc_menu_label_menu_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_menu_3_main_main_default
	static lv_style_t style_sc_menu_label_menu_3_main_main_default;
	if (style_sc_menu_label_menu_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_menu_3_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_menu_3_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_menu_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_menu_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_menu_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_menu_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_menu_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_menu_label_menu_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_menu_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_menu_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_menu_3, &style_sc_menu_label_menu_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_img_menu_2
	ui->sc_menu_img_menu_2 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_2, 38.5, 107);
	lv_obj_set_size(ui->sc_menu_img_menu_2, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_2_main_main_default
	static lv_style_t style_sc_menu_img_menu_2_main_main_default;
	if (style_sc_menu_img_menu_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_2_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_2_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_2, &style_sc_menu_img_menu_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_2,&_ICO6_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_2, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_2, 0);

	//Write codes sc_menu_img_menu_3
	ui->sc_menu_img_menu_3 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_3, 38.5, 205);
	lv_obj_set_size(ui->sc_menu_img_menu_3, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_3_main_main_default
	static lv_style_t style_sc_menu_img_menu_3_main_main_default;
	if (style_sc_menu_img_menu_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_3_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_3, &style_sc_menu_img_menu_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_3,&_ioc_sport_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_3, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_3, 0);

	//Write codes sc_menu_img_menu_4
	ui->sc_menu_img_menu_4 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_4, 38.5, 295);
	lv_obj_set_size(ui->sc_menu_img_menu_4, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_4_main_main_default
	static lv_style_t style_sc_menu_img_menu_4_main_main_default;
	if (style_sc_menu_img_menu_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_4_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_4_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_4_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_4_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_4, &style_sc_menu_img_menu_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_4,&_timer_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_4, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_4, 0);

	//Write codes sc_menu_img_menu_5
	ui->sc_menu_img_menu_5 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_5, 38.5, 385);
	lv_obj_set_size(ui->sc_menu_img_menu_5, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_5_main_main_default
	static lv_style_t style_sc_menu_img_menu_5_main_main_default;
	if (style_sc_menu_img_menu_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_5_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_5_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_5_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_5_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_5, &style_sc_menu_img_menu_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_5,&_ICO3_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_5, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_5, 0);

	//Write codes sc_menu_img_menu_8
	ui->sc_menu_img_menu_8 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_menu_8, 37.5, 666);
	lv_obj_set_size(ui->sc_menu_img_menu_8, 60, 60);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_menu_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_menu_8_main_main_default
	static lv_style_t style_sc_menu_img_menu_8_main_main_default;
	if (style_sc_menu_img_menu_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_menu_8_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_menu_8_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_menu_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_menu_8_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_menu_8_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_menu_8, &style_sc_menu_img_menu_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_menu_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_menu_8,&_ICO7_60x60);
	lv_img_set_pivot(ui->sc_menu_img_menu_8, 0,0);
	lv_img_set_angle(ui->sc_menu_img_menu_8, 0);
}