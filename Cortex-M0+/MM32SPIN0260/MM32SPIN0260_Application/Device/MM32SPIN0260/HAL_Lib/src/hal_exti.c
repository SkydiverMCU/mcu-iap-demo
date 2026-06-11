/***********************************************************************************************************************
    @file     hal_exti.c
    @author   FD TEAM
    @brief    THIS FILE PROVIDES ALL THE EXTI FIRMWARE FUNCTIONS.
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
#define _HAL_EXTI_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_exti.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup EXTI
  * @{
  */

/** @defgroup EXTI_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the EXTI peripheral registers to their default reset values.
  * @param  None
  * @retval None
  */
void EXTI_DeInit(void)
{
    EXTI->IMR = 0x00000000;
    EXTI->EMR = 0x00000000;
    EXTI->RTSR = 0x00000000;
    EXTI->FTSR = 0x00000000;
    EXTI->PR = 0x01FFFFFF;
    EXTI->DFLTEN = 0x00000000;
    EXTI->DFLTMUX = 0x00000000;
    EXTI->DFLTW = 0x00000000;
}

/**
  * @brief  Initializes the EXTI peripheral according to the specified
  *         parameters in the init_struct.
  * @param  init_struct: pointer to a EXTI_InitTypeDef structure that
  *         contains the configuration information for the EXTI peripheral.
  * @retval None.
  */
void EXTI_Init(EXTI_InitTypeDef *init_struct)
{
    if (init_struct->EXTI_LineCmd != DISABLE)
    {
        EXTI->IMR  &= ~init_struct->EXTI_Line;
        EXTI->EMR  &= ~init_struct->EXTI_Line;

        if (init_struct->EXTI_Mode == EXTI_Mode_Interrupt)
        {
            EXTI->IMR |= init_struct->EXTI_Line;
        }
        else
        {
            EXTI->EMR |= init_struct->EXTI_Line;
        }

        EXTI->RTSR &= ~init_struct->EXTI_Line;
        EXTI->FTSR &= ~init_struct->EXTI_Line;

        if (init_struct->EXTI_Trigger == EXTI_Trigger_Rising_Falling)
        {
            EXTI->RTSR |= init_struct->EXTI_Line;
            EXTI->FTSR |= init_struct->EXTI_Line; /* Rising and Faling    afio */
        }
        else if (init_struct->EXTI_Trigger == EXTI_Trigger_Rising)
        {
            EXTI->RTSR |= init_struct->EXTI_Line;
        }
        else
        {
            EXTI->FTSR |= init_struct->EXTI_Line;
        }
    }
    else
    {
        if (init_struct->EXTI_Mode == EXTI_Mode_Interrupt)
        {
            EXTI->IMR &= ~init_struct->EXTI_Line;
        }
        else
        {
            EXTI->EMR &= ~init_struct->EXTI_Line;
        }
    }
}

/**
  * @brief  Fills each init_struct member with its reset value.
  * @param  init_struct: pointer to a EXTI_InitTypeDef structure which will
  *         be initialized.
  * @retval None.
  */
void EXTI_StructInit(EXTI_InitTypeDef *init_struct)
{
    init_struct->EXTI_Line    = EXTI_LineNone;
    init_struct->EXTI_Mode    = EXTI_Mode_Interrupt;
    init_struct->EXTI_Trigger = EXTI_Trigger_Falling;
    init_struct->EXTI_LineCmd = DISABLE;
}

/**
  * @brief  Generates a Software interrupt on selected EXTI line.
  * @param  line: specifies the EXTI line on which the software interrupt
  *         will be generated.
  * @retval None.
  */
void EXTI_GenerateSWInterrupt(uint32_t line)
{
    EXTI->SWIER |= line;
}

/**
  * @brief  Checks whether the specified EXTI line flag is set or not.
  * @param  line: specifies the EXTI line flag to check.
  * @retval The new state of line (SET or RESET).
  */
FlagStatus EXTI_GetFlagStatus(uint32_t line)
{
    return ((EXTI->PR & line) ? SET : RESET);
}

/**
  * @brief  Clears the EXTI's line pending flags.
  * @param  line: specifies the EXTI lines flags to clear.
  * @retval None.
  */
void EXTI_ClearFlag(uint32_t line)
{
    EXTI->PR = line;
}

/**
  * @brief  Checks whether the specified EXTI line is asserted or not.
  * @param  line: specifies the EXTI line to check.
  * @retval The new state of line (SET or RESET).
  */
ITStatus EXTI_GetITStatus(uint32_t line)
{
    return (((EXTI->PR & line) && (EXTI->IMR & line)) ? SET : RESET);
}

/**
  * @brief  Clears the EXTI's line pending bits.
  * @param  line: specifies the EXTI lines to clear.
  * @retval None.
  */
void EXTI_ClearITPendingBit(uint32_t line)
{
    EXTI->PR = line;
}

/**
  * @brief  Filter clock pre-frequency division setting.
  * @param  prescaler: Pre-frequency division coefficient.
  *     @arg   EXTI_FLT_Prescaler_1
  *     @arg   EXTI_FLT_Prescaler_2
  *     @arg   EXTI_FLT_Prescaler_4
  *     @arg   EXTI_FLT_Prescaler_8
  *     @arg   EXTI_FLT_Prescaler_16
  * @retval None.
  */
void EXTI_FilterClkConfig(uint32_t prescaler)
{
    MODIFY_REG(EXTI->DFLTEN, EXTI_DFLTEN_FILTER_PRE_Msk, prescaler);
}

/**
  * @brief  Filter window configuration. 
  * @param  filter_x:  Choose which filter to use.
  *     @arg   EXTI_FLT_0
  *     @arg   EXTI_FLT_1
  * @param  width: filter width.
  *     @arg   EXTI_FLT_Width_2
  *     @arg   EXTI_FLT_Width_4
  *     @arg   EXTI_FLT_Width_8
  *     @arg   EXTI_FLT_Width_16
  * @param  line: this parameter can be EXTI_Line0 ... EXTI_Line15.
  * @retval   None.
  */
void EXTI_FilterWindowConfig(uint8_t filter_x, uint32_t width, uint32_t line)
{
    uint8_t idx = 0;
    
    for (idx = 0; idx < 16; idx ++)
    {
        if (((line >> idx) & 0x01) == 0x01)
        {
            break;
        }
    }
    
    if (filter_x == EXTI_FLT_0)
    {
        MODIFY_REG(EXTI->DFLTW, EXTI_DFLTW_FILTER0_SEL_Msk, width <<  EXTI_DFLTW_FILTER0_SEL_Pos);
        MODIFY_REG(EXTI->DFLTMUX, EXTI_DFLTMUX_FILTER0_MUX_Msk, idx << EXTI_DFLTMUX_FILTER0_MUX_Pos);
    }
    else if (filter_x == EXTI_FLT_1)
    {
        MODIFY_REG(EXTI->DFLTW, EXTI_DFLTW_FILTER1_SEL_Msk, width <<  EXTI_DFLTW_FILTER1_SEL_Pos);
        MODIFY_REG(EXTI->DFLTMUX, EXTI_DFLTMUX_FILTER1_MUX_Msk, idx << EXTI_DFLTMUX_FILTER1_MUX_Pos);
    }    
}

/**
  * @brief  Enables or disables the EXTI Filter.
  * @note   Please do not use the digital filtering function in low-power mode.
  * @param  filter_x:  Choose which filter to use.
  *     @arg   EXTI_FLT_0
  *     @arg   EXTI_FLT_1
  * @param  state: new state of the adc peripheral.
  * @retval None.
  */
void EXTI_FilterCmd(uint8_t filter_x, FunctionalState state)
{
    (state) ?                             \
    (EXTI->DFLTEN |=  (0x01U << filter_x)) : \
    (EXTI->DFLTEN &= ~(0x01U << filter_x));
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
