#include "hal_data.h"
#include "led/bsp_led.h"
#include "eeprom/i2c_ee.h"
#include "debug_uart/bsp_debug_uart.h"
#include "adc/bsp_adc.h"
FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER
double Read_ADC_Voltage_Value(void);
/*******************************************************************************************************************//**
 * main() is generated by the RA Configuration editor and is used to generate threads if an RTOS is used.  This function
 * is called by main() when no RTOS is used.
 **********************************************************************************************************************/
void hal_entry(void)
{
    /* TODO: add your own code here */

    I2C_EE_Init();
        Debug_UART1_Init();
        //ADC_Init();
        //printf("欢迎使用野火  RA6M5 开发板。\r\n");
        //printf("这是一个I2C外设(AT24C02)读写测试例程 \r\n");
       // printf("这是一个读取电位器ADC电压转换值的例程\r\n");
        //    printf("打开串口助手查看ADC转换结果，旋钮电位器，可以看到ADC值在一定范围之内发生变化\r\n");
        //    printf("开始读取ADC转换值：\r\n");
            //printf("a0 = %f\r\n", Read_ADC_Voltage_Value());
       // R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);

        while (1)
        {
            //printf("a0 = %f\r\n", a0);

                  // R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS); //大概0.5秒钟读取一次
                 //  Read_ADC_Voltage_Value();
                   //printf(" a0=%f\n",  a0);
            I2C_EE_Writedrase();
            if (I2C_Test() ==1) {
                LED3_OFF;
                //R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MILLISECONDS);
            } else {
                LED1_ON;
                //R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);
            }

            //while(1);
        }

#if BSP_TZ_SECURE_BUILD
    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open (&g_ioport_ctrl, &IOPORT_CFG_NAME);
    }
}

#if BSP_TZ_SECURE_BUILD

FSP_CPP_HEADER
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ();

/* Trustzone Secure Projects require at least one nonsecure callable function in order to build (Remove this if it is not required to build). */
BSP_CMSE_NONSECURE_ENTRY void template_nonsecure_callable ()
{

}
FSP_CPP_FOOTER

#endif
