/***********************************************************************************************************************
    @file    uart_receiveridleframe_interrupt.c
    @author  FAE Team
    @date    28-Feb-2023
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
 * @addtogroup MM32L0130_LibSamples
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
 * @brief
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void UART_Configure(uint32_t Baudrate)
{
#if 0
    
    GPIO_InitTypeDef GPIO_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    UART_InitTypeDef UART_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART1, ENABLE);

    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.BaudRate      = Baudrate;
    UART_InitStruct.WordLength    = UART_WordLength_8b;
    UART_InitStruct.StopBits      = UART_StopBits_1;
    UART_InitStruct.Parity        = UART_Parity_No;
    UART_InitStruct.HWFlowControl = UART_HWFlowControl_None;
    UART_InitStruct.Mode          = UART_Mode_Rx | UART_Mode_Tx;
    UART_Init(UART1, &UART_InitStruct);

    UART_ITConfig(UART1, UART_IT_RX, ENABLE);
    UART_ITConfig(UART1, UART_IT_RXIDLE, ENABLE);

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = UART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPriority = 0x01;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    UART_Cmd(UART1, ENABLE);

#else

  RCC->APB2ENR |= RCC_APB2Periph_UART1;

  RCC->APB2RSTR |= RCC_APB2RSTR_UART1_Pos;
  RCC->APB2RSTR &= ~RCC_APB2RSTR_UART1_Pos;

  /* UART CCR Configuration */
  MODIFY_REG(UART1->CCR, UART_CCR_CHAR_Msk, UART_WordLength_8b);

  MODIFY_REG(UART1->CCR, (UART_CCR_SPB0_Msk | UART_CCR_SPB1_Msk), UART_StopBits_1);

  MODIFY_REG(UART1->CCR, (UART_CCR_PEN_Msk | UART_CCR_PSEL_Msk), UART_Parity_No);

  /* UART GCR Configuration */
  MODIFY_REG(UART1->GCR, (UART_GCR_TXEN_Msk | UART_GCR_RXEN_Msk), UART_Mode_Rx | UART_Mode_Tx);
  MODIFY_REG(UART1->GCR, UART_GCR_AUTOFLOWEN_Msk, UART_HWFlowControl_None);

  /* UART BRR Configuration */
  /* Configure the UART Baud Rate */

  /* Determine the UART_baud */
  UART1->BRR = (SystemCoreClock / Baudrate) / 16;
  UART1->FRA = (SystemCoreClock / Baudrate) % 16;

  UART1->IER |= (UART_IT_RX | UART_IT_RXIDLE);

  NVIC_SetPriority(UART1_IRQn, 1);
  NVIC_EnableIRQ(UART1_IRQn);

  RCC->AHBENR |= RCC_AHBPeriph_GPIOA;

  /* Config PA9 AF1 */
  MODIFY_REG(GPIOA->AFRH, GPIO_AFRH_AFR9_Msk, 0x01U << GPIO_AFRH_AFR9_Pos);

  /* Config PA9 Alternate Function Output Push-Pull */
  MODIFY_REG(GPIOA->CRH, GPIO_CRH_MODE9_Msk, 0x01U << GPIO_CRH_MODE9_Pos);
  MODIFY_REG(GPIOA->CRH, GPIO_CRH_CNF9_Msk, 0x02U << GPIO_CRH_CNF9_Pos);

  /* Config PA10 AF1 */
  MODIFY_REG(GPIOA->AFRH, GPIO_AFRH_AFR10_Msk, 0x01U << GPIO_AFRH_AFR10_Pos);

  /* Config PA10 Input Pull-Up/Pull-Down Mode */
  MODIFY_REG(GPIOA->CRH, GPIO_CRH_MODE10_Msk, 0x00U << GPIO_CRH_MODE10_Pos);
  MODIFY_REG(GPIOA->CRH, GPIO_CRH_CNF10_Msk, 0x02U << GPIO_CRH_CNF10_Pos);

  UART1->GCR |= (0x01U << UART_GCR_UARTEN_Pos); // enable uart1

#endif
}

/***********************************************************************************************************************
 * @brief
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void UART_SendGroup(uint8_t *pBuff, uint16_t length)
{
  while (length--)
  {
    UART1->TDR = (uint8_t)*pBuff;

    while ((UART1->CSR & UART_FLAG_TXEPT) == 0)
    {
    }
    pBuff++;
  }
}

/***********************************************************************************************************************
 * @brief  This function handles UART1 Handler
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void UART1_IRQHandler(void)
{
  if (UART1->ISR & UART_IT_RX) // (SET == UART_GetITStatus(UART1, UART_IT_RX))
  {
    if ((UART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
    {
      if (UART_RX_STA < REPORT_PACKET_SIZE) // 还可以接收数据
      {
        UART_RxBuff[UART_RX_STA++] = UART1->RDR; // UART_ReceiveData(UART1); // 记录接收到的值
      }
      else
      {
        UART_RX_STA |= 0x8000; // 强制标记接收完成
      }
    }

    UART1->ICR = UART_IT_RX; // UART_ClearITPendingBit(UART1, UART_IT_RX);
  }

  if (UART1->ISR & UART_IT_RXIDLE) // (SET == UART_GetITStatus(UART1, UART_IT_RXIDLE))
  {
    UART1->ICR = UART_IT_RXIDLE; // UART_ClearITPendingBit(UART1, UART_IT_RXIDLE);

    UART_RX_STA |= 0x8000;
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
