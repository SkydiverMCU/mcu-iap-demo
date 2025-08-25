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
    uint32_t SYSCLK_Frequency;          /*!< returns SYSCLK clock frequency. */
    uint32_t HCLK_Frequency;            /*!< returns hclk clock frequency. */
    uint32_t PCLK1_Frequency;           /*!< returns PCLK1 clock frequency. */
    uint32_t PCLK2_Frequency;           /*!< returns PCLK2 clock frequency. */
} RCC_ClocksTypeDef;

/**
  * @}
  */

/** @defgroup RCC_Exported_Constants
  * @{
  */

/**
  * @brief HSE configuration
  */
#define RCC_HSE_OFF                     (0x00U << RCC_CR_HSEON_Pos)   /* HSE OFF */
#define RCC_HSE_ON                      (0x01U << RCC_CR_HSEON_Pos)   /* HSE ON */
#define RCC_HSE_Bypass                  (0x01U << RCC_CR_HSEBYP_Pos)  /* HSE Bypass */

/**
  * @brief RCC Flag
  */
/* Flags in the CR register */
#define RCC_FLAG_HSIRDY                 ((uint8_t)((1 << 5U) | RCC_CR_HSIRDY_Pos))        /*!< Internal High Speed clock ready flag */
#define RCC_FLAG_HSERDY                 ((uint8_t)((1 << 5U) | RCC_CR_HSERDY_Pos))        /*!< External High Speed clock ready flag */

/* Flags in the BDCR register */
#define RCC_FLAG_LSERDY                 ((uint8_t)((2 << 5U) | RCC_BDCR_LSERDY_Pos))      /*!< External Low Speed oscillator Ready */

/* Flags in the CSR register */
#define RCC_FLAG_LSIRDY                 ((uint8_t)((3 << 5U) | RCC_CSR_LSIRDY_Pos))      /*!< Internal Low Speed oscillator Ready */
#define RCC_FLAG_PINRST                 ((uint8_t)((3 << 5U) | RCC_CSR_PINRSTF_Pos))     /*!< PIN reset flag */
#define RCC_FLAG_PORRST                 ((uint8_t)((3 << 5U) | RCC_CSR_PORRSTF_Pos))     /*!< POR/PDR reset flag */
#define RCC_FLAG_SFTRST                 ((uint8_t)((3 << 5U) | RCC_CSR_SFTRSTF_Pos))     /*!< Software Reset flag */
#define RCC_FLAG_IWDGRST                ((uint8_t)((3 << 5U) | RCC_CSR_IWDGRSTF_Pos))    /*!< Independent Watchdog reset flag */

/**
  * @brief HSI clock source
  */
#define RCC_HSI_Div1                    (0x00U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 1   factor  */
#define RCC_HSI_Div2                    (0x01U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 2   factor  */
#define RCC_HSI_Div3                    (0x02U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 3   factor  */
#define RCC_HSI_Div4                    (0x03U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 4   factor  */
#define RCC_HSI_Div5                    (0x04U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 5   factor  */
#define RCC_HSI_Div6                    (0x05U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 6   factor  */
#define RCC_HSI_Div7                    (0x06U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 7   factor  */
#define RCC_HSI_Div8                    (0x07U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 8   factor  */
#define RCC_HSI_Div12                   (0x08U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 12  factor  */
#define RCC_HSI_Div16                   (0x09U << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 16  factor  */
#define RCC_HSI_Div20                   (0x0AU << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 20  factor  */
#define RCC_HSI_Div24                   (0x0BU << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 24  factor  */
#define RCC_HSI_Div32                   (0x0CU << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 32  factor  */
#define RCC_HSI_Div48                   (0x0DU << RCC_CR_HSIDIV_Pos) /*!< HSI clock division 48  factor  */

/**
  * @brief System clock source
  */
#define RCC_SYSCLKSource_HSI            (0x00U << RCC_CFGR_SW_Pos)      /* Set HSI as systemCLOCK */
#define RCC_SYSCLKSource_HSE            (0x01U << RCC_CFGR_SW_Pos)      /* Set HSE as systemCLOCK */
#define RCC_SYSCLKSource_LSCLK          (0x03U << RCC_CFGR_SW_Pos)      /* Set LSCLK as systemCLOCK */

/**
  * @brief AHB clock source
  */
#define RCC_SYSCLK_Div1                 (0x00U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div2                 (0x08U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div4                 (0x09U << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div8                 (0x0AU << RCC_CFGR_HPRE_Pos)
#define RCC_SYSCLK_Div16                (0x0BU << RCC_CFGR_HPRE_Pos)

#define RCC_HCLK_Div1                   0x00U
#define RCC_HCLK_Div2                   0x04U
#define RCC_HCLK_Div4                   0x05U
#define RCC_HCLK_Div8                   0x06U
#define RCC_HCLK_Div16                  0x07U

/**
  * @brief RCC Interrupt source
  */
#define RCC_IT_LSIRDY                   0x01
#define RCC_IT_LSERDY                   0x02
#define RCC_IT_HSIRDY                   0x04
#define RCC_IT_HSERDY                   0x08

/**
  * @brief SLCD clock source
  */
#define RCC_SLCDCLKSource_LSI           (0x00U << RCC_BDCR_LCDSEL_Pos)
#define RCC_SLCDCLKSource_LSE           (0x01U << RCC_BDCR_LCDSEL_Pos)
#define RCC_SLCDCLKSource_HSI48M_Div128 (0x02U << RCC_BDCR_LCDSEL_Pos)

/**
  * @brief LSE configuration
  */
#define RCC_LSE_OFF                     (0x00U << RCC_BDCR_LSEON_Pos)  /* LSE OFF */
#define RCC_LSE_ON                      (0x01U << RCC_BDCR_LSEON_Pos)  /* LSE ON */
#define RCC_LSE_Bypass                  (0x01U << RCC_BDCR_LSEBYP_Pos) /* LSE Bypass */

/**
  * @brief LSI clock Source configuration
  */
#define RCC_LSICLKSource_40KHz          (0x00U << RCC_CSR_LSISEL_Pos)  /* LSI oscillator 40KHz */
#define RCC_LSICLKSource_10KHz          (0x01U << RCC_CSR_LSISEL_Pos)  /* LSI oscillator 10KHz */
#define RCC_LSICLKSource_32KHz          (0x02U << RCC_CSR_LSISEL_Pos)  /* LSI oscillator 32KHz*/

/**
  * @brief LS clock Source configuration
  */
#define RCC_LSCLKSource_LSICLK          (0x00U << RCC_CSR_LSCLKSEL_Pos)  
#define RCC_LSCLKSource_LSECLK          (0x01U << RCC_CSR_LSCLKSEL_Pos)  

/**
  * @brief RTC clock source
  */
#define RCC_RTCCLKSource_LSE            (0x01U << RCC_BDCR_RTCSEL_Pos)
#define RCC_RTCCLKSource_LSI            (0x02U << RCC_BDCR_RTCSEL_Pos)
#define RCC_RTCCLKSource_HSE_Div128     (0x03U << RCC_BDCR_RTCSEL_Pos)

#define RCC_AHBPeriph_DMA               (0x01U << RCC_AHBENR_DMA_Pos)
#define RCC_AHBPeriph_SRAM              (0x01U << RCC_AHBENR_SRAM_Pos)
#define RCC_AHBPeriph_FLASH             (0x01U << RCC_AHBENR_FLASH_Pos)
#define RCC_AHBPeriph_CRC               (0x01U << RCC_AHBENR_CRC_Pos)
#define RCC_AHBPeriph_GPIOA             (0x01U << RCC_AHBENR_GPIOA_Pos)
#define RCC_AHBPeriph_GPIOB             (0x01U << RCC_AHBENR_GPIOB_Pos)
#define RCC_AHBPeriph_GPIOC             (0x01U << RCC_AHBENR_GPIOC_Pos)
#define RCC_AHBPeriph_GPIOD             (0x01U << RCC_AHBENR_GPIOD_Pos)
#define RCC_AHBPeriph_GPIOE             (0x01U << RCC_AHBENR_GPIOE_Pos)
#define RCC_AHBPeriph_GPIOH             (0x01U << RCC_AHBENR_GPIOH_Pos)

#define RCC_APB1Periph_TIM3             (0x01U << RCC_APB1ENR_TIM3_Pos)
#define RCC_APB1Periph_TIM4             (0x01U << RCC_APB1ENR_TIM4_Pos)
#define RCC_APB1Periph_LPTIM3           (0x01U << RCC_APB1ENR_LPTIM3_Pos)
#define RCC_APB1Periph_LPTIM4           (0x01U << RCC_APB1ENR_LPTIM4_Pos)
#define RCC_APB1Periph_IRM              (0x01U << RCC_APB1ENR_IRM_Pos)
#define RCC_APB1Periph_USART2           (0x01U << RCC_APB1ENR_USART2_Pos)
#define RCC_APB1Periph_LPUART3          (0x01U << RCC_APB1ENR_LPUART3_Pos)
#define RCC_APB1Periph_LPUART4          (0x01U << RCC_APB1ENR_LPUART4_Pos)
#define RCC_APB1Periph_LPUART5          (0x01U << RCC_APB1ENR_LPUART5_Pos)
#define RCC_APB1Periph_I2C1             (0x01U << RCC_APB1ENR_I2C1_Pos)
#define RCC_APB1Periph_BKP              (0x01U << RCC_APB1ENR_BKP_Pos)
#define RCC_APB1Periph_PWR              (0x01U << RCC_APB1ENR_PWR_Pos)
#define RCC_APB1Periph_LCD              (0x01U << RCC_APB1ENR_LCD_Pos)
#define RCC_APB1Periph_IWDG             (0x01U << RCC_APB1ENR_IWDG_Pos)
#define RCC_APB1Periph_RTC              (0x01U << RCC_APB1ENR_RTC_Pos)

#define RCC_APB2Periph_SYSCFG           (0x01U << RCC_APB2ENR_SYSCFG_Pos)
#define RCC_APB2Periph_AES              (0x01U << RCC_APB2ENR_AES_Pos)
#define RCC_APB2Periph_ADC              (0x01U << RCC_APB2ENR_ADC_Pos)
#define RCC_APB2Periph_SPI1             (0x01U << RCC_APB2ENR_SPI1_Pos)
#define RCC_APB2Periph_USART1           (0x01U << RCC_APB2ENR_USART1_Pos)
#define RCC_APB2Periph_COMP             (0x01U << RCC_APB2ENR_COMP_Pos)
#define RCC_APB2Periph_TIM16            (0x01U << RCC_APB2ENR_TIM16_Pos)
#define RCC_APB2Periph_TIM17            (0x01U << RCC_APB2ENR_TIM17_Pos)
#define RCC_APB2Periph_LPTIM2           (0x01U << RCC_APB2ENR_LPTIM2_Pos)
#define RCC_APB2Periph_DBG              (0x01U << RCC_APB2ENR_DBG_Pos)
#define RCC_APB2Periph_LPUART2          (0x01U << RCC_APB2ENR_LPUART2_Pos)
#define RCC_APB2Periph_EXTI             (0x01U << RCC_APB2ENR_EXTI_Pos)
#define RCC_APB2Periph_LPTIM1           (0x01U << RCC_APB2ENR_LPTIM1_Pos)
#define RCC_APB2Periph_LPUART1          (0x01U << RCC_APB2ENR_LPUART1_Pos)

/**
  * @brief Clock source to output on MCO pin
  */
#define RCC_MCO_NoClock                 (0x00U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_LSI_40K                 (0x01U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_LSI_32K                 (0x02U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_LSE                     (0x03U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_SYSCLK                  (0x04U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_HSI                     (0x05U << RCC_CFGR_MCO_Pos)
#define RCC_MCO_HSE                     (0x06U << RCC_CFGR_MCO_Pos)

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
void RCC_HSIConfig(uint32_t clk);
void RCC_HSICmd(FunctionalState state);
void RCC_SYSCLKConfig(uint32_t sys_clk_source);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t clk);
void RCC_PCLK1Config(uint32_t clk);
void RCC_PCLK2Config(uint32_t clk);
void RCC_ITConfig(uint8_t it, FunctionalState state);
ITStatus RCC_GetITStatus(uint8_t it);
void RCC_ClearITPendingBit(uint8_t it);
void RCC_SLCDCLKConfig(uint32_t slcd_clk_src);
uint32_t RCC_GetSlcdClockConfig(void);
uint32_t RCC_GetSlcdClockFreq(void);
void RCC_LSEConfig(uint32_t rcc_lse);
void RCC_LSICLKConfig(uint32_t lsi_clk_src);
void RCC_LSICmd(FunctionalState state);
void RCC_LSCLKConfig(uint32_t ls_clk_src);
void RCC_RTCCLKConfig(uint32_t rtc_clk_src);
void RCC_RTCCLKCmd(FunctionalState state);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* clk);
void RCC_AHBPeriphClockCmd(uint32_t ahb_periph, FunctionalState state);
void RCC_APB2PeriphClockCmd(uint32_t apb2_periph, FunctionalState state);
void RCC_APB1PeriphClockCmd(uint32_t apb1_periph, FunctionalState state);
void RCC_AHBPeriphResetCmd(uint32_t ahb_periph, FunctionalState state);
void RCC_APB2PeriphResetCmd(uint32_t apb2_periph, FunctionalState state);
void RCC_APB1PeriphResetCmd(uint32_t apb1_periph, FunctionalState state);
void RCC_ClockSecuritySystemCmd(FunctionalState state);
void RCC_MCOConfig(uint32_t mco_src);
void RCC_ClearFlag(void);
void RCC_BackupResetCmd(FunctionalState state);


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
