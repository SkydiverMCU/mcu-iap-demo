/***********************************************************************************************************************
    @file    platform.c
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
#define _PLATFORM_C_

/* Files include */
#include <stdio.h>
#include "platform.h"

/**
 * @addtogroup MM32G0001_LibSamples
 * @{
 */

/**
 * @addtogroup MM32
 * @{
 */

/**
 * @addtogroup PLATFORM
 * @{
 */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/
extern uint32_t SystemCoreClock;
/***********************************************************************************************************************
 * @brief  Initialize SysTick for delay function
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void PLATFORM_InitDelay(void)
{
  // RCC_ClocksTypeDef RCC_Clocks;

  // RCC_GetClocksFreq(&RCC_Clocks);

  if (SysTick_Config(SystemCoreClock / 1000))
  {
    while (1)
    {
    }
  }

  NVIC_SetPriority(SysTick_IRQn, 0x0);
}

/***********************************************************************************************************************
 * @brief  Millisecond delay
 * @note   none
 * @param  Millisecond: delay time unit
 * @retval none
 *********************************************************************************************************************/
void PLATFORM_DelayMS(uint32_t Millisecond)
{
  PLATFORM_DelayTick = Millisecond;

  while (0 != PLATFORM_DelayTick)
  {
  }
}

/***********************************************************************************************************************
 * @brief  Initialize console for printf
 * @note   none
 * @param  Baudrate : USART1 communication baudrate
 * @retval none
 *********************************************************************************************************************/
void PLATFORM_InitConsole(uint32_t Baudrate)
{

#if 0
  
  GPIO_InitTypeDef GPIO_InitStruct;
  USART_InitTypeDef USART_InitStruct;

  RCC_APB1PeriphClockCmd(RCC_APB1PERIPH_USART1, ENABLE);

  USART_StructInit(&USART_InitStruct);
  USART_InitStruct.USART_BaudRate = Baudrate;
  USART_InitStruct.USART_StopBits = USART_StopBits_1;
  USART_InitStruct.USART_Parity = USART_Parity_No;
  USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART1, &USART_InitStruct);

  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_4);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  USART_Cmd(USART1, ENABLE);

#else

  /* Enable GPIOA Clock */
  SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOA);

  /* Config PA10 AF1 */
  MODIFY_REG(GPIOA->AFRH, GPIO_AFRH_AFR10, 0x04U << GPIO_AFRH_AFR12_Pos);

  /* Config PA10 Alternate Function AF_PP */
  MODIFY_REG(GPIOA->CRH, GPIO_CRH_MODE10, 0x01U << GPIO_CRH_MODE12_Pos);
  MODIFY_REG(GPIOA->CRH, GPIO_CRH_CNF10, 0x02U << GPIO_CRH_CNF12_Pos);

  /* Enable USART1 Clock */
  SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART1);

  /* Parity : None */
  CLEAR_BIT(USART1->CR1, USART_CR1_PCE);
  CLEAR_BIT(USART1->CR1, USART_CR1_PS);

  /* Data Length : 8-bit */
  CLEAR_BIT(USART1->CR1, USART_CR1_DL);

  /* Stop Bit : 1-bit */
  MODIFY_REG(USART1->CR2, USART_CR2_STOP, 0x00U << USART_CR2_STOP_Pos);

  /* Baudrate */
  MODIFY_REG(USART1->BRR, USART_BRR_MFD, ((SystemCoreClock / Baudrate) / 16) << USART_BRR_MFD_Pos);
  MODIFY_REG(USART1->BRR, USART_BRR_FFD, ((SystemCoreClock / Baudrate) % 16) << USART_BRR_FFD_Pos);

  /* Enable Transmit */
  SET_BIT(USART1->CR1, USART_CR1_TE);

  /* Enable USART1 */
  SET_BIT(USART1->CR1, USART_CR1_UE);

#endif
}

#if defined(__ICCARM__)

#if (__VER__ >= 9030001)

/* Files include */
#include <stddef.h>
#include <LowLevelIOInterface.h>

/***********************************************************************************************************************
 * @brief  redefine __write function
 * @note   for printf
 * @param  handle
 * @param  *buf
 * @param  bufSize
 * @retval nChars
 *********************************************************************************************************************/
size_t __write(int handle, const unsigned char *buf, size_t bufSize)
{
  size_t nChars = 0;

  /* Check for the command to flush all handles */
  if (-1 == handle)
  {
    return (0);
  }

  /* Check for stdout and stderr (only necessary if FILE descriptors are enabled.) */
  if ((_LLIO_STDOUT != handle) && (_LLIO_STDERR != handle))
  {
    return (-1);
  }

  for (/* Empty */; bufSize > 0; --bufSize)
  {
    USART_SendData(USART1, *buf);

    while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
    {
    }

    ++buf;
    ++nChars;
  }

  return (nChars);
}

#else

/***********************************************************************************************************************
 * @brief  redefine fputc function
 * @note   for printf
 * @param  ch
 * @param  f
 * @retval ch
 *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
  USART_SendData(USART1, (uint8_t)ch);

  while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
  {
  }

  return (ch);
}

#endif

#elif defined(__GNUC__)

/***********************************************************************************************************************
 * @brief  redefine fputc function
 * @note   for printf
 * @param  ch
 * @param  f
 * @retval ch
 *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
  USART_SendData(USART1, (uint8_t)ch);

  while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
  {
  }

  return (ch);
}

#else

/***********************************************************************************************************************
 * @brief  redefine fputc function
 * @note   for printf
 * @param  ch
 * @param  f
 * @retval ch
 *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
  USART_SendData(USART1, (uint8_t)ch);

  while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
  {
  }

  return (ch);
}

#endif

/***********************************************************************************************************************
 * @brief  Initialize Platform
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void PLATFORM_Init(void)
{
  PLATFORM_InitDelay();

  PLATFORM_InitConsole(115200);
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
