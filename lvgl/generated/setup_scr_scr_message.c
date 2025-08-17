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


void setup_scr_scr_message(lv_ui *ui){

	//Write codes scr_message
	ui->scr_message = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->scr_message, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scr_message_main_main_default
	static lv_style_t style_scr_message_main_main_default;
	if (style_scr_message_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scr_message_main_main_default);
	else
		lv_style_init(&style_scr_message_main_main_default);
	lv_style_set_bg_color(&style_scr_message_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_scr_message_main_main_default, 255);
	lv_obj_add_style(ui->scr_message, &style_scr_message_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes scr_message_img_1
	ui->scr_message_img_1 = lv_img_create(ui->scr_message);
	lv_obj_set_pos(ui->scr_message_img_1, 37.5, 90);
	lv_obj_set_size(ui->scr_message_img_1, 60, 60);
	lv_obj_set_scrollbar_mode(ui->scr_message_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_scr_message_img_1_main_main_default
	static lv_style_t style_scr_message_img_1_main_main_default;
	if (style_scr_message_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scr_message_img_1_main_main_default);
	else
		lv_style_init(&style_scr_message_img_1_main_main_default);
	lv_style_set_img_recolor(&style_scr_message_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_scr_message_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_scr_message_img_1_main_main_default, 255);
	lv_obj_add_style(ui->scr_message_img_1, &style_scr_message_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->scr_message_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->scr_message_img_1,&_message_60x60);
	lv_img_set_pivot(ui->scr_message_img_1, 0,0);
	lv_img_set_angle(ui->scr_message_img_1, 0);

	//Write codes scr_message_label_1
	ui->scr_message_label_1 = lv_label_create(ui->scr_message);
	lv_obj_set_pos(ui->scr_message_label_1, 25, 171);
	lv_obj_set_size(ui->scr_message_label_1, 85, 33);
	lv_obj_set_scrollbar_mode(ui->scr_message_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->scr_message_label_1, "无通知");
	lv_label_set_long_mode(ui->scr_message_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_scr_message_label_1_main_main_default
	static lv_style_t style_scr_message_label_1_main_main_default;
	if (style_scr_message_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_scr_message_label_1_main_main_default);
	else
		lv_style_init(&style_scr_message_label_1_main_main_default);
	lv_style_set_radius(&style_scr_message_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_scr_message_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_scr_message_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_scr_message_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_scr_message_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_scr_message_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_scr_message_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_scr_message_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_scr_message_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_scr_message_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_scr_message_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_scr_message_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_scr_message_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_scr_message_label_1_main_main_default, 0);
	lv_obj_add_style(ui->scr_message_label_1, &style_scr_message_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}