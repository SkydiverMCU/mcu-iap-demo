/***********************************************************************************************************************
    @file    uart_receiveridleframe_interrupt.c
    @author  FAE Team
    @date    30-Nov-2023
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
#define _UART_RECEIVERIDLEFRAME_INTERRUPT_C_

/* Files include */
#include <stdio.h>
#include "platform.h"
#include "uart_receiveridleframe_interrupt.h"

/**
 * @addtogroup MM32F0020_LibSamples
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
 * @brief
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void UART_Configure(uint32_t Baudrate)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  NVIC_InitTypeDef NVIC_InitStruct;
  UART_InitTypeDef UART_InitStruct;

  RCC_APB1PeriphClockCmd(RCC_APB1ENR_UART1, ENABLE);

  UART_StructInit(&UART_InitStruct);
  UART_InitStruct.BaudRate = Baudrate;
  UART_InitStruct.WordLength = UART_WordLength_8b;
  UART_InitStruct.StopBits = UART_StopBits_1;
  UART_InitStruct.Parity = UART_Parity_No;
  UART_InitStruct.HWFlowControl = UART_HWFlowControl_None;
  UART_InitStruct.Mode = UART_Mode_Rx | UART_Mode_Tx;
  UART_Init(UART1, &UART_InitStruct);

  UART_ITConfig(UART1, UART_IER_RX, ENABLE);
  UART_ITConfig(UART1, UART_IER_RXIDLE, ENABLE);

  RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  NVIC_InitStruct.NVIC_IRQChannel = UART1_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPriority = 1;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);

  UART_Cmd(UART1, ENABLE);
}

/***********************************************************************************************************************
 * @brief  This function handles UART1 Handler
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void UART1_IRQHandler(void)
{

  if (RESET != UART_GetITStatus(UART1, UART_ISR_RX_INTF))
  {
    // UART_RxBuffer[UART_RxLength++] = UART_ReceiveData(UART1);
    if ((UART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
    {
      if (UART_RX_STA < REPORT_PACKET_SIZE) // 还可以接收数据
      {
        UART_RxBuff[UART_RX_STA++] = UART_ReceiveData(UART1); // UART_ReceiveData(UART2); // 记录接收到的值
      }
      else
      {
        UART_RX_STA |= 0x8000; // 强制标记接收完成
      }
    }
    UART_ClearITPendingBit(UART1, UART_ICR_RX);
  }

  if (RESET != (UART1->ISR & UART_ISR_RXIDLE))
  {
    UART_RX_STA |= 0x8000;

    UART1->ICR = UART_ICR_RXIDLE;
  }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  UART send byte.
/// @note   None.
/// @param  buf:buffer address.
/// @param  len:data length.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART_SendGroup(u8 *buf, u16 len)
{
  while (len--)
  {
    UART_SendData(UART1, *buf++);

    while (RESET == UART_GetFlagStatus(UART1, UART_FLAG_TXEPT))
    {
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
