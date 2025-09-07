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


void setup_scr_sc_main(lv_ui *ui){

	//Write codes sc_main
	ui->sc_main = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_main, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_main_main_default
	static lv_style_t style_sc_main_main_main_default;
	if (style_sc_main_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_main_main_default);
	else
		lv_style_init(&style_sc_main_main_main_default);
	lv_style_set_bg_color(&style_sc_main_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_sc_main_main_main_default, 0);
	lv_obj_add_style(ui->sc_main, &style_sc_main_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_main_img_1
	ui->sc_main_img_1 = lv_img_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_img_1, 0, 0);
	lv_obj_set_size(ui->sc_main_img_1, 172, 320);
	lv_obj_set_scrollbar_mode(ui->sc_main_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_img_1_main_main_default
	static lv_style_t style_sc_main_img_1_main_main_default;
	if (style_sc_main_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_img_1_main_main_default);
	else
		lv_style_init(&style_sc_main_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_main_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_main_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_main_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_main_img_1, &style_sc_main_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_main_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_main_img_1,&_2_172x320);
	lv_img_set_pivot(ui->sc_main_img_1, 0,0);
	lv_img_set_angle(ui->sc_main_img_1, 0);

	//Write codes sc_main_img_2
	ui->sc_main_img_2 = lv_img_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_img_2, -66, 146);
	lv_obj_set_size(ui->sc_main_img_2, 142, 166);
	lv_obj_set_scrollbar_mode(ui->sc_main_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_img_2_main_main_default
	static lv_style_t style_sc_main_img_2_main_main_default;
	if (style_sc_main_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_img_2_main_main_default);
	else
		lv_style_init(&style_sc_main_img_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_main_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_main_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_main_img_2_main_main_default, 255);
	lv_obj_add_style(ui->sc_main_img_2, &style_sc_main_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_main_img_2, LV_OBJ_FLAG_CLICKABLE);

	//Update pos for widget sc_main_img_2
	lv_obj_update_layout(ui->sc_main_img_2);

	//Write animation: sc_main_img_2move in x direction
	lv_anim_t sc_main_img_2_x;
	lv_anim_init(&sc_main_img_2_x);
	lv_anim_set_var(&sc_main_img_2_x, ui->sc_main_img_2);
	lv_anim_set_time(&sc_main_img_2_x, 1000);
	lv_anim_set_exec_cb(&sc_main_img_2_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
	lv_anim_set_values(&sc_main_img_2_x, lv_obj_get_x(ui->sc_main_img_2), 6);
	lv_anim_set_path_cb(&sc_main_img_2_x, lv_anim_path_ease_out);
	lv_anim_start(&sc_main_img_2_x);

	//Write animation: sc_main_img_2move in y direction
	lv_anim_t sc_main_img_2_y;
	lv_anim_init(&sc_main_img_2_y);
	lv_anim_set_var(&sc_main_img_2_y, ui->sc_main_img_2);
	lv_anim_set_time(&sc_main_img_2_y, 1000);
	lv_anim_set_exec_cb(&sc_main_img_2_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
	lv_anim_set_values(&sc_main_img_2_y, lv_obj_get_y(ui->sc_main_img_2), 144);
	lv_anim_set_path_cb(&sc_main_img_2_y, lv_anim_path_ease_out);
	lv_anim_start(&sc_main_img_2_y);

	lv_img_set_src(ui->sc_main_img_2,&_1_142x166);
	lv_img_set_pivot(ui->sc_main_img_2, 0,0);
	lv_img_set_angle(ui->sc_main_img_2, 0);

	//Write codes sc_main_img_num_0
	ui->sc_main_img_num_0 = lv_img_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_img_num_0, 10, 31);
	lv_obj_set_size(ui->sc_main_img_num_0, 29, 78);
	lv_obj_set_scrollbar_mode(ui->sc_main_img_num_0, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_img_num_0_main_main_default
	static lv_style_t style_sc_main_img_num_0_main_main_default;
	if (style_sc_main_img_num_0_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_img_num_0_main_main_default);
	else
		lv_style_init(&style_sc_main_img_num_0_main_main_default);
	lv_style_set_img_recolor(&style_sc_main_img_num_0_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_main_img_num_0_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_main_img_num_0_main_main_default, 255);
	lv_obj_add_style(ui->sc_main_img_num_0, &style_sc_main_img_num_0_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_main_img_num_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_main_img_num_0,&_NUM5_29x78);
	lv_img_set_pivot(ui->sc_main_img_num_0, 0,0);
	lv_img_set_angle(ui->sc_main_img_num_0, 0);

	//Write codes sc_main_img_num_1
	ui->sc_main_img_num_1 = lv_img_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_img_num_1, 39, 31);
	lv_obj_set_size(ui->sc_main_img_num_1, 29, 78);
	lv_obj_set_scrollbar_mode(ui->sc_main_img_num_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_img_num_1_main_main_default
	static lv_style_t style_sc_main_img_num_1_main_main_default;
	if (style_sc_main_img_num_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_img_num_1_main_main_default);
	else
		lv_style_init(&style_sc_main_img_num_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_main_img_num_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_main_img_num_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_main_img_num_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_main_img_num_1, &style_sc_main_img_num_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_main_img_num_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_main_img_num_1,&_NUM5_29x78);
	lv_img_set_pivot(ui->sc_main_img_num_1, 0,0);
	lv_img_set_angle(ui->sc_main_img_num_1, 0);

	//Write codes sc_main_img_num_2
	ui->sc_main_img_num_2 = lv_img_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_img_num_2, 95, 31);
	lv_obj_set_size(ui->sc_main_img_num_2, 29, 78);
	lv_obj_set_scrollbar_mode(ui->sc_main_img_num_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_img_num_2_main_main_default
	static lv_style_t style_sc_main_img_num_2_main_main_default;
	if (style_sc_main_img_num_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_img_num_2_main_main_default);
	else
		lv_style_init(&style_sc_main_img_num_2_main_main_default);
	lv_style_set_img_recolor(&style_sc_main_img_num_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_main_img_num_2_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_main_img_num_2_main_main_default, 255);
	lv_obj_add_style(ui->sc_main_img_num_2, &style_sc_main_img_num_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_main_img_num_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_main_img_num_2,&_NUM5_29x78);
	lv_img_set_pivot(ui->sc_main_img_num_2, 0,0);
	lv_img_set_angle(ui->sc_main_img_num_2, 0);

	//Write codes sc_main_img_num_3
	ui->sc_main_img_num_3 = lv_img_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_img_num_3, 131, 31);
	lv_obj_set_size(ui->sc_main_img_num_3, 29, 78);
	lv_obj_set_scrollbar_mode(ui->sc_main_img_num_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_img_num_3_main_main_default
	static lv_style_t style_sc_main_img_num_3_main_main_default;
	if (style_sc_main_img_num_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_img_num_3_main_main_default);
	else
		lv_style_init(&style_sc_main_img_num_3_main_main_default);
	lv_style_set_img_recolor(&style_sc_main_img_num_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_main_img_num_3_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_main_img_num_3_main_main_default, 255);
	lv_obj_add_style(ui->sc_main_img_num_3, &style_sc_main_img_num_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_main_img_num_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_main_img_num_3,&_NUM5_29x78);
	lv_img_set_pivot(ui->sc_main_img_num_3, 0,0);
	lv_img_set_angle(ui->sc_main_img_num_3, 0);

	//Write codes sc_main_bar_battery
	ui->sc_main_bar_battery = lv_bar_create(ui->sc_main);
	lv_obj_set_pos(ui->sc_main_bar_battery, 61, 9);
	lv_obj_set_size(ui->sc_main_bar_battery, 51, 6);
	lv_obj_set_scrollbar_mode(ui->sc_main_bar_battery, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_bar_battery_main_main_default
	static lv_style_t style_sc_main_bar_battery_main_main_default;
	if (style_sc_main_bar_battery_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_bar_battery_main_main_default);
	else
		lv_style_init(&style_sc_main_bar_battery_main_main_default);
	lv_style_set_radius(&style_sc_main_bar_battery_main_main_default, 10);
	lv_style_set_bg_color(&style_sc_main_bar_battery_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_sc_main_bar_battery_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_sc_main_bar_battery_main_main_default, LV_GRAD_DIR_HOR);
	lv_style_set_bg_opa(&style_sc_main_bar_battery_main_main_default, 124);
	lv_style_set_shadow_width(&style_sc_main_bar_battery_main_main_default, 2);
	lv_style_set_shadow_color(&style_sc_main_bar_battery_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_shadow_opa(&style_sc_main_bar_battery_main_main_default, 196);
	lv_style_set_shadow_spread(&style_sc_main_bar_battery_main_main_default, 2);
	lv_style_set_shadow_ofs_x(&style_sc_main_bar_battery_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_sc_main_bar_battery_main_main_default, 0);
	lv_obj_add_style(ui->sc_main_bar_battery, &style_sc_main_bar_battery_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_sc_main_bar_battery_main_indicator_default
	static lv_style_t style_sc_main_bar_battery_main_indicator_default;
	if (style_sc_main_bar_battery_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_sc_main_bar_battery_main_indicator_default);
	else
		lv_style_init(&style_sc_main_bar_battery_main_indicator_default);
	lv_style_set_radius(&style_sc_main_bar_battery_main_indicator_default, 10);
	lv_style_set_bg_color(&style_sc_main_bar_battery_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_sc_main_bar_battery_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_sc_main_bar_battery_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_sc_main_bar_battery_main_indicator_default, 255);
	lv_obj_add_style(ui->sc_main_bar_battery, &style_sc_main_bar_battery_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_anim_time(ui->sc_main_bar_battery, 600, 0);
	lv_bar_set_mode(ui->sc_main_bar_battery, LV_BAR_MODE_NORMAL);
	lv_bar_set_value(ui->sc_main_bar_battery, 80, LV_ANIM_ON);
}