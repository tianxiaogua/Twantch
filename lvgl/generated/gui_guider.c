/*
 * Copyright 2025 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void init_scr_del_flag(lv_ui *ui){
	ui->sc_main_del = true;
	ui->sc_heart_del = true;
	ui->sc_spo2_del = true;
	ui->sc_sport_del = true;
	ui->sc_menu_del = true;
	ui->sc_second_del = true;
	ui->sc_clock_del = true;
	ui->sc_light_del = true;
	ui->sc_weather_del = true;
	ui->sc_message_del = true;
	ui->screen_1_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_sc_main(ui);
	lv_scr_load(ui->sc_main);
}
