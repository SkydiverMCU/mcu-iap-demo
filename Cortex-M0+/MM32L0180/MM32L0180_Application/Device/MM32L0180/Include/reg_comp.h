/***********************************************************************************************************************
    @file     reg_comp.h
    @author   VV TEAM
    @brief    This flie contains all the COMP's register and its field definition.
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

#ifndef __REG_COMP_H
#define __REG_COMP_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief COMP Base Address Definition
  */
#define  COMP_BASE                                 0x40013C00                                       /*!<Base Address: 0x40013C00*/

/**
  * @brief COMP Register Structure Definition
  */
typedef struct
{
    __IO uint32_t COMP1CSR;                       /*!<COMP COMP x (x=1,2) control and status         offset: 0x00
                                                      register                                                          */
    __IO uint32_t COMP2CSR;                       /*!<COMP COMP x (x=1,2) control and status         offset: 0x04
                                                      register                                                          */
    __IO uint32_t RESERVED0x08[4];                /*!<                                               offset: 0x08~0x14  */
    __IO uint32_t CRV;                            /*!<COMP COMP external reference voltage register  offset: 0x18       */
    __IO uint32_t COMP1POLL;                      /*!<COMP COMP x (x=1,2) polling register           offset: 0x1C       */
    __IO uint32_t COMP2POLL;                      /*!<COMP COMP x (x=1,2) polling register           offset: 0x20       */
} COMP_TypeDef;

/**
  * @brief COMP type pointer Definition
  */
#define COMP                                      ((COMP_TypeDef *)COMP_BASE)

/**
  * @brief COMP_COMPCSR Register Bit Definition
  */
#define  COMP_COMPCSR_EN_Pos                      (0)
#define  COMP_COMPCSR_EN_Msk                      (0x1U << COMP_COMPCSR_EN_Pos)                     /*!<Comparator x Enable*/
#define  COMP_COMPCSR_EN                          COMP_COMPCSR_EN_Msk
#define  COMP_COMPCSR_MODE_Pos                    (2)
#define  COMP_COMPCSR_MODE_Msk                    (0x1U << COMP_COMPCSR_MODE_Pos)                   /*!<Comparator x Mode*/
#define  COMP_COMPCSR_MODE                        COMP_COMPCSR_MODE_Msk
#define  COMP_COMPCSR_INM_SEL_Pos                 (4)
#define  COMP_COMPCSR_INM_SEL_Msk                 (0x7U << COMP_COMPCSR_INM_SEL_Pos)                /*!<Comparator x Negative Input Selection*/
#define  COMP_COMPCSR_INM_SEL                     COMP_COMPCSR_INM_SEL_Msk
#define  COMP_COMPCSR_INM_SEL_0                   (0x1U << COMP_COMPCSR_INM_SEL_Pos) 
#define  COMP_COMPCSR_INM_SEL_1                   (0x2U << COMP_COMPCSR_INM_SEL_Pos) 
#define  COMP_COMPCSR_INM_SEL_2                   (0x4U << COMP_COMPCSR_INM_SEL_Pos) 
#define  COMP_COMPCSR_INP_SEL_Pos                 (7)
#define  COMP_COMPCSR_INP_SEL_Msk                 (0x3U << COMP_COMPCSR_INP_SEL_Pos)                /*!<Comparator x Positive Input Selection*/
#define  COMP_COMPCSR_INP_SEL                     COMP_COMPCSR_INP_SEL_Msk
#define  COMP_COMPCSR_INP_SEL_0                   (0x1U << COMP_COMPCSR_INP_SEL_Pos) 
#define  COMP_COMPCSR_INP_SEL_1                   (0x2U << COMP_COMPCSR_INP_SEL_Pos) 
#define  COMP_COMPCSR_OUT_SEL_Pos                 (10)
#define  COMP_COMPCSR_OUT_SEL_Msk                 (0xFU << COMP_COMPCSR_OUT_SEL_Pos)                /*!<Comparator x Output Selection*/
#define  COMP_COMPCSR_OUT_SEL                     COMP_COMPCSR_OUT_SEL_Msk
#define  COMP_COMPCSR_OUT_SEL_0                   (0x1U << COMP_COMPCSR_OUT_SEL_Pos) 
#define  COMP_COMPCSR_OUT_SEL_1                   (0x2U << COMP_COMPCSR_OUT_SEL_Pos) 
#define  COMP_COMPCSR_OUT_SEL_2                   (0x4U << COMP_COMPCSR_OUT_SEL_Pos) 
#define  COMP_COMPCSR_OUT_SEL_3                   (0x8U << COMP_COMPCSR_OUT_SEL_Pos) 
#define  COMP_COMPCSR_POL_Pos                     (15)
#define  COMP_COMPCSR_POL_Msk                     (0x1U << COMP_COMPCSR_POL_Pos)                    /*!<Comparator x Output Polarity*/
#define  COMP_COMPCSR_POL                         COMP_COMPCSR_POL_Msk
#define  COMP_COMPCSR_HYST_Pos                    (16)
#define  COMP_COMPCSR_HYST_Msk                    (0x3U << COMP_COMPCSR_HYST_Pos)                   /*!<Comparator x Hysteresis*/
#define  COMP_COMPCSR_HYST                        COMP_COMPCSR_HYST_Msk
#define  COMP_COMPCSR_HYST_0                      (0x1U << COMP_COMPCSR_HYST_Pos) 
#define  COMP_COMPCSR_HYST_1                      (0x2U << COMP_COMPCSR_HYST_Pos) 
#define  COMP_COMPCSR_OFLT_Pos                    (18)
#define  COMP_COMPCSR_OFLT_Msk                    (0x7U << COMP_COMPCSR_OFLT_Pos)                   /*!<Comparator x Output Filter Period*/
#define  COMP_COMPCSR_OFLT                        COMP_COMPCSR_OFLT_Msk
#define  COMP_COMPCSR_OFLT_0                      (0x1U << COMP_COMPCSR_OFLT_Pos) 
#define  COMP_COMPCSR_OFLT_1                      (0x2U << COMP_COMPCSR_OFLT_Pos) 
#define  COMP_COMPCSR_OFLT_2                      (0x4U << COMP_COMPCSR_OFLT_Pos) 
#define  COMP_COMPCSR_OUT_ANA_SEL_Pos             (29)
#define  COMP_COMPCSR_OUT_ANA_SEL_Msk             (0x1U << COMP_COMPCSR_OUT_ANA_SEL_Pos)            /*!<Comparator x output source selection*/
#define  COMP_COMPCSR_OUT_ANA_SEL                 COMP_COMPCSR_OUT_ANA_SEL_Msk
#define  COMP_COMPCSR_OUT_Pos                     (30)
#define  COMP_COMPCSR_OUT_Msk                     (0x1U << COMP_COMPCSR_OUT_Pos)                    /*!<Comparator x Output*/
#define  COMP_COMPCSR_OUT                         COMP_COMPCSR_OUT_Msk
#define  COMP_COMPCSR_LOCK_Pos                    (31)
#define  COMP_COMPCSR_LOCK_Msk                    (0x1U << COMP_COMPCSR_LOCK_Pos)                   /*!<Comparator Register Lock*/
#define  COMP_COMPCSR_LOCK                        COMP_COMPCSR_LOCK_Msk

/**
  * @brief COMP_CRV Register Bit Definition
  */
#define  COMP_CRV_CRV_SEL_Pos                     (0)
#define  COMP_CRV_CRV_SEL_Msk                     (0x3FU << COMP_CRV_CRV_SEL_Pos)                   /*!<Comparator Reference Voltage Select*/
#define  COMP_CRV_CRV_SEL                         COMP_CRV_CRV_SEL_Msk
#define  COMP_CRV_CRV_SEL_0                       (0x01U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_1                       (0x02U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_2                       (0x04U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_3                       (0x08U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_4                       (0x10U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_5                       (0x20U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SRC_Pos                     (12)
#define  COMP_CRV_CRV_SRC_Msk                     (0x1U << COMP_CRV_CRV_SRC_Pos)                    /*!<Comparator Reference Voltage Source Select*/
#define  COMP_CRV_CRV_SRC                         COMP_CRV_CRV_SRC_Msk
#define  COMP_CRV_CRV_EN_Pos                      (15)
#define  COMP_CRV_CRV_EN_Msk                      (0x1U << COMP_CRV_CRV_EN_Pos)                     /*!<Comparator Reference Voltage Enable*/
#define  COMP_CRV_CRV_EN                          COMP_CRV_CRV_EN_Msk

/**
  * @brief COMP_COMPPOLL Register Bit Definition
  */
#define  COMP_COMPPOLL_POLL_EN_Pos                (0)
#define  COMP_COMPPOLL_POLL_EN_Msk                (0x1U << COMP_COMPPOLL_POLL_EN_Pos)               /*!<Comparator Polling Enable*/
#define  COMP_COMPPOLL_POLL_EN                    COMP_COMPPOLL_POLL_EN_Msk
#define  COMP_COMPPOLL_POLL_CH_Pos                (1)
#define  COMP_COMPPOLL_POLL_CH_Msk                (0x1U << COMP_COMPPOLL_POLL_CH_Pos)               /*!<Comparator Polling Channel*/
#define  COMP_COMPPOLL_POLL_CH                    COMP_COMPPOLL_POLL_CH_Msk
#define  COMP_COMPPOLL_FIXN_Pos                   (2)
#define  COMP_COMPPOLL_FIXN_Msk                   (0x1U << COMP_COMPPOLL_FIXN_Pos)                  /*!<Polling Negative Input Fix*/
#define  COMP_COMPPOLL_FIXN                       COMP_COMPPOLL_FIXN_Msk
#define  COMP_COMPPOLL_PERIOD_Pos                 (4)
#define  COMP_COMPPOLL_PERIOD_Msk                 (0x7U << COMP_COMPPOLL_PERIOD_Pos)                /*!<Polling Wait Cycle*/
#define  COMP_COMPPOLL_PERIOD                     COMP_COMPPOLL_PERIOD_Msk
#define  COMP_COMPPOLL_PERIOD_0                   (0x1U << COMP_COMPPOLL_PERIOD_Pos) 
#define  COMP_COMPPOLL_PERIOD_1                   (0x2U << COMP_COMPPOLL_PERIOD_Pos) 
#define  COMP_COMPPOLL_PERIOD_2                   (0x4U << COMP_COMPPOLL_PERIOD_Pos) 
#define  COMP_COMPPOLL_POUT_Pos                   (8)
#define  COMP_COMPPOLL_POUT_Msk                   (0x7U << COMP_COMPPOLL_POUT_Pos)                  /*!<Polling Output*/
#define  COMP_COMPPOLL_POUT                       COMP_COMPPOLL_POUT_Msk
#define  COMP_COMPPOLL_POUT_0                     (0x1U << COMP_COMPPOLL_POUT_Pos) 
#define  COMP_COMPPOLL_POUT_1                     (0x2U << COMP_COMPPOLL_POUT_Pos) 
#define  COMP_COMPPOLL_POUT_2                     (0x4U << COMP_COMPPOLL_POUT_Pos) 

#endif

