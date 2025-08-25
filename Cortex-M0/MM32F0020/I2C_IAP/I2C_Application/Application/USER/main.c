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
#include "led.h"
#include "delay.h"
#include "uart.h"
#include "protocol.h"

#define APPLICATION_ADDRESS (uint32_t)(0x08002800) // APP START ADDRESS

// 支持将向量表转移到SRAM
/**********************************function*******************************/
__IO uint32_t VectorTable[48] __attribute__((at(0x20000000)));
#define VECTOR_SIZE 0xC0

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
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
s32 main(void)
{
    u8 i;

    // 将APP的向量表转移到SRAM
    for (i = 0; i < 48; i++)
    {
        VectorTable[i] = *(__IO uint32_t *)(APPLICATION_ADDRESS + (i << 2));
    }
    // Enable the SYSCFG Peripheral Clock
    RCC_APB1PeriphClockCmd(RCC_APB1ENR_SYSCFG, ENABLE);

    // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    LED_Init();
    DELAY_Init();

    while (1)
    {
        LED1_TOGGLE();
        DELAY_Ms(300);
    }
}

/// @}

/// @}

/// @}
