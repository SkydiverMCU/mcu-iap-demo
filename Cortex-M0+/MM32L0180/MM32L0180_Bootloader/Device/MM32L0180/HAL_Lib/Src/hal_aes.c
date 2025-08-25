/***********************************************************************************************************************
    @file     hal_aes.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE ADC FIRMWARE FUNCTIONS.
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
#define _HAL_AES_C_

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_aes.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup AES
  * @{
  */

/** @defgroup AES_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup AES_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes AES peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void AES_DeInit(void)
{
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_AES, ENABLE);
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_AES, DISABLE);
}

/**
  * @brief  Initializes the AES peripheral according to the specified parameters
  * @note   If AES is already enabled, use AES_Cmd(DISABLE) before setting the new
  *         configuration (When AES is enabled, setting configuration is forbidden).
  * @param  init_struct: pointer to an AES_InitTypeDef structure that contains
  *         the configuration information for AES peripheral.
  * @retval None
  */
void AES_Init(AES_InitTypeDef *init_struct)
{
    MODIFY_REG(AES->CNTRL, (AES_CNTRL_ENCRYPT_Msk |                             \
                            AES_CNTRL_KEY_MODE_Msk |                             \
                            AES_CNTRL_MODE_Msk |                                \
                            AES_CNTRL_KEY_SEL_Msk |                              \
                            AES_CNTRL_IV_SEL_Msk), (init_struct->AES_Operation | \
                                                   init_struct->AES_KeyMode |   \
                                                   init_struct->AES_Chaining |  \
                                                   init_struct->AES_KeySel |    \
                                                   init_struct->AES_IvSel));
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to a AES_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void AES_StructInit(AES_InitTypeDef *init_struct)
{
    init_struct->AES_Operation = AES_Operation_Decryp;
    init_struct->AES_KeyMode   = AES_KeyMode_Normal;
    init_struct->AES_Chaining  = AES_Chaining_ECB;
    init_struct->AES_KeySel    = AES_KeySel_Normal;
    init_struct->AES_IvSel     = AES_IvSel_Normal;
}

/**
  * @brief  Enable or disable the AES peripheral.
  * @param  state: new state of the AES peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @note   The key must be written while AES is disabled.
  * @retval None
  */
void AES_Cmd(FunctionalState state)
{
    (state) ?                                       \
    (AES->CNTRL |= (0x1U << AES_CNTRL_START_Pos)) : \
    (AES->CNTRL &= ~(0x1U << AES_CNTRL_START_Pos));
}

/**
  * @brief  Enable or disable the AES 256-bits key.
  * @param  state: new state of the AES 256-bits key.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void AES_256BitsKeyCmd(FunctionalState state)
{
    (state) ?                                        \
    (AES->CNTRL |= (0x1U << AES_CNTRL_KEY256_Pos)) : \
    (AES->CNTRL &= ~(0x1U << AES_CNTRL_KEY256_Pos));
}

/**
  * @brief  Enable or disable the AES DMA access.
  * @param  state: new state of the AES DMA access.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void AES_DMAAccessCmd(FunctionalState state)
{
    (state) ?                                       \
    (AES->CNTRL |= (0x1U << AES_CNTRL_DMA_EN_Pos)) : \
    (AES->CNTRL &= ~(0x1U << AES_CNTRL_DMA_EN_Pos));
}

/**
  * @brief  Write data in DATA register to be processed by AES peripheral.
  * @param  Data: The data to be processed.
  * @retval None
  */
void AES_WriteData(uint32_t Data)
{
    AES->DATA = Data;
}

/**
  * @brief  Returns the data in DATA register processed by AES peripheral.
  * @retval The processed data.
  */
uint32_t AES_ReadData(void)
{
    return (AES->DATA);
}

/**
  * @brief  Enables or disables the specified AES interrupt.
  * @param  it: Specifies the AES interrupt source to enable/disable.
  *         This parameter can be any combinations of the following values:
  *     @arg AES_IT_DIN 
  *     @arg AES_IT_DOUT
  * @param  state: The new state of the AES interrupt source.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void AES_ITConfig(uint32_t it, FunctionalState state)
{
    (state) ?            \
    (AES->CNTRL |= it) : \
    (AES->CNTRL &= ~it);
}

/**
  * @brief  Checks whether the specified AES flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    AES_FLAG_OPTRDY
  * @arg    AES_FLAG_DIN   
  * @arg    AES_FLAG_DOUT  
  * @retval FlagStatus (SET or RESET)
  */
FlagStatus AES_GetFlagStatus(uint32_t flag)
{
    return ((AES->STATUS & flag) ? SET : RESET);
}

/**
  * @brief  Clears the AES flags.
  * @param  flag: specifies the flag to clear.
  *         This parameter can be:
  * @arg    AES_FLAG_DIN   
  * @arg    AES_FLAG_DOUT
  * @retval None
  */
void AES_ClearFlag(uint32_t flag)
{
    AES->STATUS = flag;
}

/**
  * @brief  Checks whether the specified AES interrupt has occurred or not.
  * @param  it: Specifies the AES interrupt pending bit to check.
  *         This parameter can be:
  *     @arg AES_IT_DIN 
  *     @arg AES_IT_DOUT
  * @retval ITStatus The new state of AES interrupt (SET or RESET).
  */
ITStatus AES_GetITStatus(uint32_t it)
{
    ITStatus itstatus = RESET;

    if ((AES->CNTRL & AES_CNTRL_DOUT_INT_EN_Msk) && (it == AES_IT_DOUT))
    {
        itstatus = ((AES->STATUS & AES_STATUS_DOUT_INT_Msk) ? SET : RESET);
    }

    if ((AES->CNTRL & AES_CNTRL_DIN_INT_EN_Msk) && (it == AES_IT_DIN))
    {
        itstatus = ((AES->STATUS & AES_STATUS_DIN_INT_Msk) ? SET : RESET);
    }

    return (itstatus);
}

/**
  * @brief  Clears the AES's interrupt pending bits.
  * @param  it: specifies the interrupt pending bit to clear.
  *   This parameter can be any combinations of the following values:
  *     @arg AES_IT_DIN 
  *     @arg AES_IT_DOUT
  * @retval None
  */
void AES_ClearITPendingBit(uint32_t it)
{
    AES->STATUS = (it >> 9);
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

