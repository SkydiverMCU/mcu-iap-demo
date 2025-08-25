/***********************************************************************************************************************
    @file     reg_mds.h
    @author   VV TEAM
    @brief    This flie contains all the MDS's register and its field definition.
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

#ifndef __REG_MDS_H
#define __REG_MDS_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief MDS Base Address Definition
  */
#define  MDS_BASE                                  0x4001FC00                                       /*!<Base Address: 0x4001FC00*/

/**
  * @brief MDS Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TRIGCR[13];                     /*!<MDS Trigger Channel x Control and Status       offset: 0x00
                                                      Register                                                          */
    __IO uint32_t RESERVED0x34[19];               /*!<                                               offset: 0x34~0x7C  */
    __IO uint32_t TRIG_CLUSEL[4];                 /*!<MDS Trigger Channel CLUx Input Select          offset: 0x80
                                                      Register                                                          */
    __IO uint32_t RESERVED0x90[12];               /*!<                                               offset: 0x90~0xBC  */
    __IO uint32_t TRIG_CLUCFG[4];                 /*!<MDS Trigger Channel CLUx Configuration         offset: 0xC0
                                                      Register                                                          */
    __IO uint32_t RESERVED0xD0[11];               /*!<                                               offset: 0xD0~0xF8  */
    __IO uint32_t SWTRIG;                         /*!<MDS Software Trigger Register                  offset: 0xFC       */
    __IO uint32_t CONNCR[8];                      /*!<MDS Connection Channel x Control and Status    offset: 0x100
                                                      Register                                                          */
    __IO uint32_t RESERVED0x120[24];              /*!<                                               offset: 0x120~0x17C*/
    __IO uint32_t CONN_CLUSEL[4];                 /*!<MDS Connection Channel CLUx Input Select       offset: 0x180
                                                      Register                                                          */
    __IO uint32_t RESERVED0x190[12];              /*!<                                               offset: 0x190~0x1BC*/
    __IO uint32_t CONN_CLUCFG[4];                 /*!<MDS Connection Channel CLUx Configuration      offset: 0x1C0
                                                      Register                                                          */
} MDS_TypeDef;

/**
  * @brief MDS type pointer Definition
  */
#define MDS                                       ((MDS_TypeDef *)MDS_BASE)

/**
  * @brief MDS_TRIGCR Register Bit Definition
  */
#define  MDS_TRIGCR_TRGSEL_Pos                    (0)
#define  MDS_TRIGCR_TRGSEL_Msk                    (0x7FU << MDS_TRIGCR_TRGSEL_Pos)                  /*!<Trigger Source Select Register This register only works when CLUEN is set to 0. It controls the option of channel trigger sources. See MindSwitch Trigger Source Mapping for specific numbers. When the TRGSEL configuration is out of scope of the mapping list, the channel will select input 0 as the trigger source.*/
#define  MDS_TRIGCR_TRGSEL                        MDS_TRIGCR_TRGSEL_Msk
#define  MDS_TRIGCR_TRGSEL_Bit0                   (0x01U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_TRGSEL_Bit1                   (0x02U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_TRGSEL_Bit2                   (0x04U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_TRGSEL_Bit3                   (0x08U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_TRGSEL_Bit4                   (0x10U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_TRGSEL_Bit5                   (0x20U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_TRGSEL_Bit6                   (0x40U << MDS_TRIGCR_TRGSEL_Pos) 
#define  MDS_TRIGCR_CLUEN_Pos                     (16)
#define  MDS_TRIGCR_CLUEN_Msk                     (0x1U << MDS_TRIGCR_CLUEN_Pos)                    /*!<CLU Enable Register*/
#define  MDS_TRIGCR_CLUEN                         MDS_TRIGCR_CLUEN_Msk
#define  MDS_TRIGCR_CLUSEL_Pos                    (17)
#define  MDS_TRIGCR_CLUSEL_Msk                    (0x3U << MDS_TRIGCR_CLUSEL_Pos)                   /*!<CLU Select Register*/
#define  MDS_TRIGCR_CLUSEL                        MDS_TRIGCR_CLUSEL_Msk
#define  MDS_TRIGCR_CLUSEL_Bit0                   (0x1U << MDS_TRIGCR_CLUSEL_Pos) 
#define  MDS_TRIGCR_CLUSEL_Bit1                   (0x2U << MDS_TRIGCR_CLUSEL_Pos) 
#define  MDS_TRIGCR_EDGESEL_Pos                   (24)
#define  MDS_TRIGCR_EDGESEL_Msk                   (0x3U << MDS_TRIGCR_EDGESEL_Pos)                  /*!<Edge Select Register*/
#define  MDS_TRIGCR_EDGESEL                       MDS_TRIGCR_EDGESEL_Msk
#define  MDS_TRIGCR_EDGESEL_Bit0                  (0x1U << MDS_TRIGCR_EDGESEL_Pos) 
#define  MDS_TRIGCR_EDGESEL_Bit1                  (0x2U << MDS_TRIGCR_EDGESEL_Pos) 

/**
  * @brief MDS_TRIG_CLUSEL Register Bit Definition
  */
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos           (0)
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Msk           (0x7FU << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos)         /*!<CLU Input0 Select Register This register controls the option of CLU Input0 trigger source. See MindSwitch Trigger Source Mapping for specific numbers.*/
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL               MDS_TRIG_CLUSEL_CLUIN0_SEL_Msk
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit0          (0x01U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit1          (0x02U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit2          (0x04U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit3          (0x08U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit4          (0x10U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit5          (0x20U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN0_SEL_Bit6          (0x40U << MDS_TRIG_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos           (8)
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Msk           (0x7FU << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos)         /*!<CLU Input1 Select Register This register controls the option of CLU Input1 trigger source. See MindSwitch Trigger Source Mapping for specific numbers.*/
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL               MDS_TRIG_CLUSEL_CLUIN1_SEL_Msk
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit0          (0x01U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit1          (0x02U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit2          (0x04U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit3          (0x08U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit4          (0x10U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit5          (0x20U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN1_SEL_Bit6          (0x40U << MDS_TRIG_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos           (16)
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Msk           (0x7FU << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos)         /*!<CLU Input2 Select Register This register controls the option of CLU Input2 trigger source. See MindSwitch Trigger Source Mapping for specific numbers.*/
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL               MDS_TRIG_CLUSEL_CLUIN2_SEL_Msk
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit0          (0x01U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit1          (0x02U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit2          (0x04U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit3          (0x08U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit4          (0x10U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit5          (0x20U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN2_SEL_Bit6          (0x40U << MDS_TRIG_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos           (24)
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Msk           (0x7FU << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos)         /*!<CLU Input3 Select Register This register controls the option of CLU Input3 trigger source. See MindSwitch Trigger Source Mapping for specific numbers.*/
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL               MDS_TRIG_CLUSEL_CLUIN3_SEL_Msk
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit0          (0x01U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit1          (0x02U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit2          (0x04U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit3          (0x08U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit4          (0x10U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit5          (0x20U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_TRIG_CLUSEL_CLUIN3_SEL_Bit6          (0x40U << MDS_TRIG_CLUSEL_CLUIN3_SEL_Pos) 

/**
  * @brief MDS_TRIG_CLUCFG Register Bit Definition
  */
#define  MDS_TRIG_CLUCFG_CLUIN0_ED_Pos            (0)
#define  MDS_TRIG_CLUCFG_CLUIN0_ED_Msk            (0x3U << MDS_TRIG_CLUCFG_CLUIN0_ED_Pos)           /*!<CLUIN0 Edge Detect Mode*/
#define  MDS_TRIG_CLUCFG_CLUIN0_ED                MDS_TRIG_CLUCFG_CLUIN0_ED_Msk
#define  MDS_TRIG_CLUCFG_CLUIN0_ED_Bit0           (0x1U << MDS_TRIG_CLUCFG_CLUIN0_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN0_ED_Bit1           (0x2U << MDS_TRIG_CLUCFG_CLUIN0_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN0_IC_Pos            (2)
#define  MDS_TRIG_CLUCFG_CLUIN0_IC_Msk            (0x1U << MDS_TRIG_CLUCFG_CLUIN0_IC_Pos)           /*!<CLUIN0 Input Cascade*/
#define  MDS_TRIG_CLUCFG_CLUIN0_IC                MDS_TRIG_CLUCFG_CLUIN0_IC_Msk
#define  MDS_TRIG_CLUCFG_CLUIN1_ED_Pos            (8)
#define  MDS_TRIG_CLUCFG_CLUIN1_ED_Msk            (0x3U << MDS_TRIG_CLUCFG_CLUIN1_ED_Pos)           /*!<CLUIN1 Edge Detect Mode*/
#define  MDS_TRIG_CLUCFG_CLUIN1_ED                MDS_TRIG_CLUCFG_CLUIN1_ED_Msk
#define  MDS_TRIG_CLUCFG_CLUIN1_ED_Bit0           (0x1U << MDS_TRIG_CLUCFG_CLUIN1_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN1_ED_Bit1           (0x2U << MDS_TRIG_CLUCFG_CLUIN1_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN1_IC_Pos            (10)
#define  MDS_TRIG_CLUCFG_CLUIN1_IC_Msk            (0x1U << MDS_TRIG_CLUCFG_CLUIN1_IC_Pos)           /*!<CLUIN1 Input Cascade*/
#define  MDS_TRIG_CLUCFG_CLUIN1_IC                MDS_TRIG_CLUCFG_CLUIN1_IC_Msk
#define  MDS_TRIG_CLUCFG_CLUIN2_ED_Pos            (16)
#define  MDS_TRIG_CLUCFG_CLUIN2_ED_Msk            (0x3U << MDS_TRIG_CLUCFG_CLUIN2_ED_Pos)           /*!<CLUIN2 Edge Detect Mode*/
#define  MDS_TRIG_CLUCFG_CLUIN2_ED                MDS_TRIG_CLUCFG_CLUIN2_ED_Msk
#define  MDS_TRIG_CLUCFG_CLUIN2_ED_Bit0           (0x1U << MDS_TRIG_CLUCFG_CLUIN2_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN2_ED_Bit1           (0x2U << MDS_TRIG_CLUCFG_CLUIN2_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN2_IC_Pos            (18)
#define  MDS_TRIG_CLUCFG_CLUIN2_IC_Msk            (0x1U << MDS_TRIG_CLUCFG_CLUIN2_IC_Pos)           /*!<CLUIN2 Input Cascade*/
#define  MDS_TRIG_CLUCFG_CLUIN2_IC                MDS_TRIG_CLUCFG_CLUIN2_IC_Msk
#define  MDS_TRIG_CLUCFG_CLUIN3_ED_Pos            (24)
#define  MDS_TRIG_CLUCFG_CLUIN3_ED_Msk            (0x3U << MDS_TRIG_CLUCFG_CLUIN3_ED_Pos)           /*!<CLUIN3 Edge Detect Mode*/
#define  MDS_TRIG_CLUCFG_CLUIN3_ED                MDS_TRIG_CLUCFG_CLUIN3_ED_Msk
#define  MDS_TRIG_CLUCFG_CLUIN3_ED_Bit0           (0x1U << MDS_TRIG_CLUCFG_CLUIN3_ED_Pos) 
#define  MDS_TRIG_CLUCFG_CLUIN3_ED_Bit1           (0x2U << MDS_TRIG_CLUCFG_CLUIN3_ED_Pos) 

/**
  * @brief MDS_SWTRIG Register Bit Definition
  */
#define  MDS_SWTRIG_SW_TRIG_Pos                   (0)
#define  MDS_SWTRIG_SW_TRIG_Msk                   (0x1U << MDS_SWTRIG_SW_TRIG_Pos)                  /*!<Software trigger register*/
#define  MDS_SWTRIG_SW_TRIG                       MDS_SWTRIG_SW_TRIG_Msk

/**
  * @brief MDS_CONNCR Register Bit Definition
  */
#define  MDS_CONNCR_TRGSEL_Pos                    (0)
#define  MDS_CONNCR_TRGSEL_Msk                    (0x3FU << MDS_CONNCR_TRGSEL_Pos)                  /*!<Trigger Source Select Register*/
#define  MDS_CONNCR_TRGSEL                        MDS_CONNCR_TRGSEL_Msk
#define  MDS_CONNCR_TRGSEL_Bit0                   (0x01U << MDS_CONNCR_TRGSEL_Pos) 
#define  MDS_CONNCR_TRGSEL_Bit1                   (0x02U << MDS_CONNCR_TRGSEL_Pos) 
#define  MDS_CONNCR_TRGSEL_Bit2                   (0x04U << MDS_CONNCR_TRGSEL_Pos) 
#define  MDS_CONNCR_TRGSEL_Bit3                   (0x08U << MDS_CONNCR_TRGSEL_Pos) 
#define  MDS_CONNCR_TRGSEL_Bit4                   (0x10U << MDS_CONNCR_TRGSEL_Pos) 
#define  MDS_CONNCR_TRGSEL_Bit5                   (0x20U << MDS_CONNCR_TRGSEL_Pos) 
#define  MDS_CONNCR_CLUEN_Pos                     (16)
#define  MDS_CONNCR_CLUEN_Msk                     (0x1U << MDS_CONNCR_CLUEN_Pos)                    /*!<CLU Enable Register*/
#define  MDS_CONNCR_CLUEN                         MDS_CONNCR_CLUEN_Msk
#define  MDS_CONNCR_CLUSEL_Pos                    (17)
#define  MDS_CONNCR_CLUSEL_Msk                    (0x3U << MDS_CONNCR_CLUSEL_Pos)                   /*!<CLU Select Register*/
#define  MDS_CONNCR_CLUSEL                        MDS_CONNCR_CLUSEL_Msk
#define  MDS_CONNCR_CLUSEL_Bit0                   (0x1U << MDS_CONNCR_CLUSEL_Pos) 
#define  MDS_CONNCR_CLUSEL_Bit1                   (0x2U << MDS_CONNCR_CLUSEL_Pos) 

/**
  * @brief MDS_CONN_CLUSEL Register Bit Definition
  */
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Pos           (0)
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos)         /*!<CLU Input0 Select Register This register controls the option of CLU Input0 trigger source. See MindSwitch Connection Source Mapping for specific numbers.*/
#define  MDS_CONN_CLUSEL_CLUIN0_SEL               MDS_CONN_CLUSEL_CLUIN0_SEL_Msk
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Bit0          (0x01U << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Bit1          (0x02U << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Bit2          (0x04U << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Bit3          (0x08U << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Bit4          (0x10U << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN0_SEL_Bit5          (0x20U << MDS_CONN_CLUSEL_CLUIN0_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Pos           (8)
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos)         /*!<CLU Input1 Select Register This register controls the option of CLU Input1 trigger source. See MindSwitch Connection Source Mapping for specific numbers.*/
#define  MDS_CONN_CLUSEL_CLUIN1_SEL               MDS_CONN_CLUSEL_CLUIN1_SEL_Msk
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Bit0          (0x01U << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Bit1          (0x02U << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Bit2          (0x04U << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Bit3          (0x08U << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Bit4          (0x10U << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN1_SEL_Bit5          (0x20U << MDS_CONN_CLUSEL_CLUIN1_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Pos           (16)
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos)         /*!<CLU Input2 Select Register This register controls the option of CLU Input2 trigger source. See MindSwitch Connection Source Mapping for specific numbers.*/
#define  MDS_CONN_CLUSEL_CLUIN2_SEL               MDS_CONN_CLUSEL_CLUIN2_SEL_Msk
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Bit0          (0x01U << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Bit1          (0x02U << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Bit2          (0x04U << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Bit3          (0x08U << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Bit4          (0x10U << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN2_SEL_Bit5          (0x20U << MDS_CONN_CLUSEL_CLUIN2_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Pos           (24)
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Msk           (0x3FU << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos)         /*!<CLU Input3 Select Register This register controls the option of CLU Input3 trigger source. See MindSwitch Connection Source Mapping for specific numbers.*/
#define  MDS_CONN_CLUSEL_CLUIN3_SEL               MDS_CONN_CLUSEL_CLUIN3_SEL_Msk
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Bit0          (0x01U << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Bit1          (0x02U << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Bit2          (0x04U << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Bit3          (0x08U << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Bit4          (0x10U << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) 
#define  MDS_CONN_CLUSEL_CLUIN3_SEL_Bit5          (0x20U << MDS_CONN_CLUSEL_CLUIN3_SEL_Pos) 

/**
  * @brief MDS_CONN_CLUCFG Register Bit Definition
  */
#define  MDS_CONN_CLUCFG_CLMODE_Pos               (0)
#define  MDS_CONN_CLUCFG_CLMODE_Msk               (0x3U << MDS_CONN_CLUCFG_CLMODE_Pos)              /*!<CLU Mode Select*/
#define  MDS_CONN_CLUCFG_CLMODE                   MDS_CONN_CLUCFG_CLMODE_Msk
#define  MDS_CONN_CLUCFG_CLMODE_Bit0              (0x1U << MDS_CONN_CLUCFG_CLMODE_Pos) 
#define  MDS_CONN_CLUCFG_CLMODE_Bit1              (0x2U << MDS_CONN_CLUCFG_CLMODE_Pos) 
#define  MDS_CONN_CLUCFG_INV0_Pos                 (8)
#define  MDS_CONN_CLUCFG_INV0_Msk                 (0x1U << MDS_CONN_CLUCFG_INV0_Pos)                /*!<CLU Input0 Invert*/
#define  MDS_CONN_CLUCFG_INV0                     MDS_CONN_CLUCFG_INV0_Msk
#define  MDS_CONN_CLUCFG_INV1_Pos                 (9)
#define  MDS_CONN_CLUCFG_INV1_Msk                 (0x1U << MDS_CONN_CLUCFG_INV1_Pos)                /*!<CLU Input1 Invert*/
#define  MDS_CONN_CLUCFG_INV1                     MDS_CONN_CLUCFG_INV1_Msk
#define  MDS_CONN_CLUCFG_INV2_Pos                 (10)
#define  MDS_CONN_CLUCFG_INV2_Msk                 (0x1U << MDS_CONN_CLUCFG_INV2_Pos)                /*!<CLU Input2 Invert*/
#define  MDS_CONN_CLUCFG_INV2                     MDS_CONN_CLUCFG_INV2_Msk
#define  MDS_CONN_CLUCFG_INV3_Pos                 (11)
#define  MDS_CONN_CLUCFG_INV3_Msk                 (0x1U << MDS_CONN_CLUCFG_INV3_Pos)                /*!<CLU Input3 Invert*/
#define  MDS_CONN_CLUCFG_INV3                     MDS_CONN_CLUCFG_INV3_Msk


#endif

