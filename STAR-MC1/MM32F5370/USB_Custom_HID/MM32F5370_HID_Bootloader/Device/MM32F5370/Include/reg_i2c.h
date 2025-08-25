/***********************************************************************************************************************
    @file     reg_i2c.h
    @author   VV TEAM
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
#include "core_starmc1.h"



/**
  * @brief I2C Base Address Definition
  */
#define  I2C1_BASE                                 0x40005400                                       /*!<Base Address: 0x40005400*/
#define  I2C2_BASE                                 0x40005800                                       /*!<Base Address: 0x40005800*/

/**
  * @brief I2C Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<I2C Control Register                           offset: 0x00       */
    __IO uint32_t TAR;                            /*!<I2C Target Address Register                    offset: 0x04       */
    __IO uint32_t SAR;                            /*!<I2C Slave Address Register                     offset: 0x08       */
    __IO uint32_t RESERVED0x0C[1];                /*!<                                               offset: 0x0C       */
    __IO uint32_t DR;                             /*!<I2C Data Command Register                      offset: 0x10       */
    __IO uint32_t SSHR;                           /*!<I2C Standard Mode SCL High Count Register      offset: 0x14       */
    __IO uint32_t SSLR;                           /*!<I2C Standard Mode SCL Low Count Register       offset: 0x18       */
    __IO uint32_t FSHR;                           /*!<I2C Fast/Super fast Mode SCL High Count        offset: 0x1C
                                                      Register                                                          */
    __IO uint32_t FSLR;                           /*!<I2C Fast/Super fast Mode SCL Low Count         offset: 0x20
                                                      Register                                                          */
    __IO uint32_t RESERVED0x24[2];                /*!<                                               offset: 0x24~0x28  */
    __IO uint32_t ISR;                            /*!<I2C Interrupt Status Register                  offset: 0x2C       */
    __IO uint32_t IMR;                            /*!<I2C Interrupt Mask Register                    offset: 0x30       */
    __IO uint32_t RAWISR;                         /*!<I2C RAW Interrupt Status Register              offset: 0x34       */
    __IO uint32_t RXTLR;                          /*!<I2C Receive Threshold Register                 offset: 0x38       */
    __IO uint32_t TXTLR;                          /*!<I2C Transmit Threshold Register                offset: 0x3C       */
    __IO uint32_t ICR;                            /*!<I2C Combined and Independent Interrupt Clear   offset: 0x40
                                                      Register                                                          */
    __IO uint32_t RX_UNDER;                       /*!<I2C RX_UNDER Interrupt Clear Register          offset: 0x44       */
    __IO uint32_t RX_OVER;                        /*!<I2C RX_OVER Interrupt Clear Register           offset: 0x48       */
    __IO uint32_t TX_OVER;                        /*!<I2C TX_OVER Interrupt Clear Register           offset: 0x4C       */
    __IO uint32_t RD_REQ;                         /*!<I2C RD_REQ Interrupt Clear Register            offset: 0x50       */
    __IO uint32_t TX_ABRT;                        /*!<I2C TX_ABRT Interrupt Clear Register           offset: 0x54       */
    __IO uint32_t RX_DONE;                        /*!<I2C RX_DONE Interrupt Clear Register           offset: 0x58       */
    __IO uint32_t ACTIV;                          /*!<I2C ACTIVITY Interrupt Clear Register          offset: 0x5C       */
    __IO uint32_t STOP;                           /*!<I2C STOP_DET Interrupt Clear Register          offset: 0x60       */
    __IO uint32_t START;                          /*!<I2C START_DET Interrupt Clear Register         offset: 0x64       */
    __IO uint32_t GC;                             /*!<I2C GEN_CALL Interrupt Clear Register          offset: 0x68       */
    __IO uint32_t ENR;                            /*!<I2C Enable Register                            offset: 0x6C       */
    __IO uint32_t SR;                             /*!<I2C Status Register                            offset: 0x70       */
    __IO uint32_t TXFLR;                          /*!<I2C Transmit FIFO Level Register               offset: 0x74       */
    __IO uint32_t RXFLR;                          /*!<I2C Receive FIFO Level Register                offset: 0x78       */
    __IO uint32_t HOLD;                           /*!<I2C SDA Hold Time Register                     offset: 0x7C       */
    __IO uint32_t TX_ABRT_SRC;                    /*!<                                               offset: 0x80       */
    __IO uint32_t SLV_NACK;                       /*!<                                               offset: 0x84       */
    __IO uint32_t DMA;                            /*!<I2C DMA Control Register                       offset: 0x88       */
    __IO uint32_t RESERVED0x8C[2];                /*!<                                               offset: 0x8C~0x90  */
    __IO uint32_t SETUP;                          /*!<I2C SDA Setup Time Register                    offset: 0x94       */
    __IO uint32_t GCR;                            /*!<I2C General Call ACK Register                  offset: 0x98       */
    __IO uint32_t EN_SR;                          /*!<                                               offset: 0x9C       */
    __IO uint32_t SPKLEN;                         /*!<                                               offset: 0xA0       */
    __IO uint32_t RESERVED0xA4[2];                /*!<                                               offset: 0xA4~0xA8  */
    __IO uint32_t SCL_TMO;                        /*!<                                               offset: 0xAC       */
    __IO uint32_t SDA_TMO;                        /*!<                                               offset: 0xB0       */
    __IO uint32_t SCL_STUCK;                      /*!<                                               offset: 0xB4       */
    __IO uint32_t RESERVED0xB8[1];                /*!<                                               offset: 0xB8       */
    __IO uint32_t SMB_SEXT;                       /*!<                                               offset: 0xBC       */
    __IO uint32_t SMB_MEXT;                       /*!<                                               offset: 0xC0       */
    __IO uint32_t SMB_IDLE;                       /*!<                                               offset: 0xC4       */
    __IO uint32_t SMB_ISR;                        /*!<                                               offset: 0xC8       */
    __IO uint32_t SMB_IMR;                        /*!<                                               offset: 0xCC       */
    __IO uint32_t SMB_RAWISR;                     /*!<                                               offset: 0xD0       */
    __IO uint32_t SMB_ICR;                        /*!<                                               offset: 0xD4       */
    __IO uint32_t OPT_SAR;                        /*!<                                               offset: 0xD8       */
    __IO uint32_t SMB_UDID_LSB;                   /*!<                                               offset: 0xDC       */
    __IO uint32_t SMB_UDID_MSB0;                  /*!<                                               offset: 0xE0       */
    __IO uint32_t SMB_UDID_MSB1;                  /*!<                                               offset: 0xE4       */
    __IO uint32_t SMB_UDID_MSB2;                  /*!<                                               offset: 0xE8       */
    __IO uint32_t SLVMASK;                        /*!<                                               offset: 0xEC       */
    __IO uint32_t SLVRCVADDR;                     /*!<                                               offset: 0xF0       */
} I2C_TypeDef;

/**
  * @brief I2C type pointer Definition
  */
#define I2C1                                      ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                                      ((I2C_TypeDef *)I2C2_BASE)

/**
  * @brief I2C_CR Register Bit Definition
  */
#define  I2C_CR_MASTER_Pos                        (0)
#define  I2C_CR_MASTER_Msk                        (0x1U << I2C_CR_MASTER_Pos)                       /*!<This bit controls whether the I2C master is enabled.*/
#define  I2C_CR_MASTER                            I2C_CR_MASTER_Msk
#define  I2C_CR_SPEED_Pos                         (1)
#define  I2C_CR_SPEED_Msk                         (0x3U << I2C_CR_SPEED_Pos)                        /*!<These bits control at which speed the I2C operates in the Master mode.*/
#define  I2C_CR_SPEED                             I2C_CR_SPEED_Msk
#define  I2C_CR_SPEED_Bit0                        (0x1U << I2C_CR_SPEED_Pos) 
#define  I2C_CR_SPEED_Bit1                        (0x2U << I2C_CR_SPEED_Pos) 
#define  I2C_CR_SLAVE10_Pos                       (3)
#define  I2C_CR_SLAVE10_Msk                       (0x1U << I2C_CR_SLAVE10_Pos)                      /*!<When I2C is acting as a slave, this bit controls whether it responds to 7- or 10-bit addresses.*/
#define  I2C_CR_SLAVE10                           I2C_CR_SLAVE10_Msk
#define  I2C_CR_MASTER10_Pos                      (4)
#define  I2C_CR_MASTER10_Msk                      (0x1U << I2C_CR_MASTER10_Pos)                     /*!<Addressing mode when I2C is acting as a master*/
#define  I2C_CR_MASTER10                          I2C_CR_MASTER10_Msk
#define  I2C_CR_REPEN_Pos                         (5)
#define  I2C_CR_REPEN_Msk                         (0x1U << I2C_CR_REPEN_Pos)                        /*!<This bit determines whether RESTART conditions may be sent when I2C is acting as a master.*/
#define  I2C_CR_REPEN                             I2C_CR_REPEN_Msk
#define  I2C_CR_DISSLAVE_Pos                      (6)
#define  I2C_CR_DISSLAVE_Msk                      (0x1U << I2C_CR_DISSLAVE_Pos)                     /*!<This bit controls whether I2C has its slave disabled*/
#define  I2C_CR_DISSLAVE                          I2C_CR_DISSLAVE_Msk
#define  I2C_CR_STOPINT_Pos                       (7)
#define  I2C_CR_STOPINT_Msk                       (0x1U << I2C_CR_STOPINT_Pos)                      /*!<This bit controls whether a STOP interrupt is generated in the Slave mode.*/
#define  I2C_CR_STOPINT                           I2C_CR_STOPINT_Msk
#define  I2C_CR_EMPINT_Pos                        (8)
#define  I2C_CR_EMPINT_Msk                        (0x1U << I2C_CR_EMPINT_Pos)                       /*!<This bit controls whether a TX_EMPTY interrupt is generated. For details, refer to the I2C_RAWISR register.*/
#define  I2C_CR_EMPINT                            I2C_CR_EMPINT_Msk
#define  I2C_CR_STOP_Pos                          (9)
#define  I2C_CR_STOP_Msk                          (0x1U << I2C_CR_STOP_Pos)                         /*!<This bit controls whether a STOP is issued after transmission or reception.*/
#define  I2C_CR_STOP                              I2C_CR_STOP_Msk
#define  I2C_CR_RESTART_Pos                       (10)
#define  I2C_CR_RESTART_Msk                       (0x1U << I2C_CR_RESTART_Pos)                      /*!<This bit controls whether a RESTART is issued before transmission or reception.*/
#define  I2C_CR_RESTART                           I2C_CR_RESTART_Msk
#define  I2C_CR_SLV_TX_ABRT_DIS_Pos               (11)
#define  I2C_CR_SLV_TX_ABRT_DIS_Msk               (0x1U << I2C_CR_SLV_TX_ABRT_DIS_Pos)              /*!<When I2C is acting as a slave-transmitter*/
#define  I2C_CR_SLV_TX_ABRT_DIS                   I2C_CR_SLV_TX_ABRT_DIS_Msk
#define  I2C_CR_PAD_SEL_Pos                       (12)
#define  I2C_CR_PAD_SEL_Msk                       (0x1U << I2C_CR_PAD_SEL_Pos)                      /*!<PAD MUX Exchange the corresponding PADs of SCL and SDA*/
#define  I2C_CR_PAD_SEL                           I2C_CR_PAD_SEL_Msk
#define  I2C_CR_OPT_SAR_EN_Pos                    (16)
#define  I2C_CR_OPT_SAR_EN_Msk                    (0x1U << I2C_CR_OPT_SAR_EN_Pos)                   /*!<0: Disable the usage of OPT_SAR register*/
#define  I2C_CR_OPT_SAR_EN                        I2C_CR_OPT_SAR_EN_Msk
#define  I2C_CR_SMB_SLV_QC_EN_Pos                 (17)
#define  I2C_CR_SMB_SLV_QC_EN_Msk                 (0x1U << I2C_CR_SMB_SLV_QC_EN_Pos)                /*!<0: I2C slave slave receives all bus protocols but not Quick commands*/
#define  I2C_CR_SMB_SLV_QC_EN                     I2C_CR_SMB_SLV_QC_EN_Msk
#define  I2C_CR_SMB_ARP_EN_Pos                    (18)
#define  I2C_CR_SMB_ARP_EN_Msk                    (0x1U << I2C_CR_SMB_ARP_EN_Pos)                   /*!<0: Address resolution logic disable in SMBus mode*/
#define  I2C_CR_SMB_ARP_EN                        I2C_CR_SMB_ARP_EN_Msk
#define  I2C_CR_SMB_PSA_EN_Pos                    (19)
#define  I2C_CR_SMB_PSA_EN_Msk                    (0x1U << I2C_CR_SMB_PSA_EN_Pos)                   /*!<0: enable I2C as non-persistent slave device; I2C slave device clears the address valid flag bit for General/Directed Reset ARP command*/
#define  I2C_CR_SMB_PSA_EN                        I2C_CR_SMB_PSA_EN_Msk
#define  I2C_CR_STOP_DET_MST_ACT_Pos              (20)
#define  I2C_CR_STOP_DET_MST_ACT_Msk              (0x1U << I2C_CR_STOP_DET_MST_ACT_Pos)             /*!<In master mode,*/
#define  I2C_CR_STOP_DET_MST_ACT                  I2C_CR_STOP_DET_MST_ACT_Msk
#define  I2C_CR_BUS_CLR_Pos                       (21)
#define  I2C_CR_BUS_CLR_Msk                       (0x1U << I2C_CR_BUS_CLR_Pos)                      /*!<0: Bus Clear is disabled*/
#define  I2C_CR_BUS_CLR                           I2C_CR_BUS_CLR_Msk
#define  I2C_CR_RX_FULL_HLD_Pos                   (22)
#define  I2C_CR_RX_FULL_HLD_Msk                   (0x1U << I2C_CR_RX_FULL_HLD_Pos)                  /*!<0: I2C does not hold the bus when RX FIFO is physically full to its depth*/
#define  I2C_CR_RX_FULL_HLD                       I2C_CR_RX_FULL_HLD_Msk

/**
  * @brief I2C_TAR Register Bit Definition
  */
#define  I2C_TAR_ADDR_Pos                         (0)
#define  I2C_TAR_ADDR_Msk                         (0x3FFU << I2C_TAR_ADDR_Pos)                      /*!<This is the target address for any master transaction.*/
#define  I2C_TAR_ADDR                             I2C_TAR_ADDR_Msk
#define  I2C_TAR_ADDR_Bit0                        (0x001U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit1                        (0x002U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit2                        (0x004U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit3                        (0x008U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit4                        (0x010U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit5                        (0x020U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit6                        (0x040U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit7                        (0x080U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit8                        (0x100U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_ADDR_Bit9                        (0x200U << I2C_TAR_ADDR_Pos) 
#define  I2C_TAR_GC_Pos                           (10)
#define  I2C_TAR_GC_Msk                           (0x1U << I2C_TAR_GC_Pos)                          /*!<If bit 11 (SPECIAL) is set to 1, then this bit indicates whether a General Call or START byte command is to be performed by the I2C.*/
#define  I2C_TAR_GC                               I2C_TAR_GC_Msk
#define  I2C_TAR_SPECIAL_Pos                      (11)
#define  I2C_TAR_SPECIAL_Msk                      (0x1U << I2C_TAR_SPECIAL_Pos)                     /*!<This bit indicates whether software performs a General Call or Start Byte command.*/
#define  I2C_TAR_SPECIAL                          I2C_TAR_SPECIAL_Msk
#define  I2C_TAR_SMB_QC_Pos                       (16)
#define  I2C_TAR_SMB_QC_Msk                       (0x1U << I2C_TAR_SMB_QC_Pos)                      /*!<If bit 11 (SPECIAL) is set to 1, then this bit indicates whether a Quick command is to be performed by the I2C*/
#define  I2C_TAR_SMB_QC                           I2C_TAR_SMB_QC_Msk

/**
  * @brief I2C_SAR Register Bit Definition
  */
#define  I2C_SAR_ADDR_Pos                         (0)
#define  I2C_SAR_ADDR_Msk                         (0x3FFU << I2C_SAR_ADDR_Pos)                      /*!<The slave address of I2C. For 7-bit addressing, only ADDR [6:0] is valid.*/
#define  I2C_SAR_ADDR                             I2C_SAR_ADDR_Msk
#define  I2C_SAR_ADDR_Bit0                        (0x001U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit1                        (0x002U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit2                        (0x004U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit3                        (0x008U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit4                        (0x010U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit5                        (0x020U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit6                        (0x040U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit7                        (0x080U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit8                        (0x100U << I2C_SAR_ADDR_Pos) 
#define  I2C_SAR_ADDR_Bit9                        (0x200U << I2C_SAR_ADDR_Pos) 

/**
  * @brief I2C_DR Register Bit Definition
  */
#define  I2C_DR_DAT_Pos                           (0)
#define  I2C_DR_DAT_Msk                           (0xFFU << I2C_DR_DAT_Pos)                         /*!<This register contains the data to be transmitted or received on the I2C bus.*/
#define  I2C_DR_DAT                               I2C_DR_DAT_Msk
#define  I2C_DR_DAT_Bit0                          (0x01U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit1                          (0x02U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit2                          (0x04U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit3                          (0x08U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit4                          (0x10U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit5                          (0x20U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit6                          (0x40U << I2C_DR_DAT_Pos) 
#define  I2C_DR_DAT_Bit7                          (0x80U << I2C_DR_DAT_Pos) 
#define  I2C_DR_CMD_Pos                           (8)
#define  I2C_DR_CMD_Msk                           (0x1U << I2C_DR_CMD_Pos)                          /*!<This bit controls whether a read or a write is performed in the Master mode.*/
#define  I2C_DR_CMD                               I2C_DR_CMD_Msk
#define  I2C_DR_FIRST_DATA_Pos                    (11)
#define  I2C_DR_FIRST_DATA_Msk                    (0x1U << I2C_DR_FIRST_DATA_Pos)                   /*!<Indicates the first data byte received after the address phase for receive transfer in Master receiver or Slave receiver mode.*/
#define  I2C_DR_FIRST_DATA                        I2C_DR_FIRST_DATA_Msk

/**
  * @brief I2C_SSHR Register Bit Definition
  */
#define  I2C_SSHR_CNT_Pos                         (0)
#define  I2C_SSHR_CNT_Msk                         (0xFFFFU << I2C_SSHR_CNT_Pos)                     /*!<This register sets the SCL clock high-period count (min valid value is 6) for Standard mode.*/
#define  I2C_SSHR_CNT                             I2C_SSHR_CNT_Msk
#define  I2C_SSHR_CNT_Bit0                        (0x0001U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit1                        (0x0002U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit2                        (0x0004U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit3                        (0x0008U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit4                        (0x0010U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit5                        (0x0020U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit6                        (0x0040U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit7                        (0x0080U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit8                        (0x0100U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit9                        (0x0200U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit10                       (0x0400U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit11                       (0x0800U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit12                       (0x1000U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit13                       (0x2000U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit14                       (0x4000U << I2C_SSHR_CNT_Pos) 
#define  I2C_SSHR_CNT_Bit15                       (0x8000U << I2C_SSHR_CNT_Pos) 

/**
  * @brief I2C_SSLR Register Bit Definition
  */
#define  I2C_SSLR_CNT_Pos                         (0)
#define  I2C_SSLR_CNT_Msk                         (0xFFFFU << I2C_SSLR_CNT_Pos)                     /*!<This register sets the SCL clock low-period count (min valid value is 6) for Standard mode.*/
#define  I2C_SSLR_CNT                             I2C_SSLR_CNT_Msk
#define  I2C_SSLR_CNT_Bit0                        (0x0001U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit1                        (0x0002U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit2                        (0x0004U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit3                        (0x0008U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit4                        (0x0010U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit5                        (0x0020U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit6                        (0x0040U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit7                        (0x0080U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit8                        (0x0100U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit9                        (0x0200U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit10                       (0x0400U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit11                       (0x0800U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit12                       (0x1000U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit13                       (0x2000U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit14                       (0x4000U << I2C_SSLR_CNT_Pos) 
#define  I2C_SSLR_CNT_Bit15                       (0x8000U << I2C_SSLR_CNT_Pos) 

/**
  * @brief I2C_FSHR Register Bit Definition
  */
#define  I2C_FSHR_CNT_Pos                         (0)
#define  I2C_FSHR_CNT_Msk                         (0xFFFFU << I2C_FSHR_CNT_Pos)                     /*!<This register sets the SCL clock high-period count (min valid value is 1) for Fast mode/ Fast mode Plus.*/
#define  I2C_FSHR_CNT                             I2C_FSHR_CNT_Msk
#define  I2C_FSHR_CNT_Bit0                        (0x0001U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit1                        (0x0002U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit2                        (0x0004U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit3                        (0x0008U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit4                        (0x0010U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit5                        (0x0020U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit6                        (0x0040U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit7                        (0x0080U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit8                        (0x0100U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit9                        (0x0200U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit10                       (0x0400U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit11                       (0x0800U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit12                       (0x1000U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit13                       (0x2000U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit14                       (0x4000U << I2C_FSHR_CNT_Pos) 
#define  I2C_FSHR_CNT_Bit15                       (0x8000U << I2C_FSHR_CNT_Pos) 

/**
  * @brief I2C_FSLR Register Bit Definition
  */
#define  I2C_FSLR_CNT_Pos                         (0)
#define  I2C_FSLR_CNT_Msk                         (0xFFFFU << I2C_FSLR_CNT_Pos)                     /*!<This register sets the SCL clock low-period count (min valid value is 6) for Fast mode/ Fast mode Plus.*/
#define  I2C_FSLR_CNT                             I2C_FSLR_CNT_Msk
#define  I2C_FSLR_CNT_Bit0                        (0x0001U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit1                        (0x0002U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit2                        (0x0004U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit3                        (0x0008U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit4                        (0x0010U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit5                        (0x0020U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit6                        (0x0040U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit7                        (0x0080U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit8                        (0x0100U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit9                        (0x0200U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit10                       (0x0400U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit11                       (0x0800U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit12                       (0x1000U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit13                       (0x2000U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit14                       (0x4000U << I2C_FSLR_CNT_Pos) 
#define  I2C_FSLR_CNT_Bit15                       (0x8000U << I2C_FSLR_CNT_Pos) 

/**
  * @brief I2C_ISR Register Bit Definition
  */
#define  I2C_ISR_R_RX_UNDER_Pos                   (0)
#define  I2C_ISR_R_RX_UNDER_Msk                   (0x1U << I2C_ISR_R_RX_UNDER_Pos)                  /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_RX_UNDER                       I2C_ISR_R_RX_UNDER_Msk
#define  I2C_ISR_R_RX_OVER_Pos                    (1)
#define  I2C_ISR_R_RX_OVER_Msk                    (0x1U << I2C_ISR_R_RX_OVER_Pos)                   /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_RX_OVER                        I2C_ISR_R_RX_OVER_Msk
#define  I2C_ISR_R_RX_FULL_Pos                    (2)
#define  I2C_ISR_R_RX_FULL_Msk                    (0x1U << I2C_ISR_R_RX_FULL_Pos)                   /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_RX_FULL                        I2C_ISR_R_RX_FULL_Msk
#define  I2C_ISR_R_TX_OVER_Pos                    (3)
#define  I2C_ISR_R_TX_OVER_Msk                    (0x1U << I2C_ISR_R_TX_OVER_Pos)                   /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_TX_OVER                        I2C_ISR_R_TX_OVER_Msk
#define  I2C_ISR_R_TX_EMPTY_Pos                   (4)
#define  I2C_ISR_R_TX_EMPTY_Msk                   (0x1U << I2C_ISR_R_TX_EMPTY_Pos)                  /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_TX_EMPTY                       I2C_ISR_R_TX_EMPTY_Msk
#define  I2C_ISR_R_RD_REQ_Pos                     (5)
#define  I2C_ISR_R_RD_REQ_Msk                     (0x1U << I2C_ISR_R_RD_REQ_Pos)                    /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_RD_REQ                         I2C_ISR_R_RD_REQ_Msk
#define  I2C_ISR_R_TX_ABRT_Pos                    (6)
#define  I2C_ISR_R_TX_ABRT_Msk                    (0x1U << I2C_ISR_R_TX_ABRT_Pos)                   /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_TX_ABRT                        I2C_ISR_R_TX_ABRT_Msk
#define  I2C_ISR_R_RX_DONE_Pos                    (7)
#define  I2C_ISR_R_RX_DONE_Msk                    (0x1U << I2C_ISR_R_RX_DONE_Pos)                   /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_RX_DONE                        I2C_ISR_R_RX_DONE_Msk
#define  I2C_ISR_R_ACTIV_Pos                      (8)
#define  I2C_ISR_R_ACTIV_Msk                      (0x1U << I2C_ISR_R_ACTIV_Pos)                     /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_ACTIV                          I2C_ISR_R_ACTIV_Msk
#define  I2C_ISR_R_STOP_Pos                       (9)
#define  I2C_ISR_R_STOP_Msk                       (0x1U << I2C_ISR_R_STOP_Pos)                      /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_STOP                           I2C_ISR_R_STOP_Msk
#define  I2C_ISR_R_START_Pos                      (10)
#define  I2C_ISR_R_START_Msk                      (0x1U << I2C_ISR_R_START_Pos)                     /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_START                          I2C_ISR_R_START_Msk
#define  I2C_ISR_R_GC_Pos                         (11)
#define  I2C_ISR_R_GC_Msk                         (0x1U << I2C_ISR_R_GC_Pos)                        /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_GC                             I2C_ISR_R_GC_Msk
#define  I2C_ISR_R_MST_ON_HOLD_Pos                (13)
#define  I2C_ISR_R_MST_ON_HOLD_Msk                (0x1U << I2C_ISR_R_MST_ON_HOLD_Pos)               /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_MST_ON_HOLD                    I2C_ISR_R_MST_ON_HOLD_Msk
#define  I2C_ISR_R_SCL_STUCK_AT_LOW_Pos           (14)
#define  I2C_ISR_R_SCL_STUCK_AT_LOW_Msk           (0x1U << I2C_ISR_R_SCL_STUCK_AT_LOW_Pos)          /*!<Refer to I2C_RAWISR register for more details*/
#define  I2C_ISR_R_SCL_STUCK_AT_LOW               I2C_ISR_R_SCL_STUCK_AT_LOW_Msk

/**
  * @brief I2C_IMR Register Bit Definition
  */
#define  I2C_IMR_M_RX_UNDER_Pos                   (0)
#define  I2C_IMR_M_RX_UNDER_Msk                   (0x1U << I2C_IMR_M_RX_UNDER_Pos)                  /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_RX_UNDER                       I2C_IMR_M_RX_UNDER_Msk
#define  I2C_IMR_M_RX_OVER_Pos                    (1)
#define  I2C_IMR_M_RX_OVER_Msk                    (0x1U << I2C_IMR_M_RX_OVER_Pos)                   /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_RX_OVER                        I2C_IMR_M_RX_OVER_Msk
#define  I2C_IMR_M_RX_FULL_Pos                    (2)
#define  I2C_IMR_M_RX_FULL_Msk                    (0x1U << I2C_IMR_M_RX_FULL_Pos)                   /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_RX_FULL                        I2C_IMR_M_RX_FULL_Msk
#define  I2C_IMR_M_TX_OVER_Pos                    (3)
#define  I2C_IMR_M_TX_OVER_Msk                    (0x1U << I2C_IMR_M_TX_OVER_Pos)                   /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_TX_OVER                        I2C_IMR_M_TX_OVER_Msk
#define  I2C_IMR_M_TX_EMPTY_Pos                   (4)
#define  I2C_IMR_M_TX_EMPTY_Msk                   (0x1U << I2C_IMR_M_TX_EMPTY_Pos)                  /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_TX_EMPTY                       I2C_IMR_M_TX_EMPTY_Msk
#define  I2C_IMR_M_RD_REQ_Pos                     (5)
#define  I2C_IMR_M_RD_REQ_Msk                     (0x1U << I2C_IMR_M_RD_REQ_Pos)                    /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_RD_REQ                         I2C_IMR_M_RD_REQ_Msk
#define  I2C_IMR_M_TX_ABRT_Pos                    (6)
#define  I2C_IMR_M_TX_ABRT_Msk                    (0x1U << I2C_IMR_M_TX_ABRT_Pos)                   /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_TX_ABRT                        I2C_IMR_M_TX_ABRT_Msk
#define  I2C_IMR_M_RX_DONE_Pos                    (7)
#define  I2C_IMR_M_RX_DONE_Msk                    (0x1U << I2C_IMR_M_RX_DONE_Pos)                   /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_RX_DONE                        I2C_IMR_M_RX_DONE_Msk
#define  I2C_IMR_M_ACTIV_Pos                      (8)
#define  I2C_IMR_M_ACTIV_Msk                      (0x1U << I2C_IMR_M_ACTIV_Pos)                     /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_ACTIV                          I2C_IMR_M_ACTIV_Msk
#define  I2C_IMR_M_STOP_Pos                       (9)
#define  I2C_IMR_M_STOP_Msk                       (0x1U << I2C_IMR_M_STOP_Pos)                      /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_STOP                           I2C_IMR_M_STOP_Msk
#define  I2C_IMR_M_START_Pos                      (10)
#define  I2C_IMR_M_START_Msk                      (0x1U << I2C_IMR_M_START_Pos)                     /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_START                          I2C_IMR_M_START_Msk
#define  I2C_IMR_M_GC_Pos                         (11)
#define  I2C_IMR_M_GC_Msk                         (0x1U << I2C_IMR_M_GC_Pos)                        /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_GC                             I2C_IMR_M_GC_Msk
#define  I2C_IMR_M_MST_ON_HOLD_Pos                (13)
#define  I2C_IMR_M_MST_ON_HOLD_Msk                (0x1U << I2C_IMR_M_MST_ON_HOLD_Pos)               /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_MST_ON_HOLD                    I2C_IMR_M_MST_ON_HOLD_Msk
#define  I2C_IMR_M_SCL_STUCK_Pos                  (14)
#define  I2C_IMR_M_SCL_STUCK_Msk                  (0x1U << I2C_IMR_M_SCL_STUCK_Pos)                 /*!<Mask the interrupt status bit corresponding to I2C_ISR register*/
#define  I2C_IMR_M_SCL_STUCK                      I2C_IMR_M_SCL_STUCK_Msk

/**
  * @brief I2C_RAWISR Register Bit Definition
  */
#define  I2C_RAWISR_RX_UNDER_Pos                  (0)
#define  I2C_RAWISR_RX_UNDER_Msk                  (0x1U << I2C_RAWISR_RX_UNDER_Pos)                 /*!<Receive buffer over Set if the processor attempts to read the I2C_DR register when RX FIFO is empty.*/
#define  I2C_RAWISR_RX_UNDER                      I2C_RAWISR_RX_UNDER_Msk
#define  I2C_RAWISR_RX_OVER_Pos                   (1)
#define  I2C_RAWISR_RX_OVER_Msk                   (0x1U << I2C_RAWISR_RX_OVER_Pos)                  /*!<Receive buffer over Set if the receive buffer is full and an additional byte is received. The I2C interface acknowledges this, but new data will be lost. Note: RX_OVER interrupt cannot occur when RX_FULL_HLD = 1.*/
#define  I2C_RAWISR_RX_OVER                       I2C_RAWISR_RX_OVER_Msk
#define  I2C_RAWISR_RX_FULL_Pos                   (2)
#define  I2C_RAWISR_RX_FULL_Msk                   (0x1U << I2C_RAWISR_RX_FULL_Pos)                  /*!<Receive buffer full Set when the receive buffer is above the threshold. It is cleared by hardware when the receive buffer level is at or below the threshold.*/
#define  I2C_RAWISR_RX_FULL                       I2C_RAWISR_RX_FULL_Msk
#define  I2C_RAWISR_TX_OVER_Pos                   (3)
#define  I2C_RAWISR_TX_OVER_Msk                   (0x1U << I2C_RAWISR_TX_OVER_Pos)                  /*!<Transmit buffer over When the transmit buffer is full, the processor writes new data and causes overflow, which sets the bit to 1.*/
#define  I2C_RAWISR_TX_OVER                       I2C_RAWISR_TX_OVER_Msk
#define  I2C_RAWISR_TX_EMPTY_Pos                  (4)
#define  I2C_RAWISR_TX_EMPTY_Msk                  (0x1U << I2C_RAWISR_TX_EMPTY_Pos)                 /*!<Transmit buffer empty*/
#define  I2C_RAWISR_TX_EMPTY                      I2C_RAWISR_TX_EMPTY_Msk
#define  I2C_RAWISR_RD_REQ_Pos                    (5)
#define  I2C_RAWISR_RD_REQ_Msk                    (0x1U << I2C_RAWISR_RD_REQ_Pos)                   /*!<Read request*/
#define  I2C_RAWISR_RD_REQ                        I2C_RAWISR_RD_REQ_Msk
#define  I2C_RAWISR_TX_ABRT_Pos                   (6)
#define  I2C_RAWISR_TX_ABRT_Msk                   (0x1U << I2C_RAWISR_TX_ABRT_Pos)                  /*!<Transmit abort*/
#define  I2C_RAWISR_TX_ABRT                       I2C_RAWISR_TX_ABRT_Msk
#define  I2C_RAWISR_RX_DONE_Pos                   (7)
#define  I2C_RAWISR_RX_DONE_Msk                   (0x1U << I2C_RAWISR_RX_DONE_Pos)                  /*!<Slave transmit done When the I2C is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.*/
#define  I2C_RAWISR_RX_DONE                       I2C_RAWISR_RX_DONE_Msk
#define  I2C_RAWISR_ACTIV_Pos                     (8)
#define  I2C_RAWISR_ACTIV_Msk                     (0x1U << I2C_RAWISR_ACTIV_Pos)                    /*!<This bit captures I2C module activity. Once this bit is set, it stays set unless one of the four methods is used to clear it: Disabling the I2C Reading the I2C_ACTIV register Reading the I2C_ICR register System reset Even if the I2C is idle, this bit remains set until cleared.*/
#define  I2C_RAWISR_ACTIV                         I2C_RAWISR_ACTIV_Msk
#define  I2C_RAWISR_STOP_Pos                      (9)
#define  I2C_RAWISR_STOP_Msk                      (0x1U << I2C_RAWISR_STOP_Pos)                     /*!<STOP condition detection The status of this bit differs based on the status of I2C_CR.STOPINT (bit 7): STOPINT = 0*/
#define  I2C_RAWISR_STOP                          I2C_RAWISR_STOP_Msk
#define  I2C_RAWISR_START_Pos                     (10)
#define  I2C_RAWISR_START_Msk                     (0x1U << I2C_RAWISR_START_Pos)                    /*!<START condition detection This bit is set to 1 once a START or RESTART condition has occurred on the I2C interface regardless of whether I2C is operating in Master or Slave mode.*/
#define  I2C_RAWISR_START                         I2C_RAWISR_START_Msk
#define  I2C_RAWISR_GC_Pos                        (11)
#define  I2C_RAWISR_GC_Msk                        (0x1U << I2C_RAWISR_GC_Pos)                       /*!<General Call Set when a General Call address is received and acknowledged. It is cleared either by disabling I2C or when the CPU reads the I2C_GC.GC (bit 0). I2C stores the received data in the Rx buffer.*/
#define  I2C_RAWISR_GC                            I2C_RAWISR_GC_Msk
#define  I2C_RAWISR_MST_ON_HOLD_Pos               (13)
#define  I2C_RAWISR_MST_ON_HOLD_Msk               (0x1U << I2C_RAWISR_MST_ON_HOLD_Pos)              /*!<Indicates whether a master is holding the bus and the TX FIFO is empty.*/
#define  I2C_RAWISR_MST_ON_HOLD                   I2C_RAWISR_MST_ON_HOLD_Msk
#define  I2C_RAWISR_SCL_STUCK_Pos                 (14)
#define  I2C_RAWISR_SCL_STUCK_Msk                 (0x1U << I2C_RAWISR_SCL_STUCK_Pos)                /*!<Indicates whether the SCL Line is stuck at low for the I2C_SCL_TMO number of APB clock periods.*/
#define  I2C_RAWISR_SCL_STUCK                     I2C_RAWISR_SCL_STUCK_Msk

/**
  * @brief I2C_RXTLR Register Bit Definition
  */
#define  I2C_RXTLR_TL_Pos                         (0)
#define  I2C_RXTLR_TL_Msk                         (0x3U << I2C_RXTLR_TL_Pos)                        /*!<Receive FIFO threshold level*/
#define  I2C_RXTLR_TL                             I2C_RXTLR_TL_Msk
#define  I2C_RXTLR_TL_Bit0                        (0x1U << I2C_RXTLR_TL_Pos) 
#define  I2C_RXTLR_TL_Bit1                        (0x2U << I2C_RXTLR_TL_Pos) 

/**
  * @brief I2C_TXTLR Register Bit Definition
  */
#define  I2C_TXTLR_TL_Pos                         (0)
#define  I2C_TXTLR_TL_Msk                         (0x3U << I2C_TXTLR_TL_Pos)                        /*!<Transmit FIFO threshold level*/
#define  I2C_TXTLR_TL                             I2C_TXTLR_TL_Msk
#define  I2C_TXTLR_TL_Bit0                        (0x1U << I2C_TXTLR_TL_Pos) 
#define  I2C_TXTLR_TL_Bit1                        (0x2U << I2C_TXTLR_TL_Pos) 

/**
  * @brief I2C_ICR Register Bit Definition
  */
#define  I2C_ICR_ICR_Pos                          (0)
#define  I2C_ICR_ICR_Msk                          (0x1U << I2C_ICR_ICR_Pos)                         /*!<Reading this register clears all combined and independent interrupts. This bit only clears software clearable interrupts, instead of hardware clearable interrupts*/
#define  I2C_ICR_ICR                              I2C_ICR_ICR_Msk

/**
  * @brief I2C_RX_UNDER Register Bit Definition
  */
#define  I2C_RX_UNDER_RX_UNDER_Pos                (0)
#define  I2C_RX_UNDER_RX_UNDER_Msk                (0x1U << I2C_RX_UNDER_RX_UNDER_Pos)               /*!<Reading this register clears the RX_UNDER interrupt (I2C_RAWISR[0]).*/
#define  I2C_RX_UNDER_RX_UNDER                    I2C_RX_UNDER_RX_UNDER_Msk

/**
  * @brief I2C_RX_OVER Register Bit Definition
  */
#define  I2C_RX_OVER_RX_OVER_Pos                  (0)
#define  I2C_RX_OVER_RX_OVER_Msk                  (0x1U << I2C_RX_OVER_RX_OVER_Pos)                 /*!<Reading this register clears the RX_OVER interrupt (I2C_RAWISR[1]).*/
#define  I2C_RX_OVER_RX_OVER                      I2C_RX_OVER_RX_OVER_Msk

/**
  * @brief I2C_TX_OVER Register Bit Definition
  */
#define  I2C_TX_OVER_TX_OVER_Pos                  (0)
#define  I2C_TX_OVER_TX_OVER_Msk                  (0x1U << I2C_TX_OVER_TX_OVER_Pos)                 /*!<Reading this register clears the TX_OVER interrupt (I2C_RAWISR[3]).*/
#define  I2C_TX_OVER_TX_OVER                      I2C_TX_OVER_TX_OVER_Msk

/**
  * @brief I2C_RD_REQ Register Bit Definition
  */
#define  I2C_RD_REQ_RD_REQ_Pos                    (0)
#define  I2C_RD_REQ_RD_REQ_Msk                    (0x1U << I2C_RD_REQ_RD_REQ_Pos)                   /*!<Reading this register clears the RD_REQ interrupt (I2C_RAWISR[5]).*/
#define  I2C_RD_REQ_RD_REQ                        I2C_RD_REQ_RD_REQ_Msk

/**
  * @brief I2C_TX_ABRT Register Bit Definition
  */
#define  I2C_TX_ABRT_TX_ABRT_Pos                  (0)
#define  I2C_TX_ABRT_TX_ABRT_Msk                  (0x1U << I2C_TX_ABRT_TX_ABRT_Pos)                 /*!<Reading this register clears the TX_ABRT interrupt (I2C_RAWISR[6]). This also releases the TX FIFO from the flushed/reset state, allowing more writes to the TX FIFO.*/
#define  I2C_TX_ABRT_TX_ABRT                      I2C_TX_ABRT_TX_ABRT_Msk

/**
  * @brief I2C_RX_DONE Register Bit Definition
  */
#define  I2C_RX_DONE_RX_DONE_Pos                  (0)
#define  I2C_RX_DONE_RX_DONE_Msk                  (0x1U << I2C_RX_DONE_RX_DONE_Pos)                 /*!<Reading this register clears the RX_DONE interrupt (I2C_RAWISR[7]).*/
#define  I2C_RX_DONE_RX_DONE                      I2C_RX_DONE_RX_DONE_Msk

/**
  * @brief I2C_ACTIV Register Bit Definition
  */
#define  I2C_ACTIV_ACTIV_Pos                      (0)
#define  I2C_ACTIV_ACTIV_Msk                      (0x1U << I2C_ACTIV_ACTIV_Pos)                     /*!<Reading this register clears the ACTIV interrupt (I2C_RAWISR[8]) if the I2C is not active anymore.*/
#define  I2C_ACTIV_ACTIV                          I2C_ACTIV_ACTIV_Msk

/**
  * @brief I2C_STOP Register Bit Definition
  */
#define  I2C_STOP_STOP_Pos                        (0)
#define  I2C_STOP_STOP_Msk                        (0x1U << I2C_STOP_STOP_Pos)                       /*!<Reading this register clears the STOP interrupt (I2C_RAWISR[9]).*/
#define  I2C_STOP_STOP                            I2C_STOP_STOP_Msk

/**
  * @brief I2C_START Register Bit Definition
  */
#define  I2C_START_START_Pos                      (0)
#define  I2C_START_START_Msk                      (0x1U << I2C_START_START_Pos)                     /*!<Reading this register clears the START interrupt (I2C_RAWISR[10]).*/
#define  I2C_START_START                          I2C_START_START_Msk

/**
  * @brief I2C_GC Register Bit Definition
  */
#define  I2C_GC_GC_Pos                            (0)
#define  I2C_GC_GC_Msk                            (0x1U << I2C_GC_GC_Pos)                           /*!<Reading this register clears the GC interrupt (I2C_RAWISR[11]).*/
#define  I2C_GC_GC                                I2C_GC_GC_Msk

/**
  * @brief I2C_ENR Register Bit Definition
  */
#define  I2C_ENR_ENABLE_Pos                       (0)
#define  I2C_ENR_ENABLE_Msk                       (0x1U << I2C_ENR_ENABLE_Pos)                      /*!<I2C module enable*/
#define  I2C_ENR_ENABLE                           I2C_ENR_ENABLE_Msk
#define  I2C_ENR_ABORT_Pos                        (1)
#define  I2C_ENR_ABORT_Msk                        (0x1U << I2C_ENR_ABORT_Pos)                       /*!<I2C transfer abort*/
#define  I2C_ENR_ABORT                            I2C_ENR_ABORT_Msk
#define  I2C_ENR_TX_CMD_BLOCK_Pos                 (2)
#define  I2C_ENR_TX_CMD_BLOCK_Msk                 (0x1U << I2C_ENR_TX_CMD_BLOCK_Pos)                /*!<In master mode,*/
#define  I2C_ENR_TX_CMD_BLOCK                     I2C_ENR_TX_CMD_BLOCK_Msk
#define  I2C_ENR_SDA_RCV_EN_Pos                   (3)
#define  I2C_ENR_SDA_RCV_EN_Msk                   (0x1U << I2C_ENR_SDA_RCV_EN_Pos)                  /*!<If SDA is stuck at low indicated through the TX_ABORT interrupt, then this bit is used as a control knob to initiate the SDA Recovery Mechanism (that is, send at most 9 SCL clocks and STOP to release the SDA line) and then this bit gets auto clear.*/
#define  I2C_ENR_SDA_RCV_EN                       I2C_ENR_SDA_RCV_EN_Msk
#define  I2C_ENR_SMB_CLK_RST_Pos                  (16)
#define  I2C_ENR_SMB_CLK_RST_Msk                  (0x1U << I2C_ENR_SMB_CLK_RST_Pos)                 /*!<This bit is used in SMBus Host mode to initiate the SMBus Master Clock Reset. Whenever this bit is enabled, SMBCLK is held low for I2C_SCL_TMO.SCL_TIMEOUT APB cycles to reset the slave device.*/
#define  I2C_ENR_SMB_CLK_RST                      I2C_ENR_SMB_CLK_RST_Msk
#define  I2C_ENR_SMB_ALT_EN_Pos                   (18)
#define  I2C_ENR_SMB_ALT_EN_Msk                   (0x1U << I2C_ENR_SMB_ALT_EN_Pos)                  /*!<SMBus Alert Enable*/
#define  I2C_ENR_SMB_ALT_EN                       I2C_ENR_SMB_ALT_EN_Msk

/**
  * @brief I2C_SR Register Bit Definition
  */
#define  I2C_SR_ACTIV_Pos                         (0)
#define  I2C_SR_ACTIV_Msk                         (0x1U << I2C_SR_ACTIV_Pos)                        /*!<I2C activity status*/
#define  I2C_SR_ACTIV                             I2C_SR_ACTIV_Msk
#define  I2C_SR_TFNF_Pos                          (1)
#define  I2C_SR_TFNF_Msk                          (0x1U << I2C_SR_TFNF_Pos)                         /*!<Transmit FIFO not full*/
#define  I2C_SR_TFNF                              I2C_SR_TFNF_Msk
#define  I2C_SR_TFE_Pos                           (2)
#define  I2C_SR_TFE_Msk                           (0x1U << I2C_SR_TFE_Pos)                          /*!<Transmit FIFO completely empty*/
#define  I2C_SR_TFE                               I2C_SR_TFE_Msk
#define  I2C_SR_RFNE_Pos                          (3)
#define  I2C_SR_RFNE_Msk                          (0x1U << I2C_SR_RFNE_Pos)                         /*!<Receive FIFO not empty*/
#define  I2C_SR_RFNE                              I2C_SR_RFNE_Msk
#define  I2C_SR_RFF_Pos                           (4)
#define  I2C_SR_RFF_Msk                           (0x1U << I2C_SR_RFF_Pos)                          /*!<Receive FIFO completely full*/
#define  I2C_SR_RFF                               I2C_SR_RFF_Msk
#define  I2C_SR_MST_ACTIV_Pos                     (5)
#define  I2C_SR_MST_ACTIV_Msk                     (0x1U << I2C_SR_MST_ACTIV_Pos)                    /*!<Master FSM activity status*/
#define  I2C_SR_MST_ACTIV                         I2C_SR_MST_ACTIV_Msk
#define  I2C_SR_SLV_ACTIV_Pos                     (6)
#define  I2C_SR_SLV_ACTIV_Msk                     (0x1U << I2C_SR_SLV_ACTIV_Pos)                    /*!<Slave FSM activity status*/
#define  I2C_SR_SLV_ACTIV                         I2C_SR_SLV_ACTIV_Msk
#define  I2C_SR_MST_HOLD_TX_EMPTY_Pos             (7)
#define  I2C_SR_MST_HOLD_TX_EMPTY_Msk             (0x1U << I2C_SR_MST_HOLD_TX_EMPTY_Pos)            /*!<This bit indicates the BUS hold when the master holds the bus because of the TX FIFO being empty*/
#define  I2C_SR_MST_HOLD_TX_EMPTY                 I2C_SR_MST_HOLD_TX_EMPTY_Msk
#define  I2C_SR_MST_HOLD_RX_FULL_Pos              (8)
#define  I2C_SR_MST_HOLD_RX_FULL_Msk              (0x1U << I2C_SR_MST_HOLD_RX_FULL_Pos)             /*!<This bit indicates the BUS Hold in Master mode due to RX FIFO is Full and additional byte has been received*/
#define  I2C_SR_MST_HOLD_RX_FULL                  I2C_SR_MST_HOLD_RX_FULL_Msk
#define  I2C_SR_SLV_HOLD_TX_EMPTY_Pos             (9)
#define  I2C_SR_SLV_HOLD_TX_EMPTY_Msk             (0x1U << I2C_SR_SLV_HOLD_TX_EMPTY_Pos)            /*!<This bit indicates the BUS Hold in Slave mode for the Read request when the TX FIFO is empty. The Bus is in hold until the TX FIFO has data to Transmit for the read request.*/
#define  I2C_SR_SLV_HOLD_TX_EMPTY                 I2C_SR_SLV_HOLD_TX_EMPTY_Msk
#define  I2C_SR_SLV_HOLD_RX_FULL_Pos              (10)
#define  I2C_SR_SLV_HOLD_RX_FULL_Msk              (0x1U << I2C_SR_SLV_HOLD_RX_FULL_Pos)             /*!<This bit indicates the BUS Hold in Slave mode due to the RX FIFO being Full and an additional byte being received*/
#define  I2C_SR_SLV_HOLD_RX_FULL                  I2C_SR_SLV_HOLD_RX_FULL_Msk
#define  I2C_SR_SDA_NOT_RECOVERED_Pos             (11)
#define  I2C_SR_SDA_NOT_RECOVERED_Msk             (0x1U << I2C_SR_SDA_NOT_RECOVERED_Pos)            /*!<This bit indicates that an SDA stuck at low is not recovered after the recovery mechanism.*/
#define  I2C_SR_SDA_NOT_RECOVERED                 I2C_SR_SDA_NOT_RECOVERED_Msk
#define  I2C_SR_SMB_QC_Pos                        (16)
#define  I2C_SR_SMB_QC_Msk                        (0x1U << I2C_SR_SMB_QC_Pos)                       /*!<SMBus Quick command status bit*/
#define  I2C_SR_SMB_QC                            I2C_SR_SMB_QC_Msk
#define  I2C_SR_SMB_SLV_AV_Pos                    (17)
#define  I2C_SR_SMB_SLV_AV_Msk                    (0x1U << I2C_SR_SMB_SLV_AV_Pos)                   /*!<SMBus Slave Address Valid Status Bit*/
#define  I2C_SR_SMB_SLV_AV                        I2C_SR_SMB_SLV_AV_Msk
#define  I2C_SR_SMB_SLV_AR_Pos                    (18)
#define  I2C_SR_SMB_SLV_AR_Msk                    (0x1U << I2C_SR_SMB_SLV_AR_Pos)                   /*!<SMBus Slave Address Resolved status bits*/
#define  I2C_SR_SMB_SLV_AR                        I2C_SR_SMB_SLV_AR_Msk
#define  I2C_SR_SMB_ALT_Pos                       (20)
#define  I2C_SR_SMB_ALT_Msk                       (0x1U << I2C_SR_SMB_ALT_Pos)                      /*!<SMBus alert status bit*/
#define  I2C_SR_SMB_ALT                           I2C_SR_SMB_ALT_Msk

/**
  * @brief I2C_TXFLR Register Bit Definition
  */
#define  I2C_TXFLR_CNT_Pos                        (0)
#define  I2C_TXFLR_CNT_Msk                        (0x7U << I2C_TXFLR_CNT_Pos)                       /*!<Contains the number of valid data entries in the transmit FIFO (0~4)*/
#define  I2C_TXFLR_CNT                            I2C_TXFLR_CNT_Msk
#define  I2C_TXFLR_CNT_Bit0                       (0x1U << I2C_TXFLR_CNT_Pos) 
#define  I2C_TXFLR_CNT_Bit1                       (0x2U << I2C_TXFLR_CNT_Pos) 
#define  I2C_TXFLR_CNT_Bit2                       (0x4U << I2C_TXFLR_CNT_Pos) 

/**
  * @brief I2C_RXFLR Register Bit Definition
  */
#define  I2C_RXFLR_CNT_Pos                        (0)
#define  I2C_RXFLR_CNT_Msk                        (0x7U << I2C_RXFLR_CNT_Pos)                       /*!<Contains the number of valid data entries in the receive FIFO (0~4)*/
#define  I2C_RXFLR_CNT                            I2C_RXFLR_CNT_Msk
#define  I2C_RXFLR_CNT_Bit0                       (0x1U << I2C_RXFLR_CNT_Pos) 
#define  I2C_RXFLR_CNT_Bit1                       (0x2U << I2C_RXFLR_CNT_Pos) 
#define  I2C_RXFLR_CNT_Bit2                       (0x4U << I2C_RXFLR_CNT_Pos) 

/**
  * @brief I2C_HOLD Register Bit Definition
  */
#define  I2C_HOLD_TX_HOLD_Pos                     (0)
#define  I2C_HOLD_TX_HOLD_Msk                     (0xFFFFU << I2C_HOLD_TX_HOLD_Pos)                 /*!<Sets the SDA hold time (after SCL goes from high to low ) in units of APB clock period, when I2C device acts as a transmitter.*/
#define  I2C_HOLD_TX_HOLD                         I2C_HOLD_TX_HOLD_Msk
#define  I2C_HOLD_TX_HOLD_Bit0                    (0x0001U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit1                    (0x0002U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit2                    (0x0004U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit3                    (0x0008U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit4                    (0x0010U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit5                    (0x0020U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit6                    (0x0040U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit7                    (0x0080U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit8                    (0x0100U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit9                    (0x0200U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit10                   (0x0400U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit11                   (0x0800U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit12                   (0x1000U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit13                   (0x2000U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit14                   (0x4000U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_TX_HOLD_Bit15                   (0x8000U << I2C_HOLD_TX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Pos                     (16)
#define  I2C_HOLD_RX_HOLD_Msk                     (0xFFU << I2C_HOLD_RX_HOLD_Pos)                   /*!<Sets the internal SDA hold time (valid while SCL is high) in units of APB clock period, when I2C device acts as a receiver.*/
#define  I2C_HOLD_RX_HOLD                         I2C_HOLD_RX_HOLD_Msk
#define  I2C_HOLD_RX_HOLD_Bit0                    (0x01U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit1                    (0x02U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit2                    (0x04U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit3                    (0x08U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit4                    (0x10U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit5                    (0x20U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit6                    (0x40U << I2C_HOLD_RX_HOLD_Pos) 
#define  I2C_HOLD_RX_HOLD_Bit7                    (0x80U << I2C_HOLD_RX_HOLD_Pos) 

/**
  * @brief I2C_TX_ABRT_SRC Register Bit Definition
  */
#define  I2C_TX_ABRT_SRC_7ADDR_NOACK_Pos          (0)
#define  I2C_TX_ABRT_SRC_7ADDR_NOACK_Msk          (0x1U << I2C_TX_ABRT_SRC_7ADDR_NOACK_Pos)         /*!<Set when the master device operates in 7-bit addressing mode and no slave device responds to the address*/
#define  I2C_TX_ABRT_SRC_7ADDR_NOACK              I2C_TX_ABRT_SRC_7ADDR_NOACK_Msk
#define  I2C_TX_ABRT_SRC_10ADDR1_NOACK_Pos        (1)
#define  I2C_TX_ABRT_SRC_10ADDR1_NOACK_Msk        (0x1U << I2C_TX_ABRT_SRC_10ADDR1_NOACK_Pos)       /*!<Set when the master device operates in 10-bit addressing mode and no slave device responds to the first address byte*/
#define  I2C_TX_ABRT_SRC_10ADDR1_NOACK            I2C_TX_ABRT_SRC_10ADDR1_NOACK_Msk
#define  I2C_TX_ABRT_SRC_10ADDR2_NOACK_Pos        (2)
#define  I2C_TX_ABRT_SRC_10ADDR2_NOACK_Msk        (0x1U << I2C_TX_ABRT_SRC_10ADDR2_NOACK_Pos)       /*!<Set when the master device operates in 10-bit addressing mode and no slave device responds to the second address byte*/
#define  I2C_TX_ABRT_SRC_10ADDR2_NOACK            I2C_TX_ABRT_SRC_10ADDR2_NOACK_Msk
#define  I2C_TX_ABRT_SRC_TXDATA_NOACK_Pos         (3)
#define  I2C_TX_ABRT_SRC_TXDATA_NOACK_Msk         (0x1U << I2C_TX_ABRT_SRC_TXDATA_NOACK_Pos)        /*!<Set when the master device receives an address response and no slave device responds to the data sent*/
#define  I2C_TX_ABRT_SRC_TXDATA_NOACK             I2C_TX_ABRT_SRC_TXDATA_NOACK_Msk
#define  I2C_TX_ABRT_SRC_GC_NOACK_Pos             (4)
#define  I2C_TX_ABRT_SRC_GC_NOACK_Msk             (0x1U << I2C_TX_ABRT_SRC_GC_NOACK_Pos)            /*!<Set when no slave device responds after a general call is sent by the master device*/
#define  I2C_TX_ABRT_SRC_GC_NOACK                 I2C_TX_ABRT_SRC_GC_NOACK_Msk
#define  I2C_TX_ABRT_SRC_GC_READ_Pos              (5)
#define  I2C_TX_ABRT_SRC_GC_READ_Msk              (0x1U << I2C_TX_ABRT_SRC_GC_READ_Pos)             /*!<Set when the master device sends a general call, followed by a read request*/
#define  I2C_TX_ABRT_SRC_GC_READ                  I2C_TX_ABRT_SRC_GC_READ_Msk
#define  I2C_TX_ABRT_SRC_SBYTE_ACKDET_Pos         (7)
#define  I2C_TX_ABRT_SRC_SBYTE_ACKDET_Msk         (0x1U << I2C_TX_ABRT_SRC_SBYTE_ACKDET_Pos)        /*!<Set when the master device sends the start byte and is responded (error behavior)*/
#define  I2C_TX_ABRT_SRC_SBYTE_ACKDET             I2C_TX_ABRT_SRC_SBYTE_ACKDET_Msk
#define  I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Pos        (9)
#define  I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Msk        (0x1U << I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Pos)       /*!<Send the start byte when RESTART is not enabled (I2C_CR.REPEN is 0) and this bit is set*/
#define  I2C_TX_ABRT_SRC_SBYTE_NORSTRT            I2C_TX_ABRT_SRC_SBYTE_NORSTRT_Msk
#define  I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Pos       (10)
#define  I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Msk       (0x1U << I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Pos)      /*!<This bit is set when RESTART is not enabled (I2C_CR.REPEN is 0) and the master device sends a read request in 10-bit addressing mode*/
#define  I2C_TX_ABRT_SRC_10B_RD_NORSTRT           I2C_TX_ABRT_SRC_10B_RD_NORSTRT_Msk
#define  I2C_TX_ABRT_SRC_MST_DIS_Pos              (11)
#define  I2C_TX_ABRT_SRC_MST_DIS_Msk              (0x1U << I2C_TX_ABRT_SRC_MST_DIS_Pos)             /*!<This bit is set when the master device is operated in the disabled master mode*/
#define  I2C_TX_ABRT_SRC_MST_DIS                  I2C_TX_ABRT_SRC_MST_DIS_Msk
#define  I2C_TX_ABRT_SRC_LOST_Pos                 (12)
#define  I2C_TX_ABRT_SRC_LOST_Msk                 (0x1U << I2C_TX_ABRT_SRC_LOST_Pos)                /*!<This bit is set if the master device arbitration fails, or the slave device arbitration fails when bit 14 is set to 1*/
#define  I2C_TX_ABRT_SRC_LOST                     I2C_TX_ABRT_SRC_LOST_Msk
#define  I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Pos      (13)
#define  I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Msk      (0x1U << I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Pos)     /*!<1: Data is still in TX FIFO when the slave device receives the read request, and the slave device clears the old data in TX FIFO by generating TX_ABRT interrupt.*/
#define  I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO          I2C_TX_ABRT_SRC_SLVFLUSH_TXFIFO_Msk
#define  I2C_TX_ABRT_SRC_SLV_ARBLOST_Pos          (14)
#define  I2C_TX_ABRT_SRC_SLV_ARBLOST_Msk          (0x1U << I2C_TX_ABRT_SRC_SLV_ARBLOST_Pos)         /*!<This bit and bit 12 are set simultaneously if the bus is lost when the slave device sends data.*/
#define  I2C_TX_ABRT_SRC_SLV_ARBLOST              I2C_TX_ABRT_SRC_SLV_ARBLOST_Msk
#define  I2C_TX_ABRT_SRC_SLVRD_INTX_Pos           (15)
#define  I2C_TX_ABRT_SRC_SLVRD_INTX_Msk           (0x1U << I2C_TX_ABRT_SRC_SLVRD_INTX_Pos)          /*!<This bit is set when I2C is requested for data from send mode to write 1 (read command) to I2C_DR.CMD (bit 8)*/
#define  I2C_TX_ABRT_SRC_SLVRD_INTX               I2C_TX_ABRT_SRC_SLVRD_INTX_Msk
#define  I2C_TX_ABRT_SRC_USER_ABRT_Pos            (16)
#define  I2C_TX_ABRT_SRC_USER_ABRT_Msk            (0x1U << I2C_TX_ABRT_SRC_USER_ABRT_Pos)           /*!<Set when transfer abort (I2C_ENR.ABORT is 1) is detected by the master device*/
#define  I2C_TX_ABRT_SRC_USER_ABRT                I2C_TX_ABRT_SRC_USER_ABRT_Msk
#define  I2C_TX_ABRT_SRC_SDA_LOW_Pos              (17)
#define  I2C_TX_ABRT_SRC_SDA_LOW_Msk              (0x1U << I2C_TX_ABRT_SRC_SDA_LOW_Pos)             /*!<This bit is set when SDA low timeout is detected by the master device*/
#define  I2C_TX_ABRT_SRC_SDA_LOW                  I2C_TX_ABRT_SRC_SDA_LOW_Msk
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos         (23)
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Msk         (0x1FFU << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos)      /*!<Number of data/commands in the TX FIFO that were flushed due to transfer interrupt*/
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT             I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Msk
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit0        (0x001U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit1        (0x002U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit2        (0x004U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit3        (0x008U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit4        (0x010U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit5        (0x020U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit6        (0x040U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit7        (0x080U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 
#define  I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Bit8        (0x100U << I2C_TX_ABRT_SRC_TX_FLUSH_CNT_Pos) 

/**
  * @brief I2C_SLV_NACK Register Bit Definition
  */
#define  I2C_SLV_NACK_NACK_Pos                    (0)
#define  I2C_SLV_NACK_NACK_Msk                    (0x1U << I2C_SLV_NACK_NACK_Pos)                   /*!<0: Generate ACK/NACK normally*/
#define  I2C_SLV_NACK_NACK                        I2C_SLV_NACK_NACK_Msk

/**
  * @brief I2C_DMA Register Bit Definition
  */
#define  I2C_DMA_RXEN_Pos                         (0)
#define  I2C_DMA_RXEN_Msk                         (0x1U << I2C_DMA_RXEN_Pos)                        /*!<Receive DMA enable*/
#define  I2C_DMA_RXEN                             I2C_DMA_RXEN_Msk
#define  I2C_DMA_TXEN_Pos                         (1)
#define  I2C_DMA_TXEN_Msk                         (0x1U << I2C_DMA_TXEN_Pos)                        /*!<Transmit DMA enable*/
#define  I2C_DMA_TXEN                             I2C_DMA_TXEN_Msk

/**
  * @brief I2C_SETUP Register Bit Definition
  */
#define  I2C_SETUP_CNT_Pos                        (0)
#define  I2C_SETUP_CNT_Msk                        (0xFFU << I2C_SETUP_CNT_Pos)                      /*!<SDA setup time (min value is 2)*/
#define  I2C_SETUP_CNT                            I2C_SETUP_CNT_Msk
#define  I2C_SETUP_CNT_Bit0                       (0x01U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit1                       (0x02U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit2                       (0x04U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit3                       (0x08U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit4                       (0x10U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit5                       (0x20U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit6                       (0x40U << I2C_SETUP_CNT_Pos) 
#define  I2C_SETUP_CNT_Bit7                       (0x80U << I2C_SETUP_CNT_Pos) 

/**
  * @brief I2C_GCR Register Bit Definition
  */
#define  I2C_GCR_GC_Pos                           (0)
#define  I2C_GCR_GC_Msk                           (0x1U << I2C_GCR_GC_Pos)                          /*!<ACK General Call*/
#define  I2C_GCR_GC                               I2C_GCR_GC_Msk

/**
  * @brief I2C_EN_SR Register Bit Definition
  */
#define  I2C_EN_SR_IC_EN_Pos                      (0)
#define  I2C_EN_SR_IC_EN_Msk                      (0x1U << I2C_EN_SR_IC_EN_Pos)                     /*!<This bit is set to 1 in the following conditions*/
#define  I2C_EN_SR_IC_EN                          I2C_EN_SR_IC_EN_Msk
#define  I2C_EN_SR_SLV_DIS_WHILE_BUSY_Pos         (1)
#define  I2C_EN_SR_SLV_DIS_WHILE_BUSY_Msk         (0x1U << I2C_EN_SR_SLV_DIS_WHILE_BUSY_Pos)        /*!<This bit indicates whether the ongoing slave mode action has been terminated by setting I2C_ENR.ENABLE from 1 to 0. (Slave Disabled While Busy)*/
#define  I2C_EN_SR_SLV_DIS_WHILE_BUSY             I2C_EN_SR_SLV_DIS_WHILE_BUSY_Msk
#define  I2C_EN_SR_SLV_RX_DATA_LOST_Pos           (2)
#define  I2C_EN_SR_SLV_RX_DATA_LOST_Msk           (0x1U << I2C_EN_SR_SLV_RX_DATA_LOST_Pos)          /*!<This bit indicates that the slave receive action (at least one data byte is received) is interrupted because I2C_ENR.ENABLE is set from 1 to 0. (Slave Received Data Lost)*/
#define  I2C_EN_SR_SLV_RX_DATA_LOST               I2C_EN_SR_SLV_RX_DATA_LOST_Msk

/**
  * @brief I2C_SPKLEN Register Bit Definition
  */
#define  I2C_SPKLEN_SPKLEN_Pos                    (0)
#define  I2C_SPKLEN_SPKLEN_Msk                    (0xFFU << I2C_SPKLEN_SPKLEN_Pos)                  /*!<Configure the Spike Suppression time, whose unit is APB clock period and minimum value is 1.*/
#define  I2C_SPKLEN_SPKLEN                        I2C_SPKLEN_SPKLEN_Msk
#define  I2C_SPKLEN_SPKLEN_Bit0                   (0x01U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit1                   (0x02U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit2                   (0x04U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit3                   (0x08U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit4                   (0x10U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit5                   (0x20U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit6                   (0x40U << I2C_SPKLEN_SPKLEN_Pos) 
#define  I2C_SPKLEN_SPKLEN_Bit7                   (0x80U << I2C_SPKLEN_SPKLEN_Pos) 

/**
  * @brief I2C_SCL_TMO Register Bit Definition
  */
#define  I2C_SCL_TMO_SCL_TIMEOUT_Pos              (0)
#define  I2C_SCL_TMO_SCL_TIMEOUT_Msk              (0xFFFFFFFFU << I2C_SCL_TMO_SCL_TIMEOUT_Pos)      /*!<Configure the duration of SCL low timeout whose unit is APB clock period*/
#define  I2C_SCL_TMO_SCL_TIMEOUT                  I2C_SCL_TMO_SCL_TIMEOUT_Msk
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit0             (0x00000001U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit1             (0x00000002U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit2             (0x00000004U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit3             (0x00000008U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit4             (0x00000010U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit5             (0x00000020U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit6             (0x00000040U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit7             (0x00000080U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit8             (0x00000100U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit9             (0x00000200U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit10            (0x00000400U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit11            (0x00000800U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit12            (0x00001000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit13            (0x00002000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit14            (0x00004000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit15            (0x00008000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit16            (0x00010000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit17            (0x00020000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit18            (0x00040000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit19            (0x00080000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit20            (0x00100000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit21            (0x00200000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit22            (0x00400000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit23            (0x00800000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit24            (0x01000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit25            (0x02000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit26            (0x04000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit27            (0x08000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit28            (0x10000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit29            (0x20000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit30            (0x40000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 
#define  I2C_SCL_TMO_SCL_TIMEOUT_Bit31            (0x80000000U << I2C_SCL_TMO_SCL_TIMEOUT_Pos) 

/**
  * @brief I2C_SDA_TMO Register Bit Definition
  */
#define  I2C_SDA_TMO_SDA_TIMEOUT_Pos              (0)
#define  I2C_SDA_TMO_SDA_TIMEOUT_Msk              (0xFFFFFFFFU << I2C_SDA_TMO_SDA_TIMEOUT_Pos)      /*!<Configure the duration of SDA low timeout whose unit is APB clock period*/
#define  I2C_SDA_TMO_SDA_TIMEOUT                  I2C_SDA_TMO_SDA_TIMEOUT_Msk
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit0             (0x00000001U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit1             (0x00000002U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit2             (0x00000004U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit3             (0x00000008U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit4             (0x00000010U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit5             (0x00000020U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit6             (0x00000040U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit7             (0x00000080U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit8             (0x00000100U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit9             (0x00000200U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit10            (0x00000400U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit11            (0x00000800U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit12            (0x00001000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit13            (0x00002000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit14            (0x00004000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit15            (0x00008000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit16            (0x00010000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit17            (0x00020000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit18            (0x00040000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit19            (0x00080000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit20            (0x00100000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit21            (0x00200000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit22            (0x00400000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit23            (0x00800000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit24            (0x01000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit25            (0x02000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit26            (0x04000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit27            (0x08000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit28            (0x10000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit29            (0x20000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit30            (0x40000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 
#define  I2C_SDA_TMO_SDA_TIMEOUT_Bit31            (0x80000000U << I2C_SDA_TMO_SDA_TIMEOUT_Pos) 

/**
  * @brief I2C_SCL_STUCK Register Bit Definition
  */
#define  I2C_SCL_STUCK_SCL_STUCK_Pos              (0)
#define  I2C_SCL_STUCK_SCL_STUCK_Msk              (0x1U << I2C_SCL_STUCK_SCL_STUCK_Pos)             /*!<Read this register and clear SCL_STUCK interrupt (RAWISR[14])*/
#define  I2C_SCL_STUCK_SCL_STUCK                  I2C_SCL_STUCK_SCL_STUCK_Msk

/**
  * @brief I2C_SMB_SEXT Register Bit Definition
  */
#define  I2C_SMB_SEXT_SMB_SEXT_Pos                (0)
#define  I2C_SMB_SEXT_SMB_SEXT_Msk                (0xFFFFFFFFU << I2C_SMB_SEXT_SMB_SEXT_Pos)        /*!<Configure the slave device clock extension timeout (tLOW:SEXT) whose unit is APB clock period*/
#define  I2C_SMB_SEXT_SMB_SEXT                    I2C_SMB_SEXT_SMB_SEXT_Msk
#define  I2C_SMB_SEXT_SMB_SEXT_Bit0               (0x00000001U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit1               (0x00000002U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit2               (0x00000004U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit3               (0x00000008U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit4               (0x00000010U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit5               (0x00000020U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit6               (0x00000040U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit7               (0x00000080U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit8               (0x00000100U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit9               (0x00000200U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit10              (0x00000400U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit11              (0x00000800U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit12              (0x00001000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit13              (0x00002000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit14              (0x00004000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit15              (0x00008000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit16              (0x00010000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit17              (0x00020000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit18              (0x00040000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit19              (0x00080000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit20              (0x00100000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit21              (0x00200000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit22              (0x00400000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit23              (0x00800000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit24              (0x01000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit25              (0x02000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit26              (0x04000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit27              (0x08000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit28              (0x10000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit29              (0x20000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit30              (0x40000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 
#define  I2C_SMB_SEXT_SMB_SEXT_Bit31              (0x80000000U << I2C_SMB_SEXT_SMB_SEXT_Pos) 

/**
  * @brief I2C_SMB_MEXT Register Bit Definition
  */
#define  I2C_SMB_MEXT_SMB_MEXT_Pos                (0)
#define  I2C_SMB_MEXT_SMB_MEXT_Msk                (0xFFFFFFFFU << I2C_SMB_MEXT_SMB_MEXT_Pos)        /*!<Configure the clock extension timeout (tLOW:MEXT) for master device to transmit a byte. The unit is APB clock period*/
#define  I2C_SMB_MEXT_SMB_MEXT                    I2C_SMB_MEXT_SMB_MEXT_Msk
#define  I2C_SMB_MEXT_SMB_MEXT_Bit0               (0x00000001U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit1               (0x00000002U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit2               (0x00000004U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit3               (0x00000008U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit4               (0x00000010U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit5               (0x00000020U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit6               (0x00000040U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit7               (0x00000080U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit8               (0x00000100U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit9               (0x00000200U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit10              (0x00000400U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit11              (0x00000800U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit12              (0x00001000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit13              (0x00002000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit14              (0x00004000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit15              (0x00008000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit16              (0x00010000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit17              (0x00020000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit18              (0x00040000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit19              (0x00080000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit20              (0x00100000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit21              (0x00200000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit22              (0x00400000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit23              (0x00800000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit24              (0x01000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit25              (0x02000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit26              (0x04000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit27              (0x08000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit28              (0x10000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit29              (0x20000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit30              (0x40000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 
#define  I2C_SMB_MEXT_SMB_MEXT_Bit31              (0x80000000U << I2C_SMB_MEXT_SMB_MEXT_Pos) 

/**
  * @brief I2C_SMB_IDLE Register Bit Definition
  */
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Pos            (0)
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Msk            (0xFFFFU << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos)        /*!<Configure the required bus idle time and the unit is APB clock period*/
#define  I2C_SMB_IDLE_SMB_IDLE_CNT                I2C_SMB_IDLE_SMB_IDLE_CNT_Msk
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit0           (0x0001U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit1           (0x0002U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit2           (0x0004U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit3           (0x0008U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit4           (0x0010U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit5           (0x0020U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit6           (0x0040U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit7           (0x0080U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit8           (0x0100U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit9           (0x0200U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit10          (0x0400U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit11          (0x0800U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit12          (0x1000U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit13          (0x2000U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit14          (0x4000U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 
#define  I2C_SMB_IDLE_SMB_IDLE_CNT_Bit15          (0x8000U << I2C_SMB_IDLE_SMB_IDLE_CNT_Pos) 

/**
  * @brief I2C_SMB_ISR Register Bit Definition
  */
#define  I2C_SMB_ISR_R_SLV_TMO_Pos                (0)
#define  I2C_SMB_ISR_R_SLV_TMO_Msk                (0x1U << I2C_SMB_ISR_R_SLV_TMO_Pos)               /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_SLV_TMO                    I2C_SMB_ISR_R_SLV_TMO_Msk
#define  I2C_SMB_ISR_R_MST_TMO_Pos                (1)
#define  I2C_SMB_ISR_R_MST_TMO_Msk                (0x1U << I2C_SMB_ISR_R_MST_TMO_Pos)               /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_MST_TMO                    I2C_SMB_ISR_R_MST_TMO_Msk
#define  I2C_SMB_ISR_R_ARP_QUICK_Pos              (2)
#define  I2C_SMB_ISR_R_ARP_QUICK_Msk              (0x1U << I2C_SMB_ISR_R_ARP_QUICK_Pos)             /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_ARP_QUICK                  I2C_SMB_ISR_R_ARP_QUICK_Msk
#define  I2C_SMB_ISR_R_ARP_NOTIFY_Pos             (3)
#define  I2C_SMB_ISR_R_ARP_NOTIFY_Msk             (0x1U << I2C_SMB_ISR_R_ARP_NOTIFY_Pos)            /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_ARP_NOTIFY                 I2C_SMB_ISR_R_ARP_NOTIFY_Msk
#define  I2C_SMB_ISR_R_ARP_PRE_Pos                (4)
#define  I2C_SMB_ISR_R_ARP_PRE_Msk                (0x1U << I2C_SMB_ISR_R_ARP_PRE_Pos)               /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_ARP_PRE                    I2C_SMB_ISR_R_ARP_PRE_Msk
#define  I2C_SMB_ISR_R_ARP_RST_Pos                (5)
#define  I2C_SMB_ISR_R_ARP_RST_Msk                (0x1U << I2C_SMB_ISR_R_ARP_RST_Pos)               /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_ARP_RST                    I2C_SMB_ISR_R_ARP_RST_Msk
#define  I2C_SMB_ISR_R_ARP_UDID_Pos               (6)
#define  I2C_SMB_ISR_R_ARP_UDID_Msk               (0x1U << I2C_SMB_ISR_R_ARP_UDID_Pos)              /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_ARP_UDID                   I2C_SMB_ISR_R_ARP_UDID_Msk
#define  I2C_SMB_ISR_R_ARP_ASSGN_Pos              (7)
#define  I2C_SMB_ISR_R_ARP_ASSGN_Msk              (0x1U << I2C_SMB_ISR_R_ARP_ASSGN_Pos)             /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_ARP_ASSGN                  I2C_SMB_ISR_R_ARP_ASSGN_Msk
#define  I2C_SMB_ISR_R_PEC_NACK_Pos               (8)
#define  I2C_SMB_ISR_R_PEC_NACK_Msk               (0x1U << I2C_SMB_ISR_R_PEC_NACK_Pos)              /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_PEC_NACK                   I2C_SMB_ISR_R_PEC_NACK_Msk
#define  I2C_SMB_ISR_R_SMB_ALT_Pos                (10)
#define  I2C_SMB_ISR_R_SMB_ALT_Msk                (0x1U << I2C_SMB_ISR_R_SMB_ALT_Pos)               /*!<Refer to I2C_SMB_RAWISR register for more details*/
#define  I2C_SMB_ISR_R_SMB_ALT                    I2C_SMB_ISR_R_SMB_ALT_Msk

/**
  * @brief I2C_SMB_IMR Register Bit Definition
  */
#define  I2C_SMB_IMR_M_SLV_TMO_Pos                (0)
#define  I2C_SMB_IMR_M_SLV_TMO_Msk                (0x1U << I2C_SMB_IMR_M_SLV_TMO_Pos)               /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_SLV_TMO                    I2C_SMB_IMR_M_SLV_TMO_Msk
#define  I2C_SMB_IMR_M_MST_TMO_Pos                (1)
#define  I2C_SMB_IMR_M_MST_TMO_Msk                (0x1U << I2C_SMB_IMR_M_MST_TMO_Pos)               /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_MST_TMO                    I2C_SMB_IMR_M_MST_TMO_Msk
#define  I2C_SMB_IMR_M_ARP_QUICK_Pos              (2)
#define  I2C_SMB_IMR_M_ARP_QUICK_Msk              (0x1U << I2C_SMB_IMR_M_ARP_QUICK_Pos)             /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_ARP_QUICK                  I2C_SMB_IMR_M_ARP_QUICK_Msk
#define  I2C_SMB_IMR_M_ARP_NOTIFY_Pos             (3)
#define  I2C_SMB_IMR_M_ARP_NOTIFY_Msk             (0x1U << I2C_SMB_IMR_M_ARP_NOTIFY_Pos)            /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_ARP_NOTIFY                 I2C_SMB_IMR_M_ARP_NOTIFY_Msk
#define  I2C_SMB_IMR_M_ARP_PRE_Pos                (4)
#define  I2C_SMB_IMR_M_ARP_PRE_Msk                (0x1U << I2C_SMB_IMR_M_ARP_PRE_Pos)               /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_ARP_PRE                    I2C_SMB_IMR_M_ARP_PRE_Msk
#define  I2C_SMB_IMR_M_ARP_RST_Pos                (5)
#define  I2C_SMB_IMR_M_ARP_RST_Msk                (0x1U << I2C_SMB_IMR_M_ARP_RST_Pos)               /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_ARP_RST                    I2C_SMB_IMR_M_ARP_RST_Msk
#define  I2C_SMB_IMR_M_ARP_UDID_Pos               (6)
#define  I2C_SMB_IMR_M_ARP_UDID_Msk               (0x1U << I2C_SMB_IMR_M_ARP_UDID_Pos)              /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_ARP_UDID                   I2C_SMB_IMR_M_ARP_UDID_Msk
#define  I2C_SMB_IMR_M_ARP_ASSGN_Pos              (7)
#define  I2C_SMB_IMR_M_ARP_ASSGN_Msk              (0x1U << I2C_SMB_IMR_M_ARP_ASSGN_Pos)             /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_ARP_ASSGN                  I2C_SMB_IMR_M_ARP_ASSGN_Msk
#define  I2C_SMB_IMR_M_PEC_NACK_Pos               (8)
#define  I2C_SMB_IMR_M_PEC_NACK_Msk               (0x1U << I2C_SMB_IMR_M_PEC_NACK_Pos)              /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_PEC_NACK                   I2C_SMB_IMR_M_PEC_NACK_Msk
#define  I2C_SMB_IMR_M_SMB_ALT_Pos                (10)
#define  I2C_SMB_IMR_M_SMB_ALT_Msk                (0x1U << I2C_SMB_IMR_M_SMB_ALT_Pos)               /*!<Mask the interrupt status bit corresponding to I2C_SMB_ISR register*/
#define  I2C_SMB_IMR_M_SMB_ALT                    I2C_SMB_IMR_M_SMB_ALT_Msk

/**
  * @brief I2C_SMB_RAWISR Register Bit Definition
  */
#define  I2C_SMB_RAWISR_SLV_TMO_Pos               (0)
#define  I2C_SMB_RAWISR_SLV_TMO_Msk               (0x1U << I2C_SMB_RAWISR_SLV_TMO_Pos)              /*!<This bit is set when the clock for the slave device to communicate for one time extends timeout (START to STOP)*/
#define  I2C_SMB_RAWISR_SLV_TMO                   I2C_SMB_RAWISR_SLV_TMO_Msk
#define  I2C_SMB_RAWISR_MST_TMO_Pos               (1)
#define  I2C_SMB_RAWISR_MST_TMO_Msk               (0x1U << I2C_SMB_RAWISR_MST_TMO_Pos)              /*!<This bit is set when the master device transmits the clock extension timeout of a byte (START to ACK, ACK to ACK, ACK to STOP)*/
#define  I2C_SMB_RAWISR_MST_TMO                   I2C_SMB_RAWISR_MST_TMO_Msk
#define  I2C_SMB_RAWISR_ARP_QUICK_Pos             (2)
#define  I2C_SMB_RAWISR_ARP_QUICK_Msk             (0x1U << I2C_SMB_RAWISR_ARP_QUICK_Pos)            /*!<Set when the Quick command is received*/
#define  I2C_SMB_RAWISR_ARP_QUICK                 I2C_SMB_RAWISR_ARP_QUICK_Msk
#define  I2C_SMB_RAWISR_ARP_NOTIFY_Pos            (3)
#define  I2C_SMB_RAWISR_ARP_NOTIFY_Msk            (0x1U << I2C_SMB_RAWISR_ARP_NOTIFY_Pos)           /*!<Set when the Host Notify command is received*/
#define  I2C_SMB_RAWISR_ARP_NOTIFY                I2C_SMB_RAWISR_ARP_NOTIFY_Msk
#define  I2C_SMB_RAWISR_ARP_PRE_Pos               (4)
#define  I2C_SMB_RAWISR_ARP_PRE_Msk               (0x1U << I2C_SMB_RAWISR_ARP_PRE_Pos)              /*!<Set when the Prepare to ARP command is received*/
#define  I2C_SMB_RAWISR_ARP_PRE                   I2C_SMB_RAWISR_ARP_PRE_Msk
#define  I2C_SMB_RAWISR_ARP_RST_Pos               (5)
#define  I2C_SMB_RAWISR_ARP_RST_Msk               (0x1U << I2C_SMB_RAWISR_ARP_RST_Pos)              /*!<Set when the Reset ARP command is received*/
#define  I2C_SMB_RAWISR_ARP_RST                   I2C_SMB_RAWISR_ARP_RST_Msk
#define  I2C_SMB_RAWISR_ARP_UDID_Pos              (6)
#define  I2C_SMB_RAWISR_ARP_UDID_Msk              (0x1U << I2C_SMB_RAWISR_ARP_UDID_Pos)             /*!<Set when the Get UDID ARP command is received*/
#define  I2C_SMB_RAWISR_ARP_UDID                  I2C_SMB_RAWISR_ARP_UDID_Msk
#define  I2C_SMB_RAWISR_ARP_ASSGN_Pos             (7)
#define  I2C_SMB_RAWISR_ARP_ASSGN_Msk             (0x1U << I2C_SMB_RAWISR_ARP_ASSGN_Pos)            /*!<Set when the Assign Address ARP command is received*/
#define  I2C_SMB_RAWISR_ARP_ASSGN                 I2C_SMB_RAWISR_ARP_ASSGN_Msk
#define  I2C_SMB_RAWISR_PEC_NACK_Pos              (8)
#define  I2C_SMB_RAWISR_PEC_NACK_Msk              (0x1U << I2C_SMB_RAWISR_PEC_NACK_Pos)             /*!<Set when the slave device does not respond to the PEC byte of the ARP command*/
#define  I2C_SMB_RAWISR_PEC_NACK                  I2C_SMB_RAWISR_PEC_NACK_Msk
#define  I2C_SMB_RAWISR_SMB_ALT_Pos               (10)
#define  I2C_SMB_RAWISR_SMB_ALT_Msk               (0x1U << I2C_SMB_RAWISR_SMB_ALT_Pos)              /*!<Set when the slave device alarm is detected (SMBA is low)*/
#define  I2C_SMB_RAWISR_SMB_ALT                   I2C_SMB_RAWISR_SMB_ALT_Msk

/**
  * @brief I2C_SMB_ICR Register Bit Definition
  */
#define  I2C_SMB_ICR_CLR_SLV_TMO_Pos              (0)
#define  I2C_SMB_ICR_CLR_SLV_TMO_Msk              (0x1U << I2C_SMB_ICR_CLR_SLV_TMO_Pos)             /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_SLV_TMO                  I2C_SMB_ICR_CLR_SLV_TMO_Msk
#define  I2C_SMB_ICR_CLR_MST_TMO_Pos              (1)
#define  I2C_SMB_ICR_CLR_MST_TMO_Msk              (0x1U << I2C_SMB_ICR_CLR_MST_TMO_Pos)             /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_MST_TMO                  I2C_SMB_ICR_CLR_MST_TMO_Msk
#define  I2C_SMB_ICR_CLR_ARP_QUICK_Pos            (2)
#define  I2C_SMB_ICR_CLR_ARP_QUICK_Msk            (0x1U << I2C_SMB_ICR_CLR_ARP_QUICK_Pos)           /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_ARP_QUICK                I2C_SMB_ICR_CLR_ARP_QUICK_Msk
#define  I2C_SMB_ICR_CLR_ARP_NOTIFY_Pos           (3)
#define  I2C_SMB_ICR_CLR_ARP_NOTIFY_Msk           (0x1U << I2C_SMB_ICR_CLR_ARP_NOTIFY_Pos)          /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_ARP_NOTIFY               I2C_SMB_ICR_CLR_ARP_NOTIFY_Msk
#define  I2C_SMB_ICR_CLR_ARP_PRE_Pos              (4)
#define  I2C_SMB_ICR_CLR_ARP_PRE_Msk              (0x1U << I2C_SMB_ICR_CLR_ARP_PRE_Pos)             /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_ARP_PRE                  I2C_SMB_ICR_CLR_ARP_PRE_Msk
#define  I2C_SMB_ICR_CLR_ARP_RST_Pos              (5)
#define  I2C_SMB_ICR_CLR_ARP_RST_Msk              (0x1U << I2C_SMB_ICR_CLR_ARP_RST_Pos)             /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_ARP_RST                  I2C_SMB_ICR_CLR_ARP_RST_Msk
#define  I2C_SMB_ICR_CLR_ARP_UDID_Pos             (6)
#define  I2C_SMB_ICR_CLR_ARP_UDID_Msk             (0x1U << I2C_SMB_ICR_CLR_ARP_UDID_Pos)            /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_ARP_UDID                 I2C_SMB_ICR_CLR_ARP_UDID_Msk
#define  I2C_SMB_ICR_CLR_ARP_ASSGN_Pos            (7)
#define  I2C_SMB_ICR_CLR_ARP_ASSGN_Msk            (0x1U << I2C_SMB_ICR_CLR_ARP_ASSGN_Pos)           /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_ARP_ASSGN                I2C_SMB_ICR_CLR_ARP_ASSGN_Msk
#define  I2C_SMB_ICR_CLR_PEC_NACK_Pos             (8)
#define  I2C_SMB_ICR_CLR_PEC_NACK_Msk             (0x1U << I2C_SMB_ICR_CLR_PEC_NACK_Pos)            /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_PEC_NACK                 I2C_SMB_ICR_CLR_PEC_NACK_Msk
#define  I2C_SMB_ICR_CLR_SMB_ALT_Pos              (10)
#define  I2C_SMB_ICR_CLR_SMB_ALT_Msk              (0x1U << I2C_SMB_ICR_CLR_SMB_ALT_Pos)             /*!<Write this bit to clear the interrupt corresponding to I2C_SMB_RAWISR*/
#define  I2C_SMB_ICR_CLR_SMB_ALT                  I2C_SMB_ICR_CLR_SMB_ALT_Msk

/**
  * @brief I2C_OPT_SAR Register Bit Definition
  */
#define  I2C_OPT_SAR_ADDR_Pos                     (0)
#define  I2C_OPT_SAR_ADDR_Msk                     (0x7FU << I2C_OPT_SAR_ADDR_Pos)                   /*!<The slave address of the I2C interface when working in SMBus slave mode*/
#define  I2C_OPT_SAR_ADDR                         I2C_OPT_SAR_ADDR_Msk
#define  I2C_OPT_SAR_ADDR_Bit0                    (0x01U << I2C_OPT_SAR_ADDR_Pos) 
#define  I2C_OPT_SAR_ADDR_Bit1                    (0x02U << I2C_OPT_SAR_ADDR_Pos) 
#define  I2C_OPT_SAR_ADDR_Bit2                    (0x04U << I2C_OPT_SAR_ADDR_Pos) 
#define  I2C_OPT_SAR_ADDR_Bit3                    (0x08U << I2C_OPT_SAR_ADDR_Pos) 
#define  I2C_OPT_SAR_ADDR_Bit4                    (0x10U << I2C_OPT_SAR_ADDR_Pos) 
#define  I2C_OPT_SAR_ADDR_Bit5                    (0x20U << I2C_OPT_SAR_ADDR_Pos) 
#define  I2C_OPT_SAR_ADDR_Bit6                    (0x40U << I2C_OPT_SAR_ADDR_Pos) 

/**
  * @brief I2C_SMB_UDID_LSB Register Bit Definition
  */
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos        (0)
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Msk        (0xFFFFFFFFU << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) /*!<Configure SMBus UDID[31:0]*/
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB            I2C_SMB_UDID_LSB_SMB_UDID_LSB_Msk
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit0       (0x00000001U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit1       (0x00000002U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit2       (0x00000004U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit3       (0x00000008U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit4       (0x00000010U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit5       (0x00000020U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit6       (0x00000040U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit7       (0x00000080U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit8       (0x00000100U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit9       (0x00000200U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit10      (0x00000400U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit11      (0x00000800U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit12      (0x00001000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit13      (0x00002000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit14      (0x00004000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit15      (0x00008000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit16      (0x00010000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit17      (0x00020000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit18      (0x00040000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit19      (0x00080000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit20      (0x00100000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit21      (0x00200000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit22      (0x00400000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit23      (0x00800000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit24      (0x01000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit25      (0x02000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit26      (0x04000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit27      (0x08000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit28      (0x10000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit29      (0x20000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit30      (0x40000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 
#define  I2C_SMB_UDID_LSB_SMB_UDID_LSB_Bit31      (0x80000000U << I2C_SMB_UDID_LSB_SMB_UDID_LSB_Pos) 

/**
  * @brief I2C_SMB_UDID_MSB0 Register Bit Definition
  */
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos      (0)
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Msk      (0xFFFFFFFFU << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) /*!<Configure SMBus UDID[63:32]*/
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0          I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Msk
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit0     (0x00000001U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit1     (0x00000002U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit2     (0x00000004U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit3     (0x00000008U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit4     (0x00000010U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit5     (0x00000020U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit6     (0x00000040U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit7     (0x00000080U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit8     (0x00000100U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit9     (0x00000200U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit10    (0x00000400U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit11    (0x00000800U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit12    (0x00001000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit13    (0x00002000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit14    (0x00004000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit15    (0x00008000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit16    (0x00010000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit17    (0x00020000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit18    (0x00040000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit19    (0x00080000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit20    (0x00100000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit21    (0x00200000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit22    (0x00400000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit23    (0x00800000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit24    (0x01000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit25    (0x02000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit26    (0x04000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit27    (0x08000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit28    (0x10000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit29    (0x20000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit30    (0x40000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 
#define  I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Bit31    (0x80000000U << I2C_SMB_UDID_MSB0_SMB_UDID_MSB0_Pos) 

/**
  * @brief I2C_SMB_UDID_MSB1 Register Bit Definition
  */
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos      (0)
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Msk      (0xFFFFFFFFU << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) /*!<Configure SMBus UDID[95:64]*/
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1          I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Msk
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit0     (0x00000001U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit1     (0x00000002U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit2     (0x00000004U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit3     (0x00000008U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit4     (0x00000010U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit5     (0x00000020U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit6     (0x00000040U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit7     (0x00000080U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit8     (0x00000100U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit9     (0x00000200U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit10    (0x00000400U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit11    (0x00000800U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit12    (0x00001000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit13    (0x00002000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit14    (0x00004000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit15    (0x00008000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit16    (0x00010000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit17    (0x00020000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit18    (0x00040000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit19    (0x00080000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit20    (0x00100000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit21    (0x00200000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit22    (0x00400000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit23    (0x00800000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit24    (0x01000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit25    (0x02000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit26    (0x04000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit27    (0x08000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit28    (0x10000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit29    (0x20000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit30    (0x40000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 
#define  I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Bit31    (0x80000000U << I2C_SMB_UDID_MSB1_SMB_UDID_MSB1_Pos) 

/**
  * @brief I2C_SMB_UDID_MSB2 Register Bit Definition
  */
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos      (0)
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Msk      (0xFFFFFFFFU << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) /*!<Configure SMBus UDID[127:96]*/
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2          I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Msk
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit0     (0x00000001U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit1     (0x00000002U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit2     (0x00000004U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit3     (0x00000008U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit4     (0x00000010U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit5     (0x00000020U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit6     (0x00000040U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit7     (0x00000080U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit8     (0x00000100U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit9     (0x00000200U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit10    (0x00000400U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit11    (0x00000800U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit12    (0x00001000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit13    (0x00002000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit14    (0x00004000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit15    (0x00008000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit16    (0x00010000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit17    (0x00020000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit18    (0x00040000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit19    (0x00080000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit20    (0x00100000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit21    (0x00200000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit22    (0x00400000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit23    (0x00800000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit24    (0x01000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit25    (0x02000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit26    (0x04000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit27    (0x08000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit28    (0x10000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit29    (0x20000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit30    (0x40000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 
#define  I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Bit31    (0x80000000U << I2C_SMB_UDID_MSB2_SMB_UDID_MSB2_Pos) 

/**
  * @brief I2C_SLVMASK Register Bit Definition
  */
#define  I2C_SLVMASK_MASK_Pos                     (0)
#define  I2C_SLVMASK_MASK_Msk                     (0x3FFU << I2C_SLVMASK_MASK_Pos)                  /*!<Slave address mask*/
#define  I2C_SLVMASK_MASK                         I2C_SLVMASK_MASK_Msk
#define  I2C_SLVMASK_MASK_Bit0                    (0x001U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit1                    (0x002U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit2                    (0x004U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit3                    (0x008U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit4                    (0x010U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit5                    (0x020U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit6                    (0x040U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit7                    (0x080U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit8                    (0x100U << I2C_SLVMASK_MASK_Pos) 
#define  I2C_SLVMASK_MASK_Bit9                    (0x200U << I2C_SLVMASK_MASK_Pos) 

/**
  * @brief I2C_SLVRCVADDR Register Bit Definition
  */
#define  I2C_SLVRCVADDR_ADDR_Pos                  (0)
#define  I2C_SLVRCVADDR_ADDR_Msk                  (0x3FFU << I2C_SLVRCVADDR_ADDR_Pos)               /*!<Slave address actually received by I2C*/
#define  I2C_SLVRCVADDR_ADDR                      I2C_SLVRCVADDR_ADDR_Msk
#define  I2C_SLVRCVADDR_ADDR_Bit0                 (0x001U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit1                 (0x002U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit2                 (0x004U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit3                 (0x008U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit4                 (0x010U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit5                 (0x020U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit6                 (0x040U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit7                 (0x080U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit8                 (0x100U << I2C_SLVRCVADDR_ADDR_Pos) 
#define  I2C_SLVRCVADDR_ADDR_Bit9                 (0x200U << I2C_SLVRCVADDR_ADDR_Pos) 


#endif

