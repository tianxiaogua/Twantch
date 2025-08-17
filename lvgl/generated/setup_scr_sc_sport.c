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

	//Write codes sc_sport_bar_1
	ui->sc_sport_bar_1 = lv_bar_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_bar_1, 10.5, 33);
	lv_obj_set_size(ui->sc_sport_bar_1, 114, 20);
	lv_obj_set_scrollbar_mode(ui->sc_sport_bar_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_1_main_main_default
	static lv_style_t style_sc_sport_bar_1_main_main_default;
	if (style_sc_sport_bar_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_1_main_main_default);
	else
		lv_style_init(&style_sc_sport_bar_1_main_main_default);
	lv_style_set_radius(&style_sc_sport_bar_1_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_1_main_main_default, lv_color_make(0x00, 0xff, 0x62));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_1_main_main_default, 48);
	lv_style_set_shadow_width(&style_sc_sport_bar_1_main_main_default, 10);
	lv_style_set_shadow_color(&style_sc_sport_bar_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sc_sport_bar_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sc_sport_bar_1_main_main_default, 1);
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
	lv_obj_set_style_anim_time(ui->sc_sport_bar_1, 1000, 0);
	lv_bar_set_mode(ui->sc_sport_bar_1, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_sport_bar_1, 50, LV_ANIM_OFF);

	//Write codes sc_sport_bar_2
	ui->sc_sport_bar_2 = lv_bar_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_bar_2, 12.5, 107);
	lv_obj_set_size(ui->sc_sport_bar_2, 110, 20);
	lv_obj_set_scrollbar_mode(ui->sc_sport_bar_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_2_main_main_default
	static lv_style_t style_sc_sport_bar_2_main_main_default;
	if (style_sc_sport_bar_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_2_main_main_default);
	else
		lv_style_init(&style_sc_sport_bar_2_main_main_default);
	lv_style_set_radius(&style_sc_sport_bar_2_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_2_main_main_default, lv_color_make(0x00, 0xff, 0x62));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_2_main_main_default, 48);
	lv_style_set_shadow_width(&style_sc_sport_bar_2_main_main_default, 10);
	lv_style_set_shadow_color(&style_sc_sport_bar_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sc_sport_bar_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sc_sport_bar_2_main_main_default, 1);
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
	lv_obj_set_style_anim_time(ui->sc_sport_bar_2, 1000, 0);
	lv_bar_set_mode(ui->sc_sport_bar_2, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_sport_bar_2, 50, LV_ANIM_OFF);

	//Write codes sc_sport_img_1
	ui->sc_sport_img_1 = lv_img_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_img_1, 3, 7);
	lv_obj_set_size(ui->sc_sport_img_1, 20, 23);
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
	lv_img_set_src(ui->sc_sport_img_1,&_step_20x23);
	lv_img_set_pivot(ui->sc_sport_img_1, 0,0);
	lv_img_set_angle(ui->sc_sport_img_1, 0);

	//Write codes sc_sport_img_2
	ui->sc_sport_img_2 = lv_img_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_img_2, 3, 81);
	lv_obj_set_size(ui->sc_sport_img_2, 20, 20);
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
	lv_img_set_src(ui->sc_sport_img_2,&_calorie_20x20);
	lv_img_set_pivot(ui->sc_sport_img_2, 0,0);
	lv_img_set_angle(ui->sc_sport_img_2, 10);

	//Write codes sc_sport_img_3
	ui->sc_sport_img_3 = lv_img_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_img_3, 3, 160);
	lv_obj_set_size(ui->sc_sport_img_3, 20, 20);
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
	lv_img_set_src(ui->sc_sport_img_3,&_time_20x20);
	lv_img_set_pivot(ui->sc_sport_img_3, 0,0);
	lv_img_set_angle(ui->sc_sport_img_3, 10);

	//Write codes sc_sport_label_1
	ui->sc_sport_label_1 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_1, -5, 59);
	lv_obj_set_size(ui->sc_sport_label_1, 101, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_1, "122/10K");
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
	lv_style_set_text_color(&style_sc_sport_label_1_main_main_default, lv_color_make(0x6b, 0xff, 0xd5));
	lv_style_set_text_font(&style_sc_sport_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_1, &style_sc_sport_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_3
	ui->sc_sport_label_3 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_3, 88, 59);
	lv_obj_set_size(ui->sc_sport_label_3, 37, 17);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_3, "步数");
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
	lv_style_set_text_color(&style_sc_sport_label_3_main_main_default, lv_color_make(0x6b, 0xff, 0xd5));
	lv_style_set_text_font(&style_sc_sport_label_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_3, &style_sc_sport_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_5
	ui->sc_sport_label_5 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_5, 26.5, 12);
	lv_obj_set_size(ui->sc_sport_label_5, 82, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_5, "运动步数");
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
	lv_style_set_text_color(&style_sc_sport_label_5_main_main_default, lv_color_make(0x75, 0xff, 0xf6));
	lv_style_set_text_font(&style_sc_sport_label_5_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_5_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_5, &style_sc_sport_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_7
	ui->sc_sport_label_7 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_7, 26.5, 162);
	lv_obj_set_size(ui->sc_sport_label_7, 82, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_7, "活动时长");
	lv_label_set_long_mode(ui->sc_sport_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_7_main_main_default
	static lv_style_t style_sc_sport_label_7_main_main_default;
	if (style_sc_sport_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_7_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_7_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_7_main_main_default, lv_color_make(0xff, 0xeb, 0x6b));
	lv_style_set_text_font(&style_sc_sport_label_7_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_7_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_7, &style_sc_sport_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_6
	ui->sc_sport_label_6 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_6, 26.5, 86);
	lv_obj_set_size(ui->sc_sport_label_6, 82, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_6, "热量消耗");
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
	lv_style_set_text_color(&style_sc_sport_label_6_main_main_default, lv_color_make(0xf9, 0x93, 0x71));
	lv_style_set_text_font(&style_sc_sport_label_6_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_6_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_6, &style_sc_sport_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_2
	ui->sc_sport_label_2 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_2, -12, 136);
	lv_obj_set_size(ui->sc_sport_label_2, 100, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_2, "122/2K");
	lv_label_set_long_mode(ui->sc_sport_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_2_main_main_default
	static lv_style_t style_sc_sport_label_2_main_main_default;
	if (style_sc_sport_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_2_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_2_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_2_main_main_default, lv_color_make(0xe3, 0x6b, 0x2b));
	lv_style_set_text_font(&style_sc_sport_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_2, &style_sc_sport_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_8
	ui->sc_sport_label_8 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_8, -12, 211);
	lv_obj_set_size(ui->sc_sport_label_8, 100, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_8, "87/100");
	lv_label_set_long_mode(ui->sc_sport_label_8, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_8_main_main_default
	static lv_style_t style_sc_sport_label_8_main_main_default;
	if (style_sc_sport_label_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_8_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_8_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_8_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_8_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_8_main_main_default, lv_color_make(0xe7, 0xd5, 0x5a));
	lv_style_set_text_font(&style_sc_sport_label_8_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_8_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_8_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_8_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_8_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_8_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_8_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_8, &style_sc_sport_label_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_9
	ui->sc_sport_label_9 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_9, 88, 211);
	lv_obj_set_size(ui->sc_sport_label_9, 36, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_9, "分钟");
	lv_label_set_long_mode(ui->sc_sport_label_9, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_label_9_main_main_default
	static lv_style_t style_sc_sport_label_9_main_main_default;
	if (style_sc_sport_label_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_label_9_main_main_default);
	else
		lv_style_init(&style_sc_sport_label_9_main_main_default);
	lv_style_set_radius(&style_sc_sport_label_9_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_sport_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_sport_label_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_label_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_label_9_main_main_default, 0);
	lv_style_set_text_color(&style_sc_sport_label_9_main_main_default, lv_color_make(0xe7, 0xd5, 0x5a));
	lv_style_set_text_font(&style_sc_sport_label_9_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_9_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_9_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_9_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_9_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_9_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_9_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_9, &style_sc_sport_label_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_label_4
	ui->sc_sport_label_4 = lv_label_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_label_4, 88, 136);
	lv_obj_set_size(ui->sc_sport_label_4, 37, 15);
	lv_obj_set_scrollbar_mode(ui->sc_sport_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_sport_label_4, "大卡");
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
	lv_style_set_text_color(&style_sc_sport_label_4_main_main_default, lv_color_make(0xe3, 0x6b, 0x2b));
	lv_style_set_text_font(&style_sc_sport_label_4_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_sport_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_sc_sport_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_sport_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_sport_label_4_main_main_default, 0);
	lv_obj_add_style(ui->sc_sport_label_4, &style_sc_sport_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_sport_bar_3
	ui->sc_sport_bar_3 = lv_bar_create(ui->sc_sport);
	lv_obj_set_pos(ui->sc_sport_bar_3, 11, 185);
	lv_obj_set_size(ui->sc_sport_bar_3, 113, 20);
	lv_obj_set_scrollbar_mode(ui->sc_sport_bar_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_sport_bar_3_main_main_default
	static lv_style_t style_sc_sport_bar_3_main_main_default;
	if (style_sc_sport_bar_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_sport_bar_3_main_main_default);
	else
		lv_style_init(&style_sc_sport_bar_3_main_main_default);
	lv_style_set_radius(&style_sc_sport_bar_3_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_sport_bar_3_main_main_default, lv_color_make(0x00, 0xff, 0x62));
	lv_style_set_bg_grad_color(&style_sc_sport_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_sport_bar_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_sport_bar_3_main_main_default, 48);
	lv_style_set_shadow_width(&style_sc_sport_bar_3_main_main_default, 10);
	lv_style_set_shadow_color(&style_sc_sport_bar_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_sc_sport_bar_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sc_sport_bar_3_main_main_default, 1);
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
	lv_obj_set_style_anim_time(ui->sc_sport_bar_3, 1000, 0);
	lv_bar_set_mode(ui->sc_sport_bar_3, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_sport_bar_3, 50, LV_ANIM_OFF);
}