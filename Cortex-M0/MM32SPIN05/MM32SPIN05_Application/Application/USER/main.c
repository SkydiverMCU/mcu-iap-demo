////////////////////////////////////////////////////////////////////////////////
/// @file    main.c
/// @author  AE TEAM
/// @brief   Output received data.
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
#include "led.h"
#include "delay.h"
#include "stdio.h"
#include "string.h"
#include "uart_txrx_interrupt.h"
#include "app_protocol.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{

    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)(FLASH_BASE | APP_ADDRESS_OFFSET), VECTOR_SIZE);
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    DELAY_Init();
    LED_Init();
    UART1_NVIC_Init(115200);

    // printf("MM32SPIN05 enter application \r\n");

    TIM3_Up_Init(100 - 1, 72 - 1); // 100us 中断 用于UART接收空闲处理

    while (1)
    {
        LED1_TOGGLE();
        LED2_TOGGLE();
        LED3_TOGGLE();
        LED4_TOGGLE();
        Receive_Protocol_Process(); // 添加串口，支持直接Application接收串口升级协议，跳转回Bootloader
    }
}

/// @}

/// @}

/// @}
