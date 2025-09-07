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

	//Write codes sc_menu_img_1
	ui->sc_menu_img_1 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_1, 46, 1);
	lv_obj_set_size(ui->sc_menu_img_1, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_1_main_main_default
	static lv_style_t style_sc_menu_img_1_main_main_default;
	if (style_sc_menu_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_1_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_1, &style_sc_menu_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_1,&_ICO5_81x80);
	lv_img_set_pivot(ui->sc_menu_img_1, 0,0);
	lv_img_set_angle(ui->sc_menu_img_1, 0);

	//Write codes sc_menu_img_2
	ui->sc_menu_img_2 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_2, 46, 141);
	lv_obj_set_size(ui->sc_menu_img_2, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_2_main_main_default
	static lv_style_t style_sc_menu_img_2_main_main_default;
	if (style_sc_menu_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_2_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_2_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_2, &style_sc_menu_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_2,&_ICO6_81x80);
	lv_img_set_pivot(ui->sc_menu_img_2, 0,0);
	lv_img_set_angle(ui->sc_menu_img_2, 0);

	//Write codes sc_menu_img_3
	ui->sc_menu_img_3 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_3, 46, 276);
	lv_obj_set_size(ui->sc_menu_img_3, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_3_main_main_default
	static lv_style_t style_sc_menu_img_3_main_main_default;
	if (style_sc_menu_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_3_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_3, &style_sc_menu_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_3,&_ICO8_81x80);
	lv_img_set_pivot(ui->sc_menu_img_3, 0,0);
	lv_img_set_angle(ui->sc_menu_img_3, 0);

	//Write codes sc_menu_img_4
	ui->sc_menu_img_4 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_4, 46, 415);
	lv_obj_set_size(ui->sc_menu_img_4, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_4_main_main_default
	static lv_style_t style_sc_menu_img_4_main_main_default;
	if (style_sc_menu_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_4_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_4_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_4_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_4, &style_sc_menu_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_4,&_ICO12_81x80);
	lv_img_set_pivot(ui->sc_menu_img_4, 0,0);
	lv_img_set_angle(ui->sc_menu_img_4, 0);

	//Write codes sc_menu_img_5
	ui->sc_menu_img_5 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_5, 55, 563);
	lv_obj_set_size(ui->sc_menu_img_5, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_5_main_main_default
	static lv_style_t style_sc_menu_img_5_main_main_default;
	if (style_sc_menu_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_5_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_5_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_5_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_5, &style_sc_menu_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_5,&_ICO3_81x80);
	lv_img_set_pivot(ui->sc_menu_img_5, 0,0);
	lv_img_set_angle(ui->sc_menu_img_5, 0);

	//Write codes sc_menu_img_6
	ui->sc_menu_img_6 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_6, 46, 694);
	lv_obj_set_size(ui->sc_menu_img_6, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_6_main_main_default
	static lv_style_t style_sc_menu_img_6_main_main_default;
	if (style_sc_menu_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_6_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_6_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_6_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_6, &style_sc_menu_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_6,&_ICO11_81x80);
	lv_img_set_pivot(ui->sc_menu_img_6, 0,0);
	lv_img_set_angle(ui->sc_menu_img_6, 0);

	//Write codes sc_menu_img_7
	ui->sc_menu_img_7 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_7, 46, 845);
	lv_obj_set_size(ui->sc_menu_img_7, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_7_main_main_default
	static lv_style_t style_sc_menu_img_7_main_main_default;
	if (style_sc_menu_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_7_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_7_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_7_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_7, &style_sc_menu_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_7,&_ICO7_81x80);
	lv_img_set_pivot(ui->sc_menu_img_7, 0,0);
	lv_img_set_angle(ui->sc_menu_img_7, 0);

	//Write codes sc_menu_img_8
	ui->sc_menu_img_8 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_8, 36, 990);
	lv_obj_set_size(ui->sc_menu_img_8, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_8_main_main_default
	static lv_style_t style_sc_menu_img_8_main_main_default;
	if (style_sc_menu_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_8_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_8_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_8_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_8, &style_sc_menu_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_8,&_ICO1_81x80);
	lv_img_set_pivot(ui->sc_menu_img_8, 0,0);
	lv_img_set_angle(ui->sc_menu_img_8, 0);

	//Write codes sc_menu_img_9
	ui->sc_menu_img_9 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_9, 36, 1146);
	lv_obj_set_size(ui->sc_menu_img_9, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_9_main_main_default
	static lv_style_t style_sc_menu_img_9_main_main_default;
	if (style_sc_menu_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_9_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_9_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_9_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_9, &style_sc_menu_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_9,&_ICO4_81x80);
	lv_img_set_pivot(ui->sc_menu_img_9, 0,0);
	lv_img_set_angle(ui->sc_menu_img_9, 0);

	//Write codes sc_menu_img_10
	ui->sc_menu_img_10 = lv_img_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_img_10, 36, 1273);
	lv_obj_set_size(ui->sc_menu_img_10, 81, 80);
	lv_obj_set_scrollbar_mode(ui->sc_menu_img_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_img_10_main_main_default
	static lv_style_t style_sc_menu_img_10_main_main_default;
	if (style_sc_menu_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_img_10_main_main_default);
	else
		lv_style_init(&style_sc_menu_img_10_main_main_default);
	lv_style_set_img_recolor(&style_sc_menu_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_menu_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_menu_img_10_main_main_default, 255);
	lv_obj_add_style(ui->sc_menu_img_10, &style_sc_menu_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_menu_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_menu_img_10,&_ICO2_81x80);
	lv_img_set_pivot(ui->sc_menu_img_10, 0,0);
	lv_img_set_angle(ui->sc_menu_img_10, 0);

	//Write codes sc_menu_label_3
	ui->sc_menu_label_3 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_3, 36, 370);
	lv_obj_set_size(ui->sc_menu_label_3, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_3, "运动");
	lv_label_set_long_mode(ui->sc_menu_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_3_main_main_default
	static lv_style_t style_sc_menu_label_3_main_main_default;
	if (style_sc_menu_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_3_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_3_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_3, &style_sc_menu_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_4
	ui->sc_menu_label_4 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_4, 36, 510);
	lv_obj_set_size(ui->sc_menu_label_4, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_4, "闹钟");
	lv_label_set_long_mode(ui->sc_menu_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_4_main_main_default
	static lv_style_t style_sc_menu_label_4_main_main_default;
	if (style_sc_menu_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_4_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_4_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_4_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_4, &style_sc_menu_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_5
	ui->sc_menu_label_5 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_5, 45, 653);
	lv_obj_set_size(ui->sc_menu_label_5, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_5, "定时");
	lv_label_set_long_mode(ui->sc_menu_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_5_main_main_default
	static lv_style_t style_sc_menu_label_5_main_main_default;
	if (style_sc_menu_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_5_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_5_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_5_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_5_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_5, &style_sc_menu_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_6
	ui->sc_menu_label_6 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_6, 45, 798);
	lv_obj_set_size(ui->sc_menu_label_6, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_6, "秒表");
	lv_label_set_long_mode(ui->sc_menu_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_6_main_main_default
	static lv_style_t style_sc_menu_label_6_main_main_default;
	if (style_sc_menu_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_6_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_6_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_6_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_6_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_6, &style_sc_menu_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_7
	ui->sc_menu_label_7 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_7, 36, 943);
	lv_obj_set_size(ui->sc_menu_label_7, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_7, "手电筒");
	lv_label_set_long_mode(ui->sc_menu_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_7_main_main_default
	static lv_style_t style_sc_menu_label_7_main_main_default;
	if (style_sc_menu_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_7_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_7_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_7_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_7, &style_sc_menu_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_8
	ui->sc_menu_label_8 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_8, 26, 1090);
	lv_obj_set_size(ui->sc_menu_label_8, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_8, "天气");
	lv_label_set_long_mode(ui->sc_menu_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_8_main_main_default
	static lv_style_t style_sc_menu_label_8_main_main_default;
	if (style_sc_menu_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_8_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_8_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_8_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_8_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_8, &style_sc_menu_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_9
	ui->sc_menu_label_9 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_9, 26, 1241);
	lv_obj_set_size(ui->sc_menu_label_9, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_9, "消息");
	lv_label_set_long_mode(ui->sc_menu_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_9_main_main_default
	static lv_style_t style_sc_menu_label_9_main_main_default;
	if (style_sc_menu_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_9_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_9_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_9_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_9_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_9, &style_sc_menu_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_10
	ui->sc_menu_label_10 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_10, 26, 1362);
	lv_obj_set_size(ui->sc_menu_label_10, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_10, "设置");
	lv_label_set_long_mode(ui->sc_menu_label_10, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_10_main_main_default
	static lv_style_t style_sc_menu_label_10_main_main_default;
	if (style_sc_menu_label_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_10_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_10_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_10_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_10_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_10_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_10_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_10_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_10_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_10_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_10_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_10_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_10_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_10, &style_sc_menu_label_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_1
	ui->sc_menu_label_1 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_1, 36, 94);
	lv_obj_set_size(ui->sc_menu_label_1, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_1, "心率");
	lv_label_set_long_mode(ui->sc_menu_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_1_main_main_default
	static lv_style_t style_sc_menu_label_1_main_main_default;
	if (style_sc_menu_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_1_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_1_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_1, &style_sc_menu_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_menu_label_2
	ui->sc_menu_label_2 = lv_label_create(ui->sc_menu);
	lv_obj_set_pos(ui->sc_menu_label_2, 36, 238);
	lv_obj_set_size(ui->sc_menu_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_menu_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_menu_label_2, "血氧");
	lv_label_set_long_mode(ui->sc_menu_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_menu_label_2_main_main_default
	static lv_style_t style_sc_menu_label_2_main_main_default;
	if (style_sc_menu_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_menu_label_2_main_main_default);
	else
		lv_style_init(&style_sc_menu_label_2_main_main_default);
	lv_style_set_radius(&style_sc_menu_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_menu_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_menu_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_menu_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_menu_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_menu_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_menu_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_menu_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_menu_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_menu_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_menu_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_menu_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_menu_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_menu_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_menu_label_2, &style_sc_menu_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}