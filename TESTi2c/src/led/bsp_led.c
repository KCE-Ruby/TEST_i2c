/*
 * bsp_led.c
 *
 *  Created on: 2024年7月30日
 *      Author: steve
 */
#include "bsp_led.h"
#ifndef LED_BSP_LED_C_
#define LED_BSP_LED_C_

void LED_Init(void)
{
    /* 初始化配置引脚（这里重复初始化了，可以注释掉） */
    R_IOPORT_Open (&g_ioport_ctrl, g_ioport.p_cfg);
}

#endif /* LED_BSP_LED_C_ */
