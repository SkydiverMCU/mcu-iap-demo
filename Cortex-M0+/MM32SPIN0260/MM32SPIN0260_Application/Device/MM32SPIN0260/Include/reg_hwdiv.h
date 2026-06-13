/***********************************************************************************************************************
    @file     reg_hwdiv.h
    @author   FD TEAM
    @brief    This flie contains all the HWDIV's register and its field definition.
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

#ifndef __REG_HWDIV_H
#define __REG_HWDIV_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief HWDIV Base Address Definition
  */
#define  HWDIV_BASE                                0x40030000                                       /*!<Base Address: 0x40030000*/

/**
  * @brief HWDIV Register Structure Definition
  */
typedef struct
{
    __IO uint32_t DVDR;                           /*!<HWDIV Dividend register                        offset: 0x00       */
    __IO uint32_t DVSR;                           /*!<HWDIV Divisor register                         offset: 0x04       */
    __IO uint32_t QUOTR;                          /*!<HWDIV Quotient register                        offset: 0x08       */
    __IO uint32_t RMDR;                           /*!<HWDIV Remainder register                       offset: 0x0C       */
    __IO uint32_t SR;                             /*!<HWDIV Status register                          offset: 0x10       */
    __IO uint32_t CR;                             /*!<HWDIV Control register                         offset: 0x14       */
} HWDIV_TypeDef;

/**
  * @brief HWDIV type pointer Definition
  */
#define HWDIV                                     ((HWDIV_TypeDef *)HWDIV_BASE)

/**
  * @brief HWDIV_DVDR Register Bit Definition
  */
#define  HWDIV_DVDR_DIVIDEND_Pos                  (0)
#define  HWDIV_DVDR_DIVIDEND_Msk                  (0xFFFFFFFFU << HWDIV_DVDR_DIVIDEND_Pos)          /*!<Dividend data*/
#define  HWDIV_DVDR_DIVIDEND                      HWDIV_DVDR_DIVIDEND_Msk
#define  HWDIV_DVDR_DIVIDEND_Bit0                 (0x00000001U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit1                 (0x00000002U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit2                 (0x00000004U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit3                 (0x00000008U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit4                 (0x00000010U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit5                 (0x00000020U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit6                 (0x00000040U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit7                 (0x00000080U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit8                 (0x00000100U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit9                 (0x00000200U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit10                (0x00000400U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit11                (0x00000800U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit12                (0x00001000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit13                (0x00002000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit14                (0x00004000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit15                (0x00008000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit16                (0x00010000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit17                (0x00020000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit18                (0x00040000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit19                (0x00080000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit20                (0x00100000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit21                (0x00200000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit22                (0x00400000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit23                (0x00800000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit24                (0x01000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit25                (0x02000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit26                (0x04000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit27                (0x08000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit28                (0x10000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit29                (0x20000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit30                (0x40000000U << HWDIV_DVDR_DIVIDEND_Pos) 
#define  HWDIV_DVDR_DIVIDEND_Bit31                (0x80000000U << HWDIV_DVDR_DIVIDEND_Pos) 

/**
  * @brief HWDIV_DVSR Register Bit Definition
  */
#define  HWDIV_DVSR_DIVISOR_Pos                   (0)
#define  HWDIV_DVSR_DIVISOR_Msk                   (0xFFFFFFFFU << HWDIV_DVSR_DIVISOR_Pos)           /*!<Each time the divisor register (Divisor data) is written, the division operation is automatically triggered.*/
#define  HWDIV_DVSR_DIVISOR                       HWDIV_DVSR_DIVISOR_Msk
#define  HWDIV_DVSR_DIVISOR_Bit0                  (0x00000001U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit1                  (0x00000002U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit2                  (0x00000004U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit3                  (0x00000008U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit4                  (0x00000010U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit5                  (0x00000020U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit6                  (0x00000040U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit7                  (0x00000080U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit8                  (0x00000100U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit9                  (0x00000200U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit10                 (0x00000400U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit11                 (0x00000800U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit12                 (0x00001000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit13                 (0x00002000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit14                 (0x00004000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit15                 (0x00008000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit16                 (0x00010000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit17                 (0x00020000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit18                 (0x00040000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit19                 (0x00080000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit20                 (0x00100000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit21                 (0x00200000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit22                 (0x00400000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit23                 (0x00800000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit24                 (0x01000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit25                 (0x02000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit26                 (0x04000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit27                 (0x08000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit28                 (0x10000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit29                 (0x20000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit30                 (0x40000000U << HWDIV_DVSR_DIVISOR_Pos) 
#define  HWDIV_DVSR_DIVISOR_Bit31                 (0x80000000U << HWDIV_DVSR_DIVISOR_Pos) 

/**
  * @brief HWDIV_QUOTR Register Bit Definition
  */
#define  HWDIV_QUOTR_QUOTIENT_Pos                 (0)
#define  HWDIV_QUOTR_QUOTIENT_Msk                 (0xFFFFFFFFU << HWDIV_QUOTR_QUOTIENT_Pos)         /*!<Quotient data*/
#define  HWDIV_QUOTR_QUOTIENT                     HWDIV_QUOTR_QUOTIENT_Msk
#define  HWDIV_QUOTR_QUOTIENT_Bit0                (0x00000001U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit1                (0x00000002U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit2                (0x00000004U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit3                (0x00000008U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit4                (0x00000010U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit5                (0x00000020U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit6                (0x00000040U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit7                (0x00000080U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit8                (0x00000100U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit9                (0x00000200U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit10               (0x00000400U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit11               (0x00000800U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit12               (0x00001000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit13               (0x00002000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit14               (0x00004000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit15               (0x00008000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit16               (0x00010000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit17               (0x00020000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit18               (0x00040000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit19               (0x00080000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit20               (0x00100000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit21               (0x00200000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit22               (0x00400000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit23               (0x00800000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit24               (0x01000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit25               (0x02000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit26               (0x04000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit27               (0x08000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit28               (0x10000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit29               (0x20000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit30               (0x40000000U << HWDIV_QUOTR_QUOTIENT_Pos) 
#define  HWDIV_QUOTR_QUOTIENT_Bit31               (0x80000000U << HWDIV_QUOTR_QUOTIENT_Pos) 

/**
  * @brief HWDIV_RMDR Register Bit Definition
  */
#define  HWDIV_RMDR_REMAINDER_Pos                 (0)
#define  HWDIV_RMDR_REMAINDER_Msk                 (0xFFFFFFFFU << HWDIV_RMDR_REMAINDER_Pos)         /*!<Remainder data*/
#define  HWDIV_RMDR_REMAINDER                     HWDIV_RMDR_REMAINDER_Msk
#define  HWDIV_RMDR_REMAINDER_Bit0                (0x00000001U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit1                (0x00000002U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit2                (0x00000004U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit3                (0x00000008U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit4                (0x00000010U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit5                (0x00000020U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit6                (0x00000040U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit7                (0x00000080U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit8                (0x00000100U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit9                (0x00000200U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit10               (0x00000400U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit11               (0x00000800U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit12               (0x00001000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit13               (0x00002000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit14               (0x00004000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit15               (0x00008000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit16               (0x00010000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit17               (0x00020000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit18               (0x00040000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit19               (0x00080000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit20               (0x00100000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit21               (0x00200000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit22               (0x00400000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit23               (0x00800000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit24               (0x01000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit25               (0x02000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit26               (0x04000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit27               (0x08000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit28               (0x10000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit29               (0x20000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit30               (0x40000000U << HWDIV_RMDR_REMAINDER_Pos) 
#define  HWDIV_RMDR_REMAINDER_Bit31               (0x80000000U << HWDIV_RMDR_REMAINDER_Pos) 

/**
  * @brief HWDIV_SR Register Bit Definition
  */
#define  HWDIV_SR_OVF_Pos                         (0)
#define  HWDIV_SR_OVF_Msk                         (0x1U << HWDIV_SR_OVF_Pos)                        /*!<Overflow flag bit is cleared by writing 1 in the software during the next division operation*/
#define  HWDIV_SR_OVF                             HWDIV_SR_OVF_Msk

/**
  * @brief HWDIV_CR Register Bit Definition
  */
#define  HWDIV_CR_USIGN_Pos                       (0)
#define  HWDIV_CR_USIGN_Msk                       (0x1U << HWDIV_CR_USIGN_Pos)                      /*!<Unsigned enable*/
#define  HWDIV_CR_USIGN                           HWDIV_CR_USIGN_Msk
#define  HWDIV_CR_OVFE_Pos                        (1)
#define  HWDIV_CR_OVFE_Msk                        (0x1U << HWDIV_CR_OVFE_Pos)                       /*!<Overflow interrupt enable*/
#define  HWDIV_CR_OVFE                            HWDIV_CR_OVFE_Msk


#endif

