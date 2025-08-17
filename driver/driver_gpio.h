#ifndef driver_gpio_h
#define driver_gpio_h
#include "main.h"
#include "driver_tool.h"

#define KEY_UP_GET 0
#define LEY_DOWN_GET 1


void init_gpio(void);
void init_key_gpio(void);

int32_t get_key1(void);
int32_t get_key2(void);
int32_t get_key3(void);

int32_t mcu_power_set_ctol(uint8_t user_ctl);
int32_t muc_power_set_shutdown(void);
int32_t muc_power_set_starting(uint8_t user_ctl);

void set_gpio(int32 in);
#endif

