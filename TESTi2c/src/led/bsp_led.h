/*
 * bsp_led.h
 *
 *  Created on: 2024年7月30日
 *      Author: steve
 */

#ifndef LED_BSP_LED_H_
#define LED_BSP_LED_H_
#include "hal_data.h"

#define LED_RED   BSP_IO_PORT_03_PIN_01
#define LED_BULE  BSP_IO_PORT_03_PIN_02
#define LED_GREEN BSP_IO_PORT_02_PIN_07

/* LED引脚置低电平 LED灯亮 */
#define LED1_ON     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_01, BSP_IO_LEVEL_LOW)
#define LED2_ON     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_02, BSP_IO_LEVEL_LOW)
#define LED3_ON     R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_07, BSP_IO_LEVEL_LOW)

/* LED引脚置高电平 LED灯灭 */
#define LED1_OFF    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_01, BSP_IO_LEVEL_HIGH)
#define LED2_OFF    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_02, BSP_IO_LEVEL_HIGH)
#define LED3_OFF    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_07, BSP_IO_LEVEL_HIGH)


/* LED初始化函数 */
void LED_Init(void);


#endif /* LED_BSP_LED_H_ */
