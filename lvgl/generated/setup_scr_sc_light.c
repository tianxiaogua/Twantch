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


void setup_scr_sc_light(lv_ui *ui){

	//Write codes sc_light
	ui->sc_light = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sc_light, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_light_main_main_default
	static lv_style_t style_sc_light_main_main_default;
	if (style_sc_light_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_light_main_main_default);
	else
		lv_style_init(&style_sc_light_main_main_default);
	lv_style_set_bg_color(&style_sc_light_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_sc_light_main_main_default, 255);
	lv_obj_add_style(ui->sc_light, &style_sc_light_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sc_light_img_1
	ui->sc_light_img_1 = lv_img_create(ui->sc_light);
	lv_obj_set_pos(ui->sc_light_img_1, 61, 239);
	lv_obj_set_size(ui->sc_light_img_1, 52, 65);
	lv_obj_set_scrollbar_mode(ui->sc_light_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sc_light_img_1_main_main_default
	static lv_style_t style_sc_light_img_1_main_main_default;
	if (style_sc_light_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sc_light_img_1_main_main_default);
	else
		lv_style_init(&style_sc_light_img_1_main_main_default);
	lv_style_set_img_recolor(&style_sc_light_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sc_light_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_sc_light_img_1_main_main_default, 255);
	lv_obj_add_style(ui->sc_light_img_1, &style_sc_light_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->sc_light_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sc_light_img_1,&_light_52x65);
	lv_img_set_pivot(ui->sc_light_img_1, 0,0);
	lv_img_set_angle(ui->sc_light_img_1, 0);
}