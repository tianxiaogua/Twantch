#ifndef __DELAY_H
#define __DELAY_H 			   

#include "main.h"
#include <stdlib.h>

#define CPU_FREQUENCY_MHZ    170		// STM32时钟主频

void delay_ms(uint16_t nms);
void delay_us(uint32_t nus);

#endif


