/***********************************************************************************************************************
    @file     reg_trng.h
    @author   VV TEAM
    @brief    This flie contains all the TRNG's register and its field definition.
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

#ifndef __REG_TRNG_H
#define __REG_TRNG_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief TRNG Base Address Definition
  */
#define  TRNG_BASE                                 0x40015800                                       /*!<Base Address: 0x40015800*/

/**
  * @brief TRNG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<TRNG TRNG control register                     offset: 0x00       */
    __IO uint32_t SR;                             /*!<TRNG TRNG status register                      offset: 0x04       */
    __IO uint32_t INT;                            /*!<TRNG TRNG interrupt enable register            offset: 0x08       */
    __IO uint32_t RESERVED0x0C[1];                /*!<                                               offset: 0x0C       */
    __IO uint32_t DR;                             /*!<TRNG TRNG data register                        offset: 0x10       */
    __IO uint32_t SEED1;                          /*!<TRNG TRNG Temporary Seed Register 1            offset: 0x14       */
    __IO uint32_t SEED2;                          /*!<TRNG TRNG Temporary Seed Register 2            offset: 0x18       */
    __IO uint32_t SEED3;                          /*!<TRNG TRNG Temporary Seed Register 3            offset: 0x1C       */
} TRNG_TypeDef;

/**
  * @brief TRNG type pointer Definition
  */
#define TRNG                                      ((TRNG_TypeDef *)TRNG_BASE)

/**
  * @brief TRNG_CR Register Bit Definition
  */
#define  TRNG_CR_RECNTEN_Pos                      (0)
#define  TRNG_CR_RECNTEN_Msk                      (0x1U << TRNG_CR_RECNTEN_Pos)                     /*!<restart counter enable*/
#define  TRNG_CR_RECNTEN                          TRNG_CR_RECNTEN_Msk
#define  TRNG_CR_RINGEN_Pos                       (1)
#define  TRNG_CR_RINGEN_Msk                       (0x1U << TRNG_CR_RINGEN_Pos)                      /*!<ring enable*/
#define  TRNG_CR_RINGEN                           TRNG_CR_RINGEN_Msk
#define  TRNG_CR_NONLFS_Pos                       (28)
#define  TRNG_CR_NONLFS_Msk                       (0x1U << TRNG_CR_NONLFS_Pos)                      /*!<nonce_lfsr_select*/
#define  TRNG_CR_NONLFS                           TRNG_CR_NONLFS_Msk
#define  TRNG_CR_NONRESLD_Pos                     (29)
#define  TRNG_CR_NONRESLD_Msk                     (0x1U << TRNG_CR_NONRESLD_Pos)                    /*!<nonce_reseed_ld*/
#define  TRNG_CR_NONRESLD                         TRNG_CR_NONRESLD_Msk
#define  TRNG_CR_NONRES_Pos                       (30)
#define  TRNG_CR_NONRES_Msk                       (0x1U << TRNG_CR_NONRES_Pos)                      /*!<nonce_reseed*/
#define  TRNG_CR_NONRES                           TRNG_CR_NONRES_Msk
#define  TRNG_CR_RARES_Pos                        (31)
#define  TRNG_CR_RARES_Msk                        (0x1U << TRNG_CR_RARES_Pos)                       /*!<rand_reseed*/
#define  TRNG_CR_RARES                            TRNG_CR_RARES_Msk

/**
  * @brief TRNG_SR Register Bit Definition
  */
#define  TRNG_SR_DRDY_Pos                         (0)
#define  TRNG_SR_DRDY_Msk                         (0x1U << TRNG_SR_DRDY_Pos)                        /*!<Data ready*/
#define  TRNG_SR_DRDY                             TRNG_SR_DRDY_Msk

/**
  * @brief TRNG_INT Register Bit Definition
  */
#define  TRNG_INT_IE_Pos                          (0)
#define  TRNG_INT_IE_Msk                          (0x1U << TRNG_INT_IE_Pos)                         /*!<interrupt enable*/
#define  TRNG_INT_IE                              TRNG_INT_IE_Msk

/**
  * @brief TRNG_DR Register Bit Definition
  */
#define  TRNG_DR_DR_Pos                           (0)
#define  TRNG_DR_DR_Msk                           (0xFFFFFFFFU << TRNG_DR_DR_Pos)                   /*!<The 32-bit data written is used to set the temporary seed trngynonce_seed0. This seed software is unable to read the generated valid random number when the DRDY is valid in the TRANS_SR register*/
#define  TRNG_DR_DR                               TRNG_DR_DR_Msk
#define  TRNG_DR_DR_0                             (0x00000001U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_1                             (0x00000002U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_2                             (0x00000004U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_3                             (0x00000008U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_4                             (0x00000010U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_5                             (0x00000020U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_6                             (0x00000040U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_7                             (0x00000080U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_8                             (0x00000100U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_9                             (0x00000200U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_10                            (0x00000400U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_11                            (0x00000800U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_12                            (0x00001000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_13                            (0x00002000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_14                            (0x00004000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_15                            (0x00008000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_16                            (0x00010000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_17                            (0x00020000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_18                            (0x00040000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_19                            (0x00080000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_20                            (0x00100000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_21                            (0x00200000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_22                            (0x00400000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_23                            (0x00800000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_24                            (0x01000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_25                            (0x02000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_26                            (0x04000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_27                            (0x08000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_28                            (0x10000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_29                            (0x20000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_30                            (0x40000000U << TRNG_DR_DR_Pos) 
#define  TRNG_DR_DR_31                            (0x80000000U << TRNG_DR_DR_Pos) 

/**
  * @brief TRNG_SEED1 Register Bit Definition
  */
#define  TRNG_SEED1_NONCESEED1_Pos                (0)
#define  TRNG_SEED1_NONCESEED1_Msk                (0xFFFFFFFFU << TRNG_SEED1_NONCESEED1_Pos)        /*!<Write 32-bit data to generate temporary seeds.*/
#define  TRNG_SEED1_NONCESEED1                    TRNG_SEED1_NONCESEED1_Msk
#define  TRNG_SEED1_NONCESEED1_0                  (0x00000001U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_1                  (0x00000002U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_2                  (0x00000004U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_3                  (0x00000008U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_4                  (0x00000010U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_5                  (0x00000020U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_6                  (0x00000040U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_7                  (0x00000080U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_8                  (0x00000100U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_9                  (0x00000200U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_10                 (0x00000400U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_11                 (0x00000800U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_12                 (0x00001000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_13                 (0x00002000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_14                 (0x00004000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_15                 (0x00008000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_16                 (0x00010000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_17                 (0x00020000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_18                 (0x00040000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_19                 (0x00080000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_20                 (0x00100000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_21                 (0x00200000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_22                 (0x00400000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_23                 (0x00800000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_24                 (0x01000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_25                 (0x02000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_26                 (0x04000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_27                 (0x08000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_28                 (0x10000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_29                 (0x20000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_30                 (0x40000000U << TRNG_SEED1_NONCESEED1_Pos) 
#define  TRNG_SEED1_NONCESEED1_31                 (0x80000000U << TRNG_SEED1_NONCESEED1_Pos) 

/**
  * @brief TRNG_SEED2 Register Bit Definition
  */
#define  TRNG_SEED2_NONCESEED2_Pos                (0)
#define  TRNG_SEED2_NONCESEED2_Msk                (0xFFFFFFFFU << TRNG_SEED2_NONCESEED2_Pos)        /*!<Write 32-bit data to generate temporary seeds.*/
#define  TRNG_SEED2_NONCESEED2                    TRNG_SEED2_NONCESEED2_Msk
#define  TRNG_SEED2_NONCESEED2_0                  (0x00000001U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_1                  (0x00000002U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_2                  (0x00000004U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_3                  (0x00000008U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_4                  (0x00000010U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_5                  (0x00000020U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_6                  (0x00000040U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_7                  (0x00000080U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_8                  (0x00000100U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_9                  (0x00000200U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_10                 (0x00000400U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_11                 (0x00000800U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_12                 (0x00001000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_13                 (0x00002000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_14                 (0x00004000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_15                 (0x00008000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_16                 (0x00010000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_17                 (0x00020000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_18                 (0x00040000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_19                 (0x00080000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_20                 (0x00100000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_21                 (0x00200000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_22                 (0x00400000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_23                 (0x00800000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_24                 (0x01000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_25                 (0x02000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_26                 (0x04000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_27                 (0x08000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_28                 (0x10000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_29                 (0x20000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_30                 (0x40000000U << TRNG_SEED2_NONCESEED2_Pos) 
#define  TRNG_SEED2_NONCESEED2_31                 (0x80000000U << TRNG_SEED2_NONCESEED2_Pos) 

/**
  * @brief TRNG_SEED3 Register Bit Definition
  */
#define  TRNG_SEED3_NONCESEED3_Pos                (0)
#define  TRNG_SEED3_NONCESEED3_Msk                (0xFFFFFFFFU << TRNG_SEED3_NONCESEED3_Pos)        /*!<Write 32-bit data to generate temporary seeds.*/
#define  TRNG_SEED3_NONCESEED3                    TRNG_SEED3_NONCESEED3_Msk
#define  TRNG_SEED3_NONCESEED3_0                  (0x00000001U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_1                  (0x00000002U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_2                  (0x00000004U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_3                  (0x00000008U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_4                  (0x00000010U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_5                  (0x00000020U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_6                  (0x00000040U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_7                  (0x00000080U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_8                  (0x00000100U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_9                  (0x00000200U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_10                 (0x00000400U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_11                 (0x00000800U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_12                 (0x00001000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_13                 (0x00002000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_14                 (0x00004000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_15                 (0x00008000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_16                 (0x00010000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_17                 (0x00020000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_18                 (0x00040000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_19                 (0x00080000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_20                 (0x00100000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_21                 (0x00200000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_22                 (0x00400000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_23                 (0x00800000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_24                 (0x01000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_25                 (0x02000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_26                 (0x04000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_27                 (0x08000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_28                 (0x10000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_29                 (0x20000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_30                 (0x40000000U << TRNG_SEED3_NONCESEED3_Pos) 
#define  TRNG_SEED3_NONCESEED3_31                 (0x80000000U << TRNG_SEED3_NONCESEED3_Pos) 

#endif

