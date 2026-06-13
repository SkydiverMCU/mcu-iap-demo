/***********************************************************************************************************************
    @file     reg_tim.h
    @author   FD TEAM
    @brief    This flie contains all the TIM's register and its field definition.
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

#ifndef __REG_TIM_H
#define __REG_TIM_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief TIM Base Address Definition
  */
#define  TIM2_BASE                                 0x40000000                                       /*!<Base Address: 0x40000000*/
#define  TIM1_BASE                                 0x40012C00                                       /*!<Base Address: 0x40012C00*/
#define  TIM14_BASE                                0x40014000                                       /*!<Base Address: 0x40014000*/
#define  TIM16_BASE                                0x40014400                                       /*!<Base Address: 0x40014400*/
#define  TIM17_BASE                                0x40014800                                       /*!<Base Address: 0x40014800*/

/**
  * @brief TIM Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                            /*!<TIM Control Register 1                         offset: 0x00       */
    __IO uint32_t CR2;                            /*!<TIM Control Register 2                         offset: 0x04       */
    __IO uint32_t SMCR;                           /*!<TIM Slave Mode Control Register                offset: 0x08       */
    __IO uint32_t DIER;                           /*!<TIM DMA/Interrupt Enable Register (DMA is      offset: 0x0C
                                                      only suitable for the chip with built in DMA)                     */
    __IO uint32_t SR;                             /*!<TIM Status Register                            offset: 0x10       */
    __IO uint32_t EGR;                            /*!<TIM Event Generation Register                  offset: 0x14       */
    __IO uint32_t CCMR1;                          /*!<TIM Capture/Compare Mode Register 1            offset: 0x18       */
    __IO uint32_t CCMR2;                          /*!<TIM Capture/Compare Mode Register 2            offset: 0x1C       */
    __IO uint32_t CCER;                           /*!<TIM Capture/Compare Enable Register            offset: 0x20       */
    __IO uint32_t CNT;                            /*!<TIM Counter                                    offset: 0x24       */
    __IO uint32_t PSC;                            /*!<TIM Prescaler                                  offset: 0x28       */
    __IO uint32_t ARR;                            /*!<TIM Auto Reload Register                       offset: 0x2C       */
    __IO uint32_t RCR;                            /*!<TIM Repeat Count Register                      offset: 0x30       */
    __IO uint32_t CCR1;                           /*!<TIM Capture/Compare Register 1                 offset: 0x34       */
    __IO uint32_t CCR2;                           /*!<TIM Capture/Compare Register 2                 offset: 0x38       */
    __IO uint32_t CCR3;                           /*!<TIM Capture/Compare Register 3                 offset: 0x3C       */
    __IO uint32_t CCR4;                           /*!<TIM Capture/Compare Register 4                 offset: 0x40       */
    __IO uint32_t BDTR;                           /*!<TIM Break And Dead-Time Register               offset: 0x44       */
    __IO uint32_t DCR;                            /*!<TIM DMA Control Register (only suitable for    offset: 0x48
                                                      the chip with built in DMA)                                       */
    __IO uint32_t DMAR;                           /*!<TIM DMA Address Register Of Continuous Mode    offset: 0x4C
                                                      (only suitable for the chip with built in     
                                                      DMA)                                                              */
    __IO uint32_t OR;                             /*!<TIM Input Option Register                      offset: 0x50       */
    __IO uint32_t CCMR3;                          /*!<TIM Input Option Register                      offset: 0x54       */
    __IO uint32_t CCR5;                           /*!<TIM Compare Register 5                         offset: 0x58       */
    __IO uint32_t PDER;                           /*!<TIM PWM Phase Shift/DMA Repeat Update Request  offset: 0x5C
                                                      Enable Register                                                   */
    __IO uint32_t CCR1EXT;                        /*!<TIM PWM Phase Shift Count Down                 offset: 0x60
                                                      Capture/Compare Register                                          */
    __IO uint32_t CCR2EXT;                        /*!<TIM PWM Phase Shift Count Down                 offset: 0x64
                                                      Capture/Compare Register                                          */
    __IO uint32_t CCR3EXT;                        /*!<TIM PWM Phase Shift Count Down                 offset: 0x68
                                                      Capture/Compare Register                                          */
    __IO uint32_t CCR4EXT;                        /*!<TIM PWM Phase Shift Count Down                 offset: 0x6C
                                                      Capture/Compare Register                                          */
    __IO uint32_t CCR5EXT;                        /*!<TIM PWM Phase Shift Count Down                 offset: 0x70
                                                      Capture/Compare Register                                          */
    __IO uint32_t BKINF;                          /*!<TIM Break Input Filter Register                offset: 0x74       */
    __IO uint32_t CCR6;                           /*!<TIM Capture/Compare Register 6                 offset: 0x78       */
    __IO uint32_t CCR6EXT;                        /*!<TIM PWM Phase Shift Count Down                 offset: 0x7C
                                                      Capture/Compare Register 6                                        */
    __IO uint32_t DOCR;                           /*!<TIM Debug Output Control Register              offset: 0x80       */
    __IO uint32_t SOER;                           /*!<TIM Software Input Setting Master Enable       offset: 0x84
                                                      Register                                                          */
    __IO uint32_t SOCR;                           /*!<TIM Software Input Enable / Output Value       offset: 0x88
                                                      Register                                                          */
    __IO uint32_t BKSR;                           /*!<TIM Brake Input Status Control Register​       offset: 0x8C       */
} TIM_TypeDef;

/**
  * @brief TIM type pointer Definition
  */
#define TIM2                                      ((TIM_TypeDef *)TIM2_BASE)
#define TIM1                                      ((TIM_TypeDef *)TIM1_BASE)
#define TIM14                                     ((TIM_TypeDef *)TIM14_BASE)
#define TIM16                                     ((TIM_TypeDef *)TIM16_BASE)
#define TIM17                                     ((TIM_TypeDef *)TIM17_BASE)

/**
  * @brief TIM_CR1 Register Bit Definition
  */
#define  TIM_CR1_CEN_Pos                          (0)
#define  TIM_CR1_CEN_Msk                          (0x1U << TIM_CR1_CEN_Pos)                         /*!<Counter enable*/
#define  TIM_CR1_CEN                              TIM_CR1_CEN_Msk
#define  TIM_CR1_UDIS_Pos                         (1)
#define  TIM_CR1_UDIS_Msk                         (0x1U << TIM_CR1_UDIS_Pos)                        /*!<Update disable*/
#define  TIM_CR1_UDIS                             TIM_CR1_UDIS_Msk
#define  TIM_CR1_URS_Pos                          (2)
#define  TIM_CR1_URS_Msk                          (0x1U << TIM_CR1_URS_Pos)                         /*!<Update request source*/
#define  TIM_CR1_URS                              TIM_CR1_URS_Msk
#define  TIM_CR1_OPM_Pos                          (3)
#define  TIM_CR1_OPM_Msk                          (0x1U << TIM_CR1_OPM_Pos)                         /*!<one-pulse mode*/
#define  TIM_CR1_OPM                              TIM_CR1_OPM_Msk
#define  TIM_CR1_DIR_Pos                          (4)
#define  TIM_CR1_DIR_Msk                          (0x1U << TIM_CR1_DIR_Pos)                         /*!<Count direction*/
#define  TIM_CR1_DIR                              TIM_CR1_DIR_Msk
#define  TIM_CR1_CMS_Pos                          (5)
#define  TIM_CR1_CMS_Msk                          (0x3U << TIM_CR1_CMS_Pos)                         /*!<Center alignment mode selection*/
#define  TIM_CR1_CMS                              TIM_CR1_CMS_Msk
#define  TIM_CR1_CMS_Bit0                         (0x1U << TIM_CR1_CMS_Pos) 
#define  TIM_CR1_CMS_Bit1                         (0x2U << TIM_CR1_CMS_Pos) 
#define  TIM_CR1_ARPE_Pos                         (7)
#define  TIM_CR1_ARPE_Msk                         (0x1U << TIM_CR1_ARPE_Pos)                        /*!<Auto reload preload enable*/
#define  TIM_CR1_ARPE                             TIM_CR1_ARPE_Msk
#define  TIM_CR1_CKD_Pos                          (8)
#define  TIM_CR1_CKD_Msk                          (0x3U << TIM_CR1_CKD_Pos)                         /*!<Clock division*/
#define  TIM_CR1_CKD                              TIM_CR1_CKD_Msk
#define  TIM_CR1_CKD_Bit0                         (0x1U << TIM_CR1_CKD_Pos) 
#define  TIM_CR1_CKD_Bit1                         (0x2U << TIM_CR1_CKD_Pos) 
#define  TIM_CR1_RMC_Pos                          (10)
#define  TIM_CR1_RMC_Msk                          (0x3U << TIM_CR1_RMC_Pos)                         /*!<Reset Mode Control*/
#define  TIM_CR1_RMC                              TIM_CR1_RMC_Msk
#define  TIM_CR1_RMC_Bit0                         (0x1U << TIM_CR1_RMC_Pos) 
#define  TIM_CR1_RMC_Bit1                         (0x2U << TIM_CR1_RMC_Pos) 

/**
  * @brief TIM_CR2 Register Bit Definition
  */
#define  TIM_CR2_CCPC_Pos                         (0)
#define  TIM_CR2_CCPC_Msk                         (0x1U << TIM_CR2_CCPC_Pos)                        /*!<Compare preloaded control bit*/
#define  TIM_CR2_CCPC                             TIM_CR2_CCPC_Msk
#define  TIM_CR2_CCUS_Pos                         (2)
#define  TIM_CR2_CCUS_Msk                         (0x1U << TIM_CR2_CCUS_Pos)                        /*!<Capture/compare control update selection*/
#define  TIM_CR2_CCUS                             TIM_CR2_CCUS_Msk
#define  TIM_CR2_CCDS_Pos                         (3)
#define  TIM_CR2_CCDS_Msk                         (0x1U << TIM_CR2_CCDS_Pos)                        /*!<DMA request source selection*/
#define  TIM_CR2_CCDS                             TIM_CR2_CCDS_Msk
#define  TIM_CR2_MMS_Pos                          (4)
#define  TIM_CR2_MMS_Msk                          (0x7U << TIM_CR2_MMS_Pos)                         /*!<Master mode selection*/
#define  TIM_CR2_MMS                              TIM_CR2_MMS_Msk
#define  TIM_CR2_MMS_Bit0                         (0x1U << TIM_CR2_MMS_Pos) 
#define  TIM_CR2_MMS_Bit1                         (0x2U << TIM_CR2_MMS_Pos) 
#define  TIM_CR2_MMS_Bit2                         (0x4U << TIM_CR2_MMS_Pos) 
#define  TIM_CR2_TI1S_Pos                         (7)
#define  TIM_CR2_TI1S_Msk                         (0x1U << TIM_CR2_TI1S_Pos)                        /*!<TI1 selection*/
#define  TIM_CR2_TI1S                             TIM_CR2_TI1S_Msk
#define  TIM_CR2_OIS1_Pos                         (8)
#define  TIM_CR2_OIS1_Msk                         (0x1U << TIM_CR2_OIS1_Pos)                        /*!<(Output idle state 1) (OC1 output)*/
#define  TIM_CR2_OIS1                             TIM_CR2_OIS1_Msk
#define  TIM_CR2_OIS1N_Pos                        (9)
#define  TIM_CR2_OIS1N_Msk                        (0x1U << TIM_CR2_OIS1N_Pos)                       /*!<(Output idle state 1) (OC1N output)*/
#define  TIM_CR2_OIS1N                            TIM_CR2_OIS1N_Msk
#define  TIM_CR2_OIS2_Pos                         (10)
#define  TIM_CR2_OIS2_Msk                         (0x1U << TIM_CR2_OIS2_Pos)                        /*!<Output idle state 2 (OC2 output). Refer to OIS1 bit.*/
#define  TIM_CR2_OIS2                             TIM_CR2_OIS2_Msk
#define  TIM_CR2_OIS2N_Pos                        (11)
#define  TIM_CR2_OIS2N_Msk                        (0x1U << TIM_CR2_OIS2N_Pos)                       /*!<Output idle state 2 (OC2N output). Refer to OIS1N bit.*/
#define  TIM_CR2_OIS2N                            TIM_CR2_OIS2N_Msk
#define  TIM_CR2_OIS3_Pos                         (12)
#define  TIM_CR2_OIS3_Msk                         (0x1U << TIM_CR2_OIS3_Pos)                        /*!<Output idle state 3 (OC3 output). Refer to OIS1 bit.*/
#define  TIM_CR2_OIS3                             TIM_CR2_OIS3_Msk
#define  TIM_CR2_OIS3N_Pos                        (13)
#define  TIM_CR2_OIS3N_Msk                        (0x1U << TIM_CR2_OIS3N_Pos)                       /*!<Output idle state 3 (OC3N output). Refer to OIS1N bit.*/
#define  TIM_CR2_OIS3N                            TIM_CR2_OIS3N_Msk
#define  TIM_CR2_OIS4_Pos                         (14)
#define  TIM_CR2_OIS4_Msk                         (0x1U << TIM_CR2_OIS4_Pos)                        /*!<Output idle state 4 (OC4 output). Refer to OIS1 bit.*/
#define  TIM_CR2_OIS4                             TIM_CR2_OIS4_Msk
#define  TIM_CR2_OIS4N_Pos                        (15)
#define  TIM_CR2_OIS4N_Msk                        (0x1U << TIM_CR2_OIS4N_Pos)                       /*!<Output idle state 4 (OC4N output). Refer to OIS1N bit.*/
#define  TIM_CR2_OIS4N                            TIM_CR2_OIS4N_Msk

/**
  * @brief TIM_SMCR Register Bit Definition
  */
#define  TIM_SMCR_SMS_Pos                         (0)
#define  TIM_SMCR_SMS_Msk                         (0x7U << TIM_SMCR_SMS_Pos)                        /*!<Slave mode selection*/
#define  TIM_SMCR_SMS                             TIM_SMCR_SMS_Msk
#define  TIM_SMCR_SMS_Bit0                        (0x1U << TIM_SMCR_SMS_Pos) 
#define  TIM_SMCR_SMS_Bit1                        (0x2U << TIM_SMCR_SMS_Pos) 
#define  TIM_SMCR_SMS_Bit2                        (0x4U << TIM_SMCR_SMS_Pos) 
#define  TIM_SMCR_OCCS_Pos                        (3)
#define  TIM_SMCR_OCCS_Msk                        (0x1U << TIM_SMCR_OCCS_Pos)                       /*!<Timer compare output signal(OCxREF) clear selection*/
#define  TIM_SMCR_OCCS                            TIM_SMCR_OCCS_Msk
#define  TIM_SMCR_TS_L_Pos                        (4)
#define  TIM_SMCR_TS_L_Msk                        (0x7U << TIM_SMCR_TS_L_Pos)                       /*!<Trigger selection*/
#define  TIM_SMCR_TS_L                            TIM_SMCR_TS_L_Msk
#define  TIM_SMCR_TS_L_Bit0                       (0x1U << TIM_SMCR_TS_L_Pos) 
#define  TIM_SMCR_TS_L_Bit1                       (0x2U << TIM_SMCR_TS_L_Pos) 
#define  TIM_SMCR_TS_L_Bit2                       (0x4U << TIM_SMCR_TS_L_Pos) 
#define  TIM_SMCR_MSM_Pos                         (7)
#define  TIM_SMCR_MSM_Msk                         (0x1U << TIM_SMCR_MSM_Pos)                        /*!<Master/slave mode*/
#define  TIM_SMCR_MSM                             TIM_SMCR_MSM_Msk
#define  TIM_SMCR_ETF_Pos                         (8)
#define  TIM_SMCR_ETF_Msk                         (0xFU << TIM_SMCR_ETF_Pos)                        /*!<External trigger filter*/
#define  TIM_SMCR_ETF                             TIM_SMCR_ETF_Msk
#define  TIM_SMCR_ETF_Bit0                        (0x1U << TIM_SMCR_ETF_Pos) 
#define  TIM_SMCR_ETF_Bit1                        (0x2U << TIM_SMCR_ETF_Pos) 
#define  TIM_SMCR_ETF_Bit2                        (0x4U << TIM_SMCR_ETF_Pos) 
#define  TIM_SMCR_ETF_Bit3                        (0x8U << TIM_SMCR_ETF_Pos) 
#define  TIM_SMCR_ETPS_Pos                        (12)
#define  TIM_SMCR_ETPS_Msk                        (0x3U << TIM_SMCR_ETPS_Pos)                       /*!<External trigger prescaler*/
#define  TIM_SMCR_ETPS                            TIM_SMCR_ETPS_Msk
#define  TIM_SMCR_ETPS_Bit0                       (0x1U << TIM_SMCR_ETPS_Pos) 
#define  TIM_SMCR_ETPS_Bit1                       (0x2U << TIM_SMCR_ETPS_Pos) 
#define  TIM_SMCR_ECE_Pos                         (14)
#define  TIM_SMCR_ECE_Msk                         (0x1U << TIM_SMCR_ECE_Pos)                        /*!<External clock enable*/
#define  TIM_SMCR_ECE                             TIM_SMCR_ECE_Msk
#define  TIM_SMCR_ETP_Pos                         (15)
#define  TIM_SMCR_ETP_Msk                         (0x1U << TIM_SMCR_ETP_Pos)                        /*!<External trigger polarity*/
#define  TIM_SMCR_ETP                             TIM_SMCR_ETP_Msk
#define  TIM_SMCR_TS_H_Pos                        (20)
#define  TIM_SMCR_TS_H_Msk                        (0x3U << TIM_SMCR_TS_H_Pos)                       /*!<Trigger selection*/
#define  TIM_SMCR_TS_H                            TIM_SMCR_TS_H_Msk
#define  TIM_SMCR_TS_H_Bit0                       (0x1U << TIM_SMCR_TS_H_Pos) 
#define  TIM_SMCR_TS_H_Bit1                       (0x2U << TIM_SMCR_TS_H_Pos) 

/**
  * @brief TIM_DIER Register Bit Definition
  */
#define  TIM_DIER_UIE_Pos                         (0)
#define  TIM_DIER_UIE_Msk                         (0x1U << TIM_DIER_UIE_Pos)                        /*!<Enable update interrupt*/
#define  TIM_DIER_UIE                             TIM_DIER_UIE_Msk
#define  TIM_DIER_CC1IE_Pos                       (1)
#define  TIM_DIER_CC1IE_Msk                       (0x1U << TIM_DIER_CC1IE_Pos)                      /*!<Enable capture/compare 1 interrupt*/
#define  TIM_DIER_CC1IE                           TIM_DIER_CC1IE_Msk
#define  TIM_DIER_CC2IE_Pos                       (2)
#define  TIM_DIER_CC2IE_Msk                       (0x1U << TIM_DIER_CC2IE_Pos)                      /*!<Enable capture/compare 2 interrupt*/
#define  TIM_DIER_CC2IE                           TIM_DIER_CC2IE_Msk
#define  TIM_DIER_CC3IE_Pos                       (3)
#define  TIM_DIER_CC3IE_Msk                       (0x1U << TIM_DIER_CC3IE_Pos)                      /*!<Enable capture/compare 3 interrupt*/
#define  TIM_DIER_CC3IE                           TIM_DIER_CC3IE_Msk
#define  TIM_DIER_CC4IE_Pos                       (4)
#define  TIM_DIER_CC4IE_Msk                       (0x1U << TIM_DIER_CC4IE_Pos)                      /*!<Enable capture/compare 4 interrupt*/
#define  TIM_DIER_CC4IE                           TIM_DIER_CC4IE_Msk
#define  TIM_DIER_COMIE_Pos                       (5)
#define  TIM_DIER_COMIE_Msk                       (0x1U << TIM_DIER_COMIE_Pos)                      /*!<Enable COM interrupt*/
#define  TIM_DIER_COMIE                           TIM_DIER_COMIE_Msk
#define  TIM_DIER_TIE_Pos                         (6)
#define  TIM_DIER_TIE_Msk                         (0x1U << TIM_DIER_TIE_Pos)                        /*!<Trigger interrupt enable*/
#define  TIM_DIER_TIE                             TIM_DIER_TIE_Msk
#define  TIM_DIER_BIE_Pos                         (7)
#define  TIM_DIER_BIE_Msk                         (0x1U << TIM_DIER_BIE_Pos)                        /*!<Break interrupt enable*/
#define  TIM_DIER_BIE                             TIM_DIER_BIE_Msk
#define  TIM_DIER_UDE_Pos                         (8)
#define  TIM_DIER_UDE_Msk                         (0x1U << TIM_DIER_UDE_Pos)                        /*!<Update DMA request enable*/
#define  TIM_DIER_UDE                             TIM_DIER_UDE_Msk
#define  TIM_DIER_CC1DE_Pos                       (9)
#define  TIM_DIER_CC1DE_Msk                       (0x1U << TIM_DIER_CC1DE_Pos)                      /*!<Capture/compare 1 DMA request enable*/
#define  TIM_DIER_CC1DE                           TIM_DIER_CC1DE_Msk
#define  TIM_DIER_CC2DE_Pos                       (10)
#define  TIM_DIER_CC2DE_Msk                       (0x1U << TIM_DIER_CC2DE_Pos)                      /*!<Capture/Compare 2 DMA request enable*/
#define  TIM_DIER_CC2DE                           TIM_DIER_CC2DE_Msk
#define  TIM_DIER_CC3DE_Pos                       (11)
#define  TIM_DIER_CC3DE_Msk                       (0x1U << TIM_DIER_CC3DE_Pos)                      /*!<Capture/compare 3 DMA request enable*/
#define  TIM_DIER_CC3DE                           TIM_DIER_CC3DE_Msk
#define  TIM_DIER_CC4DE_Pos                       (12)
#define  TIM_DIER_CC4DE_Msk                       (0x1U << TIM_DIER_CC4DE_Pos)                      /*!<Capture/compare 4 DMA request enable*/
#define  TIM_DIER_CC4DE                           TIM_DIER_CC4DE_Msk
#define  TIM_DIER_COMDE_Pos                       (13)
#define  TIM_DIER_COMDE_Msk                       (0x1U << TIM_DIER_COMDE_Pos)                      /*!<COM DMA request enable*/
#define  TIM_DIER_COMDE                           TIM_DIER_COMDE_Msk
#define  TIM_DIER_TDE_Pos                         (14)
#define  TIM_DIER_TDE_Msk                         (0x1U << TIM_DIER_TDE_Pos)                        /*!<Trigger DMA request enable*/
#define  TIM_DIER_TDE                             TIM_DIER_TDE_Msk
#define  TIM_DIER_CC5IE_Pos                       (16)
#define  TIM_DIER_CC5IE_Msk                       (0x1U << TIM_DIER_CC5IE_Pos)                      /*!<Compare 5 interrupt enable*/
#define  TIM_DIER_CC5IE                           TIM_DIER_CC5IE_Msk
#define  TIM_DIER_CC5DE_Pos                       (17)
#define  TIM_DIER_CC5DE_Msk                       (0x1U << TIM_DIER_CC5DE_Pos)                      /*!<Compare 5 DMA request enable*/
#define  TIM_DIER_CC5DE                           TIM_DIER_CC5DE_Msk
#define  TIM_DIER_CC6IE_Pos                       (18)
#define  TIM_DIER_CC6IE_Msk                       (0x1U << TIM_DIER_CC6IE_Pos)                      /*!<Compare 6 interrupt enable*/
#define  TIM_DIER_CC6IE                           TIM_DIER_CC6IE_Msk
#define  TIM_DIER_CC6DE_Pos                       (19)
#define  TIM_DIER_CC6DE_Msk                       (0x1U << TIM_DIER_CC6DE_Pos)                      /*!<Compare 6 DMA request enable*/
#define  TIM_DIER_CC6DE                           TIM_DIER_CC6DE_Msk

/**
  * @brief TIM_SR Register Bit Definition
  */
#define  TIM_SR_UIF_Pos                           (0)
#define  TIM_SR_UIF_Msk                           (0x1U << TIM_SR_UIF_Pos)                          /*!<Update interrupt flag*/
#define  TIM_SR_UIF                               TIM_SR_UIF_Msk
#define  TIM_SR_CC1IF_Pos                         (1)
#define  TIM_SR_CC1IF_Msk                         (0x1U << TIM_SR_CC1IF_Pos)                        /*!<Capture/compare 1 interrupt flag*/
#define  TIM_SR_CC1IF                             TIM_SR_CC1IF_Msk
#define  TIM_SR_CC2IF_Pos                         (2)
#define  TIM_SR_CC2IF_Msk                         (0x1U << TIM_SR_CC2IF_Pos)                        /*!<Capture/compare 2 interrupt flag*/
#define  TIM_SR_CC2IF                             TIM_SR_CC2IF_Msk
#define  TIM_SR_CC3IF_Pos                         (3)
#define  TIM_SR_CC3IF_Msk                         (0x1U << TIM_SR_CC3IF_Pos)                        /*!<Capture/compare 3 interrupt flag*/
#define  TIM_SR_CC3IF                             TIM_SR_CC3IF_Msk
#define  TIM_SR_CC4IF_Pos                         (4)
#define  TIM_SR_CC4IF_Msk                         (0x1U << TIM_SR_CC4IF_Pos)                        /*!<Capture/compare 4 interrupt flag*/
#define  TIM_SR_CC4IF                             TIM_SR_CC4IF_Msk
#define  TIM_SR_COMIF_Pos                         (5)
#define  TIM_SR_COMIF_Msk                         (0x1U << TIM_SR_COMIF_Pos)                        /*!<COM interrupt flag*/
#define  TIM_SR_COMIF                             TIM_SR_COMIF_Msk
#define  TIM_SR_TIF_Pos                           (6)
#define  TIM_SR_TIF_Msk                           (0x1U << TIM_SR_TIF_Pos)                          /*!<Trigger interrupt flag*/
#define  TIM_SR_TIF                               TIM_SR_TIF_Msk
#define  TIM_SR_BIF_Pos                           (7)
#define  TIM_SR_BIF_Msk                           (0x1U << TIM_SR_BIF_Pos)                          /*!<Break interrupt flag*/
#define  TIM_SR_BIF                               TIM_SR_BIF_Msk
#define  TIM_SR_CC1OF_Pos                         (9)
#define  TIM_SR_CC1OF_Msk                         (0x1U << TIM_SR_CC1OF_Pos)                        /*!<Capture/compare 1 over capture flag*/
#define  TIM_SR_CC1OF                             TIM_SR_CC1OF_Msk
#define  TIM_SR_CC2OF_Pos                         (10)
#define  TIM_SR_CC2OF_Msk                         (0x1U << TIM_SR_CC2OF_Pos)                        /*!<Capture/compare 2 over capture flag*/
#define  TIM_SR_CC2OF                             TIM_SR_CC2OF_Msk
#define  TIM_SR_CC3OF_Pos                         (11)
#define  TIM_SR_CC3OF_Msk                         (0x1U << TIM_SR_CC3OF_Pos)                        /*!<Capture/compare 3 over capture flag*/
#define  TIM_SR_CC3OF                             TIM_SR_CC3OF_Msk
#define  TIM_SR_CC4OF_Pos                         (12)
#define  TIM_SR_CC4OF_Msk                         (0x1U << TIM_SR_CC4OF_Pos)                        /*!<Capture/compare 4 over capture flag*/
#define  TIM_SR_CC4OF                             TIM_SR_CC4OF_Msk
#define  TIM_SR_CC5IF_Pos                         (16)
#define  TIM_SR_CC5IF_Msk                         (0x1U << TIM_SR_CC5IF_Pos)                        /*!<Compare 5 interrupt flag*/
#define  TIM_SR_CC5IF                             TIM_SR_CC5IF_Msk
#define  TIM_SR_CC6IF_Pos                         (18)
#define  TIM_SR_CC6IF_Msk                         (0x1U << TIM_SR_CC6IF_Pos)                        /*!<Compare 6 interrupt flag*/
#define  TIM_SR_CC6IF                             TIM_SR_CC6IF_Msk

/**
  * @brief TIM_EGR Register Bit Definition
  */
#define  TIM_EGR_UG_Pos                           (0)
#define  TIM_EGR_UG_Msk                           (0x1U << TIM_EGR_UG_Pos)                          /*!<Update event generation*/
#define  TIM_EGR_UG                               TIM_EGR_UG_Msk
#define  TIM_EGR_CC1G_Pos                         (1)
#define  TIM_EGR_CC1G_Msk                         (0x1U << TIM_EGR_CC1G_Pos)                        /*!<Capture/compare 1 generation*/
#define  TIM_EGR_CC1G                             TIM_EGR_CC1G_Msk
#define  TIM_EGR_CC2G_Pos                         (2)
#define  TIM_EGR_CC2G_Msk                         (0x1U << TIM_EGR_CC2G_Pos)                        /*!<Capture/compare 2 generation*/
#define  TIM_EGR_CC2G                             TIM_EGR_CC2G_Msk
#define  TIM_EGR_CC3G_Pos                         (3)
#define  TIM_EGR_CC3G_Msk                         (0x1U << TIM_EGR_CC3G_Pos)                        /*!<Capture/compare 3 generation*/
#define  TIM_EGR_CC3G                             TIM_EGR_CC3G_Msk
#define  TIM_EGR_CC4G_Pos                         (4)
#define  TIM_EGR_CC4G_Msk                         (0x1U << TIM_EGR_CC4G_Pos)                        /*!<Capture/compare 4 generation*/
#define  TIM_EGR_CC4G                             TIM_EGR_CC4G_Msk
#define  TIM_EGR_COMG_Pos                         (5)
#define  TIM_EGR_COMG_Msk                         (0x1U << TIM_EGR_COMG_Pos)                        /*!<Compare control update generation*/
#define  TIM_EGR_COMG                             TIM_EGR_COMG_Msk
#define  TIM_EGR_TG_Pos                           (6)
#define  TIM_EGR_TG_Msk                           (0x1U << TIM_EGR_TG_Pos)                          /*!<Trigger generation*/
#define  TIM_EGR_TG                               TIM_EGR_TG_Msk
#define  TIM_EGR_BG_Pos                           (7)
#define  TIM_EGR_BG_Msk                           (0x1U << TIM_EGR_BG_Pos)                          /*!<Break generation*/
#define  TIM_EGR_BG                               TIM_EGR_BG_Msk
#define  TIM_EGR_CC5G_Pos                         (16)
#define  TIM_EGR_CC5G_Msk                         (0x1U << TIM_EGR_CC5G_Pos)                        /*!<Compare 5 generation*/
#define  TIM_EGR_CC5G                             TIM_EGR_CC5G_Msk
#define  TIM_EGR_CC6G_Pos                         (17)
#define  TIM_EGR_CC6G_Msk                         (0x1U << TIM_EGR_CC6G_Pos)                        /*!<Compare 6 generation*/
#define  TIM_EGR_CC6G                             TIM_EGR_CC6G_Msk

/**
  * @brief TIM_CCMR1 Register Bit Definition
  */

/* CCMR1 */
#define  TIM_CCMR1_CC1S_Pos                       (0)
#define  TIM_CCMR1_CC1S_Msk                       (0x3U << TIM_CCMR1_CC1S_Pos)                      /*!<Channel 1 capture/compare selection*/
#define  TIM_CCMR1_CC1S                           TIM_CCMR1_CC1S_Msk
#define  TIM_CCMR1_CC1S_Bit0                      (0x1U << TIM_CCMR1_CC1S_Pos) 
#define  TIM_CCMR1_CC1S_Bit1                      (0x2U << TIM_CCMR1_CC1S_Pos) 
#define  TIM_CCMR1_OC1FE_Pos                      (2)
#define  TIM_CCMR1_OC1FE_Msk                      (0x1U << TIM_CCMR1_OC1FE_Pos)                     /*!<Channel 1 output compare quick enable*/
#define  TIM_CCMR1_OC1FE                          TIM_CCMR1_OC1FE_Msk
#define  TIM_CCMR1_IC1PSC_Pos                     (2)
#define  TIM_CCMR1_IC1PSC_Msk                     (0x3U << TIM_CCMR1_IC1PSC_Pos)                    /*!<Channel 1 input/capture prescaler*/
#define  TIM_CCMR1_IC1PSC                         TIM_CCMR1_IC1PSC_Msk
#define  TIM_CCMR1_IC1PSC_Bit0                    (0x1U << TIM_CCMR1_IC1PSC_Pos) 
#define  TIM_CCMR1_IC1PSC_Bit1                    (0x2U << TIM_CCMR1_IC1PSC_Pos) 
#define  TIM_CCMR1_OC1PE_Pos                      (3)
#define  TIM_CCMR1_OC1PE_Msk                      (0x1U << TIM_CCMR1_OC1PE_Pos)                     /*!<Channel 1 output compare preload enable*/
#define  TIM_CCMR1_OC1PE                          TIM_CCMR1_OC1PE_Msk
#define  TIM_CCMR1_OC1M_Pos                       (4)
#define  TIM_CCMR1_OC1M_Msk                       (0x7U << TIM_CCMR1_OC1M_Pos)                      /*!<Channel 1 output compare mode*/
#define  TIM_CCMR1_OC1M                           TIM_CCMR1_OC1M_Msk
#define  TIM_CCMR1_OC1M_Bit0                      (0x1U << TIM_CCMR1_OC1M_Pos) 
#define  TIM_CCMR1_OC1M_Bit1                      (0x2U << TIM_CCMR1_OC1M_Pos) 
#define  TIM_CCMR1_OC1M_Bit2                      (0x4U << TIM_CCMR1_OC1M_Pos) 
#define  TIM_CCMR1_IC1F_Pos                       (4)
#define  TIM_CCMR1_IC1F_Msk                       (0xFU << TIM_CCMR1_IC1F_Pos)                      /*!<Channel 1 input capture filter*/
#define  TIM_CCMR1_IC1F                           TIM_CCMR1_IC1F_Msk
#define  TIM_CCMR1_IC1F_Bit0                      (0x1U << TIM_CCMR1_IC1F_Pos) 
#define  TIM_CCMR1_IC1F_Bit1                      (0x2U << TIM_CCMR1_IC1F_Pos) 
#define  TIM_CCMR1_IC1F_Bit2                      (0x4U << TIM_CCMR1_IC1F_Pos) 
#define  TIM_CCMR1_IC1F_Bit3                      (0x8U << TIM_CCMR1_IC1F_Pos) 
#define  TIM_CCMR1_OC1CE_Pos                      (7)
#define  TIM_CCMR1_OC1CE_Msk                      (0x1U << TIM_CCMR1_OC1CE_Pos)                     /*!<Channel 1 capture/compare clear enable*/
#define  TIM_CCMR1_OC1CE                          TIM_CCMR1_OC1CE_Msk
#define  TIM_CCMR1_CC2S_Pos                       (8)
#define  TIM_CCMR1_CC2S_Msk                       (0x3U << TIM_CCMR1_CC2S_Pos)                      /*!<Channel 2 capture/compare 2 selection*/
#define  TIM_CCMR1_CC2S                           TIM_CCMR1_CC2S_Msk
#define  TIM_CCMR1_CC2S_Bit0                      (0x1U << TIM_CCMR1_CC2S_Pos) 
#define  TIM_CCMR1_CC2S_Bit1                      (0x2U << TIM_CCMR1_CC2S_Pos) 
#define  TIM_CCMR1_OC2FE_Pos                      (10)
#define  TIM_CCMR1_OC2FE_Msk                      (0x1U << TIM_CCMR1_OC2FE_Pos)                     /*!<Channel 2 output and compare quick enable*/
#define  TIM_CCMR1_OC2FE                          TIM_CCMR1_OC2FE_Msk
#define  TIM_CCMR1_IC2PSC_Pos                     (10)
#define  TIM_CCMR1_IC2PSC_Msk                     (0x3U << TIM_CCMR1_IC2PSC_Pos)                    /*!<Input/capture 2 prescaler*/
#define  TIM_CCMR1_IC2PSC                         TIM_CCMR1_IC2PSC_Msk
#define  TIM_CCMR1_IC2PSC_Bit0                    (0x1U << TIM_CCMR1_IC2PSC_Pos) 
#define  TIM_CCMR1_IC2PSC_Bit1                    (0x2U << TIM_CCMR1_IC2PSC_Pos) 
#define  TIM_CCMR1_OC2PE_Pos                      (11)
#define  TIM_CCMR1_OC2PE_Msk                      (0x1U << TIM_CCMR1_OC2PE_Pos)                     /*!<Channel 2 output and compare preload enable*/
#define  TIM_CCMR1_OC2PE                          TIM_CCMR1_OC2PE_Msk
#define  TIM_CCMR1_OC2M_Pos                       (12)
#define  TIM_CCMR1_OC2M_Msk                       (0x7U << TIM_CCMR1_OC2M_Pos)                      /*!<Channel 2 output and compare mode*/
#define  TIM_CCMR1_OC2M                           TIM_CCMR1_OC2M_Msk
#define  TIM_CCMR1_OC2M_Bit0                      (0x1U << TIM_CCMR1_OC2M_Pos) 
#define  TIM_CCMR1_OC2M_Bit1                      (0x2U << TIM_CCMR1_OC2M_Pos) 
#define  TIM_CCMR1_OC2M_Bit2                      (0x4U << TIM_CCMR1_OC2M_Pos) 
#define  TIM_CCMR1_IC2F_Pos                       (12)
#define  TIM_CCMR1_IC2F_Msk                       (0xFU << TIM_CCMR1_IC2F_Pos)                      /*!<Input capture 2 filter*/
#define  TIM_CCMR1_IC2F                           TIM_CCMR1_IC2F_Msk
#define  TIM_CCMR1_IC2F_Bit0                      (0x1U << TIM_CCMR1_IC2F_Pos) 
#define  TIM_CCMR1_IC2F_Bit1                      (0x2U << TIM_CCMR1_IC2F_Pos) 
#define  TIM_CCMR1_IC2F_Bit2                      (0x4U << TIM_CCMR1_IC2F_Pos) 
#define  TIM_CCMR1_IC2F_Bit3                      (0x8U << TIM_CCMR1_IC2F_Pos) 
#define  TIM_CCMR1_OC2CE_Pos                      (15)
#define  TIM_CCMR1_OC2CE_Msk                      (0x1U << TIM_CCMR1_OC2CE_Pos)                     /*!<Channel 2 output and compare clear enable*/
#define  TIM_CCMR1_OC2CE                          TIM_CCMR1_OC2CE_Msk

/**
  * @brief TIM_CCMR2 Register Bit Definition
  */

/* CCMR2 */
#define  TIM_CCMR2_CC3S_Pos                       (0)
#define  TIM_CCMR2_CC3S_Msk                       (0x3U << TIM_CCMR2_CC3S_Pos)                      /*!<Channel 3 capture/compare selection*/
#define  TIM_CCMR2_CC3S                           TIM_CCMR2_CC3S_Msk
#define  TIM_CCMR2_CC3S_Bit0                      (0x1U << TIM_CCMR2_CC3S_Pos) 
#define  TIM_CCMR2_CC3S_Bit1                      (0x2U << TIM_CCMR2_CC3S_Pos) 
#define  TIM_CCMR2_OC3FE_Pos                      (2)
#define  TIM_CCMR2_OC3FE_Msk                      (0x1U << TIM_CCMR2_OC3FE_Pos)                     /*!<Channel 3 output compare quick enable*/
#define  TIM_CCMR2_OC3FE                          TIM_CCMR2_OC3FE_Msk
#define  TIM_CCMR2_IC3PSC_Pos                     (2)
#define  TIM_CCMR2_IC3PSC_Msk                     (0x3U << TIM_CCMR2_IC3PSC_Pos)                    /*!<Channel 3 input/capture prescaler*/
#define  TIM_CCMR2_IC3PSC                         TIM_CCMR2_IC3PSC_Msk
#define  TIM_CCMR2_IC3PSC_Bit0                    (0x1U << TIM_CCMR2_IC3PSC_Pos) 
#define  TIM_CCMR2_IC3PSC_Bit1                    (0x2U << TIM_CCMR2_IC3PSC_Pos) 
#define  TIM_CCMR2_OC3PE_Pos                      (3)
#define  TIM_CCMR2_OC3PE_Msk                      (0x1U << TIM_CCMR2_OC3PE_Pos)                     /*!<Channel 3 output compare preload enable*/
#define  TIM_CCMR2_OC3PE                          TIM_CCMR2_OC3PE_Msk
#define  TIM_CCMR2_OC3M_Pos                       (4)
#define  TIM_CCMR2_OC3M_Msk                       (0x7U << TIM_CCMR2_OC3M_Pos)                      /*!<Channel 3 output compare mode*/
#define  TIM_CCMR2_OC3M                           TIM_CCMR2_OC3M_Msk
#define  TIM_CCMR2_OC3M_Bit0                      (0x1U << TIM_CCMR2_OC3M_Pos) 
#define  TIM_CCMR2_OC3M_Bit1                      (0x2U << TIM_CCMR2_OC3M_Pos) 
#define  TIM_CCMR2_OC3M_Bit2                      (0x4U << TIM_CCMR2_OC3M_Pos) 
#define  TIM_CCMR2_IC3F_Pos                       (4)
#define  TIM_CCMR2_IC3F_Msk                       (0xFU << TIM_CCMR2_IC3F_Pos)                      /*!<Channel 3 input capture filter*/
#define  TIM_CCMR2_IC3F                           TIM_CCMR2_IC3F_Msk
#define  TIM_CCMR2_IC3F_Bit0                      (0x1U << TIM_CCMR2_IC3F_Pos) 
#define  TIM_CCMR2_IC3F_Bit1                      (0x2U << TIM_CCMR2_IC3F_Pos) 
#define  TIM_CCMR2_IC3F_Bit2                      (0x4U << TIM_CCMR2_IC3F_Pos) 
#define  TIM_CCMR2_IC3F_Bit3                      (0x8U << TIM_CCMR2_IC3F_Pos) 
#define  TIM_CCMR2_OC3CE_Pos                      (7)
#define  TIM_CCMR2_OC3CE_Msk                      (0x1U << TIM_CCMR2_OC3CE_Pos)                     /*!<Channel 3 output compare clear enable*/
#define  TIM_CCMR2_OC3CE                          TIM_CCMR2_OC3CE_Msk
#define  TIM_CCMR2_CC4S_Pos                       (8)
#define  TIM_CCMR2_CC4S_Msk                       (0x3U << TIM_CCMR2_CC4S_Pos)                      /*!<Channel 4 capture/compare selection*/
#define  TIM_CCMR2_CC4S                           TIM_CCMR2_CC4S_Msk
#define  TIM_CCMR2_CC4S_Bit0                      (0x1U << TIM_CCMR2_CC4S_Pos) 
#define  TIM_CCMR2_CC4S_Bit1                      (0x2U << TIM_CCMR2_CC4S_Pos) 
#define  TIM_CCMR2_OC4FE_Pos                      (10)
#define  TIM_CCMR2_OC4FE_Msk                      (0x1U << TIM_CCMR2_OC4FE_Pos)                     /*!<Refer to OC3PE description*/
#define  TIM_CCMR2_OC4FE                          TIM_CCMR2_OC4FE_Msk
#define  TIM_CCMR2_IC4PSC_Pos                     (10)
#define  TIM_CCMR2_IC4PSC_Msk                     (0x3U << TIM_CCMR2_IC4PSC_Pos)                    /*!<Input/capture 4 prescaler*/
#define  TIM_CCMR2_IC4PSC                         TIM_CCMR2_IC4PSC_Msk
#define  TIM_CCMR2_IC4PSC_Bit0                    (0x1U << TIM_CCMR2_IC4PSC_Pos) 
#define  TIM_CCMR2_IC4PSC_Bit1                    (0x2U << TIM_CCMR2_IC4PSC_Pos) 
#define  TIM_CCMR2_OC4PE_Pos                      (11)
#define  TIM_CCMR2_OC4PE_Msk                      (0x1U << TIM_CCMR2_OC4PE_Pos)                     /*!<Channel 4 output compare preload enable*/
#define  TIM_CCMR2_OC4PE                          TIM_CCMR2_OC4PE_Msk
#define  TIM_CCMR2_OC4M_Pos                       (12)
#define  TIM_CCMR2_OC4M_Msk                       (0x7U << TIM_CCMR2_OC4M_Pos)                      /*!<Channel 4 output compare mode*/
#define  TIM_CCMR2_OC4M                           TIM_CCMR2_OC4M_Msk
#define  TIM_CCMR2_OC4M_Bit0                      (0x1U << TIM_CCMR2_OC4M_Pos) 
#define  TIM_CCMR2_OC4M_Bit1                      (0x2U << TIM_CCMR2_OC4M_Pos) 
#define  TIM_CCMR2_OC4M_Bit2                      (0x4U << TIM_CCMR2_OC4M_Pos) 
#define  TIM_CCMR2_IC4F_Pos                       (12)
#define  TIM_CCMR2_IC4F_Msk                       (0xFU << TIM_CCMR2_IC4F_Pos)                      /*!<Input capture 4 filter*/
#define  TIM_CCMR2_IC4F                           TIM_CCMR2_IC4F_Msk
#define  TIM_CCMR2_IC4F_Bit0                      (0x1U << TIM_CCMR2_IC4F_Pos) 
#define  TIM_CCMR2_IC4F_Bit1                      (0x2U << TIM_CCMR2_IC4F_Pos) 
#define  TIM_CCMR2_IC4F_Bit2                      (0x4U << TIM_CCMR2_IC4F_Pos) 
#define  TIM_CCMR2_IC4F_Bit3                      (0x8U << TIM_CCMR2_IC4F_Pos) 
#define  TIM_CCMR2_OC4CE_Pos                      (15)
#define  TIM_CCMR2_OC4CE_Msk                      (0x1U << TIM_CCMR2_OC4CE_Pos)                     /*!<Channel 4 output compare clear enable*/
#define  TIM_CCMR2_OC4CE                          TIM_CCMR2_OC4CE_Msk

/**
  * @brief TIM_CCER Register Bit Definition
  */
#define  TIM_CCER_CC1E_Pos                        (0)
#define  TIM_CCER_CC1E_Msk                        (0x1U << TIM_CCER_CC1E_Pos)                       /*!<Channel 1 input/capture output enable*/
#define  TIM_CCER_CC1E                            TIM_CCER_CC1E_Msk
#define  TIM_CCER_CC1P_Pos                        (1)
#define  TIM_CCER_CC1P_Msk                        (0x1U << TIM_CCER_CC1P_Pos)                       /*!<Channel 1 input/capture output polarity*/
#define  TIM_CCER_CC1P                            TIM_CCER_CC1P_Msk
#define  TIM_CCER_CC1NE_Pos                       (2)
#define  TIM_CCER_CC1NE_Msk                       (0x1U << TIM_CCER_CC1NE_Pos)                      /*!<Channel 1 complementary output enable*/
#define  TIM_CCER_CC1NE                           TIM_CCER_CC1NE_Msk
#define  TIM_CCER_CC1NP_Pos                       (3)
#define  TIM_CCER_CC1NP_Msk                       (0x1U << TIM_CCER_CC1NP_Pos)                      /*!<Channel 1 input/capture complementary output polarity*/
#define  TIM_CCER_CC1NP                           TIM_CCER_CC1NP_Msk
#define  TIM_CCER_CC2E_Pos                        (4)
#define  TIM_CCER_CC2E_Msk                        (0x1U << TIM_CCER_CC2E_Pos)                       /*!<Channel 2 input/capture output enable*/
#define  TIM_CCER_CC2E                            TIM_CCER_CC2E_Msk
#define  TIM_CCER_CC2P_Pos                        (5)
#define  TIM_CCER_CC2P_Msk                        (0x1U << TIM_CCER_CC2P_Pos)                       /*!<Channel 2 input capture output polarity*/
#define  TIM_CCER_CC2P                            TIM_CCER_CC2P_Msk
#define  TIM_CCER_CC2NE_Pos                       (6)
#define  TIM_CCER_CC2NE_Msk                       (0x1U << TIM_CCER_CC2NE_Pos)                      /*!<Channel 2 complementary output enable*/
#define  TIM_CCER_CC2NE                           TIM_CCER_CC2NE_Msk
#define  TIM_CCER_CC2NP_Pos                       (7)
#define  TIM_CCER_CC2NP_Msk                       (0x1U << TIM_CCER_CC2NP_Pos)                      /*!<Channel 2 input/capture complementary output polarity*/
#define  TIM_CCER_CC2NP                           TIM_CCER_CC2NP_Msk
#define  TIM_CCER_CC3E_Pos                        (8)
#define  TIM_CCER_CC3E_Msk                        (0x1U << TIM_CCER_CC3E_Pos)                       /*!<Channel 3 input/capture output enable*/
#define  TIM_CCER_CC3E                            TIM_CCER_CC3E_Msk
#define  TIM_CCER_CC3P_Pos                        (9)
#define  TIM_CCER_CC3P_Msk                        (0x1U << TIM_CCER_CC3P_Pos)                       /*!<Channel 3 input capture output polarity*/
#define  TIM_CCER_CC3P                            TIM_CCER_CC3P_Msk
#define  TIM_CCER_CC3NE_Pos                       (10)
#define  TIM_CCER_CC3NE_Msk                       (0x1U << TIM_CCER_CC3NE_Pos)                      /*!<Channel 3 complementary output enable*/
#define  TIM_CCER_CC3NE                           TIM_CCER_CC3NE_Msk
#define  TIM_CCER_CC3NP_Pos                       (11)
#define  TIM_CCER_CC3NP_Msk                       (0x1U << TIM_CCER_CC3NP_Pos)                      /*!<Channel 3 input/capture complementary output polarity*/
#define  TIM_CCER_CC3NP                           TIM_CCER_CC3NP_Msk
#define  TIM_CCER_CC4E_Pos                        (12)
#define  TIM_CCER_CC4E_Msk                        (0x1U << TIM_CCER_CC4E_Pos)                       /*!<Channel 4 capture/compare enable*/
#define  TIM_CCER_CC4E                            TIM_CCER_CC4E_Msk
#define  TIM_CCER_CC4P_Pos                        (13)
#define  TIM_CCER_CC4P_Msk                        (0x1U << TIM_CCER_CC4P_Pos)                       /*!<Channel 4 capture/compare output polarity*/
#define  TIM_CCER_CC4P                            TIM_CCER_CC4P_Msk
#define  TIM_CCER_CC4NE_Pos                       (14)
#define  TIM_CCER_CC4NE_Msk                       (0x1U << TIM_CCER_CC4NE_Pos)                      /*!<Capture/Compare 4 output enable*/
#define  TIM_CCER_CC4NE                           TIM_CCER_CC4NE_Msk
#define  TIM_CCER_CC4NP_Pos                       (15)
#define  TIM_CCER_CC4NP_Msk                       (0x1U << TIM_CCER_CC4NP_Pos)                      /*!<Channel 4 input/capture complementary output polarity*/
#define  TIM_CCER_CC4NP                           TIM_CCER_CC4NP_Msk

/**
  * @brief TIM_CNT Register Bit Definition
  */
#define  TIM_CNT_CNT_Pos                          (0)
#define  TIM_CNT_CNT_Msk                          (0xFFFFFFFFU << TIM_CNT_CNT_Pos)                  /*!<Counter value*/
#define  TIM_CNT_CNT                              TIM_CNT_CNT_Msk
#define  TIM_CNT_CNT_Bit0                         (0x00000001U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit1                         (0x00000002U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit2                         (0x00000004U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit3                         (0x00000008U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit4                         (0x00000010U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit5                         (0x00000020U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit6                         (0x00000040U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit7                         (0x00000080U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit8                         (0x00000100U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit9                         (0x00000200U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit10                        (0x00000400U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit11                        (0x00000800U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit12                        (0x00001000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit13                        (0x00002000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit14                        (0x00004000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit15                        (0x00008000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit16                        (0x00010000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit17                        (0x00020000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit18                        (0x00040000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit19                        (0x00080000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit20                        (0x00100000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit21                        (0x00200000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit22                        (0x00400000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit23                        (0x00800000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit24                        (0x01000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit25                        (0x02000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit26                        (0x04000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit27                        (0x08000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit28                        (0x10000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit29                        (0x20000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit30                        (0x40000000U << TIM_CNT_CNT_Pos) 
#define  TIM_CNT_CNT_Bit31                        (0x80000000U << TIM_CNT_CNT_Pos) 

/**
  * @brief TIM_PSC Register Bit Definition
  */
#define  TIM_PSC_PSC_Pos                          (0)
#define  TIM_PSC_PSC_Msk                          (0xFFFFU << TIM_PSC_PSC_Pos)                      /*!<Prescaler value*/
#define  TIM_PSC_PSC                              TIM_PSC_PSC_Msk
#define  TIM_PSC_PSC_Bit0                         (0x0001U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit1                         (0x0002U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit2                         (0x0004U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit3                         (0x0008U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit4                         (0x0010U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit5                         (0x0020U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit6                         (0x0040U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit7                         (0x0080U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit8                         (0x0100U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit9                         (0x0200U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit10                        (0x0400U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit11                        (0x0800U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit12                        (0x1000U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit13                        (0x2000U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit14                        (0x4000U << TIM_PSC_PSC_Pos) 
#define  TIM_PSC_PSC_Bit15                        (0x8000U << TIM_PSC_PSC_Pos) 

/**
  * @brief TIM_ARR Register Bit Definition
  */
#define  TIM_ARR_ARR_Pos                          (0)
#define  TIM_ARR_ARR_Msk                          (0xFFFFFFFFU << TIM_ARR_ARR_Pos)                  /*!<Auto reload value*/
#define  TIM_ARR_ARR                              TIM_ARR_ARR_Msk
#define  TIM_ARR_ARR_Bit0                         (0x00000001U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit1                         (0x00000002U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit2                         (0x00000004U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit3                         (0x00000008U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit4                         (0x00000010U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit5                         (0x00000020U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit6                         (0x00000040U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit7                         (0x00000080U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit8                         (0x00000100U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit9                         (0x00000200U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit10                        (0x00000400U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit11                        (0x00000800U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit12                        (0x00001000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit13                        (0x00002000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit14                        (0x00004000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit15                        (0x00008000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit16                        (0x00010000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit17                        (0x00020000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit18                        (0x00040000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit19                        (0x00080000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit20                        (0x00100000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit21                        (0x00200000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit22                        (0x00400000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit23                        (0x00800000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit24                        (0x01000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit25                        (0x02000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit26                        (0x04000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit27                        (0x08000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit28                        (0x10000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit29                        (0x20000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit30                        (0x40000000U << TIM_ARR_ARR_Pos) 
#define  TIM_ARR_ARR_Bit31                        (0x80000000U << TIM_ARR_ARR_Pos) 

/**
  * @brief TIM_RCR Register Bit Definition
  */
#define  TIM_RCR_REP_Pos                          (0)
#define  TIM_RCR_REP_Msk                          (0xFFU << TIM_RCR_REP_Pos)                        /*!<Repeat counter value*/
#define  TIM_RCR_REP                              TIM_RCR_REP_Msk
#define  TIM_RCR_REP_Bit0                         (0x01U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit1                         (0x02U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit2                         (0x04U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit3                         (0x08U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit4                         (0x10U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit5                         (0x20U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit6                         (0x40U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_Bit7                         (0x80U << TIM_RCR_REP_Pos) 
#define  TIM_RCR_REP_CNT_Pos                      (8)
#define  TIM_RCR_REP_CNT_Msk                      (0xFFU << TIM_RCR_REP_CNT_Pos)                    /*!<Real-time value written by the repeat counter*/
#define  TIM_RCR_REP_CNT                          TIM_RCR_REP_CNT_Msk
#define  TIM_RCR_REP_CNT_Bit0                     (0x01U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit1                     (0x02U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit2                     (0x04U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit3                     (0x08U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit4                     (0x10U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit5                     (0x20U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit6                     (0x40U << TIM_RCR_REP_CNT_Pos) 
#define  TIM_RCR_REP_CNT_Bit7                     (0x80U << TIM_RCR_REP_CNT_Pos) 

/**
  * @brief TIM_CCR1 Register Bit Definition
  */
#define  TIM_CCR1_CCR1_Pos                        (0)
#define  TIM_CCR1_CCR1_Msk                        (0xFFFFFFFFU << TIM_CCR1_CCR1_Pos)                /*!<Channel 1 capture/compare value*/
#define  TIM_CCR1_CCR1                            TIM_CCR1_CCR1_Msk
#define  TIM_CCR1_CCR1_Bit0                       (0x00000001U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit1                       (0x00000002U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit2                       (0x00000004U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit3                       (0x00000008U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit4                       (0x00000010U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit5                       (0x00000020U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit6                       (0x00000040U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit7                       (0x00000080U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit8                       (0x00000100U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit9                       (0x00000200U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit10                      (0x00000400U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit11                      (0x00000800U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit12                      (0x00001000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit13                      (0x00002000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit14                      (0x00004000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit15                      (0x00008000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit16                      (0x00010000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit17                      (0x00020000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit18                      (0x00040000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit19                      (0x00080000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit20                      (0x00100000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit21                      (0x00200000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit22                      (0x00400000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit23                      (0x00800000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit24                      (0x01000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit25                      (0x02000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit26                      (0x04000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit27                      (0x08000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit28                      (0x10000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit29                      (0x20000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit30                      (0x40000000U << TIM_CCR1_CCR1_Pos) 
#define  TIM_CCR1_CCR1_Bit31                      (0x80000000U << TIM_CCR1_CCR1_Pos) 

/**
  * @brief TIM_CCR2 Register Bit Definition
  */
#define  TIM_CCR2_CCR2_Pos                        (0)
#define  TIM_CCR2_CCR2_Msk                        (0xFFFFFFFFU << TIM_CCR2_CCR2_Pos)                /*!<Channel 2 capture/compare value*/
#define  TIM_CCR2_CCR2                            TIM_CCR2_CCR2_Msk
#define  TIM_CCR2_CCR2_Bit0                       (0x00000001U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit1                       (0x00000002U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit2                       (0x00000004U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit3                       (0x00000008U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit4                       (0x00000010U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit5                       (0x00000020U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit6                       (0x00000040U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit7                       (0x00000080U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit8                       (0x00000100U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit9                       (0x00000200U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit10                      (0x00000400U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit11                      (0x00000800U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit12                      (0x00001000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit13                      (0x00002000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit14                      (0x00004000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit15                      (0x00008000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit16                      (0x00010000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit17                      (0x00020000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit18                      (0x00040000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit19                      (0x00080000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit20                      (0x00100000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit21                      (0x00200000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit22                      (0x00400000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit23                      (0x00800000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit24                      (0x01000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit25                      (0x02000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit26                      (0x04000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit27                      (0x08000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit28                      (0x10000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit29                      (0x20000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit30                      (0x40000000U << TIM_CCR2_CCR2_Pos) 
#define  TIM_CCR2_CCR2_Bit31                      (0x80000000U << TIM_CCR2_CCR2_Pos) 

/**
  * @brief TIM_CCR3 Register Bit Definition
  */
#define  TIM_CCR3_CCR3_Pos                        (0)
#define  TIM_CCR3_CCR3_Msk                        (0xFFFFFFFFU << TIM_CCR3_CCR3_Pos)                /*!<Channel 3 capture/compare value*/
#define  TIM_CCR3_CCR3                            TIM_CCR3_CCR3_Msk
#define  TIM_CCR3_CCR3_Bit0                       (0x00000001U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit1                       (0x00000002U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit2                       (0x00000004U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit3                       (0x00000008U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit4                       (0x00000010U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit5                       (0x00000020U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit6                       (0x00000040U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit7                       (0x00000080U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit8                       (0x00000100U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit9                       (0x00000200U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit10                      (0x00000400U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit11                      (0x00000800U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit12                      (0x00001000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit13                      (0x00002000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit14                      (0x00004000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit15                      (0x00008000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit16                      (0x00010000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit17                      (0x00020000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit18                      (0x00040000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit19                      (0x00080000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit20                      (0x00100000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit21                      (0x00200000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit22                      (0x00400000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit23                      (0x00800000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit24                      (0x01000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit25                      (0x02000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit26                      (0x04000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit27                      (0x08000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit28                      (0x10000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit29                      (0x20000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit30                      (0x40000000U << TIM_CCR3_CCR3_Pos) 
#define  TIM_CCR3_CCR3_Bit31                      (0x80000000U << TIM_CCR3_CCR3_Pos) 

/**
  * @brief TIM_CCR4 Register Bit Definition
  */
#define  TIM_CCR4_CCR4_Pos                        (0)
#define  TIM_CCR4_CCR4_Msk                        (0xFFFFFFFFU << TIM_CCR4_CCR4_Pos)                /*!<Channel 4 capture/compare value*/
#define  TIM_CCR4_CCR4                            TIM_CCR4_CCR4_Msk
#define  TIM_CCR4_CCR4_Bit0                       (0x00000001U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit1                       (0x00000002U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit2                       (0x00000004U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit3                       (0x00000008U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit4                       (0x00000010U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit5                       (0x00000020U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit6                       (0x00000040U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit7                       (0x00000080U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit8                       (0x00000100U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit9                       (0x00000200U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit10                      (0x00000400U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit11                      (0x00000800U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit12                      (0x00001000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit13                      (0x00002000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit14                      (0x00004000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit15                      (0x00008000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit16                      (0x00010000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit17                      (0x00020000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit18                      (0x00040000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit19                      (0x00080000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit20                      (0x00100000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit21                      (0x00200000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit22                      (0x00400000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit23                      (0x00800000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit24                      (0x01000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit25                      (0x02000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit26                      (0x04000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit27                      (0x08000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit28                      (0x10000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit29                      (0x20000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit30                      (0x40000000U << TIM_CCR4_CCR4_Pos) 
#define  TIM_CCR4_CCR4_Bit31                      (0x80000000U << TIM_CCR4_CCR4_Pos) 

/**
  * @brief TIM_BDTR Register Bit Definition
  */
#define  TIM_BDTR_DTG_Pos                         (0)
#define  TIM_BDTR_DTG_Msk                         (0xFFU << TIM_BDTR_DTG_Pos)                       /*!<Dead-time generator setup adjustment*/
#define  TIM_BDTR_DTG                             TIM_BDTR_DTG_Msk
#define  TIM_BDTR_DTG_Bit0                        (0x01U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit1                        (0x02U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit2                        (0x04U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit3                        (0x08U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit4                        (0x10U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit5                        (0x20U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit6                        (0x40U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_DTG_Bit7                        (0x80U << TIM_BDTR_DTG_Pos) 
#define  TIM_BDTR_LOCK_Pos                        (8)
#define  TIM_BDTR_LOCK_Msk                        (0x3U << TIM_BDTR_LOCK_Pos)                       /*!<Lock configuration*/
#define  TIM_BDTR_LOCK                            TIM_BDTR_LOCK_Msk
#define  TIM_BDTR_LOCK_Bit0                       (0x1U << TIM_BDTR_LOCK_Pos) 
#define  TIM_BDTR_LOCK_Bit1                       (0x2U << TIM_BDTR_LOCK_Pos) 
#define  TIM_BDTR_OSSI_Pos                        (10)
#define  TIM_BDTR_OSSI_Msk                        (0x1U << TIM_BDTR_OSSI_Pos)                       /*!<Off state selection in the idle mode*/
#define  TIM_BDTR_OSSI                            TIM_BDTR_OSSI_Msk
#define  TIM_BDTR_OSSR_Pos                        (11)
#define  TIM_BDTR_OSSR_Msk                        (0x1U << TIM_BDTR_OSSR_Pos)                       /*!<Off state selection in the run mode*/
#define  TIM_BDTR_OSSR                            TIM_BDTR_OSSR_Msk
#define  TIM_BDTR_BKE_Pos                         (12)
#define  TIM_BDTR_BKE_Msk                         (0x1U << TIM_BDTR_BKE_Pos)                        /*!<Break function enable*/
#define  TIM_BDTR_BKE                             TIM_BDTR_BKE_Msk
#define  TIM_BDTR_BKP_Pos                         (13)
#define  TIM_BDTR_BKP_Msk                         (0x1U << TIM_BDTR_BKP_Pos)                        /*!<Break input polarity*/
#define  TIM_BDTR_BKP                             TIM_BDTR_BKP_Msk
#define  TIM_BDTR_AOE_Pos                         (14)
#define  TIM_BDTR_AOE_Msk                         (0x1U << TIM_BDTR_AOE_Pos)                        /*!<Auto output enable*/
#define  TIM_BDTR_AOE                             TIM_BDTR_AOE_Msk
#define  TIM_BDTR_MOE_Pos                         (15)
#define  TIM_BDTR_MOE_Msk                         (0x1U << TIM_BDTR_MOE_Pos)                        /*!<Main output enable*/
#define  TIM_BDTR_MOE                             TIM_BDTR_MOE_Msk
#define  TIM_BDTR_DOE_Pos                         (16)
#define  TIM_BDTR_DOE_Msk                         (0x1U << TIM_BDTR_DOE_Pos)                        /*!<Direct output enable*/
#define  TIM_BDTR_DOE                             TIM_BDTR_DOE_Msk

/**
  * @brief TIM_DCR Register Bit Definition
  */
#define  TIM_DCR_DBA_Pos                          (0)
#define  TIM_DCR_DBA_Msk                          (0x1FU << TIM_DCR_DBA_Pos)                        /*!<DMA base address*/
#define  TIM_DCR_DBA                              TIM_DCR_DBA_Msk
#define  TIM_DCR_DBA_Bit0                         (0x01U << TIM_DCR_DBA_Pos) 
#define  TIM_DCR_DBA_Bit1                         (0x02U << TIM_DCR_DBA_Pos) 
#define  TIM_DCR_DBA_Bit2                         (0x04U << TIM_DCR_DBA_Pos) 
#define  TIM_DCR_DBA_Bit3                         (0x08U << TIM_DCR_DBA_Pos) 
#define  TIM_DCR_DBA_Bit4                         (0x10U << TIM_DCR_DBA_Pos) 
#define  TIM_DCR_DBL_Pos                          (8)
#define  TIM_DCR_DBL_Msk                          (0x1FU << TIM_DCR_DBL_Pos)                        /*!<DMA continuous transmission length*/
#define  TIM_DCR_DBL                              TIM_DCR_DBL_Msk
#define  TIM_DCR_DBL_Bit0                         (0x01U << TIM_DCR_DBL_Pos) 
#define  TIM_DCR_DBL_Bit1                         (0x02U << TIM_DCR_DBL_Pos) 
#define  TIM_DCR_DBL_Bit2                         (0x04U << TIM_DCR_DBL_Pos) 
#define  TIM_DCR_DBL_Bit3                         (0x08U << TIM_DCR_DBL_Pos) 
#define  TIM_DCR_DBL_Bit4                         (0x10U << TIM_DCR_DBL_Pos) 

/**
  * @brief TIM_DMAR Register Bit Definition
  */
#define  TIM_DMAR_DMAB_Pos                        (0)
#define  TIM_DMAR_DMAB_Msk                        (0xFFFFU << TIM_DMAR_DMAB_Pos)                    /*!<DMA register for burst accesses*/
#define  TIM_DMAR_DMAB                            TIM_DMAR_DMAB_Msk
#define  TIM_DMAR_DMAB_Bit0                       (0x0001U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit1                       (0x0002U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit2                       (0x0004U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit3                       (0x0008U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit4                       (0x0010U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit5                       (0x0020U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit6                       (0x0040U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit7                       (0x0080U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit8                       (0x0100U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit9                       (0x0200U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit10                      (0x0400U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit11                      (0x0800U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit12                      (0x1000U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit13                      (0x2000U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit14                      (0x4000U << TIM_DMAR_DMAB_Pos) 
#define  TIM_DMAR_DMAB_Bit15                      (0x8000U << TIM_DMAR_DMAB_Pos) 

/**
  * @brief TIM_OR Register Bit Definition
  */

/* OR */
#define  TIM_OR_ETR_RMP_Pos                       (0)
#define  TIM_OR_ETR_RMP_Msk                       (0x3U << TIM_OR_ETR_RMP_Pos)                      /*!<ETR multiplex*/
#define  TIM_OR_ETR_RMP                           TIM_OR_ETR_RMP_Msk
#define  TIM_OR_ETR_RMP_Bit0                      (0x1U << TIM_OR_ETR_RMP_Pos) 
#define  TIM_OR_ETR_RMP_Bit1                      (0x2U << TIM_OR_ETR_RMP_Pos) 

/* CCR1_EXT */
#define  TIM_OR_CCR1_EXT_Pos                      (0)
#define  TIM_OR_CCR1_EXT_Msk                      (0xFFFFU << TIM_OR_CCR1_EXT_Pos)                  /*!<Capture/Compare 1 value*/
#define  TIM_OR_CCR1_EXT                          TIM_OR_CCR1_EXT_Msk
#define  TIM_OR_CCR1_EXT_Bit0                     (0x0001U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit1                     (0x0002U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit2                     (0x0004U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit3                     (0x0008U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit4                     (0x0010U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit5                     (0x0020U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit6                     (0x0040U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit7                     (0x0080U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit8                     (0x0100U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit9                     (0x0200U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit10                    (0x0400U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit11                    (0x0800U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit12                    (0x1000U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit13                    (0x2000U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit14                    (0x4000U << TIM_OR_CCR1_EXT_Pos) 
#define  TIM_OR_CCR1_EXT_Bit15                    (0x8000U << TIM_OR_CCR1_EXT_Pos) 

/* OR */
#define  TIM_OR_TI4_RMP_Pos                       (6)
#define  TIM_OR_TI4_RMP_Msk                       (0x3U << TIM_OR_TI4_RMP_Pos)                      /*!<TI4 multiplex*/
#define  TIM_OR_TI4_RMP                           TIM_OR_TI4_RMP_Msk
#define  TIM_OR_TI4_RMP_Bit0                      (0x1U << TIM_OR_TI4_RMP_Pos) 
#define  TIM_OR_TI4_RMP_Bit1                      (0x2U << TIM_OR_TI4_RMP_Pos) 

/**
  * @brief TIM_CCMR3 Register Bit Definition
  */
#define  TIM_CCMR3_OC5PE_Pos                      (3)
#define  TIM_CCMR3_OC5PE_Msk                      (0x1U << TIM_CCMR3_OC5PE_Pos)                     /*!<Output compare 5 preload enable*/
#define  TIM_CCMR3_OC5PE                          TIM_CCMR3_OC5PE_Msk
#define  TIM_CCMR3_OC6PE_Pos                      (11)
#define  TIM_CCMR3_OC6PE_Msk                      (0x1U << TIM_CCMR3_OC6PE_Pos)                     /*!<Output compare 6 preload enable*/
#define  TIM_CCMR3_OC6PE                          TIM_CCMR3_OC6PE_Msk

/**
  * @brief TIM_CCR5 Register Bit Definition
  */
#define  TIM_CCR5_CCR5_Pos                        (0)
#define  TIM_CCR5_CCR5_Msk                        (0xFFFFU << TIM_CCR5_CCR5_Pos)                    /*!<Compare 5 value*/
#define  TIM_CCR5_CCR5                            TIM_CCR5_CCR5_Msk
#define  TIM_CCR5_CCR5_Bit0                       (0x0001U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit1                       (0x0002U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit2                       (0x0004U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit3                       (0x0008U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit4                       (0x0010U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit5                       (0x0020U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit6                       (0x0040U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit7                       (0x0080U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit8                       (0x0100U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit9                       (0x0200U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit10                      (0x0400U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit11                      (0x0800U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit12                      (0x1000U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit13                      (0x2000U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit14                      (0x4000U << TIM_CCR5_CCR5_Pos) 
#define  TIM_CCR5_CCR5_Bit15                      (0x8000U << TIM_CCR5_CCR5_Pos) 

/**
  * @brief TIM_PDER Register Bit Definition
  */
#define  TIM_PDER_CCDREPE_Pos                     (0)
#define  TIM_PDER_CCDREPE_Msk                     (0x1U << TIM_PDER_CCDREPE_Pos)                    /*!<Enable DMA will generate the update request at each underflow or overflow*/
#define  TIM_PDER_CCDREPE                         TIM_PDER_CCDREPE_Msk
#define  TIM_PDER_CCR1_SHIFT_EN_Pos               (1)
#define  TIM_PDER_CCR1_SHIFT_EN_Msk               (0x1U << TIM_PDER_CCR1_SHIFT_EN_Pos)              /*!<Enable channel 1 output PWM phase shift bit*/
#define  TIM_PDER_CCR1_SHIFT_EN                   TIM_PDER_CCR1_SHIFT_EN_Msk
#define  TIM_PDER_CCR2_SHIFT_EN_Pos               (2)
#define  TIM_PDER_CCR2_SHIFT_EN_Msk               (0x1U << TIM_PDER_CCR2_SHIFT_EN_Pos)              /*!<Enable channel 2 output PWM phase shift bit*/
#define  TIM_PDER_CCR2_SHIFT_EN                   TIM_PDER_CCR2_SHIFT_EN_Msk
#define  TIM_PDER_CCR3_SHIFT_EN_Pos               (3)
#define  TIM_PDER_CCR3_SHIFT_EN_Msk               (0x1U << TIM_PDER_CCR3_SHIFT_EN_Pos)              /*!<Enable channel 3 output PWM phase shift bit*/
#define  TIM_PDER_CCR3_SHIFT_EN                   TIM_PDER_CCR3_SHIFT_EN_Msk
#define  TIM_PDER_CCR4_SHIFT_EN_Pos               (4)
#define  TIM_PDER_CCR4_SHIFT_EN_Msk               (0x1U << TIM_PDER_CCR4_SHIFT_EN_Pos)              /*!<Enable channel 4 output PWM phase shift bit*/
#define  TIM_PDER_CCR4_SHIFT_EN                   TIM_PDER_CCR4_SHIFT_EN_Msk
#define  TIM_PDER_CCR5_SHIFT_EN_Pos               (5)
#define  TIM_PDER_CCR5_SHIFT_EN_Msk               (0x1U << TIM_PDER_CCR5_SHIFT_EN_Pos)              /*!<Enable channel 5 output PWM phase shift bit*/
#define  TIM_PDER_CCR5_SHIFT_EN                   TIM_PDER_CCR5_SHIFT_EN_Msk
#define  TIM_PDER_CCR6_SHIFT_EN_Pos               (6)
#define  TIM_PDER_CCR6_SHIFT_EN_Msk               (0x1U << TIM_PDER_CCR6_SHIFT_EN_Pos)              /*!<Enable channel 6 output PWM phase shift bit*/
#define  TIM_PDER_CCR6_SHIFT_EN                   TIM_PDER_CCR6_SHIFT_EN_Msk
#define  TIM_PDER_CCR1_WINDOW_EN_Pos              (9)
#define  TIM_PDER_CCR1_WINDOW_EN_Msk              (0x1U << TIM_PDER_CCR1_WINDOW_EN_Pos)             /*!<*/
#define  TIM_PDER_CCR1_WINDOW_EN                  TIM_PDER_CCR1_WINDOW_EN_Msk
#define  TIM_PDER_CCR2_WINDOW_EN_Pos              (10)
#define  TIM_PDER_CCR2_WINDOW_EN_Msk              (0x1U << TIM_PDER_CCR2_WINDOW_EN_Pos)             /*!<*/
#define  TIM_PDER_CCR2_WINDOW_EN                  TIM_PDER_CCR2_WINDOW_EN_Msk
#define  TIM_PDER_CCR3_WINDOW_EN_Pos              (11)
#define  TIM_PDER_CCR3_WINDOW_EN_Msk              (0x1U << TIM_PDER_CCR3_WINDOW_EN_Pos)             /*!<*/
#define  TIM_PDER_CCR3_WINDOW_EN                  TIM_PDER_CCR3_WINDOW_EN_Msk
#define  TIM_PDER_CCR4_WINDOW_EN_Pos              (12)
#define  TIM_PDER_CCR4_WINDOW_EN_Msk              (0x1U << TIM_PDER_CCR4_WINDOW_EN_Pos)             /*!<*/
#define  TIM_PDER_CCR4_WINDOW_EN                  TIM_PDER_CCR4_WINDOW_EN_Msk
#define  TIM_PDER_CCR5_WINDOW_EN_Pos              (13)
#define  TIM_PDER_CCR5_WINDOW_EN_Msk              (0x1U << TIM_PDER_CCR5_WINDOW_EN_Pos)             /*!<*/
#define  TIM_PDER_CCR5_WINDOW_EN                  TIM_PDER_CCR5_WINDOW_EN_Msk
#define  TIM_PDER_CCR6_WINDOW_EN_Pos              (14)
#define  TIM_PDER_CCR6_WINDOW_EN_Msk              (0x1U << TIM_PDER_CCR6_WINDOW_EN_Pos)             /*!<*/
#define  TIM_PDER_CCR6_WINDOW_EN                  TIM_PDER_CCR6_WINDOW_EN_Msk

/**
  * @brief TIM_CCREXT Register Bit Definition
  */
#define  TIM_CCR1EXT_CCRxEXT_Pos                  (0)
#define  TIM_CCR1EXT_CCRxEXT_Msk                  (0xFFFFU << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT                      TIM_CCR1EXT_CCRxEXT_Msk                           /*!<The channel x capture/compare extension register can be configured with different PWM modes through TIMx_PDER to achieve various PWM output waveforms. Note: x = 1~5 Note: CCR5 and CCR5EXT cannot directly control PWM output. However, when CCR5_SHIFT_EN or CCR5_WINDOW_EN is enabled, the CC5_SETTRGO output signal will exhibit corresponding changes.*/
#define  TIM_CCR1EXT_CCRxEXT_Bit0                 (0x0001U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit1                 (0x0002U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit2                 (0x0004U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit3                 (0x0008U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit4                 (0x0010U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit5                 (0x0020U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit6                 (0x0040U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit7                 (0x0080U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit8                 (0x0100U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit9                 (0x0200U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit10                (0x0400U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit11                (0x0800U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit12                (0x1000U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit13                (0x2000U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit14                (0x4000U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR1EXT_CCRxEXT_Bit15                (0x8000U << TIM_CCR1EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Pos                  (0)
#define  TIM_CCR2EXT_CCRxEXT_Msk                  (0xFFFFU << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT                      TIM_CCR2EXT_CCRxEXT_Msk                           /*!<The channel x capture/compare extension register can be configured with different PWM modes through TIMx_PDER to achieve various PWM output waveforms. Note: x = 1~5 Note: CCR5 and CCR5EXT cannot directly control PWM output. However, when CCR5_SHIFT_EN or CCR5_WINDOW_EN is enabled, the CC5_SETTRGO output signal will exhibit corresponding changes.*/
#define  TIM_CCR2EXT_CCRxEXT_Bit0                 (0x0001U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit1                 (0x0002U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit2                 (0x0004U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit3                 (0x0008U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit4                 (0x0010U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit5                 (0x0020U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit6                 (0x0040U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit7                 (0x0080U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit8                 (0x0100U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit9                 (0x0200U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit10                (0x0400U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit11                (0x0800U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit12                (0x1000U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit13                (0x2000U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit14                (0x4000U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR2EXT_CCRxEXT_Bit15                (0x8000U << TIM_CCR2EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Pos                  (0)
#define  TIM_CCR3EXT_CCRxEXT_Msk                  (0xFFFFU << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT                      TIM_CCR3EXT_CCRxEXT_Msk                           /*!<The channel x capture/compare extension register can be configured with different PWM modes through TIMx_PDER to achieve various PWM output waveforms. Note: x = 1~5 Note: CCR5 and CCR5EXT cannot directly control PWM output. However, when CCR5_SHIFT_EN or CCR5_WINDOW_EN is enabled, the CC5_SETTRGO output signal will exhibit corresponding changes.*/
#define  TIM_CCR3EXT_CCRxEXT_Bit0                 (0x0001U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit1                 (0x0002U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit2                 (0x0004U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit3                 (0x0008U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit4                 (0x0010U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit5                 (0x0020U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit6                 (0x0040U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit7                 (0x0080U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit8                 (0x0100U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit9                 (0x0200U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit10                (0x0400U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit11                (0x0800U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit12                (0x1000U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit13                (0x2000U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit14                (0x4000U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR3EXT_CCRxEXT_Bit15                (0x8000U << TIM_CCR3EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Pos                  (0)
#define  TIM_CCR4EXT_CCRxEXT_Msk                  (0xFFFFU << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT                      TIM_CCR4EXT_CCRxEXT_Msk                           /*!<The channel x capture/compare extension register can be configured with different PWM modes through TIMx_PDER to achieve various PWM output waveforms. Note: x = 1~5 Note: CCR5 and CCR5EXT cannot directly control PWM output. However, when CCR5_SHIFT_EN or CCR5_WINDOW_EN is enabled, the CC5_SETTRGO output signal will exhibit corresponding changes.*/
#define  TIM_CCR4EXT_CCRxEXT_Bit0                 (0x0001U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit1                 (0x0002U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit2                 (0x0004U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit3                 (0x0008U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit4                 (0x0010U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit5                 (0x0020U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit6                 (0x0040U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit7                 (0x0080U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit8                 (0x0100U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit9                 (0x0200U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit10                (0x0400U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit11                (0x0800U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit12                (0x1000U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit13                (0x2000U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit14                (0x4000U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR4EXT_CCRxEXT_Bit15                (0x8000U << TIM_CCR4EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Pos                  (0)
#define  TIM_CCR5EXT_CCRxEXT_Msk                  (0xFFFFU << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT                      TIM_CCR5EXT_CCRxEXT_Msk                           /*!<The channel x capture/compare extension register can be configured with different PWM modes through TIMx_PDER to achieve various PWM output waveforms. Note: x = 1~5 Note: CCR5 and CCR5EXT cannot directly control PWM output. However, when CCR5_SHIFT_EN or CCR5_WINDOW_EN is enabled, the CC5_SETTRGO output signal will exhibit corresponding changes.*/
#define  TIM_CCR5EXT_CCRxEXT_Bit0                 (0x0001U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit1                 (0x0002U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit2                 (0x0004U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit3                 (0x0008U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit4                 (0x0010U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit5                 (0x0020U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit6                 (0x0040U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit7                 (0x0080U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit8                 (0x0100U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit9                 (0x0200U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit10                (0x0400U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit11                (0x0800U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit12                (0x1000U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit13                (0x2000U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit14                (0x4000U << TIM_CCR5EXT_CCRxEXT_Pos) 
#define  TIM_CCR5EXT_CCRxEXT_Bit15                (0x8000U << TIM_CCR5EXT_CCRxEXT_Pos) 

/**
  * @brief TIM_BKINF Register Bit Definition
  */
#define  TIM_BKINF_BKINFE_Pos                     (0)
#define  TIM_BKINF_BKINFE_Msk                     (0x1U << TIM_BKINF_BKINFE_Pos)                    /*!<Break input filter enable*/
#define  TIM_BKINF_BKINFE                         TIM_BKINF_BKINFE_Msk
#define  TIM_BKINF_BKINF_Pos                      (1)
#define  TIM_BKINF_BKINF_Msk                      (0xFU << TIM_BKINF_BKINF_Pos)                     /*!<Break input filter*/
#define  TIM_BKINF_BKINF                          TIM_BKINF_BKINF_Msk
#define  TIM_BKINF_BKINF_Bit0                     (0x1U << TIM_BKINF_BKINF_Pos) 
#define  TIM_BKINF_BKINF_Bit1                     (0x2U << TIM_BKINF_BKINF_Pos) 
#define  TIM_BKINF_BKINF_Bit2                     (0x4U << TIM_BKINF_BKINF_Pos) 
#define  TIM_BKINF_BKINF_Bit3                     (0x8U << TIM_BKINF_BKINF_Pos) 
#define  TIM_BKINF_CSSBKIN_SEL_Pos                (5)
#define  TIM_BKINF_CSSBKIN_SEL_Msk                (0x1U << TIM_BKINF_CSSBKIN_SEL_Pos)               /*!<CSS break input channel selects*/
#define  TIM_BKINF_CSSBKIN_SEL                    TIM_BKINF_CSSBKIN_SEL_Msk
#define  TIM_BKINF_IOBKIN_SEL_L_Pos               (6)
#define  TIM_BKINF_IOBKIN_SEL_L_Msk               (0x7FU << TIM_BKINF_IOBKIN_SEL_L_Pos)             /*!<IO break input channel selects*/
#define  TIM_BKINF_IOBKIN_SEL_L                   TIM_BKINF_IOBKIN_SEL_L_Msk
#define  TIM_BKINF_IOBKIN_SEL_L_Bit0              (0x01U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_L_Bit1              (0x02U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_L_Bit2              (0x04U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_L_Bit3              (0x08U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_L_Bit4              (0x10U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_L_Bit5              (0x20U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_L_Bit6              (0x40U << TIM_BKINF_IOBKIN_SEL_L_Pos) 
#define  TIM_BKINF_BKIN_SEL_Pos                   (6)
#define  TIM_BKINF_BKIN_SEL_Msk                   (0x3FU << TIM_BKINF_BKIN_SEL_Pos)                 /*!<IO break input channel selects*/
#define  TIM_BKINF_BKIN_SEL                       TIM_BKINF_BKIN_SEL_Msk
#define  TIM_BKINF_BKIN_SEL_Bit0                  (0x01U << TIM_BKINF_BKIN_SEL_Pos) 
#define  TIM_BKINF_BKIN_SEL_Bit1                  (0x02U << TIM_BKINF_BKIN_SEL_Pos) 
#define  TIM_BKINF_BKIN_SEL_Bit2                  (0x04U << TIM_BKINF_BKIN_SEL_Pos) 
#define  TIM_BKINF_BKIN_SEL_Bit3                  (0x08U << TIM_BKINF_BKIN_SEL_Pos) 
#define  TIM_BKINF_BKIN_SEL_Bit4                  (0x10U << TIM_BKINF_BKIN_SEL_Pos) 
#define  TIM_BKINF_BKIN_SEL_Bit5                  (0x20U << TIM_BKINF_BKIN_SEL_Pos) 
#define  TIM_BKINF_COMPBKIN_SEL_Pos               (13)
#define  TIM_BKINF_COMPBKIN_SEL_Msk               (0x3U << TIM_BKINF_COMPBKIN_SEL_Pos)              /*!<COMP break input sel*/
#define  TIM_BKINF_COMPBKIN_SEL                   TIM_BKINF_COMPBKIN_SEL_Msk
#define  TIM_BKINF_COMPBKIN_SEL_Bit0              (0x1U << TIM_BKINF_COMPBKIN_SEL_Pos) 
#define  TIM_BKINF_COMPBKIN_SEL_Bit1              (0x2U << TIM_BKINF_COMPBKIN_SEL_Pos) 
#define  TIM_BKINF_IOBKIN_SEL_H_Pos               (24)
#define  TIM_BKINF_IOBKIN_SEL_H_Msk               (0x1U << TIM_BKINF_IOBKIN_SEL_H_Pos)              /*!<IO break input sel*/
#define  TIM_BKINF_IOBKIN_SEL_H                   TIM_BKINF_IOBKIN_SEL_H_Msk

/**
  * @brief TIM_CCR6 Register Bit Definition
  */
#define  TIM_CCR6_CCR6_Pos                        (0)
#define  TIM_CCR6_CCR6_Msk                        (0xFFFFU << TIM_CCR6_CCR6_Pos)                    /*!<Capture/Compare 6 value*/
#define  TIM_CCR6_CCR6                            TIM_CCR6_CCR6_Msk
#define  TIM_CCR6_CCR6_Bit0                       (0x0001U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit1                       (0x0002U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit2                       (0x0004U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit3                       (0x0008U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit4                       (0x0010U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit5                       (0x0020U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit6                       (0x0040U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit7                       (0x0080U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit8                       (0x0100U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit9                       (0x0200U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit10                      (0x0400U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit11                      (0x0800U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit12                      (0x1000U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit13                      (0x2000U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit14                      (0x4000U << TIM_CCR6_CCR6_Pos) 
#define  TIM_CCR6_CCR6_Bit15                      (0x8000U << TIM_CCR6_CCR6_Pos) 

/**
  * @brief TIM_CCR6EXT Register Bit Definition
  */
#define  TIM_CCR6EXT_CCR6EXT_Pos                  (0)
#define  TIM_CCR6EXT_CCR6EXT_Msk                  (0xFFFFU << TIM_CCR6EXT_CCR6EXT_Pos)              /*!<Channel x compare value during count down in PWM central alignment mode.PWM phase shift function: Enable PDER register PWM phase shift. According to the required phase shift, configure CCRxFALL and CCRx, PWM exports programmable phase shift waveform, and can shift left or right.*/
#define  TIM_CCR6EXT_CCR6EXT                      TIM_CCR6EXT_CCR6EXT_Msk
#define  TIM_CCR6EXT_CCR6EXT_Bit0                 (0x0001U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit1                 (0x0002U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit2                 (0x0004U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit3                 (0x0008U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit4                 (0x0010U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit5                 (0x0020U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit6                 (0x0040U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit7                 (0x0080U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit8                 (0x0100U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit9                 (0x0200U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit10                (0x0400U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit11                (0x0800U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit12                (0x1000U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit13                (0x2000U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit14                (0x4000U << TIM_CCR6EXT_CCR6EXT_Pos) 
#define  TIM_CCR6EXT_CCR6EXT_Bit15                (0x8000U << TIM_CCR6EXT_CCR6EXT_Pos) 

/**
  * @brief TIM_DOCR Register Bit Definition
  */
#define  TIM_DOCR_DOS_Pos                         (0)
#define  TIM_DOCR_DOS_Msk                         (0x7U << TIM_DOCR_DOS_Pos)                        /*!<Debug halt Output select*/
#define  TIM_DOCR_DOS                             TIM_DOCR_DOS_Msk
#define  TIM_DOCR_DOS_Bit0                        (0x1U << TIM_DOCR_DOS_Pos) 
#define  TIM_DOCR_DOS_Bit1                        (0x2U << TIM_DOCR_DOS_Pos) 
#define  TIM_DOCR_DOS_Bit2                        (0x4U << TIM_DOCR_DOS_Pos) 

/**
  * @brief TIM_SOER Register Bit Definition
  */
#define  TIM_SOER_SOEN_Pos                        (0)
#define  TIM_SOER_SOEN_Msk                        (0x1U << TIM_SOER_SOEN_Pos)                       /*!<Soft Output Enable*/
#define  TIM_SOER_SOEN                            TIM_SOER_SOEN_Msk

/**
  * @brief TIM_SOCR Register Bit Definition
  */
#define  TIM_SOCR_SFTV_Pos                        (0)
#define  TIM_SOCR_SFTV_Msk                        (0xFFU << TIM_SOCR_SFTV_Pos)                      /*!<Soft Output Value*/
#define  TIM_SOCR_SFTV                            TIM_SOCR_SFTV_Msk
#define  TIM_SOCR_SFTV_Bit0                       (0x01U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit1                       (0x02U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit2                       (0x04U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit3                       (0x08U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit4                       (0x10U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit5                       (0x20U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit6                       (0x40U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTV_Bit7                       (0x80U << TIM_SOCR_SFTV_Pos) 
#define  TIM_SOCR_SFTEN_Pos                       (8)
#define  TIM_SOCR_SFTEN_Msk                       (0xFFU << TIM_SOCR_SFTEN_Pos)                     /*!<Soft Output Enable*/
#define  TIM_SOCR_SFTEN                           TIM_SOCR_SFTEN_Msk
#define  TIM_SOCR_SFTEN_Bit0                      (0x01U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit1                      (0x02U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit2                      (0x04U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit3                      (0x08U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit4                      (0x10U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit5                      (0x20U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit6                      (0x40U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_SFTEN_Bit7                      (0x80U << TIM_SOCR_SFTEN_Pos) 
#define  TIM_SOCR_BSFTV_Pos                       (16)
#define  TIM_SOCR_BSFTV_Msk                       (0xFFU << TIM_SOCR_BSFTV_Pos)                     /*!<Break Soft Output Value*/
#define  TIM_SOCR_BSFTV                           TIM_SOCR_BSFTV_Msk
#define  TIM_SOCR_BSFTV_Bit0                      (0x01U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit1                      (0x02U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit2                      (0x04U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit3                      (0x08U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit4                      (0x10U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit5                      (0x20U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit6                      (0x40U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTV_Bit7                      (0x80U << TIM_SOCR_BSFTV_Pos) 
#define  TIM_SOCR_BSFTEN_Pos                      (24)
#define  TIM_SOCR_BSFTEN_Msk                      (0xFFU << TIM_SOCR_BSFTEN_Pos)                    /*!<Break Soft Output Enable*/
#define  TIM_SOCR_BSFTEN                          TIM_SOCR_BSFTEN_Msk
#define  TIM_SOCR_BSFTEN_Bit0                     (0x01U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit1                     (0x02U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit2                     (0x04U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit3                     (0x08U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit4                     (0x10U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit5                     (0x20U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit6                     (0x40U << TIM_SOCR_BSFTEN_Pos) 
#define  TIM_SOCR_BSFTEN_Bit7                     (0x80U << TIM_SOCR_BSFTEN_Pos) 

/**
  * @brief TIM_BKSR Register Bit Definition
  */
#define  TIM_BKSR_CSSBF_Pos                       (0)
#define  TIM_BKSR_CSSBF_Msk                       (0x1U << TIM_BKSR_CSSBF_Pos)                      /*!<CSSBF Break Flag*/
#define  TIM_BKSR_CSSBF                           TIM_BKSR_CSSBF_Msk
#define  TIM_BKSR_IOBF_Pos                        (1)
#define  TIM_BKSR_IOBF_Msk                        (0x1U << TIM_BKSR_IOBF_Pos)                       /*!<IO Break Flag*/
#define  TIM_BKSR_IOBF                            TIM_BKSR_IOBF_Msk
#define  TIM_BKSR_BCPTF1_Pos                      (2)
#define  TIM_BKSR_BCPTF1_Msk                      (0x1U << TIM_BKSR_BCPTF1_Pos)                     /*!<CMP1 Break Flag*/
#define  TIM_BKSR_BCPTF1                          TIM_BKSR_BCPTF1_Msk
#define  TIM_BKSR_BCPTF2_Pos                      (3)
#define  TIM_BKSR_BCPTF2_Msk                      (0x1U << TIM_BKSR_BCPTF2_Pos)                     /*!<CMP2 Break Flag*/
#define  TIM_BKSR_BCPTF2                          TIM_BKSR_BCPTF2_Msk


#endif

