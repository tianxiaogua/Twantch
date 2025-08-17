# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=135,h=240)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(135*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 135
disp_drv.ver_res = 240
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


sc_main = lv.obj()
sc_main.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_main_main_main_default
style_sc_main_main_main_default = lv.style_t()
style_sc_main_main_main_default.init()
style_sc_main_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sc_main_main_main_default.set_bg_opa(0)

# add style for sc_main
sc_main.add_style(style_sc_main_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_img_1 = lv.img(sc_main)
sc_main_img_1.set_pos(int(0),int(0))
sc_main_img_1.set_size(135,240)
sc_main_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1030619232.png','rb') as f:
        sc_main_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1030619232.png')
    sys.exit()

sc_main_img_1_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_1_img_data),
  'header': {'always_zero': 0, 'w': 135, 'h': 240, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_img_1_img_data
})

sc_main_img_1.set_src(sc_main_img_1_img)
sc_main_img_1.set_pivot(0,0)
sc_main_img_1.set_angle(0)
# create style style_sc_main_img_1_main_main_default
style_sc_main_img_1_main_main_default = lv.style_t()
style_sc_main_img_1_main_main_default.init()
style_sc_main_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_img_1_main_main_default.set_img_recolor_opa(0)
style_sc_main_img_1_main_main_default.set_img_opa(255)

# add style for sc_main_img_1
sc_main_img_1.add_style(style_sc_main_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_sc_main_lable_bar_battery = lv.bar(sc_main)
sc_main_sc_main_lable_bar_battery.set_pos(int(32.5),int(15))
sc_main_sc_main_lable_bar_battery.set_size(70,8)
sc_main_sc_main_lable_bar_battery.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_sc_main_lable_bar_battery.set_style_anim_time(400, 0)
sc_main_sc_main_lable_bar_battery.set_mode(lv.bar.MODE.NORMAL)
sc_main_sc_main_lable_bar_battery.set_value(0, lv.ANIM.OFF)
sc_main_sc_main_img1 = lv.img(sc_main)
sc_main_sc_main_img1.set_pos(int(-81),int(107))
sc_main_sc_main_img1.set_size(102,122)
sc_main_sc_main_img1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_sc_main_img1.add_flag(lv.obj.FLAG.CLICKABLE)
sc_main_sc_main_img1.update_layout()
sc_main_sc_main_img1_anim_move_x = lv.anim_t()
sc_main_sc_main_img1_anim_move_x.init()
sc_main_sc_main_img1_anim_move_x.set_var(sc_main_sc_main_img1)
sc_main_sc_main_img1_anim_move_x.set_values(sc_main_sc_main_img1.get_x(), 0)
sc_main_sc_main_img1_anim_move_x.set_time(2000)
sc_main_sc_main_img1_anim_move_x.set_path_cb(lv.anim_t.path_ease_out)
sc_main_sc_main_img1_anim_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(sc_main_sc_main_img1,val))
lv.anim_t.start(sc_main_sc_main_img1_anim_move_x)

sc_main_sc_main_img1_anim_move_y = lv.anim_t()
sc_main_sc_main_img1_anim_move_y.init()
sc_main_sc_main_img1_anim_move_y.set_var(sc_main_sc_main_img1)
sc_main_sc_main_img1_anim_move_y.set_values(sc_main_sc_main_img1.get_y(), 107)
sc_main_sc_main_img1_anim_move_y.set_time(2000)
sc_main_sc_main_img1_anim_move_y.set_path_cb(lv.anim_t.path_ease_out)
sc_main_sc_main_img1_anim_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(sc_main_sc_main_img1,val))
lv.anim_t.start(sc_main_sc_main_img1_anim_move_y)

try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-149544638.png','rb') as f:
        sc_main_sc_main_img1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-149544638.png')
    sys.exit()

sc_main_sc_main_img1_img = lv.img_dsc_t({
  'data_size': len(sc_main_sc_main_img1_img_data),
  'header': {'always_zero': 0, 'w': 102, 'h': 122, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_sc_main_img1_img_data
})

sc_main_sc_main_img1.set_src(sc_main_sc_main_img1_img)
sc_main_sc_main_img1.set_pivot(0,0)
sc_main_sc_main_img1.set_angle(0)
# create style style_sc_main_sc_main_img1_main_main_default
style_sc_main_sc_main_img1_main_main_default = lv.style_t()
style_sc_main_sc_main_img1_main_main_default.init()
style_sc_main_sc_main_img1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_sc_main_img1_main_main_default.set_img_recolor_opa(0)
style_sc_main_sc_main_img1_main_main_default.set_img_opa(255)

# add style for sc_main_sc_main_img1
sc_main_sc_main_img1.add_style(style_sc_main_sc_main_img1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_img_num_0 = lv.img(sc_main)
sc_main_img_num_0.set_pos(int(4),int(30))
sc_main_img_num_0.set_size(25,60)
sc_main_img_num_0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_0.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png','rb') as f:
        sc_main_img_num_0_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png')
    sys.exit()

sc_main_img_num_0_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_0_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_img_num_0_img_data
})

sc_main_img_num_0.set_src(sc_main_img_num_0_img)
sc_main_img_num_0.set_pivot(0,0)
sc_main_img_num_0.set_angle(0)
# create style style_sc_main_img_num_0_main_main_default
style_sc_main_img_num_0_main_main_default = lv.style_t()
style_sc_main_img_num_0_main_main_default.init()
style_sc_main_img_num_0_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_img_num_0_main_main_default.set_img_recolor_opa(0)
style_sc_main_img_num_0_main_main_default.set_img_opa(255)

# add style for sc_main_img_num_0
sc_main_img_num_0.add_style(style_sc_main_img_num_0_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_img_num_1 = lv.img(sc_main)
sc_main_img_num_1.set_pos(int(34),int(30))
sc_main_img_num_1.set_size(25,60)
sc_main_img_num_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png','rb') as f:
        sc_main_img_num_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png')
    sys.exit()

sc_main_img_num_1_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_1_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_img_num_1_img_data
})

sc_main_img_num_1.set_src(sc_main_img_num_1_img)
sc_main_img_num_1.set_pivot(0,0)
sc_main_img_num_1.set_angle(0)
# create style style_sc_main_img_num_1_main_main_default
style_sc_main_img_num_1_main_main_default = lv.style_t()
style_sc_main_img_num_1_main_main_default.init()
style_sc_main_img_num_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_img_num_1_main_main_default.set_img_recolor_opa(0)
style_sc_main_img_num_1_main_main_default.set_img_opa(255)

# add style for sc_main_img_num_1
sc_main_img_num_1.add_style(style_sc_main_img_num_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_img_num_2 = lv.img(sc_main)
sc_main_img_num_2.set_pos(int(73),int(30))
sc_main_img_num_2.set_size(25,60)
sc_main_img_num_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png','rb') as f:
        sc_main_img_num_2_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png')
    sys.exit()

sc_main_img_num_2_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_2_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_img_num_2_img_data
})

sc_main_img_num_2.set_src(sc_main_img_num_2_img)
sc_main_img_num_2.set_pivot(0,0)
sc_main_img_num_2.set_angle(0)
# create style style_sc_main_img_num_2_main_main_default
style_sc_main_img_num_2_main_main_default = lv.style_t()
style_sc_main_img_num_2_main_main_default.init()
style_sc_main_img_num_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_img_num_2_main_main_default.set_img_recolor_opa(0)
style_sc_main_img_num_2_main_main_default.set_img_opa(255)

# add style for sc_main_img_num_2
sc_main_img_num_2.add_style(style_sc_main_img_num_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_img_num_3 = lv.img(sc_main)
sc_main_img_num_3.set_pos(int(105),int(30))
sc_main_img_num_3.set_size(25,60)
sc_main_img_num_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png','rb') as f:
        sc_main_img_num_3_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png')
    sys.exit()

sc_main_img_num_3_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_3_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_img_num_3_img_data
})

sc_main_img_num_3.set_src(sc_main_img_num_3_img)
sc_main_img_num_3.set_pivot(0,0)
sc_main_img_num_3.set_angle(0)
# create style style_sc_main_img_num_3_main_main_default
style_sc_main_img_num_3_main_main_default = lv.style_t()
style_sc_main_img_num_3_main_main_default.init()
style_sc_main_img_num_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_img_num_3_main_main_default.set_img_recolor_opa(0)
style_sc_main_img_num_3_main_main_default.set_img_opa(255)

# add style for sc_main_img_num_3
sc_main_img_num_3.add_style(style_sc_main_img_num_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu = lv.obj()
sc_menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_menu_main_main_default
style_sc_menu_main_main_default = lv.style_t()
style_sc_menu_main_main_default.init()
style_sc_menu_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_menu_main_main_default.set_bg_opa(255)

# add style for sc_menu
sc_menu.add_style(style_sc_menu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_1 = lv.img(sc_menu)
sc_menu_img_menu_1.set_pos(int(42),int(9))
sc_menu_img_menu_1.set_size(60,60)
sc_menu_img_menu_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1542051615.png','rb') as f:
        sc_menu_img_menu_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1542051615.png')
    sys.exit()

sc_menu_img_menu_1_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_1_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_1_img_data
})

sc_menu_img_menu_1.set_src(sc_menu_img_menu_1_img)
sc_menu_img_menu_1.set_pivot(0,0)
sc_menu_img_menu_1.set_angle(0)
# create style style_sc_menu_img_menu_1_main_main_default
style_sc_menu_img_menu_1_main_main_default = lv.style_t()
style_sc_menu_img_menu_1_main_main_default.init()
style_sc_menu_img_menu_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_1_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_1_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_1
sc_menu_img_menu_1.add_style(style_sc_menu_img_menu_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_10 = lv.img(sc_menu)
sc_menu_img_menu_10.set_pos(int(37),int(850))
sc_menu_img_menu_10.set_size(60,60)
sc_menu_img_menu_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp535157728.png','rb') as f:
        sc_menu_img_menu_10_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp535157728.png')
    sys.exit()

sc_menu_img_menu_10_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_10_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_10_img_data
})

sc_menu_img_menu_10.set_src(sc_menu_img_menu_10_img)
sc_menu_img_menu_10.set_pivot(0,0)
sc_menu_img_menu_10.set_angle(0)
# create style style_sc_menu_img_menu_10_main_main_default
style_sc_menu_img_menu_10_main_main_default = lv.style_t()
style_sc_menu_img_menu_10_main_main_default.init()
style_sc_menu_img_menu_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_10_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_10_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_10
sc_menu_img_menu_10.add_style(style_sc_menu_img_menu_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_9 = lv.img(sc_menu)
sc_menu_img_menu_9.set_pos(int(38),int(759))
sc_menu_img_menu_9.set_size(60,60)
sc_menu_img_menu_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1823148835.png','rb') as f:
        sc_menu_img_menu_9_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1823148835.png')
    sys.exit()

sc_menu_img_menu_9_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_9_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_9_img_data
})

sc_menu_img_menu_9.set_src(sc_menu_img_menu_9_img)
sc_menu_img_menu_9.set_pivot(0,0)
sc_menu_img_menu_9.set_angle(0)
# create style style_sc_menu_img_menu_9_main_main_default
style_sc_menu_img_menu_9_main_main_default = lv.style_t()
style_sc_menu_img_menu_9_main_main_default.init()
style_sc_menu_img_menu_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_9_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_9_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_9
sc_menu_img_menu_9.add_style(style_sc_menu_img_menu_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_4 = lv.label(sc_menu)
sc_menu_label_menu_4.set_pos(int(32),int(359))
sc_menu_label_menu_4.set_size(70,26)
sc_menu_label_menu_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_4.set_text("闹钟")
sc_menu_label_menu_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_4_main_main_default
style_sc_menu_label_menu_4_main_main_default = lv.style_t()
style_sc_menu_label_menu_4_main_main_default.init()
style_sc_menu_label_menu_4_main_main_default.set_radius(0)
style_sc_menu_label_menu_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_4_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_4_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_4_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_4_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_4_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_4_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_4_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_4_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_4
sc_menu_label_menu_4.add_style(style_sc_menu_label_menu_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_6 = lv.label(sc_menu)
sc_menu_label_menu_6.set_pos(int(32.5),int(537))
sc_menu_label_menu_6.set_size(70,26)
sc_menu_label_menu_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_6.set_text("秒表")
sc_menu_label_menu_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_6_main_main_default
style_sc_menu_label_menu_6_main_main_default = lv.style_t()
style_sc_menu_label_menu_6_main_main_default.init()
style_sc_menu_label_menu_6_main_main_default.set_radius(0)
style_sc_menu_label_menu_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_6_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_6_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_6_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_6_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_6_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_6_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_6_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_6_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_6
sc_menu_label_menu_6.add_style(style_sc_menu_label_menu_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_7 = lv.label(sc_menu)
sc_menu_label_menu_7.set_pos(int(32.5),int(631))
sc_menu_label_menu_7.set_size(70,26)
sc_menu_label_menu_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_7.set_text("设置")
sc_menu_label_menu_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_7_main_main_default
style_sc_menu_label_menu_7_main_main_default = lv.style_t()
style_sc_menu_label_menu_7_main_main_default.init()
style_sc_menu_label_menu_7_main_main_default.set_radius(0)
style_sc_menu_label_menu_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_7_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_7_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_7_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_7_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_7_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_7_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_7_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_7_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_7
sc_menu_label_menu_7.add_style(style_sc_menu_label_menu_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_8 = lv.label(sc_menu)
sc_menu_label_menu_8.set_pos(int(25),int(726))
sc_menu_label_menu_8.set_size(85,26)
sc_menu_label_menu_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_8.set_text("手电筒")
sc_menu_label_menu_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_8_main_main_default
style_sc_menu_label_menu_8_main_main_default = lv.style_t()
style_sc_menu_label_menu_8_main_main_default.init()
style_sc_menu_label_menu_8_main_main_default.set_radius(0)
style_sc_menu_label_menu_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_8_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_8_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_8_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_8_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_8_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_8_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_8_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_8_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_8
sc_menu_label_menu_8.add_style(style_sc_menu_label_menu_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_9 = lv.label(sc_menu)
sc_menu_label_menu_9.set_pos(int(25),int(824))
sc_menu_label_menu_9.set_size(85,26)
sc_menu_label_menu_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_9.set_text("天气")
sc_menu_label_menu_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_9_main_main_default
style_sc_menu_label_menu_9_main_main_default = lv.style_t()
style_sc_menu_label_menu_9_main_main_default.init()
style_sc_menu_label_menu_9_main_main_default.set_radius(0)
style_sc_menu_label_menu_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_9_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_9_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_9_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_9_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_9_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_9_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_9_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_9_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_9
sc_menu_label_menu_9.add_style(style_sc_menu_label_menu_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_10 = lv.label(sc_menu)
sc_menu_label_menu_10.set_pos(int(25),int(910))
sc_menu_label_menu_10.set_size(85,26)
sc_menu_label_menu_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_10.set_text("消息")
sc_menu_label_menu_10.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_10_main_main_default
style_sc_menu_label_menu_10_main_main_default = lv.style_t()
style_sc_menu_label_menu_10_main_main_default.init()
style_sc_menu_label_menu_10_main_main_default.set_radius(0)
style_sc_menu_label_menu_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_10_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_10_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_10_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_10_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_10_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_10_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_10_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_10_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_10
sc_menu_label_menu_10.add_style(style_sc_menu_label_menu_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_7 = lv.img(sc_menu)
sc_menu_img_menu_7.set_pos(int(37.5),int(563))
sc_menu_img_menu_7.set_size(60,60)
sc_menu_img_menu_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp394609118.png','rb') as f:
        sc_menu_img_menu_7_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp394609118.png')
    sys.exit()

sc_menu_img_menu_7_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_7_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_7_img_data
})

sc_menu_img_menu_7.set_src(sc_menu_img_menu_7_img)
sc_menu_img_menu_7.set_pivot(0,0)
sc_menu_img_menu_7.set_angle(0)
# create style style_sc_menu_img_menu_7_main_main_default
style_sc_menu_img_menu_7_main_main_default = lv.style_t()
style_sc_menu_img_menu_7_main_main_default.init()
style_sc_menu_img_menu_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_7_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_7_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_7
sc_menu_img_menu_7.add_style(style_sc_menu_img_menu_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_5 = lv.label(sc_menu)
sc_menu_label_menu_5.set_pos(int(32.5),int(452))
sc_menu_label_menu_5.set_size(70,26)
sc_menu_label_menu_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_5.set_text("定时")
sc_menu_label_menu_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_5_main_main_default
style_sc_menu_label_menu_5_main_main_default = lv.style_t()
style_sc_menu_label_menu_5_main_main_default.init()
style_sc_menu_label_menu_5_main_main_default.set_radius(0)
style_sc_menu_label_menu_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_5_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_5_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_5_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_5_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_5_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_5_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_5_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_5_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_5
sc_menu_label_menu_5.add_style(style_sc_menu_label_menu_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_6 = lv.img(sc_menu)
sc_menu_img_menu_6.set_pos(int(37.5),int(478))
sc_menu_img_menu_6.set_size(60,60)
sc_menu_img_menu_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp919103925.png','rb') as f:
        sc_menu_img_menu_6_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp919103925.png')
    sys.exit()

sc_menu_img_menu_6_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_6_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_6_img_data
})

sc_menu_img_menu_6.set_src(sc_menu_img_menu_6_img)
sc_menu_img_menu_6.set_pivot(0,0)
sc_menu_img_menu_6.set_angle(0)
# create style style_sc_menu_img_menu_6_main_main_default
style_sc_menu_img_menu_6_main_main_default = lv.style_t()
style_sc_menu_img_menu_6_main_main_default.init()
style_sc_menu_img_menu_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_6_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_6_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_6
sc_menu_img_menu_6.add_style(style_sc_menu_img_menu_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_1 = lv.label(sc_menu)
sc_menu_label_menu_1.set_pos(int(42),int(69))
sc_menu_label_menu_1.set_size(62,32)
sc_menu_label_menu_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_1.set_text("心率")
sc_menu_label_menu_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_1_main_main_default
style_sc_menu_label_menu_1_main_main_default = lv.style_t()
style_sc_menu_label_menu_1_main_main_default.init()
style_sc_menu_label_menu_1_main_main_default.set_radius(0)
style_sc_menu_label_menu_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_1_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_1_main_main_default.set_shadow_width(1)
style_sc_menu_label_menu_1_main_main_default.set_shadow_color(lv.color_make(0x00,0x00,0x00))
style_sc_menu_label_menu_1_main_main_default.set_shadow_opa(0)
style_sc_menu_label_menu_1_main_main_default.set_shadow_spread(1)
style_sc_menu_label_menu_1_main_main_default.set_shadow_ofs_x(0)
style_sc_menu_label_menu_1_main_main_default.set_shadow_ofs_y(0)
style_sc_menu_label_menu_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_1_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_1_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_1_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_1_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_1_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_1_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_1
sc_menu_label_menu_1.add_style(style_sc_menu_label_menu_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_2 = lv.label(sc_menu)
sc_menu_label_menu_2.set_pos(int(0),int(171))
sc_menu_label_menu_2.set_size(135,24)
sc_menu_label_menu_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_2.set_text("血氧")
sc_menu_label_menu_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_2_main_main_default
style_sc_menu_label_menu_2_main_main_default = lv.style_t()
style_sc_menu_label_menu_2_main_main_default.init()
style_sc_menu_label_menu_2_main_main_default.set_radius(0)
style_sc_menu_label_menu_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_2_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_2_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_2_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_2_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_2_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_2_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_2_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_2
sc_menu_label_menu_2.add_style(style_sc_menu_label_menu_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_menu_3 = lv.label(sc_menu)
sc_menu_label_menu_3.set_pos(int(8),int(265))
sc_menu_label_menu_3.set_size(119,24)
sc_menu_label_menu_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_menu_3.set_text("运动")
sc_menu_label_menu_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_menu_3_main_main_default
style_sc_menu_label_menu_3_main_main_default = lv.style_t()
style_sc_menu_label_menu_3_main_main_default.init()
style_sc_menu_label_menu_3_main_main_default.set_radius(0)
style_sc_menu_label_menu_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_menu_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_menu_3_main_main_default.set_bg_opa(0)
style_sc_menu_label_menu_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_menu_3_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_menu_label_menu_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_menu_label_menu_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_menu_3_main_main_default.set_text_letter_space(2)
style_sc_menu_label_menu_3_main_main_default.set_text_line_space(0)
style_sc_menu_label_menu_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_menu_3_main_main_default.set_pad_left(0)
style_sc_menu_label_menu_3_main_main_default.set_pad_right(0)
style_sc_menu_label_menu_3_main_main_default.set_pad_top(0)
style_sc_menu_label_menu_3_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_menu_3
sc_menu_label_menu_3.add_style(style_sc_menu_label_menu_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_2 = lv.img(sc_menu)
sc_menu_img_menu_2.set_pos(int(38.5),int(107))
sc_menu_img_menu_2.set_size(60,60)
sc_menu_img_menu_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp675706338.png','rb') as f:
        sc_menu_img_menu_2_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp675706338.png')
    sys.exit()

sc_menu_img_menu_2_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_2_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_2_img_data
})

sc_menu_img_menu_2.set_src(sc_menu_img_menu_2_img)
sc_menu_img_menu_2.set_pivot(0,0)
sc_menu_img_menu_2.set_angle(0)
# create style style_sc_menu_img_menu_2_main_main_default
style_sc_menu_img_menu_2_main_main_default = lv.style_t()
style_sc_menu_img_menu_2_main_main_default.init()
style_sc_menu_img_menu_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_2_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_2_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_2
sc_menu_img_menu_2.add_style(style_sc_menu_img_menu_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_3 = lv.img(sc_menu)
sc_menu_img_menu_3.set_pos(int(38.5),int(205))
sc_menu_img_menu_3.set_size(60,60)
sc_menu_img_menu_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp713830169.png','rb') as f:
        sc_menu_img_menu_3_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp713830169.png')
    sys.exit()

sc_menu_img_menu_3_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_3_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_3_img_data
})

sc_menu_img_menu_3.set_src(sc_menu_img_menu_3_img)
sc_menu_img_menu_3.set_pivot(0,0)
sc_menu_img_menu_3.set_angle(0)
# create style style_sc_menu_img_menu_3_main_main_default
style_sc_menu_img_menu_3_main_main_default = lv.style_t()
style_sc_menu_img_menu_3_main_main_default.init()
style_sc_menu_img_menu_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_3_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_3_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_3
sc_menu_img_menu_3.add_style(style_sc_menu_img_menu_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_4 = lv.img(sc_menu)
sc_menu_img_menu_4.set_pos(int(38.5),int(295))
sc_menu_img_menu_4.set_size(60,60)
sc_menu_img_menu_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1866528300.png','rb') as f:
        sc_menu_img_menu_4_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1866528300.png')
    sys.exit()

sc_menu_img_menu_4_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_4_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_4_img_data
})

sc_menu_img_menu_4.set_src(sc_menu_img_menu_4_img)
sc_menu_img_menu_4.set_pivot(0,0)
sc_menu_img_menu_4.set_angle(0)
# create style style_sc_menu_img_menu_4_main_main_default
style_sc_menu_img_menu_4_main_main_default = lv.style_t()
style_sc_menu_img_menu_4_main_main_default.init()
style_sc_menu_img_menu_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_4_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_4_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_4
sc_menu_img_menu_4.add_style(style_sc_menu_img_menu_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_5 = lv.img(sc_menu)
sc_menu_img_menu_5.set_pos(int(38.5),int(385))
sc_menu_img_menu_5.set_size(60,60)
sc_menu_img_menu_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1682600225.png','rb') as f:
        sc_menu_img_menu_5_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1682600225.png')
    sys.exit()

sc_menu_img_menu_5_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_5_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_5_img_data
})

sc_menu_img_menu_5.set_src(sc_menu_img_menu_5_img)
sc_menu_img_menu_5.set_pivot(0,0)
sc_menu_img_menu_5.set_angle(0)
# create style style_sc_menu_img_menu_5_main_main_default
style_sc_menu_img_menu_5_main_main_default = lv.style_t()
style_sc_menu_img_menu_5_main_main_default.init()
style_sc_menu_img_menu_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_5_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_5_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_5
sc_menu_img_menu_5.add_style(style_sc_menu_img_menu_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_menu_8 = lv.img(sc_menu)
sc_menu_img_menu_8.set_pos(int(37.5),int(666))
sc_menu_img_menu_8.set_size(60,60)
sc_menu_img_menu_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_menu_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1401503005.png','rb') as f:
        sc_menu_img_menu_8_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1401503005.png')
    sys.exit()

sc_menu_img_menu_8_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_menu_8_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_menu_8_img_data
})

sc_menu_img_menu_8.set_src(sc_menu_img_menu_8_img)
sc_menu_img_menu_8.set_pivot(0,0)
sc_menu_img_menu_8.set_angle(0)
# create style style_sc_menu_img_menu_8_main_main_default
style_sc_menu_img_menu_8_main_main_default = lv.style_t()
style_sc_menu_img_menu_8_main_main_default.init()
style_sc_menu_img_menu_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_menu_8_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_menu_8_main_main_default.set_img_opa(255)

# add style for sc_menu_img_menu_8
sc_menu_img_menu_8.add_style(style_sc_menu_img_menu_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer = lv.obj()
sc_timer.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_timer_main_main_default
style_sc_timer_main_main_default = lv.style_t()
style_sc_timer_main_main_default.init()
style_sc_timer_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_timer_main_main_default.set_bg_opa(255)

# add style for sc_timer
sc_timer.add_style(style_sc_timer_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer_label_1 = lv.label(sc_timer)
sc_timer_label_1.set_pos(int(13),int(70))
sc_timer_label_1.set_size(108,26)
sc_timer_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_timer_label_1.set_text("00:02:23")
sc_timer_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_timer_label_1_main_main_default
style_sc_timer_label_1_main_main_default = lv.style_t()
style_sc_timer_label_1_main_main_default.init()
style_sc_timer_label_1_main_main_default.set_radius(0)
style_sc_timer_label_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sc_timer_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_timer_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_timer_label_1_main_main_default.set_bg_opa(0)
style_sc_timer_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_timer_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_timer_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_timer_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_timer_label_1_main_main_default.set_text_letter_space(0)
style_sc_timer_label_1_main_main_default.set_text_line_space(0)
style_sc_timer_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_timer_label_1_main_main_default.set_pad_left(0)
style_sc_timer_label_1_main_main_default.set_pad_right(0)
style_sc_timer_label_1_main_main_default.set_pad_top(0)
style_sc_timer_label_1_main_main_default.set_pad_bottom(0)

# add style for sc_timer_label_1
sc_timer_label_1.add_style(style_sc_timer_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer_img_1 = lv.img(sc_timer)
sc_timer_img_1.set_pos(int(9),int(196))
sc_timer_img_1.set_size(116,38)
sc_timer_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_timer_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-71130032.png','rb') as f:
        sc_timer_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-71130032.png')
    sys.exit()

sc_timer_img_1_img = lv.img_dsc_t({
  'data_size': len(sc_timer_img_1_img_data),
  'header': {'always_zero': 0, 'w': 116, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_timer_img_1_img_data
})

sc_timer_img_1.set_src(sc_timer_img_1_img)
sc_timer_img_1.set_pivot(0,0)
sc_timer_img_1.set_angle(0)
# create style style_sc_timer_img_1_main_main_default
style_sc_timer_img_1_main_main_default = lv.style_t()
style_sc_timer_img_1_main_main_default.init()
style_sc_timer_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_timer_img_1_main_main_default.set_img_recolor_opa(0)
style_sc_timer_img_1_main_main_default.set_img_opa(255)

# add style for sc_timer_img_1
sc_timer_img_1.add_style(style_sc_timer_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer_img_2 = lv.img(sc_timer)
sc_timer_img_2.set_pos(int(9),int(22))
sc_timer_img_2.set_size(116,38)
sc_timer_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_timer_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-71130032.png','rb') as f:
        sc_timer_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-71130032.png')
    sys.exit()

sc_timer_img_2_img = lv.img_dsc_t({
  'data_size': len(sc_timer_img_2_img_data),
  'header': {'always_zero': 0, 'w': 116, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_timer_img_2_img_data
})

sc_timer_img_2.set_src(sc_timer_img_2_img)
sc_timer_img_2.set_pivot(0,0)
sc_timer_img_2.set_angle(0)
# create style style_sc_timer_img_2_main_main_default
style_sc_timer_img_2_main_main_default = lv.style_t()
style_sc_timer_img_2_main_main_default.init()
style_sc_timer_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_timer_img_2_main_main_default.set_img_recolor_opa(0)
style_sc_timer_img_2_main_main_default.set_img_opa(117)

# add style for sc_timer_img_2
sc_timer_img_2.add_style(style_sc_timer_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer_label_2 = lv.label(sc_timer)
sc_timer_label_2.set_pos(int(22.5),int(3))
sc_timer_label_2.set_size(90,15)
sc_timer_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_timer_label_2.set_text("10:23 AM")
sc_timer_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_timer_label_2_main_main_default
style_sc_timer_label_2_main_main_default = lv.style_t()
style_sc_timer_label_2_main_main_default.init()
style_sc_timer_label_2_main_main_default.set_radius(0)
style_sc_timer_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_timer_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_timer_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_timer_label_2_main_main_default.set_bg_opa(0)
style_sc_timer_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_timer_label_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_timer_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_timer_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_timer_label_2_main_main_default.set_text_letter_space(2)
style_sc_timer_label_2_main_main_default.set_text_line_space(0)
style_sc_timer_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_timer_label_2_main_main_default.set_pad_left(0)
style_sc_timer_label_2_main_main_default.set_pad_right(0)
style_sc_timer_label_2_main_main_default.set_pad_top(0)
style_sc_timer_label_2_main_main_default.set_pad_bottom(0)

# add style for sc_timer_label_2
sc_timer_label_2.add_style(style_sc_timer_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer_img_3 = lv.img(sc_timer)
sc_timer_img_3.set_pos(int(52),int(26))
sc_timer_img_3.set_size(31,28)
sc_timer_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_timer_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-914965708.png','rb') as f:
        sc_timer_img_3_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-914965708.png')
    sys.exit()

sc_timer_img_3_img = lv.img_dsc_t({
  'data_size': len(sc_timer_img_3_img_data),
  'header': {'always_zero': 0, 'w': 31, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_timer_img_3_img_data
})

sc_timer_img_3.set_src(sc_timer_img_3_img)
sc_timer_img_3.set_pivot(0,0)
sc_timer_img_3.set_angle(0)
# create style style_sc_timer_img_3_main_main_default
style_sc_timer_img_3_main_main_default = lv.style_t()
style_sc_timer_img_3_main_main_default.init()
style_sc_timer_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_timer_img_3_main_main_default.set_img_recolor_opa(0)
style_sc_timer_img_3_main_main_default.set_img_opa(255)

# add style for sc_timer_img_3
sc_timer_img_3.add_style(style_sc_timer_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_timer_img_4 = lv.img(sc_timer)
sc_timer_img_4.set_pos(int(52),int(200))
sc_timer_img_4.set_size(30,30)
sc_timer_img_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_timer_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp726812535.png','rb') as f:
        sc_timer_img_4_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp726812535.png')
    sys.exit()

sc_timer_img_4_img = lv.img_dsc_t({
  'data_size': len(sc_timer_img_4_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_timer_img_4_img_data
})

sc_timer_img_4.set_src(sc_timer_img_4_img)
sc_timer_img_4.set_pivot(0,0)
sc_timer_img_4.set_angle(0)
# create style style_sc_timer_img_4_main_main_default
style_sc_timer_img_4_main_main_default = lv.style_t()
style_sc_timer_img_4_main_main_default.init()
style_sc_timer_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_timer_img_4_main_main_default.set_img_recolor_opa(0)
style_sc_timer_img_4_main_main_default.set_img_opa(255)

# add style for sc_timer_img_4
sc_timer_img_4.add_style(style_sc_timer_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_message2 = lv.obj()
sc_message2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_message2_main_main_default
style_sc_message2_main_main_default = lv.style_t()
style_sc_message2_main_main_default.init()
style_sc_message2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_message2_main_main_default.set_bg_opa(255)

# add style for sc_message2
sc_message2.add_style(style_sc_message2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_message2_img_2 = lv.img(sc_message2)
sc_message2_img_2.set_pos(int(52),int(206))
sc_message2_img_2.set_size(30,30)
sc_message2_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_message2_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-242873230.png','rb') as f:
        sc_message2_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-242873230.png')
    sys.exit()

sc_message2_img_2_img = lv.img_dsc_t({
  'data_size': len(sc_message2_img_2_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_message2_img_2_img_data
})

sc_message2_img_2.set_src(sc_message2_img_2_img)
sc_message2_img_2.set_pivot(0,0)
sc_message2_img_2.set_angle(0)
# create style style_sc_message2_img_2_main_main_default
style_sc_message2_img_2_main_main_default = lv.style_t()
style_sc_message2_img_2_main_main_default.init()
style_sc_message2_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_message2_img_2_main_main_default.set_img_recolor_opa(0)
style_sc_message2_img_2_main_main_default.set_img_opa(255)

# add style for sc_message2_img_2
sc_message2_img_2.add_style(style_sc_message2_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_message2_cont_1 = lv.obj(sc_message2)
sc_message2_cont_1.set_pos(int(0),int(3))
sc_message2_cont_1.set_size(135,81)
sc_message2_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_message2_label_3 = lv.label(sc_message2_cont_1)
sc_message2_label_3.set_pos(int(35),int(10))
sc_message2_label_3.set_size(90,17)
sc_message2_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_message2_label_3.set_text("微信")
sc_message2_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_message2_label_3_main_main_default
style_sc_message2_label_3_main_main_default = lv.style_t()
style_sc_message2_label_3_main_main_default.init()
style_sc_message2_label_3_main_main_default.set_radius(0)
style_sc_message2_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_message2_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_message2_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_message2_label_3_main_main_default.set_bg_opa(0)
style_sc_message2_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_message2_label_3_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_message2_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_message2_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_message2_label_3_main_main_default.set_text_letter_space(0)
style_sc_message2_label_3_main_main_default.set_text_line_space(0)
style_sc_message2_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_message2_label_3_main_main_default.set_pad_left(0)
style_sc_message2_label_3_main_main_default.set_pad_right(0)
style_sc_message2_label_3_main_main_default.set_pad_top(0)
style_sc_message2_label_3_main_main_default.set_pad_bottom(0)

# add style for sc_message2_label_3
sc_message2_label_3.add_style(style_sc_message2_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_message2_label_2 = lv.label(sc_message2_cont_1)
sc_message2_label_2.set_pos(int(3),int(35))
sc_message2_label_2.set_size(130,70)
sc_message2_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_message2_label_2.set_text("[18条]这是一条新消息通知.。动画表情")
sc_message2_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_message2_label_2_main_main_default
style_sc_message2_label_2_main_main_default = lv.style_t()
style_sc_message2_label_2_main_main_default.init()
style_sc_message2_label_2_main_main_default.set_radius(0)
style_sc_message2_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_message2_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_message2_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_message2_label_2_main_main_default.set_bg_opa(0)
style_sc_message2_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_message2_label_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_message2_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_message2_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_message2_label_2_main_main_default.set_text_letter_space(0)
style_sc_message2_label_2_main_main_default.set_text_line_space(0)
style_sc_message2_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_message2_label_2_main_main_default.set_pad_left(0)
style_sc_message2_label_2_main_main_default.set_pad_right(0)
style_sc_message2_label_2_main_main_default.set_pad_top(0)
style_sc_message2_label_2_main_main_default.set_pad_bottom(0)

# add style for sc_message2_label_2
sc_message2_label_2.add_style(style_sc_message2_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_message2_img_3 = lv.img(sc_message2_cont_1)
sc_message2_img_3.set_pos(int(5),int(1))
sc_message2_img_3.set_size(30,30)
sc_message2_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_message2_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-258477608.png','rb') as f:
        sc_message2_img_3_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-258477608.png')
    sys.exit()

sc_message2_img_3_img = lv.img_dsc_t({
  'data_size': len(sc_message2_img_3_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_message2_img_3_img_data
})

sc_message2_img_3.set_src(sc_message2_img_3_img)
sc_message2_img_3.set_pivot(0,0)
sc_message2_img_3.set_angle(0)
# create style style_sc_message2_img_3_main_main_default
style_sc_message2_img_3_main_main_default = lv.style_t()
style_sc_message2_img_3_main_main_default.init()
style_sc_message2_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_message2_img_3_main_main_default.set_img_recolor_opa(0)
style_sc_message2_img_3_main_main_default.set_img_opa(255)

# add style for sc_message2_img_3
sc_message2_img_3.add_style(style_sc_message2_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_message2_line_1 = lv.line(sc_message2_cont_1)
sc_message2_line_1.set_pos(int(7),int(115))
sc_message2_line_1.set_size(118,4)
sc_message2_line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":130, "y":0}, 
			  ]
sc_message2_line_1.set_points(line_points, 2)
# create style style_sc_message2_line_1_main_main_default
style_sc_message2_line_1_main_main_default = lv.style_t()
style_sc_message2_line_1_main_main_default.init()
style_sc_message2_line_1_main_main_default.set_line_color(lv.color_make(0x75,0x75,0x75))
style_sc_message2_line_1_main_main_default.set_line_width(2)
style_sc_message2_line_1_main_main_default.set_line_rounded(True)

# add style for sc_message2_line_1
sc_message2_line_1.add_style(style_sc_message2_line_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sc_message2_cont_1_main_main_default
style_sc_message2_cont_1_main_main_default = lv.style_t()
style_sc_message2_cont_1_main_main_default.init()
style_sc_message2_cont_1_main_main_default.set_radius(0)
style_sc_message2_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_message2_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_message2_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_message2_cont_1_main_main_default.set_bg_opa(0)
style_sc_message2_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_sc_message2_cont_1_main_main_default.set_border_width(0)
style_sc_message2_cont_1_main_main_default.set_border_opa(0)
style_sc_message2_cont_1_main_main_default.set_pad_left(0)
style_sc_message2_cont_1_main_main_default.set_pad_right(0)
style_sc_message2_cont_1_main_main_default.set_pad_top(0)
style_sc_message2_cont_1_main_main_default.set_pad_bottom(0)

# add style for sc_message2_cont_1
sc_message2_cont_1.add_style(style_sc_message2_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

scr_message = lv.obj()
scr_message.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_scr_message_main_main_default
style_scr_message_main_main_default = lv.style_t()
style_scr_message_main_main_default.init()
style_scr_message_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_scr_message_main_main_default.set_bg_opa(255)

# add style for scr_message
scr_message.add_style(style_scr_message_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

scr_message_img_1 = lv.img(scr_message)
scr_message_img_1.set_pos(int(37.5),int(90))
scr_message_img_1.set_size(60,60)
scr_message_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scr_message_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1276333010.png','rb') as f:
        scr_message_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1276333010.png')
    sys.exit()

scr_message_img_1_img = lv.img_dsc_t({
  'data_size': len(scr_message_img_1_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': scr_message_img_1_img_data
})

scr_message_img_1.set_src(scr_message_img_1_img)
scr_message_img_1.set_pivot(0,0)
scr_message_img_1.set_angle(0)
# create style style_scr_message_img_1_main_main_default
style_scr_message_img_1_main_main_default = lv.style_t()
style_scr_message_img_1_main_main_default.init()
style_scr_message_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_scr_message_img_1_main_main_default.set_img_recolor_opa(0)
style_scr_message_img_1_main_main_default.set_img_opa(255)

# add style for scr_message_img_1
scr_message_img_1.add_style(style_scr_message_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

scr_message_label_1 = lv.label(scr_message)
scr_message_label_1.set_pos(int(25),int(171))
scr_message_label_1.set_size(85,33)
scr_message_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
scr_message_label_1.set_text("无通知")
scr_message_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_scr_message_label_1_main_main_default
style_scr_message_label_1_main_main_default = lv.style_t()
style_scr_message_label_1_main_main_default.init()
style_scr_message_label_1_main_main_default.set_radius(0)
style_scr_message_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_scr_message_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_scr_message_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_scr_message_label_1_main_main_default.set_bg_opa(0)
style_scr_message_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_scr_message_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_scr_message_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_scr_message_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_scr_message_label_1_main_main_default.set_text_letter_space(2)
style_scr_message_label_1_main_main_default.set_text_line_space(0)
style_scr_message_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_scr_message_label_1_main_main_default.set_pad_left(0)
style_scr_message_label_1_main_main_default.set_pad_right(0)
style_scr_message_label_1_main_main_default.set_pad_top(0)
style_scr_message_label_1_main_main_default.set_pad_bottom(0)

# add style for scr_message_label_1
scr_message_label_1.add_style(style_scr_message_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_light = lv.obj()
sc_light.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_light_main_main_default
style_sc_light_main_main_default = lv.style_t()
style_sc_light_main_main_default.init()
style_sc_light_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sc_light_main_main_default.set_bg_opa(255)

# add style for sc_light
sc_light.add_style(style_sc_light_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport = lv.obj()
sc_sport.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_sport_main_main_default
style_sc_sport_main_main_default = lv.style_t()
style_sc_sport_main_main_default.init()
style_sc_sport_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_sport_main_main_default.set_bg_opa(255)

# add style for sc_sport
sc_sport.add_style(style_sc_sport_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_bar_1 = lv.bar(sc_sport)
sc_sport_bar_1.set_pos(int(10.5),int(33))
sc_sport_bar_1.set_size(114,20)
sc_sport_bar_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_bar_1.set_style_anim_time(1000, 0)
sc_sport_bar_1.set_mode(lv.bar.MODE.NORMAL)
sc_sport_bar_1.set_value(50, lv.ANIM.OFF)
# create style style_sc_sport_bar_1_main_main_default
style_sc_sport_bar_1_main_main_default = lv.style_t()
style_sc_sport_bar_1_main_main_default.init()
style_sc_sport_bar_1_main_main_default.set_radius(10)
style_sc_sport_bar_1_main_main_default.set_bg_color(lv.color_make(0x00,0xff,0x62))
style_sc_sport_bar_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_bar_1_main_main_default.set_bg_opa(48)
style_sc_sport_bar_1_main_main_default.set_shadow_width(10)
style_sc_sport_bar_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_1_main_main_default.set_shadow_opa(255)
style_sc_sport_bar_1_main_main_default.set_shadow_spread(1)
style_sc_sport_bar_1_main_main_default.set_shadow_ofs_x(0)
style_sc_sport_bar_1_main_main_default.set_shadow_ofs_y(0)

# add style for sc_sport_bar_1
sc_sport_bar_1.add_style(style_sc_sport_bar_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sc_sport_bar_1_main_indicator_default
style_sc_sport_bar_1_main_indicator_default = lv.style_t()
style_sc_sport_bar_1_main_indicator_default.init()
style_sc_sport_bar_1_main_indicator_default.set_radius(10)
style_sc_sport_bar_1_main_indicator_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_bar_1_main_indicator_default.set_bg_opa(255)

# add style for sc_sport_bar_1
sc_sport_bar_1.add_style(style_sc_sport_bar_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

sc_sport_bar_2 = lv.bar(sc_sport)
sc_sport_bar_2.set_pos(int(12.5),int(107))
sc_sport_bar_2.set_size(110,20)
sc_sport_bar_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_bar_2.set_style_anim_time(1000, 0)
sc_sport_bar_2.set_mode(lv.bar.MODE.NORMAL)
sc_sport_bar_2.set_value(50, lv.ANIM.OFF)
# create style style_sc_sport_bar_2_main_main_default
style_sc_sport_bar_2_main_main_default = lv.style_t()
style_sc_sport_bar_2_main_main_default.init()
style_sc_sport_bar_2_main_main_default.set_radius(10)
style_sc_sport_bar_2_main_main_default.set_bg_color(lv.color_make(0x00,0xff,0x62))
style_sc_sport_bar_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_bar_2_main_main_default.set_bg_opa(48)
style_sc_sport_bar_2_main_main_default.set_shadow_width(10)
style_sc_sport_bar_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_2_main_main_default.set_shadow_opa(255)
style_sc_sport_bar_2_main_main_default.set_shadow_spread(1)
style_sc_sport_bar_2_main_main_default.set_shadow_ofs_x(0)
style_sc_sport_bar_2_main_main_default.set_shadow_ofs_y(0)

# add style for sc_sport_bar_2
sc_sport_bar_2.add_style(style_sc_sport_bar_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sc_sport_bar_2_main_indicator_default
style_sc_sport_bar_2_main_indicator_default = lv.style_t()
style_sc_sport_bar_2_main_indicator_default.init()
style_sc_sport_bar_2_main_indicator_default.set_radius(10)
style_sc_sport_bar_2_main_indicator_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_2_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_2_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_bar_2_main_indicator_default.set_bg_opa(255)

# add style for sc_sport_bar_2
sc_sport_bar_2.add_style(style_sc_sport_bar_2_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

sc_sport_img_1 = lv.img(sc_sport)
sc_sport_img_1.set_pos(int(3),int(7))
sc_sport_img_1.set_size(20,23)
sc_sport_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1888424.png','rb') as f:
        sc_sport_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1888424.png')
    sys.exit()

sc_sport_img_1_img = lv.img_dsc_t({
  'data_size': len(sc_sport_img_1_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 23, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_sport_img_1_img_data
})

sc_sport_img_1.set_src(sc_sport_img_1_img)
sc_sport_img_1.set_pivot(0,0)
sc_sport_img_1.set_angle(0)
# create style style_sc_sport_img_1_main_main_default
style_sc_sport_img_1_main_main_default = lv.style_t()
style_sc_sport_img_1_main_main_default.init()
style_sc_sport_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_sport_img_1_main_main_default.set_img_recolor_opa(0)
style_sc_sport_img_1_main_main_default.set_img_opa(255)

# add style for sc_sport_img_1
sc_sport_img_1.add_style(style_sc_sport_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_img_2 = lv.img(sc_sport)
sc_sport_img_2.set_pos(int(3),int(81))
sc_sport_img_2.set_size(20,20)
sc_sport_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp485799740.png','rb') as f:
        sc_sport_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp485799740.png')
    sys.exit()

sc_sport_img_2_img = lv.img_dsc_t({
  'data_size': len(sc_sport_img_2_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_sport_img_2_img_data
})

sc_sport_img_2.set_src(sc_sport_img_2_img)
sc_sport_img_2.set_pivot(0,0)
sc_sport_img_2.set_angle(10)
# create style style_sc_sport_img_2_main_main_default
style_sc_sport_img_2_main_main_default = lv.style_t()
style_sc_sport_img_2_main_main_default.init()
style_sc_sport_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_sport_img_2_main_main_default.set_img_recolor_opa(0)
style_sc_sport_img_2_main_main_default.set_img_opa(255)

# add style for sc_sport_img_2
sc_sport_img_2.add_style(style_sc_sport_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_img_3 = lv.img(sc_sport)
sc_sport_img_3.set_pos(int(3),int(160))
sc_sport_img_3.set_size(20,20)
sc_sport_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-386781610.png','rb') as f:
        sc_sport_img_3_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-386781610.png')
    sys.exit()

sc_sport_img_3_img = lv.img_dsc_t({
  'data_size': len(sc_sport_img_3_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_sport_img_3_img_data
})

sc_sport_img_3.set_src(sc_sport_img_3_img)
sc_sport_img_3.set_pivot(0,0)
sc_sport_img_3.set_angle(10)
# create style style_sc_sport_img_3_main_main_default
style_sc_sport_img_3_main_main_default = lv.style_t()
style_sc_sport_img_3_main_main_default.init()
style_sc_sport_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_sport_img_3_main_main_default.set_img_recolor_opa(0)
style_sc_sport_img_3_main_main_default.set_img_opa(255)

# add style for sc_sport_img_3
sc_sport_img_3.add_style(style_sc_sport_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_1 = lv.label(sc_sport)
sc_sport_label_1.set_pos(int(-5),int(59))
sc_sport_label_1.set_size(101,15)
sc_sport_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_1.set_text("122/10K")
sc_sport_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_1_main_main_default
style_sc_sport_label_1_main_main_default = lv.style_t()
style_sc_sport_label_1_main_main_default.init()
style_sc_sport_label_1_main_main_default.set_radius(0)
style_sc_sport_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_1_main_main_default.set_bg_opa(0)
style_sc_sport_label_1_main_main_default.set_text_color(lv.color_make(0x6b,0xff,0xd5))
try:
    style_sc_sport_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_1_main_main_default.set_text_letter_space(2)
style_sc_sport_label_1_main_main_default.set_text_line_space(0)
style_sc_sport_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_1_main_main_default.set_pad_left(0)
style_sc_sport_label_1_main_main_default.set_pad_right(0)
style_sc_sport_label_1_main_main_default.set_pad_top(0)
style_sc_sport_label_1_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_1
sc_sport_label_1.add_style(style_sc_sport_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_3 = lv.label(sc_sport)
sc_sport_label_3.set_pos(int(88),int(59))
sc_sport_label_3.set_size(37,17)
sc_sport_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_3.set_text("步数")
sc_sport_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_3_main_main_default
style_sc_sport_label_3_main_main_default = lv.style_t()
style_sc_sport_label_3_main_main_default.init()
style_sc_sport_label_3_main_main_default.set_radius(0)
style_sc_sport_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_3_main_main_default.set_bg_opa(0)
style_sc_sport_label_3_main_main_default.set_text_color(lv.color_make(0x6b,0xff,0xd5))
try:
    style_sc_sport_label_3_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_3_main_main_default.set_text_letter_space(2)
style_sc_sport_label_3_main_main_default.set_text_line_space(0)
style_sc_sport_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_3_main_main_default.set_pad_left(0)
style_sc_sport_label_3_main_main_default.set_pad_right(0)
style_sc_sport_label_3_main_main_default.set_pad_top(0)
style_sc_sport_label_3_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_3
sc_sport_label_3.add_style(style_sc_sport_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_5 = lv.label(sc_sport)
sc_sport_label_5.set_pos(int(26.5),int(12))
sc_sport_label_5.set_size(82,15)
sc_sport_label_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_5.set_text("运动步数")
sc_sport_label_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_5_main_main_default
style_sc_sport_label_5_main_main_default = lv.style_t()
style_sc_sport_label_5_main_main_default.init()
style_sc_sport_label_5_main_main_default.set_radius(0)
style_sc_sport_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_5_main_main_default.set_bg_opa(0)
style_sc_sport_label_5_main_main_default.set_text_color(lv.color_make(0x75,0xff,0xf6))
try:
    style_sc_sport_label_5_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_5_main_main_default.set_text_letter_space(2)
style_sc_sport_label_5_main_main_default.set_text_line_space(0)
style_sc_sport_label_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_5_main_main_default.set_pad_left(0)
style_sc_sport_label_5_main_main_default.set_pad_right(0)
style_sc_sport_label_5_main_main_default.set_pad_top(0)
style_sc_sport_label_5_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_5
sc_sport_label_5.add_style(style_sc_sport_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_7 = lv.label(sc_sport)
sc_sport_label_7.set_pos(int(26.5),int(162))
sc_sport_label_7.set_size(82,15)
sc_sport_label_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_7.set_text("活动时长")
sc_sport_label_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_7_main_main_default
style_sc_sport_label_7_main_main_default = lv.style_t()
style_sc_sport_label_7_main_main_default.init()
style_sc_sport_label_7_main_main_default.set_radius(0)
style_sc_sport_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_7_main_main_default.set_bg_opa(0)
style_sc_sport_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xeb,0x6b))
try:
    style_sc_sport_label_7_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_7_main_main_default.set_text_letter_space(2)
style_sc_sport_label_7_main_main_default.set_text_line_space(0)
style_sc_sport_label_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_7_main_main_default.set_pad_left(0)
style_sc_sport_label_7_main_main_default.set_pad_right(0)
style_sc_sport_label_7_main_main_default.set_pad_top(0)
style_sc_sport_label_7_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_7
sc_sport_label_7.add_style(style_sc_sport_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_6 = lv.label(sc_sport)
sc_sport_label_6.set_pos(int(26.5),int(86))
sc_sport_label_6.set_size(82,15)
sc_sport_label_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_6.set_text("热量消耗")
sc_sport_label_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_6_main_main_default
style_sc_sport_label_6_main_main_default = lv.style_t()
style_sc_sport_label_6_main_main_default.init()
style_sc_sport_label_6_main_main_default.set_radius(0)
style_sc_sport_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_6_main_main_default.set_bg_opa(0)
style_sc_sport_label_6_main_main_default.set_text_color(lv.color_make(0xf9,0x93,0x71))
try:
    style_sc_sport_label_6_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_6_main_main_default.set_text_letter_space(2)
style_sc_sport_label_6_main_main_default.set_text_line_space(0)
style_sc_sport_label_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_6_main_main_default.set_pad_left(0)
style_sc_sport_label_6_main_main_default.set_pad_right(0)
style_sc_sport_label_6_main_main_default.set_pad_top(0)
style_sc_sport_label_6_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_6
sc_sport_label_6.add_style(style_sc_sport_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_2 = lv.label(sc_sport)
sc_sport_label_2.set_pos(int(-12),int(136))
sc_sport_label_2.set_size(100,15)
sc_sport_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_2.set_text("122/2K")
sc_sport_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_2_main_main_default
style_sc_sport_label_2_main_main_default = lv.style_t()
style_sc_sport_label_2_main_main_default.init()
style_sc_sport_label_2_main_main_default.set_radius(0)
style_sc_sport_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_2_main_main_default.set_bg_opa(0)
style_sc_sport_label_2_main_main_default.set_text_color(lv.color_make(0xe3,0x6b,0x2b))
try:
    style_sc_sport_label_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_2_main_main_default.set_text_letter_space(2)
style_sc_sport_label_2_main_main_default.set_text_line_space(0)
style_sc_sport_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_2_main_main_default.set_pad_left(0)
style_sc_sport_label_2_main_main_default.set_pad_right(0)
style_sc_sport_label_2_main_main_default.set_pad_top(0)
style_sc_sport_label_2_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_2
sc_sport_label_2.add_style(style_sc_sport_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_8 = lv.label(sc_sport)
sc_sport_label_8.set_pos(int(-12),int(211))
sc_sport_label_8.set_size(100,15)
sc_sport_label_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_8.set_text("87/100")
sc_sport_label_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_8_main_main_default
style_sc_sport_label_8_main_main_default = lv.style_t()
style_sc_sport_label_8_main_main_default.init()
style_sc_sport_label_8_main_main_default.set_radius(0)
style_sc_sport_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_8_main_main_default.set_bg_opa(0)
style_sc_sport_label_8_main_main_default.set_text_color(lv.color_make(0xe7,0xd5,0x5a))
try:
    style_sc_sport_label_8_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_8_main_main_default.set_text_letter_space(2)
style_sc_sport_label_8_main_main_default.set_text_line_space(0)
style_sc_sport_label_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_8_main_main_default.set_pad_left(0)
style_sc_sport_label_8_main_main_default.set_pad_right(0)
style_sc_sport_label_8_main_main_default.set_pad_top(0)
style_sc_sport_label_8_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_8
sc_sport_label_8.add_style(style_sc_sport_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_9 = lv.label(sc_sport)
sc_sport_label_9.set_pos(int(88),int(211))
sc_sport_label_9.set_size(36,15)
sc_sport_label_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_9.set_text("分钟")
sc_sport_label_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_9_main_main_default
style_sc_sport_label_9_main_main_default = lv.style_t()
style_sc_sport_label_9_main_main_default.init()
style_sc_sport_label_9_main_main_default.set_radius(0)
style_sc_sport_label_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_9_main_main_default.set_bg_opa(0)
style_sc_sport_label_9_main_main_default.set_text_color(lv.color_make(0xe7,0xd5,0x5a))
try:
    style_sc_sport_label_9_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_9_main_main_default.set_text_letter_space(2)
style_sc_sport_label_9_main_main_default.set_text_line_space(0)
style_sc_sport_label_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_9_main_main_default.set_pad_left(0)
style_sc_sport_label_9_main_main_default.set_pad_right(0)
style_sc_sport_label_9_main_main_default.set_pad_top(0)
style_sc_sport_label_9_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_9
sc_sport_label_9.add_style(style_sc_sport_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_label_4 = lv.label(sc_sport)
sc_sport_label_4.set_pos(int(88),int(136))
sc_sport_label_4.set_size(37,15)
sc_sport_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_label_4.set_text("大卡")
sc_sport_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_sport_label_4_main_main_default
style_sc_sport_label_4_main_main_default = lv.style_t()
style_sc_sport_label_4_main_main_default.init()
style_sc_sport_label_4_main_main_default.set_radius(0)
style_sc_sport_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_label_4_main_main_default.set_bg_opa(0)
style_sc_sport_label_4_main_main_default.set_text_color(lv.color_make(0xe3,0x6b,0x2b))
try:
    style_sc_sport_label_4_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_sport_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_sport_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_sport_label_4_main_main_default.set_text_letter_space(2)
style_sc_sport_label_4_main_main_default.set_text_line_space(0)
style_sc_sport_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_sport_label_4_main_main_default.set_pad_left(0)
style_sc_sport_label_4_main_main_default.set_pad_right(0)
style_sc_sport_label_4_main_main_default.set_pad_top(0)
style_sc_sport_label_4_main_main_default.set_pad_bottom(0)

# add style for sc_sport_label_4
sc_sport_label_4.add_style(style_sc_sport_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_sport_bar_3 = lv.bar(sc_sport)
sc_sport_bar_3.set_pos(int(11),int(185))
sc_sport_bar_3.set_size(113,20)
sc_sport_bar_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_sport_bar_3.set_style_anim_time(1000, 0)
sc_sport_bar_3.set_mode(lv.bar.MODE.NORMAL)
sc_sport_bar_3.set_value(50, lv.ANIM.OFF)
# create style style_sc_sport_bar_3_main_main_default
style_sc_sport_bar_3_main_main_default = lv.style_t()
style_sc_sport_bar_3_main_main_default.init()
style_sc_sport_bar_3_main_main_default.set_radius(10)
style_sc_sport_bar_3_main_main_default.set_bg_color(lv.color_make(0x00,0xff,0x62))
style_sc_sport_bar_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_bar_3_main_main_default.set_bg_opa(48)
style_sc_sport_bar_3_main_main_default.set_shadow_width(10)
style_sc_sport_bar_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_3_main_main_default.set_shadow_opa(255)
style_sc_sport_bar_3_main_main_default.set_shadow_spread(1)
style_sc_sport_bar_3_main_main_default.set_shadow_ofs_x(0)
style_sc_sport_bar_3_main_main_default.set_shadow_ofs_y(0)

# add style for sc_sport_bar_3
sc_sport_bar_3.add_style(style_sc_sport_bar_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sc_sport_bar_3_main_indicator_default
style_sc_sport_bar_3_main_indicator_default = lv.style_t()
style_sc_sport_bar_3_main_indicator_default.init()
style_sc_sport_bar_3_main_indicator_default.set_radius(10)
style_sc_sport_bar_3_main_indicator_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_3_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_sport_bar_3_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_sport_bar_3_main_indicator_default.set_bg_opa(255)

# add style for sc_sport_bar_3
sc_sport_bar_3.add_style(style_sc_sport_bar_3_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

sc_weather = lv.obj()
sc_weather.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_weather_main_main_default
style_sc_weather_main_main_default = lv.style_t()
style_sc_weather_main_main_default.init()
style_sc_weather_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_weather_main_main_default.set_bg_opa(255)

# add style for sc_weather
sc_weather.add_style(style_sc_weather_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_label_1 = lv.label(sc_weather)
sc_weather_label_1.set_pos(int(17),int(9))
sc_weather_label_1.set_size(100,32)
sc_weather_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_label_1.set_text("滨江区")
sc_weather_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_weather_label_1_main_main_default
style_sc_weather_label_1_main_main_default = lv.style_t()
style_sc_weather_label_1_main_main_default.init()
style_sc_weather_label_1_main_main_default.set_radius(0)
style_sc_weather_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_weather_label_1_main_main_default.set_bg_opa(0)
style_sc_weather_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_weather_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_weather_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_weather_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_weather_label_1_main_main_default.set_text_letter_space(2)
style_sc_weather_label_1_main_main_default.set_text_line_space(0)
style_sc_weather_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_weather_label_1_main_main_default.set_pad_left(0)
style_sc_weather_label_1_main_main_default.set_pad_right(0)
style_sc_weather_label_1_main_main_default.set_pad_top(0)
style_sc_weather_label_1_main_main_default.set_pad_bottom(0)

# add style for sc_weather_label_1
sc_weather_label_1.add_style(style_sc_weather_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_img_1 = lv.img(sc_weather)
sc_weather_img_1.set_pos(int(37),int(41))
sc_weather_img_1.set_size(60,60)
sc_weather_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1400643606.png','rb') as f:
        sc_weather_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1400643606.png')
    sys.exit()

sc_weather_img_1_img = lv.img_dsc_t({
  'data_size': len(sc_weather_img_1_img_data),
  'header': {'always_zero': 0, 'w': 60, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_weather_img_1_img_data
})

sc_weather_img_1.set_src(sc_weather_img_1_img)
sc_weather_img_1.set_pivot(0,0)
sc_weather_img_1.set_angle(0)
# create style style_sc_weather_img_1_main_main_default
style_sc_weather_img_1_main_main_default = lv.style_t()
style_sc_weather_img_1_main_main_default.init()
style_sc_weather_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_weather_img_1_main_main_default.set_img_recolor_opa(0)
style_sc_weather_img_1_main_main_default.set_img_opa(255)

# add style for sc_weather_img_1
sc_weather_img_1.add_style(style_sc_weather_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_label_2 = lv.label(sc_weather)
sc_weather_label_2.set_pos(int(4),int(108))
sc_weather_label_2.set_size(126,25)
sc_weather_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_label_2.set_text("大雨")
sc_weather_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_weather_label_2_main_main_default
style_sc_weather_label_2_main_main_default = lv.style_t()
style_sc_weather_label_2_main_main_default.init()
style_sc_weather_label_2_main_main_default.set_radius(0)
style_sc_weather_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_weather_label_2_main_main_default.set_bg_opa(0)
style_sc_weather_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_weather_label_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_24)
except AttributeError:
    try:
        style_sc_weather_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_sc_weather_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_weather_label_2_main_main_default.set_text_letter_space(2)
style_sc_weather_label_2_main_main_default.set_text_line_space(0)
style_sc_weather_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_weather_label_2_main_main_default.set_pad_left(0)
style_sc_weather_label_2_main_main_default.set_pad_right(0)
style_sc_weather_label_2_main_main_default.set_pad_top(0)
style_sc_weather_label_2_main_main_default.set_pad_bottom(0)

# add style for sc_weather_label_2
sc_weather_label_2.add_style(style_sc_weather_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_label_3 = lv.label(sc_weather)
sc_weather_label_3.set_pos(int(3),int(133))
sc_weather_label_3.set_size(127,20)
sc_weather_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_label_3.set_text("23℃ / 12℃")
sc_weather_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_weather_label_3_main_main_default
style_sc_weather_label_3_main_main_default = lv.style_t()
style_sc_weather_label_3_main_main_default.init()
style_sc_weather_label_3_main_main_default.set_radius(0)
style_sc_weather_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_weather_label_3_main_main_default.set_bg_opa(0)
style_sc_weather_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_weather_label_3_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_weather_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_weather_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_weather_label_3_main_main_default.set_text_letter_space(2)
style_sc_weather_label_3_main_main_default.set_text_line_space(0)
style_sc_weather_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_weather_label_3_main_main_default.set_pad_left(0)
style_sc_weather_label_3_main_main_default.set_pad_right(0)
style_sc_weather_label_3_main_main_default.set_pad_top(0)
style_sc_weather_label_3_main_main_default.set_pad_bottom(0)

# add style for sc_weather_label_3
sc_weather_label_3.add_style(style_sc_weather_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_label_4 = lv.label(sc_weather)
sc_weather_label_4.set_pos(int(17),int(161))
sc_weather_label_4.set_size(100,15)
sc_weather_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_label_4.set_text("空气质量优")
sc_weather_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_weather_label_4_main_main_default
style_sc_weather_label_4_main_main_default = lv.style_t()
style_sc_weather_label_4_main_main_default.init()
style_sc_weather_label_4_main_main_default.set_radius(0)
style_sc_weather_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_weather_label_4_main_main_default.set_bg_opa(0)
style_sc_weather_label_4_main_main_default.set_text_color(lv.color_make(0x61,0xf0,0x2d))
try:
    style_sc_weather_label_4_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_weather_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_weather_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_weather_label_4_main_main_default.set_text_letter_space(2)
style_sc_weather_label_4_main_main_default.set_text_line_space(0)
style_sc_weather_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_weather_label_4_main_main_default.set_pad_left(0)
style_sc_weather_label_4_main_main_default.set_pad_right(0)
style_sc_weather_label_4_main_main_default.set_pad_top(0)
style_sc_weather_label_4_main_main_default.set_pad_bottom(0)

# add style for sc_weather_label_4
sc_weather_label_4.add_style(style_sc_weather_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_label_5 = lv.label(sc_weather)
sc_weather_label_5.set_pos(int(17),int(185))
sc_weather_label_5.set_size(100,15)
sc_weather_label_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_label_5.set_text("上次更新时间")
sc_weather_label_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_weather_label_5_main_main_default
style_sc_weather_label_5_main_main_default = lv.style_t()
style_sc_weather_label_5_main_main_default.init()
style_sc_weather_label_5_main_main_default.set_radius(0)
style_sc_weather_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_weather_label_5_main_main_default.set_bg_opa(0)
style_sc_weather_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_weather_label_5_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_weather_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_weather_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_weather_label_5_main_main_default.set_text_letter_space(2)
style_sc_weather_label_5_main_main_default.set_text_line_space(0)
style_sc_weather_label_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_weather_label_5_main_main_default.set_pad_left(0)
style_sc_weather_label_5_main_main_default.set_pad_right(0)
style_sc_weather_label_5_main_main_default.set_pad_top(0)
style_sc_weather_label_5_main_main_default.set_pad_bottom(0)

# add style for sc_weather_label_5
sc_weather_label_5.add_style(style_sc_weather_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_weather_label_6 = lv.label(sc_weather)
sc_weather_label_6.set_pos(int(17),int(206))
sc_weather_label_6.set_size(100,18)
sc_weather_label_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_weather_label_6.set_text("2025-07-12")
sc_weather_label_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_weather_label_6_main_main_default
style_sc_weather_label_6_main_main_default = lv.style_t()
style_sc_weather_label_6_main_main_default.init()
style_sc_weather_label_6_main_main_default.set_radius(0)
style_sc_weather_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_weather_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_weather_label_6_main_main_default.set_bg_opa(0)
style_sc_weather_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_weather_label_6_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_weather_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_weather_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_weather_label_6_main_main_default.set_text_letter_space(2)
style_sc_weather_label_6_main_main_default.set_text_line_space(0)
style_sc_weather_label_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_weather_label_6_main_main_default.set_pad_left(0)
style_sc_weather_label_6_main_main_default.set_pad_right(0)
style_sc_weather_label_6_main_main_default.set_pad_top(0)
style_sc_weather_label_6_main_main_default.set_pad_bottom(0)

# add style for sc_weather_label_6
sc_weather_label_6.add_style(style_sc_weather_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2 = lv.obj()
sc_spo2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_spo2_main_main_default
style_sc_spo2_main_main_default = lv.style_t()
style_sc_spo2_main_main_default.init()
style_sc_spo2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_spo2_main_main_default.set_bg_opa(255)

# add style for sc_spo2
sc_spo2.add_style(style_sc_spo2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_chart_1 = lv.chart(sc_spo2)
sc_spo2_chart_1.set_pos(int(30),int(33))
sc_spo2_chart_1.set_size(106,141)
sc_spo2_chart_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_chart_1.set_type(lv.chart.TYPE.LINE)
sc_spo2_chart_1.set_range(lv.chart.AXIS.PRIMARY_Y, 0, 100)
sc_spo2_chart_1.set_div_line_count(3, 0)
sc_spo2_chart_1.set_point_count(24)
chart_series_0 = lv.chart.add_series(sc_spo2_chart_1, lv.color_make(0x0a,0xff,0x12), lv.chart.AXIS.PRIMARY_Y);
sc_spo2_chart_1.set_next_value(chart_series_0, 70)
sc_spo2_chart_1.set_next_value(chart_series_0, 60)
sc_spo2_chart_1.set_next_value(chart_series_0, 80)
sc_spo2_chart_1.set_next_value(chart_series_0, 76)
sc_spo2_chart_1.set_next_value(chart_series_0, 70)
sc_spo2_chart_1.set_next_value(chart_series_0, 80)
sc_spo2_chart_1.set_next_value(chart_series_0, 80)
sc_spo2_chart_1.set_next_value(chart_series_0, 80)
sc_spo2_chart_1.set_next_value(chart_series_0, 80)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
sc_spo2_chart_1.set_next_value(chart_series_0, 72)
# create style style_sc_spo2_chart_1_main_main_default
style_sc_spo2_chart_1_main_main_default = lv.style_t()
style_sc_spo2_chart_1_main_main_default.init()
style_sc_spo2_chart_1_main_main_default.set_radius(0)
style_sc_spo2_chart_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_spo2_chart_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sc_spo2_chart_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_chart_1_main_main_default.set_bg_opa(255)
style_sc_spo2_chart_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_sc_spo2_chart_1_main_main_default.set_border_width(0)
style_sc_spo2_chart_1_main_main_default.set_border_opa(201)
style_sc_spo2_chart_1_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_sc_spo2_chart_1_main_main_default.set_line_width(1)
style_sc_spo2_chart_1_main_main_default.set_line_opa(255)

# add style for sc_spo2_chart_1
sc_spo2_chart_1.add_style(style_sc_spo2_chart_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_1 = lv.label(sc_spo2)
sc_spo2_label_1.set_pos(int(-6),int(27))
sc_spo2_label_1.set_size(42,16)
sc_spo2_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_1.set_text("100%")
sc_spo2_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_1_main_main_default
style_sc_spo2_label_1_main_main_default = lv.style_t()
style_sc_spo2_label_1_main_main_default.init()
style_sc_spo2_label_1_main_main_default.set_radius(0)
style_sc_spo2_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_1_main_main_default.set_bg_opa(0)
style_sc_spo2_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_1_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_1_main_main_default.set_text_line_space(0)
style_sc_spo2_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_1_main_main_default.set_pad_left(0)
style_sc_spo2_label_1_main_main_default.set_pad_right(0)
style_sc_spo2_label_1_main_main_default.set_pad_top(0)
style_sc_spo2_label_1_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_1
sc_spo2_label_1.add_style(style_sc_spo2_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_7 = lv.label(sc_spo2)
sc_spo2_label_7.set_pos(int(-7),int(158))
sc_spo2_label_7.set_size(42,16)
sc_spo2_label_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_7.set_text("90%")
sc_spo2_label_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_7_main_main_default
style_sc_spo2_label_7_main_main_default = lv.style_t()
style_sc_spo2_label_7_main_main_default.init()
style_sc_spo2_label_7_main_main_default.set_radius(0)
style_sc_spo2_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_7_main_main_default.set_bg_opa(0)
style_sc_spo2_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_7_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_7_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_7_main_main_default.set_text_line_space(0)
style_sc_spo2_label_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_7_main_main_default.set_pad_left(0)
style_sc_spo2_label_7_main_main_default.set_pad_right(0)
style_sc_spo2_label_7_main_main_default.set_pad_top(0)
style_sc_spo2_label_7_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_7
sc_spo2_label_7.add_style(style_sc_spo2_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_10 = lv.label(sc_spo2)
sc_spo2_label_10.set_pos(int(10),int(174))
sc_spo2_label_10.set_size(50,16)
sc_spo2_label_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_10.set_text("00:00")
sc_spo2_label_10.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_10_main_main_default
style_sc_spo2_label_10_main_main_default = lv.style_t()
style_sc_spo2_label_10_main_main_default.init()
style_sc_spo2_label_10_main_main_default.set_radius(0)
style_sc_spo2_label_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_10_main_main_default.set_bg_opa(0)
style_sc_spo2_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_10_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_10_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_10_main_main_default.set_text_line_space(0)
style_sc_spo2_label_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_10_main_main_default.set_pad_left(0)
style_sc_spo2_label_10_main_main_default.set_pad_right(0)
style_sc_spo2_label_10_main_main_default.set_pad_top(0)
style_sc_spo2_label_10_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_10
sc_spo2_label_10.add_style(style_sc_spo2_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_9 = lv.label(sc_spo2)
sc_spo2_label_9.set_pos(int(0),int(206))
sc_spo2_label_9.set_size(135,16)
sc_spo2_label_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_9.set_text("MAX:99 MIN:99")
sc_spo2_label_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_9_main_main_default
style_sc_spo2_label_9_main_main_default = lv.style_t()
style_sc_spo2_label_9_main_main_default.init()
style_sc_spo2_label_9_main_main_default.set_radius(0)
style_sc_spo2_label_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_9_main_main_default.set_bg_opa(0)
style_sc_spo2_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_9_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_9_main_main_default.set_text_letter_space(2)
style_sc_spo2_label_9_main_main_default.set_text_line_space(0)
style_sc_spo2_label_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_9_main_main_default.set_pad_left(0)
style_sc_spo2_label_9_main_main_default.set_pad_right(0)
style_sc_spo2_label_9_main_main_default.set_pad_top(0)
style_sc_spo2_label_9_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_9
sc_spo2_label_9.add_style(style_sc_spo2_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_4 = lv.label(sc_spo2)
sc_spo2_label_4.set_pos(int(-7),int(89))
sc_spo2_label_4.set_size(42,16)
sc_spo2_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_4.set_text("95%")
sc_spo2_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_4_main_main_default
style_sc_spo2_label_4_main_main_default = lv.style_t()
style_sc_spo2_label_4_main_main_default.init()
style_sc_spo2_label_4_main_main_default.set_radius(0)
style_sc_spo2_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_4_main_main_default.set_bg_opa(0)
style_sc_spo2_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_4_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_4_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_4_main_main_default.set_text_line_space(0)
style_sc_spo2_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_4_main_main_default.set_pad_left(0)
style_sc_spo2_label_4_main_main_default.set_pad_right(0)
style_sc_spo2_label_4_main_main_default.set_pad_top(0)
style_sc_spo2_label_4_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_4
sc_spo2_label_4.add_style(style_sc_spo2_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_11 = lv.label(sc_spo2)
sc_spo2_label_11.set_pos(int(80),int(174))
sc_spo2_label_11.set_size(49,16)
sc_spo2_label_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_11.set_text("24:00")
sc_spo2_label_11.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_11_main_main_default
style_sc_spo2_label_11_main_main_default = lv.style_t()
style_sc_spo2_label_11_main_main_default.init()
style_sc_spo2_label_11_main_main_default.set_radius(0)
style_sc_spo2_label_11_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_11_main_main_default.set_bg_opa(0)
style_sc_spo2_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_11_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_11_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_11_main_main_default.set_text_line_space(0)
style_sc_spo2_label_11_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_11_main_main_default.set_pad_left(0)
style_sc_spo2_label_11_main_main_default.set_pad_right(0)
style_sc_spo2_label_11_main_main_default.set_pad_top(0)
style_sc_spo2_label_11_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_11
sc_spo2_label_11.add_style(style_sc_spo2_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_12 = lv.label(sc_spo2)
sc_spo2_label_12.set_pos(int(0),int(3))
sc_spo2_label_12.set_size(45,18)
sc_spo2_label_12.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_12.set_text("SpO2")
sc_spo2_label_12.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_12_main_main_default
style_sc_spo2_label_12_main_main_default = lv.style_t()
style_sc_spo2_label_12_main_main_default.init()
style_sc_spo2_label_12_main_main_default.set_radius(0)
style_sc_spo2_label_12_main_main_default.set_bg_color(lv.color_make(0xf2,0x5f,0x5f))
style_sc_spo2_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_12_main_main_default.set_bg_opa(255)
style_sc_spo2_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_12_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_12_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_12_main_main_default.set_text_line_space(0)
style_sc_spo2_label_12_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_12_main_main_default.set_pad_left(0)
style_sc_spo2_label_12_main_main_default.set_pad_right(0)
style_sc_spo2_label_12_main_main_default.set_pad_top(0)
style_sc_spo2_label_12_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_12
sc_spo2_label_12.add_style(style_sc_spo2_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_spo2_label_13 = lv.label(sc_spo2)
sc_spo2_label_13.set_pos(int(52),int(4))
sc_spo2_label_13.set_size(30,17)
sc_spo2_label_13.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_spo2_label_13.set_text("99%")
sc_spo2_label_13.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_spo2_label_13_main_main_default
style_sc_spo2_label_13_main_main_default = lv.style_t()
style_sc_spo2_label_13_main_main_default.init()
style_sc_spo2_label_13_main_main_default.set_radius(0)
style_sc_spo2_label_13_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_spo2_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_spo2_label_13_main_main_default.set_bg_opa(0)
style_sc_spo2_label_13_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_spo2_label_13_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_spo2_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_spo2_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_spo2_label_13_main_main_default.set_text_letter_space(1)
style_sc_spo2_label_13_main_main_default.set_text_line_space(0)
style_sc_spo2_label_13_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_spo2_label_13_main_main_default.set_pad_left(0)
style_sc_spo2_label_13_main_main_default.set_pad_right(0)
style_sc_spo2_label_13_main_main_default.set_pad_top(0)
style_sc_spo2_label_13_main_main_default.set_pad_bottom(0)

# add style for sc_spo2_label_13
sc_spo2_label_13.add_style(style_sc_spo2_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart = lv.obj()
sc_heart.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_heart_main_main_default
style_sc_heart_main_main_default = lv.style_t()
style_sc_heart_main_main_default.init()
style_sc_heart_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_heart_main_main_default.set_bg_opa(255)

# add style for sc_heart
sc_heart.add_style(style_sc_heart_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_chart_1 = lv.chart(sc_heart)
sc_heart_chart_1.set_pos(int(29),int(35))
sc_heart_chart_1.set_size(104,164)
sc_heart_chart_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_chart_1.set_type(lv.chart.TYPE.LINE)
sc_heart_chart_1.set_range(lv.chart.AXIS.PRIMARY_Y, 0, 100)
sc_heart_chart_1.set_div_line_count(5, 0)
sc_heart_chart_1.set_point_count(24)
chart_series_0 = lv.chart.add_series(sc_heart_chart_1, lv.color_make(0xff,0x0a,0x0a), lv.chart.AXIS.PRIMARY_Y);
sc_heart_chart_1.set_next_value(chart_series_0, 70)
sc_heart_chart_1.set_next_value(chart_series_0, 60)
sc_heart_chart_1.set_next_value(chart_series_0, 80)
sc_heart_chart_1.set_next_value(chart_series_0, 76)
sc_heart_chart_1.set_next_value(chart_series_0, 70)
sc_heart_chart_1.set_next_value(chart_series_0, 80)
sc_heart_chart_1.set_next_value(chart_series_0, 80)
sc_heart_chart_1.set_next_value(chart_series_0, 80)
sc_heart_chart_1.set_next_value(chart_series_0, 80)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
sc_heart_chart_1.set_next_value(chart_series_0, 72)
# create style style_sc_heart_chart_1_main_main_default
style_sc_heart_chart_1_main_main_default = lv.style_t()
style_sc_heart_chart_1_main_main_default.init()
style_sc_heart_chart_1_main_main_default.set_radius(0)
style_sc_heart_chart_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_heart_chart_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sc_heart_chart_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_chart_1_main_main_default.set_bg_opa(255)
style_sc_heart_chart_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_sc_heart_chart_1_main_main_default.set_border_width(0)
style_sc_heart_chart_1_main_main_default.set_border_opa(201)
style_sc_heart_chart_1_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_sc_heart_chart_1_main_main_default.set_line_width(1)
style_sc_heart_chart_1_main_main_default.set_line_opa(255)

# add style for sc_heart_chart_1
sc_heart_chart_1.add_style(style_sc_heart_chart_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_1 = lv.label(sc_heart)
sc_heart_label_1.set_pos(int(-8),int(29))
sc_heart_label_1.set_size(42,16)
sc_heart_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_1.set_text("175")
sc_heart_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_1_main_main_default
style_sc_heart_label_1_main_main_default = lv.style_t()
style_sc_heart_label_1_main_main_default.init()
style_sc_heart_label_1_main_main_default.set_radius(0)
style_sc_heart_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_1_main_main_default.set_bg_opa(0)
style_sc_heart_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_1_main_main_default.set_text_letter_space(1)
style_sc_heart_label_1_main_main_default.set_text_line_space(0)
style_sc_heart_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_1_main_main_default.set_pad_left(0)
style_sc_heart_label_1_main_main_default.set_pad_right(0)
style_sc_heart_label_1_main_main_default.set_pad_top(0)
style_sc_heart_label_1_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_1
sc_heart_label_1.add_style(style_sc_heart_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_2 = lv.label(sc_heart)
sc_heart_label_2.set_pos(int(-7),int(64))
sc_heart_label_2.set_size(42,16)
sc_heart_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_2.set_text("150")
sc_heart_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_2_main_main_default
style_sc_heart_label_2_main_main_default = lv.style_t()
style_sc_heart_label_2_main_main_default.init()
style_sc_heart_label_2_main_main_default.set_radius(0)
style_sc_heart_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_2_main_main_default.set_bg_opa(0)
style_sc_heart_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_2_main_main_default.set_text_letter_space(1)
style_sc_heart_label_2_main_main_default.set_text_line_space(0)
style_sc_heart_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_2_main_main_default.set_pad_left(0)
style_sc_heart_label_2_main_main_default.set_pad_right(0)
style_sc_heart_label_2_main_main_default.set_pad_top(0)
style_sc_heart_label_2_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_2
sc_heart_label_2.add_style(style_sc_heart_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_3 = lv.label(sc_heart)
sc_heart_label_3.set_pos(int(-7),int(146))
sc_heart_label_3.set_size(42,16)
sc_heart_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_3.set_text("75")
sc_heart_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_3_main_main_default
style_sc_heart_label_3_main_main_default = lv.style_t()
style_sc_heart_label_3_main_main_default.init()
style_sc_heart_label_3_main_main_default.set_radius(0)
style_sc_heart_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_3_main_main_default.set_bg_opa(0)
style_sc_heart_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_3_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_3_main_main_default.set_text_letter_space(1)
style_sc_heart_label_3_main_main_default.set_text_line_space(0)
style_sc_heart_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_3_main_main_default.set_pad_left(0)
style_sc_heart_label_3_main_main_default.set_pad_right(0)
style_sc_heart_label_3_main_main_default.set_pad_top(0)
style_sc_heart_label_3_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_3
sc_heart_label_3.add_style(style_sc_heart_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_7 = lv.label(sc_heart)
sc_heart_label_7.set_pos(int(-7),int(184))
sc_heart_label_7.set_size(42,16)
sc_heart_label_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_7.set_text("50")
sc_heart_label_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_7_main_main_default
style_sc_heart_label_7_main_main_default = lv.style_t()
style_sc_heart_label_7_main_main_default.init()
style_sc_heart_label_7_main_main_default.set_radius(0)
style_sc_heart_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_7_main_main_default.set_bg_opa(0)
style_sc_heart_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_7_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_7_main_main_default.set_text_letter_space(1)
style_sc_heart_label_7_main_main_default.set_text_line_space(0)
style_sc_heart_label_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_7_main_main_default.set_pad_left(0)
style_sc_heart_label_7_main_main_default.set_pad_right(0)
style_sc_heart_label_7_main_main_default.set_pad_top(0)
style_sc_heart_label_7_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_7
sc_heart_label_7.add_style(style_sc_heart_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_10 = lv.label(sc_heart)
sc_heart_label_10.set_pos(int(4),int(199))
sc_heart_label_10.set_size(55,16)
sc_heart_label_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_10.set_text("00:00")
sc_heart_label_10.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_10_main_main_default
style_sc_heart_label_10_main_main_default = lv.style_t()
style_sc_heart_label_10_main_main_default.init()
style_sc_heart_label_10_main_main_default.set_radius(0)
style_sc_heart_label_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_10_main_main_default.set_bg_opa(0)
style_sc_heart_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_10_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_10_main_main_default.set_text_letter_space(1)
style_sc_heart_label_10_main_main_default.set_text_line_space(0)
style_sc_heart_label_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_10_main_main_default.set_pad_left(0)
style_sc_heart_label_10_main_main_default.set_pad_right(0)
style_sc_heart_label_10_main_main_default.set_pad_top(0)
style_sc_heart_label_10_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_10
sc_heart_label_10.add_style(style_sc_heart_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_8 = lv.label(sc_heart)
sc_heart_label_8.set_pos(int(4),int(4))
sc_heart_label_8.set_size(127,20)
sc_heart_label_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_8.set_text("Heart: 87BMP")
sc_heart_label_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_8_main_main_default
style_sc_heart_label_8_main_main_default = lv.style_t()
style_sc_heart_label_8_main_main_default.init()
style_sc_heart_label_8_main_main_default.set_radius(0)
style_sc_heart_label_8_main_main_default.set_bg_color(lv.color_make(0x5f,0x5c,0xff))
style_sc_heart_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_8_main_main_default.set_bg_opa(255)
style_sc_heart_label_8_main_main_default.set_shadow_width(2)
style_sc_heart_label_8_main_main_default.set_shadow_color(lv.color_make(0xff,0xff,0xff))
style_sc_heart_label_8_main_main_default.set_shadow_opa(99)
style_sc_heart_label_8_main_main_default.set_shadow_spread(2)
style_sc_heart_label_8_main_main_default.set_shadow_ofs_x(0)
style_sc_heart_label_8_main_main_default.set_shadow_ofs_y(0)
style_sc_heart_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_8_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_8_main_main_default.set_text_letter_space(1)
style_sc_heart_label_8_main_main_default.set_text_line_space(0)
style_sc_heart_label_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_8_main_main_default.set_pad_left(1)
style_sc_heart_label_8_main_main_default.set_pad_right(1)
style_sc_heart_label_8_main_main_default.set_pad_top(1)
style_sc_heart_label_8_main_main_default.set_pad_bottom(1)

# add style for sc_heart_label_8
sc_heart_label_8.add_style(style_sc_heart_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_9 = lv.label(sc_heart)
sc_heart_label_9.set_pos(int(-1),int(220))
sc_heart_label_9.set_size(135,22)
sc_heart_label_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_9.set_text("MAX:76 MIN:66")
sc_heart_label_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_9_main_main_default
style_sc_heart_label_9_main_main_default = lv.style_t()
style_sc_heart_label_9_main_main_default.init()
style_sc_heart_label_9_main_main_default.set_radius(0)
style_sc_heart_label_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_9_main_main_default.set_bg_opa(0)
style_sc_heart_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_9_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_9_main_main_default.set_text_letter_space(2)
style_sc_heart_label_9_main_main_default.set_text_line_space(0)
style_sc_heart_label_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_9_main_main_default.set_pad_left(0)
style_sc_heart_label_9_main_main_default.set_pad_right(0)
style_sc_heart_label_9_main_main_default.set_pad_top(0)
style_sc_heart_label_9_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_9
sc_heart_label_9.add_style(style_sc_heart_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_4 = lv.label(sc_heart)
sc_heart_label_4.set_pos(int(-8),int(104))
sc_heart_label_4.set_size(42,16)
sc_heart_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_4.set_text("100")
sc_heart_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_4_main_main_default
style_sc_heart_label_4_main_main_default = lv.style_t()
style_sc_heart_label_4_main_main_default.init()
style_sc_heart_label_4_main_main_default.set_radius(0)
style_sc_heart_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_4_main_main_default.set_bg_opa(0)
style_sc_heart_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_4_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_4_main_main_default.set_text_letter_space(1)
style_sc_heart_label_4_main_main_default.set_text_line_space(0)
style_sc_heart_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_4_main_main_default.set_pad_left(0)
style_sc_heart_label_4_main_main_default.set_pad_right(0)
style_sc_heart_label_4_main_main_default.set_pad_top(0)
style_sc_heart_label_4_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_4
sc_heart_label_4.add_style(style_sc_heart_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_heart_label_11 = lv.label(sc_heart)
sc_heart_label_11.set_pos(int(84),int(199))
sc_heart_label_11.set_size(50,16)
sc_heart_label_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_heart_label_11.set_text("24:00")
sc_heart_label_11.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_heart_label_11_main_main_default
style_sc_heart_label_11_main_main_default = lv.style_t()
style_sc_heart_label_11_main_main_default.init()
style_sc_heart_label_11_main_main_default.set_radius(0)
style_sc_heart_label_11_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_heart_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_heart_label_11_main_main_default.set_bg_opa(0)
style_sc_heart_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_heart_label_11_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_16)
except AttributeError:
    try:
        style_sc_heart_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_sc_heart_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_heart_label_11_main_main_default.set_text_letter_space(1)
style_sc_heart_label_11_main_main_default.set_text_line_space(0)
style_sc_heart_label_11_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_heart_label_11_main_main_default.set_pad_left(0)
style_sc_heart_label_11_main_main_default.set_pad_right(0)
style_sc_heart_label_11_main_main_default.set_pad_top(0)
style_sc_heart_label_11_main_main_default.set_pad_bottom(0)

# add style for sc_heart_label_11
sc_heart_label_11.add_style(style_sc_heart_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo = lv.obj()
demo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_demo_main_main_default
style_demo_main_main_default = lv.style_t()
style_demo_main_main_default.init()
style_demo_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_demo_main_main_default.set_bg_opa(255)

# add style for demo
demo.add_style(style_demo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_1 = lv.img(demo)
demo_img_1.set_pos(int(12),int(18))
demo_img_1.set_size(25,60)
demo_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1321783211.png','rb') as f:
        demo_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1321783211.png')
    sys.exit()

demo_img_1_img = lv.img_dsc_t({
  'data_size': len(demo_img_1_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_1_img_data
})

demo_img_1.set_src(demo_img_1_img)
demo_img_1.set_pivot(0,0)
demo_img_1.set_angle(0)
# create style style_demo_img_1_main_main_default
style_demo_img_1_main_main_default = lv.style_t()
style_demo_img_1_main_main_default.init()
style_demo_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_1_main_main_default.set_img_recolor_opa(0)
style_demo_img_1_main_main_default.set_img_opa(255)

# add style for demo_img_1
demo_img_1.add_style(style_demo_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_2 = lv.img(demo)
demo_img_2.set_pos(int(42),int(48))
demo_img_2.set_size(25,60)
demo_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp895974742.png','rb') as f:
        demo_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp895974742.png')
    sys.exit()

demo_img_2_img = lv.img_dsc_t({
  'data_size': len(demo_img_2_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_2_img_data
})

demo_img_2.set_src(demo_img_2_img)
demo_img_2.set_pivot(0,0)
demo_img_2.set_angle(0)
# create style style_demo_img_2_main_main_default
style_demo_img_2_main_main_default = lv.style_t()
style_demo_img_2_main_main_default.init()
style_demo_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_2_main_main_default.set_img_recolor_opa(0)
style_demo_img_2_main_main_default.set_img_opa(255)

# add style for demo_img_2
demo_img_2.add_style(style_demo_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_3 = lv.img(demo)
demo_img_3.set_pos(int(72),int(78))
demo_img_3.set_size(25,60)
demo_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1181234601.png','rb') as f:
        demo_img_3_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1181234601.png')
    sys.exit()

demo_img_3_img = lv.img_dsc_t({
  'data_size': len(demo_img_3_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_3_img_data
})

demo_img_3.set_src(demo_img_3_img)
demo_img_3.set_pivot(0,0)
demo_img_3.set_angle(0)
# create style style_demo_img_3_main_main_default
style_demo_img_3_main_main_default = lv.style_t()
style_demo_img_3_main_main_default.init()
style_demo_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_3_main_main_default.set_img_recolor_opa(0)
style_demo_img_3_main_main_default.set_img_opa(255)

# add style for demo_img_3
demo_img_3.add_style(style_demo_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_4 = lv.img(demo)
demo_img_4.set_pos(int(17),int(120))
demo_img_4.set_size(25,60)
demo_img_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1036523352.png','rb') as f:
        demo_img_4_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1036523352.png')
    sys.exit()

demo_img_4_img = lv.img_dsc_t({
  'data_size': len(demo_img_4_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_4_img_data
})

demo_img_4.set_src(demo_img_4_img)
demo_img_4.set_pivot(0,0)
demo_img_4.set_angle(0)
# create style style_demo_img_4_main_main_default
style_demo_img_4_main_main_default = lv.style_t()
style_demo_img_4_main_main_default.init()
style_demo_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_4_main_main_default.set_img_recolor_opa(0)
style_demo_img_4_main_main_default.set_img_opa(255)

# add style for demo_img_4
demo_img_4.add_style(style_demo_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_5 = lv.img(demo)
demo_img_5.set_pos(int(42),int(138))
demo_img_5.set_size(25,60)
demo_img_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1040685991.png','rb') as f:
        demo_img_5_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-1040685991.png')
    sys.exit()

demo_img_5_img = lv.img_dsc_t({
  'data_size': len(demo_img_5_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_5_img_data
})

demo_img_5.set_src(demo_img_5_img)
demo_img_5.set_pivot(0,0)
demo_img_5.set_angle(0)
# create style style_demo_img_5_main_main_default
style_demo_img_5_main_main_default = lv.style_t()
style_demo_img_5_main_main_default.init()
style_demo_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_5_main_main_default.set_img_recolor_opa(0)
style_demo_img_5_main_main_default.set_img_opa(255)

# add style for demo_img_5
demo_img_5.add_style(style_demo_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_6 = lv.img(demo)
demo_img_6.set_pos(int(72),int(151))
demo_img_6.set_size(25,60)
demo_img_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1177071962.png','rb') as f:
        demo_img_6_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1177071962.png')
    sys.exit()

demo_img_6_img = lv.img_dsc_t({
  'data_size': len(demo_img_6_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_6_img_data
})

demo_img_6.set_src(demo_img_6_img)
demo_img_6.set_pivot(0,0)
demo_img_6.set_angle(0)
# create style style_demo_img_6_main_main_default
style_demo_img_6_main_main_default = lv.style_t()
style_demo_img_6_main_main_default.init()
style_demo_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_6_main_main_default.set_img_recolor_opa(0)
style_demo_img_6_main_main_default.set_img_opa(255)

# add style for demo_img_6
demo_img_6.add_style(style_demo_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_7 = lv.img(demo)
demo_img_7.set_pos(int(46),int(7))
demo_img_7.set_size(25,60)
demo_img_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-900137381.png','rb') as f:
        demo_img_7_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-900137381.png')
    sys.exit()

demo_img_7_img = lv.img_dsc_t({
  'data_size': len(demo_img_7_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_7_img_data
})

demo_img_7.set_src(demo_img_7_img)
demo_img_7.set_pivot(0,0)
demo_img_7.set_angle(0)
# create style style_demo_img_7_main_main_default
style_demo_img_7_main_main_default = lv.style_t()
style_demo_img_7_main_main_default.init()
style_demo_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_7_main_main_default.set_img_recolor_opa(0)
style_demo_img_7_main_main_default.set_img_opa(255)

# add style for demo_img_7
demo_img_7.add_style(style_demo_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_8 = lv.img(demo)
demo_img_8.set_pos(int(85),int(37))
demo_img_8.set_size(25,60)
demo_img_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1317620572.png','rb') as f:
        demo_img_8_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp1317620572.png')
    sys.exit()

demo_img_8_img = lv.img_dsc_t({
  'data_size': len(demo_img_8_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_8_img_data
})

demo_img_8.set_src(demo_img_8_img)
demo_img_8.set_pivot(0,0)
demo_img_8.set_angle(0)
# create style style_demo_img_8_main_main_default
style_demo_img_8_main_main_default = lv.style_t()
style_demo_img_8_main_main_default.init()
style_demo_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_8_main_main_default.set_img_recolor_opa(0)
style_demo_img_8_main_main_default.set_img_opa(255)

# add style for demo_img_8
demo_img_8.add_style(style_demo_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_9 = lv.img(demo)
demo_img_9.set_pos(int(97),int(157))
demo_img_9.set_size(25,60)
demo_img_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-759588771.png','rb') as f:
        demo_img_9_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp-759588771.png')
    sys.exit()

demo_img_9_img = lv.img_dsc_t({
  'data_size': len(demo_img_9_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_9_img_data
})

demo_img_9.set_src(demo_img_9_img)
demo_img_9.set_pivot(0,0)
demo_img_9.set_angle(0)
# create style style_demo_img_9_main_main_default
style_demo_img_9_main_main_default = lv.style_t()
style_demo_img_9_main_main_default.init()
style_demo_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_9_main_main_default.set_img_recolor_opa(0)
style_demo_img_9_main_main_default.set_img_opa(255)

# add style for demo_img_9
demo_img_9.add_style(style_demo_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

demo_img_10 = lv.img(demo)
demo_img_10.set_pos(int(97),int(90))
demo_img_10.set_size(25,60)
demo_img_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
demo_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png','rb') as f:
        demo_img_10_img_data = f.read()
except:
    print('Could not open D:\\code\\wwatch-guider\\generated\\mPythonImages\\mp755426132.png')
    sys.exit()

demo_img_10_img = lv.img_dsc_t({
  'data_size': len(demo_img_10_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': demo_img_10_img_data
})

demo_img_10.set_src(demo_img_10_img)
demo_img_10.set_pivot(0,0)
demo_img_10.set_angle(0)
# create style style_demo_img_10_main_main_default
style_demo_img_10_main_main_default = lv.style_t()
style_demo_img_10_main_main_default.init()
style_demo_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_demo_img_10_main_main_default.set_img_recolor_opa(0)
style_demo_img_10_main_main_default.set_img_opa(255)

# add style for demo_img_10
demo_img_10.add_style(style_demo_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)




# content from custom.py

# Load the default screen
lv.scr_load(sc_main)

while SDL.check():
    time.sleep_ms(5)
