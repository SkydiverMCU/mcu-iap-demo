/***********************************************************************************************************************
    @file     hal_syscfg.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE SYSCFG FIRMWARE FUNCTIONS.
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
#include "hal_syscfg.h"

/** @addtogroup MM32_StdPeriph_Driver
* @{
*/

/** @defgroup SYSCFG
* @{
*/

/** @defgroup SYSCFG_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCFG_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup SYSCFG_Private_Functions
* @{
*/

/**
* @brief  Deinitializes the SYSCFG registers to their default reset values.
* @param  None
* @retval None
*/
void SYSCFG_DeInit(void)
{
    /* Set SYSCFG_CFGR1 register to reset value without affecting MEM_MODE bits */
    SYSCFG->CFGR &= SYSCFG_CFGR_MEM_MODE_Msk;
    /* Set EXTICRx registers to reset value */
    SYSCFG->EXTICR1 = 0;
    SYSCFG->EXTICR2 = 0;
    SYSCFG->EXTICR3 = 0;
    SYSCFG->EXTICR4 = 0;
}

/**
* @brief  Configures the memory mapping at address 0x00000000.
* @param  SYSCFG_MemoryRemap: selects the memory remapping.
*          This parameter can be one of the following values:
*            @arg SYSCFG_MemoryRemap_Flash: Main Flash memory mapped at 0x00000000
*            @arg SYSCFG_MemoryRemap_SystemMemory: System Flash memory mapped at 0x00000000
*            @arg SYSCFG_MemoryRemap_SRAM: Embedded SRAM mapped at 0x00000000
* @retval None
*/
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap)
{
    MODIFY_REG(SYSCFG->CFGR, SYSCFG_CFGR_MEM_MODE_Msk, SYSCFG_MemoryRemap);
}

/**
  * @brief  Selects the GPIO pin used as EXTI Line.
  * @param  port_source_gpio: EXTI_PortSourceGPIOx .
  * @param  pin_source: EXTI_PinSourcex.
  * @retval None.
  */
void SYSCFG_EXTILineConfig(uint8_t port_source_gpio, uint8_t pin_source)
{
    uint32_t tmp = 0x00;

    tmp = ((uint32_t)0x0F) << (0x04 * (pin_source & (uint8_t)0x03));

    if ((pin_source >> 0x02) == 0)
    {
        SYSCFG->EXTICR1 &= ~tmp;
        SYSCFG->EXTICR1 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
    else if ((pin_source >> 0x02) == 1)
    {
        SYSCFG->EXTICR2 &= ~tmp;
        SYSCFG->EXTICR2 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
    else if ((pin_source >> 0x02) == 2)
    {
        SYSCFG->EXTICR3 &= ~tmp;
        SYSCFG->EXTICR3 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
    else if ((pin_source >> 0x02) == 3)
    {
        SYSCFG->EXTICR4 &= ~tmp;
        SYSCFG->EXTICR4 |= (((uint32_t)port_source_gpio) << (0x04 * (pin_source & (uint8_t)0x03)));
    }
}


/**
  * @brief  Configure the DMA channel remapping function
  *         corresponding to the peripheral.
  * @param  perip_dma: Select the module that you want to remap.
  *         This parameter can be one of the following values:
  * @arg    SYSCFG_TIM17_TRIG_RMP_DMA_CH2
  * @arg    SYSCFG_TIM17_TRIG_RMP_DMA_CH3
  * @arg    SYSCFG_TIM16_TRIG_RMP_DMA_CH1
  * @arg    SYSCFG_TIM16_TRIG_RMP_DMA_CH2
  * @arg    SYSCFG_TIM1_CH3_RMP_DMA_CH1  
  * @arg    SYSCFG_TIM1_CH3_RMP_DMA_CH3  
  * @arg    SYSCFG_CSM_RMP_DMA_CH1       
  * @arg    SYSCFG_CSM_RMP_DMA_CH3       
  * @arg    SYSCFG_USART3_TX_RMP_DMA_CH1 
  * @arg    SYSCFG_USART3_TX_RMP_DMA_CH2 
  * @arg    SYSCFG_USART2_RX_RMP_DMA_CH2 
  * @arg    SYSCFG_USART2_RX_RMP_DMA_CH3 
  * @arg    SYSCFG_USART1_TX_RMP_DMA_CH1 
  * @arg    SYSCFG_USART1_TX_RMP_DMA_CH3 
  * @arg    SYSCFG_ADC_RMP_DMA_CH1       
  * @arg    SYSCFG_ADC_RMP_DMA_CH2       
  * @retval None.
  */
void SYSCFG_DMARemapConfig(uint8_t perip_dma)
{
    uint32_t tmp_vale, tmp_msk;
    uint8_t tmp_pos;

    tmp_pos  = (perip_dma & 0x1F);
    tmp_vale = (perip_dma >> 5) << tmp_pos;

    if (tmp_pos == 0x02)
    {
        tmp_msk = 0x03 << tmp_pos;
    }
    else
    {
        tmp_msk = 0x01 << tmp_pos;
    }

    MODIFY_REG(SYSCFG->CFGR, tmp_msk, tmp_vale);
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
