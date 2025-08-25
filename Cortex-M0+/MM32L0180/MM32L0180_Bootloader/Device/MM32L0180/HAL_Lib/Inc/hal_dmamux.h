/***********************************************************************************************************************
    @file     hal_dmamux.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE DMA
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
#ifndef __HAL_DMAMUX_H
#define __HAL_DMAMUX_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup DMAMUX
  * @{
  */

/** @defgroup DMAMUX_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup DMAMUX_Exported_Constants
  * @{
  */

#define DMA_ModuleMaxNumber             (0x01U)
#define DMA_ChanMaxNumber               (0x03U)

/**
  * @brief DMA_MUX_Source definition
  */
#define DMA_MUX_ADC1                   (0x00U)
#define DMA_MUX_SPI1_RX                (0x02U)
#define DMA_MUX_SPI1_TX                (0x03U)
#define DMA_MUX_LPUART5_TX             (0x08U)
#define DMA_MUX_LPUART5_RX             (0x09U)
#define DMA_MUX_USART1_TX              (0x0AU)
#define DMA_MUX_USART1_RX              (0x0BU)
#define DMA_MUX_USART2_TX              (0x0CU)
#define DMA_MUX_USART2_RX              (0x0DU)
#define DMA_MUX_LPUART1_TX             (0x0EU)
#define DMA_MUX_LPUART1_RX             (0x0FU)
#define DMA_MUX_LPUART2_TX             (0x10U)
#define DMA_MUX_LPUART2_RX             (0x11U)
#define DMA_MUX_LPUART3_TX             (0x12U)
#define DMA_MUX_LPUART3_RX             (0x13U)
#define DMA_MUX_LPUART4_TX             (0x14U)
#define DMA_MUX_LPUART4_RX             (0x15U)
#define DMA_MUX_I2C1_TX                (0x16U)
#define DMA_MUX_I2C1_RX                (0x17U)
#define DMA_MUX_TIM3_UP                (0x1AU)
#define DMA_MUX_TIM3_TRIG              (0x1BU)
#define DMA_MUX_TIM3_CH1               (0x1CU)
#define DMA_MUX_TIM3_CH2               (0x1DU)
#define DMA_MUX_TIM3_CH3               (0x1EU)
#define DMA_MUX_TIM3_CH4               (0x1FU)
#define DMA_MUX_TIM4_UP                (0x20U)
#define DMA_MUX_TIM4_TRIG              (0x21U)
#define DMA_MUX_TIM4_CH1               (0x22U)
#define DMA_MUX_TIM4_CH2               (0x23U)
#define DMA_MUX_TIM4_CH3               (0x24U)
#define DMA_MUX_TIM4_CH4               (0x25U)
#define DMA_MUX_TIM16_UP               (0x26U)
#define DMA_MUX_TIM16_CH1              (0x27U)
#define DMA_MUX_TIM17_UP               (0x28U)
#define DMA_MUX_TIM17_CH1              (0x29U)
#define DMA_MUX_SLCD_FRM               (0x30U)
#define DMA_MUX_AES_TX                 (0x31U)
#define DMA_MUX_AES_RX                 (0x32U)
#define DMA_MUX_TRNG_INT               (0x33U)


/**
  * @}
  */

/** @defgroup DMAMUX_Exported_Functions
  * @{
  */

ErrorStatus DMA_DecodeDmaIrqNumber(DMA_Channel_TypeDef *channel, IRQn_Type *get_irq_number);
void DMA_SetChannelMuxSource(DMA_Channel_TypeDef *channel, uint32_t muxvalue);
uint32_t DMA_GetChannelMuxSource(DMA_Channel_TypeDef *channel);

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
