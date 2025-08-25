/***********************************************************************************************************************
    @file     reg_crs.h
    @author   VV TEAM
    @brief    This flie contains all the CRS's register and its field definition.
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

#ifndef __REG_CRS_H
#define __REG_CRS_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief CRS Base Address Definition
  */
#define  CRS_BASE                                  0x40006C00                                       /*!<Base Address: 0x40006C00*/

/**
  * @brief CRS Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<                                               offset: 0x00       */
    __IO uint32_t CFGR;                           /*!<                                               offset: 0x04       */
    __IO uint32_t ISR;                            /*!<                                               offset: 0x08       */
    __IO uint32_t ICR;                            /*!<                                               offset: 0x0C       */
} CRS_TypeDef;

/**
  * @brief CRS type pointer Definition
  */
#define CRS                                       ((CRS_TypeDef *)CRS_BASE)

/**
  * @brief CRS_CR Register Bit Definition
  */
#define  CRS_CR_SYNCOKIE_Pos                      (0)
#define  CRS_CR_SYNCOKIE_Msk                      (0x1U << CRS_CR_SYNCOKIE_Pos)                     /*!<*/
#define  CRS_CR_SYNCOKIE                          CRS_CR_SYNCOKIE_Msk
#define  CRS_CR_SYNCWARNIE_Pos                    (1)
#define  CRS_CR_SYNCWARNIE_Msk                    (0x1U << CRS_CR_SYNCWARNIE_Pos)                   /*!<*/
#define  CRS_CR_SYNCWARNIE                        CRS_CR_SYNCWARNIE_Msk
#define  CRS_CR_ERRIE_Pos                         (2)
#define  CRS_CR_ERRIE_Msk                         (0x1U << CRS_CR_ERRIE_Pos)                        /*!<*/
#define  CRS_CR_ERRIE                             CRS_CR_ERRIE_Msk
#define  CRS_CR_ESYNCIE_Pos                       (3)
#define  CRS_CR_ESYNCIE_Msk                       (0x1U << CRS_CR_ESYNCIE_Pos)                      /*!<*/
#define  CRS_CR_ESYNCIE                           CRS_CR_ESYNCIE_Msk
#define  CRS_CR_CEN_Pos                           (5)
#define  CRS_CR_CEN_Msk                           (0x1U << CRS_CR_CEN_Pos)                          /*!<*/
#define  CRS_CR_CEN                               CRS_CR_CEN_Msk
#define  CRS_CR_AUTOTRIMEN_Pos                    (6)
#define  CRS_CR_AUTOTRIMEN_Msk                    (0x1U << CRS_CR_AUTOTRIMEN_Pos)                   /*!<*/
#define  CRS_CR_AUTOTRIMEN                        CRS_CR_AUTOTRIMEN_Msk
#define  CRS_CR_SWSYNC_Pos                        (7)
#define  CRS_CR_SWSYNC_Msk                        (0x1U << CRS_CR_SWSYNC_Pos)                       /*!<*/
#define  CRS_CR_SWSYNC                            CRS_CR_SWSYNC_Msk
#define  CRS_CR_TRIM_Pos                          (8)
#define  CRS_CR_TRIM_Msk                          (0x3FFU << CRS_CR_TRIM_Pos)                       /*!<*/
#define  CRS_CR_TRIM                              CRS_CR_TRIM_Msk
#define  CRS_CR_TRIM_Bit0                         (0x001U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit1                         (0x002U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit2                         (0x004U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit3                         (0x008U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit4                         (0x010U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit5                         (0x020U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit6                         (0x040U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit7                         (0x080U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit8                         (0x100U << CRS_CR_TRIM_Pos) 
#define  CRS_CR_TRIM_Bit9                         (0x200U << CRS_CR_TRIM_Pos) 

/**
  * @brief CRS_CFGR Register Bit Definition
  */
#define  CRS_CFGR_RELOAD_Pos                      (0)
#define  CRS_CFGR_RELOAD_Msk                      (0xFFFFU << CRS_CFGR_RELOAD_Pos)                  /*!<*/
#define  CRS_CFGR_RELOAD                          CRS_CFGR_RELOAD_Msk
#define  CRS_CFGR_RELOAD_Bit0                     (0x0001U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit1                     (0x0002U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit2                     (0x0004U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit3                     (0x0008U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit4                     (0x0010U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit5                     (0x0020U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit6                     (0x0040U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit7                     (0x0080U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit8                     (0x0100U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit9                     (0x0200U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit10                    (0x0400U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit11                    (0x0800U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit12                    (0x1000U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit13                    (0x2000U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit14                    (0x4000U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_RELOAD_Bit15                    (0x8000U << CRS_CFGR_RELOAD_Pos) 
#define  CRS_CFGR_FELIM_Pos                       (16)
#define  CRS_CFGR_FELIM_Msk                       (0xFFU << CRS_CFGR_FELIM_Pos)                     /*!<*/
#define  CRS_CFGR_FELIM                           CRS_CFGR_FELIM_Msk
#define  CRS_CFGR_FELIM_Bit0                      (0x01U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit1                      (0x02U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit2                      (0x04U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit3                      (0x08U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit4                      (0x10U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit5                      (0x20U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit6                      (0x40U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_FELIM_Bit7                      (0x80U << CRS_CFGR_FELIM_Pos) 
#define  CRS_CFGR_SYNCDIV_Pos                     (24)
#define  CRS_CFGR_SYNCDIV_Msk                     (0x7U << CRS_CFGR_SYNCDIV_Pos)                    /*!<*/
#define  CRS_CFGR_SYNCDIV                         CRS_CFGR_SYNCDIV_Msk
#define  CRS_CFGR_SYNCDIV_Bit0                    (0x1U << CRS_CFGR_SYNCDIV_Pos) 
#define  CRS_CFGR_SYNCDIV_Bit1                    (0x2U << CRS_CFGR_SYNCDIV_Pos) 
#define  CRS_CFGR_SYNCDIV_Bit2                    (0x4U << CRS_CFGR_SYNCDIV_Pos) 
#define  CRS_CFGR_SYNCSRC_Pos                     (28)
#define  CRS_CFGR_SYNCSRC_Msk                     (0x3U << CRS_CFGR_SYNCSRC_Pos)                    /*!<*/
#define  CRS_CFGR_SYNCSRC                         CRS_CFGR_SYNCSRC_Msk
#define  CRS_CFGR_SYNCSRC_Bit0                    (0x1U << CRS_CFGR_SYNCSRC_Pos) 
#define  CRS_CFGR_SYNCSRC_Bit1                    (0x2U << CRS_CFGR_SYNCSRC_Pos) 
#define  CRS_CFGR_SYNCPOL_Pos                     (31)
#define  CRS_CFGR_SYNCPOL_Msk                     (0x1U << CRS_CFGR_SYNCPOL_Pos)                    /*!<*/
#define  CRS_CFGR_SYNCPOL                         CRS_CFGR_SYNCPOL_Msk

/**
  * @brief CRS_ISR Register Bit Definition
  */
#define  CRS_ISR_SYNCOKF_Pos                      (0)
#define  CRS_ISR_SYNCOKF_Msk                      (0x1U << CRS_ISR_SYNCOKF_Pos)                     /*!<*/
#define  CRS_ISR_SYNCOKF                          CRS_ISR_SYNCOKF_Msk
#define  CRS_ISR_SYNCWARNF_Pos                    (1)
#define  CRS_ISR_SYNCWARNF_Msk                    (0x1U << CRS_ISR_SYNCWARNF_Pos)                   /*!<*/
#define  CRS_ISR_SYNCWARNF                        CRS_ISR_SYNCWARNF_Msk
#define  CRS_ISR_ERRF_Pos                         (2)
#define  CRS_ISR_ERRF_Msk                         (0x1U << CRS_ISR_ERRF_Pos)                        /*!<*/
#define  CRS_ISR_ERRF                             CRS_ISR_ERRF_Msk
#define  CRS_ISR_ESYNCF_Pos                       (3)
#define  CRS_ISR_ESYNCF_Msk                       (0x1U << CRS_ISR_ESYNCF_Pos)                      /*!<*/
#define  CRS_ISR_ESYNCF                           CRS_ISR_ESYNCF_Msk
#define  CRS_ISR_SYNCERR_Pos                      (8)
#define  CRS_ISR_SYNCERR_Msk                      (0x1U << CRS_ISR_SYNCERR_Pos)                     /*!<*/
#define  CRS_ISR_SYNCERR                          CRS_ISR_SYNCERR_Msk
#define  CRS_ISR_SYNCMISS_Pos                     (9)
#define  CRS_ISR_SYNCMISS_Msk                     (0x1U << CRS_ISR_SYNCMISS_Pos)                    /*!<*/
#define  CRS_ISR_SYNCMISS                         CRS_ISR_SYNCMISS_Msk
#define  CRS_ISR_TRIMOVF_Pos                      (10)
#define  CRS_ISR_TRIMOVF_Msk                      (0x1U << CRS_ISR_TRIMOVF_Pos)                     /*!<*/
#define  CRS_ISR_TRIMOVF                          CRS_ISR_TRIMOVF_Msk
#define  CRS_ISR_FEDIR_Pos                        (15)
#define  CRS_ISR_FEDIR_Msk                        (0x1U << CRS_ISR_FEDIR_Pos)                       /*!<*/
#define  CRS_ISR_FEDIR                            CRS_ISR_FEDIR_Msk
#define  CRS_ISR_FECAP_Pos                        (16)
#define  CRS_ISR_FECAP_Msk                        (0xFFFFU << CRS_ISR_FECAP_Pos)                    /*!<*/
#define  CRS_ISR_FECAP                            CRS_ISR_FECAP_Msk
#define  CRS_ISR_FECAP_Bit0                       (0x0001U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit1                       (0x0002U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit2                       (0x0004U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit3                       (0x0008U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit4                       (0x0010U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit5                       (0x0020U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit6                       (0x0040U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit7                       (0x0080U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit8                       (0x0100U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit9                       (0x0200U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit10                      (0x0400U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit11                      (0x0800U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit12                      (0x1000U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit13                      (0x2000U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit14                      (0x4000U << CRS_ISR_FECAP_Pos) 
#define  CRS_ISR_FECAP_Bit15                      (0x8000U << CRS_ISR_FECAP_Pos) 

/**
  * @brief CRS_ICR Register Bit Definition
  */
#define  CRS_ICR_SYNCOKC_Pos                      (0)
#define  CRS_ICR_SYNCOKC_Msk                      (0x1U << CRS_ICR_SYNCOKC_Pos)                     /*!<*/
#define  CRS_ICR_SYNCOKC                          CRS_ICR_SYNCOKC_Msk
#define  CRS_ICR_SYNCWARNC_Pos                    (1)
#define  CRS_ICR_SYNCWARNC_Msk                    (0x1U << CRS_ICR_SYNCWARNC_Pos)                   /*!<*/
#define  CRS_ICR_SYNCWARNC                        CRS_ICR_SYNCWARNC_Msk
#define  CRS_ICR_ERRC_Pos                         (2)
#define  CRS_ICR_ERRC_Msk                         (0x1U << CRS_ICR_ERRC_Pos)                        /*!<*/
#define  CRS_ICR_ERRC                             CRS_ICR_ERRC_Msk
#define  CRS_ICR_ESYNCC_Pos                       (3)
#define  CRS_ICR_ESYNCC_Msk                       (0x1U << CRS_ICR_ESYNCC_Pos)                      /*!<*/
#define  CRS_ICR_ESYNCC                           CRS_ICR_ESYNCC_Msk


#endif

