/***********************************************************************************************************************
    @file     reg_spi.h
    @author   VV TEAM
    @brief    This flie contains all the SPI's register and its field definition.
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

#ifndef __REG_SPI_H
#define __REG_SPI_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief SPI Base Address Definition
  */
#define  SPI1_BASE                                 0x40013000                                       /*!<Base Address: 0x40013000*/

/**
  * @brief SPI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TXREG;                          /*!<SPI Transmission Data Register                 offset: 0x00       */
    __IO uint32_t RXREG;                          /*!<SPI Receipt Data Register                      offset: 0x04       */
    __IO uint32_t CSTAT;                          /*!<SPI Current Status Register                    offset: 0x08       */
    __IO uint32_t INTSTAT;                        /*!<SPI Interrupt Status Register                  offset: 0x0C       */
    __IO uint32_t INTEN;                          /*!<SPI Interrupt Enable Register                  offset: 0x10       */
    __IO uint32_t INTCLR;                         /*!<SPI Interrupt Clear Register                   offset: 0x14       */
    __IO uint32_t GCTL;                           /*!<SPI Global Control Register                    offset: 0x18       */
    __IO uint32_t CCTL;                           /*!<SPI Universal Control Register                 offset: 0x1C       */
    __IO uint32_t SPBRG;                          /*!<SPI Baud Rate Generator                        offset: 0x20       */
    __IO uint32_t RXDNR;                          /*!<SPI Receipt Data Number Register               offset: 0x24       */
    __IO uint32_t NSSR;                           /*!<SPI Slave Chip Selection Register              offset: 0x28       */
    __IO uint32_t EXTCTL;                         /*!<SPI Data Length Control Register               offset: 0x2C       */
} SPI_TypeDef;

/**
  * @brief SPI type pointer Definition
  */
#define SPI1                                      ((SPI_TypeDef *)SPI1_BASE)

/**
  * @brief SPI_TXREG Register Bit Definition
  */
#define  SPI_TXREG_TXREG_Pos                      (0)
#define  SPI_TXREG_TXREG_Msk                      (0xFFFFFFFFU << SPI_TXREG_TXREG_Pos)              /*!<Transmission data register*/
#define  SPI_TXREG_TXREG                          SPI_TXREG_TXREG_Msk
#define  SPI_TXREG_TXREG_Bit0                     (0x00000001U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit1                     (0x00000002U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit2                     (0x00000004U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit3                     (0x00000008U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit4                     (0x00000010U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit5                     (0x00000020U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit6                     (0x00000040U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit7                     (0x00000080U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit8                     (0x00000100U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit9                     (0x00000200U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit10                    (0x00000400U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit11                    (0x00000800U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit12                    (0x00001000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit13                    (0x00002000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit14                    (0x00004000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit15                    (0x00008000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit16                    (0x00010000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit17                    (0x00020000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit18                    (0x00040000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit19                    (0x00080000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit20                    (0x00100000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit21                    (0x00200000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit22                    (0x00400000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit23                    (0x00800000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit24                    (0x01000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit25                    (0x02000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit26                    (0x04000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit27                    (0x08000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit28                    (0x10000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit29                    (0x20000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit30                    (0x40000000U << SPI_TXREG_TXREG_Pos) 
#define  SPI_TXREG_TXREG_Bit31                    (0x80000000U << SPI_TXREG_TXREG_Pos) 

/**
  * @brief SPI_RXREG Register Bit Definition
  */
#define  SPI_RXREG_RXREG_Pos                      (0)
#define  SPI_RXREG_RXREG_Msk                      (0xFFFFFFFFU << SPI_RXREG_RXREG_Pos)              /*!<Receipt data register*/
#define  SPI_RXREG_RXREG                          SPI_RXREG_RXREG_Msk
#define  SPI_RXREG_RXREG_Bit0                     (0x00000001U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit1                     (0x00000002U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit2                     (0x00000004U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit3                     (0x00000008U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit4                     (0x00000010U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit5                     (0x00000020U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit6                     (0x00000040U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit7                     (0x00000080U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit8                     (0x00000100U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit9                     (0x00000200U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit10                    (0x00000400U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit11                    (0x00000800U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit12                    (0x00001000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit13                    (0x00002000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit14                    (0x00004000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit15                    (0x00008000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit16                    (0x00010000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit17                    (0x00020000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit18                    (0x00040000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit19                    (0x00080000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit20                    (0x00100000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit21                    (0x00200000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit22                    (0x00400000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit23                    (0x00800000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit24                    (0x01000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit25                    (0x02000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit26                    (0x04000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit27                    (0x08000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit28                    (0x10000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit29                    (0x20000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit30                    (0x40000000U << SPI_RXREG_RXREG_Pos) 
#define  SPI_RXREG_RXREG_Bit31                    (0x80000000U << SPI_RXREG_RXREG_Pos) 

/**
  * @brief SPI_CSTAT Register Bit Definition
  */
#define  SPI_CSTAT_TXEPT_Pos                      (0)
#define  SPI_CSTAT_TXEPT_Msk                      (0x1U << SPI_CSTAT_TXEPT_Pos)                     /*!<Transmission empty bit*/
#define  SPI_CSTAT_TXEPT                          SPI_CSTAT_TXEPT_Msk
#define  SPI_CSTAT_RXAVL_Pos                      (1)
#define  SPI_CSTAT_RXAVL_Msk                      (0x1U << SPI_CSTAT_RXAVL_Pos)                     /*!<Receipt valid byte data message bit*/
#define  SPI_CSTAT_RXAVL                          SPI_CSTAT_RXAVL_Msk
#define  SPI_CSTAT_TXFULL_Pos                     (2)
#define  SPI_CSTAT_TXFULL_Msk                     (0x1U << SPI_CSTAT_TXFULL_Pos)                    /*!<Transmission buffer full flag bit*/
#define  SPI_CSTAT_TXFULL                         SPI_CSTAT_TXFULL_Msk
#define  SPI_CSTAT_RXAVL_4BYTE_Pos                (3)
#define  SPI_CSTAT_RXAVL_4BYTE_Msk                (0x1U << SPI_CSTAT_RXAVL_4BYTE_Pos)               /*!<Valid data in the receipt buffer reaches 4 byte flag bit*/
#define  SPI_CSTAT_RXAVL_4BYTE                    SPI_CSTAT_RXAVL_4BYTE_Msk
#define  SPI_CSTAT_TXFADDR_Pos                    (4)
#define  SPI_CSTAT_TXFADDR_Msk                    (0x7U << SPI_CSTAT_TXFADDR_Pos)                   /*!<Number of valid byte in the transmission buffer*/
#define  SPI_CSTAT_TXFADDR                        SPI_CSTAT_TXFADDR_Msk
#define  SPI_CSTAT_TXFADDR_Bit0                   (0x1U << SPI_CSTAT_TXFADDR_Pos) 
#define  SPI_CSTAT_TXFADDR_Bit1                   (0x2U << SPI_CSTAT_TXFADDR_Pos) 
#define  SPI_CSTAT_TXFADDR_Bit2                   (0x4U << SPI_CSTAT_TXFADDR_Pos) 
#define  SPI_CSTAT_RXFADDR_Pos                    (8)
#define  SPI_CSTAT_RXFADDR_Msk                    (0x7U << SPI_CSTAT_RXFADDR_Pos)                   /*!<Number of valid byte in the current buffer*/
#define  SPI_CSTAT_RXFADDR                        SPI_CSTAT_RXFADDR_Msk
#define  SPI_CSTAT_RXFADDR_Bit0                   (0x1U << SPI_CSTAT_RXFADDR_Pos) 
#define  SPI_CSTAT_RXFADDR_Bit1                   (0x2U << SPI_CSTAT_RXFADDR_Pos) 
#define  SPI_CSTAT_RXFADDR_Bit2                   (0x4U << SPI_CSTAT_RXFADDR_Pos) 

/**
  * @brief SPI_INTSTAT Register Bit Definition
  */
#define  SPI_INTSTAT_TX_INTF_Pos                  (0)
#define  SPI_INTSTAT_TX_INTF_Msk                  (0x1U << SPI_INTSTAT_TX_INTF_Pos)                 /*!<Transmission buffer empty interrupt flag bit (buffer is empty, can write TXREG)*/
#define  SPI_INTSTAT_TX_INTF                      SPI_INTSTAT_TX_INTF_Msk
#define  SPI_INTSTAT_RX_INTF_Pos                  (1)
#define  SPI_INTSTAT_RX_INTF_Msk                  (0x1U << SPI_INTSTAT_RX_INTF_Pos)                 /*!<Receipt data valid interrupt flag bit Auto set by the hardware, clear by writing INTCLR register RX_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RX_INTF                      SPI_INTSTAT_RX_INTF_Msk
#define  SPI_INTSTAT_UNDERRUN_INTF_Pos            (2)
#define  SPI_INTSTAT_UNDERRUN_INTF_Msk            (0x1U << SPI_INTSTAT_UNDERRUN_INTF_Pos)           /*!<SPI auxiliary mode underflow interrupt flag bit Auto set by the hardware, clear by writing INTCLR.UNDERRUN_ICLR bit as '1'.*/
#define  SPI_INTSTAT_UNDERRUN_INTF                SPI_INTSTAT_UNDERRUN_INTF_Msk
#define  SPI_INTSTAT_RXOERR_INTF_Pos              (3)
#define  SPI_INTSTAT_RXOERR_INTF_Msk              (0x1U << SPI_INTSTAT_RXOERR_INTF_Pos)             /*!<Receipt overflow error interrupt flag bit Auto set by the hardware, clear by writing INTCLR register RXOERR_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RXOERR_INTF                  SPI_INTSTAT_RXOERR_INTF_Msk
#define  SPI_INTSTAT_RXMATCH_INTF_Pos             (4)
#define  SPI_INTSTAT_RXMATCH_INTF_Msk             (0x1U << SPI_INTSTAT_RXMATCH_INTF_Pos)            /*!<Receipt specified byte interrupt flag bit Auto set by the hardware, clear by writing INTCLR register RXMATCH_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RXMATCH_INTF                 SPI_INTSTAT_RXMATCH_INTF_Msk
#define  SPI_INTSTAT_RXFULL_INTF_Pos              (5)
#define  SPI_INTSTAT_RXFULL_INTF_Msk              (0x1U << SPI_INTSTAT_RXFULL_INTF_Pos)             /*!<Receipt buffer full interrupt flag bit Auto set by the hardware, clear by writing INTCLR register RXFULL_ICLR bit as '1'.*/
#define  SPI_INTSTAT_RXFULL_INTF                  SPI_INTSTAT_RXFULL_INTF_Msk
#define  SPI_INTSTAT_TXEPT_INTF_Pos               (6)
#define  SPI_INTSTAT_TXEPT_INTF_Msk               (0x1U << SPI_INTSTAT_TXEPT_INTF_Pos)              /*!<Transmission empty interrupt flag bit Auto set by the hardware, clear by writing the INTCLR. TXEPT_ICLR bit as '1'.*/
#define  SPI_INTSTAT_TXEPT_INTF                   SPI_INTSTAT_TXEPT_INTF_Msk

/**
  * @brief SPI_INTEN Register Bit Definition
  */
#define  SPI_INTEN_TX_IEN_Pos                     (0)
#define  SPI_INTEN_TX_IEN_Msk                     (0x1U << SPI_INTEN_TX_IEN_Pos)                    /*!<Transmission buffer empty interrupt enable bit*/
#define  SPI_INTEN_TX_IEN                         SPI_INTEN_TX_IEN_Msk
#define  SPI_INTEN_RX_IEN_Pos                     (1)
#define  SPI_INTEN_RX_IEN_Msk                     (0x1U << SPI_INTEN_RX_IEN_Pos)                    /*!<Receipt data interrupt enable bit*/
#define  SPI_INTEN_RX_IEN                         SPI_INTEN_RX_IEN_Msk
#define  SPI_INTEN_UNDERRUN_IEN_Pos               (2)
#define  SPI_INTEN_UNDERRUN_IEN_Msk               (0x1U << SPI_INTEN_UNDERRUN_IEN_Pos)              /*!<SPI auxiliary mode underflow interrupt enable bit*/
#define  SPI_INTEN_UNDERRUN_IEN                   SPI_INTEN_UNDERRUN_IEN_Msk
#define  SPI_INTEN_RXOERR_IEN_Pos                 (3)
#define  SPI_INTEN_RXOERR_IEN_Msk                 (0x1U << SPI_INTEN_RXOERR_IEN_Pos)                /*!<Receipt overflow error interrupt enable bit*/
#define  SPI_INTEN_RXOERR_IEN                     SPI_INTEN_RXOERR_IEN_Msk
#define  SPI_INTEN_RXMATCH_IEN_Pos                (4)
#define  SPI_INTEN_RXMATCH_IEN_Msk                (0x1U << SPI_INTEN_RXMATCH_IEN_Pos)               /*!<Receipt specified byte interrupt enable bit*/
#define  SPI_INTEN_RXMATCH_IEN                    SPI_INTEN_RXMATCH_IEN_Msk
#define  SPI_INTEN_RXFULL_IEN_Pos                 (5)
#define  SPI_INTEN_RXFULL_IEN_Msk                 (0x1U << SPI_INTEN_RXFULL_IEN_Pos)                /*!<Receipt buffer full interrupt enable bit*/
#define  SPI_INTEN_RXFULL_IEN                     SPI_INTEN_RXFULL_IEN_Msk
#define  SPI_INTEN_TXEPT_IEN_Pos                  (6)
#define  SPI_INTEN_TXEPT_IEN_Msk                  (0x1U << SPI_INTEN_TXEPT_IEN_Pos)                 /*!<Transmission empty interrupt enable bit*/
#define  SPI_INTEN_TXEPT_IEN                      SPI_INTEN_TXEPT_IEN_Msk

/**
  * @brief SPI_INTCLR Register Bit Definition
  */
#define  SPI_INTCLR_TX_ICLR_Pos                   (0)
#define  SPI_INTCLR_TX_ICLR_Msk                   (0x1U << SPI_INTCLR_TX_ICLR_Pos)                  /*!<Transmission buffer empty interrupt clear bit*/
#define  SPI_INTCLR_TX_ICLR                       SPI_INTCLR_TX_ICLR_Msk
#define  SPI_INTCLR_RX_ICLR_Pos                   (1)
#define  SPI_INTCLR_RX_ICLR_Msk                   (0x1U << SPI_INTCLR_RX_ICLR_Pos)                  /*!<Receipt interrupt clear bit*/
#define  SPI_INTCLR_RX_ICLR                       SPI_INTCLR_RX_ICLR_Msk
#define  SPI_INTCLR_UNDERRUN_ICLR_Pos             (2)
#define  SPI_INTCLR_UNDERRUN_ICLR_Msk             (0x1U << SPI_INTCLR_UNDERRUN_ICLR_Pos)            /*!<SPI auxiliary mode underflow interrupt clear bit*/
#define  SPI_INTCLR_UNDERRUN_ICLR                 SPI_INTCLR_UNDERRUN_ICLR_Msk
#define  SPI_INTCLR_RXOERR_ICLR_Pos               (3)
#define  SPI_INTCLR_RXOERR_ICLR_Msk               (0x1U << SPI_INTCLR_RXOERR_ICLR_Pos)              /*!<Receipt overflow error interrupt clear bit*/
#define  SPI_INTCLR_RXOERR_ICLR                   SPI_INTCLR_RXOERR_ICLR_Msk
#define  SPI_INTCLR_RXMATCH_ICLR_Pos              (4)
#define  SPI_INTCLR_RXMATCH_ICLR_Msk              (0x1U << SPI_INTCLR_RXMATCH_ICLR_Pos)             /*!<Receipt specified byte interrupt clear bit*/
#define  SPI_INTCLR_RXMATCH_ICLR                  SPI_INTCLR_RXMATCH_ICLR_Msk
#define  SPI_INTCLR_RXFULL_ICLR_Pos               (5)
#define  SPI_INTCLR_RXFULL_ICLR_Msk               (0x1U << SPI_INTCLR_RXFULL_ICLR_Pos)              /*!<Receipt buffer full interrupt clear bit*/
#define  SPI_INTCLR_RXFULL_ICLR                   SPI_INTCLR_RXFULL_ICLR_Msk
#define  SPI_INTCLR_TXEPT_ICLR_Pos                (6)
#define  SPI_INTCLR_TXEPT_ICLR_Msk                (0x1U << SPI_INTCLR_TXEPT_ICLR_Pos)               /*!<Transmission empty interrupt clear bit*/
#define  SPI_INTCLR_TXEPT_ICLR                    SPI_INTCLR_TXEPT_ICLR_Msk

/**
  * @brief SPI_GCTL Register Bit Definition
  */
#define  SPI_GCTL_SPIEN_Pos                       (0)
#define  SPI_GCTL_SPIEN_Msk                       (0x1U << SPI_GCTL_SPIEN_Pos)                      /*!<SPI selection bit*/
#define  SPI_GCTL_SPIEN                           SPI_GCTL_SPIEN_Msk
#define  SPI_GCTL_INTEN_Pos                       (1)
#define  SPI_GCTL_INTEN_Msk                       (0x1U << SPI_GCTL_INTEN_Pos)                      /*!<SPI interrupt enable bit*/
#define  SPI_GCTL_INTEN                           SPI_GCTL_INTEN_Msk
#define  SPI_GCTL_MODE_Pos                        (2)
#define  SPI_GCTL_MODE_Msk                        (0x1U << SPI_GCTL_MODE_Pos)                       /*!<Host mode bit*/
#define  SPI_GCTL_MODE                            SPI_GCTL_MODE_Msk
#define  SPI_GCTL_TXEN_Pos                        (3)
#define  SPI_GCTL_TXEN_Msk                        (0x1U << SPI_GCTL_TXEN_Pos)                       /*!<Transmission enable bit*/
#define  SPI_GCTL_TXEN                            SPI_GCTL_TXEN_Msk
#define  SPI_GCTL_RXEN_Pos                        (4)
#define  SPI_GCTL_RXEN_Msk                        (0x1U << SPI_GCTL_RXEN_Pos)                       /*!<Receipt enable bit*/
#define  SPI_GCTL_RXEN                            SPI_GCTL_RXEN_Msk
#define  SPI_GCTL_NSS_M_Pos                       (10)
#define  SPI_GCTL_NSS_M_Msk                       (0x1U << SPI_GCTL_NSS_M_Pos)                      /*!<NSS output in the hardware or software control master mode*/
#define  SPI_GCTL_NSS_M                           SPI_GCTL_NSS_M_Msk
#define  SPI_GCTL_DW8_32_Pos                      (11)
#define  SPI_GCTL_DW8_32_Msk                      (0x1U << SPI_GCTL_DW8_32_Pos)                     /*!<Transmission and receipt data register valid data selection*/
#define  SPI_GCTL_DW8_32                          SPI_GCTL_DW8_32_Msk
#define  SPI_GCTL_PAD_SEL_Pos                     (13)
#define  SPI_GCTL_PAD_SEL_Msk                     (0x1FU << SPI_GCTL_PAD_SEL_Pos)                   /*!<*/
#define  SPI_GCTL_PAD_SEL                         SPI_GCTL_PAD_SEL_Msk
#define  SPI_GCTL_PAD_SEL_Bit0                    (0x01U << SPI_GCTL_PAD_SEL_Pos) 
#define  SPI_GCTL_PAD_SEL_Bit1                    (0x02U << SPI_GCTL_PAD_SEL_Pos) 
#define  SPI_GCTL_PAD_SEL_Bit2                    (0x04U << SPI_GCTL_PAD_SEL_Pos) 
#define  SPI_GCTL_PAD_SEL_Bit3                    (0x08U << SPI_GCTL_PAD_SEL_Pos) 
#define  SPI_GCTL_PAD_SEL_Bit4                    (0x10U << SPI_GCTL_PAD_SEL_Pos) 
#define  SPI_GCTL_NSS_S_Pos                       (18)
#define  SPI_GCTL_NSS_S_Msk                       (0x1U << SPI_GCTL_NSS_S_Pos)                      /*!<NSS select signal that from software or external PAD.*/
#define  SPI_GCTL_NSS_S                           SPI_GCTL_NSS_S_Msk

/**
  * @brief SPI_CCTL Register Bit Definition
  */
#define  SPI_CCTL_CPHA_Pos                        (0)
#define  SPI_CCTL_CPHA_Msk                        (0x1U << SPI_CCTL_CPHA_Pos)                       /*!<Clock phase selection bit*/
#define  SPI_CCTL_CPHA                            SPI_CCTL_CPHA_Msk
#define  SPI_CCTL_CPOL_Pos                        (1)
#define  SPI_CCTL_CPOL_Msk                        (0x1U << SPI_CCTL_CPOL_Pos)                       /*!<Clock polarity flag bit*/
#define  SPI_CCTL_CPOL                            SPI_CCTL_CPOL_Msk
#define  SPI_CCTL_LSBFE_Pos                       (2)
#define  SPI_CCTL_LSBFE_Msk                       (0x1U << SPI_CCTL_LSBFE_Pos)                      /*!<LSBFE:LSB front enable bit*/
#define  SPI_CCTL_LSBFE                           SPI_CCTL_LSBFE_Msk
#define  SPI_CCTL_SPILEN_Pos                      (3)
#define  SPI_CCTL_SPILEN_Msk                      (0x1U << SPI_CCTL_SPILEN_Pos)                     /*!<SPI data width bit*/
#define  SPI_CCTL_SPILEN                          SPI_CCTL_SPILEN_Msk
#define  SPI_CCTL_RXEDGE_Pos                      (4)
#define  SPI_CCTL_RXEDGE_Msk                      (0x1U << SPI_CCTL_RXEDGE_Pos)                     /*!<Receipt data sampling clock edge selection bit (master mode)*/
#define  SPI_CCTL_RXEDGE                          SPI_CCTL_RXEDGE_Msk
#define  SPI_CCTL_TXEDGE_Pos                      (5)
#define  SPI_CCTL_TXEDGE_Msk                      (0x1U << SPI_CCTL_TXEDGE_Pos)                     /*!<Transmission data phase bit adjustment (slave mode)*/
#define  SPI_CCTL_TXEDGE                          SPI_CCTL_TXEDGE_Msk
#define  SPI_CCTL_CPHASEL_Pos                     (6)
#define  SPI_CCTL_CPHASEL_Msk                     (0x1U << SPI_CCTL_CPHASEL_Pos)                    /*!<CPHA polarity inversion selection*/
#define  SPI_CCTL_CPHASEL                         SPI_CCTL_CPHASEL_Msk
#define  SPI_CCTL_MRDECHG_Pos                     (8)
#define  SPI_CCTL_MRDECHG_Msk                     (0x7U << SPI_CCTL_MRDECHG_Pos)                    /*!<*/
#define  SPI_CCTL_MRDECHG                         SPI_CCTL_MRDECHG_Msk
#define  SPI_CCTL_MRDECHG_Bit0                    (0x1U << SPI_CCTL_MRDECHG_Pos) 
#define  SPI_CCTL_MRDECHG_Bit1                    (0x2U << SPI_CCTL_MRDECHG_Pos) 
#define  SPI_CCTL_MRDECHG_Bit2                    (0x4U << SPI_CCTL_MRDECHG_Pos) 

/**
  * @brief SPI_SPBRG Register Bit Definition
  */
#define  SPI_SPBRG_SPBRG_Pos                      (0)
#define  SPI_SPBRG_SPBRG_Msk                      (0xFFFFU << SPI_SPBRG_SPBRG_Pos)                  /*!<SPI baud rate control register for baud rate*/
#define  SPI_SPBRG_SPBRG                          SPI_SPBRG_SPBRG_Msk
#define  SPI_SPBRG_SPBRG_Bit0                     (0x0001U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit1                     (0x0002U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit2                     (0x0004U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit3                     (0x0008U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit4                     (0x0010U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit5                     (0x0020U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit6                     (0x0040U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit7                     (0x0080U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit8                     (0x0100U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit9                     (0x0200U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit10                    (0x0400U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit11                    (0x0800U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit12                    (0x1000U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit13                    (0x2000U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit14                    (0x4000U << SPI_SPBRG_SPBRG_Pos) 
#define  SPI_SPBRG_SPBRG_Bit15                    (0x8000U << SPI_SPBRG_SPBRG_Pos) 

/**
  * @brief SPI_RXDNR Register Bit Definition
  */
#define  SPI_RXDNR_RXDNR_Pos                      (0)
#define  SPI_RXDNR_RXDNR_Msk                      (0xFFFFU << SPI_RXDNR_RXDNR_Pos)                  /*!<The register is used to hold a count of to be received in the next receipt process*/
#define  SPI_RXDNR_RXDNR                          SPI_RXDNR_RXDNR_Msk
#define  SPI_RXDNR_RXDNR_Bit0                     (0x0001U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit1                     (0x0002U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit2                     (0x0004U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit3                     (0x0008U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit4                     (0x0010U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit5                     (0x0020U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit6                     (0x0040U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit7                     (0x0080U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit8                     (0x0100U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit9                     (0x0200U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit10                    (0x0400U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit11                    (0x0800U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit12                    (0x1000U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit13                    (0x2000U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit14                    (0x4000U << SPI_RXDNR_RXDNR_Pos) 
#define  SPI_RXDNR_RXDNR_Bit15                    (0x8000U << SPI_RXDNR_RXDNR_Pos) 

/**
  * @brief SPI_NSSR Register Bit Definition
  */
#define  SPI_NSSR_NSS_Pos                         (0)
#define  SPI_NSSR_NSS_Msk                         (0x1U << SPI_NSSR_NSS_Pos)                        /*!<The chip selection output signal in the master mode. Low valid, the bit is invalid in the slave mode*/
#define  SPI_NSSR_NSS                             SPI_NSSR_NSS_Msk

/**
  * @brief SPI_EXTCTL Register Bit Definition
  */
#define  SPI_EXTCTL_EXTLEN_Pos                    (0)
#define  SPI_EXTCTL_EXTLEN_Msk                    (0x1FU << SPI_EXTCTL_EXTLEN_Pos)                  /*!<Control SPI data length*/
#define  SPI_EXTCTL_EXTLEN                        SPI_EXTCTL_EXTLEN_Msk
#define  SPI_EXTCTL_EXTLEN_Bit0                   (0x01U << SPI_EXTCTL_EXTLEN_Pos) 
#define  SPI_EXTCTL_EXTLEN_Bit1                   (0x02U << SPI_EXTCTL_EXTLEN_Pos) 
#define  SPI_EXTCTL_EXTLEN_Bit2                   (0x04U << SPI_EXTCTL_EXTLEN_Pos) 
#define  SPI_EXTCTL_EXTLEN_Bit3                   (0x08U << SPI_EXTCTL_EXTLEN_Pos) 
#define  SPI_EXTCTL_EXTLEN_Bit4                   (0x10U << SPI_EXTCTL_EXTLEN_Pos) 


#endif

