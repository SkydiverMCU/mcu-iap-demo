/***********************************************************************************************************************
    @file     hal_codic.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE CORDIC FIRMWARE LIBRARY.
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
#ifndef __HAL_CORDIC_H
#define __HAL_CORDIC_H


/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup CORDIC
  * @{
  */

/** @defgroup CORDIC_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup CORDIC_Exported_Constants
  * @{
  */

/**
  * @brief  Write a value in CORDIC->DXR register
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define CORDIC_WriteDXR(__VALUE__) ((CORDIC->DX) = (__VALUE__))

/**
  * @brief  Read a value in CORDIC->DXR register
  * @retval Register value
  */
#define CORDIC_ReadDXR()           (CORDIC->DX)

/**
  * @brief  Write a value in CORDIC->DYR register
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define CORDIC_WriteDYR(__VALUE__) ((CORDIC->DY) = (__VALUE__))

/**
  * @brief  Read a value in CORDIC->DYR register
  * @retval Register value
  */
#define CORDIC_ReadDYR()           (CORDIC->DY)

/**
  * @brief  Write a value in CORDIC->DZR register
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define CORDIC_WriteDZR(__VALUE__) ((CORDIC->DZ) = (__VALUE__))

/**
  * @brief  Read a value in CORDIC->DZR register
  * @retval Register value
  */
#define CORDIC_ReadDZR()           (CORDIC->DZ)

/**
  * @brief  Read a value in CORDIC->RXR register
  * @retval Register value
  */
#define CORDIC_ReadRXR()           (CORDIC->RX)

/**
  * @brief  Read a value in CORDIC->RYR register
  * @retval Register value
  */
#define CORDIC_ReadRYR()           (CORDIC->RY)

/**
  * @brief  Read a value in CORDIC->RZR register
  * @retval Register value
  */
#define CORDIC_ReadRZR()           (CORDIC->RZ)

/**
  * @brief CORDIC work mode configuration
  */
#define CORDIC_WorkMode_Vector              (0x00U << CORDIC_CTRL_WORK_MODE_Pos)
#define CORDIC_WorkMode_Rotation            (0x01U << CORDIC_CTRL_WORK_MODE_Pos)

/**
  * @brief CORDIC start mode configuration
  */
#define CORDIC_StartMode_AfterDXWrite       (0x00U << CORDIC_CTRL_START_MODE_Pos)
#define CORDIC_StartMode_StartBitSet        (0x01U << CORDIC_CTRL_START_MODE_Pos)

/**
  * @}
  */

/** @defgroup CORDIC_Exported_Functions
  * @{
  */
void CORDIC_DeInit(void);
void CORDIC_Start(void);
void CORDIC_SetWorkMode(uint32_t mode);
void CORDIC_SetStartMode(uint32_t mode);
void CORDIC_Cmd(FunctionalState state);
FlagStatus CORDIC_GetBusyStatus(void);

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
