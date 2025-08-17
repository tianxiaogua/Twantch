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


void setup_scr_sc_timer(lv_ui *ui){

	//Write codes sc_timer
	ui->sc_timer = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_timer, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_main_main_default
	static lv_style_t style_sc_timer_main_main_default;
	if (style_sc_timer_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_main_main_default);
	else
		lv_style_init(&style_sc_timer_main_main_default);
	lv_style_set_bg_color(&style_sc_timer_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_timer_main_main_default, 255);
	lv_obj_add_style(ui->sc_timer, &style_sc_timer_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_timer_label_1
	ui->sc_timer_label_1 = lv_label_create(ui->sc_timer);
	lv_obj_set_pos(ui->sc_timer_label_1, 13, 70);
	lv_obj_set_size(ui->sc_timer_label_1, 108, 26);
	lv_obj_set_scrollbar_mode(ui->sc_timer_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_timer_label_1, "00:02:23");
	lv_label_set_long_mode(ui->sc_timer_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_label_1_main_main_default
	static lv_style_t style_sc_timer_label_1_main_main_default;
	if (style_sc_timer_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_label_1_main_main_default);
	else
		lv_style_init(&style_sc_timer_label_1_main_main_default);
	lv_style_set_radius(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_timer_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sc_timer_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_timer_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_timer_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_timer_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_timer_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_timer_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_timer_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_timer_label_1, &style_sc_timer_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_timer_img_1
	ui->sc_timer_img_1 = lv_img_create(ui->sc_timer);
	lv_obj_set_pos(ui->sc_timer_img_1, 9, 196);
	lv_obj_set_size(ui->sc_timer_img_1, 116, 38);
	lv_obj_set_scrollbar_mode(ui->sc_timer_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_img_1_main_main_default
	static lv_style_t style_sc_timer_img_1_main_main_default;
	if (style_sc_timer_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_img_1_main_main_default);
	else
		lv_style_init(&style_sc_timer_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_timer_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_timer_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_timer_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_timer_img_1, &style_sc_timer_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_timer_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_timer_img_1,&_set_116x38);
	lv_img_set_pivot(ui->sc_timer_img_1, 0,0);
	lv_img_set_angle(ui->sc_timer_img_1, 0);

	//Write codes sc_timer_img_2
	ui->sc_timer_img_2 = lv_img_create(ui->sc_timer);
	lv_obj_set_pos(ui->sc_timer_img_2, 9, 22);
	lv_obj_set_size(ui->sc_timer_img_2, 116, 38);
	lv_obj_set_scrollbar_mode(ui->sc_timer_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_img_2_main_main_default
	static lv_style_t style_sc_timer_img_2_main_main_default;
	if (style_sc_timer_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_img_2_main_main_default);
	else
		lv_style_init(&style_sc_timer_img_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_timer_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_timer_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_timer_img_2_main_main_default, 117);
	lv_obj_add_style(ui->sc_timer_img_2, &style_sc_timer_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_timer_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_timer_img_2,&_set_116x38);
	lv_img_set_pivot(ui->sc_timer_img_2, 0,0);
	lv_img_set_angle(ui->sc_timer_img_2, 0);

	//Write codes sc_timer_label_2
	ui->sc_timer_label_2 = lv_label_create(ui->sc_timer);
	lv_obj_set_pos(ui->sc_timer_label_2, 22.5, 3);
	lv_obj_set_size(ui->sc_timer_label_2, 90, 15);
	lv_obj_set_scrollbar_mode(ui->sc_timer_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_timer_label_2, "10:23 AM");
	lv_label_set_long_mode(ui->sc_timer_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_label_2_main_main_default
	static lv_style_t style_sc_timer_label_2_main_main_default;
	if (style_sc_timer_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_label_2_main_main_default);
	else
		lv_style_init(&style_sc_timer_label_2_main_main_default);
	lv_style_set_radius(&style_sc_timer_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_timer_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_timer_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_timer_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_timer_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_timer_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_timer_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_timer_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_timer_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_timer_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_timer_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_timer_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_timer_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_timer_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_timer_label_2, &style_sc_timer_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_timer_img_3
	ui->sc_timer_img_3 = lv_img_create(ui->sc_timer);
	lv_obj_set_pos(ui->sc_timer_img_3, 52, 26);
	lv_obj_set_size(ui->sc_timer_img_3, 31, 28);
	lv_obj_set_scrollbar_mode(ui->sc_timer_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_img_3_main_main_default
	static lv_style_t style_sc_timer_img_3_main_main_default;
	if (style_sc_timer_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_img_3_main_main_default);
	else
		lv_style_init(&style_sc_timer_img_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_timer_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_timer_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_timer_img_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_timer_img_3, &style_sc_timer_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_timer_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_timer_img_3,&_reset2_31x28);
	lv_img_set_pivot(ui->sc_timer_img_3, 0,0);
	lv_img_set_angle(ui->sc_timer_img_3, 0);

	//Write codes sc_timer_img_4
	ui->sc_timer_img_4 = lv_img_create(ui->sc_timer);
	lv_obj_set_pos(ui->sc_timer_img_4, 52, 200);
	lv_obj_set_size(ui->sc_timer_img_4, 30, 30);
	lv_obj_set_scrollbar_mode(ui->sc_timer_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_timer_img_4_main_main_default
	static lv_style_t style_sc_timer_img_4_main_main_default;
	if (style_sc_timer_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_timer_img_4_main_main_default);
	else
		lv_style_init(&style_sc_timer_img_4_main_main_default);
	lv_style_set_img_recolor(&style_sc_timer_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_timer_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_timer_img_4_main_main_default, 255);
	lv_obj_add_style(ui->sc_timer_img_4, &style_sc_timer_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_timer_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_timer_img_4,&_sey_start_30x30);
	lv_img_set_pivot(ui->sc_timer_img_4, 0,0);
	lv_img_set_angle(ui->sc_timer_img_4, 0);
}