/***********************************************************************************************************************
    @file     reg_sram.h
    @author   VV TEAM
    @brief    This flie contains all the SRAM's register and its field definition.
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

#ifndef __REG_SRAM_H
#define __REG_SRAM_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief SRAM Base Address Definition
  */
#define  SRAM_BASE                                 0x4002B000                                       /*!<Base Address: 0x4002B000*/

/**
  * @brief SRAM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CFGR1;                          /*!<                                               offset: 0x00       */
    __IO uint32_t CFGR2;                          /*!<                                               offset: 0x04       */
    __IO uint32_t RESERVED0x08[1];                /*!<                                               offset: 0x08       */
    __IO uint32_t BKPRAM;                         /*!<                                               offset: 0x0C       */
    __IO uint32_t RESERVED0x10[12];               /*!<                                               offset: 0x10~0x3C  */
    __IO uint32_t ECCCR;                          /*!<                                               offset: 0x40       */
    __IO uint32_t ECCEINR0;                       /*!<                                               offset: 0x44       */
    __IO uint32_t ECCEINR1;                       /*!<                                               offset: 0x48       */
    __IO uint32_t ECCSR;                          /*!<                                               offset: 0x4C       */
    __IO uint32_t ECCEADRR;                       /*!<                                               offset: 0x50       */
    __IO uint32_t RESERVED0x54[11];               /*!<                                               offset: 0x54~0x7C  */
    __IO uint32_t ECCESYNR;                       /*!<                                               offset: 0x80       */
    __IO uint32_t ECCEDATAR;                      /*!<                                               offset: 0x84       */
} SRAM_TypeDef;

/**
  * @brief SRAM type pointer Definition
  */
#define SRAM                                      ((SRAM_TypeDef *)SRAM_BASE)

/**
  * @brief SRAM_CFGR1 Register Bit Definition
  */
#define  SRAM_CFGR1_RD_LAT_Pos                    (0)
#define  SRAM_CFGR1_RD_LAT_Msk                    (0x7U << SRAM_CFGR1_RD_LAT_Pos)                   /*!<*/
#define  SRAM_CFGR1_RD_LAT                        SRAM_CFGR1_RD_LAT_Msk
#define  SRAM_CFGR1_RD_LAT_Bit0                   (0x1U << SRAM_CFGR1_RD_LAT_Pos) 
#define  SRAM_CFGR1_RD_LAT_Bit1                   (0x2U << SRAM_CFGR1_RD_LAT_Pos) 
#define  SRAM_CFGR1_RD_LAT_Bit2                   (0x4U << SRAM_CFGR1_RD_LAT_Pos) 
#define  SRAM_CFGR1_WR_WT_Pos                     (3)
#define  SRAM_CFGR1_WR_WT_Msk                     (0x7U << SRAM_CFGR1_WR_WT_Pos)                    /*!<*/
#define  SRAM_CFGR1_WR_WT                         SRAM_CFGR1_WR_WT_Msk
#define  SRAM_CFGR1_WR_WT_Bit0                    (0x1U << SRAM_CFGR1_WR_WT_Pos) 
#define  SRAM_CFGR1_WR_WT_Bit1                    (0x2U << SRAM_CFGR1_WR_WT_Pos) 
#define  SRAM_CFGR1_WR_WT_Bit2                    (0x4U << SRAM_CFGR1_WR_WT_Pos) 

/**
  * @brief SRAM_CFGR2 Register Bit Definition
  */
#define  SRAM_CFGR2_RD_LAT_Pos                    (0)
#define  SRAM_CFGR2_RD_LAT_Msk                    (0x7U << SRAM_CFGR2_RD_LAT_Pos)                   /*!<*/
#define  SRAM_CFGR2_RD_LAT                        SRAM_CFGR2_RD_LAT_Msk
#define  SRAM_CFGR2_RD_LAT_Bit0                   (0x1U << SRAM_CFGR2_RD_LAT_Pos) 
#define  SRAM_CFGR2_RD_LAT_Bit1                   (0x2U << SRAM_CFGR2_RD_LAT_Pos) 
#define  SRAM_CFGR2_RD_LAT_Bit2                   (0x4U << SRAM_CFGR2_RD_LAT_Pos) 
#define  SRAM_CFGR2_WR_WT_Pos                     (3)
#define  SRAM_CFGR2_WR_WT_Msk                     (0x7U << SRAM_CFGR2_WR_WT_Pos)                    /*!<*/
#define  SRAM_CFGR2_WR_WT                         SRAM_CFGR2_WR_WT_Msk
#define  SRAM_CFGR2_WR_WT_Bit0                    (0x1U << SRAM_CFGR2_WR_WT_Pos) 
#define  SRAM_CFGR2_WR_WT_Bit1                    (0x2U << SRAM_CFGR2_WR_WT_Pos) 
#define  SRAM_CFGR2_WR_WT_Bit2                    (0x4U << SRAM_CFGR2_WR_WT_Pos) 

/**
  * @brief SRAM_BKPRAM Register Bit Definition
  */
#define  SRAM_BKPRAM_RD_LAT_Pos                    (0)
#define  SRAM_BKPRAM_RD_LAT_Msk                    (0x7U << SRAM_BKPRAM_RD_LAT_Pos)                   /*!<*/
#define  SRAM_BKPRAM_RD_LAT                        SRAM_BKPRAM_RD_LAT_Msk
#define  SRAM_BKPRAM_RD_LAT_Bit0                   (0x1U << SRAM_BKPRAM_RD_LAT_Pos) 
#define  SRAM_BKPRAM_RD_LAT_Bit1                   (0x2U << SRAM_BKPRAM_RD_LAT_Pos) 
#define  SRAM_BKPRAM_RD_LAT_Bit2                   (0x4U << SRAM_BKPRAM_RD_LAT_Pos) 
#define  SRAM_BKPRAM_WR_WT_Pos                     (3)
#define  SRAM_BKPRAM_WR_WT_Msk                     (0x7U << SRAM_BKPRAM_WR_WT_Pos)                    /*!<*/
#define  SRAM_BKPRAM_WR_WT                         SRAM_BKPRAM_WR_WT_Msk
#define  SRAM_BKPRAM_WR_WT_Bit0                    (0x1U << SRAM_BKPRAM_WR_WT_Pos) 
#define  SRAM_BKPRAM_WR_WT_Bit1                    (0x2U << SRAM_BKPRAM_WR_WT_Pos) 
#define  SRAM_BKPRAM_WR_WT_Bit2                    (0x4U << SRAM_BKPRAM_WR_WT_Pos) 

/**
  * @brief SRAM_ECCCR Register Bit Definition
  */
#define  SRAM_ECCCR_ECCSECEN_Pos                  (0)
#define  SRAM_ECCCR_ECCSECEN_Msk                  (0x1U << SRAM_ECCCR_ECCSECEN_Pos)                 /*!<*/
#define  SRAM_ECCCR_ECCSECEN                      SRAM_ECCCR_ECCSECEN_Msk
#define  SRAM_ECCCR_ECCEUPEN_Pos                  (1)
#define  SRAM_ECCCR_ECCEUPEN_Msk                  (0x1U << SRAM_ECCCR_ECCEUPEN_Pos)                 /*!<*/
#define  SRAM_ECCCR_ECCEUPEN                      SRAM_ECCCR_ECCEUPEN_Msk
#define  SRAM_ECCCR_ECCSNEIE_Pos                  (2)
#define  SRAM_ECCCR_ECCSNEIE_Msk                  (0x1U << SRAM_ECCCR_ECCSNEIE_Pos)                 /*!<*/
#define  SRAM_ECCCR_ECCSNEIE                      SRAM_ECCCR_ECCSNEIE_Msk
#define  SRAM_ECCCR_ECCDBEIE_Pos                  (3)
#define  SRAM_ECCCR_ECCDBEIE_Msk                  (0x1U << SRAM_ECCCR_ECCDBEIE_Pos)                 /*!<*/
#define  SRAM_ECCCR_ECCDBEIE                      SRAM_ECCCR_ECCDBEIE_Msk
#define  SRAM_ECCCR_ECCDBFREIE_Pos                (4)
#define  SRAM_ECCCR_ECCDBFREIE_Msk                (0x1U << SRAM_ECCCR_ECCDBFREIE_Pos)               /*!<*/
#define  SRAM_ECCCR_ECCDBFREIE                    SRAM_ECCCR_ECCDBFREIE_Msk
#define  SRAM_ECCCR_ECCEN_Pos                     (5)
#define  SRAM_ECCCR_ECCEN_Msk                     (0x1U << SRAM_ECCCR_ECCEN_Pos)                    /*!<*/
#define  SRAM_ECCCR_ECCEN                         SRAM_ECCCR_ECCEN_Msk

/**
  * @brief SRAM_ECCEINR0 Register Bit Definition
  */
#define  SRAM_ECCEINR0_ECCEIEN_Pos                (0)
#define  SRAM_ECCEINR0_ECCEIEN_Msk                (0xFFFFU << SRAM_ECCEINR0_ECCEIEN_Pos)            /*!<*/
#define  SRAM_ECCEINR0_ECCEIEN                    SRAM_ECCEINR0_ECCEIEN_Msk
#define  SRAM_ECCEINR0_ECCEIEN_Bit0               (0x0001U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit1               (0x0002U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit2               (0x0004U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit3               (0x0008U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit4               (0x0010U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit5               (0x0020U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit6               (0x0040U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit7               (0x0080U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit8               (0x0100U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit9               (0x0200U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit10              (0x0400U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit11              (0x0800U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit12              (0x1000U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit13              (0x2000U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit14              (0x4000U << SRAM_ECCEINR0_ECCEIEN_Pos) 
#define  SRAM_ECCEINR0_ECCEIEN_Bit15              (0x8000U << SRAM_ECCEINR0_ECCEIEN_Pos) 

/**
  * @brief SRAM_ECCEINR1 Register Bit Definition
  */
#define  SRAM_ECCEINR1_ECCEIEN_Pos                (0)
#define  SRAM_ECCEINR1_ECCEIEN_Msk                (0x7FU << SRAM_ECCEINR1_ECCEIEN_Pos)              /*!<*/
#define  SRAM_ECCEINR1_ECCEIEN                    SRAM_ECCEINR1_ECCEIEN_Msk
#define  SRAM_ECCEINR1_ECCEIEN_Bit0               (0x01U << SRAM_ECCEINR1_ECCEIEN_Pos) 
#define  SRAM_ECCEINR1_ECCEIEN_Bit1               (0x02U << SRAM_ECCEINR1_ECCEIEN_Pos) 
#define  SRAM_ECCEINR1_ECCEIEN_Bit2               (0x04U << SRAM_ECCEINR1_ECCEIEN_Pos) 
#define  SRAM_ECCEINR1_ECCEIEN_Bit3               (0x08U << SRAM_ECCEINR1_ECCEIEN_Pos) 
#define  SRAM_ECCEINR1_ECCEIEN_Bit4               (0x10U << SRAM_ECCEINR1_ECCEIEN_Pos) 
#define  SRAM_ECCEINR1_ECCEIEN_Bit5               (0x20U << SRAM_ECCEINR1_ECCEIEN_Pos) 
#define  SRAM_ECCEINR1_ECCEIEN_Bit6               (0x40U << SRAM_ECCEINR1_ECCEIEN_Pos) 

/**
  * @brief SRAM_ECCSR Register Bit Definition
  */
#define  SRAM_ECCSR_ECCSNERRF_Pos                 (0)
#define  SRAM_ECCSR_ECCSNERRF_Msk                 (0x1U << SRAM_ECCSR_ECCSNERRF_Pos)                /*!<*/
#define  SRAM_ECCSR_ECCSNERRF                     SRAM_ECCSR_ECCSNERRF_Msk
#define  SRAM_ECCSR_ECCDBERRF_Pos                 (1)
#define  SRAM_ECCSR_ECCDBERRF_Msk                 (0x1U << SRAM_ECCSR_ECCDBERRF_Pos)                /*!<*/
#define  SRAM_ECCSR_ECCDBERRF                     SRAM_ECCSR_ECCDBERRF_Msk
#define  SRAM_ECCSR_ECCDBFREF_Pos                 (2)
#define  SRAM_ECCSR_ECCDBFREF_Msk                 (0x1U << SRAM_ECCSR_ECCDBFREF_Pos)                /*!<*/
#define  SRAM_ECCSR_ECCDBFREF                     SRAM_ECCSR_ECCDBFREF_Msk

/**
  * @brief SRAM_ECCEADRR Register Bit Definition
  */
#define  SRAM_ECCEADRR_ECCEADR_Pos                (0)
#define  SRAM_ECCEADRR_ECCEADR_Msk                (0xFFFFU << SRAM_ECCEADRR_ECCEADR_Pos)            /*!<*/
#define  SRAM_ECCEADRR_ECCEADR                    SRAM_ECCEADRR_ECCEADR_Msk
#define  SRAM_ECCEADRR_ECCEADR_Bit0               (0x0001U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit1               (0x0002U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit2               (0x0004U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit3               (0x0008U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit4               (0x0010U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit5               (0x0020U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit6               (0x0040U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit7               (0x0080U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit8               (0x0100U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit9               (0x0200U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit10              (0x0400U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit11              (0x0800U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit12              (0x1000U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit13              (0x2000U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit14              (0x4000U << SRAM_ECCEADRR_ECCEADR_Pos) 
#define  SRAM_ECCEADRR_ECCEADR_Bit15              (0x8000U << SRAM_ECCEADRR_ECCEADR_Pos) 

/**
  * @brief SRAM_ECCESYNR Register Bit Definition
  */
#define  SRAM_ECCESYNR_ECCESYN_Pos                (0)
#define  SRAM_ECCESYNR_ECCESYN_Msk                (0x7FU << SRAM_ECCESYNR_ECCESYN_Pos)              /*!<*/
#define  SRAM_ECCESYNR_ECCESYN                    SRAM_ECCESYNR_ECCESYN_Msk
#define  SRAM_ECCESYNR_ECCESYN_Bit0               (0x01U << SRAM_ECCESYNR_ECCESYN_Pos) 
#define  SRAM_ECCESYNR_ECCESYN_Bit1               (0x02U << SRAM_ECCESYNR_ECCESYN_Pos) 
#define  SRAM_ECCESYNR_ECCESYN_Bit2               (0x04U << SRAM_ECCESYNR_ECCESYN_Pos) 
#define  SRAM_ECCESYNR_ECCESYN_Bit3               (0x08U << SRAM_ECCESYNR_ECCESYN_Pos) 
#define  SRAM_ECCESYNR_ECCESYN_Bit4               (0x10U << SRAM_ECCESYNR_ECCESYN_Pos) 
#define  SRAM_ECCESYNR_ECCESYN_Bit5               (0x20U << SRAM_ECCESYNR_ECCESYN_Pos) 
#define  SRAM_ECCESYNR_ECCESYN_Bit6               (0x40U << SRAM_ECCESYNR_ECCESYN_Pos) 

/**
  * @brief SRAM_ECCEDATAR Register Bit Definition
  */
#define  SRAM_ECCEDATAR_ECCEDATA_Pos              (0)
#define  SRAM_ECCEDATAR_ECCEDATA_Msk              (0xFFFFU << SRAM_ECCEDATAR_ECCEDATA_Pos)          /*!<*/
#define  SRAM_ECCEDATAR_ECCEDATA                  SRAM_ECCEDATAR_ECCEDATA_Msk
#define  SRAM_ECCEDATAR_ECCEDATA_Bit0             (0x0001U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit1             (0x0002U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit2             (0x0004U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit3             (0x0008U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit4             (0x0010U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit5             (0x0020U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit6             (0x0040U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit7             (0x0080U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit8             (0x0100U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit9             (0x0200U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit10            (0x0400U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit11            (0x0800U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit12            (0x1000U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit13            (0x2000U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit14            (0x4000U << SRAM_ECCEDATAR_ECCEDATA_Pos) 
#define  SRAM_ECCEDATAR_ECCEDATA_Bit15            (0x8000U << SRAM_ECCEDATAR_ECCEDATA_Pos) 


#endif

