#include "driver_task.h"
#include <stdio.h>
#include <stdlib.h>
#include "tim.h"
#include "driver_tool.h"

#define TIME_TASK_NUM       10

typedef enum {
  TIME_TASK_OK = 0,
  TIME_TASK_RUN,
  TIME_TASK_DELAY,
} TIME_TASK_STATUS;

typedef struct {
  task_callback fun;
  uint32_t delay_seconds;
  uint32_t run_seconds;
  TIME_TASK_STATUS task_status;
} TIME_TASK;


typedef struct STRUCT_CABCK_FUN{
  task_callback fun;
  uint32_t cycle;
  struct STRUCT_CABCK_FUN *next;
} STRUCT_CABCK_FUN;

typedef struct {
  uint32_t T10ms;
  uint32_t T50ms;
  uint32_t T100ms;
  uint32_t T300ms;
  uint32_t T500ms;
  uint32_t T1000ms;
} RUN_FLASG;

static TIME_TASK g_time_task[TIME_TASK_NUM] = {0};

STRUCT_CABCK_FUN* head_cycle_10ms = NULL;
STRUCT_CABCK_FUN* head_cycle_50ms = NULL;
STRUCT_CABCK_FUN* head_cycle_100ms = NULL;
STRUCT_CABCK_FUN* head_cycle_300ms = NULL;
STRUCT_CABCK_FUN* head_cycle_500ms = NULL;
STRUCT_CABCK_FUN* head_cycle_1000ms = NULL;
uint32_t tim_cnt = 0;
uint32_t tim_cnt_300ms = 0;
RUN_FLASG g_run_flag;

// 创建新节点
static STRUCT_CABCK_FUN* create_node(task_callback fun, uint32_t cycle) {
  STRUCT_CABCK_FUN* new_node = (STRUCT_CABCK_FUN*)malloc(sizeof(STRUCT_CABCK_FUN));
  if(!new_node) {
      GUA_LOGI("内存分配失败!\n");
  }
  new_node->fun = fun;
  new_node->cycle = cycle;
  new_node->next = NULL;
  return new_node;
}


// 尾部插入
static void insertAtEnd(STRUCT_CABCK_FUN** head, task_callback fun, uint32_t cycle)
{

  STRUCT_CABCK_FUN* new_node = create_node(fun, cycle);

  if(*head == NULL) {
      *head = new_node;
      GUA_LOGI("head = NULL\r\n");
      return;
  }
  GUA_LOGI("head != NULL\r\n");
  STRUCT_CABCK_FUN* current = *head;
  while(current->next != NULL) {
      current = current->next;
      GUA_LOGI("head move\r\n");
  }
  current->next = new_node;
  GUA_LOGI("head end \r\n");
}


// 执行周期函数
static void run_periodic_fun(STRUCT_CABCK_FUN** head, uint32_t cycle)
{
  STRUCT_CABCK_FUN* current = *head;
	STRUCT_CABCK_FUN* next;

  while(current != NULL) {
    if (cycle == current->cycle) {
      current->fun();
      current = next;
    } else {
      return;
    }
  }
}


void register_interupt(task_callback fun, uint32_t cycle)
{
	switch(cycle) {
		case INTER_10MS: insertAtEnd(&head_cycle_10ms, fun, cycle); break;
		case INTER_50MS: insertAtEnd(&head_cycle_50ms, fun, cycle); break;
		case INTER_100MS: insertAtEnd(&head_cycle_100ms, fun, cycle); break;
    case INTER_300MS: insertAtEnd(&head_cycle_300ms, fun, cycle); break;
		case INTER_500MS: insertAtEnd(&head_cycle_500ms, fun, cycle); break;
		case INTER_1000MS: insertAtEnd(&head_cycle_1000ms, fun, cycle); break;
    default: GUA_LOGI("input error!\r\n");
	}
}


// 10毫秒定时器中断函数
void interrupt_task(void)
{
  tim_cnt++;
  tim_cnt_300ms++;

  g_run_flag.T10ms = 1;

  if(tim_cnt_300ms == 30) {
    tim_cnt_300ms = 0;
    g_run_flag.T300ms = 1;
  }
  // GUA_LOGI("T%d\r\n", tim_cnt);
  if ((tim_cnt % 5) ==  0) { // 50ms周期
    // GUA_LOGI("5! %d\r\n", tim_cnt);
    g_run_flag.T50ms = 1;

		if ((tim_cnt % 10) == 0) { // 100ms周期
			// GUA_LOGI("10! %d\r\n", tim_cnt);
			g_run_flag.T100ms = 1;

			if ((tim_cnt % 50) == 0) { // 500ms周期
				g_run_flag.T500ms = 1;
        // GUA_LOGI("50! %d\r\n", tim_cnt);
				if ((tim_cnt % 100) == 0) { // 1000ms周期
					// GUA_LOGI("100! %d\r\n", tim_cnt);
					g_run_flag.T1000ms = 1;
				}
			}
		}
  }
	if (tim_cnt > 100) {
		tim_cnt = 0;
    // GUA_LOGI("100!\r\n");
	}
}

void run_task(void)
{
  if (g_run_flag.T10ms == 1) {
    g_run_flag.T10ms = 0;
    run_periodic_fun(&head_cycle_10ms, INTER_10MS);
  }

  if (g_run_flag.T50ms) {
    g_run_flag.T50ms = 0;
    run_periodic_fun(&head_cycle_50ms, INTER_50MS);
  }
  if (g_run_flag.T100ms) {
    g_run_flag.T100ms = 0;
    run_periodic_fun(&head_cycle_100ms, INTER_100MS);
  }

  if (g_run_flag.T300ms) {
    g_run_flag.T300ms = 0;
    run_periodic_fun(&head_cycle_300ms, INTER_300MS);
  }

  if (g_run_flag.T500ms) {
    g_run_flag.T500ms = 0;
    run_periodic_fun(&head_cycle_500ms, INTER_500MS);
  }
  if (g_run_flag.T1000ms) {
    g_run_flag.T1000ms = 0;
    // GUA_LOGI("g_run_flag.T1000ms = 0;\r\n");
    run_periodic_fun(&head_cycle_1000ms, INTER_1000MS);
  }

}

// 使能定时器中断
void init_timer(void)
{
 HAL_TIM_Base_Start_IT(&htim3); // 1ms
}


// 在主函数中运行
void run_single_time_task(void) // 单次定时执行任务
{
  uint32_t i = 0;

  for (i=0; i<TIME_TASK_NUM; i++) {
    if (g_time_task[i].task_status == TIME_TASK_RUN) {
      if (g_time_task[i].fun != NULL) {
        g_time_task[i].fun();

        g_time_task[i].fun = NULL;
        g_time_task[i].task_status = TIME_TASK_OK; // 执行完成后清除标志内容
      }
    }
  }
}


void updata_time_task_time(void) // 更新定时器 1秒周期执行
{
  uint8_t i = 0;
  for (i=0; i<TIME_TASK_NUM; i++) {

    if (g_time_task[i].task_status == TIME_TASK_DELAY && g_time_task[i].run_seconds < g_time_task[i].delay_seconds) {
      g_time_task[i].run_seconds ++;
      g_time_task[i].task_status = TIME_TASK_DELAY;
      GUA_LOGI("timer task: id[%d] run seconds[%d] < delay[%d]", i, g_time_task[i].run_seconds, g_time_task[i].delay_seconds);

    } else if (g_time_task[i].task_status == TIME_TASK_DELAY && g_time_task[i].run_seconds >= g_time_task[i].delay_seconds) {
      GUA_LOGI("timeout ! timer task: id[%d] run seconds[%d] = delay[%d]", i, g_time_task[i].run_seconds, g_time_task[i].delay_seconds);
      g_time_task[i].run_seconds = 0;
      g_time_task[i].task_status = TIME_TASK_RUN;
    }
  }
}



int32_t register_run_single_time_task(task_callback fun, uint32_t seconds) // 单次定时执行任务注册函数
{
  uint8_t i = 0;

  for (i=0; i<TIME_TASK_NUM; i++) {
    if (g_time_task[i].task_status == TIME_TASK_OK ) {
      g_time_task[i].fun = fun;
      g_time_task[i].delay_seconds = seconds;
      g_time_task[i].task_status = TIME_TASK_DELAY;
      g_time_task[i].run_seconds = 0;
      GUA_LOGI("register timer task times[%d] status[%d] delay[%d] run[%d]", i, g_time_task[i].task_status, seconds, g_time_task[i].run_seconds);
      return 0;
    }
  }

  GUA_LOGE("task register error! task memory empty!");
  return -1;
}

void init_timer_task(void)
{
  uint8_t i = 0;

  for (i=0; i<TIME_TASK_NUM; i++) {
      g_time_task[i].fun = NULL;
      g_time_task[i].delay_seconds = 0;
      g_time_task[i].task_status = TIME_TASK_OK;
      g_time_task[i].run_seconds = 0;
  }
}
