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


void setup_scr_sc_second(lv_ui *ui){

	//Write codes sc_second
	ui->sc_second = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_second, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_main_main_default
	static lv_style_t style_sc_second_main_main_default;
	if (style_sc_second_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_main_main_default);
	else
		lv_style_init(&style_sc_second_main_main_default);
	lv_style_set_bg_color(&style_sc_second_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_second_main_main_default, 255);
	lv_obj_add_style(ui->sc_second, &style_sc_second_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_second_img_1
	ui->sc_second_img_1 = lv_img_create(ui->sc_second);
	lv_obj_set_pos(ui->sc_second_img_1, 26, 259);
	lv_obj_set_size(ui->sc_second_img_1, 123, 44);
	lv_obj_set_scrollbar_mode(ui->sc_second_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_img_1_main_main_default
	static lv_style_t style_sc_second_img_1_main_main_default;
	if (style_sc_second_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_img_1_main_main_default);
	else
		lv_style_init(&style_sc_second_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_second_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_second_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_second_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_second_img_1, &style_sc_second_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_second_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_second_img_1,&_set_123x44);
	lv_img_set_pivot(ui->sc_second_img_1, 0,0);
	lv_img_set_angle(ui->sc_second_img_1, 0);

	//Write codes sc_second_img_2
	ui->sc_second_img_2 = lv_img_create(ui->sc_second);
	lv_obj_set_pos(ui->sc_second_img_2, 25, 40);
	lv_obj_set_size(ui->sc_second_img_2, 122, 44);
	lv_obj_set_scrollbar_mode(ui->sc_second_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_img_2_main_main_default
	static lv_style_t style_sc_second_img_2_main_main_default;
	if (style_sc_second_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_img_2_main_main_default);
	else
		lv_style_init(&style_sc_second_img_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_second_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_second_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_second_img_2_main_main_default, 123);
	lv_obj_add_style(ui->sc_second_img_2, &style_sc_second_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_second_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_second_img_2,&_set_122x44);
	lv_img_set_pivot(ui->sc_second_img_2, 0,0);
	lv_img_set_angle(ui->sc_second_img_2, 0);

	//Write codes sc_second_label_1
	ui->sc_second_label_1 = lv_label_create(ui->sc_second);
	lv_obj_set_pos(ui->sc_second_label_1, 36, 11);
	lv_obj_set_size(ui->sc_second_label_1, 100, 21);
	lv_obj_set_scrollbar_mode(ui->sc_second_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_second_label_1, "10:23 AM");
	lv_label_set_long_mode(ui->sc_second_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_label_1_main_main_default
	static lv_style_t style_sc_second_label_1_main_main_default;
	if (style_sc_second_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_label_1_main_main_default);
	else
		lv_style_init(&style_sc_second_label_1_main_main_default);
	lv_style_set_radius(&style_sc_second_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_second_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sc_second_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_second_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_second_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_second_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_second_label_1_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_sc_second_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_second_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_second_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_second_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_second_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_second_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_second_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_second_label_1, &style_sc_second_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_second_label_2
	ui->sc_second_label_2 = lv_label_create(ui->sc_second);
	lv_obj_set_pos(ui->sc_second_label_2, 36, 96);
	lv_obj_set_size(ui->sc_second_label_2, 100, 21);
	lv_obj_set_scrollbar_mode(ui->sc_second_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_second_label_2, "00:02:23");
	lv_label_set_long_mode(ui->sc_second_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_label_2_main_main_default
	static lv_style_t style_sc_second_label_2_main_main_default;
	if (style_sc_second_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_label_2_main_main_default);
	else
		lv_style_init(&style_sc_second_label_2_main_main_default);
	lv_style_set_radius(&style_sc_second_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_second_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sc_second_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_second_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_second_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_second_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_second_label_2_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_sc_second_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_second_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_second_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_second_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_second_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_second_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_second_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_second_label_2, &style_sc_second_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_second_img_3
	ui->sc_second_img_3 = lv_img_create(ui->sc_second);
	lv_obj_set_pos(ui->sc_second_img_3, 69, 265);
	lv_obj_set_size(ui->sc_second_img_3, 34, 32);
	lv_obj_set_scrollbar_mode(ui->sc_second_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_img_3_main_main_default
	static lv_style_t style_sc_second_img_3_main_main_default;
	if (style_sc_second_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_img_3_main_main_default);
	else
		lv_style_init(&style_sc_second_img_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_second_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_second_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_second_img_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_second_img_3, &style_sc_second_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_second_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_second_img_3,&_sey_start_34x32);
	lv_img_set_pivot(ui->sc_second_img_3, 0,0);
	lv_img_set_angle(ui->sc_second_img_3, 0);

	//Write codes sc_second_img_4
	ui->sc_second_img_4 = lv_img_create(ui->sc_second);
	lv_obj_set_pos(ui->sc_second_img_4, 69, 46);
	lv_obj_set_size(ui->sc_second_img_4, 35, 33);
	lv_obj_set_scrollbar_mode(ui->sc_second_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_second_img_4_main_main_default
	static lv_style_t style_sc_second_img_4_main_main_default;
	if (style_sc_second_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_second_img_4_main_main_default);
	else
		lv_style_init(&style_sc_second_img_4_main_main_default);
	lv_style_set_img_recolor(&style_sc_second_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_second_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_second_img_4_main_main_default, 255);
	lv_obj_add_style(ui->sc_second_img_4, &style_sc_second_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_second_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_second_img_4,&_reset_35x33);
	lv_img_set_pivot(ui->sc_second_img_4, 0,0);
	lv_img_set_angle(ui->sc_second_img_4, 0);
}