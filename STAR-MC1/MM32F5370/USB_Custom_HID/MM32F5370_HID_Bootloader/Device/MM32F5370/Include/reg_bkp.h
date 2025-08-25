/***********************************************************************************************************************
    @file     reg_bkp.h
    @author   VV TEAM
    @brief    This flie contains all the BKP's register and its field definition.
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

#ifndef __REG_BKP_H
#define __REG_BKP_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief BKP Base Address Definition
  */
#define  BKP_BASE                                  0x40002840                                       /*!<Base Address: 0x40002840*/

/**
  * @brief BKP Register Structure Definition
  */
typedef struct
{
    __IO uint32_t RTCCR;                          /*!<                                               offset: 0x00       */
    __IO uint32_t CR;                             /*!<                                               offset: 0x04       */
    __IO uint32_t CSR;                            /*!<                                               offset: 0x08       */
    __IO uint32_t RESERVED0x0C[1];                /*!<                                               offset: 0x0C       */
    __IO uint32_t DR[20];                         /*!<                                               offset: 0x10       */
} BKP_TypeDef;

/**
  * @brief BKP type pointer Definition
  */
#define BKP                                       ((BKP_TypeDef *)BKP_BASE)

/**
  * @brief BKP_RTCCR Register Bit Definition
  */
#define  BKP_RTCCR_CAL_Pos                        (0)
#define  BKP_RTCCR_CAL_Msk                        (0x7FU << BKP_RTCCR_CAL_Pos)                      /*!<*/
#define  BKP_RTCCR_CAL                            BKP_RTCCR_CAL_Msk
#define  BKP_RTCCR_CAL_Bit0                       (0x01U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CAL_Bit1                       (0x02U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CAL_Bit2                       (0x04U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CAL_Bit3                       (0x08U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CAL_Bit4                       (0x10U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CAL_Bit5                       (0x20U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CAL_Bit6                       (0x40U << BKP_RTCCR_CAL_Pos) 
#define  BKP_RTCCR_CCO_Pos                        (7)
#define  BKP_RTCCR_CCO_Msk                        (0x1U << BKP_RTCCR_CCO_Pos)                       /*!<*/
#define  BKP_RTCCR_CCO                            BKP_RTCCR_CCO_Msk
#define  BKP_RTCCR_ASOE_Pos                       (8)
#define  BKP_RTCCR_ASOE_Msk                       (0x1U << BKP_RTCCR_ASOE_Pos)                      /*!<*/
#define  BKP_RTCCR_ASOE                           BKP_RTCCR_ASOE_Msk
#define  BKP_RTCCR_ASOS_Pos                       (9)
#define  BKP_RTCCR_ASOS_Msk                       (0x1U << BKP_RTCCR_ASOS_Pos)                      /*!<*/
#define  BKP_RTCCR_ASOS                           BKP_RTCCR_ASOS_Msk

/**
  * @brief BKP_CR Register Bit Definition
  */
#define  BKP_CR_TPE_Pos                           (0)
#define  BKP_CR_TPE_Msk                           (0x1U << BKP_CR_TPE_Pos)                          /*!<*/
#define  BKP_CR_TPE                               BKP_CR_TPE_Msk
#define  BKP_CR_TPAL_Pos                          (1)
#define  BKP_CR_TPAL_Msk                          (0x1U << BKP_CR_TPAL_Pos)                         /*!<*/
#define  BKP_CR_TPAL                              BKP_CR_TPAL_Msk

/**
  * @brief BKP_CSR Register Bit Definition
  */
#define  BKP_CSR_CTE_Pos                          (0)
#define  BKP_CSR_CTE_Msk                          (0x1U << BKP_CSR_CTE_Pos)                         /*!<*/
#define  BKP_CSR_CTE                              BKP_CSR_CTE_Msk
#define  BKP_CSR_CTI_Pos                          (1)
#define  BKP_CSR_CTI_Msk                          (0x1U << BKP_CSR_CTI_Pos)                         /*!<*/
#define  BKP_CSR_CTI                              BKP_CSR_CTI_Msk
#define  BKP_CSR_TPIE_Pos                         (2)
#define  BKP_CSR_TPIE_Msk                         (0x1U << BKP_CSR_TPIE_Pos)                        /*!<*/
#define  BKP_CSR_TPIE                             BKP_CSR_TPIE_Msk
#define  BKP_CSR_TEF_Pos                          (8)
#define  BKP_CSR_TEF_Msk                          (0x1U << BKP_CSR_TEF_Pos)                         /*!<*/
#define  BKP_CSR_TEF                              BKP_CSR_TEF_Msk
#define  BKP_CSR_TIF_Pos                          (9)
#define  BKP_CSR_TIF_Msk                          (0x1U << BKP_CSR_TIF_Pos)                         /*!<*/
#define  BKP_CSR_TIF                              BKP_CSR_TIF_Msk

/**
  * @brief BKP_DR Register Bit Definition
  */
#define  BKP_DR_BKP_Pos                           (0)
#define  BKP_DR_BKP_Msk                           (0xFFFFU << BKP_DR_BKP_Pos)                       /*!<*/
#define  BKP_DR_BKP                               BKP_DR_BKP_Msk
#define  BKP_DR_BKP_Bit0                          (0x0001U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit1                          (0x0002U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit2                          (0x0004U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit3                          (0x0008U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit4                          (0x0010U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit5                          (0x0020U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit6                          (0x0040U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit7                          (0x0080U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit8                          (0x0100U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit9                          (0x0200U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit10                         (0x0400U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit11                         (0x0800U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit12                         (0x1000U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit13                         (0x2000U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit14                         (0x4000U << BKP_DR_BKP_Pos) 
#define  BKP_DR_BKP_Bit15                         (0x8000U << BKP_DR_BKP_Pos) 


#endif

