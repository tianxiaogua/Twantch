# [7.26] FATFS文件系统 STM32 配置

[CubeMX配置STM32实现FatFS文件系统（五）_stm32cubemx文件系统-CSDN博客](https://blog.csdn.net/qq_30623327/article/details/122470223)

减少fatfs内存占用

[stm32 FATFS文件系统如何减少Flash和RAM占用，FATFS移除中文文件名，FATFS移除动态内存_fatfs ram-CSDN博客](https://blog.csdn.net/Mark_md/article/details/108386706)

stm32驱动 fatfs

[STM32CubeMX之FATFS+SPI驱动W25QXX_nss signal type-CSDN博客](https://blog.csdn.net/qq_42900996/article/details/117113717)



[STM32Cube MX USB虚拟U盘+FATFS+W25Q128_stm32cube 虚拟u盘 w25q128-CSDN博客](https://blog.csdn.net/m0_52169267/article/details/121707346)

[STM32CubeMX教程26 FatFs 文件系统 - W25Q128读写_w25q128 fatfs-CSDN博客](https://blog.csdn.net/lc_guo/article/details/135780639)



stm32驱动全系列w25QXX

[STM32CubeMX+w25qxx - 曾经梦想少年 - 博客园](https://www.cnblogs.com/kdsj/p/15371137.html)

[STM32系列(HAL库)——F103C8T6通过SPI方式读写W25Q64—(Flash存储模块)_stm32f1 w25q215 hal-CSDN博客](https://blog.csdn.net/lwb450921/article/details/124695575)





# [7.19] Ymodem协议，串口传文件flash保存

[(72 封私信 / 81 条消息) 使用Xshell串口通过Ymodem协议发送文件 - 知乎](https://zhuanlan.zhihu.com/p/654782539)



# [7.26] LVGL 图片问题

LVGL转换图片为BIN文件储存在flash中启动：

FATFS：

```c
lv_img_set_src(ui->screen_img_1,"0:/_1_111x174.bin");

lv_obj_t* obj = lv_img_create(ui->screen_1);
// lv_img_set_src(obj, "0:/img_main.bin");
lv_img_set_src(obj, "0:/star.bin");
lv_obj_center(obj);
```

[STM32F103RCT6 移植LVGL与空间不足解决_lvgl内存不足-CSDN博客](https://blog.csdn.net/m0_58418074/article/details/143819363)

## 1、图片转为bin文件

[Image Converter — LVGL](https://lvgl.io/tools/imageconverter)

2、bin文件烧录到flash

3、使用FatFS对文件进行管理



# [6.12] LVGL 字体文件、中文编译解决

[LVGL-字体库 - QuecPython](https://developer.quectel.com/doc/quecpython/Application_guide/zh/multi-media/lvgl/lvgl_fontlib.html)

[LVGL实现字库的下载和使用_lvgl字库外置-CSDN博客](https://blog.csdn.net/jcf5832/article/details/140103042)

[lvgl 笔记(3)-中文字库的制作和使用(windows模拟和esp32) - 汉塘阿德 - 博客园](https://www.cnblogs.com/hwd00001/p/17393135.html)

使用LvglFontTool 工具

字体烧录使用Ymodem

中文编译和显示存在的问题：

[Keil5编译UTF8码中文字符串报错_utf-8 字符数组中加入汉字 编译错误-CSDN博客](https://blog.csdn.net/yiluang/article/details/106382167)

字库

[STM32外部Flash-----unicode字库制作基于LvglFontTool(AuroraFOC) - 知乎](https://zhuanlan.zhihu.com/p/680461788)

[LvglFontTool字体工具更新V0.4版本 - LittlevGL - 里飞网 - Powered by Discuz!](http://dz.lfly.xyz/forum.php?mod=viewthread&tid=24&extra=page%3D1)

[幼圆字体免费下载和在线预览-字体天下](https://www.fonts.net.cn/fonts-zh/tag-youyuan-1.html)

[STM32+LVGL+SD外部存储字库_lvgl外部字库-CSDN博客](https://blog.csdn.net/qq_53923927/article/details/146226524)

# [6.10] LVGL滚动菜单设计

设计滚动菜单

[lvgl之图标滚动简化版_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1fhV7zwEN9/?spm_id_from=333.337.search-card.all.click&vd_source=c13bbf05d4b570439590d88626eb3093)

[使用GUI Guider工具开发嵌入式GUI应用（6）-切换多screen换场景_使用guiguider时卡在创建页面-CSDN博客](https://blog.csdn.net/suyong_yq/article/details/132371746?spm=1001.2014.3001.5502)



# [6.2] LVGL多界面切换至ram不足问题 

在 STM32 中使用 LVGL 切换界面时出现内存不足报错（`Error: L6406E`），通常是由于 RAM 或 Flash 空间不足内存管理不当或代码优化不足导致的。以下是综合解决方案：

### 1. **检查内存占用并优化配置**

#### （1）调整 LVGL 内存池大小

- 在 lv_conf.h   中减少   LV_MEM_SIZE

  （默认可能为 32KB），例如改为 16KB：

  ```
  #define LV_MEM_SIZE (16 * 1024)  // 降低内存池大小
  ```

  若使用外部 RAM（如 PSRAM），启用外部内存支持：

  ```
  #define LV_USE_PSRAM 1  // 启用外部 RAM
  ```

#### （2）优化显示缓冲区

- 使用单缓冲区或非全尺寸双缓冲

  （如屏幕 1/4 大小），减少 RAM 占用：

  ```
  static lv_color_t buf[320 * 40];  // 示例：320x240 屏幕的 40 行缓冲区
  ```

#### （3）关闭未使用的 LVGL 功能

在 `lv_conf.h` 中禁用非必要模块：

```
#define LV_USE_ANIMATION 0     // 禁用动画
#define LV_USE_THEME_DEFAULT 0 // 禁用默认主题
#define LV_USE_LOG 0           // 禁用日志
```

### 2. **优化界面切换逻辑**

#### （1）避免重复创建和删除界面

- **预创建界面**：启动时创建所有界面，切换时通过 `lv_obj_add/clear_flag` 隐藏/显示，而非动态创建删除。
- 复用控件：如列表项等控件尽量复用，减少内存碎片

#### （2）正确释放旧界面

使用 `lv_scr_load_anim` 时，设置 `auto_del=true` 自动释放旧界面：

```
lv_scr_load_anim(new_screen, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, true);
```

若需手动释放，调用 `lv_obj_clean(old_screen)` 或 `lv_obj_delete(old_screen)`

#### （3）使用内存池管理

避免频繁动态内存分配，改用静态内存池管理：

```
// 示例：静态分配界面对象
static lv_obj_t *screen1, *screen2;
void create_screens() {
    screen1 = lv_obj_create(NULL);
    screen2 = lv_obj_create(NULL);
}
```

### 3. **硬件与编译器优化**

#### （1）扩展外部 RAM

- 若 STM32 支持 FSMC/EXMC（如 STM32F4），连接外部 SRAM（如 XM8A51216），将大缓冲区分配到外部内存：

  ```
  __attribute__((at(0x68000000))) lv_color_t ext_buf[1024 * 1024];  // 外部 SRAM
  ```

#### （2）调整堆栈大小

- 修改链接脚本（.ld或.sct文件），增加堆（Heap）和栈（Stack）空间：

  ```
  PlaintextHeap_Size EQU 0x2000;  // 改为 8KB
  Stack_Size EQU 0x1000;  // 改为 4KB
  ```

#### （3）启用编译器优化

- 在 Keil/IAR 中设置优化等级为-O2或-Os（优化代码大小），减少 Flash 占用。

### 4. **调试与验证**

1. 分析 `.map` 文件

   - 定位 app_menu.o(i.scroll_anim_ready_cb) 的具体内存占用，检查是否有大数组或未释放的变量。

2. 监控实时内存调用

   ```
   lv_mem_monitor()
   ```

   打印内存使用情况和碎片率：

   ```
   Clv_mem_monitor_t mem_mon;
   lv_mem_monitor(&mem_mon);
   printf("Used: %d, Frag: %d%%\n", mem_mon.total_used, mem_mon.frag_pct);
   ```

3. 简化测试工程逐步添加功能模块，观察内存变化，隔离问题源。

### 5. **替代方案：避免动态内存**

- 使用 LVGL 内部 Timer 替代线程

  将界面刷新逻辑放到 LVGL Timer 回调中，避免多线程竞争和内存泄漏：

  ```
  lv_timer_create(refresh_cb, 100, NULL);  // 100ms 周期刷新
  ```





# [6.29] LVGL移植学习

[欢迎阅读百问网LVGL中文开发手册！ — 百问网LVGL中文教程文档 文档](https://lvgl.100ask.net/8.1/index.html)

https://github.com/lvgl/sim

[在STM32F4上移植LVGL8.2_stm32f4 lvgl-CSDN博客](https://blog.csdn.net/qq_39649731/article/details/127534934)

[批处理：把某个文件夹下的所有子文件夹内的文件拷贝到一个文件夹下_将多级的文件夹下的文件复制到一个文件夹下的bat-CSDN博客](https://blog.csdn.net/niuba123456/article/details/101528871)

[基于HAL库的STM32的串口DMA发送数据（解决只发送一次数据）及DMA+空闲中断接受数据_stm32串口dma只能发送一次-CSDN博客](https://blog.csdn.net/PHILICS7/article/details/127197248)

[Littlevgl键盘和编码器驱动_littlevgl 键盘-CSDN博客](https://blog.csdn.net/qq_41281869/article/details/108262870)

[STM32移植LVGL8.3 （保姆级图文教程）_lvgl移植-CSDN博客](https://blog.csdn.net/weixin_56167571/article/details/147879170)

[Guide - 滚动容器 - 《FairyGUI 教程》 - 书栈网 · BookStack](https://www.bookstack.cn/read/fairygui/4d4ab56f02e168aa.md)

vmware挂在共享文件夹

[主机与VMware虚拟机共享文件夹：解决虚拟机找不到共享文件夹问题 - 知乎](https://zhuanlan.zhihu.com/p/650638983)

```shell
sudo mount -t fuse.vmhgfs-fuse .host:/share/ /mnt/hgfs -o allow_other
```

guider进行仿真的时候，需要jre8

[【Java8 环境安装】Java1.8&JDK环境安装jdk-8u361-windows-x64-CSDN博客](https://blog.csdn.net/MidNight_Anthony/article/details/129783433)

guider移植到模拟器：

[【快速入门 LVGL】-- 5、Gui Guider界面移植到STM32工程_gui guider stm32-CSDN博客](https://blog.csdn.net/qq_49053936/article/details/137834282)





# LVGL基础移植

其中GUI/LVGL，添加lvgl->src下的所有C文件。这个比较考验耐心，很多文件。
GUI/Porting，添加lvgl->porting文件夹里面的C文件。
GUI/APP，添加lv_config.h和lvgl.h头文件，添加完效果如下：

注意：

```c
/* 1：启用屏幕透明度。
 * 这对于OSD菜单、视频播放器和重叠的GUI有用。
 * 需要32位深度的颜色，并且屏幕的' bg_opa '应该设置为非LV_OPA_COVER值 */
#define LV_COLOR_SCREEN_TRANSP 0
```

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/6d6db6f10a76c3c8dcbdec3e2234c5bb.png)

![image.png](https://ucc.alicdn.com/pic/developer-ecology/4lq55i3m4rlok_cb6c4be1ed374394ab531468843ed6ec.png?x-oss-process=image%2Fresize%2Cw_1400%2Cm_lfit%2Fformat%2Cwebp)

.在lv_conf.h中开启如下两个宏，运行程序，没有错误的话，就会在屏幕下方，看到内存占用率和帧率。这样就不需要用例程来确定lvgl是否可以正常显示了。

SPI颜色数据传输问题：

```
/*Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface (e.g. SPI)*/
#define LV_COLOR_16_SWAP 1
```

[LVGL——STM32F4移植lvgl8 - 我是，一株蒜。 - 博客园](https://www.cnblogs.com/LiuYong2021/p/16791861.html)



****

****

****



![](./doc/photo/实物.jpg)

**注**：程序运行在基于watchT V3的版本上。相比较之前的V2版本的PCB，V3版本对所有的期间都进行了重新布局，但是所有的引脚对应编号都没有改变。由于之前发现充电时，撒热电阻 发热严重，在V3版本上面把散热电阻移动到PCB边缘，远离屏幕。同时增加了PCB底板。底板上预留了一个心率血氧传感器，可以透过PCB测量人体心率和血液氧气浓度。需要一路IIC和一个输入IO，提供3.3V电源。同时为了方便连接，直接在watchT的PCB上面预留了这五个导线接口，设计直接使用导线进行焊接。另外还增加了光照传感器，改变了电池供电结构。



**注**：硬件链接 [田小呱/wwatch-hardware](https://gitee.com/tianxiaohuahua/wwatch-hardware)  !! 



#  V9.1.1

### 20.9.21 更新PCB

重新设计完成了PCB



# V10.1

#### 20.9.29

刚刚完成了PCB的调试和焊接，先前的程序已经 可以完善的运行在这个版本的PCB上面。最新的发现是这个PCB版本还是不能尽人意，一开始使用的LM27313的芯片，并不能起到升压作用。因为在上一个版本的PCB就存在了设计缺陷。电池电压没有直接得到升压的作用，而是直接绕过了升压芯片给了降压芯片为系统供电。这个版本的PCB开关只是截断了所有的器件和电池的连接。因此开关断开以后就不能充电了，也是一个严重的缺陷。下一个版本的PCB还会改进这些缺陷。



开始对光照强度传感器进行驱动。



# 适合的PCB版本更新到V4 20.10.13

# V10.2

目前PCB的各个功能模块以切正常，可以最后的代码编辑了。

更改之前的充电检测，把原来的高电平检测转换为低电平检测。

10月22日早上成功讲V4 PCB 上面的 所有硬件驱动成功！！

下一步准备把温湿度显示到主界面上，另外需要进一步改进和完善陀螺仪部分的驱动，需要增加计步算法。

10月22日晚上 已经完成了温湿度的显示以及对步数算法的实现，以及把步数显示到主界面的显示屏幕上面。完成了显示屏幕的最终显示。

明天先解决闹钟部分的Bug问题，之后解决存储部分，把数据储存到FLASH内。包括七个闹钟，七天的步数以及设置部分的数据！

还需要抬手晃动唤醒休眠。

之后还需要重新对PCB部分进行刷新设计。最好找到合适的端子，最好还可以集成一个通讯类的传感器。





# 2021年3月31日

# 更新WOKE_OUT_WATCH版本

# 更新了PCB

# 更新KEIL工程WOKE_OUT_WATCH-V1.0

PCB1对应着V1.0版本工程

在V1.0工程下更细了原有的PCB的驱动

使用SI7020芯片替代SHT30芯片作为温湿度传感器芯片并实现了驱动的更换

增加了血氧传感器及其驱动程序

# WOKE_OUT_WATCH-V1.1

替换了正点原子的驱动程序，帮助完成了初始化的驱动

更新后的初始化程序的代码不会应为角度的变换造成之后测量角度的偏差

# WOKE_OUT_WATCH-V1.2

修改了界面，更正了血氧传感器的UI

# WOKE_OUT_WATCH-V1.3

更正了电池电量检测部分。电池ADC采样后检测得到的电池电量更准确



# 22年1月29 V2.1.1

!!!此程序版本为V2.1.1，对应的硬件版本为：V2.1；
在硬件V2.1的主要配置：
    单片机使用了STM32F401CCU6 
        ARM 32-bit Cortex-M4 with FPU
        80 MHz maximum frequency
        256k flash
        64k ram
        UFQFPN 封装48pin
    主要晶振：8Mhz
    带有32.768Khz外部低速晶振
    1.14寸 TFT液晶屏幕
    使用间距为1.0mm的sh接口作为Debug接口
    配置Typec接口提供大约500ma充电电流
    电池大小为300maH
    配置三个功能按键，同时引出复位按键
    可以调音无源蜂鸣器
    

在本版本中实现了功能：

1、血样传感器心率检测，由于在PCB上改进了工艺，将血样传感器放置在手表下面进一步缩小了手表的体积，在正常同步心率状态下会在屏幕上显示心率和血样，在同步心率时候会伴随右侧灯光闪烁，闪烁频率和心跳频率一致。但传感器精度很难达到，需要多次测量。在推出学氧传感器界面后由于未关闭学氧传感器，底部灯光会一直闪烁；

2、闹钟，正常可以设置闹钟，设置闹钟时候必须在满足时间完全符合才会响起，也就是时钟数字完全对应的一分钟，使用中间按键退出闹钟；

3、游戏；继承了之前的游戏，使用陀螺仪消除像素点；

4、照明；使用所有灯光进行照明；

5、设置；在设置中可以对时间和日期声音进行设置；

后台功能实现了：

1、计步器正常记录步数，正常显示；

2、时间日期秒钟数字正常显示无延迟；

3、显示日期，显示星期；

4、显示温湿度，温湿度更新频率在一秒钟左右；

5、电池电量显示，电池在充电状态下可以正常检测到正在充电并显示充电动画；

6、在正常状态下可以实现没有操作10秒钟的时候熄灭屏幕，但是只是通过关闭背光的方式来熄灭屏幕，没有实现后台降低功耗，因此正常仅能在正常待机的50ma电流状态下减少10ma左右电流；

7、蜂鸣器可以在按键按下时候正常发出声音，可以在设置中对俺家声音进行设置。

**硬件改动**

硬件改动不大，所有硬件正常驱动。

需要的改进：

1、电源管理：将电源反馈，屏幕，血氧传感器，蜂鸣器，灯光LED，设置成一个电源开关控制，将陀螺仪单独设置电源控制。更换电源芯片。

2、简化LCD背光控制，去除三极管电路；

3、简化单片机的晶振，去掉外部晶振；

4、去掉BOOT1电阻。

