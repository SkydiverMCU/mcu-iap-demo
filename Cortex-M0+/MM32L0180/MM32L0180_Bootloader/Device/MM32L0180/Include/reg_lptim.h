/***********************************************************************************************************************
    @file     reg_lptim.h
    @author   VV TEAM
    @brief    This flie contains all the LPTIM's register and its field definition.
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

#ifndef __REG_LPTIM_H
#define __REG_LPTIM_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief LPTIM Base Address Definition
  */
#define  LPTIM1_BASE                               0x40012800                                       /*!<Base Address: 0x40012800*/
#define  LPTIM3_BASE                               0x40008000                                       /*!<Base Address: 0x40008000*/
#define  LPTIM4_BASE                               0x40008400                                       /*!<Base Address: 0x40008400*/
#define  LPTIM2_BASE                               0x40014C00                                       /*!<Base Address: 0x40014C00*/

/**
  * @brief LPTIM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFG;                            /*!<LPTIM Configuration Register                   offset: 0x00       */
    __IO uint32_t IE;                             /*!<LPTIM Interrupt Enable Register                offset: 0x04       */
    __IO uint32_t IF;                             /*!<LPTIM Interrupt Flag Register                  offset: 0x08       */
    __IO uint32_t CTRL;                           /*!<LPTIM Control Register                         offset: 0x0C       */
    __IO uint32_t CNT;                            /*!<LPTIM Count Register                           offset: 0x10       */
    __IO uint32_t CMP;                            /*!<LPTIM Compare Value Register                   offset: 0x14       */
    __IO uint32_t TARGET;                         /*!<LPTIM Target Value Register                    offset: 0x18       */
} LPTIM_TypeDef;

/**
  * @brief LPTIM type pointer Definition
  */
#define LPTIM1                                    ((LPTIM_TypeDef *)LPTIM1_BASE)
#define LPTIM3                                    ((LPTIM_TypeDef *)LPTIM3_BASE)
#define LPTIM4                                    ((LPTIM_TypeDef *)LPTIM4_BASE)
#define LPTIM2                                    ((LPTIM_TypeDef *)LPTIM2_BASE)

/**
  * @brief LPTIM_CFG Register Bit Definition
  */
#define  LPTIM_CFG_MODE_Pos                       (0)
#define  LPTIM_CFG_MODE_Msk                       (0x1U << LPTIM_CFG_MODE_Pos)                      /*!<Count mode*/
#define  LPTIM_CFG_MODE                           LPTIM_CFG_MODE_Msk
#define  LPTIM_CFG_TMODE_Pos                      (1)
#define  LPTIM_CFG_TMODE_Msk                      (0x3U << LPTIM_CFG_TMODE_Pos)                     /*!<Woke mode selection*/
#define  LPTIM_CFG_TMODE                          LPTIM_CFG_TMODE_Msk
#define  LPTIM_CFG_TMODE_0                        (0x1U << LPTIM_CFG_TMODE_Pos) 
#define  LPTIM_CFG_TMODE_1                        (0x2U << LPTIM_CFG_TMODE_Pos) 
#define  LPTIM_CFG_PWM_Pos                        (3)
#define  LPTIM_CFG_PWM_Msk                        (0x1U << LPTIM_CFG_PWM_Pos)                       /*!<Pulse width modulation*/
#define  LPTIM_CFG_PWM                            LPTIM_CFG_PWM_Msk
#define  LPTIM_CFG_POLARITY_Pos                   (4)
#define  LPTIM_CFG_POLARITY_Msk                   (0x1U << LPTIM_CFG_POLARITY_Pos)                  /*!<Match compare waveform polarity selection*/
#define  LPTIM_CFG_POLARITY                       LPTIM_CFG_POLARITY_Msk
#define  LPTIM_CFG_TRIGSEL_Pos                    (5)
#define  LPTIM_CFG_TRIGSEL_Msk                    (0x1U << LPTIM_CFG_TRIGSEL_Pos)                   /*!<Trigger input source selection*/
#define  LPTIM_CFG_TRIGSEL                        LPTIM_CFG_TRIGSEL_Msk
#define  LPTIM_CFG_TRIGCFG_Pos                    (6)
#define  LPTIM_CFG_TRIGCFG_Msk                    (0x3U << LPTIM_CFG_TRIGCFG_Pos)                   /*!<External trigger edge selection*/
#define  LPTIM_CFG_TRIGCFG                        LPTIM_CFG_TRIGCFG_Msk
#define  LPTIM_CFG_TRIGCFG_0                      (0x1U << LPTIM_CFG_TRIGCFG_Pos) 
#define  LPTIM_CFG_TRIGCFG_1                      (0x2U << LPTIM_CFG_TRIGCFG_Pos) 
#define  LPTIM_CFG_DIVSEL_Pos                     (8)
#define  LPTIM_CFG_DIVSEL_Msk                     (0x7U << LPTIM_CFG_DIVSEL_Pos)                    /*!<Counter clock division selection*/
#define  LPTIM_CFG_DIVSEL                         LPTIM_CFG_DIVSEL_Msk
#define  LPTIM_CFG_DIVSEL_0                       (0x1U << LPTIM_CFG_DIVSEL_Pos) 
#define  LPTIM_CFG_DIVSEL_1                       (0x2U << LPTIM_CFG_DIVSEL_Pos) 
#define  LPTIM_CFG_DIVSEL_2                       (0x4U << LPTIM_CFG_DIVSEL_Pos) 
#define  LPTIM_CFG_FLTEN_Pos                      (15)
#define  LPTIM_CFG_FLTEN_Msk                      (0x1U << LPTIM_CFG_FLTEN_Pos)                     /*!<Input signal filter enable bit*/
#define  LPTIM_CFG_FLTEN                          LPTIM_CFG_FLTEN_Msk

/**
  * @brief LPTIM_IE Register Bit Definition
  */
#define  LPTIM_IE_OVIE_Pos                        (0)
#define  LPTIM_IE_OVIE_Msk                        (0x1U << LPTIM_IE_OVIE_Pos)                       /*!<Counter overflow interrupt enable bit*/
#define  LPTIM_IE_OVIE                            LPTIM_IE_OVIE_Msk
#define  LPTIM_IE_TRIGIE_Pos                      (1)
#define  LPTIM_IE_TRIGIE_Msk                      (0x1U << LPTIM_IE_TRIGIE_Pos)                     /*!<External trigger interrupt enable bit*/
#define  LPTIM_IE_TRIGIE                          LPTIM_IE_TRIGIE_Msk
#define  LPTIM_IE_CMPIE_Pos                       (2)
#define  LPTIM_IE_CMPIE_Msk                       (0x1U << LPTIM_IE_CMPIE_Pos)                      /*!<Match compare interrupt enable bit*/
#define  LPTIM_IE_CMPIE                           LPTIM_IE_CMPIE_Msk

/**
  * @brief LPTIM_IF Register Bit Definition
  */
#define  LPTIM_IF_OVIF_Pos                        (0)
#define  LPTIM_IF_OVIF_Msk                        (0x1U << LPTIM_IF_OVIF_Pos)                       /*!<Counter overflow interrupt flag bit, write 1 to clear*/
#define  LPTIM_IF_OVIF                            LPTIM_IF_OVIF_Msk
#define  LPTIM_IF_TRIGIF_Pos                      (1)
#define  LPTIM_IF_TRIGIF_Msk                      (0x1U << LPTIM_IF_TRIGIF_Pos)                     /*!<External trigger interrupt flag bit, write 1 to clear*/
#define  LPTIM_IF_TRIGIF                          LPTIM_IF_TRIGIF_Msk
#define  LPTIM_IF_CMPIF_Pos                       (2)
#define  LPTIM_IF_CMPIF_Msk                       (0x1U << LPTIM_IF_CMPIF_Pos)                      /*!<Match compare interrupt flag bit, write 1 to clear*/
#define  LPTIM_IF_CMPIF                           LPTIM_IF_CMPIF_Msk

/**
  * @brief LPTIM_CTRL Register Bit Definition
  */
#define  LPTIM_CTRL_LPTEN_Pos                     (0)
#define  LPTIM_CTRL_LPTEN_Msk                     (0x1U << LPTIM_CTRL_LPTEN_Pos)                    /*!<LPTIM enable bit*/
#define  LPTIM_CTRL_LPTEN                         LPTIM_CTRL_LPTEN_Msk

/**
  * @brief LPTIM_CNT Register Bit Definition
  */
#define  LPTIM_CNT_CNT_Pos                        (0)
#define  LPTIM_CNT_CNT_Msk                        (0xFFFFU << LPTIM_CNT_CNT_Pos)                    /*!<LPTIM counter value*/
#define  LPTIM_CNT_CNT                            LPTIM_CNT_CNT_Msk
#define  LPTIM_CNT_CNT_0                          (0x0001U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_1                          (0x0002U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_2                          (0x0004U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_3                          (0x0008U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_4                          (0x0010U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_5                          (0x0020U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_6                          (0x0040U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_7                          (0x0080U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_8                          (0x0100U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_9                          (0x0200U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_10                         (0x0400U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_11                         (0x0800U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_12                         (0x1000U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_13                         (0x2000U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_14                         (0x4000U << LPTIM_CNT_CNT_Pos) 
#define  LPTIM_CNT_CNT_15                         (0x8000U << LPTIM_CNT_CNT_Pos) 

/**
  * @brief LPTIM_CMP Register Bit Definition
  */
#define  LPTIM_CMP_COMPARE_REG_Pos                (0)
#define  LPTIM_CMP_COMPARE_REG_Msk                (0xFFFFU << LPTIM_CMP_COMPARE_REG_Pos)            /*!<LPTIM comparator value register*/
#define  LPTIM_CMP_COMPARE_REG                    LPTIM_CMP_COMPARE_REG_Msk
#define  LPTIM_CMP_COMPARE_REG_0                  (0x0001U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_1                  (0x0002U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_2                  (0x0004U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_3                  (0x0008U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_4                  (0x0010U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_5                  (0x0020U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_6                  (0x0040U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_7                  (0x0080U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_8                  (0x0100U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_9                  (0x0200U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_10                 (0x0400U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_11                 (0x0800U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_12                 (0x1000U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_13                 (0x2000U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_14                 (0x4000U << LPTIM_CMP_COMPARE_REG_Pos) 
#define  LPTIM_CMP_COMPARE_REG_15                 (0x8000U << LPTIM_CMP_COMPARE_REG_Pos) 

/**
  * @brief LPTIM_TARGET Register Bit Definition
  */
#define  LPTIM_TARGET_TARGET_REG_Pos              (0)
#define  LPTIM_TARGET_TARGET_REG_Msk              (0xFFFFU << LPTIM_TARGET_TARGET_REG_Pos)          /*!<LPTIM target value register,PWM output frequency = clock frequency / (TARGET_REG+1)*/
#define  LPTIM_TARGET_TARGET_REG                  LPTIM_TARGET_TARGET_REG_Msk
#define  LPTIM_TARGET_TARGET_REG_0                (0x0001U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_1                (0x0002U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_2                (0x0004U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_3                (0x0008U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_4                (0x0010U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_5                (0x0020U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_6                (0x0040U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_7                (0x0080U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_8                (0x0100U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_9                (0x0200U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_10               (0x0400U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_11               (0x0800U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_12               (0x1000U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_13               (0x2000U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_14               (0x4000U << LPTIM_TARGET_TARGET_REG_Pos) 
#define  LPTIM_TARGET_TARGET_REG_15               (0x8000U << LPTIM_TARGET_TARGET_REG_Pos) 

#endif

