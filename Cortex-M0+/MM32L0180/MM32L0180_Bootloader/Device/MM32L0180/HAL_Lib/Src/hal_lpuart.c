/***********************************************************************************************************************
    @file     hal_lpuart.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE LPUART FIRMWARE FUNCTIONS.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#define _HAL_LPUART_C_

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_lpuart.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup LPUART
  * @{
  */

/** @defgroup LPUART_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup LPUART_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the lpuart peripheral registers to their
  *         default reset values.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @retval None.
  */
void LPUART_DeInit(LPUART_TypeDef *lpuart)
{
    if (lpuart == LPUART1)
    {
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_LPUART1, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_LPUART1, DISABLE);
    }
    else if (lpuart == LPUART2)
    {
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_LPUART2, ENABLE);
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_LPUART2, DISABLE);
    }
    else if (lpuart == LPUART3)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_LPUART3, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_LPUART3, DISABLE);
    }
    else if (lpuart == LPUART4)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_LPUART4, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_LPUART4, DISABLE);
    }
    else if (lpuart == LPUART5)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_LPUART5, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_LPUART5, DISABLE);
    }
}

/**
  * @brief  Initializes the lpuart peripheral according to the specified
  *         parameters in the LPUART_InitStruct .
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  init_struct: pointer to a LPUART_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified LPUART peripheral.
  * @retval None.
  */
void LPUART_Init(LPUART_TypeDef *lpuart, LPUART_InitTypeDef *init_struct)
{
    if (lpuart == LPUART1)
    {
        MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPUART1CLKSEL_Msk, init_struct->LPUART_ClockSource);
    }
    else if (lpuart == LPUART2)
    {
        MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPUART2CLKSEL_Msk, (init_struct->LPUART_ClockSource << 2));
    }
    else if (lpuart == LPUART3)
    {
        MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPUART3CLKSEL_Msk, (init_struct->LPUART_ClockSource << 4));
    }
    else if (lpuart == LPUART4)
    {
        MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPUART4CLKSEL_Msk, (init_struct->LPUART_ClockSource << 6));
    }
    else if (lpuart == LPUART5)
    {
        MODIFY_REG(RCC->CFGR2, RCC_CFGR2_LPUART5CLKSEL_Msk, (init_struct->LPUART_ClockSource << 8));
    }
    
    MODIFY_REG(lpuart->BAUD, LPUART_BAUD_BAUD_Msk, init_struct->LPUART_BaudRate);
    MODIFY_REG(lpuart->MODU, LPUART_MODU_MCTL_Msk, init_struct->LPUART_MODU);

    MODIFY_REG( lpuart->CR,      \
              ( LPUART_CR_DL_Msk |
                LPUART_CR_SL_Msk |
                LPUART_CR_PAREN_Msk |
                LPUART_CR_PTYP_Msk  |
                LPUART_CR_RXEV_Msk  |
                LPUART_CR_NEDET_Msk ),  \
              ( init_struct->LPUART_WordLength |
                init_struct->LPUART_StopBits   |
                init_struct->LPUART_Parity     |
                init_struct->LPUART_RecvEvent  |
                init_struct->LPUART_NEDET ) );
}

/**
  * @brief  Fills each LPUART_InitStruct member with its default value.
  * @param  init_struct: pointer to a LPUART_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void LPUART_StructInit(LPUART_InitTypeDef *init_struct)
{
    /* LPUART_InitStruct members default value */
    init_struct->LPUART_BaudRate        = LPUART_Baudrate_9600;
    init_struct->LPUART_WordLength      = LPUART_WordLength_8b;
    init_struct->LPUART_StopBits        = LPUART_StopBits_1;
    init_struct->LPUART_Parity          = LPUART_Parity_No;
    init_struct->LPUART_ClockSource     = LPUART_ClockSource_LSI;
    init_struct->LPUART_MODU            = 0x952;
    init_struct->LPUART_NEDET           = LPUART_NegativeDectect_Use;
    init_struct->LPUART_RecvEvent       = LPUART_RecvEvent_Start_Bit;
}

/**
  * @brief  Enables or disables the specified LPUART Tx and Rx.
  * @param  lpuart: Select the LPUART peripheral.
  * @param  state: new state of the lpuart peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_Cmd(LPUART_TypeDef* lpuart, FunctionalState state)
{
    (state) ?                                                                          \
    (lpuart->EN |=  ((0x01U << LPUART_EN_TXEN_Pos) | (0x01U << LPUART_EN_RXEN_Pos)) ): \
    (lpuart->EN &= ~((0x01U << LPUART_EN_TXEN_Pos) | (0x01U << LPUART_EN_RXEN_Pos)) );
}

/**
  * @brief  Enables or disables the specified LPUART Tx.
  * @param  lpuart: Select the LPUART.
  * @param  state: new state of the lpuart Tx.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_TX_Cmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                        \
    (lpuart->EN |=  (0x01U << LPUART_EN_TXEN_Pos)) : \
    (lpuart->EN &= ~(0x01U << LPUART_EN_TXEN_Pos));
}

/**
  * @brief  Enables or disables the specified LPUART Rx.
  * @param  lpuart: Select the LPUART.
  * @param  state: new state of the lpuart Rx.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_RX_Cmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                        \
    (lpuart->EN |=  (0x01U << LPUART_EN_RXEN_Pos)) : \
    (lpuart->EN &= ~(0x01U << LPUART_EN_RXEN_Pos));
}

/**
  * @brief  Enables or disables the specified LPUART interrupts.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  it: specifies the LPUART interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    LPUART_IT_ERR : Error interrupt Enable
  * @arg    LPUART_IT_RX  : Receive interrupt Enable
  * @arg    LPUART_IT_TC  : Transmit complete interrupt Enable
  * @arg    LPUART_IT_TX  : Transmit Buffer Empty interrupt Enable
  * @param  state: new state of the specified lpuart interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_ITConfig(LPUART_TypeDef *lpuart, uint32_t it, FunctionalState state)
{
    (state) ?             \
    (lpuart->CR |=  it) : \
    (lpuart->CR &= ~it);
}

/**
  * @brief  Enables or disables the LPUART DMA interface.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_DMACmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                                                          \
    (lpuart->EN |=  ((0x01U << LPUART_EN_DMAT_Pos) | (0x01U << LPUART_EN_DMAR_Pos)) ): \
    (lpuart->EN &= ~((0x01U << LPUART_EN_DMAT_Pos) | (0x01U << LPUART_EN_DMAR_Pos)) );
}

/**
  * @brief  Enables or disables the LPUART DMA Tx interface.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_TX_DMACmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                        \
    (lpuart->EN |=  (0x01U << LPUART_EN_DMAT_Pos)) : \
    (lpuart->EN &= ~(0x01U << LPUART_EN_DMAT_Pos));
}

/**
  * @brief  Enables or disables the LPUART DMA Rx interface.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of the DMA Request sources.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void LPUART_RX_DMACmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                        \
    (lpuart->EN |=  (0x01U << LPUART_EN_DMAR_Pos)) : \
    (lpuart->EN &= ~(0x01U << LPUART_EN_DMAR_Pos));
}

/**
  * @brief  Transmits single data through the lpuart peripheral.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  value: the data to transmit.
  * @retval None.
  */
void LPUART_SendData(LPUART_TypeDef *lpuart, uint8_t value)
{
    lpuart->TXD = (value & 0xFFU);
}

/**
  * @brief  Returns the most recent received data by the lpuart peripheral.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @retval  The received data.
  */
uint8_t LPUART_ReceiveData(LPUART_TypeDef *lpuart)
{
    return ((uint8_t)(lpuart->RXD & 0xFFU));
}

/**
  * @brief  Checks whether the specified LPUART flag is set or not.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    LPUART_FLAG_START : Start bit detected flag
  * @arg    LPUART_FLAG_PERR  : Check bit error flag
  * @arg    LPUART_FLAG_TC    : Transmit data completed flag
  * @arg    LPUART_FLAG_TXE   : Transmit buffer empty flag
  * @arg    LPUART_FLAG_RXF   : Receive buffer is fulled flag
  * @arg    LPUART_FLAG_MATCH : Data is matched flag
  * @arg    LPUART_FLAG_FERR  : Frame format error flag
  * @arg    LPUART_FLAG_RXOV  : Receive buffer overflow flag
  * @retval The new state of LPUART_FLAG (SET or RESET).
  */
FlagStatus LPUART_GetFlagStatus(LPUART_TypeDef *lpuart, uint32_t flag)
{
    return ((lpuart->SR & flag) ? SET : RESET);
}

/**
  * @brief  Clear the specified LPUART status flag.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    LPUART_FLAG_START : Start bit detected flag
  * @arg    LPUART_FLAG_PERR  : Check bit error flag
  * @arg    LPUART_FLAG_MATCH : Data is matched flag
  * @arg    LPUART_FLAG_FERR  : Frame format error flag
  * @arg    LPUART_FLAG_RXOV  : Receive buffer overflow flag
  * @retval The new state of LPUART_FLAG (SET or RESET).
  */
void LPUART_ClearFlagStatus(LPUART_TypeDef *lpuart, uint32_t flag)
{
    lpuart->SR = flag;
}

/**
  * @brief  Checks whether the specified LPUART interrupt has occurred or not.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  it: specifies the LPUART interrupt source to check.
  *         This parameter can be one of the following values:
  * @arg    LPUART_IT_TC     : Transmit complete interrupt complete flag
  * @arg    LPUART_IT_RXNEG  : Received falling edge interrupt flag
  * @arg    LPUART_IT_TX     : Transmit buffer empty interrupt flag
  * @arg    LPUART_IT_RX     : Receive data finish interrupt flag
  * @retval  The new state of LPUART_IT (SET or RESET).
  */
ITStatus LPUART_GetITStatus(LPUART_TypeDef *lpuart, uint32_t it)
{
    ITStatus ret = RESET;
    
    if (LPUART_IT_TX == it)
    {
        ret = ((lpuart->IFR & LPUART_IFR_TXIF_Msk) ? SET : RESET);
    }
    else
    {
        ret = ((lpuart->IFR & it) ? SET : RESET);
    }

    return (ret);
}

/**
  * @brief  Clears the lpuart interrupt pending bits.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  it: specifies the interrupt pending bit to clear.
  *         This parameter can be one of the following values:
  * @arg    LPUART_IT_TC     : Transmit complete interrupt complete flag
  * @arg    LPUART_IT_RXNEG  : Received falling edge interrupt flag
  * @arg    LPUART_IT_TX     : Transmit buffer empty interrupt flag
  * @arg    LPUART_IT_RX     : Receive data finish interrupt flag
  * @retval None.
  */
void LPUART_ClearITPendingBit(LPUART_TypeDef *lpuart, uint32_t it)
{
    if (LPUART_IT_TX == it)
    {
       lpuart->IFR = (0x01U << LPUART_IFR_TXIF_Pos);
    }
    else
    {
        lpuart->IFR = it;
    }
}

/**
  * @brief  Selects the LPUART WakeUp method.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  mode: specifies the LPUART wakeup method.
  * @arg    LPUART_WakeUp_ByData
  * @arg    LPUART_WakeUp_ByMatch
  * @retval None.
  */
void LPUART_WakeUpConfig(LPUART_TypeDef *lpuart, uint32_t mode)
{
    MODIFY_REG(lpuart->WKCKE, LPUART_WKCKE_LPUART_WKCKE_Msk, mode);
}

/**
  * @brief  Set LPUART  TX polarity
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of TX polarity.
  * @retval None.
  */
void LPUART_TXToggleCmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                         \
    (lpuart->CR |=  (0x01U << LPUART_CR_TXPOL_Pos)) : \
    (lpuart->CR &= ~(0x01U << LPUART_CR_TXPOL_Pos));
}

/**
  * @brief  Set LPUART  RX polarity
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  state: new state of RX polarity.
  * @retval None.
  */
void LPUART_RXToggleCmd(LPUART_TypeDef *lpuart, FunctionalState state)
{
    (state) ?                                         \
    (lpuart->CR |=  (0x01U << LPUART_CR_RXPOL_Pos)) : \
    (lpuart->CR &= ~(0x01U << LPUART_CR_RXPOL_Pos));
}

/**
  * @brief  Set match compare data through the lpuart peripheral.
  * @param  lpuart: Select the LPUART or the LPUART peripheral.
  * @param  value: the data to be compared.
  * @retval None.
  */
void LPUART_SetMatchData(LPUART_TypeDef *lpuart, uint8_t value)
{
    lpuart->COMPARE = (value & 0xFFU);
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
