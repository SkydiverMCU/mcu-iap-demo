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
#include <core_cm0.h>



/**
  * @brief RTC Base Address Definition
  */
#define  RTC_BASE                                  0x40002800                                       /*!<Base Address: 0x40002800*/

/**
  * @brief RTC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CRH;                            /*!<RTC RTC control register high                  offset: 0x00       */
    __IO uint32_t CRL;                            /*!<RTC RTC control register low                   offset: 0x04       */
    __IO uint32_t PRLH;                           /*!<RTC RTC prescaler load register high           offset: 0x08       */
    __IO uint32_t PRLL;                           /*!<RTC RTC prescaler load register low            offset: 0x0C       */
    __IO uint32_t DIVH;                           /*!<RTC RTC prescaler divider register high        offset: 0x10       */
    __IO uint32_t DIVL;                           /*!<RTC RTC prescaler divider register low         offset: 0x14       */
    __IO uint32_t CNTH;                           /*!<RTC RTC counter register high                  offset: 0x18       */
    __IO uint32_t CNTL;                           /*!<RTC RTC counter register low                   offset: 0x1C       */
    __IO uint32_t ALRH;                           /*!<RTC RTC alarm register high                    offset: 0x20       */
    __IO uint32_t ALRL;                           /*!<RTC RTC alarm register low                     offset: 0x24       */
    __IO uint32_t MSRH;                           /*!<RTC RTC millisecond register high              offset: 0x28       */
    __IO uint32_t MSRL;                           /*!<RTC RTC millisecond register low               offset: 0x2C       */
    __IO uint32_t RESERVED0x30[3];                /*!<                                               offset: 0x30~0x38  */
    __IO uint32_t LSE_CFG;                        /*!<RTC RTC LSE configuration register             offset: 0x3C       */
} RTC_TypeDef;

/**
  * @brief RTC type pointer Definition
  */
#define RTC                                       ((RTC_TypeDef *)RTC_BASE)

/**
  * @brief RTC_CRH Register Bit Definition
  */
#define  RTC_CRH_SECIE_Pos                        (0)
#define  RTC_CRH_SECIE_Msk                        (0x1U << RTC_CRH_SECIE_Pos)                       /*!<Second Interrupt Enable*/
#define  RTC_CRH_SECIE                            RTC_CRH_SECIE_Msk
#define  RTC_CRH_ALRIE_Pos                        (1)
#define  RTC_CRH_ALRIE_Msk                        (0x1U << RTC_CRH_ALRIE_Pos)                       /*!<Alarm Interrupt Enable*/
#define  RTC_CRH_ALRIE                            RTC_CRH_ALRIE_Msk
#define  RTC_CRH_OWIE_Pos                         (2)
#define  RTC_CRH_OWIE_Msk                         (0x1U << RTC_CRH_OWIE_Pos)                        /*!<Overflow Interrupt Enable*/
#define  RTC_CRH_OWIE                             RTC_CRH_OWIE_Msk

/**
  * @brief RTC_CRL Register Bit Definition
  */
#define  RTC_CRL_SECF_Pos                         (0)
#define  RTC_CRL_SECF_Msk                         (0x1U << RTC_CRL_SECF_Pos)                        /*!<Second Flag*/
#define  RTC_CRL_SECF                             RTC_CRL_SECF_Msk
#define  RTC_CRL_ALRF_Pos                         (1)
#define  RTC_CRL_ALRF_Msk                         (0x1U << RTC_CRL_ALRF_Pos)                        /*!<Alarm Flag*/
#define  RTC_CRL_ALRF                             RTC_CRL_ALRF_Msk
#define  RTC_CRL_OWF_Pos                          (2)
#define  RTC_CRL_OWF_Msk                          (0x1U << RTC_CRL_OWF_Pos)                         /*!<Overflow Flag*/
#define  RTC_CRL_OWF                              RTC_CRL_OWF_Msk
#define  RTC_CRL_RSF_Pos                          (3)
#define  RTC_CRL_RSF_Msk                          (0x1U << RTC_CRL_RSF_Pos)                         /*!<Registers Synchronized Flag*/
#define  RTC_CRL_RSF                              RTC_CRL_RSF_Msk
#define  RTC_CRL_CNF_Pos                          (4)
#define  RTC_CRL_CNF_Msk                          (0x1U << RTC_CRL_CNF_Pos)                         /*!<Configuration Flag*/
#define  RTC_CRL_CNF                              RTC_CRL_CNF_Msk
#define  RTC_CRL_RTOFF_Pos                        (5)
#define  RTC_CRL_RTOFF_Msk                        (0x1U << RTC_CRL_RTOFF_Pos)                       /*!<RTC Operation OFF*/
#define  RTC_CRL_RTOFF                            RTC_CRL_RTOFF_Msk
#define  RTC_CRL_ALPEN_Pos                        (6)
#define  RTC_CRL_ALPEN_Msk                        (0x1U << RTC_CRL_ALPEN_Pos)                       /*!<RTC Alarm Loop Enable*/
#define  RTC_CRL_ALPEN                            RTC_CRL_ALPEN_Msk

/**
  * @brief RTC_PRLH Register Bit Definition
  */
#define  RTC_PRLH_PRLH_Pos                        (0)
#define  RTC_PRLH_PRLH_Msk                        (0xFU << RTC_PRLH_PRLH_Pos)                       /*!<RTC Prescaler Reload Value High*/
#define  RTC_PRLH_PRLH                            RTC_PRLH_PRLH_Msk
#define  RTC_PRLH_PRLH_0                          (0x1U << RTC_PRLH_PRLH_Pos) 
#define  RTC_PRLH_PRLH_1                          (0x2U << RTC_PRLH_PRLH_Pos) 
#define  RTC_PRLH_PRLH_2                          (0x4U << RTC_PRLH_PRLH_Pos) 
#define  RTC_PRLH_PRLH_3                          (0x8U << RTC_PRLH_PRLH_Pos) 

/**
  * @brief RTC_PRLL Register Bit Definition
  */
#define  RTC_PRLL_PRLL_Pos                        (0)
#define  RTC_PRLL_PRLL_Msk                        (0xFFFFU << RTC_PRLL_PRLL_Pos)                    /*!<RTC Prescaler Reload Value Low*/
#define  RTC_PRLL_PRLL                            RTC_PRLL_PRLL_Msk
#define  RTC_PRLL_PRLL_0                          (0x0001U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_1                          (0x0002U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_2                          (0x0004U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_3                          (0x0008U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_4                          (0x0010U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_5                          (0x0020U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_6                          (0x0040U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_7                          (0x0080U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_8                          (0x0100U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_9                          (0x0200U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_10                         (0x0400U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_11                         (0x0800U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_12                         (0x1000U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_13                         (0x2000U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_14                         (0x4000U << RTC_PRLL_PRLL_Pos) 
#define  RTC_PRLL_PRLL_15                         (0x8000U << RTC_PRLL_PRLL_Pos) 

/**
  * @brief RTC_DIVH Register Bit Definition
  */
#define  RTC_DIVH_DIVH_Pos                        (0)
#define  RTC_DIVH_DIVH_Msk                        (0xFU << RTC_DIVH_DIVH_Pos)                       /*!<RTC Clock Divider High*/
#define  RTC_DIVH_DIVH                            RTC_DIVH_DIVH_Msk
#define  RTC_DIVH_DIVH_0                          (0x1U << RTC_DIVH_DIVH_Pos) 
#define  RTC_DIVH_DIVH_1                          (0x2U << RTC_DIVH_DIVH_Pos) 
#define  RTC_DIVH_DIVH_2                          (0x4U << RTC_DIVH_DIVH_Pos) 
#define  RTC_DIVH_DIVH_3                          (0x8U << RTC_DIVH_DIVH_Pos) 

/**
  * @brief RTC_DIVL Register Bit Definition
  */
#define  RTC_DIVL_DIVL_Pos                        (0)
#define  RTC_DIVL_DIVL_Msk                        (0xFFFFU << RTC_DIVL_DIVL_Pos)                    /*!<RTC Clock Divider Low*/
#define  RTC_DIVL_DIVL                            RTC_DIVL_DIVL_Msk
#define  RTC_DIVL_DIVL_0                          (0x0001U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_1                          (0x0002U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_2                          (0x0004U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_3                          (0x0008U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_4                          (0x0010U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_5                          (0x0020U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_6                          (0x0040U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_7                          (0x0080U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_8                          (0x0100U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_9                          (0x0200U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_10                         (0x0400U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_11                         (0x0800U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_12                         (0x1000U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_13                         (0x2000U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_14                         (0x4000U << RTC_DIVL_DIVL_Pos) 
#define  RTC_DIVL_DIVL_15                         (0x8000U << RTC_DIVL_DIVL_Pos) 

/**
  * @brief RTC_CNTH Register Bit Definition
  */
#define  RTC_CNTH_CNTH_Pos                        (0)
#define  RTC_CNTH_CNTH_Msk                        (0xFFFFU << RTC_CNTH_CNTH_Pos)                    /*!<RTC Counter High*/
#define  RTC_CNTH_CNTH                            RTC_CNTH_CNTH_Msk
#define  RTC_CNTH_CNTH_0                          (0x0001U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_1                          (0x0002U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_2                          (0x0004U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_3                          (0x0008U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_4                          (0x0010U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_5                          (0x0020U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_6                          (0x0040U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_7                          (0x0080U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_8                          (0x0100U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_9                          (0x0200U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_10                         (0x0400U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_11                         (0x0800U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_12                         (0x1000U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_13                         (0x2000U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_14                         (0x4000U << RTC_CNTH_CNTH_Pos) 
#define  RTC_CNTH_CNTH_15                         (0x8000U << RTC_CNTH_CNTH_Pos) 

/**
  * @brief RTC_CNTL Register Bit Definition
  */
#define  RTC_CNTL_CNTL_Pos                        (0)
#define  RTC_CNTL_CNTL_Msk                        (0xFFFFU << RTC_CNTL_CNTL_Pos)                    /*!<RTC Counter Low*/
#define  RTC_CNTL_CNTL                            RTC_CNTL_CNTL_Msk
#define  RTC_CNTL_CNTL_0                          (0x0001U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_1                          (0x0002U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_2                          (0x0004U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_3                          (0x0008U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_4                          (0x0010U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_5                          (0x0020U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_6                          (0x0040U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_7                          (0x0080U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_8                          (0x0100U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_9                          (0x0200U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_10                         (0x0400U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_11                         (0x0800U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_12                         (0x1000U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_13                         (0x2000U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_14                         (0x4000U << RTC_CNTL_CNTL_Pos) 
#define  RTC_CNTL_CNTL_15                         (0x8000U << RTC_CNTL_CNTL_Pos) 

/**
  * @brief RTC_ALRH Register Bit Definition
  */
#define  RTC_ALRH_ALRH_Pos                        (0)
#define  RTC_ALRH_ALRH_Msk                        (0xFFFFU << RTC_ALRH_ALRH_Pos)                    /*!<RTC Alarm High*/
#define  RTC_ALRH_ALRH                            RTC_ALRH_ALRH_Msk
#define  RTC_ALRH_ALRH_0                          (0x0001U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_1                          (0x0002U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_2                          (0x0004U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_3                          (0x0008U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_4                          (0x0010U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_5                          (0x0020U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_6                          (0x0040U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_7                          (0x0080U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_8                          (0x0100U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_9                          (0x0200U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_10                         (0x0400U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_11                         (0x0800U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_12                         (0x1000U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_13                         (0x2000U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_14                         (0x4000U << RTC_ALRH_ALRH_Pos) 
#define  RTC_ALRH_ALRH_15                         (0x8000U << RTC_ALRH_ALRH_Pos) 

/**
  * @brief RTC_ALRL Register Bit Definition
  */
#define  RTC_ALRL_ALRL_Pos                        (0)
#define  RTC_ALRL_ALRL_Msk                        (0xFFFFU << RTC_ALRL_ALRL_Pos)                    /*!<RTC Alarm Low*/
#define  RTC_ALRL_ALRL                            RTC_ALRL_ALRL_Msk
#define  RTC_ALRL_ALRL_0                          (0x0001U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_1                          (0x0002U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_2                          (0x0004U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_3                          (0x0008U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_4                          (0x0010U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_5                          (0x0020U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_6                          (0x0040U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_7                          (0x0080U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_8                          (0x0100U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_9                          (0x0200U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_10                         (0x0400U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_11                         (0x0800U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_12                         (0x1000U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_13                         (0x2000U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_14                         (0x4000U << RTC_ALRL_ALRL_Pos) 
#define  RTC_ALRL_ALRL_15                         (0x8000U << RTC_ALRL_ALRL_Pos) 

/**
  * @brief RTC_MSRH Register Bit Definition
  */
#define  RTC_MSRH_MSRH_Pos                        (0)
#define  RTC_MSRH_MSRH_Msk                        (0xFU << RTC_MSRH_MSRH_Pos)                       /*!<RTC Msec High*/
#define  RTC_MSRH_MSRH                            RTC_MSRH_MSRH_Msk
#define  RTC_MSRH_MSRH_0                          (0x1U << RTC_MSRH_MSRH_Pos) 
#define  RTC_MSRH_MSRH_1                          (0x2U << RTC_MSRH_MSRH_Pos) 
#define  RTC_MSRH_MSRH_2                          (0x4U << RTC_MSRH_MSRH_Pos) 
#define  RTC_MSRH_MSRH_3                          (0x8U << RTC_MSRH_MSRH_Pos) 

/**
  * @brief RTC_MSRL Register Bit Definition
  */
#define  RTC_MSRL_MSRL_Pos                        (0)
#define  RTC_MSRL_MSRL_Msk                        (0xFFFFU << RTC_MSRL_MSRL_Pos)                    /*!<RTC Msec Low*/
#define  RTC_MSRL_MSRL                            RTC_MSRL_MSRL_Msk
#define  RTC_MSRL_MSRL_0                          (0x0001U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_1                          (0x0002U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_2                          (0x0004U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_3                          (0x0008U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_4                          (0x0010U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_5                          (0x0020U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_6                          (0x0040U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_7                          (0x0080U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_8                          (0x0100U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_9                          (0x0200U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_10                         (0x0400U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_11                         (0x0800U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_12                         (0x1000U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_13                         (0x2000U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_14                         (0x4000U << RTC_MSRL_MSRL_Pos) 
#define  RTC_MSRL_MSRL_15                         (0x8000U << RTC_MSRL_MSRL_Pos) 

/**
  * @brief RTC_LSE_CFG Register Bit Definition
  */
#define  RTC_LSE_CFG_LSE_IB_Pos                   (0)
#define  RTC_LSE_CFG_LSE_IB_Msk                   (0xFU << RTC_LSE_CFG_LSE_IB_Pos)                  /*!<LSE bias current adjustment*/
#define  RTC_LSE_CFG_LSE_IB                       RTC_LSE_CFG_LSE_IB_Msk
#define  RTC_LSE_CFG_LSE_IB_0                     (0x1U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_IB_1                     (0x2U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_IB_2                     (0x4U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_IB_3                     (0x8U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_IB_FCIN_Pos              (4)
#define  RTC_LSE_CFG_LSE_IB_FCIN_Msk              (0x1U << RTC_LSE_CFG_LSE_IB_FCIN_Pos)             /*!<LSE current for inv*/
#define  RTC_LSE_CFG_LSE_IB_FCIN                  RTC_LSE_CFG_LSE_IB_FCIN_Msk
#define  RTC_LSE_CFG_LSE_RFB_SEL_Pos              (6)
#define  RTC_LSE_CFG_LSE_RFB_SEL_Msk              (0x7U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)             /*!<Feedback resistor selection*/
#define  RTC_LSE_CFG_LSE_RFB_SEL                  RTC_LSE_CFG_LSE_RFB_SEL_Msk
#define  RTC_LSE_CFG_LSE_RFB_SEL_0                (0x1U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 
#define  RTC_LSE_CFG_LSE_RFB_SEL_1                (0x2U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 
#define  RTC_LSE_CFG_LSE_RFB_SEL_2                (0x4U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 


#endif

