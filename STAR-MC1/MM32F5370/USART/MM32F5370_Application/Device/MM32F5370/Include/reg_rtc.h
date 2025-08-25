/***********************************************************************************************************************
    @file     reg_rtc.h
    @author   VV TEAM
    @brief    This flie contains all the RTC's register and its field definition.
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

#ifndef __REG_RTC_H
#define __REG_RTC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief RTC Base Address Definition
  */
#define  RTC_BASE                                  0x40002800                                       /*!<Base Address: 0x40002800*/

/**
  * @brief RTC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CRH;                            /*!<                                               offset: 0x00       */
    __IO uint32_t CRL;                            /*!<                                               offset: 0x04       */
    __IO uint32_t PRLH;                           /*!<                                               offset: 0x08       */
    __IO uint32_t PRLL;                           /*!<                                               offset: 0x0C       */
    __IO uint32_t DIVH;                           /*!<                                               offset: 0x10       */
    __IO uint32_t DIVL;                           /*!<                                               offset: 0x14       */
    __IO uint32_t CNTH;                           /*!<                                               offset: 0x18       */
    __IO uint32_t CNTL;                           /*!<                                               offset: 0x1C       */
    __IO uint32_t ALRH;                           /*!<                                               offset: 0x20       */
    __IO uint32_t ALRL;                           /*!<                                               offset: 0x24       */
    __IO uint32_t MSRH;                           /*!<                                               offset: 0x28       */
    __IO uint32_t MSRL;                           /*!<                                               offset: 0x2C       */
    __IO uint32_t RESERVED0x30[3];                /*!<                                               offset: 0x30~0x38  */
    __IO uint32_t LSE_CFG;                        /*!<                                               offset: 0x3C       */
} RTC_TypeDef;

/**
  * @brief RTC type pointer Definition
  */
#define RTC                                       ((RTC_TypeDef *)RTC_BASE)

/**
  * @brief RTC_CRH Register Bit Definition
  */
#define  RTC_CRH_SECIE_Pos                        (0)
#define  RTC_CRH_SECIE_Msk                        (0x1U << RTC_CRH_SECIE_Pos)                       /*!<*/
#define  RTC_CRH_SECIE                            RTC_CRH_SECIE_Msk
#define  RTC_CRH_ALRIE_Pos                        (1)
#define  RTC_CRH_ALRIE_Msk                        (0x1U << RTC_CRH_ALRIE_Pos)                       /*!<*/
#define  RTC_CRH_ALRIE                            RTC_CRH_ALRIE_Msk
#define  RTC_CRH_OWIE_Pos                         (2)
#define  RTC_CRH_OWIE_Msk                         (0x1U << RTC_CRH_OWIE_Pos)                        /*!<*/
#define  RTC_CRH_OWIE                             RTC_CRH_OWIE_Msk

/**
  * @brief RTC_CRL Register Bit Definition
  */
#define  RTC_CRL_SECF_Pos                         (0)
#define  RTC_CRL_SECF_Msk                         (0x1U << RTC_CRL_SECF_Pos)                        /*!<*/
#define  RTC_CRL_SECF                             RTC_CRL_SECF_Msk
#define  RTC_CRL_ALRF_Pos                         (1)
#define  RTC_CRL_ALRF_Msk                         (0x1U << RTC_CRL_ALRF_Pos)                        /*!<*/
#define  RTC_CRL_ALRF                             RTC_CRL_ALRF_Msk
#define  RTC_CRL_OWF_Pos                          (2)
#define  RTC_CRL_OWF_Msk                          (0x1U << RTC_CRL_OWF_Pos)                         /*!<*/
#define  RTC_CRL_OWF                              RTC_CRL_OWF_Msk
#define  RTC_CRL_RSF_Pos                          (3)
#define  RTC_CRL_RSF_Msk                          (0x1U << RTC_CRL_RSF_Pos)                         /*!<*/
#define  RTC_CRL_RSF                              RTC_CRL_RSF_Msk
#define  RTC_CRL_CNF_Pos                          (4)
#define  RTC_CRL_CNF_Msk                          (0x1U << RTC_CRL_CNF_Pos)                         /*!<*/
#define  RTC_CRL_CNF                              RTC_CRL_CNF_Msk
#define  RTC_CRL_RTOFF_Pos                        (5)
#define  RTC_CRL_RTOFF_Msk                        (0x1U << RTC_CRL_RTOFF_Pos)                       /*!<*/
#define  RTC_CRL_RTOFF                            RTC_CRL_RTOFF_Msk
#define  RTC_CRL_ALPEN_Pos                        (6)
#define  RTC_CRL_ALPEN_Msk                        (0x1U << RTC_CRL_ALPEN_Pos)                       /*!<*/
#define  RTC_CRL_ALPEN                            RTC_CRL_ALPEN_Msk

/**
  * @brief RTC_PRLH Register Bit Definition
  */
#define  RTC_PRLH_PRL_Pos                         (0)
#define  RTC_PRLH_PRL_Msk                         (0xFU << RTC_PRLH_PRL_Pos)                        /*!<*/
#define  RTC_PRLH_PRL                             RTC_PRLH_PRL_Msk
#define  RTC_PRLH_PRL_Bit0                        (0x1U << RTC_PRLH_PRL_Pos) 
#define  RTC_PRLH_PRL_Bit1                        (0x2U << RTC_PRLH_PRL_Pos) 
#define  RTC_PRLH_PRL_Bit2                        (0x4U << RTC_PRLH_PRL_Pos) 
#define  RTC_PRLH_PRL_Bit3                        (0x8U << RTC_PRLH_PRL_Pos) 

/**
  * @brief RTC_PRLL Register Bit Definition
  */
#define  RTC_PRLL_PRL_Pos                         (0)
#define  RTC_PRLL_PRL_Msk                         (0xFFFFU << RTC_PRLL_PRL_Pos)                     /*!<*/
#define  RTC_PRLL_PRL                             RTC_PRLL_PRL_Msk
#define  RTC_PRLL_PRL_Bit0                        (0x0001U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit1                        (0x0002U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit2                        (0x0004U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit3                        (0x0008U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit4                        (0x0010U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit5                        (0x0020U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit6                        (0x0040U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit7                        (0x0080U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit8                        (0x0100U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit9                        (0x0200U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit10                       (0x0400U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit11                       (0x0800U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit12                       (0x1000U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit13                       (0x2000U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit14                       (0x4000U << RTC_PRLL_PRL_Pos) 
#define  RTC_PRLL_PRL_Bit15                       (0x8000U << RTC_PRLL_PRL_Pos) 

/**
  * @brief RTC_DIVH Register Bit Definition
  */
#define  RTC_DIVH_DIV_Pos                         (0)
#define  RTC_DIVH_DIV_Msk                         (0xFU << RTC_DIVH_DIV_Pos)                        /*!<*/
#define  RTC_DIVH_DIV                             RTC_DIVH_DIV_Msk
#define  RTC_DIVH_DIV_Bit0                        (0x1U << RTC_DIVH_DIV_Pos) 
#define  RTC_DIVH_DIV_Bit1                        (0x2U << RTC_DIVH_DIV_Pos) 
#define  RTC_DIVH_DIV_Bit2                        (0x4U << RTC_DIVH_DIV_Pos) 
#define  RTC_DIVH_DIV_Bit3                        (0x8U << RTC_DIVH_DIV_Pos) 

/**
  * @brief RTC_DIVL Register Bit Definition
  */
#define  RTC_DIVL_DIV_Pos                         (0)
#define  RTC_DIVL_DIV_Msk                         (0xFFFFU << RTC_DIVL_DIV_Pos)                     /*!<*/
#define  RTC_DIVL_DIV                             RTC_DIVL_DIV_Msk
#define  RTC_DIVL_DIV_Bit0                        (0x0001U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit1                        (0x0002U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit2                        (0x0004U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit3                        (0x0008U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit4                        (0x0010U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit5                        (0x0020U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit6                        (0x0040U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit7                        (0x0080U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit8                        (0x0100U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit9                        (0x0200U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit10                       (0x0400U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit11                       (0x0800U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit12                       (0x1000U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit13                       (0x2000U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit14                       (0x4000U << RTC_DIVL_DIV_Pos) 
#define  RTC_DIVL_DIV_Bit15                       (0x8000U << RTC_DIVL_DIV_Pos) 

/**
  * @brief RTC_CNTH Register Bit Definition
  */
#define  RTC_CNTH_CNT_Pos                         (0)
#define  RTC_CNTH_CNT_Msk                         (0xFFFFU << RTC_CNTH_CNT_Pos)                     /*!<*/
#define  RTC_CNTH_CNT                             RTC_CNTH_CNT_Msk
#define  RTC_CNTH_CNT_Bit0                        (0x0001U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit1                        (0x0002U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit2                        (0x0004U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit3                        (0x0008U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit4                        (0x0010U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit5                        (0x0020U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit6                        (0x0040U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit7                        (0x0080U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit8                        (0x0100U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit9                        (0x0200U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit10                       (0x0400U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit11                       (0x0800U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit12                       (0x1000U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit13                       (0x2000U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit14                       (0x4000U << RTC_CNTH_CNT_Pos) 
#define  RTC_CNTH_CNT_Bit15                       (0x8000U << RTC_CNTH_CNT_Pos) 

/**
  * @brief RTC_CNTL Register Bit Definition
  */
#define  RTC_CNTL_CNT_Pos                         (0)
#define  RTC_CNTL_CNT_Msk                         (0xFFFFU << RTC_CNTL_CNT_Pos)                     /*!<*/
#define  RTC_CNTL_CNT                             RTC_CNTL_CNT_Msk
#define  RTC_CNTL_CNT_Bit0                        (0x0001U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit1                        (0x0002U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit2                        (0x0004U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit3                        (0x0008U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit4                        (0x0010U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit5                        (0x0020U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit6                        (0x0040U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit7                        (0x0080U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit8                        (0x0100U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit9                        (0x0200U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit10                       (0x0400U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit11                       (0x0800U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit12                       (0x1000U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit13                       (0x2000U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit14                       (0x4000U << RTC_CNTL_CNT_Pos) 
#define  RTC_CNTL_CNT_Bit15                       (0x8000U << RTC_CNTL_CNT_Pos) 

/**
  * @brief RTC_ALRH Register Bit Definition
  */
#define  RTC_ALRH_ALR_Pos                         (0)
#define  RTC_ALRH_ALR_Msk                         (0xFFFFU << RTC_ALRH_ALR_Pos)                     /*!<*/
#define  RTC_ALRH_ALR                             RTC_ALRH_ALR_Msk
#define  RTC_ALRH_ALR_Bit0                        (0x0001U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit1                        (0x0002U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit2                        (0x0004U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit3                        (0x0008U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit4                        (0x0010U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit5                        (0x0020U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit6                        (0x0040U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit7                        (0x0080U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit8                        (0x0100U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit9                        (0x0200U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit10                       (0x0400U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit11                       (0x0800U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit12                       (0x1000U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit13                       (0x2000U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit14                       (0x4000U << RTC_ALRH_ALR_Pos) 
#define  RTC_ALRH_ALR_Bit15                       (0x8000U << RTC_ALRH_ALR_Pos) 

/**
  * @brief RTC_ALRL Register Bit Definition
  */
#define  RTC_ALRL_ALR_Pos                         (0)
#define  RTC_ALRL_ALR_Msk                         (0xFFFFU << RTC_ALRL_ALR_Pos)                     /*!<*/
#define  RTC_ALRL_ALR                             RTC_ALRL_ALR_Msk
#define  RTC_ALRL_ALR_Bit0                        (0x0001U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit1                        (0x0002U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit2                        (0x0004U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit3                        (0x0008U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit4                        (0x0010U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit5                        (0x0020U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit6                        (0x0040U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit7                        (0x0080U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit8                        (0x0100U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit9                        (0x0200U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit10                       (0x0400U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit11                       (0x0800U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit12                       (0x1000U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit13                       (0x2000U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit14                       (0x4000U << RTC_ALRL_ALR_Pos) 
#define  RTC_ALRL_ALR_Bit15                       (0x8000U << RTC_ALRL_ALR_Pos) 

/**
  * @brief RTC_MSRH Register Bit Definition
  */
#define  RTC_MSRH_MSR_Pos                         (0)
#define  RTC_MSRH_MSR_Msk                         (0xFU << RTC_MSRH_MSR_Pos)                        /*!<*/
#define  RTC_MSRH_MSR                             RTC_MSRH_MSR_Msk
#define  RTC_MSRH_MSR_Bit0                        (0x1U << RTC_MSRH_MSR_Pos) 
#define  RTC_MSRH_MSR_Bit1                        (0x2U << RTC_MSRH_MSR_Pos) 
#define  RTC_MSRH_MSR_Bit2                        (0x4U << RTC_MSRH_MSR_Pos) 
#define  RTC_MSRH_MSR_Bit3                        (0x8U << RTC_MSRH_MSR_Pos) 

/**
  * @brief RTC_MSRL Register Bit Definition
  */
#define  RTC_MSRL_MSR_Pos                         (0)
#define  RTC_MSRL_MSR_Msk                         (0xFFFFU << RTC_MSRL_MSR_Pos)                     /*!<*/
#define  RTC_MSRL_MSR                             RTC_MSRL_MSR_Msk
#define  RTC_MSRL_MSR_Bit0                        (0x0001U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit1                        (0x0002U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit2                        (0x0004U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit3                        (0x0008U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit4                        (0x0010U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit5                        (0x0020U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit6                        (0x0040U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit7                        (0x0080U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit8                        (0x0100U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit9                        (0x0200U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit10                       (0x0400U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit11                       (0x0800U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit12                       (0x1000U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit13                       (0x2000U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit14                       (0x4000U << RTC_MSRL_MSR_Pos) 
#define  RTC_MSRL_MSR_Bit15                       (0x8000U << RTC_MSRL_MSR_Pos) 

/**
  * @brief RTC_LSE_CFG Register Bit Definition
  */
#define  RTC_LSE_CFG_LSE_TC_Pos                   (0)
#define  RTC_LSE_CFG_LSE_TC_Msk                   (0x3U << RTC_LSE_CFG_LSE_TC_Pos)                  /*!<*/
#define  RTC_LSE_CFG_LSE_TC                       RTC_LSE_CFG_LSE_TC_Msk
#define  RTC_LSE_CFG_LSE_TC_Bit0                  (0x1U << RTC_LSE_CFG_LSE_TC_Pos) 
#define  RTC_LSE_CFG_LSE_TC_Bit1                  (0x2U << RTC_LSE_CFG_LSE_TC_Pos) 
#define  RTC_LSE_CFG_LSE_OUTENH_Pos               (2)
#define  RTC_LSE_CFG_LSE_OUTENH_Msk               (0x1U << RTC_LSE_CFG_LSE_OUTENH_Pos)              /*!<*/
#define  RTC_LSE_CFG_LSE_OUTENH                   RTC_LSE_CFG_LSE_OUTENH_Msk
#define  RTC_LSE_CFG_LSE_DR_Pos                   (4)
#define  RTC_LSE_CFG_LSE_DR_Msk                   (0x3U << RTC_LSE_CFG_LSE_DR_Pos)                  /*!<*/
#define  RTC_LSE_CFG_LSE_DR                       RTC_LSE_CFG_LSE_DR_Msk
#define  RTC_LSE_CFG_LSE_DR_Bit0                  (0x1U << RTC_LSE_CFG_LSE_DR_Pos) 
#define  RTC_LSE_CFG_LSE_DR_Bit1                  (0x2U << RTC_LSE_CFG_LSE_DR_Pos) 
#define  RTC_LSE_CFG_LSE_RFB_SEL_Pos              (6)
#define  RTC_LSE_CFG_LSE_RFB_SEL_Msk              (0x3U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)             /*!<*/
#define  RTC_LSE_CFG_LSE_RFB_SEL                  RTC_LSE_CFG_LSE_RFB_SEL_Msk
#define  RTC_LSE_CFG_LSE_RFB_SEL_Bit0             (0x1U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 
#define  RTC_LSE_CFG_LSE_RFB_SEL_Bit1             (0x2U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 
#define  RTC_LSE_CFG_LSE_IB_Pos                   (8)
#define  RTC_LSE_CFG_LSE_IB_Msk                   (0x3U << RTC_LSE_CFG_LSE_IB_Pos)                  /*!<*/
#define  RTC_LSE_CFG_LSE_IB                       RTC_LSE_CFG_LSE_IB_Msk
#define  RTC_LSE_CFG_LSE_IB_Bit0                  (0x1U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_IB_Bit1                  (0x2U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_AAC_Pos                  (10)
#define  RTC_LSE_CFG_LSE_AAC_Msk                  (0x1U << RTC_LSE_CFG_LSE_AAC_Pos)                 /*!<*/
#define  RTC_LSE_CFG_LSE_AAC                      RTC_LSE_CFG_LSE_AAC_Msk


#endif

