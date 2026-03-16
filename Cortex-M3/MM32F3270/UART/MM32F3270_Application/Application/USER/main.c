////////////////////////////////////////////////////////////////////////////////
/// @file    main.c
/// @author  AE TEAM
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion
#define _MAIN_C_

// Files includes

#include "main.h"
#include "delay.h"
#include "led.h"
#include "uart_txrx_interrupt.h"
#include "app_protocol.h"
////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    SCB->VTOR = FLASH_BASE | APP_ADDRESS_OFFSET; // M3可以对中断向量进行偏移，这样app的中断可以直接跳到自己的中断服务函数
    __enable_irq();                              // 跳转之后要确保打开总中断

    DELAY_Init();
    UART1_NVIC_Init(115200);

    // printf("MM32F3270 enter application \r\n");

    while (1)
    {
        LED1_OFF();
        LED2_OFF();
        LED3_OFF();
        LED4_OFF();

        LED1_ON();
        LED2_ON();
        LED3_ON();
        LED4_ON();

        Receive_Protocol_Process(); // 添加串口，支持直接Application接收串口升级协议，跳转回Bootloader
    }
}

/// @}

/// @}

/// @}
