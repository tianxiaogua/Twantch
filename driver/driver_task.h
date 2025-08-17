#ifndef _DRIVER_TASK_H
#define _DRIVER_TASK_H

#include "main.h"


enum CYCLE {
  INTER_1MS = 1,
  INTER_10MS,
  INTER_50MS,
  INTER_100MS,
  INTER_300MS,
  INTER_500MS ,
  INTER_1000MS,
  INTER_2000MS,
};


typedef void (*task_callback)(void);

// 用于注册回调函数，在周期运行的函数中执行
void register_interupt(task_callback fun, uint32_t cycle);

// 用于在周期定时器中执行，用于计时判断 !!需要在10毫秒定时器中断函数中执行
void interrupt_task(void);

// 用于在while中执行判断
void run_task(void);


// 使能定时器中断
void init_timer(void);

void run_single_time_task(void); // 单次定时执行任务
void updata_time_task_time(void); // 更新定时器 10毫秒周期执行
int32_t register_run_single_time_task(task_callback fun, uint32_t seconds); // 单次定时执行任务注册函数
void init_timer_task(void);
#endif


