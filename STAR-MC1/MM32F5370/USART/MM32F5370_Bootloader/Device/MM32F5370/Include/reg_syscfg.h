/***********************************************************************************************************************
    @file     reg_syscfg.h
    @author   VV TEAM
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
#include "core_starmc1.h"



/**
  * @brief SYSCFG Base Address Definition
  */
#define  SYSCFG_BASE                               0x40010000                                       /*!<Base Address: 0x40010000*/

/**
  * @brief SYSCFG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFGR1;                          /*!<SYSCFG SYSCFG configuration register 1         offset: 0x00       */
    __IO uint32_t FLEXCAN;                        /*!<                                               offset: 0x04       */
    __IO uint32_t EXTICR1;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x08
                                                      configuration register 1                                          */
    __IO uint32_t EXTICR2;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x0C
                                                      configuration register 2                                          */
    __IO uint32_t EXTICR3;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x10
                                                      configuration register 3                                          */
    __IO uint32_t EXTICR4;                        /*!<SYSCFG SYSCFG external interrupt               offset: 0x14
                                                      configuration register 4                                          */
    __IO uint32_t CFGR2;                          /*!<SYSCFG SYSCFG configuration register 2         offset: 0x18       */
    __IO uint32_t PDETCSR;                        /*!<                                               offset: 0x1C       */
    __IO uint32_t VOSDLY;                         /*!<                                               offset: 0x20       */
    __IO uint32_t DMARMP;                         /*!<                                               offset: 0x24       */
    __IO uint32_t BUS_PRI;                        /*!<                                               offset: 0x28       */
    __IO uint32_t RESERVED0x2C[1];                /*!<                                               offset: 0x2C       */
    __IO uint32_t LP_CFGR1;                       /*!<                                               offset: 0x30       */
    __IO uint32_t RESERVED0x34[19];               /*!<                                               offset: 0x34~0x7C  */
    __IO uint32_t TEST;                           /*!<                                               offset: 0x80       */
} SYSCFG_TypeDef;

/**
  * @brief SYSCFG type pointer Definition
  */
#define SYSCFG                                    ((SYSCFG_TypeDef *)SYSCFG_BASE)

/**
  * @brief SYSCFG_CFGR1 Register Bit Definition
  */
#define  SYSCFG_CFGR1_CAN1_SPV_Pos                (16)
#define  SYSCFG_CFGR1_CAN1_SPV_Msk                (0x1U << SYSCFG_CFGR1_CAN1_SPV_Pos)               /*!<*/
#define  SYSCFG_CFGR1_CAN1_SPV                    SYSCFG_CFGR1_CAN1_SPV_Msk
#define  SYSCFG_CFGR1_CAN1_TEST_Pos               (17)
#define  SYSCFG_CFGR1_CAN1_TEST_Msk               (0x1U << SYSCFG_CFGR1_CAN1_TEST_Pos)              /*!<*/
#define  SYSCFG_CFGR1_CAN1_TEST                   SYSCFG_CFGR1_CAN1_TEST_Msk
#define  SYSCFG_CFGR1_CAN1_STOP_Pos               (18)
#define  SYSCFG_CFGR1_CAN1_STOP_Msk               (0x1U << SYSCFG_CFGR1_CAN1_STOP_Pos)              /*!<*/
#define  SYSCFG_CFGR1_CAN1_STOP                   SYSCFG_CFGR1_CAN1_STOP_Msk
#define  SYSCFG_CFGR1_CAN2_SPV_Pos                (19)
#define  SYSCFG_CFGR1_CAN2_SPV_Msk                (0x1U << SYSCFG_CFGR1_CAN2_SPV_Pos)               /*!<*/
#define  SYSCFG_CFGR1_CAN2_SPV                    SYSCFG_CFGR1_CAN2_SPV_Msk
#define  SYSCFG_CFGR1_CAN2_TEST_Pos               (20)
#define  SYSCFG_CFGR1_CAN2_TEST_Msk               (0x1U << SYSCFG_CFGR1_CAN2_TEST_Pos)              /*!<*/
#define  SYSCFG_CFGR1_CAN2_TEST                   SYSCFG_CFGR1_CAN2_TEST_Msk
#define  SYSCFG_CFGR1_CAN2_STOP_Pos               (21)
#define  SYSCFG_CFGR1_CAN2_STOP_Msk               (0x1U << SYSCFG_CFGR1_CAN2_STOP_Pos)              /*!<*/
#define  SYSCFG_CFGR1_CAN2_STOP                   SYSCFG_CFGR1_CAN2_STOP_Msk

/**
  * @brief SYSCFG_FLEXCAN Register Bit Definition
  */
#define  SYSCFG_FLEXCAN_FLEXCAN1_DMAEN_Pos        (0)
#define  SYSCFG_FLEXCAN_FLEXCAN1_DMAEN_Msk        (0x1U << SYSCFG_FLEXCAN_FLEXCAN1_DMAEN_Pos)       /*!<*/
#define  SYSCFG_FLEXCAN_FLEXCAN1_DMAEN            SYSCFG_FLEXCAN_FLEXCAN1_DMAEN_Msk
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos       (1)
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Msk       (0x1FU << SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos)     /*!<*/
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM           SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Msk
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Bit0      (0x01U << SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Bit1      (0x02U << SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Bit2      (0x04U << SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Bit3      (0x08U << SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Bit4      (0x10U << SYSCFG_FLEXCAN_DMA1_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_FLEXCAN2_DMAEN_Pos        (8)
#define  SYSCFG_FLEXCAN_FLEXCAN2_DMAEN_Msk        (0x1U << SYSCFG_FLEXCAN_FLEXCAN2_DMAEN_Pos)       /*!<*/
#define  SYSCFG_FLEXCAN_FLEXCAN2_DMAEN            SYSCFG_FLEXCAN_FLEXCAN2_DMAEN_Msk
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos       (9)
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Msk       (0x1FU << SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos)     /*!<*/
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM           SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Msk
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Bit0      (0x01U << SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Bit1      (0x02U << SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Bit2      (0x04U << SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Bit3      (0x08U << SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos) 
#define  SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Bit4      (0x10U << SYSCFG_FLEXCAN_DMA2_REQEXT_NUM_Pos) 

/**
  * @brief SYSCFG_EXTICR1 Register Bit Definition
  */
#define  SYSCFG_EXTICR1_EXTI0_Pos                 (0)
#define  SYSCFG_EXTICR1_EXTI0_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI0_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR1_EXTI0                     SYSCFG_EXTICR1_EXTI0_Msk
#define  SYSCFG_EXTICR1_EXTI0_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI0_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI0_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI0_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI0_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Pos                 (4)
#define  SYSCFG_EXTICR1_EXTI1_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI1_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR1_EXTI1                     SYSCFG_EXTICR1_EXTI1_Msk
#define  SYSCFG_EXTICR1_EXTI1_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI1_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI1_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Pos                 (8)
#define  SYSCFG_EXTICR1_EXTI2_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI2_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR1_EXTI2                     SYSCFG_EXTICR1_EXTI2_Msk
#define  SYSCFG_EXTICR1_EXTI2_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI2_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI2_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Pos                 (12)
#define  SYSCFG_EXTICR1_EXTI3_Msk                 (0xFU << SYSCFG_EXTICR1_EXTI3_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR1_EXTI3                     SYSCFG_EXTICR1_EXTI3_Msk
#define  SYSCFG_EXTICR1_EXTI3_Bit0                (0x1U << SYSCFG_EXTICR1_EXTI3_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Bit1                (0x2U << SYSCFG_EXTICR1_EXTI3_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Bit2                (0x4U << SYSCFG_EXTICR1_EXTI3_Pos) 
#define  SYSCFG_EXTICR1_EXTI3_Bit3                (0x8U << SYSCFG_EXTICR1_EXTI3_Pos) 

/**
  * @brief SYSCFG_EXTICR2 Register Bit Definition
  */
#define  SYSCFG_EXTICR2_EXTI4_Pos                 (0)
#define  SYSCFG_EXTICR2_EXTI4_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI4_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR2_EXTI4                     SYSCFG_EXTICR2_EXTI4_Msk
#define  SYSCFG_EXTICR2_EXTI4_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI4_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI4_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI4_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI4_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Pos                 (4)
#define  SYSCFG_EXTICR2_EXTI5_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI5_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR2_EXTI5                     SYSCFG_EXTICR2_EXTI5_Msk
#define  SYSCFG_EXTICR2_EXTI5_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI5_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI5_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Pos                 (8)
#define  SYSCFG_EXTICR2_EXTI6_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI6_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR2_EXTI6                     SYSCFG_EXTICR2_EXTI6_Msk
#define  SYSCFG_EXTICR2_EXTI6_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI6_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI6_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Pos                 (12)
#define  SYSCFG_EXTICR2_EXTI7_Msk                 (0xFU << SYSCFG_EXTICR2_EXTI7_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR2_EXTI7                     SYSCFG_EXTICR2_EXTI7_Msk
#define  SYSCFG_EXTICR2_EXTI7_Bit0                (0x1U << SYSCFG_EXTICR2_EXTI7_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Bit1                (0x2U << SYSCFG_EXTICR2_EXTI7_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Bit2                (0x4U << SYSCFG_EXTICR2_EXTI7_Pos) 
#define  SYSCFG_EXTICR2_EXTI7_Bit3                (0x8U << SYSCFG_EXTICR2_EXTI7_Pos) 

/**
  * @brief SYSCFG_EXTICR3 Register Bit Definition
  */
#define  SYSCFG_EXTICR3_EXTI8_Pos                 (0)
#define  SYSCFG_EXTICR3_EXTI8_Msk                 (0xFU << SYSCFG_EXTICR3_EXTI8_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR3_EXTI8                     SYSCFG_EXTICR3_EXTI8_Msk
#define  SYSCFG_EXTICR3_EXTI8_Bit0                (0x1U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI8_Bit1                (0x2U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI8_Bit2                (0x4U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI8_Bit3                (0x8U << SYSCFG_EXTICR3_EXTI8_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Pos                 (4)
#define  SYSCFG_EXTICR3_EXTI9_Msk                 (0xFU << SYSCFG_EXTICR3_EXTI9_Pos)                /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR3_EXTI9                     SYSCFG_EXTICR3_EXTI9_Msk
#define  SYSCFG_EXTICR3_EXTI9_Bit0                (0x1U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Bit1                (0x2U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Bit2                (0x4U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI9_Bit3                (0x8U << SYSCFG_EXTICR3_EXTI9_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Pos                (8)
#define  SYSCFG_EXTICR3_EXTI10_Msk                (0xFU << SYSCFG_EXTICR3_EXTI10_Pos)               /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR3_EXTI10                    SYSCFG_EXTICR3_EXTI10_Msk
#define  SYSCFG_EXTICR3_EXTI10_Bit0               (0x1U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Bit1               (0x2U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Bit2               (0x4U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI10_Bit3               (0x8U << SYSCFG_EXTICR3_EXTI10_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Pos                (12)
#define  SYSCFG_EXTICR3_EXTI11_Msk                (0xFU << SYSCFG_EXTICR3_EXTI11_Pos)               /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR3_EXTI11                    SYSCFG_EXTICR3_EXTI11_Msk
#define  SYSCFG_EXTICR3_EXTI11_Bit0               (0x1U << SYSCFG_EXTICR3_EXTI11_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Bit1               (0x2U << SYSCFG_EXTICR3_EXTI11_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Bit2               (0x4U << SYSCFG_EXTICR3_EXTI11_Pos) 
#define  SYSCFG_EXTICR3_EXTI11_Bit3               (0x8U << SYSCFG_EXTICR3_EXTI11_Pos) 

/**
  * @brief SYSCFG_EXTICR4 Register Bit Definition
  */
#define  SYSCFG_EXTICR4_EXTI12_Pos                (0)
#define  SYSCFG_EXTICR4_EXTI12_Msk                (0xFU << SYSCFG_EXTICR4_EXTI12_Pos)               /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR4_EXTI12                    SYSCFG_EXTICR4_EXTI12_Msk
#define  SYSCFG_EXTICR4_EXTI12_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI12_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI12_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI12_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI12_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Pos                (4)
#define  SYSCFG_EXTICR4_EXTI13_Msk                (0xFU << SYSCFG_EXTICR4_EXTI13_Pos)               /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR4_EXTI13                    SYSCFG_EXTICR4_EXTI13_Msk
#define  SYSCFG_EXTICR4_EXTI13_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI13_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI13_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Pos                (8)
#define  SYSCFG_EXTICR4_EXTI14_Msk                (0xFU << SYSCFG_EXTICR4_EXTI14_Pos)               /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR4_EXTI14                    SYSCFG_EXTICR4_EXTI14_Msk
#define  SYSCFG_EXTICR4_EXTI14_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI14_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI14_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Pos                (12)
#define  SYSCFG_EXTICR4_EXTI15_Msk                (0xFU << SYSCFG_EXTICR4_EXTI15_Pos)               /*!<EXTIx configuration Select the input source of EXTIx external interrupt.*/
#define  SYSCFG_EXTICR4_EXTI15                    SYSCFG_EXTICR4_EXTI15_Msk
#define  SYSCFG_EXTICR4_EXTI15_Bit0               (0x1U << SYSCFG_EXTICR4_EXTI15_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Bit1               (0x2U << SYSCFG_EXTICR4_EXTI15_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Bit2               (0x4U << SYSCFG_EXTICR4_EXTI15_Pos) 
#define  SYSCFG_EXTICR4_EXTI15_Bit3               (0x8U << SYSCFG_EXTICR4_EXTI15_Pos) 

/**
  * @brief SYSCFG_CFGR2 Register Bit Definition
  */
#define  SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Pos        (0)
#define  SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Msk        (0x1U << SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Pos)       /*!<*/
#define  SYSCFG_CFGR2_QSPI_AUTOIDLE_EN            SYSCFG_CFGR2_QSPI_AUTOIDLE_EN_Msk
#define  SYSCFG_CFGR2_I2C1_MODE_SEL_Pos           (16)
#define  SYSCFG_CFGR2_I2C1_MODE_SEL_Msk           (0x1U << SYSCFG_CFGR2_I2C1_MODE_SEL_Pos)          /*!<*/
#define  SYSCFG_CFGR2_I2C1_MODE_SEL               SYSCFG_CFGR2_I2C1_MODE_SEL_Msk
#define  SYSCFG_CFGR2_I2C2_MODE_SEL_Pos           (17)
#define  SYSCFG_CFGR2_I2C2_MODE_SEL_Msk           (0x1U << SYSCFG_CFGR2_I2C2_MODE_SEL_Pos)          /*!<*/
#define  SYSCFG_CFGR2_I2C2_MODE_SEL               SYSCFG_CFGR2_I2C2_MODE_SEL_Msk
#define  SYSCFG_CFGR2_PB10FMP_Pos                 (24)
#define  SYSCFG_CFGR2_PB10FMP_Msk                 (0x1U << SYSCFG_CFGR2_PB10FMP_Pos)                /*!<*/
#define  SYSCFG_CFGR2_PB10FMP                     SYSCFG_CFGR2_PB10FMP_Msk
#define  SYSCFG_CFGR2_PB11FMP_Pos                 (25)
#define  SYSCFG_CFGR2_PB11FMP_Msk                 (0x1U << SYSCFG_CFGR2_PB11FMP_Pos)                /*!<*/
#define  SYSCFG_CFGR2_PB11FMP                     SYSCFG_CFGR2_PB11FMP_Msk

/**
  * @brief SYSCFG_PDETCSR Register Bit Definition
  */
#define  SYSCFG_PDETCSR_PVDE_Pos                  (0)
#define  SYSCFG_PDETCSR_PVDE_Msk                  (0x1U << SYSCFG_PDETCSR_PVDE_Pos)                 /*!<*/
#define  SYSCFG_PDETCSR_PVDE                      SYSCFG_PDETCSR_PVDE_Msk
#define  SYSCFG_PDETCSR_PLS_Pos                   (1)
#define  SYSCFG_PDETCSR_PLS_Msk                   (0xFU << SYSCFG_PDETCSR_PLS_Pos)                  /*!<*/
#define  SYSCFG_PDETCSR_PLS                       SYSCFG_PDETCSR_PLS_Msk
#define  SYSCFG_PDETCSR_PLS_Bit0                  (0x1U << SYSCFG_PDETCSR_PLS_Pos) 
#define  SYSCFG_PDETCSR_PLS_Bit1                  (0x2U << SYSCFG_PDETCSR_PLS_Pos) 
#define  SYSCFG_PDETCSR_PLS_Bit2                  (0x4U << SYSCFG_PDETCSR_PLS_Pos) 
#define  SYSCFG_PDETCSR_PLS_Bit3                  (0x8U << SYSCFG_PDETCSR_PLS_Pos) 
#define  SYSCFG_PDETCSR_PVDO_Pos                  (5)
#define  SYSCFG_PDETCSR_PVDO_Msk                  (0x1U << SYSCFG_PDETCSR_PVDO_Pos)                 /*!<*/
#define  SYSCFG_PDETCSR_PVDO                      SYSCFG_PDETCSR_PVDO_Msk
#define  SYSCFG_PDETCSR_VBAT_DIV3_EN_Pos          (11)
#define  SYSCFG_PDETCSR_VBAT_DIV3_EN_Msk          (0x1U << SYSCFG_PDETCSR_VBAT_DIV3_EN_Pos)         /*!<*/
#define  SYSCFG_PDETCSR_VBAT_DIV3_EN              SYSCFG_PDETCSR_VBAT_DIV3_EN_Msk

/**
  * @brief SYSCFG_VOSDLY Register Bit Definition
  */
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Pos             (0)
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Msk             (0x3FFU << SYSCFG_VOSDLY_VOSDLY_CNT_Pos)          /*!<*/
#define  SYSCFG_VOSDLY_VOSDLY_CNT                 SYSCFG_VOSDLY_VOSDLY_CNT_Msk
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit0            (0x001U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit1            (0x002U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit2            (0x004U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit3            (0x008U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit4            (0x010U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit5            (0x020U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit6            (0x040U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit7            (0x080U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit8            (0x100U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 
#define  SYSCFG_VOSDLY_VOSDLY_CNT_Bit9            (0x200U << SYSCFG_VOSDLY_VOSDLY_CNT_Pos) 

/**
  * @brief SYSCFG_DMARMP Register Bit Definition
  */
#define  SYSCFG_DMARMP_TIM1_TRIG_RMP_Pos          (0)
#define  SYSCFG_DMARMP_TIM1_TRIG_RMP_Msk          (0x1U << SYSCFG_DMARMP_TIM1_TRIG_RMP_Pos)         /*!<*/
#define  SYSCFG_DMARMP_TIM1_TRIG_RMP              SYSCFG_DMARMP_TIM1_TRIG_RMP_Msk
#define  SYSCFG_DMARMP_TIM1_COM_RMP_Pos           (1)
#define  SYSCFG_DMARMP_TIM1_COM_RMP_Msk           (0x1U << SYSCFG_DMARMP_TIM1_COM_RMP_Pos)          /*!<*/
#define  SYSCFG_DMARMP_TIM1_COM_RMP               SYSCFG_DMARMP_TIM1_COM_RMP_Msk
#define  SYSCFG_DMARMP_TIM2_UP_RMP_Pos            (2)
#define  SYSCFG_DMARMP_TIM2_UP_RMP_Msk            (0x3U << SYSCFG_DMARMP_TIM2_UP_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_TIM2_UP_RMP                SYSCFG_DMARMP_TIM2_UP_RMP_Msk
#define  SYSCFG_DMARMP_TIM2_UP_RMP_Bit0           (0x1U << SYSCFG_DMARMP_TIM2_UP_RMP_Pos) 
#define  SYSCFG_DMARMP_TIM2_UP_RMP_Bit1           (0x2U << SYSCFG_DMARMP_TIM2_UP_RMP_Pos) 
#define  SYSCFG_DMARMP_TIM2_CC3_RMP_Pos           (4)
#define  SYSCFG_DMARMP_TIM2_CC3_RMP_Msk           (0x1U << SYSCFG_DMARMP_TIM2_CC3_RMP_Pos)          /*!<*/
#define  SYSCFG_DMARMP_TIM2_CC3_RMP               SYSCFG_DMARMP_TIM2_CC3_RMP_Msk
#define  SYSCFG_DMARMP_TIM2_CC4_RMP_Pos           (5)
#define  SYSCFG_DMARMP_TIM2_CC4_RMP_Msk           (0x1U << SYSCFG_DMARMP_TIM2_CC4_RMP_Pos)          /*!<*/
#define  SYSCFG_DMARMP_TIM2_CC4_RMP               SYSCFG_DMARMP_TIM2_CC4_RMP_Msk
#define  SYSCFG_DMARMP_TIM5_UP_RMP_Pos            (8)
#define  SYSCFG_DMARMP_TIM5_UP_RMP_Msk            (0x1U << SYSCFG_DMARMP_TIM5_UP_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_TIM5_UP_RMP                SYSCFG_DMARMP_TIM5_UP_RMP_Msk
#define  SYSCFG_DMARMP_TIM6_UP_RMP_Pos            (10)
#define  SYSCFG_DMARMP_TIM6_UP_RMP_Msk            (0x1U << SYSCFG_DMARMP_TIM6_UP_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_TIM6_UP_RMP                SYSCFG_DMARMP_TIM6_UP_RMP_Msk
#define  SYSCFG_DMARMP_TIM7_UP_RMP_Pos            (12)
#define  SYSCFG_DMARMP_TIM7_UP_RMP_Msk            (0x1U << SYSCFG_DMARMP_TIM7_UP_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_TIM7_UP_RMP                SYSCFG_DMARMP_TIM7_UP_RMP_Msk
#define  SYSCFG_DMARMP_TIM8_TRIG_RMP_Pos          (13)
#define  SYSCFG_DMARMP_TIM8_TRIG_RMP_Msk          (0x1U << SYSCFG_DMARMP_TIM8_TRIG_RMP_Pos)         /*!<*/
#define  SYSCFG_DMARMP_TIM8_TRIG_RMP              SYSCFG_DMARMP_TIM8_TRIG_RMP_Msk
#define  SYSCFG_DMARMP_TIM8_UP_RMP_Pos            (14)
#define  SYSCFG_DMARMP_TIM8_UP_RMP_Msk            (0x1U << SYSCFG_DMARMP_TIM8_UP_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_TIM8_UP_RMP                SYSCFG_DMARMP_TIM8_UP_RMP_Msk
#define  SYSCFG_DMARMP_TIM8_COM_RMP_Pos           (15)
#define  SYSCFG_DMARMP_TIM8_COM_RMP_Msk           (0x1U << SYSCFG_DMARMP_TIM8_COM_RMP_Pos)          /*!<*/
#define  SYSCFG_DMARMP_TIM8_COM_RMP               SYSCFG_DMARMP_TIM8_COM_RMP_Msk
#define  SYSCFG_DMARMP_USART4_RX_RMP_Pos          (16)
#define  SYSCFG_DMARMP_USART4_RX_RMP_Msk          (0x1U << SYSCFG_DMARMP_USART4_RX_RMP_Pos)         /*!<*/
#define  SYSCFG_DMARMP_USART4_RX_RMP              SYSCFG_DMARMP_USART4_RX_RMP_Msk
#define  SYSCFG_DMARMP_USART4_TX_RMP_Pos          (17)
#define  SYSCFG_DMARMP_USART4_TX_RMP_Msk          (0x1U << SYSCFG_DMARMP_USART4_TX_RMP_Pos)         /*!<*/
#define  SYSCFG_DMARMP_USART4_TX_RMP              SYSCFG_DMARMP_USART4_TX_RMP_Msk
#define  SYSCFG_DMARMP_DAC_CH2_RMP_Pos            (27)
#define  SYSCFG_DMARMP_DAC_CH2_RMP_Msk            (0x1U << SYSCFG_DMARMP_DAC_CH2_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_DAC_CH2_RMP                SYSCFG_DMARMP_DAC_CH2_RMP_Msk
#define  SYSCFG_DMARMP_DAC_CH1_RMP_Pos            (28)
#define  SYSCFG_DMARMP_DAC_CH1_RMP_Msk            (0x1U << SYSCFG_DMARMP_DAC_CH1_RMP_Pos)           /*!<*/
#define  SYSCFG_DMARMP_DAC_CH1_RMP                SYSCFG_DMARMP_DAC_CH1_RMP_Msk
#define  SYSCFG_DMARMP_ADC3_RMP_Pos               (29)
#define  SYSCFG_DMARMP_ADC3_RMP_Msk               (0x1U << SYSCFG_DMARMP_ADC3_RMP_Pos)              /*!<*/
#define  SYSCFG_DMARMP_ADC3_RMP                   SYSCFG_DMARMP_ADC3_RMP_Msk
#define  SYSCFG_DMARMP_ADC1_RMP_Pos               (30)
#define  SYSCFG_DMARMP_ADC1_RMP_Msk               (0x1U << SYSCFG_DMARMP_ADC1_RMP_Pos)              /*!<*/
#define  SYSCFG_DMARMP_ADC1_RMP                   SYSCFG_DMARMP_ADC1_RMP_Msk
#define  SYSCFG_DMARMP_ADC2_RMP_Pos               (31)
#define  SYSCFG_DMARMP_ADC2_RMP_Msk               (0x1U << SYSCFG_DMARMP_ADC2_RMP_Pos)              /*!<*/
#define  SYSCFG_DMARMP_ADC2_RMP                   SYSCFG_DMARMP_ADC2_RMP_Msk

/**
  * @brief SYSCFG_BUS_PRI Register Bit Definition
  */
#define  SYSCFG_BUS_PRI_PRI_M1_Pos                (0)
#define  SYSCFG_BUS_PRI_PRI_M1_Msk                (0x7U << SYSCFG_BUS_PRI_PRI_M1_Pos)               /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M1                    SYSCFG_BUS_PRI_PRI_M1_Msk
#define  SYSCFG_BUS_PRI_PRI_M1_Bit0               (0x1U << SYSCFG_BUS_PRI_PRI_M1_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M1_Bit1               (0x2U << SYSCFG_BUS_PRI_PRI_M1_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M1_Bit2               (0x4U << SYSCFG_BUS_PRI_PRI_M1_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M2_Pos                (3)
#define  SYSCFG_BUS_PRI_PRI_M2_Msk                (0x7U << SYSCFG_BUS_PRI_PRI_M2_Pos)               /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M2                    SYSCFG_BUS_PRI_PRI_M2_Msk
#define  SYSCFG_BUS_PRI_PRI_M2_Bit0               (0x1U << SYSCFG_BUS_PRI_PRI_M2_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M2_Bit1               (0x2U << SYSCFG_BUS_PRI_PRI_M2_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M2_Bit2               (0x4U << SYSCFG_BUS_PRI_PRI_M2_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M3_Pos                (6)
#define  SYSCFG_BUS_PRI_PRI_M3_Msk                (0x7U << SYSCFG_BUS_PRI_PRI_M3_Pos)               /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M3                    SYSCFG_BUS_PRI_PRI_M3_Msk
#define  SYSCFG_BUS_PRI_PRI_M3_Bit0               (0x1U << SYSCFG_BUS_PRI_PRI_M3_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M3_Bit1               (0x2U << SYSCFG_BUS_PRI_PRI_M3_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M3_Bit2               (0x4U << SYSCFG_BUS_PRI_PRI_M3_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M4_Pos                (9)
#define  SYSCFG_BUS_PRI_PRI_M4_Msk                (0x7U << SYSCFG_BUS_PRI_PRI_M4_Pos)               /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M4                    SYSCFG_BUS_PRI_PRI_M4_Msk
#define  SYSCFG_BUS_PRI_PRI_M4_Bit0               (0x1U << SYSCFG_BUS_PRI_PRI_M4_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M4_Bit1               (0x2U << SYSCFG_BUS_PRI_PRI_M4_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M4_Bit2               (0x4U << SYSCFG_BUS_PRI_PRI_M4_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M5_Pos                (12)
#define  SYSCFG_BUS_PRI_PRI_M5_Msk                (0x7U << SYSCFG_BUS_PRI_PRI_M5_Pos)               /*!<*/
#define  SYSCFG_BUS_PRI_PRI_M5                    SYSCFG_BUS_PRI_PRI_M5_Msk
#define  SYSCFG_BUS_PRI_PRI_M5_Bit0               (0x1U << SYSCFG_BUS_PRI_PRI_M5_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M5_Bit1               (0x2U << SYSCFG_BUS_PRI_PRI_M5_Pos) 
#define  SYSCFG_BUS_PRI_PRI_M5_Bit2               (0x4U << SYSCFG_BUS_PRI_PRI_M5_Pos) 

/**
  * @brief SYSCFG_LP_CFGR1 Register Bit Definition
  */
#define  SYSCFG_LP_CFGR1_SRAM1_P0_PSD_Pos         (0)
#define  SYSCFG_LP_CFGR1_SRAM1_P0_PSD_Msk         (0x1U << SYSCFG_LP_CFGR1_SRAM1_P0_PSD_Pos)        /*!<*/
#define  SYSCFG_LP_CFGR1_SRAM1_P0_PSD             SYSCFG_LP_CFGR1_SRAM1_P0_PSD_Msk
#define  SYSCFG_LP_CFGR1_SRAM1_P1_PSD_Pos         (1)
#define  SYSCFG_LP_CFGR1_SRAM1_P1_PSD_Msk         (0x1U << SYSCFG_LP_CFGR1_SRAM1_P1_PSD_Pos)        /*!<*/
#define  SYSCFG_LP_CFGR1_SRAM1_P1_PSD             SYSCFG_LP_CFGR1_SRAM1_P1_PSD_Msk
#define  SYSCFG_LP_CFGR1_SRAM2_P0_PSD_Pos         (2)
#define  SYSCFG_LP_CFGR1_SRAM2_P0_PSD_Msk         (0x1U << SYSCFG_LP_CFGR1_SRAM2_P0_PSD_Pos)        /*!<*/
#define  SYSCFG_LP_CFGR1_SRAM2_P0_PSD             SYSCFG_LP_CFGR1_SRAM2_P0_PSD_Msk
#define  SYSCFG_LP_CFGR1_SRAM2_P1_PSD_Pos         (3)
#define  SYSCFG_LP_CFGR1_SRAM2_P1_PSD_Msk         (0x1U << SYSCFG_LP_CFGR1_SRAM2_P1_PSD_Pos)        /*!<*/
#define  SYSCFG_LP_CFGR1_SRAM2_P1_PSD             SYSCFG_LP_CFGR1_SRAM2_P1_PSD_Msk
#define  SYSCFG_LP_CFGR1_CACHE_MEM_PSD_Pos        (7)
#define  SYSCFG_LP_CFGR1_CACHE_MEM_PSD_Msk        (0x1U << SYSCFG_LP_CFGR1_CACHE_MEM_PSD_Pos)       /*!<*/
#define  SYSCFG_LP_CFGR1_CACHE_MEM_PSD            SYSCFG_LP_CFGR1_CACHE_MEM_PSD_Msk
#define  SYSCFG_LP_CFGR1_FCAN1_MEM_PSD_Pos        (8)
#define  SYSCFG_LP_CFGR1_FCAN1_MEM_PSD_Msk        (0x1U << SYSCFG_LP_CFGR1_FCAN1_MEM_PSD_Pos)       /*!<*/
#define  SYSCFG_LP_CFGR1_FCAN1_MEM_PSD            SYSCFG_LP_CFGR1_FCAN1_MEM_PSD_Msk
#define  SYSCFG_LP_CFGR1_FCAN2_MEM_PSD_Pos        (9)
#define  SYSCFG_LP_CFGR1_FCAN2_MEM_PSD_Msk        (0x1U << SYSCFG_LP_CFGR1_FCAN2_MEM_PSD_Pos)       /*!<*/
#define  SYSCFG_LP_CFGR1_FCAN2_MEM_PSD            SYSCFG_LP_CFGR1_FCAN2_MEM_PSD_Msk
#define  SYSCFG_LP_CFGR1_KEY_Pos                  (15)
#define  SYSCFG_LP_CFGR1_KEY_Msk                  (0x1FFFFU << SYSCFG_LP_CFGR1_KEY_Pos)             /*!<*/
#define  SYSCFG_LP_CFGR1_KEY                      SYSCFG_LP_CFGR1_KEY_Msk
#define  SYSCFG_LP_CFGR1_KEY_Bit0                 (0x00001U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit1                 (0x00002U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit2                 (0x00004U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit3                 (0x00008U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit4                 (0x00010U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit5                 (0x00020U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit6                 (0x00040U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit7                 (0x00080U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit8                 (0x00100U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit9                 (0x00200U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit10                (0x00400U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit11                (0x00800U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit12                (0x01000U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit13                (0x02000U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit14                (0x04000U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit15                (0x08000U << SYSCFG_LP_CFGR1_KEY_Pos) 
#define  SYSCFG_LP_CFGR1_KEY_Bit16                (0x10000U << SYSCFG_LP_CFGR1_KEY_Pos) 

/**
  * @brief SYSCFG_TEST Register Bit Definition
  */
#define  SYSCFG_TEST_ANA_DUMMY_Pos                (0)
#define  SYSCFG_TEST_ANA_DUMMY_Msk                (0xFFU << SYSCFG_TEST_ANA_DUMMY_Pos)              /*!<*/
#define  SYSCFG_TEST_ANA_DUMMY                    SYSCFG_TEST_ANA_DUMMY_Msk
#define  SYSCFG_TEST_ANA_DUMMY_Bit0               (0x01U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit1               (0x02U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit2               (0x04U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit3               (0x08U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit4               (0x10U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit5               (0x20U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit6               (0x40U << SYSCFG_TEST_ANA_DUMMY_Pos) 
#define  SYSCFG_TEST_ANA_DUMMY_Bit7               (0x80U << SYSCFG_TEST_ANA_DUMMY_Pos) 


#endif

