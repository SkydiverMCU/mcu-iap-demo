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
#include <core_cm0plus.h>



/**
  * @brief LPUART Base Address Definition
  */
#define  LPUART1_BASE                              0x40010800                                       /*!<Base Address: 0x40010800*/
#define  LPUART3_BASE                              0x4000B000                                       /*!<Base Address: 0x4000B000*/
#define  LPUART4_BASE                              0x4000B400                                       /*!<Base Address: 0x4000B400*/
#define  LPUART5_BASE                              0x4000B800                                       /*!<Base Address: 0x4000B800*/
#define  LPUART2_BASE                              0x40010C00                                       /*!<Base Address: 0x40010C00*/

/**
  * @brief LPUART Register Structure Definition
  */
typedef struct
{
    __IO uint32_t BAUD;                           /*!<LPUART Baud Rate Register                      offset: 0x00       */
    __IO uint32_t MODU;                           /*!<LPUART Baud Rate Modulating Control Register   offset: 0x04       */
    __IO uint32_t IFR;                            /*!<LPUART Interrupt Flag Register                 offset: 0x08       */
    __IO uint32_t SR;                             /*!<LPUART Status Register                         offset: 0x0C       */
    __IO uint32_t CR;                             /*!<LPUART Control Register                        offset: 0x10       */
    __IO uint32_t EN;                             /*!<LPUART Ransmission And Reception Enable        offset: 0x14
                                                      Register                                                          */
    __IO uint32_t RXD;                            /*!<LPUART Receive Data Register                   offset: 0x18       */
    __IO uint32_t TXD;                            /*!<LPUART Transmit Data Register                  offset: 0x1C       */
    __IO uint32_t COMPARE;                        /*!<LPUART Compare Register                        offset: 0x20       */
    __IO uint32_t WKCKE;                          /*!<LPUART Wakeup Register                         offset: 0x24       */
} LPUART_TypeDef;

/**
  * @brief LPUART type pointer Definition
  */
#define LPUART1                                   ((LPUART_TypeDef *)LPUART1_BASE)
#define LPUART3                                   ((LPUART_TypeDef *)LPUART3_BASE)
#define LPUART4                                   ((LPUART_TypeDef *)LPUART4_BASE)
#define LPUART5                                   ((LPUART_TypeDef *)LPUART5_BASE)
#define LPUART2                                   ((LPUART_TypeDef *)LPUART2_BASE)

/**
  * @brief LPUART_BAUD Register Bit Definition
  */
#define  LPUART_BAUD_BAUD_Pos                     (0)
#define  LPUART_BAUD_BAUD_Msk                     (0x7U << LPUART_BAUD_BAUD_Pos)                    /*!<Baud rate control, valid only when BREN=0*/
#define  LPUART_BAUD_BAUD                         LPUART_BAUD_BAUD_Msk
#define  LPUART_BAUD_BAUD_0                       (0x1U << LPUART_BAUD_BAUD_Pos) 
#define  LPUART_BAUD_BAUD_1                       (0x2U << LPUART_BAUD_BAUD_Pos) 
#define  LPUART_BAUD_BAUD_2                       (0x4U << LPUART_BAUD_BAUD_Pos) 
#define  LPUART_BAUD_BREN_Pos                     (8)
#define  LPUART_BAUD_BREN_Msk                     (0x1U << LPUART_BAUD_BREN_Pos)                    /*!<Baud rate division enable*/
#define  LPUART_BAUD_BREN                         LPUART_BAUD_BREN_Msk
#define  LPUART_BAUD_BR_Pos                       (16)
#define  LPUART_BAUD_BR_Msk                       (0xFFFFU << LPUART_BAUD_BR_Pos)                   /*!<Baud rate division*/
#define  LPUART_BAUD_BR                           LPUART_BAUD_BR_Msk
#define  LPUART_BAUD_BR_0                         (0x0001U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_1                         (0x0002U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_2                         (0x0004U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_3                         (0x0008U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_4                         (0x0010U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_5                         (0x0020U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_6                         (0x0040U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_7                         (0x0080U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_8                         (0x0100U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_9                         (0x0200U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_10                        (0x0400U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_11                        (0x0800U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_12                        (0x1000U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_13                        (0x2000U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_14                        (0x4000U << LPUART_BAUD_BR_Pos) 
#define  LPUART_BAUD_BR_15                        (0x8000U << LPUART_BAUD_BR_Pos) 

/**
  * @brief LPUART_MODU Register Bit Definition
  */
#define  LPUART_MODU_MCTL_Pos                     (0)
#define  LPUART_MODU_MCTL_Msk                     (0xFFFU << LPUART_MODU_MCTL_Pos)                  /*!<Modulating control signal of each bit in the LPUART*/
#define  LPUART_MODU_MCTL                         LPUART_MODU_MCTL_Msk
#define  LPUART_MODU_MCTL_0                       (0x001U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_1                       (0x002U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_2                       (0x004U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_3                       (0x008U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_4                       (0x010U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_5                       (0x020U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_6                       (0x040U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_7                       (0x080U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_8                       (0x100U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_9                       (0x200U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_10                      (0x400U << LPUART_MODU_MCTL_Pos) 
#define  LPUART_MODU_MCTL_11                      (0x800U << LPUART_MODU_MCTL_Pos) 

/**
  * @brief LPUART_IFR Register Bit Definition
  */
#define  LPUART_IFR_RXIF_Pos                      (0)
#define  LPUART_IFR_RXIF_Msk                      (0x1U << LPUART_IFR_RXIF_Pos)                     /*!<Reception complete interrupt flag*/
#define  LPUART_IFR_RXIF                          LPUART_IFR_RXIF_Msk
#define  LPUART_IFR_TXIF_Pos                      (1)
#define  LPUART_IFR_TXIF_Msk                      (0x1U << LPUART_IFR_TXIF_Pos)                     /*!<Tx buffer empty interrupt flag*/
#define  LPUART_IFR_TXIF                          LPUART_IFR_TXIF_Msk
#define  LPUART_IFR_RXNEGIF_Pos                   (2)
#define  LPUART_IFR_RXNEGIF_Msk                   (0x1U << LPUART_IFR_RXNEGIF_Pos)                  /*!<RXD falling edge interrupt flag*/
#define  LPUART_IFR_RXNEGIF                       LPUART_IFR_RXNEGIF_Msk
#define  LPUART_IFR_TC_IF_Pos                     (3)
#define  LPUART_IFR_TC_IF_Msk                     (0x1U << LPUART_IFR_TC_IF_Pos)                    /*!<Transmission complete interrupt flag*/
#define  LPUART_IFR_TC_IF                         LPUART_IFR_TC_IF_Msk

/**
  * @brief LPUART_SR Register Bit Definition
  */
#define  LPUART_SR_RXOV_Pos                       (0)
#define  LPUART_SR_RXOV_Msk                       (0x1U << LPUART_SR_RXOV_Pos)                      /*!<Rx buffer overrun*/
#define  LPUART_SR_RXOV                           LPUART_SR_RXOV_Msk
#define  LPUART_SR_FERR_Pos                       (1)
#define  LPUART_SR_FERR_Msk                       (0x1U << LPUART_SR_FERR_Pos)                      /*!<Frame format error*/
#define  LPUART_SR_FERR                           LPUART_SR_FERR_Msk
#define  LPUART_SR_MATCH_Pos                      (2)
#define  LPUART_SR_MATCH_Msk                      (0x1U << LPUART_SR_MATCH_Pos)                     /*!<Data match flag*/
#define  LPUART_SR_MATCH                          LPUART_SR_MATCH_Msk
#define  LPUART_SR_RXF_Pos                        (3)
#define  LPUART_SR_RXF_Msk                        (0x1U << LPUART_SR_RXF_Pos)                       /*!<Rx buffer full*/
#define  LPUART_SR_RXF                            LPUART_SR_RXF_Msk
#define  LPUART_SR_TXE_Pos                        (4)
#define  LPUART_SR_TXE_Msk                        (0x1U << LPUART_SR_TXE_Pos)                       /*!<Tx buffer empty flag*/
#define  LPUART_SR_TXE                            LPUART_SR_TXE_Msk
#define  LPUART_SR_TC_Pos                         (5)
#define  LPUART_SR_TC_Msk                         (0x1U << LPUART_SR_TC_Pos)                        /*!<Transmission complete flag*/
#define  LPUART_SR_TC                             LPUART_SR_TC_Msk
#define  LPUART_SR_PERR_Pos                       (6)
#define  LPUART_SR_PERR_Msk                       (0x1U << LPUART_SR_PERR_Pos)                      /*!<Parity error*/
#define  LPUART_SR_PERR                           LPUART_SR_PERR_Msk
#define  LPUART_SR_START_Pos                      (7)
#define  LPUART_SR_START_Msk                      (0x1U << LPUART_SR_START_Pos)                     /*!<Start bit detection flag*/
#define  LPUART_SR_START                          LPUART_SR_START_Msk

/**
  * @brief LPUART_CR Register Bit Definition
  */
#define  LPUART_CR_RXIE_Pos                       (0)
#define  LPUART_CR_RXIE_Msk                       (0x1U << LPUART_CR_RXIE_Pos)                      /*!<Receive interrupt enable*/
#define  LPUART_CR_RXIE                           LPUART_CR_RXIE_Msk
#define  LPUART_CR_NEDET_Pos                      (1)
#define  LPUART_CR_NEDET_Msk                      (0x1U << LPUART_CR_NEDET_Pos)                     /*!<Falling edge sample enable bit*/
#define  LPUART_CR_NEDET                          LPUART_CR_NEDET_Msk
#define  LPUART_CR_TXIE_Pos                       (2)
#define  LPUART_CR_TXIE_Msk                       (0x1U << LPUART_CR_TXIE_Pos)                      /*!<Tx buffer empty interrupt enable*/
#define  LPUART_CR_TXIE                           LPUART_CR_TXIE_Msk
#define  LPUART_CR_TCIE_Pos                       (3)
#define  LPUART_CR_TCIE_Msk                       (0x1U << LPUART_CR_TCIE_Pos)                      /*!<Transmission complete interrupt enable*/
#define  LPUART_CR_TCIE                           LPUART_CR_TCIE_Msk
#define  LPUART_CR_ERRIE_Pos                      (4)
#define  LPUART_CR_ERRIE_Msk                      (0x1U << LPUART_CR_ERRIE_Pos)                     /*!<Error interrupt enable*/
#define  LPUART_CR_ERRIE                          LPUART_CR_ERRIE_Msk
#define  LPUART_CR_RXEV_Pos                       (5)
#define  LPUART_CR_RXEV_Msk                       (0x3U << LPUART_CR_RXEV_Pos)                      /*!<Rx interrupt event configuration*/
#define  LPUART_CR_RXEV                           LPUART_CR_RXEV_Msk
#define  LPUART_CR_RXEV_0                         (0x1U << LPUART_CR_RXEV_Pos) 
#define  LPUART_CR_RXEV_1                         (0x2U << LPUART_CR_RXEV_Pos) 
#define  LPUART_CR_DL_Pos                         (7)
#define  LPUART_CR_DL_Msk                         (0x1U << LPUART_CR_DL_Pos)                        /*!<Data length*/
#define  LPUART_CR_DL                             LPUART_CR_DL_Msk
#define  LPUART_CR_SL_Pos                         (8)
#define  LPUART_CR_SL_Msk                         (0x1U << LPUART_CR_SL_Pos)                        /*!<Stop bit length*/
#define  LPUART_CR_SL                             LPUART_CR_SL_Msk
#define  LPUART_CR_PTYP_Pos                       (9)
#define  LPUART_CR_PTYP_Msk                       (0x1U << LPUART_CR_PTYP_Pos)                      /*!<Parity bit type*/
#define  LPUART_CR_PTYP                           LPUART_CR_PTYP_Msk
#define  LPUART_CR_PAREN_Pos                      (10)
#define  LPUART_CR_PAREN_Msk                      (0x1U << LPUART_CR_PAREN_Pos)                     /*!<Parity bit enable*/
#define  LPUART_CR_PAREN                          LPUART_CR_PAREN_Msk
#define  LPUART_CR_RXPOL_Pos                      (11)
#define  LPUART_CR_RXPOL_Msk                      (0x1U << LPUART_CR_RXPOL_Pos)                     /*!<Reception polarity*/
#define  LPUART_CR_RXPOL                          LPUART_CR_RXPOL_Msk
#define  LPUART_CR_TXPOL_Pos                      (12)
#define  LPUART_CR_TXPOL_Msk                      (0x1U << LPUART_CR_TXPOL_Pos)                     /*!<Transmission polarity*/
#define  LPUART_CR_TXPOL                          LPUART_CR_TXPOL_Msk

/**
  * @brief LPUART_EN Register Bit Definition
  */
#define  LPUART_EN_TXEN_Pos                       (0)
#define  LPUART_EN_TXEN_Msk                       (0x1U << LPUART_EN_TXEN_Pos)                      /*!<Transmit enable*/
#define  LPUART_EN_TXEN                           LPUART_EN_TXEN_Msk
#define  LPUART_EN_RXEN_Pos                       (1)
#define  LPUART_EN_RXEN_Msk                       (0x1U << LPUART_EN_RXEN_Pos)                      /*!<Receive enable*/
#define  LPUART_EN_RXEN                           LPUART_EN_RXEN_Msk
#define  LPUART_EN_DMAT_Pos                       (2)
#define  LPUART_EN_DMAT_Msk                       (0x1U << LPUART_EN_DMAT_Pos)                      /*!<DMA transmit enable*/
#define  LPUART_EN_DMAT                           LPUART_EN_DMAT_Msk
#define  LPUART_EN_DMAR_Pos                       (3)
#define  LPUART_EN_DMAR_Msk                       (0x1U << LPUART_EN_DMAR_Pos)                      /*!<DMA receive enable*/
#define  LPUART_EN_DMAR                           LPUART_EN_DMAR_Msk
#define  LPUART_EN_SYN_RXF_Pos                    (29)
#define  LPUART_EN_SYN_RXF_Msk                    (0x1U << LPUART_EN_SYN_RXF_Pos)                   /*!<Enable RXF synchronous logic*/
#define  LPUART_EN_SYN_RXF                        LPUART_EN_SYN_RXF_Msk
#define  LPUART_EN_SYN_RXD_Pos                    (30)
#define  LPUART_EN_SYN_RXD_Msk                    (0x1U << LPUART_EN_SYN_RXD_Pos)                   /*!<Enable RXD synchronous logic*/
#define  LPUART_EN_SYN_RXD                        LPUART_EN_SYN_RXD_Msk
#define  LPUART_EN_SYN_DMA_Pos                    (31)
#define  LPUART_EN_SYN_DMA_Msk                    (0x1U << LPUART_EN_SYN_DMA_Pos)                   /*!<Enable DMA_REQ synchronous logic*/
#define  LPUART_EN_SYN_DMA                        LPUART_EN_SYN_DMA_Msk

/**
  * @brief LPUART_RXD Register Bit Definition
  */
#define  LPUART_RXD_DATA_Pos                      (0)
#define  LPUART_RXD_DATA_Msk                      (0xFFU << LPUART_RXD_DATA_Pos)                    /*!<Rx data register(only-read)*/
#define  LPUART_RXD_DATA                          LPUART_RXD_DATA_Msk
#define  LPUART_RXD_DATA_0                        (0x01U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_1                        (0x02U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_2                        (0x04U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_3                        (0x08U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_4                        (0x10U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_5                        (0x20U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_6                        (0x40U << LPUART_RXD_DATA_Pos) 
#define  LPUART_RXD_DATA_7                        (0x80U << LPUART_RXD_DATA_Pos) 

/**
  * @brief LPUART_TXD Register Bit Definition
  */
#define  LPUART_TXD_DATA_Pos                      (0)
#define  LPUART_TXD_DATA_Msk                      (0xFFU << LPUART_TXD_DATA_Pos)                    /*!<Tx data register*/
#define  LPUART_TXD_DATA                          LPUART_TXD_DATA_Msk
#define  LPUART_TXD_DATA_0                        (0x01U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_1                        (0x02U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_2                        (0x04U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_3                        (0x08U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_4                        (0x10U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_5                        (0x20U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_6                        (0x40U << LPUART_TXD_DATA_Pos) 
#define  LPUART_TXD_DATA_7                        (0x80U << LPUART_TXD_DATA_Pos) 

/**
  * @brief LPUART_COMPARE Register Bit Definition
  */
#define  LPUART_COMPARE_COMPARE_Pos               (0)
#define  LPUART_COMPARE_COMPARE_Msk               (0xFFU << LPUART_COMPARE_COMPARE_Pos)             /*!<Compare data*/
#define  LPUART_COMPARE_COMPARE                   LPUART_COMPARE_COMPARE_Msk
#define  LPUART_COMPARE_COMPARE_0                 (0x01U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_1                 (0x02U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_2                 (0x04U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_3                 (0x08U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_4                 (0x10U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_5                 (0x20U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_6                 (0x40U << LPUART_COMPARE_COMPARE_Pos) 
#define  LPUART_COMPARE_COMPARE_7                 (0x80U << LPUART_COMPARE_COMPARE_Pos) 

/**
  * @brief LPUART_WKCKE Register Bit Definition
  */
#define  LPUART_WKCKE_LPUART_WKCKE_Pos            (0)
#define  LPUART_WKCKE_LPUART_WKCKE_Msk            (0x1U << LPUART_WKCKE_LPUART_WKCKE_Pos)           /*!<1-byte Sleep mode wakeup control bit*/
#define  LPUART_WKCKE_LPUART_WKCKE                LPUART_WKCKE_LPUART_WKCKE_Msk

#endif

