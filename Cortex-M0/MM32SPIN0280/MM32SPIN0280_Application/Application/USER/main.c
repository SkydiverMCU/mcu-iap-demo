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
#include "uart.h"
#include "uart_txrx_idleframe_interrupt.h"

#define APPLICATION_ADDRESS (uint32_t)(0x08001800) // APP START ADDRESS

/**********************************function*******************************/
#define VECTOR_SIZE 0xC0

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)APPLICATION_ADDRESS, VECTOR_SIZE);
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG, ENABLE);
    // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    DELAY_Init();
    CONSOLE_Init(115200);
    UART1_NVIC_Init(115200);

    printf("Enter Application success...\r\n");

    while (1)
    {
        UART1_RxTx_Transceiving();
    }

    // return 0;
}

/// @}

/// @}

/// @}
