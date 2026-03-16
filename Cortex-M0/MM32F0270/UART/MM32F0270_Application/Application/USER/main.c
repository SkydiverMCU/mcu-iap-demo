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
#include "uart_txrx_idleframe_interrupt.h"
#include "app_protocol.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{

    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)(FLASH_BASE | APP_ADDRESS_OFFSET), VECTOR_SIZE);
    // Enable the SYSCFG Peripheral Clock
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG, ENABLE);
    // 将向量表映射到SRAM 0x20000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    DELAY_Init();
    UART1_NVIC_Init(115200);

    // printf("MM32F0270 enter application \r\n");

    while (1)
    {
        Receive_Protocol_Process(); // 添加串口，支持直接Application接收串口升级协议，跳转回Bootloader
    }
}

/// @}

/// @}

/// @}
