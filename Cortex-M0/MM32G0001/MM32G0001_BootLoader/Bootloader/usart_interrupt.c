/***********************************************************************************************************************
    @file    usart_interrupt.c
    @author  FAE Team
    @date    14-Nov-2023
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
extern uint32_t SystemCoreClock;
/***********************************************************************************************************************
 * @brief
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void USART_Configure(uint32_t Baudrate)
{

#if 0
  
  GPIO_InitTypeDef GPIO_InitStruct;
  NVIC_InitTypeDef NVIC_InitStruct;
  USART_InitTypeDef USART_InitStruct;

  NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPriority = 0x01;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);

  RCC_AHBPeriphClockCmd(RCC_AHBPERIPH_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPERIPH_GPIOB, ENABLE);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_2);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_2);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOB, &GPIO_InitStruct);

  RCC_APB1PeriphClockCmd(RCC_APB1ENR_USART2, ENABLE);

  USART_StructInit(&USART_InitStruct);
  USART_InitStruct.USART_BaudRate = Baudrate;
  USART_InitStruct.USART_WordLength = USART_WordLength_8b;
  USART_InitStruct.USART_StopBits = USART_StopBits_1;
  USART_InitStruct.USART_Parity = USART_Parity_No;
  USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART2, &USART_InitStruct);

  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
  USART_ITConfig(USART2, USART_IT_PE, ENABLE);
  USART_ITConfig(USART2, USART_IT_ERR, ENABLE);

  USART_Cmd(USART2, ENABLE);

#else

  /* Enable GPIOA Clock */
  SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOA);

  /* Config PA1 AF2 */
  MODIFY_REG(GPIOA->AFRL, GPIO_AFRL_AFR1, 0x02U << GPIO_AFRL_AFR1_Pos);

  /* Config PA1 Alternate Function Output Push-Pull */
  MODIFY_REG(GPIOA->CRL, GPIO_CRL_MODE1, 0x01U << GPIO_CRL_MODE1_Pos);
  MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF1, 0x02U << GPIO_CRL_CNF1_Pos);

  /* Enable GPIOB Clock */
  SET_BIT(RCC->AHBENR, RCC_AHBENR_GPIOB);

  /* Config PB1 AF2 */
  MODIFY_REG(GPIOB->AFRL, GPIO_AFRL_AFR1, 0x02U << GPIO_AFRL_AFR1_Pos);

  /* Config PB1 Input Pull-Up/Pull-Down Mode */
  MODIFY_REG(GPIOB->CRL, GPIO_CRL_MODE1, 0x00U << GPIO_CRL_MODE1_Pos);
  MODIFY_REG(GPIOB->CRL, GPIO_CRL_CNF1, 0x02U << GPIO_CRL_CNF1_Pos);
  /* Pull-Up */
  WRITE_REG(GPIOB->BSRR, GPIO_BSRR_BS1);

  /* Enable USART2 Clock */
  SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2);

  /* Parity : None */
  CLEAR_BIT(USART2->CR1, USART_CR1_PCE);
  CLEAR_BIT(USART2->CR1, USART_CR1_PS);

  /* Data Length : 8-bit */
  CLEAR_BIT(USART2->CR1, USART_CR1_DL);

  /* Stop Bit : 1-bit */
  MODIFY_REG(USART2->CR2, USART_CR2_STOP, 0x00U << USART_CR2_STOP_Pos);

  /* Baudrate */
  MODIFY_REG(USART2->BRR, USART_BRR_MFD, ((SystemCoreClock / Baudrate) / 16) << USART_BRR_MFD_Pos);
  MODIFY_REG(USART2->BRR, USART_BRR_FFD, ((SystemCoreClock / Baudrate) % 16) << USART_BRR_FFD_Pos);

  /* Enable Transmit And Receive */
  SET_BIT(USART2->CR1, USART_CR1_TE | USART_CR1_RE);

  /* Enable PE Interrupt */
  SET_BIT(USART2->CR1, USART_CR1_PEIEN);

  /* Enable Error(FE/ORE/NF) Interrupt */
  SET_BIT(USART2->CR3, USART_CR3_ERRIEN);

  /* Enable RXNE Interrupt */
  SET_BIT(USART2->CR1, USART_CR1_RXNEIEN);

  NVIC_SetPriority(USART2_IRQn, 1);
  NVIC_EnableIRQ(USART2_IRQn);

  /* Enable USART2 */
  SET_BIT(USART2->CR1, USART_CR1_UE);

#endif
}

/***********************************************************************************************************************
 * @brief  This function handles USART2 Handler
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void USART2_IRQHandler(void)
{
  uint8_t RxData = 0;

  if (READ_BIT(USART2->SR, USART_SR_PE) || READ_BIT(USART2->SR, USART_SR_FE) ||
      READ_BIT(USART2->SR, USART_SR_NF) || READ_BIT(USART2->SR, USART_SR_ORE))
  {
    READ_REG(USART2->DR);
  }



  if (READ_BIT(USART2->SR, USART_SR_RXNE))
  {
    RxData = ((uint8_t)(USART2->DR & (uint16_t)0x01FF)); // USART_ReceiveData(USART2);

    if (0 == READ_BIT(USART2->CR1, USART_CR1_IDLEIEN))
    {
      /* Enable IDLE Interrupt */
      SET_BIT(USART2->CR1, USART_CR1_IDLEIEN);
    }

    if ((USART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
    {
      if (USART_RX_STA < UART_REC_LEN) // 还可以接收数据
      {
        USART_RxBuff[USART_RX_STA++] = RxData; // 记录接收到的值
      }
      else
      {
        USART_RX_STA |= 0x8000; // 强制标记接收完成
      }
    }
  }
  
  if (READ_BIT(USART2->SR, USART_SR_IDLE))
  {
    /* Disable IDLE Interrupt */
    CLEAR_BIT(USART2->CR1, USART_CR1_IDLEIEN);
    READ_REG(USART2->DR);

    USART_RX_STA |= 0x8000;
  }  
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
    USART_SendData(USART2, (uint8_t)*pBuff);

    while (RESET == USART_GetFlagStatus(USART2, USART_FLAG_TC))
    {
    }
    pBuff++;
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
