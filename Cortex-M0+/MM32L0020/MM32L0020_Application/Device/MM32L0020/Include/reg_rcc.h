/***********************************************************************************************************************
    @file     reg_rcc.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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

#ifndef __REG_RCC_H
#define __REG_RCC_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0plus.h>

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/**
  * @brief RCC Base Address Definition
  */
#define RCC_BASE                        (AHBPERIPH_BASE + 0x1000) /*!< Base Address: 0x40021000 */

/**
  * @brief RCC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                    /*!< Control Register                               offset: 0x00 */
    __IO uint32_t CFGR;                  /*!< Configuration Register                         offset: 0x04 */
    __IO uint32_t CIR;                   /*!< Clock Interrupt Register                       offset: 0x08 */
    __IO uint32_t RESERVED0x0C;          /*!< RESERVED                                       offset: 0x0C */
    __IO uint32_t APB1RSTR;              /*!< Advanced Peripheral Bus 1 Reset Register       offset: 0x10 */
    __IO uint32_t AHBENR;                /*!< Advanced High Performance Bus Enable Register  offset: 0x14 */
    __IO uint32_t RESERVED0x18;          /*!< Advanced Peripheral Bus 2 Enable Register      offset: 0x18 */
    __IO uint32_t APB1ENR;               /*!< Advanced Peripheral Bus 1 Enable Register      offset: 0x1C */
    __IO uint32_t RESERVED0x24;          /*!< Reserved                                       offset: 0x20 */
    __IO uint32_t CSR;                   /*!< Control Status Register                        offset: 0x24 */
    __IO uint32_t AHBRSTR;               /*!< Advanced High Performance Bus Reset Register   offset: 0x28 */
    __IO uint32_t CFGR2;                 /*!< Configuration Register 2                       offset: 0x2C */
    __IO uint32_t RESERVEDOFFSET0X30[4]; /*!< Reserved                                       offset: 0x30 34 38 3C */
    __IO uint32_t SYSCFGR;               /*!< System Configuration Register                  offset: 0x40 */
    __IO uint32_t RESERVED0x44[3];       /*!< Reserved                                       offset: 0x44 48 4C */
    __IO uint32_t PLLCFGR;               /*!< PLL Configuration Register                     offset: 0x50 */
} RCC_TypeDef;

/**
  * @brief RCC type pointer Definition
  */
#define RCC                             ((RCC_TypeDef *)RCC_BASE)

/**
  * @brief RCC_CR Register Bit Definition
  */
#define RCC_CR_HSION_Pos                (0)
#define RCC_CR_HSION_Msk                (0x01U << RCC_CR_HSION_Pos)         /*!< Internal High Speed clock enable */
#define RCC_CR_HSIRDY_Pos               (1)
#define RCC_CR_HSIRDY_Msk               (0x01U << RCC_CR_HSIRDY_Pos)        /*!< Internal High Speed clock ready flag */
#define RCC_CR_HSIDIV_Pos               (11)
#define RCC_CR_HSIDIV_Msk               (0x07U << RCC_CR_HSIDIV_Pos)
#define RCC_CR_HSIDIV_1                 (0x00U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 1   factor  */
#define RCC_CR_HSIDIV_2                 (0x01U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 2   factor  */
#define RCC_CR_HSIDIV_4                 (0x02U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 4   factor  */
#define RCC_CR_HSIDIV_8                 (0x03U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 8   factor  */
#define RCC_CR_HSIDIV_16                (0x04U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 16  factor  */
#define RCC_CR_HSIDIV_32                (0x05U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 32  factor  */
#define RCC_CR_HSIDIV_64                (0x06U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 64  factor  */
#define RCC_CR_HSIDIV_128               (0x07U << RCC_CR_HSIDIV_Pos)        /*!< HSI clock division 128 factor  */
#define RCC_CR_PLLON_Pos                (24)
#define RCC_CR_PLLON_Msk                (0x01U << RCC_CR_PLLON_Pos)         /*!< PLL enable */
#define RCC_CR_PLLRDY_Pos               (25)
#define RCC_CR_PLLRDY_Msk               (0x01U << RCC_CR_PLLRDY_Pos)        /*!< PLL clock ready flag */

/**
  * @brief RCC_CFGR Register Bit Definition
  */
#define RCC_CFGR_SW_Pos                 (0)
#define RCC_CFGR_SW_Msk                 (0x03U << RCC_CFGR_SW_Pos)          /*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_HSI                 (0x00U << RCC_CFGR_SW_Pos)          /*!< HSI selected as system clock */
#define RCC_CFGR_SW_PLL                 (0x02U << RCC_CFGR_SW_Pos)          /*!< PLL selected as system clock */
#define RCC_CFGR_SW_LSI                 (0x03U << RCC_CFGR_SW_Pos)          /*!< LSI selected as system clock */

#define RCC_CFGR_SWS_Pos                (2)
#define RCC_CFGR_SWS_Msk                (0x03U << RCC_CFGR_SWS_Pos)         /*!< SWS[1:0] bits (System Clock Switch Status) */

#define RCC_CFGR_HPRE_Pos               (4)
#define RCC_CFGR_HPRE_Msk               (0x0FU << RCC_CFGR_HPRE_Pos)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_PPRE_0                 (0x01U << RCC_CFGR_HPRE_Pos)        /*!< Bit 0 */
#define RCC_CFGR_PPRE_1                 (0x02U << RCC_CFGR_HPRE_Pos)        /*!< Bit 1 */
#define RCC_CFGR_PPRE_2                 (0x04U << RCC_CFGR_HPRE_Pos)        /*!< Bit 2 */
#define RCC_CFGR_PPRE_3                 (0x08U << RCC_CFGR_HPRE_Pos)        /*!< Bit 3 */

#define RCC_CFGR_HPRE_DIV1              (0x00U << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2              (0x08U << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4              (0x09U << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8              (0x0AU << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16             (0x0BU << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64             (0x0CU << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128            (0x0DU << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256            (0x0EU << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512            (0x0FU << RCC_CFGR_HPRE_Pos)        /*!< AHB = FCLK = SYSCLK divided by 512 */

#define RCC_CFGR_PPRE1_Pos              (8)
#define RCC_CFGR_PPRE1_Msk              (0x07U << RCC_CFGR_PPRE1_Pos)       /*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0                (0x01U << RCC_CFGR_PPRE1_Pos)       /*!< Bit 0 */
#define RCC_CFGR_PPRE1_1                (0x02U << RCC_CFGR_PPRE1_Pos)       /*!< Bit 1 */
#define RCC_CFGR_PPRE1_2                (0x04U << RCC_CFGR_PPRE1_Pos)       /*!< Bit 2 */

#define RCC_CFGR_PPRE1_DIV1             (0x00U << RCC_CFGR_PPRE1_Pos)       /*!< APB1 = HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2             (0x04U << RCC_CFGR_PPRE1_Pos)       /*!< APB1 = HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4             (0x05U << RCC_CFGR_PPRE1_Pos)       /*!< APB1 = HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8             (0x06U << RCC_CFGR_PPRE1_Pos)       /*!< APB1 = HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16            (0x07U << RCC_CFGR_PPRE1_Pos)       /*!< APB1 = HCLK divided by 16 */

#define RCC_CFGR_MCO_Pos                (24)
#define RCC_CFGR_MCO_Msk                (0x0FU << RCC_CFGR_MCO_Pos)         /*!< MCO[2:0] bits (Microcontroller Clock Output) */


/**
  * @brief RCC_CIR Register Bit Definition
  */
#define RCC_CIR_LSIRDYF_Pos             (0)
#define RCC_CIR_LSIRDYF_Msk             (0x01U << RCC_CIR_LSIRDYF_Pos)      /*!< LSI Ready Interrupt flag */

#define RCC_CIR_HSIRDYF_Pos             (2)
#define RCC_CIR_HSIRDYF_Msk             (0x01U << RCC_CIR_HSIRDYF_Pos)      /*!< HSI Ready Interrupt flag */

#define RCC_CIR_PLLRDYF_Pos             (4)
#define RCC_CIR_PLLRDYF_Msk             (0x01U << RCC_CIR_PLLRDYF_Pos)      /*!< PLL Ready Interrupt flag */

#define RCC_CIR_LSIRDYIE_Pos            (8)
#define RCC_CIR_LSIRDYIE_Msk            (0x01U << RCC_CIR_LSIRDYIE_Pos)     /*!< LSI Ready Interrupt Enable */

#define RCC_CIR_HSIRDYIE_Pos            (10)
#define RCC_CIR_HSIRDYIE_Msk            (0x01U << RCC_CIR_HSIRDYIE_Pos)     /*!< HSI Ready Interrupt Enable */

#define RCC_CIR_PLLRDYIE_Pos            (12)
#define RCC_CIR_PLLRDYIE_Msk            (0x01U << RCC_CIR_PLLRDYIE_Pos)     /*!< PLL Ready Interrupt Enable */

#define RCC_CIR_LSIRDYC_Pos             (16)
#define RCC_CIR_LSIRDYC_Msk             (0x01U << RCC_CIR_LSIRDYC_Pos)      /*!< LSI Ready Interrupt Clear */

#define RCC_CIR_HSIRDYC_Pos             (18)
#define RCC_CIR_HSIRDYC_Msk             (0x01U << RCC_CIR_HSIRDYC_Pos)      /*!< HSI Ready Interrupt Clear */

#define RCC_CIR_PLLRDYC_Pos             (20)
#define RCC_CIR_PLLRDYC_Msk             (0x01U << RCC_CIR_PLLRDYC_Pos)      /*!< PLL Ready Interrupt Clear */


/**
  * @brief RCC_APB1RSTR Register Bit Definition
  */
#define RCC_APB1RSTR_TIM3_Pos           (1)
#define RCC_APB1RSTR_TIM3_Msk           (0x01U << RCC_APB1RSTR_TIM3_Pos)        /*!< Timer 3 reset */

#define RCC_APB1RSTR_TIM16_Pos          (4)
#define RCC_APB1RSTR_TIM16_Msk          (0x01U << RCC_APB1RSTR_TIM16_Pos)       /*!< Timer 16 reset */

#define RCC_APB1RSTR_TIM17_Pos          (5)
#define RCC_APB1RSTR_TIM17_Msk          (0x01U << RCC_APB1RSTR_TIM17_Pos)       /*!< Timer 17 reset */

#define RCC_APB1RSTR_ADC_Pos            (9)
#define RCC_APB1RSTR_ADC_Msk            (0x01U << RCC_APB1RSTR_ADC_Pos)         /*!< ADC reset */

#define RCC_APB1RSTR_WWDG_Pos           (11)
#define RCC_APB1RSTR_WWDG_Msk           (0x01U << RCC_APB1RSTR_WWDG_Pos)        /*!< Window Watchdog reset */

#define RCC_APB1RSTR_SPI_Pos            (12)
#define RCC_APB1RSTR_SPI_Msk            (0x01U << RCC_APB1RSTR_SPI_Pos)         /*!< SPI reset */

#define RCC_APB1RSTR_LPTIM_Pos          (14)
#define RCC_APB1RSTR_LPTIM_Msk          (0x01U << RCC_APB1RSTR_LPTIM_Pos)       /*!< LPTIM reset */

#define RCC_APB1RSTR_UART1_Pos          (16)
#define RCC_APB1RSTR_UART1_Msk          (0x01U << RCC_APB1RSTR_UART1_Pos)       /*!< UART 1 reset */

#define RCC_APB1RSTR_LPUART_Pos         (19)
#define RCC_APB1RSTR_LPUART_Msk         (0x01U << RCC_APB1RSTR_LPUART_Pos)      /*!< LPUART rese */


#define RCC_APB1RSTR_I2C_Pos            (21)
#define RCC_APB1RSTR_I2C_Msk            (0x01U << RCC_APB1RSTR_I2C_Pos)         /*!< I2C reset */

#define RCC_APB1RSTR_COMP_Pos           (23)
#define RCC_APB1RSTR_COMP_Msk           (0x01U << RCC_APB1RSTR_COMP_Pos)        /*!< COMP reset */

#define RCC_APB1RSTR_OPA1_Pos           (25)
#define RCC_APB1RSTR_OPA1_Msk           (0x01U << RCC_APB1RSTR_OPA1_Pos)        /*!< OPA 1 reset */

#define RCC_APB1RSTR_OPA2_Pos           (26)
#define RCC_APB1RSTR_OPA2_Msk           (0x01U << RCC_APB1RSTR_OPA2_Pos)        /*!< OPA 2 reset */

#define RCC_APB1RSTR_PWR_Pos            (28)
#define RCC_APB1RSTR_PWR_Msk            (0x01U << RCC_APB1RSTR_PWR_Pos)         /*!< Power interface reset */

#define RCC_APB1RSTR_DBG_Pos            (29)
#define RCC_APB1RSTR_DBG_Msk            (0x01U << RCC_APB1RSTR_DBG_Pos)         /*!< DBG reset */

#define RCC_APB1RSTR_SYSCFG_Pos         (30)
#define RCC_APB1RSTR_SYSCFG_Msk         (0x01U << RCC_APB1RSTR_SYSCFG_Pos)      /*!< SYSCFG reset */

/**
  * @brief RCC_AHBENR Register Bit Definition
  */
#define RCC_AHBENR_SRAM_Pos             (2)
#define RCC_AHBENR_SRAM_Msk             (0x01U << RCC_AHBENR_SRAM_Pos)          /*!< SRAM interface clock enable */
#define RCC_AHBENR_FLASH_Pos            (4)
#define RCC_AHBENR_FLASH_Msk            (0x01U << RCC_AHBENR_FLASH_Pos)         /*!< FLASH clock enable */
#define RCC_AHBENR_CRC_Pos              (6)
#define RCC_AHBENR_CRC_Msk              (0x01U << RCC_AHBENR_CRC_Pos)           /*!< CRC clock enable */

#define RCC_AHBENR_GPIOA_Pos            (17)
#define RCC_AHBENR_GPIOA_Msk            (0x01U << RCC_AHBENR_GPIOA_Pos)         /*!< GPIOA clock enable */
#define RCC_AHBENR_GPIOB_Pos            (18)
#define RCC_AHBENR_GPIOB_Msk            (0x01U << RCC_AHBENR_GPIOB_Pos)         /*!< GPIOB clock enable */


/**
  * @brief RCC_APB1ENR Register Bit Definition
  */

#define RCC_APB1ENR_TIM3_Pos            (1)
#define RCC_APB1ENR_TIM3_Msk            (0x01U << RCC_APB1ENR_TIM3_Pos)         /*!< Timer 3 clock enabled */

#define RCC_APB1ENR_TIM16_Pos           (4)
#define RCC_APB1ENR_TIM16_Msk           (0x01U << RCC_APB1ENR_TIM16_Pos)        /*!< Timer 16 clock enabled */
#define RCC_APB1ENR_TIM17_Pos           (5)
#define RCC_APB1ENR_TIM17_Msk           (0x01U << RCC_APB1ENR_TIM17_Pos)       /*!< Timer 17 clock enabled */

#define RCC_APB1ENR_IWDG_Pos            (6)
#define RCC_APB1ENR_IWDG_Msk            (0x01U << RCC_APB1ENR_IWDG_Pos)         /*!< IWDG clock enabled */

#define RCC_APB1ENR_EXTI_Pos            (7)
#define RCC_APB1ENR_EXTI_Msk            (0x01U << RCC_APB1ENR_EXTI_Pos)         /*!< EXTI clock enabled */

#define RCC_APB1ENR_ADC_Pos             (9)
#define RCC_APB1ENR_ADC_Msk             (0x01U << RCC_APB1ENR_ADC_Pos)          /*!< ADC clock enabled */


#define RCC_APB1ENR_WWDG_Pos            (11)
#define RCC_APB1ENR_WWDG_Msk            (0x01U << RCC_APB1ENR_WWDG_Pos)         /*!< Window Watchdog clock enable */
#define RCC_APB1ENR_SPI_Pos             (12)
#define RCC_APB1ENR_SPI_Msk             (0x01U << RCC_APB1ENR_SPI_Pos)          /*!< SPI enable */

#define RCC_APB1ENR_LPTIM_Pos           (14)
#define RCC_APB1ENR_LPTIM_Msk           (0x01U << RCC_APB1ENR_LPTIM_Pos)        /*!< LPTIM clock enable */

#define RCC_APB1ENR_UART1_Pos           (16)
#define RCC_APB1ENR_UART1_Msk           (0x01U << RCC_APB1ENR_UART1_Pos)        /*!< UART 1 clock enable */

#define RCC_APB1ENR_LPUART_Pos          (19)
#define RCC_APB1ENR_LPUART_Msk          (0x01U << RCC_APB1ENR_LPUART_Pos)       /*!< LPUART clock enable */

#define RCC_APB1ENR_I2C_Pos             (21)
#define RCC_APB1ENR_I2C_Msk             (0x01U << RCC_APB1ENR_I2C_Pos)          /*!< I2C clock enable */

#define RCC_APB1ENR_COMP_Pos            (23)
#define RCC_APB1ENR_COMP_Msk            (0x01U << RCC_APB1ENR_COMP_Pos)         /*!< COMP clock enable */

#define RCC_APB1ENR_OPA1_Pos            (25)
#define RCC_APB1ENR_OPA1_Msk            (0x01U << RCC_APB1ENR_OPA1_Pos)         /*!< Operational amplifier1 clock enable */

#define RCC_APB1ENR_OPA2_Pos            (26)
#define RCC_APB1ENR_OPA2_Msk            (0x01U << RCC_APB1ENR_OPA2_Pos)         /*!< Operational amplifier2 clock enable */

#define RCC_APB1ENR_PWR_Pos             (28)
#define RCC_APB1ENR_PWR_Msk             (0x01U << RCC_APB1ENR_PWR_Pos)          /*!< Power interface clock enable */

#define RCC_APB1ENR_DBG_Pos             (29)
#define RCC_APB1ENR_DBG_Msk             (0x01U << RCC_APB1ENR_DBG_Pos)          /*!< DBG clock enable */

#define RCC_APB1ENR_SYSCFG_Pos          (30)
#define RCC_APB1ENR_SYSCFG_Msk          (0x01U << RCC_APB1ENR_SYSCFG_Pos)       /*!< SYSCFG clock enable */


/**
  * @brief RCC_CSR Register Bit Definition
  */
#define RCC_CSR_LSION_Pos               (0)
#define RCC_CSR_LSION_Msk               (0x01U << RCC_CSR_LSION_Pos)            /*!< Internal Low Speed oscillator enable */
#define RCC_CSR_LSIRDY_Pos              (1)
#define RCC_CSR_LSIRDY_Msk              (0x01U << RCC_CSR_LSIRDY_Pos)           /*!< Internal Low Speed oscillator Ready */
#define RCC_CSR_LSIOE_Pos               (5)
#define RCC_CSR_LSIOE_Msk               (0x01U << RCC_CSR_LSIOE_Pos)            /*!< LSI Output Enable */
#define RCC_CSR_PVDRSTEN_Pos            (6)
#define RCC_CSR_PVDRSTEN_Msk            (0x01U << RCC_CSR_PVDRSTEN_Pos)         /*!< PVDRSTEN reset enable */
#define RCC_CSR_LOCKUPEN_Pos            (7)
#define RCC_CSR_LOCKUPEN_Msk            (0x01U << RCC_CSR_LOCKUPEN_Pos)         /*!< CPU Lockup Reset Enable */
#define RCC_CSR_PVDRSTF_Pos             (22)
#define RCC_CSR_PVDRSTF_Msk             (0x01U << RCC_CSR_PVDRSTF_Pos)          /*!< PVD reset flag */
#define RCC_CSR_LOCKUPF_Pos             (23)
#define RCC_CSR_LOCKUPF_Msk             (0x01U << RCC_CSR_LOCKUPF_Pos)          /*!< CPU lockup reset flag */

#define RCC_CSR_RMVF_Pos                (24)
#define RCC_CSR_RMVF_Msk                (0x01U << RCC_CSR_RMVF_Pos)             /*!< Remove reset flag */
#define RCC_CSR_PINRSTF_Pos             (26)
#define RCC_CSR_PINRSTF_Msk             (0x01U << RCC_CSR_PINRSTF_Pos)          /*!< PIN reset flag */

#define RCC_CSR_PORRSTF_Pos             (27)
#define RCC_CSR_PORRSTF_Msk             (0x01U << RCC_CSR_PORRSTF_Pos)          /*!< POR/PDR reset flag */

#define RCC_CSR_SFTRSTF_Pos             (28)
#define RCC_CSR_SFTRSTF_Msk             (0x01U << RCC_CSR_SFTRSTF_Pos)          /*!< Software Reset flag */

#define RCC_CSR_IWDGRSTF_Pos            (29)
#define RCC_CSR_IWDGRSTF_Msk            (0x01U << RCC_CSR_IWDGRSTF_Pos)         /*!< Independent Watchdog reset flag */

#define RCC_CSR_WWDGRSTF_Pos            (30)
#define RCC_CSR_WWDGRSTF_Msk            (0x01U << RCC_CSR_WWDGRSTF_Pos)         /*!< Window watchdog reset flag */
#define RCC_CSR_LPWRRSTF_Pos            (31)
#define RCC_CSR_LPWRRSTF_Msk            (0x01U << RCC_CSR_LPWRRSTF_Pos)         /*!< Low power reset flag */

/**
  * @brief RCC_AHBRSTR Register Bit Definition
  */
#define RCC_AHBRSTR_CRC_Pos             (6)
#define RCC_AHBRSTR_CRC_Msk             (0x01U << RCC_AHBRSTR_CRC_Pos)          /*!< CRC clock reset */
#define RCC_AHBRSTR_GPIOA_Pos           (17)
#define RCC_AHBRSTR_GPIOA_Msk           (0x01U << RCC_AHBRSTR_GPIOA_Pos)        /*!< GPIOA clock reset */
#define RCC_AHBRSTR_GPIOB_Pos           (18)
#define RCC_AHBRSTR_GPIOB_Msk           (0x01U << RCC_AHBRSTR_GPIOB_Pos)        /*!< GPIOB clock reset */

/**
  * @brief RCC_CFGR2 Register Bit Definition
  */
#define RCC_CFGR2_LPUARTCLKSEL_Pos     (0)
#define RCC_CFGR2_LPUARTCLKSEL_Msk     (0x03U << RCC_CFGR2_LPUARTCLKSEL_Pos)      /*!< LPUART clock source selection */
#define RCC_CFGR2_LPUARTCLKSEL_LSE     (0x00U << RCC_CFGR2_LPUARTCLKSEL_Pos)      /*!< LSE (default) */
#define RCC_CFGR2_LPUARTCLKSEL_LSI     (0x01U << RCC_CFGR2_LPUARTCLKSEL_Pos)      /*!< LSI */
#define RCC_CFGR2_LPUARTCLKSEL_PCLK    (0x02U << RCC_CFGR2_LPUARTCLKSEL_Pos)  /*!< PCLK_LPUART */
#define RCC_CFGR2_LPUARTCLKSEL_NONE    (0x03U << RCC_CFGR2_LPUARTCLKSEL_Pos)      /*!< No clock */

#define RCC_CFGR2_MCOPRE_Pos            (20)
#define RCC_CFGR2_MCOPRE_Msk            (0x0FU << RCC_CFGR2_MCOPRE_Pos)
#define RCC_CFGR2_MCOPRE_1              (0x00U << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 1   frequency division */
#define RCC_CFGR2_MCOPRE_2              (0x08U << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 2   frequency division */
#define RCC_CFGR2_MCOPRE_4              (0x09U << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 4   frequency division */
#define RCC_CFGR2_MCOPRE_8              (0x0AU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 8   frequency division */
#define RCC_CFGR2_MCOPRE_16             (0x0BU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 16  frequency division */
#define RCC_CFGR2_MCOPRE_64             (0x0CU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 64  frequency division */
#define RCC_CFGR2_MCOPRE_128            (0x0DU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 128 frequency division */
#define RCC_CFGR2_MCOPRE_256            (0x0EU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 256 frequency division */
#define RCC_CFGR2_MCOPRE_512            (0x0FU << RCC_CFGR2_MCOPRE_Pos)         /*!< MCO 512 frequency division */

#define RCC_CFGR2_LPTIMCLKSEL_Pos      (29)
#define RCC_CFGR2_LPTIMCLKSEL_Msk      (0x03U << RCC_CFGR2_LPTIMCLKSEL_Pos)      /*!< LPTIM clock source selection */
#define RCC_CFGR2_LPTIMCLKSEL_LSE      (0x00U << RCC_CFGR2_LPTIMCLKSEL_Pos)      /*!< LSE (default) */
#define RCC_CFGR2_LPTIMCLKSEL_LSI      (0x01U << RCC_CFGR2_LPTIMCLKSEL_Pos)      /*!< LSI */
#define RCC_CFGR2_LPTIMCLKSEL_PCLK_LPTIMER (0x02U << RCC_CFGR2_LPTIMCLKSEL_Pos)  /*!< PCLK_LPTIMER */
#define RCC_CFGR2_LPTIMCLKSEL_NONE     (0x03U << RCC_CFGR2_LPTIMCLKSEL_Pos)      /*!< No clock */

/**
  * @brief RCC_SYSCFG Register Bit Definition
  */
#define RCC_SYSCFG_PROGCHECKEN_Pos      (0)
#define RCC_SYSCFG_PROGCHECKEN_Msk      (0x01U << RCC_SYSCFG_PROGCHECKEN_Pos) /*!< Whether to check the number in Flash when writing to Flash */


/**
  * @brief RCC_PLLCFGR Register Bit Definition
  */
#define RCC_PLLCFGR_PLLSRC_Pos          (0)
#define RCC_PLLCFGR_PLLSRC_Msk          (0x01U << RCC_PLLCFGR_PLLSRC_Pos)       /*!< HSI as PLL entry clock */
#define RCC_PLLCFGR_PLL_ICTRL_Pos       (2)
#define RCC_PLLCFGR_PLL_ICTRL_Msk       (0x03U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals mask */
#define RCC_PLLCFGR_PLL_ICTRL_0         (0x00U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 2.5u */
#define RCC_PLLCFGR_PLL_ICTRL_1         (0x01U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 5u */
#define RCC_PLLCFGR_PLL_ICTRL_2         (0x02U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 7.5u */
#define RCC_PLLCFGR_PLL_ICTRL_3         (0x03U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 10u */
#define RCC_PLLCFGR_PLL_ICTRL_2_5       (0x00U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 2.5u */
#define RCC_PLLCFGR_PLL_ICTRL_5         (0x01U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 5u */
#define RCC_PLLCFGR_PLL_ICTRL_7_5       (0x02U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 7.5u */
#define RCC_PLLCFGR_PLL_ICTRL_10        (0x03U << RCC_PLLCFGR_PLL_ICTRL_Pos)    /*!< PLL CP current control signals 10u */
#define RCC_PLLCFGR_PLL_LDS_Pos         (4)
#define RCC_PLLCFGR_PLL_LDS_Msk         (0x03U << RCC_PLLCFGR_PLL_LDS_Pos)      /*!< PLL LOCK DETECTOR ACCURACY SELECT */
#define RCC_PLLCFGR_PLL_LDS_0           (0x00U << RCC_PLLCFGR_PLL_LDS_Pos)      /*!< PLL LOCK DETECTOR ACCURACY value = 0 */
#define RCC_PLLCFGR_PLL_LDS_1           (0x01U << RCC_PLLCFGR_PLL_LDS_Pos)      /*!< PLL LOCK DETECTOR ACCURACY value = 1 */
#define RCC_PLLCFGR_PLL_LDS_2           (0x02U << RCC_PLLCFGR_PLL_LDS_Pos)      /*!< PLL LOCK DETECTOR ACCURACY value = 2 */
#define RCC_PLLCFGR_PLL_LDS_3           (0x03U << RCC_PLLCFGR_PLL_LDS_Pos)      /*!< PLL LOCK DETECTOR ACCURACY value = 3 */
#define RCC_PLLCFGR_PLLDIV_Pos          (8)
#define RCC_PLLCFGR_PLLDIV_Msk          (0x07U << RCC_PLLCFGR_PLLDIV_Pos)       /*!< PLL Divide Factor */
#define RCC_PLLCFGR_PLLMUL_Pos          (16)
#define RCC_PLLCFGR_PLLMUL_Msk          (0xFFU << RCC_PLLCFGR_PLLMUL_Pos)       /*!< PLL Multiplication Factor */
#define RCC_PLLCFGR_PLLPDIV_Pos         (29)
#define RCC_PLLCFGR_PLLPDIV_Msk         (0x07U << RCC_PLLCFGR_PLLPDIV_Pos)      /*!< PLL Pre-divide Factor */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/** --------------------------------------------------------------------------*/
#endif
/** --------------------------------------------------------------------------*/

