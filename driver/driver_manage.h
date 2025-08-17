#ifndef DRIVER_MANAGE_H
#define DRIVER_MANAGE_H

#include "main.h"

#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TURN_ON 1
#define TURN_OFF 0

#define DRIVER_USART       TURN_ON
#define DRIVER_ADC         TURN_ON
#define DRIVER_DELAY       TURN_ON
#define DRIVER_ENCODER     TURN_ON
#define DRIVER_GPIO        TURN_ON
#define DRIVER_IIC         TURN_ON
#define DRIVER_KEY         TURN_ON
#define DRIVER_LOWPOWER    TURN_ON
#define DRIVER_NVIC        TURN_ON
#define DRIVER_PWM         TURN_ON
#define DRIVER_TOOL        TURN_ON

#if DRIVER_USART
#include "driver_usart.h"
#endif



#endif
