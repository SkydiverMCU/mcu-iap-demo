/***********************************************************************************************************************
    @file     reg_qspi.h
    @author   VV TEAM
    @brief    This flie contains all the QSPI's register and its field definition.
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

#ifndef __REG_QSPI_H
#define __REG_QSPI_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief QSPI Base Address Definition
  */
#define  QSPI_BASE                                 0xA0001000                                       /*!<Base Address: 0xA0001000*/

/**
  * @brief QSPI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<                                               offset: 0x00       */
    __IO uint32_t SR;                             /*!<                                               offset: 0x04       */
    __IO uint32_t DMCR;                           /*!<                                               offset: 0x08       */
    __IO uint32_t IMCR;                           /*!<                                               offset: 0x0C       */
    __IO uint32_t DABR;                           /*!<                                               offset: 0x10       */
    __IO uint32_t IABR;                           /*!<                                               offset: 0x14       */
    __IO uint32_t IADR;                           /*!<                                               offset: 0x18       */
    __IO uint32_t IDFR;                           /*!<                                               offset: 0x1C       */
    __IO uint32_t IDLR;                           /*!<                                               offset: 0x20       */
    __IO uint32_t IWCR;                           /*!<                                               offset: 0x24       */
    __IO uint32_t IDER;                           /*!<                                               offset: 0x28       */
} QSPI_TypeDef;

/**
  * @brief QSPI type pointer Definition
  */
#define QSPI                                      ((QSPI_TypeDef *)QSPI_BASE)

/**
  * @brief QSPI_CR Register Bit Definition
  */
#define  QSPI_CR_OPMODE_Pos                       (0)
#define  QSPI_CR_OPMODE_Msk                       (0x3U << QSPI_CR_OPMODE_Pos)                      /*!<*/
#define  QSPI_CR_OPMODE                           QSPI_CR_OPMODE_Msk
#define  QSPI_CR_OPMODE_Bit0                      (0x1U << QSPI_CR_OPMODE_Pos) 
#define  QSPI_CR_OPMODE_Bit1                      (0x2U << QSPI_CR_OPMODE_Pos) 
#define  QSPI_CR_SCKMODE_Pos                      (4)
#define  QSPI_CR_SCKMODE_Msk                      (0x1U << QSPI_CR_SCKMODE_Pos)                     /*!<*/
#define  QSPI_CR_SCKMODE                          QSPI_CR_SCKMODE_Msk
#define  QSPI_CR_XIPMODE_Pos                      (5)
#define  QSPI_CR_XIPMODE_Msk                      (0x1U << QSPI_CR_XIPMODE_Pos)                     /*!<*/
#define  QSPI_CR_XIPMODE                          QSPI_CR_XIPMODE_Msk
#define  QSPI_CR_CSRHT_Pos                        (16)
#define  QSPI_CR_CSRHT_Msk                        (0x7U << QSPI_CR_CSRHT_Pos)                       /*!<*/
#define  QSPI_CR_CSRHT                            QSPI_CR_CSRHT_Msk
#define  QSPI_CR_CSRHT_Bit0                       (0x1U << QSPI_CR_CSRHT_Pos) 
#define  QSPI_CR_CSRHT_Bit1                       (0x2U << QSPI_CR_CSRHT_Pos) 
#define  QSPI_CR_CSRHT_Bit2                       (0x4U << QSPI_CR_CSRHT_Pos) 
#define  QSPI_CR_SCKDIV_Pos                       (24)
#define  QSPI_CR_SCKDIV_Msk                       (0x3FU << QSPI_CR_SCKDIV_Pos)                     /*!<*/
#define  QSPI_CR_SCKDIV                           QSPI_CR_SCKDIV_Msk
#define  QSPI_CR_SCKDIV_Bit0                      (0x01U << QSPI_CR_SCKDIV_Pos) 
#define  QSPI_CR_SCKDIV_Bit1                      (0x02U << QSPI_CR_SCKDIV_Pos) 
#define  QSPI_CR_SCKDIV_Bit2                      (0x04U << QSPI_CR_SCKDIV_Pos) 
#define  QSPI_CR_SCKDIV_Bit3                      (0x08U << QSPI_CR_SCKDIV_Pos) 
#define  QSPI_CR_SCKDIV_Bit4                      (0x10U << QSPI_CR_SCKDIV_Pos) 
#define  QSPI_CR_SCKDIV_Bit5                      (0x20U << QSPI_CR_SCKDIV_Pos) 

/**
  * @brief QSPI_SR Register Bit Definition
  */
#define  QSPI_SR_CUROP_Pos                        (0)
#define  QSPI_SR_CUROP_Msk                        (0x3U << QSPI_SR_CUROP_Pos)                       /*!<*/
#define  QSPI_SR_CUROP                            QSPI_SR_CUROP_Msk
#define  QSPI_SR_CUROP_Bit0                       (0x1U << QSPI_SR_CUROP_Pos) 
#define  QSPI_SR_CUROP_Bit1                       (0x2U << QSPI_SR_CUROP_Pos) 
#define  QSPI_SR_OPCRCF_Pos                       (2)
#define  QSPI_SR_OPCRCF_Msk                       (0x1U << QSPI_SR_OPCRCF_Pos)                      /*!<*/
#define  QSPI_SR_OPCRCF                           QSPI_SR_OPCRCF_Msk
#define  QSPI_SR_TCF_Pos                          (4)
#define  QSPI_SR_TCF_Msk                          (0x1U << QSPI_SR_TCF_Pos)                         /*!<*/
#define  QSPI_SR_TCF                              QSPI_SR_TCF_Msk
#define  QSPI_SR_BUSY_Pos                         (5)
#define  QSPI_SR_BUSY_Msk                         (0x1U << QSPI_SR_BUSY_Pos)                        /*!<*/
#define  QSPI_SR_BUSY                             QSPI_SR_BUSY_Msk
#define  QSPI_SR_XIPST_Pos                        (6)
#define  QSPI_SR_XIPST_Msk                        (0x1U << QSPI_SR_XIPST_Pos)                       /*!<*/
#define  QSPI_SR_XIPST                            QSPI_SR_XIPST_Msk
#define  QSPI_SR_EMPTY_Pos                        (8)
#define  QSPI_SR_EMPTY_Msk                        (0x1U << QSPI_SR_EMPTY_Pos)                       /*!<*/
#define  QSPI_SR_EMPTY                            QSPI_SR_EMPTY_Msk
#define  QSPI_SR_FULL_Pos                         (9)
#define  QSPI_SR_FULL_Msk                         (0x1U << QSPI_SR_FULL_Pos)                        /*!<*/
#define  QSPI_SR_FULL                             QSPI_SR_FULL_Msk
#define  QSPI_SR_LEVEL_Pos                        (12)
#define  QSPI_SR_LEVEL_Msk                        (0xFU << QSPI_SR_LEVEL_Pos)                       /*!<*/
#define  QSPI_SR_LEVEL                            QSPI_SR_LEVEL_Msk
#define  QSPI_SR_LEVEL_Bit0                       (0x1U << QSPI_SR_LEVEL_Pos) 
#define  QSPI_SR_LEVEL_Bit1                       (0x2U << QSPI_SR_LEVEL_Pos) 
#define  QSPI_SR_LEVEL_Bit2                       (0x4U << QSPI_SR_LEVEL_Pos) 
#define  QSPI_SR_LEVEL_Bit3                       (0x8U << QSPI_SR_LEVEL_Pos) 
#define  QSPI_SR_DEPTH_Pos                        (24)
#define  QSPI_SR_DEPTH_Msk                        (0xFU << QSPI_SR_DEPTH_Pos)                       /*!<*/
#define  QSPI_SR_DEPTH                            QSPI_SR_DEPTH_Msk
#define  QSPI_SR_DEPTH_Bit0                       (0x1U << QSPI_SR_DEPTH_Pos) 
#define  QSPI_SR_DEPTH_Bit1                       (0x2U << QSPI_SR_DEPTH_Pos) 
#define  QSPI_SR_DEPTH_Bit2                       (0x4U << QSPI_SR_DEPTH_Pos) 
#define  QSPI_SR_DEPTH_Bit3                       (0x8U << QSPI_SR_DEPTH_Pos) 

/**
  * @brief QSPI_DMCR Register Bit Definition
  */
#define  QSPI_DMCR_INST_Pos                       (0)
#define  QSPI_DMCR_INST_Msk                       (0xFFU << QSPI_DMCR_INST_Pos)                     /*!<*/
#define  QSPI_DMCR_INST                           QSPI_DMCR_INST_Msk
#define  QSPI_DMCR_INST_Bit0                      (0x01U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit1                      (0x02U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit2                      (0x04U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit3                      (0x08U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit4                      (0x10U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit5                      (0x20U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit6                      (0x40U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_INST_Bit7                      (0x80U << QSPI_DMCR_INST_Pos) 
#define  QSPI_DMCR_IMODE_Pos                      (8)
#define  QSPI_DMCR_IMODE_Msk                      (0x3U << QSPI_DMCR_IMODE_Pos)                     /*!<*/
#define  QSPI_DMCR_IMODE                          QSPI_DMCR_IMODE_Msk
#define  QSPI_DMCR_IMODE_Bit0                     (0x1U << QSPI_DMCR_IMODE_Pos) 
#define  QSPI_DMCR_IMODE_Bit1                     (0x2U << QSPI_DMCR_IMODE_Pos) 
#define  QSPI_DMCR_ADMODE_Pos                     (10)
#define  QSPI_DMCR_ADMODE_Msk                     (0x3U << QSPI_DMCR_ADMODE_Pos)                    /*!<*/
#define  QSPI_DMCR_ADMODE                         QSPI_DMCR_ADMODE_Msk
#define  QSPI_DMCR_ADMODE_Bit0                    (0x1U << QSPI_DMCR_ADMODE_Pos) 
#define  QSPI_DMCR_ADMODE_Bit1                    (0x2U << QSPI_DMCR_ADMODE_Pos) 
#define  QSPI_DMCR_ADSIZE_Pos                     (12)
#define  QSPI_DMCR_ADSIZE_Msk                     (0x3U << QSPI_DMCR_ADSIZE_Pos)                    /*!<*/
#define  QSPI_DMCR_ADSIZE                         QSPI_DMCR_ADSIZE_Msk
#define  QSPI_DMCR_ADSIZE_Bit0                    (0x1U << QSPI_DMCR_ADSIZE_Pos) 
#define  QSPI_DMCR_ADSIZE_Bit1                    (0x2U << QSPI_DMCR_ADSIZE_Pos) 
#define  QSPI_DMCR_ABMODE_Pos                     (14)
#define  QSPI_DMCR_ABMODE_Msk                     (0x3U << QSPI_DMCR_ABMODE_Pos)                    /*!<*/
#define  QSPI_DMCR_ABMODE                         QSPI_DMCR_ABMODE_Msk
#define  QSPI_DMCR_ABMODE_Bit0                    (0x1U << QSPI_DMCR_ABMODE_Pos) 
#define  QSPI_DMCR_ABMODE_Bit1                    (0x2U << QSPI_DMCR_ABMODE_Pos) 
#define  QSPI_DMCR_ABSIZE_Pos                     (16)
#define  QSPI_DMCR_ABSIZE_Msk                     (0x3U << QSPI_DMCR_ABSIZE_Pos)                    /*!<*/
#define  QSPI_DMCR_ABSIZE                         QSPI_DMCR_ABSIZE_Msk
#define  QSPI_DMCR_ABSIZE_Bit0                    (0x1U << QSPI_DMCR_ABSIZE_Pos) 
#define  QSPI_DMCR_ABSIZE_Bit1                    (0x2U << QSPI_DMCR_ABSIZE_Pos) 
#define  QSPI_DMCR_DMODE_Pos                      (18)
#define  QSPI_DMCR_DMODE_Msk                      (0x3U << QSPI_DMCR_DMODE_Pos)                     /*!<*/
#define  QSPI_DMCR_DMODE                          QSPI_DMCR_DMODE_Msk
#define  QSPI_DMCR_DMODE_Bit0                     (0x1U << QSPI_DMCR_DMODE_Pos) 
#define  QSPI_DMCR_DMODE_Bit1                     (0x2U << QSPI_DMCR_DMODE_Pos) 
#define  QSPI_DMCR_DSIZE_Pos                      (20)
#define  QSPI_DMCR_DSIZE_Msk                      (0x3U << QSPI_DMCR_DSIZE_Pos)                     /*!<*/
#define  QSPI_DMCR_DSIZE                          QSPI_DMCR_DSIZE_Msk
#define  QSPI_DMCR_DSIZE_Bit0                     (0x1U << QSPI_DMCR_DSIZE_Pos) 
#define  QSPI_DMCR_DSIZE_Bit1                     (0x2U << QSPI_DMCR_DSIZE_Pos) 
#define  QSPI_DMCR_RXDLY_Pos                      (22)
#define  QSPI_DMCR_RXDLY_Msk                      (0x3U << QSPI_DMCR_RXDLY_Pos)                     /*!<*/
#define  QSPI_DMCR_RXDLY                          QSPI_DMCR_RXDLY_Msk
#define  QSPI_DMCR_RXDLY_Bit0                     (0x1U << QSPI_DMCR_RXDLY_Pos) 
#define  QSPI_DMCR_RXDLY_Bit1                     (0x2U << QSPI_DMCR_RXDLY_Pos) 
#define  QSPI_DMCR_NUMDC_Pos                      (24)
#define  QSPI_DMCR_NUMDC_Msk                      (0x1FU << QSPI_DMCR_NUMDC_Pos)                    /*!<*/
#define  QSPI_DMCR_NUMDC                          QSPI_DMCR_NUMDC_Msk
#define  QSPI_DMCR_NUMDC_Bit0                     (0x01U << QSPI_DMCR_NUMDC_Pos) 
#define  QSPI_DMCR_NUMDC_Bit1                     (0x02U << QSPI_DMCR_NUMDC_Pos) 
#define  QSPI_DMCR_NUMDC_Bit2                     (0x04U << QSPI_DMCR_NUMDC_Pos) 
#define  QSPI_DMCR_NUMDC_Bit3                     (0x08U << QSPI_DMCR_NUMDC_Pos) 
#define  QSPI_DMCR_NUMDC_Bit4                     (0x10U << QSPI_DMCR_NUMDC_Pos) 

/**
  * @brief QSPI_IMCR Register Bit Definition
  */
#define  QSPI_IMCR_INST_Pos                       (0)
#define  QSPI_IMCR_INST_Msk                       (0xFFU << QSPI_IMCR_INST_Pos)                     /*!<*/
#define  QSPI_IMCR_INST                           QSPI_IMCR_INST_Msk
#define  QSPI_IMCR_INST_Bit0                      (0x01U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit1                      (0x02U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit2                      (0x04U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit3                      (0x08U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit4                      (0x10U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit5                      (0x20U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit6                      (0x40U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_INST_Bit7                      (0x80U << QSPI_IMCR_INST_Pos) 
#define  QSPI_IMCR_IMODE_Pos                      (8)
#define  QSPI_IMCR_IMODE_Msk                      (0x3U << QSPI_IMCR_IMODE_Pos)                     /*!<*/
#define  QSPI_IMCR_IMODE                          QSPI_IMCR_IMODE_Msk
#define  QSPI_IMCR_IMODE_Bit0                     (0x1U << QSPI_IMCR_IMODE_Pos) 
#define  QSPI_IMCR_IMODE_Bit1                     (0x2U << QSPI_IMCR_IMODE_Pos) 
#define  QSPI_IMCR_ADMODE_Pos                     (10)
#define  QSPI_IMCR_ADMODE_Msk                     (0x3U << QSPI_IMCR_ADMODE_Pos)                    /*!<*/
#define  QSPI_IMCR_ADMODE                         QSPI_IMCR_ADMODE_Msk
#define  QSPI_IMCR_ADMODE_Bit0                    (0x1U << QSPI_IMCR_ADMODE_Pos) 
#define  QSPI_IMCR_ADMODE_Bit1                    (0x2U << QSPI_IMCR_ADMODE_Pos) 
#define  QSPI_IMCR_ADSIZE_Pos                     (12)
#define  QSPI_IMCR_ADSIZE_Msk                     (0x3U << QSPI_IMCR_ADSIZE_Pos)                    /*!<*/
#define  QSPI_IMCR_ADSIZE                         QSPI_IMCR_ADSIZE_Msk
#define  QSPI_IMCR_ADSIZE_Bit0                    (0x1U << QSPI_IMCR_ADSIZE_Pos) 
#define  QSPI_IMCR_ADSIZE_Bit1                    (0x2U << QSPI_IMCR_ADSIZE_Pos) 
#define  QSPI_IMCR_ABMODE_Pos                     (14)
#define  QSPI_IMCR_ABMODE_Msk                     (0x3U << QSPI_IMCR_ABMODE_Pos)                    /*!<*/
#define  QSPI_IMCR_ABMODE                         QSPI_IMCR_ABMODE_Msk
#define  QSPI_IMCR_ABMODE_Bit0                    (0x1U << QSPI_IMCR_ABMODE_Pos) 
#define  QSPI_IMCR_ABMODE_Bit1                    (0x2U << QSPI_IMCR_ABMODE_Pos) 
#define  QSPI_IMCR_ABSIZE_Pos                     (16)
#define  QSPI_IMCR_ABSIZE_Msk                     (0x3U << QSPI_IMCR_ABSIZE_Pos)                    /*!<*/
#define  QSPI_IMCR_ABSIZE                         QSPI_IMCR_ABSIZE_Msk
#define  QSPI_IMCR_ABSIZE_Bit0                    (0x1U << QSPI_IMCR_ABSIZE_Pos) 
#define  QSPI_IMCR_ABSIZE_Bit1                    (0x2U << QSPI_IMCR_ABSIZE_Pos) 
#define  QSPI_IMCR_DMODE_Pos                      (18)
#define  QSPI_IMCR_DMODE_Msk                      (0x3U << QSPI_IMCR_DMODE_Pos)                     /*!<*/
#define  QSPI_IMCR_DMODE                          QSPI_IMCR_DMODE_Msk
#define  QSPI_IMCR_DMODE_Bit0                     (0x1U << QSPI_IMCR_DMODE_Pos) 
#define  QSPI_IMCR_DMODE_Bit1                     (0x2U << QSPI_IMCR_DMODE_Pos) 
#define  QSPI_IMCR_DSIZE_Pos                      (20)
#define  QSPI_IMCR_DSIZE_Msk                      (0x3U << QSPI_IMCR_DSIZE_Pos)                     /*!<*/
#define  QSPI_IMCR_DSIZE                          QSPI_IMCR_DSIZE_Msk
#define  QSPI_IMCR_DSIZE_Bit0                     (0x1U << QSPI_IMCR_DSIZE_Pos) 
#define  QSPI_IMCR_DSIZE_Bit1                     (0x2U << QSPI_IMCR_DSIZE_Pos) 
#define  QSPI_IMCR_RXDLY_Pos                      (22)
#define  QSPI_IMCR_RXDLY_Msk                      (0x3U << QSPI_IMCR_RXDLY_Pos)                     /*!<*/
#define  QSPI_IMCR_RXDLY                          QSPI_IMCR_RXDLY_Msk
#define  QSPI_IMCR_RXDLY_Bit0                     (0x1U << QSPI_IMCR_RXDLY_Pos) 
#define  QSPI_IMCR_RXDLY_Bit1                     (0x2U << QSPI_IMCR_RXDLY_Pos) 
#define  QSPI_IMCR_NUMDC_Pos                      (24)
#define  QSPI_IMCR_NUMDC_Msk                      (0x1FU << QSPI_IMCR_NUMDC_Pos)                    /*!<*/
#define  QSPI_IMCR_NUMDC                          QSPI_IMCR_NUMDC_Msk
#define  QSPI_IMCR_NUMDC_Bit0                     (0x01U << QSPI_IMCR_NUMDC_Pos) 
#define  QSPI_IMCR_NUMDC_Bit1                     (0x02U << QSPI_IMCR_NUMDC_Pos) 
#define  QSPI_IMCR_NUMDC_Bit2                     (0x04U << QSPI_IMCR_NUMDC_Pos) 
#define  QSPI_IMCR_NUMDC_Bit3                     (0x08U << QSPI_IMCR_NUMDC_Pos) 
#define  QSPI_IMCR_NUMDC_Bit4                     (0x10U << QSPI_IMCR_NUMDC_Pos) 
#define  QSPI_IMCR_XIPIM_Pos                      (29)
#define  QSPI_IMCR_XIPIM_Msk                      (0x1U << QSPI_IMCR_XIPIM_Pos)                     /*!<*/
#define  QSPI_IMCR_XIPIM                          QSPI_IMCR_XIPIM_Msk
#define  QSPI_IMCR_IDMODE_Pos                     (30)
#define  QSPI_IMCR_IDMODE_Msk                     (0x1U << QSPI_IMCR_IDMODE_Pos)                    /*!<*/
#define  QSPI_IMCR_IDMODE                         QSPI_IMCR_IDMODE_Msk

/**
  * @brief QSPI_DABR Register Bit Definition
  */
#define  QSPI_DABR_DALT_Pos                       (0)
#define  QSPI_DABR_DALT_Msk                       (0xFFFFFFFFU << QSPI_DABR_DALT_Pos)               /*!<*/
#define  QSPI_DABR_DALT                           QSPI_DABR_DALT_Msk
#define  QSPI_DABR_DALT_Bit0                      (0x00000001U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit1                      (0x00000002U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit2                      (0x00000004U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit3                      (0x00000008U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit4                      (0x00000010U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit5                      (0x00000020U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit6                      (0x00000040U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit7                      (0x00000080U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit8                      (0x00000100U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit9                      (0x00000200U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit10                     (0x00000400U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit11                     (0x00000800U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit12                     (0x00001000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit13                     (0x00002000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit14                     (0x00004000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit15                     (0x00008000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit16                     (0x00010000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit17                     (0x00020000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit18                     (0x00040000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit19                     (0x00080000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit20                     (0x00100000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit21                     (0x00200000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit22                     (0x00400000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit23                     (0x00800000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit24                     (0x01000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit25                     (0x02000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit26                     (0x04000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit27                     (0x08000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit28                     (0x10000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit29                     (0x20000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit30                     (0x40000000U << QSPI_DABR_DALT_Pos) 
#define  QSPI_DABR_DALT_Bit31                     (0x80000000U << QSPI_DABR_DALT_Pos) 

/**
  * @brief QSPI_IABR Register Bit Definition
  */
#define  QSPI_IABR_IALT_Pos                       (0)
#define  QSPI_IABR_IALT_Msk                       (0xFFFFFFFFU << QSPI_IABR_IALT_Pos)               /*!<*/
#define  QSPI_IABR_IALT                           QSPI_IABR_IALT_Msk
#define  QSPI_IABR_IALT_Bit0                      (0x00000001U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit1                      (0x00000002U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit2                      (0x00000004U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit3                      (0x00000008U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit4                      (0x00000010U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit5                      (0x00000020U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit6                      (0x00000040U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit7                      (0x00000080U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit8                      (0x00000100U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit9                      (0x00000200U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit10                     (0x00000400U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit11                     (0x00000800U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit12                     (0x00001000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit13                     (0x00002000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit14                     (0x00004000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit15                     (0x00008000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit16                     (0x00010000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit17                     (0x00020000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit18                     (0x00040000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit19                     (0x00080000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit20                     (0x00100000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit21                     (0x00200000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit22                     (0x00400000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit23                     (0x00800000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit24                     (0x01000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit25                     (0x02000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit26                     (0x04000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit27                     (0x08000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit28                     (0x10000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit29                     (0x20000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit30                     (0x40000000U << QSPI_IABR_IALT_Pos) 
#define  QSPI_IABR_IALT_Bit31                     (0x80000000U << QSPI_IABR_IALT_Pos) 

/**
  * @brief QSPI_IADR Register Bit Definition
  */
#define  QSPI_IADR_IADDR_Pos                      (0)
#define  QSPI_IADR_IADDR_Msk                      (0xFFFFFFFFU << QSPI_IADR_IADDR_Pos)              /*!<*/
#define  QSPI_IADR_IADDR                          QSPI_IADR_IADDR_Msk
#define  QSPI_IADR_IADDR_Bit0                     (0x00000001U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit1                     (0x00000002U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit2                     (0x00000004U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit3                     (0x00000008U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit4                     (0x00000010U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit5                     (0x00000020U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit6                     (0x00000040U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit7                     (0x00000080U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit8                     (0x00000100U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit9                     (0x00000200U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit10                    (0x00000400U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit11                    (0x00000800U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit12                    (0x00001000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit13                    (0x00002000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit14                    (0x00004000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit15                    (0x00008000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit16                    (0x00010000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit17                    (0x00020000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit18                    (0x00040000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit19                    (0x00080000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit20                    (0x00100000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit21                    (0x00200000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit22                    (0x00400000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit23                    (0x00800000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit24                    (0x01000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit25                    (0x02000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit26                    (0x04000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit27                    (0x08000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit28                    (0x10000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit29                    (0x20000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit30                    (0x40000000U << QSPI_IADR_IADDR_Pos) 
#define  QSPI_IADR_IADDR_Bit31                    (0x80000000U << QSPI_IADR_IADDR_Pos) 

/**
  * @brief QSPI_IDFR Register Bit Definition
  */
#define  QSPI_IDFR_IDATA_Pos                      (0)
#define  QSPI_IDFR_IDATA_Msk                      (0xFFFFFFFFU << QSPI_IDFR_IDATA_Pos)              /*!<*/
#define  QSPI_IDFR_IDATA                          QSPI_IDFR_IDATA_Msk
#define  QSPI_IDFR_IDATA_Bit0                     (0x00000001U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit1                     (0x00000002U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit2                     (0x00000004U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit3                     (0x00000008U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit4                     (0x00000010U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit5                     (0x00000020U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit6                     (0x00000040U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit7                     (0x00000080U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit8                     (0x00000100U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit9                     (0x00000200U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit10                    (0x00000400U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit11                    (0x00000800U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit12                    (0x00001000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit13                    (0x00002000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit14                    (0x00004000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit15                    (0x00008000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit16                    (0x00010000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit17                    (0x00020000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit18                    (0x00040000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit19                    (0x00080000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit20                    (0x00100000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit21                    (0x00200000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit22                    (0x00400000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit23                    (0x00800000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit24                    (0x01000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit25                    (0x02000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit26                    (0x04000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit27                    (0x08000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit28                    (0x10000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit29                    (0x20000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit30                    (0x40000000U << QSPI_IDFR_IDATA_Pos) 
#define  QSPI_IDFR_IDATA_Bit31                    (0x80000000U << QSPI_IDFR_IDATA_Pos) 

/**
  * @brief QSPI_IDLR Register Bit Definition
  */
#define  QSPI_IDLR_IDLEN_Pos                      (0)
#define  QSPI_IDLR_IDLEN_Msk                      (0xFFFFFU << QSPI_IDLR_IDLEN_Pos)                 /*!<*/
#define  QSPI_IDLR_IDLEN                          QSPI_IDLR_IDLEN_Msk
#define  QSPI_IDLR_IDLEN_Bit0                     (0x00001U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit1                     (0x00002U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit2                     (0x00004U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit3                     (0x00008U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit4                     (0x00010U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit5                     (0x00020U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit6                     (0x00040U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit7                     (0x00080U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit8                     (0x00100U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit9                     (0x00200U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit10                    (0x00400U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit11                    (0x00800U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit12                    (0x01000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit13                    (0x02000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit14                    (0x04000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit15                    (0x08000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit16                    (0x10000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit17                    (0x20000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit18                    (0x40000U << QSPI_IDLR_IDLEN_Pos) 
#define  QSPI_IDLR_IDLEN_Bit19                    (0x80000U << QSPI_IDLR_IDLEN_Pos) 

/**
  * @brief QSPI_IWCR Register Bit Definition
  */
#define  QSPI_IWCR_IWCNT_Pos                      (0)
#define  QSPI_IWCR_IWCNT_Msk                      (0x3FFFFFFFU << QSPI_IWCR_IWCNT_Pos)              /*!<*/
#define  QSPI_IWCR_IWCNT                          QSPI_IWCR_IWCNT_Msk
#define  QSPI_IWCR_IWCNT_Bit0                     (0x00000001U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit1                     (0x00000002U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit2                     (0x00000004U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit3                     (0x00000008U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit4                     (0x00000010U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit5                     (0x00000020U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit6                     (0x00000040U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit7                     (0x00000080U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit8                     (0x00000100U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit9                     (0x00000200U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit10                    (0x00000400U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit11                    (0x00000800U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit12                    (0x00001000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit13                    (0x00002000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit14                    (0x00004000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit15                    (0x00008000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit16                    (0x00010000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit17                    (0x00020000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit18                    (0x00040000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit19                    (0x00080000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit20                    (0x00100000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit21                    (0x00200000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit22                    (0x00400000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit23                    (0x00800000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit24                    (0x01000000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit25                    (0x02000000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit26                    (0x04000000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit27                    (0x08000000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit28                    (0x10000000U << QSPI_IWCR_IWCNT_Pos) 
#define  QSPI_IWCR_IWCNT_Bit29                    (0x20000000U << QSPI_IWCR_IWCNT_Pos) 

/**
  * @brief QSPI_IDER Register Bit Definition
  */
#define  QSPI_IDER_TCFINTEN_Pos                   (0)
#define  QSPI_IDER_TCFINTEN_Msk                   (0x1U << QSPI_IDER_TCFINTEN_Pos)                  /*!<*/
#define  QSPI_IDER_TCFINTEN                       QSPI_IDER_TCFINTEN_Msk
#define  QSPI_IDER_EMPTYINTEN_Pos                 (6)
#define  QSPI_IDER_EMPTYINTEN_Msk                 (0x1U << QSPI_IDER_EMPTYINTEN_Pos)                /*!<*/
#define  QSPI_IDER_EMPTYINTEN                     QSPI_IDER_EMPTYINTEN_Msk
#define  QSPI_IDER_FULLINTEN_Pos                  (7)
#define  QSPI_IDER_FULLINTEN_Msk                  (0x1U << QSPI_IDER_FULLINTEN_Pos)                 /*!<*/
#define  QSPI_IDER_FULLINTEN                      QSPI_IDER_FULLINTEN_Msk
#define  QSPI_IDER_TCFDMAEN_Pos                   (8)
#define  QSPI_IDER_TCFDMAEN_Msk                   (0x1U << QSPI_IDER_TCFDMAEN_Pos)                  /*!<*/
#define  QSPI_IDER_TCFDMAEN                       QSPI_IDER_TCFDMAEN_Msk
#define  QSPI_IDER_EMPTYDMAEN_Pos                 (14)
#define  QSPI_IDER_EMPTYDMAEN_Msk                 (0x1U << QSPI_IDER_EMPTYDMAEN_Pos)                /*!<*/
#define  QSPI_IDER_EMPTYDMAEN                     QSPI_IDER_EMPTYDMAEN_Msk
#define  QSPI_IDER_FULLDMAEN_Pos                  (15)
#define  QSPI_IDER_FULLDMAEN_Msk                  (0x1U << QSPI_IDER_FULLDMAEN_Pos)                 /*!<*/
#define  QSPI_IDER_FULLDMAEN                      QSPI_IDER_FULLDMAEN_Msk


#endif

