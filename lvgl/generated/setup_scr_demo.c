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


void setup_scr_demo(lv_ui *ui){

	//Write codes demo
	ui->demo = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->demo, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_main_main_default
	static lv_style_t style_demo_main_main_default;
	if (style_demo_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_main_main_default);
	else
		lv_style_init(&style_demo_main_main_default);
	lv_style_set_bg_color(&style_demo_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_demo_main_main_default, 255);
	lv_obj_add_style(ui->demo, &style_demo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes demo_img_1
	ui->demo_img_1 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_1, 12, 18);
	lv_obj_set_size(ui->demo_img_1, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_1_main_main_default
	static lv_style_t style_demo_img_1_main_main_default;
	if (style_demo_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_1_main_main_default);
	else
		lv_style_init(&style_demo_img_1_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_1_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_1, &style_demo_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_1,&_NUM1_25x60);
	lv_img_set_pivot(ui->demo_img_1, 0,0);
	lv_img_set_angle(ui->demo_img_1, 0);

	//Write codes demo_img_2
	ui->demo_img_2 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_2, 42, 48);
	lv_obj_set_size(ui->demo_img_2, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_2_main_main_default
	static lv_style_t style_demo_img_2_main_main_default;
	if (style_demo_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_2_main_main_default);
	else
		lv_style_init(&style_demo_img_2_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_2_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_2, &style_demo_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_2,&_NUM2_25x60);
	lv_img_set_pivot(ui->demo_img_2, 0,0);
	lv_img_set_angle(ui->demo_img_2, 0);

	//Write codes demo_img_3
	ui->demo_img_3 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_3, 72, 78);
	lv_obj_set_size(ui->demo_img_3, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_3_main_main_default
	static lv_style_t style_demo_img_3_main_main_default;
	if (style_demo_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_3_main_main_default);
	else
		lv_style_init(&style_demo_img_3_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_3_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_3, &style_demo_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_3,&_NUM3_25x60);
	lv_img_set_pivot(ui->demo_img_3, 0,0);
	lv_img_set_angle(ui->demo_img_3, 0);

	//Write codes demo_img_4
	ui->demo_img_4 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_4, 17, 120);
	lv_obj_set_size(ui->demo_img_4, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_4_main_main_default
	static lv_style_t style_demo_img_4_main_main_default;
	if (style_demo_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_4_main_main_default);
	else
		lv_style_init(&style_demo_img_4_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_4_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_4, &style_demo_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_4,&_NUM4_25x60);
	lv_img_set_pivot(ui->demo_img_4, 0,0);
	lv_img_set_angle(ui->demo_img_4, 0);

	//Write codes demo_img_5
	ui->demo_img_5 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_5, 42, 138);
	lv_obj_set_size(ui->demo_img_5, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_5_main_main_default
	static lv_style_t style_demo_img_5_main_main_default;
	if (style_demo_img_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_5_main_main_default);
	else
		lv_style_init(&style_demo_img_5_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_5_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_5_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_5, &style_demo_img_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_5,&_NUM5_25x60);
	lv_img_set_pivot(ui->demo_img_5, 0,0);
	lv_img_set_angle(ui->demo_img_5, 0);

	//Write codes demo_img_6
	ui->demo_img_6 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_6, 72, 151);
	lv_obj_set_size(ui->demo_img_6, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_6_main_main_default
	static lv_style_t style_demo_img_6_main_main_default;
	if (style_demo_img_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_6_main_main_default);
	else
		lv_style_init(&style_demo_img_6_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_6_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_6_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_6, &style_demo_img_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_6,&_NUM6_25x60);
	lv_img_set_pivot(ui->demo_img_6, 0,0);
	lv_img_set_angle(ui->demo_img_6, 0);

	//Write codes demo_img_7
	ui->demo_img_7 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_7, 46, 7);
	lv_obj_set_size(ui->demo_img_7, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_7_main_main_default
	static lv_style_t style_demo_img_7_main_main_default;
	if (style_demo_img_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_7_main_main_default);
	else
		lv_style_init(&style_demo_img_7_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_7_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_7_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_7, &style_demo_img_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_7,&_NUM7_25x60);
	lv_img_set_pivot(ui->demo_img_7, 0,0);
	lv_img_set_angle(ui->demo_img_7, 0);

	//Write codes demo_img_8
	ui->demo_img_8 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_8, 85, 37);
	lv_obj_set_size(ui->demo_img_8, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_8_main_main_default
	static lv_style_t style_demo_img_8_main_main_default;
	if (style_demo_img_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_8_main_main_default);
	else
		lv_style_init(&style_demo_img_8_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_8_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_8_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_8, &style_demo_img_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_8,&_NUM8_25x60);
	lv_img_set_pivot(ui->demo_img_8, 0,0);
	lv_img_set_angle(ui->demo_img_8, 0);

	//Write codes demo_img_9
	ui->demo_img_9 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_9, 97, 157);
	lv_obj_set_size(ui->demo_img_9, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_9_main_main_default
	static lv_style_t style_demo_img_9_main_main_default;
	if (style_demo_img_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_9_main_main_default);
	else
		lv_style_init(&style_demo_img_9_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_9_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_9_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_9, &style_demo_img_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_9,&_NUM9_25x60);
	lv_img_set_pivot(ui->demo_img_9, 0,0);
	lv_img_set_angle(ui->demo_img_9, 0);

	//Write codes demo_img_10
	ui->demo_img_10 = lv_img_create(ui->demo);
	lv_obj_set_pos(ui->demo_img_10, 97, 90);
	lv_obj_set_size(ui->demo_img_10, 25, 60);
	lv_obj_set_scrollbar_mode(ui->demo_img_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_demo_img_10_main_main_default
	static lv_style_t style_demo_img_10_main_main_default;
	if (style_demo_img_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_demo_img_10_main_main_default);
	else
		lv_style_init(&style_demo_img_10_main_main_default);
	lv_style_set_img_recolor(&style_demo_img_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_demo_img_10_main_main_default, 0);
	lv_style_set_img_opa(&style_demo_img_10_main_main_default, 255);
	lv_obj_add_style(ui->demo_img_10, &style_demo_img_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->demo_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->demo_img_10,&_NUM0_25x60);
	lv_img_set_pivot(ui->demo_img_10, 0,0);
	lv_img_set_angle(ui->demo_img_10, 0);
}