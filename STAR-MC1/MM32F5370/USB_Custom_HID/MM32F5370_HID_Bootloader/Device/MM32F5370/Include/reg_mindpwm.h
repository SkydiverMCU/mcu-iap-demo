/***********************************************************************************************************************
    @file     reg_mindpwm.h
    @author   VV TEAM
    @brief    This flie contains all the MINDPWM's register and its field definition.
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

#ifndef __REG_MINDPWM_H
#define __REG_MINDPWM_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief MindPWM Base Address Definition
  */
#define  MindPWM_BASE                              0x40016800                                       /*!<Base Address: 0x40016800*/

/**
  * @brief MindPWM Register Structure Definition
  */
typedef struct
{
    struct 
    {
        __IO uint32_t CR0;                         /*!<                                               offset: 0x00       */
        __IO uint32_t CR1;                         /*!<                                               offset: 0x04       */
        __IO uint32_t OCR;                         /*!<                                               offset: 0x08       */
        __IO uint32_t CNT;                         /*!<                                               offset: 0x0C       */
        __IO uint32_t INIT;                        /*!<                                               offset: 0x10       */
        __IO uint32_t VAL0;                        /*!<                                               offset: 0x14       */
        __IO uint32_t VAL1;                        /*!<                                               offset: 0x18       */
        __IO uint32_t VAL2;                        /*!<                                               offset: 0x1C       */
        __IO uint32_t VAL3;                        /*!<                                               offset: 0x20       */
        __IO uint32_t VAL4;                        /*!<                                               offset: 0x24       */
        __IO uint32_t VAL5;                        /*!<                                               offset: 0x28       */
        __IO uint32_t FRCR0;                       /*!<                                               offset: 0x2C       */
        __IO uint32_t FRCR1;                       /*!<                                               offset: 0x30       */
        __IO uint32_t SR;                          /*!<                                               offset: 0x34       */
        __IO uint32_t INTE;                        /*!<                                               offset: 0x38       */
        __IO uint32_t DMAE;                        /*!<                                               offset: 0x3C       */
        __IO uint32_t TRGCR;                       /*!<                                               offset: 0x40       */
        __IO uint32_t FDIS0;                       /*!<                                               offset: 0x44       */
        __IO uint32_t FDIS1;                       /*!<                                               offset: 0x48       */
        __IO uint32_t DTCNT;                       /*!<                                               offset: 0x4C       */
        __IO uint32_t CAPTCRX;                     /*!<                                               offset: 0x50       */
        __IO uint32_t CAPTCRA;                     /*!<                                               offset: 0x54       */
        __IO uint32_t CAPTCRB;                     /*!<                                               offset: 0x58       */
        __IO uint32_t CVAL0;                       /*!<                                               offset: 0x5C       */
        __IO uint32_t CVAL1;                       /*!<                                               offset: 0x60       */
        __IO uint32_t CVAL2;                       /*!<                                               offset: 0x64       */
        __IO uint32_t CVAL3;                       /*!<                                               offset: 0x68       */
        __IO uint32_t CVAL4;                       /*!<                                               offset: 0x6C       */
        __IO uint32_t CVAL5;                       /*!<                                               offset: 0x70       */
        __IO uint32_t CCYC0;                       /*!<                                               offset: 0x74       */
        __IO uint32_t CCYC1;                       /*!<                                               offset: 0x78       */
        __IO uint32_t CCYC2;                       /*!<                                               offset: 0x7C       */
    }SM[4];
    __IO uint32_t GCR0;                           /*!<                                               offset: 0x200      */
    __IO uint32_t GCR1;                           /*!<                                               offset: 0x204      */
    __IO uint32_t DTCR;                           /*!<                                               offset: 0x208      */
    __IO uint32_t RESERVED0x20C[1];               /*!<                                               offset: 0x20C      */
    __IO uint32_t FC0CR0;                         /*!<                                               offset: 0x210      */
    __IO uint32_t FC0CR1;                         /*!<                                               offset: 0x214      */
    __IO uint32_t RESERVED0x218[2];               /*!<                                               offset: 0x218~0x21C*/
    __IO uint32_t FC1CR0;                         /*!<                                               offset: 0x220      */
    __IO uint32_t FC1CR1;                         /*!<                                               offset: 0x224      */
    __IO uint32_t RESERVED0x228[2];               /*!<                                               offset: 0x228~0x22C*/
    __IO uint32_t FC2CR0;                         /*!<                                               offset: 0x230      */
    __IO uint32_t FC2CR1;                         /*!<                                               offset: 0x234      */
    __IO uint32_t RESERVED0x238[2];               /*!<                                               offset: 0x238~0x23C*/
    __IO uint32_t FC3CR0;                         /*!<                                               offset: 0x240      */
    __IO uint32_t FC3CR1;                         /*!<                                               offset: 0x244      */
} MindPWM_TypeDef;

/**
  * @brief MindPWM type pointer Definition
  */
#define MindPWM                                   ((MindPWM_TypeDef *)MindPWM_BASE)

/**
  * @brief MindPWM_SMCR0 Register Bit Definition
  */
#define  MindPWM_SMCR0_CLK_SEL_Pos                (0)
#define  MindPWM_SMCR0_CLK_SEL_Msk                (0x3U << MindPWM_SMCR0_CLK_SEL_Pos)               /*!<*/
#define  MindPWM_SMCR0_CLK_SEL                    MindPWM_SMCR0_CLK_SEL_Msk
#define  MindPWM_SMCR0_CLK_SEL_Bit0               (0x1U << MindPWM_SMCR0_CLK_SEL_Pos) 
#define  MindPWM_SMCR0_CLK_SEL_Bit1               (0x2U << MindPWM_SMCR0_CLK_SEL_Pos) 
#define  MindPWM_SMCR0_PRSC_Pos                   (2)
#define  MindPWM_SMCR0_PRSC_Msk                   (0x7U << MindPWM_SMCR0_PRSC_Pos)                  /*!<*/
#define  MindPWM_SMCR0_PRSC                       MindPWM_SMCR0_PRSC_Msk
#define  MindPWM_SMCR0_PRSC_Bit0                  (0x1U << MindPWM_SMCR0_PRSC_Pos) 
#define  MindPWM_SMCR0_PRSC_Bit1                  (0x2U << MindPWM_SMCR0_PRSC_Pos) 
#define  MindPWM_SMCR0_PRSC_Bit2                  (0x4U << MindPWM_SMCR0_PRSC_Pos) 
#define  MindPWM_SMCR0_FORCE_SEL_Pos              (8)
#define  MindPWM_SMCR0_FORCE_SEL_Msk              (0x7U << MindPWM_SMCR0_FORCE_SEL_Pos)             /*!<*/
#define  MindPWM_SMCR0_FORCE_SEL                  MindPWM_SMCR0_FORCE_SEL_Msk
#define  MindPWM_SMCR0_FORCE_SEL_Bit0             (0x1U << MindPWM_SMCR0_FORCE_SEL_Pos) 
#define  MindPWM_SMCR0_FORCE_SEL_Bit1             (0x2U << MindPWM_SMCR0_FORCE_SEL_Pos) 
#define  MindPWM_SMCR0_FORCE_SEL_Bit2             (0x4U << MindPWM_SMCR0_FORCE_SEL_Pos) 
#define  MindPWM_SMCR0_FORCE_LOCAL_Pos            (11)
#define  MindPWM_SMCR0_FORCE_LOCAL_Msk            (0x1U << MindPWM_SMCR0_FORCE_LOCAL_Pos)           /*!<*/
#define  MindPWM_SMCR0_FORCE_LOCAL                MindPWM_SMCR0_FORCE_LOCAL_Msk
#define  MindPWM_SMCR0_FORCE_INIT_Pos             (12)
#define  MindPWM_SMCR0_FORCE_INIT_Msk             (0x1U << MindPWM_SMCR0_FORCE_INIT_Pos)            /*!<*/
#define  MindPWM_SMCR0_FORCE_INIT                 MindPWM_SMCR0_FORCE_INIT_Msk
#define  MindPWM_SMCR0_PWMX_INIT_Pos              (13)
#define  MindPWM_SMCR0_PWMX_INIT_Msk              (0x1U << MindPWM_SMCR0_PWMX_INIT_Pos)             /*!<*/
#define  MindPWM_SMCR0_PWMX_INIT                  MindPWM_SMCR0_PWMX_INIT_Msk
#define  MindPWM_SMCR0_PWMA_INIT_Pos              (14)
#define  MindPWM_SMCR0_PWMA_INIT_Msk              (0x1U << MindPWM_SMCR0_PWMA_INIT_Pos)             /*!<*/
#define  MindPWM_SMCR0_PWMA_INIT                  MindPWM_SMCR0_PWMA_INIT_Msk
#define  MindPWM_SMCR0_PWMB_INIT_Pos              (15)
#define  MindPWM_SMCR0_PWMB_INIT_Msk              (0x1U << MindPWM_SMCR0_PWMB_INIT_Pos)             /*!<*/
#define  MindPWM_SMCR0_PWMB_INIT                  MindPWM_SMCR0_PWMB_INIT_Msk
#define  MindPWM_SMCR0_INIT_SEL_Pos               (16)
#define  MindPWM_SMCR0_INIT_SEL_Msk               (0xFU << MindPWM_SMCR0_INIT_SEL_Pos)              /*!<*/
#define  MindPWM_SMCR0_INIT_SEL                   MindPWM_SMCR0_INIT_SEL_Msk
#define  MindPWM_SMCR0_INIT_SEL_Bit0              (0x1U << MindPWM_SMCR0_INIT_SEL_Pos) 
#define  MindPWM_SMCR0_INIT_SEL_Bit1              (0x2U << MindPWM_SMCR0_INIT_SEL_Pos) 
#define  MindPWM_SMCR0_INIT_SEL_Bit2              (0x4U << MindPWM_SMCR0_INIT_SEL_Pos) 
#define  MindPWM_SMCR0_INIT_SEL_Bit3              (0x8U << MindPWM_SMCR0_INIT_SEL_Pos) 
#define  MindPWM_SMCR0_RELOAD_SEL_Pos             (24)
#define  MindPWM_SMCR0_RELOAD_SEL_Msk             (0x1U << MindPWM_SMCR0_RELOAD_SEL_Pos)            /*!<*/
#define  MindPWM_SMCR0_RELOAD_SEL                 MindPWM_SMCR0_RELOAD_SEL_Msk
#define  MindPWM_SMCR0_LDMOD_Pos                  (25)
#define  MindPWM_SMCR0_LDMOD_Msk                  (0x1U << MindPWM_SMCR0_LDMOD_Pos)                 /*!<*/
#define  MindPWM_SMCR0_LDMOD                      MindPWM_SMCR0_LDMOD_Msk
#define  MindPWM_SMCR0_FULL_Pos                   (26)
#define  MindPWM_SMCR0_FULL_Msk                   (0x1U << MindPWM_SMCR0_FULL_Pos)                  /*!<*/
#define  MindPWM_SMCR0_FULL                       MindPWM_SMCR0_FULL_Msk
#define  MindPWM_SMCR0_HALF_Pos                   (27)
#define  MindPWM_SMCR0_HALF_Msk                   (0x1U << MindPWM_SMCR0_HALF_Pos)                  /*!<*/
#define  MindPWM_SMCR0_HALF                       MindPWM_SMCR0_HALF_Msk
#define  MindPWM_SMCR0_LDFQ_Pos                   (28)
#define  MindPWM_SMCR0_LDFQ_Msk                   (0xFU << MindPWM_SMCR0_LDFQ_Pos)                  /*!<*/
#define  MindPWM_SMCR0_LDFQ                       MindPWM_SMCR0_LDFQ_Msk
#define  MindPWM_SMCR0_LDFQ_Bit0                  (0x1U << MindPWM_SMCR0_LDFQ_Pos) 
#define  MindPWM_SMCR0_LDFQ_Bit1                  (0x2U << MindPWM_SMCR0_LDFQ_Pos) 
#define  MindPWM_SMCR0_LDFQ_Bit2                  (0x4U << MindPWM_SMCR0_LDFQ_Pos) 
#define  MindPWM_SMCR0_LDFQ_Bit3                  (0x8U << MindPWM_SMCR0_LDFQ_Pos) 

/**
  * @brief MindPWM_SMCR1 Register Bit Definition
  */
#define  MindPWM_SMCR1_DBLEN_Pos                  (0)
#define  MindPWM_SMCR1_DBLEN_Msk                  (0x1U << MindPWM_SMCR1_DBLEN_Pos)                 /*!<*/
#define  MindPWM_SMCR1_DBLEN                      MindPWM_SMCR1_DBLEN_Msk
#define  MindPWM_SMCR1_DBLXEN_Pos                 (1)
#define  MindPWM_SMCR1_DBLXEN_Msk                 (0x1U << MindPWM_SMCR1_DBLXEN_Pos)                /*!<*/
#define  MindPWM_SMCR1_DBLXEN                     MindPWM_SMCR1_DBLXEN_Msk
#define  MindPWM_SMCR1_SPLIT_Pos                  (2)
#define  MindPWM_SMCR1_SPLIT_Msk                  (0x1U << MindPWM_SMCR1_SPLIT_Pos)                 /*!<*/
#define  MindPWM_SMCR1_SPLIT                      MindPWM_SMCR1_SPLIT_Msk
#define  MindPWM_SMCR1_COMPMOD_Pos                (3)
#define  MindPWM_SMCR1_COMPMOD_Msk                (0x1U << MindPWM_SMCR1_COMPMOD_Pos)               /*!<*/
#define  MindPWM_SMCR1_COMPMOD                    MindPWM_SMCR1_COMPMOD_Msk
#define  MindPWM_SMCR1_INDEP_Pos                  (4)
#define  MindPWM_SMCR1_INDEP_Msk                  (0x1U << MindPWM_SMCR1_INDEP_Pos)                 /*!<*/
#define  MindPWM_SMCR1_INDEP                      MindPWM_SMCR1_INDEP_Msk
#define  MindPWM_SMCR1_DT_Pos                     (14)
#define  MindPWM_SMCR1_DT_Msk                     (0x3U << MindPWM_SMCR1_DT_Pos)                    /*!<*/
#define  MindPWM_SMCR1_DT                         MindPWM_SMCR1_DT_Msk
#define  MindPWM_SMCR1_DT_Bit0                    (0x1U << MindPWM_SMCR1_DT_Pos) 
#define  MindPWM_SMCR1_DT_Bit1                    (0x2U << MindPWM_SMCR1_DT_Pos) 
#define  MindPWM_SMCR1_UDM_Pos                    (16)
#define  MindPWM_SMCR1_UDM_Msk                    (0x3U << MindPWM_SMCR1_UDM_Pos)                   /*!<*/
#define  MindPWM_SMCR1_UDM                        MindPWM_SMCR1_UDM_Msk
#define  MindPWM_SMCR1_UDM_Bit0                   (0x1U << MindPWM_SMCR1_UDM_Pos) 
#define  MindPWM_SMCR1_UDM_Bit1                   (0x2U << MindPWM_SMCR1_UDM_Pos) 
#define  MindPWM_SMCR1_UDM_CMPUP_Pos              (20)
#define  MindPWM_SMCR1_UDM_CMPUP_Msk              (0x1U << MindPWM_SMCR1_UDM_CMPUP_Pos)             /*!<*/
#define  MindPWM_SMCR1_UDM_CMPUP                  MindPWM_SMCR1_UDM_CMPUP_Msk
#define  MindPWM_SMCR1_UDM_CMPDN_Pos              (21)
#define  MindPWM_SMCR1_UDM_CMPDN_Msk              (0x1U << MindPWM_SMCR1_UDM_CMPDN_Pos)             /*!<*/
#define  MindPWM_SMCR1_UDM_CMPDN                  MindPWM_SMCR1_UDM_CMPDN_Msk
#define  MindPWM_SMCR1_UDM_FULL_CRESTS_Pos        (22)
#define  MindPWM_SMCR1_UDM_FULL_CRESTS_Msk        (0x1U << MindPWM_SMCR1_UDM_FULL_CRESTS_Pos)       /*!<*/
#define  MindPWM_SMCR1_UDM_FULL_CRESTS            MindPWM_SMCR1_UDM_FULL_CRESTS_Msk
#define  MindPWM_SMCR1_UDM_FULL_TROUGHS_Pos       (23)
#define  MindPWM_SMCR1_UDM_FULL_TROUGHS_Msk       (0x1U << MindPWM_SMCR1_UDM_FULL_TROUGHS_Pos)      /*!<*/
#define  MindPWM_SMCR1_UDM_FULL_TROUGHS           MindPWM_SMCR1_UDM_FULL_TROUGHS_Msk

/**
  * @brief MindPWM_SMOCR Register Bit Definition
  */
#define  MindPWM_SMOCR_PWMX_FS_Pos                (0)
#define  MindPWM_SMOCR_PWMX_FS_Msk                (0x3U << MindPWM_SMOCR_PWMX_FS_Pos)               /*!<*/
#define  MindPWM_SMOCR_PWMX_FS                    MindPWM_SMOCR_PWMX_FS_Msk
#define  MindPWM_SMOCR_PWMX_FS_Bit0               (0x1U << MindPWM_SMOCR_PWMX_FS_Pos) 
#define  MindPWM_SMOCR_PWMX_FS_Bit1               (0x2U << MindPWM_SMOCR_PWMX_FS_Pos) 
#define  MindPWM_SMOCR_PWMA_FS_Pos                (2)
#define  MindPWM_SMOCR_PWMA_FS_Msk                (0x3U << MindPWM_SMOCR_PWMA_FS_Pos)               /*!<*/
#define  MindPWM_SMOCR_PWMA_FS                    MindPWM_SMOCR_PWMA_FS_Msk
#define  MindPWM_SMOCR_PWMA_FS_Bit0               (0x1U << MindPWM_SMOCR_PWMA_FS_Pos) 
#define  MindPWM_SMOCR_PWMA_FS_Bit1               (0x2U << MindPWM_SMOCR_PWMA_FS_Pos) 
#define  MindPWM_SMOCR_PWMB_FS_Pos                (4)
#define  MindPWM_SMOCR_PWMB_FS_Msk                (0x3U << MindPWM_SMOCR_PWMB_FS_Pos)               /*!<*/
#define  MindPWM_SMOCR_PWMB_FS                    MindPWM_SMOCR_PWMB_FS_Msk
#define  MindPWM_SMOCR_PWMB_FS_Bit0               (0x1U << MindPWM_SMOCR_PWMB_FS_Pos) 
#define  MindPWM_SMOCR_PWMB_FS_Bit1               (0x2U << MindPWM_SMOCR_PWMB_FS_Pos) 
#define  MindPWM_SMOCR_POLX_Pos                   (8)
#define  MindPWM_SMOCR_POLX_Msk                   (0x1U << MindPWM_SMOCR_POLX_Pos)                  /*!<*/
#define  MindPWM_SMOCR_POLX                       MindPWM_SMOCR_POLX_Msk
#define  MindPWM_SMOCR_POLA_Pos                   (9)
#define  MindPWM_SMOCR_POLA_Msk                   (0x1U << MindPWM_SMOCR_POLA_Pos)                  /*!<*/
#define  MindPWM_SMOCR_POLA                       MindPWM_SMOCR_POLA_Msk
#define  MindPWM_SMOCR_POLB_Pos                   (10)
#define  MindPWM_SMOCR_POLB_Msk                   (0x1U << MindPWM_SMOCR_POLB_Pos)                  /*!<*/
#define  MindPWM_SMOCR_POLB                       MindPWM_SMOCR_POLB_Msk
#define  MindPWM_SMOCR_PWMX_DS_Pos                (16)
#define  MindPWM_SMOCR_PWMX_DS_Msk                (0x3U << MindPWM_SMOCR_PWMX_DS_Pos)               /*!<*/
#define  MindPWM_SMOCR_PWMX_DS                    MindPWM_SMOCR_PWMX_DS_Msk
#define  MindPWM_SMOCR_PWMX_DS_Bit0               (0x1U << MindPWM_SMOCR_PWMX_DS_Pos) 
#define  MindPWM_SMOCR_PWMX_DS_Bit1               (0x2U << MindPWM_SMOCR_PWMX_DS_Pos) 
#define  MindPWM_SMOCR_PWMA_DS_Pos                (18)
#define  MindPWM_SMOCR_PWMA_DS_Msk                (0x3U << MindPWM_SMOCR_PWMA_DS_Pos)               /*!<*/
#define  MindPWM_SMOCR_PWMA_DS                    MindPWM_SMOCR_PWMA_DS_Msk
#define  MindPWM_SMOCR_PWMA_DS_Bit0               (0x1U << MindPWM_SMOCR_PWMA_DS_Pos) 
#define  MindPWM_SMOCR_PWMA_DS_Bit1               (0x2U << MindPWM_SMOCR_PWMA_DS_Pos) 
#define  MindPWM_SMOCR_PWMB_DS_Pos                (20)
#define  MindPWM_SMOCR_PWMB_DS_Msk                (0x3U << MindPWM_SMOCR_PWMB_DS_Pos)               /*!<*/
#define  MindPWM_SMOCR_PWMB_DS                    MindPWM_SMOCR_PWMB_DS_Msk
#define  MindPWM_SMOCR_PWMB_DS_Bit0               (0x1U << MindPWM_SMOCR_PWMB_DS_Pos) 
#define  MindPWM_SMOCR_PWMB_DS_Bit1               (0x2U << MindPWM_SMOCR_PWMB_DS_Pos) 
#define  MindPWM_SMOCR_SLEEPEN_Pos                (30)
#define  MindPWM_SMOCR_SLEEPEN_Msk                (0x1U << MindPWM_SMOCR_SLEEPEN_Pos)               /*!<*/
#define  MindPWM_SMOCR_SLEEPEN                    MindPWM_SMOCR_SLEEPEN_Msk
#define  MindPWM_SMOCR_DBGEN_Pos                  (31)
#define  MindPWM_SMOCR_DBGEN_Msk                  (0x1U << MindPWM_SMOCR_DBGEN_Pos)                 /*!<*/
#define  MindPWM_SMOCR_DBGEN                      MindPWM_SMOCR_DBGEN_Msk

/**
  * @brief MindPWM_SMCNT Register Bit Definition
  */
#define  MindPWM_SMCNT_CNT_Pos                    (0)
#define  MindPWM_SMCNT_CNT_Msk                    (0xFFFFU << MindPWM_SMCNT_CNT_Pos)                /*!<*/
#define  MindPWM_SMCNT_CNT                        MindPWM_SMCNT_CNT_Msk
#define  MindPWM_SMCNT_CNT_Bit0                   (0x0001U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit1                   (0x0002U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit2                   (0x0004U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit3                   (0x0008U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit4                   (0x0010U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit5                   (0x0020U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit6                   (0x0040U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit7                   (0x0080U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit8                   (0x0100U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit9                   (0x0200U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit10                  (0x0400U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit11                  (0x0800U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit12                  (0x1000U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit13                  (0x2000U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit14                  (0x4000U << MindPWM_SMCNT_CNT_Pos) 
#define  MindPWM_SMCNT_CNT_Bit15                  (0x8000U << MindPWM_SMCNT_CNT_Pos) 

/**
  * @brief MindPWM_SMINIT Register Bit Definition
  */
#define  MindPWM_SMINIT_INIT_Pos                  (0)
#define  MindPWM_SMINIT_INIT_Msk                  (0xFFFFU << MindPWM_SMINIT_INIT_Pos)              /*!<*/
#define  MindPWM_SMINIT_INIT                      MindPWM_SMINIT_INIT_Msk
#define  MindPWM_SMINIT_INIT_Bit0                 (0x0001U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit1                 (0x0002U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit2                 (0x0004U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit3                 (0x0008U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit4                 (0x0010U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit5                 (0x0020U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit6                 (0x0040U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit7                 (0x0080U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit8                 (0x0100U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit9                 (0x0200U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit10                (0x0400U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit11                (0x0800U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit12                (0x1000U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit13                (0x2000U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit14                (0x4000U << MindPWM_SMINIT_INIT_Pos) 
#define  MindPWM_SMINIT_INIT_Bit15                (0x8000U << MindPWM_SMINIT_INIT_Pos) 

/**
  * @brief MindPWM_SMVAL0 Register Bit Definition
  */
#define  MindPWM_SMVAL0_VAL0_Pos                  (0)
#define  MindPWM_SMVAL0_VAL0_Msk                  (0xFFFFU << MindPWM_SMVAL0_VAL0_Pos)              /*!<*/
#define  MindPWM_SMVAL0_VAL0                      MindPWM_SMVAL0_VAL0_Msk
#define  MindPWM_SMVAL0_VAL0_Bit0                 (0x0001U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit1                 (0x0002U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit2                 (0x0004U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit3                 (0x0008U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit4                 (0x0010U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit5                 (0x0020U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit6                 (0x0040U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit7                 (0x0080U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit8                 (0x0100U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit9                 (0x0200U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit10                (0x0400U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit11                (0x0800U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit12                (0x1000U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit13                (0x2000U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit14                (0x4000U << MindPWM_SMVAL0_VAL0_Pos) 
#define  MindPWM_SMVAL0_VAL0_Bit15                (0x8000U << MindPWM_SMVAL0_VAL0_Pos) 

/**
  * @brief MindPWM_SMVAL1 Register Bit Definition
  */
#define  MindPWM_SMVAL1_VAL1_Pos                  (0)
#define  MindPWM_SMVAL1_VAL1_Msk                  (0xFFFFU << MindPWM_SMVAL1_VAL1_Pos)              /*!<*/
#define  MindPWM_SMVAL1_VAL1                      MindPWM_SMVAL1_VAL1_Msk
#define  MindPWM_SMVAL1_VAL1_Bit0                 (0x0001U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit1                 (0x0002U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit2                 (0x0004U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit3                 (0x0008U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit4                 (0x0010U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit5                 (0x0020U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit6                 (0x0040U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit7                 (0x0080U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit8                 (0x0100U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit9                 (0x0200U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit10                (0x0400U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit11                (0x0800U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit12                (0x1000U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit13                (0x2000U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit14                (0x4000U << MindPWM_SMVAL1_VAL1_Pos) 
#define  MindPWM_SMVAL1_VAL1_Bit15                (0x8000U << MindPWM_SMVAL1_VAL1_Pos) 

/**
  * @brief MindPWM_SMVAL2 Register Bit Definition
  */
#define  MindPWM_SMVAL2_VAL2_Pos                  (0)
#define  MindPWM_SMVAL2_VAL2_Msk                  (0xFFFFU << MindPWM_SMVAL2_VAL2_Pos)              /*!<*/
#define  MindPWM_SMVAL2_VAL2                      MindPWM_SMVAL2_VAL2_Msk
#define  MindPWM_SMVAL2_VAL2_Bit0                 (0x0001U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit1                 (0x0002U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit2                 (0x0004U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit3                 (0x0008U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit4                 (0x0010U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit5                 (0x0020U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit6                 (0x0040U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit7                 (0x0080U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit8                 (0x0100U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit9                 (0x0200U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit10                (0x0400U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit11                (0x0800U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit12                (0x1000U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit13                (0x2000U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit14                (0x4000U << MindPWM_SMVAL2_VAL2_Pos) 
#define  MindPWM_SMVAL2_VAL2_Bit15                (0x8000U << MindPWM_SMVAL2_VAL2_Pos) 

/**
  * @brief MindPWM_SMVAL3 Register Bit Definition
  */
#define  MindPWM_SMVAL3_VAL3_Pos                  (0)
#define  MindPWM_SMVAL3_VAL3_Msk                  (0xFFFFU << MindPWM_SMVAL3_VAL3_Pos)              /*!<*/
#define  MindPWM_SMVAL3_VAL3                      MindPWM_SMVAL3_VAL3_Msk
#define  MindPWM_SMVAL3_VAL3_Bit0                 (0x0001U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit1                 (0x0002U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit2                 (0x0004U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit3                 (0x0008U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit4                 (0x0010U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit5                 (0x0020U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit6                 (0x0040U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit7                 (0x0080U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit8                 (0x0100U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit9                 (0x0200U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit10                (0x0400U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit11                (0x0800U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit12                (0x1000U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit13                (0x2000U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit14                (0x4000U << MindPWM_SMVAL3_VAL3_Pos) 
#define  MindPWM_SMVAL3_VAL3_Bit15                (0x8000U << MindPWM_SMVAL3_VAL3_Pos) 

/**
  * @brief MindPWM_SMVAL4 Register Bit Definition
  */
#define  MindPWM_SMVAL4_VAL4_Pos                  (0)
#define  MindPWM_SMVAL4_VAL4_Msk                  (0xFFFFU << MindPWM_SMVAL4_VAL4_Pos)              /*!<*/
#define  MindPWM_SMVAL4_VAL4                      MindPWM_SMVAL4_VAL4_Msk
#define  MindPWM_SMVAL4_VAL4_Bit0                 (0x0001U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit1                 (0x0002U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit2                 (0x0004U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit3                 (0x0008U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit4                 (0x0010U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit5                 (0x0020U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit6                 (0x0040U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit7                 (0x0080U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit8                 (0x0100U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit9                 (0x0200U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit10                (0x0400U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit11                (0x0800U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit12                (0x1000U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit13                (0x2000U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit14                (0x4000U << MindPWM_SMVAL4_VAL4_Pos) 
#define  MindPWM_SMVAL4_VAL4_Bit15                (0x8000U << MindPWM_SMVAL4_VAL4_Pos) 

/**
  * @brief MindPWM_SMVAL5 Register Bit Definition
  */
#define  MindPWM_SMVAL5_VAL5_Pos                  (0)
#define  MindPWM_SMVAL5_VAL5_Msk                  (0xFFFFU << MindPWM_SMVAL5_VAL5_Pos)              /*!<*/
#define  MindPWM_SMVAL5_VAL5                      MindPWM_SMVAL5_VAL5_Msk
#define  MindPWM_SMVAL5_VAL5_Bit0                 (0x0001U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit1                 (0x0002U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit2                 (0x0004U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit3                 (0x0008U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit4                 (0x0010U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit5                 (0x0020U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit6                 (0x0040U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit7                 (0x0080U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit8                 (0x0100U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit9                 (0x0200U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit10                (0x0400U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit11                (0x0800U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit12                (0x1000U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit13                (0x2000U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit14                (0x4000U << MindPWM_SMVAL5_VAL5_Pos) 
#define  MindPWM_SMVAL5_VAL5_Bit15                (0x8000U << MindPWM_SMVAL5_VAL5_Pos) 

/**
  * @brief MindPWM_SMFRCR0 Register Bit Definition
  */
#define  MindPWM_SMFRCR0_FRAC1_EN_Pos             (0)
#define  MindPWM_SMFRCR0_FRAC1_EN_Msk             (0x1U << MindPWM_SMFRCR0_FRAC1_EN_Pos)            /*!<*/
#define  MindPWM_SMFRCR0_FRAC1_EN                 MindPWM_SMFRCR0_FRAC1_EN_Msk
#define  MindPWM_SMFRCR0_FRAC23_EN_Pos            (1)
#define  MindPWM_SMFRCR0_FRAC23_EN_Msk            (0x1U << MindPWM_SMFRCR0_FRAC23_EN_Pos)           /*!<*/
#define  MindPWM_SMFRCR0_FRAC23_EN                MindPWM_SMFRCR0_FRAC23_EN_Msk
#define  MindPWM_SMFRCR0_FRAC45_EN_Pos            (2)
#define  MindPWM_SMFRCR0_FRAC45_EN_Msk            (0x1U << MindPWM_SMFRCR0_FRAC45_EN_Pos)           /*!<*/
#define  MindPWM_SMFRCR0_FRAC45_EN                MindPWM_SMFRCR0_FRAC45_EN_Msk
#define  MindPWM_SMFRCR0_FRAC_PU_Pos              (8)
#define  MindPWM_SMFRCR0_FRAC_PU_Msk              (0x1U << MindPWM_SMFRCR0_FRAC_PU_Pos)             /*!<*/
#define  MindPWM_SMFRCR0_FRAC_PU                  MindPWM_SMFRCR0_FRAC_PU_Msk
#define  MindPWM_SMFRCR0_FRACVAL1_Pos             (19)
#define  MindPWM_SMFRCR0_FRACVAL1_Msk             (0x1FU << MindPWM_SMFRCR0_FRACVAL1_Pos)           /*!<*/
#define  MindPWM_SMFRCR0_FRACVAL1                 MindPWM_SMFRCR0_FRACVAL1_Msk
#define  MindPWM_SMFRCR0_FRACVAL1_Bit0            (0x01U << MindPWM_SMFRCR0_FRACVAL1_Pos) 
#define  MindPWM_SMFRCR0_FRACVAL1_Bit1            (0x02U << MindPWM_SMFRCR0_FRACVAL1_Pos) 
#define  MindPWM_SMFRCR0_FRACVAL1_Bit2            (0x04U << MindPWM_SMFRCR0_FRACVAL1_Pos) 
#define  MindPWM_SMFRCR0_FRACVAL1_Bit3            (0x08U << MindPWM_SMFRCR0_FRACVAL1_Pos) 
#define  MindPWM_SMFRCR0_FRACVAL1_Bit4            (0x10U << MindPWM_SMFRCR0_FRACVAL1_Pos) 

/**
  * @brief MindPWM_SMFRCR1 Register Bit Definition
  */
#define  MindPWM_SMFRCR1_FRACVAL2_Pos             (3)
#define  MindPWM_SMFRCR1_FRACVAL2_Msk             (0x1FU << MindPWM_SMFRCR1_FRACVAL2_Pos)           /*!<*/
#define  MindPWM_SMFRCR1_FRACVAL2                 MindPWM_SMFRCR1_FRACVAL2_Msk
#define  MindPWM_SMFRCR1_FRACVAL2_Bit0            (0x01U << MindPWM_SMFRCR1_FRACVAL2_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL2_Bit1            (0x02U << MindPWM_SMFRCR1_FRACVAL2_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL2_Bit2            (0x04U << MindPWM_SMFRCR1_FRACVAL2_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL2_Bit3            (0x08U << MindPWM_SMFRCR1_FRACVAL2_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL2_Bit4            (0x10U << MindPWM_SMFRCR1_FRACVAL2_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL3_Pos             (11)
#define  MindPWM_SMFRCR1_FRACVAL3_Msk             (0x1FU << MindPWM_SMFRCR1_FRACVAL3_Pos)           /*!<*/
#define  MindPWM_SMFRCR1_FRACVAL3                 MindPWM_SMFRCR1_FRACVAL3_Msk
#define  MindPWM_SMFRCR1_FRACVAL3_Bit0            (0x01U << MindPWM_SMFRCR1_FRACVAL3_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL3_Bit1            (0x02U << MindPWM_SMFRCR1_FRACVAL3_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL3_Bit2            (0x04U << MindPWM_SMFRCR1_FRACVAL3_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL3_Bit3            (0x08U << MindPWM_SMFRCR1_FRACVAL3_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL3_Bit4            (0x10U << MindPWM_SMFRCR1_FRACVAL3_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL4_Pos             (19)
#define  MindPWM_SMFRCR1_FRACVAL4_Msk             (0x1FU << MindPWM_SMFRCR1_FRACVAL4_Pos)           /*!<*/
#define  MindPWM_SMFRCR1_FRACVAL4                 MindPWM_SMFRCR1_FRACVAL4_Msk
#define  MindPWM_SMFRCR1_FRACVAL4_Bit0            (0x01U << MindPWM_SMFRCR1_FRACVAL4_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL4_Bit1            (0x02U << MindPWM_SMFRCR1_FRACVAL4_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL4_Bit2            (0x04U << MindPWM_SMFRCR1_FRACVAL4_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL4_Bit3            (0x08U << MindPWM_SMFRCR1_FRACVAL4_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL4_Bit4            (0x10U << MindPWM_SMFRCR1_FRACVAL4_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL5_Pos             (27)
#define  MindPWM_SMFRCR1_FRACVAL5_Msk             (0x1FU << MindPWM_SMFRCR1_FRACVAL5_Pos)           /*!<*/
#define  MindPWM_SMFRCR1_FRACVAL5                 MindPWM_SMFRCR1_FRACVAL5_Msk
#define  MindPWM_SMFRCR1_FRACVAL5_Bit0            (0x01U << MindPWM_SMFRCR1_FRACVAL5_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL5_Bit1            (0x02U << MindPWM_SMFRCR1_FRACVAL5_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL5_Bit2            (0x04U << MindPWM_SMFRCR1_FRACVAL5_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL5_Bit3            (0x08U << MindPWM_SMFRCR1_FRACVAL5_Pos) 
#define  MindPWM_SMFRCR1_FRACVAL5_Bit4            (0x10U << MindPWM_SMFRCR1_FRACVAL5_Pos) 

/**
  * @brief MindPWM_SMSR Register Bit Definition
  */
#define  MindPWM_SMSR_CMP0F_Pos                   (0)
#define  MindPWM_SMSR_CMP0F_Msk                   (0x1U << MindPWM_SMSR_CMP0F_Pos)                  /*!<*/
#define  MindPWM_SMSR_CMP0F                       MindPWM_SMSR_CMP0F_Msk
#define  MindPWM_SMSR_CMP1F_Pos                   (1)
#define  MindPWM_SMSR_CMP1F_Msk                   (0x1U << MindPWM_SMSR_CMP1F_Pos)                  /*!<*/
#define  MindPWM_SMSR_CMP1F                       MindPWM_SMSR_CMP1F_Msk
#define  MindPWM_SMSR_CMP2F_Pos                   (2)
#define  MindPWM_SMSR_CMP2F_Msk                   (0x1U << MindPWM_SMSR_CMP2F_Pos)                  /*!<*/
#define  MindPWM_SMSR_CMP2F                       MindPWM_SMSR_CMP2F_Msk
#define  MindPWM_SMSR_CMP3F_Pos                   (3)
#define  MindPWM_SMSR_CMP3F_Msk                   (0x1U << MindPWM_SMSR_CMP3F_Pos)                  /*!<*/
#define  MindPWM_SMSR_CMP3F                       MindPWM_SMSR_CMP3F_Msk
#define  MindPWM_SMSR_CMP4F_Pos                   (4)
#define  MindPWM_SMSR_CMP4F_Msk                   (0x1U << MindPWM_SMSR_CMP4F_Pos)                  /*!<*/
#define  MindPWM_SMSR_CMP4F                       MindPWM_SMSR_CMP4F_Msk
#define  MindPWM_SMSR_CMP5F_Pos                   (5)
#define  MindPWM_SMSR_CMP5F_Msk                   (0x1U << MindPWM_SMSR_CMP5F_Pos)                  /*!<*/
#define  MindPWM_SMSR_CMP5F                       MindPWM_SMSR_CMP5F_Msk
#define  MindPWM_SMSR_CX0F_Pos                    (6)
#define  MindPWM_SMSR_CX0F_Msk                    (0x1U << MindPWM_SMSR_CX0F_Pos)                   /*!<*/
#define  MindPWM_SMSR_CX0F                        MindPWM_SMSR_CX0F_Msk
#define  MindPWM_SMSR_CX1F_Pos                    (7)
#define  MindPWM_SMSR_CX1F_Msk                    (0x1U << MindPWM_SMSR_CX1F_Pos)                   /*!<*/
#define  MindPWM_SMSR_CX1F                        MindPWM_SMSR_CX1F_Msk
#define  MindPWM_SMSR_CA0F_Pos                    (8)
#define  MindPWM_SMSR_CA0F_Msk                    (0x1U << MindPWM_SMSR_CA0F_Pos)                   /*!<*/
#define  MindPWM_SMSR_CA0F                        MindPWM_SMSR_CA0F_Msk
#define  MindPWM_SMSR_CA1F_Pos                    (9)
#define  MindPWM_SMSR_CA1F_Msk                    (0x1U << MindPWM_SMSR_CA1F_Pos)                   /*!<*/
#define  MindPWM_SMSR_CA1F                        MindPWM_SMSR_CA1F_Msk
#define  MindPWM_SMSR_CB0F_Pos                    (10)
#define  MindPWM_SMSR_CB0F_Msk                    (0x1U << MindPWM_SMSR_CB0F_Pos)                   /*!<*/
#define  MindPWM_SMSR_CB0F                        MindPWM_SMSR_CB0F_Msk
#define  MindPWM_SMSR_CB1F_Pos                    (11)
#define  MindPWM_SMSR_CB1F_Msk                    (0x1U << MindPWM_SMSR_CB1F_Pos)                   /*!<*/
#define  MindPWM_SMSR_CB1F                        MindPWM_SMSR_CB1F_Msk
#define  MindPWM_SMSR_RF_Pos                      (12)
#define  MindPWM_SMSR_RF_Msk                      (0x1U << MindPWM_SMSR_RF_Pos)                     /*!<*/
#define  MindPWM_SMSR_RF                          MindPWM_SMSR_RF_Msk
#define  MindPWM_SMSR_REF_Pos                     (13)
#define  MindPWM_SMSR_REF_Msk                     (0x1U << MindPWM_SMSR_REF_Pos)                    /*!<*/
#define  MindPWM_SMSR_REF                         MindPWM_SMSR_REF_Msk
#define  MindPWM_SMSR_RUF_Pos                     (14)
#define  MindPWM_SMSR_RUF_Msk                     (0x1U << MindPWM_SMSR_RUF_Pos)                    /*!<*/
#define  MindPWM_SMSR_RUF                         MindPWM_SMSR_RUF_Msk
#define  MindPWM_SMSR_PWMX_IN_Pos                 (16)
#define  MindPWM_SMSR_PWMX_IN_Msk                 (0x1U << MindPWM_SMSR_PWMX_IN_Pos)                /*!<*/
#define  MindPWM_SMSR_PWMX_IN                     MindPWM_SMSR_PWMX_IN_Msk
#define  MindPWM_SMSR_PWMA_IN_Pos                 (17)
#define  MindPWM_SMSR_PWMA_IN_Msk                 (0x1U << MindPWM_SMSR_PWMA_IN_Pos)                /*!<*/
#define  MindPWM_SMSR_PWMA_IN                     MindPWM_SMSR_PWMA_IN_Msk
#define  MindPWM_SMSR_PWMB_IN_Pos                 (18)
#define  MindPWM_SMSR_PWMB_IN_Msk                 (0x1U << MindPWM_SMSR_PWMB_IN_Pos)                /*!<*/
#define  MindPWM_SMSR_PWMB_IN                     MindPWM_SMSR_PWMB_IN_Msk

/**
  * @brief MindPWM_SMINTE Register Bit Definition
  */
#define  MindPWM_SMINTE_CMP0IE_Pos                (0)
#define  MindPWM_SMINTE_CMP0IE_Msk                (0x1U << MindPWM_SMINTE_CMP0IE_Pos)               /*!<*/
#define  MindPWM_SMINTE_CMP0IE                    MindPWM_SMINTE_CMP0IE_Msk
#define  MindPWM_SMINTE_CMP1IE_Pos                (1)
#define  MindPWM_SMINTE_CMP1IE_Msk                (0x1U << MindPWM_SMINTE_CMP1IE_Pos)               /*!<*/
#define  MindPWM_SMINTE_CMP1IE                    MindPWM_SMINTE_CMP1IE_Msk
#define  MindPWM_SMINTE_CMP2IE_Pos                (2)
#define  MindPWM_SMINTE_CMP2IE_Msk                (0x1U << MindPWM_SMINTE_CMP2IE_Pos)               /*!<*/
#define  MindPWM_SMINTE_CMP2IE                    MindPWM_SMINTE_CMP2IE_Msk
#define  MindPWM_SMINTE_CMP3IE_Pos                (3)
#define  MindPWM_SMINTE_CMP3IE_Msk                (0x1U << MindPWM_SMINTE_CMP3IE_Pos)               /*!<*/
#define  MindPWM_SMINTE_CMP3IE                    MindPWM_SMINTE_CMP3IE_Msk
#define  MindPWM_SMINTE_CMP4IE_Pos                (4)
#define  MindPWM_SMINTE_CMP4IE_Msk                (0x1U << MindPWM_SMINTE_CMP4IE_Pos)               /*!<*/
#define  MindPWM_SMINTE_CMP4IE                    MindPWM_SMINTE_CMP4IE_Msk
#define  MindPWM_SMINTE_CMP5IE_Pos                (5)
#define  MindPWM_SMINTE_CMP5IE_Msk                (0x1U << MindPWM_SMINTE_CMP5IE_Pos)               /*!<*/
#define  MindPWM_SMINTE_CMP5IE                    MindPWM_SMINTE_CMP5IE_Msk
#define  MindPWM_SMINTE_CX0IE_Pos                 (6)
#define  MindPWM_SMINTE_CX0IE_Msk                 (0x1U << MindPWM_SMINTE_CX0IE_Pos)                /*!<*/
#define  MindPWM_SMINTE_CX0IE                     MindPWM_SMINTE_CX0IE_Msk
#define  MindPWM_SMINTE_CX1IE_Pos                 (7)
#define  MindPWM_SMINTE_CX1IE_Msk                 (0x1U << MindPWM_SMINTE_CX1IE_Pos)                /*!<*/
#define  MindPWM_SMINTE_CX1IE                     MindPWM_SMINTE_CX1IE_Msk
#define  MindPWM_SMINTE_CA0IE_Pos                 (8)
#define  MindPWM_SMINTE_CA0IE_Msk                 (0x1U << MindPWM_SMINTE_CA0IE_Pos)                /*!<*/
#define  MindPWM_SMINTE_CA0IE                     MindPWM_SMINTE_CA0IE_Msk
#define  MindPWM_SMINTE_CA1IE_Pos                 (9)
#define  MindPWM_SMINTE_CA1IE_Msk                 (0x1U << MindPWM_SMINTE_CA1IE_Pos)                /*!<*/
#define  MindPWM_SMINTE_CA1IE                     MindPWM_SMINTE_CA1IE_Msk
#define  MindPWM_SMINTE_CB0IE_Pos                 (10)
#define  MindPWM_SMINTE_CB0IE_Msk                 (0x1U << MindPWM_SMINTE_CB0IE_Pos)                /*!<*/
#define  MindPWM_SMINTE_CB0IE                     MindPWM_SMINTE_CB0IE_Msk
#define  MindPWM_SMINTE_CB1IE_Pos                 (11)
#define  MindPWM_SMINTE_CB1IE_Msk                 (0x1U << MindPWM_SMINTE_CB1IE_Pos)                /*!<*/
#define  MindPWM_SMINTE_CB1IE                     MindPWM_SMINTE_CB1IE_Msk
#define  MindPWM_SMINTE_RIE_Pos                   (12)
#define  MindPWM_SMINTE_RIE_Msk                   (0x1U << MindPWM_SMINTE_RIE_Pos)                  /*!<*/
#define  MindPWM_SMINTE_RIE                       MindPWM_SMINTE_RIE_Msk
#define  MindPWM_SMINTE_REIE_Pos                  (13)
#define  MindPWM_SMINTE_REIE_Msk                  (0x1U << MindPWM_SMINTE_REIE_Pos)                 /*!<*/
#define  MindPWM_SMINTE_REIE                      MindPWM_SMINTE_REIE_Msk

/**
  * @brief MindPWM_SMDMAE Register Bit Definition
  */
#define  MindPWM_SMDMAE_CX0DE_Pos                 (0)
#define  MindPWM_SMDMAE_CX0DE_Msk                 (0x1U << MindPWM_SMDMAE_CX0DE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_CX0DE                     MindPWM_SMDMAE_CX0DE_Msk
#define  MindPWM_SMDMAE_CX1DE_Pos                 (1)
#define  MindPWM_SMDMAE_CX1DE_Msk                 (0x1U << MindPWM_SMDMAE_CX1DE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_CX1DE                     MindPWM_SMDMAE_CX1DE_Msk
#define  MindPWM_SMDMAE_CA0DE_Pos                 (2)
#define  MindPWM_SMDMAE_CA0DE_Msk                 (0x1U << MindPWM_SMDMAE_CA0DE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_CA0DE                     MindPWM_SMDMAE_CA0DE_Msk
#define  MindPWM_SMDMAE_CA1DE_Pos                 (3)
#define  MindPWM_SMDMAE_CA1DE_Msk                 (0x1U << MindPWM_SMDMAE_CA1DE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_CA1DE                     MindPWM_SMDMAE_CA1DE_Msk
#define  MindPWM_SMDMAE_CB0DE_Pos                 (4)
#define  MindPWM_SMDMAE_CB0DE_Msk                 (0x1U << MindPWM_SMDMAE_CB0DE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_CB0DE                     MindPWM_SMDMAE_CB0DE_Msk
#define  MindPWM_SMDMAE_CB1DE_Pos                 (5)
#define  MindPWM_SMDMAE_CB1DE_Msk                 (0x1U << MindPWM_SMDMAE_CB1DE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_CB1DE                     MindPWM_SMDMAE_CB1DE_Msk
#define  MindPWM_SMDMAE_CAPTDE_Pos                (6)
#define  MindPWM_SMDMAE_CAPTDE_Msk                (0x3U << MindPWM_SMDMAE_CAPTDE_Pos)               /*!<*/
#define  MindPWM_SMDMAE_CAPTDE                    MindPWM_SMDMAE_CAPTDE_Msk
#define  MindPWM_SMDMAE_CAPTDE_Bit0               (0x1U << MindPWM_SMDMAE_CAPTDE_Pos) 
#define  MindPWM_SMDMAE_CAPTDE_Bit1               (0x2U << MindPWM_SMDMAE_CAPTDE_Pos) 
#define  MindPWM_SMDMAE_FAND_Pos                  (8)
#define  MindPWM_SMDMAE_FAND_Msk                  (0x1U << MindPWM_SMDMAE_FAND_Pos)                 /*!<*/
#define  MindPWM_SMDMAE_FAND                      MindPWM_SMDMAE_FAND_Msk
#define  MindPWM_SMDMAE_VALDE_Pos                 (9)
#define  MindPWM_SMDMAE_VALDE_Msk                 (0x1U << MindPWM_SMDMAE_VALDE_Pos)                /*!<*/
#define  MindPWM_SMDMAE_VALDE                     MindPWM_SMDMAE_VALDE_Msk

/**
  * @brief MindPWM_SMTRGCR Register Bit Definition
  */
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Pos          (0)
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Msk          (0x3FU << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos)        /*!<*/
#define  MindPWM_SMTRGCR_OUT_TRIG_EN              MindPWM_SMTRGCR_OUT_TRIG_EN_Msk
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Bit0         (0x01U << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos) 
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Bit1         (0x02U << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos) 
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Bit2         (0x04U << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos) 
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Bit3         (0x08U << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos) 
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Bit4         (0x10U << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos) 
#define  MindPWM_SMTRGCR_OUT_TRIG_EN_Bit5         (0x20U << MindPWM_SMTRGCR_OUT_TRIG_EN_Pos) 
#define  MindPWM_SMTRGCR_TRGFRQ_Pos               (8)
#define  MindPWM_SMTRGCR_TRGFRQ_Msk               (0x1U << MindPWM_SMTRGCR_TRGFRQ_Pos)              /*!<*/
#define  MindPWM_SMTRGCR_TRGFRQ                   MindPWM_SMTRGCR_TRGFRQ_Msk
#define  MindPWM_SMTRGCR_OT0_SEL_Pos              (10)
#define  MindPWM_SMTRGCR_OT0_SEL_Msk              (0x3U << MindPWM_SMTRGCR_OT0_SEL_Pos)             /*!<*/
#define  MindPWM_SMTRGCR_OT0_SEL                  MindPWM_SMTRGCR_OT0_SEL_Msk
#define  MindPWM_SMTRGCR_OT0_SEL_Bit0             (0x1U << MindPWM_SMTRGCR_OT0_SEL_Pos) 
#define  MindPWM_SMTRGCR_OT0_SEL_Bit1             (0x2U << MindPWM_SMTRGCR_OT0_SEL_Pos) 
#define  MindPWM_SMTRGCR_OT1_SEL_Pos              (13)
#define  MindPWM_SMTRGCR_OT1_SEL_Msk              (0x3U << MindPWM_SMTRGCR_OT1_SEL_Pos)             /*!<*/
#define  MindPWM_SMTRGCR_OT1_SEL                  MindPWM_SMTRGCR_OT1_SEL_Msk
#define  MindPWM_SMTRGCR_OT1_SEL_Bit0             (0x1U << MindPWM_SMTRGCR_OT1_SEL_Pos) 
#define  MindPWM_SMTRGCR_OT1_SEL_Bit1             (0x2U << MindPWM_SMTRGCR_OT1_SEL_Pos) 

/**
  * @brief MindPWM_SMFDIS0 Register Bit Definition
  */
#define  MindPWM_SMFDIS0_FDISX0_Pos               (0)
#define  MindPWM_SMFDIS0_FDISX0_Msk               (0xFU << MindPWM_SMFDIS0_FDISX0_Pos)              /*!<*/
#define  MindPWM_SMFDIS0_FDISX0                   MindPWM_SMFDIS0_FDISX0_Msk
#define  MindPWM_SMFDIS0_FDISX0_Bit0              (0x1U << MindPWM_SMFDIS0_FDISX0_Pos) 
#define  MindPWM_SMFDIS0_FDISX0_Bit1              (0x2U << MindPWM_SMFDIS0_FDISX0_Pos) 
#define  MindPWM_SMFDIS0_FDISX0_Bit2              (0x4U << MindPWM_SMFDIS0_FDISX0_Pos) 
#define  MindPWM_SMFDIS0_FDISX0_Bit3              (0x8U << MindPWM_SMFDIS0_FDISX0_Pos) 
#define  MindPWM_SMFDIS0_FDISA0_Pos               (4)
#define  MindPWM_SMFDIS0_FDISA0_Msk               (0xFU << MindPWM_SMFDIS0_FDISA0_Pos)              /*!<*/
#define  MindPWM_SMFDIS0_FDISA0                   MindPWM_SMFDIS0_FDISA0_Msk
#define  MindPWM_SMFDIS0_FDISA0_Bit0              (0x1U << MindPWM_SMFDIS0_FDISA0_Pos) 
#define  MindPWM_SMFDIS0_FDISA0_Bit1              (0x2U << MindPWM_SMFDIS0_FDISA0_Pos) 
#define  MindPWM_SMFDIS0_FDISA0_Bit2              (0x4U << MindPWM_SMFDIS0_FDISA0_Pos) 
#define  MindPWM_SMFDIS0_FDISA0_Bit3              (0x8U << MindPWM_SMFDIS0_FDISA0_Pos) 
#define  MindPWM_SMFDIS0_FDISB0_Pos               (8)
#define  MindPWM_SMFDIS0_FDISB0_Msk               (0xFU << MindPWM_SMFDIS0_FDISB0_Pos)              /*!<*/
#define  MindPWM_SMFDIS0_FDISB0                   MindPWM_SMFDIS0_FDISB0_Msk
#define  MindPWM_SMFDIS0_FDISB0_Bit0              (0x1U << MindPWM_SMFDIS0_FDISB0_Pos) 
#define  MindPWM_SMFDIS0_FDISB0_Bit1              (0x2U << MindPWM_SMFDIS0_FDISB0_Pos) 
#define  MindPWM_SMFDIS0_FDISB0_Bit2              (0x4U << MindPWM_SMFDIS0_FDISB0_Pos) 
#define  MindPWM_SMFDIS0_FDISB0_Bit3              (0x8U << MindPWM_SMFDIS0_FDISB0_Pos) 
#define  MindPWM_SMFDIS0_FDISX1_Pos               (16)
#define  MindPWM_SMFDIS0_FDISX1_Msk               (0xFU << MindPWM_SMFDIS0_FDISX1_Pos)              /*!<*/
#define  MindPWM_SMFDIS0_FDISX1                   MindPWM_SMFDIS0_FDISX1_Msk
#define  MindPWM_SMFDIS0_FDISX1_Bit0              (0x1U << MindPWM_SMFDIS0_FDISX1_Pos) 
#define  MindPWM_SMFDIS0_FDISX1_Bit1              (0x2U << MindPWM_SMFDIS0_FDISX1_Pos) 
#define  MindPWM_SMFDIS0_FDISX1_Bit2              (0x4U << MindPWM_SMFDIS0_FDISX1_Pos) 
#define  MindPWM_SMFDIS0_FDISX1_Bit3              (0x8U << MindPWM_SMFDIS0_FDISX1_Pos) 
#define  MindPWM_SMFDIS0_FDISA1_Pos               (20)
#define  MindPWM_SMFDIS0_FDISA1_Msk               (0xFU << MindPWM_SMFDIS0_FDISA1_Pos)              /*!<*/
#define  MindPWM_SMFDIS0_FDISA1                   MindPWM_SMFDIS0_FDISA1_Msk
#define  MindPWM_SMFDIS0_FDISA1_Bit0              (0x1U << MindPWM_SMFDIS0_FDISA1_Pos) 
#define  MindPWM_SMFDIS0_FDISA1_Bit1              (0x2U << MindPWM_SMFDIS0_FDISA1_Pos) 
#define  MindPWM_SMFDIS0_FDISA1_Bit2              (0x4U << MindPWM_SMFDIS0_FDISA1_Pos) 
#define  MindPWM_SMFDIS0_FDISA1_Bit3              (0x8U << MindPWM_SMFDIS0_FDISA1_Pos) 
#define  MindPWM_SMFDIS0_FDISB1_Pos               (24)
#define  MindPWM_SMFDIS0_FDISB1_Msk               (0xFU << MindPWM_SMFDIS0_FDISB1_Pos)              /*!<*/
#define  MindPWM_SMFDIS0_FDISB1                   MindPWM_SMFDIS0_FDISB1_Msk
#define  MindPWM_SMFDIS0_FDISB1_Bit0              (0x1U << MindPWM_SMFDIS0_FDISB1_Pos) 
#define  MindPWM_SMFDIS0_FDISB1_Bit1              (0x2U << MindPWM_SMFDIS0_FDISB1_Pos) 
#define  MindPWM_SMFDIS0_FDISB1_Bit2              (0x4U << MindPWM_SMFDIS0_FDISB1_Pos) 
#define  MindPWM_SMFDIS0_FDISB1_Bit3              (0x8U << MindPWM_SMFDIS0_FDISB1_Pos) 

/**
  * @brief MindPWM_SMFDIS1 Register Bit Definition
  */
#define  MindPWM_SMFDIS1_FDISX2_Pos               (0)
#define  MindPWM_SMFDIS1_FDISX2_Msk               (0xFU << MindPWM_SMFDIS1_FDISX2_Pos)              /*!<*/
#define  MindPWM_SMFDIS1_FDISX2                   MindPWM_SMFDIS1_FDISX2_Msk
#define  MindPWM_SMFDIS1_FDISX2_Bit0              (0x1U << MindPWM_SMFDIS1_FDISX2_Pos) 
#define  MindPWM_SMFDIS1_FDISX2_Bit1              (0x2U << MindPWM_SMFDIS1_FDISX2_Pos) 
#define  MindPWM_SMFDIS1_FDISX2_Bit2              (0x4U << MindPWM_SMFDIS1_FDISX2_Pos) 
#define  MindPWM_SMFDIS1_FDISX2_Bit3              (0x8U << MindPWM_SMFDIS1_FDISX2_Pos) 
#define  MindPWM_SMFDIS1_FDISA2_Pos               (4)
#define  MindPWM_SMFDIS1_FDISA2_Msk               (0xFU << MindPWM_SMFDIS1_FDISA2_Pos)              /*!<*/
#define  MindPWM_SMFDIS1_FDISA2                   MindPWM_SMFDIS1_FDISA2_Msk
#define  MindPWM_SMFDIS1_FDISA2_Bit0              (0x1U << MindPWM_SMFDIS1_FDISA2_Pos) 
#define  MindPWM_SMFDIS1_FDISA2_Bit1              (0x2U << MindPWM_SMFDIS1_FDISA2_Pos) 
#define  MindPWM_SMFDIS1_FDISA2_Bit2              (0x4U << MindPWM_SMFDIS1_FDISA2_Pos) 
#define  MindPWM_SMFDIS1_FDISA2_Bit3              (0x8U << MindPWM_SMFDIS1_FDISA2_Pos) 
#define  MindPWM_SMFDIS1_FDISB2_Pos               (8)
#define  MindPWM_SMFDIS1_FDISB2_Msk               (0xFU << MindPWM_SMFDIS1_FDISB2_Pos)              /*!<*/
#define  MindPWM_SMFDIS1_FDISB2                   MindPWM_SMFDIS1_FDISB2_Msk
#define  MindPWM_SMFDIS1_FDISB2_Bit0              (0x1U << MindPWM_SMFDIS1_FDISB2_Pos) 
#define  MindPWM_SMFDIS1_FDISB2_Bit1              (0x2U << MindPWM_SMFDIS1_FDISB2_Pos) 
#define  MindPWM_SMFDIS1_FDISB2_Bit2              (0x4U << MindPWM_SMFDIS1_FDISB2_Pos) 
#define  MindPWM_SMFDIS1_FDISB2_Bit3              (0x8U << MindPWM_SMFDIS1_FDISB2_Pos) 
#define  MindPWM_SMFDIS1_FDISX3_Pos               (16)
#define  MindPWM_SMFDIS1_FDISX3_Msk               (0xFU << MindPWM_SMFDIS1_FDISX3_Pos)              /*!<*/
#define  MindPWM_SMFDIS1_FDISX3                   MindPWM_SMFDIS1_FDISX3_Msk
#define  MindPWM_SMFDIS1_FDISX3_Bit0              (0x1U << MindPWM_SMFDIS1_FDISX3_Pos) 
#define  MindPWM_SMFDIS1_FDISX3_Bit1              (0x2U << MindPWM_SMFDIS1_FDISX3_Pos) 
#define  MindPWM_SMFDIS1_FDISX3_Bit2              (0x4U << MindPWM_SMFDIS1_FDISX3_Pos) 
#define  MindPWM_SMFDIS1_FDISX3_Bit3              (0x8U << MindPWM_SMFDIS1_FDISX3_Pos) 
#define  MindPWM_SMFDIS1_FDISA3_Pos               (20)
#define  MindPWM_SMFDIS1_FDISA3_Msk               (0xFU << MindPWM_SMFDIS1_FDISA3_Pos)              /*!<*/
#define  MindPWM_SMFDIS1_FDISA3                   MindPWM_SMFDIS1_FDISA3_Msk
#define  MindPWM_SMFDIS1_FDISA3_Bit0              (0x1U << MindPWM_SMFDIS1_FDISA3_Pos) 
#define  MindPWM_SMFDIS1_FDISA3_Bit1              (0x2U << MindPWM_SMFDIS1_FDISA3_Pos) 
#define  MindPWM_SMFDIS1_FDISA3_Bit2              (0x4U << MindPWM_SMFDIS1_FDISA3_Pos) 
#define  MindPWM_SMFDIS1_FDISA3_Bit3              (0x8U << MindPWM_SMFDIS1_FDISA3_Pos) 
#define  MindPWM_SMFDIS1_FDISB3_Pos               (24)
#define  MindPWM_SMFDIS1_FDISB3_Msk               (0xFU << MindPWM_SMFDIS1_FDISB3_Pos)              /*!<*/
#define  MindPWM_SMFDIS1_FDISB3                   MindPWM_SMFDIS1_FDISB3_Msk
#define  MindPWM_SMFDIS1_FDISB3_Bit0              (0x1U << MindPWM_SMFDIS1_FDISB3_Pos) 
#define  MindPWM_SMFDIS1_FDISB3_Bit1              (0x2U << MindPWM_SMFDIS1_FDISB3_Pos) 
#define  MindPWM_SMFDIS1_FDISB3_Bit2              (0x4U << MindPWM_SMFDIS1_FDISB3_Pos) 
#define  MindPWM_SMFDIS1_FDISB3_Bit3              (0x8U << MindPWM_SMFDIS1_FDISB3_Pos) 

/**
  * @brief MindPWM_SMDTCNT Register Bit Definition
  */
#define  MindPWM_SMDTCNT_DTCNTA_Pos               (0)
#define  MindPWM_SMDTCNT_DTCNTA_Msk               (0xFFFFU << MindPWM_SMDTCNT_DTCNTA_Pos)           /*!<*/
#define  MindPWM_SMDTCNT_DTCNTA                   MindPWM_SMDTCNT_DTCNTA_Msk
#define  MindPWM_SMDTCNT_DTCNTA_Bit0              (0x0001U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit1              (0x0002U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit2              (0x0004U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit3              (0x0008U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit4              (0x0010U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit5              (0x0020U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit6              (0x0040U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit7              (0x0080U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit8              (0x0100U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit9              (0x0200U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit10             (0x0400U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit11             (0x0800U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit12             (0x1000U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit13             (0x2000U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit14             (0x4000U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTA_Bit15             (0x8000U << MindPWM_SMDTCNT_DTCNTA_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Pos               (16)
#define  MindPWM_SMDTCNT_DTCNTB_Msk               (0xFFFFU << MindPWM_SMDTCNT_DTCNTB_Pos)           /*!<*/
#define  MindPWM_SMDTCNT_DTCNTB                   MindPWM_SMDTCNT_DTCNTB_Msk
#define  MindPWM_SMDTCNT_DTCNTB_Bit0              (0x0001U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit1              (0x0002U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit2              (0x0004U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit3              (0x0008U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit4              (0x0010U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit5              (0x0020U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit6              (0x0040U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit7              (0x0080U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit8              (0x0100U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit9              (0x0200U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit10             (0x0400U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit11             (0x0800U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit12             (0x1000U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit13             (0x2000U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit14             (0x4000U << MindPWM_SMDTCNT_DTCNTB_Pos) 
#define  MindPWM_SMDTCNT_DTCNTB_Bit15             (0x8000U << MindPWM_SMDTCNT_DTCNTB_Pos) 

/**
  * @brief MindPWM_SMCAPTCRX Register Bit Definition
  */
#define  MindPWM_SMCAPTCRX_ARMX_Pos               (0)
#define  MindPWM_SMCAPTCRX_ARMX_Msk               (0x1U << MindPWM_SMCAPTCRX_ARMX_Pos)              /*!<*/
#define  MindPWM_SMCAPTCRX_ARMX                   MindPWM_SMCAPTCRX_ARMX_Msk
#define  MindPWM_SMCAPTCRX_ONESHOTX_Pos           (1)
#define  MindPWM_SMCAPTCRX_ONESHOTX_Msk           (0x1U << MindPWM_SMCAPTCRX_ONESHOTX_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRX_ONESHOTX               MindPWM_SMCAPTCRX_ONESHOTX_Msk
#define  MindPWM_SMCAPTCRX_EDGX0_Pos              (2)
#define  MindPWM_SMCAPTCRX_EDGX0_Msk              (0x3U << MindPWM_SMCAPTCRX_EDGX0_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRX_EDGX0                  MindPWM_SMCAPTCRX_EDGX0_Msk
#define  MindPWM_SMCAPTCRX_EDGX0_Bit0             (0x1U << MindPWM_SMCAPTCRX_EDGX0_Pos) 
#define  MindPWM_SMCAPTCRX_EDGX0_Bit1             (0x2U << MindPWM_SMCAPTCRX_EDGX0_Pos) 
#define  MindPWM_SMCAPTCRX_EDGX1_Pos              (4)
#define  MindPWM_SMCAPTCRX_EDGX1_Msk              (0x3U << MindPWM_SMCAPTCRX_EDGX1_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRX_EDGX1                  MindPWM_SMCAPTCRX_EDGX1_Msk
#define  MindPWM_SMCAPTCRX_EDGX1_Bit0             (0x1U << MindPWM_SMCAPTCRX_EDGX1_Pos) 
#define  MindPWM_SMCAPTCRX_EDGX1_Bit1             (0x2U << MindPWM_SMCAPTCRX_EDGX1_Pos) 
#define  MindPWM_SMCAPTCRX_INP_SELX_Pos           (6)
#define  MindPWM_SMCAPTCRX_INP_SELX_Msk           (0x1U << MindPWM_SMCAPTCRX_INP_SELX_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRX_INP_SELX               MindPWM_SMCAPTCRX_INP_SELX_Msk
#define  MindPWM_SMCAPTCRX_EDGCNTX_EN_Pos         (7)
#define  MindPWM_SMCAPTCRX_EDGCNTX_EN_Msk         (0x1U << MindPWM_SMCAPTCRX_EDGCNTX_EN_Pos)        /*!<*/
#define  MindPWM_SMCAPTCRX_EDGCNTX_EN             MindPWM_SMCAPTCRX_EDGCNTX_EN_Msk
#define  MindPWM_SMCAPTCRX_CFXWM_Pos              (8)
#define  MindPWM_SMCAPTCRX_CFXWM_Msk              (0x3U << MindPWM_SMCAPTCRX_CFXWM_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRX_CFXWM                  MindPWM_SMCAPTCRX_CFXWM_Msk
#define  MindPWM_SMCAPTCRX_CFXWM_Bit0             (0x1U << MindPWM_SMCAPTCRX_CFXWM_Pos) 
#define  MindPWM_SMCAPTCRX_CFXWM_Bit1             (0x2U << MindPWM_SMCAPTCRX_CFXWM_Pos) 
#define  MindPWM_SMCAPTCRX_CX0CNT_Pos             (10)
#define  MindPWM_SMCAPTCRX_CX0CNT_Msk             (0x7U << MindPWM_SMCAPTCRX_CX0CNT_Pos)            /*!<*/
#define  MindPWM_SMCAPTCRX_CX0CNT                 MindPWM_SMCAPTCRX_CX0CNT_Msk
#define  MindPWM_SMCAPTCRX_CX0CNT_Bit0            (0x1U << MindPWM_SMCAPTCRX_CX0CNT_Pos) 
#define  MindPWM_SMCAPTCRX_CX0CNT_Bit1            (0x2U << MindPWM_SMCAPTCRX_CX0CNT_Pos) 
#define  MindPWM_SMCAPTCRX_CX0CNT_Bit2            (0x4U << MindPWM_SMCAPTCRX_CX0CNT_Pos) 
#define  MindPWM_SMCAPTCRX_CX1CNT_Pos             (13)
#define  MindPWM_SMCAPTCRX_CX1CNT_Msk             (0x7U << MindPWM_SMCAPTCRX_CX1CNT_Pos)            /*!<*/
#define  MindPWM_SMCAPTCRX_CX1CNT                 MindPWM_SMCAPTCRX_CX1CNT_Msk
#define  MindPWM_SMCAPTCRX_CX1CNT_Bit0            (0x1U << MindPWM_SMCAPTCRX_CX1CNT_Pos) 
#define  MindPWM_SMCAPTCRX_CX1CNT_Bit1            (0x2U << MindPWM_SMCAPTCRX_CX1CNT_Pos) 
#define  MindPWM_SMCAPTCRX_CX1CNT_Bit2            (0x4U << MindPWM_SMCAPTCRX_CX1CNT_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Pos            (16)
#define  MindPWM_SMCAPTCRX_EDGCMPX_Msk            (0xFFU << MindPWM_SMCAPTCRX_EDGCMPX_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRX_EDGCMPX                MindPWM_SMCAPTCRX_EDGCMPX_Msk
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit0           (0x01U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit1           (0x02U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit2           (0x04U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit3           (0x08U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit4           (0x10U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit5           (0x20U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit6           (0x40U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCMPX_Bit7           (0x80U << MindPWM_SMCAPTCRX_EDGCMPX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Pos            (24)
#define  MindPWM_SMCAPTCRX_EDGCNTX_Msk            (0xFFU << MindPWM_SMCAPTCRX_EDGCNTX_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRX_EDGCNTX                MindPWM_SMCAPTCRX_EDGCNTX_Msk
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit0           (0x01U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit1           (0x02U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit2           (0x04U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit3           (0x08U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit4           (0x10U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit5           (0x20U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit6           (0x40U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 
#define  MindPWM_SMCAPTCRX_EDGCNTX_Bit7           (0x80U << MindPWM_SMCAPTCRX_EDGCNTX_Pos) 

/**
  * @brief MindPWM_SMCAPTCRA Register Bit Definition
  */
#define  MindPWM_SMCAPTCRA_ARMA_Pos               (0)
#define  MindPWM_SMCAPTCRA_ARMA_Msk               (0x1U << MindPWM_SMCAPTCRA_ARMA_Pos)              /*!<*/
#define  MindPWM_SMCAPTCRA_ARMA                   MindPWM_SMCAPTCRA_ARMA_Msk
#define  MindPWM_SMCAPTCRA_ONESHOTA_Pos           (1)
#define  MindPWM_SMCAPTCRA_ONESHOTA_Msk           (0x1U << MindPWM_SMCAPTCRA_ONESHOTA_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRA_ONESHOTA               MindPWM_SMCAPTCRA_ONESHOTA_Msk
#define  MindPWM_SMCAPTCRA_EDGA0_Pos              (2)
#define  MindPWM_SMCAPTCRA_EDGA0_Msk              (0x3U << MindPWM_SMCAPTCRA_EDGA0_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRA_EDGA0                  MindPWM_SMCAPTCRA_EDGA0_Msk
#define  MindPWM_SMCAPTCRA_EDGA0_Bit0             (0x1U << MindPWM_SMCAPTCRA_EDGA0_Pos) 
#define  MindPWM_SMCAPTCRA_EDGA0_Bit1             (0x2U << MindPWM_SMCAPTCRA_EDGA0_Pos) 
#define  MindPWM_SMCAPTCRA_EDGA1_Pos              (4)
#define  MindPWM_SMCAPTCRA_EDGA1_Msk              (0x3U << MindPWM_SMCAPTCRA_EDGA1_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRA_EDGA1                  MindPWM_SMCAPTCRA_EDGA1_Msk
#define  MindPWM_SMCAPTCRA_EDGA1_Bit0             (0x1U << MindPWM_SMCAPTCRA_EDGA1_Pos) 
#define  MindPWM_SMCAPTCRA_EDGA1_Bit1             (0x2U << MindPWM_SMCAPTCRA_EDGA1_Pos) 
#define  MindPWM_SMCAPTCRA_INP_SELA_Pos           (6)
#define  MindPWM_SMCAPTCRA_INP_SELA_Msk           (0x1U << MindPWM_SMCAPTCRA_INP_SELA_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRA_INP_SELA               MindPWM_SMCAPTCRA_INP_SELA_Msk
#define  MindPWM_SMCAPTCRA_EDGCNTA_EN_Pos         (7)
#define  MindPWM_SMCAPTCRA_EDGCNTA_EN_Msk         (0x1U << MindPWM_SMCAPTCRA_EDGCNTA_EN_Pos)        /*!<*/
#define  MindPWM_SMCAPTCRA_EDGCNTA_EN             MindPWM_SMCAPTCRA_EDGCNTA_EN_Msk
#define  MindPWM_SMCAPTCRA_CFAWM_Pos              (8)
#define  MindPWM_SMCAPTCRA_CFAWM_Msk              (0x3U << MindPWM_SMCAPTCRA_CFAWM_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRA_CFAWM                  MindPWM_SMCAPTCRA_CFAWM_Msk
#define  MindPWM_SMCAPTCRA_CFAWM_Bit0             (0x1U << MindPWM_SMCAPTCRA_CFAWM_Pos) 
#define  MindPWM_SMCAPTCRA_CFAWM_Bit1             (0x2U << MindPWM_SMCAPTCRA_CFAWM_Pos) 
#define  MindPWM_SMCAPTCRA_CA0CNT_Pos             (10)
#define  MindPWM_SMCAPTCRA_CA0CNT_Msk             (0x7U << MindPWM_SMCAPTCRA_CA0CNT_Pos)            /*!<*/
#define  MindPWM_SMCAPTCRA_CA0CNT                 MindPWM_SMCAPTCRA_CA0CNT_Msk
#define  MindPWM_SMCAPTCRA_CA0CNT_Bit0            (0x1U << MindPWM_SMCAPTCRA_CA0CNT_Pos) 
#define  MindPWM_SMCAPTCRA_CA0CNT_Bit1            (0x2U << MindPWM_SMCAPTCRA_CA0CNT_Pos) 
#define  MindPWM_SMCAPTCRA_CA0CNT_Bit2            (0x4U << MindPWM_SMCAPTCRA_CA0CNT_Pos) 
#define  MindPWM_SMCAPTCRA_CA1CNT_Pos             (13)
#define  MindPWM_SMCAPTCRA_CA1CNT_Msk             (0x7U << MindPWM_SMCAPTCRA_CA1CNT_Pos)            /*!<*/
#define  MindPWM_SMCAPTCRA_CA1CNT                 MindPWM_SMCAPTCRA_CA1CNT_Msk
#define  MindPWM_SMCAPTCRA_CA1CNT_Bit0            (0x1U << MindPWM_SMCAPTCRA_CA1CNT_Pos) 
#define  MindPWM_SMCAPTCRA_CA1CNT_Bit1            (0x2U << MindPWM_SMCAPTCRA_CA1CNT_Pos) 
#define  MindPWM_SMCAPTCRA_CA1CNT_Bit2            (0x4U << MindPWM_SMCAPTCRA_CA1CNT_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Pos            (16)
#define  MindPWM_SMCAPTCRA_EDGCMPA_Msk            (0xFFU << MindPWM_SMCAPTCRA_EDGCMPA_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRA_EDGCMPA                MindPWM_SMCAPTCRA_EDGCMPA_Msk
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit0           (0x01U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit1           (0x02U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit2           (0x04U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit3           (0x08U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit4           (0x10U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit5           (0x20U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit6           (0x40U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCMPA_Bit7           (0x80U << MindPWM_SMCAPTCRA_EDGCMPA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Pos            (24)
#define  MindPWM_SMCAPTCRA_EDGCNTA_Msk            (0xFFU << MindPWM_SMCAPTCRA_EDGCNTA_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRA_EDGCNTA                MindPWM_SMCAPTCRA_EDGCNTA_Msk
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit0           (0x01U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit1           (0x02U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit2           (0x04U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit3           (0x08U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit4           (0x10U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit5           (0x20U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit6           (0x40U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 
#define  MindPWM_SMCAPTCRA_EDGCNTA_Bit7           (0x80U << MindPWM_SMCAPTCRA_EDGCNTA_Pos) 

/**
  * @brief MindPWM_SMCAPTCRB Register Bit Definition
  */
#define  MindPWM_SMCAPTCRB_ARMB_Pos               (0)
#define  MindPWM_SMCAPTCRB_ARMB_Msk               (0x1U << MindPWM_SMCAPTCRB_ARMB_Pos)              /*!<*/
#define  MindPWM_SMCAPTCRB_ARMB                   MindPWM_SMCAPTCRB_ARMB_Msk
#define  MindPWM_SMCAPTCRB_ONESHOTB_Pos           (1)
#define  MindPWM_SMCAPTCRB_ONESHOTB_Msk           (0x1U << MindPWM_SMCAPTCRB_ONESHOTB_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRB_ONESHOTB               MindPWM_SMCAPTCRB_ONESHOTB_Msk
#define  MindPWM_SMCAPTCRB_EDGB0_Pos              (2)
#define  MindPWM_SMCAPTCRB_EDGB0_Msk              (0x3U << MindPWM_SMCAPTCRB_EDGB0_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRB_EDGB0                  MindPWM_SMCAPTCRB_EDGB0_Msk
#define  MindPWM_SMCAPTCRB_EDGB0_Bit0             (0x1U << MindPWM_SMCAPTCRB_EDGB0_Pos) 
#define  MindPWM_SMCAPTCRB_EDGB0_Bit1             (0x2U << MindPWM_SMCAPTCRB_EDGB0_Pos) 
#define  MindPWM_SMCAPTCRB_EDGB1_Pos              (4)
#define  MindPWM_SMCAPTCRB_EDGB1_Msk              (0x3U << MindPWM_SMCAPTCRB_EDGB1_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRB_EDGB1                  MindPWM_SMCAPTCRB_EDGB1_Msk
#define  MindPWM_SMCAPTCRB_EDGB1_Bit0             (0x1U << MindPWM_SMCAPTCRB_EDGB1_Pos) 
#define  MindPWM_SMCAPTCRB_EDGB1_Bit1             (0x2U << MindPWM_SMCAPTCRB_EDGB1_Pos) 
#define  MindPWM_SMCAPTCRB_INP_SELB_Pos           (6)
#define  MindPWM_SMCAPTCRB_INP_SELB_Msk           (0x1U << MindPWM_SMCAPTCRB_INP_SELB_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRB_INP_SELB               MindPWM_SMCAPTCRB_INP_SELB_Msk
#define  MindPWM_SMCAPTCRB_EDGCNTB_EN_Pos         (7)
#define  MindPWM_SMCAPTCRB_EDGCNTB_EN_Msk         (0x1U << MindPWM_SMCAPTCRB_EDGCNTB_EN_Pos)        /*!<*/
#define  MindPWM_SMCAPTCRB_EDGCNTB_EN             MindPWM_SMCAPTCRB_EDGCNTB_EN_Msk
#define  MindPWM_SMCAPTCRB_CFBWM_Pos              (8)
#define  MindPWM_SMCAPTCRB_CFBWM_Msk              (0x3U << MindPWM_SMCAPTCRB_CFBWM_Pos)             /*!<*/
#define  MindPWM_SMCAPTCRB_CFBWM                  MindPWM_SMCAPTCRB_CFBWM_Msk
#define  MindPWM_SMCAPTCRB_CFBWM_Bit0             (0x1U << MindPWM_SMCAPTCRB_CFBWM_Pos) 
#define  MindPWM_SMCAPTCRB_CFBWM_Bit1             (0x2U << MindPWM_SMCAPTCRB_CFBWM_Pos) 
#define  MindPWM_SMCAPTCRB_CB0CNT_Pos             (10)
#define  MindPWM_SMCAPTCRB_CB0CNT_Msk             (0x7U << MindPWM_SMCAPTCRB_CB0CNT_Pos)            /*!<*/
#define  MindPWM_SMCAPTCRB_CB0CNT                 MindPWM_SMCAPTCRB_CB0CNT_Msk
#define  MindPWM_SMCAPTCRB_CB0CNT_Bit0            (0x1U << MindPWM_SMCAPTCRB_CB0CNT_Pos) 
#define  MindPWM_SMCAPTCRB_CB0CNT_Bit1            (0x2U << MindPWM_SMCAPTCRB_CB0CNT_Pos) 
#define  MindPWM_SMCAPTCRB_CB0CNT_Bit2            (0x4U << MindPWM_SMCAPTCRB_CB0CNT_Pos) 
#define  MindPWM_SMCAPTCRB_CB1CNT_Pos             (13)
#define  MindPWM_SMCAPTCRB_CB1CNT_Msk             (0x7U << MindPWM_SMCAPTCRB_CB1CNT_Pos)            /*!<*/
#define  MindPWM_SMCAPTCRB_CB1CNT                 MindPWM_SMCAPTCRB_CB1CNT_Msk
#define  MindPWM_SMCAPTCRB_CB1CNT_Bit0            (0x1U << MindPWM_SMCAPTCRB_CB1CNT_Pos) 
#define  MindPWM_SMCAPTCRB_CB1CNT_Bit1            (0x2U << MindPWM_SMCAPTCRB_CB1CNT_Pos) 
#define  MindPWM_SMCAPTCRB_CB1CNT_Bit2            (0x4U << MindPWM_SMCAPTCRB_CB1CNT_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Pos            (16)
#define  MindPWM_SMCAPTCRB_EDGCMPB_Msk            (0xFFU << MindPWM_SMCAPTCRB_EDGCMPB_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRB_EDGCMPB                MindPWM_SMCAPTCRB_EDGCMPB_Msk
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit0           (0x01U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit1           (0x02U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit2           (0x04U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit3           (0x08U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit4           (0x10U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit5           (0x20U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit6           (0x40U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCMPB_Bit7           (0x80U << MindPWM_SMCAPTCRB_EDGCMPB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Pos            (24)
#define  MindPWM_SMCAPTCRB_EDGCNTB_Msk            (0xFFU << MindPWM_SMCAPTCRB_EDGCNTB_Pos)          /*!<*/
#define  MindPWM_SMCAPTCRB_EDGCNTB                MindPWM_SMCAPTCRB_EDGCNTB_Msk
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit0           (0x01U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit1           (0x02U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit2           (0x04U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit3           (0x08U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit4           (0x10U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit5           (0x20U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit6           (0x40U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 
#define  MindPWM_SMCAPTCRB_EDGCNTB_Bit7           (0x80U << MindPWM_SMCAPTCRB_EDGCNTB_Pos) 

/**
  * @brief MindPWM_SMCVAL0 Register Bit Definition
  */
#define  MindPWM_SMCVAL0_CAPTVAL0_Pos             (0)
#define  MindPWM_SMCVAL0_CAPTVAL0_Msk             (0xFFFFU << MindPWM_SMCVAL0_CAPTVAL0_Pos)         /*!<*/
#define  MindPWM_SMCVAL0_CAPTVAL0                 MindPWM_SMCVAL0_CAPTVAL0_Msk
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit0            (0x0001U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit1            (0x0002U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit2            (0x0004U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit3            (0x0008U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit4            (0x0010U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit5            (0x0020U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit6            (0x0040U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit7            (0x0080U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit8            (0x0100U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit9            (0x0200U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit10           (0x0400U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit11           (0x0800U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit12           (0x1000U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit13           (0x2000U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit14           (0x4000U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 
#define  MindPWM_SMCVAL0_CAPTVAL0_Bit15           (0x8000U << MindPWM_SMCVAL0_CAPTVAL0_Pos) 

/**
  * @brief MindPWM_SMCVAL1 Register Bit Definition
  */
#define  MindPWM_SMCVAL1_CAPTVAL1_Pos             (0)
#define  MindPWM_SMCVAL1_CAPTVAL1_Msk             (0xFFFFU << MindPWM_SMCVAL1_CAPTVAL1_Pos)         /*!<*/
#define  MindPWM_SMCVAL1_CAPTVAL1                 MindPWM_SMCVAL1_CAPTVAL1_Msk
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit0            (0x0001U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit1            (0x0002U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit2            (0x0004U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit3            (0x0008U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit4            (0x0010U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit5            (0x0020U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit6            (0x0040U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit7            (0x0080U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit8            (0x0100U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit9            (0x0200U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit10           (0x0400U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit11           (0x0800U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit12           (0x1000U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit13           (0x2000U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit14           (0x4000U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 
#define  MindPWM_SMCVAL1_CAPTVAL1_Bit15           (0x8000U << MindPWM_SMCVAL1_CAPTVAL1_Pos) 

/**
  * @brief MindPWM_SMCVAL2 Register Bit Definition
  */
#define  MindPWM_SMCVAL2_CAPTVAL2_Pos             (0)
#define  MindPWM_SMCVAL2_CAPTVAL2_Msk             (0xFFFFU << MindPWM_SMCVAL2_CAPTVAL2_Pos)         /*!<*/
#define  MindPWM_SMCVAL2_CAPTVAL2                 MindPWM_SMCVAL2_CAPTVAL2_Msk
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit0            (0x0001U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit1            (0x0002U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit2            (0x0004U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit3            (0x0008U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit4            (0x0010U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit5            (0x0020U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit6            (0x0040U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit7            (0x0080U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit8            (0x0100U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit9            (0x0200U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit10           (0x0400U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit11           (0x0800U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit12           (0x1000U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit13           (0x2000U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit14           (0x4000U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 
#define  MindPWM_SMCVAL2_CAPTVAL2_Bit15           (0x8000U << MindPWM_SMCVAL2_CAPTVAL2_Pos) 

/**
  * @brief MindPWM_SMCVAL3 Register Bit Definition
  */
#define  MindPWM_SMCVAL3_CAPTVAL3_Pos             (0)
#define  MindPWM_SMCVAL3_CAPTVAL3_Msk             (0xFFFFU << MindPWM_SMCVAL3_CAPTVAL3_Pos)         /*!<*/
#define  MindPWM_SMCVAL3_CAPTVAL3                 MindPWM_SMCVAL3_CAPTVAL3_Msk
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit0            (0x0001U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit1            (0x0002U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit2            (0x0004U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit3            (0x0008U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit4            (0x0010U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit5            (0x0020U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit6            (0x0040U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit7            (0x0080U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit8            (0x0100U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit9            (0x0200U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit10           (0x0400U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit11           (0x0800U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit12           (0x1000U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit13           (0x2000U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit14           (0x4000U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 
#define  MindPWM_SMCVAL3_CAPTVAL3_Bit15           (0x8000U << MindPWM_SMCVAL3_CAPTVAL3_Pos) 

/**
  * @brief MindPWM_SMCVAL4 Register Bit Definition
  */
#define  MindPWM_SMCVAL4_CAPTVAL4_Pos             (0)
#define  MindPWM_SMCVAL4_CAPTVAL4_Msk             (0xFFFFU << MindPWM_SMCVAL4_CAPTVAL4_Pos)         /*!<*/
#define  MindPWM_SMCVAL4_CAPTVAL4                 MindPWM_SMCVAL4_CAPTVAL4_Msk
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit0            (0x0001U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit1            (0x0002U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit2            (0x0004U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit3            (0x0008U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit4            (0x0010U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit5            (0x0020U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit6            (0x0040U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit7            (0x0080U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit8            (0x0100U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit9            (0x0200U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit10           (0x0400U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit11           (0x0800U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit12           (0x1000U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit13           (0x2000U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit14           (0x4000U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 
#define  MindPWM_SMCVAL4_CAPTVAL4_Bit15           (0x8000U << MindPWM_SMCVAL4_CAPTVAL4_Pos) 

/**
  * @brief MindPWM_SMCVAL5 Register Bit Definition
  */
#define  MindPWM_SMCVAL5_CAPTVAL5_Pos             (0)
#define  MindPWM_SMCVAL5_CAPTVAL5_Msk             (0xFFFFU << MindPWM_SMCVAL5_CAPTVAL5_Pos)         /*!<*/
#define  MindPWM_SMCVAL5_CAPTVAL5                 MindPWM_SMCVAL5_CAPTVAL5_Msk
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit0            (0x0001U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit1            (0x0002U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit2            (0x0004U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit3            (0x0008U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit4            (0x0010U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit5            (0x0020U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit6            (0x0040U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit7            (0x0080U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit8            (0x0100U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit9            (0x0200U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit10           (0x0400U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit11           (0x0800U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit12           (0x1000U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit13           (0x2000U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit14           (0x4000U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 
#define  MindPWM_SMCVAL5_CAPTVAL5_Bit15           (0x8000U << MindPWM_SMCVAL5_CAPTVAL5_Pos) 

/**
  * @brief MindPWM_SMCCYC0 Register Bit Definition
  */
#define  MindPWM_SMCCYC0_CVAL0CYC_Pos             (0)
#define  MindPWM_SMCCYC0_CVAL0CYC_Msk             (0xFU << MindPWM_SMCCYC0_CVAL0CYC_Pos)            /*!<*/
#define  MindPWM_SMCCYC0_CVAL0CYC                 MindPWM_SMCCYC0_CVAL0CYC_Msk
#define  MindPWM_SMCCYC0_CVAL0CYC_Bit0            (0x1U << MindPWM_SMCCYC0_CVAL0CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL0CYC_Bit1            (0x2U << MindPWM_SMCCYC0_CVAL0CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL0CYC_Bit2            (0x4U << MindPWM_SMCCYC0_CVAL0CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL0CYC_Bit3            (0x8U << MindPWM_SMCCYC0_CVAL0CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL1CYC_Pos             (16)
#define  MindPWM_SMCCYC0_CVAL1CYC_Msk             (0xFU << MindPWM_SMCCYC0_CVAL1CYC_Pos)            /*!<*/
#define  MindPWM_SMCCYC0_CVAL1CYC                 MindPWM_SMCCYC0_CVAL1CYC_Msk
#define  MindPWM_SMCCYC0_CVAL1CYC_Bit0            (0x1U << MindPWM_SMCCYC0_CVAL1CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL1CYC_Bit1            (0x2U << MindPWM_SMCCYC0_CVAL1CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL1CYC_Bit2            (0x4U << MindPWM_SMCCYC0_CVAL1CYC_Pos) 
#define  MindPWM_SMCCYC0_CVAL1CYC_Bit3            (0x8U << MindPWM_SMCCYC0_CVAL1CYC_Pos) 

/**
  * @brief MindPWM_SMCCYC1 Register Bit Definition
  */
#define  MindPWM_SMCCYC1_CVAL2CYC_Pos             (0)
#define  MindPWM_SMCCYC1_CVAL2CYC_Msk             (0xFU << MindPWM_SMCCYC1_CVAL2CYC_Pos)            /*!<*/
#define  MindPWM_SMCCYC1_CVAL2CYC                 MindPWM_SMCCYC1_CVAL2CYC_Msk
#define  MindPWM_SMCCYC1_CVAL2CYC_Bit0            (0x1U << MindPWM_SMCCYC1_CVAL2CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL2CYC_Bit1            (0x2U << MindPWM_SMCCYC1_CVAL2CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL2CYC_Bit2            (0x4U << MindPWM_SMCCYC1_CVAL2CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL2CYC_Bit3            (0x8U << MindPWM_SMCCYC1_CVAL2CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL3CYC_Pos             (16)
#define  MindPWM_SMCCYC1_CVAL3CYC_Msk             (0xFU << MindPWM_SMCCYC1_CVAL3CYC_Pos)            /*!<*/
#define  MindPWM_SMCCYC1_CVAL3CYC                 MindPWM_SMCCYC1_CVAL3CYC_Msk
#define  MindPWM_SMCCYC1_CVAL3CYC_Bit0            (0x1U << MindPWM_SMCCYC1_CVAL3CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL3CYC_Bit1            (0x2U << MindPWM_SMCCYC1_CVAL3CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL3CYC_Bit2            (0x4U << MindPWM_SMCCYC1_CVAL3CYC_Pos) 
#define  MindPWM_SMCCYC1_CVAL3CYC_Bit3            (0x8U << MindPWM_SMCCYC1_CVAL3CYC_Pos) 

/**
  * @brief MindPWM_SMCCYC2 Register Bit Definition
  */
#define  MindPWM_SMCCYC2_CVAL4CYC_Pos             (0)
#define  MindPWM_SMCCYC2_CVAL4CYC_Msk             (0xFU << MindPWM_SMCCYC2_CVAL4CYC_Pos)            /*!<*/
#define  MindPWM_SMCCYC2_CVAL4CYC                 MindPWM_SMCCYC2_CVAL4CYC_Msk
#define  MindPWM_SMCCYC2_CVAL4CYC_Bit0            (0x1U << MindPWM_SMCCYC2_CVAL4CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL4CYC_Bit1            (0x2U << MindPWM_SMCCYC2_CVAL4CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL4CYC_Bit2            (0x4U << MindPWM_SMCCYC2_CVAL4CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL4CYC_Bit3            (0x8U << MindPWM_SMCCYC2_CVAL4CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL5CYC_Pos             (16)
#define  MindPWM_SMCCYC2_CVAL5CYC_Msk             (0xFU << MindPWM_SMCCYC2_CVAL5CYC_Pos)            /*!<*/
#define  MindPWM_SMCCYC2_CVAL5CYC                 MindPWM_SMCCYC2_CVAL5CYC_Msk
#define  MindPWM_SMCCYC2_CVAL5CYC_Bit0            (0x1U << MindPWM_SMCCYC2_CVAL5CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL5CYC_Bit1            (0x2U << MindPWM_SMCCYC2_CVAL5CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL5CYC_Bit2            (0x4U << MindPWM_SMCCYC2_CVAL5CYC_Pos) 
#define  MindPWM_SMCCYC2_CVAL5CYC_Bit3            (0x8U << MindPWM_SMCCYC2_CVAL5CYC_Pos) 

/**
  * @brief MindPWM_GCR0 Register Bit Definition
  */
#define  MindPWM_GCR0_LDOK_Pos                    (0)
#define  MindPWM_GCR0_LDOK_Msk                    (0xFU << MindPWM_GCR0_LDOK_Pos)                   /*!<*/
#define  MindPWM_GCR0_LDOK                        MindPWM_GCR0_LDOK_Msk
#define  MindPWM_GCR0_LDOK_Bit0                   (0x1U << MindPWM_GCR0_LDOK_Pos) 
#define  MindPWM_GCR0_LDOK_Bit1                   (0x2U << MindPWM_GCR0_LDOK_Pos) 
#define  MindPWM_GCR0_LDOK_Bit2                   (0x4U << MindPWM_GCR0_LDOK_Pos) 
#define  MindPWM_GCR0_LDOK_Bit3                   (0x8U << MindPWM_GCR0_LDOK_Pos) 
#define  MindPWM_GCR0_CLDOK_Pos                   (4)
#define  MindPWM_GCR0_CLDOK_Msk                   (0xFU << MindPWM_GCR0_CLDOK_Pos)                  /*!<*/
#define  MindPWM_GCR0_CLDOK                       MindPWM_GCR0_CLDOK_Msk
#define  MindPWM_GCR0_CLDOK_Bit0                  (0x1U << MindPWM_GCR0_CLDOK_Pos) 
#define  MindPWM_GCR0_CLDOK_Bit1                  (0x2U << MindPWM_GCR0_CLDOK_Pos) 
#define  MindPWM_GCR0_CLDOK_Bit2                  (0x4U << MindPWM_GCR0_CLDOK_Pos) 
#define  MindPWM_GCR0_CLDOK_Bit3                  (0x8U << MindPWM_GCR0_CLDOK_Pos) 
#define  MindPWM_GCR0_RUN_Pos                     (8)
#define  MindPWM_GCR0_RUN_Msk                     (0xFU << MindPWM_GCR0_RUN_Pos)                    /*!<*/
#define  MindPWM_GCR0_RUN                         MindPWM_GCR0_RUN_Msk
#define  MindPWM_GCR0_RUN_Bit0                    (0x1U << MindPWM_GCR0_RUN_Pos) 
#define  MindPWM_GCR0_RUN_Bit1                    (0x2U << MindPWM_GCR0_RUN_Pos) 
#define  MindPWM_GCR0_RUN_Bit2                    (0x4U << MindPWM_GCR0_RUN_Pos) 
#define  MindPWM_GCR0_RUN_Bit3                    (0x8U << MindPWM_GCR0_RUN_Pos) 
#define  MindPWM_GCR0_IPOL_Pos                    (12)
#define  MindPWM_GCR0_IPOL_Msk                    (0xFU << MindPWM_GCR0_IPOL_Pos)                   /*!<*/
#define  MindPWM_GCR0_IPOL                        MindPWM_GCR0_IPOL_Msk
#define  MindPWM_GCR0_IPOL_Bit0                   (0x1U << MindPWM_GCR0_IPOL_Pos) 
#define  MindPWM_GCR0_IPOL_Bit1                   (0x2U << MindPWM_GCR0_IPOL_Pos) 
#define  MindPWM_GCR0_IPOL_Bit2                   (0x4U << MindPWM_GCR0_IPOL_Pos) 
#define  MindPWM_GCR0_IPOL_Bit3                   (0x8U << MindPWM_GCR0_IPOL_Pos) 
#define  MindPWM_GCR0_PWMX_EN_Pos                 (16)
#define  MindPWM_GCR0_PWMX_EN_Msk                 (0xFU << MindPWM_GCR0_PWMX_EN_Pos)                /*!<*/
#define  MindPWM_GCR0_PWMX_EN                     MindPWM_GCR0_PWMX_EN_Msk
#define  MindPWM_GCR0_PWMX_EN_Bit0                (0x1U << MindPWM_GCR0_PWMX_EN_Pos) 
#define  MindPWM_GCR0_PWMX_EN_Bit1                (0x2U << MindPWM_GCR0_PWMX_EN_Pos) 
#define  MindPWM_GCR0_PWMX_EN_Bit2                (0x4U << MindPWM_GCR0_PWMX_EN_Pos) 
#define  MindPWM_GCR0_PWMX_EN_Bit3                (0x8U << MindPWM_GCR0_PWMX_EN_Pos) 
#define  MindPWM_GCR0_PWMA_EN_Pos                 (20)
#define  MindPWM_GCR0_PWMA_EN_Msk                 (0xFU << MindPWM_GCR0_PWMA_EN_Pos)                /*!<*/
#define  MindPWM_GCR0_PWMA_EN                     MindPWM_GCR0_PWMA_EN_Msk
#define  MindPWM_GCR0_PWMA_EN_Bit0                (0x1U << MindPWM_GCR0_PWMA_EN_Pos) 
#define  MindPWM_GCR0_PWMA_EN_Bit1                (0x2U << MindPWM_GCR0_PWMA_EN_Pos) 
#define  MindPWM_GCR0_PWMA_EN_Bit2                (0x4U << MindPWM_GCR0_PWMA_EN_Pos) 
#define  MindPWM_GCR0_PWMA_EN_Bit3                (0x8U << MindPWM_GCR0_PWMA_EN_Pos) 
#define  MindPWM_GCR0_PWMB_EN_Pos                 (24)
#define  MindPWM_GCR0_PWMB_EN_Msk                 (0xFU << MindPWM_GCR0_PWMB_EN_Pos)                /*!<*/
#define  MindPWM_GCR0_PWMB_EN                     MindPWM_GCR0_PWMB_EN_Msk
#define  MindPWM_GCR0_PWMB_EN_Bit0                (0x1U << MindPWM_GCR0_PWMB_EN_Pos) 
#define  MindPWM_GCR0_PWMB_EN_Bit1                (0x2U << MindPWM_GCR0_PWMB_EN_Pos) 
#define  MindPWM_GCR0_PWMB_EN_Bit2                (0x4U << MindPWM_GCR0_PWMB_EN_Pos) 
#define  MindPWM_GCR0_PWMB_EN_Bit3                (0x8U << MindPWM_GCR0_PWMB_EN_Pos) 

/**
  * @brief MindPWM_GCR1 Register Bit Definition
  */
#define  MindPWM_GCR1_MASKX_Pos                   (0)
#define  MindPWM_GCR1_MASKX_Msk                   (0xFU << MindPWM_GCR1_MASKX_Pos)                  /*!<*/
#define  MindPWM_GCR1_MASKX                       MindPWM_GCR1_MASKX_Msk
#define  MindPWM_GCR1_MASKX_Bit0                  (0x1U << MindPWM_GCR1_MASKX_Pos) 
#define  MindPWM_GCR1_MASKX_Bit1                  (0x2U << MindPWM_GCR1_MASKX_Pos) 
#define  MindPWM_GCR1_MASKX_Bit2                  (0x4U << MindPWM_GCR1_MASKX_Pos) 
#define  MindPWM_GCR1_MASKX_Bit3                  (0x8U << MindPWM_GCR1_MASKX_Pos) 
#define  MindPWM_GCR1_MASKA_Pos                   (4)
#define  MindPWM_GCR1_MASKA_Msk                   (0xFU << MindPWM_GCR1_MASKA_Pos)                  /*!<*/
#define  MindPWM_GCR1_MASKA                       MindPWM_GCR1_MASKA_Msk
#define  MindPWM_GCR1_MASKA_Bit0                  (0x1U << MindPWM_GCR1_MASKA_Pos) 
#define  MindPWM_GCR1_MASKA_Bit1                  (0x2U << MindPWM_GCR1_MASKA_Pos) 
#define  MindPWM_GCR1_MASKA_Bit2                  (0x4U << MindPWM_GCR1_MASKA_Pos) 
#define  MindPWM_GCR1_MASKA_Bit3                  (0x8U << MindPWM_GCR1_MASKA_Pos) 
#define  MindPWM_GCR1_MASKB_Pos                   (8)
#define  MindPWM_GCR1_MASKB_Msk                   (0xFU << MindPWM_GCR1_MASKB_Pos)                  /*!<*/
#define  MindPWM_GCR1_MASKB                       MindPWM_GCR1_MASKB_Msk
#define  MindPWM_GCR1_MASKB_Bit0                  (0x1U << MindPWM_GCR1_MASKB_Pos) 
#define  MindPWM_GCR1_MASKB_Bit1                  (0x2U << MindPWM_GCR1_MASKB_Pos) 
#define  MindPWM_GCR1_MASKB_Bit2                  (0x4U << MindPWM_GCR1_MASKB_Pos) 
#define  MindPWM_GCR1_MASKB_Bit3                  (0x8U << MindPWM_GCR1_MASKB_Pos) 
#define  MindPWM_GCR1_MASK_UP_Pos                 (12)
#define  MindPWM_GCR1_MASK_UP_Msk                 (0xFU << MindPWM_GCR1_MASK_UP_Pos)                /*!<*/
#define  MindPWM_GCR1_MASK_UP                     MindPWM_GCR1_MASK_UP_Msk
#define  MindPWM_GCR1_MASK_UP_Bit0                (0x1U << MindPWM_GCR1_MASK_UP_Pos) 
#define  MindPWM_GCR1_MASK_UP_Bit1                (0x2U << MindPWM_GCR1_MASK_UP_Pos) 
#define  MindPWM_GCR1_MASK_UP_Bit2                (0x4U << MindPWM_GCR1_MASK_UP_Pos) 
#define  MindPWM_GCR1_MASK_UP_Bit3                (0x8U << MindPWM_GCR1_MASK_UP_Pos) 
#define  MindPWM_GCR1_HRPWM_LDO_EN_Pos            (28)
#define  MindPWM_GCR1_HRPWM_LDO_EN_Msk            (0x1U << MindPWM_GCR1_HRPWM_LDO_EN_Pos)           /*!<*/
#define  MindPWM_GCR1_HRPWM_LDO_EN                MindPWM_GCR1_HRPWM_LDO_EN_Msk
#define  MindPWM_GCR1_MON_CSS_Pos                 (30)
#define  MindPWM_GCR1_MON_CSS_Msk                 (0x1U << MindPWM_GCR1_MON_CSS_Pos)                /*!<*/
#define  MindPWM_GCR1_MON_CSS                     MindPWM_GCR1_MON_CSS_Msk
#define  MindPWM_GCR1_MON_LOCK_Pos                (31)
#define  MindPWM_GCR1_MON_LOCK_Msk                (0x1U << MindPWM_GCR1_MON_LOCK_Pos)               /*!<*/
#define  MindPWM_GCR1_MON_LOCK                    MindPWM_GCR1_MON_LOCK_Msk

/**
  * @brief MindPWM_DTCR Register Bit Definition
  */
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Pos           (0)
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Msk           (0xFFU << MindPWM_DTCR_SMnPWMA_DTSEL_Pos)         /*!<*/
#define  MindPWM_DTCR_SMnPWMA_DTSEL               MindPWM_DTCR_SMnPWMA_DTSEL_Msk
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit0          (0x01U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit1          (0x02U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit2          (0x04U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit3          (0x08U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit4          (0x10U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit5          (0x20U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit6          (0x40U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSEL_Bit7          (0x80U << MindPWM_DTCR_SMnPWMA_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Pos           (8)
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Msk           (0xFFU << MindPWM_DTCR_SMnPWMB_DTSEL_Pos)         /*!<*/
#define  MindPWM_DTCR_SMnPWMB_DTSEL               MindPWM_DTCR_SMnPWMB_DTSEL_Msk
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit0          (0x01U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit1          (0x02U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit2          (0x04U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit3          (0x08U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit4          (0x10U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit5          (0x20U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit6          (0x40U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSEL_Bit7          (0x80U << MindPWM_DTCR_SMnPWMB_DTSEL_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSW_Pos            (16)
#define  MindPWM_DTCR_SMnPWMA_DTSW_Msk            (0xFU << MindPWM_DTCR_SMnPWMA_DTSW_Pos)           /*!<*/
#define  MindPWM_DTCR_SMnPWMA_DTSW                MindPWM_DTCR_SMnPWMA_DTSW_Msk
#define  MindPWM_DTCR_SMnPWMA_DTSW_Bit0           (0x1U << MindPWM_DTCR_SMnPWMA_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSW_Bit1           (0x2U << MindPWM_DTCR_SMnPWMA_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSW_Bit2           (0x4U << MindPWM_DTCR_SMnPWMA_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMA_DTSW_Bit3           (0x8U << MindPWM_DTCR_SMnPWMA_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSW_Pos            (20)
#define  MindPWM_DTCR_SMnPWMB_DTSW_Msk            (0xFU << MindPWM_DTCR_SMnPWMB_DTSW_Pos)           /*!<*/
#define  MindPWM_DTCR_SMnPWMB_DTSW                MindPWM_DTCR_SMnPWMB_DTSW_Msk
#define  MindPWM_DTCR_SMnPWMB_DTSW_Bit0           (0x1U << MindPWM_DTCR_SMnPWMB_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSW_Bit1           (0x2U << MindPWM_DTCR_SMnPWMB_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSW_Bit2           (0x4U << MindPWM_DTCR_SMnPWMB_DTSW_Pos) 
#define  MindPWM_DTCR_SMnPWMB_DTSW_Bit3           (0x8U << MindPWM_DTCR_SMnPWMB_DTSW_Pos) 

/**
  * @brief MindPWM_FCCR0 Register Bit Definition
  */
#define  MindPWM_FCCR0_FIE_Pos                    (0)
#define  MindPWM_FCCR0_FIE_Msk                    (0xFU << MindPWM_FCCR0_FIE_Pos)                   /*!<*/
#define  MindPWM_FCCR0_FIE                        MindPWM_FCCR0_FIE_Msk
#define  MindPWM_FCCR0_FIE_Bit0                   (0x1U << MindPWM_FCCR0_FIE_Pos) 
#define  MindPWM_FCCR0_FIE_Bit1                   (0x2U << MindPWM_FCCR0_FIE_Pos) 
#define  MindPWM_FCCR0_FIE_Bit2                   (0x4U << MindPWM_FCCR0_FIE_Pos) 
#define  MindPWM_FCCR0_FIE_Bit3                   (0x8U << MindPWM_FCCR0_FIE_Pos) 
#define  MindPWM_FCCR0_FSAFE_Pos                  (4)
#define  MindPWM_FCCR0_FSAFE_Msk                  (0xFU << MindPWM_FCCR0_FSAFE_Pos)                 /*!<*/
#define  MindPWM_FCCR0_FSAFE                      MindPWM_FCCR0_FSAFE_Msk
#define  MindPWM_FCCR0_FSAFE_Bit0                 (0x1U << MindPWM_FCCR0_FSAFE_Pos) 
#define  MindPWM_FCCR0_FSAFE_Bit1                 (0x2U << MindPWM_FCCR0_FSAFE_Pos) 
#define  MindPWM_FCCR0_FSAFE_Bit2                 (0x4U << MindPWM_FCCR0_FSAFE_Pos) 
#define  MindPWM_FCCR0_FSAFE_Bit3                 (0x8U << MindPWM_FCCR0_FSAFE_Pos) 
#define  MindPWM_FCCR0_FAUTO_Pos                  (8)
#define  MindPWM_FCCR0_FAUTO_Msk                  (0xFU << MindPWM_FCCR0_FAUTO_Pos)                 /*!<*/
#define  MindPWM_FCCR0_FAUTO                      MindPWM_FCCR0_FAUTO_Msk
#define  MindPWM_FCCR0_FAUTO_Bit0                 (0x1U << MindPWM_FCCR0_FAUTO_Pos) 
#define  MindPWM_FCCR0_FAUTO_Bit1                 (0x2U << MindPWM_FCCR0_FAUTO_Pos) 
#define  MindPWM_FCCR0_FAUTO_Bit2                 (0x4U << MindPWM_FCCR0_FAUTO_Pos) 
#define  MindPWM_FCCR0_FAUTO_Bit3                 (0x8U << MindPWM_FCCR0_FAUTO_Pos) 
#define  MindPWM_FCCR0_FLVL_Pos                   (12)
#define  MindPWM_FCCR0_FLVL_Msk                   (0xFU << MindPWM_FCCR0_FLVL_Pos)                  /*!<*/
#define  MindPWM_FCCR0_FLVL                       MindPWM_FCCR0_FLVL_Msk
#define  MindPWM_FCCR0_FLVL_Bit0                  (0x1U << MindPWM_FCCR0_FLVL_Pos) 
#define  MindPWM_FCCR0_FLVL_Bit1                  (0x2U << MindPWM_FCCR0_FLVL_Pos) 
#define  MindPWM_FCCR0_FLVL_Bit2                  (0x4U << MindPWM_FCCR0_FLVL_Pos) 
#define  MindPWM_FCCR0_FLVL_Bit3                  (0x8U << MindPWM_FCCR0_FLVL_Pos) 
#define  MindPWM_FCCR0_FFULL_Pos                  (16)
#define  MindPWM_FCCR0_FFULL_Msk                  (0xFU << MindPWM_FCCR0_FFULL_Pos)                 /*!<*/
#define  MindPWM_FCCR0_FFULL                      MindPWM_FCCR0_FFULL_Msk
#define  MindPWM_FCCR0_FFULL_Bit0                 (0x1U << MindPWM_FCCR0_FFULL_Pos) 
#define  MindPWM_FCCR0_FFULL_Bit1                 (0x2U << MindPWM_FCCR0_FFULL_Pos) 
#define  MindPWM_FCCR0_FFULL_Bit2                 (0x4U << MindPWM_FCCR0_FFULL_Pos) 
#define  MindPWM_FCCR0_FFULL_Bit3                 (0x8U << MindPWM_FCCR0_FFULL_Pos) 
#define  MindPWM_FCCR0_FHALF_Pos                  (20)
#define  MindPWM_FCCR0_FHALF_Msk                  (0xFU << MindPWM_FCCR0_FHALF_Pos)                 /*!<*/
#define  MindPWM_FCCR0_FHALF                      MindPWM_FCCR0_FHALF_Msk
#define  MindPWM_FCCR0_FHALF_Bit0                 (0x1U << MindPWM_FCCR0_FHALF_Pos) 
#define  MindPWM_FCCR0_FHALF_Bit1                 (0x2U << MindPWM_FCCR0_FHALF_Pos) 
#define  MindPWM_FCCR0_FHALF_Bit2                 (0x4U << MindPWM_FCCR0_FHALF_Pos) 
#define  MindPWM_FCCR0_FHALF_Bit3                 (0x8U << MindPWM_FCCR0_FHALF_Pos) 
#define  MindPWM_FCCR0_FFLAG_Pos                  (24)
#define  MindPWM_FCCR0_FFLAG_Msk                  (0xFU << MindPWM_FCCR0_FFLAG_Pos)                 /*!<*/
#define  MindPWM_FCCR0_FFLAG                      MindPWM_FCCR0_FFLAG_Msk
#define  MindPWM_FCCR0_FFLAG_Bit0                 (0x1U << MindPWM_FCCR0_FFLAG_Pos) 
#define  MindPWM_FCCR0_FFLAG_Bit1                 (0x2U << MindPWM_FCCR0_FFLAG_Pos) 
#define  MindPWM_FCCR0_FFLAG_Bit2                 (0x4U << MindPWM_FCCR0_FFLAG_Pos) 
#define  MindPWM_FCCR0_FFLAG_Bit3                 (0x8U << MindPWM_FCCR0_FFLAG_Pos) 
#define  MindPWM_FCCR0_FFPIN_Pos                  (28)
#define  MindPWM_FCCR0_FFPIN_Msk                  (0xFU << MindPWM_FCCR0_FFPIN_Pos)                 /*!<*/
#define  MindPWM_FCCR0_FFPIN                      MindPWM_FCCR0_FFPIN_Msk
#define  MindPWM_FCCR0_FFPIN_Bit0                 (0x1U << MindPWM_FCCR0_FFPIN_Pos) 
#define  MindPWM_FCCR0_FFPIN_Bit1                 (0x2U << MindPWM_FCCR0_FFPIN_Pos) 
#define  MindPWM_FCCR0_FFPIN_Bit2                 (0x4U << MindPWM_FCCR0_FFPIN_Pos) 
#define  MindPWM_FCCR0_FFPIN_Bit3                 (0x8U << MindPWM_FCCR0_FFPIN_Pos) 

/**
  * @brief MindPWM_FCCR1 Register Bit Definition
  */
#define  MindPWM_FCCR1_FILT_PER_Pos               (0)
#define  MindPWM_FCCR1_FILT_PER_Msk               (0xFFU << MindPWM_FCCR1_FILT_PER_Pos)             /*!<*/
#define  MindPWM_FCCR1_FILT_PER                   MindPWM_FCCR1_FILT_PER_Msk
#define  MindPWM_FCCR1_FILT_PER_Bit0              (0x01U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit1              (0x02U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit2              (0x04U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit3              (0x08U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit4              (0x10U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit5              (0x20U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit6              (0x40U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_PER_Bit7              (0x80U << MindPWM_FCCR1_FILT_PER_Pos) 
#define  MindPWM_FCCR1_FILT_CNT_Pos               (8)
#define  MindPWM_FCCR1_FILT_CNT_Msk               (0x7U << MindPWM_FCCR1_FILT_CNT_Pos)              /*!<*/
#define  MindPWM_FCCR1_FILT_CNT                   MindPWM_FCCR1_FILT_CNT_Msk
#define  MindPWM_FCCR1_FILT_CNT_Bit0              (0x1U << MindPWM_FCCR1_FILT_CNT_Pos) 
#define  MindPWM_FCCR1_FILT_CNT_Bit1              (0x2U << MindPWM_FCCR1_FILT_CNT_Pos) 
#define  MindPWM_FCCR1_FILT_CNT_Bit2              (0x4U << MindPWM_FCCR1_FILT_CNT_Pos) 
#define  MindPWM_FCCR1_FEN_Pos                    (15)
#define  MindPWM_FCCR1_FEN_Msk                    (0xFU << MindPWM_FCCR1_FEN_Pos)  
#define  MindPWM_FCCR1_NOCOMB_Pos                 (16)
#define  MindPWM_FCCR1_NOCOMB_Msk                 (0xFU << MindPWM_FCCR1_NOCOMB_Pos)                /*!<*/
#define  MindPWM_FCCR1_NOCOMB                     MindPWM_FCCR1_NOCOMB_Msk
#define  MindPWM_FCCR1_NOCOMB_Bit0                (0x1U << MindPWM_FCCR1_NOCOMB_Pos) 
#define  MindPWM_FCCR1_NOCOMB_Bit1                (0x2U << MindPWM_FCCR1_NOCOMB_Pos) 
#define  MindPWM_FCCR1_NOCOMB_Bit2                (0x4U << MindPWM_FCCR1_NOCOMB_Pos) 
#define  MindPWM_FCCR1_NOCOMB_Bit3                (0x8U << MindPWM_FCCR1_NOCOMB_Pos) 
#define  MindPWM_FCCR1_GSTR_Pos                   (30)
#define  MindPWM_FCCR1_GSTR_Msk                   (0x1U << MindPWM_FCCR1_GSTR_Pos)                  /*!<*/
#define  MindPWM_FCCR1_GSTR                       MindPWM_FCCR1_GSTR_Msk
#define  MindPWM_FCCR1_FTEST_Pos                  (31)
#define  MindPWM_FCCR1_FTEST_Msk                  (0x1U << MindPWM_FCCR1_FTEST_Pos)                 /*!<*/
#define  MindPWM_FCCR1_FTEST                      MindPWM_FCCR1_FTEST_Msk


#endif

