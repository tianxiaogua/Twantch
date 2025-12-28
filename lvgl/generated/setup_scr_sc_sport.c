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


void setup_scr_sc_sport(lv_ui *ui){

	//Write codes sc_sport
	ui->sc_sport = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_sport, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_main_main_default
	static lv_style_t style_sc_sport_main_main_default;
	if (style_sc_sport_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_main_main_default);
	else
		lv_style_init(&style_sc_sport_main_main_default);
	lv_style_set_bg_color(&style_sc_sport_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_sport_main_main_default, 255);
	lv_obj_add_style(ui->sc_sport, &style_sc_sport_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_1
	ui->sc_sport_label_1 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_1, 43, 12);
	lv_obj_set_size(ui->sc_sport_label_1, 103, 21);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_1, "运动步数");
	lv_label_set_long_mode(ui->sc_sport_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_1_main_main_default
	static lv_style_t style_sc_sport_label_1_main_main_default;
	if (style_sc_sport_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_1_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_1_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_1_main_main_default, lv_color_make(0x66, 0xf0, 0xcd));
	lv_style_set_text_font(&style_sc_sport_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_sport_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_1, &style_sc_sport_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_img_1
	ui->sc_sport_img_1 = lv_img_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_img_1, 13, 4);
	lv_obj_set_size(ui->sc_sport_img_1, 30, 30);
	lv_obj_set_scrollbar_mode(ui->sc_sport_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_img_1_main_main_default
	static lv_style_t style_sc_sport_img_1_main_main_default;
	if (style_sc_sport_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_img_1_main_main_default);
	else
		lv_style_init(&style_sc_sport_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_sport_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_sport_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_sport_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_sport_img_1, &style_sc_sport_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_sport_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_sport_img_1,&_step_30x30);
	lv_img_set_pivot(ui->sc_sport_img_1, 0,0);
	lv_img_set_angle(ui->sc_sport_img_1, 0);

	//Write codes sc_sport_bar_1
	ui->sc_sport_bar_1 = lv_bar_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_bar_1, 25, 44);
	lv_obj_set_size(ui->sc_sport_bar_1, 123, 20);
	lv_obj_set_scrollbar_mode(ui->sc_sport_bar_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_1_main_main_default
	static lv_style_t style_sc_sport_bar_1_main_main_default;
	if (style_sc_sport_bar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_1_main_main_default);
	else
		lv_style_init(&style_sc_sport_bar_1_main_main_default);
	lv_style_set_radius(&style_sc_sport_bar_1_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_1_main_main_default, 60);
	lv_style_set_shadow_width(&style_sc_sport_bar_1_main_main_default, 2);
	lv_style_set_shadow_color(&style_sc_sport_bar_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sc_sport_bar_1_main_main_default, 149);
	lv_style_set_shadow_spread(&style_sc_sport_bar_1_main_main_default, 3);
	lv_style_set_shadow_ofs_x(&style_sc_sport_bar_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_sport_bar_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_bar_1, &style_sc_sport_bar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_1_main_indicator_default
	static lv_style_t style_sc_sport_bar_1_main_indicator_default;
	if (style_sc_sport_bar_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_1_main_indicator_default);
	else
		lv_style_init(&style_sc_sport_bar_1_main_indicator_default);
	lv_style_set_radius(&style_sc_sport_bar_1_main_indicator_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_1_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_1_main_indicator_default, 255);
	lv_obj_add_style(ui->sc_sport_bar_1, &style_sc_sport_bar_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->sc_sport_bar_1, 300, 0);
	lv_bar_set_mode(ui->sc_sport_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_sport_bar_1, 0, LV_ANIM_ON);

	//Write codes sc_sport_label_2
	ui->sc_sport_label_2 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_2, 36, 75);
	lv_obj_set_size(ui->sc_sport_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_2, "122");
	lv_label_set_long_mode(ui->sc_sport_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_2_main_main_default
	static lv_style_t style_sc_sport_label_2_main_main_default;
	if (style_sc_sport_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_2_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_2_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_2_main_main_default, lv_color_make(0x95, 0xc3, 0xe9));
	lv_style_set_bg_grad_color(&style_sc_sport_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_2_main_main_default, lv_color_make(0x35, 0xa7, 0xa5));
	lv_style_set_text_font(&style_sc_sport_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_sport_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_2, &style_sc_sport_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_img_2
	ui->sc_sport_img_2 = lv_img_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_img_2, 13, 107);
	lv_obj_set_size(ui->sc_sport_img_2, 30, 30);
	lv_obj_set_scrollbar_mode(ui->sc_sport_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_img_2_main_main_default
	static lv_style_t style_sc_sport_img_2_main_main_default;
	if (style_sc_sport_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_img_2_main_main_default);
	else
		lv_style_init(&style_sc_sport_img_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_sport_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_sport_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_sport_img_2_main_main_default, 255);
	lv_obj_add_style(ui->sc_sport_img_2, &style_sc_sport_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_sport_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_sport_img_2,&_calorie_30x30);
	lv_img_set_pivot(ui->sc_sport_img_2, 0,0);
	lv_img_set_angle(ui->sc_sport_img_2, 0);

	//Write codes sc_sport_label_3
	ui->sc_sport_label_3 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_3, 48, 114);
	lv_obj_set_size(ui->sc_sport_label_3, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_3, "热量消耗");
	lv_label_set_long_mode(ui->sc_sport_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_3_main_main_default
	static lv_style_t style_sc_sport_label_3_main_main_default;
	if (style_sc_sport_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_3_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_3_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_3_main_main_default, lv_color_make(0xeb, 0x66, 0x1e));
	lv_style_set_text_font(&style_sc_sport_label_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_sport_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_3, &style_sc_sport_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_bar_2
	ui->sc_sport_bar_2 = lv_bar_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_bar_2, 30, 150);
	lv_obj_set_size(ui->sc_sport_bar_2, 113, 20);
	lv_obj_set_scrollbar_mode(ui->sc_sport_bar_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_2_main_main_default
	static lv_style_t style_sc_sport_bar_2_main_main_default;
	if (style_sc_sport_bar_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_2_main_main_default);
	else
		lv_style_init(&style_sc_sport_bar_2_main_main_default);
	lv_style_set_radius(&style_sc_sport_bar_2_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_2_main_main_default, 60);
	lv_style_set_shadow_width(&style_sc_sport_bar_2_main_main_default, 2);
	lv_style_set_shadow_color(&style_sc_sport_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sc_sport_bar_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sc_sport_bar_2_main_main_default, 3);
	lv_style_set_shadow_ofs_x(&style_sc_sport_bar_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_sport_bar_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_bar_2, &style_sc_sport_bar_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_2_main_indicator_default
	static lv_style_t style_sc_sport_bar_2_main_indicator_default;
	if (style_sc_sport_bar_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_2_main_indicator_default);
	else
		lv_style_init(&style_sc_sport_bar_2_main_indicator_default);
	lv_style_set_radius(&style_sc_sport_bar_2_main_indicator_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_2_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_2_main_indicator_default, 255);
	lv_obj_add_style(ui->sc_sport_bar_2, &style_sc_sport_bar_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->sc_sport_bar_2, 300, 0);
	lv_bar_set_mode(ui->sc_sport_bar_2, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_sport_bar_2, 0, LV_ANIM_ON);

	//Write codes sc_sport_label_4
	ui->sc_sport_label_4 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_4, 44, 189);
	lv_obj_set_size(ui->sc_sport_label_4, 85, 19);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_4, "1222K");
	lv_label_set_long_mode(ui->sc_sport_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_4_main_main_default
	static lv_style_t style_sc_sport_label_4_main_main_default;
	if (style_sc_sport_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_4_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_4_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_4_main_main_default, lv_color_make(0xf0, 0x69, 0x3d));
	lv_style_set_text_font(&style_sc_sport_label_4_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_sport_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_4, &style_sc_sport_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_img_3
	ui->sc_sport_img_3 = lv_img_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_img_3, 13, 216);
	lv_obj_set_size(ui->sc_sport_img_3, 30, 30);
	lv_obj_set_scrollbar_mode(ui->sc_sport_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_img_3_main_main_default
	static lv_style_t style_sc_sport_img_3_main_main_default;
	if (style_sc_sport_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_img_3_main_main_default);
	else
		lv_style_init(&style_sc_sport_img_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_sport_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_sport_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_sport_img_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_sport_img_3, &style_sc_sport_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_sport_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_sport_img_3,&_time_30x30);
	lv_img_set_pivot(ui->sc_sport_img_3, 0,0);
	lv_img_set_angle(ui->sc_sport_img_3, 0);

	//Write codes sc_sport_label_5
	ui->sc_sport_label_5 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_5, 48, 222);
	lv_obj_set_size(ui->sc_sport_label_5, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_5, "活动时长");
	lv_label_set_long_mode(ui->sc_sport_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_5_main_main_default
	static lv_style_t style_sc_sport_label_5_main_main_default;
	if (style_sc_sport_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_5_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_5_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_5_main_main_default, lv_color_make(0xff, 0xaf, 0x24));
	lv_style_set_text_font(&style_sc_sport_label_5_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_sport_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_5_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_5, &style_sc_sport_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_bar_3
	ui->sc_sport_bar_3 = lv_bar_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_bar_3, 31, 254);
	lv_obj_set_size(ui->sc_sport_bar_3, 117, 20);
	lv_obj_set_scrollbar_mode(ui->sc_sport_bar_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_3_main_main_default
	static lv_style_t style_sc_sport_bar_3_main_main_default;
	if (style_sc_sport_bar_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_3_main_main_default);
	else
		lv_style_init(&style_sc_sport_bar_3_main_main_default);
	lv_style_set_radius(&style_sc_sport_bar_3_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_3_main_main_default, 60);
	lv_style_set_shadow_width(&style_sc_sport_bar_3_main_main_default, 2);
	lv_style_set_shadow_color(&style_sc_sport_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sc_sport_bar_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sc_sport_bar_3_main_main_default, 3);
	lv_style_set_shadow_ofs_x(&style_sc_sport_bar_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_sport_bar_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_bar_3, &style_sc_sport_bar_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_3_main_indicator_default
	static lv_style_t style_sc_sport_bar_3_main_indicator_default;
	if (style_sc_sport_bar_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_3_main_indicator_default);
	else
		lv_style_init(&style_sc_sport_bar_3_main_indicator_default);
	lv_style_set_radius(&style_sc_sport_bar_3_main_indicator_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_3_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_3_main_indicator_default, 255);
	lv_obj_add_style(ui->sc_sport_bar_3, &style_sc_sport_bar_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->sc_sport_bar_3, 300, 0);
	lv_bar_set_mode(ui->sc_sport_bar_3, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_sport_bar_3, 0, LV_ANIM_ON);

	//Write codes sc_sport_label_6
	ui->sc_sport_label_6 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_6, 36, 286);
	lv_obj_set_size(ui->sc_sport_label_6, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_6, "78min");
	lv_label_set_long_mode(ui->sc_sport_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_6_main_main_default
	static lv_style_t style_sc_sport_label_6_main_main_default;
	if (style_sc_sport_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_6_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_6_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_6_main_main_default, lv_color_make(0xff, 0xbb, 0x00));
	lv_style_set_text_font(&style_sc_sport_label_6_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_sport_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_6_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_6, &style_sc_sport_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}