/***********************************************************************************************************************
    @file     hal_csm.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE CSM FIRMWARE LIBRARY.
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HAL_CSM_H
#define __HAL_CSM_H

/* Includes ------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup CSM
  * @{
  */

/** @defgroup CSM_Exported_Types
  * @{
  */

/**
  * @brief  CSM Init Structure definition
  */

typedef struct
{
    uint32_t CSM_Channel;
    uint32_t CSM_InputSource;
    uint32_t CSM_DataDir;
    uint32_t CSM_IdleLevel;
    uint32_t CSM_BaudRate;
    uint32_t CSM_MaxBit;
    uint32_t CSM_StopSel;
    uint32_t CSM_StarSel;
} CSM_InitTypeDef;

/**
  * @}
  */

/** @defgroup CSM_Exported_Constants
  * @{
  */

/**
  * @brief CSM_Channel
  */
#define CSM_Channel_1                     (0x00)
#define CSM_Channel_2                     (0x01)

/**
  * @brief CSM_DataDir
  */
#define CSM_DataDir_Send                  (0x01U << CSM_CR1_TXSEL1_Pos)
#define CSM_DataDir_Recv                  (0x00U << CSM_CR1_TXSEL1_Pos)

/**
  * @brief CSM_InputSource
  */
#define CSM_InputSource_COMP              1

/**
  * @brief CSM_IdleLevel
  */
#define CSM_IdleLevel_High              (0x01U << CSM_CR1_IDLEP1_Pos)
#define CSM_IdleLevel_Low               (0x00U << CSM_CR1_IDLEP1_Pos)

/**
  * @brief CSM_StopSel
  */
#define CSM_StopSel_UntilLength          (0x01U << CSM_CFG_STOPSEL_Pos)
#define CSM_StopSel_UntilIdle            (0x00U << CSM_CFG_STOPSEL_Pos)

/**
  * @brief CSM_StarSel
  */
#define CSM_StarSel_NoDetect            (0x01U << CSM_CFG_STARTSEL_Pos)
#define CSM_StarSel_Detect              (0x00U << CSM_CFG_STARTSEL_Pos)

/**
  * @brief CSM Interrupt definition
  */
#define CSM_IT_STOP            (0x01U << CSM_IER_STOP_IEN_Pos)
#define CSM_IT_START           (0x01U << CSM_IER_START_IEN_Pos)
#define CSM_IT_TXC             (0x01U << CSM_IER_TXC_IEN_Pos)
#define CSM_IT_RX              (0x01U << CSM_IER_RX_IEN_Pos)
#define CSM_IT_TX              (0x01U << CSM_IER_TX_IEN_Pos)

/**
  * @}
  */

/** @defgroup CSM_Exported_Functions
  * @{
  */

void CSM_DeInit(void);
void CSM_StructInit(CSM_InitTypeDef* init_struct);
void CSM_Init(CSM_InitTypeDef* init_struct);
void CSM_Cmd(uint8_t channel, FunctionalState state);
void CSM_DMACmd(uint8_t channel, FunctionalState state);
void CSM_VoltageDivCmd(FunctionalState state);
void CSM_SendData(uint8_t channel, uint32_t data);
uint32_t CSM_ReceiveData(uint8_t channel);
void CSM_ITConfig(uint32_t csm_it, FunctionalState state);
ITStatus CSM_GetITStatus(uint32_t csm_it);

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
