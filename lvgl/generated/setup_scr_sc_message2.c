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


void setup_scr_sc_message2(lv_ui *ui){

	//Write codes sc_message2
	ui->sc_message2 = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_message2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_main_main_default
	static lv_style_t style_sc_message2_main_main_default;
	if (style_sc_message2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_main_main_default);
	else
		lv_style_init(&style_sc_message2_main_main_default);
	lv_style_set_bg_color(&style_sc_message2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_message2_main_main_default, 255);
	lv_obj_add_style(ui->sc_message2, &style_sc_message2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_message2_img_2
	ui->sc_message2_img_2 = lv_img_create(ui->sc_message2);
	lv_obj_set_pos(ui->sc_message2_img_2, 52, 206);
	lv_obj_set_size(ui->sc_message2_img_2, 30, 30);
	lv_obj_set_scrollbar_mode(ui->sc_message2_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_img_2_main_main_default
	static lv_style_t style_sc_message2_img_2_main_main_default;
	if (style_sc_message2_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_img_2_main_main_default);
	else
		lv_style_init(&style_sc_message2_img_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_message2_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_message2_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_message2_img_2_main_main_default, 255);
	lv_obj_add_style(ui->sc_message2_img_2, &style_sc_message2_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_message2_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_message2_img_2,&_delete_30x30);
	lv_img_set_pivot(ui->sc_message2_img_2, 0,0);
	lv_img_set_angle(ui->sc_message2_img_2, 0);

	//Write codes sc_message2_cont_1
	ui->sc_message2_cont_1 = lv_obj_create(ui->sc_message2);
	lv_obj_set_pos(ui->sc_message2_cont_1, 0, 3);
	lv_obj_set_size(ui->sc_message2_cont_1, 135, 81);
	lv_obj_set_scrollbar_mode(ui->sc_message2_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_cont_1_main_main_default
	static lv_style_t style_sc_message2_cont_1_main_main_default;
	if (style_sc_message2_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_cont_1_main_main_default);
	else
		lv_style_init(&style_sc_message2_cont_1_main_main_default);
	lv_style_set_radius(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_message2_cont_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sc_message2_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_message2_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_border_color(&style_sc_message2_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_pad_left(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_message2_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_message2_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_message2_cont_1, &style_sc_message2_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_message2_label_3
	ui->sc_message2_label_3 = lv_label_create(ui->sc_message2_cont_1);
	lv_obj_set_pos(ui->sc_message2_label_3, 35, 10);
	lv_obj_set_size(ui->sc_message2_label_3, 90, 17);
	lv_obj_set_scrollbar_mode(ui->sc_message2_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_message2_label_3, "微信");
	lv_label_set_long_mode(ui->sc_message2_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_label_3_main_main_default
	static lv_style_t style_sc_message2_label_3_main_main_default;
	if (style_sc_message2_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_label_3_main_main_default);
	else
		lv_style_init(&style_sc_message2_label_3_main_main_default);
	lv_style_set_radius(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_message2_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_message2_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_message2_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_sc_message2_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_message2_label_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_16);
	lv_style_set_text_letter_space(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_text_line_space(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_sc_message2_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_message2_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_message2_label_3_main_main_default, 0);
	lv_obj_add_style(ui->sc_message2_label_3, &style_sc_message2_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_message2_label_2
	ui->sc_message2_label_2 = lv_label_create(ui->sc_message2_cont_1);
	lv_obj_set_pos(ui->sc_message2_label_2, 3, 35);
	lv_obj_set_size(ui->sc_message2_label_2, 130, 70);
	lv_obj_set_scrollbar_mode(ui->sc_message2_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_message2_label_2, "[18条]这是一条新消息通知.。动画表情");
	lv_label_set_long_mode(ui->sc_message2_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_label_2_main_main_default
	static lv_style_t style_sc_message2_label_2_main_main_default;
	if (style_sc_message2_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_label_2_main_main_default);
	else
		lv_style_init(&style_sc_message2_label_2_main_main_default);
	lv_style_set_radius(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_message2_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_message2_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_message2_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_message2_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_message2_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_24);
	lv_style_set_text_letter_space(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_text_line_space(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_message2_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_message2_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_message2_label_2_main_main_default, 0);
	lv_obj_add_style(ui->sc_message2_label_2, &style_sc_message2_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_message2_img_3
	ui->sc_message2_img_3 = lv_img_create(ui->sc_message2_cont_1);
	lv_obj_set_pos(ui->sc_message2_img_3, 5, 1);
	lv_obj_set_size(ui->sc_message2_img_3, 30, 30);
	lv_obj_set_scrollbar_mode(ui->sc_message2_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_img_3_main_main_default
	static lv_style_t style_sc_message2_img_3_main_main_default;
	if (style_sc_message2_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_img_3_main_main_default);
	else
		lv_style_init(&style_sc_message2_img_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_message2_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_message2_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_message2_img_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_message2_img_3, &style_sc_message2_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_message2_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_message2_img_3,&_rng_30x30);
	lv_img_set_pivot(ui->sc_message2_img_3, 0,0);
	lv_img_set_angle(ui->sc_message2_img_3, 0);

	//Write codes sc_message2_line_1
	ui->sc_message2_line_1 = lv_line_create(ui->sc_message2_cont_1);
	lv_obj_set_pos(ui->sc_message2_line_1, 7, 115);
	lv_obj_set_size(ui->sc_message2_line_1, 118, 4);
	lv_obj_set_scrollbar_mode(ui->sc_message2_line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_message2_line_1_main_main_default
	static lv_style_t style_sc_message2_line_1_main_main_default;
	if (style_sc_message2_line_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_message2_line_1_main_main_default);
	else
		lv_style_init(&style_sc_message2_line_1_main_main_default);
	lv_style_set_line_color(&style_sc_message2_line_1_main_main_default, lv_color_make(0x75, 0x75, 0x75));
	lv_style_set_line_width(&style_sc_message2_line_1_main_main_default, 2);
	lv_style_set_line_rounded(&style_sc_message2_line_1_main_main_default, true);
	lv_obj_add_style(ui->sc_message2_line_1, &style_sc_message2_line_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t sc_message2_line_1[] ={{0, 0},{130, 0},};
	lv_line_set_points(ui->sc_message2_line_1,sc_message2_line_1,2);
}