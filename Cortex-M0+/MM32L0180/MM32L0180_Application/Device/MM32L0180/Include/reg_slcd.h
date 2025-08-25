/***********************************************************************************************************************
    @file     reg_slcd.h
    @author   VV TEAM
    @brief    This flie contains all the SLCD's register and its field definition.
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

#ifndef __REG_SLCD_H
#define __REG_SLCD_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief SLCD Base Address Definition
  */
#define  SLCD_BASE                                 0x40009400                                       /*!<Base Address: 0x40009400*/

/**
  * @brief SLCD Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR;                             /*!<SLCD Control register                          offset: 0x00       */
    __IO uint32_t FCR;                            /*!<SLCD Frame control register                    offset: 0x04       */
    __IO uint32_t SR;                             /*!<SLCD Status register                           offset: 0x08       */
    __IO uint32_t CLRR;                           /*!<SLCD Status clear register                     offset: 0x0C       */
    __IO uint32_t BLKR0;                          /*!<SLCD Blinking control register 0               offset: 0x10       */
    __IO uint32_t BLKR1;                          /*!<SLCD Blinking control register 1               offset: 0x14       */
    __IO uint32_t BLKR2;                          /*!<SLCD Blinking control register 2               offset: 0x18       */
    __IO uint32_t BLKR3;                          /*!<SLCD Blinking control register 3               offset: 0x1C       */
    __IO uint32_t IOENR0;                         /*!<SLCD IO enable register 0                      offset: 0x20       */
    __IO uint32_t IOENR1;                         /*!<SLCD IO enable register 1                      offset: 0x24       */
    __IO uint32_t RESERVED0x28[2];                /*!<                                               offset: 0x28~0x2C  */
    __IO uint32_t CFGR0;                          /*!<SLCD COM/SEG configuration register 0          offset: 0x30       */
    __IO uint32_t CFGR1;                          /*!<SLCD COM/SEG configuration register 1          offset: 0x34       */
    __IO uint32_t IDXR0;                          /*!<SLCD COM index register 0                      offset: 0x38       */
    __IO uint32_t IDXR1;                          /*!<SLCD COM index register 1                      offset: 0x3C       */
    __IO uint32_t DR[16];                         /*!<SLCD Display data register                    offset: 0x40       */
} SLCD_TypeDef;

/**
  * @brief SLCD type pointer Definition
  */
#define SLCD                                      ((SLCD_TypeDef *)SLCD_BASE)

/**
  * @brief SLCD_CR Register Bit Definition
  */
#define  SLCD_CR_SLCDEN_Pos                       (0)
#define  SLCD_CR_SLCDEN_Msk                       (0x1U << SLCD_CR_SLCDEN_Pos)                      /*!<SLCD module enable*/
#define  SLCD_CR_SLCDEN                           SLCD_CR_SLCDEN_Msk
#define  SLCD_CR_LPEN_Pos                         (1)
#define  SLCD_CR_LPEN_Msk                         (0x1U << SLCD_CR_LPEN_Pos)                        /*!<Low power drive waveform enable*/
#define  SLCD_CR_LPEN                             SLCD_CR_LPEN_Msk
#define  SLCD_CR_DUTY_Pos                         (2)
#define  SLCD_CR_DUTY_Msk                         (0x7U << SLCD_CR_DUTY_Pos)                        /*!<Duty cycle mode selection*/
#define  SLCD_CR_DUTY                             SLCD_CR_DUTY_Msk
#define  SLCD_CR_DUTY_0                           (0x1U << SLCD_CR_DUTY_Pos) 
#define  SLCD_CR_DUTY_1                           (0x2U << SLCD_CR_DUTY_Pos) 
#define  SLCD_CR_DUTY_2                           (0x4U << SLCD_CR_DUTY_Pos) 
#define  SLCD_CR_BIAS_Pos                         (5)
#define  SLCD_CR_BIAS_Msk                         (0x3U << SLCD_CR_BIAS_Pos)                        /*!<Bias mode selection*/
#define  SLCD_CR_BIAS                             SLCD_CR_BIAS_Msk
#define  SLCD_CR_BIAS_0                           (0x1U << SLCD_CR_BIAS_Pos) 
#define  SLCD_CR_BIAS_1                           (0x2U << SLCD_CR_BIAS_Pos) 
#define  SLCD_CR_CPMODE_Pos                       (7)
#define  SLCD_CR_CPMODE_Msk                       (0x3U << SLCD_CR_CPMODE_Pos)                      /*!<Charge pump mode selection*/
#define  SLCD_CR_CPMODE                           SLCD_CR_CPMODE_Msk
#define  SLCD_CR_CPMODE_0                         (0x1U << SLCD_CR_CPMODE_Pos) 
#define  SLCD_CR_CPMODE_1                         (0x2U << SLCD_CR_CPMODE_Pos) 
#define  SLCD_CR_REFEN_Pos                        (9)
#define  SLCD_CR_REFEN_Msk                        (0x1U << SLCD_CR_REFEN_Pos)                       /*!<Internal voltage reference enable*/
#define  SLCD_CR_REFEN                            SLCD_CR_REFEN_Msk
#define  SLCD_CR_VDDEN_Pos                        (10)
#define  SLCD_CR_VDDEN_Msk                        (0x1U << SLCD_CR_VDDEN_Pos)                       /*!<Internal VDD as SLCD power enable*/
#define  SLCD_CR_VDDEN                            SLCD_CR_VDDEN_Msk
#define  SLCD_CR_INTR_Pos                         (11)
#define  SLCD_CR_INTR_Msk                         (0x1U << SLCD_CR_INTR_Pos)                        /*!<Internal resistor divider mode is enabled*/
#define  SLCD_CR_INTR                             SLCD_CR_INTR_Msk
#define  SLCD_CR_INTLP_Pos                        (12)
#define  SLCD_CR_INTLP_Msk                        (0x1U << SLCD_CR_INTLP_Pos)                       /*!<Internal resistor divider power consumption mode*/
#define  SLCD_CR_INTLP                            SLCD_CR_INTLP_Msk

/**
  * @brief SLCD_FCR Register Bit Definition
  */
#define  SLCD_FCR_SLCDIE_Pos                      (0)
#define  SLCD_FCR_SLCDIE_Msk                      (0x1U << SLCD_FCR_SLCDIE_Pos)                     /*!<LCD module interrupt enable*/
#define  SLCD_FCR_SLCDIE                          SLCD_FCR_SLCDIE_Msk
#define  SLCD_FCR_EOFIE_Pos                       (1)
#define  SLCD_FCR_EOFIE_Msk                       (0x1U << SLCD_FCR_EOFIE_Pos)                      /*!<End of frame interrupt enable*/
#define  SLCD_FCR_EOFIE                           SLCD_FCR_EOFIE_Msk
#define  SLCD_FCR_BLKIE_Pos                       (2)
#define  SLCD_FCR_BLKIE_Msk                       (0x1U << SLCD_FCR_BLKIE_Pos)                      /*!<Blinking interrupt enable*/
#define  SLCD_FCR_BLKIE                           SLCD_FCR_BLKIE_Msk
#define  SLCD_FCR_SOFF_Pos                        (3)
#define  SLCD_FCR_SOFF_Msk                        (0x1U << SLCD_FCR_SOFF_Pos)                       /*!<Close all SEGs*/
#define  SLCD_FCR_SOFF                            SLCD_FCR_SOFF_Msk
#define  SLCD_FCR_CC_Pos                          (4)
#define  SLCD_FCR_CC_Msk                          (0xFU << SLCD_FCR_CC_Pos)                         /*!<Contrast control*/
#define  SLCD_FCR_CC                              SLCD_FCR_CC_Msk
#define  SLCD_FCR_CC_0                            (0x1U << SLCD_FCR_CC_Pos) 
#define  SLCD_FCR_CC_1                            (0x2U << SLCD_FCR_CC_Pos) 
#define  SLCD_FCR_CC_2                            (0x4U << SLCD_FCR_CC_Pos) 
#define  SLCD_FCR_CC_3                            (0x8U << SLCD_FCR_CC_Pos) 
#define  SLCD_FCR_DEAD_Pos                        (8)
#define  SLCD_FCR_DEAD_Msk                        (0x7U << SLCD_FCR_DEAD_Pos)                       /*!<Dead insertion*/
#define  SLCD_FCR_DEAD                            SLCD_FCR_DEAD_Msk
#define  SLCD_FCR_DEAD_0                          (0x1U << SLCD_FCR_DEAD_Pos) 
#define  SLCD_FCR_DEAD_1                          (0x2U << SLCD_FCR_DEAD_Pos) 
#define  SLCD_FCR_DEAD_2                          (0x4U << SLCD_FCR_DEAD_Pos) 
#define  SLCD_FCR_BLINK_Pos                       (11)
#define  SLCD_FCR_BLINK_Msk                       (0x3U << SLCD_FCR_BLINK_Pos)                      /*!<Blinking mode selection*/
#define  SLCD_FCR_BLINK                           SLCD_FCR_BLINK_Msk
#define  SLCD_FCR_BLINK_0                         (0x1U << SLCD_FCR_BLINK_Pos) 
#define  SLCD_FCR_BLINK_1                         (0x2U << SLCD_FCR_BLINK_Pos) 
#define  SLCD_FCR_BLINKF_Pos                      (13)
#define  SLCD_FCR_BLINKF_Msk                      (0x7U << SLCD_FCR_BLINKF_Pos)                     /*!<Blinking division*/
#define  SLCD_FCR_BLINKF                          SLCD_FCR_BLINKF_Msk
#define  SLCD_FCR_BLINKF_0                        (0x1U << SLCD_FCR_BLINKF_Pos) 
#define  SLCD_FCR_BLINKF_1                        (0x2U << SLCD_FCR_BLINKF_Pos) 
#define  SLCD_FCR_BLINKF_2                        (0x4U << SLCD_FCR_BLINKF_Pos) 
#define  SLCD_FCR_DIV_Pos                         (16)
#define  SLCD_FCR_DIV_Msk                         (0xFU << SLCD_FCR_DIV_Pos)                        /*!<SLCD clock division*/
#define  SLCD_FCR_DIV                             SLCD_FCR_DIV_Msk
#define  SLCD_FCR_DIV_0                           (0x1U << SLCD_FCR_DIV_Pos) 
#define  SLCD_FCR_DIV_1                           (0x2U << SLCD_FCR_DIV_Pos) 
#define  SLCD_FCR_DIV_2                           (0x4U << SLCD_FCR_DIV_Pos) 
#define  SLCD_FCR_DIV_3                           (0x8U << SLCD_FCR_DIV_Pos) 
#define  SLCD_FCR_PS_Pos                          (20)
#define  SLCD_FCR_PS_Msk                          (0xFU << SLCD_FCR_PS_Pos)                         /*!<SLCD clock prescaler*/
#define  SLCD_FCR_PS                              SLCD_FCR_PS_Msk
#define  SLCD_FCR_PS_0                            (0x1U << SLCD_FCR_PS_Pos) 
#define  SLCD_FCR_PS_1                            (0x2U << SLCD_FCR_PS_Pos) 
#define  SLCD_FCR_PS_2                            (0x4U << SLCD_FCR_PS_Pos) 
#define  SLCD_FCR_PS_3                            (0x8U << SLCD_FCR_PS_Pos) 
#define  SLCD_FCR_CPDIV_Pos                       (24)
#define  SLCD_FCR_CPDIV_Msk                       (0x7U << SLCD_FCR_CPDIV_Pos)                      /*!<Charge pump clock division*/
#define  SLCD_FCR_CPDIV                           SLCD_FCR_CPDIV_Msk
#define  SLCD_FCR_CPDIV_0                         (0x1U << SLCD_FCR_CPDIV_Pos) 
#define  SLCD_FCR_CPDIV_1                         (0x2U << SLCD_FCR_CPDIV_Pos) 
#define  SLCD_FCR_CPDIV_2                         (0x4U << SLCD_FCR_CPDIV_Pos) 
#define  SLCD_FCR_DRLC_Pos                        (27)
#define  SLCD_FCR_DRLC_Msk                        (0x1U << SLCD_FCR_DRLC_Pos)                       /*!<SLCD_DR [7:0] data clear*/
#define  SLCD_FCR_DRLC                            SLCD_FCR_DRLC_Msk
#define  SLCD_FCR_DRHC_Pos                        (28)
#define  SLCD_FCR_DRHC_Msk                        (0x1U << SLCD_FCR_DRHC_Pos)                       /*!<SLCD_DR [15:8] data clear*/
#define  SLCD_FCR_DRHC                            SLCD_FCR_DRHC_Msk
#define  SLCD_FCR_DRSEL_Pos                       (29)
#define  SLCD_FCR_DRSEL_Msk                       (0x1U << SLCD_FCR_DRSEL_Pos)                      /*!<Display register selection*/
#define  SLCD_FCR_DRSEL                           SLCD_FCR_DRSEL_Msk
#define  SLCD_FCR_DMAEN_Pos                       (30)
#define  SLCD_FCR_DMAEN_Msk                       (0x1U << SLCD_FCR_DMAEN_Pos)                      /*!<DMA transfer enable*/
#define  SLCD_FCR_DMAEN                           SLCD_FCR_DMAEN_Msk

/**
  * @brief SLCD_SR Register Bit Definition
  */
#define  SLCD_SR_ENS_Pos                          (0)
#define  SLCD_SR_ENS_Msk                          (0x1U << SLCD_SR_ENS_Pos)                         /*!<SLCD enable flag*/
#define  SLCD_SR_ENS                              SLCD_SR_ENS_Msk
#define  SLCD_SR_EOF_Pos                          (1)
#define  SLCD_SR_EOF_Msk                          (0x1U << SLCD_SR_EOF_Pos)                         /*!<End of frame flag*/
#define  SLCD_SR_EOF                              SLCD_SR_EOF_Msk
#define  SLCD_SR_BLKF_Pos                         (2)
#define  SLCD_SR_BLKF_Msk                         (0x1U << SLCD_SR_BLKF_Pos)                        /*!<Blinking cycle flag*/
#define  SLCD_SR_BLKF                             SLCD_SR_BLKF_Msk
#define  SLCD_SR_DRSS_Pos                         (3)
#define  SLCD_SR_DRSS_Msk                         (0x1U << SLCD_SR_DRSS_Pos)                        /*!<Display data register indication*/
#define  SLCD_SR_DRSS                             SLCD_SR_DRSS_Msk
#define  SLCD_SR_FCRSF_Pos                        (5)
#define  SLCD_SR_FCRSF_Msk                        (0x1U << SLCD_SR_FCRSF_Pos)                       /*!<FCR register synchronization flag*/
#define  SLCD_SR_FCRSF                            SLCD_SR_FCRSF_Msk

/**
  * @brief SLCD_CLRR Register Bit Definition
  */
#define  SLCD_CLRR_EOFC_Pos                       (1)
#define  SLCD_CLRR_EOFC_Msk                       (0x1U << SLCD_CLRR_EOFC_Pos)                      /*!<Clear the end of frame flag*/
#define  SLCD_CLRR_EOFC                           SLCD_CLRR_EOFC_Msk
#define  SLCD_CLRR_BLKFC_Pos                      (2)
#define  SLCD_CLRR_BLKFC_Msk                      (0x1U << SLCD_CLRR_BLKFC_Pos)                     /*!<Clear the blinking cycle flag*/
#define  SLCD_CLRR_BLKFC                          SLCD_CLRR_BLKFC_Msk

/**
  * @brief SLCD_BLKR0 Register Bit Definition
  */
#define  SLCD_BLKR0_SEGIDX0_Pos                   (0)
#define  SLCD_BLKR0_SEGIDX0_Msk                   (0x3FU << SLCD_BLKR0_SEGIDX0_Pos)                 /*!<Blinking SEG0 index*/
#define  SLCD_BLKR0_SEGIDX0                       SLCD_BLKR0_SEGIDX0_Msk
#define  SLCD_BLKR0_SEGIDX0_0                     (0x01U << SLCD_BLKR0_SEGIDX0_Pos) 
#define  SLCD_BLKR0_SEGIDX0_1                     (0x02U << SLCD_BLKR0_SEGIDX0_Pos) 
#define  SLCD_BLKR0_SEGIDX0_2                     (0x04U << SLCD_BLKR0_SEGIDX0_Pos) 
#define  SLCD_BLKR0_SEGIDX0_3                     (0x08U << SLCD_BLKR0_SEGIDX0_Pos) 
#define  SLCD_BLKR0_SEGIDX0_4                     (0x10U << SLCD_BLKR0_SEGIDX0_Pos) 
#define  SLCD_BLKR0_SEGIDX0_5                     (0x20U << SLCD_BLKR0_SEGIDX0_Pos) 
#define  SLCD_BLKR0_COMIDX0_Pos                   (8)
#define  SLCD_BLKR0_COMIDX0_Msk                   (0x7U << SLCD_BLKR0_COMIDX0_Pos)                  /*!<Blinking COM0 index*/
#define  SLCD_BLKR0_COMIDX0                       SLCD_BLKR0_COMIDX0_Msk
#define  SLCD_BLKR0_COMIDX0_0                     (0x1U << SLCD_BLKR0_COMIDX0_Pos) 
#define  SLCD_BLKR0_COMIDX0_1                     (0x2U << SLCD_BLKR0_COMIDX0_Pos) 
#define  SLCD_BLKR0_COMIDX0_2                     (0x4U << SLCD_BLKR0_COMIDX0_Pos) 
#define  SLCD_BLKR0_IDXEN0_Pos                    (15)
#define  SLCD_BLKR0_IDXEN0_Msk                    (0x1U << SLCD_BLKR0_IDXEN0_Pos)                   /*!<Blinking index 0 enable*/
#define  SLCD_BLKR0_IDXEN0                        SLCD_BLKR0_IDXEN0_Msk
#define  SLCD_BLKR0_SEGIDX1_Pos                   (16)
#define  SLCD_BLKR0_SEGIDX1_Msk                   (0x3FU << SLCD_BLKR0_SEGIDX1_Pos)                 /*!<Blinking SEG1 index*/
#define  SLCD_BLKR0_SEGIDX1                       SLCD_BLKR0_SEGIDX1_Msk
#define  SLCD_BLKR0_SEGIDX1_0                     (0x01U << SLCD_BLKR0_SEGIDX1_Pos) 
#define  SLCD_BLKR0_SEGIDX1_1                     (0x02U << SLCD_BLKR0_SEGIDX1_Pos) 
#define  SLCD_BLKR0_SEGIDX1_2                     (0x04U << SLCD_BLKR0_SEGIDX1_Pos) 
#define  SLCD_BLKR0_SEGIDX1_3                     (0x08U << SLCD_BLKR0_SEGIDX1_Pos) 
#define  SLCD_BLKR0_SEGIDX1_4                     (0x10U << SLCD_BLKR0_SEGIDX1_Pos) 
#define  SLCD_BLKR0_SEGIDX1_5                     (0x20U << SLCD_BLKR0_SEGIDX1_Pos) 
#define  SLCD_BLKR0_COMIDX1_Pos                   (24)
#define  SLCD_BLKR0_COMIDX1_Msk                   (0x7U << SLCD_BLKR0_COMIDX1_Pos)                  /*!<Blinking COM1 index*/
#define  SLCD_BLKR0_COMIDX1                       SLCD_BLKR0_COMIDX1_Msk
#define  SLCD_BLKR0_COMIDX1_0                     (0x1U << SLCD_BLKR0_COMIDX1_Pos) 
#define  SLCD_BLKR0_COMIDX1_1                     (0x2U << SLCD_BLKR0_COMIDX1_Pos) 
#define  SLCD_BLKR0_COMIDX1_2                     (0x4U << SLCD_BLKR0_COMIDX1_Pos) 
#define  SLCD_BLKR0_IDXEN1_Pos                    (31)
#define  SLCD_BLKR0_IDXEN1_Msk                    (0x1U << SLCD_BLKR0_IDXEN1_Pos)                   /*!<Blinking index 1 enable*/
#define  SLCD_BLKR0_IDXEN1                        SLCD_BLKR0_IDXEN1_Msk

/**
  * @brief SLCD_BLKR1 Register Bit Definition
  */
#define  SLCD_BLKR1_SEGIDX2_Pos                   (0)
#define  SLCD_BLKR1_SEGIDX2_Msk                   (0x3FU << SLCD_BLKR1_SEGIDX2_Pos)                 /*!<Blinking SEG2 index*/
#define  SLCD_BLKR1_SEGIDX2                       SLCD_BLKR1_SEGIDX2_Msk
#define  SLCD_BLKR1_SEGIDX2_0                     (0x01U << SLCD_BLKR1_SEGIDX2_Pos) 
#define  SLCD_BLKR1_SEGIDX2_1                     (0x02U << SLCD_BLKR1_SEGIDX2_Pos) 
#define  SLCD_BLKR1_SEGIDX2_2                     (0x04U << SLCD_BLKR1_SEGIDX2_Pos) 
#define  SLCD_BLKR1_SEGIDX2_3                     (0x08U << SLCD_BLKR1_SEGIDX2_Pos) 
#define  SLCD_BLKR1_SEGIDX2_4                     (0x10U << SLCD_BLKR1_SEGIDX2_Pos) 
#define  SLCD_BLKR1_SEGIDX2_5                     (0x20U << SLCD_BLKR1_SEGIDX2_Pos) 
#define  SLCD_BLKR1_COMIDX2_Pos                   (8)
#define  SLCD_BLKR1_COMIDX2_Msk                   (0x7U << SLCD_BLKR1_COMIDX2_Pos)                  /*!<Blinking COM2 index*/
#define  SLCD_BLKR1_COMIDX2                       SLCD_BLKR1_COMIDX2_Msk
#define  SLCD_BLKR1_COMIDX2_0                     (0x1U << SLCD_BLKR1_COMIDX2_Pos) 
#define  SLCD_BLKR1_COMIDX2_1                     (0x2U << SLCD_BLKR1_COMIDX2_Pos) 
#define  SLCD_BLKR1_COMIDX2_2                     (0x4U << SLCD_BLKR1_COMIDX2_Pos) 
#define  SLCD_BLKR1_IDXEN2_Pos                    (15)
#define  SLCD_BLKR1_IDXEN2_Msk                    (0x1U << SLCD_BLKR1_IDXEN2_Pos)                   /*!<Blinking index 2 enable*/
#define  SLCD_BLKR1_IDXEN2                        SLCD_BLKR1_IDXEN2_Msk
#define  SLCD_BLKR1_SEGIDX3_Pos                   (16)
#define  SLCD_BLKR1_SEGIDX3_Msk                   (0x3FU << SLCD_BLKR1_SEGIDX3_Pos)                 /*!<Blinking SEG3 index*/
#define  SLCD_BLKR1_SEGIDX3                       SLCD_BLKR1_SEGIDX3_Msk
#define  SLCD_BLKR1_SEGIDX3_0                     (0x01U << SLCD_BLKR1_SEGIDX3_Pos) 
#define  SLCD_BLKR1_SEGIDX3_1                     (0x02U << SLCD_BLKR1_SEGIDX3_Pos) 
#define  SLCD_BLKR1_SEGIDX3_2                     (0x04U << SLCD_BLKR1_SEGIDX3_Pos) 
#define  SLCD_BLKR1_SEGIDX3_3                     (0x08U << SLCD_BLKR1_SEGIDX3_Pos) 
#define  SLCD_BLKR1_SEGIDX3_4                     (0x10U << SLCD_BLKR1_SEGIDX3_Pos) 
#define  SLCD_BLKR1_SEGIDX3_5                     (0x20U << SLCD_BLKR1_SEGIDX3_Pos) 
#define  SLCD_BLKR1_COMIDX3_Pos                   (24)
#define  SLCD_BLKR1_COMIDX3_Msk                   (0x7U << SLCD_BLKR1_COMIDX3_Pos)                  /*!<Blinking COM3 index*/
#define  SLCD_BLKR1_COMIDX3                       SLCD_BLKR1_COMIDX3_Msk
#define  SLCD_BLKR1_COMIDX3_0                     (0x1U << SLCD_BLKR1_COMIDX3_Pos) 
#define  SLCD_BLKR1_COMIDX3_1                     (0x2U << SLCD_BLKR1_COMIDX3_Pos) 
#define  SLCD_BLKR1_COMIDX3_2                     (0x4U << SLCD_BLKR1_COMIDX3_Pos) 
#define  SLCD_BLKR1_IDXEN3_Pos                    (31)
#define  SLCD_BLKR1_IDXEN3_Msk                    (0x1U << SLCD_BLKR1_IDXEN3_Pos)                   /*!<Blinking index 3 enable*/
#define  SLCD_BLKR1_IDXEN3                        SLCD_BLKR1_IDXEN3_Msk

/**
  * @brief SLCD_BLKR2 Register Bit Definition
  */
#define  SLCD_BLKR2_SEGIDX4_Pos                   (0)
#define  SLCD_BLKR2_SEGIDX4_Msk                   (0x3FU << SLCD_BLKR2_SEGIDX4_Pos)                 /*!<Blinking SEG4 index*/
#define  SLCD_BLKR2_SEGIDX4                       SLCD_BLKR2_SEGIDX4_Msk
#define  SLCD_BLKR2_SEGIDX4_0                     (0x01U << SLCD_BLKR2_SEGIDX4_Pos) 
#define  SLCD_BLKR2_SEGIDX4_1                     (0x02U << SLCD_BLKR2_SEGIDX4_Pos) 
#define  SLCD_BLKR2_SEGIDX4_2                     (0x04U << SLCD_BLKR2_SEGIDX4_Pos) 
#define  SLCD_BLKR2_SEGIDX4_3                     (0x08U << SLCD_BLKR2_SEGIDX4_Pos) 
#define  SLCD_BLKR2_SEGIDX4_4                     (0x10U << SLCD_BLKR2_SEGIDX4_Pos) 
#define  SLCD_BLKR2_SEGIDX4_5                     (0x20U << SLCD_BLKR2_SEGIDX4_Pos) 
#define  SLCD_BLKR2_COMIDX4_Pos                   (8)
#define  SLCD_BLKR2_COMIDX4_Msk                   (0x7U << SLCD_BLKR2_COMIDX4_Pos)                  /*!<Blinking COM4 index*/
#define  SLCD_BLKR2_COMIDX4                       SLCD_BLKR2_COMIDX4_Msk
#define  SLCD_BLKR2_COMIDX4_0                     (0x1U << SLCD_BLKR2_COMIDX4_Pos) 
#define  SLCD_BLKR2_COMIDX4_1                     (0x2U << SLCD_BLKR2_COMIDX4_Pos) 
#define  SLCD_BLKR2_COMIDX4_2                     (0x4U << SLCD_BLKR2_COMIDX4_Pos) 
#define  SLCD_BLKR2_IDXEN4_Pos                    (15)
#define  SLCD_BLKR2_IDXEN4_Msk                    (0x1U << SLCD_BLKR2_IDXEN4_Pos)                   /*!<Blinking index 4 enable*/
#define  SLCD_BLKR2_IDXEN4                        SLCD_BLKR2_IDXEN4_Msk
#define  SLCD_BLKR2_SEGIDX5_Pos                   (16)
#define  SLCD_BLKR2_SEGIDX5_Msk                   (0x3FU << SLCD_BLKR2_SEGIDX5_Pos)                 /*!<Blinking SEG5 index*/
#define  SLCD_BLKR2_SEGIDX5                       SLCD_BLKR2_SEGIDX5_Msk
#define  SLCD_BLKR2_SEGIDX5_0                     (0x01U << SLCD_BLKR2_SEGIDX5_Pos) 
#define  SLCD_BLKR2_SEGIDX5_1                     (0x02U << SLCD_BLKR2_SEGIDX5_Pos) 
#define  SLCD_BLKR2_SEGIDX5_2                     (0x04U << SLCD_BLKR2_SEGIDX5_Pos) 
#define  SLCD_BLKR2_SEGIDX5_3                     (0x08U << SLCD_BLKR2_SEGIDX5_Pos) 
#define  SLCD_BLKR2_SEGIDX5_4                     (0x10U << SLCD_BLKR2_SEGIDX5_Pos) 
#define  SLCD_BLKR2_SEGIDX5_5                     (0x20U << SLCD_BLKR2_SEGIDX5_Pos) 
#define  SLCD_BLKR2_COMIDX5_Pos                   (24)
#define  SLCD_BLKR2_COMIDX5_Msk                   (0x7U << SLCD_BLKR2_COMIDX5_Pos)                  /*!<Blinking COM5 index*/
#define  SLCD_BLKR2_COMIDX5                       SLCD_BLKR2_COMIDX5_Msk
#define  SLCD_BLKR2_COMIDX5_0                     (0x1U << SLCD_BLKR2_COMIDX5_Pos) 
#define  SLCD_BLKR2_COMIDX5_1                     (0x2U << SLCD_BLKR2_COMIDX5_Pos) 
#define  SLCD_BLKR2_COMIDX5_2                     (0x4U << SLCD_BLKR2_COMIDX5_Pos) 
#define  SLCD_BLKR2_IDXEN5_Pos                    (31)
#define  SLCD_BLKR2_IDXEN5_Msk                    (0x1U << SLCD_BLKR2_IDXEN5_Pos)                   /*!<Blinking index 5 enable*/
#define  SLCD_BLKR2_IDXEN5                        SLCD_BLKR2_IDXEN5_Msk

/**
  * @brief SLCD_BLKR3 Register Bit Definition
  */
#define  SLCD_BLKR3_SEGIDX6_Pos                   (0)
#define  SLCD_BLKR3_SEGIDX6_Msk                   (0x3FU << SLCD_BLKR3_SEGIDX6_Pos)                 /*!<Blinking SEG6 index*/
#define  SLCD_BLKR3_SEGIDX6                       SLCD_BLKR3_SEGIDX6_Msk
#define  SLCD_BLKR3_SEGIDX6_0                     (0x01U << SLCD_BLKR3_SEGIDX6_Pos) 
#define  SLCD_BLKR3_SEGIDX6_1                     (0x02U << SLCD_BLKR3_SEGIDX6_Pos) 
#define  SLCD_BLKR3_SEGIDX6_2                     (0x04U << SLCD_BLKR3_SEGIDX6_Pos) 
#define  SLCD_BLKR3_SEGIDX6_3                     (0x08U << SLCD_BLKR3_SEGIDX6_Pos) 
#define  SLCD_BLKR3_SEGIDX6_4                     (0x10U << SLCD_BLKR3_SEGIDX6_Pos) 
#define  SLCD_BLKR3_SEGIDX6_5                     (0x20U << SLCD_BLKR3_SEGIDX6_Pos) 
#define  SLCD_BLKR3_COMIDX6_Pos                   (8)
#define  SLCD_BLKR3_COMIDX6_Msk                   (0x7U << SLCD_BLKR3_COMIDX6_Pos)                  /*!<Blinking COM6 index*/
#define  SLCD_BLKR3_COMIDX6                       SLCD_BLKR3_COMIDX6_Msk
#define  SLCD_BLKR3_COMIDX6_0                     (0x1U << SLCD_BLKR3_COMIDX6_Pos) 
#define  SLCD_BLKR3_COMIDX6_1                     (0x2U << SLCD_BLKR3_COMIDX6_Pos) 
#define  SLCD_BLKR3_COMIDX6_2                     (0x4U << SLCD_BLKR3_COMIDX6_Pos) 
#define  SLCD_BLKR3_IDXEN6_Pos                    (15)
#define  SLCD_BLKR3_IDXEN6_Msk                    (0x1U << SLCD_BLKR3_IDXEN6_Pos)                   /*!<Blinking index 6 enable*/
#define  SLCD_BLKR3_IDXEN6                        SLCD_BLKR3_IDXEN6_Msk
#define  SLCD_BLKR3_SEGIDX7_Pos                   (16)
#define  SLCD_BLKR3_SEGIDX7_Msk                   (0x3FU << SLCD_BLKR3_SEGIDX7_Pos)                 /*!<Blinking SEG7 index*/
#define  SLCD_BLKR3_SEGIDX7                       SLCD_BLKR3_SEGIDX7_Msk
#define  SLCD_BLKR3_SEGIDX7_0                     (0x01U << SLCD_BLKR3_SEGIDX7_Pos) 
#define  SLCD_BLKR3_SEGIDX7_1                     (0x02U << SLCD_BLKR3_SEGIDX7_Pos) 
#define  SLCD_BLKR3_SEGIDX7_2                     (0x04U << SLCD_BLKR3_SEGIDX7_Pos) 
#define  SLCD_BLKR3_SEGIDX7_3                     (0x08U << SLCD_BLKR3_SEGIDX7_Pos) 
#define  SLCD_BLKR3_SEGIDX7_4                     (0x10U << SLCD_BLKR3_SEGIDX7_Pos) 
#define  SLCD_BLKR3_SEGIDX7_5                     (0x20U << SLCD_BLKR3_SEGIDX7_Pos) 
#define  SLCD_BLKR3_COMIDX7_Pos                   (24)
#define  SLCD_BLKR3_COMIDX7_Msk                   (0x7U << SLCD_BLKR3_COMIDX7_Pos)                  /*!<Blinking COM7 index*/
#define  SLCD_BLKR3_COMIDX7                       SLCD_BLKR3_COMIDX7_Msk
#define  SLCD_BLKR3_COMIDX7_0                     (0x1U << SLCD_BLKR3_COMIDX7_Pos) 
#define  SLCD_BLKR3_COMIDX7_1                     (0x2U << SLCD_BLKR3_COMIDX7_Pos) 
#define  SLCD_BLKR3_COMIDX7_2                     (0x4U << SLCD_BLKR3_COMIDX7_Pos) 
#define  SLCD_BLKR3_IDXEN7_Pos                    (31)
#define  SLCD_BLKR3_IDXEN7_Msk                    (0x1U << SLCD_BLKR3_IDXEN7_Pos)                   /*!<Blinking index 7 enable*/
#define  SLCD_BLKR3_IDXEN7                        SLCD_BLKR3_IDXEN7_Msk

/**
  * @brief SLCD_IOENR0 Register Bit Definition
  */
#define  SLCD_IOENR0_IOENR0_Pos                   (0)
#define  SLCD_IOENR0_IOENR0_Msk                   (0xFFFFFFFFU << SLCD_IOENR0_IOENR0_Pos)           /*!<IO enable control corresponding to the low 32 bit SLCD pin.*/
#define  SLCD_IOENR0_IOENR0                       SLCD_IOENR0_IOENR0_Msk
#define  SLCD_IOENR0_IOENR0_0                     (0x00000001U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_1                     (0x00000002U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_2                     (0x00000004U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_3                     (0x00000008U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_4                     (0x00000010U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_5                     (0x00000020U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_6                     (0x00000040U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_7                     (0x00000080U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_8                     (0x00000100U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_9                     (0x00000200U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_10                    (0x00000400U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_11                    (0x00000800U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_12                    (0x00001000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_13                    (0x00002000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_14                    (0x00004000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_15                    (0x00008000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_16                    (0x00010000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_17                    (0x00020000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_18                    (0x00040000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_19                    (0x00080000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_20                    (0x00100000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_21                    (0x00200000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_22                    (0x00400000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_23                    (0x00800000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_24                    (0x01000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_25                    (0x02000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_26                    (0x04000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_27                    (0x08000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_28                    (0x10000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_29                    (0x20000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_30                    (0x40000000U << SLCD_IOENR0_IOENR0_Pos) 
#define  SLCD_IOENR0_IOENR0_31                    (0x80000000U << SLCD_IOENR0_IOENR0_Pos) 

/**
  * @brief SLCD_IOENR1 Register Bit Definition
  */
#define  SLCD_IOENR1_IOENR1_Pos                   (0)
#define  SLCD_IOENR1_IOENR1_Msk                   (0xFFFFFFFFU << SLCD_IOENR1_IOENR1_Pos)           /*!<IO enable control corresponding to the high 32 bit SLCD pin.*/
#define  SLCD_IOENR1_IOENR1                       SLCD_IOENR1_IOENR1_Msk
#define  SLCD_IOENR1_IOENR1_0                     (0x00000001U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_1                     (0x00000002U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_2                     (0x00000004U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_3                     (0x00000008U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_4                     (0x00000010U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_5                     (0x00000020U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_6                     (0x00000040U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_7                     (0x00000080U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_8                     (0x00000100U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_9                     (0x00000200U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_10                    (0x00000400U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_11                    (0x00000800U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_12                    (0x00001000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_13                    (0x00002000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_14                    (0x00004000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_15                    (0x00008000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_16                    (0x00010000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_17                    (0x00020000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_18                    (0x00040000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_19                    (0x00080000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_20                    (0x00100000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_21                    (0x00200000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_22                    (0x00400000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_23                    (0x00800000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_24                    (0x01000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_25                    (0x02000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_26                    (0x04000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_27                    (0x08000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_28                    (0x10000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_29                    (0x20000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_30                    (0x40000000U << SLCD_IOENR1_IOENR1_Pos) 
#define  SLCD_IOENR1_IOENR1_31                    (0x80000000U << SLCD_IOENR1_IOENR1_Pos) 

/**
  * @brief SLCD_CFGR0 Register Bit Definition
  */
#define  SLCD_CFGR0_CFG0_Pos                      (0)
#define  SLCD_CFGR0_CFG0_Msk                      (0xFFFFFFFFU << SLCD_CFGR0_CFG0_Pos)              /*!<SEG/COM selection control corresponding to the low 32 bit SLCD*/
#define  SLCD_CFGR0_CFG0                          SLCD_CFGR0_CFG0_Msk
#define  SLCD_CFGR0_CFG0_0                        (0x00000001U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_1                        (0x00000002U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_2                        (0x00000004U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_3                        (0x00000008U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_4                        (0x00000010U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_5                        (0x00000020U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_6                        (0x00000040U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_7                        (0x00000080U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_8                        (0x00000100U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_9                        (0x00000200U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_10                       (0x00000400U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_11                       (0x00000800U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_12                       (0x00001000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_13                       (0x00002000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_14                       (0x00004000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_15                       (0x00008000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_16                       (0x00010000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_17                       (0x00020000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_18                       (0x00040000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_19                       (0x00080000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_20                       (0x00100000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_21                       (0x00200000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_22                       (0x00400000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_23                       (0x00800000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_24                       (0x01000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_25                       (0x02000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_26                       (0x04000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_27                       (0x08000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_28                       (0x10000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_29                       (0x20000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_30                       (0x40000000U << SLCD_CFGR0_CFG0_Pos) 
#define  SLCD_CFGR0_CFG0_31                       (0x80000000U << SLCD_CFGR0_CFG0_Pos) 

/**
  * @brief SLCD_CFGR1 Register Bit Definition
  */
#define  SLCD_CFGR1_CFG1_Pos                      (0)
#define  SLCD_CFGR1_CFG1_Msk                      (0xFFFFFFFFU << SLCD_CFGR1_CFG1_Pos)              /*!<SEG/COM selection control corresponding to the high 32 bit SLCD*/
#define  SLCD_CFGR1_CFG1                          SLCD_CFGR1_CFG1_Msk
#define  SLCD_CFGR1_CFG1_0                        (0x00000001U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_1                        (0x00000002U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_2                        (0x00000004U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_3                        (0x00000008U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_4                        (0x00000010U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_5                        (0x00000020U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_6                        (0x00000040U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_7                        (0x00000080U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_8                        (0x00000100U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_9                        (0x00000200U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_10                       (0x00000400U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_11                       (0x00000800U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_12                       (0x00001000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_13                       (0x00002000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_14                       (0x00004000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_15                       (0x00008000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_16                       (0x00010000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_17                       (0x00020000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_18                       (0x00040000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_19                       (0x00080000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_20                       (0x00100000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_21                       (0x00200000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_22                       (0x00400000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_23                       (0x00800000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_24                       (0x01000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_25                       (0x02000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_26                       (0x04000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_27                       (0x08000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_28                       (0x10000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_29                       (0x20000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_30                       (0x40000000U << SLCD_CFGR1_CFG1_Pos) 
#define  SLCD_CFGR1_CFG1_31                       (0x80000000U << SLCD_CFGR1_CFG1_Pos) 

/**
  * @brief SLCD_IDXR0 Register Bit Definition
  */
#define  SLCD_IDXR0_COM0IDX_Pos                   (0)
#define  SLCD_IDXR0_COM0IDX_Msk                   (0x3FU << SLCD_IDXR0_COM0IDX_Pos)                 /*!<COM0 index*/
#define  SLCD_IDXR0_COM0IDX                       SLCD_IDXR0_COM0IDX_Msk
#define  SLCD_IDXR0_COM0IDX_0                     (0x01U << SLCD_IDXR0_COM0IDX_Pos) 
#define  SLCD_IDXR0_COM0IDX_1                     (0x02U << SLCD_IDXR0_COM0IDX_Pos) 
#define  SLCD_IDXR0_COM0IDX_2                     (0x04U << SLCD_IDXR0_COM0IDX_Pos) 
#define  SLCD_IDXR0_COM0IDX_3                     (0x08U << SLCD_IDXR0_COM0IDX_Pos) 
#define  SLCD_IDXR0_COM0IDX_4                     (0x10U << SLCD_IDXR0_COM0IDX_Pos) 
#define  SLCD_IDXR0_COM0IDX_5                     (0x20U << SLCD_IDXR0_COM0IDX_Pos) 
#define  SLCD_IDXR0_COM1IDX_Pos                   (8)
#define  SLCD_IDXR0_COM1IDX_Msk                   (0x3FU << SLCD_IDXR0_COM1IDX_Pos)                 /*!<COM1 index*/
#define  SLCD_IDXR0_COM1IDX                       SLCD_IDXR0_COM1IDX_Msk
#define  SLCD_IDXR0_COM1IDX_0                     (0x01U << SLCD_IDXR0_COM1IDX_Pos) 
#define  SLCD_IDXR0_COM1IDX_1                     (0x02U << SLCD_IDXR0_COM1IDX_Pos) 
#define  SLCD_IDXR0_COM1IDX_2                     (0x04U << SLCD_IDXR0_COM1IDX_Pos) 
#define  SLCD_IDXR0_COM1IDX_3                     (0x08U << SLCD_IDXR0_COM1IDX_Pos) 
#define  SLCD_IDXR0_COM1IDX_4                     (0x10U << SLCD_IDXR0_COM1IDX_Pos) 
#define  SLCD_IDXR0_COM1IDX_5                     (0x20U << SLCD_IDXR0_COM1IDX_Pos) 
#define  SLCD_IDXR0_COM2IDX_Pos                   (16)
#define  SLCD_IDXR0_COM2IDX_Msk                   (0x3FU << SLCD_IDXR0_COM2IDX_Pos)                 /*!<COM2 index*/
#define  SLCD_IDXR0_COM2IDX                       SLCD_IDXR0_COM2IDX_Msk
#define  SLCD_IDXR0_COM2IDX_0                     (0x01U << SLCD_IDXR0_COM2IDX_Pos) 
#define  SLCD_IDXR0_COM2IDX_1                     (0x02U << SLCD_IDXR0_COM2IDX_Pos) 
#define  SLCD_IDXR0_COM2IDX_2                     (0x04U << SLCD_IDXR0_COM2IDX_Pos) 
#define  SLCD_IDXR0_COM2IDX_3                     (0x08U << SLCD_IDXR0_COM2IDX_Pos) 
#define  SLCD_IDXR0_COM2IDX_4                     (0x10U << SLCD_IDXR0_COM2IDX_Pos) 
#define  SLCD_IDXR0_COM2IDX_5                     (0x20U << SLCD_IDXR0_COM2IDX_Pos) 
#define  SLCD_IDXR0_COM3IDX_Pos                   (24)
#define  SLCD_IDXR0_COM3IDX_Msk                   (0x3FU << SLCD_IDXR0_COM3IDX_Pos)                 /*!<COM3 index*/
#define  SLCD_IDXR0_COM3IDX                       SLCD_IDXR0_COM3IDX_Msk
#define  SLCD_IDXR0_COM3IDX_0                     (0x01U << SLCD_IDXR0_COM3IDX_Pos) 
#define  SLCD_IDXR0_COM3IDX_1                     (0x02U << SLCD_IDXR0_COM3IDX_Pos) 
#define  SLCD_IDXR0_COM3IDX_2                     (0x04U << SLCD_IDXR0_COM3IDX_Pos) 
#define  SLCD_IDXR0_COM3IDX_3                     (0x08U << SLCD_IDXR0_COM3IDX_Pos) 
#define  SLCD_IDXR0_COM3IDX_4                     (0x10U << SLCD_IDXR0_COM3IDX_Pos) 
#define  SLCD_IDXR0_COM3IDX_5                     (0x20U << SLCD_IDXR0_COM3IDX_Pos) 

/**
  * @brief SLCD_IDXR1 Register Bit Definition
  */
#define  SLCD_IDXR1_COM4IDX_Pos                   (0)
#define  SLCD_IDXR1_COM4IDX_Msk                   (0x3FU << SLCD_IDXR1_COM4IDX_Pos)                 /*!<COM4 index*/
#define  SLCD_IDXR1_COM4IDX                       SLCD_IDXR1_COM4IDX_Msk
#define  SLCD_IDXR1_COM4IDX_0                     (0x01U << SLCD_IDXR1_COM4IDX_Pos) 
#define  SLCD_IDXR1_COM4IDX_1                     (0x02U << SLCD_IDXR1_COM4IDX_Pos) 
#define  SLCD_IDXR1_COM4IDX_2                     (0x04U << SLCD_IDXR1_COM4IDX_Pos) 
#define  SLCD_IDXR1_COM4IDX_3                     (0x08U << SLCD_IDXR1_COM4IDX_Pos) 
#define  SLCD_IDXR1_COM4IDX_4                     (0x10U << SLCD_IDXR1_COM4IDX_Pos) 
#define  SLCD_IDXR1_COM4IDX_5                     (0x20U << SLCD_IDXR1_COM4IDX_Pos) 
#define  SLCD_IDXR1_COM5IDX_Pos                   (8)
#define  SLCD_IDXR1_COM5IDX_Msk                   (0x3FU << SLCD_IDXR1_COM5IDX_Pos)                 /*!<COM5 index*/
#define  SLCD_IDXR1_COM5IDX                       SLCD_IDXR1_COM5IDX_Msk
#define  SLCD_IDXR1_COM5IDX_0                     (0x01U << SLCD_IDXR1_COM5IDX_Pos) 
#define  SLCD_IDXR1_COM5IDX_1                     (0x02U << SLCD_IDXR1_COM5IDX_Pos) 
#define  SLCD_IDXR1_COM5IDX_2                     (0x04U << SLCD_IDXR1_COM5IDX_Pos) 
#define  SLCD_IDXR1_COM5IDX_3                     (0x08U << SLCD_IDXR1_COM5IDX_Pos) 
#define  SLCD_IDXR1_COM5IDX_4                     (0x10U << SLCD_IDXR1_COM5IDX_Pos) 
#define  SLCD_IDXR1_COM5IDX_5                     (0x20U << SLCD_IDXR1_COM5IDX_Pos) 
#define  SLCD_IDXR1_COM6IDX_Pos                   (16)
#define  SLCD_IDXR1_COM6IDX_Msk                   (0x3FU << SLCD_IDXR1_COM6IDX_Pos)                 /*!<COM6 index*/
#define  SLCD_IDXR1_COM6IDX                       SLCD_IDXR1_COM6IDX_Msk
#define  SLCD_IDXR1_COM6IDX_0                     (0x01U << SLCD_IDXR1_COM6IDX_Pos) 
#define  SLCD_IDXR1_COM6IDX_1                     (0x02U << SLCD_IDXR1_COM6IDX_Pos) 
#define  SLCD_IDXR1_COM6IDX_2                     (0x04U << SLCD_IDXR1_COM6IDX_Pos) 
#define  SLCD_IDXR1_COM6IDX_3                     (0x08U << SLCD_IDXR1_COM6IDX_Pos) 
#define  SLCD_IDXR1_COM6IDX_4                     (0x10U << SLCD_IDXR1_COM6IDX_Pos) 
#define  SLCD_IDXR1_COM6IDX_5                     (0x20U << SLCD_IDXR1_COM6IDX_Pos) 
#define  SLCD_IDXR1_COM7IDX_Pos                   (24)
#define  SLCD_IDXR1_COM7IDX_Msk                   (0x3FU << SLCD_IDXR1_COM7IDX_Pos)                 /*!<COM7 index*/
#define  SLCD_IDXR1_COM7IDX                       SLCD_IDXR1_COM7IDX_Msk
#define  SLCD_IDXR1_COM7IDX_0                     (0x01U << SLCD_IDXR1_COM7IDX_Pos) 
#define  SLCD_IDXR1_COM7IDX_1                     (0x02U << SLCD_IDXR1_COM7IDX_Pos) 
#define  SLCD_IDXR1_COM7IDX_2                     (0x04U << SLCD_IDXR1_COM7IDX_Pos) 
#define  SLCD_IDXR1_COM7IDX_3                     (0x08U << SLCD_IDXR1_COM7IDX_Pos) 
#define  SLCD_IDXR1_COM7IDX_4                     (0x10U << SLCD_IDXR1_COM7IDX_Pos) 
#define  SLCD_IDXR1_COM7IDX_5                     (0x20U << SLCD_IDXR1_COM7IDX_Pos) 

/**
  * @brief SLCD_DR0 Register Bit Definition
  */
#define  SLCD_DR0_SLCD_DR0_Pos                    (0)
#define  SLCD_DR0_SLCD_DR0_Msk                    (0xFFFFFFFFU << SLCD_DR0_SLCD_DR0_Pos)            /*!<Low 32 bit display data corresponding to COM0*/
#define  SLCD_DR0_SLCD_DR0                        SLCD_DR0_SLCD_DR0_Msk
#define  SLCD_DR0_SLCD_DR0_0                      (0x00000001U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_1                      (0x00000002U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_2                      (0x00000004U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_3                      (0x00000008U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_4                      (0x00000010U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_5                      (0x00000020U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_6                      (0x00000040U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_7                      (0x00000080U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_8                      (0x00000100U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_9                      (0x00000200U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_10                     (0x00000400U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_11                     (0x00000800U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_12                     (0x00001000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_13                     (0x00002000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_14                     (0x00004000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_15                     (0x00008000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_16                     (0x00010000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_17                     (0x00020000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_18                     (0x00040000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_19                     (0x00080000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_20                     (0x00100000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_21                     (0x00200000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_22                     (0x00400000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_23                     (0x00800000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_24                     (0x01000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_25                     (0x02000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_26                     (0x04000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_27                     (0x08000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_28                     (0x10000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_29                     (0x20000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_30                     (0x40000000U << SLCD_DR0_SLCD_DR0_Pos) 
#define  SLCD_DR0_SLCD_DR0_31                     (0x80000000U << SLCD_DR0_SLCD_DR0_Pos) 

/**
  * @brief SLCD_DR1 Register Bit Definition
  */
#define  SLCD_DR1_SLCD_DR1_Pos                    (0)
#define  SLCD_DR1_SLCD_DR1_Msk                    (0xFFFFFFFFU << SLCD_DR1_SLCD_DR1_Pos)            /*!<High 32 bit display data corresponding to COM0*/
#define  SLCD_DR1_SLCD_DR1                        SLCD_DR1_SLCD_DR1_Msk
#define  SLCD_DR1_SLCD_DR1_0                      (0x00000001U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_1                      (0x00000002U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_2                      (0x00000004U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_3                      (0x00000008U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_4                      (0x00000010U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_5                      (0x00000020U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_6                      (0x00000040U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_7                      (0x00000080U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_8                      (0x00000100U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_9                      (0x00000200U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_10                     (0x00000400U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_11                     (0x00000800U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_12                     (0x00001000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_13                     (0x00002000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_14                     (0x00004000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_15                     (0x00008000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_16                     (0x00010000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_17                     (0x00020000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_18                     (0x00040000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_19                     (0x00080000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_20                     (0x00100000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_21                     (0x00200000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_22                     (0x00400000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_23                     (0x00800000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_24                     (0x01000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_25                     (0x02000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_26                     (0x04000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_27                     (0x08000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_28                     (0x10000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_29                     (0x20000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_30                     (0x40000000U << SLCD_DR1_SLCD_DR1_Pos) 
#define  SLCD_DR1_SLCD_DR1_31                     (0x80000000U << SLCD_DR1_SLCD_DR1_Pos) 

/**
  * @brief SLCD_DR2 Register Bit Definition
  */
#define  SLCD_DR2_SLCD_DR2_Pos                    (0)
#define  SLCD_DR2_SLCD_DR2_Msk                    (0xFFFFFFFFU << SLCD_DR2_SLCD_DR2_Pos)            /*!<Low 32 bit display data corresponding to COM1*/
#define  SLCD_DR2_SLCD_DR2                        SLCD_DR2_SLCD_DR2_Msk
#define  SLCD_DR2_SLCD_DR2_0                      (0x00000001U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_1                      (0x00000002U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_2                      (0x00000004U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_3                      (0x00000008U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_4                      (0x00000010U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_5                      (0x00000020U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_6                      (0x00000040U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_7                      (0x00000080U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_8                      (0x00000100U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_9                      (0x00000200U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_10                     (0x00000400U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_11                     (0x00000800U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_12                     (0x00001000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_13                     (0x00002000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_14                     (0x00004000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_15                     (0x00008000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_16                     (0x00010000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_17                     (0x00020000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_18                     (0x00040000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_19                     (0x00080000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_20                     (0x00100000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_21                     (0x00200000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_22                     (0x00400000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_23                     (0x00800000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_24                     (0x01000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_25                     (0x02000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_26                     (0x04000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_27                     (0x08000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_28                     (0x10000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_29                     (0x20000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_30                     (0x40000000U << SLCD_DR2_SLCD_DR2_Pos) 
#define  SLCD_DR2_SLCD_DR2_31                     (0x80000000U << SLCD_DR2_SLCD_DR2_Pos) 

/**
  * @brief SLCD_DR3 Register Bit Definition
  */
#define  SLCD_DR3_SLCD_DR3_Pos                    (0)
#define  SLCD_DR3_SLCD_DR3_Msk                    (0xFFFFFFFFU << SLCD_DR3_SLCD_DR3_Pos)            /*!<High 32 bit display data corresponding to COM1*/
#define  SLCD_DR3_SLCD_DR3                        SLCD_DR3_SLCD_DR3_Msk
#define  SLCD_DR3_SLCD_DR3_0                      (0x00000001U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_1                      (0x00000002U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_2                      (0x00000004U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_3                      (0x00000008U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_4                      (0x00000010U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_5                      (0x00000020U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_6                      (0x00000040U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_7                      (0x00000080U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_8                      (0x00000100U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_9                      (0x00000200U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_10                     (0x00000400U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_11                     (0x00000800U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_12                     (0x00001000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_13                     (0x00002000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_14                     (0x00004000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_15                     (0x00008000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_16                     (0x00010000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_17                     (0x00020000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_18                     (0x00040000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_19                     (0x00080000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_20                     (0x00100000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_21                     (0x00200000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_22                     (0x00400000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_23                     (0x00800000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_24                     (0x01000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_25                     (0x02000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_26                     (0x04000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_27                     (0x08000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_28                     (0x10000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_29                     (0x20000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_30                     (0x40000000U << SLCD_DR3_SLCD_DR3_Pos) 
#define  SLCD_DR3_SLCD_DR3_31                     (0x80000000U << SLCD_DR3_SLCD_DR3_Pos) 

/**
  * @brief SLCD_DR4 Register Bit Definition
  */
#define  SLCD_DR4_SLCD_DR4_Pos                    (0)
#define  SLCD_DR4_SLCD_DR4_Msk                    (0xFFFFFFFFU << SLCD_DR4_SLCD_DR4_Pos)            /*!<Low 32 bit display data corresponding to COM2*/
#define  SLCD_DR4_SLCD_DR4                        SLCD_DR4_SLCD_DR4_Msk
#define  SLCD_DR4_SLCD_DR4_0                      (0x00000001U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_1                      (0x00000002U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_2                      (0x00000004U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_3                      (0x00000008U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_4                      (0x00000010U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_5                      (0x00000020U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_6                      (0x00000040U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_7                      (0x00000080U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_8                      (0x00000100U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_9                      (0x00000200U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_10                     (0x00000400U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_11                     (0x00000800U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_12                     (0x00001000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_13                     (0x00002000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_14                     (0x00004000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_15                     (0x00008000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_16                     (0x00010000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_17                     (0x00020000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_18                     (0x00040000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_19                     (0x00080000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_20                     (0x00100000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_21                     (0x00200000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_22                     (0x00400000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_23                     (0x00800000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_24                     (0x01000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_25                     (0x02000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_26                     (0x04000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_27                     (0x08000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_28                     (0x10000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_29                     (0x20000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_30                     (0x40000000U << SLCD_DR4_SLCD_DR4_Pos) 
#define  SLCD_DR4_SLCD_DR4_31                     (0x80000000U << SLCD_DR4_SLCD_DR4_Pos) 

/**
  * @brief SLCD_DR5 Register Bit Definition
  */
#define  SLCD_DR5_SLCD_DR5_Pos                    (0)
#define  SLCD_DR5_SLCD_DR5_Msk                    (0xFFFFFFFFU << SLCD_DR5_SLCD_DR5_Pos)            /*!<High 32 bit display data corresponding to COM2*/
#define  SLCD_DR5_SLCD_DR5                        SLCD_DR5_SLCD_DR5_Msk
#define  SLCD_DR5_SLCD_DR5_0                      (0x00000001U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_1                      (0x00000002U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_2                      (0x00000004U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_3                      (0x00000008U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_4                      (0x00000010U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_5                      (0x00000020U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_6                      (0x00000040U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_7                      (0x00000080U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_8                      (0x00000100U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_9                      (0x00000200U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_10                     (0x00000400U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_11                     (0x00000800U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_12                     (0x00001000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_13                     (0x00002000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_14                     (0x00004000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_15                     (0x00008000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_16                     (0x00010000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_17                     (0x00020000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_18                     (0x00040000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_19                     (0x00080000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_20                     (0x00100000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_21                     (0x00200000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_22                     (0x00400000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_23                     (0x00800000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_24                     (0x01000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_25                     (0x02000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_26                     (0x04000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_27                     (0x08000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_28                     (0x10000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_29                     (0x20000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_30                     (0x40000000U << SLCD_DR5_SLCD_DR5_Pos) 
#define  SLCD_DR5_SLCD_DR5_31                     (0x80000000U << SLCD_DR5_SLCD_DR5_Pos) 

/**
  * @brief SLCD_DR6 Register Bit Definition
  */
#define  SLCD_DR6_SLCD_DR6_Pos                    (0)
#define  SLCD_DR6_SLCD_DR6_Msk                    (0xFFFFFFFFU << SLCD_DR6_SLCD_DR6_Pos)            /*!<Low 32 bit display data corresponding to COM3*/
#define  SLCD_DR6_SLCD_DR6                        SLCD_DR6_SLCD_DR6_Msk
#define  SLCD_DR6_SLCD_DR6_0                      (0x00000001U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_1                      (0x00000002U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_2                      (0x00000004U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_3                      (0x00000008U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_4                      (0x00000010U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_5                      (0x00000020U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_6                      (0x00000040U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_7                      (0x00000080U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_8                      (0x00000100U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_9                      (0x00000200U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_10                     (0x00000400U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_11                     (0x00000800U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_12                     (0x00001000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_13                     (0x00002000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_14                     (0x00004000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_15                     (0x00008000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_16                     (0x00010000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_17                     (0x00020000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_18                     (0x00040000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_19                     (0x00080000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_20                     (0x00100000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_21                     (0x00200000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_22                     (0x00400000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_23                     (0x00800000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_24                     (0x01000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_25                     (0x02000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_26                     (0x04000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_27                     (0x08000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_28                     (0x10000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_29                     (0x20000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_30                     (0x40000000U << SLCD_DR6_SLCD_DR6_Pos) 
#define  SLCD_DR6_SLCD_DR6_31                     (0x80000000U << SLCD_DR6_SLCD_DR6_Pos) 

/**
  * @brief SLCD_DR7 Register Bit Definition
  */
#define  SLCD_DR7_SLCD_DR7_Pos                    (0)
#define  SLCD_DR7_SLCD_DR7_Msk                    (0xFFFFFFFFU << SLCD_DR7_SLCD_DR7_Pos)            /*!<High 32 bit display data corresponding to COM3*/
#define  SLCD_DR7_SLCD_DR7                        SLCD_DR7_SLCD_DR7_Msk
#define  SLCD_DR7_SLCD_DR7_0                      (0x00000001U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_1                      (0x00000002U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_2                      (0x00000004U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_3                      (0x00000008U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_4                      (0x00000010U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_5                      (0x00000020U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_6                      (0x00000040U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_7                      (0x00000080U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_8                      (0x00000100U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_9                      (0x00000200U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_10                     (0x00000400U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_11                     (0x00000800U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_12                     (0x00001000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_13                     (0x00002000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_14                     (0x00004000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_15                     (0x00008000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_16                     (0x00010000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_17                     (0x00020000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_18                     (0x00040000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_19                     (0x00080000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_20                     (0x00100000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_21                     (0x00200000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_22                     (0x00400000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_23                     (0x00800000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_24                     (0x01000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_25                     (0x02000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_26                     (0x04000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_27                     (0x08000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_28                     (0x10000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_29                     (0x20000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_30                     (0x40000000U << SLCD_DR7_SLCD_DR7_Pos) 
#define  SLCD_DR7_SLCD_DR7_31                     (0x80000000U << SLCD_DR7_SLCD_DR7_Pos) 

/**
  * @brief SLCD_DR8 Register Bit Definition
  */
#define  SLCD_DR8_SLCD_DR8_Pos                    (0)
#define  SLCD_DR8_SLCD_DR8_Msk                    (0xFFFFFFFFU << SLCD_DR8_SLCD_DR8_Pos)            /*!<Low 32 bit display data corresponding to COM4*/
#define  SLCD_DR8_SLCD_DR8                        SLCD_DR8_SLCD_DR8_Msk
#define  SLCD_DR8_SLCD_DR8_0                      (0x00000001U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_1                      (0x00000002U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_2                      (0x00000004U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_3                      (0x00000008U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_4                      (0x00000010U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_5                      (0x00000020U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_6                      (0x00000040U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_7                      (0x00000080U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_8                      (0x00000100U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_9                      (0x00000200U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_10                     (0x00000400U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_11                     (0x00000800U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_12                     (0x00001000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_13                     (0x00002000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_14                     (0x00004000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_15                     (0x00008000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_16                     (0x00010000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_17                     (0x00020000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_18                     (0x00040000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_19                     (0x00080000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_20                     (0x00100000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_21                     (0x00200000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_22                     (0x00400000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_23                     (0x00800000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_24                     (0x01000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_25                     (0x02000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_26                     (0x04000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_27                     (0x08000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_28                     (0x10000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_29                     (0x20000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_30                     (0x40000000U << SLCD_DR8_SLCD_DR8_Pos) 
#define  SLCD_DR8_SLCD_DR8_31                     (0x80000000U << SLCD_DR8_SLCD_DR8_Pos) 

/**
  * @brief SLCD_DR9 Register Bit Definition
  */
#define  SLCD_DR9_SLCD_DR9_Pos                    (0)
#define  SLCD_DR9_SLCD_DR9_Msk                    (0xFFFFFFFFU << SLCD_DR9_SLCD_DR9_Pos)            /*!<High 32 bit display data corresponding to COM4*/
#define  SLCD_DR9_SLCD_DR9                        SLCD_DR9_SLCD_DR9_Msk
#define  SLCD_DR9_SLCD_DR9_0                      (0x00000001U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_1                      (0x00000002U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_2                      (0x00000004U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_3                      (0x00000008U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_4                      (0x00000010U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_5                      (0x00000020U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_6                      (0x00000040U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_7                      (0x00000080U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_8                      (0x00000100U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_9                      (0x00000200U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_10                     (0x00000400U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_11                     (0x00000800U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_12                     (0x00001000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_13                     (0x00002000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_14                     (0x00004000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_15                     (0x00008000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_16                     (0x00010000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_17                     (0x00020000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_18                     (0x00040000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_19                     (0x00080000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_20                     (0x00100000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_21                     (0x00200000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_22                     (0x00400000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_23                     (0x00800000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_24                     (0x01000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_25                     (0x02000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_26                     (0x04000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_27                     (0x08000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_28                     (0x10000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_29                     (0x20000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_30                     (0x40000000U << SLCD_DR9_SLCD_DR9_Pos) 
#define  SLCD_DR9_SLCD_DR9_31                     (0x80000000U << SLCD_DR9_SLCD_DR9_Pos) 

/**
  * @brief SLCD_DR10 Register Bit Definition
  */
#define  SLCD_DR10_SLCD_DR10_Pos                  (0)
#define  SLCD_DR10_SLCD_DR10_Msk                  (0xFFFFFFFFU << SLCD_DR10_SLCD_DR10_Pos)          /*!<Low 32 bit display data corresponding to COM5*/
#define  SLCD_DR10_SLCD_DR10                      SLCD_DR10_SLCD_DR10_Msk
#define  SLCD_DR10_SLCD_DR10_0                    (0x00000001U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_1                    (0x00000002U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_2                    (0x00000004U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_3                    (0x00000008U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_4                    (0x00000010U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_5                    (0x00000020U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_6                    (0x00000040U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_7                    (0x00000080U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_8                    (0x00000100U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_9                    (0x00000200U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_10                   (0x00000400U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_11                   (0x00000800U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_12                   (0x00001000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_13                   (0x00002000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_14                   (0x00004000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_15                   (0x00008000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_16                   (0x00010000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_17                   (0x00020000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_18                   (0x00040000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_19                   (0x00080000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_20                   (0x00100000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_21                   (0x00200000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_22                   (0x00400000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_23                   (0x00800000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_24                   (0x01000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_25                   (0x02000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_26                   (0x04000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_27                   (0x08000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_28                   (0x10000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_29                   (0x20000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_30                   (0x40000000U << SLCD_DR10_SLCD_DR10_Pos) 
#define  SLCD_DR10_SLCD_DR10_31                   (0x80000000U << SLCD_DR10_SLCD_DR10_Pos) 

/**
  * @brief SLCD_DR11 Register Bit Definition
  */
#define  SLCD_DR11_SLCD_DR11_Pos                  (0)
#define  SLCD_DR11_SLCD_DR11_Msk                  (0xFFFFFFFFU << SLCD_DR11_SLCD_DR11_Pos)          /*!<High 32 bit display data corresponding to COM5*/
#define  SLCD_DR11_SLCD_DR11                      SLCD_DR11_SLCD_DR11_Msk
#define  SLCD_DR11_SLCD_DR11_0                    (0x00000001U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_1                    (0x00000002U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_2                    (0x00000004U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_3                    (0x00000008U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_4                    (0x00000010U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_5                    (0x00000020U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_6                    (0x00000040U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_7                    (0x00000080U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_8                    (0x00000100U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_9                    (0x00000200U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_10                   (0x00000400U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_11                   (0x00000800U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_12                   (0x00001000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_13                   (0x00002000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_14                   (0x00004000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_15                   (0x00008000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_16                   (0x00010000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_17                   (0x00020000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_18                   (0x00040000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_19                   (0x00080000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_20                   (0x00100000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_21                   (0x00200000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_22                   (0x00400000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_23                   (0x00800000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_24                   (0x01000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_25                   (0x02000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_26                   (0x04000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_27                   (0x08000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_28                   (0x10000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_29                   (0x20000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_30                   (0x40000000U << SLCD_DR11_SLCD_DR11_Pos) 
#define  SLCD_DR11_SLCD_DR11_31                   (0x80000000U << SLCD_DR11_SLCD_DR11_Pos) 

/**
  * @brief SLCD_DR12 Register Bit Definition
  */
#define  SLCD_DR12_SLCD_DR12_Pos                  (0)
#define  SLCD_DR12_SLCD_DR12_Msk                  (0xFFFFFFFFU << SLCD_DR12_SLCD_DR12_Pos)          /*!<Low 32 bit display data corresponding to COM6*/
#define  SLCD_DR12_SLCD_DR12                      SLCD_DR12_SLCD_DR12_Msk
#define  SLCD_DR12_SLCD_DR12_0                    (0x00000001U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_1                    (0x00000002U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_2                    (0x00000004U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_3                    (0x00000008U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_4                    (0x00000010U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_5                    (0x00000020U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_6                    (0x00000040U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_7                    (0x00000080U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_8                    (0x00000100U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_9                    (0x00000200U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_10                   (0x00000400U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_11                   (0x00000800U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_12                   (0x00001000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_13                   (0x00002000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_14                   (0x00004000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_15                   (0x00008000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_16                   (0x00010000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_17                   (0x00020000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_18                   (0x00040000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_19                   (0x00080000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_20                   (0x00100000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_21                   (0x00200000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_22                   (0x00400000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_23                   (0x00800000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_24                   (0x01000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_25                   (0x02000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_26                   (0x04000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_27                   (0x08000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_28                   (0x10000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_29                   (0x20000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_30                   (0x40000000U << SLCD_DR12_SLCD_DR12_Pos) 
#define  SLCD_DR12_SLCD_DR12_31                   (0x80000000U << SLCD_DR12_SLCD_DR12_Pos) 

/**
  * @brief SLCD_DR13 Register Bit Definition
  */
#define  SLCD_DR13_SLCD_DR13_Pos                  (0)
#define  SLCD_DR13_SLCD_DR13_Msk                  (0xFFFFFFFFU << SLCD_DR13_SLCD_DR13_Pos)          /*!<High 32 bit display data corresponding to COM6*/
#define  SLCD_DR13_SLCD_DR13                      SLCD_DR13_SLCD_DR13_Msk
#define  SLCD_DR13_SLCD_DR13_0                    (0x00000001U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_1                    (0x00000002U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_2                    (0x00000004U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_3                    (0x00000008U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_4                    (0x00000010U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_5                    (0x00000020U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_6                    (0x00000040U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_7                    (0x00000080U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_8                    (0x00000100U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_9                    (0x00000200U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_10                   (0x00000400U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_11                   (0x00000800U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_12                   (0x00001000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_13                   (0x00002000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_14                   (0x00004000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_15                   (0x00008000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_16                   (0x00010000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_17                   (0x00020000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_18                   (0x00040000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_19                   (0x00080000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_20                   (0x00100000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_21                   (0x00200000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_22                   (0x00400000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_23                   (0x00800000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_24                   (0x01000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_25                   (0x02000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_26                   (0x04000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_27                   (0x08000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_28                   (0x10000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_29                   (0x20000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_30                   (0x40000000U << SLCD_DR13_SLCD_DR13_Pos) 
#define  SLCD_DR13_SLCD_DR13_31                   (0x80000000U << SLCD_DR13_SLCD_DR13_Pos) 

/**
  * @brief SLCD_DR14 Register Bit Definition
  */
#define  SLCD_DR14_SLCD_DR14_Pos                  (0)
#define  SLCD_DR14_SLCD_DR14_Msk                  (0xFFFFFFFFU << SLCD_DR14_SLCD_DR14_Pos)          /*!<Low 32 bit display data corresponding to COM7*/
#define  SLCD_DR14_SLCD_DR14                      SLCD_DR14_SLCD_DR14_Msk
#define  SLCD_DR14_SLCD_DR14_0                    (0x00000001U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_1                    (0x00000002U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_2                    (0x00000004U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_3                    (0x00000008U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_4                    (0x00000010U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_5                    (0x00000020U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_6                    (0x00000040U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_7                    (0x00000080U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_8                    (0x00000100U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_9                    (0x00000200U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_10                   (0x00000400U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_11                   (0x00000800U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_12                   (0x00001000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_13                   (0x00002000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_14                   (0x00004000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_15                   (0x00008000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_16                   (0x00010000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_17                   (0x00020000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_18                   (0x00040000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_19                   (0x00080000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_20                   (0x00100000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_21                   (0x00200000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_22                   (0x00400000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_23                   (0x00800000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_24                   (0x01000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_25                   (0x02000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_26                   (0x04000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_27                   (0x08000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_28                   (0x10000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_29                   (0x20000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_30                   (0x40000000U << SLCD_DR14_SLCD_DR14_Pos) 
#define  SLCD_DR14_SLCD_DR14_31                   (0x80000000U << SLCD_DR14_SLCD_DR14_Pos) 

/**
  * @brief SLCD_DR15 Register Bit Definition
  */
#define  SLCD_DR15_SLCD_DR15_Pos                  (0)
#define  SLCD_DR15_SLCD_DR15_Msk                  (0xFFFFFFFFU << SLCD_DR15_SLCD_DR15_Pos)          /*!<High 32 bit display data corresponding to COM7*/
#define  SLCD_DR15_SLCD_DR15                      SLCD_DR15_SLCD_DR15_Msk
#define  SLCD_DR15_SLCD_DR15_0                    (0x00000001U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_1                    (0x00000002U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_2                    (0x00000004U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_3                    (0x00000008U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_4                    (0x00000010U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_5                    (0x00000020U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_6                    (0x00000040U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_7                    (0x00000080U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_8                    (0x00000100U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_9                    (0x00000200U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_10                   (0x00000400U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_11                   (0x00000800U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_12                   (0x00001000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_13                   (0x00002000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_14                   (0x00004000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_15                   (0x00008000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_16                   (0x00010000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_17                   (0x00020000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_18                   (0x00040000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_19                   (0x00080000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_20                   (0x00100000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_21                   (0x00200000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_22                   (0x00400000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_23                   (0x00800000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_24                   (0x01000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_25                   (0x02000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_26                   (0x04000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_27                   (0x08000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_28                   (0x10000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_29                   (0x20000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_30                   (0x40000000U << SLCD_DR15_SLCD_DR15_Pos) 
#define  SLCD_DR15_SLCD_DR15_31                   (0x80000000U << SLCD_DR15_SLCD_DR15_Pos) 

#endif

