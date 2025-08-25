/***********************************************************************************************************************
    @file     reg_csm.h
    @author   VV TEAM
    @brief    This flie contains all the CSM's register and its field definition.
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

#ifndef __REG_CSM_H
#define __REG_CSM_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0.h>



/**
  * @brief CSM Base Address Definition
  */
#define  CSM_BASE                                  0x40006800                                       /*!<Base Address: 0x40006800*/

/**
  * @brief CSM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TDR1;                           /*!<CSM CSM transmit data register 1               offset: 0x00       */
    __IO uint32_t RESERVED0x04[1];                /*!<                                               offset: 0x04       */
    __IO uint32_t RDR1;                           /*!<CSM CSM receive data register 1                offset: 0x08       */
    __IO uint32_t RESERVED0x0C[1];                /*!<                                               offset: 0x0C       */
    __IO uint32_t ISR;                            /*!<CSM CSM interrupt status register              offset: 0x10       */
    __IO uint32_t IER;                            /*!<CSM CSM interrupt enable register              offset: 0x14       */
    __IO uint32_t CR1;                            /*!<CSM CSM control register 1                     offset: 0x18       */
    __IO uint32_t RESERVED0x1C[1];                /*!<                                               offset: 0x1C       */
    __IO uint32_t CFG;                            /*!<CSM CSM configuration register                 offset: 0x20       */
    __IO uint32_t SPBRG;                          /*!<CSM CSM baud rate generator                    offset: 0x24       */
    __IO uint32_t BCNT;                           /*!<CSM CSM bit count register                     offset: 0x28       */
} CSM_TypeDef;

/**
  * @brief CSM type pointer Definition
  */
#define CSM                                       ((CSM_TypeDef *)CSM_BASE)

/**
  * @brief CSM_TDR1 Register Bit Definition
  */
#define  CSM_TDR1_TDR1_Pos                        (0)
#define  CSM_TDR1_TDR1_Msk                        (0xFFFFFFFFU << CSM_TDR1_TDR1_Pos)                /*!<Transmit data register 1*/
#define  CSM_TDR1_TDR1                            CSM_TDR1_TDR1_Msk
#define  CSM_TDR1_TDR1_0                          (0x00000001U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_1                          (0x00000002U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_2                          (0x00000004U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_3                          (0x00000008U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_4                          (0x00000010U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_5                          (0x00000020U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_6                          (0x00000040U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_7                          (0x00000080U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_8                          (0x00000100U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_9                          (0x00000200U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_10                         (0x00000400U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_11                         (0x00000800U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_12                         (0x00001000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_13                         (0x00002000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_14                         (0x00004000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_15                         (0x00008000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_16                         (0x00010000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_17                         (0x00020000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_18                         (0x00040000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_19                         (0x00080000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_20                         (0x00100000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_21                         (0x00200000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_22                         (0x00400000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_23                         (0x00800000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_24                         (0x01000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_25                         (0x02000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_26                         (0x04000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_27                         (0x08000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_28                         (0x10000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_29                         (0x20000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_30                         (0x40000000U << CSM_TDR1_TDR1_Pos) 
#define  CSM_TDR1_TDR1_31                         (0x80000000U << CSM_TDR1_TDR1_Pos) 

/**
  * @brief CSM_RDR1 Register Bit Definition
  */
#define  CSM_RDR1_RDR1_Pos                        (0)
#define  CSM_RDR1_RDR1_Msk                        (0xFFFFFFFFU << CSM_RDR1_RDR1_Pos)                /*!<Receive data register 1*/
#define  CSM_RDR1_RDR1                            CSM_RDR1_RDR1_Msk
#define  CSM_RDR1_RDR1_0                          (0x00000001U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_1                          (0x00000002U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_2                          (0x00000004U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_3                          (0x00000008U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_4                          (0x00000010U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_5                          (0x00000020U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_6                          (0x00000040U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_7                          (0x00000080U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_8                          (0x00000100U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_9                          (0x00000200U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_10                         (0x00000400U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_11                         (0x00000800U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_12                         (0x00001000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_13                         (0x00002000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_14                         (0x00004000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_15                         (0x00008000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_16                         (0x00010000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_17                         (0x00020000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_18                         (0x00040000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_19                         (0x00080000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_20                         (0x00100000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_21                         (0x00200000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_22                         (0x00400000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_23                         (0x00800000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_24                         (0x01000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_25                         (0x02000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_26                         (0x04000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_27                         (0x08000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_28                         (0x10000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_29                         (0x20000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_30                         (0x40000000U << CSM_RDR1_RDR1_Pos) 
#define  CSM_RDR1_RDR1_31                         (0x80000000U << CSM_RDR1_RDR1_Pos) 

/**
  * @brief CSM_ISR Register Bit Definition
  */
#define  CSM_ISR_TX_INTF_Pos                      (0)
#define  CSM_ISR_TX_INTF_Msk                      (0x1U << CSM_ISR_TX_INTF_Pos)                     /*!<Transmit FIFO available interrupt flag bit*/
#define  CSM_ISR_TX_INTF                          CSM_ISR_TX_INTF_Msk
#define  CSM_ISR_RX_INTF_Pos                      (1)
#define  CSM_ISR_RX_INTF_Msk                      (0x1U << CSM_ISR_RX_INTF_Pos)                     /*!<Receive data available interrupt flag bit*/
#define  CSM_ISR_RX_INTF                          CSM_ISR_RX_INTF_Msk
#define  CSM_ISR_TXC_INTF_Pos                     (2)
#define  CSM_ISR_TXC_INTF_Msk                     (0x1U << CSM_ISR_TXC_INTF_Pos)                    /*!<Transmit shift register complete interrupt flag bit*/
#define  CSM_ISR_TXC_INTF                         CSM_ISR_TXC_INTF_Msk
#define  CSM_ISR_START_INTF_Pos                   (3)
#define  CSM_ISR_START_INTF_Msk                   (0x1U << CSM_ISR_START_INTF_Pos)                  /*!<Start interrupt flag*/
#define  CSM_ISR_START_INTF                       CSM_ISR_START_INTF_Msk
#define  CSM_ISR_STOP_INTF_Pos                    (4)
#define  CSM_ISR_STOP_INTF_Msk                    (0x1U << CSM_ISR_STOP_INTF_Pos)                   /*!<Stop interrupt flag*/
#define  CSM_ISR_STOP_INTF                        CSM_ISR_STOP_INTF_Msk

/**
  * @brief CSM_IER Register Bit Definition
  */
#define  CSM_IER_TX_IEN_Pos                       (0)
#define  CSM_IER_TX_IEN_Msk                       (0x1U << CSM_IER_TX_IEN_Pos)                      /*!<Transmit FIFO available interrupt enable bit*/
#define  CSM_IER_TX_IEN                           CSM_IER_TX_IEN_Msk
#define  CSM_IER_RX_IEN_Pos                       (1)
#define  CSM_IER_RX_IEN_Msk                       (0x1U << CSM_IER_RX_IEN_Pos)                      /*!<Receive data available interrupt enable bit*/
#define  CSM_IER_RX_IEN                           CSM_IER_RX_IEN_Msk
#define  CSM_IER_TXC_IEN_Pos                      (2)
#define  CSM_IER_TXC_IEN_Msk                      (0x1U << CSM_IER_TXC_IEN_Pos)                     /*!<Transmit shift register complete interrupt enable bit*/
#define  CSM_IER_TXC_IEN                          CSM_IER_TXC_IEN_Msk
#define  CSM_IER_START_IEN_Pos                    (3)
#define  CSM_IER_START_IEN_Msk                    (0x1U << CSM_IER_START_IEN_Pos)                   /*!<Start data reception interrupt enable bit*/
#define  CSM_IER_START_IEN                        CSM_IER_START_IEN_Msk
#define  CSM_IER_STOP_IEN_Pos                     (4)
#define  CSM_IER_STOP_IEN_Msk                     (0x1U << CSM_IER_STOP_IEN_Pos)                    /*!<Stop data reception interrupt enable bit*/
#define  CSM_IER_STOP_IEN                         CSM_IER_STOP_IEN_Msk

/**
  * @brief CSM_CR1 Register Bit Definition
  */
#define  CSM_CR1_EN1_Pos                          (0)
#define  CSM_CR1_EN1_Msk                          (0x1U << CSM_CR1_EN1_Pos)                         /*!<enable the module*/
#define  CSM_CR1_EN1                              CSM_CR1_EN1_Msk
#define  CSM_CR1_IDLEP1_Pos                       (1)
#define  CSM_CR1_IDLEP1_Msk                       (0x1U << CSM_CR1_IDLEP1_Pos)                      /*!<idle level*/
#define  CSM_CR1_IDLEP1                           CSM_CR1_IDLEP1_Msk
#define  CSM_CR1_DMAEN1_Pos                       (3)
#define  CSM_CR1_DMAEN1_Msk                       (0x1U << CSM_CR1_DMAEN1_Pos)                      /*!<enable the DMA*/
#define  CSM_CR1_DMAEN1                           CSM_CR1_DMAEN1_Msk
#define  CSM_CR1_TXSEL1_Pos                       (4)
#define  CSM_CR1_TXSEL1_Msk                       (0x1U << CSM_CR1_TXSEL1_Pos)                      /*!<Select to transmit or receive data*/
#define  CSM_CR1_TXSEL1                           CSM_CR1_TXSEL1_Msk
#define  CSM_CR1_OCSEL_Pos                        (5)
#define  CSM_CR1_OCSEL_Msk                        (0x1U << CSM_CR1_OCSEL_Pos)                       /*!<The bleeder circuit Driver output channel selection*/
#define  CSM_CR1_OCSEL                            CSM_CR1_OCSEL_Msk

/**
  * @brief CSM_CFG Register Bit Definition
  */
#define  CSM_CFG_STARTSEL_Pos                     (0)
#define  CSM_CFG_STARTSEL_Msk                     (0x1U << CSM_CFG_STARTSEL_Pos)                    /*!<start condition detection*/
#define  CSM_CFG_STARTSEL                         CSM_CFG_STARTSEL_Msk
#define  CSM_CFG_STOPSEL_Pos                      (1)
#define  CSM_CFG_STOPSEL_Msk                      (0x1U << CSM_CFG_STOPSEL_Pos)                     /*!<sampling stop condition*/
#define  CSM_CFG_STOPSEL                          CSM_CFG_STOPSEL_Msk
#define  CSM_CFG_VTXEN_Pos                        (3)
#define  CSM_CFG_VTXEN_Msk                        (0x1U << CSM_CFG_VTXEN_Pos)                       /*!<transmit bleeder circuit enable*/
#define  CSM_CFG_VTXEN                            CSM_CFG_VTXEN_Msk
#define  CSM_CFG_MAXBIT_Pos                       (16)
#define  CSM_CFG_MAXBIT_Msk                       (0xFFFFU << CSM_CFG_MAXBIT_Pos)                   /*!<the length of data transferred (in bit)*/
#define  CSM_CFG_MAXBIT                           CSM_CFG_MAXBIT_Msk
#define  CSM_CFG_MAXBIT_0                         (0x0001U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_1                         (0x0002U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_2                         (0x0004U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_3                         (0x0008U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_4                         (0x0010U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_5                         (0x0020U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_6                         (0x0040U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_7                         (0x0080U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_8                         (0x0100U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_9                         (0x0200U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_10                        (0x0400U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_11                        (0x0800U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_12                        (0x1000U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_13                        (0x2000U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_14                        (0x4000U << CSM_CFG_MAXBIT_Pos) 
#define  CSM_CFG_MAXBIT_15                        (0x8000U << CSM_CFG_MAXBIT_Pos) 

/**
  * @brief CSM_SPBRG Register Bit Definition
  */
#define  CSM_SPBRG_SPBRG_Pos                      (0)
#define  CSM_SPBRG_SPBRG_Msk                      (0xFFFFU << CSM_SPBRG_SPBRG_Pos)                  /*!<baud rate control register for sampling clock*/
#define  CSM_SPBRG_SPBRG                          CSM_SPBRG_SPBRG_Msk
#define  CSM_SPBRG_SPBRG_0                        (0x0001U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_1                        (0x0002U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_2                        (0x0004U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_3                        (0x0008U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_4                        (0x0010U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_5                        (0x0020U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_6                        (0x0040U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_7                        (0x0080U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_8                        (0x0100U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_9                        (0x0200U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_10                       (0x0400U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_11                       (0x0800U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_12                       (0x1000U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_13                       (0x2000U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_14                       (0x4000U << CSM_SPBRG_SPBRG_Pos) 
#define  CSM_SPBRG_SPBRG_15                       (0x8000U << CSM_SPBRG_SPBRG_Pos) 

/**
  * @brief CSM_BCNT Register Bit Definition
  */
#define  CSM_BCNT_BCNT_Pos                        (0)
#define  CSM_BCNT_BCNT_Msk                        (0xFFFFU << CSM_BCNT_BCNT_Pos)                    /*!<The length of data bits that are currently received or transmitted. This field is read-only.*/
#define  CSM_BCNT_BCNT                            CSM_BCNT_BCNT_Msk
#define  CSM_BCNT_BCNT_0                          (0x0001U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_1                          (0x0002U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_2                          (0x0004U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_3                          (0x0008U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_4                          (0x0010U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_5                          (0x0020U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_6                          (0x0040U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_7                          (0x0080U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_8                          (0x0100U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_9                          (0x0200U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_10                         (0x0400U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_11                         (0x0800U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_12                         (0x1000U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_13                         (0x2000U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_14                         (0x4000U << CSM_BCNT_BCNT_Pos) 
#define  CSM_BCNT_BCNT_15                         (0x8000U << CSM_BCNT_BCNT_Pos) 


#endif

