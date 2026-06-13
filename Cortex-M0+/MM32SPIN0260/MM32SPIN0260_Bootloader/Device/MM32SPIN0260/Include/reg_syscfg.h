/***********************************************************************************************************************
    @file     reg_syscfg.h
    @author   FD TEAM
    @brief    This flie contains all the SYSCFG's register and its field definition.
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

#ifndef __REG_SYSCFG_H
#define __REG_SYSCFG_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief SYSCFG Base Address Definition
  */
#define  SYSCFG_BASE                               0x40010000                                       /*!<Base Address: 0x40010000*/

/**
  * @brief SYSCFG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFGR;                           /*!<SYSCFG SYSCFG configuration register 1         offset: 0x00       */
    __IO uint32_t RESERVED0x04[1];                /*!<                                               offset: 0x04       */
    __IO uint32_t EXTICR1;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x08
                                                      configuration register 1                                          */
    __IO uint32_t EXTICR2;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x0C
                                                      configuration register 2                                          */
    __IO uint32_t EXTICR3;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x10
                                                      configuration register 3                                          */
    __IO uint32_t EXTICR4;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x14
                                                      configuration register 4                                          */
    __IO uint32_t RESERVED0x18[1];                /*!<                                               offset: 0x18       */
    __IO uint32_t SENSORCR;                       /*!<SYSCFG SYSCFG internal sensor configuration    offset: 0x1C
                                                      register                                                          */
    __IO uint32_t SCCR;                           /*!<SYSCFG SYSCFG analog signal configuration      offset: 0x20
                                                      register                                                          */
} SYSCFG_TypeDef;

/**
  * @brief SYSCFG type pointer Definition
  */
#define SYSCFG                                    ((SYSCFG_TypeDef *)SYSCFG_BASE)

/**
  * @brief SYSCFG_CFGR Register Bit Definition
  */
#define  SYSCFG_CFGR_MEM_MODE_Pos                 (0)
#define  SYSCFG_CFGR_MEM_MODE_Msk                 (0x3U << SYSCFG_CFGR_MEM_MODE_Pos)                /*!<Memory selection Bit*/
#define  SYSCFG_CFGR_MEM_MODE                     SYSCFG_CFGR_MEM_MODE_Msk
#define  SYSCFG_CFGR_MEM_MODE_Bit0                (0x1U << SYSCFG_CFGR_MEM_MODE_Pos) 
#define  SYSCFG_CFGR_MEM_MODE_Bit1                (0x2U << SYSCFG_CFGR_MEM_MODE_Pos) 
#define  SYSCFG_CFGR_USART2_RX_DMA_RMP_Pos        (7)
#define  SYSCFG_CFGR_USART2_RX_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR_USART2_RX_DMA_RMP_Pos)       /*!<USART2 RX DMA RMP: USART1 RX(USART2 RX DMA request remapping bit )*/
#define  SYSCFG_CFGR_USART2_RX_DMA_RMP            SYSCFG_CFGR_USART2_RX_DMA_RMP_Msk
#define  SYSCFG_CFGR_ADC1_DMA_RMP_Pos             (8)
#define  SYSCFG_CFGR_ADC1_DMA_RMP_Msk             (0x1U << SYSCFG_CFGR_ADC1_DMA_RMP_Pos)            /*!<0: No remapping (ADC DMA request is mapped on DMA channel 1)*/
#define  SYSCFG_CFGR_ADC1_DMA_RMP                 SYSCFG_CFGR_ADC1_DMA_RMP_Msk
#define  SYSCFG_CFGR_USART1_TX_DMA_RMP_Pos        (9)
#define  SYSCFG_CFGR_USART1_TX_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR_USART1_TX_DMA_RMP_Pos)       /*!<0: No remapping (USART1_TX request is mapped on DMA channel 2)*/
#define  SYSCFG_CFGR_USART1_TX_DMA_RMP            SYSCFG_CFGR_USART1_TX_DMA_RMP_Msk
#define  SYSCFG_CFGR_USART1_RX_DMA_RMP_Pos        (10)
#define  SYSCFG_CFGR_USART1_RX_DMA_RMP_Msk        (0x1U << SYSCFG_CFGR_USART1_RX_DMA_RMP_Pos)       /*!<0: No remapping (USART1_ RX request is mapped on DMA channel 3)*/
#define  SYSCFG_CFGR_USART1_RX_DMA_RMP            SYSCFG_CFGR_USART1_RX_DMA_RMP_Msk
#define  SYSCFG_CFGR_TIM16_DMA_RMP_Pos            (11)
#define  SYSCFG_CFGR_TIM16_DMA_RMP_Msk            (0x1U << SYSCFG_CFGR_TIM16_DMA_RMP_Pos)           /*!<0: No remapping (TIM16 requests are mapped on DMA channel 3)*/
#define  SYSCFG_CFGR_TIM16_DMA_RMP                SYSCFG_CFGR_TIM16_DMA_RMP_Msk
#define  SYSCFG_CFGR_TIM17_DMA_RMP_Pos            (12)
#define  SYSCFG_CFGR_TIM17_DMA_RMP_Msk            (0x1U << SYSCFG_CFGR_TIM17_DMA_RMP_Pos)           /*!<0: No remapping (TIM17 requests are mapped on DMA channel 1)*/
#define  SYSCFG_CFGR_TIM17_DMA_RMP                SYSCFG_CFGR_TIM17_DMA_RMP_Msk
#define  SYSCFG_CFGR_IRQLATENCY_Pos               (16)
#define  SYSCFG_CFGR_IRQLATENCY_Msk               (0xFFU << SYSCFG_CFGR_IRQLATENCY_Pos)             /*!<Interrupt Latency?*/
#define  SYSCFG_CFGR_IRQLATENCY                   SYSCFG_CFGR_IRQLATENCY_Msk
#define  SYSCFG_CFGR_IRQLATENCY_Bit0              (0x01U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit1              (0x02U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit2              (0x04U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit3              (0x08U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit4              (0x10U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit5              (0x20U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit6              (0x40U << SYSCFG_CFGR_IRQLATENCY_Pos) 
#define  SYSCFG_CFGR_IRQLATENCY_Bit7              (0x80U << SYSCFG_CFGR_IRQLATENCY_Pos) 

/**
  * @brief SYSCFG_EXTICR1 Register Bit Definition
  */
#define  SYSCFG_EXTICR1_EXTI0_Pos                 (0)
#define  SYSCFG_EXTICR1_EXTI0_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI0_Pos)                /*!<EXTIx configuration(x=0)*/
#define  SYSCFG_EXTICR1_EXTI0                     SYSCFG_EXTICR1_EXTI0_Msk
#define  SYSCFG_EXTICR1_EXTI0_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI0_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI0_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI0_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Pos                 (4)
#define  SYSCFG_EXTICR1_EXTI1_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI1_Pos)                /*!<EXTIx configuration(x=1)*/
#define  SYSCFG_EXTICR1_EXTI1                     SYSCFG_EXTICR1_EXTI1_Msk
#define  SYSCFG_EXTICR1_EXTI1_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Pos                 (8)
#define  SYSCFG_EXTICR1_EXTI2_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI2_Pos)                /*!<EXTIx configuration(x=2)*/
#define  SYSCFG_EXTICR1_EXTI2                     SYSCFG_EXTICR1_EXTI2_Msk
#define  SYSCFG_EXTICR1_EXTI2_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Pos                 (12)
#define  SYSCFG_EXTICR1_EXTI3_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI3_Pos)                /*!<EXTIx configuration(x=3)*/
#define  SYSCFG_EXTICR1_EXTI3                     SYSCFG_EXTICR1_EXTI3_Msk
#define  SYSCFG_EXTICR1_EXTI3_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI3_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI3_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI3_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI3_Pos) 

/**
  * @brief SYSCFG_EXTICR2 Register Bit Definition
  */
#define  SYSCFG_EXTICR2_EXTI4_Pos                 (0)
#define  SYSCFG_EXTICR2_EXTI4_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI4_Pos)                /*!<EXTIx configuration(x=4)*/
#define  SYSCFG_EXTICR2_EXTI4                     SYSCFG_EXTICR2_EXTI4_Msk
#define  SYSCFG_EXTICR2_EXTI4_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI4_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI4_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI4_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Pos                 (4)
#define  SYSCFG_EXTICR2_EXTI5_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI5_Pos)                /*!<EXTIx configuration(x=5)*/
#define  SYSCFG_EXTICR2_EXTI5                     SYSCFG_EXTICR2_EXTI5_Msk
#define  SYSCFG_EXTICR2_EXTI5_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Pos                 (8)
#define  SYSCFG_EXTICR2_EXTI6_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI6_Pos)                /*!<EXTIx configuration(x=6)*/
#define  SYSCFG_EXTICR2_EXTI6                     SYSCFG_EXTICR2_EXTI6_Msk
#define  SYSCFG_EXTICR2_EXTI6_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Pos                 (12)
#define  SYSCFG_EXTICR2_EXTI7_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI7_Pos)                /*!<EXTIx configuration(x=7)*/
#define  SYSCFG_EXTICR2_EXTI7                     SYSCFG_EXTICR2_EXTI7_Msk
#define  SYSCFG_EXTICR2_EXTI7_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI7_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI7_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI7_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI7_Pos) 

/**
  * @brief SYSCFG_EXTICR3 Register Bit Definition
  */
#define  SYSCFG_EXTICR3_EXTI8_Pos                 (0)
#define  SYSCFG_EXTICR3_EXTI8_Msk                 (0xFU << SYSCFG_EXTICR3_EXTI8_Pos)                /*!<EXTIx configuration(x=8)*/
#define  SYSCFG_EXTICR3_EXTI8                     SYSCFG_EXTICR3_EXTI8_Msk
#define  SYSCFG_EXTICR3_EXTI8_Bit0                (0x1U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI8_Bit1                (0x2U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI8_Bit2                (0x4U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI8_Bit3                (0x8U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Pos                 (4)
#define  SYSCFG_EXTICR3_EXTI9_Msk                 (0xFU << SYSCFG_EXTICR3_EXTI9_Pos)                /*!<EXTIx configuration(x=9)*/
#define  SYSCFG_EXTICR3_EXTI9                     SYSCFG_EXTICR3_EXTI9_Msk
#define  SYSCFG_EXTICR3_EXTI9_Bit0                (0x1U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Bit1                (0x2U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Bit2                (0x4U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Bit3                (0x8U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Pos                (8)
#define  SYSCFG_EXTICR3_EXTI10_Msk                (0xFU << SYSCFG_EXTICR3_EXTI10_Pos)               /*!<EXTIx configuration(x=10)*/
#define  SYSCFG_EXTICR3_EXTI10                    SYSCFG_EXTICR3_EXTI10_Msk
#define  SYSCFG_EXTICR3_EXTI10_Bit0               (0x1U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Bit1               (0x2U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Bit2               (0x4U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Bit3               (0x8U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Pos                (12)
#define  SYSCFG_EXTICR3_EXTI11_Msk                (0xFU << SYSCFG_EXTICR3_EXTI11_Pos)               /*!<EXTIx configuration(x=11)*/
#define  SYSCFG_EXTICR3_EXTI11                    SYSCFG_EXTICR3_EXTI11_Msk
#define  SYSCFG_EXTICR3_EXTI11_Bit0               (0x1U << SYSCFG_EXTICR3_EXTI11_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Bit1               (0x2U << SYSCFG_EXTICR3_EXTI11_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Bit2               (0x4U << SYSCFG_EXTICR3_EXTI11_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Bit3               (0x8U << SYSCFG_EXTICR3_EXTI11_Pos) 

/**
  * @brief SYSCFG_EXTICR4 Register Bit Definition
  */
#define  SYSCFG_EXTICR4_EXTI12_Pos                (0)
#define  SYSCFG_EXTICR4_EXTI12_Msk                (0xFU << SYSCFG_EXTICR4_EXTI12_Pos)               /*!<EXTIx configuration(x=12)*/
#define  SYSCFG_EXTICR4_EXTI12                    SYSCFG_EXTICR4_EXTI12_Msk
#define  SYSCFG_EXTICR4_EXTI12_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI12_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI12_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI12_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Pos                (4)
#define  SYSCFG_EXTICR4_EXTI13_Msk                (0xFU << SYSCFG_EXTICR4_EXTI13_Pos)               /*!<EXTIx configuration(x=13)*/
#define  SYSCFG_EXTICR4_EXTI13                    SYSCFG_EXTICR4_EXTI13_Msk
#define  SYSCFG_EXTICR4_EXTI13_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Pos                (8)
#define  SYSCFG_EXTICR4_EXTI14_Msk                (0xFU << SYSCFG_EXTICR4_EXTI14_Pos)               /*!<EXTIx configuration(x=14)*/
#define  SYSCFG_EXTICR4_EXTI14                    SYSCFG_EXTICR4_EXTI14_Msk
#define  SYSCFG_EXTICR4_EXTI14_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Pos                (12)
#define  SYSCFG_EXTICR4_EXTI15_Msk                (0xFU << SYSCFG_EXTICR4_EXTI15_Pos)               /*!<EXTIx configuration(x=15)*/
#define  SYSCFG_EXTICR4_EXTI15                    SYSCFG_EXTICR4_EXTI15_Msk
#define  SYSCFG_EXTICR4_EXTI15_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI15_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI15_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI15_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI15_Pos) 

/**
  * @brief SYSCFG_SENSORCR Register Bit Definition
  */
#define  SYSCFG_SENSORCR_VS_EN_Pos                (0)
#define  SYSCFG_SENSORCR_VS_EN_Msk                (0x1U << SYSCFG_SENSORCR_VS_EN_Pos)               /*!<Voltage sensor enable*/
#define  SYSCFG_SENSORCR_VS_EN                    SYSCFG_SENSORCR_VS_EN_Msk
#define  SYSCFG_SENSORCR_TS_EN_Pos                (1)
#define  SYSCFG_SENSORCR_TS_EN_Msk                (0x1U << SYSCFG_SENSORCR_TS_EN_Pos)               /*!<Temperature sensor enable*/
#define  SYSCFG_SENSORCR_TS_EN                    SYSCFG_SENSORCR_TS_EN_Msk

/**
  * @brief SYSCFG_SCCR Register Bit Definition
  */
#define  SYSCFG_SCCR_SCVREF_EN_Pos                (0)
#define  SYSCFG_SCCR_SCVREF_EN_Msk                (0x1U << SYSCFG_SCCR_SCVREF_EN_Pos)               /*!<Enable SCVREF*/
#define  SYSCFG_SCCR_SCVREF_EN                    SYSCFG_SCCR_SCVREF_EN_Msk
#define  SYSCFG_SCCR_SCVREF_SEL_Pos               (1)
#define  SYSCFG_SCCR_SCVREF_SEL_Msk               (0x3U << SYSCFG_SCCR_SCVREF_SEL_Pos)              /*!<Select SCVREF output*/
#define  SYSCFG_SCCR_SCVREF_SEL                   SYSCFG_SCCR_SCVREF_SEL_Msk
#define  SYSCFG_SCCR_SCVREF_SEL_Bit0              (0x1U << SYSCFG_SCCR_SCVREF_SEL_Pos) 
#define  SYSCFG_SCCR_SCVREF_SEL_Bit1              (0x2U << SYSCFG_SCCR_SCVREF_SEL_Pos) 
#define  SYSCFG_SCCR_OPAHBBUF_EN_Pos              (4)
#define  SYSCFG_SCCR_OPAHBBUF_EN_Msk              (0x1U << SYSCFG_SCCR_OPAHBBUF_EN_Pos)             /*!<Enable the output of a 1/2 divided voltage from the SCVERF*/
#define  SYSCFG_SCCR_OPAHBBUF_EN                  SYSCFG_SCCR_OPAHBBUF_EN_Msk
#define  SYSCFG_SCCR_OPAQBUG_EN_Pos               (5)
#define  SYSCFG_SCCR_OPAQBUG_EN_Msk               (0x1U << SYSCFG_SCCR_OPAQBUG_EN_Pos)              /*!<Enable the output of a 1/4 divided voltage from the SCVERF*/
#define  SYSCFG_SCCR_OPAQBUG_EN                   SYSCFG_SCCR_OPAQBUG_EN_Msk
#define  SYSCFG_SCCR_MCP_EN_Pos                   (8)
#define  SYSCFG_SCCR_MCP_EN_Msk                   (0x1U << SYSCFG_SCCR_MCP_EN_Pos)                  /*!<Mid-Point voltage output enable Enable the output of midpoint voltage on PA0, PA1, PA2, which can serve as the inverting input for COMP2*/
#define  SYSCFG_SCCR_MCP_EN                       SYSCFG_SCCR_MCP_EN_Msk


#endif

