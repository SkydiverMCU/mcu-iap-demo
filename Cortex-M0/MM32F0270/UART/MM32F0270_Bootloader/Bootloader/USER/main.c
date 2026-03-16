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
#include "boot.h"
#include "stdio.h"
#include "crc32_algorithm.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    uint8_t flag[4];
    uint16_t len;
    uint32_t Read_address = 0x08000000;

    uint32_t Calculation_crc_result = 0;

    uint32_t Bootloader_crc_result = 0;
    uint32_t Information_crc_result = 0;
    uint32_t Application_crc_result = 0;
    uint32_t Application_lenth = 0;

    Bootloader_crc_result = *(volatile uint32_t *)(BootJumpFlagAddress - 4);
    Information_crc_result = *(volatile uint32_t *)(ApplicationAddress - 4);
    Application_crc_result = *(volatile uint32_t *)(BootJumpFlagAddress + 8);

    Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)Read_address, (BOOT_SIZE * 1024) - 4); // Bootloader CRC 校验
    if (Calculation_crc_result != Bootloader_crc_result)
    {
        // printf("Boot Error\r\n");
        while (1) // Bootloader CRC32校验失败
        {
        }
    }

    Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)BootJumpFlagAddress, 1024 - 4); // 1K Information CRC 校验
    if (Calculation_crc_result == Information_crc_result)
    {
        Application_lenth = *(volatile uint32_t *)(BootJumpFlagAddress + 4);
        if ((Application_lenth != 0xFFFFFFFF) && (Application_lenth <= (APP_SIZE * 1024))) // 获取 Application 程序区长度
        {
            Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)ApplicationAddress, Application_lenth); // Application CRC 校验
            if (Calculation_crc_result == Application_crc_result)
            {
                FLASH_Read(flag, BootJumpFlagAddress, 4);

                if ((flag[0] == 0x55) && (flag[1] == 0xAA) && (flag[2] == 0xAA) && (flag[3] == 0x55)) // 如果用户程序有效，则跳转到用户程序执行用户程序。
                {
                    if (((*(__IO uint32_t *)ApplicationAddress) & SRAM_LEGAL_ADDRESS_MASK) == 0x20000000) // 检查栈顶地址是否SRAM合法
                    {

                        // Reset_Periph();//跳转之前，需要关闭boot初始化过的外设，避免导致跳到APP里面后boot里面的外设仍然在工作
                        __disable_irq();
                        __set_MSP(*(u32 *)ApplicationAddress);                     // 设置SP堆栈栈顶地址
                        ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))(); // 生成跳转函数.将复位中断向量地址做为函数指针
                    }
                }
            }
        }
    }

    // printf("MM32F0270 enter bootloader \r\n");

    DELAY_Init();
    UART1_NVIC_Init(115200);
    while (1)
    {
        if (UART_RX_STA & 0x8000)
        {
            len = UART_RX_STA & 0x7FFF;
            boot_protocol(UART_RxBuff, len);
            UART_RX_STA = 0;
        }
    }
}

/// @}

/// @}

/// @}
