/***********************************************************************************************************************
    @file    main.c
    @author  FAE Team
    @date    17-Nov-2023
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
#include "usart_interrupt.h"
#include "main.h"
#include "boot.h"
#include "crc32_algorithm.h"
#include <stdio.h>
/**
 * @addtogroup MM32G0001_LibSamples
 * @{
 */

/**
 * @addtogroup USART
 * @{
 */

/**
 * @addtogroup USART_Interrupt
 * @{
 */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/
const uint8_t booterror_str[] = {"Boot Error\r\n"};
/***********************************************************************************************************************
 * @brief  This function is main entrance
 * @note   main
 * @param  none
 * @retval none
 *********************************************************************************************************************/
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
    USART_Configure(115200);
    USART_SendGroup((uint8_t *)&booterror_str, sizeof(booterror_str));
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

  PLATFORM_Init();

  printf("MM32G0001 enter bootloader \r\n");

  USART_Configure(115200);

  while (1)
  {
    if (USART_RX_STA & 0x8000)
    {
      len = USART_RX_STA & 0x7FFF;
      boot_protocol(USART_RxBuff, len);
      USART_RX_STA = 0;
    }
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
