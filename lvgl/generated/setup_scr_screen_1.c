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


void setup_scr_screen_1(lv_ui *ui){

	//Write codes screen_1
	ui->screen_1 = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_main_main_default
	static lv_style_t style_screen_1_main_main_default;
	if (style_screen_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_main_main_default);
	else
		lv_style_init(&style_screen_1_main_main_default);
	lv_style_set_bg_color(&style_screen_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_screen_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_1, &style_screen_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_1_img_1
	ui->screen_1_img_1 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_1, 25, 35);
	lv_obj_set_size(ui->screen_1_img_1, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_1_main_main_default
	static lv_style_t style_screen_1_img_1_main_main_default;
	if (style_screen_1_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_1_main_main_default);
	else
		lv_style_init(&style_screen_1_img_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_1, &style_screen_1_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_1,&_NUM1_29x78);
	lv_img_set_pivot(ui->screen_1_img_1, 0,0);
	lv_img_set_angle(ui->screen_1_img_1, 0);

	//Write codes screen_1_img_2
	ui->screen_1_img_2 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_2, 62, 42);
	lv_obj_set_size(ui->screen_1_img_2, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_2_main_main_default
	static lv_style_t style_screen_1_img_2_main_main_default;
	if (style_screen_1_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_2_main_main_default);
	else
		lv_style_init(&style_screen_1_img_2_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_2_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_2, &style_screen_1_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_2,&_NUM0_29x78);
	lv_img_set_pivot(ui->screen_1_img_2, 0,0);
	lv_img_set_angle(ui->screen_1_img_2, 0);

	//Write codes screen_1_img_8
	ui->screen_1_img_8 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_8, 120, 88);
	lv_obj_set_size(ui->screen_1_img_8, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_8_main_main_default
	static lv_style_t style_screen_1_img_8_main_main_default;
	if (style_screen_1_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_8_main_main_default);
	else
		lv_style_init(&style_screen_1_img_8_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_8_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_8, &style_screen_1_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_8,&_NUM3_29x78);
	lv_img_set_pivot(ui->screen_1_img_8, 0,0);
	lv_img_set_angle(ui->screen_1_img_8, 0);

	//Write codes screen_1_img_7
	ui->screen_1_img_7 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_7, 62, 203);
	lv_obj_set_size(ui->screen_1_img_7, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_7_main_main_default
	static lv_style_t style_screen_1_img_7_main_main_default;
	if (style_screen_1_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_7_main_main_default);
	else
		lv_style_init(&style_screen_1_img_7_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_7_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_7, &style_screen_1_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_7,&_NUM6_29x78);
	lv_img_set_pivot(ui->screen_1_img_7, 0,0);
	lv_img_set_angle(ui->screen_1_img_7, 0);

	//Write codes screen_1_img_6
	ui->screen_1_img_6 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_6, 120, 175);
	lv_obj_set_size(ui->screen_1_img_6, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_6_main_main_default
	static lv_style_t style_screen_1_img_6_main_main_default;
	if (style_screen_1_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_6_main_main_default);
	else
		lv_style_init(&style_screen_1_img_6_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_6_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_6, &style_screen_1_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_6,&_NUM4_29x78);
	lv_img_set_pivot(ui->screen_1_img_6, 0,0);
	lv_img_set_angle(ui->screen_1_img_6, 0);

	//Write codes screen_1_img_5
	ui->screen_1_img_5 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_5, 91, 166);
	lv_obj_set_size(ui->screen_1_img_5, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_5_main_main_default
	static lv_style_t style_screen_1_img_5_main_main_default;
	if (style_screen_1_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_5_main_main_default);
	else
		lv_style_init(&style_screen_1_img_5_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_5_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_5, &style_screen_1_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_5,&_NUM5_29x78);
	lv_img_set_pivot(ui->screen_1_img_5, 0,0);
	lv_img_set_angle(ui->screen_1_img_5, 0);

	//Write codes screen_1_img_4
	ui->screen_1_img_4 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_4, 37, 166);
	lv_obj_set_size(ui->screen_1_img_4, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_4_main_main_default
	static lv_style_t style_screen_1_img_4_main_main_default;
	if (style_screen_1_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_4_main_main_default);
	else
		lv_style_init(&style_screen_1_img_4_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_4_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_4, &style_screen_1_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_4,&_NUM7_29x78);
	lv_img_set_pivot(ui->screen_1_img_4, 0,0);
	lv_img_set_angle(ui->screen_1_img_4, 0);

	//Write codes screen_1_img_3
	ui->screen_1_img_3 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_3, 98, 23);
	lv_obj_set_size(ui->screen_1_img_3, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_3_main_main_default
	static lv_style_t style_screen_1_img_3_main_main_default;
	if (style_screen_1_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_3_main_main_default);
	else
		lv_style_init(&style_screen_1_img_3_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_3_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_3, &style_screen_1_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_3,&_NUM8_29x78);
	lv_img_set_pivot(ui->screen_1_img_3, 0,0);
	lv_img_set_angle(ui->screen_1_img_3, 0);

	//Write codes screen_1_img_9
	ui->screen_1_img_9 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_9, 135, 72);
	lv_obj_set_size(ui->screen_1_img_9, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_9_main_main_default
	static lv_style_t style_screen_1_img_9_main_main_default;
	if (style_screen_1_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_9_main_main_default);
	else
		lv_style_init(&style_screen_1_img_9_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_9_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_9, &style_screen_1_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_9,&_NUM2_29x78);
	lv_img_set_pivot(ui->screen_1_img_9, 0,0);
	lv_img_set_angle(ui->screen_1_img_9, 0);

	//Write codes screen_1_img_10
	ui->screen_1_img_10 = lv_img_create(ui->screen_1);
	lv_obj_set_pos(ui->screen_1_img_10, 8, 166);
	lv_obj_set_size(ui->screen_1_img_10, 29, 78);
	lv_obj_set_scrollbar_mode(ui->screen_1_img_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_1_img_10_main_main_default
	static lv_style_t style_screen_1_img_10_main_main_default;
	if (style_screen_1_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_1_img_10_main_main_default);
	else
		lv_style_init(&style_screen_1_img_10_main_main_default);
	lv_style_set_img_recolor(&style_screen_1_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_1_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_1_img_10_main_main_default, 255);
	lv_obj_add_style(ui->screen_1_img_10, &style_screen_1_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_1_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_1_img_10,&_NUM9_29x78);
	lv_img_set_pivot(ui->screen_1_img_10, 0,0);
	lv_img_set_angle(ui->screen_1_img_10, 0);
}