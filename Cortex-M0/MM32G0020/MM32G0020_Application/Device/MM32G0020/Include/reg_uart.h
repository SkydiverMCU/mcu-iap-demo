
/***********************************************************************************************************************
    @file     reg_uart.h
    @author   VV TEAM
    @brief    This flie contains all the UART's register and its field definition.
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
#ifndef __REG_UART_H
#define __REG_UART_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0.h"

/**
  * @brief UART Base Address Definition
  */
#define  UART2_BASE                                0x40004400                                       /*!<Base Address: 0x40004400*/
#define  UART1_BASE                                0x40013800                                       /*!<Base Address: 0x40013800*/

/**
  * @brief UART Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TDR;                            /*!<UART UART Transmission Data Register           offset: 0x00       */
    __IO uint32_t RDR;                            /*!<UART UART Receipt Data Register                offset: 0x04       */
    __IO uint32_t CSR;                            /*!<UART UART Current Status Register              offset: 0x08       */
    __IO uint32_t ISR;                            /*!<UART UART Interrupt Status Register            offset: 0x0C       */
    __IO uint32_t IER;                            /*!<UART UART Interrupt Enable Register            offset: 0x10       */
    __IO uint32_t ICR;                            /*!<UART UART Interrupt Clear Register             offset: 0x14       */
    __IO uint32_t GCR;                            /*!<UART UART Global Control Register              offset: 0x18       */
    __IO uint32_t CCR;                            /*!<UART UART Universal Control Register           offset: 0x1C       */
    __IO uint32_t BRR;                            /*!<UART UART Baud Rate Register                   offset: 0x20       */
    __IO uint32_t FRA;                            /*!<UART UART Fraction Baud Rate Register          offset: 0x24       */
    __IO uint32_t RXADDR;                         /*!<UART UART Receipt Address Register             offset: 0x28       */
    __IO uint32_t RXMASK;                         /*!<UART UART Receipt Mask Register                offset: 0x2C       */
    __IO uint32_t SCR;                            /*!<UART UART SCR Register                         offset: 0x30       */
    __IO uint32_t IDLR;                           /*!<UART UART Idle Data Length Register            offset: 0x34       */
    __IO uint32_t ABRCR;                          /*!<UART UART Auto Baud Rate Control Register      offset: 0x38       */
} UART_TypeDef;

/**
  * @brief UART type pointer Definition
  */
#define UART2                                     ((UART_TypeDef *)UART2_BASE)
#define UART1                                     ((UART_TypeDef *)UART1_BASE)

/**
  * @brief UART_TDR Register Bit Definition
  */
#define  UART_TDR_TXREG_Pos                       (0)
#define  UART_TDR_TXREG_Msk                       (0x1FFU << UART_TDR_TXREG_Pos)                    /*!<Transmission data register*/
#define  UART_TDR_TXREG                           UART_TDR_TXREG_Msk
#define  UART_TDR_TXREG_0                         (0x001U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_1                         (0x002U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_2                         (0x004U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_3                         (0x008U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_4                         (0x010U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_5                         (0x020U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_6                         (0x040U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_7                         (0x080U << UART_TDR_TXREG_Pos) 
#define  UART_TDR_TXREG_8                         (0x100U << UART_TDR_TXREG_Pos) 

/**
  * @brief UART_RDR Register Bit Definition
  */
#define  UART_RDR_RXREG_Pos                       (0)
#define  UART_RDR_RXREG_Msk                       (0x1FFU << UART_RDR_RXREG_Pos)                    /*!<Receipt data register This register is only readable*/
#define  UART_RDR_RXREG                           UART_RDR_RXREG_Msk
#define  UART_RDR_RXREG_0                         (0x001U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_1                         (0x002U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_2                         (0x004U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_3                         (0x008U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_4                         (0x010U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_5                         (0x020U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_6                         (0x040U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_7                         (0x080U << UART_RDR_RXREG_Pos) 
#define  UART_RDR_RXREG_8                         (0x100U << UART_RDR_RXREG_Pos) 

/**
  * @brief UART_CSR Register Bit Definition
  */
#define  UART_CSR_TXC_Pos                         (0)
#define  UART_CSR_TXC_Msk                         (0x1U << UART_CSR_TXC_Pos)                        /*!<Transmission complete flag bit*/
#define  UART_CSR_TXC                             UART_CSR_TXC_Msk
#define  UART_CSR_RXAVL_Pos                       (1)
#define  UART_CSR_RXAVL_Msk                       (0x1U << UART_CSR_RXAVL_Pos)                      /*!<Receipt valid data flag bit When the receipt buffer receives a complete byte data, the bit is asserted.*/
#define  UART_CSR_RXAVL                           UART_CSR_RXAVL_Msk
#define  UART_CSR_TXFULL_Pos                      (2)
#define  UART_CSR_TXFULL_Msk                      (0x1U << UART_CSR_TXFULL_Pos)                     /*!<Transmission buffer full flag bit*/
#define  UART_CSR_TXFULL                          UART_CSR_TXFULL_Msk
#define  UART_CSR_TXEPT_Pos                       (3)
#define  UART_CSR_TXEPT_Msk                       (0x1U << UART_CSR_TXEPT_Pos)                      /*!<Transmission buffer empty flag bit*/
#define  UART_CSR_TXEPT                           UART_CSR_TXEPT_Msk

/**
  * @brief UART_ISR Register Bit Definition
  */
#define  UART_ISR_TX_INTF_Pos                     (0)
#define  UART_ISR_TX_INTF_Msk                     (0x1U << UART_ISR_TX_INTF_Pos)                    /*!<Transmission buffer empty interrupt flag bit*/
#define  UART_ISR_TX_INTF                         UART_ISR_TX_INTF_Msk
#define  UART_ISR_RX_INTF_Pos                     (1)
#define  UART_ISR_RX_INTF_Msk                     (0x1U << UART_ISR_RX_INTF_Pos)                    /*!<Receipt valid data interrupt flag bit The bit is asserted when the receipt buffer receives a complete byte data.*/
#define  UART_ISR_RX_INTF                         UART_ISR_RX_INTF_Msk
#define  UART_ISR_TXC_INTF_Pos                    (2)
#define  UART_ISR_TXC_INTF_Msk                    (0x1U << UART_ISR_TXC_INTF_Pos)                   /*!<UART transmission shift register end interrupt flag bit*/
#define  UART_ISR_TXC_INTF                        UART_ISR_TXC_INTF_Msk
#define  UART_ISR_RXOERR_INTF_Pos                 (3)
#define  UART_ISR_RXOERR_INTF_Msk                 (0x1U << UART_ISR_RXOERR_INTF_Pos)                /*!<Receipt overflow error interrupt flag bit It is asserted only in case of autoflowen=0*/
#define  UART_ISR_RXOERR_INTF                     UART_ISR_RXOERR_INTF_Msk
#define  UART_ISR_RXPERR_INTF_Pos                 (4)
#define  UART_ISR_RXPERR_INTF_Msk                 (0x1U << UART_ISR_RXPERR_INTF_Pos)                /*!<Parity check error interrupt flag bit*/
#define  UART_ISR_RXPERR_INTF                     UART_ISR_RXPERR_INTF_Msk
#define  UART_ISR_RXFERR_INTF_Pos                 (5)
#define  UART_ISR_RXFERR_INTF_Msk                 (0x1U << UART_ISR_RXFERR_INTF_Pos)                /*!<Frame error interrupt flag bit Frame error occurs in the detection of anomaly stop bit.*/
#define  UART_ISR_RXFERR_INTF                     UART_ISR_RXFERR_INTF_Msk
#define  UART_ISR_RXBRK_INTF_Pos                  (6)
#define  UART_ISR_RXBRK_INTF_Msk                  (0x1U << UART_ISR_RXBRK_INTF_Pos)                 /*!<UART receipt frame break interrupt flag bit After the anomaly stop bit, RX pin receives 10 or more than 10 bit low levels after a while.*/
#define  UART_ISR_RXBRK_INTF                      UART_ISR_RXBRK_INTF_Msk
#define  UART_ISR_TXBRK_INTF_Pos                  (7)
#define  UART_ISR_TXBRK_INTF_Msk                  (0x1U << UART_ISR_TXBRK_INTF_Pos)                 /*!<UART Break frame transmission end interrupt flag bit*/
#define  UART_ISR_TXBRK_INTF                      UART_ISR_TXBRK_INTF_Msk
#define  UART_ISR_RXB8_INTF_Pos                   (8)
#define  UART_ISR_RXB8_INTF_Msk                   (0x1U << UART_ISR_RXB8_INTF_Pos)                  /*!<UART sync frame interrupt flag bit In the 9 bit communication mode, when the 9th bit data received is sames as the register CCR.B8POL, RXB8_INT is asserted. The bit can serve as the interrupt request signal*/
#define  UART_ISR_RXB8_INTF                       UART_ISR_RXB8_INTF_Msk
#define  UART_ISR_RXIDLE_INTF_Pos                 (9)
#define  UART_ISR_RXIDLE_INTF_Msk                 (0x1U << UART_ISR_RXIDLE_INTF_Pos)                /*!<UART receipt frame idle interrupt flag bit After the stop bit, RX pin receives several (UART_IDLR) high levels after a while.*/
#define  UART_ISR_RXIDLE_INTF                     UART_ISR_RXIDLE_INTF_Msk
#define  UART_ISR_ABREND_INTF_Pos                 (10)
#define  UART_ISR_ABREND_INTF_Msk                 (0x1U << UART_ISR_ABREND_INTF_Pos)                /*!<UART auto baud rate end interrupt flag bit*/
#define  UART_ISR_ABREND_INTF                     UART_ISR_ABREND_INTF_Msk
#define  UART_ISR_ABRERR_INTF_Pos                 (11)
#define  UART_ISR_ABRERR_INTF_Msk                 (0x1U << UART_ISR_ABRERR_INTF_Pos)                /*!<UART auto baud rate error interrupt flag bit*/
#define  UART_ISR_ABRERR_INTF                     UART_ISR_ABRERR_INTF_Msk

/**
  * @brief UART_IER Register Bit Definition
  */
#define  UART_IER_TX_IEN_Pos                      (0)
#define  UART_IER_TX_IEN_Msk                      (0x1U << UART_IER_TX_IEN_Pos)                     /*!<Transmission buffer empty interrupt enable bit*/
#define  UART_IER_TX_IEN                          UART_IER_TX_IEN_Msk
#define  UART_IER_RX_IEN_Pos                      (1)
#define  UART_IER_RX_IEN_Msk                      (0x1U << UART_IER_RX_IEN_Pos)                     /*!<Receipt buffer interrupt enable bit*/
#define  UART_IER_RX_IEN                          UART_IER_RX_IEN_Msk
#define  UART_IER_TXC_IEN_Pos                     (2)
#define  UART_IER_TXC_IEN_Msk                     (0x1U << UART_IER_TXC_IEN_Pos)                    /*!<UART transmission shift register end interrupt enable control bit*/
#define  UART_IER_TXC_IEN                         UART_IER_TXC_IEN_Msk
#define  UART_IER_RXOERR_IEN_Pos                  (3)
#define  UART_IER_RXOERR_IEN_Msk                  (0x1U << UART_IER_RXOERR_IEN_Pos)                 /*!<Receipt overflow error interrupt enable bit*/
#define  UART_IER_RXOERR_IEN                      UART_IER_RXOERR_IEN_Msk
#define  UART_IER_RXPERR_IEN_Pos                  (4)
#define  UART_IER_RXPERR_IEN_Msk                  (0x1U << UART_IER_RXPERR_IEN_Pos)                 /*!<Parity error interrupt enable bit*/
#define  UART_IER_RXPERR_IEN                      UART_IER_RXPERR_IEN_Msk
#define  UART_IER_RXFERR_IEN_Pos                  (5)
#define  UART_IER_RXFERR_IEN_Msk                  (0x1U << UART_IER_RXFERR_IEN_Pos)                 /*!<Frame error interrupt enable bit*/
#define  UART_IER_RXFERR_IEN                      UART_IER_RXFERR_IEN_Msk
#define  UART_IER_RXBRK_IEN_Pos                   (6)
#define  UART_IER_RXBRK_IEN_Msk                   (0x1U << UART_IER_RXBRK_IEN_Pos)                  /*!<UART receipt Break frame interrupt enable bit*/
#define  UART_IER_RXBRK_IEN                       UART_IER_RXBRK_IEN_Msk
#define  UART_IER_TXBRK_IEN_Pos                   (7)
#define  UART_IER_TXBRK_IEN_Msk                   (0x1U << UART_IER_TXBRK_IEN_Pos)                  /*!<UART Break frame transmission end interrupt enable bit*/
#define  UART_IER_TXBRK_IEN                       UART_IER_TXBRK_IEN_Msk
#define  UART_IER_RXB8_IEN_Pos                    (8)
#define  UART_IER_RXB8_IEN_Msk                    (0x1U << UART_IER_RXB8_IEN_Pos)                   /*!<UART sync frame interrupt enable bit*/
#define  UART_IER_RXB8_IEN                        UART_IER_RXB8_IEN_Msk
#define  UART_IER_RXIDLE_IEN_Pos                  (9)
#define  UART_IER_RXIDLE_IEN_Msk                  (0x1U << UART_IER_RXIDLE_IEN_Pos)                 /*!<Receipt frame idle interrupt enable bit*/
#define  UART_IER_RXIDLE_IEN                      UART_IER_RXIDLE_IEN_Msk
#define  UART_IER_ABREND_IEN_Pos                  (10)
#define  UART_IER_ABREND_IEN_Msk                  (0x1U << UART_IER_ABREND_IEN_Pos)                 /*!<Auto baud rate end enable bit*/
#define  UART_IER_ABREND_IEN                      UART_IER_ABREND_IEN_Msk
#define  UART_IER_ABRERR_IEN_Pos                  (11)
#define  UART_IER_ABRERR_IEN_Msk                  (0x1U << UART_IER_ABRERR_IEN_Pos)                 /*!<Auto baud rate error enable bit*/
#define  UART_IER_ABRERR_IEN                      UART_IER_ABRERR_IEN_Msk

/**
  * @brief UART_ICR Register Bit Definition
  */
#define  UART_ICR_TX_ICLR_Pos                     (0)
#define  UART_ICR_TX_ICLR_Msk                     (0x1U << UART_ICR_TX_ICLR_Pos)                    /*!<Transmission buffer empty interrupt clear bit*/
#define  UART_ICR_TX_ICLR                         UART_ICR_TX_ICLR_Msk
#define  UART_ICR_RX_ICLR_Pos                     (1)
#define  UART_ICR_RX_ICLR_Msk                     (0x1U << UART_ICR_RX_ICLR_Pos)                    /*!<Receipt interrupt clear bit*/
#define  UART_ICR_RX_ICLR                         UART_ICR_RX_ICLR_Msk
#define  UART_ICR_TXC_ICLR_Pos                    (2)
#define  UART_ICR_TXC_ICLR_Msk                    (0x1U << UART_ICR_TXC_ICLR_Pos)                   /*!<Transmission end interrupt clear bit*/
#define  UART_ICR_TXC_ICLR                        UART_ICR_TXC_ICLR_Msk
#define  UART_ICR_RXOERR_ICLR_Pos                 (3)
#define  UART_ICR_RXOERR_ICLR_Msk                 (0x1U << UART_ICR_RXOERR_ICLR_Pos)                /*!<Receipt overflow error interrupt clear bit*/
#define  UART_ICR_RXOERR_ICLR                     UART_ICR_RXOERR_ICLR_Msk
#define  UART_ICR_RXPERR_ICLR_Pos                 (4)
#define  UART_ICR_RXPERR_ICLR_Msk                 (0x1U << UART_ICR_RXPERR_ICLR_Pos)                /*!<Parity error interrupt clear bit*/
#define  UART_ICR_RXPERR_ICLR                     UART_ICR_RXPERR_ICLR_Msk
#define  UART_ICR_RXFERR_ICLR_Pos                 (5)
#define  UART_ICR_RXFERR_ICLR_Msk                 (0x1U << UART_ICR_RXFERR_ICLR_Pos)                /*!<Frame error interrupt enable bit*/
#define  UART_ICR_RXFERR_ICLR                     UART_ICR_RXFERR_ICLR_Msk
#define  UART_ICR_RXBRK_ICLR_Pos                  (6)
#define  UART_ICR_RXBRK_ICLR_Msk                  (0x1U << UART_ICR_RXBRK_ICLR_Pos)                 /*!<UART receipt Break frame interrupt clear bit*/
#define  UART_ICR_RXBRK_ICLR                      UART_ICR_RXBRK_ICLR_Msk
#define  UART_ICR_TXBRK_ICLR_Pos                  (7)
#define  UART_ICR_TXBRK_ICLR_Msk                  (0x1U << UART_ICR_TXBRK_ICLR_Pos)                 /*!<UART Break frame transmission end interrupt flag clear control bit.*/
#define  UART_ICR_TXBRK_ICLR                      UART_ICR_TXBRK_ICLR_Msk
#define  UART_ICR_RXB8_ICLR_Pos                   (8)
#define  UART_ICR_RXB8_ICLR_Msk                   (0x1U << UART_ICR_RXB8_ICLR_Pos)                  /*!<UART sync frame interrupt flag clear control bit*/
#define  UART_ICR_RXB8_ICLR                       UART_ICR_RXB8_ICLR_Msk
#define  UART_ICR_RXIDLE_ICLR_Pos                 (9)
#define  UART_ICR_RXIDLE_ICLR_Msk                 (0x1U << UART_ICR_RXIDLE_ICLR_Pos)                /*!<UART receipt frame idle interrupt clear bit*/
#define  UART_ICR_RXIDLE_ICLR                     UART_ICR_RXIDLE_ICLR_Msk
#define  UART_ICR_ABREND_ICLR_Pos                 (10)
#define  UART_ICR_ABREND_ICLR_Msk                 (0x1U << UART_ICR_ABREND_ICLR_Pos)                /*!<UART auto baud rate end clear bit*/
#define  UART_ICR_ABREND_ICLR                     UART_ICR_ABREND_ICLR_Msk
#define  UART_ICR_ABRERR_ICLR_Pos                 (11)
#define  UART_ICR_ABRERR_ICLR_Msk                 (0x1U << UART_ICR_ABRERR_ICLR_Pos)                /*!<UART auto baud rate error clear bit*/
#define  UART_ICR_ABRERR_ICLR                     UART_ICR_ABRERR_ICLR_Msk

/**
  * @brief UART_GCR Register Bit Definition
  */
#define  UART_GCR_UARTEN_Pos                      (0)
#define  UART_GCR_UARTEN_Msk                      (0x1U << UART_GCR_UARTEN_Pos)                     /*!<UART module selection bit*/
#define  UART_GCR_UARTEN                          UART_GCR_UARTEN_Msk
#define  UART_GCR_RXEN_Pos                        (3)
#define  UART_GCR_RXEN_Msk                        (0x1U << UART_GCR_RXEN_Pos)                       /*!<Receipt enable bit*/
#define  UART_GCR_RXEN                            UART_GCR_RXEN_Msk
#define  UART_GCR_TXEN_Pos                        (4)
#define  UART_GCR_TXEN_Msk                        (0x1U << UART_GCR_TXEN_Pos)                       /*!<Transmission enable bit*/
#define  UART_GCR_TXEN                            UART_GCR_TXEN_Msk
#define  UART_GCR_SELB8_Pos                       (7)
#define  UART_GCR_SELB8_Msk                       (0x1U << UART_GCR_SELB8_Pos)                      /*!<Selection B8 data receipt or transmission valid or not*/
#define  UART_GCR_SELB8                           UART_GCR_SELB8_Msk
#define  UART_GCR_SWAP_Pos                        (8)
#define  UART_GCR_SWAP_Msk                        (0x1U << UART_GCR_SWAP_Pos)                       /*!<Input and output exchange*/
#define  UART_GCR_SWAP                            UART_GCR_SWAP_Msk
#define  UART_GCR_RXTOG_Pos                       (9)
#define  UART_GCR_RXTOG_Msk                       (0x1U << UART_GCR_RXTOG_Pos)                      /*!<Receipt inversion*/
#define  UART_GCR_RXTOG                           UART_GCR_RXTOG_Msk
#define  UART_GCR_TXTOG_Pos                       (10)
#define  UART_GCR_TXTOG_Msk                       (0x1U << UART_GCR_TXTOG_Pos)                      /*!<Transmission inversion bit*/
#define  UART_GCR_TXTOG                           UART_GCR_TXTOG_Msk

/**
  * @brief UART_CCR Register Bit Definition
  */
#define  UART_CCR_PEN_Pos                         (0)
#define  UART_CCR_PEN_Msk                         (0x1U << UART_CCR_PEN_Pos)                        /*!<Parity enable bit*/
#define  UART_CCR_PEN                             UART_CCR_PEN_Msk
#define  UART_CCR_PSEL_Pos                        (1)
#define  UART_CCR_PSEL_Msk                        (0x1U << UART_CCR_PSEL_Pos)                       /*!<Check selection bit After the parity check enable, this bit is used to select whether to use even check or odd check.*/
#define  UART_CCR_PSEL                            UART_CCR_PSEL_Msk
#define  UART_CCR_SPB0_Pos                        (2)
#define  UART_CCR_SPB0_Msk                        (0x1U << UART_CCR_SPB0_Pos)                       /*!<Stop bit selection Set transmission stop bit.*/
#define  UART_CCR_SPB0                            UART_CCR_SPB0_Msk
#define  UART_CCR_BRK_Pos                         (3)
#define  UART_CCR_BRK_Msk                         (0x1U << UART_CCR_BRK_Pos)                        /*!<UART transmission Break frame*/
#define  UART_CCR_BRK                             UART_CCR_BRK_Msk
#define  UART_CCR_CHAR_Pos                        (4)
#define  UART_CCR_CHAR_Msk                        (0x3U << UART_CCR_CHAR_Pos)                       /*!<UART data width bit*/
#define  UART_CCR_CHAR                            UART_CCR_CHAR_Msk
#define  UART_CCR_CHAR_0                          (0x1U << UART_CCR_CHAR_Pos) 
#define  UART_CCR_CHAR_1                          (0x2U << UART_CCR_CHAR_Pos) 
#define  UART_CCR_SPB1_Pos                        (6)
#define  UART_CCR_SPB1_Msk                        (0x1U << UART_CCR_SPB1_Pos)                       /*!<Stop selection bit, plus SPB0, set the stop bit.*/
#define  UART_CCR_SPB1                            UART_CCR_SPB1_Msk
#define  UART_CCR_B8RXD_Pos                       (7)
#define  UART_CCR_B8RXD_Msk                       (0x1U << UART_CCR_B8RXD_Pos)                      /*!<UART sync frame receipt data 9th bit Only readable*/
#define  UART_CCR_B8RXD                           UART_CCR_B8RXD_Msk
#define  UART_CCR_B8TXD_Pos                       (8)
#define  UART_CCR_B8TXD_Msk                       (0x1U << UART_CCR_B8TXD_Pos)                      /*!<UART sync frame transmission data 9th bit*/
#define  UART_CCR_B8TXD                           UART_CCR_B8TXD_Msk
#define  UART_CCR_B8POL_Pos                       (9)
#define  UART_CCR_B8POL_Msk                       (0x1U << UART_CCR_B8POL_Pos)                      /*!<UART sync frame 9th bit polarity control bit*/
#define  UART_CCR_B8POL                           UART_CCR_B8POL_Msk
#define  UART_CCR_B8TOG_Pos                       (10)
#define  UART_CCR_B8TOG_Msk                       (0x1U << UART_CCR_B8TOG_Pos)                      /*!<UART sync frame transmission 9th bit auto roll control bit*/
#define  UART_CCR_B8TOG                           UART_CCR_B8TOG_Msk
#define  UART_CCR_B8EN_Pos                        (11)
#define  UART_CCR_B8EN_Msk                        (0x1U << UART_CCR_B8EN_Pos)                       /*!<UART sync frame 9th bit enable control bit. When the bit is enabled, the check enable bit PEN does not work*/
#define  UART_CCR_B8EN                            UART_CCR_B8EN_Msk
#define  UART_CCR_RWU_Pos                         (12)
#define  UART_CCR_RWU_Msk                         (0x1U << UART_CCR_RWU_Pos)                        /*!<Receiver in mute mode This bit is used to determine whether to put UART in the mute mode. This bit can be set or cleared by the software. When the wake-up sequence is available, the hardware will also clear it*/
#define  UART_CCR_RWU                             UART_CCR_RWU_Msk
#define  UART_CCR_WAKE_Pos                        (13)
#define  UART_CCR_WAKE_Msk                        (0x1U << UART_CCR_WAKE_Pos)                       /*!<Wake-up method. This bit determines UART wake-up method*/
#define  UART_CCR_WAKE                            UART_CCR_WAKE_Msk
#define  UART_CCR_LIN_Pos                         (14)
#define  UART_CCR_LIN_Msk                         (0x1U << UART_CCR_LIN_Pos)                        /*!<UART LIN protocol receipt and transmission Break frame*/
#define  UART_CCR_LIN                             UART_CCR_LIN_Msk

/**
  * @brief UART_BRR Register Bit Definition
  */
#define  UART_BRR_DIV_Mantissa_Pos                (0)
#define  UART_BRR_DIV_Mantissa_Msk                (0xFFFFU << UART_BRR_DIV_Mantissa_Pos)            /*!<Integer These 16 bits define the integer of UART divider factor (UARTDIV) DIV_Mantissa min value 1*/
#define  UART_BRR_DIV_Mantissa                    UART_BRR_DIV_Mantissa_Msk
#define  UART_BRR_DIV_Mantissa_0                  (0x0001U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_1                  (0x0002U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_2                  (0x0004U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_3                  (0x0008U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_4                  (0x0010U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_5                  (0x0020U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_6                  (0x0040U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_7                  (0x0080U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_8                  (0x0100U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_9                  (0x0200U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_10                 (0x0400U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_11                 (0x0800U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_12                 (0x1000U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_13                 (0x2000U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_14                 (0x4000U << UART_BRR_DIV_Mantissa_Pos) 
#define  UART_BRR_DIV_Mantissa_15                 (0x8000U << UART_BRR_DIV_Mantissa_Pos) 

/**
  * @brief UART_FRA Register Bit Definition
  */
#define  UART_FRA_DIV_FRACTION_Pos                (0)
#define  UART_FRA_DIV_FRACTION_Msk                (0xFU << UART_FRA_DIV_FRACTION_Pos)               /*!<UARTDIV Fraction setting The low 4 bits define the decimal of UART divider factor (UARTDIV)*/
#define  UART_FRA_DIV_FRACTION                    UART_FRA_DIV_FRACTION_Msk
#define  UART_FRA_DIV_FRACTION_0                  (0x1U << UART_FRA_DIV_FRACTION_Pos) 
#define  UART_FRA_DIV_FRACTION_1                  (0x2U << UART_FRA_DIV_FRACTION_Pos) 
#define  UART_FRA_DIV_FRACTION_2                  (0x4U << UART_FRA_DIV_FRACTION_Pos) 
#define  UART_FRA_DIV_FRACTION_3                  (0x8U << UART_FRA_DIV_FRACTION_Pos) 

/**
  * @brief UART_RXADDR Register Bit Definition
  */
#define  UART_RXADDR_RXADDR_Pos                   (0)
#define  UART_RXADDR_RXADDR_Msk                   (0xFFU << UART_RXADDR_RXADDR_Pos)                 /*!<UART sync frame data host match address In case of RXMASK =0xFF, the received sync frame data is same as the host match address, produce RXB8_INTF. The address 0 is broadcast address, and will respond after receipt.*/
#define  UART_RXADDR_RXADDR                       UART_RXADDR_RXADDR_Msk
#define  UART_RXADDR_RXADDR_0                     (0x01U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_1                     (0x02U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_2                     (0x04U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_3                     (0x08U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_4                     (0x10U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_5                     (0x20U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_6                     (0x40U << UART_RXADDR_RXADDR_Pos) 
#define  UART_RXADDR_RXADDR_7                     (0x80U << UART_RXADDR_RXADDR_Pos) 

/**
  * @brief UART_RXMASK Register Bit Definition
  */
#define  UART_RXMASK_RXMASK_Pos                   (0)
#define  UART_RXMASK_RXMASK_Msk                   (0xFFU << UART_RXMASK_RXMASK_Pos)                 /*!<When the data bits are all "0", any receipt data will produce sync frame interrupt request (RXB8_INTF). If the data bits whichone is "1", then the corresponding bit in RDR and RXADDR has to be the same, only that can produce the sync frame interrupt request.*/
#define  UART_RXMASK_RXMASK                       UART_RXMASK_RXMASK_Msk
#define  UART_RXMASK_RXMASK_0                     (0x01U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_1                     (0x02U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_2                     (0x04U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_3                     (0x08U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_4                     (0x10U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_5                     (0x20U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_6                     (0x40U << UART_RXMASK_RXMASK_Pos) 
#define  UART_RXMASK_RXMASK_7                     (0x80U << UART_RXMASK_RXMASK_Pos) 

/**
  * @brief UART_SCR Register Bit Definition
  */
#define  UART_SCR_SCEN_Pos                        (0)
#define  UART_SCR_SCEN_Msk                        (0x1U << UART_SCR_SCEN_Pos)                       /*!<ISO7816 enable control bit*/
#define  UART_SCR_SCEN                            UART_SCR_SCEN_Msk
#define  UART_SCR_SCAEN_Pos                       (1)
#define  UART_SCR_SCAEN_Msk                       (0x1U << UART_SCR_SCAEN_Pos)                      /*!<ISO7816 check auto response bit*/
#define  UART_SCR_SCAEN                           UART_SCR_SCAEN_Msk
#define  UART_SCR_NACK_Pos                        (2)
#define  UART_SCR_NACK_Msk                        (0x1U << UART_SCR_NACK_Pos)                       /*!<Active receipt frame response bit Receipt low level during protection period,this bit will be set to 1 by hardware.*/
#define  UART_SCR_NACK                            UART_SCR_NACK_Msk
#define  UART_SCR_SCFCNT_Pos                      (4)
#define  UART_SCR_SCFCNT_Msk                      (0xFFU << UART_SCR_SCFCNT_Pos)                    /*!<ISO7816 protection counter. During data transmission, the time to delay TXC flag bit assertion when the current data transmission by the register finished. Before reaching the count period, the transmitter will disable the start bit for the next data.*/
#define  UART_SCR_SCFCNT                          UART_SCR_SCFCNT_Msk
#define  UART_SCR_SCFCNT_0                        (0x01U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_1                        (0x02U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_2                        (0x04U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_3                        (0x08U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_4                        (0x10U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_5                        (0x20U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_6                        (0x40U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_SCFCNT_7                        (0x80U << UART_SCR_SCFCNT_Pos) 
#define  UART_SCR_HDSEL_Pos                       (12)
#define  UART_SCR_HDSEL_Msk                       (0x1U << UART_SCR_HDSEL_Pos)                      /*!<Single wire half duplex mode selection*/
#define  UART_SCR_HDSEL                           UART_SCR_HDSEL_Msk

/**
  * @brief UART_IDLR Register Bit Definition
  */
#define  UART_IDLR_IDLR_Pos                       (0)
#define  UART_IDLR_IDLR_Msk                       (0xFFFFU << UART_IDLR_IDLR_Pos)                   /*!<UART idle data length register Data length is not allowed to set as 0.*/
#define  UART_IDLR_IDLR                           UART_IDLR_IDLR_Msk
#define  UART_IDLR_IDLR_0                         (0x0001U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_1                         (0x0002U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_2                         (0x0004U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_3                         (0x0008U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_4                         (0x0010U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_5                         (0x0020U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_6                         (0x0040U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_7                         (0x0080U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_8                         (0x0100U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_9                         (0x0200U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_10                        (0x0400U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_11                        (0x0800U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_12                        (0x1000U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_13                        (0x2000U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_14                        (0x4000U << UART_IDLR_IDLR_Pos) 
#define  UART_IDLR_IDLR_15                        (0x8000U << UART_IDLR_IDLR_Pos) 

/**
  * @brief UART_ABRCR Register Bit Definition
  */
#define  UART_ABRCR_ABREN_Pos                     (0)
#define  UART_ABRCR_ABREN_Msk                     (0x1U << UART_ABRCR_ABREN_Pos)                    /*!<Auto baud rate enable Enable auto baud rate only when UART is idle. After enabling, detect the edge of the receipt signal. After auto detection of auto baud rate, the hardware auto sets UART_BRR and UART_FRA register.*/
#define  UART_ABRCR_ABREN                         UART_ABRCR_ABREN_Msk
#define  UART_ABRCR_ABR_BITCNT_Pos                (1)
#define  UART_ABRCR_ABR_BITCNT_Msk                (0x3U << UART_ABRCR_ABR_BITCNT_Pos)               /*!<Auto baud rate detection length Detect the bit length between the previous edge and the following edge.*/
#define  UART_ABRCR_ABR_BITCNT                    UART_ABRCR_ABR_BITCNT_Msk
#define  UART_ABRCR_ABR_BITCNT_MODE0              (0x00U << UART_ABRCR_ABR_BITCNT_Pos)              /*!< Automatic baud rate length detection 1 */
#define  UART_ABRCR_ABR_BITCNT_MODE1              (0x01U << UART_ABRCR_ABR_BITCNT_Pos)              /*!< Automatic baud rate length detection 2 */
#define  UART_ABRCR_ABR_BITCNT_MODE2              (0x02U << UART_ABRCR_ABR_BITCNT_Pos)              /*!< Automatic baud rate length detection 4 */
#define  UART_ABRCR_ABR_BITCNT_MODE3              (0x03U << UART_ABRCR_ABR_BITCNT_Pos)              /*!< Automatic baud rate length detection 8 */
#define  UART_ABRCR_FORMER_EDGE_Pos               (3)
#define  UART_ABRCR_FORMER_EDGE_Msk               (0x1U << UART_ABRCR_FORMER_EDGE_Pos)              /*!<One edge selection before the auto baud rate*/
#define  UART_ABRCR_FORMER_EDGE                   UART_ABRCR_FORMER_EDGE_Msk
#define  UART_ABRCR_LATTER_EDGE_Pos               (4)
#define  UART_ABRCR_LATTER_EDGE_Msk               (0x1U << UART_ABRCR_LATTER_EDGE_Pos)              /*!<One edge selection after the auto baud rate*/
#define  UART_ABRCR_LATTER_EDGE                   UART_ABRCR_LATTER_EDGE_Msk

/** ------------------------------------------------------------------------------------------------------------------*/
#endif
/** ------------------------------------------------------------------------------------------------------------------*/
