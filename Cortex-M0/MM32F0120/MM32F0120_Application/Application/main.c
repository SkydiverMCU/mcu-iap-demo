/***********************************************************************************************************************
    @file    main.c
    @author  FD Team
    @date    12-Dec-2023
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
#include "string.h"
#include "stdio.h"

/**
 * @addtogroup MM32F0120_LibSamples
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
#define APPLICATION_ADDRESS (uint32_t)(0x08001800) // APP START ADDRESS
#define VECTOR_SIZE 0xC0
/***********************************************************************************************************************
 * @brief  This function is main entrance
 * @note   main
 * @param  none
 * @retval none
 *********************************************************************************************************************/
int main(void)
{
  // M0 要把APP的向量表转移到SRAM
  memcpy((void *)0x20000000, (void *)APPLICATION_ADDRESS, VECTOR_SIZE);
  // Enable the SYSCFG Peripheral Clock
  RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG_Msk, ENABLE);
  // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
  SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
  __enable_irq();

  PLATFORM_Init();
    
  printf("Enter Application success...\r\n");

  USART_Interrupt_Sample();

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
