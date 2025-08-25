/***********************************************************************************************************************
    @file     reg_crcpoly.h
    @author   VV TEAM
    @brief    This flie contains all the CRCPOLY's register and its field definition.
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

#ifndef __REG_CRCPOLY_H
#define __REG_CRCPOLY_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief CRCPOLY Base Address Definition
  */
#define  CRCPOLY_BASE                              0x40023000                                       /*!<Base Address: 0x40023000*/

/**
  * @brief CRCPOLY Register Structure Definition
  */
typedef struct
{
    __IO uint32_t DR;                             /*!<CRCPOLY CRC data register                      offset: 0x00       */
    __IO uint32_t IDR;                            /*!<CRCPOLY CRC independent data register          offset: 0x04       */
    __IO uint32_t CR;                             /*!<CRCPOLY CRC control register                   offset: 0x08       */
    __IO uint32_t IVR;                            /*!<CRCPOLY CRC initial value register             offset: 0x0C       */
    __IO uint32_t PR;                             /*!<CRCPOLY CRC polynomial register                offset: 0x10       */
} CRCPOLY_TypeDef;

/**
  * @brief CRCPOLY type pointer Definition
  */
#define CRCPOLY                                   ((CRCPOLY_TypeDef *)CRCPOLY_BASE)

/**
  * @brief CRCPOLY_DR Register Bit Definition
  */
#define  CRCPOLY_DR_DR_Pos                        (0)
#define  CRCPOLY_DR_DR_Msk                        (0xFFFFFFFFU << CRCPOLY_DR_DR_Pos)                /*!<Data register*/
#define  CRCPOLY_DR_DR                            CRCPOLY_DR_DR_Msk
#define  CRCPOLY_DR_DR_Bit0                       (0x00000001U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit1                       (0x00000002U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit2                       (0x00000004U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit3                       (0x00000008U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit4                       (0x00000010U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit5                       (0x00000020U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit6                       (0x00000040U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit7                       (0x00000080U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit8                       (0x00000100U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit9                       (0x00000200U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit10                      (0x00000400U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit11                      (0x00000800U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit12                      (0x00001000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit13                      (0x00002000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit14                      (0x00004000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit15                      (0x00008000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit16                      (0x00010000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit17                      (0x00020000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit18                      (0x00040000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit19                      (0x00080000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit20                      (0x00100000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit21                      (0x00200000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit22                      (0x00400000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit23                      (0x00800000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit24                      (0x01000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit25                      (0x02000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit26                      (0x04000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit27                      (0x08000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit28                      (0x10000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit29                      (0x20000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit30                      (0x40000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_Bit31                      (0x80000000U << CRCPOLY_DR_DR_Pos) 

/**
  * @brief CRCPOLY_IDR Register Bit Definition
  */
#define  CRCPOLY_IDR_IDR_Pos                      (0)
#define  CRCPOLY_IDR_IDR_Msk                      (0xFFFFFFFFU << CRCPOLY_IDR_IDR_Pos)              /*!<General-purpose 32-bit data register*/
#define  CRCPOLY_IDR_IDR                          CRCPOLY_IDR_IDR_Msk
#define  CRCPOLY_IDR_IDR_Bit0                     (0x00000001U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit1                     (0x00000002U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit2                     (0x00000004U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit3                     (0x00000008U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit4                     (0x00000010U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit5                     (0x00000020U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit6                     (0x00000040U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit7                     (0x00000080U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit8                     (0x00000100U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit9                     (0x00000200U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit10                    (0x00000400U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit11                    (0x00000800U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit12                    (0x00001000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit13                    (0x00002000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit14                    (0x00004000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit15                    (0x00008000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit16                    (0x00010000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit17                    (0x00020000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit18                    (0x00040000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit19                    (0x00080000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit20                    (0x00100000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit21                    (0x00200000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit22                    (0x00400000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit23                    (0x00800000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit24                    (0x01000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit25                    (0x02000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit26                    (0x04000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit27                    (0x08000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit28                    (0x10000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit29                    (0x20000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit30                    (0x40000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_Bit31                    (0x80000000U << CRCPOLY_IDR_IDR_Pos) 

/**
  * @brief CRCPOLY_CR Register Bit Definition
  */
#define  CRCPOLY_CR_RST_Pos                       (0)
#define  CRCPOLY_CR_RST_Msk                       (0x1U << CRCPOLY_CR_RST_Pos)                      /*!<Reset CRC calculation unit*/
#define  CRCPOLY_CR_RST                           CRCPOLY_CR_RST_Msk
#define  CRCPOLY_CR_RI_Pos                        (1)
#define  CRCPOLY_CR_RI_Msk                        (0x1U << CRCPOLY_CR_RI_Pos)                       /*!<Reverse input*/
#define  CRCPOLY_CR_RI                            CRCPOLY_CR_RI_Msk
#define  CRCPOLY_CR_BEI_Pos                       (4)
#define  CRCPOLY_CR_BEI_Msk                       (0x1U << CRCPOLY_CR_BEI_Pos)                      /*!<Big-endian /little-endian selection for input*/
#define  CRCPOLY_CR_BEI                           CRCPOLY_CR_BEI_Msk
#define  CRCPOLY_CR_BEO_Pos                       (5)
#define  CRCPOLY_CR_BEO_Msk                       (0x1U << CRCPOLY_CR_BEO_Pos)                      /*!<Big-endian /little-endian selection for output*/
#define  CRCPOLY_CR_BEO                           CRCPOLY_CR_BEO_Msk
#define  CRCPOLY_CR_RO_Pos                        (6)
#define  CRCPOLY_CR_RO_Msk                        (0x1U << CRCPOLY_CR_RO_Pos)                       /*!<Reverse output*/
#define  CRCPOLY_CR_RO                            CRCPOLY_CR_RO_Msk
#define  CRCPOLY_CR_PWIDTH_Pos                    (14)
#define  CRCPOLY_CR_PWIDTH_Msk                    (0x3U << CRCPOLY_CR_PWIDTH_Pos)                   /*!<Polynomial width*/
#define  CRCPOLY_CR_PWIDTH                        CRCPOLY_CR_PWIDTH_Msk
#define  CRCPOLY_CR_PWIDTH_Bit0                   (0x1U << CRCPOLY_CR_PWIDTH_Pos) 
#define  CRCPOLY_CR_PWIDTH_Bit1                   (0x2U << CRCPOLY_CR_PWIDTH_Pos) 

/**
  * @brief CRCPOLY_IVR Register Bit Definition
  */
#define  CRCPOLY_IVR_IVR_Pos                      (0)
#define  CRCPOLY_IVR_IVR_Msk                      (0xFFFFFFFFU << CRCPOLY_IVR_IVR_Pos)              /*!<Initial value register*/
#define  CRCPOLY_IVR_IVR                          CRCPOLY_IVR_IVR_Msk
#define  CRCPOLY_IVR_IVR_Bit0                     (0x00000001U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit1                     (0x00000002U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit2                     (0x00000004U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit3                     (0x00000008U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit4                     (0x00000010U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit5                     (0x00000020U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit6                     (0x00000040U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit7                     (0x00000080U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit8                     (0x00000100U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit9                     (0x00000200U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit10                    (0x00000400U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit11                    (0x00000800U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit12                    (0x00001000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit13                    (0x00002000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit14                    (0x00004000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit15                    (0x00008000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit16                    (0x00010000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit17                    (0x00020000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit18                    (0x00040000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit19                    (0x00080000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit20                    (0x00100000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit21                    (0x00200000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit22                    (0x00400000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit23                    (0x00800000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit24                    (0x01000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit25                    (0x02000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit26                    (0x04000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit27                    (0x08000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit28                    (0x10000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit29                    (0x20000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit30                    (0x40000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_Bit31                    (0x80000000U << CRCPOLY_IVR_IVR_Pos) 

/**
  * @brief CRCPOLY_PR Register Bit Definition
  */
#define  CRCPOLY_PR_IVR_Pos                       (0)
#define  CRCPOLY_PR_IVR_Msk                       (0xFFFFFFFFU << CRCPOLY_PR_IVR_Pos)               /*!<Polynomial register*/
#define  CRCPOLY_PR_IVR                           CRCPOLY_PR_IVR_Msk
#define  CRCPOLY_PR_IVR_Bit0                      (0x00000001U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit1                      (0x00000002U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit2                      (0x00000004U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit3                      (0x00000008U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit4                      (0x00000010U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit5                      (0x00000020U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit6                      (0x00000040U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit7                      (0x00000080U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit8                      (0x00000100U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit9                      (0x00000200U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit10                     (0x00000400U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit11                     (0x00000800U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit12                     (0x00001000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit13                     (0x00002000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit14                     (0x00004000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit15                     (0x00008000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit16                     (0x00010000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit17                     (0x00020000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit18                     (0x00040000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit19                     (0x00080000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit20                     (0x00100000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit21                     (0x00200000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit22                     (0x00400000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit23                     (0x00800000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit24                     (0x01000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit25                     (0x02000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit26                     (0x04000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit27                     (0x08000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit28                     (0x10000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit29                     (0x20000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit30                     (0x40000000U << CRCPOLY_PR_IVR_Pos) 
#define  CRCPOLY_PR_IVR_Bit31                     (0x80000000U << CRCPOLY_PR_IVR_Pos) 


#endif

