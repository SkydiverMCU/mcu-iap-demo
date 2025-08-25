/***********************************************************************************************************************
    @file    platform.c
    @author  FAE Team
    @date    20-Jan-2023
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
 * @addtogroup MM32L0020_LibSamples
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
 * @param  Baudrate : LPUART1 communication baudrate
 * @retval none
 *********************************************************************************************************************/
void PLATFORM_InitConsole(void)
{

#if 0

    GPIO_InitTypeDef   GPIO_InitStruct;
    LPUART_InitTypeDef LPUART_InitStruct;

    RCC_LSICmd(ENABLE);

    while (RESET == RCC_GetFlagStatus(RCC_FLAG_LSIRDY))
    {
        __NOP();
    }

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_LPUART, ENABLE);

    LPUART_StructInit(&LPUART_InitStruct);
    LPUART_InitStruct.LPUART_BaudRate     = LPUART_Baudrate_9600;
    LPUART_InitStruct.LPUART_WordLength   = LPUART_WordLength_8b;
    LPUART_InitStruct.LPUART_StopBits     = LPUART_StopBits_1;
    LPUART_InitStruct.LPUART_Parity       = LPUART_Parity_No;
    LPUART_InitStruct.LPUART_ClockSource  = 0;
    LPUART_InitStruct.LPUART_MODU         = 0x952;
    LPUART_InitStruct.LPUART_NEDET        = LPUART_NegativeDectect_Use;
    LPUART_InitStruct.LPUART_RecvEvent    = LPUART_RecvEvent_Start_Bit;
    LPUART_Init(LPUART1, &LPUART_InitStruct);

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_2);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_1;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    LPUART_Cmd(LPUART1, ENABLE);

#else

  RCC->CSR |= ((0x01U << RCC_CSR_LSION_Pos) | (0x01U << RCC_CSR_LSIOE_Pos));
  while ((RCC->CSR & RCC_CSR_LSIRDY_Msk) == 0)
  {
    __NOP();
  }
  RCC->APB1ENR |= RCC_APB1ENR_LPUART_Msk;

  RCC->APB1RSTR |= RCC_APB1RSTR_LPUART_Msk;
  RCC->APB1RSTR &= ~RCC_APB1RSTR_LPUART_Msk;

  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPUARTCLKSEL_Msk, RCC_CFGR2_LPUARTCLKSEL_LSI); // LSI
  MODIFY_REG(LPUART1->LPUBAUD, LPUART_LPUBAUD_BAUD_Msk, LPUART_LPUBAUD_BAUD_9600);
  MODIFY_REG(LPUART1->MODU, LPUART_MODU_MCTL_Msk, 0x952);

  MODIFY_REG(LPUART1->LPUCON,
             (LPUART_LPUCON_DL_Msk |
              LPUART_LPUCON_SL_Msk |
              LPUART_LPUCON_PAREN_Msk |
              LPUART_LPUCON_PTYP_Msk |
              LPUART_LPUCON_RXEV_Msk |
              LPUART_LPUCON_NEDET_Msk),
             (LPUART_WordLength_8b |
              LPUART_StopBits_1 |
              LPUART_Parity_No |
              LPUART_RecvEvent_Start_Bit |
              LPUART_NegativeDectect_Use));

  RCC->AHBENR |= RCC_AHBPeriph_GPIOA;

  /* Config PA1 AF2 */
  MODIFY_REG(GPIOA->AFRL, GPIO_AFRL_AFR1, 0x02U << GPIO_AFRL_AFR1_Pos);

  /* Config PA1 Alternate Function Output Push-Pull */
  MODIFY_REG(GPIOA->CRL, GPIO_CRL_MODE1, 0x01U << GPIO_CRL_MODE1_Pos);
  MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF1, 0x02U << GPIO_CRL_CNF1_Pos);

  LPUART1->LPUEN |= (0x01U << LPUART_LPUEN_TXEN_Pos);

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
    LPUART_SendData(LPUART1, *buf);

    while (RESET == LPUART_GetFlagStatus(LPUART1, LPUART_LPUSTA_TXE))
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
  LPUART1->LPUTXD = (uint8_t)ch;

  while ((LPUART1->LPUSTA & LPUART_LPUSTA_TXE) == 0)
  {
  }

  return (ch);
}

#endif

#elif defined(__GNUC__)

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
  LPUART1->LPUTXD = (uint8_t)ch;

  while ((LPUART1->LPUSTA & LPUART_LPUSTA_TXE) == 0)
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

  // PLATFORM_InitLED();

  PLATFORM_InitConsole();
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
