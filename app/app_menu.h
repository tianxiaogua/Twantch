#ifndef APP_MENU_H
#define APP_MENU_H

#include "lvgl.h"
#include "gui_guider.h"
#include "driver_tool.h"
#include "driver_key.h"

// 心率 血氧 运动 闹钟 定时 秒表 设置 手电筒 天气 消息
typedef enum {
    SCREEN_MENU_RATE   = 0,
    SCREEN_MENU_OXY    = 1,
    SCREEN_MENU_SPORT  = 2,
    SCREEN_MENU_CLOCK  = 3,
    SCREEN_MENU_TIC    = 4,
    SCREEN_MENU_TIMER  = 5,
    SCREEN_MENU_SET    = 6,
    SCREEN_MENU_LIT    = 7,
    SCREEN_MENU_WEAT   = 8,
    SCREEN_MENU_MSG    = 9,

    SCREEN_MENU_MAX,
} MENU_DEFINE;

typedef void (*app_menu_callback)(MENU_DEFINE id);

int32 app_menu_lvgl_set_indev(lv_indev_t *indev_encoder);
int32 app_menu_lvgl_set_event_key(KEY_TYPE type);
int32 app_menu_lvgl_setup(lv_ui *ui, lv_obj_t * parent);
int32 app_menu_lvgl_get_id(void);

#endif

