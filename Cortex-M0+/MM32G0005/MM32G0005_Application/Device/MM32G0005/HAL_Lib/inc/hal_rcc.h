/***********************************************************************************************************************
    @file     hal_rcc.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE RCC FIRMWARE LIBRARY.
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
#ifndef __HAL_RCC_H
#define __HAL_RCC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup RCC
  * @{
  */

/** @defgroup RCC_Exported_Types
  * @{
  */
/**
  * @brief RCC clock frequency type definition
  */
typedef struct
{
    uint32_t SYSCLK_Frequency;         /*!< returns SYSCLK clock frequency. */
    uint32_t HCLK_Frequency;           /*!< returns hclk clock frequency. */
    uint32_t PCLK1_Frequency;          /*!< returns PCLK1 clock frequency. */
} RCC_ClocksTypeDef;
/**
  * @}
  */

/** @defgroup ADC_Exported_Constants
  * @{
  */

/**
  * @brief HSE configuration
  */
#define RCC_HSE_OFF       (0x00U << RCC_CR_HSEON_Pos)   /* HSE OFF */
#define RCC_HSE_ON        (0x01U << RCC_CR_HSEON_Pos)   /* HSE ON */

/**
  * @brief RCC Flag
  */
/* Flags in the CR register */
#define RCC_FLAG_HSIRDY                  ((uint8_t)((1 << 5U) | RCC_CR_HSIRDY_Pos))    /*!< Internal High Speed clock ready flag */
#define RCC_FLAG_HSERDY                  ((uint8_t)((1 << 5U) | RCC_CR_HSERDY_Pos))    /*!< External High Speed clock ready flag */

/* Flags in the CSR register */
#define RCC_FLAG_LSIRDY                  ((uint8_t)((3 << 5U) | RCC_CSR_LSIRDY_Pos))   /*!< Internal Low Speed oscillator Ready */
#define RCC_FLAG_PINRST                  ((uint8_t)((3 << 5U) | RCC_CSR_PINRSTF_Pos))  /*!< PIN reset flag */
#define RCC_FLAG_PORRST                  ((uint8_t)((3 << 5U) | RCC_CSR_PORRSTF_Pos))  /*!< POR/PDR reset flag */
#define RCC_FLAG_SFTRST                  ((uint8_t)((3 << 5U) | RCC_CSR_SFTRSTF_Pos))  /*!< Software Reset flag */
#define RCC_FLAG_IWDGRST                 ((uint8_t)((3 << 5U) | RCC_CSR_IWDGRSTF_Pos)) /*!< Independent Watchdog reset flag */

/**
  * @brief System clock source
  */
#define RCC_SYSCLKSource_HSIDIV          (0x00U << RCC_CFGR_SW_Pos)                    /* Set HSI Div12 as systemCLOCK */
#define RCC_SYSCLKSource_HSE             (0x01U << RCC_CFGR_SW_Pos)                    /* Set HSE as systemCLOCK */
#define RCC_SYSCLKSource_HSI             (0x02U << RCC_CFGR_SW_Pos)                    /* Set HSI as systemCLOCK */
#define RCC_SYSCLKSource_LSI             (0x03U << RCC_CFGR_SW_Pos)                    /* Set LSI as systemCLOCK */

/**
  * @brief AHB clock source
  */
#define RCC_SYSCLK_Div1                  (0x00U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div2                  (0x08U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div4                  (0x09U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div8                  (0x0AU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div16                 (0x0BU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div64                 (0x0CU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div128                (0x0DU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div256                (0x0EU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div512                (0x0FU << RCC_CFGR_HPRE_Pos)

/**
  * @brief APB1 clock source
  */
#define RCC_HCLK_Div1                    0x00U
#define RCC_HCLK_Div2                    0x04U
#define RCC_HCLK_Div4                    0x05U
#define RCC_HCLK_Div8                    0x06U
#define RCC_HCLK_Div16                   0x07U

/**
  * @brief RCC Interrupt source
  */
#define RCC_IT_LSIRDY                    0x01
#define RCC_IT_HSIRDY                    0x04
#define RCC_IT_HSERDY                    0x08

#define RCC_AHBPeriph_SRAM               (0x01U << RCC_AHBENR_SRAM_Pos)
#define RCC_AHBPeriph_FLASH              (0x01U << RCC_AHBENR_FLASH_Pos)
#define RCC_AHBPeriph_CRC                (0x01U << RCC_AHBENR_CRC_Pos)
#define RCC_AHBPeriph_GPIOA              (0x01U << RCC_AHBENR_GPIOA_Pos)
#define RCC_AHBPeriph_GPIOB              (0x01U << RCC_AHBENR_GPIOB_Pos)

#define RCC_APB1Periph_TIM3              (0x01U << RCC_APB1ENR_TIM3_Pos)
#define RCC_APB1Periph_TIM1              (0x01U << RCC_APB1ENR_TIM1_Pos)
#define RCC_APB1Periph_TIM14             (0x01U << RCC_APB1ENR_TIM14_Pos)
#define RCC_APB1Periph_ADC1              (0x01U << RCC_APB1ENR_ADC1_Pos)
#define RCC_APB1Periph_SPI1              (0x01U << RCC_APB1ENR_SPI1_Pos)
#define RCC_APB1Periph_USART1            (0x01U << RCC_APB1ENR_USART1_Pos)
#define RCC_APB1Periph_USART2            (0x01U << RCC_APB1ENR_USART2_Pos)
#define RCC_APB1Periph_I2C1              (0x01U << RCC_APB1ENR_I2C1_Pos)
#define RCC_APB1Periph_CPT               (0x01U << RCC_APB1ENR_CPT_Pos)
#define RCC_APB1Periph_PWR               (0x01U << RCC_APB1ENR_PWR_Pos)
#define RCC_APB1Periph_DBG               (0x01U << RCC_APB1ENR_DBG_Pos)
#define RCC_APB1Periph_SYSCFG            (0x01U << RCC_APB1ENR_SYSCFG_Pos)

/**
  * @brief Clock source to output on MCO pin
  */
#define RCC_MCO_NoClock                  (0x00U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_LSI                      (0x02U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_SYSCLK                   (0x04U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_HSI_Div4                 (0x05U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_HSE                      (0x06U << RCC_CFGR_MCO_Pos)

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions
  * @{
  */

void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t hsesource);
FlagStatus RCC_GetFlagStatus(uint8_t flag);
ErrorStatus RCC_WaitForHSEStartUp(void);

void RCC_HSICmd(FunctionalState state);
void RCC_SYSCLKConfig(uint32_t sys_clk_src);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t clk);
void RCC_PCLK1Config(uint32_t clk);
void RCC_ITConfig(uint8_t it, FunctionalState state);
ITStatus RCC_GetITStatus(uint8_t it);
void RCC_ClearITPendingBit(uint8_t it);
void RCC_LSICmd(FunctionalState state);
void RCC_GetClocksFreq(RCC_ClocksTypeDef *clk);
void RCC_AHBPeriphClockCmd(uint32_t ahb_periph, FunctionalState state);
void RCC_APB1PeriphClockCmd(uint32_t apb1_periph, FunctionalState state);
void RCC_AHBPeriphResetCmd(uint32_t ahb1_periph, FunctionalState state);
void RCC_APB1PeriphResetCmd(uint32_t apb1_periph, FunctionalState state);
void RCC_MCOConfig(uint32_t mco_src);
void RCC_ClearFlag(void);

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

