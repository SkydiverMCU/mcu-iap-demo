/***********************************************************************************************************************
    @file    main.c
    @author  FD Team
    @date    22-March-2024
    @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Define to prevent recursive inclusion */
#define _MAIN_C_

/* Files include */
#include "platform.h"
#include "tinyusb_device_msc.h"
#include "main.h"
//#include "SEGGER_RTT.h"
#include "boot.h"
#include "stdio.h"
#include "crc32_algorithm.h"
#include "gpio_key_input.h"
/**
  * @addtogroup MM32F5330_TinyUSB
  * @{
  */

/**
  * @addtogroup TinyUSB_Device
  * @{
  */

/**
  * @addtogroup TinyUSB_Device_MSC
  * @{
  */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/
/* 使用说明

   Bootloader 和 Application 都通过PB6 pritnf打印输出log信息，460800bps
   程序基于外部 SPI Flash  W25Q64 枚举一个 8M 的U盘 用于IAP升级
   升级的时候直接把Application工程里面 Application.uvprojx 同级目录下 Update.bin 文件 放到U盘里面
   等待系统检测到U盘里面有文件更新，则会去读取 Update.bin 文件进行升级
   具体128K Flash 空间划分请参考 boot.h文件
   Bootloader 默认使用外部8M晶振，PLL2倍频到96M 二分频后给到USB

   SPI Flash 与 MCU 接线引脚定义

   PA15  -->  CS
   PB3   -->  SCLK
   PB4   -->  MISO
   PB5   -->  MOSI

  */

/***********************************************************************************************************************
  * @brief  This function is main entrance
  * @note   main
  * @param  none
  * @retval none
  *********************************************************************************************************************/
/*请注意/Please note*/
/*修改 Bootloader 和 Application Flash空间大小分配，请到Options for Target -> Linker -> ..\..\Device\MM32F5330\Source\mm32f5330.sct  分散加载文件里面去修改*/
/*To modify the allocation of Bootloader and Application Flash space, please go to Options for Target -> Linker -> ....\Device\MM32F5330\Source\mm32f5330.sct in the scatter-loading file to make the changes.*/
/*程序使用外部8M晶振*/
/*Please using an External 8MHz Crystal Oscillator*/
int main(void)
{
    uint8_t flag[4];
    uint16_t len;
    uint32_t Read_address = 0x08000000;
    uint32_t Calculation_crc_result = 0;
    uint32_t Bootloader_crc_result  = 0;
    uint32_t Information_crc_result = 0;
    uint32_t Application_crc_result = 0;
    uint32_t Application_lenth = 0;

    //SEGGER_RTT_Init();
    //SEGGER_RTT_WriteString(0, RTT_CTRL_CLEAR);
    //DEBUG0_WHITE("\r\nSEGGER_RTT Run...%s %s\r\n", __DATE__, __TIME__);
    //DEBUG0_WHITE("Offline Programmer System Initial Success...\r\n");

    Bootloader_crc_result  = *(volatile uint32_t *)(BootJumpFlagAddress - 4);
    Information_crc_result = *(volatile uint32_t *)(ApplicationAddress - 4);
    Application_crc_result = *(volatile uint32_t *)(BootJumpFlagAddress + 8);

    Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)Read_address, (BOOT_SIZE * 1024) - 4, CRC32_MPEG2_INIT); // Bootloader CRC 校验

    if (Calculation_crc_result != Bootloader_crc_result)
    {
        PLATFORM_Init();
        printf("Boot Error\r\n");

        while (1)                      // Bootloader CRC32校验失败
        {
        }
    }

    Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)BootJumpFlagAddress, 1024 - 4, CRC32_MPEG2_INIT); // 1K Information CRC 校验

    if (Calculation_crc_result == Information_crc_result)
    {
        Application_lenth = *(volatile uint32_t *)(BootJumpFlagAddress + 4);

        if ((Application_lenth != 0xFFFFFFFF) && (Application_lenth <= (APP_SIZE * 1024)))                                      // 获取 Application 程序区长度
        {
            Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)ApplicationAddress, Application_lenth, CRC32_MPEG2_INIT); // Application CRC 校验

            if (Calculation_crc_result == Application_crc_result)
            {
                FLASH_Read(flag, BootJumpFlagAddress, 4);

                if ((flag[0] == 0x32) && (flag[1] == 0x33) && (flag[2] == 0x4D) && (flag[3] == 0x4D))     // 如果用户程序有效，则跳转到用户程序执行用户程序。   #define HEADER_VALUE   0x4D4D3332
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

    PLATFORM_Init();

    TinyUSB_Mass_Storage_Sample();

    while (1)
    {
    }
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/********************************************** (C) Copyright MindMotion **********************************************/

