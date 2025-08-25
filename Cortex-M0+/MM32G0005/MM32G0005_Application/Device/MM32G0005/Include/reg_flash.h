/***********************************************************************************************************************
    @file     reg_flash.h
    @author   VV TEAM
    @brief    This flie contains all the FLASH's register and its field definition.
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

#ifndef __REG_FLASH_H
#define __REG_FLASH_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief FLASH Base Address Definition
  */
#define  FLASH_BASE                                0x40022000                                       /*!<Base Address: 0x40022000*/

/**
  * @brief FLASH Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ACR;                            /*!<FLASH Flash access control register            offset: 0x00       */
    __IO uint32_t KEYR;                           /*!<FLASH FPEC key register                        offset: 0x04       */
    __IO uint32_t OPTKEYR;                        /*!<FLASH Flash OPTKEY register                    offset: 0x08       */
    __IO uint32_t SR;                             /*!<FLASH Flash status register                    offset: 0x0C       */
    __IO uint32_t CR;                             /*!<FLASH Flash control register                   offset: 0x10       */
    __IO uint32_t AR;                             /*!<FLASH Flash address register                   offset: 0x14       */
    __IO uint32_t RESERVED0x18[1];                /*!<                                               offset: 0x18       */
    __IO uint32_t OBR;                            /*!<FLASH Option byte register                     offset: 0x1C       */
    __IO uint32_t WRPR;                           /*!<FLASH Write protection register                offset: 0x20       */
} FLASH_TypeDef;

/**
  * @brief FLASH type pointer Definition
  */
#define FLASH                                     ((FLASH_TypeDef *)FLASH_BASE)

/**
  * @brief FLASH_ACR Register Bit Definition
  */
#define  FLASH_ACR_LATENCY_Pos                    (0)
#define  FLASH_ACR_LATENCY_Msk                    (0x7U << FLASH_ACR_LATENCY_Pos)                   /*!<Latency*/
#define  FLASH_ACR_LATENCY                        FLASH_ACR_LATENCY_Msk
#define  FLASH_ACR_LATENCY_Bit0                   (0x1U << FLASH_ACR_LATENCY_Pos) 
#define  FLASH_ACR_LATENCY_Bit1                   (0x2U << FLASH_ACR_LATENCY_Pos) 
#define  FLASH_ACR_LATENCY_Bit2                   (0x4U << FLASH_ACR_LATENCY_Pos) 
#define  FLASH_ACR_PRFTBE_Pos                     (4)
#define  FLASH_ACR_PRFTBE_Msk                     (0x1U << FLASH_ACR_PRFTBE_Pos)                    /*!<Prefetch buffer enable*/
#define  FLASH_ACR_PRFTBE                         FLASH_ACR_PRFTBE_Msk
#define  FLASH_ACR_PRFTBS_Pos                     (5)
#define  FLASH_ACR_PRFTBS_Msk                     (0x1U << FLASH_ACR_PRFTBS_Pos)                    /*!<*/
#define  FLASH_ACR_PRFTBS                         FLASH_ACR_PRFTBS_Msk

/**
  * @brief FLASH_KEYR Register Bit Definition
  */
#define  FLASH_KEYR_FKEYR_Pos                     (0)
#define  FLASH_KEYR_FKEYR_Msk                     (0xFFFFFFFFU << FLASH_KEYR_FKEYR_Pos)             /*!<FPEC Flash key*/
#define  FLASH_KEYR_FKEYR                         FLASH_KEYR_FKEYR_Msk
#define  FLASH_KEYR_FKEYR_Bit0                    (0x00000001U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit1                    (0x00000002U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit2                    (0x00000004U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit3                    (0x00000008U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit4                    (0x00000010U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit5                    (0x00000020U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit6                    (0x00000040U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit7                    (0x00000080U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit8                    (0x00000100U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit9                    (0x00000200U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit10                   (0x00000400U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit11                   (0x00000800U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit12                   (0x00001000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit13                   (0x00002000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit14                   (0x00004000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit15                   (0x00008000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit16                   (0x00010000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit17                   (0x00020000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit18                   (0x00040000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit19                   (0x00080000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit20                   (0x00100000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit21                   (0x00200000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit22                   (0x00400000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit23                   (0x00800000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit24                   (0x01000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit25                   (0x02000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit26                   (0x04000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit27                   (0x08000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit28                   (0x10000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit29                   (0x20000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit30                   (0x40000000U << FLASH_KEYR_FKEYR_Pos) 
#define  FLASH_KEYR_FKEYR_Bit31                   (0x80000000U << FLASH_KEYR_FKEYR_Pos) 

/**
  * @brief FLASH_OPTKEYR Register Bit Definition
  */
#define  FLASH_OPTKEYR_OPTKEYR_Pos                (0)
#define  FLASH_OPTKEYR_OPTKEYR_Msk                (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_Pos)        /*!<Option byte key*/
#define  FLASH_OPTKEYR_OPTKEYR                    FLASH_OPTKEYR_OPTKEYR_Msk
#define  FLASH_OPTKEYR_OPTKEYR_Bit0               (0x00000001U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit1               (0x00000002U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit2               (0x00000004U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit3               (0x00000008U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit4               (0x00000010U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit5               (0x00000020U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit6               (0x00000040U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit7               (0x00000080U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit8               (0x00000100U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit9               (0x00000200U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit10              (0x00000400U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit11              (0x00000800U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit12              (0x00001000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit13              (0x00002000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit14              (0x00004000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit15              (0x00008000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit16              (0x00010000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit17              (0x00020000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit18              (0x00040000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit19              (0x00080000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit20              (0x00100000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit21              (0x00200000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit22              (0x00400000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit23              (0x00800000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit24              (0x01000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit25              (0x02000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit26              (0x04000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit27              (0x08000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit28              (0x10000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit29              (0x20000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit30              (0x40000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 
#define  FLASH_OPTKEYR_OPTKEYR_Bit31              (0x80000000U << FLASH_OPTKEYR_OPTKEYR_Pos) 

/**
  * @brief FLASH_SR Register Bit Definition
  */
#define  FLASH_SR_BSY_Pos                         (0)
#define  FLASH_SR_BSY_Msk                         (0x1U << FLASH_SR_BSY_Pos)                        /*!<Busy*/
#define  FLASH_SR_BSY                             FLASH_SR_BSY_Msk
#define  FLASH_SR_PGERR_Pos                       (2)
#define  FLASH_SR_PGERR_Msk                       (0x1U << FLASH_SR_PGERR_Pos)                      /*!<Programming error*/
#define  FLASH_SR_PGERR                           FLASH_SR_PGERR_Msk
#define  FLASH_SR_WRPRTERR_Pos                    (4)
#define  FLASH_SR_WRPRTERR_Msk                    (0x1U << FLASH_SR_WRPRTERR_Pos)                   /*!<Write protection error*/
#define  FLASH_SR_WRPRTERR                        FLASH_SR_WRPRTERR_Msk
#define  FLASH_SR_EOP_Pos                         (5)
#define  FLASH_SR_EOP_Msk                         (0x1U << FLASH_SR_EOP_Pos)                        /*!<End of operation*/
#define  FLASH_SR_EOP                             FLASH_SR_EOP_Msk

/**
  * @brief FLASH_CR Register Bit Definition
  */
#define  FLASH_CR_PG_Pos                          (0)
#define  FLASH_CR_PG_Msk                          (0x1U << FLASH_CR_PG_Pos)                         /*!<Programming*/
#define  FLASH_CR_PG                              FLASH_CR_PG_Msk
#define  FLASH_CR_PER_Pos                         (1)
#define  FLASH_CR_PER_Msk                         (0x1U << FLASH_CR_PER_Pos)                        /*!<Page erase*/
#define  FLASH_CR_PER                             FLASH_CR_PER_Msk
#define  FLASH_CR_MER_Pos                         (2)
#define  FLASH_CR_MER_Msk                         (0x1U << FLASH_CR_MER_Pos)                        /*!<Mass erase*/
#define  FLASH_CR_MER                             FLASH_CR_MER_Msk
#define  FLASH_CR_OPTPG_Pos                       (4)
#define  FLASH_CR_OPTPG_Msk                       (0x1U << FLASH_CR_OPTPG_Pos)                      /*!<Option byte programming*/
#define  FLASH_CR_OPTPG                           FLASH_CR_OPTPG_Msk
#define  FLASH_CR_OPTER_Pos                       (5)
#define  FLASH_CR_OPTER_Msk                       (0x1U << FLASH_CR_OPTER_Pos)                      /*!<Option byte erase*/
#define  FLASH_CR_OPTER                           FLASH_CR_OPTER_Msk
#define  FLASH_CR_STRT_Pos                        (6)
#define  FLASH_CR_STRT_Msk                        (0x1U << FLASH_CR_STRT_Pos)                       /*!<Start*/
#define  FLASH_CR_STRT                            FLASH_CR_STRT_Msk
#define  FLASH_CR_LOCK_Pos                        (7)
#define  FLASH_CR_LOCK_Msk                        (0x1U << FLASH_CR_LOCK_Pos)                       /*!<Lock*/
#define  FLASH_CR_LOCK                            FLASH_CR_LOCK_Msk
#define  FLASH_CR_OPTWRE_Pos                      (9)
#define  FLASH_CR_OPTWRE_Msk                      (0x1U << FLASH_CR_OPTWRE_Pos)                     /*!<Option byte write enable*/
#define  FLASH_CR_OPTWRE                          FLASH_CR_OPTWRE_Msk
#define  FLASH_CR_ERRIE_Pos                       (10)
#define  FLASH_CR_ERRIE_Msk                       (0x1U << FLASH_CR_ERRIE_Pos)                      /*!<Error interrupt enable*/
#define  FLASH_CR_ERRIE                           FLASH_CR_ERRIE_Msk
#define  FLASH_CR_EOPIE_Pos                       (12)
#define  FLASH_CR_EOPIE_Msk                       (0x1U << FLASH_CR_EOPIE_Pos)                      /*!<End of operation interrupt enable*/
#define  FLASH_CR_EOPIE                           FLASH_CR_EOPIE_Msk

/**
  * @brief FLASH_AR Register Bit Definition
  */
#define  FLASH_AR_FAR_Pos                         (0)
#define  FLASH_AR_FAR_Msk                         (0xFFFFFFFFU << FLASH_AR_FAR_Pos)                 /*!<Flash Address*/
#define  FLASH_AR_FAR                             FLASH_AR_FAR_Msk
#define  FLASH_AR_FAR_Bit0                        (0x00000001U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit1                        (0x00000002U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit2                        (0x00000004U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit3                        (0x00000008U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit4                        (0x00000010U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit5                        (0x00000020U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit6                        (0x00000040U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit7                        (0x00000080U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit8                        (0x00000100U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit9                        (0x00000200U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit10                       (0x00000400U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit11                       (0x00000800U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit12                       (0x00001000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit13                       (0x00002000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit14                       (0x00004000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit15                       (0x00008000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit16                       (0x00010000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit17                       (0x00020000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit18                       (0x00040000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit19                       (0x00080000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit20                       (0x00100000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit21                       (0x00200000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit22                       (0x00400000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit23                       (0x00800000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit24                       (0x01000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit25                       (0x02000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit26                       (0x04000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit27                       (0x08000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit28                       (0x10000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit29                       (0x20000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit30                       (0x40000000U << FLASH_AR_FAR_Pos) 
#define  FLASH_AR_FAR_Bit31                       (0x80000000U << FLASH_AR_FAR_Pos) 

/**
  * @brief FLASH_OBR Register Bit Definition
  */
#define  FLASH_OBR_OPTERR_Pos                     (0)
#define  FLASH_OBR_OPTERR_Msk                     (0x1U << FLASH_OBR_OPTERR_Pos)                    /*!<Option byte error*/
#define  FLASH_OBR_OPTERR                         FLASH_OBR_OPTERR_Msk
#define  FLASH_OBR_RDPRT_Pos                      (1)
#define  FLASH_OBR_RDPRT_Msk                      (0x1U << FLASH_OBR_RDPRT_Pos)                     /*!<Read protection level status*/
#define  FLASH_OBR_RDPRT                          FLASH_OBR_RDPRT_Msk
#define  FLASH_OBR_WDG_SW_Pos                     (2)
#define  FLASH_OBR_WDG_SW_Msk                     (0x1U << FLASH_OBR_WDG_SW_Pos)                    /*!<Select watchdog event*/
#define  FLASH_OBR_WDG_SW                         FLASH_OBR_WDG_SW_Msk
#define  FLASH_OBR_nRST_STOP_Pos                  (3)
#define  FLASH_OBR_nRST_STOP_Msk                  (0x1U << FLASH_OBR_nRST_STOP_Pos)                 /*!<Reset event in stop mode*/
#define  FLASH_OBR_nRST_STOP                      FLASH_OBR_nRST_STOP_Msk
#define  FLASH_OBR_Data0_Pos                      (10)
#define  FLASH_OBR_Data0_Msk                      (0xFFU << FLASH_OBR_Data0_Pos)                    /*!<Data0*/
#define  FLASH_OBR_Data0                          FLASH_OBR_Data0_Msk
#define  FLASH_OBR_Data0_Bit0                     (0x01U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit1                     (0x02U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit2                     (0x04U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit3                     (0x08U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit4                     (0x10U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit5                     (0x20U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit6                     (0x40U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data0_Bit7                     (0x80U << FLASH_OBR_Data0_Pos) 
#define  FLASH_OBR_Data1_Pos                      (18)
#define  FLASH_OBR_Data1_Msk                      (0xFFU << FLASH_OBR_Data1_Pos)                    /*!<Data1*/
#define  FLASH_OBR_Data1                          FLASH_OBR_Data1_Msk
#define  FLASH_OBR_Data1_Bit0                     (0x01U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit1                     (0x02U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit2                     (0x04U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit3                     (0x08U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit4                     (0x10U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit5                     (0x20U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit6                     (0x40U << FLASH_OBR_Data1_Pos) 
#define  FLASH_OBR_Data1_Bit7                     (0x80U << FLASH_OBR_Data1_Pos) 

/**
  * @brief FLASH_WRPR Register Bit Definition
  */
#define  FLASH_WRPR_WRP_Pos                       (0)
#define  FLASH_WRPR_WRP_Msk                       (0xFFFFU << FLASH_WRPR_WRP_Pos)                   /*!<Write protect*/
#define  FLASH_WRPR_WRP                           FLASH_WRPR_WRP_Msk
#define  FLASH_WRPR_WRP_Bit0                      (0x0001U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit1                      (0x0002U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit2                      (0x0004U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit3                      (0x0008U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit4                      (0x0010U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit5                      (0x0020U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit6                      (0x0040U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit7                      (0x0080U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit8                      (0x0100U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit9                      (0x0200U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit10                     (0x0400U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit11                     (0x0800U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit12                     (0x1000U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit13                     (0x2000U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit14                     (0x4000U << FLASH_WRPR_WRP_Pos) 
#define  FLASH_WRPR_WRP_Bit15                     (0x8000U << FLASH_WRPR_WRP_Pos) 


#endif

