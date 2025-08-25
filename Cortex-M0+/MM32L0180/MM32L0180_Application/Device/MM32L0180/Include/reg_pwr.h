/***********************************************************************************************************************
    @file     reg_pwr.h
    @author   VV TEAM
    @brief    This flie contains all the PWR's register and its field definition.
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

#ifndef __REG_PWR_H
#define __REG_PWR_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief PWR Base Address Definition
  */
#define  PWR_BASE                                  0x40007000                                       /*!<Base Address: 0x40007000*/

/**
  * @brief PWR Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                            /*!<PWR Power control register 1                   offset: 0x00       */
    __IO uint32_t CSR;                            /*!<PWR Power control status register              offset: 0x04       */
    __IO uint32_t CR2;                            /*!<PWR Power control register 2                   offset: 0x08       */
    __IO uint32_t CR3;                            /*!<PWR Power control register 3                   offset: 0x0C       */
    __IO uint32_t RESERVED0x10[2];                /*!<                                               offset: 0x10~0x14  */
    __IO uint32_t CR6;                            /*!<PWR Power control register 6                   offset: 0x18       */
    __IO uint32_t SR;                             /*!<PWR Power status register                      offset: 0x1C       */
    __IO uint32_t SCR;                            /*!<PWR Power status clear register                offset: 0x20       */
    __IO uint32_t CFGR;                           /*!<PWR Power configuration register               offset: 0x24       */
    __IO uint32_t CFGR2;                          /*!<PWR Power configuration register 2             offset: 0x28       */
} PWR_TypeDef;

/**
  * @brief PWR type pointer Definition
  */
#define PWR                                       ((PWR_TypeDef *)PWR_BASE)

/**
  * @brief PWR_CR1 Register Bit Definition
  */
#define  PWR_CR1_LPDS_Pos                         (0)
#define  PWR_CR1_LPDS_Msk                         (0x1U << PWR_CR1_LPDS_Pos)                        /*!<Low power deepsleep*/
#define  PWR_CR1_LPDS                             PWR_CR1_LPDS_Msk
#define  PWR_CR1_PDDS_Pos                         (1)
#define  PWR_CR1_PDDS_Msk                         (0x1U << PWR_CR1_PDDS_Pos)                        /*!<Power down deepsleep*/
#define  PWR_CR1_PDDS                             PWR_CR1_PDDS_Msk
#define  PWR_CR1_CWUF_Pos                         (2)
#define  PWR_CR1_CWUF_Msk                         (0x1U << PWR_CR1_CWUF_Pos)                        /*!<Clear Wakeup flag*/
#define  PWR_CR1_CWUF                             PWR_CR1_CWUF_Msk
#define  PWR_CR1_CSBF_Pos                         (3)
#define  PWR_CR1_CSBF_Msk                         (0x1U << PWR_CR1_CSBF_Pos)                        /*!<Clear standby flag*/
#define  PWR_CR1_CSBF                             PWR_CR1_CSBF_Msk
#define  PWR_CR1_LPR_Pos                          (13)
#define  PWR_CR1_LPR_Msk                          (0x1U << PWR_CR1_LPR_Pos)                         /*!<Low power configuration bit, after assertion, the voltage regulator changes over from normal mode to low power mode.*/
#define  PWR_CR1_LPR                              PWR_CR1_LPR_Msk

/**
  * @brief PWR_CSR Register Bit Definition
  */
#define  PWR_CSR_WUF_Pos                          (0)
#define  PWR_CSR_WUF_Msk                          (0x1U << PWR_CSR_WUF_Pos)                         /*!<Wakup flag*/
#define  PWR_CSR_WUF                              PWR_CSR_WUF_Msk
#define  PWR_CSR_SBF_Pos                          (1)
#define  PWR_CSR_SBF_Msk                          (0x1U << PWR_CSR_SBF_Pos)                         /*!<Standby Flag*/
#define  PWR_CSR_SBF                              PWR_CSR_SBF_Msk

/**
  * @brief PWR_CR2 Register Bit Definition
  */
#define  PWR_CR2_EWUP0_Pos                        (0)
#define  PWR_CR2_EWUP0_Msk                        (0x1U << PWR_CR2_EWUP0_Pos)                       /*!<Enable wakeup pin 0*/
#define  PWR_CR2_EWUP0                            PWR_CR2_EWUP0_Msk
#define  PWR_CR2_EWUP1_Pos                        (1)
#define  PWR_CR2_EWUP1_Msk                        (0x1U << PWR_CR2_EWUP1_Pos)                       /*!<Enable wakeup pin 1*/
#define  PWR_CR2_EWUP1                            PWR_CR2_EWUP1_Msk
#define  PWR_CR2_EWUP2_Pos                        (2)
#define  PWR_CR2_EWUP2_Msk                        (0x1U << PWR_CR2_EWUP2_Pos)                       /*!<Enable wakeup pin 2*/
#define  PWR_CR2_EWUP2                            PWR_CR2_EWUP2_Msk
#define  PWR_CR2_EWUP3_Pos                        (3)
#define  PWR_CR2_EWUP3_Msk                        (0x1U << PWR_CR2_EWUP3_Pos)                       /*!<Enable wakeup pin 3*/
#define  PWR_CR2_EWUP3                            PWR_CR2_EWUP3_Msk
#define  PWR_CR2_EWUP4_Pos                        (4)
#define  PWR_CR2_EWUP4_Msk                        (0x1U << PWR_CR2_EWUP4_Pos)                       /*!<Enable wakeup pin 4*/
#define  PWR_CR2_EWUP4                            PWR_CR2_EWUP4_Msk
#define  PWR_CR2_EWUP5_Pos                        (5)
#define  PWR_CR2_EWUP5_Msk                        (0x1U << PWR_CR2_EWUP5_Pos)                       /*!<Enable wakeup pin 5*/
#define  PWR_CR2_EWUP5                            PWR_CR2_EWUP5_Msk

/**
  * @brief PWR_CR3 Register Bit Definition
  */
#define  PWR_CR3_WP0_Pos                          (0)
#define  PWR_CR3_WP0_Msk                          (0x1U << PWR_CR3_WP0_Pos)                         /*!<Polarity detection of wakeup pin 0*/
#define  PWR_CR3_WP0                              PWR_CR3_WP0_Msk
#define  PWR_CR3_WP1_Pos                          (1)
#define  PWR_CR3_WP1_Msk                          (0x1U << PWR_CR3_WP1_Pos)                         /*!<Polarity detection of wakeup pin 1*/
#define  PWR_CR3_WP1                              PWR_CR3_WP1_Msk
#define  PWR_CR3_WP2_Pos                          (2)
#define  PWR_CR3_WP2_Msk                          (0x1U << PWR_CR3_WP2_Pos)                         /*!<Polarity detection of wakeup pin 2*/
#define  PWR_CR3_WP2                              PWR_CR3_WP2_Msk
#define  PWR_CR3_WP3_Pos                          (3)
#define  PWR_CR3_WP3_Msk                          (0x1U << PWR_CR3_WP3_Pos)                         /*!<Polarity detection of wakeup pin 3*/
#define  PWR_CR3_WP3                              PWR_CR3_WP3_Msk
#define  PWR_CR3_WP4_Pos                          (4)
#define  PWR_CR3_WP4_Msk                          (0x1U << PWR_CR3_WP4_Pos)                         /*!<Polarity detection of wakeup pin 4*/
#define  PWR_CR3_WP4                              PWR_CR3_WP4_Msk
#define  PWR_CR3_WP5_Pos                          (5)
#define  PWR_CR3_WP5_Msk                          (0x1U << PWR_CR3_WP5_Pos)                         /*!<Polarity detection of wakeup pin 5*/
#define  PWR_CR3_WP5                              PWR_CR3_WP5_Msk

/**
  * @brief PWR_CR6 Register Bit Definition
  */
#define  PWR_CR6_STDBY_FS_WK_Pos                  (0)
#define  PWR_CR6_STDBY_FS_WK_Msk                  (0x3U << PWR_CR6_STDBY_FS_WK_Pos)                 /*!<STDBY_FS_WK: Rapidly wakeup standby mode selection bit*/
#define  PWR_CR6_STDBY_FS_WK                      PWR_CR6_STDBY_FS_WK_Msk
#define  PWR_CR6_STDBY_FS_WK_0                    (0x1U << PWR_CR6_STDBY_FS_WK_Pos) 
#define  PWR_CR6_STDBY_FS_WK_1                    (0x2U << PWR_CR6_STDBY_FS_WK_Pos) 
#define  PWR_CR6_PWR_SYNC_REQ_Pos                 (2)
#define  PWR_CR6_PWR_SYNC_REQ_Msk                 (0x1U << PWR_CR6_PWR_SYNC_REQ_Pos)                /*!<*/
#define  PWR_CR6_PWR_SYNC_REQ                     PWR_CR6_PWR_SYNC_REQ_Msk

/**
  * @brief PWR_SR Register Bit Definition
  */
#define  PWR_SR_WUF0_Pos                          (0)
#define  PWR_SR_WUF0_Msk                          (0x1U << PWR_SR_WUF0_Pos)                         /*!<Wakeup flag of wakeup pin 0*/
#define  PWR_SR_WUF0                              PWR_SR_WUF0_Msk
#define  PWR_SR_WUF1_Pos                          (1)
#define  PWR_SR_WUF1_Msk                          (0x1U << PWR_SR_WUF1_Pos)                         /*!<Wakeup flag of wakeup pin 1*/
#define  PWR_SR_WUF1                              PWR_SR_WUF1_Msk
#define  PWR_SR_WUF2_Pos                          (2)
#define  PWR_SR_WUF2_Msk                          (0x1U << PWR_SR_WUF2_Pos)                         /*!<Wakeup flag of wakeup pin 2*/
#define  PWR_SR_WUF2                              PWR_SR_WUF2_Msk
#define  PWR_SR_WUF3_Pos                          (3)
#define  PWR_SR_WUF3_Msk                          (0x1U << PWR_SR_WUF3_Pos)                         /*!<Wakeup flag of wakeup pin 3*/
#define  PWR_SR_WUF3                              PWR_SR_WUF3_Msk
#define  PWR_SR_WUF4_Pos                          (4)
#define  PWR_SR_WUF4_Msk                          (0x1U << PWR_SR_WUF4_Pos)                         /*!<Wakeup flag of wakeup pin 4*/
#define  PWR_SR_WUF4                              PWR_SR_WUF4_Msk
#define  PWR_SR_WUF5_Pos                          (5)
#define  PWR_SR_WUF5_Msk                          (0x1U << PWR_SR_WUF5_Pos)                         /*!<Wakeup flag of wakeup pin 5*/
#define  PWR_SR_WUF5                              PWR_SR_WUF5_Msk

/**
  * @brief PWR_SCR Register Bit Definition
  */
#define  PWR_SCR_CWUF0_Pos                        (0)
#define  PWR_SCR_CWUF0_Msk                        (0x1U << PWR_SCR_CWUF0_Pos)                       /*!<Wakeup flag of clearing wakeup pin 0*/
#define  PWR_SCR_CWUF0                            PWR_SCR_CWUF0_Msk
#define  PWR_SCR_CWUF1_Pos                        (1)
#define  PWR_SCR_CWUF1_Msk                        (0x1U << PWR_SCR_CWUF1_Pos)                       /*!<Wakeup flag of clearing wakeup pin 1*/
#define  PWR_SCR_CWUF1                            PWR_SCR_CWUF1_Msk
#define  PWR_SCR_CWUF2_Pos                        (2)
#define  PWR_SCR_CWUF2_Msk                        (0x1U << PWR_SCR_CWUF2_Pos)                       /*!<Wakeup flag of clearing wakeup pin 2*/
#define  PWR_SCR_CWUF2                            PWR_SCR_CWUF2_Msk
#define  PWR_SCR_CWUF3_Pos                        (3)
#define  PWR_SCR_CWUF3_Msk                        (0x1U << PWR_SCR_CWUF3_Pos)                       /*!<Wakeup flag of clearing wakeup pin 3*/
#define  PWR_SCR_CWUF3                            PWR_SCR_CWUF3_Msk
#define  PWR_SCR_CWUF4_Pos                        (4)
#define  PWR_SCR_CWUF4_Msk                        (0x1U << PWR_SCR_CWUF4_Pos)                       /*!<Wakeup flag of clearing wakeup pin 4*/
#define  PWR_SCR_CWUF4                            PWR_SCR_CWUF4_Msk
#define  PWR_SCR_CWUF5_Pos                        (5)
#define  PWR_SCR_CWUF5_Msk                        (0x1U << PWR_SCR_CWUF5_Pos)                       /*!<Wakeup flag of clearing wakeup pin 5*/
#define  PWR_SCR_CWUF5                            PWR_SCR_CWUF5_Msk

/**
  * @brief PWR_CFGR Register Bit Definition
  */
#define  PWR_CFGR_LSI_32K_CAL_SEL_Pos             (0)
#define  PWR_CFGR_LSI_32K_CAL_SEL_Msk             (0x1FU << PWR_CFGR_LSI_32K_CAL_SEL_Pos)           /*!<Internal Low-speed Calibration Select*/
#define  PWR_CFGR_LSI_32K_CAL_SEL                 PWR_CFGR_LSI_32K_CAL_SEL_Msk
#define  PWR_CFGR_LSI_32K_CAL_SEL_0               (0x01U << PWR_CFGR_LSI_32K_CAL_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_CAL_SEL_1               (0x02U << PWR_CFGR_LSI_32K_CAL_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_CAL_SEL_2               (0x04U << PWR_CFGR_LSI_32K_CAL_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_CAL_SEL_3               (0x08U << PWR_CFGR_LSI_32K_CAL_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_CAL_SEL_4               (0x10U << PWR_CFGR_LSI_32K_CAL_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_TSEL_Pos                (5)
#define  PWR_CFGR_LSI_32K_TSEL_Msk                (0x3U << PWR_CFGR_LSI_32K_TSEL_Pos)               /*!<Internal Low-speed Clock Temperature Calibration Bits*/
#define  PWR_CFGR_LSI_32K_TSEL                    PWR_CFGR_LSI_32K_TSEL_Msk
#define  PWR_CFGR_LSI_32K_TSEL_0                  (0x1U << PWR_CFGR_LSI_32K_TSEL_Pos) 
#define  PWR_CFGR_LSI_32K_TSEL_1                  (0x2U << PWR_CFGR_LSI_32K_TSEL_Pos) 
#define  PWR_CFGR_LSI_32K_FINE_SEL_Pos            (7)
#define  PWR_CFGR_LSI_32K_FINE_SEL_Msk            (0x1FU << PWR_CFGR_LSI_32K_FINE_SEL_Pos)          /*!<Internal Low-speed Clock Fine Calibration Bits*/
#define  PWR_CFGR_LSI_32K_FINE_SEL                PWR_CFGR_LSI_32K_FINE_SEL_Msk
#define  PWR_CFGR_LSI_32K_FINE_SEL_0              (0x01U << PWR_CFGR_LSI_32K_FINE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_FINE_SEL_1              (0x02U << PWR_CFGR_LSI_32K_FINE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_FINE_SEL_2              (0x04U << PWR_CFGR_LSI_32K_FINE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_FINE_SEL_3              (0x08U << PWR_CFGR_LSI_32K_FINE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_FINE_SEL_4              (0x10U << PWR_CFGR_LSI_32K_FINE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_COARSE_SEL_Pos          (12)
#define  PWR_CFGR_LSI_32K_COARSE_SEL_Msk          (0x7U << PWR_CFGR_LSI_32K_COARSE_SEL_Pos)         /*!<Internal Low-speed Clock Calibration Bits*/
#define  PWR_CFGR_LSI_32K_COARSE_SEL              PWR_CFGR_LSI_32K_COARSE_SEL_Msk
#define  PWR_CFGR_LSI_32K_COARSE_SEL_0            (0x1U << PWR_CFGR_LSI_32K_COARSE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_COARSE_SEL_1            (0x2U << PWR_CFGR_LSI_32K_COARSE_SEL_Pos) 
#define  PWR_CFGR_LSI_32K_COARSE_SEL_2            (0x4U << PWR_CFGR_LSI_32K_COARSE_SEL_Pos) 

/**
  * @brief PWR_CFGR2 Register Bit Definition
  */
#define  PWR_CFGR2_LSI_40K_CAL_SEL_Pos            (0)
#define  PWR_CFGR2_LSI_40K_CAL_SEL_Msk            (0x1FU << PWR_CFGR2_LSI_40K_CAL_SEL_Pos)          /*!<Internal Low-speed Calibration Select*/
#define  PWR_CFGR2_LSI_40K_CAL_SEL                PWR_CFGR2_LSI_40K_CAL_SEL_Msk
#define  PWR_CFGR2_LSI_40K_CAL_SEL_0              (0x01U << PWR_CFGR2_LSI_40K_CAL_SEL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_SEL_1              (0x02U << PWR_CFGR2_LSI_40K_CAL_SEL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_SEL_2              (0x04U << PWR_CFGR2_LSI_40K_CAL_SEL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_SEL_3              (0x08U << PWR_CFGR2_LSI_40K_CAL_SEL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_SEL_4              (0x10U << PWR_CFGR2_LSI_40K_CAL_SEL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_Pos                (8)
#define  PWR_CFGR2_LSI_40K_CAL_Msk                (0x1FU << PWR_CFGR2_LSI_40K_CAL_Pos)              /*!<Internal Low-speed 40K Clock Calibration Bits*/
#define  PWR_CFGR2_LSI_40K_CAL                    PWR_CFGR2_LSI_40K_CAL_Msk
#define  PWR_CFGR2_LSI_40K_CAL_0                  (0x01U << PWR_CFGR2_LSI_40K_CAL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_1                  (0x02U << PWR_CFGR2_LSI_40K_CAL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_2                  (0x04U << PWR_CFGR2_LSI_40K_CAL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_3                  (0x08U << PWR_CFGR2_LSI_40K_CAL_Pos) 
#define  PWR_CFGR2_LSI_40K_CAL_4                  (0x10U << PWR_CFGR2_LSI_40K_CAL_Pos) 

#endif

