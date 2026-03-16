/***********************************************************************************************************************
    @file    main.c
    @author  FAE Team
    @date    25-May-2023
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
#include "uart_receiveridleframe_interrupt.h"
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "app_protocol.h"

/**
 * @addtogroup MM32G0020_LibSamples
 * @{
 */

/**
 * @addtogroup UART
 * @{
 */

/**
 * @addtogroup UART_ReceiverIdleFrame_Interrupt
 * @{
 */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/

/***********************************************************************************************************************
 * @brief  This function is main entrance
 * @note   main
 * @param  none
 * @retval none
 *********************************************************************************************************************/
int main(void)
{
  // M0 要把APP的向量表转移到SRAM
  memcpy((void *)0x20000000, (void *)(FLASH_START_ADDR | APP_ADDRESS_OFFSET), VECTOR_SIZE);
  // Enable the SYSCFG Peripheral Clock
  RCC_APB1PeriphClockCmd(RCC_APB1ENR_SYSCFG, ENABLE);
  // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
  SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
  __enable_irq();

  PLATFORM_Init();

  printf("MM32G0020 enter application \r\n");

  UART_Configure(115200);

  while (1)
  {
    Receive_Protocol_Process(); // 添加串口，支持直接Application接收串口升级协议，跳转回Bootloader
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
