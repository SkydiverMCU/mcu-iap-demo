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
#include "core_starmc1.h"



/**
  * @brief PWR Base Address Definition
  */
#define  PWR_BASE                                  0x40007000                                       /*!<Base Address: 0x40007000*/

/**
  * @brief PWR Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CR1;                            /*!<PWR Power control register1                    offset: 0x00       */
    __IO uint32_t CSR;                            /*!<PWR Power control status register              offset: 0x04       */
    __IO uint32_t CR2;                            /*!<PWR Power control register2                    offset: 0x08       */
    __IO uint32_t CR3;                            /*!<PWR Power control register3                    offset: 0x0C       */
    __IO uint32_t CR4;                            /*!<PWR Power control register4                    offset: 0x10       */
    __IO uint32_t CR5;                            /*!<PWR Power control register5                    offset: 0x14       */
    __IO uint32_t CR6;                            /*!<PWR Power control register6                    offset: 0x18       */
    __IO uint32_t SR;                             /*!<PWR Power status register                      offset: 0x1C       */
    __IO uint32_t SCR;                            /*!<PWR Power status clear register                offset: 0x20       */
    __IO uint32_t CFGR;                           /*!<PWR Power configuration register               offset: 0x24       */
    __IO uint32_t RESERVED0x28[2];                /*!<                                               offset: 0x28~0x2C  */
    __IO uint32_t MEMCR;                          /*!<PWR Power memory control register              offset: 0x30       */
    __IO uint32_t RESERVED0x34[3];                /*!<                                               offset: 0x34~0x3C  */
    __IO uint32_t CR7;                            /*!<PWR Power control register7                    offset: 0x40       */
} PWR_TypeDef;

/**
  * @brief PWR type pointer Definition
  */
#define PWR                                       ((PWR_TypeDef *)PWR_BASE)

/**
  * @brief PWR_CR1 Register Bit Definition
  */
#define  PWR_CR1_LPDS_Pos                         (0)
#define  PWR_CR1_LPDS_Msk                         (0x1U << PWR_CR1_LPDS_Pos)                        /*!<*/
#define  PWR_CR1_LPDS                             PWR_CR1_LPDS_Msk
#define  PWR_CR1_PDDS_Pos                         (1)
#define  PWR_CR1_PDDS_Msk                         (0x1U << PWR_CR1_PDDS_Pos)                        /*!<*/
#define  PWR_CR1_PDDS                             PWR_CR1_PDDS_Msk
#define  PWR_CR1_CSBF_Pos                         (3)
#define  PWR_CR1_CSBF_Msk                         (0x1U << PWR_CR1_CSBF_Pos)                        /*!<*/
#define  PWR_CR1_CSBF                             PWR_CR1_CSBF_Msk
#define  PWR_CR1_VOSH_Pos                         (8)
#define  PWR_CR1_VOSH_Msk                         (0x1U << PWR_CR1_VOSH_Pos)                        /*!<*/
#define  PWR_CR1_VOSH                             PWR_CR1_VOSH_Msk
#define  PWR_CR1_LPR_Pos                          (13)
#define  PWR_CR1_LPR_Msk                          (0x1U << PWR_CR1_LPR_Pos)                         /*!<*/
#define  PWR_CR1_LPR                              PWR_CR1_LPR_Msk
#define  PWR_CR1_VOSL_Pos                         (14)
#define  PWR_CR1_VOSL_Msk                         (0x3U << PWR_CR1_VOSL_Pos)                        /*!<*/
#define  PWR_CR1_VOSL                             PWR_CR1_VOSL_Msk
#define  PWR_CR1_VOSL_Bit0                        (0x1U << PWR_CR1_VOSL_Pos) 
#define  PWR_CR1_VOSL_Bit1                        (0x2U << PWR_CR1_VOSL_Pos) 

/**
  * @brief PWR_CSR Register Bit Definition
  */
#define  PWR_CSR_SBF_Pos                          (1)
#define  PWR_CSR_SBF_Msk                          (0x1U << PWR_CSR_SBF_Pos)                         /*!<*/
#define  PWR_CSR_SBF                              PWR_CSR_SBF_Msk
#define  PWR_CSR_VOSRDY_Pos                       (14)
#define  PWR_CSR_VOSRDY_Msk                       (0x1U << PWR_CSR_VOSRDY_Pos)                      /*!<*/
#define  PWR_CSR_VOSRDY                           PWR_CSR_VOSRDY_Msk

/**
  * @brief PWR_CR2 Register Bit Definition
  */
#define  PWR_CR2_EWUP0_Pos                        (0)
#define  PWR_CR2_EWUP0_Msk                        (0x1U << PWR_CR2_EWUP0_Pos)                       /*!<*/
#define  PWR_CR2_EWUP0                            PWR_CR2_EWUP0_Msk
#define  PWR_CR2_EWUP1_Pos                        (1)
#define  PWR_CR2_EWUP1_Msk                        (0x1U << PWR_CR2_EWUP1_Pos)                       /*!<*/
#define  PWR_CR2_EWUP1                            PWR_CR2_EWUP1_Msk
#define  PWR_CR2_EWUP2_Pos                        (2)
#define  PWR_CR2_EWUP2_Msk                        (0x1U << PWR_CR2_EWUP2_Pos)                       /*!<*/
#define  PWR_CR2_EWUP2                            PWR_CR2_EWUP2_Msk
#define  PWR_CR2_EWUP3_Pos                        (3)
#define  PWR_CR2_EWUP3_Msk                        (0x1U << PWR_CR2_EWUP3_Pos)                       /*!<*/
#define  PWR_CR2_EWUP3                            PWR_CR2_EWUP3_Msk
#define  PWR_CR2_EWUP4_Pos                        (4)
#define  PWR_CR2_EWUP4_Msk                        (0x1U << PWR_CR2_EWUP4_Pos)                       /*!<*/
#define  PWR_CR2_EWUP4                            PWR_CR2_EWUP4_Msk
#define  PWR_CR2_EWUP5_Pos                        (5)
#define  PWR_CR2_EWUP5_Msk                        (0x1U << PWR_CR2_EWUP5_Pos)                       /*!<*/
#define  PWR_CR2_EWUP5                            PWR_CR2_EWUP5_Msk

/**
  * @brief PWR_CR3 Register Bit Definition
  */
#define  PWR_CR3_WP0_Pos                          (0)
#define  PWR_CR3_WP0_Msk                          (0x1U << PWR_CR3_WP0_Pos)                         /*!<*/
#define  PWR_CR3_WP0                              PWR_CR3_WP0_Msk
#define  PWR_CR3_WP1_Pos                          (1)
#define  PWR_CR3_WP1_Msk                          (0x1U << PWR_CR3_WP1_Pos)                         /*!<*/
#define  PWR_CR3_WP1                              PWR_CR3_WP1_Msk
#define  PWR_CR3_WP2_Pos                          (2)
#define  PWR_CR3_WP2_Msk                          (0x1U << PWR_CR3_WP2_Pos)                         /*!<*/
#define  PWR_CR3_WP2                              PWR_CR3_WP2_Msk
#define  PWR_CR3_WP3_Pos                          (3)
#define  PWR_CR3_WP3_Msk                          (0x1U << PWR_CR3_WP3_Pos)                         /*!<*/
#define  PWR_CR3_WP3                              PWR_CR3_WP3_Msk
#define  PWR_CR3_WP4_Pos                          (4)
#define  PWR_CR3_WP4_Msk                          (0x1U << PWR_CR3_WP4_Pos)                         /*!<*/
#define  PWR_CR3_WP4                              PWR_CR3_WP4_Msk
#define  PWR_CR3_WP5_Pos                          (5)
#define  PWR_CR3_WP5_Msk                          (0x1U << PWR_CR3_WP5_Pos)                         /*!<*/
#define  PWR_CR3_WP5                              PWR_CR3_WP5_Msk

/**
  * @brief PWR_CR4 Register Bit Definition
  */
#define  PWR_CR4_FILTSEL0_Pos                     (0)
#define  PWR_CR4_FILTSEL0_Msk                     (0x3U << PWR_CR4_FILTSEL0_Pos)                    /*!<*/
#define  PWR_CR4_FILTSEL0                         PWR_CR4_FILTSEL0_Msk
#define  PWR_CR4_FILTSEL0_Bit0                    (0x1U << PWR_CR4_FILTSEL0_Pos) 
#define  PWR_CR4_FILTSEL0_Bit1                    (0x2U << PWR_CR4_FILTSEL0_Pos) 
#define  PWR_CR4_FILTE0_Pos                       (2)
#define  PWR_CR4_FILTE0_Msk                       (0x3U << PWR_CR4_FILTE0_Pos)                      /*!<*/
#define  PWR_CR4_FILTE0                           PWR_CR4_FILTE0_Msk
#define  PWR_CR4_FILTE0_Bit0                      (0x1U << PWR_CR4_FILTE0_Pos) 
#define  PWR_CR4_FILTE0_Bit1                      (0x2U << PWR_CR4_FILTE0_Pos) 
#define  PWR_CR4_FILTF0_Pos                       (4)
#define  PWR_CR4_FILTF0_Msk                       (0x1U << PWR_CR4_FILTF0_Pos)                      /*!<*/
#define  PWR_CR4_FILTF0                           PWR_CR4_FILTF0_Msk
#define  PWR_CR4_FILTCNT0_Pos                     (8)
#define  PWR_CR4_FILTCNT0_Msk                     (0xFFU << PWR_CR4_FILTCNT0_Pos)                   /*!<*/
#define  PWR_CR4_FILTCNT0                         PWR_CR4_FILTCNT0_Msk
#define  PWR_CR4_FILTCNT0_Bit0                    (0x01U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit1                    (0x02U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit2                    (0x04U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit3                    (0x08U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit4                    (0x10U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit5                    (0x20U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit6                    (0x40U << PWR_CR4_FILTCNT0_Pos) 
#define  PWR_CR4_FILTCNT0_Bit7                    (0x80U << PWR_CR4_FILTCNT0_Pos) 

/**
  * @brief PWR_CR5 Register Bit Definition
  */
#define  PWR_CR5_FILTSEL1_Pos                     (0)
#define  PWR_CR5_FILTSEL1_Msk                     (0x3U << PWR_CR5_FILTSEL1_Pos)                    /*!<*/
#define  PWR_CR5_FILTSEL1                         PWR_CR5_FILTSEL1_Msk
#define  PWR_CR5_FILTSEL1_Bit0                    (0x1U << PWR_CR5_FILTSEL1_Pos) 
#define  PWR_CR5_FILTSEL1_Bit1                    (0x2U << PWR_CR5_FILTSEL1_Pos) 
#define  PWR_CR5_FILTE1_Pos                       (2)
#define  PWR_CR5_FILTE1_Msk                       (0x3U << PWR_CR5_FILTE1_Pos)                      /*!<*/
#define  PWR_CR5_FILTE1                           PWR_CR5_FILTE1_Msk
#define  PWR_CR5_FILTE1_Bit0                      (0x1U << PWR_CR5_FILTE1_Pos) 
#define  PWR_CR5_FILTE1_Bit1                      (0x2U << PWR_CR5_FILTE1_Pos) 
#define  PWR_CR5_FILTF1_Pos                       (4)
#define  PWR_CR5_FILTF1_Msk                       (0x1U << PWR_CR5_FILTF1_Pos)                      /*!<*/
#define  PWR_CR5_FILTF1                           PWR_CR5_FILTF1_Msk
#define  PWR_CR5_FILTCNT1_Pos                     (8)
#define  PWR_CR5_FILTCNT1_Msk                     (0xFFU << PWR_CR5_FILTCNT1_Pos)                   /*!<*/
#define  PWR_CR5_FILTCNT1                         PWR_CR5_FILTCNT1_Msk
#define  PWR_CR5_FILTCNT1_Bit0                    (0x01U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit1                    (0x02U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit2                    (0x04U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit3                    (0x08U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit4                    (0x10U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit5                    (0x20U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit6                    (0x40U << PWR_CR5_FILTCNT1_Pos) 
#define  PWR_CR5_FILTCNT1_Bit7                    (0x80U << PWR_CR5_FILTCNT1_Pos) 

/**
  * @brief PWR_CR6 Register Bit Definition
  */
#define  PWR_CR6_STDBY_FS_WK_Pos                  (0)
#define  PWR_CR6_STDBY_FS_WK_Msk                  (0x7U << PWR_CR6_STDBY_FS_WK_Pos)                 /*!<*/
#define  PWR_CR6_STDBY_FS_WK                      PWR_CR6_STDBY_FS_WK_Msk
#define  PWR_CR6_STDBY_FS_WK_Bit0                 (0x1U << PWR_CR6_STDBY_FS_WK_Pos) 
#define  PWR_CR6_STDBY_FS_WK_Bit1                 (0x2U << PWR_CR6_STDBY_FS_WK_Pos) 
#define  PWR_CR6_STDBY_FS_WK_Bit2                 (0x4U << PWR_CR6_STDBY_FS_WK_Pos) 

/**
  * @brief PWR_SR Register Bit Definition
  */
#define  PWR_SR_WUP0_Pos                          (0)
#define  PWR_SR_WUP0_Msk                          (0x1U << PWR_SR_WUP0_Pos)                         /*!<*/
#define  PWR_SR_WUP0                              PWR_SR_WUP0_Msk
#define  PWR_SR_WUP1_Pos                          (1)
#define  PWR_SR_WUP1_Msk                          (0x1U << PWR_SR_WUP1_Pos)                         /*!<*/
#define  PWR_SR_WUP1                              PWR_SR_WUP1_Msk
#define  PWR_SR_WUP2_Pos                          (2)
#define  PWR_SR_WUP2_Msk                          (0x1U << PWR_SR_WUP2_Pos)                         /*!<*/
#define  PWR_SR_WUP2                              PWR_SR_WUP2_Msk
#define  PWR_SR_WUP3_Pos                          (3)
#define  PWR_SR_WUP3_Msk                          (0x1U << PWR_SR_WUP3_Pos)                         /*!<*/
#define  PWR_SR_WUP3                              PWR_SR_WUP3_Msk
#define  PWR_SR_WUP4_Pos                          (4)
#define  PWR_SR_WUP4_Msk                          (0x1U << PWR_SR_WUP4_Pos)                         /*!<*/
#define  PWR_SR_WUP4                              PWR_SR_WUP4_Msk
#define  PWR_SR_WUP5_Pos                          (5)
#define  PWR_SR_WUP5_Msk                          (0x1U << PWR_SR_WUP5_Pos)                         /*!<*/
#define  PWR_SR_WUP5                              PWR_SR_WUP5_Msk

/**
  * @brief PWR_SCR Register Bit Definition
  */
#define  PWR_SCR_CWUP0_Pos                        (0)
#define  PWR_SCR_CWUP0_Msk                        (0x1U << PWR_SCR_CWUP0_Pos)                       /*!<*/
#define  PWR_SCR_CWUP0                            PWR_SCR_CWUP0_Msk
#define  PWR_SCR_CWUP1_Pos                        (1)
#define  PWR_SCR_CWUP1_Msk                        (0x1U << PWR_SCR_CWUP1_Pos)                       /*!<*/
#define  PWR_SCR_CWUP1                            PWR_SCR_CWUP1_Msk
#define  PWR_SCR_CWUP2_Pos                        (2)
#define  PWR_SCR_CWUP2_Msk                        (0x1U << PWR_SCR_CWUP2_Pos)                       /*!<*/
#define  PWR_SCR_CWUP2                            PWR_SCR_CWUP2_Msk
#define  PWR_SCR_CWUP3_Pos                        (3)
#define  PWR_SCR_CWUP3_Msk                        (0x1U << PWR_SCR_CWUP3_Pos)                       /*!<*/
#define  PWR_SCR_CWUP3                            PWR_SCR_CWUP3_Msk
#define  PWR_SCR_CWUP4_Pos                        (4)
#define  PWR_SCR_CWUP4_Msk                        (0x1U << PWR_SCR_CWUP4_Pos)                       /*!<*/
#define  PWR_SCR_CWUP4                            PWR_SCR_CWUP4_Msk
#define  PWR_SCR_CWUP5_Pos                        (5)
#define  PWR_SCR_CWUP5_Msk                        (0x1U << PWR_SCR_CWUP5_Pos)                       /*!<*/
#define  PWR_SCR_CWUP5                            PWR_SCR_CWUP5_Msk

/**
  * @brief PWR_CFGR Register Bit Definition
  */
#define  PWR_CFGR_LSICALSEL_Pos                   (0)
#define  PWR_CFGR_LSICALSEL_Msk                   (0x1FU << PWR_CFGR_LSICALSEL_Pos)                 /*!<*/
#define  PWR_CFGR_LSICALSEL                       PWR_CFGR_LSICALSEL_Msk
#define  PWR_CFGR_LSICALSEL_Bit0                  (0x01U << PWR_CFGR_LSICALSEL_Pos) 
#define  PWR_CFGR_LSICALSEL_Bit1                  (0x02U << PWR_CFGR_LSICALSEL_Pos) 
#define  PWR_CFGR_LSICALSEL_Bit2                  (0x04U << PWR_CFGR_LSICALSEL_Pos) 
#define  PWR_CFGR_LSICALSEL_Bit3                  (0x08U << PWR_CFGR_LSICALSEL_Pos) 
#define  PWR_CFGR_LSICALSEL_Bit4                  (0x10U << PWR_CFGR_LSICALSEL_Pos) 
#define  PWR_CFGR_LSICAL_Pos                      (5)
#define  PWR_CFGR_LSICAL_Msk                      (0x3FU << PWR_CFGR_LSICAL_Pos)                    /*!<*/
#define  PWR_CFGR_LSICAL                          PWR_CFGR_LSICAL_Msk
#define  PWR_CFGR_LSICAL_Bit0                     (0x01U << PWR_CFGR_LSICAL_Pos) 
#define  PWR_CFGR_LSICAL_Bit1                     (0x02U << PWR_CFGR_LSICAL_Pos) 
#define  PWR_CFGR_LSICAL_Bit2                     (0x04U << PWR_CFGR_LSICAL_Pos) 
#define  PWR_CFGR_LSICAL_Bit3                     (0x08U << PWR_CFGR_LSICAL_Pos) 
#define  PWR_CFGR_LSICAL_Bit4                     (0x10U << PWR_CFGR_LSICAL_Pos) 
#define  PWR_CFGR_LSICAL_Bit5                     (0x20U << PWR_CFGR_LSICAL_Pos) 

/**
  * @brief PWR_MEMCR Register Bit Definition
  */
#define  PWR_MEMCR_MEM_LOCK_Pos                   (0)
#define  PWR_MEMCR_MEM_LOCK_Msk                   (0x1FU << PWR_MEMCR_MEM_LOCK_Pos)                 /*!<*/
#define  PWR_MEMCR_MEM_LOCK                       PWR_MEMCR_MEM_LOCK_Msk
#define  PWR_MEMCR_MEM_LOCK_Bit0                  (0x01U << PWR_MEMCR_MEM_LOCK_Pos) 
#define  PWR_MEMCR_MEM_LOCK_Bit1                  (0x02U << PWR_MEMCR_MEM_LOCK_Pos) 
#define  PWR_MEMCR_MEM_LOCK_Bit2                  (0x04U << PWR_MEMCR_MEM_LOCK_Pos) 
#define  PWR_MEMCR_MEM_LOCK_Bit3                  (0x08U << PWR_MEMCR_MEM_LOCK_Pos) 
#define  PWR_MEMCR_MEM_LOCK_Bit4                  (0x10U << PWR_MEMCR_MEM_LOCK_Pos) 
#define  PWR_MEMCR_FDP_STOP_EN_Pos                (6)
#define  PWR_MEMCR_FDP_STOP_EN_Msk                (0x1U << PWR_MEMCR_FDP_STOP_EN_Pos)               /*!<*/
#define  PWR_MEMCR_FDP_STOP_EN                    PWR_MEMCR_FDP_STOP_EN_Msk

/**
  * @brief PWR_CR7 Register Bit Definition
  */
#define  PWR_CR7_STPPLEV_Pos                      (0)
#define  PWR_CR7_STPPLEV_Msk                      (0x3U << PWR_CR7_STPPLEV_Pos)                     /*!<*/
#define  PWR_CR7_STPPLEV                          PWR_CR7_STPPLEV_Msk
#define  PWR_CR7_STPPLEV_Bit0                     (0x1U << PWR_CR7_STPPLEV_Pos) 
#define  PWR_CR7_STPPLEV_Bit1                     (0x2U << PWR_CR7_STPPLEV_Pos) 


#endif

