/***********************************************************************************************************************
    @file     reg_i2c.h
    @author   FD TEAM
    @brief    This flie contains all the I2C's register and its field definition.
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

#ifndef __REG_I2C_H
#define __REG_I2C_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief I2C Base Address Definition
  */
#define  I2C1_BASE                                 0x40005400                                       /*!<Base Address: 0x40005400*/

/**
  * @brief I2C Register Structure Definition
  */
typedef struct
{
    __IO uint32_t DAT;                            /*!<I2C Data Register                              offset: 0x00       */
    __IO uint32_t ADR;                            /*!<I2C Address Register                           offset: 0x04       */
    __IO uint32_t CON;                            /*!<I2C Control Register                           offset: 0x08       */
    __IO uint32_t STA;                            /*!<I2C Status Register                            offset: 0x0C       */
    __IO uint32_t DIV;                            /*!<I2C Prescaler Register                         offset: 0x10       */
    __IO uint32_t FIFO;                           /*!<I2C FIFO Regitser                              offset: 0x14       */
} I2C_TypeDef;

/**
  * @brief I2C type pointer Definition
  */
#define I2C1                                      ((I2C_TypeDef *)I2C1_BASE)

/**
  * @brief I2C_DAT Register Bit Definition
  */
#define  I2C_DAT_DATA_Pos                         (0)
#define  I2C_DAT_DATA_Msk                         (0xFFU << I2C_DAT_DATA_Pos)                       /*!<Transmit data buffer?or receive data buffer?*/
#define  I2C_DAT_DATA                             I2C_DAT_DATA_Msk
#define  I2C_DAT_DATA_Bit0                        (0x01U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit1                        (0x02U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit2                        (0x04U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit3                        (0x08U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit4                        (0x10U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit5                        (0x20U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit6                        (0x40U << I2C_DAT_DATA_Pos) 
#define  I2C_DAT_DATA_Bit7                        (0x80U << I2C_DAT_DATA_Pos) 

/**
  * @brief I2C_ADR Register Bit Definition
  */
#define  I2C_ADR_GC_Pos                           (0)
#define  I2C_ADR_GC_Msk                           (0x1U << I2C_ADR_GC_Pos)                          /*!<*/
#define  I2C_ADR_GC                               I2C_ADR_GC_Msk
#define  I2C_ADR_ADDR_Pos                         (1)
#define  I2C_ADR_ADDR_Msk                         (0x7FU << I2C_ADR_ADDR_Pos)                       /*!<*/
#define  I2C_ADR_ADDR                             I2C_ADR_ADDR_Msk
#define  I2C_ADR_ADDR_Bit0                        (0x01U << I2C_ADR_ADDR_Pos) 
#define  I2C_ADR_ADDR_Bit1                        (0x02U << I2C_ADR_ADDR_Pos) 
#define  I2C_ADR_ADDR_Bit2                        (0x04U << I2C_ADR_ADDR_Pos) 
#define  I2C_ADR_ADDR_Bit3                        (0x08U << I2C_ADR_ADDR_Pos) 
#define  I2C_ADR_ADDR_Bit4                        (0x10U << I2C_ADR_ADDR_Pos) 
#define  I2C_ADR_ADDR_Bit5                        (0x20U << I2C_ADR_ADDR_Pos) 
#define  I2C_ADR_ADDR_Bit6                        (0x40U << I2C_ADR_ADDR_Pos) 

/**
  * @brief I2C_CON Register Bit Definition
  */
#define  I2C_CON_AA_Pos                           (2)
#define  I2C_CON_AA_Msk                           (0x1U << I2C_CON_AA_Pos)                          /*!<*/
#define  I2C_CON_AA                               I2C_CON_AA_Msk
#define  I2C_CON_SI_Pos                           (3)
#define  I2C_CON_SI_Msk                           (0x1U << I2C_CON_SI_Pos)                          /*!<*/
#define  I2C_CON_SI                               I2C_CON_SI_Msk
#define  I2C_CON_STO_Pos                          (4)
#define  I2C_CON_STO_Msk                          (0x1U << I2C_CON_STO_Pos)                         /*!<*/
#define  I2C_CON_STO                              I2C_CON_STO_Msk
#define  I2C_CON_STA_Pos                          (5)
#define  I2C_CON_STA_Msk                          (0x1U << I2C_CON_STA_Pos)                         /*!<*/
#define  I2C_CON_STA                              I2C_CON_STA_Msk
#define  I2C_CON_ENS1_Pos                         (6)
#define  I2C_CON_ENS1_Msk                         (0x1U << I2C_CON_ENS1_Pos)                        /*!<*/
#define  I2C_CON_ENS1                             I2C_CON_ENS1_Msk

/**
  * @brief I2C_STA Register Bit Definition
  */
#define  I2C_STA_STA_Pos                          (0)
#define  I2C_STA_STA_Msk                          (0xFFU << I2C_STA_STA_Pos)                        /*!<*/
#define  I2C_STA_STA                              I2C_STA_STA_Msk
#define  I2C_STA_STA_Bit0                         (0x01U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit1                         (0x02U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit2                         (0x04U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit3                         (0x08U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit4                         (0x10U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit5                         (0x20U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit6                         (0x40U << I2C_STA_STA_Pos) 
#define  I2C_STA_STA_Bit7                         (0x80U << I2C_STA_STA_Pos) 

/**
  * @brief I2C_DIV Register Bit Definition
  */
#define  I2C_DIV_DIV_Pos                          (0)
#define  I2C_DIV_DIV_Msk                          (0xFFFFU << I2C_DIV_DIV_Pos)                      /*!<*/
#define  I2C_DIV_DIV                              I2C_DIV_DIV_Msk
#define  I2C_DIV_DIV_Bit0                         (0x0001U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit1                         (0x0002U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit2                         (0x0004U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit3                         (0x0008U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit4                         (0x0010U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit5                         (0x0020U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit6                         (0x0040U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit7                         (0x0080U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit8                         (0x0100U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit9                         (0x0200U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit10                        (0x0400U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit11                        (0x0800U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit12                        (0x1000U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit13                        (0x2000U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit14                        (0x4000U << I2C_DIV_DIV_Pos) 
#define  I2C_DIV_DIV_Bit15                        (0x8000U << I2C_DIV_DIV_Pos) 

/**
  * @brief I2C_FIFO Register Bit Definition
  */
#define  I2C_FIFO_FIFO_EN_Pos                     (0)
#define  I2C_FIFO_FIFO_EN_Msk                     (0x1U << I2C_FIFO_FIFO_EN_Pos)                    /*!<Enable Buffer Mode*/
#define  I2C_FIFO_FIFO_EN                         I2C_FIFO_FIFO_EN_Msk
#define  I2C_FIFO_FIFO_CLEAR_Pos                  (1)
#define  I2C_FIFO_FIFO_CLEAR_Msk                  (0x1U << I2C_FIFO_FIFO_CLEAR_Pos)                 /*!<Clear Send and Receive Buffers*/
#define  I2C_FIFO_FIFO_CLEAR                      I2C_FIFO_FIFO_CLEAR_Msk
#define  I2C_FIFO_RXFIFO_TL_Pos                   (8)
#define  I2C_FIFO_RXFIFO_TL_Msk                   (0x7U << I2C_FIFO_RXFIFO_TL_Pos)                  /*!<Receive Buffer Threshold*/
#define  I2C_FIFO_RXFIFO_TL                       I2C_FIFO_RXFIFO_TL_Msk
#define  I2C_FIFO_RXFIFO_TL_Bit0                  (0x1U << I2C_FIFO_RXFIFO_TL_Pos) 
#define  I2C_FIFO_RXFIFO_TL_Bit1                  (0x2U << I2C_FIFO_RXFIFO_TL_Pos) 
#define  I2C_FIFO_RXFIFO_TL_Bit2                  (0x4U << I2C_FIFO_RXFIFO_TL_Pos) 
#define  I2C_FIFO_RXFIFO_LEVEL_Pos                (16)
#define  I2C_FIFO_RXFIFO_LEVEL_Msk                (0x7U << I2C_FIFO_RXFIFO_LEVEL_Pos)               /*!<Number of Valid Bytes in Receive Buffer*/
#define  I2C_FIFO_RXFIFO_LEVEL                    I2C_FIFO_RXFIFO_LEVEL_Msk
#define  I2C_FIFO_RXFIFO_LEVEL_Bit0               (0x1U << I2C_FIFO_RXFIFO_LEVEL_Pos) 
#define  I2C_FIFO_RXFIFO_LEVEL_Bit1               (0x2U << I2C_FIFO_RXFIFO_LEVEL_Pos) 
#define  I2C_FIFO_RXFIFO_LEVEL_Bit2               (0x4U << I2C_FIFO_RXFIFO_LEVEL_Pos) 
#define  I2C_FIFO_TXFIFO_LEVEL_Pos                (24)
#define  I2C_FIFO_TXFIFO_LEVEL_Msk                (0x7U << I2C_FIFO_TXFIFO_LEVEL_Pos)               /*!<Number of Valid Bytes in Send Buffer*/
#define  I2C_FIFO_TXFIFO_LEVEL                    I2C_FIFO_TXFIFO_LEVEL_Msk
#define  I2C_FIFO_TXFIFO_LEVEL_Bit0               (0x1U << I2C_FIFO_TXFIFO_LEVEL_Pos) 
#define  I2C_FIFO_TXFIFO_LEVEL_Bit1               (0x2U << I2C_FIFO_TXFIFO_LEVEL_Pos) 
#define  I2C_FIFO_TXFIFO_LEVEL_Bit2               (0x4U << I2C_FIFO_TXFIFO_LEVEL_Pos) 


#endif

