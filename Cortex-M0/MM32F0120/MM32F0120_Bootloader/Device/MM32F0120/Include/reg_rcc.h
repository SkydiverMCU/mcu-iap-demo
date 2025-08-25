/***********************************************************************************************************************
    @file     reg_rcc.h
    @author   VV TEAM
    @brief    This flie contains all the RCC's register and its field definition.
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

#ifndef __REG_RCC_H
#define __REG_RCC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0.h>



/**
  * @brief RCC Base Address Definition
  */
#define  RCC_BASE                                  0x40021000                                       /*!<Base Address: 0x40021000*/

/**
  * @brief RCC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<RCC Clock Control Register                     offset: 0x00       */
    __IO uint32_t CFGR;                           /*!<RCC Clock Configuration Register               offset: 0x04       */
    __IO uint32_t CIR;                            /*!<RCC Clock Interrupt Register                   offset: 0x08       */
    __IO uint32_t APB2RSTR;                       /*!<RCC APB2 Peripheral Reset Register             offset: 0x0C       */
    __IO uint32_t APB1RSTR;                       /*!<RCC APB1 Peripheral Reset Register             offset: 0x10       */
    __IO uint32_t AHBENR;                         /*!<RCC AHB Peripheral Clock Enable Register       offset: 0x14       */
    __IO uint32_t APB2ENR;                        /*!<RCC APB2 Peripheral Clock Enable Register      offset: 0x18       */
    __IO uint32_t APB1ENR;                        /*!<RCC APB1Peripheral Clock Enable Register       offset: 0x1C       */
    __IO uint32_t BDCR;                           /*!<RCC Backup Domain Control Register             offset: 0x20       */
    __IO uint32_t CSR;                            /*!<RCC Control Status Register                    offset: 0x24       */
    __IO uint32_t AHBRSTR;                        /*!<RCC AHB Peripheral Reset Register              offset: 0x28       */
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                                       ((RCC_TypeDef *)RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define  RCC_CR_HSION_Pos                         (0)
#define  RCC_CR_HSION_Msk                         (0x1U << RCC_CR_HSION_Pos)                        /*!<Internal High-speed Clock Enable*/
#define  RCC_CR_HSION                             RCC_CR_HSION_Msk
#define  RCC_CR_HSIRDY_Pos                        (1)
#define  RCC_CR_HSIRDY_Msk                        (0x1U << RCC_CR_HSIRDY_Pos)                       /*!<Internal High-speed Clock Ready Flag*/
#define  RCC_CR_HSIRDY                            RCC_CR_HSIRDY_Msk
#define  RCC_CR_HSI144DIV_Pos                     (11)
#define  RCC_CR_HSI144DIV_Msk                     (0x1U << RCC_CR_HSI144DIV_Pos)                    /*!<Internal high-speed clock division factor*/
#define  RCC_CR_HSI144DIV                         RCC_CR_HSI144DIV_Msk
#define  RCC_CR_HSEON_Pos                         (16)
#define  RCC_CR_HSEON_Msk                         (0x1U << RCC_CR_HSEON_Pos)                        /*!<External High-speed Clock Enable*/
#define  RCC_CR_HSEON                             RCC_CR_HSEON_Msk
#define  RCC_CR_HSERDY_Pos                        (17)
#define  RCC_CR_HSERDY_Msk                        (0x1U << RCC_CR_HSERDY_Pos)                       /*!<External High-speed Clock Ready Flag*/
#define  RCC_CR_HSERDY                            RCC_CR_HSERDY_Msk
#define  RCC_CR_CSSON_Pos                         (19)
#define  RCC_CR_CSSON_Msk                         (0x1U << RCC_CR_CSSON_Pos)                        /*!<Clock Security System Enable*/
#define  RCC_CR_CSSON                             RCC_CR_CSSON_Msk

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define  RCC_CFGR_SW_Pos                          (0)
#define  RCC_CFGR_SW_Msk                          (0x3U << RCC_CFGR_SW_Pos)                         /*!<System Clock Switch*/
#define  RCC_CFGR_SW                              RCC_CFGR_SW_Msk
#define  RCC_CFGR_SW_0                            (0x1U << RCC_CFGR_SW_Pos) 
#define  RCC_CFGR_SW_1                            (0x2U << RCC_CFGR_SW_Pos) 
#define  RCC_CFGR_SWS_Pos                         (2)
#define  RCC_CFGR_SWS_Msk                         (0x3U << RCC_CFGR_SWS_Pos)                        /*!<System Clock Switch Status*/
#define  RCC_CFGR_SWS                             RCC_CFGR_SWS_Msk
#define  RCC_CFGR_SWS_0                           (0x1U << RCC_CFGR_SWS_Pos) 
#define  RCC_CFGR_SWS_1                           (0x2U << RCC_CFGR_SWS_Pos) 
#define  RCC_CFGR_HPRE_Pos                        (4)
#define  RCC_CFGR_HPRE_Msk                        (0xFU << RCC_CFGR_HPRE_Pos)                       /*!<AHB prescaler coefficient*/
#define  RCC_CFGR_HPRE                            RCC_CFGR_HPRE_Msk
#define  RCC_CFGR_HPRE_0                          (0x1U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_HPRE_1                          (0x2U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_HPRE_2                          (0x4U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_HPRE_3                          (0x8U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_PPRE1_Pos                       (8)
#define  RCC_CFGR_PPRE1_Msk                       (0x7U << RCC_CFGR_PPRE1_Pos)                      /*!<APB1 prescaler coefficient*/
#define  RCC_CFGR_PPRE1                           RCC_CFGR_PPRE1_Msk
#define  RCC_CFGR_PPRE1_0                         (0x1U << RCC_CFGR_PPRE1_Pos) 
#define  RCC_CFGR_PPRE1_1                         (0x2U << RCC_CFGR_PPRE1_Pos) 
#define  RCC_CFGR_PPRE1_2                         (0x4U << RCC_CFGR_PPRE1_Pos) 
#define  RCC_CFGR_PPRE2_Pos                       (11)
#define  RCC_CFGR_PPRE2_Msk                       (0x7U << RCC_CFGR_PPRE2_Pos)                      /*!<APB2 prescaler coefficient*/
#define  RCC_CFGR_PPRE2                           RCC_CFGR_PPRE2_Msk
#define  RCC_CFGR_PPRE2_0                         (0x1U << RCC_CFGR_PPRE2_Pos) 
#define  RCC_CFGR_PPRE2_1                         (0x2U << RCC_CFGR_PPRE2_Pos) 
#define  RCC_CFGR_PPRE2_2                         (0x4U << RCC_CFGR_PPRE2_Pos) 
#define  RCC_CFGR_MCO_Pos                         (24)
#define  RCC_CFGR_MCO_Msk                         (0x7U << RCC_CFGR_MCO_Pos)                        /*!<Micro Controller Clock Output*/
#define  RCC_CFGR_MCO                             RCC_CFGR_MCO_Msk
#define  RCC_CFGR_MCO_0                           (0x1U << RCC_CFGR_MCO_Pos) 
#define  RCC_CFGR_MCO_1                           (0x2U << RCC_CFGR_MCO_Pos) 
#define  RCC_CFGR_MCO_2                           (0x4U << RCC_CFGR_MCO_Pos) 

/**
  * @brief RCC_CIR Register Bit Definition
  */
#define  RCC_CIR_LSIRDYF_Pos                      (0)
#define  RCC_CIR_LSIRDYF_Msk                      (0x1U << RCC_CIR_LSIRDYF_Pos)                     /*!<LSI Ready Interrupt Flag*/
#define  RCC_CIR_LSIRDYF                          RCC_CIR_LSIRDYF_Msk
#define  RCC_CIR_LSERDYF_Pos                      (1)
#define  RCC_CIR_LSERDYF_Msk                      (0x1U << RCC_CIR_LSERDYF_Pos)                     /*!<LSERDYF: LSE Ready Interrupt Flag*/
#define  RCC_CIR_LSERDYF                          RCC_CIR_LSERDYF_Msk
#define  RCC_CIR_HSIRDYF_Pos                      (2)
#define  RCC_CIR_HSIRDYF_Msk                      (0x1U << RCC_CIR_HSIRDYF_Pos)                     /*!<HSI Ready Interrupt Flag*/
#define  RCC_CIR_HSIRDYF                          RCC_CIR_HSIRDYF_Msk
#define  RCC_CIR_HSERDYF_Pos                      (3)
#define  RCC_CIR_HSERDYF_Msk                      (0x1U << RCC_CIR_HSERDYF_Pos)                     /*!<HSE Ready Interrupt Flag*/
#define  RCC_CIR_HSERDYF                          RCC_CIR_HSERDYF_Msk
#define  RCC_CIR_CSSF_Pos                         (7)
#define  RCC_CIR_CSSF_Msk                         (0x1U << RCC_CIR_CSSF_Pos)                        /*!<Clock Security System Interrupt Flag*/
#define  RCC_CIR_CSSF                             RCC_CIR_CSSF_Msk
#define  RCC_CIR_LSIRDYIE_Pos                     (8)
#define  RCC_CIR_LSIRDYIE_Msk                     (0x1U << RCC_CIR_LSIRDYIE_Pos)                    /*!<LSI Ready Interrupt Enable*/
#define  RCC_CIR_LSIRDYIE                         RCC_CIR_LSIRDYIE_Msk
#define  RCC_CIR_LSERDYIE_Pos                     (9)
#define  RCC_CIR_LSERDYIE_Msk                     (0x1U << RCC_CIR_LSERDYIE_Pos)                    /*!<LSERDYIE: LSE Ready Interrupt Enable*/
#define  RCC_CIR_LSERDYIE                         RCC_CIR_LSERDYIE_Msk
#define  RCC_CIR_HSIRDYIE_Pos                     (10)
#define  RCC_CIR_HSIRDYIE_Msk                     (0x1U << RCC_CIR_HSIRDYIE_Pos)                    /*!<HSI Ready Interrupt Enable*/
#define  RCC_CIR_HSIRDYIE                         RCC_CIR_HSIRDYIE_Msk
#define  RCC_CIR_HSERDYIE_Pos                     (11)
#define  RCC_CIR_HSERDYIE_Msk                     (0x1U << RCC_CIR_HSERDYIE_Pos)                    /*!<HSE Ready Interrupt Enable*/
#define  RCC_CIR_HSERDYIE                         RCC_CIR_HSERDYIE_Msk
#define  RCC_CIR_LSIRDYC_Pos                      (16)
#define  RCC_CIR_LSIRDYC_Msk                      (0x1U << RCC_CIR_LSIRDYC_Pos)                     /*!<LSI Ready Interrupt Clear*/
#define  RCC_CIR_LSIRDYC                          RCC_CIR_LSIRDYC_Msk
#define  RCC_CIR_LSERDYC_Pos                      (17)
#define  RCC_CIR_LSERDYC_Msk                      (0x1U << RCC_CIR_LSERDYC_Pos)                     /*!<LSERDYC: LSE Ready Interrupt Clear*/
#define  RCC_CIR_LSERDYC                          RCC_CIR_LSERDYC_Msk
#define  RCC_CIR_HSIRDYC_Pos                      (18)
#define  RCC_CIR_HSIRDYC_Msk                      (0x1U << RCC_CIR_HSIRDYC_Pos)                     /*!<HSI Ready Interrupt Clear*/
#define  RCC_CIR_HSIRDYC                          RCC_CIR_HSIRDYC_Msk
#define  RCC_CIR_HSERDYC_Pos                      (19)
#define  RCC_CIR_HSERDYC_Msk                      (0x1U << RCC_CIR_HSERDYC_Pos)                     /*!<HSE Ready Interrupt Clear*/
#define  RCC_CIR_HSERDYC                          RCC_CIR_HSERDYC_Msk
#define  RCC_CIR_CSSC_Pos                         (23)
#define  RCC_CIR_CSSC_Msk                         (0x1U << RCC_CIR_CSSC_Pos)                        /*!<Clock Security System Interrupt Clear*/
#define  RCC_CIR_CSSC                             RCC_CIR_CSSC_Msk

/**
  * @brief RCC_APB2RSTR Register Bit Definition
  */
#define  RCC_APB2RSTR_SYSCFG_Pos                  (0)
#define  RCC_APB2RSTR_SYSCFG_Msk                  (0x1U << RCC_APB2RSTR_SYSCFG_Pos)                 /*!<SYSCFG Reset*/
#define  RCC_APB2RSTR_SYSCFG                      RCC_APB2RSTR_SYSCFG_Msk
#define  RCC_APB2RSTR_ADC_Pos                     (9)
#define  RCC_APB2RSTR_ADC_Msk                     (0x1U << RCC_APB2RSTR_ADC_Pos)                    /*!<ADC Reset*/
#define  RCC_APB2RSTR_ADC                         RCC_APB2RSTR_ADC_Msk
#define  RCC_APB2RSTR_TIM1_Pos                    (11)
#define  RCC_APB2RSTR_TIM1_Msk                    (0x1U << RCC_APB2RSTR_TIM1_Pos)                   /*!<TIM1 Reset*/
#define  RCC_APB2RSTR_TIM1                        RCC_APB2RSTR_TIM1_Msk
#define  RCC_APB2RSTR_SPI1_Pos                    (12)
#define  RCC_APB2RSTR_SPI1_Msk                    (0x1U << RCC_APB2RSTR_SPI1_Pos)                   /*!<SPI1 Reset*/
#define  RCC_APB2RSTR_SPI1                        RCC_APB2RSTR_SPI1_Msk
#define  RCC_APB2RSTR_UART1_Pos                   (14)
#define  RCC_APB2RSTR_UART1_Msk                   (0x1U << RCC_APB2RSTR_UART1_Pos)                  /*!<UART1 Reset*/
#define  RCC_APB2RSTR_UART1                       RCC_APB2RSTR_UART1_Msk
#define  RCC_APB2RSTR_CPT_Pos                     (15)
#define  RCC_APB2RSTR_CPT_Msk                     (0x1U << RCC_APB2RSTR_CPT_Pos)                    /*!<Comparator reset*/
#define  RCC_APB2RSTR_CPT                         RCC_APB2RSTR_CPT_Msk
#define  RCC_APB2RSTR_TIM14_Pos                   (16)
#define  RCC_APB2RSTR_TIM14_Msk                   (0x1U << RCC_APB2RSTR_TIM14_Pos)                  /*!<TIM14 Reset*/
#define  RCC_APB2RSTR_TIM14                       RCC_APB2RSTR_TIM14_Msk
#define  RCC_APB2RSTR_TIM16_Pos                   (17)
#define  RCC_APB2RSTR_TIM16_Msk                   (0x1U << RCC_APB2RSTR_TIM16_Pos)                  /*!<TIM16 Reset*/
#define  RCC_APB2RSTR_TIM16                       RCC_APB2RSTR_TIM16_Msk
#define  RCC_APB2RSTR_TIM17_Pos                   (18)
#define  RCC_APB2RSTR_TIM17_Msk                   (0x1U << RCC_APB2RSTR_TIM17_Pos)                  /*!<TIM17 Reset*/
#define  RCC_APB2RSTR_TIM17                       RCC_APB2RSTR_TIM17_Msk
#define  RCC_APB2RSTR_DBG_Pos                     (22)
#define  RCC_APB2RSTR_DBG_Msk                     (0x1U << RCC_APB2RSTR_DBG_Pos)                    /*!<DBG Reset*/
#define  RCC_APB2RSTR_DBG                         RCC_APB2RSTR_DBG_Msk

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define  RCC_APB1RSTR_TIM3_Pos                    (1)
#define  RCC_APB1RSTR_TIM3_Msk                    (0x1U << RCC_APB1RSTR_TIM3_Pos)                   /*!<TIM3 Reset*/
#define  RCC_APB1RSTR_TIM3                        RCC_APB1RSTR_TIM3_Msk
#define  RCC_APB1RSTR_UART2_Pos                   (17)
#define  RCC_APB1RSTR_UART2_Msk                   (0x1U << RCC_APB1RSTR_UART2_Pos)                  /*!<UART2 Reset*/
#define  RCC_APB1RSTR_UART2                       RCC_APB1RSTR_UART2_Msk
#define  RCC_APB1RSTR_USART3_Pos                  (18)
#define  RCC_APB1RSTR_USART3_Msk                  (0x1U << RCC_APB1RSTR_USART3_Pos)                 /*!<USART3 Reset*/
#define  RCC_APB1RSTR_USART3                      RCC_APB1RSTR_USART3_Msk
#define  RCC_APB1RSTR_I2C1_Pos                    (21)
#define  RCC_APB1RSTR_I2C1_Msk                    (0x1U << RCC_APB1RSTR_I2C1_Pos)                   /*!<2C1 Reset*/
#define  RCC_APB1RSTR_I2C1                        RCC_APB1RSTR_I2C1_Msk
#define  RCC_APB1RSTR_BKP_Pos                     (24)
#define  RCC_APB1RSTR_BKP_Msk                     (0x1U << RCC_APB1RSTR_BKP_Pos)                    /*!<BKP Reset*/
#define  RCC_APB1RSTR_BKP                         RCC_APB1RSTR_BKP_Msk
#define  RCC_APB1RSTR_CSM_Pos                     (26)
#define  RCC_APB1RSTR_CSM_Msk                     (0x1U << RCC_APB1RSTR_CSM_Pos)                    /*!<CSM Reset*/
#define  RCC_APB1RSTR_CSM                         RCC_APB1RSTR_CSM_Msk
#define  RCC_APB1RSTR_PWR_Pos                     (28)
#define  RCC_APB1RSTR_PWR_Msk                     (0x1U << RCC_APB1RSTR_PWR_Pos)                    /*!<Power Interface Reset*/
#define  RCC_APB1RSTR_PWR                         RCC_APB1RSTR_PWR_Msk
#define  RCC_APB1RSTR_RTC_Pos                     (31)
#define  RCC_APB1RSTR_RTC_Msk                     (0x1U << RCC_APB1RSTR_RTC_Pos)                    /*!<RTC Reset*/
#define  RCC_APB1RSTR_RTC                         RCC_APB1RSTR_RTC_Msk

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define  RCC_AHBENR_DMA_Pos                       (0)
#define  RCC_AHBENR_DMA_Msk                       (0x1U << RCC_AHBENR_DMA_Pos)                      /*!<DMA clock enable*/
#define  RCC_AHBENR_DMA                           RCC_AHBENR_DMA_Msk
#define  RCC_AHBENR_SRAM_Pos                      (2)
#define  RCC_AHBENR_SRAM_Msk                      (0x1U << RCC_AHBENR_SRAM_Pos)                     /*!<SRAM Clock Enable*/
#define  RCC_AHBENR_SRAM                          RCC_AHBENR_SRAM_Msk
#define  RCC_AHBENR_FLASH_Pos                     (4)
#define  RCC_AHBENR_FLASH_Msk                     (0x1U << RCC_AHBENR_FLASH_Pos)                    /*!<FLASH Clock Enable*/
#define  RCC_AHBENR_FLASH                         RCC_AHBENR_FLASH_Msk
#define  RCC_AHBENR_CRC_Pos                       (6)
#define  RCC_AHBENR_CRC_Msk                       (0x1U << RCC_AHBENR_CRC_Pos)                      /*!<CRC Clock Enable*/
#define  RCC_AHBENR_CRC                           RCC_AHBENR_CRC_Msk
#define  RCC_AHBENR_GPIOA_Pos                     (17)
#define  RCC_AHBENR_GPIOA_Msk                     (0x1U << RCC_AHBENR_GPIOA_Pos)                    /*!<GPIOA Clock Enable*/
#define  RCC_AHBENR_GPIOA                         RCC_AHBENR_GPIOA_Msk
#define  RCC_AHBENR_GPIOB_Pos                     (18)
#define  RCC_AHBENR_GPIOB_Msk                     (0x1U << RCC_AHBENR_GPIOB_Pos)                    /*!<GPIOB Clock Enable*/
#define  RCC_AHBENR_GPIOB                         RCC_AHBENR_GPIOB_Msk
#define  RCC_AHBENR_GPIOC_Pos                     (19)
#define  RCC_AHBENR_GPIOC_Msk                     (0x1U << RCC_AHBENR_GPIOC_Pos)                    /*!<GPIOC Clock Enable*/
#define  RCC_AHBENR_GPIOC                         RCC_AHBENR_GPIOC_Msk
#define  RCC_AHBENR_GPIOD_Pos                     (20)
#define  RCC_AHBENR_GPIOD_Msk                     (0x1U << RCC_AHBENR_GPIOD_Pos)                    /*!<GPIOD Clock Enable*/
#define  RCC_AHBENR_GPIOD                         RCC_AHBENR_GPIOD_Msk
#define  RCC_AHBENR_HWDIV_Pos                     (26)
#define  RCC_AHBENR_HWDIV_Msk                     (0x1U << RCC_AHBENR_HWDIV_Pos)                    /*!<HWDIV Clock Enable*/
#define  RCC_AHBENR_HWDIV                         RCC_AHBENR_HWDIV_Msk

/**
  * @brief RCC_APB2ENR Register Bit Definition
  */
#define  RCC_APB2ENR_SYSCFG_Pos                   (0)
#define  RCC_APB2ENR_SYSCFG_Msk                   (0x1U << RCC_APB2ENR_SYSCFG_Pos)                  /*!<SYSCFG Clock Enable*/
#define  RCC_APB2ENR_SYSCFG                       RCC_APB2ENR_SYSCFG_Msk
#define  RCC_APB2ENR_ADC_Pos                      (9)
#define  RCC_APB2ENR_ADC_Msk                      (0x1U << RCC_APB2ENR_ADC_Pos)                     /*!<ADC Clock Enable*/
#define  RCC_APB2ENR_ADC                          RCC_APB2ENR_ADC_Msk
#define  RCC_APB2ENR_TIM1_Pos                     (11)
#define  RCC_APB2ENR_TIM1_Msk                     (0x1U << RCC_APB2ENR_TIM1_Pos)                    /*!<TIM1 Clock Enable*/
#define  RCC_APB2ENR_TIM1                         RCC_APB2ENR_TIM1_Msk
#define  RCC_APB2ENR_SPI1_Pos                     (12)
#define  RCC_APB2ENR_SPI1_Msk                     (0x1U << RCC_APB2ENR_SPI1_Pos)                    /*!<SPI1 Clock Enable*/
#define  RCC_APB2ENR_SPI1                         RCC_APB2ENR_SPI1_Msk
#define  RCC_APB2ENR_USART1_Pos                   (14)
#define  RCC_APB2ENR_USART1_Msk                   (0x1U << RCC_APB2ENR_USART1_Pos)                  /*!<USART1 Clock Enable*/
#define  RCC_APB2ENR_USART1                       RCC_APB2ENR_USART1_Msk
#define  RCC_APB2ENR_CPT_Pos                      (15)
#define  RCC_APB2ENR_CPT_Msk                      (0x1U << RCC_APB2ENR_CPT_Pos)                     /*!<Comparator Clock Enable*/
#define  RCC_APB2ENR_CPT                          RCC_APB2ENR_CPT_Msk
#define  RCC_APB2ENR_TIM14_Pos                    (16)
#define  RCC_APB2ENR_TIM14_Msk                    (0x1U << RCC_APB2ENR_TIM14_Pos)                   /*!<TIM14 Clock Enable*/
#define  RCC_APB2ENR_TIM14                        RCC_APB2ENR_TIM14_Msk
#define  RCC_APB2ENR_TIM16_Pos                    (17)
#define  RCC_APB2ENR_TIM16_Msk                    (0x1U << RCC_APB2ENR_TIM16_Pos)                   /*!<TIM16 Clock Enable*/
#define  RCC_APB2ENR_TIM16                        RCC_APB2ENR_TIM16_Msk
#define  RCC_APB2ENR_TIM17_Pos                    (18)
#define  RCC_APB2ENR_TIM17_Msk                    (0x1U << RCC_APB2ENR_TIM17_Pos)                   /*!<TIM17 Clock Enable*/
#define  RCC_APB2ENR_TIM17                        RCC_APB2ENR_TIM17_Msk
#define  RCC_APB2ENR_DBG_Pos                      (22)
#define  RCC_APB2ENR_DBG_Msk                      (0x1U << RCC_APB2ENR_DBG_Pos)                     /*!<DBG Clock Enable*/
#define  RCC_APB2ENR_DBG                          RCC_APB2ENR_DBG_Msk
#define  RCC_APB2ENR_EXTI_Pos                     (29)
#define  RCC_APB2ENR_EXTI_Msk                     (0x1U << RCC_APB2ENR_EXTI_Pos)                    /*!<EXTI Clock Enable*/
#define  RCC_APB2ENR_EXTI                         RCC_APB2ENR_EXTI_Msk

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define  RCC_APB1ENR_TIM3_Pos                     (1)
#define  RCC_APB1ENR_TIM3_Msk                     (0x1U << RCC_APB1ENR_TIM3_Pos)                    /*!<TIM3 Clock Enable*/
#define  RCC_APB1ENR_TIM3                         RCC_APB1ENR_TIM3_Msk
#define  RCC_APB1ENR_USART2_Pos                   (17)
#define  RCC_APB1ENR_USART2_Msk                   (0x1U << RCC_APB1ENR_USART2_Pos)                  /*!<USART2 Clock Enable*/
#define  RCC_APB1ENR_USART2                       RCC_APB1ENR_USART2_Msk
#define  RCC_APB1ENR_USART3_Pos                   (18)
#define  RCC_APB1ENR_USART3_Msk                   (0x1U << RCC_APB1ENR_USART3_Pos)                  /*!<USART3 Clock Enable*/
#define  RCC_APB1ENR_USART3                       RCC_APB1ENR_USART3_Msk
#define  RCC_APB1ENR_I2C1_Pos                     (21)
#define  RCC_APB1ENR_I2C1_Msk                     (0x1U << RCC_APB1ENR_I2C1_Pos)                    /*!<I2C1 Clock Enable*/
#define  RCC_APB1ENR_I2C1                         RCC_APB1ENR_I2C1_Msk
#define  RCC_APB1ENR_BKP_Pos                      (24)
#define  RCC_APB1ENR_BKP_Msk                      (0x1U << RCC_APB1ENR_BKP_Pos)                     /*!<BKP Clock Enable*/
#define  RCC_APB1ENR_BKP                          RCC_APB1ENR_BKP_Msk
#define  RCC_APB1ENR_CSM_Pos                      (26)
#define  RCC_APB1ENR_CSM_Msk                      (0x1U << RCC_APB1ENR_CSM_Pos)                     /*!<CSM Clock Enable*/
#define  RCC_APB1ENR_CSM                          RCC_APB1ENR_CSM_Msk
#define  RCC_APB1ENR_PWR_Pos                      (28)
#define  RCC_APB1ENR_PWR_Msk                      (0x1U << RCC_APB1ENR_PWR_Pos)                     /*!<Power Clock Enable*/
#define  RCC_APB1ENR_PWR                          RCC_APB1ENR_PWR_Msk
#define  RCC_APB1ENR_IWDG_Pos                     (30)
#define  RCC_APB1ENR_IWDG_Msk                     (0x1U << RCC_APB1ENR_IWDG_Pos)                    /*!<IWDG Clock Enable*/
#define  RCC_APB1ENR_IWDG                         RCC_APB1ENR_IWDG_Msk
#define  RCC_APB1ENR_RTC_Pos                      (31)
#define  RCC_APB1ENR_RTC_Msk                      (0x1U << RCC_APB1ENR_RTC_Pos)                     /*!<RTC Clock Enable*/
#define  RCC_APB1ENR_RTC                          RCC_APB1ENR_RTC_Msk

/**
  * @brief RCC_BDCR Register Bit Definition
  */
#define  RCC_BDCR_LSEON_Pos                       (0)
#define  RCC_BDCR_LSEON_Msk                       (0x1U << RCC_BDCR_LSEON_Pos)                      /*!<External Low-speed Oscillator Enable*/
#define  RCC_BDCR_LSEON                           RCC_BDCR_LSEON_Msk
#define  RCC_BDCR_LSERDY_Pos                      (1)
#define  RCC_BDCR_LSERDY_Msk                      (0x1U << RCC_BDCR_LSERDY_Pos)                     /*!<External Low-speed Oscillator Ready*/
#define  RCC_BDCR_LSERDY                          RCC_BDCR_LSERDY_Msk
#define  RCC_BDCR_LSEBYP_Pos                      (2)
#define  RCC_BDCR_LSEBYP_Msk                      (0x1U << RCC_BDCR_LSEBYP_Pos)                     /*!<External Low-speed Oscillator Bypass*/
#define  RCC_BDCR_LSEBYP                          RCC_BDCR_LSEBYP_Msk
#define  RCC_BDCR_RTCSEL_Pos                      (8)
#define  RCC_BDCR_RTCSEL_Msk                      (0x3U << RCC_BDCR_RTCSEL_Pos)                     /*!<RTC Clock Source Selection*/
#define  RCC_BDCR_RTCSEL                          RCC_BDCR_RTCSEL_Msk
#define  RCC_BDCR_RTCSEL_0                        (0x1U << RCC_BDCR_RTCSEL_Pos) 
#define  RCC_BDCR_RTCSEL_1                        (0x2U << RCC_BDCR_RTCSEL_Pos) 
#define  RCC_BDCR_RTCEN_Pos                       (15)
#define  RCC_BDCR_RTCEN_Msk                       (0x1U << RCC_BDCR_RTCEN_Pos)                      /*!<RTC Clock Enable*/
#define  RCC_BDCR_RTCEN                           RCC_BDCR_RTCEN_Msk
#define  RCC_BDCR_BDRST_Pos                       (16)
#define  RCC_BDCR_BDRST_Msk                       (0x1U << RCC_BDCR_BDRST_Pos)                      /*!<Backup domain software reset*/
#define  RCC_BDCR_BDRST                           RCC_BDCR_BDRST_Msk
#define  RCC_BDCR_DBP_Pos                         (24)
#define  RCC_BDCR_DBP_Msk                         (0x1U << RCC_BDCR_DBP_Pos)                        /*!<Remove write protection from the backup domain. After reset, the backup register is protected against accidental writing. This bit is set to allow being written to these registers.*/
#define  RCC_BDCR_DBP                             RCC_BDCR_DBP_Msk

/**
  * @brief RCC_CSR Register Bit Definition
  */
#define  RCC_CSR_LSION_Pos                        (0)
#define  RCC_CSR_LSION_Msk                        (0x1U << RCC_CSR_LSION_Pos)                       /*!<Internal Low-speed Oscillator Enable*/
#define  RCC_CSR_LSION                            RCC_CSR_LSION_Msk
#define  RCC_CSR_LSIRDY_Pos                       (1)
#define  RCC_CSR_LSIRDY_Msk                       (0x1U << RCC_CSR_LSIRDY_Pos)                      /*!<Internal Low-speed Oscillator Ready*/
#define  RCC_CSR_LSIRDY                           RCC_CSR_LSIRDY_Msk
#define  RCC_CSR_PVDRSTEN_Pos                     (6)
#define  RCC_CSR_PVDRSTEN_Msk                     (0x1U << RCC_CSR_PVDRSTEN_Pos)                    /*!<PVD Reset Enable*/
#define  RCC_CSR_PVDRSTEN                         RCC_CSR_PVDRSTEN_Msk
#define  RCC_CSR_LOCKUPEN_Pos                     (7)
#define  RCC_CSR_LOCKUPEN_Msk                     (0x1U << RCC_CSR_LOCKUPEN_Pos)                    /*!<CPU Lockup Reset Enable*/
#define  RCC_CSR_LOCKUPEN                         RCC_CSR_LOCKUPEN_Msk
#define  RCC_CSR_PVDRSTF_Pos                      (22)
#define  RCC_CSR_PVDRSTF_Msk                      (0x1U << RCC_CSR_PVDRSTF_Pos)                     /*!<PVD Reset Flag*/
#define  RCC_CSR_PVDRSTF                          RCC_CSR_PVDRSTF_Msk
#define  RCC_CSR_LOCKUPF_Pos                      (23)
#define  RCC_CSR_LOCKUPF_Msk                      (0x1U << RCC_CSR_LOCKUPF_Pos)                     /*!<CPU Lockup Reset Flag*/
#define  RCC_CSR_LOCKUPF                          RCC_CSR_LOCKUPF_Msk
#define  RCC_CSR_RMVF_Pos                         (24)
#define  RCC_CSR_RMVF_Msk                         (0x1U << RCC_CSR_RMVF_Pos)                        /*!<Remove Reset Flag*/
#define  RCC_CSR_RMVF                             RCC_CSR_RMVF_Msk
#define  RCC_CSR_PINRSTF_Pos                      (26)
#define  RCC_CSR_PINRSTF_Msk                      (0x1U << RCC_CSR_PINRSTF_Pos)                     /*!<PIN Reset Flag*/
#define  RCC_CSR_PINRSTF                          RCC_CSR_PINRSTF_Msk
#define  RCC_CSR_PORRSTF_Pos                      (27)
#define  RCC_CSR_PORRSTF_Msk                      (0x1U << RCC_CSR_PORRSTF_Pos)                     /*!<POR/PDR Reset Flag*/
#define  RCC_CSR_PORRSTF                          RCC_CSR_PORRSTF_Msk
#define  RCC_CSR_SFTRSTF_Pos                      (28)
#define  RCC_CSR_SFTRSTF_Msk                      (0x1U << RCC_CSR_SFTRSTF_Pos)                     /*!<Software Reset Flag*/
#define  RCC_CSR_SFTRSTF                          RCC_CSR_SFTRSTF_Msk
#define  RCC_CSR_IWDGRSTF_Pos                     (29)
#define  RCC_CSR_IWDGRSTF_Msk                     (0x1U << RCC_CSR_IWDGRSTF_Pos)                    /*!<Independent Watchdog Reset Flag*/
#define  RCC_CSR_IWDGRSTF                         RCC_CSR_IWDGRSTF_Msk
#define  RCC_CSR_LPWRRSTF_Pos                     (31)
#define  RCC_CSR_LPWRRSTF_Msk                     (0x1U << RCC_CSR_LPWRRSTF_Pos)                    /*!<Low Power Reset Flag*/
#define  RCC_CSR_LPWRRSTF                         RCC_CSR_LPWRRSTF_Msk

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define  RCC_AHBRSTR_DMA_Pos                      (0)
#define  RCC_AHBRSTR_DMA_Msk                      (0x1U << RCC_AHBRSTR_DMA_Pos)                     /*!<DMA Reset*/
#define  RCC_AHBRSTR_DMA                          RCC_AHBRSTR_DMA_Msk
#define  RCC_AHBRSTR_CRC_Pos                      (6)
#define  RCC_AHBRSTR_CRC_Msk                      (0x1U << RCC_AHBRSTR_CRC_Pos)                     /*!<CRC Reset*/
#define  RCC_AHBRSTR_CRC                          RCC_AHBRSTR_CRC_Msk
#define  RCC_AHBRSTR_GPIOA_Pos                    (17)
#define  RCC_AHBRSTR_GPIOA_Msk                    (0x1U << RCC_AHBRSTR_GPIOA_Pos)                   /*!<GPIOA Reset*/
#define  RCC_AHBRSTR_GPIOA                        RCC_AHBRSTR_GPIOA_Msk
#define  RCC_AHBRSTR_GPIOB_Pos                    (18)
#define  RCC_AHBRSTR_GPIOB_Msk                    (0x1U << RCC_AHBRSTR_GPIOB_Pos)                   /*!<GPIOB Reset*/
#define  RCC_AHBRSTR_GPIOB                        RCC_AHBRSTR_GPIOB_Msk
#define  RCC_AHBRSTR_GPIOC_Pos                    (19)
#define  RCC_AHBRSTR_GPIOC_Msk                    (0x1U << RCC_AHBRSTR_GPIOC_Pos)                   /*!<GPIOC Reset*/
#define  RCC_AHBRSTR_GPIOC                        RCC_AHBRSTR_GPIOC_Msk
#define  RCC_AHBRSTR_GPIOD_Pos                    (20)
#define  RCC_AHBRSTR_GPIOD_Msk                    (0x1U << RCC_AHBRSTR_GPIOD_Pos)                   /*!<GPIOD Reset*/
#define  RCC_AHBRSTR_GPIOD                        RCC_AHBRSTR_GPIOD_Msk
#define  RCC_AHBRSTR_HWDIV_Pos                    (26)
#define  RCC_AHBRSTR_HWDIV_Msk                    (0x1U << RCC_AHBRSTR_HWDIV_Pos)                   /*!<HWDIV Reset*/
#define  RCC_AHBRSTR_HWDIV                        RCC_AHBRSTR_HWDIV_Msk


#endif

