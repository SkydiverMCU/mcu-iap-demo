/***********************************************************************************************************************
    @file     reg_comp.h
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

#ifndef __REG_COMP_H
#define __REG_COMP_H

/* Files includes ------------------------------------------------------------*/
#include <core_cm0plus.h>

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/**
  * @brief COMP Base Address Definition
  */
#define COMP_BASE                       (APB2PERIPH_BASE + 0x3C00) /*!< Base Address: 0x40013C00 */

/**
  * @brief Comparators Register Structure Definition
  */

typedef struct
{

    __IO uint32_t COMPx_CSR;            /*!< COMP1 Control Status Register                  offset: 0x00 */
    __IO uint32_t RESERVED0;            /*!<                                                offset: 0x04 */
    __IO uint32_t RESERVED1;            /*!<                                                offset: 0x08 */
    __IO uint32_t RESERVED2;            /*!<                                                offset: 0x0C */
    __IO uint32_t RESERVED3;            /*!<                                                offset: 0x10 */
    __IO uint32_t RESERVED4;            /*!<                                                offset: 0x14 */
    __IO uint32_t RESERVED6;             /*!< COMP external reference voltage register       offset: 0x18 */
    __IO uint32_t COMPx_POLL;           /*!< COMP1 polling register                         offset: 0x1C */
} COMP_TypeDef;


/**
  * @brief COMP type pointer Definition
  */
#define COMP1                           ((COMP_TypeDef *)COMP_BASE)

#define COMP_CRV                        ((__IO uint32_t *)(COMP_BASE + 0x18)) 

/**
  * @brief COMP_CSR Register Bit Definition
  */
#define COMP_CSR_EN_Pos                 (0)
#define COMP_CSR_EN                     (0x01U << COMP_CSR_EN_Pos)   /*!< Comparator enable */


#define COMP_CSR_INM_SEL_Pos            (4)
#define COMP_CSR_INM_SEL_Msk            (0x03U << COMP_CSR_INM_SEL_Pos)  /*!< Comparator inverting input selection */
#define COMP_CSR_INM_SEL_0              (0x00U << COMP_CSR_INM_SEL_Pos)  /*!< INM0 as COMP inverting input */
#define COMP_CSR_INM_SEL_1              (0x01U << COMP_CSR_INM_SEL_Pos)  /*!< INM1 as COMP inverting input */
#define COMP_CSR_INM_SEL_2              (0x02U << COMP_CSR_INM_SEL_Pos)  /*!< INM2 as COMP inverting input */
#define COMP_CSR_INM_SEL_3              (0x03U << COMP_CSR_INM_SEL_Pos)  /*!< INM3 as COMP inverting input */

#define COMP_CSR_INP_SEL_Pos            (7)
#define COMP_CSR_INP_SEL_Msk            (0x03U << COMP_CSR_INP_SEL_Pos)  /*!< Comparator non-inverting input selection */
#define COMP_CSR_INP_SEL_INP0           (0x00U << COMP_CSR_INP_SEL_Pos)  /*!< INP0 as COMP non-inverting input */
#define COMP_CSR_INP_SEL_INP1           (0x01U << COMP_CSR_INP_SEL_Pos)  /*!< INP1 as COMP non-inverting input */
#define COMP_CSR_INP_SEL_INP2           (0x02U << COMP_CSR_INP_SEL_Pos)  /*!< INP2 as COMP non-inverting input */
#define COMP_CSR_INP_SEL_INP3           (0x03U << COMP_CSR_INP_SEL_Pos)  /*!< INP3 as COMP non-inverting input */

#define COMP_CSR_OUT_SEL_Pos            (10)
#define COMP_CSR_OUT_SEL_Msk            (0x0FU << COMP_CSR_OUT_SEL_Pos)     /*!< Comparator output selection */
#define COMP_CSR_OUT_SEL_TIM1_BRAKE     (0x02U << COMP_CSR_OUT_SEL_Pos)     /*!< Timer1 brake input */
#define COMP_CSR_OUT_SEL_TIM1_OCREFCLR  (0x06U << COMP_CSR_OUT_SEL_Pos)     /*!< Timer1 ocrefclear input */
#define COMP_CSR_OUT_SEL_TIM1_CAPTURE1  (0x07U << COMP_CSR_OUT_SEL_Pos)     /*!< Timer1 input capture 1 */
#define COMP_CSR_OUT_SEL_TIM2_CAPTURE4  (0x08U << COMP_CSR_OUT_SEL_Pos)     /*!< Timer2 input capture 4 */
#define COMP_CSR_OUT_SEL_TIM2_OCREFCLR  (0x09U << COMP_CSR_OUT_SEL_Pos)     /*!< Timer2 ocrefclear input */
#define COMP_CSR_OUT_SEL_TIM3_CAPTURE1  (0x0AU << COMP_CSR_OUT_SEL_Pos)     /*!< Timer3 input capture 1 */
#define COMP_CSR_OUT_SEL_TIM3_OCREFCLR  (0x0BU << COMP_CSR_OUT_SEL_Pos)     /*!< Timer3 ocrefclear input */

#define COMP_CSR_POL_Pos                (15)
#define COMP_CSR_POL_Msk                (0x01U << COMP_CSR_POL_Pos)  /*!< Comparator output polarity */

#define COMP_CSR_MODE_Pos               (2)
#define COMP_CSR_MODE_Msk               (0x03U << COMP_CSR_MODE_Pos)
#define COMP_CSR_HYST_Pos               (16)
#define COMP_CSR_HYST_Msk               (0x03U << COMP_CSR_HYST_Pos)                                  /*!< Comparator hysteresis */
#define COMP_CSR_HYST_0                 (0x00U << COMP_CSR_HYST_Pos)                                  /*!< Hysteresis Voltage: 0mV */
#define COMP_CSR_HYST_22                (0x01U << COMP_CSR_HYST_Pos)                                  /*!< Hysteresis Voltage: 22mV */
#define COMP_CSR_HYST_44                (0x02U << COMP_CSR_HYST_Pos)                                  /*!< Hysteresis Voltage: 44mV */
#define COMP_CSR_HYST_80                (0x03U << COMP_CSR_HYST_Pos)                                  /*!< Hysteresis Voltage: 80mV */
#define COMP_CSR_HYST_20                (0x01U << COMP_CSR_MODE_Pos) + (0x01U << COMP_CSR_HYST_Pos)   /*!< Hysteresis Voltage: 20mV */
#define COMP_CSR_HYST_37                (0x01U << COMP_CSR_MODE_Pos) + (0x02U << COMP_CSR_HYST_Pos)   /*!< Hysteresis Voltage: 37mV */
#define COMP_CSR_HYST_65                (0x01U << COMP_CSR_MODE_Pos) + (0x03U << COMP_CSR_HYST_Pos)   /*!< Hysteresis Voltage: 65mV */

#define COMP_CSR_OFLT_Pos               (18)
#define COMP_CSR_OFLT_Msk               (0x07U << COMP_CSR_OFLT_Pos) /*!< Comparator output filter */
#define COMP_CSR_OFLT_0                 (0x00U << COMP_CSR_OFLT_Pos) /*!< 0 clock cycle */
#define COMP_CSR_OFLT_1                 (0x01U << COMP_CSR_OFLT_Pos) /*!< 2 clock cycle */
#define COMP_CSR_OFLT_2                 (0x02U << COMP_CSR_OFLT_Pos) /*!< 4 clock cycle */
#define COMP_CSR_OFLT_3                 (0x03U << COMP_CSR_OFLT_Pos) /*!< 8 clock cycle */
#define COMP_CSR_OFLT_4                 (0x04U << COMP_CSR_OFLT_Pos) /*!< 16 clock cycle */
#define COMP_CSR_OFLT_5                 (0x05U << COMP_CSR_OFLT_Pos) /*!< 32 clock cycle */
#define COMP_CSR_OFLT_6                 (0x06U << COMP_CSR_OFLT_Pos) /*!< 64 clock cycle */
#define COMP_CSR_OFLT_7                 (0x07U << COMP_CSR_OFLT_Pos) /*!< 128 clock cycle */

#define COMP_CSR_OUT_ANA_SEL_Pos        (29)
#define COMP_CSR_OUT_ANA_SEL_Msk        (0x01U << COMP_CSR_OUT_ANA_SEL_Pos) /*!< Comparator x output source select Analog output */

#define COMP_CSR_OUT_Pos                (30)
#define COMP_CSR_OUT_Msk                (0x01U << COMP_CSR_OUT_Pos)  /*!< Comparator output status */
#define COMP_CSR_LOCK_Pos               (31)
#define COMP_CSR_LOCK                   (0x01U << COMP_CSR_LOCK_Pos) /*!< Comparator lock */

/**
  * @brief COMP_CRV Register Bit Definition
  */
#define COMP_CRV_SEL_Pos                (0)
#define COMP_CRV_SEL_Msk                (0x3FU << COMP_CRV_SEL_Pos)             /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_1_64               (0x00U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_2_64               (0x01U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_3_64               (0x02U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_4_64               (0x03U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_5_64               (0x04U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_6_64               (0x05U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_7_64               (0x06U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_8_64               (0x07U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_9_64               (0x08U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_10_64              (0x09U << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_11_64              (0x0AU << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_12_64              (0x0BU << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_13_64              (0x0CU << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_14_64              (0x0DU << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_15_64              (0x0EU << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */
#define COMP_CRV_SEL_16_64              (0x0FU << COMP_CRV_SEL_Pos)                 /*!< Comparator external reference voltage select */

#define COMP_CRV_SRC_Pos                (12)
#define COMP_CRV_SRC_Msk                (0x01U << COMP_CRV_SRC_Pos)
#define COMP_CRV_SRC                    (0x01U << COMP_CRV_SRC_Pos)             /*!< Comparator external reference voltage source select */
#define COMP_CRV_SRC_VREF               (0x00U << COMP_CRV_SRC_Pos)             /*!< Select VREF */
#define COMP_CRV_SRC_VDAA               (0x01U << COMP_CRV_SRC_Pos)             /*!< Select VDAA */

#define COMP_CRV_EN_Pos                 (15)
#define COMP_CRV_EN                     (0x01U << COMP_CRV_EN_Pos)              /*!< Comparator external reference voltage enable */

/**
  * @brief COMP_POL Register Bit Definition
  */
#define COMP_POLL_EN_Pos                (0)
#define COMP_POLL_EN                    (0x01U << COMP_POLL_EN_Pos)     /*!< Comparator polling enable */
#define COMP_POLL_EN_DISABLE            (0x00U << COMP_POLL_EN_Pos)     /*!< Disable comparator polling mode */
#define COMP_POLL_EN_ENABLE             (0x01U << COMP_POLL_EN_Pos)     /*!< Enable comparator polling mode */
#define COMP_POLL_CH_Pos                (1)
#define COMP_POLL_CH_Msk                (0x01U << COMP_POLL_CH_Pos)     /*!< Comparator polling channel */
#define COMP_POLL_CH_1_2                (0x00U << COMP_POLL_CH_Pos)     /*!< Polling channel 1/2 */
#define COMP_POLL_CH_1_2_3              (0x01U << COMP_POLL_CH_Pos)     /*!< Polling channel 1/2/3 */
#define COMP_POLL_FIXN_Pos              (2)
#define COMP_POLL_FIXN_Msk              (0x01U << COMP_POLL_FIXN_Pos)   /*!< Polling inverting input fix */
#define COMP_POLL_FIXN_NOTFIXED         (0x00U << COMP_POLL_FIXN_Pos)   /*!< Polling channel inverting input is not fixed */
#define COMP_POLL_FIXN_FIXED            (0x01U << COMP_POLL_FIXN_Pos)   /*!< Polling channel inverting input fixed */
#define COMP_POLL_PERIOD_Pos            (4)
#define COMP_POLL_PERIOD_Msk            (0x07U << COMP_POLL_PERIOD_Pos) /*!< polling wait cycle */
#define COMP_POLL_PERIOD_1              (0x00U << COMP_POLL_PERIOD_Pos) /*!< 1 clock cycle */
#define COMP_POLL_PERIOD_2              (0x01U << COMP_POLL_PERIOD_Pos) /*!< 2 clock cycle */
#define COMP_POLL_PERIOD_4              (0x02U << COMP_POLL_PERIOD_Pos) /*!< 4 clock cycle */
#define COMP_POLL_PERIOD_8              (0x03U << COMP_POLL_PERIOD_Pos) /*!< 8 clock cycle */
#define COMP_POLL_PERIOD_16             (0x04U << COMP_POLL_PERIOD_Pos) /*!< 16 clock cycle */
#define COMP_POLL_PERIOD_32             (0x05U << COMP_POLL_PERIOD_Pos) /*!< 32 clock cycle */
#define COMP_POLL_PERIOD_64             (0x06U << COMP_POLL_PERIOD_Pos) /*!< 64 clock cycle */
#define COMP_POLL_PERIOD_128            (0x07U << COMP_POLL_PERIOD_Pos) /*!< 128 clock cycle */
#define COMP_POLL_POUT_Pos              (8)
#define COMP_POLL_POUT                  (0x07U << COMP_POLL_POUT_Pos)   /*!< Polling output */
#define COMP_POLL_POUT_Low              (0x00U << COMP_POLL_POUT_Pos)   /*!< Non-inverting input is lower than inverting input */
#define COMP_POLL_POUT_High             (0x01U << COMP_POLL_POUT_Pos)   /*!< Non-inverting input is higher than inverting input */

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

