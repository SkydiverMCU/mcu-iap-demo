/***********************************************************************************************************************
    @file     hal_aes.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE ADC FIRMWARE LIBRARY.
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
#ifndef __HAL_AES_H
#define __HAL_AES_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup AES
  * @{
  */

/** @defgroup AES_Exported_Types
  * @{
  */



/** @defgroup ADC_Exported_Constants
  * @{
  */

/**
  * @brief   AES Init structure definition
  */
typedef struct
{
    uint32_t AES_Operation;     /*!< Specifies the AES mode of operation. */
    uint32_t AES_KeyMode;       /*!< Specifies the AES Key mode. */
    uint32_t AES_Chaining;      /*!< Specifies the AES Chaining modes: ECB, CBC. */
    uint32_t AES_KeySel;        /*!< Specifies the AES Key storage mode. */
    uint32_t AES_IvSel;         /*!< Specifies the AES initial value storage mode. */
} AES_InitTypeDef;

/**
  * @}
  */

/** @defgroup AES_Exported_Constants
  * @{
  */
/** @defgroup AES operation mode
  * @{
  */  
#define AES_Operation_Decryp        (0x00U << AES_CNTRL_ENCRYPT_Pos) /*!< AES in Decryption mode */
#define AES_Operation_Encryp        (0x01U << AES_CNTRL_ENCRYPT_Pos) /*!< AES in Encryption mode */

/** @defgroup AES key mode
  * @{
  */  
#define AES_KeyMode_Normal          (0x00U << AES_CNTRL_KEY_MODE_Pos) /*!< AES in Key normal mode */
#define AES_KeyMode_Inversion       (0x01U << AES_CNTRL_KEY_MODE_Pos) /*!< AES in Key inversion mode */

/** @defgroup AES chaining mode
  * @{
  */ 
#define AES_Chaining_ECB        (0x00U << AES_CNTRL_MODE_Pos) /*!< AES in ECB chaining mode */
#define AES_Chaining_CBC        (0x01U << AES_CNTRL_MODE_Pos) /*!< AES in CBC chaining mode */

/** @defgroup AES key sel
  * @{
  */ 
#define AES_KeySel_Normal        (0x00U << AES_CNTRL_KEY_SEL_Pos)
#define AES_KeySel_Internal      (0x01U << AES_CNTRL_KEY_SEL_Pos)

/** @defgroup AES iv sel
  * @{
  */ 
#define AES_IvSel_Normal        (0x00U << AES_CNTRL_IV_SEL_Pos) 
#define AES_IvSel_Internal      (0x01U << AES_CNTRL_IV_SEL_Pos) 

/** @defgroup AES flag
  * @{
  */ 
#define AES_FLAG_OPTRDY          (0x1U << AES_STATUS_OPT_RDY_Pos)  
#define AES_FLAG_DIN             (0x1U << AES_STATUS_DIN_INT_Pos)
#define AES_FLAG_DOUT            (0x1U << AES_STATUS_DOUT_INT_Pos)

/** @defgroup AES interrupt
  * @{
  */ 
#define AES_IT_DIN              (0x01U << AES_CNTRL_DIN_INT_EN_Pos) 
#define AES_IT_DOUT             (0x01U << AES_CNTRL_DOUT_INT_EN_Pos)

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions
  * @{
  */
void AES_DeInit(void);
void AES_Init(AES_InitTypeDef *init_struct);
void AES_StructInit(AES_InitTypeDef *init_struct);
void AES_Cmd(FunctionalState state);
void AES_256BitsKeyCmd(FunctionalState state);
void AES_DMAAccessCmd(FunctionalState state);
void AES_WriteData(uint32_t Data);
uint32_t AES_ReadData(void);
void AES_ITConfig(uint32_t it, FunctionalState state);
FlagStatus AES_GetFlagStatus(uint32_t flag);
void AES_ClearFlag(uint32_t flag);
ITStatus AES_GetITStatus(uint32_t it);
void AES_ClearITPendingBit(uint32_t it);

#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
