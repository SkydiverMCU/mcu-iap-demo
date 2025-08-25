/***********************************************************************************************************************
    @file     reg_exti.h
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

#ifndef __REG_EXTI_H
#define __REG_EXTI_H

/* Files includes ------------------------------------------------------------*/

#include <core_cm0plus.h>

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/**
  * @brief EXTI Base Address Definition
  */
#define EXTI_BASE                       (APB2PERIPH_BASE + 0x0400) 

/**
  * @brief EXTI Registers Structure Definition
  */
typedef struct
{
    __IO uint32_t IMR;                     /*!< Interrupt Mask Register                        offset: 0x00*/
    __IO uint32_t EMR;                     /*!< Event Mask Register                            offset: 0x04*/
    __IO uint32_t RTSR;                    /*!< Rising Trigger Status Register                 offset: 0x08*/
    __IO uint32_t FTSR;                    /*!< Falling Trigger Status Register                offset: 0x0C*/
    __IO uint32_t SWIER;                   /*!< Software Interrupt Enable Register             offset: 0x10*/
    __IO uint32_t PR;                      /*!< Pending Register                               offset: 0x14*/
} EXTI_TypeDef;

/**
  * @brief EXTI type pointer Definition
  */
#define EXTI                         ((EXTI_TypeDef *)EXTI_BASE)


/**
  * @brief EXTI_IMR Register Bit Definition
  */
#define EXTI_IMR_0_Pos               (0)
#define EXTI_IMR_0                   (0x01U << EXTI_IMR_0_Pos)            /*!< Interrupt Mask on line 0 */
#define EXTI_IMR_1_Pos               (1)
#define EXTI_IMR_1                   (0x01U << EXTI_IMR_1_Pos)            /*!< Interrupt Mask on line 1 */
#define EXTI_IMR_2_Pos               (2)
#define EXTI_IMR_2                   (0x01U << EXTI_IMR_2_Pos)            /*!< Interrupt Mask on line 2 */
#define EXTI_IMR_3_Pos               (3)
#define EXTI_IMR_3                   (0x01U << EXTI_IMR_3_Pos)            /*!< Interrupt Mask on line 3 */
#define EXTI_IMR_4_Pos               (4)
#define EXTI_IMR_4                   (0x01U << EXTI_IMR_4_Pos)            /*!< Interrupt Mask on line 4 */
#define EXTI_IMR_5_Pos               (5)
#define EXTI_IMR_5                   (0x01U << EXTI_IMR_5_Pos)            /*!< Interrupt Mask on line 5 */
#define EXTI_IMR_6_Pos               (6)
#define EXTI_IMR_6                   (0x01U << EXTI_IMR_6_Pos)            /*!< Interrupt Mask on line 6 */
#define EXTI_IMR_7_Pos               (7)
#define EXTI_IMR_7                   (0x01U << EXTI_IMR_7_Pos)            /*!< Interrupt Mask on line 7 */
#define EXTI_IMR_8_Pos               (8)
#define EXTI_IMR_8                   (0x01U << EXTI_IMR_8_Pos)            /*!< Interrupt Mask on line 8 */
#define EXTI_IMR_9_Pos               (9)
#define EXTI_IMR_9                   (0x01U << EXTI_IMR_9_Pos)            /*!< Interrupt Mask on line 9 */
#define EXTI_IMR_10_Pos              (10)
#define EXTI_IMR_10                  (0x01U << EXTI_IMR_10_Pos)           /*!< Interrupt Mask on line 10 */
#define EXTI_IMR_11_Pos              (11)
#define EXTI_IMR_11                  (0x01U << EXTI_IMR_11_Pos)           /*!< Interrupt Mask on line 11 */
#define EXTI_IMR_12_Pos              (12)
#define EXTI_IMR_12                  (0x01U << EXTI_IMR_12_Pos)           /*!< Interrupt Mask on line 12 */
#define EXTI_IMR_13_Pos              (13)
#define EXTI_IMR_13                  (0x01U << EXTI_IMR_13_Pos)           /*!< Interrupt Mask on line 13 */
#define EXTI_IMR_14_Pos              (14)
#define EXTI_IMR_14                  (0x01U << EXTI_IMR_14_Pos)           /*!< Interrupt Mask on line 14 */
#define EXTI_IMR_15_Pos              (15)
#define EXTI_IMR_15                  (0x01U << EXTI_IMR_15_Pos)           /*!< Interrupt Mask on line 15 */
#define EXTI_IMR_16_Pos              (16)
#define EXTI_IMR_16                  (0x01U << EXTI_IMR_16_Pos)           /*!< Interrupt Mask on line 16 */

#define EXTI_IMR_19_Pos              (19)
#define EXTI_IMR_19                  (0x01U << EXTI_IMR_19_Pos)           /*!< Interrupt Mask on line 19 */

#define EXTI_IMR_24_Pos              (24)
#define EXTI_IMR_24                  (0x01U << EXTI_IMR_24_Pos)           /*!< Interrupt Mask on line 24 */

/**
  * @brief EXTI_EMR Register Bit Definition
  */
#define EXTI_EMR_0_Pos               (0)
#define EXTI_EMR_0                   (0x01U << EXTI_EMR_0_Pos)  /*!< Event Mask on line 0 */
#define EXTI_EMR_1_Pos               (1)
#define EXTI_EMR_1                   (0x01U << EXTI_EMR_1_Pos)  /*!< Event Mask on line 1 */
#define EXTI_EMR_2_Pos               (2)
#define EXTI_EMR_2                   (0x01U << EXTI_EMR_2_Pos)  /*!< Event Mask on line 2 */
#define EXTI_EMR_3_Pos               (3)
#define EXTI_EMR_3                   (0x01U << EXTI_EMR_3_Pos)  /*!< Event Mask on line 3 */
#define EXTI_EMR_4_Pos               (4)
#define EXTI_EMR_4                   (0x01U << EXTI_EMR_4_Pos)  /*!< Event Mask on line 4 */
#define EXTI_EMR_5_Pos               (5)
#define EXTI_EMR_5                   (0x01U << EXTI_EMR_5_Pos)  /*!< Event Mask on line 5 */
#define EXTI_EMR_6_Pos               (6)
#define EXTI_EMR_6                   (0x01U << EXTI_EMR_6_Pos)  /*!< Event Mask on line 6 */
#define EXTI_EMR_7_Pos               (7)
#define EXTI_EMR_7                   (0x01U << EXTI_EMR_7_Pos)  /*!< Event Mask on line 7 */
#define EXTI_EMR_8_Pos               (8)
#define EXTI_EMR_8                   (0x01U << EXTI_EMR_8_Pos)  /*!< Event Mask on line 8 */
#define EXTI_EMR_9_Pos               (9)
#define EXTI_EMR_9                   (0x01U << EXTI_EMR_9_Pos)  /*!< Event Mask on line 9 */
#define EXTI_EMR_10_Pos              (10)
#define EXTI_EMR_10                  (0x01U << EXTI_EMR_10_Pos) /*!< Event Mask on line 10 */
#define EXTI_EMR_11_Pos              (11)
#define EXTI_EMR_11                  (0x01U << EXTI_EMR_11_Pos) /*!< Event Mask on line 11 */
#define EXTI_EMR_12_Pos              (12)
#define EXTI_EMR_12                  (0x01U << EXTI_EMR_12_Pos) /*!< Event Mask on line 12 */
#define EXTI_EMR_13_Pos              (13)
#define EXTI_EMR_13                  (0x01U << EXTI_EMR_13_Pos) /*!< Event Mask on line 13 */
#define EXTI_EMR_14_Pos              (14)
#define EXTI_EMR_14                  (0x01U << EXTI_EMR_14_Pos) /*!< Event Mask on line 14 */
#define EXTI_EMR_15_Pos              (15)
#define EXTI_EMR_15                  (0x01U << EXTI_EMR_15_Pos) /*!< Event Mask on line 15 */
#define EXTI_EMR_16_Pos              (16)
#define EXTI_EMR_16                  (0x01U << EXTI_EMR_16_Pos) /*!< Event Mask on line 16 */

#define EXTI_EMR_19_Pos              (19)
#define EXTI_EMR_19                  (0x01U << EXTI_EMR_19_Pos) /*!< Event Mask on line 19 */

#define EXTI_EMR_24_Pos              (24)
#define EXTI_EMR_24                  (0x01U << EXTI_EMR_24_Pos) /*!< Event Mask on line 24 */

/**
  * @brief EXTI_RTSR Register Bit Definition
  */
#define EXTI_RTSR_0_Pos              (0)
#define EXTI_RTSR_0                  (0x01U << EXTI_RTSR_0_Pos)  /*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR_1_Pos              (1)
#define EXTI_RTSR_1                  (0x01U << EXTI_RTSR_1_Pos)  /*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR_2_Pos              (2)
#define EXTI_RTSR_2                  (0x01U << EXTI_RTSR_2_Pos)  /*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR_3_Pos              (3)
#define EXTI_RTSR_3                  (0x01U << EXTI_RTSR_3_Pos)  /*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR_4_Pos              (4)
#define EXTI_RTSR_4                  (0x01U << EXTI_RTSR_4_Pos)  /*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR_5_Pos              (5)
#define EXTI_RTSR_5                  (0x01U << EXTI_RTSR_5_Pos)  /*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR_6_Pos              (6)
#define EXTI_RTSR_6                  (0x01U << EXTI_RTSR_6_Pos)  /*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR_7_Pos              (7)
#define EXTI_RTSR_7                  (0x01U << EXTI_RTSR_7_Pos)  /*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR_8_Pos              (8)
#define EXTI_RTSR_8                  (0x01U << EXTI_RTSR_8_Pos)  /*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR_9_Pos              (9)
#define EXTI_RTSR_9                  (0x01U << EXTI_RTSR_9_Pos)  /*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR_10_Pos             (10)
#define EXTI_RTSR_10                 (0x01U << EXTI_RTSR_10_Pos) /*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR_11_Pos             (11)
#define EXTI_RTSR_11                 (0x01U << EXTI_RTSR_11_Pos) /*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR_12_Pos             (12)
#define EXTI_RTSR_12                 (0x01U << EXTI_RTSR_12_Pos) /*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR_13_Pos             (13)
#define EXTI_RTSR_13                 (0x01U << EXTI_RTSR_13_Pos) /*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR_14_Pos             (14)
#define EXTI_RTSR_14                 (0x01U << EXTI_RTSR_14_Pos) /*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR_15_Pos             (15)
#define EXTI_RTSR_15                 (0x01U << EXTI_RTSR_15_Pos) /*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR_16_Pos             (16)
#define EXTI_RTSR_16                 (0x01U << EXTI_RTSR_16_Pos) /*!< Rising trigger event configuration bit of line 16 */

#define EXTI_RTSR_19_Pos             (19)
#define EXTI_RTSR_19                 (0x01U << EXTI_RTSR_19_Pos) /*!< Rising trigger event configuration bit of line 19 */

#define EXTI_RTSR_24_Pos             (24)
#define EXTI_RTSR_24                 (0x01U << EXTI_RTSR_24_Pos) /*!< Rising trigger event configuration bit of line 24 */

/**
  * @brief EXTI_FTSR Register Bit Definition
  */
#define EXTI_FTSR_0_Pos              (0)
#define EXTI_FTSR_0                  (0x01U << EXTI_FTSR_0_Pos)  /*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR_1_Pos              (1)
#define EXTI_FTSR_1                  (0x01U << EXTI_FTSR_1_Pos)  /*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR_2_Pos              (2)
#define EXTI_FTSR_2                  (0x01U << EXTI_FTSR_2_Pos)  /*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR_3_Pos              (3)
#define EXTI_FTSR_3                  (0x01U << EXTI_FTSR_3_Pos)  /*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR_4_Pos              (4)
#define EXTI_FTSR_4                  (0x01U << EXTI_FTSR_4_Pos)  /*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR_5_Pos              (5)
#define EXTI_FTSR_5                  (0x01U << EXTI_FTSR_5_Pos)  /*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR_6_Pos              (6)
#define EXTI_FTSR_6                  (0x01U << EXTI_FTSR_6_Pos)  /*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR_7_Pos              (7)
#define EXTI_FTSR_7                  (0x01U << EXTI_FTSR_7_Pos)  /*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR_8_Pos              (8)
#define EXTI_FTSR_8                  (0x01U << EXTI_FTSR_8_Pos)  /*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR_9_Pos              (9)
#define EXTI_FTSR_9                  (0x01U << EXTI_FTSR_9_Pos)  /*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR_10_Pos             (10)
#define EXTI_FTSR_10                 (0x01U << EXTI_FTSR_10_Pos) /*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR_11_Pos             (11)
#define EXTI_FTSR_11                 (0x01U << EXTI_FTSR_11_Pos) /*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR_12_Pos             (12)
#define EXTI_FTSR_12                 (0x01U << EXTI_FTSR_12_Pos) /*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR_13_Pos             (13)
#define EXTI_FTSR_13                 (0x01U << EXTI_FTSR_13_Pos) /*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR_14_Pos             (14)
#define EXTI_FTSR_14                 (0x01U << EXTI_FTSR_14_Pos) /*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR_15_Pos             (15)
#define EXTI_FTSR_15                 (0x01U << EXTI_FTSR_15_Pos) /*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR_16_Pos             (16)
#define EXTI_FTSR_16                 (0x01U << EXTI_FTSR_16_Pos) /*!< Falling trigger event configuration bit of line 16 */

#define EXTI_FTSR_19_Pos             (19)
#define EXTI_FTSR_19                 (0x01U << EXTI_FTSR_19_Pos) /*!< Falling trigger event configuration bit of line 19 */

#define EXTI_FTSR_24_Pos             (24)
#define EXTI_FTSR_24                 (0x01U << EXTI_FTSR_24_Pos) /*!< Falling trigger event configuration bit of line 24 */

/**
  * @brief EXTI_SWIER Register Bit Definition
  */
#define EXTI_SWIER_0_Pos             (0)
#define EXTI_SWIER_0                 (0x01U << EXTI_SWIER_0_Pos)  /*!< Software Interrupt on line  0 */
#define EXTI_SWIER_1_Pos             (1)
#define EXTI_SWIER_1                 (0x01U << EXTI_SWIER_1_Pos)  /*!< Software Interrupt on line  1 */
#define EXTI_SWIER_2_Pos             (2)
#define EXTI_SWIER_2                 (0x01U << EXTI_SWIER_2_Pos)  /*!< Software Interrupt on line  2 */
#define EXTI_SWIER_3_Pos             (3)
#define EXTI_SWIER_3                 (0x01U << EXTI_SWIER_3_Pos)  /*!< Software Interrupt on line  3 */
#define EXTI_SWIER_4_Pos             (4)
#define EXTI_SWIER_4                 (0x01U << EXTI_SWIER_4_Pos)  /*!< Software Interrupt on line  4 */
#define EXTI_SWIER_5_Pos             (5)
#define EXTI_SWIER_5                 (0x01U << EXTI_SWIER_5_Pos)  /*!< Software Interrupt on line  5 */
#define EXTI_SWIER_6_Pos             (6)
#define EXTI_SWIER_6                 (0x01U << EXTI_SWIER_6_Pos)  /*!< Software Interrupt on line  6 */
#define EXTI_SWIER_7_Pos             (7)
#define EXTI_SWIER_7                 (0x01U << EXTI_SWIER_7_Pos)  /*!< Software Interrupt on line  7 */
#define EXTI_SWIER_8_Pos             (8)
#define EXTI_SWIER_8                 (0x01U << EXTI_SWIER_8_Pos)  /*!< Software Interrupt on line  8 */
#define EXTI_SWIER_9_Pos             (9)
#define EXTI_SWIER_9                 (0x01U << EXTI_SWIER_9_Pos)  /*!< Software Interrupt on line  9 */
#define EXTI_SWIER_10_Pos            (10)
#define EXTI_SWIER_10                (0x01U << EXTI_SWIER_10_Pos) /*!< Software Interrupt on line  10 */
#define EXTI_SWIER_11_Pos            (11)
#define EXTI_SWIER_11                (0x01U << EXTI_SWIER_11_Pos) /*!< Software Interrupt on line  11 */
#define EXTI_SWIER_12_Pos            (12)
#define EXTI_SWIER_12                (0x01U << EXTI_SWIER_12_Pos) /*!< Software Interrupt on line  12 */
#define EXTI_SWIER_13_Pos            (13)
#define EXTI_SWIER_13                (0x01U << EXTI_SWIER_13_Pos) /*!< Software Interrupt on line  13 */
#define EXTI_SWIER_14_Pos            (14)
#define EXTI_SWIER_14                (0x01U << EXTI_SWIER_14_Pos) /*!< Software Interrupt on line  14 */
#define EXTI_SWIER_15_Pos            (15)
#define EXTI_SWIER_15                (0x01U << EXTI_SWIER_15_Pos) /*!< Software Interrupt on line  15 */
#define EXTI_SWIER_16_Pos            (16)
#define EXTI_SWIER_16                (0x01U << EXTI_SWIER_16_Pos) /*!< Software Interrupt on line  16 */

#define EXTI_SWIER_19_Pos            (19)
#define EXTI_SWIER_19                (0x01U << EXTI_SWIER_19_Pos) /*!< Software Interrupt on line  19 */

#define EXTI_SWIER_24_Pos            (24)
#define EXTI_SWIER_24                (0x01U << EXTI_SWIER_24_Pos) /*!< Software Interrupt on line  24 */

/**
  * @brief EXTI_PR Register Bit Definition
  */
#define EXTI_PR_0_Pos                (0)
#define EXTI_PR_0                    (0x01U << EXTI_PR_0_Pos)  /*!< Pending bit 0 */
#define EXTI_PR_1_Pos                (1)
#define EXTI_PR_1                    (0x01U << EXTI_PR_1_Pos)  /*!< Pending bit 1 */
#define EXTI_PR_2_Pos                (2)
#define EXTI_PR_2                    (0x01U << EXTI_PR_2_Pos)  /*!< Pending bit 2 */
#define EXTI_PR_3_Pos                (3)
#define EXTI_PR_3                    (0x01U << EXTI_PR_3_Pos)  /*!< Pending bit 3 */
#define EXTI_PR_4_Pos                (4)
#define EXTI_PR_4                    (0x01U << EXTI_PR_4_Pos)  /*!< Pending bit 4 */
#define EXTI_PR_5_Pos                (5)
#define EXTI_PR_5                    (0x01U << EXTI_PR_5_Pos)  /*!< Pending bit 5 */
#define EXTI_PR_6_Pos                (6)
#define EXTI_PR_6                    (0x01U << EXTI_PR_6_Pos)  /*!< Pending bit 6 */
#define EXTI_PR_7_Pos                (7)
#define EXTI_PR_7                    (0x01U << EXTI_PR_7_Pos)  /*!< Pending bit 7 */
#define EXTI_PR_8_Pos                (8)
#define EXTI_PR_8                    (0x01U << EXTI_PR_8_Pos)  /*!< Pending bit 8 */
#define EXTI_PR_9_Pos                (9)
#define EXTI_PR_9                    (0x01U << EXTI_PR_9_Pos)  /*!< Pending bit 9 */
#define EXTI_PR_10_Pos               (10)
#define EXTI_PR_10                   (0x01U << EXTI_PR_10_Pos) /*!< Pending bit 10 */
#define EXTI_PR_11_Pos               (11)
#define EXTI_PR_11                   (0x01U << EXTI_PR_11_Pos) /*!< Pending bit 11 */
#define EXTI_PR_12_Pos               (12)
#define EXTI_PR_12                   (0x01U << EXTI_PR_12_Pos) /*!< Pending bit 12 */
#define EXTI_PR_13_Pos               (13)
#define EXTI_PR_13                   (0x01U << EXTI_PR_13_Pos) /*!< Pending bit 13 */
#define EXTI_PR_14_Pos               (14)
#define EXTI_PR_14                   (0x01U << EXTI_PR_14_Pos) /*!< Pending bit 14 */
#define EXTI_PR_15_Pos               (15)
#define EXTI_PR_15                   (0x01U << EXTI_PR_15_Pos) /*!< Pending bit 15 */
#define EXTI_PR_16_Pos               (16)
#define EXTI_PR_16                   (0x01U << EXTI_PR_16_Pos) /*!< Pending bit 16 */

#define EXTI_PR_19_Pos               (19)
#define EXTI_PR_19                   (0x01U << EXTI_PR_19_Pos) /*!< Pending bit 19 */

#define EXTI_PR_24_Pos               (24)
#define EXTI_PR_24                   (0x01U << EXTI_PR_24_Pos) /*!< Pending bit 24 */

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

