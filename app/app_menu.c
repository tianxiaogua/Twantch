#include "lvgl.h"
#include  "app_menu.h"
#include <stdlib.h>

#include "stdio.h"

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "driver_usart.h"
#include "lcd_init.h"

#define CARTOON_TIME  (80) // 动画时间
#define SCREEN_HEIGHT LCD_H // 屏幕高度
#define SCREEN_WIDTH  LCD_W // 屏幕宽度

#define IMG_HEIGHT    (80)  // 图片高度
#define LABEL_HEIGHT  (40)  // 文本高度

#define IMG_LENGTH    (IMG_HEIGHT + LABEL_HEIGHT + 6) // 图标之间中心距离
#define I_L_DISTANCE  (IMG_HEIGHT + 2)  // 图标和文字的中心距离
#define POSION_X      ((SCREEN_WIDTH - IMG_HEIGHT) / 2) // 图片横坐标位置
#define POSION_Y      (((SCREEN_HEIGHT - IMG_HEIGHT) / 2)-10) // 中心图标纵坐标位置

static KEY_TYPE g_event_type;
static lv_indev_t *g_indev_encoder;
static lv_obj_t * img[SCREEN_MENU_MAX];
static lv_obj_t * label[SCREEN_MENU_MAX];
int32_t g_menu_status = SCREEN_MENU_RATE;

static void menu_lvgl_init_menu_font(lv_ui *ui)
{
   label[0] = ui->sc_menu_label_1;
   label[1] = ui->sc_menu_label_2;
   label[2] = ui->sc_menu_label_3;
   label[3] = ui->sc_menu_label_4;
   label[4] = ui->sc_menu_label_5;
   label[5] = ui->sc_menu_label_6;
   label[6] = ui->sc_menu_label_7;
   label[7] = ui->sc_menu_label_8;
   label[8] = ui->sc_menu_label_9;
    GUA_LOGI("inti font\r\n");
    return;
}


static void menu_lvgl_init_menu_image(lv_ui *ui)
{
   img[0] = ui->sc_menu_img_1;
   img[1] = ui->sc_menu_img_2;
   img[2] = ui->sc_menu_img_3;
   img[3] = ui->sc_menu_img_4;
   img[4] = ui->sc_menu_img_5;
   img[5] = ui->sc_menu_img_6;
   img[6] = ui->sc_menu_img_7;
   img[7] = ui->sc_menu_img_8;
   img[8] = ui->sc_menu_img_9;
    GUA_LOGI("image font\r\n");
    return;
}

// 动画完成回调函数
static void menu_lvgl_scroll_anim_ready_cb(lv_anim_t * a)
{

}

static void menu_lvgl_play_anim_rotate_y(lv_obj_t * img_obj, int32_t start, int32_t end)
{
    // 创建动画对象
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, img_obj);
    lv_anim_set_exec_cb(&anim, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&anim, start,  end);
    lv_anim_set_time(&anim, CARTOON_TIME); // 动画时间300ms
    lv_anim_set_ready_cb(&anim, menu_lvgl_scroll_anim_ready_cb);
    lv_anim_start(&anim);
}


static void menu_lvgl_down_set_menu()
{
    int32_t move_y_start, move_y_end;
    int16_t num_temp[10];
    uint16_t i = 0;

    g_menu_status ++;
    if (g_menu_status > SCREEN_MENU_MAX-1){
        g_menu_status = 0;
    }

    for (i=0; i<SCREEN_MENU_MAX; i++) {
        if (i<SCREEN_MENU_MAX-g_menu_status) {
            num_temp[i] = g_menu_status+i;
        } else {
            num_temp[i] = i-(SCREEN_MENU_MAX-g_menu_status);
        }
        // GUA_LOGN("%d ", num_temp[i]);
    }
    // GUA_LOGN("\r\n");

    for (i=0; i< SCREEN_MENU_MAX; i++) {
        if (i < 3) {
            move_y_start = ((POSION_Y + (i+1)*IMG_LENGTH));
            move_y_end   = ((POSION_Y + i*IMG_LENGTH));
        } else {
            move_y_start = ((POSION_Y -(SCREEN_MENU_MAX-i-1)*IMG_LENGTH));
            move_y_end   = ((POSION_Y -(SCREEN_MENU_MAX-i)*IMG_LENGTH));
        }

        menu_lvgl_play_anim_rotate_y(img[num_temp[i]],   move_y_start, move_y_end);
        menu_lvgl_play_anim_rotate_y(label[num_temp[i]], move_y_start + I_L_DISTANCE,  move_y_end+ I_L_DISTANCE);

        // GUA_LOGI("menu_status[%d] num[%d] now[%d] move_y[%d]\r\n", g_menu_status, num_temp[i], move_y_start, move_y_end);
    }
}

static void menu_lvgl_up_set_menu()
{
    int32_t move_y_start, move_y_end;
    int16_t num_temp[10];
    uint16_t i = 0;

    g_menu_status --;
    if (g_menu_status < 0){
        g_menu_status = SCREEN_MENU_MAX-1;
    }

    for (i=0; i<SCREEN_MENU_MAX; i++) {
        if (i<SCREEN_MENU_MAX-g_menu_status) {
            num_temp[i] = g_menu_status+i;
        } else {
            num_temp[i] = i-(SCREEN_MENU_MAX-g_menu_status);
        }
        // GUA_LOGN("%d ", num_temp[i]);
    }
    // GUA_LOGN("\r\n");

    for (i=0; i< SCREEN_MENU_MAX; i++) {
        if (i < 3) {
            move_y_start = ((POSION_Y + (i-1)*IMG_LENGTH));
            move_y_end   = ((POSION_Y + i*IMG_LENGTH));
        } else {
            move_y_start = ((POSION_Y -(SCREEN_MENU_MAX-i+1)*IMG_LENGTH));
            move_y_end   = ((POSION_Y -(SCREEN_MENU_MAX-i)*IMG_LENGTH));
        }

        menu_lvgl_play_anim_rotate_y(img[num_temp[i]],   move_y_start,  move_y_end);
        menu_lvgl_play_anim_rotate_y(label[num_temp[i]], move_y_start + I_L_DISTANCE,  move_y_end + I_L_DISTANCE);

        // GUA_LOGI("menu_status[%d] num[%d] now[%d] move_y[%d]\r\n", g_menu_status, num_temp[i], move_y_start, move_y_end);
    }
}

// 编码器处理回调函数
static void menu_lvgl_encoder_handler(lv_event_t * e)
{
    GUA_LOGI("lv_event_get_code %d menu_status %d\r\n", g_event_type, g_menu_status);

    if (g_event_type == KEY_TYPE_UP || g_event_type == KEY_TYPE_UP_LONG) {
        menu_lvgl_down_set_menu();
    } else if(g_event_type == KEY_TYPE_DOWN || g_event_type == KEY_TYPE_DOWN_LONG) {
        menu_lvgl_up_set_menu();
    }
}


int32 app_menu_lvgl_setup(lv_ui *ui, lv_obj_t * parent)
{
    lv_group_t *group = lv_group_create();
    uint16_t i = 0;
    uint16_t location = 0;
    int32 posion_y = 0;

    GUA_LOGI("init app menu, g_menu_status:[%d]\r\n", g_menu_status);

    menu_lvgl_init_menu_font(ui);
    menu_lvgl_init_menu_image(ui);
    lv_indev_set_group(g_indev_encoder, group);

    for (i=0; i< SCREEN_MENU_MAX; i++) {
        lv_group_add_obj(group, img[i]);
        lv_obj_add_event_cb(img[i], menu_lvgl_encoder_handler, LV_EVENT_KEY, NULL);
    }

    location = g_menu_status;
    for (i=0; i<SCREEN_MENU_MAX-2; i++) {
        posion_y = POSION_Y + (i)*IMG_LENGTH;
        lv_obj_set_pos(img[location], POSION_X, posion_y);
        lv_obj_align(label[location], LV_ALIGN_TOP_MID, 0, 0); // 水平居中
        lv_obj_set_y(label[location], posion_y + I_L_DISTANCE); // 纵坐标固定

        location ++;
        if (location >= SCREEN_MENU_MAX) {
            location = 0;
        }
    }

    for (i=0; i<2; i++) {
        posion_y = POSION_Y - (2-i)*IMG_LENGTH;
        lv_obj_set_pos(img[location], POSION_X, posion_y);
        lv_obj_align(label[location], LV_ALIGN_TOP_MID, 0, 0); // 水平居中
        lv_obj_set_y(label[location], posion_y + I_L_DISTANCE); // 纵坐标固定
        location ++;
        if (location >= SCREEN_MENU_MAX) {
            location = 0;
        }
    }

    return REV_OK;
}

int32 app_menu_lvgl_get_id(void)
{
    return g_menu_status;
}

int32 app_menu_lvgl_set_indev(lv_indev_t *indev_encoder)
{
    g_indev_encoder = indev_encoder;
    return REV_OK;
}

int32 app_menu_lvgl_set_event_key(KEY_TYPE type)
{
    g_event_type = type;
    return REV_OK;
}
