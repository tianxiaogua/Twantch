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
SDL.init(w=172,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(172*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 172
disp_drv.ver_res = 320
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
sc_main_img_1.set_size(172,320)
sc_main_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp530962983.png','rb') as f:
        sc_main_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp530962983.png')
    sys.exit()

sc_main_img_1_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_1_img_data),
  'header': {'always_zero': 0, 'w': 172, 'h': 320, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
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

sc_main_img_2 = lv.img(sc_main)
sc_main_img_2.set_pos(int(-66),int(146))
sc_main_img_2.set_size(142,166)
sc_main_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
sc_main_img_2.update_layout()
sc_main_img_2_anim_move_x = lv.anim_t()
sc_main_img_2_anim_move_x.init()
sc_main_img_2_anim_move_x.set_var(sc_main_img_2)
sc_main_img_2_anim_move_x.set_values(sc_main_img_2.get_x(), 6)
sc_main_img_2_anim_move_x.set_time(1000)
sc_main_img_2_anim_move_x.set_path_cb(lv.anim_t.path_ease_out)
sc_main_img_2_anim_move_x.set_custom_exec_cb(lambda a,val: anim_x_cb(sc_main_img_2,val))
lv.anim_t.start(sc_main_img_2_anim_move_x)

sc_main_img_2_anim_move_y = lv.anim_t()
sc_main_img_2_anim_move_y.init()
sc_main_img_2_anim_move_y.set_var(sc_main_img_2)
sc_main_img_2_anim_move_y.set_values(sc_main_img_2.get_y(), 144)
sc_main_img_2_anim_move_y.set_time(1000)
sc_main_img_2_anim_move_y.set_path_cb(lv.anim_t.path_ease_out)
sc_main_img_2_anim_move_y.set_custom_exec_cb(lambda a,val: anim_y_cb(sc_main_img_2,val))
lv.anim_t.start(sc_main_img_2_anim_move_y)

try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp460841443.png','rb') as f:
        sc_main_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp460841443.png')
    sys.exit()

sc_main_img_2_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_2_img_data),
  'header': {'always_zero': 0, 'w': 142, 'h': 166, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_main_img_2_img_data
})

sc_main_img_2.set_src(sc_main_img_2_img)
sc_main_img_2.set_pivot(0,0)
sc_main_img_2.set_angle(0)
# create style style_sc_main_img_2_main_main_default
style_sc_main_img_2_main_main_default = lv.style_t()
style_sc_main_img_2_main_main_default.init()
style_sc_main_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_main_img_2_main_main_default.set_img_recolor_opa(0)
style_sc_main_img_2_main_main_default.set_img_opa(255)

# add style for sc_main_img_2
sc_main_img_2.add_style(style_sc_main_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_main_img_num_0 = lv.img(sc_main)
sc_main_img_num_0.set_pos(int(10),int(31))
sc_main_img_num_0.set_size(29,78)
sc_main_img_num_0.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_0.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png','rb') as f:
        sc_main_img_num_0_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png')
    sys.exit()

sc_main_img_num_0_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_0_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
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
sc_main_img_num_1.set_pos(int(39),int(31))
sc_main_img_num_1.set_size(29,78)
sc_main_img_num_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png','rb') as f:
        sc_main_img_num_1_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png')
    sys.exit()

sc_main_img_num_1_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_1_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
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
sc_main_img_num_2.set_pos(int(95),int(31))
sc_main_img_num_2.set_size(29,78)
sc_main_img_num_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png','rb') as f:
        sc_main_img_num_2_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png')
    sys.exit()

sc_main_img_num_2_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_2_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
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
sc_main_img_num_3.set_pos(int(131),int(31))
sc_main_img_num_3.set_size(29,78)
sc_main_img_num_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_img_num_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png','rb') as f:
        sc_main_img_num_3_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png')
    sys.exit()

sc_main_img_num_3_img = lv.img_dsc_t({
  'data_size': len(sc_main_img_num_3_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
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

sc_main_bar_battery = lv.bar(sc_main)
sc_main_bar_battery.set_pos(int(61),int(9))
sc_main_bar_battery.set_size(51,6)
sc_main_bar_battery.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_main_bar_battery.set_style_anim_time(600, 0)
sc_main_bar_battery.set_mode(lv.bar.MODE.NORMAL)
sc_main_bar_battery.set_value(80, lv.ANIM.ON)
# create style style_sc_main_bar_battery_main_main_default
style_sc_main_bar_battery_main_main_default = lv.style_t()
style_sc_main_bar_battery_main_main_default.init()
style_sc_main_bar_battery_main_main_default.set_radius(10)
style_sc_main_bar_battery_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sc_main_bar_battery_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_sc_main_bar_battery_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.HOR)
style_sc_main_bar_battery_main_main_default.set_bg_opa(124)
style_sc_main_bar_battery_main_main_default.set_shadow_width(2)
style_sc_main_bar_battery_main_main_default.set_shadow_color(lv.color_make(0xff,0xff,0xff))
style_sc_main_bar_battery_main_main_default.set_shadow_opa(196)
style_sc_main_bar_battery_main_main_default.set_shadow_spread(2)
style_sc_main_bar_battery_main_main_default.set_shadow_ofs_x(0)
style_sc_main_bar_battery_main_main_default.set_shadow_ofs_y(0)

# add style for sc_main_bar_battery
sc_main_bar_battery.add_style(style_sc_main_bar_battery_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sc_main_bar_battery_main_indicator_default
style_sc_main_bar_battery_main_indicator_default = lv.style_t()
style_sc_main_bar_battery_main_indicator_default.init()
style_sc_main_bar_battery_main_indicator_default.set_radius(10)
style_sc_main_bar_battery_main_indicator_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_main_bar_battery_main_indicator_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_main_bar_battery_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_main_bar_battery_main_indicator_default.set_bg_opa(255)

# add style for sc_main_bar_battery
sc_main_bar_battery.add_style(style_sc_main_bar_battery_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

sc_menu = lv.obj()
sc_menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sc_menu_main_main_default
style_sc_menu_main_main_default = lv.style_t()
style_sc_menu_main_main_default.init()
style_sc_menu_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_sc_menu_main_main_default.set_bg_opa(255)

# add style for sc_menu
sc_menu.add_style(style_sc_menu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_1 = lv.img(sc_menu)
sc_menu_img_1.set_pos(int(46),int(1))
sc_menu_img_1.set_size(81,80)
sc_menu_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-822717151.png','rb') as f:
        sc_menu_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-822717151.png')
    sys.exit()

sc_menu_img_1_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_1_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_1_img_data
})

sc_menu_img_1.set_src(sc_menu_img_1_img)
sc_menu_img_1.set_pivot(0,0)
sc_menu_img_1.set_angle(0)
# create style style_sc_menu_img_1_main_main_default
style_sc_menu_img_1_main_main_default = lv.style_t()
style_sc_menu_img_1_main_main_default.init()
style_sc_menu_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_1_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_1_main_main_default.set_img_opa(255)

# add style for sc_menu_img_1
sc_menu_img_1.add_style(style_sc_menu_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_2 = lv.img(sc_menu)
sc_menu_img_2.set_pos(int(46),int(141))
sc_menu_img_2.set_size(81,80)
sc_menu_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1395040802.png','rb') as f:
        sc_menu_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1395040802.png')
    sys.exit()

sc_menu_img_2_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_2_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_2_img_data
})

sc_menu_img_2.set_src(sc_menu_img_2_img)
sc_menu_img_2.set_pivot(0,0)
sc_menu_img_2.set_angle(0)
# create style style_sc_menu_img_2_main_main_default
style_sc_menu_img_2_main_main_default = lv.style_t()
style_sc_menu_img_2_main_main_default.init()
style_sc_menu_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_2_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_2_main_main_default.set_img_opa(255)

# add style for sc_menu_img_2
sc_menu_img_2.add_style(style_sc_menu_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_3 = lv.img(sc_menu)
sc_menu_img_3.set_pos(int(46),int(276))
sc_menu_img_3.set_size(81,80)
sc_menu_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1535589412.png','rb') as f:
        sc_menu_img_3_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1535589412.png')
    sys.exit()

sc_menu_img_3_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_3_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_3_img_data
})

sc_menu_img_3.set_src(sc_menu_img_3_img)
sc_menu_img_3.set_pivot(0,0)
sc_menu_img_3.set_angle(0)
# create style style_sc_menu_img_3_main_main_default
style_sc_menu_img_3_main_main_default = lv.style_t()
style_sc_menu_img_3_main_main_default.init()
style_sc_menu_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_3_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_3_main_main_default.set_img_opa(255)

# add style for sc_menu_img_3
sc_menu_img_3.add_style(style_sc_menu_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_4 = lv.img(sc_menu)
sc_menu_img_4.set_pos(int(46),int(415))
sc_menu_img_4.set_size(81,80)
sc_menu_img_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1462045911.png','rb') as f:
        sc_menu_img_4_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1462045911.png')
    sys.exit()

sc_menu_img_4_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_4_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_4_img_data
})

sc_menu_img_4.set_src(sc_menu_img_4_img)
sc_menu_img_4.set_pivot(0,0)
sc_menu_img_4.set_angle(0)
# create style style_sc_menu_img_4_main_main_default
style_sc_menu_img_4_main_main_default = lv.style_t()
style_sc_menu_img_4_main_main_default.init()
style_sc_menu_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_4_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_4_main_main_default.set_img_opa(255)

# add style for sc_menu_img_4
sc_menu_img_4.add_style(style_sc_menu_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_5 = lv.img(sc_menu)
sc_menu_img_5.set_pos(int(55),int(563))
sc_menu_img_5.set_size(81,80)
sc_menu_img_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-963265761.png','rb') as f:
        sc_menu_img_5_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-963265761.png')
    sys.exit()

sc_menu_img_5_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_5_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_5_img_data
})

sc_menu_img_5.set_src(sc_menu_img_5_img)
sc_menu_img_5.set_pivot(0,0)
sc_menu_img_5.set_angle(0)
# create style style_sc_menu_img_5_main_main_default
style_sc_menu_img_5_main_main_default = lv.style_t()
style_sc_menu_img_5_main_main_default.init()
style_sc_menu_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_5_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_5_main_main_default.set_img_opa(255)

# add style for sc_menu_img_5
sc_menu_img_5.add_style(style_sc_menu_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_6 = lv.img(sc_menu)
sc_menu_img_6.set_pos(int(46),int(694))
sc_menu_img_6.set_size(81,80)
sc_menu_img_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-755712042.png','rb') as f:
        sc_menu_img_6_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-755712042.png')
    sys.exit()

sc_menu_img_6_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_6_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_6_img_data
})

sc_menu_img_6.set_src(sc_menu_img_6_img)
sc_menu_img_6.set_pivot(0,0)
sc_menu_img_6.set_angle(0)
# create style style_sc_menu_img_6_main_main_default
style_sc_menu_img_6_main_main_default = lv.style_t()
style_sc_menu_img_6_main_main_default.init()
style_sc_menu_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_6_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_6_main_main_default.set_img_opa(255)

# add style for sc_menu_img_6
sc_menu_img_6.add_style(style_sc_menu_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_7 = lv.img(sc_menu)
sc_menu_img_7.set_pos(int(46),int(845))
sc_menu_img_7.set_size(81,80)
sc_menu_img_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-682168541.png','rb') as f:
        sc_menu_img_7_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-682168541.png')
    sys.exit()

sc_menu_img_7_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_7_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_7_img_data
})

sc_menu_img_7.set_src(sc_menu_img_7_img)
sc_menu_img_7.set_pivot(0,0)
sc_menu_img_7.set_angle(0)
# create style style_sc_menu_img_7_main_main_default
style_sc_menu_img_7_main_main_default = lv.style_t()
style_sc_menu_img_7_main_main_default.init()
style_sc_menu_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_7_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_7_main_main_default.set_img_opa(255)

# add style for sc_menu_img_7
sc_menu_img_7.add_style(style_sc_menu_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_8 = lv.img(sc_menu)
sc_menu_img_8.set_pos(int(36),int(990))
sc_menu_img_8.set_size(81,80)
sc_menu_img_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1103814371.png','rb') as f:
        sc_menu_img_8_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1103814371.png')
    sys.exit()

sc_menu_img_8_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_8_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_8_img_data
})

sc_menu_img_8.set_src(sc_menu_img_8_img)
sc_menu_img_8.set_pivot(0,0)
sc_menu_img_8.set_angle(0)
# create style style_sc_menu_img_8_main_main_default
style_sc_menu_img_8_main_main_default = lv.style_t()
style_sc_menu_img_8_main_main_default.init()
style_sc_menu_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_8_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_8_main_main_default.set_img_opa(255)

# add style for sc_menu_img_8
sc_menu_img_8.add_style(style_sc_menu_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_9 = lv.img(sc_menu)
sc_menu_img_9.set_pos(int(36),int(1146))
sc_menu_img_9.set_size(81,80)
sc_menu_img_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1254492192.png','rb') as f:
        sc_menu_img_9_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1254492192.png')
    sys.exit()

sc_menu_img_9_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_9_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_9_img_data
})

sc_menu_img_9.set_src(sc_menu_img_9_img)
sc_menu_img_9.set_pivot(0,0)
sc_menu_img_9.set_angle(0)
# create style style_sc_menu_img_9_main_main_default
style_sc_menu_img_9_main_main_default = lv.style_t()
style_sc_menu_img_9_main_main_default.init()
style_sc_menu_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_9_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_9_main_main_default.set_img_opa(255)

# add style for sc_menu_img_9
sc_menu_img_9.add_style(style_sc_menu_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_img_10 = lv.img(sc_menu)
sc_menu_img_10.set_pos(int(36),int(1273))
sc_menu_img_10.set_size(81,80)
sc_menu_img_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1113943582.png','rb') as f:
        sc_menu_img_10_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1113943582.png')
    sys.exit()

sc_menu_img_10_img = lv.img_dsc_t({
  'data_size': len(sc_menu_img_10_img_data),
  'header': {'always_zero': 0, 'w': 81, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sc_menu_img_10_img_data
})

sc_menu_img_10.set_src(sc_menu_img_10_img)
sc_menu_img_10.set_pivot(0,0)
sc_menu_img_10.set_angle(0)
# create style style_sc_menu_img_10_main_main_default
style_sc_menu_img_10_main_main_default = lv.style_t()
style_sc_menu_img_10_main_main_default.init()
style_sc_menu_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sc_menu_img_10_main_main_default.set_img_recolor_opa(0)
style_sc_menu_img_10_main_main_default.set_img_opa(255)

# add style for sc_menu_img_10
sc_menu_img_10.add_style(style_sc_menu_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_3 = lv.label(sc_menu)
sc_menu_label_3.set_pos(int(36),int(370))
sc_menu_label_3.set_size(100,32)
sc_menu_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_3.set_text("运动")
sc_menu_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_3_main_main_default
style_sc_menu_label_3_main_main_default = lv.style_t()
style_sc_menu_label_3_main_main_default.init()
style_sc_menu_label_3_main_main_default.set_radius(0)
style_sc_menu_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_3_main_main_default.set_bg_opa(0)
style_sc_menu_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_3_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_3_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_3_main_main_default.set_text_letter_space(2)
style_sc_menu_label_3_main_main_default.set_text_line_space(0)
style_sc_menu_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_3_main_main_default.set_pad_left(0)
style_sc_menu_label_3_main_main_default.set_pad_right(0)
style_sc_menu_label_3_main_main_default.set_pad_top(0)
style_sc_menu_label_3_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_3
sc_menu_label_3.add_style(style_sc_menu_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_4 = lv.label(sc_menu)
sc_menu_label_4.set_pos(int(36),int(510))
sc_menu_label_4.set_size(100,32)
sc_menu_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_4.set_text("闹钟")
sc_menu_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_4_main_main_default
style_sc_menu_label_4_main_main_default = lv.style_t()
style_sc_menu_label_4_main_main_default.init()
style_sc_menu_label_4_main_main_default.set_radius(0)
style_sc_menu_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_4_main_main_default.set_bg_opa(0)
style_sc_menu_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_4_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_4_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_4_main_main_default.set_text_letter_space(2)
style_sc_menu_label_4_main_main_default.set_text_line_space(0)
style_sc_menu_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_4_main_main_default.set_pad_left(0)
style_sc_menu_label_4_main_main_default.set_pad_right(0)
style_sc_menu_label_4_main_main_default.set_pad_top(0)
style_sc_menu_label_4_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_4
sc_menu_label_4.add_style(style_sc_menu_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_5 = lv.label(sc_menu)
sc_menu_label_5.set_pos(int(45),int(653))
sc_menu_label_5.set_size(100,32)
sc_menu_label_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_5.set_text("定时")
sc_menu_label_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_5_main_main_default
style_sc_menu_label_5_main_main_default = lv.style_t()
style_sc_menu_label_5_main_main_default.init()
style_sc_menu_label_5_main_main_default.set_radius(0)
style_sc_menu_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_5_main_main_default.set_bg_opa(0)
style_sc_menu_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_5_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_5_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_5_main_main_default.set_text_letter_space(2)
style_sc_menu_label_5_main_main_default.set_text_line_space(0)
style_sc_menu_label_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_5_main_main_default.set_pad_left(0)
style_sc_menu_label_5_main_main_default.set_pad_right(0)
style_sc_menu_label_5_main_main_default.set_pad_top(0)
style_sc_menu_label_5_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_5
sc_menu_label_5.add_style(style_sc_menu_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_6 = lv.label(sc_menu)
sc_menu_label_6.set_pos(int(45),int(798))
sc_menu_label_6.set_size(100,32)
sc_menu_label_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_6.set_text("秒表")
sc_menu_label_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_6_main_main_default
style_sc_menu_label_6_main_main_default = lv.style_t()
style_sc_menu_label_6_main_main_default.init()
style_sc_menu_label_6_main_main_default.set_radius(0)
style_sc_menu_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_6_main_main_default.set_bg_opa(0)
style_sc_menu_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_6_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_6_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_6_main_main_default.set_text_letter_space(2)
style_sc_menu_label_6_main_main_default.set_text_line_space(0)
style_sc_menu_label_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_6_main_main_default.set_pad_left(0)
style_sc_menu_label_6_main_main_default.set_pad_right(0)
style_sc_menu_label_6_main_main_default.set_pad_top(0)
style_sc_menu_label_6_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_6
sc_menu_label_6.add_style(style_sc_menu_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_7 = lv.label(sc_menu)
sc_menu_label_7.set_pos(int(36),int(943))
sc_menu_label_7.set_size(100,32)
sc_menu_label_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_7.set_text("手电筒")
sc_menu_label_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_7_main_main_default
style_sc_menu_label_7_main_main_default = lv.style_t()
style_sc_menu_label_7_main_main_default.init()
style_sc_menu_label_7_main_main_default.set_radius(0)
style_sc_menu_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_7_main_main_default.set_bg_opa(0)
style_sc_menu_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_7_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_7_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_7_main_main_default.set_text_letter_space(2)
style_sc_menu_label_7_main_main_default.set_text_line_space(0)
style_sc_menu_label_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_7_main_main_default.set_pad_left(0)
style_sc_menu_label_7_main_main_default.set_pad_right(0)
style_sc_menu_label_7_main_main_default.set_pad_top(0)
style_sc_menu_label_7_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_7
sc_menu_label_7.add_style(style_sc_menu_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_8 = lv.label(sc_menu)
sc_menu_label_8.set_pos(int(26),int(1090))
sc_menu_label_8.set_size(100,32)
sc_menu_label_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_8.set_text("天气")
sc_menu_label_8.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_8_main_main_default
style_sc_menu_label_8_main_main_default = lv.style_t()
style_sc_menu_label_8_main_main_default.init()
style_sc_menu_label_8_main_main_default.set_radius(0)
style_sc_menu_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_8_main_main_default.set_bg_opa(0)
style_sc_menu_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_8_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_8_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_8_main_main_default.set_text_letter_space(2)
style_sc_menu_label_8_main_main_default.set_text_line_space(0)
style_sc_menu_label_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_8_main_main_default.set_pad_left(0)
style_sc_menu_label_8_main_main_default.set_pad_right(0)
style_sc_menu_label_8_main_main_default.set_pad_top(0)
style_sc_menu_label_8_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_8
sc_menu_label_8.add_style(style_sc_menu_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_9 = lv.label(sc_menu)
sc_menu_label_9.set_pos(int(26),int(1241))
sc_menu_label_9.set_size(100,32)
sc_menu_label_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_9.set_text("消息")
sc_menu_label_9.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_9_main_main_default
style_sc_menu_label_9_main_main_default = lv.style_t()
style_sc_menu_label_9_main_main_default.init()
style_sc_menu_label_9_main_main_default.set_radius(0)
style_sc_menu_label_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_9_main_main_default.set_bg_opa(0)
style_sc_menu_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_9_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_9_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_9_main_main_default.set_text_letter_space(2)
style_sc_menu_label_9_main_main_default.set_text_line_space(0)
style_sc_menu_label_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_9_main_main_default.set_pad_left(0)
style_sc_menu_label_9_main_main_default.set_pad_right(0)
style_sc_menu_label_9_main_main_default.set_pad_top(0)
style_sc_menu_label_9_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_9
sc_menu_label_9.add_style(style_sc_menu_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_10 = lv.label(sc_menu)
sc_menu_label_10.set_pos(int(26),int(1362))
sc_menu_label_10.set_size(100,32)
sc_menu_label_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_10.set_text("设置")
sc_menu_label_10.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_10_main_main_default
style_sc_menu_label_10_main_main_default = lv.style_t()
style_sc_menu_label_10_main_main_default.init()
style_sc_menu_label_10_main_main_default.set_radius(0)
style_sc_menu_label_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_10_main_main_default.set_bg_opa(0)
style_sc_menu_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_10_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_10_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_10_main_main_default.set_text_letter_space(2)
style_sc_menu_label_10_main_main_default.set_text_line_space(0)
style_sc_menu_label_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_10_main_main_default.set_pad_left(0)
style_sc_menu_label_10_main_main_default.set_pad_right(0)
style_sc_menu_label_10_main_main_default.set_pad_top(0)
style_sc_menu_label_10_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_10
sc_menu_label_10.add_style(style_sc_menu_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_1 = lv.label(sc_menu)
sc_menu_label_1.set_pos(int(36),int(94))
sc_menu_label_1.set_size(100,32)
sc_menu_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_1.set_text("心率")
sc_menu_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_1_main_main_default
style_sc_menu_label_1_main_main_default = lv.style_t()
style_sc_menu_label_1_main_main_default.init()
style_sc_menu_label_1_main_main_default.set_radius(0)
style_sc_menu_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_1_main_main_default.set_bg_opa(0)
style_sc_menu_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_1_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_1_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_1_main_main_default.set_text_letter_space(2)
style_sc_menu_label_1_main_main_default.set_text_line_space(0)
style_sc_menu_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_1_main_main_default.set_pad_left(0)
style_sc_menu_label_1_main_main_default.set_pad_right(0)
style_sc_menu_label_1_main_main_default.set_pad_top(0)
style_sc_menu_label_1_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_1
sc_menu_label_1.add_style(style_sc_menu_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sc_menu_label_2 = lv.label(sc_menu)
sc_menu_label_2.set_pos(int(36),int(238))
sc_menu_label_2.set_size(100,32)
sc_menu_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sc_menu_label_2.set_text("血氧")
sc_menu_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_sc_menu_label_2_main_main_default
style_sc_menu_label_2_main_main_default = lv.style_t()
style_sc_menu_label_2_main_main_default.init()
style_sc_menu_label_2_main_main_default.set_radius(0)
style_sc_menu_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_sc_menu_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_sc_menu_label_2_main_main_default.set_bg_opa(0)
style_sc_menu_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_sc_menu_label_2_main_main_default.set_text_font(lv.font_dingliehuobanfont20241217_2_29)
except AttributeError:
    try:
        style_sc_menu_label_2_main_main_default.set_text_font(lv.font_montserrat_29)
    except AttributeError:
        style_sc_menu_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_sc_menu_label_2_main_main_default.set_text_letter_space(2)
style_sc_menu_label_2_main_main_default.set_text_line_space(0)
style_sc_menu_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sc_menu_label_2_main_main_default.set_pad_left(0)
style_sc_menu_label_2_main_main_default.set_pad_right(0)
style_sc_menu_label_2_main_main_default.set_pad_top(0)
style_sc_menu_label_2_main_main_default.set_pad_bottom(0)

# add style for sc_menu_label_2
sc_menu_label_2.add_style(style_sc_menu_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1 = lv.obj()
screen_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_1_main_main_default
style_screen_1_main_main_default = lv.style_t()
style_screen_1_main_main_default.init()
style_screen_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_screen_1_main_main_default.set_bg_opa(255)

# add style for screen_1
screen_1.add_style(style_screen_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_1 = lv.img(screen_1)
screen_1_img_1.set_pos(int(25),int(35))
screen_1_img_1.set_size(29,78)
screen_1_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp915399427.png','rb') as f:
        screen_1_img_1_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp915399427.png')
    sys.exit()

screen_1_img_1_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_1_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_1_img_data
})

screen_1_img_1.set_src(screen_1_img_1_img)
screen_1_img_1.set_pivot(0,0)
screen_1_img_1.set_angle(0)
# create style style_screen_1_img_1_main_main_default
style_screen_1_img_1_main_main_default = lv.style_t()
style_screen_1_img_1_main_main_default.init()
style_screen_1_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_1_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_1_main_main_default.set_img_opa(255)

# add style for screen_1_img_1
screen_1_img_1.add_style(style_screen_1_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_2 = lv.img(screen_1)
screen_1_img_2.set_pos(int(62),int(42))
screen_1_img_2.set_size(29,78)
screen_1_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1302358526.png','rb') as f:
        screen_1_img_2_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1302358526.png')
    sys.exit()

screen_1_img_2_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_2_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_2_img_data
})

screen_1_img_2.set_src(screen_1_img_2_img)
screen_1_img_2.set_pivot(0,0)
screen_1_img_2.set_angle(0)
# create style style_screen_1_img_2_main_main_default
style_screen_1_img_2_main_main_default = lv.style_t()
style_screen_1_img_2_main_main_default.init()
style_screen_1_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_2_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_2_main_main_default.set_img_opa(255)

# add style for screen_1_img_2
screen_1_img_2.add_style(style_screen_1_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_8 = lv.img(screen_1)
screen_1_img_8.set_pos(int(120),int(88))
screen_1_img_8.set_size(29,78)
screen_1_img_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1055948037.png','rb') as f:
        screen_1_img_8_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1055948037.png')
    sys.exit()

screen_1_img_8_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_8_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_8_img_data
})

screen_1_img_8.set_src(screen_1_img_8_img)
screen_1_img_8.set_pivot(0,0)
screen_1_img_8.set_angle(0)
# create style style_screen_1_img_8_main_main_default
style_screen_1_img_8_main_main_default = lv.style_t()
style_screen_1_img_8_main_main_default.init()
style_screen_1_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_8_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_8_main_main_default.set_img_opa(255)

# add style for screen_1_img_8
screen_1_img_8.add_style(style_screen_1_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_7 = lv.img(screen_1)
screen_1_img_7.set_pos(int(62),int(203))
screen_1_img_7.set_size(29,78)
screen_1_img_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-880712696.png','rb') as f:
        screen_1_img_7_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-880712696.png')
    sys.exit()

screen_1_img_7_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_7_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_7_img_data
})

screen_1_img_7.set_src(screen_1_img_7_img)
screen_1_img_7.set_pivot(0,0)
screen_1_img_7.set_angle(0)
# create style style_screen_1_img_7_main_main_default
style_screen_1_img_7_main_main_default = lv.style_t()
style_screen_1_img_7_main_main_default.init()
style_screen_1_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_7_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_7_main_main_default.set_img_opa(255)

# add style for screen_1_img_7
screen_1_img_7.add_style(style_screen_1_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_6 = lv.img(screen_1)
screen_1_img_6.set_pos(int(120),int(175))
screen_1_img_6.set_size(29,78)
screen_1_img_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1021261306.png','rb') as f:
        screen_1_img_6_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1021261306.png')
    sys.exit()

screen_1_img_6_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_6_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_6_img_data
})

screen_1_img_6.set_src(screen_1_img_6_img)
screen_1_img_6.set_pivot(0,0)
screen_1_img_6.set_angle(0)
# create style style_screen_1_img_6_main_main_default
style_screen_1_img_6_main_main_default = lv.style_t()
style_screen_1_img_6_main_main_default.init()
style_screen_1_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_6_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_6_main_main_default.set_img_opa(255)

# add style for screen_1_img_6
screen_1_img_6.add_style(style_screen_1_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_5 = lv.img(screen_1)
screen_1_img_5.set_pos(int(91),int(166))
screen_1_img_5.set_size(29,78)
screen_1_img_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png','rb') as f:
        screen_1_img_5_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1196496647.png')
    sys.exit()

screen_1_img_5_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_5_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_5_img_data
})

screen_1_img_5.set_src(screen_1_img_5_img)
screen_1_img_5.set_pivot(0,0)
screen_1_img_5.set_angle(0)
# create style style_screen_1_img_5_main_main_default
style_screen_1_img_5_main_main_default = lv.style_t()
style_screen_1_img_5_main_main_default.init()
style_screen_1_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_5_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_5_main_main_default.set_img_opa(255)

# add style for screen_1_img_5
screen_1_img_5.add_style(style_screen_1_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_4 = lv.img(screen_1)
screen_1_img_4.set_pos(int(37),int(166))
screen_1_img_4.set_size(29,78)
screen_1_img_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1337045257.png','rb') as f:
        screen_1_img_4_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1337045257.png')
    sys.exit()

screen_1_img_4_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_4_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_4_img_data
})

screen_1_img_4.set_src(screen_1_img_4_img)
screen_1_img_4.set_pivot(0,0)
screen_1_img_4.set_angle(0)
# create style style_screen_1_img_4_main_main_default
style_screen_1_img_4_main_main_default = lv.style_t()
style_screen_1_img_4_main_main_default.init()
style_screen_1_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_4_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_4_main_main_default.set_img_opa(255)

# add style for screen_1_img_4
screen_1_img_4.add_style(style_screen_1_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_3 = lv.img(screen_1)
screen_1_img_3.set_pos(int(98),int(23))
screen_1_img_3.set_size(29,78)
screen_1_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-740164086.png','rb') as f:
        screen_1_img_3_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-740164086.png')
    sys.exit()

screen_1_img_3_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_3_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_3_img_data
})

screen_1_img_3.set_src(screen_1_img_3_img)
screen_1_img_3.set_pivot(0,0)
screen_1_img_3.set_angle(0)
# create style style_screen_1_img_3_main_main_default
style_screen_1_img_3_main_main_default = lv.style_t()
style_screen_1_img_3_main_main_default.init()
style_screen_1_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_3_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_3_main_main_default.set_img_opa(255)

# add style for screen_1_img_3
screen_1_img_3.add_style(style_screen_1_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_9 = lv.img(screen_1)
screen_1_img_9.set_pos(int(135),int(72))
screen_1_img_9.set_size(29,78)
screen_1_img_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1161809916.png','rb') as f:
        screen_1_img_9_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp-1161809916.png')
    sys.exit()

screen_1_img_9_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_9_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_9_img_data
})

screen_1_img_9.set_src(screen_1_img_9_img)
screen_1_img_9.set_pivot(0,0)
screen_1_img_9.set_angle(0)
# create style style_screen_1_img_9_main_main_default
style_screen_1_img_9_main_main_default = lv.style_t()
style_screen_1_img_9_main_main_default.init()
style_screen_1_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_9_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_9_main_main_default.set_img_opa(255)

# add style for screen_1_img_9
screen_1_img_9.add_style(style_screen_1_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_img_10 = lv.img(screen_1)
screen_1_img_10.set_pos(int(8),int(166))
screen_1_img_10.set_size(29,78)
screen_1_img_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1477593867.png','rb') as f:
        screen_1_img_10_img_data = f.read()
except:
    print('Could not open D:\\code\\watch\\Twatch-guider\\Twatch\\generated\\mPythonImages\\mp1477593867.png')
    sys.exit()

screen_1_img_10_img = lv.img_dsc_t({
  'data_size': len(screen_1_img_10_img_data),
  'header': {'always_zero': 0, 'w': 29, 'h': 78, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_1_img_10_img_data
})

screen_1_img_10.set_src(screen_1_img_10_img)
screen_1_img_10.set_pivot(0,0)
screen_1_img_10.set_angle(0)
# create style style_screen_1_img_10_main_main_default
style_screen_1_img_10_main_main_default = lv.style_t()
style_screen_1_img_10_main_main_default.init()
style_screen_1_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_1_img_10_main_main_default.set_img_recolor_opa(0)
style_screen_1_img_10_main_main_default.set_img_opa(255)

# add style for screen_1_img_10
screen_1_img_10.add_style(style_screen_1_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)




# content from custom.py

# Load the default screen
lv.scr_load(sc_main)

while SDL.check():
    time.sleep_ms(5)
