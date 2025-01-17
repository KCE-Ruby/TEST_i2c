#include "bsp_debug_uart.h"
#include "debug_uart/circular_queue.h"

volatile bool uart_send_complete_flag = false;
/* 调试串口 UART1 初始化 */
void Debug_UART1_Init(void)
{
    fsp_err_t err = FSP_SUCCESS;

    err = R_SCI_UART_Open (&g_uart9_ctrl, &g_uart9_cfg);
    assert(FSP_SUCCESS == err);
}



/* 发送完成标志 */
//volatile bool uart_send_complete_flag = false;


/* 串口中断回调 */
void debug_uart1_callback (uart_callback_args_t * p_args)
{
    switch (p_args->event)
    {
        case UART_EVENT_RX_CHAR:
        {
            /* 接收到数据后马上写入队列中 */
            Queue_Wirte(&Circular_queue, (uint8_t*) &p_args->data, 1);
            break;
        }
        case UART_EVENT_TX_COMPLETE:
        {
            uart_send_complete_flag = true;
            break;
        }
        default:
            break;
    }
}


/* 重定向 printf 输出 */
#if defined __GNUC__ && !defined __clang__
int _write(int fd, char *pBuffer, int size); //防止编译警告
int _write(int fd, char *pBuffer, int size)
{
    (void)fd;
    R_SCI_UART_Write(&g_uart9_ctrl, (uint8_t *)pBuffer, (uint32_t)size);
    while(uart_send_complete_flag == false);
    uart_send_complete_flag = false;

    return size;
}
#else
int fputc(int ch, FILE *f)
{
    (void)f;
    R_SCI_UART_Write(&g_uart9_ctrl, (uint8_t *)&ch, 1);
    while(uart_send_complete_flag == false);
    uart_send_complete_flag = false;

    return ch;
}
#endif





