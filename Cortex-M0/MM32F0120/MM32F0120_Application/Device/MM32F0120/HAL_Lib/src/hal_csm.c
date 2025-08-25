/***********************************************************************************************************************
    @file     hal_csm.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE CSM FIRMWARE FUNCTIONS.
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


/* Includes ------------------------------------------------------------------*/
#include "hal_csm.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup CSM
  * @{
  */

/** @defgroup CSM_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup CSM_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the CSM peripheral registers to their default reset values.
  * @param  None.
  * @retval None.
  */
void CSM_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_CSM, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_CSM, DISABLE);
}

/**
  * @brief  Fills CSM init_struct  member with its default value.
  * @param init_struct: pointer to a CSM_InitTypeDef structure which will be initialized.
  * @retval : None
  */
void CSM_StructInit(CSM_InitTypeDef* init_struct)
{
    init_struct->CSM_Channel = CSM_Channel_1;
    init_struct->CSM_InputSource = CSM_InputSource_COMP;
    init_struct->CSM_DataDir = CSM_DataDir_Recv;
    init_struct->CSM_IdleLevel = CSM_IdleLevel_Low;
    init_struct->CSM_BaudRate = 1000;
    init_struct->CSM_MaxBit = 100;
    init_struct->CSM_StopSel = CSM_StopSel_UntilLength;
    init_struct->CSM_StarSel = CSM_StarSel_NoDetect;
}

/**
  * @brief  Initializes the CSM peripheral according to the specified parameters in the CSM_InitStruct.
  * @param  None.
  * @retval None.
  */
void CSM_Init(CSM_InitTypeDef* init_struct)
{
    uint32_t apbclock = 0x00;
    RCC_ClocksTypeDef RCC_ClocksStatus;

    if(init_struct->CSM_Channel == CSM_Channel_1)
    {
        MODIFY_REG( CSM->CR1, \
                  ( CSM_CR1_TXSEL1_Msk |
                    CSM_CR1_IDLEP1_Msk),  \
                  ( init_struct->CSM_DataDir |
                    init_struct->CSM_IdleLevel ) );

        RCC_GetClocksFreq(&RCC_ClocksStatus);
        apbclock = RCC_ClocksStatus.PCLK1_Frequency;
        CSM->SPBRG = (apbclock / init_struct->CSM_BaudRate) - 1;

        MODIFY_REG( CSM->CFG, \
                  ( CSM_CFG_MAXBIT_Msk |
                    CSM_CFG_STOPSEL_Msk |
                    CSM_CFG_STARTSEL_Msk
                    ),  \
                  ( init_struct->CSM_MaxBit |
                    init_struct->CSM_StopSel |
                    init_struct->CSM_StarSel ) );

    }
    else if(init_struct->CSM_Channel == CSM_Channel_2)
    {

    }
}

/**
  * @brief  Enables or disables the specified CSM peripheral channel.
  * @param channel: CSM_Channel_1 or CSM_Channel_2
  * @param state: new state of the CSM channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void CSM_Cmd(uint8_t channel, FunctionalState state)
{
    if(channel == CSM_Channel_1)
    {
        (state) ? \
        (CSM->CR1 |=  (1 << CSM_CR1_EN1_Pos)): \
        (CSM->CR1 &= ~(1 << CSM_CR1_EN1_Pos));
    }
    else if(channel == CSM_Channel_2)
    {

    }
}

/**
  * @brief  Enables or disables the CSM peripheral channel DMA interface.
  * @param channel: CSM_Channel_1 or CSM_Channel_2
  * @param state: new state of the CSM channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void CSM_DMACmd(uint8_t channel, FunctionalState state)
{
    if(channel == CSM_Channel_1)
    {
        (state) ? \
        (CSM->CR1 |=  (1 << CSM_CR1_DMAEN1_Pos)): \
        (CSM->CR1 &= ~(1 << CSM_CR1_DMAEN1_Pos));
    }
    else if(channel == CSM_Channel_2)
    {

    }
}

/**
  * @brief  Enables or disables the CSM peripheral channel votage divider circuit.
  * @param state: new state of the CSM channel.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void CSM_VoltageDivCmd(FunctionalState state)
{
    (state) ? \
    (CSM->CFG |=  (1 << CSM_CFG_VTXEN_Pos)): \
    (CSM->CFG &= ~(1 << CSM_CFG_VTXEN_Pos));
}

/**
  * @brief  Transmits  data through the CSMx peripheral channel.
  * @param channel: CSM_Channel_1 or CSM_Channel_2
  * @param Data: the data to transmit.
  * @retval : None
  */
void CSM_SendData(uint8_t channel, uint32_t data)
{
    if(channel == CSM_Channel_1)
    {
        CSM->TDR1 = data;
    }
    else if(channel == CSM_Channel_2)
    {

    }
}

/**
  * @brief  Returns the  received data by the CSM peripheral channel.
  * @param channel: CSM_Channel_1 or CSM_Channel_2
  * @retval : The received data.
  */
uint32_t CSM_ReceiveData(uint8_t channel)
{
    uint32_t ret = 0;

    if(channel == CSM_Channel_1)
    {
         ret = CSM->RDR1;
    }
    else if(channel == CSM_Channel_2)
    {

    }

    return ret;
}


/**
  * @brief  Enables or disables the CSM interrupts.
  * @param csm_it: specifies the CSM interrupt sources to be enabled or disabled.
  *   This parameter can be one of the following values:
  * @arg  CSM_IT_STOP
  * @arg  CSM_IT_START
  * @arg  CSM_IT_TXC
  * @arg  CSM_IT_RX
  * @arg  CSM_IT_TX
  * @param state: new state of the CSM interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void CSM_ITConfig(uint32_t csm_it, FunctionalState state)
{
    (state) ? \
    (CSM->IER |=  csm_it): \
    (CSM->IER &= ~csm_it); 
}

/**
  * @brief  Checks whether the specified CSM interrupt has occurred or not.
  * @param csm_it:
  *   This parameter can be one of the following values:
  * @arg  CSM_IT_STOP
  * @arg  CSM_IT_START
  * @arg  CSM_IT_TXC
  * @arg  CSM_IT_RX
  * @arg  CSM_IT_TX
  * @retval : The new state of csm_it (SET or RESET).
  */
ITStatus CSM_GetITStatus(uint32_t csm_it)
{
    return ((CSM->ISR & csm_it) ? SET : RESET);
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
