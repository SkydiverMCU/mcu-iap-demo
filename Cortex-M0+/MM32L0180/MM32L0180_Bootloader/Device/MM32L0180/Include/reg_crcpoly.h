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
#include <core_cm0plus.h>



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
#define  CRCPOLY_DR_DR_0                          (0x00000001U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_1                          (0x00000002U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_2                          (0x00000004U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_3                          (0x00000008U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_4                          (0x00000010U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_5                          (0x00000020U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_6                          (0x00000040U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_7                          (0x00000080U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_8                          (0x00000100U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_9                          (0x00000200U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_10                         (0x00000400U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_11                         (0x00000800U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_12                         (0x00001000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_13                         (0x00002000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_14                         (0x00004000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_15                         (0x00008000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_16                         (0x00010000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_17                         (0x00020000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_18                         (0x00040000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_19                         (0x00080000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_20                         (0x00100000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_21                         (0x00200000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_22                         (0x00400000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_23                         (0x00800000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_24                         (0x01000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_25                         (0x02000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_26                         (0x04000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_27                         (0x08000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_28                         (0x10000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_29                         (0x20000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_30                         (0x40000000U << CRCPOLY_DR_DR_Pos) 
#define  CRCPOLY_DR_DR_31                         (0x80000000U << CRCPOLY_DR_DR_Pos) 

/**
  * @brief CRCPOLY_IDR Register Bit Definition
  */
#define  CRCPOLY_IDR_IDR_Pos                      (0)
#define  CRCPOLY_IDR_IDR_Msk                      (0xFFFFFFFFU << CRCPOLY_IDR_IDR_Pos)              /*!<General-purpose 32-bit data register*/
#define  CRCPOLY_IDR_IDR                          CRCPOLY_IDR_IDR_Msk
#define  CRCPOLY_IDR_IDR_0                        (0x00000001U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_1                        (0x00000002U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_2                        (0x00000004U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_3                        (0x00000008U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_4                        (0x00000010U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_5                        (0x00000020U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_6                        (0x00000040U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_7                        (0x00000080U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_8                        (0x00000100U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_9                        (0x00000200U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_10                       (0x00000400U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_11                       (0x00000800U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_12                       (0x00001000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_13                       (0x00002000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_14                       (0x00004000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_15                       (0x00008000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_16                       (0x00010000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_17                       (0x00020000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_18                       (0x00040000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_19                       (0x00080000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_20                       (0x00100000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_21                       (0x00200000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_22                       (0x00400000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_23                       (0x00800000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_24                       (0x01000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_25                       (0x02000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_26                       (0x04000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_27                       (0x08000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_28                       (0x10000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_29                       (0x20000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_30                       (0x40000000U << CRCPOLY_IDR_IDR_Pos) 
#define  CRCPOLY_IDR_IDR_31                       (0x80000000U << CRCPOLY_IDR_IDR_Pos) 

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
#define  CRCPOLY_CR_BEI_Msk                       (0x1U << CRCPOLY_CR_BEI_Pos)                      /*!<Big-endian input*/
#define  CRCPOLY_CR_BEI                           CRCPOLY_CR_BEI_Msk
#define  CRCPOLY_CR_BEO_Pos                       (5)
#define  CRCPOLY_CR_BEO_Msk                       (0x1U << CRCPOLY_CR_BEO_Pos)                      /*!<Big-endian output*/
#define  CRCPOLY_CR_BEO                           CRCPOLY_CR_BEO_Msk
#define  CRCPOLY_CR_RO_Pos                        (6)
#define  CRCPOLY_CR_RO_Msk                        (0x1U << CRCPOLY_CR_RO_Pos)                       /*!<Reverse output*/
#define  CRCPOLY_CR_RO                            CRCPOLY_CR_RO_Msk
#define  CRCPOLY_CR_PWIDTH_Pos                    (14)
#define  CRCPOLY_CR_PWIDTH_Msk                    (0x3U << CRCPOLY_CR_PWIDTH_Pos)                   /*!<Polynomial width*/
#define  CRCPOLY_CR_PWIDTH                        CRCPOLY_CR_PWIDTH_Msk
#define  CRCPOLY_CR_PWIDTH_0                      (0x1U << CRCPOLY_CR_PWIDTH_Pos) 
#define  CRCPOLY_CR_PWIDTH_1                      (0x2U << CRCPOLY_CR_PWIDTH_Pos) 

/**
  * @brief CRCPOLY_IVR Register Bit Definition
  */
#define  CRCPOLY_IVR_IVR_Pos                      (0)
#define  CRCPOLY_IVR_IVR_Msk                      (0xFFFFFFFFU << CRCPOLY_IVR_IVR_Pos)              /*!<Initial value register*/
#define  CRCPOLY_IVR_IVR                          CRCPOLY_IVR_IVR_Msk
#define  CRCPOLY_IVR_IVR_0                        (0x00000001U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_1                        (0x00000002U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_2                        (0x00000004U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_3                        (0x00000008U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_4                        (0x00000010U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_5                        (0x00000020U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_6                        (0x00000040U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_7                        (0x00000080U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_8                        (0x00000100U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_9                        (0x00000200U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_10                       (0x00000400U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_11                       (0x00000800U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_12                       (0x00001000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_13                       (0x00002000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_14                       (0x00004000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_15                       (0x00008000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_16                       (0x00010000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_17                       (0x00020000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_18                       (0x00040000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_19                       (0x00080000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_20                       (0x00100000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_21                       (0x00200000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_22                       (0x00400000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_23                       (0x00800000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_24                       (0x01000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_25                       (0x02000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_26                       (0x04000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_27                       (0x08000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_28                       (0x10000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_29                       (0x20000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_30                       (0x40000000U << CRCPOLY_IVR_IVR_Pos) 
#define  CRCPOLY_IVR_IVR_31                       (0x80000000U << CRCPOLY_IVR_IVR_Pos) 

/**
  * @brief CRCPOLY_PR Register Bit Definition
  */
#define  CRCPOLY_PR_PR_Pos                        (0)
#define  CRCPOLY_PR_PR_Msk                        (0xFFFFFFFFU << CRCPOLY_PR_PR_Pos)                /*!<Polynomial register*/
#define  CRCPOLY_PR_PR                            CRCPOLY_PR_PR_Msk
#define  CRCPOLY_PR_PR_0                          (0x00000001U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_1                          (0x00000002U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_2                          (0x00000004U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_3                          (0x00000008U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_4                          (0x00000010U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_5                          (0x00000020U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_6                          (0x00000040U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_7                          (0x00000080U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_8                          (0x00000100U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_9                          (0x00000200U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_10                         (0x00000400U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_11                         (0x00000800U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_12                         (0x00001000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_13                         (0x00002000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_14                         (0x00004000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_15                         (0x00008000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_16                         (0x00010000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_17                         (0x00020000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_18                         (0x00040000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_19                         (0x00080000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_20                         (0x00100000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_21                         (0x00200000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_22                         (0x00400000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_23                         (0x00800000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_24                         (0x01000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_25                         (0x02000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_26                         (0x04000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_27                         (0x08000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_28                         (0x10000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_29                         (0x20000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_30                         (0x40000000U << CRCPOLY_PR_PR_Pos) 
#define  CRCPOLY_PR_PR_31                         (0x80000000U << CRCPOLY_PR_PR_Pos) 

#endif

