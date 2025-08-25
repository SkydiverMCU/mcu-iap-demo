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
#include "core_starmc1.h"



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
    __IO uint32_t AHBRSTR2;                       /*!<RCC AHB Peripheral Reset Register2             offset: 0x10       */
    __IO uint32_t AHBRSTR;                        /*!<RCC AHB Peripheral Reset Register              offset: 0x14       */
    __IO uint32_t APB2RSTR;                       /*!<RCC APB2 Peripheral Reset Register             offset: 0x18       */
    __IO uint32_t APB1RSTR;                       /*!<RCC APB1 Peripheral Reset Register             offset: 0x1C       */
    __IO uint32_t RESERVED0x20[1];                /*!<                                               offset: 0x20       */
    __IO uint32_t AHBENR2;                        /*!<RCC AHB Peripheral Clock Enable Register2      offset: 0x24       */
    __IO uint32_t AHBENR;                         /*!<RCC AHB Peripheral Clock Enable Register       offset: 0x28       */
    __IO uint32_t APB2ENR;                        /*!<RCC APB2 Peripheral Clock Enable Register      offset: 0x2C       */
    __IO uint32_t APB1ENR;                        /*!<RCC APB1Peripheral Clock Enable Register       offset: 0x30       */
    __IO uint32_t BDCR;                           /*!<                                               offset: 0x34       */
    __IO uint32_t CSR;                            /*!<RCC Control Status Register                    offset: 0x38       */
    __IO uint32_t SYSCFGR;                        /*!<RCC System Configuration Register              offset: 0x3C       */
    __IO uint32_t CFGR2;                          /*!<RCC Clock Configuration Register 2             offset: 0x40       */
    __IO uint32_t ICSCR;                          /*!<                                               offset: 0x44       */
    __IO uint32_t PLL1CFGR;                       /*!<RCC PLL1 Configuration Register                offset: 0x48       */
    __IO uint32_t PLL2CFGR;                       /*!<RCC PLL2 Configuration Register                offset: 0x4C       */
    __IO uint32_t CFGR3;                          /*!<RCC Clock Configuration Register 3             offset: 0x50       */
    __IO uint32_t RESERVED0x54[1];                /*!<                                               offset: 0x54       */
    __IO uint32_t CANCFGR;                        /*!<RCC FLexCAN Configuration Register             offset: 0x58       */
    __IO uint32_t RESERVED0x5C[1];                /*!<                                               offset: 0x5C       */
    __IO uint32_t ADC1CFGR;                       /*!<RCC ADC1 Configuration Register                offset: 0x60       */
    __IO uint32_t ADC2CFGR;                       /*!<RCC ADC2 Configuration Register                offset: 0x64       */
    __IO uint32_t ADC3CFGR;                       /*!<RCC ADC3 Configuration Register                offset: 0x68       */
    __IO uint32_t RESERVED0x6C[1];                /*!<                                               offset: 0x6C       */
    __IO uint32_t DACCFGR;                        /*!<RCC DAC Configuration Register                 offset: 0x70       */
    __IO uint32_t RESERVED0x74[2];                /*!<                                               offset: 0x74~0x78  */
    __IO uint32_t TPIUCFGR;                       /*!<RCC TPIU Configuration Register                offset: 0x7C       */
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
#define  RCC_CR_HSELPFBYP_Pos                     (4)
#define  RCC_CR_HSELPFBYP_Msk                     (0x1U << RCC_CR_HSELPFBYP_Pos)                    /*!<Enable signal that LPF input signal directly output*/
#define  RCC_CR_HSELPFBYP                         RCC_CR_HSELPFBYP_Msk
#define  RCC_CR_HSELPFSEL_Pos                     (5)
#define  RCC_CR_HSELPFSEL_Msk                     (0x1U << RCC_CR_HSELPFSEL_Pos)                    /*!<LPF filter mode control*/
#define  RCC_CR_HSELPFSEL                         RCC_CR_HSELPFSEL_Msk
#define  RCC_CR_HSEDEGLITCHBYP_Pos                (6)
#define  RCC_CR_HSEDEGLITCHBYP_Msk                (0x1U << RCC_CR_HSEDEGLITCHBYP_Pos)               /*!<Deburring Circuit Bypass Control Bit*/
#define  RCC_CR_HSEDEGLITCHBYP                    RCC_CR_HSEDEGLITCHBYP_Msk
#define  RCC_CR_HSEDEGLITCHSEL_Pos                (7)
#define  RCC_CR_HSEDEGLITCHSEL_Msk                (0x1U << RCC_CR_HSEDEGLITCHSEL_Pos)               /*!<Deburring Width Control Bit*/
#define  RCC_CR_HSEDEGLITCHSEL                    RCC_CR_HSEDEGLITCHSEL_Msk
#define  RCC_CR_HSEOUTPUTSEL_Pos                  (8)
#define  RCC_CR_HSEOUTPUTSEL_Msk                  (0x1U << RCC_CR_HSEOUTPUTSEL_Pos)                 /*!<Output Mode Selector*/
#define  RCC_CR_HSEOUTPUTSEL                      RCC_CR_HSEOUTPUTSEL_Msk
#define  RCC_CR_HSEDR_Pos                         (9)
#define  RCC_CR_HSEDR_Msk                         (0x3U << RCC_CR_HSEDR_Pos)                        /*!<HSE Driver Ability*/
#define  RCC_CR_HSEDR                             RCC_CR_HSEDR_Msk
#define  RCC_CR_HSEDR_Bit0                        (0x1U << RCC_CR_HSEDR_Pos) 
#define  RCC_CR_HSEDR_Bit1                        (0x2U << RCC_CR_HSEDR_Pos) 
#define  RCC_CR_HSIDIV_Pos                        (11)
#define  RCC_CR_HSIDIV_Msk                        (0x7U << RCC_CR_HSIDIV_Pos)                       /*!<HSIDIV: Internal high-speed clock division factor*/
#define  RCC_CR_HSIDIV                            RCC_CR_HSIDIV_Msk
#define  RCC_CR_HSIDIV_Bit0                       (0x1U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSIDIV_Bit1                       (0x2U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSIDIV_Bit2                       (0x4U << RCC_CR_HSIDIV_Pos) 
#define  RCC_CR_HSEON_Pos                         (16)
#define  RCC_CR_HSEON_Msk                         (0x1U << RCC_CR_HSEON_Pos)                        /*!<External High-speed Clock Enable*/
#define  RCC_CR_HSEON                             RCC_CR_HSEON_Msk
#define  RCC_CR_HSERDY_Pos                        (17)
#define  RCC_CR_HSERDY_Msk                        (0x1U << RCC_CR_HSERDY_Pos)                       /*!<External High-speed Clock Ready Flag*/
#define  RCC_CR_HSERDY                            RCC_CR_HSERDY_Msk
#define  RCC_CR_HSEBYP_Pos                        (18)
#define  RCC_CR_HSEBYP_Msk                        (0x1U << RCC_CR_HSEBYP_Pos)                       /*!<External High-speed Clock Bypass*/
#define  RCC_CR_HSEBYP                            RCC_CR_HSEBYP_Msk
#define  RCC_CR_CSSON_Pos                         (19)
#define  RCC_CR_CSSON_Msk                         (0x1U << RCC_CR_CSSON_Pos)                        /*!<Clock Security System High Enable*/
#define  RCC_CR_CSSON                             RCC_CR_CSSON_Msk
#define  RCC_CR_HSEAACSEL_Pos                     (21)
#define  RCC_CR_HSEAACSEL_Msk                     (0x1U << RCC_CR_HSEAACSEL_Pos)                    /*!<HSE Amplitude Auto Calibration Select*/
#define  RCC_CR_HSEAACSEL                         RCC_CR_HSEAACSEL_Msk
#define  RCC_CR_HSEIB_Pos                         (22)
#define  RCC_CR_HSEIB_Msk                         (0x3U << RCC_CR_HSEIB_Pos)                        /*!<HSE Current Mode Select*/
#define  RCC_CR_HSEIB                             RCC_CR_HSEIB_Msk
#define  RCC_CR_HSEIB_Bit0                        (0x1U << RCC_CR_HSEIB_Pos) 
#define  RCC_CR_HSEIB_Bit1                        (0x2U << RCC_CR_HSEIB_Pos) 
#define  RCC_CR_PLL1ON_Pos                        (24)
#define  RCC_CR_PLL1ON_Msk                        (0x1U << RCC_CR_PLL1ON_Pos)                       /*!<PLL1 Enable*/
#define  RCC_CR_PLL1ON                            RCC_CR_PLL1ON_Msk
#define  RCC_CR_PLL1RDY_Pos                       (25)
#define  RCC_CR_PLL1RDY_Msk                       (0x1U << RCC_CR_PLL1RDY_Pos)                      /*!<PLL1 Clock Ready Flag(Set by hardware)*/
#define  RCC_CR_PLL1RDY                           RCC_CR_PLL1RDY_Msk
#define  RCC_CR_PLL2ON_Pos                        (28)
#define  RCC_CR_PLL2ON_Msk                        (0x1U << RCC_CR_PLL2ON_Pos)                       /*!<PLL2 Enable*/
#define  RCC_CR_PLL2ON                            RCC_CR_PLL2ON_Msk
#define  RCC_CR_PLL2RDY_Pos                       (29)
#define  RCC_CR_PLL2RDY_Msk                       (0x1U << RCC_CR_PLL2RDY_Pos)                      /*!<PLL2 Clock Ready Flag(Set by hardware)*/
#define  RCC_CR_PLL2RDY                           RCC_CR_PLL2RDY_Msk

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define  RCC_CFGR_SW_Pos                          (0)
#define  RCC_CFGR_SW_Msk                          (0x3U << RCC_CFGR_SW_Pos)                         /*!<System Clock Switch*/
#define  RCC_CFGR_SW                              RCC_CFGR_SW_Msk
#define  RCC_CFGR_SW_Bit0                         (0x1U << RCC_CFGR_SW_Pos) 
#define  RCC_CFGR_SW_Bit1                         (0x2U << RCC_CFGR_SW_Pos) 
#define  RCC_CFGR_SWS_Pos                         (2)
#define  RCC_CFGR_SWS_Msk                         (0x3U << RCC_CFGR_SWS_Pos)                        /*!<System clock selection status*/
#define  RCC_CFGR_SWS                             RCC_CFGR_SWS_Msk
#define  RCC_CFGR_SWS_Bit0                        (0x1U << RCC_CFGR_SWS_Pos) 
#define  RCC_CFGR_SWS_Bit1                        (0x2U << RCC_CFGR_SWS_Pos) 
#define  RCC_CFGR_HPRE_Pos                        (4)
#define  RCC_CFGR_HPRE_Msk                        (0xFU << RCC_CFGR_HPRE_Pos)                       /*!<AHB prescaler coefficient*/
#define  RCC_CFGR_HPRE                            RCC_CFGR_HPRE_Msk
#define  RCC_CFGR_HPRE_Bit0                       (0x1U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_HPRE_Bit1                       (0x2U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_HPRE_Bit2                       (0x4U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_HPRE_Bit3                       (0x8U << RCC_CFGR_HPRE_Pos) 
#define  RCC_CFGR_PPRE1_Pos                       (8)
#define  RCC_CFGR_PPRE1_Msk                       (0x7U << RCC_CFGR_PPRE1_Pos)                      /*!<APB1 prescaler coefficient*/
#define  RCC_CFGR_PPRE1                           RCC_CFGR_PPRE1_Msk
#define  RCC_CFGR_PPRE1_Bit0                      (0x1U << RCC_CFGR_PPRE1_Pos) 
#define  RCC_CFGR_PPRE1_Bit1                      (0x2U << RCC_CFGR_PPRE1_Pos) 
#define  RCC_CFGR_PPRE1_Bit2                      (0x4U << RCC_CFGR_PPRE1_Pos) 
#define  RCC_CFGR_PPRE2_Pos                       (11)
#define  RCC_CFGR_PPRE2_Msk                       (0x7U << RCC_CFGR_PPRE2_Pos)                      /*!<APB2 prescaler coefficient*/
#define  RCC_CFGR_PPRE2                           RCC_CFGR_PPRE2_Msk
#define  RCC_CFGR_PPRE2_Bit0                      (0x1U << RCC_CFGR_PPRE2_Pos) 
#define  RCC_CFGR_PPRE2_Bit1                      (0x2U << RCC_CFGR_PPRE2_Pos) 
#define  RCC_CFGR_PPRE2_Bit2                      (0x4U << RCC_CFGR_PPRE2_Pos) 
#define  RCC_CFGR_ADC1CLKSEL_Pos                  (16)
#define  RCC_CFGR_ADC1CLKSEL_Msk                  (0x1U << RCC_CFGR_ADC1CLKSEL_Pos)                 /*!<*/
#define  RCC_CFGR_ADC1CLKSEL                      RCC_CFGR_ADC1CLKSEL_Msk
#define  RCC_CFGR_ADC2CLKSEL_Pos                  (17)
#define  RCC_CFGR_ADC2CLKSEL_Msk                  (0x1U << RCC_CFGR_ADC2CLKSEL_Pos)                 /*!<*/
#define  RCC_CFGR_ADC2CLKSEL                      RCC_CFGR_ADC2CLKSEL_Msk
#define  RCC_CFGR_ADC3CLKSEL_Pos                  (18)
#define  RCC_CFGR_ADC3CLKSEL_Msk                  (0x1U << RCC_CFGR_ADC3CLKSEL_Pos)                 /*!<*/
#define  RCC_CFGR_ADC3CLKSEL                      RCC_CFGR_ADC3CLKSEL_Msk
#define  RCC_CFGR_USBCLKSEL_Pos                   (19)
#define  RCC_CFGR_USBCLKSEL_Msk                   (0x1U << RCC_CFGR_USBCLKSEL_Pos)                  /*!<*/
#define  RCC_CFGR_USBCLKSEL                       RCC_CFGR_USBCLKSEL_Msk
#define  RCC_CFGR_USBPRE_Pos                      (22)
#define  RCC_CFGR_USBPRE_Msk                      (0x3U << RCC_CFGR_USBPRE_Pos)                     /*!<*/
#define  RCC_CFGR_USBPRE                          RCC_CFGR_USBPRE_Msk
#define  RCC_CFGR_USBPRE_Bit0                     (0x1U << RCC_CFGR_USBPRE_Pos) 
#define  RCC_CFGR_USBPRE_Bit1                     (0x2U << RCC_CFGR_USBPRE_Pos) 
#define  RCC_CFGR_MCO_Pos                         (24)
#define  RCC_CFGR_MCO_Msk                         (0xFU << RCC_CFGR_MCO_Pos)                        /*!<Micro Controller Clock Output*/
#define  RCC_CFGR_MCO                             RCC_CFGR_MCO_Msk
#define  RCC_CFGR_MCO_Bit0                        (0x1U << RCC_CFGR_MCO_Pos) 
#define  RCC_CFGR_MCO_Bit1                        (0x2U << RCC_CFGR_MCO_Pos) 
#define  RCC_CFGR_MCO_Bit2                        (0x4U << RCC_CFGR_MCO_Pos) 
#define  RCC_CFGR_MCO_Bit3                        (0x8U << RCC_CFGR_MCO_Pos) 

/**
  * @brief RCC_CIR Register Bit Definition
  */
#define  RCC_CIR_LSIRDYF_Pos                      (0)
#define  RCC_CIR_LSIRDYF_Msk                      (0x1U << RCC_CIR_LSIRDYF_Pos)                     /*!<LSI Ready Interrupt Flag*/
#define  RCC_CIR_LSIRDYF                          RCC_CIR_LSIRDYF_Msk
#define  RCC_CIR_LSERDYF_Pos                      (1)
#define  RCC_CIR_LSERDYF_Msk                      (0x1U << RCC_CIR_LSERDYF_Pos)                     /*!<LSE Ready Interrupt Flag When the low-speed external clock is ready, set '1' by hardware. Clear by setting LSERDYC bit as '1'by software.*/
#define  RCC_CIR_LSERDYF                          RCC_CIR_LSERDYF_Msk
#define  RCC_CIR_HSIRDYF_Pos                      (2)
#define  RCC_CIR_HSIRDYF_Msk                      (0x1U << RCC_CIR_HSIRDYF_Pos)                     /*!<HSI Ready Interrupt Flag*/
#define  RCC_CIR_HSIRDYF                          RCC_CIR_HSIRDYF_Msk
#define  RCC_CIR_HSERDYF_Pos                      (3)
#define  RCC_CIR_HSERDYF_Msk                      (0x1U << RCC_CIR_HSERDYF_Pos)                     /*!<HSE Ready Interrupt Flag*/
#define  RCC_CIR_HSERDYF                          RCC_CIR_HSERDYF_Msk
#define  RCC_CIR_PLL1RDYF_Pos                     (4)
#define  RCC_CIR_PLL1RDYF_Msk                     (0x1U << RCC_CIR_PLL1RDYF_Pos)                    /*!<PLL1 Ready Interrupt Flag*/
#define  RCC_CIR_PLL1RDYF                         RCC_CIR_PLL1RDYF_Msk
#define  RCC_CIR_PLL2RDYF_Pos                     (5)
#define  RCC_CIR_PLL2RDYF_Msk                     (0x1U << RCC_CIR_PLL2RDYF_Pos)                    /*!<PLL2 Ready Interrupt Flag When PLL2 is ready, set '1' by hardware. Clear by setting PLL2RDYC bit as '1'by software.*/
#define  RCC_CIR_PLL2RDYF                         RCC_CIR_PLL2RDYF_Msk
#define  RCC_CIR_CSSF_Pos                         (7)
#define  RCC_CIR_CSSF_Msk                         (0x1U << RCC_CIR_CSSF_Pos)                        /*!<Clock security system interrupt flag*/
#define  RCC_CIR_CSSF                             RCC_CIR_CSSF_Msk
#define  RCC_CIR_LSIRDYIE_Pos                     (8)
#define  RCC_CIR_LSIRDYIE_Msk                     (0x1U << RCC_CIR_LSIRDYIE_Pos)                    /*!<LSI Ready Interrupt Enable*/
#define  RCC_CIR_LSIRDYIE                         RCC_CIR_LSIRDYIE_Msk
#define  RCC_CIR_LSERDYIE_Pos                     (9)
#define  RCC_CIR_LSERDYIE_Msk                     (0x1U << RCC_CIR_LSERDYIE_Pos)                    /*!<LSE Ready Interrupt Enable Set '1' by software to enable or clear '0' to disable external 32KHz oscillator ready interrupt.*/
#define  RCC_CIR_LSERDYIE                         RCC_CIR_LSERDYIE_Msk
#define  RCC_CIR_HSIRDYIE_Pos                     (10)
#define  RCC_CIR_HSIRDYIE_Msk                     (0x1U << RCC_CIR_HSIRDYIE_Pos)                    /*!<HSI Ready Interrupt Enable*/
#define  RCC_CIR_HSIRDYIE                         RCC_CIR_HSIRDYIE_Msk
#define  RCC_CIR_HSERDYIE_Pos                     (11)
#define  RCC_CIR_HSERDYIE_Msk                     (0x1U << RCC_CIR_HSERDYIE_Pos)                    /*!<HSE Ready Interrupt Enable*/
#define  RCC_CIR_HSERDYIE                         RCC_CIR_HSERDYIE_Msk
#define  RCC_CIR_PLL1RDYIE_Pos                    (12)
#define  RCC_CIR_PLL1RDYIE_Msk                    (0x1U << RCC_CIR_PLL1RDYIE_Pos)                   /*!<PLL1 Ready Interrupt Enable*/
#define  RCC_CIR_PLL1RDYIE                        RCC_CIR_PLL1RDYIE_Msk
#define  RCC_CIR_PLL2RDYIE_Pos                    (13)
#define  RCC_CIR_PLL2RDYIE_Msk                    (0x1U << RCC_CIR_PLL2RDYIE_Pos)                   /*!<PLL2 Ready Interrupt Enable Set '1' by software to enable or clear '0' to disable PLL2 ready interrupt.*/
#define  RCC_CIR_PLL2RDYIE                        RCC_CIR_PLL2RDYIE_Msk
#define  RCC_CIR_LSIRDYC_Pos                      (16)
#define  RCC_CIR_LSIRDYC_Msk                      (0x1U << RCC_CIR_LSIRDYC_Pos)                     /*!<LSI Ready Interrupt Clear*/
#define  RCC_CIR_LSIRDYC                          RCC_CIR_LSIRDYC_Msk
#define  RCC_CIR_LSERDYC_Pos                      (17)
#define  RCC_CIR_LSERDYC_Msk                      (0x1U << RCC_CIR_LSERDYC_Pos)                     /*!<LSE Ready Interrupt Clear Set '1' by software to clear LSE ready interrupt flag bit LSERDYF*/
#define  RCC_CIR_LSERDYC                          RCC_CIR_LSERDYC_Msk
#define  RCC_CIR_HSIRDYC_Pos                      (18)
#define  RCC_CIR_HSIRDYC_Msk                      (0x1U << RCC_CIR_HSIRDYC_Pos)                     /*!<HSI Ready Interrupt Clear*/
#define  RCC_CIR_HSIRDYC                          RCC_CIR_HSIRDYC_Msk
#define  RCC_CIR_HSERDYC_Pos                      (19)
#define  RCC_CIR_HSERDYC_Msk                      (0x1U << RCC_CIR_HSERDYC_Pos)                     /*!<HSE Ready Interrupt Clear*/
#define  RCC_CIR_HSERDYC                          RCC_CIR_HSERDYC_Msk
#define  RCC_CIR_PLL1RDYC_Pos                     (20)
#define  RCC_CIR_PLL1RDYC_Msk                     (0x1U << RCC_CIR_PLL1RDYC_Pos)                    /*!<PLL1 Ready Interrupt Clear Set '1' by software to clear PLL1 ready interrupt flag bit PLL1RDYF*/
#define  RCC_CIR_PLL1RDYC                         RCC_CIR_PLL1RDYC_Msk
#define  RCC_CIR_PLL2RDYC_Pos                     (21)
#define  RCC_CIR_PLL2RDYC_Msk                     (0x1U << RCC_CIR_PLL2RDYC_Pos)                    /*!<PLL2 Ready Interrupt Clear Set '1' by software to clear PLL2 ready interrupt flag bit PLL2RDYF*/
#define  RCC_CIR_PLL2RDYC                         RCC_CIR_PLL2RDYC_Msk
#define  RCC_CIR_CSSC_Pos                         (23)
#define  RCC_CIR_CSSC_Msk                         (0x1U << RCC_CIR_CSSC_Pos)                        /*!<Clock security system interrupt clear*/
#define  RCC_CIR_CSSC                             RCC_CIR_CSSC_Msk

/**
  * @brief RCC_AHBRSTR2 Register Bit Definition
  */
#define  RCC_AHBRSTR2_BKRAM_Pos                   (28)
#define  RCC_AHBRSTR2_BKRAM_Msk                   (0x1U << RCC_AHBRSTR2_BKRAM_Pos)                  /*!<*/
#define  RCC_AHBRSTR2_BKRAM                       RCC_AHBRSTR2_BKRAM_Msk

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define  RCC_AHBRSTR_GPIOA_Pos                    (0)
#define  RCC_AHBRSTR_GPIOA_Msk                    (0x1U << RCC_AHBRSTR_GPIOA_Pos)                   /*!<GPIOA Reset*/
#define  RCC_AHBRSTR_GPIOA                        RCC_AHBRSTR_GPIOA_Msk
#define  RCC_AHBRSTR_GPIOB_Pos                    (1)
#define  RCC_AHBRSTR_GPIOB_Msk                    (0x1U << RCC_AHBRSTR_GPIOB_Pos)                   /*!<GPIOB Reset*/
#define  RCC_AHBRSTR_GPIOB                        RCC_AHBRSTR_GPIOB_Msk
#define  RCC_AHBRSTR_GPIOC_Pos                    (2)
#define  RCC_AHBRSTR_GPIOC_Msk                    (0x1U << RCC_AHBRSTR_GPIOC_Pos)                   /*!<GPIOC Reset*/
#define  RCC_AHBRSTR_GPIOC                        RCC_AHBRSTR_GPIOC_Msk
#define  RCC_AHBRSTR_GPIOD_Pos                    (3)
#define  RCC_AHBRSTR_GPIOD_Msk                    (0x1U << RCC_AHBRSTR_GPIOD_Pos)                   /*!<GPIOD Reset*/
#define  RCC_AHBRSTR_GPIOD                        RCC_AHBRSTR_GPIOD_Msk
#define  RCC_AHBRSTR_GPIOE_Pos                    (4)
#define  RCC_AHBRSTR_GPIOE_Msk                    (0x1U << RCC_AHBRSTR_GPIOE_Pos)                   /*!<GPIOE Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_GPIOE                        RCC_AHBRSTR_GPIOE_Msk
#define  RCC_AHBRSTR_GPIOF_Pos                    (5)
#define  RCC_AHBRSTR_GPIOF_Msk                    (0x1U << RCC_AHBRSTR_GPIOF_Pos)                   /*!<GPIOF Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_GPIOF                        RCC_AHBRSTR_GPIOF_Msk
#define  RCC_AHBRSTR_GPIOH_Pos                    (7)
#define  RCC_AHBRSTR_GPIOH_Msk                    (0x1U << RCC_AHBRSTR_GPIOH_Pos)                   /*!<GPIOH Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_GPIOH                        RCC_AHBRSTR_GPIOH_Msk
#define  RCC_AHBRSTR_GPIOI_Pos                    (8)
#define  RCC_AHBRSTR_GPIOI_Msk                    (0x1U << RCC_AHBRSTR_GPIOI_Pos)                   /*!<GPIOI Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_GPIOI                        RCC_AHBRSTR_GPIOI_Msk
#define  RCC_AHBRSTR_CRC_Pos                      (12)
#define  RCC_AHBRSTR_CRC_Msk                      (0x1U << RCC_AHBRSTR_CRC_Pos)                     /*!<CRC Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_CRC                          RCC_AHBRSTR_CRC_Msk
#define  RCC_AHBRSTR_CORDIC_Pos                   (15)
#define  RCC_AHBRSTR_CORDIC_Msk                   (0x1U << RCC_AHBRSTR_CORDIC_Pos)                  /*!<CORDIC Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_CORDIC                       RCC_AHBRSTR_CORDIC_Msk
#define  RCC_AHBRSTR_DMA1_Pos                     (21)
#define  RCC_AHBRSTR_DMA1_Msk                     (0x1U << RCC_AHBRSTR_DMA1_Pos)                    /*!<DMA1 Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_DMA1                         RCC_AHBRSTR_DMA1_Msk
#define  RCC_AHBRSTR_DMA2_Pos                     (22)
#define  RCC_AHBRSTR_DMA2_Msk                     (0x1U << RCC_AHBRSTR_DMA2_Pos)                    /*!<DMA2 Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_DMA2                         RCC_AHBRSTR_DMA2_Msk
#define  RCC_AHBRSTR_USB_FS_Pos                   (24)
#define  RCC_AHBRSTR_USB_FS_Msk                   (0x1U << RCC_AHBRSTR_USB_FS_Pos)                  /*!<USB_FS Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_USB_FS                       RCC_AHBRSTR_USB_FS_Msk
#define  RCC_AHBRSTR_QSPI_Pos                     (30)
#define  RCC_AHBRSTR_QSPI_Msk                     (0x1U << RCC_AHBRSTR_QSPI_Pos)                    /*!<QSPI Reset Set '1' or clear '0' by software*/
#define  RCC_AHBRSTR_QSPI                         RCC_AHBRSTR_QSPI_Msk

/**
  * @brief RCC_APB2RSTR Register Bit Definition
  */
#define  RCC_APB2RSTR_TIM1_Pos                    (0)
#define  RCC_APB2RSTR_TIM1_Msk                    (0x1U << RCC_APB2RSTR_TIM1_Pos)                   /*!<TIM1 Reset*/
#define  RCC_APB2RSTR_TIM1                        RCC_APB2RSTR_TIM1_Msk
#define  RCC_APB2RSTR_TIM8_Pos                    (1)
#define  RCC_APB2RSTR_TIM8_Msk                    (0x1U << RCC_APB2RSTR_TIM8_Pos)                   /*!<TIM8 Reset*/
#define  RCC_APB2RSTR_TIM8                        RCC_APB2RSTR_TIM8_Msk
#define  RCC_APB2RSTR_USART1_Pos                  (4)
#define  RCC_APB2RSTR_USART1_Msk                  (0x1U << RCC_APB2RSTR_USART1_Pos)                 /*!<USART1 Reset*/
#define  RCC_APB2RSTR_USART1                      RCC_APB2RSTR_USART1_Msk
#define  RCC_APB2RSTR_ADC1_Pos                    (8)
#define  RCC_APB2RSTR_ADC1_Msk                    (0x1U << RCC_APB2RSTR_ADC1_Pos)                   /*!<ADC1 Reset*/
#define  RCC_APB2RSTR_ADC1                        RCC_APB2RSTR_ADC1_Msk
#define  RCC_APB2RSTR_ADC2_Pos                    (9)
#define  RCC_APB2RSTR_ADC2_Msk                    (0x1U << RCC_APB2RSTR_ADC2_Pos)                   /*!<ADC2 Reset*/
#define  RCC_APB2RSTR_ADC2                        RCC_APB2RSTR_ADC2_Msk
#define  RCC_APB2RSTR_ADC3_Pos                    (10)
#define  RCC_APB2RSTR_ADC3_Msk                    (0x1U << RCC_APB2RSTR_ADC3_Pos)                   /*!<ADC3 Reset*/
#define  RCC_APB2RSTR_ADC3                        RCC_APB2RSTR_ADC3_Msk
#define  RCC_APB2RSTR_SPI1_Pos                    (12)
#define  RCC_APB2RSTR_SPI1_Msk                    (0x1U << RCC_APB2RSTR_SPI1_Pos)                   /*!<SPI1 Reset*/
#define  RCC_APB2RSTR_SPI1                        RCC_APB2RSTR_SPI1_Msk
#define  RCC_APB2RSTR_SYSCFG_Pos                  (14)
#define  RCC_APB2RSTR_SYSCFG_Msk                  (0x1U << RCC_APB2RSTR_SYSCFG_Pos)                 /*!<SYSCFG Reset*/
#define  RCC_APB2RSTR_SYSCFG                      RCC_APB2RSTR_SYSCFG_Msk
#define  RCC_APB2RSTR_COMP_Pos                    (15)
#define  RCC_APB2RSTR_COMP_Msk                    (0x1U << RCC_APB2RSTR_COMP_Pos)                   /*!<Comparator reset Set to '1' or clear '0' by software*/
#define  RCC_APB2RSTR_COMP                        RCC_APB2RSTR_COMP_Msk
#define  RCC_APB2RSTR_FLEXCAN2_Pos                (24)
#define  RCC_APB2RSTR_FLEXCAN2_Msk                (0x1U << RCC_APB2RSTR_FLEXCAN2_Pos)               /*!<FLEXCAN2 Reset Set to '1' or clear '0' by software*/
#define  RCC_APB2RSTR_FLEXCAN2                    RCC_APB2RSTR_FLEXCAN2_Msk
#define  RCC_APB2RSTR_MDPWM_Pos                   (27)
#define  RCC_APB2RSTR_MDPWM_Msk                   (0x1U << RCC_APB2RSTR_MDPWM_Pos)                  /*!<MDPWM Reset Set to '1' or clear '0' by software*/
#define  RCC_APB2RSTR_MDPWM                       RCC_APB2RSTR_MDPWM_Msk
#define  RCC_APB2RSTR_MDS_Pos                     (28)
#define  RCC_APB2RSTR_MDS_Msk                     (0x1U << RCC_APB2RSTR_MDS_Pos)                    /*!<MDS Reset Set to '1' or clear '0' by software*/
#define  RCC_APB2RSTR_MDS                         RCC_APB2RSTR_MDS_Msk
#define  RCC_APB2RSTR_LPTIM_Pos                   (30)
#define  RCC_APB2RSTR_LPTIM_Msk                   (0x1U << RCC_APB2RSTR_LPTIM_Pos)                  /*!<LPTIM Reset Set to '1' or clear '0' by software*/
#define  RCC_APB2RSTR_LPTIM                       RCC_APB2RSTR_LPTIM_Msk
#define  RCC_APB2RSTR_LPUART_Pos                  (31)
#define  RCC_APB2RSTR_LPUART_Msk                  (0x1U << RCC_APB2RSTR_LPUART_Pos)                 /*!<LPUART Reset Set to '1' or clear '0' by software*/
#define  RCC_APB2RSTR_LPUART                      RCC_APB2RSTR_LPUART_Msk

/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define  RCC_APB1RSTR_TIM2_Pos                    (0)
#define  RCC_APB1RSTR_TIM2_Msk                    (0x1U << RCC_APB1RSTR_TIM2_Pos)                   /*!<TIM2 Reset*/
#define  RCC_APB1RSTR_TIM2                        RCC_APB1RSTR_TIM2_Msk
#define  RCC_APB1RSTR_TIM3_Pos                    (1)
#define  RCC_APB1RSTR_TIM3_Msk                    (0x1U << RCC_APB1RSTR_TIM3_Pos)                   /*!<TIM3 Reset*/
#define  RCC_APB1RSTR_TIM3                        RCC_APB1RSTR_TIM3_Msk
#define  RCC_APB1RSTR_TIM4_Pos                    (2)
#define  RCC_APB1RSTR_TIM4_Msk                    (0x1U << RCC_APB1RSTR_TIM4_Pos)                   /*!<TIM4 Reset*/
#define  RCC_APB1RSTR_TIM4                        RCC_APB1RSTR_TIM4_Msk
#define  RCC_APB1RSTR_TIM5_Pos                    (3)
#define  RCC_APB1RSTR_TIM5_Msk                    (0x1U << RCC_APB1RSTR_TIM5_Pos)                   /*!<TIM5 Reset*/
#define  RCC_APB1RSTR_TIM5                        RCC_APB1RSTR_TIM5_Msk
#define  RCC_APB1RSTR_TIM6_Pos                    (4)
#define  RCC_APB1RSTR_TIM6_Msk                    (0x1U << RCC_APB1RSTR_TIM6_Pos)                   /*!<TIM6 Reset*/
#define  RCC_APB1RSTR_TIM6                        RCC_APB1RSTR_TIM6_Msk
#define  RCC_APB1RSTR_TIM7_Pos                    (5)
#define  RCC_APB1RSTR_TIM7_Msk                    (0x1U << RCC_APB1RSTR_TIM7_Pos)                   /*!<TIM7 Reset*/
#define  RCC_APB1RSTR_TIM7                        RCC_APB1RSTR_TIM7_Msk
#define  RCC_APB1RSTR_WWDG_Pos                    (11)
#define  RCC_APB1RSTR_WWDG_Msk                    (0x1U << RCC_APB1RSTR_WWDG_Pos)                   /*!<Window Watchdog Reset*/
#define  RCC_APB1RSTR_WWDG                        RCC_APB1RSTR_WWDG_Msk
#define  RCC_APB1RSTR_SPI2_Pos                    (14)
#define  RCC_APB1RSTR_SPI2_Msk                    (0x1U << RCC_APB1RSTR_SPI2_Pos)                   /*!<SPI2 Reset*/
#define  RCC_APB1RSTR_SPI2                        RCC_APB1RSTR_SPI2_Msk
#define  RCC_APB1RSTR_SPI3_Pos                    (15)
#define  RCC_APB1RSTR_SPI3_Msk                    (0x1U << RCC_APB1RSTR_SPI3_Pos)                   /*!<SPI3 Reset*/
#define  RCC_APB1RSTR_SPI3                        RCC_APB1RSTR_SPI3_Msk
#define  RCC_APB1RSTR_USART2_Pos                  (17)
#define  RCC_APB1RSTR_USART2_Msk                  (0x1U << RCC_APB1RSTR_USART2_Pos)                 /*!<USART2 Reset*/
#define  RCC_APB1RSTR_USART2                      RCC_APB1RSTR_USART2_Msk
#define  RCC_APB1RSTR_USART3_Pos                  (18)
#define  RCC_APB1RSTR_USART3_Msk                  (0x1U << RCC_APB1RSTR_USART3_Pos)                 /*!<USART3 Reset*/
#define  RCC_APB1RSTR_USART3                      RCC_APB1RSTR_USART3_Msk
#define  RCC_APB1RSTR_USART4_Pos                  (19)
#define  RCC_APB1RSTR_USART4_Msk                  (0x1U << RCC_APB1RSTR_USART4_Pos)                 /*!<USART4 Reset*/
#define  RCC_APB1RSTR_USART4                      RCC_APB1RSTR_USART4_Msk
#define  RCC_APB1RSTR_USART5_Pos                  (20)
#define  RCC_APB1RSTR_USART5_Msk                  (0x1U << RCC_APB1RSTR_USART5_Pos)                 /*!<USART5 Reset*/
#define  RCC_APB1RSTR_USART5                      RCC_APB1RSTR_USART5_Msk
#define  RCC_APB1RSTR_I2C1_Pos                    (21)
#define  RCC_APB1RSTR_I2C1_Msk                    (0x1U << RCC_APB1RSTR_I2C1_Pos)                   /*!<I2C1 Reset*/
#define  RCC_APB1RSTR_I2C1                        RCC_APB1RSTR_I2C1_Msk
#define  RCC_APB1RSTR_I2C2_Pos                    (22)
#define  RCC_APB1RSTR_I2C2_Msk                    (0x1U << RCC_APB1RSTR_I2C2_Pos)                   /*!<I2C2 Reset*/
#define  RCC_APB1RSTR_I2C2                        RCC_APB1RSTR_I2C2_Msk
#define  RCC_APB1RSTR_CRS_Pos                     (24)
#define  RCC_APB1RSTR_CRS_Msk                     (0x1U << RCC_APB1RSTR_CRS_Pos)                    /*!<CRS Reset*/
#define  RCC_APB1RSTR_CRS                         RCC_APB1RSTR_CRS_Msk
#define  RCC_APB1RSTR_FlexCAN_Pos                 (25)
#define  RCC_APB1RSTR_FlexCAN_Msk                 (0x1U << RCC_APB1RSTR_FlexCAN_Pos)                /*!<FlexCAN Reset*/
#define  RCC_APB1RSTR_FlexCAN                     RCC_APB1RSTR_FlexCAN_Msk
#define  RCC_APB1RSTR_DBG_Pos                     (26)
#define  RCC_APB1RSTR_DBG_Msk                     (0x1U << RCC_APB1RSTR_DBG_Pos)                    /*!<DBG Reset*/
#define  RCC_APB1RSTR_DBG                         RCC_APB1RSTR_DBG_Msk
#define  RCC_APB1RSTR_BKP_Pos                     (27)
#define  RCC_APB1RSTR_BKP_Msk                     (0x1U << RCC_APB1RSTR_BKP_Pos)                    /*!<Backup Interface Reset*/
#define  RCC_APB1RSTR_BKP                         RCC_APB1RSTR_BKP_Msk
#define  RCC_APB1RSTR_PWR_Pos                     (28)
#define  RCC_APB1RSTR_PWR_Msk                     (0x1U << RCC_APB1RSTR_PWR_Pos)                    /*!<Power Interface Reset*/
#define  RCC_APB1RSTR_PWR                         RCC_APB1RSTR_PWR_Msk
#define  RCC_APB1RSTR_DAC_Pos                     (29)
#define  RCC_APB1RSTR_DAC_Msk                     (0x1U << RCC_APB1RSTR_DAC_Pos)                    /*!<DAC Reset*/
#define  RCC_APB1RSTR_DAC                         RCC_APB1RSTR_DAC_Msk

/**
  * @brief RCC_AHBENR2 Register Bit Definition
  */
#define  RCC_AHBENR2_BKRAM_Pos                    (28)
#define  RCC_AHBENR2_BKRAM_Msk                    (0x1U << RCC_AHBENR2_BKRAM_Pos)                   /*!<*/
#define  RCC_AHBENR2_BKRAM                        RCC_AHBENR2_BKRAM_Msk

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define  RCC_AHBENR_GPIOA_Pos                     (0)
#define  RCC_AHBENR_GPIOA_Msk                     (0x1U << RCC_AHBENR_GPIOA_Pos)                    /*!<GPIOA Clock Enable*/
#define  RCC_AHBENR_GPIOA                         RCC_AHBENR_GPIOA_Msk
#define  RCC_AHBENR_GPIOB_Pos                     (1)
#define  RCC_AHBENR_GPIOB_Msk                     (0x1U << RCC_AHBENR_GPIOB_Pos)                    /*!<GPIOB Clock Enable*/
#define  RCC_AHBENR_GPIOB                         RCC_AHBENR_GPIOB_Msk
#define  RCC_AHBENR_GPIOC_Pos                     (2)
#define  RCC_AHBENR_GPIOC_Msk                     (0x1U << RCC_AHBENR_GPIOC_Pos)                    /*!<GPIOC Clock Enable*/
#define  RCC_AHBENR_GPIOC                         RCC_AHBENR_GPIOC_Msk
#define  RCC_AHBENR_GPIOD_Pos                     (3)
#define  RCC_AHBENR_GPIOD_Msk                     (0x1U << RCC_AHBENR_GPIOD_Pos)                    /*!<GPIOD Clock Enable*/
#define  RCC_AHBENR_GPIOD                         RCC_AHBENR_GPIOD_Msk
#define  RCC_AHBENR_GPIOE_Pos                     (4)
#define  RCC_AHBENR_GPIOE_Msk                     (0x1U << RCC_AHBENR_GPIOE_Pos)                    /*!<GPIOE Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_GPIOE                         RCC_AHBENR_GPIOE_Msk
#define  RCC_AHBENR_GPIOF_Pos                     (5)
#define  RCC_AHBENR_GPIOF_Msk                     (0x1U << RCC_AHBENR_GPIOF_Pos)                    /*!<GPIOF Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_GPIOF                         RCC_AHBENR_GPIOF_Msk
#define  RCC_AHBENR_GPIOH_Pos                     (7)
#define  RCC_AHBENR_GPIOH_Msk                     (0x1U << RCC_AHBENR_GPIOH_Pos)                    /*!<GPIOH Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_GPIOH                         RCC_AHBENR_GPIOH_Msk
#define  RCC_AHBENR_GPIOI_Pos                     (8)
#define  RCC_AHBENR_GPIOI_Msk                     (0x1U << RCC_AHBENR_GPIOI_Pos)                    /*!<GPIOI Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_GPIOI                         RCC_AHBENR_GPIOI_Msk
#define  RCC_AHBENR_CRC_Pos                       (12)
#define  RCC_AHBENR_CRC_Msk                       (0x1U << RCC_AHBENR_CRC_Pos)                      /*!<CRC Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_CRC                           RCC_AHBENR_CRC_Msk
#define  RCC_AHBENR_Flash_Pos                     (13)
#define  RCC_AHBENR_Flash_Msk                     (0x1U << RCC_AHBENR_Flash_Pos)                    /*!<Flash Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_Flash                         RCC_AHBENR_Flash_Msk
#define  RCC_AHBENR_SRAM_Pos                      (14)
#define  RCC_AHBENR_SRAM_Msk                      (0x1U << RCC_AHBENR_SRAM_Pos)                     /*!<SRAM Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_SRAM                          RCC_AHBENR_SRAM_Msk
#define  RCC_AHBENR_CORDIC_Pos                    (15)
#define  RCC_AHBENR_CORDIC_Msk                    (0x1U << RCC_AHBENR_CORDIC_Pos)                   /*!<CORDIC Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_CORDIC                        RCC_AHBENR_CORDIC_Msk
#define  RCC_AHBENR_DMA1_Pos                      (21)
#define  RCC_AHBENR_DMA1_Msk                      (0x1U << RCC_AHBENR_DMA1_Pos)                     /*!<DMA1 Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_DMA1                          RCC_AHBENR_DMA1_Msk
#define  RCC_AHBENR_DMA2_Pos                      (22)
#define  RCC_AHBENR_DMA2_Msk                      (0x1U << RCC_AHBENR_DMA2_Pos)                     /*!<DMA2 Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_DMA2                          RCC_AHBENR_DMA2_Msk
#define  RCC_AHBENR_USB_FS_Pos                    (24)
#define  RCC_AHBENR_USB_FS_Msk                    (0x1U << RCC_AHBENR_USB_FS_Pos)                   /*!<USB_FS Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_USB_FS                        RCC_AHBENR_USB_FS_Msk
#define  RCC_AHBENR_QSPI_Pos                      (30)
#define  RCC_AHBENR_QSPI_Msk                      (0x1U << RCC_AHBENR_QSPI_Pos)                     /*!<QSPI Clock Enable Set '1' or clear '0' by software*/
#define  RCC_AHBENR_QSPI                          RCC_AHBENR_QSPI_Msk

/**
  * @brief RCC_APB2ENR Register Bit Definition
  */
#define  RCC_APB2ENR_TIM1_Pos                     (0)
#define  RCC_APB2ENR_TIM1_Msk                     (0x1U << RCC_APB2ENR_TIM1_Pos)                    /*!<TIM1 Clock Enable*/
#define  RCC_APB2ENR_TIM1                         RCC_APB2ENR_TIM1_Msk
#define  RCC_APB2ENR_TIM8_Pos                     (1)
#define  RCC_APB2ENR_TIM8_Msk                     (0x1U << RCC_APB2ENR_TIM8_Pos)                    /*!<TIM8 Clock Enable*/
#define  RCC_APB2ENR_TIM8                         RCC_APB2ENR_TIM8_Msk
#define  RCC_APB2ENR_USART1_Pos                   (4)
#define  RCC_APB2ENR_USART1_Msk                   (0x1U << RCC_APB2ENR_USART1_Pos)                  /*!<USART1 Clock Enable*/
#define  RCC_APB2ENR_USART1                       RCC_APB2ENR_USART1_Msk
#define  RCC_APB2ENR_ADC1_Pos                     (8)
#define  RCC_APB2ENR_ADC1_Msk                     (0x1U << RCC_APB2ENR_ADC1_Pos)                    /*!<ADC1 Clock Enable*/
#define  RCC_APB2ENR_ADC1                         RCC_APB2ENR_ADC1_Msk
#define  RCC_APB2ENR_ADC2_Pos                     (9)
#define  RCC_APB2ENR_ADC2_Msk                     (0x1U << RCC_APB2ENR_ADC2_Pos)                    /*!<ADC2 Clock Enable*/
#define  RCC_APB2ENR_ADC2                         RCC_APB2ENR_ADC2_Msk
#define  RCC_APB2ENR_ADC3_Pos                     (10)
#define  RCC_APB2ENR_ADC3_Msk                     (0x1U << RCC_APB2ENR_ADC3_Pos)                    /*!<ADC3 Clock Enable*/
#define  RCC_APB2ENR_ADC3                         RCC_APB2ENR_ADC3_Msk
#define  RCC_APB2ENR_SPI1_Pos                     (12)
#define  RCC_APB2ENR_SPI1_Msk                     (0x1U << RCC_APB2ENR_SPI1_Pos)                    /*!<SPI1 Clock Enable*/
#define  RCC_APB2ENR_SPI1                         RCC_APB2ENR_SPI1_Msk
#define  RCC_APB2ENR_SYSCFG_Pos                   (14)
#define  RCC_APB2ENR_SYSCFG_Msk                   (0x1U << RCC_APB2ENR_SYSCFG_Pos)                  /*!<SYSCFG Clock Enable*/
#define  RCC_APB2ENR_SYSCFG                       RCC_APB2ENR_SYSCFG_Msk
#define  RCC_APB2ENR_COMP_Pos                     (15)
#define  RCC_APB2ENR_COMP_Msk                     (0x1U << RCC_APB2ENR_COMP_Pos)                    /*!<Comparator Clock Enable Set to '1' or clear '0' by software*/
#define  RCC_APB2ENR_COMP                         RCC_APB2ENR_COMP_Msk
#define  RCC_APB2ENR_FLEXCAN2_Pos                 (24)
#define  RCC_APB2ENR_FLEXCAN2_Msk                 (0x1U << RCC_APB2ENR_FLEXCAN2_Pos)                /*!<FLEXCAN2 Clock Enable Set to '1' or clear '0' by software*/
#define  RCC_APB2ENR_FLEXCAN2                     RCC_APB2ENR_FLEXCAN2_Msk
#define  RCC_APB2ENR_MDPWM_Pos                    (27)
#define  RCC_APB2ENR_MDPWM_Msk                    (0x1U << RCC_APB2ENR_MDPWM_Pos)                   /*!<MDPWM Clock Enable Set to '1' or clear '0' by software*/
#define  RCC_APB2ENR_MDPWM                        RCC_APB2ENR_MDPWM_Msk
#define  RCC_APB2ENR_MDS_Pos                      (28)
#define  RCC_APB2ENR_MDS_Msk                      (0x1U << RCC_APB2ENR_MDS_Pos)                     /*!<MDS Clock Enable Set to '1' or clear '0' by software*/
#define  RCC_APB2ENR_MDS                          RCC_APB2ENR_MDS_Msk
#define  RCC_APB2ENR_LPTIM_Pos                    (30)
#define  RCC_APB2ENR_LPTIM_Msk                    (0x1U << RCC_APB2ENR_LPTIM_Pos)                   /*!<LPTIM Clock Enable Set to '1' or clear '0' by software*/
#define  RCC_APB2ENR_LPTIM                        RCC_APB2ENR_LPTIM_Msk
#define  RCC_APB2ENR_LPUART_Pos                   (31)
#define  RCC_APB2ENR_LPUART_Msk                   (0x1U << RCC_APB2ENR_LPUART_Pos)                  /*!<LPUART Clock Enable Set to '1' or clear '0' by software*/
#define  RCC_APB2ENR_LPUART                       RCC_APB2ENR_LPUART_Msk

/**
  * @brief RCC_APB1ENR Register Bit Definition
  */
#define  RCC_APB1ENR_TIM2_Pos                     (0)
#define  RCC_APB1ENR_TIM2_Msk                     (0x1U << RCC_APB1ENR_TIM2_Pos)                    /*!<TIM2 Clock Enable*/
#define  RCC_APB1ENR_TIM2                         RCC_APB1ENR_TIM2_Msk
#define  RCC_APB1ENR_TIM3_Pos                     (1)
#define  RCC_APB1ENR_TIM3_Msk                     (0x1U << RCC_APB1ENR_TIM3_Pos)                    /*!<TIM3 Clock Enable*/
#define  RCC_APB1ENR_TIM3                         RCC_APB1ENR_TIM3_Msk
#define  RCC_APB1ENR_TIM4_Pos                     (2)
#define  RCC_APB1ENR_TIM4_Msk                     (0x1U << RCC_APB1ENR_TIM4_Pos)                    /*!<TIM4 Clock Enable*/
#define  RCC_APB1ENR_TIM4                         RCC_APB1ENR_TIM4_Msk
#define  RCC_APB1ENR_TIM5_Pos                     (3)
#define  RCC_APB1ENR_TIM5_Msk                     (0x1U << RCC_APB1ENR_TIM5_Pos)                    /*!<TIM5 Clock Enable*/
#define  RCC_APB1ENR_TIM5                         RCC_APB1ENR_TIM5_Msk
#define  RCC_APB1ENR_TIM6_Pos                     (4)
#define  RCC_APB1ENR_TIM6_Msk                     (0x1U << RCC_APB1ENR_TIM6_Pos)                    /*!<TIM6 Clock Enable*/
#define  RCC_APB1ENR_TIM6                         RCC_APB1ENR_TIM6_Msk
#define  RCC_APB1ENR_TIM7_Pos                     (5)
#define  RCC_APB1ENR_TIM7_Msk                     (0x1U << RCC_APB1ENR_TIM7_Pos)                    /*!<TIM7 Clock Enable*/
#define  RCC_APB1ENR_TIM7                         RCC_APB1ENR_TIM7_Msk
#define  RCC_APB1ENR_WWDG_Pos                     (11)
#define  RCC_APB1ENR_WWDG_Msk                     (0x1U << RCC_APB1ENR_WWDG_Pos)                    /*!<Window Watchdog Clock Enable*/
#define  RCC_APB1ENR_WWDG                         RCC_APB1ENR_WWDG_Msk
#define  RCC_APB1ENR_SPI2_Pos                     (14)
#define  RCC_APB1ENR_SPI2_Msk                     (0x1U << RCC_APB1ENR_SPI2_Pos)                    /*!<SPI2 Clock Enable*/
#define  RCC_APB1ENR_SPI2                         RCC_APB1ENR_SPI2_Msk
#define  RCC_APB1ENR_SPI3_Pos                     (15)
#define  RCC_APB1ENR_SPI3_Msk                     (0x1U << RCC_APB1ENR_SPI3_Pos)                    /*!<SPI3 Clock Enable*/
#define  RCC_APB1ENR_SPI3                         RCC_APB1ENR_SPI3_Msk
#define  RCC_APB1ENR_USART2_Pos                   (17)
#define  RCC_APB1ENR_USART2_Msk                   (0x1U << RCC_APB1ENR_USART2_Pos)                  /*!<USART2 Clock Enable*/
#define  RCC_APB1ENR_USART2                       RCC_APB1ENR_USART2_Msk
#define  RCC_APB1ENR_USART3_Pos                   (18)
#define  RCC_APB1ENR_USART3_Msk                   (0x1U << RCC_APB1ENR_USART3_Pos)                  /*!<USART3 Clock Enable*/
#define  RCC_APB1ENR_USART3                       RCC_APB1ENR_USART3_Msk
#define  RCC_APB1ENR_USART4_Pos                   (19)
#define  RCC_APB1ENR_USART4_Msk                   (0x1U << RCC_APB1ENR_USART4_Pos)                  /*!<USART4 Clock Enable*/
#define  RCC_APB1ENR_USART4                       RCC_APB1ENR_USART4_Msk
#define  RCC_APB1ENR_USART5_Pos                   (20)
#define  RCC_APB1ENR_USART5_Msk                   (0x1U << RCC_APB1ENR_USART5_Pos)                  /*!<USART5 Clock Enable*/
#define  RCC_APB1ENR_USART5                       RCC_APB1ENR_USART5_Msk
#define  RCC_APB1ENR_I2C1_Pos                     (21)
#define  RCC_APB1ENR_I2C1_Msk                     (0x1U << RCC_APB1ENR_I2C1_Pos)                    /*!<I2C1 Clock Enable*/
#define  RCC_APB1ENR_I2C1                         RCC_APB1ENR_I2C1_Msk
#define  RCC_APB1ENR_I2C2_Pos                     (22)
#define  RCC_APB1ENR_I2C2_Msk                     (0x1U << RCC_APB1ENR_I2C2_Pos)                    /*!<I2C2 Clock Enable*/
#define  RCC_APB1ENR_I2C2                         RCC_APB1ENR_I2C2_Msk
#define  RCC_APB1ENR_CRS_Pos                      (24)
#define  RCC_APB1ENR_CRS_Msk                      (0x1U << RCC_APB1ENR_CRS_Pos)                     /*!<CRS Clock Enable*/
#define  RCC_APB1ENR_CRS                          RCC_APB1ENR_CRS_Msk
#define  RCC_APB1ENR_FlexCAN_Pos                  (25)
#define  RCC_APB1ENR_FlexCAN_Msk                  (0x1U << RCC_APB1ENR_FlexCAN_Pos)                 /*!<FlexCAN Clock Enable*/
#define  RCC_APB1ENR_FlexCAN                      RCC_APB1ENR_FlexCAN_Msk
#define  RCC_APB1ENR_BKP_Pos                      (27)
#define  RCC_APB1ENR_BKP_Msk                      (0x1U << RCC_APB1ENR_BKP_Pos)                     /*!<Backup Interface Clock Enable*/
#define  RCC_APB1ENR_BKP                          RCC_APB1ENR_BKP_Msk
#define  RCC_APB1ENR_PWR_DBG_Pos                  (28)
#define  RCC_APB1ENR_PWR_DBG_Msk                  (0x1U << RCC_APB1ENR_PWR_DBG_Pos)                 /*!<Power Interface/DBG Clock Enable*/
#define  RCC_APB1ENR_PWR_DBG                      RCC_APB1ENR_PWR_DBG_Msk
#define  RCC_APB1ENR_DAC_Pos                      (29)
#define  RCC_APB1ENR_DAC_Msk                      (0x1U << RCC_APB1ENR_DAC_Pos)                     /*!<DAC Clock Enable*/
#define  RCC_APB1ENR_DAC                          RCC_APB1ENR_DAC_Msk

/**
  * @brief RCC_BDCR Register Bit Definition
  */
#define  RCC_BDCR_LSEON_Pos                       (0)
#define  RCC_BDCR_LSEON_Msk                       (0x1U << RCC_BDCR_LSEON_Pos)                      /*!<*/
#define  RCC_BDCR_LSEON                           RCC_BDCR_LSEON_Msk
#define  RCC_BDCR_LSERDY_Pos                      (1)
#define  RCC_BDCR_LSERDY_Msk                      (0x1U << RCC_BDCR_LSERDY_Pos)                     /*!<*/
#define  RCC_BDCR_LSERDY                          RCC_BDCR_LSERDY_Msk
#define  RCC_BDCR_LSEBYP_Pos                      (2)
#define  RCC_BDCR_LSEBYP_Msk                      (0x1U << RCC_BDCR_LSEBYP_Pos)                     /*!<*/
#define  RCC_BDCR_LSEBYP                          RCC_BDCR_LSEBYP_Msk
#define  RCC_BDCR_RTCSEL_Pos                      (8)
#define  RCC_BDCR_RTCSEL_Msk                      (0x3U << RCC_BDCR_RTCSEL_Pos)                     /*!<*/
#define  RCC_BDCR_RTCSEL                          RCC_BDCR_RTCSEL_Msk
#define  RCC_BDCR_RTCSEL_Bit0                     (0x1U << RCC_BDCR_RTCSEL_Pos) 
#define  RCC_BDCR_RTCSEL_Bit1                     (0x2U << RCC_BDCR_RTCSEL_Pos) 
#define  RCC_BDCR_RTCEN_Pos                       (15)
#define  RCC_BDCR_RTCEN_Msk                       (0x1U << RCC_BDCR_RTCEN_Pos)                      /*!<*/
#define  RCC_BDCR_RTCEN                           RCC_BDCR_RTCEN_Msk
#define  RCC_BDCR_BDRST_Pos                       (16)
#define  RCC_BDCR_BDRST_Msk                       (0x1U << RCC_BDCR_BDRST_Pos)                      /*!<*/
#define  RCC_BDCR_BDRST                           RCC_BDCR_BDRST_Msk
#define  RCC_BDCR_DBP_Pos                         (24)
#define  RCC_BDCR_DBP_Msk                         (0x1U << RCC_BDCR_DBP_Pos)                        /*!<*/
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
#define  RCC_CSR_LSIOE_Pos                        (5)
#define  RCC_CSR_LSIOE_Msk                        (0x1U << RCC_CSR_LSIOE_Pos)                       /*!<LSI Output Enable*/
#define  RCC_CSR_LSIOE                            RCC_CSR_LSIOE_Msk
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
#define  RCC_CSR_WWDGRSTF_Pos                     (30)
#define  RCC_CSR_WWDGRSTF_Msk                     (0x1U << RCC_CSR_WWDGRSTF_Pos)                    /*!<Window Watchdog Reset Flag*/
#define  RCC_CSR_WWDGRSTF                         RCC_CSR_WWDGRSTF_Msk
#define  RCC_CSR_LPWRRSTF_Pos                     (31)
#define  RCC_CSR_LPWRRSTF_Msk                     (0x1U << RCC_CSR_LPWRRSTF_Pos)                    /*!<Low Power Reset Flag*/
#define  RCC_CSR_LPWRRSTF                         RCC_CSR_LPWRRSTF_Msk

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define  RCC_SYSCFG_PROG_CHECK_EN_Pos             (0)
#define  RCC_SYSCFG_PROG_CHECK_EN_Msk             (0x1U << RCC_SYSCFG_PROG_CHECK_EN_Pos)            /*!<Check whether the data in Flash is 0xFF when writing Flash*/
#define  RCC_SYSCFG_PROG_CHECK_EN                 RCC_SYSCFG_PROG_CHECK_EN_Msk
#define  RCC_SYSCFG_HSE_RFB_SEL_Pos               (8)
#define  RCC_SYSCFG_HSE_RFB_SEL_Msk               (0x3U << RCC_SYSCFG_HSE_RFB_SEL_Pos)              /*!<HSE_RFB_SEL: Feedback Resistor Selection.*/
#define  RCC_SYSCFG_HSE_RFB_SEL                   RCC_SYSCFG_HSE_RFB_SEL_Msk
#define  RCC_SYSCFG_HSE_RFB_SEL_Bit0              (0x1U << RCC_SYSCFG_HSE_RFB_SEL_Pos) 
#define  RCC_SYSCFG_HSE_RFB_SEL_Bit1              (0x2U << RCC_SYSCFG_HSE_RFB_SEL_Pos) 
#define  RCC_SYSCFG_HSELPFEN_Pos                  (14)
#define  RCC_SYSCFG_HSELPFEN_Msk                  (0x1U << RCC_SYSCFG_HSELPFEN_Pos)                 /*!<External Crystal Low-pass Filter Enable*/
#define  RCC_SYSCFG_HSELPFEN                      RCC_SYSCFG_HSELPFEN_Msk

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define  RCC_CFGR2_TIMADV_CKSEL_Pos               (0)
#define  RCC_CFGR2_TIMADV_CKSEL_Msk               (0x1U << RCC_CFGR2_TIMADV_CKSEL_Pos)              /*!<*/
#define  RCC_CFGR2_TIMADV_CKSEL                   RCC_CFGR2_TIMADV_CKSEL_Msk
#define  RCC_CFGR2_TIMADV_PRE_Pos                 (1)
#define  RCC_CFGR2_TIMADV_PRE_Msk                 (0x7U << RCC_CFGR2_TIMADV_PRE_Pos)                /*!<*/
#define  RCC_CFGR2_TIMADV_PRE                     RCC_CFGR2_TIMADV_PRE_Msk
#define  RCC_CFGR2_TIMADV_PRE_Bit0                (0x1U << RCC_CFGR2_TIMADV_PRE_Pos) 
#define  RCC_CFGR2_TIMADV_PRE_Bit1                (0x2U << RCC_CFGR2_TIMADV_PRE_Pos) 
#define  RCC_CFGR2_TIMADV_PRE_Bit2                (0x4U << RCC_CFGR2_TIMADV_PRE_Pos) 
#define  RCC_CFGR2_CAN1CLKSEL_Pos                 (8)
#define  RCC_CFGR2_CAN1CLKSEL_Msk                 (0x3U << RCC_CFGR2_CAN1CLKSEL_Pos)                /*!<*/
#define  RCC_CFGR2_CAN1CLKSEL                     RCC_CFGR2_CAN1CLKSEL_Msk
#define  RCC_CFGR2_CAN1CLKSEL_Bit0                (0x1U << RCC_CFGR2_CAN1CLKSEL_Pos) 
#define  RCC_CFGR2_CAN1CLKSEL_Bit1                (0x2U << RCC_CFGR2_CAN1CLKSEL_Pos) 
#define  RCC_CFGR2_CAN1PRE_Pos                    (12)
#define  RCC_CFGR2_CAN1PRE_Msk                    (0x3U << RCC_CFGR2_CAN1PRE_Pos)                   /*!<*/
#define  RCC_CFGR2_CAN1PRE                        RCC_CFGR2_CAN1PRE_Msk
#define  RCC_CFGR2_CAN1PRE_Bit0                   (0x1U << RCC_CFGR2_CAN1PRE_Pos) 
#define  RCC_CFGR2_CAN1PRE_Bit1                   (0x2U << RCC_CFGR2_CAN1PRE_Pos) 
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Pos            (16)
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Msk            (0xFU << RCC_CFGR2_APB1_CLK_HV_PRE_Pos)           /*!<APB1_HV Output Clock Division Factor*/
#define  RCC_CFGR2_APB1_CLK_HV_PRE                RCC_CFGR2_APB1_CLK_HV_PRE_Msk
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Bit0           (0x1U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos) 
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Bit1           (0x2U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos) 
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Bit2           (0x4U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos) 
#define  RCC_CFGR2_APB1_CLK_HV_PRE_Bit3           (0x8U << RCC_CFGR2_APB1_CLK_HV_PRE_Pos) 
#define  RCC_CFGR2_MCO_PRE_Pos                    (20)
#define  RCC_CFGR2_MCO_PRE_Msk                    (0xFU << RCC_CFGR2_MCO_PRE_Pos)                   /*!<MCOPRE: MCO Clock Prescaler Factor*/
#define  RCC_CFGR2_MCO_PRE                        RCC_CFGR2_MCO_PRE_Msk
#define  RCC_CFGR2_MCO_PRE_Bit0                   (0x1U << RCC_CFGR2_MCO_PRE_Pos) 
#define  RCC_CFGR2_MCO_PRE_Bit1                   (0x2U << RCC_CFGR2_MCO_PRE_Pos) 
#define  RCC_CFGR2_MCO_PRE_Bit2                   (0x4U << RCC_CFGR2_MCO_PRE_Pos) 
#define  RCC_CFGR2_MCO_PRE_Bit3                   (0x8U << RCC_CFGR2_MCO_PRE_Pos) 
#define  RCC_CFGR2_LPUARTCLKSEL_Pos               (26)
#define  RCC_CFGR2_LPUARTCLKSEL_Msk               (0x3U << RCC_CFGR2_LPUARTCLKSEL_Pos)              /*!<*/
#define  RCC_CFGR2_LPUARTCLKSEL                   RCC_CFGR2_LPUARTCLKSEL_Msk
#define  RCC_CFGR2_LPUARTCLKSEL_Bit0              (0x1U << RCC_CFGR2_LPUARTCLKSEL_Pos) 
#define  RCC_CFGR2_LPUARTCLKSEL_Bit1              (0x2U << RCC_CFGR2_LPUARTCLKSEL_Pos) 
#define  RCC_CFGR2_LPTIMCLKSEL_Pos                (29)
#define  RCC_CFGR2_LPTIMCLKSEL_Msk                (0x3U << RCC_CFGR2_LPTIMCLKSEL_Pos)               /*!<*/
#define  RCC_CFGR2_LPTIMCLKSEL                    RCC_CFGR2_LPTIMCLKSEL_Msk
#define  RCC_CFGR2_LPTIMCLKSEL_Bit0               (0x1U << RCC_CFGR2_LPTIMCLKSEL_Pos) 
#define  RCC_CFGR2_LPTIMCLKSEL_Bit1               (0x2U << RCC_CFGR2_LPTIMCLKSEL_Pos) 

/**
  * @brief RCC_ICSCR Register Bit Definition
  */
#define  RCC_ICSCR_TRIM_CRS_SEL_Pos               (0)
#define  RCC_ICSCR_TRIM_CRS_SEL_Msk               (0x1U << RCC_ICSCR_TRIM_CRS_SEL_Pos)              /*!<*/
#define  RCC_ICSCR_TRIM_CRS_SEL                   RCC_ICSCR_TRIM_CRS_SEL_Msk

/**
  * @brief RCC_PLL1CFGR Register Bit Definition
  */
#define  RCC_PLL1CFGR_PLL1SRC_Pos                 (0)
#define  RCC_PLL1CFGR_PLL1SRC_Msk                 (0x1U << RCC_PLL1CFGR_PLL1SRC_Pos)                /*!<*/
#define  RCC_PLL1CFGR_PLL1SRC                     RCC_PLL1CFGR_PLL1SRC_Msk
#define  RCC_PLL1CFGR_PLL1XTPRE_Pos               (1)
#define  RCC_PLL1CFGR_PLL1XTPRE_Msk               (0x1U << RCC_PLL1CFGR_PLL1XTPRE_Pos)              /*!<*/
#define  RCC_PLL1CFGR_PLL1XTPRE                   RCC_PLL1CFGR_PLL1XTPRE_Msk
#define  RCC_PLL1CFGR_PLL1_ICTRL_Pos              (2)
#define  RCC_PLL1CFGR_PLL1_ICTRL_Msk              (0x3U << RCC_PLL1CFGR_PLL1_ICTRL_Pos)             /*!<*/
#define  RCC_PLL1CFGR_PLL1_ICTRL                  RCC_PLL1CFGR_PLL1_ICTRL_Msk
#define  RCC_PLL1CFGR_PLL1_ICTRL_Bit0             (0x1U << RCC_PLL1CFGR_PLL1_ICTRL_Pos) 
#define  RCC_PLL1CFGR_PLL1_ICTRL_Bit1             (0x2U << RCC_PLL1CFGR_PLL1_ICTRL_Pos) 
#define  RCC_PLL1CFGR_PLL1_LDS_Pos                (4)
#define  RCC_PLL1CFGR_PLL1_LDS_Msk                (0x7U << RCC_PLL1CFGR_PLL1_LDS_Pos)               /*!<PLL1 Lock Detector Accuracy Select*/
#define  RCC_PLL1CFGR_PLL1_LDS                    RCC_PLL1CFGR_PLL1_LDS_Msk
#define  RCC_PLL1CFGR_PLL1_LDS_Bit0               (0x1U << RCC_PLL1CFGR_PLL1_LDS_Pos) 
#define  RCC_PLL1CFGR_PLL1_LDS_Bit1               (0x2U << RCC_PLL1CFGR_PLL1_LDS_Pos) 
#define  RCC_PLL1CFGR_PLL1_LDS_Bit2               (0x4U << RCC_PLL1CFGR_PLL1_LDS_Pos) 
#define  RCC_PLL1CFGR_PLL1DIV_Pos                 (8)
#define  RCC_PLL1CFGR_PLL1DIV_Msk                 (0x7U << RCC_PLL1CFGR_PLL1DIV_Pos)                /*!<PLL1 Divide Factor*/
#define  RCC_PLL1CFGR_PLL1DIV                     RCC_PLL1CFGR_PLL1DIV_Msk
#define  RCC_PLL1CFGR_PLL1DIV_Bit0                (0x1U << RCC_PLL1CFGR_PLL1DIV_Pos) 
#define  RCC_PLL1CFGR_PLL1DIV_Bit1                (0x2U << RCC_PLL1CFGR_PLL1DIV_Pos) 
#define  RCC_PLL1CFGR_PLL1DIV_Bit2                (0x4U << RCC_PLL1CFGR_PLL1DIV_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Pos                 (16)
#define  RCC_PLL1CFGR_PLL1MUL_Msk                 (0xFFU << RCC_PLL1CFGR_PLL1MUL_Pos)               /*!<PLL1 Multiplication Factor*/
#define  RCC_PLL1CFGR_PLL1MUL                     RCC_PLL1CFGR_PLL1MUL_Msk
#define  RCC_PLL1CFGR_PLL1MUL_Bit0                (0x01U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit1                (0x02U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit2                (0x04U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit3                (0x08U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit4                (0x10U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit5                (0x20U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit6                (0x40U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1MUL_Bit7                (0x80U << RCC_PLL1CFGR_PLL1MUL_Pos) 
#define  RCC_PLL1CFGR_PLL1PDIV_Pos                (24)
#define  RCC_PLL1CFGR_PLL1PDIV_Msk                (0x7U << RCC_PLL1CFGR_PLL1PDIV_Pos)               /*!<PLL1 Pre-divider Factor*/
#define  RCC_PLL1CFGR_PLL1PDIV                    RCC_PLL1CFGR_PLL1PDIV_Msk
#define  RCC_PLL1CFGR_PLL1PDIV_Bit0               (0x1U << RCC_PLL1CFGR_PLL1PDIV_Pos) 
#define  RCC_PLL1CFGR_PLL1PDIV_Bit1               (0x2U << RCC_PLL1CFGR_PLL1PDIV_Pos) 
#define  RCC_PLL1CFGR_PLL1PDIV_Bit2               (0x4U << RCC_PLL1CFGR_PLL1PDIV_Pos) 

/**
  * @brief RCC_PLL2CFGR Register Bit Definition
  */
#define  RCC_PLL2CFGR_PLL2SRC_Pos                 (0)
#define  RCC_PLL2CFGR_PLL2SRC_Msk                 (0x1U << RCC_PLL2CFGR_PLL2SRC_Pos)                /*!<*/
#define  RCC_PLL2CFGR_PLL2SRC                     RCC_PLL2CFGR_PLL2SRC_Msk
#define  RCC_PLL2CFGR_PLL2XTPRE_Pos               (1)
#define  RCC_PLL2CFGR_PLL2XTPRE_Msk               (0x1U << RCC_PLL2CFGR_PLL2XTPRE_Pos)              /*!<*/
#define  RCC_PLL2CFGR_PLL2XTPRE                   RCC_PLL2CFGR_PLL2XTPRE_Msk
#define  RCC_PLL2CFGR_PLL2_ICTRL_Pos              (2)
#define  RCC_PLL2CFGR_PLL2_ICTRL_Msk              (0x3U << RCC_PLL2CFGR_PLL2_ICTRL_Pos)             /*!<*/
#define  RCC_PLL2CFGR_PLL2_ICTRL                  RCC_PLL2CFGR_PLL2_ICTRL_Msk
#define  RCC_PLL2CFGR_PLL2_ICTRL_Bit0             (0x1U << RCC_PLL2CFGR_PLL2_ICTRL_Pos) 
#define  RCC_PLL2CFGR_PLL2_ICTRL_Bit1             (0x2U << RCC_PLL2CFGR_PLL2_ICTRL_Pos) 
#define  RCC_PLL2CFGR_PLL2_LDS_Pos                (4)
#define  RCC_PLL2CFGR_PLL2_LDS_Msk                (0x7U << RCC_PLL2CFGR_PLL2_LDS_Pos)               /*!<PLL2 Lock Detector Accuracy Select*/
#define  RCC_PLL2CFGR_PLL2_LDS                    RCC_PLL2CFGR_PLL2_LDS_Msk
#define  RCC_PLL2CFGR_PLL2_LDS_Bit0               (0x1U << RCC_PLL2CFGR_PLL2_LDS_Pos) 
#define  RCC_PLL2CFGR_PLL2_LDS_Bit1               (0x2U << RCC_PLL2CFGR_PLL2_LDS_Pos) 
#define  RCC_PLL2CFGR_PLL2_LDS_Bit2               (0x4U << RCC_PLL2CFGR_PLL2_LDS_Pos) 
#define  RCC_PLL2CFGR_PLL2DIV_Pos                 (8)
#define  RCC_PLL2CFGR_PLL2DIV_Msk                 (0x7U << RCC_PLL2CFGR_PLL2DIV_Pos)                /*!<PLL2 Divide Factor*/
#define  RCC_PLL2CFGR_PLL2DIV                     RCC_PLL2CFGR_PLL2DIV_Msk
#define  RCC_PLL2CFGR_PLL2DIV_Bit0                (0x1U << RCC_PLL2CFGR_PLL2DIV_Pos) 
#define  RCC_PLL2CFGR_PLL2DIV_Bit1                (0x2U << RCC_PLL2CFGR_PLL2DIV_Pos) 
#define  RCC_PLL2CFGR_PLL2DIV_Bit2                (0x4U << RCC_PLL2CFGR_PLL2DIV_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Pos                 (16)
#define  RCC_PLL2CFGR_PLL2MUL_Msk                 (0xFFU << RCC_PLL2CFGR_PLL2MUL_Pos)               /*!<PLL2 Multiplication Factor*/
#define  RCC_PLL2CFGR_PLL2MUL                     RCC_PLL2CFGR_PLL2MUL_Msk
#define  RCC_PLL2CFGR_PLL2MUL_Bit0                (0x01U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit1                (0x02U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit2                (0x04U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit3                (0x08U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit4                (0x10U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit5                (0x20U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit6                (0x40U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2MUL_Bit7                (0x80U << RCC_PLL2CFGR_PLL2MUL_Pos) 
#define  RCC_PLL2CFGR_PLL2PDIV_Pos                (24)
#define  RCC_PLL2CFGR_PLL2PDIV_Msk                (0x7U << RCC_PLL2CFGR_PLL2PDIV_Pos)               /*!<PLL2 Pre-divider Factor*/
#define  RCC_PLL2CFGR_PLL2PDIV                    RCC_PLL2CFGR_PLL2PDIV_Msk
#define  RCC_PLL2CFGR_PLL2PDIV_Bit0               (0x1U << RCC_PLL2CFGR_PLL2PDIV_Pos) 
#define  RCC_PLL2CFGR_PLL2PDIV_Bit1               (0x2U << RCC_PLL2CFGR_PLL2PDIV_Pos) 
#define  RCC_PLL2CFGR_PLL2PDIV_Bit2               (0x4U << RCC_PLL2CFGR_PLL2PDIV_Pos) 

/**
  * @brief RCC_CFGR3 Register Bit Definition
  */
#define  RCC_CFGR3_I2S1CLKSEL_Pos                 (16)
#define  RCC_CFGR3_I2S1CLKSEL_Msk                 (0x1U << RCC_CFGR3_I2S1CLKSEL_Pos)                /*!<*/
#define  RCC_CFGR3_I2S1CLKSEL                     RCC_CFGR3_I2S1CLKSEL_Msk
#define  RCC_CFGR3_I2S2CLKSEL_Pos                 (17)
#define  RCC_CFGR3_I2S2CLKSEL_Msk                 (0x1U << RCC_CFGR3_I2S2CLKSEL_Pos)                /*!<*/
#define  RCC_CFGR3_I2S2CLKSEL                     RCC_CFGR3_I2S2CLKSEL_Msk
#define  RCC_CFGR3_I2S3CLKSEL_Pos                 (18)
#define  RCC_CFGR3_I2S3CLKSEL_Msk                 (0x1U << RCC_CFGR3_I2S3CLKSEL_Pos)                /*!<*/
#define  RCC_CFGR3_I2S3CLKSEL                     RCC_CFGR3_I2S3CLKSEL_Msk

/**
  * @brief RCC_CANCFGR Register Bit Definition
  */
#define  RCC_CANCFGR_CAN1CLKSEL_Pos               (0)
#define  RCC_CANCFGR_CAN1CLKSEL_Msk               (0x3U << RCC_CANCFGR_CAN1CLKSEL_Pos)              /*!<*/
#define  RCC_CANCFGR_CAN1CLKSEL                   RCC_CANCFGR_CAN1CLKSEL_Msk
#define  RCC_CANCFGR_CAN1CLKSEL_Bit0              (0x1U << RCC_CANCFGR_CAN1CLKSEL_Pos) 
#define  RCC_CANCFGR_CAN1CLKSEL_Bit1              (0x2U << RCC_CANCFGR_CAN1CLKSEL_Pos) 
#define  RCC_CANCFGR_CAN1PRE_Pos                  (3)
#define  RCC_CANCFGR_CAN1PRE_Msk                  (0x3U << RCC_CANCFGR_CAN1PRE_Pos)                 /*!<*/
#define  RCC_CANCFGR_CAN1PRE                      RCC_CANCFGR_CAN1PRE_Msk
#define  RCC_CANCFGR_CAN1PRE_Bit0                 (0x1U << RCC_CANCFGR_CAN1PRE_Pos) 
#define  RCC_CANCFGR_CAN1PRE_Bit1                 (0x2U << RCC_CANCFGR_CAN1PRE_Pos) 
#define  RCC_CANCFGR_CAN2CLKSEL_Pos               (8)
#define  RCC_CANCFGR_CAN2CLKSEL_Msk               (0x3U << RCC_CANCFGR_CAN2CLKSEL_Pos)              /*!<*/
#define  RCC_CANCFGR_CAN2CLKSEL                   RCC_CANCFGR_CAN2CLKSEL_Msk
#define  RCC_CANCFGR_CAN2CLKSEL_Bit0              (0x1U << RCC_CANCFGR_CAN2CLKSEL_Pos) 
#define  RCC_CANCFGR_CAN2CLKSEL_Bit1              (0x2U << RCC_CANCFGR_CAN2CLKSEL_Pos) 
#define  RCC_CANCFGR_CAN2PRE_Pos                  (11)
#define  RCC_CANCFGR_CAN2PRE_Msk                  (0x3U << RCC_CANCFGR_CAN2PRE_Pos)                 /*!<*/
#define  RCC_CANCFGR_CAN2PRE                      RCC_CANCFGR_CAN2PRE_Msk
#define  RCC_CANCFGR_CAN2PRE_Bit0                 (0x1U << RCC_CANCFGR_CAN2PRE_Pos) 
#define  RCC_CANCFGR_CAN2PRE_Bit1                 (0x2U << RCC_CANCFGR_CAN2PRE_Pos) 

/**
  * @brief RCC_ADC1CFGR Register Bit Definition
  */
#define  RCC_ADC1CFGR_PRE_Pos                     (0)
#define  RCC_ADC1CFGR_PRE_Msk                     (0xFU << RCC_ADC1CFGR_PRE_Pos)                    /*!<*/
#define  RCC_ADC1CFGR_PRE                         RCC_ADC1CFGR_PRE_Msk
#define  RCC_ADC1CFGR_PRE_Bit0                    (0x1U << RCC_ADC1CFGR_PRE_Pos) 
#define  RCC_ADC1CFGR_PRE_Bit1                    (0x2U << RCC_ADC1CFGR_PRE_Pos) 
#define  RCC_ADC1CFGR_PRE_Bit2                    (0x4U << RCC_ADC1CFGR_PRE_Pos) 
#define  RCC_ADC1CFGR_PRE_Bit3                    (0x8U << RCC_ADC1CFGR_PRE_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Pos                  (8)
#define  RCC_ADC1CFGR_PRECAL_Msk                  (0x1FFU << RCC_ADC1CFGR_PRECAL_Pos)               /*!<*/
#define  RCC_ADC1CFGR_PRECAL                      RCC_ADC1CFGR_PRECAL_Msk
#define  RCC_ADC1CFGR_PRECAL_Bit0                 (0x001U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit1                 (0x002U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit2                 (0x004U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit3                 (0x008U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit4                 (0x010U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit5                 (0x020U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit6                 (0x040U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit7                 (0x080U << RCC_ADC1CFGR_PRECAL_Pos) 
#define  RCC_ADC1CFGR_PRECAL_Bit8                 (0x100U << RCC_ADC1CFGR_PRECAL_Pos) 

/**
  * @brief RCC_ADC2CFGR Register Bit Definition
  */
#define  RCC_ADC2CFGR_PRE_Pos                     (0)
#define  RCC_ADC2CFGR_PRE_Msk                     (0xFU << RCC_ADC2CFGR_PRE_Pos)                    /*!<*/
#define  RCC_ADC2CFGR_PRE                         RCC_ADC2CFGR_PRE_Msk
#define  RCC_ADC2CFGR_PRE_Bit0                    (0x1U << RCC_ADC2CFGR_PRE_Pos) 
#define  RCC_ADC2CFGR_PRE_Bit1                    (0x2U << RCC_ADC2CFGR_PRE_Pos) 
#define  RCC_ADC2CFGR_PRE_Bit2                    (0x4U << RCC_ADC2CFGR_PRE_Pos) 
#define  RCC_ADC2CFGR_PRE_Bit3                    (0x8U << RCC_ADC2CFGR_PRE_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Pos                  (8)
#define  RCC_ADC2CFGR_PRECAL_Msk                  (0x1FFU << RCC_ADC2CFGR_PRECAL_Pos)               /*!<*/
#define  RCC_ADC2CFGR_PRECAL                      RCC_ADC2CFGR_PRECAL_Msk
#define  RCC_ADC2CFGR_PRECAL_Bit0                 (0x001U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit1                 (0x002U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit2                 (0x004U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit3                 (0x008U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit4                 (0x010U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit5                 (0x020U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit6                 (0x040U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit7                 (0x080U << RCC_ADC2CFGR_PRECAL_Pos) 
#define  RCC_ADC2CFGR_PRECAL_Bit8                 (0x100U << RCC_ADC2CFGR_PRECAL_Pos) 

/**
  * @brief RCC_ADC3CFGR Register Bit Definition
  */
#define  RCC_ADC3CFGR_PRE_Pos                     (0)
#define  RCC_ADC3CFGR_PRE_Msk                     (0xFU << RCC_ADC3CFGR_PRE_Pos)                    /*!<*/
#define  RCC_ADC3CFGR_PRE                         RCC_ADC3CFGR_PRE_Msk
#define  RCC_ADC3CFGR_PRE_Bit0                    (0x1U << RCC_ADC3CFGR_PRE_Pos) 
#define  RCC_ADC3CFGR_PRE_Bit1                    (0x2U << RCC_ADC3CFGR_PRE_Pos) 
#define  RCC_ADC3CFGR_PRE_Bit2                    (0x4U << RCC_ADC3CFGR_PRE_Pos) 
#define  RCC_ADC3CFGR_PRE_Bit3                    (0x8U << RCC_ADC3CFGR_PRE_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Pos                  (8)
#define  RCC_ADC3CFGR_PRECAL_Msk                  (0x1FFU << RCC_ADC3CFGR_PRECAL_Pos)               /*!<*/
#define  RCC_ADC3CFGR_PRECAL                      RCC_ADC3CFGR_PRECAL_Msk
#define  RCC_ADC3CFGR_PRECAL_Bit0                 (0x001U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit1                 (0x002U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit2                 (0x004U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit3                 (0x008U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit4                 (0x010U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit5                 (0x020U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit6                 (0x040U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit7                 (0x080U << RCC_ADC3CFGR_PRECAL_Pos) 
#define  RCC_ADC3CFGR_PRECAL_Bit8                 (0x100U << RCC_ADC3CFGR_PRECAL_Pos) 

/**
  * @brief RCC_DACCFGR Register Bit Definition
  */
#define  RCC_DACCFGR_PRE_Pos                      (0)
#define  RCC_DACCFGR_PRE_Msk                      (0x7FU << RCC_DACCFGR_PRE_Pos)                    /*!<*/
#define  RCC_DACCFGR_PRE                          RCC_DACCFGR_PRE_Msk
#define  RCC_DACCFGR_PRE_Bit0                     (0x01U << RCC_DACCFGR_PRE_Pos) 
#define  RCC_DACCFGR_PRE_Bit1                     (0x02U << RCC_DACCFGR_PRE_Pos) 
#define  RCC_DACCFGR_PRE_Bit2                     (0x04U << RCC_DACCFGR_PRE_Pos) 
#define  RCC_DACCFGR_PRE_Bit3                     (0x08U << RCC_DACCFGR_PRE_Pos) 
#define  RCC_DACCFGR_PRE_Bit4                     (0x10U << RCC_DACCFGR_PRE_Pos) 
#define  RCC_DACCFGR_PRE_Bit5                     (0x20U << RCC_DACCFGR_PRE_Pos) 
#define  RCC_DACCFGR_PRE_Bit6                     (0x40U << RCC_DACCFGR_PRE_Pos) 

/**
  * @brief RCC_TPIUCFGR Register Bit Definition
  */
#define  RCC_TPIUCFGR_PRE_Pos                     (0)
#define  RCC_TPIUCFGR_PRE_Msk                     (0x3U << RCC_TPIUCFGR_PRE_Pos)                    /*!<*/
#define  RCC_TPIUCFGR_PRE                         RCC_TPIUCFGR_PRE_Msk
#define  RCC_TPIUCFGR_PRE_Bit0                    (0x1U << RCC_TPIUCFGR_PRE_Pos) 
#define  RCC_TPIUCFGR_PRE_Bit1                    (0x2U << RCC_TPIUCFGR_PRE_Pos) 


#endif

