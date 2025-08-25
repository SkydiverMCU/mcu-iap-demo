/***********************************************************************************************************************
    @file     reg_lpuart.h
    @author   VV TEAM
    @brief    This flie contains all the LPUART's register and its field definition.
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

#ifndef __REG_LPUART_H
#define __REG_LPUART_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief LPUART Base Address Definition
  */
#define  LPUART_BASE                               0x40010800                                       /*!<Base Address: 0x40010800*/

/**
  * @brief LPUART Register Structure Definition
  */
typedef struct
{
    __IO uint32_t LPUBAUD;                        /*!<                                               offset: 0x00       */
    __IO uint32_t MODU;                           /*!<                                               offset: 0x04       */
    __IO uint32_t LPUIF;                          /*!<                                               offset: 0x08       */
    __IO uint32_t LPUSTA;                         /*!<                                               offset: 0x0C       */
    __IO uint32_t LPUCON;                         /*!<                                               offset: 0x10       */
    __IO uint32_t LPUEN;                          /*!<                                               offset: 0x14       */
    __IO uint32_t LPURXD;                         /*!<                                               offset: 0x18       */
    __IO uint32_t LPUTXD;                         /*!<                                               offset: 0x1C       */
    __IO uint32_t COMPARE;                        /*!<                                               offset: 0x20       */
    __IO uint32_t WKCKE;                          /*!<                                               offset: 0x24       */
} LPUART_TypeDef;

/**
  * @brief LPUART type pointer Definition
  */
#define LPUART                                    ((LPUART_TypeDef *)LPUART_BASE)

/**
  * @brief LPUART_LPUBAUD Register Bit Definition
  */
#define  LPUART_LPUBAUD_BAUD_Pos                  (0)
#define  LPUART_LPUBAUD_BAUD_Msk                  (0x7U << LPUART_LPUBAUD_BAUD_Pos)                 /*!<*/
#define  LPUART_LPUBAUD_BAUD                      LPUART_LPUBAUD_BAUD_Msk
#define  LPUART_LPUBAUD_BAUD_Bit0                 (0x1U << LPUART_LPUBAUD_BAUD_Pos) 
#define  LPUART_LPUBAUD_BAUD_Bit1                 (0x2U << LPUART_LPUBAUD_BAUD_Pos) 
#define  LPUART_LPUBAUD_BAUD_Bit2                 (0x4U << LPUART_LPUBAUD_BAUD_Pos) 
#define  LPUART_LPUBAUD_BREN_Pos                  (8)
#define  LPUART_LPUBAUD_BREN_Msk                  (0x1U << LPUART_LPUBAUD_BREN_Pos)                 /*!<*/
#define  LPUART_LPUBAUD_BREN                      LPUART_LPUBAUD_BREN_Msk
#define  LPUART_LPUBAUD_BR_Pos                    (16)
#define  LPUART_LPUBAUD_BR_Msk                    (0xFFFFU << LPUART_LPUBAUD_BR_Pos)                /*!<*/
#define  LPUART_LPUBAUD_BR                        LPUART_LPUBAUD_BR_Msk
#define  LPUART_LPUBAUD_BR_Bit0                   (0x0001U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit1                   (0x0002U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit2                   (0x0004U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit3                   (0x0008U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit4                   (0x0010U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit5                   (0x0020U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit6                   (0x0040U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit7                   (0x0080U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit8                   (0x0100U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit9                   (0x0200U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit10                  (0x0400U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit11                  (0x0800U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit12                  (0x1000U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit13                  (0x2000U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit14                  (0x4000U << LPUART_LPUBAUD_BR_Pos) 
#define  LPUART_LPUBAUD_BR_Bit15                  (0x8000U << LPUART_LPUBAUD_BR_Pos) 

/**
  * @brief LPUART_MODU Register Bit Definition
  */
#define  LPUART_MODU_MCTL_Pos                     (0)
#define  LPUART_MODU_MCTL_Msk                     (0xFFFU << LPUART_MODU_MCTL_Pos)                  /*!<*/
#define  LPUART_MODU_MCTL                         LPUART_MODU_MCTL_Msk
#define  LPUART_MODU_MCTL_Bit0                    (0x001U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit1                    (0x002U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit2                    (0x004U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit3                    (0x008U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit4                    (0x010U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit5                    (0x020U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit6                    (0x040U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit7                    (0x080U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit8                    (0x100U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit9                    (0x200U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit10                   (0x400U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_Bit11                   (0x800U << LPUART_MODU_MCTL_Pos) 

/**
  * @brief LPUART_LPUIF Register Bit Definition
  */
#define  LPUART_LPUIF_RXIF_Pos                    (0)
#define  LPUART_LPUIF_RXIF_Msk                    (0x1U << LPUART_LPUIF_RXIF_Pos)                   /*!<*/
#define  LPUART_LPUIF_RXIF                        LPUART_LPUIF_RXIF_Msk
#define  LPUART_LPUIF_TXIF_Pos                    (1)
#define  LPUART_LPUIF_TXIF_Msk                    (0x1U << LPUART_LPUIF_TXIF_Pos)                   /*!<*/
#define  LPUART_LPUIF_TXIF                        LPUART_LPUIF_TXIF_Msk
#define  LPUART_LPUIF_RXNEGIF_Pos                 (2)
#define  LPUART_LPUIF_RXNEGIF_Msk                 (0x1U << LPUART_LPUIF_RXNEGIF_Pos)                /*!<*/
#define  LPUART_LPUIF_RXNEGIF                     LPUART_LPUIF_RXNEGIF_Msk
#define  LPUART_LPUIF_TC_IF_Pos                   (3)
#define  LPUART_LPUIF_TC_IF_Msk                   (0x1U << LPUART_LPUIF_TC_IF_Pos)                  /*!<*/
#define  LPUART_LPUIF_TC_IF                       LPUART_LPUIF_TC_IF_Msk

/**
  * @brief LPUART_LPUSTA Register Bit Definition
  */
#define  LPUART_LPUSTA_RXOV_Pos                   (0)
#define  LPUART_LPUSTA_RXOV_Msk                   (0x1U << LPUART_LPUSTA_RXOV_Pos)                  /*!<*/
#define  LPUART_LPUSTA_RXOV                       LPUART_LPUSTA_RXOV_Msk
#define  LPUART_LPUSTA_FERR_Pos                   (1)
#define  LPUART_LPUSTA_FERR_Msk                   (0x1U << LPUART_LPUSTA_FERR_Pos)                  /*!<*/
#define  LPUART_LPUSTA_FERR                       LPUART_LPUSTA_FERR_Msk
#define  LPUART_LPUSTA_MATCH_Pos                  (2)
#define  LPUART_LPUSTA_MATCH_Msk                  (0x1U << LPUART_LPUSTA_MATCH_Pos)                 /*!<*/
#define  LPUART_LPUSTA_MATCH                      LPUART_LPUSTA_MATCH_Msk
#define  LPUART_LPUSTA_RXF_Pos                    (3)
#define  LPUART_LPUSTA_RXF_Msk                    (0x1U << LPUART_LPUSTA_RXF_Pos)                   /*!<*/
#define  LPUART_LPUSTA_RXF                        LPUART_LPUSTA_RXF_Msk
#define  LPUART_LPUSTA_TXE_Pos                    (4)
#define  LPUART_LPUSTA_TXE_Msk                    (0x1U << LPUART_LPUSTA_TXE_Pos)                   /*!<*/
#define  LPUART_LPUSTA_TXE                        LPUART_LPUSTA_TXE_Msk
#define  LPUART_LPUSTA_TC_Pos                     (5)
#define  LPUART_LPUSTA_TC_Msk                     (0x1U << LPUART_LPUSTA_TC_Pos)                    /*!<*/
#define  LPUART_LPUSTA_TC                         LPUART_LPUSTA_TC_Msk
#define  LPUART_LPUSTA_PERR_Pos                   (6)
#define  LPUART_LPUSTA_PERR_Msk                   (0x1U << LPUART_LPUSTA_PERR_Pos)                  /*!<*/
#define  LPUART_LPUSTA_PERR                       LPUART_LPUSTA_PERR_Msk
#define  LPUART_LPUSTA_START_Pos                  (7)
#define  LPUART_LPUSTA_START_Msk                  (0x1U << LPUART_LPUSTA_START_Pos)                 /*!<*/
#define  LPUART_LPUSTA_START                      LPUART_LPUSTA_START_Msk

/**
  * @brief LPUART_LPUCON Register Bit Definition
  */
#define  LPUART_LPUCON_RXIE_Pos                   (0)
#define  LPUART_LPUCON_RXIE_Msk                   (0x1U << LPUART_LPUCON_RXIE_Pos)                  /*!<*/
#define  LPUART_LPUCON_RXIE                       LPUART_LPUCON_RXIE_Msk
#define  LPUART_LPUCON_NEDET_Pos                  (1)
#define  LPUART_LPUCON_NEDET_Msk                  (0x1U << LPUART_LPUCON_NEDET_Pos)                 /*!<*/
#define  LPUART_LPUCON_NEDET                      LPUART_LPUCON_NEDET_Msk
#define  LPUART_LPUCON_TXIE_Pos                   (2)
#define  LPUART_LPUCON_TXIE_Msk                   (0x1U << LPUART_LPUCON_TXIE_Pos)                  /*!<*/
#define  LPUART_LPUCON_TXIE                       LPUART_LPUCON_TXIE_Msk
#define  LPUART_LPUCON_TCIE_Pos                   (3)
#define  LPUART_LPUCON_TCIE_Msk                   (0x1U << LPUART_LPUCON_TCIE_Pos)                  /*!<*/
#define  LPUART_LPUCON_TCIE                       LPUART_LPUCON_TCIE_Msk
#define  LPUART_LPUCON_ERRIE_Pos                  (4)
#define  LPUART_LPUCON_ERRIE_Msk                  (0x1U << LPUART_LPUCON_ERRIE_Pos)                 /*!<*/
#define  LPUART_LPUCON_ERRIE                      LPUART_LPUCON_ERRIE_Msk
#define  LPUART_LPUCON_RXEV_Pos                   (5)
#define  LPUART_LPUCON_RXEV_Msk                   (0x3U << LPUART_LPUCON_RXEV_Pos)                  /*!<*/
#define  LPUART_LPUCON_RXEV                       LPUART_LPUCON_RXEV_Msk
#define  LPUART_LPUCON_RXEV_Bit0                  (0x1U << LPUART_LPUCON_RXEV_Pos) 
#define  LPUART_LPUCON_RXEV_Bit1                  (0x2U << LPUART_LPUCON_RXEV_Pos) 
#define  LPUART_LPUCON_DL_Pos                     (7)
#define  LPUART_LPUCON_DL_Msk                     (0x1U << LPUART_LPUCON_DL_Pos)                    /*!<*/
#define  LPUART_LPUCON_DL                         LPUART_LPUCON_DL_Msk
#define  LPUART_LPUCON_SL_Pos                     (8)
#define  LPUART_LPUCON_SL_Msk                     (0x1U << LPUART_LPUCON_SL_Pos)                    /*!<*/
#define  LPUART_LPUCON_SL                         LPUART_LPUCON_SL_Msk
#define  LPUART_LPUCON_PTYP_Pos                   (9)
#define  LPUART_LPUCON_PTYP_Msk                   (0x1U << LPUART_LPUCON_PTYP_Pos)                  /*!<*/
#define  LPUART_LPUCON_PTYP                       LPUART_LPUCON_PTYP_Msk
#define  LPUART_LPUCON_PAREN_Pos                  (10)
#define  LPUART_LPUCON_PAREN_Msk                  (0x1U << LPUART_LPUCON_PAREN_Pos)                 /*!<*/
#define  LPUART_LPUCON_PAREN                      LPUART_LPUCON_PAREN_Msk
#define  LPUART_LPUCON_RXPOL_Pos                  (11)
#define  LPUART_LPUCON_RXPOL_Msk                  (0x1U << LPUART_LPUCON_RXPOL_Pos)                 /*!<*/
#define  LPUART_LPUCON_RXPOL                      LPUART_LPUCON_RXPOL_Msk
#define  LPUART_LPUCON_TXPOL_Pos                  (12)
#define  LPUART_LPUCON_TXPOL_Msk                  (0x1U << LPUART_LPUCON_TXPOL_Pos)                 /*!<*/
#define  LPUART_LPUCON_TXPOL                      LPUART_LPUCON_TXPOL_Msk

/**
  * @brief LPUART_LPUEN Register Bit Definition
  */
#define  LPUART_LPUEN_TXEN_Pos                    (0)
#define  LPUART_LPUEN_TXEN_Msk                    (0x1U << LPUART_LPUEN_TXEN_Pos)                   /*!<*/
#define  LPUART_LPUEN_TXEN                        LPUART_LPUEN_TXEN_Msk
#define  LPUART_LPUEN_RXEN_Pos                    (1)
#define  LPUART_LPUEN_RXEN_Msk                    (0x1U << LPUART_LPUEN_RXEN_Pos)                   /*!<*/
#define  LPUART_LPUEN_RXEN                        LPUART_LPUEN_RXEN_Msk
#define  LPUART_LPUEN_DMAT_Pos                    (2)
#define  LPUART_LPUEN_DMAT_Msk                    (0x1U << LPUART_LPUEN_DMAT_Pos)                   /*!<*/
#define  LPUART_LPUEN_DMAT                        LPUART_LPUEN_DMAT_Msk
#define  LPUART_LPUEN_DMAR_Pos                    (3)
#define  LPUART_LPUEN_DMAR_Msk                    (0x1U << LPUART_LPUEN_DMAR_Pos)                   /*!<*/
#define  LPUART_LPUEN_DMAR                        LPUART_LPUEN_DMAR_Msk

/**
  * @brief LPUART_LPURXD Register Bit Definition
  */
#define  LPUART_LPURXD_DATA_Pos                   (0)
#define  LPUART_LPURXD_DATA_Msk                   (0xFFU << LPUART_LPURXD_DATA_Pos)                 /*!<*/
#define  LPUART_LPURXD_DATA                       LPUART_LPURXD_DATA_Msk
#define  LPUART_LPURXD_DATA_Bit0                  (0x01U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit1                  (0x02U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit2                  (0x04U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit3                  (0x08U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit4                  (0x10U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit5                  (0x20U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit6                  (0x40U << LPUART_LPURXD_DATA_Pos) 
#define  LPUART_LPURXD_DATA_Bit7                  (0x80U << LPUART_LPURXD_DATA_Pos) 

/**
  * @brief LPUART_LPUTXD Register Bit Definition
  */
#define  LPUART_LPUTXD_DATA_Pos                   (0)
#define  LPUART_LPUTXD_DATA_Msk                   (0xFFU << LPUART_LPUTXD_DATA_Pos)                 /*!<*/
#define  LPUART_LPUTXD_DATA                       LPUART_LPUTXD_DATA_Msk
#define  LPUART_LPUTXD_DATA_Bit0                  (0x01U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit1                  (0x02U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit2                  (0x04U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit3                  (0x08U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit4                  (0x10U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit5                  (0x20U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit6                  (0x40U << LPUART_LPUTXD_DATA_Pos) 
#define  LPUART_LPUTXD_DATA_Bit7                  (0x80U << LPUART_LPUTXD_DATA_Pos) 

/**
  * @brief LPUART_COMPARE Register Bit Definition
  */
#define  LPUART_COMPARE_COMPARE_Pos               (0)
#define  LPUART_COMPARE_COMPARE_Msk               (0xFFU << LPUART_COMPARE_COMPARE_Pos)             /*!<*/
#define  LPUART_COMPARE_COMPARE                   LPUART_COMPARE_COMPARE_Msk
#define  LPUART_COMPARE_COMPARE_Bit0              (0x01U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit1              (0x02U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit2              (0x04U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit3              (0x08U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit4              (0x10U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit5              (0x20U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit6              (0x40U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_Bit7              (0x80U << LPUART_COMPARE_COMPARE_Pos) 

/**
  * @brief LPUART_WKCKE Register Bit Definition
  */
#define  LPUART_WKCKE_WKCKE_Pos                   (0)
#define  LPUART_WKCKE_WKCKE_Msk                   (0x1U << LPUART_WKCKE_WKCKE_Pos)                  /*!<*/
#define  LPUART_WKCKE_WKCKE                       LPUART_WKCKE_WKCKE_Msk


#endif

