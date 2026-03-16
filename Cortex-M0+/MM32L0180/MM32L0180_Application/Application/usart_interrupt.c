/***********************************************************************************************************************
    @file    usart_interrupt.c
    @author  FAE Team
    @date    07-Feb-2025
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
#define _USART_INTERRUPT_C_

/* Files include */
#include <stdio.h>
#include "platform.h"
#include "usart_interrupt.h"

/**
 * @addtogroup MM32L0180_LibSamples
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

/***********************************************************************************************************************
 * @brief
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void USART_Configure(uint32_t Baudrate)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  NVIC_InitTypeDef NVIC_InitStruct;
  USART_InitTypeDef USART_InitStruct;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  USART_StructInit(&USART_InitStruct);
  USART_InitStruct.USART_BaudRate = Baudrate;
  USART_InitStruct.USART_WordLength = USART_WordLength_8b;
  USART_InitStruct.USART_StopBits = USART_StopBits_1;
  USART_InitStruct.USART_Parity = USART_Parity_No;
  USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_Init(USART2, &USART_InitStruct);

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPriority = 0;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);

  USART_ITConfig(USART2, USART_IT_PE, ENABLE);
  USART_ITConfig(USART2, USART_IT_ERR, ENABLE);
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

  USART_Cmd(USART2, ENABLE);
}

/***********************************************************************************************************************
 * @brief
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void USART_SendGroup(uint8_t *pBuff, uint16_t length)
{
  while (length--)
  {
    USART_SendData(USART2, (uint8_t)*pBuff);

    while (RESET == USART_GetFlagStatus(USART2, USART_FLAG_TC))
    {
    }
    pBuff++;
  }
}

/***********************************************************************************************************************
 * @brief  This function handles USART1 Handler
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void USART2_IRQHandler(void)
{
  uint8_t RxData = 0;

  if ((RESET != USART_GetITStatus(USART2, USART_IT_PE)) ||
      (RESET != USART_GetITStatus(USART2, USART_IT_ERR)))
  {
    USART_ReceiveData(USART2);
  }

  if (RESET != USART_GetITStatus(USART2, USART_IT_IDLE))
  {
    USART_ReceiveData(USART2);
    /* Disable IDLE Interrupt */
    CLEAR_BIT(USART2->CR1, USART_CR1_IDLEIEN);

    USART_RX_STA |= 0x8000;
  }

  if (RESET != USART_GetITStatus(USART2, USART_IT_RXNE))
  {
    RxData = USART_ReceiveData(USART2);

    if (0 == READ_BIT(USART2->CR1, USART_CR1_IDLEIEN))
    {
      /* Enable IDLE Interrupt */
      SET_BIT(USART2->CR1, USART_CR1_IDLEIEN);
    }

    if ((USART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
    {
      if (USART_RX_STA < REPORT_PACKET_SIZE) // 还可以接收数据
      {
        USART_RxBuff[USART_RX_STA++] = RxData; // 记录接收到的值
      }
      else
      {
        USART_RX_STA |= 0x8000; // 强制标记接收完成
      }
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
