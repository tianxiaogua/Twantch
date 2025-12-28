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


void setup_scr_sc_clock(lv_ui *ui){

	//Write codes sc_clock
	ui->sc_clock = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_clock, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_clock_main_main_default
	static lv_style_t style_sc_clock_main_main_default;
	if (style_sc_clock_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_clock_main_main_default);
	else
		lv_style_init(&style_sc_clock_main_main_default);
	lv_style_set_bg_color(&style_sc_clock_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_sc_clock_main_main_default, 255);
	lv_obj_add_style(ui->sc_clock, &style_sc_clock_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_clock_label_1
	ui->sc_clock_label_1 = lv_label_create(ui->sc_clock);
	lv_obj_set_pos(ui->sc_clock_label_1, 36, 21);
	lv_obj_set_size(ui->sc_clock_label_1, 100, 32);
	lv_obj_set_scrollbar_mode(ui->sc_clock_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_clock_label_1, "设置时间");
	lv_label_set_long_mode(ui->sc_clock_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_clock_label_1_main_main_default
	static lv_style_t style_sc_clock_label_1_main_main_default;
	if (style_sc_clock_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_clock_label_1_main_main_default);
	else
		lv_style_init(&style_sc_clock_label_1_main_main_default);
	lv_style_set_radius(&style_sc_clock_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_clock_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_clock_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_clock_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_clock_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_sc_clock_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_clock_label_1_main_main_default, &lv_font_dingliehuobanfont20241217_2_20);
	lv_style_set_text_letter_space(&style_sc_clock_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_clock_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_sc_clock_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_clock_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_sc_clock_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_sc_clock_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_sc_clock_label_1_main_main_default, 0);
	lv_obj_add_style(ui->sc_clock_label_1, &style_sc_clock_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_clock_label_2
	ui->sc_clock_label_2 = lv_label_create(ui->sc_clock);
	lv_obj_set_pos(ui->sc_clock_label_2, 34, 151);
	lv_obj_set_size(ui->sc_clock_label_2, 105, 33);
	lv_obj_set_scrollbar_mode(ui->sc_clock_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->sc_clock_label_2, "12时分");
	lv_label_set_long_mode(ui->sc_clock_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_sc_clock_label_2_main_main_default
	static lv_style_t style_sc_clock_label_2_main_main_default;
	if (style_sc_clock_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_clock_label_2_main_main_default);
	else
		lv_style_init(&style_sc_clock_label_2_main_main_default);
	lv_style_set_radius(&style_sc_clock_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_sc_clock_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_clock_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_clock_label_2_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_sc_clock_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_sc_clock_label_2_main_main_default, 2);
	lv_style_set_shadow_color(&style_sc_clock_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_shadow_opa(&style_sc_clock_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_sc_clock_label_2_main_main_default, 2);
	lv_style_set_shadow_ofs_x(&style_sc_clock_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_clock_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_sc_clock_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_clock_label_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_letter_space(&style_sc_clock_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_sc_clock_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_sc_clock_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_sc_clock_label_2_main_main_default, 2);
	lv_style_set_pad_right(&style_sc_clock_label_2_main_main_default, 2);
	lv_style_set_pad_top(&style_sc_clock_label_2_main_main_default, 2);
	lv_style_set_pad_bottom(&style_sc_clock_label_2_main_main_default, 2);
	lv_obj_add_style(ui->sc_clock_label_2, &style_sc_clock_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_clock_btn_2
	ui->sc_clock_btn_2 = lv_btn_create(ui->sc_clock);
	lv_obj_set_pos(ui->sc_clock_btn_2, 45, 79);
	lv_obj_set_size(ui->sc_clock_btn_2, 83, 37);
	lv_obj_set_scrollbar_mode(ui->sc_clock_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_clock_btn_2_main_main_default
	static lv_style_t style_sc_clock_btn_2_main_main_default;
	if (style_sc_clock_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_clock_btn_2_main_main_default);
	else
		lv_style_init(&style_sc_clock_btn_2_main_main_default);
	lv_style_set_radius(&style_sc_clock_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_sc_clock_btn_2_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sc_clock_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_clock_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_clock_btn_2_main_main_default, 255);
	lv_style_set_border_color(&style_sc_clock_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sc_clock_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_sc_clock_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_sc_clock_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_clock_btn_2_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_align(&style_sc_clock_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->sc_clock_btn_2, &style_sc_clock_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->sc_clock_btn_2_label = lv_label_create(ui->sc_clock_btn_2);
	lv_label_set_text(ui->sc_clock_btn_2_label, "↑");
	lv_obj_set_style_pad_all(ui->sc_clock_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->sc_clock_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes sc_clock_btn_3
	ui->sc_clock_btn_3 = lv_btn_create(ui->sc_clock);
	lv_obj_set_pos(ui->sc_clock_btn_3, 45, 225);
	lv_obj_set_size(ui->sc_clock_btn_3, 83, 37);
	lv_obj_set_scrollbar_mode(ui->sc_clock_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_clock_btn_3_main_main_default
	static lv_style_t style_sc_clock_btn_3_main_main_default;
	if (style_sc_clock_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_clock_btn_3_main_main_default);
	else
		lv_style_init(&style_sc_clock_btn_3_main_main_default);
	lv_style_set_radius(&style_sc_clock_btn_3_main_main_default, 5);
	lv_style_set_bg_color(&style_sc_clock_btn_3_main_main_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_sc_clock_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_clock_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_clock_btn_3_main_main_default, 255);
	lv_style_set_border_color(&style_sc_clock_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_sc_clock_btn_3_main_main_default, 0);
	lv_style_set_border_opa(&style_sc_clock_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_sc_clock_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_sc_clock_btn_3_main_main_default, &lv_font_dingliehuobanfont20241217_2_29);
	lv_style_set_text_align(&style_sc_clock_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->sc_clock_btn_3, &style_sc_clock_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->sc_clock_btn_3_label = lv_label_create(ui->sc_clock_btn_3);
	lv_label_set_text(ui->sc_clock_btn_3_label, "↓");
	lv_obj_set_style_pad_all(ui->sc_clock_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->sc_clock_btn_3_label, LV_ALIGN_CENTER, 0, 0);
}