/***********************************************************************************************************************
    @file     reg_dac.h
    @author   VV TEAM
    @brief    This flie contains all the DAC's register and its field definition.
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

#ifndef __REG_DAC_H
#define __REG_DAC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief DAC Base Address Definition
  */
#define  DAC_BASE                                  0x40007400                                       /*!<Base Address: 0x40007400*/

/**
  * @brief DAC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<DAC DAC control register                       offset: 0x00       */
    __IO uint32_t SWTRIGR;                        /*!<DAC DAC software trigger register              offset: 0x04       */
    __IO uint32_t DHR12R1;                        /*!<DAC DAC channel 1 12-bit right-aligned data    offset: 0x08
                                                      holding register                                                  */
    __IO uint32_t DHR12L1;                        /*!<DAC DAC channel 1 12-bit left-aligned data     offset: 0x0C
                                                      holding register                                                  */
    __IO uint32_t DHR8R1;                         /*!<DAC DAC channel 1 8-bit right-aligned data     offset: 0x10
                                                      holding register                                                  */
    __IO uint32_t DHR12R2;                        /*!<DAC DAC channel 2 12-bit right-aligned data    offset: 0x14
                                                      holding register                                                  */
    __IO uint32_t DHR12L2;                        /*!<DAC DAC channel 2 12-bit left-aligned data     offset: 0x18
                                                      holding register                                                  */
    __IO uint32_t DHR8R2;                         /*!<DAC DAC channel 2 8-bit right-aligned data     offset: 0x1C
                                                      holding register                                                  */
    __IO uint32_t DHR12RD;                        /*!<DAC Dual DAC 12-bit right-aligned data         offset: 0x20
                                                      holding register                                                  */
    __IO uint32_t DHR12LD;                        /*!<DAC Dual DAC 12-bit left-aligned data holding  offset: 0x24
                                                      register                                                          */
    __IO uint32_t DHR8RD;                         /*!<DAC Dual DAC 8-bit right-aligned data holding  offset: 0x28
                                                      register                                                          */
    __IO uint32_t DOR1;                           /*!<DAC DAC channel 1 data output register         offset: 0x2C       */
    __IO uint32_t DOR2;                           /*!<DAC DAC channel 2 data output register         offset: 0x30       */
} DAC_TypeDef;

/**
  * @brief DAC type pointer Definition
  */
#define DAC                                       ((DAC_TypeDef *)DAC_BASE)

/**
  * @brief DAC_CR Register Bit Definition
  */
#define  DAC_CR_EN1_Pos                           (0)
#define  DAC_CR_EN1_Msk                           (0x1U << DAC_CR_EN1_Pos)                          /*!<DAC Channel 1 Enable*/
#define  DAC_CR_EN1                               DAC_CR_EN1_Msk
#define  DAC_CR_BOFF1_Pos                         (1)
#define  DAC_CR_BOFF1_Msk                         (0x1U << DAC_CR_BOFF1_Pos)                        /*!<DAC Channel 1 Output Buffer Disable*/
#define  DAC_CR_BOFF1                             DAC_CR_BOFF1_Msk
#define  DAC_CR_TEN1_Pos                          (2)
#define  DAC_CR_TEN1_Msk                          (0x1U << DAC_CR_TEN1_Pos)                         /*!<DAC Channel 1 Trigger Enable*/
#define  DAC_CR_TEN1                              DAC_CR_TEN1_Msk
#define  DAC_CR_WAVE1_Pos                         (6)
#define  DAC_CR_WAVE1_Msk                         (0x3U << DAC_CR_WAVE1_Pos)                        /*!<DAC Channel 1 Noise/Triangle Wave Generation Enable*/
#define  DAC_CR_WAVE1                             DAC_CR_WAVE1_Msk
#define  DAC_CR_WAVE1_Bit0                        (0x1U << DAC_CR_WAVE1_Pos) 
#define  DAC_CR_WAVE1_Bit1                        (0x2U << DAC_CR_WAVE1_Pos) 
#define  DAC_CR_MAMP1_Pos                         (8)
#define  DAC_CR_MAMP1_Msk                         (0xFU << DAC_CR_MAMP1_Pos)                        /*!<DAC Channel 1 Mask/Amplitude Selector*/
#define  DAC_CR_MAMP1                             DAC_CR_MAMP1_Msk
#define  DAC_CR_MAMP1_Bit0                        (0x1U << DAC_CR_MAMP1_Pos) 
#define  DAC_CR_MAMP1_Bit1                        (0x2U << DAC_CR_MAMP1_Pos) 
#define  DAC_CR_MAMP1_Bit2                        (0x4U << DAC_CR_MAMP1_Pos) 
#define  DAC_CR_MAMP1_Bit3                        (0x8U << DAC_CR_MAMP1_Pos) 
#define  DAC_CR_DMA_EN1_Pos                       (12)
#define  DAC_CR_DMA_EN1_Msk                       (0x1U << DAC_CR_DMA_EN1_Pos)                      /*!<DAC Channel 1 DMA Enable*/
#define  DAC_CR_DMA_EN1                           DAC_CR_DMA_EN1_Msk
#define  DAC_CR_OE_EN1_Pos                        (13)
#define  DAC_CR_OE_EN1_Msk                        (0x1U << DAC_CR_OE_EN1_Pos)                       /*!<DAC channel 1 output enable*/
#define  DAC_CR_OE_EN1                            DAC_CR_OE_EN1_Msk
#define  DAC_CR_EN2_Pos                           (16)
#define  DAC_CR_EN2_Msk                           (0x1U << DAC_CR_EN2_Pos)                          /*!<DAC Channel 2 Enable*/
#define  DAC_CR_EN2                               DAC_CR_EN2_Msk
#define  DAC_CR_BOFF2_Pos                         (17)
#define  DAC_CR_BOFF2_Msk                         (0x1U << DAC_CR_BOFF2_Pos)                        /*!<DAC Channel 2 Output Buffer Disable*/
#define  DAC_CR_BOFF2                             DAC_CR_BOFF2_Msk
#define  DAC_CR_TEN2_Pos                          (18)
#define  DAC_CR_TEN2_Msk                          (0x1U << DAC_CR_TEN2_Pos)                         /*!<DAC Channel 2 Trigger Enable*/
#define  DAC_CR_TEN2                              DAC_CR_TEN2_Msk
#define  DAC_CR_WAVE2_Pos                         (22)
#define  DAC_CR_WAVE2_Msk                         (0x3U << DAC_CR_WAVE2_Pos)                        /*!<DAC Channel 2 Noise/Triangle Wave Generation Enable*/
#define  DAC_CR_WAVE2                             DAC_CR_WAVE2_Msk
#define  DAC_CR_WAVE2_Bit0                        (0x1U << DAC_CR_WAVE2_Pos) 
#define  DAC_CR_WAVE2_Bit1                        (0x2U << DAC_CR_WAVE2_Pos) 
#define  DAC_CR_MAMP2_Pos                         (24)
#define  DAC_CR_MAMP2_Msk                         (0xFU << DAC_CR_MAMP2_Pos)                        /*!<DAC Channel 2 Mask/Amplitude Selector*/
#define  DAC_CR_MAMP2                             DAC_CR_MAMP2_Msk
#define  DAC_CR_MAMP2_Bit0                        (0x1U << DAC_CR_MAMP2_Pos) 
#define  DAC_CR_MAMP2_Bit1                        (0x2U << DAC_CR_MAMP2_Pos) 
#define  DAC_CR_MAMP2_Bit2                        (0x4U << DAC_CR_MAMP2_Pos) 
#define  DAC_CR_MAMP2_Bit3                        (0x8U << DAC_CR_MAMP2_Pos) 
#define  DAC_CR_DMA_EN2_Pos                       (28)
#define  DAC_CR_DMA_EN2_Msk                       (0x1U << DAC_CR_DMA_EN2_Pos)                      /*!<DAC Channel 2 DMA Enable*/
#define  DAC_CR_DMA_EN2                           DAC_CR_DMA_EN2_Msk
#define  DAC_CR_OE_EN2_Pos                        (29)
#define  DAC_CR_OE_EN2_Msk                        (0x1U << DAC_CR_OE_EN2_Pos)                       /*!<DAC channel 2 output enable*/
#define  DAC_CR_OE_EN2                            DAC_CR_OE_EN2_Msk

/**
  * @brief DAC_SWTRIGR Register Bit Definition
  */
#define  DAC_SWTRIGR_SW_TRIG1_Pos                 (0)
#define  DAC_SWTRIGR_SW_TRIG1_Msk                 (0x1U << DAC_SWTRIGR_SW_TRIG1_Pos)                /*!<DAC Channel 1 Software Trigger*/
#define  DAC_SWTRIGR_SW_TRIG1                     DAC_SWTRIGR_SW_TRIG1_Msk
#define  DAC_SWTRIGR_SW_TRIG2_Pos                 (1)
#define  DAC_SWTRIGR_SW_TRIG2_Msk                 (0x1U << DAC_SWTRIGR_SW_TRIG2_Pos)                /*!<DAC Channel 2 Software Trigger*/
#define  DAC_SWTRIGR_SW_TRIG2                     DAC_SWTRIGR_SW_TRIG2_Msk

/**
  * @brief DAC_DHR12R1 Register Bit Definition
  */
#define  DAC_DHR12R1_DACC1DHR_Pos                 (0)
#define  DAC_DHR12R1_DACC1DHR_Msk                 (0xFFFU << DAC_DHR12R1_DACC1DHR_Pos)              /*!<DAC Channel 1 12-bit Right Aligned Data*/
#define  DAC_DHR12R1_DACC1DHR                     DAC_DHR12R1_DACC1DHR_Msk
#define  DAC_DHR12R1_DACC1DHR_Bit0                (0x001U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit1                (0x002U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit2                (0x004U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit3                (0x008U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit4                (0x010U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit5                (0x020U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit6                (0x040U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit7                (0x080U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit8                (0x100U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit9                (0x200U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit10               (0x400U << DAC_DHR12R1_DACC1DHR_Pos) 
#define  DAC_DHR12R1_DACC1DHR_Bit11               (0x800U << DAC_DHR12R1_DACC1DHR_Pos) 

/**
  * @brief DAC_DHR12L1 Register Bit Definition
  */
#define  DAC_DHR12L1_DACC1DHR_Pos                 (4)
#define  DAC_DHR12L1_DACC1DHR_Msk                 (0xFFFU << DAC_DHR12L1_DACC1DHR_Pos)              /*!<DAC Channel 1 12-bit Left Aligned Data*/
#define  DAC_DHR12L1_DACC1DHR                     DAC_DHR12L1_DACC1DHR_Msk
#define  DAC_DHR12L1_DACC1DHR_Bit0                (0x001U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit1                (0x002U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit2                (0x004U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit3                (0x008U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit4                (0x010U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit5                (0x020U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit6                (0x040U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit7                (0x080U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit8                (0x100U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit9                (0x200U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit10               (0x400U << DAC_DHR12L1_DACC1DHR_Pos) 
#define  DAC_DHR12L1_DACC1DHR_Bit11               (0x800U << DAC_DHR12L1_DACC1DHR_Pos) 

/**
  * @brief DAC_DHR8R1 Register Bit Definition
  */
#define  DAC_DHR8R1_DACC1DHR_Pos                  (0)
#define  DAC_DHR8R1_DACC1DHR_Msk                  (0xFFU << DAC_DHR8R1_DACC1DHR_Pos)                /*!<DAC Channel 1 8-bit Right Aligned Data*/
#define  DAC_DHR8R1_DACC1DHR                      DAC_DHR8R1_DACC1DHR_Msk
#define  DAC_DHR8R1_DACC1DHR_Bit0                 (0x01U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit1                 (0x02U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit2                 (0x04U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit3                 (0x08U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit4                 (0x10U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit5                 (0x20U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit6                 (0x40U << DAC_DHR8R1_DACC1DHR_Pos) 
#define  DAC_DHR8R1_DACC1DHR_Bit7                 (0x80U << DAC_DHR8R1_DACC1DHR_Pos) 

/**
  * @brief DAC_DHR12R2 Register Bit Definition
  */
#define  DAC_DHR12R2_DACC2DHR_Pos                 (0)
#define  DAC_DHR12R2_DACC2DHR_Msk                 (0xFFFU << DAC_DHR12R2_DACC2DHR_Pos)              /*!<DAC Channel 2 12-bit Right Aligned Data*/
#define  DAC_DHR12R2_DACC2DHR                     DAC_DHR12R2_DACC2DHR_Msk
#define  DAC_DHR12R2_DACC2DHR_Bit0                (0x001U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit1                (0x002U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit2                (0x004U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit3                (0x008U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit4                (0x010U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit5                (0x020U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit6                (0x040U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit7                (0x080U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit8                (0x100U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit9                (0x200U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit10               (0x400U << DAC_DHR12R2_DACC2DHR_Pos) 
#define  DAC_DHR12R2_DACC2DHR_Bit11               (0x800U << DAC_DHR12R2_DACC2DHR_Pos) 

/**
  * @brief DAC_DHR12L2 Register Bit Definition
  */
#define  DAC_DHR12L2_DACC2DHR_Pos                 (4)
#define  DAC_DHR12L2_DACC2DHR_Msk                 (0xFFFU << DAC_DHR12L2_DACC2DHR_Pos)              /*!<DAC Channel 2 12-bit Left Aligned Data*/
#define  DAC_DHR12L2_DACC2DHR                     DAC_DHR12L2_DACC2DHR_Msk
#define  DAC_DHR12L2_DACC2DHR_Bit0                (0x001U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit1                (0x002U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit2                (0x004U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit3                (0x008U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit4                (0x010U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit5                (0x020U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit6                (0x040U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit7                (0x080U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit8                (0x100U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit9                (0x200U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit10               (0x400U << DAC_DHR12L2_DACC2DHR_Pos) 
#define  DAC_DHR12L2_DACC2DHR_Bit11               (0x800U << DAC_DHR12L2_DACC2DHR_Pos) 

/**
  * @brief DAC_DHR8R2 Register Bit Definition
  */
#define  DAC_DHR8R2_DACC2DHR_Pos                  (0)
#define  DAC_DHR8R2_DACC2DHR_Msk                  (0xFFU << DAC_DHR8R2_DACC2DHR_Pos)                /*!<DAC Channel 2 8-bit Right Aligned Data*/
#define  DAC_DHR8R2_DACC2DHR                      DAC_DHR8R2_DACC2DHR_Msk
#define  DAC_DHR8R2_DACC2DHR_Bit0                 (0x01U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit1                 (0x02U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit2                 (0x04U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit3                 (0x08U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit4                 (0x10U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit5                 (0x20U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit6                 (0x40U << DAC_DHR8R2_DACC2DHR_Pos) 
#define  DAC_DHR8R2_DACC2DHR_Bit7                 (0x80U << DAC_DHR8R2_DACC2DHR_Pos) 

/**
  * @brief DAC_DHR12RD Register Bit Definition
  */
#define  DAC_DHR12RD_DACC1DHR_Pos                 (0)
#define  DAC_DHR12RD_DACC1DHR_Msk                 (0xFFFU << DAC_DHR12RD_DACC1DHR_Pos)              /*!<DAC Channel 1 12-bit Right Aligned Data*/
#define  DAC_DHR12RD_DACC1DHR                     DAC_DHR12RD_DACC1DHR_Msk
#define  DAC_DHR12RD_DACC1DHR_Bit0                (0x001U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit1                (0x002U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit2                (0x004U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit3                (0x008U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit4                (0x010U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit5                (0x020U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit6                (0x040U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit7                (0x080U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit8                (0x100U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit9                (0x200U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit10               (0x400U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC1DHR_Bit11               (0x800U << DAC_DHR12RD_DACC1DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Pos                 (16)
#define  DAC_DHR12RD_DACC2DHR_Msk                 (0xFFFU << DAC_DHR12RD_DACC2DHR_Pos)              /*!<DAC Channel 2 12-bit Right Aligned Data*/
#define  DAC_DHR12RD_DACC2DHR                     DAC_DHR12RD_DACC2DHR_Msk
#define  DAC_DHR12RD_DACC2DHR_Bit0                (0x001U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit1                (0x002U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit2                (0x004U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit3                (0x008U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit4                (0x010U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit5                (0x020U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit6                (0x040U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit7                (0x080U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit8                (0x100U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit9                (0x200U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit10               (0x400U << DAC_DHR12RD_DACC2DHR_Pos) 
#define  DAC_DHR12RD_DACC2DHR_Bit11               (0x800U << DAC_DHR12RD_DACC2DHR_Pos) 

/**
  * @brief DAC_DHR12LD Register Bit Definition
  */
#define  DAC_DHR12LD_DACC1DHR_Pos                 (4)
#define  DAC_DHR12LD_DACC1DHR_Msk                 (0xFFFU << DAC_DHR12LD_DACC1DHR_Pos)              /*!<These bits are written by software which specifies 12-bit data for DAC channel 1.*/
#define  DAC_DHR12LD_DACC1DHR                     DAC_DHR12LD_DACC1DHR_Msk
#define  DAC_DHR12LD_DACC1DHR_Bit0                (0x001U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit1                (0x002U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit2                (0x004U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit3                (0x008U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit4                (0x010U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit5                (0x020U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit6                (0x040U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit7                (0x080U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit8                (0x100U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit9                (0x200U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit10               (0x400U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC1DHR_Bit11               (0x800U << DAC_DHR12LD_DACC1DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Pos                 (20)
#define  DAC_DHR12LD_DACC2DHR_Msk                 (0xFFFU << DAC_DHR12LD_DACC2DHR_Pos)              /*!<DAC Channel 2 12-bit Left Aligned Data*/
#define  DAC_DHR12LD_DACC2DHR                     DAC_DHR12LD_DACC2DHR_Msk
#define  DAC_DHR12LD_DACC2DHR_Bit0                (0x001U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit1                (0x002U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit2                (0x004U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit3                (0x008U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit4                (0x010U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit5                (0x020U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit6                (0x040U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit7                (0x080U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit8                (0x100U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit9                (0x200U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit10               (0x400U << DAC_DHR12LD_DACC2DHR_Pos) 
#define  DAC_DHR12LD_DACC2DHR_Bit11               (0x800U << DAC_DHR12LD_DACC2DHR_Pos) 

/**
  * @brief DAC_DHR8RD Register Bit Definition
  */
#define  DAC_DHR8RD_DACC1DHR_Pos                  (0)
#define  DAC_DHR8RD_DACC1DHR_Msk                  (0xFFU << DAC_DHR8RD_DACC1DHR_Pos)                /*!<DAC Channel 1 8-bit Right Aligned Data*/
#define  DAC_DHR8RD_DACC1DHR                      DAC_DHR8RD_DACC1DHR_Msk
#define  DAC_DHR8RD_DACC1DHR_Bit0                 (0x01U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit1                 (0x02U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit2                 (0x04U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit3                 (0x08U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit4                 (0x10U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit5                 (0x20U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit6                 (0x40U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC1DHR_Bit7                 (0x80U << DAC_DHR8RD_DACC1DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Pos                  (8)
#define  DAC_DHR8RD_DACC2DHR_Msk                  (0xFFU << DAC_DHR8RD_DACC2DHR_Pos)                /*!<DAC Channel 2 8-bit Right Aligned Data*/
#define  DAC_DHR8RD_DACC2DHR                      DAC_DHR8RD_DACC2DHR_Msk
#define  DAC_DHR8RD_DACC2DHR_Bit0                 (0x01U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit1                 (0x02U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit2                 (0x04U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit3                 (0x08U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit4                 (0x10U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit5                 (0x20U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit6                 (0x40U << DAC_DHR8RD_DACC2DHR_Pos) 
#define  DAC_DHR8RD_DACC2DHR_Bit7                 (0x80U << DAC_DHR8RD_DACC2DHR_Pos) 

/**
  * @brief DAC_DOR1 Register Bit Definition
  */
#define  DAC_DOR1_DACC1DOR_Pos                    (0)
#define  DAC_DOR1_DACC1DOR_Msk                    (0xFFFU << DAC_DOR1_DACC1DOR_Pos)                 /*!<DAC Channel 1 Data Output*/
#define  DAC_DOR1_DACC1DOR                        DAC_DOR1_DACC1DOR_Msk
#define  DAC_DOR1_DACC1DOR_Bit0                   (0x001U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit1                   (0x002U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit2                   (0x004U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit3                   (0x008U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit4                   (0x010U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit5                   (0x020U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit6                   (0x040U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit7                   (0x080U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit8                   (0x100U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit9                   (0x200U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit10                  (0x400U << DAC_DOR1_DACC1DOR_Pos) 
#define  DAC_DOR1_DACC1DOR_Bit11                  (0x800U << DAC_DOR1_DACC1DOR_Pos) 

/**
  * @brief DAC_DOR2 Register Bit Definition
  */
#define  DAC_DOR2_DACC2DOR_Pos                    (0)
#define  DAC_DOR2_DACC2DOR_Msk                    (0xFFFU << DAC_DOR2_DACC2DOR_Pos)                 /*!<DAC Channel 2 Data Output*/
#define  DAC_DOR2_DACC2DOR                        DAC_DOR2_DACC2DOR_Msk
#define  DAC_DOR2_DACC2DOR_Bit0                   (0x001U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit1                   (0x002U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit2                   (0x004U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit3                   (0x008U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit4                   (0x010U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit5                   (0x020U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit6                   (0x040U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit7                   (0x080U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit8                   (0x100U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit9                   (0x200U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit10                  (0x400U << DAC_DOR2_DACC2DOR_Pos) 
#define  DAC_DOR2_DACC2DOR_Bit11                  (0x800U << DAC_DOR2_DACC2DOR_Pos) 


#endif

