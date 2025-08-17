/*
 * tool.c
 *
 *  Created on: 2023年8月1日
 *      Author: tianxiaohua
 */

#include "driver_tool.h"
#include "stdio.h"


// 冒泡排序算法
void driver_bubble_sort(float arr[], int n)
{
    // 外层循环控制遍历次数
    for (int i = 0; i < n - 1; i++) {
        // 内层循环进行相邻元素比较
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换元素
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 去掉最大值和最小值的函数
int32 driver_remove_max_and_min(float arr[], int32 n)
{
    if (n <= 2) {
        GUA_LOGE("ERROR! no enough\n");
        return -1;
    }

    // 先对数组进行排序
    driver_bubble_sort(arr, n);

    // 删除最大值和最小值，更新数组长度
    for (int32 i = 1; i < n - 1; i++) {
        arr[i - 1] = arr[i];
    }

    // 更新数组长度
    n = n - 2;

    return n;
}

