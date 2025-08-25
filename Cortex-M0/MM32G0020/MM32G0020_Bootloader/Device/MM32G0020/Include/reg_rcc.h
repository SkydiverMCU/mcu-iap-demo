
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
#include "core_cm0.h"

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
    __IO uint32_t RESERVED0x0C[1];                /*!<                                               offset: 0x0C       */
    __IO uint32_t APB1RSTR;                       /*!<RCC APB1 Peripheral Reset Register             offset: 0x10       */
    __IO uint32_t AHBENR;                         /*!<RCC AHB Peripheral Clock Enable Register       offset: 0x14       */
    __IO uint32_t RESERVED0x18[1];                /*!<                                               offset: 0x18       */
    __IO uint32_t APB1ENR;                        /*!<RCC APB1Peripheral Clock Enable Register       offset: 0x1C       */
    __IO uint32_t RESERVED0x20[1];                /*!<                                               offset: 0x20       */
    __IO uint32_t CSR;                            /*!<RCC Control Status Register                    offset: 0x24       */
    __IO uint32_t AHBRSTR;                        /*!<RCC AHB Peripheral Reset Register              offset: 0x28       */
    __IO uint32_t CFGR2;                          /*!<RCC Clock Configuration Register 2             offset: 0x2C       */
    __IO uint32_t RESERVED0x30[4];                /*!<                                               offset: 0x30~0x3C  */
    __IO uint32_t SYSCFGR;                        /*!<RCC System Configuration Register              offset: 0x40       */
    __IO uint32_t RESERVED0x44[3];                /*!<                                               offset: 0x44~0x4C  */
    __IO uint32_t PLLCFGR;                        /*!<RCC PLL Configuration Register                 offset: 0x50       */
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                                       ((RCC_TypeDef *)RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define  RCC_CR_HSION_Pos                         (0)
#define  RCC_CR_HSION_Msk                         (0x1U << RCC_CR_HSION_Pos)                        /*!<Internal high-speed clock enable*/
#define  RCC_CR_HSION                             RCC_CR_HSION_Msk
#define  RCC_CR_HSIRDY_Pos                        (1)
#define  RCC_CR_HSIRDY_Msk                        (0x1U << RCC_CR_HSIRDY_Pos)                       /*!<Internal high-speed clock ready flag*/
#define  RCC_CR_HSIRDY                            RCC_CR_HSIRDY_Msk
#define  RCC_CR_HSELPFBYP_Pos                     (4)
#define  RCC_CR_HSELPFBYP_Msk                     (0x1U << RCC_CR_HSELPFBYP_Pos)                    /*!<Enable signal that LPF input signal directly output*/
#define  RCC_CR_HSELPFBYP                         RCC_CR_HSELPFBYP_Msk
#define  RCC_CR_HSELPFSEL_Pos                     (5)
#define  RCC_CR_HSELPFSEL_Msk                     (0x1U << RCC_CR_HSELPFSEL_Pos)                    /*!<LPF filter mode control*/
#define  RCC_CR_HSELPFSEL                         RCC_CR_HSELPFSEL_Msk
#define  RCC_CR_HSEDEGLITCHBYP_Pos                (6)
#define  RCC_CR_HSEDEGLITCHBYP_Msk                (0x1U << RCC_CR_HSEDEGLITCHBYP_Pos)               /*!<Bypass control bit of deglitching circuit*/
#define  RCC_CR_HSEDEGLITCHBYP                    RCC_CR_HSEDEGLITCHBYP_Msk
#define  RCC_CR_HSEDEGLITCHSEL_Pos                (7)
#define  RCC_CR_HSEDEGLITCHSEL_Msk                (0x1U << RCC_CR_HSEDEGLITCHSEL_Pos)               /*!<Deglitching width control bit*/
#define  RCC_CR_HSEDEGLITCHSEL                    RCC_CR_HSEDEGLITCHSEL_Msk
#define  RCC_CR_HSEOUTPUTSEL_Pos                  (8)
#define  RCC_CR_HSEOUTPUTSEL_Msk                  (0x1U << RCC_CR_HSEOUTPUTSEL_Pos)                 /*!<Output mode selection*/
#define  RCC_CR_HSEOUTPUTSEL                      RCC_CR_HSEOUTPUTSEL_Msk
#define  RCC_CR_HSEON_Pos                         (16)
#define  RCC_CR_HSEON_Msk                         (0x1U << RCC_CR_HSEON_Pos)                        /*!<External High-speed Clock Enable*/
#define  RCC_CR_HSEON                             RCC_CR_HSEON_Msk
#define  RCC_CR_HSERDY_Pos                        (17)
#define  RCC_CR_HSERDY_Msk                        (0x1U << RCC_CR_HSERDY_Pos)                       /*!<External high-speed clock ready flag*/
#define  RCC_CR_HSERDY                            RCC_CR_HSERDY_Msk
#define  RCC_CR_HSEBYP_Pos                        (18)
#define  RCC_CR_HSEBYP_Msk                        (0x1U << RCC_CR_HSEBYP_Pos)                       /*!<External High-speed Clock Bypass*/
#define  RCC_CR_HSEBYP                            RCC_CR_HSEBYP_Msk
#define  RCC_CR_CSSON_Pos                         (19)
#define  RCC_CR_CSSON_Msk                         (0x1U << RCC_CR_CSSON_Pos)                        /*!<Clock security system enable*/
#define  RCC_CR_CSSON                             RCC_CR_CSSON_Msk
#define  RCC_CR_PLLON_Pos                         (24)
#define  RCC_CR_PLLON_Msk                         (0x1U << RCC_CR_PLLON_Pos)                        /*!<PLL enable*/
#define  RCC_CR_PLLON                             RCC_CR_PLLON_Msk
#define  RCC_CR_PLLRDY_Pos                        (25)
#define  RCC_CR_PLLRDY_Msk                        (0x1U << RCC_CR_PLLRDY_Pos)                       /*!<PLL Clock Ready Flag*/
#define  RCC_CR_PLLRDY                            RCC_CR_PLLRDY_Msk

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
#define  RCC_CIR_HSIRDYF_Pos                      (2)
#define  RCC_CIR_HSIRDYF_Msk                      (0x1U << RCC_CIR_HSIRDYF_Pos)                     /*!<HSI Ready Interrupt Flag*/
#define  RCC_CIR_HSIRDYF                          RCC_CIR_HSIRDYF_Msk
#define  RCC_CIR_HSERDYF_Pos                      (3)
#define  RCC_CIR_HSERDYF_Msk                      (0x1U << RCC_CIR_HSERDYF_Pos)                     /*!<HSE Ready Interrupt Flag*/
#define  RCC_CIR_HSERDYF                          RCC_CIR_HSERDYF_Msk
#define  RCC_CIR_PLLRDYF_Pos                      (4)
#define  RCC_CIR_PLLRDYF_Msk                      (0x1U << RCC_CIR_PLLRDYF_Pos)                     /*!<PLL ready interrupt flag*/
#define  RCC_CIR_PLLRDYF                          RCC_CIR_PLLRDYF_Msk
#define  RCC_CIR_CSSF_Pos                         (7)
#define  RCC_CIR_CSSF_Msk                         (0x1U << RCC_CIR_CSSF_Pos)                        /*!<Clock Security System Interrupt Flag*/
#define  RCC_CIR_CSSF                             RCC_CIR_CSSF_Msk
#define  RCC_CIR_LSIRDYIE_Pos                     (8)
#define  RCC_CIR_LSIRDYIE_Msk                     (0x1U << RCC_CIR_LSIRDYIE_Pos)                    /*!<LSI Ready Interrupt Enable*/
#define  RCC_CIR_LSIRDYIE                         RCC_CIR_LSIRDYIE_Msk
#define  RCC_CIR_HSIRDYIE_Pos                     (10)
#define  RCC_CIR_HSIRDYIE_Msk                     (0x1U << RCC_CIR_HSIRDYIE_Pos)                    /*!<HSI Ready Interrupt Enable*/
#define  RCC_CIR_HSIRDYIE                         RCC_CIR_HSIRDYIE_Msk
#define  RCC_CIR_HSERDYIE_Pos                     (11)
#define  RCC_CIR_HSERDYIE_Msk                     (0x1U << RCC_CIR_HSERDYIE_Pos)                    /*!<HSE ready interrupt enable*/
#define  RCC_CIR_HSERDYIE                         RCC_CIR_HSERDYIE_Msk
#define  RCC_CIR_PLLRDYIE_Pos                     (12)
#define  RCC_CIR_PLLRDYIE_Msk                     (0x1U << RCC_CIR_PLLRDYIE_Pos)                    /*!<PLL ready interrupt enable*/
#define  RCC_CIR_PLLRDYIE                         RCC_CIR_PLLRDYIE_Msk
#define  RCC_CIR_LSIRDYC_Pos                      (16)
#define  RCC_CIR_LSIRDYC_Msk                      (0x1U << RCC_CIR_LSIRDYC_Pos)                     /*!<LSI Ready Interrupt Clear*/
#define  RCC_CIR_LSIRDYC                          RCC_CIR_LSIRDYC_Msk
#define  RCC_CIR_HSIRDYC_Pos                      (18)
#define  RCC_CIR_HSIRDYC_Msk                      (0x1U << RCC_CIR_HSIRDYC_Pos)                     /*!<HSI Ready Interrupt Clear*/
#define  RCC_CIR_HSIRDYC                          RCC_CIR_HSIRDYC_Msk
#define  RCC_CIR_HSERDYC_Pos                      (19)
#define  RCC_CIR_HSERDYC_Msk                      (0x1U << RCC_CIR_HSERDYC_Pos)                     /*!<HSE Ready Interrupt Clear*/
#define  RCC_CIR_HSERDYC                          RCC_CIR_HSERDYC_Msk
#define  RCC_CIR_PLLRDYC_Pos                      (20)
#define  RCC_CIR_PLLRDYC_Msk                      (0x1U << RCC_CIR_PLLRDYC_Pos)                     /*!<PLL ready interrupt clear*/
#define  RCC_CIR_PLLRDYC                          RCC_CIR_PLLRDYC_Msk
#define  RCC_CIR_CSSC_Pos                         (23)
#define  RCC_CIR_CSSC_Msk                         (0x1U << RCC_CIR_CSSC_Pos)                        /*!<Clock security system interrupt clear*/
#define  RCC_CIR_CSSC                             RCC_CIR_CSSC_Msk

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define  RCC_APB1RSTR_TIM3_Pos                    (1)
#define  RCC_APB1RSTR_TIM3_Msk                    (0x1U << RCC_APB1RSTR_TIM3_Pos)                   /*!<TIM3 Reset*/
#define  RCC_APB1RSTR_TIM3                        RCC_APB1RSTR_TIM3_Msk
#define  RCC_APB1RSTR_TIM1_Pos                    (2)
#define  RCC_APB1RSTR_TIM1_Msk                    (0x1U << RCC_APB1RSTR_TIM1_Pos)                   /*!<TIM1 Reset*/
#define  RCC_APB1RSTR_TIM1                        RCC_APB1RSTR_TIM1_Msk
#define  RCC_APB1RSTR_TIM14_Pos                   (3)
#define  RCC_APB1RSTR_TIM14_Msk                   (0x1U << RCC_APB1RSTR_TIM14_Pos)                  /*!<TIM14 Reset*/
#define  RCC_APB1RSTR_TIM14                       RCC_APB1RSTR_TIM14_Msk
#define  RCC_APB1RSTR_ADC_Pos                     (9)
#define  RCC_APB1RSTR_ADC_Msk                     (0x1U << RCC_APB1RSTR_ADC_Pos)                    /*!<ADC Reset*/
#define  RCC_APB1RSTR_ADC                         RCC_APB1RSTR_ADC_Msk
#define  RCC_APB1RSTR_SPI_Pos                     (12)
#define  RCC_APB1RSTR_SPI_Msk                     (0x1U << RCC_APB1RSTR_SPI_Pos)                    /*!<SPI Reset*/
#define  RCC_APB1RSTR_SPI                         RCC_APB1RSTR_SPI_Msk
#define  RCC_APB1RSTR_UART1_Pos                   (16)
#define  RCC_APB1RSTR_UART1_Msk                   (0x1U << RCC_APB1RSTR_UART1_Pos)                  /*!<UART1 Reset*/
#define  RCC_APB1RSTR_UART1                       RCC_APB1RSTR_UART1_Msk
#define  RCC_APB1RSTR_UART2_Pos                   (17)
#define  RCC_APB1RSTR_UART2_Msk                   (0x1U << RCC_APB1RSTR_UART2_Pos)                  /*!<UART2 Reset*/
#define  RCC_APB1RSTR_UART2                       RCC_APB1RSTR_UART2_Msk
#define  RCC_APB1RSTR_I2C_Pos                     (21)
#define  RCC_APB1RSTR_I2C_Msk                     (0x1U << RCC_APB1RSTR_I2C_Pos)                    /*!<I2C Reset*/
#define  RCC_APB1RSTR_I2C                         RCC_APB1RSTR_I2C_Msk
#define  RCC_APB1RSTR_PWR_Pos                     (28)
#define  RCC_APB1RSTR_PWR_Msk                     (0x1U << RCC_APB1RSTR_PWR_Pos)                    /*!<Power Interface Reset*/
#define  RCC_APB1RSTR_PWR                         RCC_APB1RSTR_PWR_Msk
#define  RCC_APB1RSTR_DBG_Pos                     (29)
#define  RCC_APB1RSTR_DBG_Msk                     (0x1U << RCC_APB1RSTR_DBG_Pos)                    /*!<DBG Reset*/
#define  RCC_APB1RSTR_DBG                         RCC_APB1RSTR_DBG_Msk
#define  RCC_APB1RSTR_SYSCFG_Pos                  (30)
#define  RCC_APB1RSTR_SYSCFG_Msk                  (0x1U << RCC_APB1RSTR_SYSCFG_Pos)                 /*!<SYSCFG Reset*/
#define  RCC_APB1RSTR_SYSCFG                      RCC_APB1RSTR_SYSCFG_Msk

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
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

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define  RCC_APB1ENR_TIM3_Pos                     (1)
#define  RCC_APB1ENR_TIM3_Msk                     (0x1U << RCC_APB1ENR_TIM3_Pos)                    /*!<TIM3 Clock Enable*/
#define  RCC_APB1ENR_TIM3                         RCC_APB1ENR_TIM3_Msk
#define  RCC_APB1ENR_TIM1_Pos                     (2)
#define  RCC_APB1ENR_TIM1_Msk                     (0x1U << RCC_APB1ENR_TIM1_Pos)                    /*!<TIM1 Clock Enable*/
#define  RCC_APB1ENR_TIM1                         RCC_APB1ENR_TIM1_Msk
#define  RCC_APB1ENR_TIM14_Pos                    (3)
#define  RCC_APB1ENR_TIM14_Msk                    (0x1U << RCC_APB1ENR_TIM14_Pos)                   /*!<TIM14 Clock Enable*/
#define  RCC_APB1ENR_TIM14                        RCC_APB1ENR_TIM14_Msk
#define  RCC_APB1ENR_IWDG_Pos                     (6)
#define  RCC_APB1ENR_IWDG_Msk                     (0x1U << RCC_APB1ENR_IWDG_Pos)                    /*!<IWDG Clock Enable*/
#define  RCC_APB1ENR_IWDG                         RCC_APB1ENR_IWDG_Msk
#define  RCC_APB1ENR_EXTI_Pos                     (7)
#define  RCC_APB1ENR_EXTI_Msk                     (0x1U << RCC_APB1ENR_EXTI_Pos)                    /*!<EXTI Clock Enable*/
#define  RCC_APB1ENR_EXTI                         RCC_APB1ENR_EXTI_Msk
#define  RCC_APB1ENR_ADC_Pos                      (9)
#define  RCC_APB1ENR_ADC_Msk                      (0x1U << RCC_APB1ENR_ADC_Pos)                     /*!<ADC Clock Enable*/
#define  RCC_APB1ENR_ADC                          RCC_APB1ENR_ADC_Msk
#define  RCC_APB1ENR_SPI_Pos                      (12)
#define  RCC_APB1ENR_SPI_Msk                      (0x1U << RCC_APB1ENR_SPI_Pos)                     /*!<SPI Clock Enable*/
#define  RCC_APB1ENR_SPI                          RCC_APB1ENR_SPI_Msk
#define  RCC_APB1ENR_UART1_Pos                    (16)
#define  RCC_APB1ENR_UART1_Msk                    (0x1U << RCC_APB1ENR_UART1_Pos)                   /*!<UART1 Clock Enable*/
#define  RCC_APB1ENR_UART1                        RCC_APB1ENR_UART1_Msk
#define  RCC_APB1ENR_UART2_Pos                    (17)
#define  RCC_APB1ENR_UART2_Msk                    (0x1U << RCC_APB1ENR_UART2_Pos)                   /*!<UART2 Clock Enable*/
#define  RCC_APB1ENR_UART2                        RCC_APB1ENR_UART2_Msk
#define  RCC_APB1ENR_I2C_Pos                      (21)
#define  RCC_APB1ENR_I2C_Msk                      (0x1U << RCC_APB1ENR_I2C_Pos)                     /*!<I2C Clock Enable*/
#define  RCC_APB1ENR_I2C                          RCC_APB1ENR_I2C_Msk
#define  RCC_APB1ENR_PWR_Pos                      (28)
#define  RCC_APB1ENR_PWR_Msk                      (0x1U << RCC_APB1ENR_PWR_Pos)                     /*!<Power Clock Enable*/
#define  RCC_APB1ENR_PWR                          RCC_APB1ENR_PWR_Msk
#define  RCC_APB1ENR_DBG_Pos                      (29)
#define  RCC_APB1ENR_DBG_Msk                      (0x1U << RCC_APB1ENR_DBG_Pos)                     /*!<DBG Clock Enable*/
#define  RCC_APB1ENR_DBG                          RCC_APB1ENR_DBG_Msk
#define  RCC_APB1ENR_SYSCFG_Pos                   (30)
#define  RCC_APB1ENR_SYSCFG_Msk                   (0x1U << RCC_APB1ENR_SYSCFG_Pos)                  /*!<SYSCFG Clock Enable*/
#define  RCC_APB1ENR_SYSCFG                       RCC_APB1ENR_SYSCFG_Msk

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
#define  RCC_CSR_LPWRRSTF_Msk                     (0x1U << RCC_CSR_LPWRRSTF_Pos)                    /*!<Low power reset flag*/
#define  RCC_CSR_LPWRRSTF                         RCC_CSR_LPWRRSTF_Msk

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define  RCC_AHBRSTR_CRC_Pos                      (6)
#define  RCC_AHBRSTR_CRC_Msk                      (0x1U << RCC_AHBRSTR_CRC_Pos)                     /*!<CRC Reset*/
#define  RCC_AHBRSTR_CRC                          RCC_AHBRSTR_CRC_Msk
#define  RCC_AHBRSTR_GPIOA_Pos                    (17)
#define  RCC_AHBRSTR_GPIOA_Msk                    (0x1U << RCC_AHBRSTR_GPIOA_Pos)                   /*!<GPIOA Reset*/
#define  RCC_AHBRSTR_GPIOA                        RCC_AHBRSTR_GPIOA_Msk
#define  RCC_AHBRSTR_GPIOB_Pos                    (18)
#define  RCC_AHBRSTR_GPIOB_Msk                    (0x1U << RCC_AHBRSTR_GPIOB_Pos)                   /*!<GPIOB Reset*/
#define  RCC_AHBRSTR_GPIOB                        RCC_AHBRSTR_GPIOB_Msk

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define  RCC_CFGR2_MCOPRE_Pos                     (20)
#define  RCC_CFGR2_MCOPRE_Msk                     (0xFU << RCC_CFGR2_MCOPRE_Pos)                    /*!<MCO clock prescaler factor*/
#define  RCC_CFGR2_MCOPRE                         RCC_CFGR2_MCOPRE_Msk
#define  RCC_CFGR2_MCOPRE_0                       (0x1U << RCC_CFGR2_MCOPRE_Pos) 
#define  RCC_CFGR2_MCOPRE_1                       (0x2U << RCC_CFGR2_MCOPRE_Pos) 
#define  RCC_CFGR2_MCOPRE_2                       (0x4U << RCC_CFGR2_MCOPRE_Pos) 
#define  RCC_CFGR2_MCOPRE_3                       (0x8U << RCC_CFGR2_MCOPRE_Pos) 

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define  RCC_SYSCFG_PROG_CHECK_EN_Pos             (0)
#define  RCC_SYSCFG_PROG_CHECK_EN_Msk             (0x1U << RCC_SYSCFG_PROG_CHECK_EN_Pos)            /*!<Check whether the data in Flash is 0xFF when writing Flash*/
#define  RCC_SYSCFG_PROG_CHECK_EN                 RCC_SYSCFG_PROG_CHECK_EN_Msk
#define  RCC_SYSCFG_HSE_RFB_SEL_Pos               (8)
#define  RCC_SYSCFG_HSE_RFB_SEL_Msk               (0x3U << RCC_SYSCFG_HSE_RFB_SEL_Pos)              /*!<Feedback resistor selection.*/
#define  RCC_SYSCFG_HSE_RFB_SEL                   RCC_SYSCFG_HSE_RFB_SEL_Msk
#define  RCC_SYSCFG_HSE_RFB_SEL_0                 (0x1U << RCC_SYSCFG_HSE_RFB_SEL_Pos) 
#define  RCC_SYSCFG_HSE_RFB_SEL_1                 (0x2U << RCC_SYSCFG_HSE_RFB_SEL_Pos) 
#define  RCC_SYSCFG_HSELPFEN_Pos                  (14)
#define  RCC_SYSCFG_HSELPFEN_Msk                  (0x1U << RCC_SYSCFG_HSELPFEN_Pos)                 /*!<External crystal low-pass filter enable*/
#define  RCC_SYSCFG_HSELPFEN                      RCC_SYSCFG_HSELPFEN_Msk

/**
  * @brief RCC_PLLCFGR Register Bit Definition
  */
#define  RCC_PLLCFGR_PLLSRC_Pos                   (0)
#define  RCC_PLLCFGR_PLLSRC_Msk                   (0x1U << RCC_PLLCFGR_PLLSRC_Pos)                  /*!<PLL input clock source selection*/
#define  RCC_PLLCFGR_PLLSRC                       RCC_PLLCFGR_PLLSRC_Msk
#define  RCC_PLLCFGR_PLLXTPRE_Pos                 (1)
#define  RCC_PLLCFGR_PLLXTPRE_Msk                 (0x1U << RCC_PLLCFGR_PLLXTPRE_Pos)                /*!<Division selection when HSE clock is used as PLL input*/
#define  RCC_PLLCFGR_PLLXTPRE                     RCC_PLLCFGR_PLLXTPRE_Msk
#define  RCC_PLLCFGR_PLL_ICTRL_Pos                (2)
#define  RCC_PLLCFGR_PLL_ICTRL_Msk                (0x3U << RCC_PLLCFGR_PLL_ICTRL_Pos)               /*!<PLL CP current control signal*/
#define  RCC_PLLCFGR_PLL_ICTRL                    RCC_PLLCFGR_PLL_ICTRL_Msk
#define  RCC_PLLCFGR_PLL_ICTRL_0                  (0x1U << RCC_PLLCFGR_PLL_ICTRL_Pos) 
#define  RCC_PLLCFGR_PLL_ICTRL_1                  (0x2U << RCC_PLLCFGR_PLL_ICTRL_Pos) 
#define  RCC_PLLCFGR_PLL_LDS_Pos                  (4)
#define  RCC_PLLCFGR_PLL_LDS_Msk                  (0x3U << RCC_PLLCFGR_PLL_LDS_Pos)                 /*!<PLL lock detector accuracy selection*/
#define  RCC_PLLCFGR_PLL_LDS                      RCC_PLLCFGR_PLL_LDS_Msk
#define  RCC_PLLCFGR_PLL_LDS_0                    (0x1U << RCC_PLLCFGR_PLL_LDS_Pos) 
#define  RCC_PLLCFGR_PLL_LDS_1                    (0x2U << RCC_PLLCFGR_PLL_LDS_Pos) 
#define  RCC_PLLCFGR_PLLDIV_Pos                   (8)
#define  RCC_PLLCFGR_PLLDIV_Msk                   (0x7U << RCC_PLLCFGR_PLLDIV_Pos)                  /*!<PLL divide factor*/
#define  RCC_PLLCFGR_PLLDIV                       RCC_PLLCFGR_PLLDIV_Msk
#define  RCC_PLLCFGR_PLLDIV_0                     (0x1U << RCC_PLLCFGR_PLLDIV_Pos) 
#define  RCC_PLLCFGR_PLLDIV_1                     (0x2U << RCC_PLLCFGR_PLLDIV_Pos) 
#define  RCC_PLLCFGR_PLLDIV_2                     (0x4U << RCC_PLLCFGR_PLLDIV_Pos) 
#define  RCC_PLLCFGR_PLLMUL_Pos                   (16)
#define  RCC_PLLCFGR_PLLMUL_Msk                   (0xFFU << RCC_PLLCFGR_PLLMUL_Pos)                 /*!<PLL Multiplication Factor*/
#define  RCC_PLLCFGR_PLLMUL                       RCC_PLLCFGR_PLLMUL_Msk
#define  RCC_PLLCFGR_PLLMUL_0                     (0x01U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_1                     (0x02U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_2                     (0x04U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_3                     (0x08U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_4                     (0x10U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_5                     (0x20U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_6                     (0x40U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLMUL_7                     (0x80U << RCC_PLLCFGR_PLLMUL_Pos) 
#define  RCC_PLLCFGR_PLLPDIV_Pos                  (29)
#define  RCC_PLLCFGR_PLLPDIV_Msk                  (0x7U << RCC_PLLCFGR_PLLPDIV_Pos)                 /*!<PLL Pre-divide Factor*/
#define  RCC_PLLCFGR_PLLPDIV                      RCC_PLLCFGR_PLLPDIV_Msk
#define  RCC_PLLCFGR_PLLPDIV_0                    (0x1U << RCC_PLLCFGR_PLLPDIV_Pos) 
#define  RCC_PLLCFGR_PLLPDIV_1                    (0x2U << RCC_PLLCFGR_PLLPDIV_Pos) 
#define  RCC_PLLCFGR_PLLPDIV_2                    (0x4U << RCC_PLLCFGR_PLLPDIV_Pos) 

/** ------------------------------------------------------------------------------------------------------------------*/
#endif
/** ------------------------------------------------------------------------------------------------------------------*/
