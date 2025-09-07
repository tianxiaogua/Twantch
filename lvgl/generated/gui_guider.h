/*
 * Copyright 2025 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *sc_main;
	bool sc_main_del;
	lv_obj_t *sc_main_img_1;
	lv_obj_t *sc_main_img_2;
	lv_obj_t *sc_main_img_num_0;
	lv_obj_t *sc_main_img_num_1;
	lv_obj_t *sc_main_img_num_2;
	lv_obj_t *sc_main_img_num_3;
	lv_obj_t *sc_main_bar_battery;
	lv_obj_t *sc_menu;
	bool sc_menu_del;
	lv_obj_t *sc_menu_img_1;
	lv_obj_t *sc_menu_img_2;
	lv_obj_t *sc_menu_img_3;
	lv_obj_t *sc_menu_img_4;
	lv_obj_t *sc_menu_img_5;
	lv_obj_t *sc_menu_img_6;
	lv_obj_t *sc_menu_img_7;
	lv_obj_t *sc_menu_img_8;
	lv_obj_t *sc_menu_img_9;
	lv_obj_t *sc_menu_img_10;
	lv_obj_t *sc_menu_label_3;
	lv_obj_t *sc_menu_label_4;
	lv_obj_t *sc_menu_label_5;
	lv_obj_t *sc_menu_label_6;
	lv_obj_t *sc_menu_label_7;
	lv_obj_t *sc_menu_label_8;
	lv_obj_t *sc_menu_label_9;
	lv_obj_t *sc_menu_label_10;
	lv_obj_t *sc_menu_label_1;
	lv_obj_t *sc_menu_label_2;
	lv_obj_t *screen_1;
	bool screen_1_del;
	lv_obj_t *screen_1_img_1;
	lv_obj_t *screen_1_img_2;
	lv_obj_t *screen_1_img_8;
	lv_obj_t *screen_1_img_7;
	lv_obj_t *screen_1_img_6;
	lv_obj_t *screen_1_img_5;
	lv_obj_t *screen_1_img_4;
	lv_obj_t *screen_1_img_3;
	lv_obj_t *screen_1_img_9;
	lv_obj_t *screen_1_img_10;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_sc_main(lv_ui *ui);
void setup_scr_sc_menu(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);
LV_IMG_DECLARE(_ICO11_81x80);
LV_IMG_DECLARE(_NUM1_29x78);
LV_IMG_DECLARE(_ICO2_81x80);
LV_IMG_DECLARE(_NUM7_29x78);
LV_IMG_DECLARE(_ICO1_81x80);
LV_IMG_DECLARE(_NUM8_29x78);
LV_IMG_DECLARE(_ICO8_81x80);
LV_IMG_DECLARE(_ICO3_81x80);
LV_IMG_DECLARE(_NUM0_29x78);
LV_IMG_DECLARE(_2_172x320);
LV_IMG_DECLARE(_NUM9_29x78);
LV_IMG_DECLARE(_ICO7_81x80);
LV_IMG_DECLARE(_NUM4_29x78);
LV_IMG_DECLARE(_1_142x166);
LV_IMG_DECLARE(_NUM5_29x78);
LV_IMG_DECLARE(_ICO4_81x80);
LV_IMG_DECLARE(_ICO6_81x80);
LV_IMG_DECLARE(_NUM3_29x78);
LV_IMG_DECLARE(_NUM6_29x78);
LV_IMG_DECLARE(_ICO12_81x80);
LV_IMG_DECLARE(_NUM2_29x78);
LV_IMG_DECLARE(_ICO5_81x80);

#ifdef __cplusplus
}
#endif
#endif