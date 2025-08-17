/*
*---------------------------------------------------------------
*                        Lvgl Font Tool
*
* 注:使用unicode编码
* 注:本字体文件由Lvgl Font Tool V0.4 生成
* 作者:阿里(qq:617622104)
*---------------------------------------------------------------
*/


#include "lvgl.h"
#include "driver_usart.h"
#include "driver_tool.h"

typedef struct{
    uint16_t min;
    uint16_t max;
    uint8_t  bpp;
    uint8_t  reserved[3];
}x_header_t;
typedef struct{
    uint32_t pos;
}x_table_t;
typedef struct{
    uint8_t adv_w;
    uint8_t box_w;
    uint8_t box_h;
    int8_t  ofs_x;
    int8_t  ofs_y;
    uint8_t r;
}glyph_dsc_t;


static x_header_t __g_xbf_hd = {
    .min = 0x0020,
    .max = 0x9fa0,
    .bpp = 4,
};


static uint8_t __g_font_buf[312];//如bin文件存在SPI FLASH可使用此buff


static uint8_t *__user_font_getdata(int offset, int size){
    //如字模保存在SPI FLASH, SPIFLASH_Read(__g_font_buf,offset,size);
    //如字模已加载到SDRAM,直接返回偏移地址即可如:return (uint8_t*)(sdram_fontddr+offset);

    lv_fs_res_t result;
    uint32 len;
    lv_fs_file_t file;

    result = lv_fs_open(&file, "0:/font24.bin", LV_FS_MODE_RD);
    if (result != LV_FS_RES_OK) {
        GUA_LOGE("open font file error!\r\n");
        return NULL;
    }

    result = lv_fs_seek(&file, offset, LV_FS_SEEK_CUR);
    if (result != LV_FS_RES_OK) {
        GUA_LOGE("seek file error!\r\n");
        return NULL;
    }

    result = lv_fs_read(&file, __g_font_buf, size, &len);
    if (result != LV_FS_RES_OK) {
        GUA_LOGE("read file error!\r\n");
        return NULL;
    }

    GUA_LOGI("offset[0x%08d] size[%d] read[%d]\r\n", offset, size, len);
    for (uint32 i=0; i<size; i++) {
        GUA_LOGN("0x%02x ", __g_font_buf[i]);
    }GUA_LOGN("\r\n");

    lv_fs_close(&file);

    return __g_font_buf;
}


static const uint8_t * __user_font_get_bitmap(const lv_font_t * font, uint32_t unicode_letter) {
    if( unicode_letter>__g_xbf_hd.max || unicode_letter<__g_xbf_hd.min ) {
        return NULL;
    }
    uint32_t unicode_offset = sizeof(x_header_t)+(unicode_letter-__g_xbf_hd.min)*4;
    uint32_t *p_pos = (uint32_t *)__user_font_getdata(unicode_offset, 4);
    if( p_pos[0] != 0 ) {
        uint32_t pos = p_pos[0];
        glyph_dsc_t * gdsc = (glyph_dsc_t*)__user_font_getdata(pos, sizeof(glyph_dsc_t));
        return __user_font_getdata(pos+sizeof(glyph_dsc_t), gdsc->box_w*gdsc->box_h*__g_xbf_hd.bpp/8);
    }
    return NULL;
}


static bool __user_font_get_glyph_dsc(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next) {
    if( unicode_letter>__g_xbf_hd.max || unicode_letter<__g_xbf_hd.min ) {
        return NULL;
    }
    uint32_t unicode_offset = sizeof(x_header_t)+(unicode_letter-__g_xbf_hd.min)*4;
    uint32_t *p_pos = (uint32_t *)__user_font_getdata(unicode_offset, 4);
    if( p_pos[0] != 0 ) {
        glyph_dsc_t * gdsc = (glyph_dsc_t*)__user_font_getdata(p_pos[0], sizeof(glyph_dsc_t));
        dsc_out->adv_w = gdsc->adv_w;
        dsc_out->box_h = gdsc->box_h;
        dsc_out->box_w = gdsc->box_w;
        dsc_out->ofs_x = gdsc->ofs_x;
        dsc_out->ofs_y = gdsc->ofs_y;
        dsc_out->bpp   = __g_xbf_hd.bpp;
        return true;
    }
    return false;
}


//dingliehuobanfont,,-1
//字模高度：26
//XBF字体,外部bin文件
lv_font_t font24 = {
    .get_glyph_bitmap = __user_font_get_bitmap,
    .get_glyph_dsc = __user_font_get_glyph_dsc,
    .line_height = 26,
    .base_line = 0,
};

lv_font_t *get_font32_stytal(void)
{
    return &font24;
}