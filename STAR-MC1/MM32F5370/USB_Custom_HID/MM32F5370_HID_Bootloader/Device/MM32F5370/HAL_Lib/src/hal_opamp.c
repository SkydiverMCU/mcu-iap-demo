/***********************************************************************************************************************
    @file     hal_opamp.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE OPAMP FIRMWARE FUNCTIONS.
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
#define _HAL_OPAMP_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_opamp.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup OPAMP
  * @{
  */

/** @defgroup OPAMP_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @addtogroup OPAMP_Private_Functions
  * @{
  */

/**
  * @brief Deinitializes the OPAMPx peripheral registers to their default reset values.
  * @param opamp: Select the OPAMP peripheral.
  * @retval : None
  */
void OPAMP_DeInit(uint8_t opamp_x)
{
    OPAMP->OPA1CR = 0x00000000;
    OPAMP->OPA1CHSR = 0x00000000;
    OPAMP->OPA2CR = 0x00000000;
    OPAMP->OPA2CHSR = 0x00000000;
    OPAMP->OPA3CR = 0x00000000;
    OPAMP->OPA3CHSR = 0x00000000;
    OPAMP->OPA4CR = 0x00000000;
    OPAMP->OPA4CHSR = 0x00000000;
}

/**
  * @brief Initializes the OPAMPx peripheral according to the specified
  *   parameters in the OPAMP_InitStruct .
  * @param opamp: Select the OPAMP peripheral.
  * @param init_struct: pointer to a OPAMP_InitTypeDef structure
  *   that contains the configuration information for the specified OPAMP peripheral.
  * @retval : None
  */
void OPAMP_Init(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CHSR, OPAMP_OPACHSR_MSEL_Msk | OPAMP_OPACHSR_PSEL_Msk, init_struct->OPAMP_InvertingInput | init_struct->OPAMP_NonInvertingInput);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CHSR, OPAMP_OPACHSR_MSEL_Msk | OPAMP_OPACHSR_PSEL_Msk, init_struct->OPAMP_InvertingInput | init_struct->OPAMP_NonInvertingInput);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CHSR, OPAMP_OPACHSR_MSEL_Msk | OPAMP_OPACHSR_PSEL_Msk, init_struct->OPAMP_InvertingInput | init_struct->OPAMP_NonInvertingInput);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CHSR, OPAMP_OPACHSR_MSEL_Msk | OPAMP_OPACHSR_PSEL_Msk, init_struct->OPAMP_InvertingInput | init_struct->OPAMP_NonInvertingInput);
    }    
}

/**
  * @brief OPAMP_StructInit.
  * @param init_struct: pointer to a OPAMP_InitTypeDef structure
  *   that contains the configuration information for the
  *   specified OPAMP peripheral.
  * @retval : None
  */
void OPAMP_StructInit(OPAMP_InitTypeDef* init_struct)
{
    /* OPAMP_InitStruct members default value */
    init_struct->OPAMP_InvertingInput = OPAMP_InvertingInput_IO0;
    init_struct->OPAMP_NonInvertingInput = OPAMP_NonInvertingInput_IO0;
}

/**
  * @brief Enables or disables the specified OPAMP peripheral.
  * @param opamp: Select the OPAMP peripheral.
  * @param state: new state of the OPAMP peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void OPAMP_Cmd(uint8_t opamp_x, FunctionalState state)
{
    if(opamp_x == OPAMP1)
    {
        (state) ?                                  \
        (OPAMP->OPA1CR |= (0x01U << OPAMP_OPACR_OPAEN_Pos)) : \
        (OPAMP->OPA1CR &= ~(0x01U << OPAMP_OPACR_OPAEN_Pos));
    }
    else if(opamp_x == OPAMP2)
    {
        (state) ?                                  \
        (OPAMP->OPA2CR |= (0x01U << OPAMP_OPACR_OPAEN_Pos)) : \
        (OPAMP->OPA2CR &= ~(0x01U << OPAMP_OPACR_OPAEN_Pos));
    }    
    else if(opamp_x == OPAMP3)
    {
        (state) ?                                  \
        (OPAMP->OPA3CR |= (0x01U << OPAMP_OPACR_OPAEN_Pos)) : \
        (OPAMP->OPA3CR &= ~(0x01U << OPAMP_OPACR_OPAEN_Pos));
    }    
    else if(opamp_x == OPAMP4)
    {
        (state) ?                                  \
        (OPAMP->OPA4CR |= (0x01U << OPAMP_OPACR_OPAEN_Pos)) : \
        (OPAMP->OPA4CR &= ~(0x01U << OPAMP_OPACR_OPAEN_Pos));
    } 
}

/**
  * @brief Configures the OPAMP gain coefficient.
  * @param opamp: Select the OPAMP peripheral.
  * @param gain: the OPAMP gain coefficient.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_Gain_2 
  * @arg    OPAMP_Gain_4 
  * @arg    OPAMP_Gain_8 
  * @arg    OPAMP_Gain_16
  * @arg    OPAMP_Gain_32
  * @arg    OPAMP_Gain_64
  * @arg    OPAMP_Gain_1 
  * @arg    OPAMP_Gain_3 
  * @arg    OPAMP_Gain_7 
  * @arg    OPAMP_Gain_15
  * @arg    OPAMP_Gain_31
  * @arg    OPAMP_Gain_63
  * @retval : None
  */
void OPAMP_GainConfig(uint8_t opamp_x, uint32_t gain)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CR, OPAMP_OPACR_GAIN_Msk, gain);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CR, OPAMP_OPACR_GAIN_Msk, gain);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CR, OPAMP_OPACR_GAIN_Msk, gain);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CR, OPAMP_OPACR_GAIN_Msk, gain);
    } 
}

/**
  * @brief Enables or disables the TIM Channel Switch.
  * @param opamp: Select the OPAMP peripheral.
  * @param state: new state of the OPAMP peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void OPAMP_TIMCSCmd(uint8_t opamp_x, FunctionalState state)
{
    if(opamp_x == OPAMP1)
    {
        (state) ?                                    \
        (OPAMP->OPA1CR |= (0x01U << OPAMP_OPACR_TIMCSEN_Pos)) : \
        (OPAMP->OPA1CR &= ~(0x01U << OPAMP_OPACR_TIMCSEN_Pos));
    }
    else if(opamp_x == OPAMP2)
    {
        (state) ?                                    \
        (OPAMP->OPA2CR |= (0x01U << OPAMP_OPACR_TIMCSEN_Pos)) : \
        (OPAMP->OPA2CR &= ~(0x01U << OPAMP_OPACR_TIMCSEN_Pos));
    }    
    else if(opamp_x == OPAMP3)
    {
        (state) ?                                    \
        (OPAMP->OPA3CR |= (0x01U << OPAMP_OPACR_TIMCSEN_Pos)) : \
        (OPAMP->OPA3CR &= ~(0x01U << OPAMP_OPACR_TIMCSEN_Pos));
    }    
    else if(opamp_x == OPAMP4)
    {
        (state) ?                                    \
        (OPAMP->OPA4CR |= (0x01U << OPAMP_OPACR_TIMCSEN_Pos)) : \
        (OPAMP->OPA4CR &= ~(0x01U << OPAMP_OPACR_TIMCSEN_Pos));
    } 
}

/**
  * @brief Configures the TIM channel switch edge.
  * @param opamp: Select the OPAMP peripheral.
  * @param cssel: specifies the TIM channel switch edge.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_TIMCSEdge_Mode0
  * @arg    OPAMP_TIMCSEdge_Mode1
  * @retval None
  */
void OPAMP_TIMCSConfig(uint8_t opamp_x, uint32_t cssel)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CR, OPAMP_OPACR_TIMCSEG_Msk, cssel);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CR, OPAMP_OPACR_TIMCSEG_Msk, cssel);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CR, OPAMP_OPACR_TIMCSEG_Msk, cssel);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CR, OPAMP_OPACR_TIMCSEG_Msk, cssel);
    } 
}

/**
  * @brief Enables or disables the OPAMP Filter Mode.
  * @param opamp: Select the OPAMP peripheral.
  * @param state: new state of the OPAMP Filter Mode.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval : None
  */
void OPAMP_FilterCmd(uint8_t opamp_x, FunctionalState state)
{
    if(opamp_x == OPAMP1)
    {
        (state) ?                                  \
        (OPAMP->OPA1CR |= (0x01U << OPAMP_OPACR_FLTEN_Pos)) : \
        (OPAMP->OPA1CR &= ~(0x01U << OPAMP_OPACR_FLTEN_Pos));
    }
    else if(opamp_x == OPAMP2)
    {
        (state) ?                                  \
        (OPAMP->OPA2CR |= (0x01U << OPAMP_OPACR_FLTEN_Pos)) : \
        (OPAMP->OPA2CR &= ~(0x01U << OPAMP_OPACR_FLTEN_Pos));
    }    
    else if(opamp_x == OPAMP3)
    {
        (state) ?                                  \
        (OPAMP->OPA3CR |= (0x01U << OPAMP_OPACR_FLTEN_Pos)) : \
        (OPAMP->OPA3CR &= ~(0x01U << OPAMP_OPACR_FLTEN_Pos));
    }    
    else if(opamp_x == OPAMP4)
    {
        (state) ?                                  \
        (OPAMP->OPA4CR |= (0x01U << OPAMP_OPACR_FLTEN_Pos)) : \
        (OPAMP->OPA4CR &= ~(0x01U << OPAMP_OPACR_FLTEN_Pos));
    } 
}

/**
  * @brief Configures the OPAMP difference input channel.
  * @param opamp: Select the OPAMP peripheral.
  * @param dm: M channel difference input select.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_DMInput_FLOAT 
  * @arg    OPAMP_DMInput_AGND
  * @arg    OPAMP_DMInput_INM0       
  * @retval : None
  */
void OPAMP_DMMuxConfig(uint8_t opamp_x, uint32_t dm)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CR, OPAMP_OPACR_DMMUXSEL_Msk, dm);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CR, OPAMP_OPACR_DMMUXSEL_Msk, dm);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CR, OPAMP_OPACR_DMMUXSEL_Msk, dm);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CR, OPAMP_OPACR_DMMUXSEL_Msk, dm);
    }    
}

/**
  * @brief Configures the OPAMP difference input channel.
  * @param opamp: Select the OPAMP peripheral.
  * @param dp: P channel difference input select.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_DPInput_FLOAT
  * @arg    OPAMP_DPInput_INP0    
  * @arg    OPAMP_DPInput_INP1    
  * @retval : None
  */
void OPAMP_DPMuxConfig(uint8_t opamp_x, uint32_t dp)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CR, OPAMP_OPACR_DPMUXSEL_Msk, dp);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CR, OPAMP_OPACR_DPMUXSEL_Msk, dp);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CR, OPAMP_OPACR_DPMUXSEL_Msk, dp);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CR, OPAMP_OPACR_DPMUXSEL_Msk, dp);
    }  
}

/**
  * @brief Configures the OPAMP M sub channel.
  * @param opamp: Select the OPAMP peripheral.
  * @param dms: M sub channel select.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_SubInvertingInput_IO0 
  * @arg    OPAMP_SubInvertingInput_IO1 
  * @arg    OPAMP_SubInvertingInput_IO2 
  * @arg    OPAMP_SubInvertingInput_IO3 
  * @arg    OPAMP_SubInvertingInput_IO4 
  * @arg    OPAMP_SubInvertingInput_IO5 
  * @arg    OPAMP_SubInvertingInput_VREF
  * @retval : None
  */
void OPAMP_MSubChannelConfig(uint8_t opamp_x, uint32_t dms)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CHSR, OPAMP_OPACHSR_MSSEL_Msk, dms);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CHSR, OPAMP_OPACHSR_MSSEL_Msk, dms);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CHSR, OPAMP_OPACHSR_MSSEL_Msk, dms);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CHSR, OPAMP_OPACHSR_MSSEL_Msk, dms);
    }  
}

/**
  * @brief Configures the OPAMP P sub channel.
  * @param opamp: Select the OPAMP peripheral.
  * @param dps: P sub channel select.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_SubNonInvertingInput_IO0 
  * @arg    OPAMP_SubNonInvertingInput_IO1 
  * @arg    OPAMP_SubNonInvertingInput_IO2 
  * @arg    OPAMP_SubNonInvertingInput_IO3 
  * @arg    OPAMP_SubNonInvertingInput_IO4 
  * @arg    OPAMP_SubNonInvertingInput_IO5 
  * @arg    OPAMP_SubNonInvertingInput_DAC 
  * @arg    OPAMP_SubNonInvertingInput_VREF
  * @retval : None
  */
void OPAMP_PSubChannelConfig(uint8_t opamp_x, uint32_t dps)
{
    if(opamp_x == OPAMP1)
    {
        MODIFY_REG(OPAMP->OPA1CHSR, OPAMP_OPACHSR_PSSEL_Msk, dps);
    }
    else if(opamp_x == OPAMP2)
    {
        MODIFY_REG(OPAMP->OPA2CHSR, OPAMP_OPACHSR_PSSEL_Msk, dps);
    }    
    else if(opamp_x == OPAMP3)
    {
        MODIFY_REG(OPAMP->OPA3CHSR, OPAMP_OPACHSR_PSSEL_Msk, dps);
    }    
    else if(opamp_x == OPAMP4)
    {
        MODIFY_REG(OPAMP->OPA4CHSR, OPAMP_OPACHSR_PSSEL_Msk, dps);
    }  
}

/**
  * @brief Initializes the OPAMP buffer mode.
  * @param opamp: Select the OPAMP peripheral.
  * @param init_struct: pointer to a OPAMP_InitTypeDef structure
  *   that contains the configuration information for the specified OPAMP peripheral.
  * @retval : None
  */
void OPAMP_BufferInit(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct)
{
    init_struct->OPAMP_InvertingInput = OPAMP_InvertingInput_VOUT;
    OPAMP_Init(opamp_x, init_struct);
    OPAMP_DMMuxConfig(opamp_x, OPAMP_DMInput_FLOAT);
}

/**
  * @brief Initializes the OPAMP noninverting mode.
  * @param opamp: Select the OPAMP peripheral.
  * @param init_struct: pointer to a OPAMP_InitTypeDef structure
  * @param gain: the OPAMP gain coefficient.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_Gain_2 
  * @arg    OPAMP_Gain_4 
  * @arg    OPAMP_Gain_8 
  * @arg    OPAMP_Gain_16
  * @arg    OPAMP_Gain_32
  * @arg    OPAMP_Gain_64
  * @retval : None
  */
void OPAMP_NoninvertInit(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct, uint32_t gain)
{
    init_struct->OPAMP_InvertingInput = OPAMP_InvertingInput_VREF;
    OPAMP_Init(opamp_x, init_struct);
    OPAMP_DMMuxConfig(opamp_x, OPAMP_DMInput_AGND);
    OPAMP_GainConfig(opamp_x, gain);
}

/**
  * @brief Initializes the OPAMP inverting mode.
  * @param opamp: Select the OPAMP peripheral.
  * @param init_struct: pointer to a OPAMP_InitTypeDef structure.
  * @param gain: the OPAMP gain coefficient.
  *   This parameter can be one of the following values:
  * @arg    OPAMP_Gain_1 
  * @arg    OPAMP_Gain_3 
  * @arg    OPAMP_Gain_7 
  * @arg    OPAMP_Gain_15
  * @arg    OPAMP_Gain_31
  * @arg    OPAMP_Gain_63
  * @retval : None
  */
void OPAMP_InvertInit(uint8_t opamp_x, OPAMP_InitTypeDef* init_struct, uint32_t gain)
{
    init_struct->OPAMP_InvertingInput = OPAMP_InvertingInput_VREF;
    OPAMP_Init(opamp_x, init_struct);
    OPAMP_DMMuxConfig(opamp_x, OPAMP_DMInput_INM0);
    OPAMP_GainConfig(opamp_x, gain);
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
