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
#include "core_starmc1.h"



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
    __IO uint32_t WRPR[4];                        /*!<FLASH Write protection register                offset: 0x20       */
    __IO uint32_t RESERVED0x30[20];               /*!<                                               offset: 0x30~0x7C  */
    __IO uint32_t BPRT;                           /*!<                                               offset: 0x80       */
    __IO uint32_t RESERVED0x84[47];               /*!<                                               offset: 0x84~0x13C */
    __IO uint32_t ECC_CR;                         /*!<                                               offset: 0x140      */
    __IO uint32_t ECC_PR;                         /*!<                                               offset: 0x144      */
    __IO uint32_t ECC_EER;                        /*!<                                               offset: 0x148      */
    __IO uint32_t ECC_SR;                         /*!<                                               offset: 0x14C      */
    __IO uint32_t ECC_ADDRR;                      /*!<                                               offset: 0x150      */
    __IO uint32_t ECC_SYNR;                       /*!<                                               offset: 0x154      */
    __IO uint32_t ECC_DLR;                        /*!<                                               offset: 0x158      */
    __IO uint32_t ECC_DHR;                        /*!<                                               offset: 0x15C      */
    __IO uint32_t RESERVED0x160[21];              /*!<                                               offset: 0x160~0x1B0*/
    __IO uint32_t CKS;                            /*!<                                               offset: 0x1B4      */
    __IO uint32_t BPTKEYR;                        /*!<                                               offset: 0x1B8      */
} FLASH_TypeDef;

/**
  * @brief FLASH type pointer Definition
  */
#define FLASH                                     ((FLASH_TypeDef *)FLASH_BASE)

/**
  * @brief FLASH_ACR Register Bit Definition
  */
#define  FLASH_ACR_LATENCY_Pos                    (0)
#define  FLASH_ACR_LATENCY_Msk                    (0x7U << FLASH_ACR_LATENCY_Pos)                   /*!<Latency These bits indicate the ratio of SYSCLK (system clock) period to Flash memory access time.*/
#define  FLASH_ACR_LATENCY                        FLASH_ACR_LATENCY_Msk
#define  FLASH_ACR_LATENCY_Bit0                   (0x1U << FLASH_ACR_LATENCY_Pos) 
#define  FLASH_ACR_LATENCY_Bit1                   (0x2U << FLASH_ACR_LATENCY_Pos) 
#define  FLASH_ACR_LATENCY_Bit2                   (0x4U << FLASH_ACR_LATENCY_Pos) 

/**
  * @brief FLASH_KEYR Register Bit Definition
  */
#define  FLASH_KEYR_FKEYR_Pos                     (0)
#define  FLASH_KEYR_FKEYR_Msk                     (0xFFFFFFFFU << FLASH_KEYR_FKEYR_Pos)             /*!<FPEC Flash key These bits are used to input FPEC unlock key*/
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
#define  FLASH_OPTKEYR_OPTKEYR_Msk                (0xFFFFFFFFU << FLASH_OPTKEYR_OPTKEYR_Pos)        /*!<Option byte key These bits are used as the input option byte key to disable OPTWRE.*/
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
#define  FLASH_SR_BSY_Msk                         (0x1U << FLASH_SR_BSY_Pos)                        /*!<Busy This bit indicates that the operation of Flash memory is in progress. Before Flash operation starts, this bit is set as'1'. After the operation or in case of an error, this bit is cleared as '0'.*/
#define  FLASH_SR_BSY                             FLASH_SR_BSY_Msk
#define  FLASH_SR_PGERR_Pos                       (2)
#define  FLASH_SR_PGERR_Msk                       (0x1U << FLASH_SR_PGERR_Pos)                      /*!<Programming error When an attempt is made to programme an address whose content is not '0x FFFF', the hardware sets this bit as as '1' and write '1' to clear the bit status Note: Prior to programming, clear the STRT bit of FLASH_CR register.*/
#define  FLASH_SR_PGERR                           FLASH_SR_PGERR_Msk
#define  FLASH_SR_WRPRTERR_Pos                    (4)
#define  FLASH_SR_WRPRTERR_Msk                    (0x1U << FLASH_SR_WRPRTERR_Pos)                   /*!<Write protection error When an attempt is made to programme the write-protected Flash memory address, the hardware sets this bit as '1' and write '1' to clear the bit status.*/
#define  FLASH_SR_WRPRTERR                        FLASH_SR_WRPRTERR_Msk
#define  FLASH_SR_EOP_Pos                         (5)
#define  FLASH_SR_EOP_Msk                         (0x1U << FLASH_SR_EOP_Pos)                        /*!<End of operation When the Flash memory operation (programming I erasing) is completed, the hardware sets this bit as '1' and write '1' to clear the bit status*/
#define  FLASH_SR_EOP                             FLASH_SR_EOP_Msk
#define  FLASH_SR_BSTERR_Pos                      (6)
#define  FLASH_SR_BSTERR_Msk                      (0x1U << FLASH_SR_BSTERR_Pos)                     /*!<*/
#define  FLASH_SR_BSTERR                          FLASH_SR_BSTERR_Msk

/**
  * @brief FLASH_CR Register Bit Definition
  */
#define  FLASH_CR_PG_Pos                          (0)
#define  FLASH_CR_PG_Msk                          (0x1U << FLASH_CR_PG_Pos)                         /*!<Programming Choose to conduct programming.*/
#define  FLASH_CR_PG                              FLASH_CR_PG_Msk
#define  FLASH_CR_PER_Pos                         (1)
#define  FLASH_CR_PER_Msk                         (0x1U << FLASH_CR_PER_Pos)                        /*!<Page erase Choose to erase page.*/
#define  FLASH_CR_PER                             FLASH_CR_PER_Msk
#define  FLASH_CR_MER_Pos                         (2)
#define  FLASH_CR_MER_Msk                         (0x1U << FLASH_CR_MER_Pos)                        /*!<Mass erase Choose to erase all user pages.*/
#define  FLASH_CR_MER                             FLASH_CR_MER_Msk
#define  FLASH_CR_OPTPG_Pos                       (4)
#define  FLASH_CR_OPTPG_Msk                       (0x1U << FLASH_CR_OPTPG_Pos)                      /*!<Programme option byte.*/
#define  FLASH_CR_OPTPG                           FLASH_CR_OPTPG_Msk
#define  FLASH_CR_OPTER_Pos                       (5)
#define  FLASH_CR_OPTER_Msk                       (0x1U << FLASH_CR_OPTER_Pos)                      /*!<Erase option byte.*/
#define  FLASH_CR_OPTER                           FLASH_CR_OPTER_Msk
#define  FLASH_CR_STRT_Pos                        (6)
#define  FLASH_CR_STRT_Msk                        (0x1U << FLASH_CR_STRT_Pos)                       /*!<Start An erasing is triggered when this bit is '1'. The bit can only be set to '1' by software and automatically be cleared to '0' when BSY turns into '1'.*/
#define  FLASH_CR_STRT                            FLASH_CR_STRT_Msk
#define  FLASH_CR_LOCK_Pos                        (7)
#define  FLASH_CR_LOCK_Msk                        (0x1U << FLASH_CR_LOCK_Pos)                       /*!<Lock Only write '1'. When the bit is '1', it indicates that FPEC and FLASH_CR are locked. When the correct unlocking sequence is detected, the hardware automatically clears this bit as '0'. After an unsuccessful unlocking operation, this bit cannot be changed before the next system reset.*/
#define  FLASH_CR_LOCK                            FLASH_CR_LOCK_Msk
#define  FLASH_CR_BPTERE_Pos                      (8)
#define  FLASH_CR_BPTERE_Msk                      (0x1U << FLASH_CR_BPTERE_Pos)                     /*!<*/
#define  FLASH_CR_BPTERE                          FLASH_CR_BPTERE_Msk
#define  FLASH_CR_OPTWRE_Pos                      (9)
#define  FLASH_CR_OPTWRE_Msk                      (0x1U << FLASH_CR_OPTWRE_Pos)                     /*!<*/
#define  FLASH_CR_OPTWRE                          FLASH_CR_OPTWRE_Msk
#define  FLASH_CR_ERRIE_Pos                       (10)
#define  FLASH_CR_ERRIE_Msk                       (0x1U << FLASH_CR_ERRIE_Pos)                      /*!<*/
#define  FLASH_CR_ERRIE                           FLASH_CR_ERRIE_Msk
#define  FLASH_CR_EOPIE_Pos                       (12)
#define  FLASH_CR_EOPIE_Msk                       (0x1U << FLASH_CR_EOPIE_Pos)                      /*!<*/
#define  FLASH_CR_EOPIE                           FLASH_CR_EOPIE_Msk
#define  FLASH_CR_PGMD_Pos                        (13)
#define  FLASH_CR_PGMD_Msk                        (0x7U << FLASH_CR_PGMD_Pos)                       /*!<*/
#define  FLASH_CR_PGMD                            FLASH_CR_PGMD_Msk
#define  FLASH_CR_PGMD_Bit0                       (0x1U << FLASH_CR_PGMD_Pos) 
#define  FLASH_CR_PGMD_Bit1                       (0x2U << FLASH_CR_PGMD_Pos) 
#define  FLASH_CR_PGMD_Bit2                       (0x4U << FLASH_CR_PGMD_Pos) 

/**
  * @brief FLASH_AR Register Bit Definition
  */
#define  FLASH_AR_FAR_Pos                         (0)
#define  FLASH_AR_FAR_Msk                         (0xFFFFFFFFU << FLASH_AR_FAR_Pos)                 /*!<Flash Address Select the page to be erased when performing page erasing. Note: When the BSY bit in FLASH_SR is '1', the register cannot be written.*/
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
#define  FLASH_OBR_OPTERR_Msk                     (0x1U << FLASH_OBR_OPTERR_Pos)                    /*!<Read protection level status When setting to '1' , it indicates that the Flash memory is read protected. Note: The bit is read-only.*/
#define  FLASH_OBR_OPTERR                         FLASH_OBR_OPTERR_Msk
#define  FLASH_OBR_RDPRT_Pos                      (1)
#define  FLASH_OBR_RDPRT_Msk                      (0x1U << FLASH_OBR_RDPRT_Pos)                     /*!<Read protection level status When setting to '1' , it indicates that the Flash memory is read protected. Note: The bit is read-only.*/
#define  FLASH_OBR_RDPRT                          FLASH_OBR_RDPRT_Msk
#define  FLASH_OBR_WDG_SW_Pos                     (2)
#define  FLASH_OBR_WDG_SW_Msk                     (0x1U << FLASH_OBR_WDG_SW_Pos)                    /*!<*/
#define  FLASH_OBR_WDG_SW                         FLASH_OBR_WDG_SW_Msk
#define  FLASH_OBR_nRST_STOP_Pos                  (3)
#define  FLASH_OBR_nRST_STOP_Msk                  (0x1U << FLASH_OBR_nRST_STOP_Pos)                 /*!<Reset event in stop mode*/
#define  FLASH_OBR_nRST_STOP                      FLASH_OBR_nRST_STOP_Msk
#define  FLASH_OBR_nRST_STANDBY_Pos               (4)
#define  FLASH_OBR_nRST_STANDBY_Msk               (0x1U << FLASH_OBR_nRST_STANDBY_Pos)              /*!<Reset event in standby mode*/
#define  FLASH_OBR_nRST_STANDBY                   FLASH_OBR_nRST_STANDBY_Msk
#define  FLASH_OBR_FLASH_ECCEN_Pos                (7)
#define  FLASH_OBR_FLASH_ECCEN_Msk                (0x1U << FLASH_OBR_FLASH_ECCEN_Pos)               /*!<*/
#define  FLASH_OBR_FLASH_ECCEN                    FLASH_OBR_FLASH_ECCEN_Msk
#define  FLASH_OBR_SRAM_ECCEN_Pos                 (8)
#define  FLASH_OBR_SRAM_ECCEN_Msk                 (0x1U << FLASH_OBR_SRAM_ECCEN_Pos)                /*!<*/
#define  FLASH_OBR_SRAM_ECCEN                     FLASH_OBR_SRAM_ECCEN_Msk
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
#define  FLASH_WRPR_WRP_Msk                       (0xFFFFU << FLASH_WRPR_WRP_Pos)                   /*!<Write protection The register includes the write protection option byte loaded by OBL.*/
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

/**
  * @brief FLASH_BPRT Register Bit Definition
  */
#define  FLASH_BPRT_BPRT_START_Pos                (0)
#define  FLASH_BPRT_BPRT_START_Msk                (0xFFFU << FLASH_BPRT_BPRT_START_Pos)             /*!<*/
#define  FLASH_BPRT_BPRT_START                    FLASH_BPRT_BPRT_START_Msk
#define  FLASH_BPRT_BPRT_START_Bit0               (0x001U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit1               (0x002U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit2               (0x004U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit3               (0x008U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit4               (0x010U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit5               (0x020U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit6               (0x040U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit7               (0x080U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit8               (0x100U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit9               (0x200U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit10              (0x400U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_START_Bit11              (0x800U << FLASH_BPRT_BPRT_START_Pos) 
#define  FLASH_BPRT_BPRT_END_Pos                  (16)
#define  FLASH_BPRT_BPRT_END_Msk                  (0xFFFU << FLASH_BPRT_BPRT_END_Pos)               /*!<*/
#define  FLASH_BPRT_BPRT_END                      FLASH_BPRT_BPRT_END_Msk
#define  FLASH_BPRT_BPRT_END_Bit0                 (0x001U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit1                 (0x002U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit2                 (0x004U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit3                 (0x008U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit4                 (0x010U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit5                 (0x020U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit6                 (0x040U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit7                 (0x080U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit8                 (0x100U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit9                 (0x200U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit10                (0x400U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_END_Bit11                (0x800U << FLASH_BPRT_BPRT_END_Pos) 
#define  FLASH_BPRT_BPRT_RDP_Pos                  (31)
#define  FLASH_BPRT_BPRT_RDP_Msk                  (0x1U << FLASH_BPRT_BPRT_RDP_Pos)                 /*!<*/
#define  FLASH_BPRT_BPRT_RDP                      FLASH_BPRT_BPRT_RDP_Msk

/**
  * @brief FLASH_ECC_CR Register Bit Definition
  */
#define  FLASH_ECC_CR_RERR_Pos                    (1)
#define  FLASH_ECC_CR_RERR_Msk                    (0x1U << FLASH_ECC_CR_RERR_Pos)                   /*!<*/
#define  FLASH_ECC_CR_RERR                        FLASH_ECC_CR_RERR_Msk

/**
  * @brief FLASH_ECC_PR Register Bit Definition
  */
#define  FLASH_ECC_PR_PRC_Pos                     (0)
#define  FLASH_ECC_PR_PRC_Msk                     (0x1U << FLASH_ECC_PR_PRC_Pos)                    /*!<*/
#define  FLASH_ECC_PR_PRC                         FLASH_ECC_PR_PRC_Msk

/**
  * @brief FLASH_ECC_EER Register Bit Definition
  */
#define  FLASH_ECC_EER_1BITIE_Pos                 (0)
#define  FLASH_ECC_EER_1BITIE_Msk                 (0x1U << FLASH_ECC_EER_1BITIE_Pos)                /*!<*/
#define  FLASH_ECC_EER_1BITIE                     FLASH_ECC_EER_1BITIE_Msk
#define  FLASH_ECC_EER_2BITIE_Pos                 (1)
#define  FLASH_ECC_EER_2BITIE_Msk                 (0x1U << FLASH_ECC_EER_2BITIE_Pos)                /*!<*/
#define  FLASH_ECC_EER_2BITIE                     FLASH_ECC_EER_2BITIE_Msk

/**
  * @brief FLASH_ECC_SR Register Bit Definition
  */
#define  FLASH_ECC_SR_1BITF_Pos                   (0)
#define  FLASH_ECC_SR_1BITF_Msk                   (0x1U << FLASH_ECC_SR_1BITF_Pos)                  /*!<*/
#define  FLASH_ECC_SR_1BITF                       FLASH_ECC_SR_1BITF_Msk
#define  FLASH_ECC_SR_2BITF_Pos                   (1)
#define  FLASH_ECC_SR_2BITF_Msk                   (0x1U << FLASH_ECC_SR_2BITF_Pos)                  /*!<*/
#define  FLASH_ECC_SR_2BITF                       FLASH_ECC_SR_2BITF_Msk

/**
  * @brief FLASH_ECC_ADDRR Register Bit Definition
  */
#define  FLASH_ECC_ADDRR_ADDR_Pos                 (0)
#define  FLASH_ECC_ADDRR_ADDR_Msk                 (0xFFFFFFFFU << FLASH_ECC_ADDRR_ADDR_Pos)         /*!<*/
#define  FLASH_ECC_ADDRR_ADDR                     FLASH_ECC_ADDRR_ADDR_Msk
#define  FLASH_ECC_ADDRR_ADDR_Bit0                (0x00000001U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit1                (0x00000002U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit2                (0x00000004U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit3                (0x00000008U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit4                (0x00000010U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit5                (0x00000020U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit6                (0x00000040U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit7                (0x00000080U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit8                (0x00000100U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit9                (0x00000200U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit10               (0x00000400U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit11               (0x00000800U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit12               (0x00001000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit13               (0x00002000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit14               (0x00004000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit15               (0x00008000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit16               (0x00010000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit17               (0x00020000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit18               (0x00040000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit19               (0x00080000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit20               (0x00100000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit21               (0x00200000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit22               (0x00400000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit23               (0x00800000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit24               (0x01000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit25               (0x02000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit26               (0x04000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit27               (0x08000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit28               (0x10000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit29               (0x20000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit30               (0x40000000U << FLASH_ECC_ADDRR_ADDR_Pos) 
#define  FLASH_ECC_ADDRR_ADDR_Bit31               (0x80000000U << FLASH_ECC_ADDRR_ADDR_Pos) 

/**
  * @brief FLASH_ECC_SYNR Register Bit Definition
  */
#define  FLASH_ECC_SYNR_SYN_Pos                   (0)
#define  FLASH_ECC_SYNR_SYN_Msk                   (0xFFU << FLASH_ECC_SYNR_SYN_Pos)                 /*!<*/
#define  FLASH_ECC_SYNR_SYN                       FLASH_ECC_SYNR_SYN_Msk
#define  FLASH_ECC_SYNR_SYN_Bit0                  (0x01U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit1                  (0x02U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit2                  (0x04U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit3                  (0x08U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit4                  (0x10U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit5                  (0x20U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit6                  (0x40U << FLASH_ECC_SYNR_SYN_Pos) 
#define  FLASH_ECC_SYNR_SYN_Bit7                  (0x80U << FLASH_ECC_SYNR_SYN_Pos) 

/**
  * @brief FLASH_ECC_DLR Register Bit Definition
  */
#define  FLASH_ECC_DLR_DATAL_Pos                  (0)
#define  FLASH_ECC_DLR_DATAL_Msk                  (0xFFFFFFFFU << FLASH_ECC_DLR_DATAL_Pos)          /*!<*/
#define  FLASH_ECC_DLR_DATAL                      FLASH_ECC_DLR_DATAL_Msk
#define  FLASH_ECC_DLR_DATAL_Bit0                 (0x00000001U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit1                 (0x00000002U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit2                 (0x00000004U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit3                 (0x00000008U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit4                 (0x00000010U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit5                 (0x00000020U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit6                 (0x00000040U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit7                 (0x00000080U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit8                 (0x00000100U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit9                 (0x00000200U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit10                (0x00000400U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit11                (0x00000800U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit12                (0x00001000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit13                (0x00002000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit14                (0x00004000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit15                (0x00008000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit16                (0x00010000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit17                (0x00020000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit18                (0x00040000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit19                (0x00080000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit20                (0x00100000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit21                (0x00200000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit22                (0x00400000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit23                (0x00800000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit24                (0x01000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit25                (0x02000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit26                (0x04000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit27                (0x08000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit28                (0x10000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit29                (0x20000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit30                (0x40000000U << FLASH_ECC_DLR_DATAL_Pos) 
#define  FLASH_ECC_DLR_DATAL_Bit31                (0x80000000U << FLASH_ECC_DLR_DATAL_Pos) 

/**
  * @brief FLASH_ECC_DHR Register Bit Definition
  */
#define  FLASH_ECC_DHR_DATAH_Pos                  (0)
#define  FLASH_ECC_DHR_DATAH_Msk                  (0xFFFFFFFFU << FLASH_ECC_DHR_DATAH_Pos)          /*!<*/
#define  FLASH_ECC_DHR_DATAH                      FLASH_ECC_DHR_DATAH_Msk
#define  FLASH_ECC_DHR_DATAH_Bit0                 (0x00000001U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit1                 (0x00000002U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit2                 (0x00000004U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit3                 (0x00000008U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit4                 (0x00000010U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit5                 (0x00000020U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit6                 (0x00000040U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit7                 (0x00000080U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit8                 (0x00000100U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit9                 (0x00000200U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit10                (0x00000400U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit11                (0x00000800U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit12                (0x00001000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit13                (0x00002000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit14                (0x00004000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit15                (0x00008000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit16                (0x00010000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit17                (0x00020000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit18                (0x00040000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit19                (0x00080000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit20                (0x00100000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit21                (0x00200000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit22                (0x00400000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit23                (0x00800000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit24                (0x01000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit25                (0x02000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit26                (0x04000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit27                (0x08000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit28                (0x10000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit29                (0x20000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit30                (0x40000000U << FLASH_ECC_DHR_DATAH_Pos) 
#define  FLASH_ECC_DHR_DATAH_Bit31                (0x80000000U << FLASH_ECC_DHR_DATAH_Pos) 

/**
  * @brief FLASH_CKS Register Bit Definition
  */
#define  FLASH_CKS_DIV_Pos                        (0)
#define  FLASH_CKS_DIV_Msk                        (0x3FU << FLASH_CKS_DIV_Pos)                      /*!<*/
#define  FLASH_CKS_DIV                            FLASH_CKS_DIV_Msk
#define  FLASH_CKS_DIV_Bit0                       (0x01U << FLASH_CKS_DIV_Pos) 
#define  FLASH_CKS_DIV_Bit1                       (0x02U << FLASH_CKS_DIV_Pos) 
#define  FLASH_CKS_DIV_Bit2                       (0x04U << FLASH_CKS_DIV_Pos) 
#define  FLASH_CKS_DIV_Bit3                       (0x08U << FLASH_CKS_DIV_Pos) 
#define  FLASH_CKS_DIV_Bit4                       (0x10U << FLASH_CKS_DIV_Pos) 
#define  FLASH_CKS_DIV_Bit5                       (0x20U << FLASH_CKS_DIV_Pos) 
#define  FLASH_CKS_CSEL_Pos                       (6)
#define  FLASH_CKS_CSEL_Msk                       (0x1U << FLASH_CKS_CSEL_Pos)                      /*!<*/
#define  FLASH_CKS_CSEL                           FLASH_CKS_CSEL_Msk

/**
  * @brief FLASH_BPTKEYR Register Bit Definition
  */
#define  FLASH_BPTKEYR_BPTKEYR_Pos                (0)
#define  FLASH_BPTKEYR_BPTKEYR_Msk                (0xFFFFFFFFU << FLASH_BPTKEYR_BPTKEYR_Pos)        /*!<*/
#define  FLASH_BPTKEYR_BPTKEYR                    FLASH_BPTKEYR_BPTKEYR_Msk
#define  FLASH_BPTKEYR_BPTKEYR_Bit0               (0x00000001U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit1               (0x00000002U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit2               (0x00000004U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit3               (0x00000008U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit4               (0x00000010U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit5               (0x00000020U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit6               (0x00000040U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit7               (0x00000080U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit8               (0x00000100U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit9               (0x00000200U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit10              (0x00000400U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit11              (0x00000800U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit12              (0x00001000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit13              (0x00002000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit14              (0x00004000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit15              (0x00008000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit16              (0x00010000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit17              (0x00020000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit18              (0x00040000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit19              (0x00080000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit20              (0x00100000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit21              (0x00200000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit22              (0x00400000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit23              (0x00800000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit24              (0x01000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit25              (0x02000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit26              (0x04000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit27              (0x08000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit28              (0x10000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit29              (0x20000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit30              (0x40000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 
#define  FLASH_BPTKEYR_BPTKEYR_Bit31              (0x80000000U << FLASH_BPTKEYR_BPTKEYR_Pos) 


#endif

