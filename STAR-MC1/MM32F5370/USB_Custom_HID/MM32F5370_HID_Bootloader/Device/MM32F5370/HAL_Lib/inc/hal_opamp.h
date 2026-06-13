/***********************************************************************************************************************
    @file     hal_opamp.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE OPAMP FIRMWARE LIBRARY.
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
#ifndef __HAL_OPAMP_H
#define __HAL_OPAMP_H

/* Files includes ------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup OPAMP
  * @{
  */

/** @defgroup OPAMP_Exported_Types
  * @{
  */
/**
  * @brief  OPAMP Init structure definition
  */
typedef struct
{
    uint32_t OPAMP_InvertingInput;     /*!< Selects the inverting input of the operational amplifier. */
    uint32_t OPAMP_NonInvertingInput;  /*!< Selects the non inverting input of the operational amplifier. */
} OPAMP_InitTypeDef;

/**
  * @}
  */

/** @defgroup OPAMP_Exported_Constants
  * @{
  */

/**
  * @brief  Select the OPAMPx
  */
#define OPAMP1       0x01
#define OPAMP2       0x02
#define OPAMP3       0x03
#define OPAMP4       0x04

/**
  * @brief OPAMP_InvertingInput
  */
#define OPAMP_InvertingInput_IO0            (0x00U << OPAMP_OPACHSR_MSEL_Pos)     /*!< INM0 as OPAMP inverting input */
#define OPAMP_InvertingInput_IO1            (0x01U << OPAMP_OPACHSR_MSEL_Pos)     /*!< INM1 as OPAMP inverting input */
#define OPAMP_InvertingInput_IO2            (0x02U << OPAMP_OPACHSR_MSEL_Pos)     /*!< INM2 as OPAMP inverting input */
#define OPAMP_InvertingInput_IO3            (0x03U << OPAMP_OPACHSR_MSEL_Pos)     /*!< INM3 as OPAMP inverting input */
#define OPAMP_InvertingInput_IO4            (0x04U << OPAMP_OPACHSR_MSEL_Pos)     /*!< INM4 as OPAMP inverting input */
#define OPAMP_InvertingInput_IO5            (0x05U << OPAMP_OPACHSR_MSEL_Pos)     /*!< INM5 as OPAMP inverting input */
#define OPAMP_InvertingInput_VREF           (0x06U << OPAMP_OPACHSR_MSEL_Pos)     /*!< Internal resistor partial voltage output as OPAMP inverting input */
#define OPAMP_InvertingInput_VOUT           (0x07U << OPAMP_OPACHSR_MSEL_Pos)     /*!< Internal VOUT output as OPAMP inverting input */

/**
  * @brief OPAMP_NonInvertingInput
  */
#define OPAMP_NonInvertingInput_IO0         (0x00U << OPAMP_OPACHSR_PSEL_Pos)     /*!< INP0 as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_IO1         (0x01U << OPAMP_OPACHSR_PSEL_Pos)     /*!< INP1 as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_IO2         (0x02U << OPAMP_OPACHSR_PSEL_Pos)     /*!< INP2 as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_IO3         (0x03U << OPAMP_OPACHSR_PSEL_Pos)     /*!< INP3 as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_IO4         (0x04U << OPAMP_OPACHSR_PSEL_Pos)     /*!< INP4 as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_IO5         (0x05U << OPAMP_OPACHSR_PSEL_Pos)     /*!< INP5 as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_DAC         (0x06U << OPAMP_OPACHSR_PSEL_Pos)     /*!< DAC as OPAMP non-inverting input */
#define OPAMP_NonInvertingInput_VREF        (0x07U << OPAMP_OPACHSR_PSEL_Pos)     /*!< Internal resistor partial voltage output as OPAMP non-inverting input */

/**
  * @brief OPAMP_Gain
  */
#define OPAMP_Gain_2          (0x00U << OPAMP_OPACR_GAIN_Pos)  /*!< 2x gain */
#define OPAMP_Gain_4          (0x01U << OPAMP_OPACR_GAIN_Pos)  /*!< 4x gain */
#define OPAMP_Gain_8          (0x02U << OPAMP_OPACR_GAIN_Pos)  /*!< 8x gain */
#define OPAMP_Gain_16         (0x03U << OPAMP_OPACR_GAIN_Pos)  /*!< 16x gain */
#define OPAMP_Gain_32         (0x04U << OPAMP_OPACR_GAIN_Pos)  /*!< 32x gain */
#define OPAMP_Gain_64         (0x05U << OPAMP_OPACR_GAIN_Pos)  /*!< 64x gain */
                                                       
#define OPAMP_Gain_1          (0x00U << OPAMP_OPACR_GAIN_Pos)  /*!< 1x gain */
#define OPAMP_Gain_3          (0x01U << OPAMP_OPACR_GAIN_Pos)  /*!< 3x gain */
#define OPAMP_Gain_7          (0x02U << OPAMP_OPACR_GAIN_Pos)  /*!< 7x gain */
#define OPAMP_Gain_15         (0x03U << OPAMP_OPACR_GAIN_Pos)  /*!< 15x gain */
#define OPAMP_Gain_31         (0x04U << OPAMP_OPACR_GAIN_Pos)  /*!< 31x gain */
#define OPAMP_Gain_63         (0x05U << OPAMP_OPACR_GAIN_Pos)  /*!< 63x gain */

/**
  * @brief OPAMP_DMInput
  */
#define OPAMP_DMInput_FLOAT         (0x00U << OPAMP_OPACR_DMMUXSEL_Pos)  /*!< M channel difference Input Select floating. */
#define OPAMP_DMInput_AGND          (0x01U << OPAMP_OPACR_DMMUXSEL_Pos)  /*!< M channel difference Input Select analog GND. */
#define OPAMP_DMInput_INM0          (0x02U << OPAMP_OPACR_DMMUXSEL_Pos)  /*!< M channel difference Input Select INM0 pin. */

/**
  * @brief OPAMP_DPInput
  */
#define OPAMP_DPInput_FLOAT         (0x00U << OPAMP_OPACR_DPMUXSEL_Pos)  /*!< P channel difference Input Select floating. */
#define OPAMP_DPInput_INP0          (0x01U << OPAMP_OPACR_DPMUXSEL_Pos)  /*!< P channel difference Input Select INP0 pin. */
#define OPAMP_DPInput_INP1          (0x02U << OPAMP_OPACR_DPMUXSEL_Pos)  /*!< P channel difference Input Select INP1 pin. */

/**
  * @brief OPAMP_TIMCSEdge
  */
#define OPAMP_TIMCSEdge_Mode0      (0x00U << OPAMP_OPACR_TIMCSEG_Pos)  /*!< Select the main channel when the CCR6 output is low, and select the sub channel when the CCR6 output is high.  */
#define OPAMP_TIMCSEdge_Mode1      (0x01U << OPAMP_OPACR_TIMCSEG_Pos)  /*!< Select the sub channel when the CCR6 output is low, and select the main channel when the CCR6 output is high.  */

/**
  * @brief OPAMP_SubInvertingInput
  */
#define OPAMP_SubInvertingInput_IO0            (0x00U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< INM0 as OPAMP sub inverting input */
#define OPAMP_SubInvertingInput_IO1            (0x01U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< INM1 as OPAMP sub inverting input */
#define OPAMP_SubInvertingInput_IO2            (0x02U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< INM2 as OPAMP sub inverting input */
#define OPAMP_SubInvertingInput_IO3            (0x03U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< INM3 as OPAMP sub inverting input */
#define OPAMP_SubInvertingInput_IO4            (0x04U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< INM4 as OPAMP sub inverting input */
#define OPAMP_SubInvertingInput_IO5            (0x05U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< INM5 as OPAMP sub inverting input */
#define OPAMP_SubInvertingInput_VREF           (0x07U << OPAMP_OPACHSR_MSSEL_Pos)     /*!< Internal resistor partial voltage output as OPAMP sub inverting input */

/**
  * @brief OPAMP_SubNonInvertingInput
  */
#define OPAMP_SubNonInvertingInput_IO0         (0x00U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< INP0 as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_IO1         (0x01U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< INP1 as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_IO2         (0x02U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< INP2 as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_IO3         (0x03U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< INP3 as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_IO4         (0x04U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< INP4 as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_IO5         (0x05U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< INP5 as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_DAC         (0x06U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< DAC as OPAMP sub non-inverting input */
#define OPAMP_SubNonInvertingInput_VREF        (0x07U << OPAMP_OPACHSR_PSSEL_Pos)     /*!< Internal resistor partial voltage output as OPAMP sub non-inverting input */

/**
  * @}
  */

/** @defgroup OPAMP_Exported_Functions
  * @{
  */
void OPAMP_DeInit(uint8_t opamp_x);
void OPAMP_Init(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct);
void OPAMP_StructInit(OPAMP_InitTypeDef* init_struct);
void OPAMP_Cmd(uint8_t opamp_x, FunctionalState state);
void OPAMP_GainConfig(uint8_t opamp_x, uint32_t gain);
void OPAMP_TIMCSCmd(uint8_t opamp_x, FunctionalState state);
void OPAMP_TIMCSConfig(uint8_t opamp_x, uint32_t cssel);
void OPAMP_FilterCmd(uint8_t opamp_x, FunctionalState state);
void OPAMP_DMMuxConfig(uint8_t opamp_x, uint32_t dm);
void OPAMP_DPMuxConfig(uint8_t opamp_x, uint32_t dp);
void OPAMP_MSubChannelConfig(uint8_t opamp_x, uint32_t dms);
void OPAMP_PSubChannelConfig(uint8_t opamp_x, uint32_t dps);

void OPAMP_BufferInit(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct);
void OPAMP_NoninvertInit(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct, uint32_t gain);
void OPAMP_InvertInit(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct, uint32_t gain);

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
