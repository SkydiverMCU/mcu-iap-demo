/***********************************************************************************************************************
    @file     hal_pwr.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE PWR
              FIRMWARE LIBRARY.
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
#ifndef __HAL_PWR_H
#define __HAL_PWR_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @defgroup PWR_HAL
  * @brief PWR HAL modules
  * @{
  */

/** @defgroup PWR_Exported_Types
  * @{
  */

/**
  * @brief PVD_detection_level
  */
#define PWR_PVDLevel_1V8          (0x00U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_2V1          (0x01U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_2V4          (0x02U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_2V7          (0x03U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_3V0          (0x04U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_3V3          (0x05U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_3V6          (0x06U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_3V9          (0x07U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_4V2          (0x08U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_4V5          (0x09U << PWR_CR_PLS_Pos)
#define PWR_PVDLevel_4V8          (0x0AU << PWR_CR_PLS_Pos)

/**
  * @brief Regulator_state
  */
#define PWR_Regulator_ON          (0x00U << PWR_CR_LPR_Pos)
#define PWR_Regulator_LowPower    (0x01U << PWR_CR_LPR_Pos)


/**
  * @brief SLEEP_mode_entry
  */
#define PWR_SLEEPNOW_WFI   0x00000001
#define PWR_SLEEPNOW_WFE   0x00000002
#define PWR_SLEEPONEXIT    0x00000003

/**
  * @brief STOP_mode_entry
  */
#define PWR_STOPEntry_WFI   0x00000001
#define PWR_STOPEntry_WFE   0x00000002

 
#define PWR_MODE_STOP       0x00000000
#define PWR_MODE_DEEPSTOP   0x00000001


#define PWR_FLAG_WU              (0x01U << PWR_CSR_WUF_Pos)
#define PWR_FLAG_SB              (0x01U << PWR_CSR_SBF_Pos)
#define PWR_FLAG_PVDO            (0x01U << PWR_CSR_PVDO_Pos)


/**
  * @}
  */

/** @defgroup PWR_Exported_Variables
  * @{
  */

#ifdef _HAL_PWR_C_

#define GLOBAL
#else
#define GLOBAL extern
#endif

#undef GLOBAL

/**
  * @}
  */

/** @defgroup PWR_Exported_Functions
  * @{
  */

void PWR_DeInit(void);

void PWR_PVDCmd(FunctionalState state);
void PWR_PVDLevelConfig(uint32_t pvd_level);
void PWR_WakeUpPinCmd(FunctionalState state);
void PWR_EnterSLEEPMode(uint32_t regulator, uint32_t sleep_entry);
void PWR_EnterSTOPMode(uint32_t stop_mode, uint32_t stop_entry);
void PWR_EnterSTANDBYMode(void);

void PWR_ClearFlag(uint32_t flag);
FlagStatus PWR_GetFlagStatus(uint32_t flag);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/** --------------------------------------------------------------------------*/
#endif /*__HAL_PWR_H ---------------------------------------------------------*/
/** --------------------------------------------------------------------------*/

