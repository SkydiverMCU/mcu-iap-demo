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
#include <core_cm0plus.h>



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
    __IO uint32_t CFGR2;                          /*!<RCC Clock Configuration Register 2             offset: 0x2C       */
    __IO uint32_t RESERVED0x30[4];                /*!<                                               offset: 0x30~0x3C  */
    __IO uint32_t SYSCFG;                         /*!<RCC System Configuration Register              offset: 0x40       */
    __IO uint32_t HSIDLY;                         /*!<RCC HSI clock delay register                   offset: 0x44       */
    __IO uint32_t HSEDLY;                         /*!<RCC HSE clock delay register                   offset: 0x48       */
    __IO uint32_t ICSCR;                          /*!<RCC Internal clock source calibration          offset: 0x4C
                                                      register                                                          */
    __IO uint32_t RESERVED0x50[1];                /*!<                                               offset: 0x50       */
    __IO uint32_t FRVSCR;                         /*!<RCC Reference voltage calibration register     offset: 0x54       */
    __IO uint32_t RESERVED0x58[2];                /*!<                                               offset: 0x58~0x5C  */
    __IO uint32_t LSCCR;                          /*!<RCC Low Speed Clock Control Register           offset: 0x60       */
    __IO uint32_t RESERVED0x64[7];                /*!<                                               offset: 0x64~0x7C  */
    __IO uint32_t LDOCR;                          /*!<RCC LDO configuration register                 offset: 0x80       */
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
#define  RCC_CR_DEGLITCHBYP_Pos                   (6)
#define  RCC_CR_DEGLITCHBYP_Msk                   (0x1U << RCC_CR_DEGLITCHBYP_Pos)                  /*!<Deburring Circuit Bypass Control Bit*/
#define  RCC_CR_DEGLITCHBYP                       RCC_CR_DEGLITCHBYP_Msk
#define  RCC_CR_DEGLITCHSEL_Pos                   (7)
#define  RCC_CR_DEGLITCHSEL_Msk                   (0x1U << RCC_CR_DEGLITCHSEL_Pos)                  /*!<Deburring Width Control Bit*/
#define  RCC_CR_DEGLITCHSEL                       RCC_CR_DEGLITCHSEL_Msk
#define  RCC_CR_HSEOUTPUTSEL_Pos                  (8)
#define  RCC_CR_HSEOUTPUTSEL_Msk                  (0x1U << RCC_CR_HSEOUTPUTSEL_Pos)                 /*!<Output Mode Selector*/
#define  RCC_CR_HSEOUTPUTSEL                      RCC_CR_HSEOUTPUTSEL_Msk
#define  RCC_CR_HSIDIV_Pos                        (11)
#define  RCC_CR_HSIDIV_Msk                        (0xFU << RCC_CR_HSIDIV_Pos)                       /*!<Internal high-speed clock division factor*/
#define  RCC_CR_HSIDIV                            RCC_CR_HSIDIV_Msk
#define  RCC_CR_HSIDIV_0                          (0x1U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSIDIV_1                          (0x2U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSIDIV_2                          (0x4U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSIDIV_3                          (0x8U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSEON_Pos                         (16)
#define  RCC_CR_HSEON_Msk                         (0x1U << RCC_CR_HSEON_Pos)                        /*!<External High-speed Clock Enable*/
#define  RCC_CR_HSEON                             RCC_CR_HSEON_Msk
#define  RCC_CR_HSERDY_Pos                        (17)
#define  RCC_CR_HSERDY_Msk                        (0x1U << RCC_CR_HSERDY_Pos)                       /*!<External High-speed Clock Ready Flag*/
#define  RCC_CR_HSERDY                            RCC_CR_HSERDY_Msk
#define  RCC_CR_HSEBYP_Pos                        (18)
#define  RCC_CR_HSEBYP_Msk                        (0x1U << RCC_CR_HSEBYP_Pos)                       /*!<External High-speed Clock Bypass*/
#define  RCC_CR_HSEBYP                            RCC_CR_HSEBYP_Msk
#define  RCC_CR_CSSHSON_Pos                       (19)
#define  RCC_CR_CSSHSON_Msk                       (0x1U << RCC_CR_CSSHSON_Pos)                      /*!<Clock Security System HSE High Souce Enable*/
#define  RCC_CR_CSSHSON                           RCC_CR_CSSHSON_Msk
#define  RCC_CR_CSSLSON_Pos                       (20)
#define  RCC_CR_CSSLSON_Msk                       (0x1U << RCC_CR_CSSLSON_Pos)                      /*!<Clock Security System Low Souce Enable*/
#define  RCC_CR_CSSLSON                           RCC_CR_CSSLSON_Msk
#define  RCC_CR_FLEN_Pos                          (31)
#define  RCC_CR_FLEN_Msk                          (0x1U << RCC_CR_FLEN_Pos)                         /*!<Frass Lip mode clock enabled*/
#define  RCC_CR_FLEN                              RCC_CR_FLEN_Msk

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
#define  RCC_CFGR_CK_OFF_Pos                      (14)
#define  RCC_CFGR_CK_OFF_Msk                      (0x1U << RCC_CFGR_CK_OFF_Pos)                     /*!<In STOP mode, the clock turns off the control bit*/
#define  RCC_CFGR_CK_OFF                          RCC_CFGR_CK_OFF_Msk
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
#define  RCC_CIR_CSSLSF_Pos                       (6)
#define  RCC_CIR_CSSLSF_Msk                       (0x1U << RCC_CIR_CSSLSF_Pos)                      /*!<Clock Security System Low Source Interrupt Flag*/
#define  RCC_CIR_CSSLSF                           RCC_CIR_CSSLSF_Msk
#define  RCC_CIR_CSSHSF_Pos                       (7)
#define  RCC_CIR_CSSHSF_Msk                       (0x1U << RCC_CIR_CSSHSF_Pos)                      /*!<Clock Security System High Source Interrupt Flag*/
#define  RCC_CIR_CSSHSF                           RCC_CIR_CSSHSF_Msk
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
#define  RCC_CIR_CSSLSC_Pos                       (22)
#define  RCC_CIR_CSSLSC_Msk                       (0x1U << RCC_CIR_CSSLSC_Pos)                      /*!<Clock Security System Low Source Interrupt Clear*/
#define  RCC_CIR_CSSLSC                           RCC_CIR_CSSLSC_Msk
#define  RCC_CIR_CSSHSC_Pos                       (23)
#define  RCC_CIR_CSSHSC_Msk                       (0x1U << RCC_CIR_CSSHSC_Pos)                      /*!<Clock Security System High Source Interrupt Clear*/
#define  RCC_CIR_CSSHSC                           RCC_CIR_CSSHSC_Msk

/**
  * @brief RCC_APB2RSTR Register Bit Definition
  */
#define  RCC_APB2RSTR_SYSCFG_Pos                  (0)
#define  RCC_APB2RSTR_SYSCFG_Msk                  (0x1U << RCC_APB2RSTR_SYSCFG_Pos)                 /*!<SYSCFG Reset*/
#define  RCC_APB2RSTR_SYSCFG                      RCC_APB2RSTR_SYSCFG_Msk
#define  RCC_APB2RSTR_AES_Pos                     (1)
#define  RCC_APB2RSTR_AES_Msk                     (0x1U << RCC_APB2RSTR_AES_Pos)                    /*!<AESRST Reset*/
#define  RCC_APB2RSTR_AES                         RCC_APB2RSTR_AES_Msk
#define  RCC_APB2RSTR_TRNG_Pos                    (2)
#define  RCC_APB2RSTR_TRNG_Msk                    (0x1U << RCC_APB2RSTR_TRNG_Pos)                   /*!<TRNGRST Reset*/
#define  RCC_APB2RSTR_TRNG                        RCC_APB2RSTR_TRNG_Msk
#define  RCC_APB2RSTR_ADC_Pos                     (9)
#define  RCC_APB2RSTR_ADC_Msk                     (0x1U << RCC_APB2RSTR_ADC_Pos)                    /*!<ADC Reset*/
#define  RCC_APB2RSTR_ADC                         RCC_APB2RSTR_ADC_Msk
#define  RCC_APB2RSTR_SPI1_Pos                    (12)
#define  RCC_APB2RSTR_SPI1_Msk                    (0x1U << RCC_APB2RSTR_SPI1_Pos)                   /*!<SPI1 Reset*/
#define  RCC_APB2RSTR_SPI1                        RCC_APB2RSTR_SPI1_Msk
#define  RCC_APB2RSTR_USART1_Pos                  (14)
#define  RCC_APB2RSTR_USART1_Msk                  (0x1U << RCC_APB2RSTR_USART1_Pos)                 /*!<USART1 Reset*/
#define  RCC_APB2RSTR_USART1                      RCC_APB2RSTR_USART1_Msk
#define  RCC_APB2RSTR_COMP_Pos                    (15)
#define  RCC_APB2RSTR_COMP_Msk                    (0x1U << RCC_APB2RSTR_COMP_Pos)                   /*!<Comparator reset*/
#define  RCC_APB2RSTR_COMP                        RCC_APB2RSTR_COMP_Msk
#define  RCC_APB2RSTR_TIM16_Pos                   (17)
#define  RCC_APB2RSTR_TIM16_Msk                   (0x1U << RCC_APB2RSTR_TIM16_Pos)                  /*!<TIM16 Reset*/
#define  RCC_APB2RSTR_TIM16                       RCC_APB2RSTR_TIM16_Msk
#define  RCC_APB2RSTR_TIM17_Pos                   (18)
#define  RCC_APB2RSTR_TIM17_Msk                   (0x1U << RCC_APB2RSTR_TIM17_Pos)                  /*!<TIM17 Reset*/
#define  RCC_APB2RSTR_TIM17                       RCC_APB2RSTR_TIM17_Msk
#define  RCC_APB2RSTR_LPTIM2_Pos                  (19)
#define  RCC_APB2RSTR_LPTIM2_Msk                  (0x1U << RCC_APB2RSTR_LPTIM2_Pos)                 /*!<LPTIM2 reset*/
#define  RCC_APB2RSTR_LPTIM2                      RCC_APB2RSTR_LPTIM2_Msk
#define  RCC_APB2RSTR_DBG_Pos                     (22)
#define  RCC_APB2RSTR_DBG_Msk                     (0x1U << RCC_APB2RSTR_DBG_Pos)                    /*!<DBGMCU Reset*/
#define  RCC_APB2RSTR_DBG                         RCC_APB2RSTR_DBG_Msk
#define  RCC_APB2RSTR_LPUART2_Pos                 (23)
#define  RCC_APB2RSTR_LPUART2_Msk                 (0x1U << RCC_APB2RSTR_LPUART2_Pos)                /*!<LPUART2 reset*/
#define  RCC_APB2RSTR_LPUART2                     RCC_APB2RSTR_LPUART2_Msk
#define  RCC_APB2RSTR_LPTIM1_Pos                  (30)
#define  RCC_APB2RSTR_LPTIM1_Msk                  (0x1U << RCC_APB2RSTR_LPTIM1_Pos)                 /*!<LPTIM1 reset*/
#define  RCC_APB2RSTR_LPTIM1                      RCC_APB2RSTR_LPTIM1_Msk
#define  RCC_APB2RSTR_LPUART1_Pos                 (31)
#define  RCC_APB2RSTR_LPUART1_Msk                 (0x1U << RCC_APB2RSTR_LPUART1_Pos)                /*!<LPUART1 reset*/
#define  RCC_APB2RSTR_LPUART1                     RCC_APB2RSTR_LPUART1_Msk

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define  RCC_APB1RSTR_TIM3_Pos                    (1)
#define  RCC_APB1RSTR_TIM3_Msk                    (0x1U << RCC_APB1RSTR_TIM3_Pos)                   /*!<TIM3 Reset*/
#define  RCC_APB1RSTR_TIM3                        RCC_APB1RSTR_TIM3_Msk
#define  RCC_APB1RSTR_TIM4_Pos                    (2)
#define  RCC_APB1RSTR_TIM4_Msk                    (0x1U << RCC_APB1RSTR_TIM4_Pos)                   /*!<TIM4 Reset*/
#define  RCC_APB1RSTR_TIM4                        RCC_APB1RSTR_TIM4_Msk
#define  RCC_APB1RSTR_LPTIM3_Pos                  (4)
#define  RCC_APB1RSTR_LPTIM3_Msk                  (0x1U << RCC_APB1RSTR_LPTIM3_Pos)                 /*!<LPTIM3 Reset*/
#define  RCC_APB1RSTR_LPTIM3                      RCC_APB1RSTR_LPTIM3_Msk
#define  RCC_APB1RSTR_LPTIM4_Pos                  (5)
#define  RCC_APB1RSTR_LPTIM4_Msk                  (0x1U << RCC_APB1RSTR_LPTIM4_Pos)                 /*!<LPTIM4 Reset*/
#define  RCC_APB1RSTR_LPTIM4                      RCC_APB1RSTR_LPTIM4_Msk
#define  RCC_APB1RSTR_IRM_Pos                     (10)
#define  RCC_APB1RSTR_IRM_Msk                     (0x1U << RCC_APB1RSTR_IRM_Pos)                    /*!<Infrared Modulator Reset*/
#define  RCC_APB1RSTR_IRM                         RCC_APB1RSTR_IRM_Msk
#define  RCC_APB1RSTR_UART2_Pos                   (17)
#define  RCC_APB1RSTR_UART2_Msk                   (0x1U << RCC_APB1RSTR_UART2_Pos)                  /*!<UART2 Reset*/
#define  RCC_APB1RSTR_UART2                       RCC_APB1RSTR_UART2_Msk
#define  RCC_APB1RSTR_LPUART3_Pos                 (18)
#define  RCC_APB1RSTR_LPUART3_Msk                 (0x1U << RCC_APB1RSTR_LPUART3_Pos)                /*!<LPUART3 Reset*/
#define  RCC_APB1RSTR_LPUART3                     RCC_APB1RSTR_LPUART3_Msk
#define  RCC_APB1RSTR_LPUART4_Pos                 (19)
#define  RCC_APB1RSTR_LPUART4_Msk                 (0x1U << RCC_APB1RSTR_LPUART4_Pos)                /*!<LPUART4 Reset*/
#define  RCC_APB1RSTR_LPUART4                     RCC_APB1RSTR_LPUART4_Msk
#define  RCC_APB1RSTR_LPUART5_Pos                 (20)
#define  RCC_APB1RSTR_LPUART5_Msk                 (0x1U << RCC_APB1RSTR_LPUART5_Pos)                /*!<LPUART5 Reset*/
#define  RCC_APB1RSTR_LPUART5                     RCC_APB1RSTR_LPUART5_Msk
#define  RCC_APB1RSTR_I2C1_Pos                    (21)
#define  RCC_APB1RSTR_I2C1_Msk                    (0x1U << RCC_APB1RSTR_I2C1_Pos)                   /*!<2C1 Reset*/
#define  RCC_APB1RSTR_I2C1                        RCC_APB1RSTR_I2C1_Msk
#define  RCC_APB1RSTR_PWR_Pos                     (28)
#define  RCC_APB1RSTR_PWR_Msk                     (0x1U << RCC_APB1RSTR_PWR_Pos)                    /*!<Power Interface Reset*/
#define  RCC_APB1RSTR_PWR                         RCC_APB1RSTR_PWR_Msk

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
#define  RCC_AHBENR_FLASH_Msk                     (0x1U << RCC_AHBENR_FLASH_Pos)                    /*!<FLASH clock enable*/
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
#define  RCC_AHBENR_GPIOE_Pos                     (21)
#define  RCC_AHBENR_GPIOE_Msk                     (0x1U << RCC_AHBENR_GPIOE_Pos)                    /*!<GPIOE Clock Enable*/
#define  RCC_AHBENR_GPIOE                         RCC_AHBENR_GPIOE_Msk
#define  RCC_AHBENR_GPIOH_Pos                     (24)
#define  RCC_AHBENR_GPIOH_Msk                     (0x1U << RCC_AHBENR_GPIOH_Pos)                    /*!<GPIOH Clock Enable*/
#define  RCC_AHBENR_GPIOH                         RCC_AHBENR_GPIOH_Msk

/**
  * @brief RCC_APB2ENR Register Bit Definition
  */
#define  RCC_APB2ENR_SYSCFG_Pos                   (0)
#define  RCC_APB2ENR_SYSCFG_Msk                   (0x1U << RCC_APB2ENR_SYSCFG_Pos)                  /*!<SYSCFG Clock Enable*/
#define  RCC_APB2ENR_SYSCFG                       RCC_APB2ENR_SYSCFG_Msk
#define  RCC_APB2ENR_AES_Pos                      (1)
#define  RCC_APB2ENR_AES_Msk                      (0x1U << RCC_APB2ENR_AES_Pos)                     /*!<AESEN Clock Enable*/
#define  RCC_APB2ENR_AES                          RCC_APB2ENR_AES_Msk
#define  RCC_APB2ENR_TRNG_Pos                     (2)
#define  RCC_APB2ENR_TRNG_Msk                     (0x1U << RCC_APB2ENR_TRNG_Pos)                    /*!<TRNGEN Clock Enable*/
#define  RCC_APB2ENR_TRNG                         RCC_APB2ENR_TRNG_Msk
#define  RCC_APB2ENR_ADC_Pos                      (9)
#define  RCC_APB2ENR_ADC_Msk                      (0x1U << RCC_APB2ENR_ADC_Pos)                     /*!<ADC Clock Enable*/
#define  RCC_APB2ENR_ADC                          RCC_APB2ENR_ADC_Msk
#define  RCC_APB2ENR_SPI1_Pos                     (12)
#define  RCC_APB2ENR_SPI1_Msk                     (0x1U << RCC_APB2ENR_SPI1_Pos)                    /*!<SPI1 Clock Enable*/
#define  RCC_APB2ENR_SPI1                         RCC_APB2ENR_SPI1_Msk
#define  RCC_APB2ENR_USART1_Pos                   (14)
#define  RCC_APB2ENR_USART1_Msk                   (0x1U << RCC_APB2ENR_USART1_Pos)                  /*!<USART1 Clock Enable*/
#define  RCC_APB2ENR_USART1                       RCC_APB2ENR_USART1_Msk
#define  RCC_APB2ENR_COMP_Pos                     (15)
#define  RCC_APB2ENR_COMP_Msk                     (0x1U << RCC_APB2ENR_COMP_Pos)                    /*!<Comparator Clock Enable*/
#define  RCC_APB2ENR_COMP                         RCC_APB2ENR_COMP_Msk
#define  RCC_APB2ENR_TIM16_Pos                    (17)
#define  RCC_APB2ENR_TIM16_Msk                    (0x1U << RCC_APB2ENR_TIM16_Pos)                   /*!<TIM16 Clock Enable*/
#define  RCC_APB2ENR_TIM16                        RCC_APB2ENR_TIM16_Msk
#define  RCC_APB2ENR_TIM17_Pos                    (18)
#define  RCC_APB2ENR_TIM17_Msk                    (0x1U << RCC_APB2ENR_TIM17_Pos)                   /*!<TIM17 Clock Enable*/
#define  RCC_APB2ENR_TIM17                        RCC_APB2ENR_TIM17_Msk
#define  RCC_APB2ENR_LPTIM2_Pos                   (19)
#define  RCC_APB2ENR_LPTIM2_Msk                   (0x1U << RCC_APB2ENR_LPTIM2_Pos)                  /*!<LPTIM2 Clock Enable*/
#define  RCC_APB2ENR_LPTIM2                       RCC_APB2ENR_LPTIM2_Msk
#define  RCC_APB2ENR_DBG_Pos                      (22)
#define  RCC_APB2ENR_DBG_Msk                      (0x1U << RCC_APB2ENR_DBG_Pos)                     /*!<DBG Clock Enable*/
#define  RCC_APB2ENR_DBG                          RCC_APB2ENR_DBG_Msk
#define  RCC_APB2ENR_LPUART2_Pos                  (23)
#define  RCC_APB2ENR_LPUART2_Msk                  (0x1U << RCC_APB2ENR_LPUART2_Pos)                 /*!<LPUART2 Clock Enable*/
#define  RCC_APB2ENR_LPUART2                      RCC_APB2ENR_LPUART2_Msk
#define  RCC_APB2ENR_EXTI_Pos                     (29)
#define  RCC_APB2ENR_EXTI_Msk                     (0x1U << RCC_APB2ENR_EXTI_Pos)                    /*!<EXTI Clock Enable*/
#define  RCC_APB2ENR_EXTI                         RCC_APB2ENR_EXTI_Msk
#define  RCC_APB2ENR_LPTIM1_Pos                   (30)
#define  RCC_APB2ENR_LPTIM1_Msk                   (0x1U << RCC_APB2ENR_LPTIM1_Pos)                  /*!<LPTIM1 Clock Enable*/
#define  RCC_APB2ENR_LPTIM1                       RCC_APB2ENR_LPTIM1_Msk
#define  RCC_APB2ENR_LPUART1_Pos                  (31)
#define  RCC_APB2ENR_LPUART1_Msk                  (0x1U << RCC_APB2ENR_LPUART1_Pos)                 /*!<LPUART1 Clock Enable*/
#define  RCC_APB2ENR_LPUART1                      RCC_APB2ENR_LPUART1_Msk

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define  RCC_APB1ENR_TIM3_Pos                     (1)
#define  RCC_APB1ENR_TIM3_Msk                     (0x1U << RCC_APB1ENR_TIM3_Pos)                    /*!<TIM3 Clock Enable*/
#define  RCC_APB1ENR_TIM3                         RCC_APB1ENR_TIM3_Msk
#define  RCC_APB1ENR_TIM4_Pos                     (2)
#define  RCC_APB1ENR_TIM4_Msk                     (0x1U << RCC_APB1ENR_TIM4_Pos)                    /*!<TIM4 Clock Enable*/
#define  RCC_APB1ENR_TIM4                         RCC_APB1ENR_TIM4_Msk
#define  RCC_APB1ENR_LPTIM3_Pos                   (4)
#define  RCC_APB1ENR_LPTIM3_Msk                   (0x1U << RCC_APB1ENR_LPTIM3_Pos)                  /*!<LPTIM3 Clock Enable*/
#define  RCC_APB1ENR_LPTIM3                       RCC_APB1ENR_LPTIM3_Msk
#define  RCC_APB1ENR_LPTIM4_Pos                   (5)
#define  RCC_APB1ENR_LPTIM4_Msk                   (0x1U << RCC_APB1ENR_LPTIM4_Pos)                  /*!<LPTIM4 Clock Enable*/
#define  RCC_APB1ENR_LPTIM4                       RCC_APB1ENR_LPTIM4_Msk
#define  RCC_APB1ENR_IRM_Pos                      (10)
#define  RCC_APB1ENR_IRM_Msk                      (0x1U << RCC_APB1ENR_IRM_Pos)                     /*!<Infrared Module Clock Enable*/
#define  RCC_APB1ENR_IRM                          RCC_APB1ENR_IRM_Msk
#define  RCC_APB1ENR_USART2_Pos                   (17)
#define  RCC_APB1ENR_USART2_Msk                   (0x1U << RCC_APB1ENR_USART2_Pos)                  /*!<USART2 Clock Enable*/
#define  RCC_APB1ENR_USART2                       RCC_APB1ENR_USART2_Msk
#define  RCC_APB1ENR_LPUART3_Pos                  (18)
#define  RCC_APB1ENR_LPUART3_Msk                  (0x1U << RCC_APB1ENR_LPUART3_Pos)                 /*!<LPUART3 Clock Enable*/
#define  RCC_APB1ENR_LPUART3                      RCC_APB1ENR_LPUART3_Msk
#define  RCC_APB1ENR_LPUART4_Pos                  (19)
#define  RCC_APB1ENR_LPUART4_Msk                  (0x1U << RCC_APB1ENR_LPUART4_Pos)                 /*!<LPUART4 Clock Enable*/
#define  RCC_APB1ENR_LPUART4                      RCC_APB1ENR_LPUART4_Msk
#define  RCC_APB1ENR_LPUART5_Pos                  (20)
#define  RCC_APB1ENR_LPUART5_Msk                  (0x1U << RCC_APB1ENR_LPUART5_Pos)                 /*!<LPUART5 Clock Enable*/
#define  RCC_APB1ENR_LPUART5                      RCC_APB1ENR_LPUART5_Msk
#define  RCC_APB1ENR_I2C1_Pos                     (21)
#define  RCC_APB1ENR_I2C1_Msk                     (0x1U << RCC_APB1ENR_I2C1_Pos)                    /*!<I2C1 Clock Enable*/
#define  RCC_APB1ENR_I2C1                         RCC_APB1ENR_I2C1_Msk
#define  RCC_APB1ENR_BKP_Pos                      (24)
#define  RCC_APB1ENR_BKP_Msk                      (0x1U << RCC_APB1ENR_BKP_Pos)                     /*!<BKP Clock Enable*/
#define  RCC_APB1ENR_BKP                          RCC_APB1ENR_BKP_Msk
#define  RCC_APB1ENR_PWR_Pos                      (28)
#define  RCC_APB1ENR_PWR_Msk                      (0x1U << RCC_APB1ENR_PWR_Pos)                     /*!<Power Clock Enable*/
#define  RCC_APB1ENR_PWR                          RCC_APB1ENR_PWR_Msk
#define  RCC_APB1ENR_LCD_Pos                      (29)
#define  RCC_APB1ENR_LCD_Msk                      (0x1U << RCC_APB1ENR_LCD_Pos)                     /*!<LCD Clock Enable*/
#define  RCC_APB1ENR_LCD                          RCC_APB1ENR_LCD_Msk
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
#define  RCC_BDCR_LCDSEL_Pos                      (6)
#define  RCC_BDCR_LCDSEL_Msk                      (0x3U << RCC_BDCR_LCDSEL_Pos)                     /*!<LCD clock source selection*/
#define  RCC_BDCR_LCDSEL                          RCC_BDCR_LCDSEL_Msk
#define  RCC_BDCR_LCDSEL_0                        (0x1U << RCC_BDCR_LCDSEL_Pos) 
#define  RCC_BDCR_LCDSEL_1                        (0x2U << RCC_BDCR_LCDSEL_Pos) 
#define  RCC_BDCR_RTCSEL_Pos                      (8)
#define  RCC_BDCR_RTCSEL_Msk                      (0x3U << RCC_BDCR_RTCSEL_Pos)                     /*!<RTC Clock Source Selection*/
#define  RCC_BDCR_RTCSEL                          RCC_BDCR_RTCSEL_Msk
#define  RCC_BDCR_RTCSEL_0                        (0x1U << RCC_BDCR_RTCSEL_Pos) 
#define  RCC_BDCR_RTCSEL_1                        (0x2U << RCC_BDCR_RTCSEL_Pos) 
#define  RCC_BDCR_RTCEN_Pos                       (15)
#define  RCC_BDCR_RTCEN_Msk                       (0x1U << RCC_BDCR_RTCEN_Pos)                      /*!<RTC Clock Enable*/
#define  RCC_BDCR_RTCEN                           RCC_BDCR_RTCEN_Msk
#define  RCC_BDCR_RTCRST_Pos                      (16)
#define  RCC_BDCR_RTCRST_Msk                      (0x1U << RCC_BDCR_RTCRST_Pos)                     /*!<RTC/BKP software reset*/
#define  RCC_BDCR_RTCRST                          RCC_BDCR_RTCRST_Msk
#define  RCC_BDCR_LCDRST_Pos                      (17)
#define  RCC_BDCR_LCDRST_Msk                      (0x1U << RCC_BDCR_LCDRST_Pos)                     /*!<LCD software reset*/
#define  RCC_BDCR_LCDRST                          RCC_BDCR_LCDRST_Msk
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
#define  RCC_CSR_LSISEL_Pos                       (2)
#define  RCC_CSR_LSISEL_Msk                       (0x3U << RCC_CSR_LSISEL_Pos)                      /*!<LSI Clock Frequency Select Bit*/
#define  RCC_CSR_LSISEL                           RCC_CSR_LSISEL_Msk
#define  RCC_CSR_LSISEL_0                         (0x1U << RCC_CSR_LSISEL_Pos) 
#define  RCC_CSR_LSISEL_1                         (0x2U << RCC_CSR_LSISEL_Pos) 
#define  RCC_CSR_LSCLKSEL_Pos                     (4)
#define  RCC_CSR_LSCLKSEL_Msk                     (0x1U << RCC_CSR_LSCLKSEL_Pos)                    /*!<LSCLK Clock Source Select Bit*/
#define  RCC_CSR_LSCLKSEL                         RCC_CSR_LSCLKSEL_Msk
#define  RCC_CSR_LSI_OEN_LV_Pos                   (5)
#define  RCC_CSR_LSI_OEN_LV_Msk                   (0x1U << RCC_CSR_LSI_OEN_LV_Pos)                  /*!<LSI output enable lower voltage*/
#define  RCC_CSR_LSI_OEN_LV                       RCC_CSR_LSI_OEN_LV_Msk
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
#define  RCC_AHBRSTR_GPIOE_Pos                    (21)
#define  RCC_AHBRSTR_GPIOE_Msk                    (0x1U << RCC_AHBRSTR_GPIOE_Pos)                   /*!<GPIOE Reset*/
#define  RCC_AHBRSTR_GPIOE                        RCC_AHBRSTR_GPIOE_Msk
#define  RCC_AHBRSTR_GPIOH_Pos                    (24)
#define  RCC_AHBRSTR_GPIOH_Msk                    (0x1U << RCC_AHBRSTR_GPIOH_Pos)                   /*!<GPIOH Reset*/
#define  RCC_AHBRSTR_GPIOH                        RCC_AHBRSTR_GPIOH_Msk

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define  RCC_CFGR2_LPUART1CLKSEL_Pos              (0)
#define  RCC_CFGR2_LPUART1CLKSEL_Msk              (0x3U << RCC_CFGR2_LPUART1CLKSEL_Pos)             /*!<LPUART1 clock source selection*/
#define  RCC_CFGR2_LPUART1CLKSEL                  RCC_CFGR2_LPUART1CLKSEL_Msk
#define  RCC_CFGR2_LPUART1CLKSEL_0                (0x1U << RCC_CFGR2_LPUART1CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART1CLKSEL_1                (0x2U << RCC_CFGR2_LPUART1CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART2CLKSEL_Pos              (2)
#define  RCC_CFGR2_LPUART2CLKSEL_Msk              (0x3U << RCC_CFGR2_LPUART2CLKSEL_Pos)             /*!<LPUART2 clock source selection*/
#define  RCC_CFGR2_LPUART2CLKSEL                  RCC_CFGR2_LPUART2CLKSEL_Msk
#define  RCC_CFGR2_LPUART2CLKSEL_0                (0x1U << RCC_CFGR2_LPUART2CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART2CLKSEL_1                (0x2U << RCC_CFGR2_LPUART2CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART3CLKSEL_Pos              (4)
#define  RCC_CFGR2_LPUART3CLKSEL_Msk              (0x3U << RCC_CFGR2_LPUART3CLKSEL_Pos)             /*!<LPUART3 clock source selection*/
#define  RCC_CFGR2_LPUART3CLKSEL                  RCC_CFGR2_LPUART3CLKSEL_Msk
#define  RCC_CFGR2_LPUART3CLKSEL_0                (0x1U << RCC_CFGR2_LPUART3CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART3CLKSEL_1                (0x2U << RCC_CFGR2_LPUART3CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART4CLKSEL_Pos              (6)
#define  RCC_CFGR2_LPUART4CLKSEL_Msk              (0x3U << RCC_CFGR2_LPUART4CLKSEL_Pos)             /*!<LPUART4 clock source selection*/
#define  RCC_CFGR2_LPUART4CLKSEL                  RCC_CFGR2_LPUART4CLKSEL_Msk
#define  RCC_CFGR2_LPUART4CLKSEL_0                (0x1U << RCC_CFGR2_LPUART4CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART4CLKSEL_1                (0x2U << RCC_CFGR2_LPUART4CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART5CLKSEL_Pos              (8)
#define  RCC_CFGR2_LPUART5CLKSEL_Msk              (0x3U << RCC_CFGR2_LPUART5CLKSEL_Pos)             /*!<LPUART5 clock source selection*/
#define  RCC_CFGR2_LPUART5CLKSEL                  RCC_CFGR2_LPUART5CLKSEL_Msk
#define  RCC_CFGR2_LPUART5CLKSEL_0                (0x1U << RCC_CFGR2_LPUART5CLKSEL_Pos) 
#define  RCC_CFGR2_LPUART5CLKSEL_1                (0x2U << RCC_CFGR2_LPUART5CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM1CLKSEL_Pos               (12)
#define  RCC_CFGR2_LPTIM1CLKSEL_Msk               (0x3U << RCC_CFGR2_LPTIM1CLKSEL_Pos)              /*!<LPTIM1 clock source selection*/
#define  RCC_CFGR2_LPTIM1CLKSEL                   RCC_CFGR2_LPTIM1CLKSEL_Msk
#define  RCC_CFGR2_LPTIM1CLKSEL_0                 (0x1U << RCC_CFGR2_LPTIM1CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM1CLKSEL_1                 (0x2U << RCC_CFGR2_LPTIM1CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM2CLKSEL_Pos               (14)
#define  RCC_CFGR2_LPTIM2CLKSEL_Msk               (0x3U << RCC_CFGR2_LPTIM2CLKSEL_Pos)              /*!<LPTIM2 clock source selection*/
#define  RCC_CFGR2_LPTIM2CLKSEL                   RCC_CFGR2_LPTIM2CLKSEL_Msk
#define  RCC_CFGR2_LPTIM2CLKSEL_0                 (0x1U << RCC_CFGR2_LPTIM2CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM2CLKSEL_1                 (0x2U << RCC_CFGR2_LPTIM2CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM3CLKSEL_Pos               (16)
#define  RCC_CFGR2_LPTIM3CLKSEL_Msk               (0x3U << RCC_CFGR2_LPTIM3CLKSEL_Pos)              /*!<LPTIM3 clock source selection*/
#define  RCC_CFGR2_LPTIM3CLKSEL                   RCC_CFGR2_LPTIM3CLKSEL_Msk
#define  RCC_CFGR2_LPTIM3CLKSEL_0                 (0x1U << RCC_CFGR2_LPTIM3CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM3CLKSEL_1                 (0x2U << RCC_CFGR2_LPTIM3CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM4CLKSEL_Pos               (18)
#define  RCC_CFGR2_LPTIM4CLKSEL_Msk               (0x3U << RCC_CFGR2_LPTIM4CLKSEL_Pos)              /*!<LPTIM4 clock source selection*/
#define  RCC_CFGR2_LPTIM4CLKSEL                   RCC_CFGR2_LPTIM4CLKSEL_Msk
#define  RCC_CFGR2_LPTIM4CLKSEL_0                 (0x1U << RCC_CFGR2_LPTIM4CLKSEL_Pos) 
#define  RCC_CFGR2_LPTIM4CLKSEL_1                 (0x2U << RCC_CFGR2_LPTIM4CLKSEL_Pos) 
#define  RCC_CFGR2_MCOPRE_Pos                     (20)
#define  RCC_CFGR2_MCOPRE_Msk                     (0xFU << RCC_CFGR2_MCOPRE_Pos)                    /*!<MCOPRE: MCO Clock Prescaler Factor*/
#define  RCC_CFGR2_MCOPRE                         RCC_CFGR2_MCOPRE_Msk
#define  RCC_CFGR2_MCOPRE_0                       (0x1U << RCC_CFGR2_MCOPRE_Pos) 
#define  RCC_CFGR2_MCOPRE_1                       (0x2U << RCC_CFGR2_MCOPRE_Pos) 
#define  RCC_CFGR2_MCOPRE_2                       (0x4U << RCC_CFGR2_MCOPRE_Pos) 
#define  RCC_CFGR2_MCOPRE_3                       (0x8U << RCC_CFGR2_MCOPRE_Pos) 

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define  RCC_SYSCFG_PROGCHECKEN_Pos               (0)
#define  RCC_SYSCFG_PROGCHECKEN_Msk               (0x1U << RCC_SYSCFG_PROGCHECKEN_Pos)              /*!<Check whether the data in Flash is 0xFF when writing Flash*/
#define  RCC_SYSCFG_PROGCHECKEN                   RCC_SYSCFG_PROGCHECKEN_Msk
#define  RCC_SYSCFG_SECTOR1KCFG_Pos               (1)
#define  RCC_SYSCFG_SECTOR1KCFG_Msk               (0x1U << RCC_SYSCFG_SECTOR1KCFG_Pos)              /*!<The size of the erase when the Flash page is erased.*/
#define  RCC_SYSCFG_SECTOR1KCFG                   RCC_SYSCFG_SECTOR1KCFG_Msk

/**
  * @brief RCC_HSIDLY Register Bit Definition
  */
#define  RCC_HSIDLY_HSIDLY_Pos                    (0)
#define  RCC_HSIDLY_HSIDLY_Msk                    (0xFFFU << RCC_HSIDLY_HSIDLY_Pos)                 /*!<HSI delay time*/
#define  RCC_HSIDLY_HSIDLY                        RCC_HSIDLY_HSIDLY_Msk
#define  RCC_HSIDLY_HSIDLY_0                      (0x001U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_1                      (0x002U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_2                      (0x004U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_3                      (0x008U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_4                      (0x010U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_5                      (0x020U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_6                      (0x040U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_7                      (0x080U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_8                      (0x100U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_9                      (0x200U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_10                     (0x400U << RCC_HSIDLY_HSIDLY_Pos) 
#define  RCC_HSIDLY_HSIDLY_11                     (0x800U << RCC_HSIDLY_HSIDLY_Pos) 

/**
  * @brief RCC_HSEDLY Register Bit Definition
  */
#define  RCC_HSEDLY_HSEDLY_Pos                    (0)
#define  RCC_HSEDLY_HSEDLY_Msk                    (0xFFFFU << RCC_HSEDLY_HSEDLY_Pos)                /*!<HSE delay time*/
#define  RCC_HSEDLY_HSEDLY                        RCC_HSEDLY_HSEDLY_Msk
#define  RCC_HSEDLY_HSEDLY_0                      (0x0001U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_1                      (0x0002U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_2                      (0x0004U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_3                      (0x0008U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_4                      (0x0010U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_5                      (0x0020U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_6                      (0x0040U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_7                      (0x0080U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_8                      (0x0100U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_9                      (0x0200U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_10                     (0x0400U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_11                     (0x0800U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_12                     (0x1000U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_13                     (0x2000U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_14                     (0x4000U << RCC_HSEDLY_HSEDLY_Pos) 
#define  RCC_HSEDLY_HSEDLY_15                     (0x8000U << RCC_HSEDLY_HSEDLY_Pos) 

/**
  * @brief RCC_ICSCR Register Bit Definition
  */
#define  RCC_ICSCR_HSICALSEL_Pos                  (11)
#define  RCC_ICSCR_HSICALSEL_Msk                  (0x1FU << RCC_ICSCR_HSICALSEL_Pos)                /*!<Select an internal high-speed clock calibration value*/
#define  RCC_ICSCR_HSICALSEL                      RCC_ICSCR_HSICALSEL_Msk
#define  RCC_ICSCR_HSICALSEL_0                    (0x01U << RCC_ICSCR_HSICALSEL_Pos) 
#define  RCC_ICSCR_HSICALSEL_1                    (0x02U << RCC_ICSCR_HSICALSEL_Pos) 
#define  RCC_ICSCR_HSICALSEL_2                    (0x04U << RCC_ICSCR_HSICALSEL_Pos) 
#define  RCC_ICSCR_HSICALSEL_3                    (0x08U << RCC_ICSCR_HSICALSEL_Pos) 
#define  RCC_ICSCR_HSICALSEL_4                    (0x10U << RCC_ICSCR_HSICALSEL_Pos) 
#define  RCC_ICSCR_HSICALSFT_Pos                  (16)
#define  RCC_ICSCR_HSICALSFT_Msk                  (0x3FFU << RCC_ICSCR_HSICALSFT_Pos)               /*!<Internal high-speed clock calibration*/
#define  RCC_ICSCR_HSICALSFT                      RCC_ICSCR_HSICALSFT_Msk
#define  RCC_ICSCR_HSICALSFT_0                    (0x001U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_1                    (0x002U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_2                    (0x004U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_3                    (0x008U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_4                    (0x010U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_5                    (0x020U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_6                    (0x040U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_7                    (0x080U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_8                    (0x100U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSICALSFT_9                    (0x200U << RCC_ICSCR_HSICALSFT_Pos) 
#define  RCC_ICSCR_HSITEMPCAL_Pos                 (26)
#define  RCC_ICSCR_HSITEMPCAL_Msk                 (0xFU << RCC_ICSCR_HSITEMPCAL_Pos)                /*!<Internal high-speed clock temperature calibration*/
#define  RCC_ICSCR_HSITEMPCAL                     RCC_ICSCR_HSITEMPCAL_Msk
#define  RCC_ICSCR_HSITEMPCAL_0                   (0x1U << RCC_ICSCR_HSITEMPCAL_Pos) 
#define  RCC_ICSCR_HSITEMPCAL_1                   (0x2U << RCC_ICSCR_HSITEMPCAL_Pos) 
#define  RCC_ICSCR_HSITEMPCAL_2                   (0x4U << RCC_ICSCR_HSITEMPCAL_Pos) 
#define  RCC_ICSCR_HSITEMPCAL_3                   (0x8U << RCC_ICSCR_HSITEMPCAL_Pos) 

/**
  * @brief RCC_FRVSCR Register Bit Definition
  */
#define  RCC_FRVSCR_VREFBUFTRIMSEL_Pos            (11)
#define  RCC_FRVSCR_VREFBUFTRIMSEL_Msk            (0x1FU << RCC_FRVSCR_VREFBUFTRIMSEL_Pos)          /*!<Select a VREFBUF calibration value*/
#define  RCC_FRVSCR_VREFBUFTRIMSEL                RCC_FRVSCR_VREFBUFTRIMSEL_Msk
#define  RCC_FRVSCR_VREFBUFTRIMSEL_0              (0x01U << RCC_FRVSCR_VREFBUFTRIMSEL_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIMSEL_1              (0x02U << RCC_FRVSCR_VREFBUFTRIMSEL_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIMSEL_2              (0x04U << RCC_FRVSCR_VREFBUFTRIMSEL_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIMSEL_3              (0x08U << RCC_FRVSCR_VREFBUFTRIMSEL_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIMSEL_4              (0x10U << RCC_FRVSCR_VREFBUFTRIMSEL_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIM_Pos               (16)
#define  RCC_FRVSCR_VREFBUFTRIM_Msk               (0x1FU << RCC_FRVSCR_VREFBUFTRIM_Pos)             /*!<VREFBUF calibration value*/
#define  RCC_FRVSCR_VREFBUFTRIM                   RCC_FRVSCR_VREFBUFTRIM_Msk
#define  RCC_FRVSCR_VREFBUFTRIM_0                 (0x01U << RCC_FRVSCR_VREFBUFTRIM_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIM_1                 (0x02U << RCC_FRVSCR_VREFBUFTRIM_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIM_2                 (0x04U << RCC_FRVSCR_VREFBUFTRIM_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIM_3                 (0x08U << RCC_FRVSCR_VREFBUFTRIM_Pos) 
#define  RCC_FRVSCR_VREFBUFTRIM_4                 (0x10U << RCC_FRVSCR_VREFBUFTRIM_Pos) 

/**
  * @brief RCC_LSCCR Register Bit Definition
  */
#define  RCC_LSCCR_RTCLSC_Pos                     (0)
#define  RCC_LSCCR_RTCLSC_Msk                     (0x1U << RCC_LSCCR_RTCLSC_Pos)                    /*!<RTC Low Speed Clock Control*/
#define  RCC_LSCCR_RTCLSC                         RCC_LSCCR_RTCLSC_Msk
#define  RCC_LSCCR_IWDGLSC_Pos                    (2)
#define  RCC_LSCCR_IWDGLSC_Msk                    (0x1U << RCC_LSCCR_IWDGLSC_Pos)                   /*!<IWDG Low Speed Clock Control*/
#define  RCC_LSCCR_IWDGLSC                        RCC_LSCCR_IWDGLSC_Msk
#define  RCC_LSCCR_SLCDLSC_Pos                    (4)
#define  RCC_LSCCR_SLCDLSC_Msk                    (0x1U << RCC_LSCCR_SLCDLSC_Pos)                   /*!<SLCD Low Speed Clock Control*/
#define  RCC_LSCCR_SLCDLSC                        RCC_LSCCR_SLCDLSC_Msk

/**
  * @brief RCC_LDOCR Register Bit Definition
  */
#define  RCC_LDOCR_LDO_TRIM_SEL_Pos               (12)
#define  RCC_LDOCR_LDO_TRIM_SEL_Msk               (0xFU << RCC_LDOCR_LDO_TRIM_SEL_Pos)              /*!<LDO_TRIM Select bits*/
#define  RCC_LDOCR_LDO_TRIM_SEL                   RCC_LDOCR_LDO_TRIM_SEL_Msk
#define  RCC_LDOCR_LDO_TRIM_SEL_0                 (0x1U << RCC_LDOCR_LDO_TRIM_SEL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_SEL_1                 (0x2U << RCC_LDOCR_LDO_TRIM_SEL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_SEL_2                 (0x4U << RCC_LDOCR_LDO_TRIM_SEL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_SEL_3                 (0x8U << RCC_LDOCR_LDO_TRIM_SEL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_CAL_Pos               (16)
#define  RCC_LDOCR_LDO_TRIM_CAL_Msk               (0xFU << RCC_LDOCR_LDO_TRIM_CAL_Pos)              /*!<LDO_TRIM value*/
#define  RCC_LDOCR_LDO_TRIM_CAL                   RCC_LDOCR_LDO_TRIM_CAL_Msk
#define  RCC_LDOCR_LDO_TRIM_CAL_0                 (0x1U << RCC_LDOCR_LDO_TRIM_CAL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_CAL_1                 (0x2U << RCC_LDOCR_LDO_TRIM_CAL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_CAL_2                 (0x4U << RCC_LDOCR_LDO_TRIM_CAL_Pos) 
#define  RCC_LDOCR_LDO_TRIM_CAL_3                 (0x8U << RCC_LDOCR_LDO_TRIM_CAL_Pos) 

#endif

