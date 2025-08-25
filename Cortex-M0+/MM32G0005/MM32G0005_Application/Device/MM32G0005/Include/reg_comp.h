/***********************************************************************************************************************
    @file     reg_comp.h
    @author   VV TEAM
    @brief    This flie contains all the COMP's register and its field definition.
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

#ifndef __REG_COMP_H
#define __REG_COMP_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief COMP Base Address Definition
  */
#define  COMP_BASE                                 0x40014400                                       /*!<Base Address: 0x40014400*/

/**
  * @brief COMP Register Structure Definition
  */
typedef struct
{
    __IO uint32_t COMP1CSR;                       /*!<COMP COMP x (x=1) control and status register  offset: 0x00       */
    __IO uint32_t RESERVED0x04[5];                /*!<                                               offset: 0x04~0x14  */
    __IO uint32_t CRV;                            /*!<COMP COMP external reference voltage register  offset: 0x18       */
    __IO uint32_t COMP1POLL;                      /*!<COMP COMP x (x=1) polling register             offset: 0x1C       */
} COMP_TypeDef;

/**
  * @brief COMP type pointer Definition
  */
#define COMP                                      ((COMP_TypeDef *)COMP_BASE)

/**
  * @brief COMP_COMP1CSR Register Bit Definition
  */
#define  COMP_COMP1CSR_EN_Pos                     (0)
#define  COMP_COMP1CSR_EN_Msk                     (0x1U << COMP_COMP1CSR_EN_Pos)                    /*!<Comparator x enable This bit switches ON/OFF the comparator. 1: Comparator x enabled 0: Comparator x disabled*/
#define  COMP_COMP1CSR_EN                         COMP_COMP1CSR_EN_Msk
#define  COMP_COMP1CSR_MODE_Pos                   (2)
#define  COMP_COMP1CSR_MODE_Msk                   (0x3U << COMP_COMP1CSR_MODE_Pos)                  /*!<Comparator x mode These bits control the operating mode of the comparator x and allows to adjust the speed/consumption.*/
#define  COMP_COMP1CSR_MODE                       COMP_COMP1CSR_MODE_Msk
#define  COMP_COMP1CSR_MODE_Bit0                  (0x1U << COMP_COMP1CSR_MODE_Pos) 
#define  COMP_COMP1CSR_MODE_Bit1                  (0x2U << COMP_COMP1CSR_MODE_Pos) 
#define  COMP_COMP1CSR_INM_SEL_Pos                (4)
#define  COMP_COMP1CSR_INM_SEL_Msk                (0x7U << COMP_COMP1CSR_INM_SEL_Pos)               /*!<Comparator x negative input selection These bits allows to select the source connected to the negative input end of the comparator x. Comparator 1(x=1): 000: COMPx_INM0(PA4) , corresponding to the Input Negative Channel 0 001: COMPx_INM1(PA5) , corresponding to the Input Negative Channel 1 010: COMPx_INM2(PA0) , corresponding to the Input Negative Channel 2 011: COMPx_INM3(CRV) , corresponding to the Input Negative Channel 3 100: COMPx_INM4(DAC1_OUT_PRE) , corresponding to the Input Negative Channel 4 101: COMPx_INM5(DAC2_OUT_PRE) , corresponding to the Input Negative Channel 5 Other: no choice Comparator 2(x=2): 000: COMPx_INM0(PA4) , corresponding to the Input Negative Channel 0 001: COMPx_INM1(PA5) , corresponding to the Input Negative Channel 1 010: COMPx_INM2(PA2) , corresponding to the Input Negative Channel 2 011: COMPx_INM3(CRV) , corresponding to the Input Negative Channel 3 100: COMPx_INM4(DAC1_OUT_PRE) , corresponding to the Input Negative Channel 4 101: COMPx_INM5(DAC2_OUT_PRE) , corresponding to the Input Negative Channel 5 Other: no choice Comparator 3(x=3): 000: COMPx_INM0(PC0) , corresponding to the Input Negative Channel 0 001: COMPx_INM1(PB1) , corresponding to the Input Negative Channel 1 010: COMPx_INM2(PE8) , corresponding to the Input Negative Channel 2 011: COMPx_INM3(CRV) , corresponding to the Input Negative Channel 3 100: COMPx_INM4(DAC1_OUT_PRE) , corresponding to the Input Negative Channel 4 101: COMPx_INM5(DAC2_OUT_PRE) , corresponding to the Input Negative Channel 5 Other: no choice Comparator 4(x=4): 000: COMPx_INM0(PC0) , corresponding to the Input Negative Channel 0 001: COMPx_INM1(PB1) , corresponding to the Input Negative Channel 1 010: COMPx_INM2(PE8) , corresponding to the Input Negative Channel 2 011: COMPx_INM3(CRV) , corresponding to the Input Negative Channel 3 100: COMPx_INM4(DAC1_OUT_PRE) , corresponding to the Input Negative Channel 4 101: COMPx_INM5(DAC2_OUT_PRE) , corresponding to the Input Negative Channel 5 Other: no choice*/
#define  COMP_COMP1CSR_INM_SEL                    COMP_COMP1CSR_INM_SEL_Msk
#define  COMP_COMP1CSR_INM_SEL_Bit0               (0x1U << COMP_COMP1CSR_INM_SEL_Pos) 
#define  COMP_COMP1CSR_INM_SEL_Bit1               (0x2U << COMP_COMP1CSR_INM_SEL_Pos) 
#define  COMP_COMP1CSR_INM_SEL_Bit2               (0x4U << COMP_COMP1CSR_INM_SEL_Pos) 
#define  COMP_COMP1CSR_INP_SEL_Pos                (7)
#define  COMP_COMP1CSR_INP_SEL_Msk                (0x3U << COMP_COMP1CSR_INP_SEL_Pos)               /*!<Comparator x positive input selection These bits allows to select the source connected to the positive input end of the comparator x. Comparator 1(x=1): 000: COMPx_INP0(PA0) , corresponding to the Input Positive Channel 0 001: COMPx_INP1(PA1) , corresponding to the Input Positive Channel 1 010: COMPx_INP2(PA2) , corresponding to the Input Positive Channel 2 011: COMPx_INP3(PA3) , corresponding to the Input Positive Channel 3 100: COMPx_INP3(CRV) , corresponding to the Input Positive Channel 4 Other: no choice Comparator 2(x=2): 000: COMPx_INP0(PA0) , corresponding to the Input Positive Channel 0 001: COMPx_INP1(PA1) , corresponding to the Input Positive Channel 1 010: COMPx_INP2(PA2) , corresponding to the Input Positive Channel 2 011: COMPx_INP3(PA3) , corresponding to the Input Positive Channel 3 100: COMPx_INP3(CRV) , corresponding to the Input Positive Channel 4 Other: no choice Comparator 3(x=3): 000: COMPx_INP0(PC1) , corresponding to the Input Positive Channel 0 001: COMPx_INP1(PB0) , corresponding to the Input Positive Channel 1 010: COMPx_INP2(PE7) , corresponding to the Input Positive Channel 2 011: COMPx_INP3(PA0) , corresponding to the Input Positive Channel 3 100: COMPx_INP3(CRV) , corresponding to the Input Positive Channel 4 Other: no choice Comparator 4(x=4): 000: COMPx_INP0(PC1) , corresponding to the Input Positive Channel 0 001: COMPx_INP1(PB0) , corresponding to the Input Positive Channel 1 010: COMPx_INP2(PE7) , corresponding to the Input Positive Channel 2 011: COMPx_INP3(PA0) , corresponding to the Input Positive Channel 3 100: COMPx_INP3(CRV) , corresponding to the Input Positive Channel 4 Other: no choice*/
#define  COMP_COMP1CSR_INP_SEL                    COMP_COMP1CSR_INP_SEL_Msk
#define  COMP_COMP1CSR_INP_SEL_Bit0               (0x1U << COMP_COMP1CSR_INP_SEL_Pos) 
#define  COMP_COMP1CSR_INP_SEL_Bit1               (0x2U << COMP_COMP1CSR_INP_SEL_Pos) 
#define  COMP_COMP1CSR_OUT_SEL_Pos                (10)
#define  COMP_COMP1CSR_OUT_SEL_Msk                (0xFU << COMP_COMP1CSR_OUT_SEL_Pos)               /*!<Comparator x output selection These bits select the destination of the comparator x output. For specific configuration methods and mapping relationships, please refer to "Comparator Output Direction Selection Table" in the "hardware interconnection" of the chapter "chip-specific configuration". In addition to changing the output selection of comparator by configuring OUT_SEL, you can also configure relative registers of SYSCFG, referring to the "TIM Input Capture Event Interconnection Table", "TIM OCREFCLR Event Interconnection Table", and "TIM Brake Event Interconnection Table".*/
#define  COMP_COMP1CSR_OUT_SEL                    COMP_COMP1CSR_OUT_SEL_Msk
#define  COMP_COMP1CSR_OUT_SEL_Bit0               (0x1U << COMP_COMP1CSR_OUT_SEL_Pos) 
#define  COMP_COMP1CSR_OUT_SEL_Bit1               (0x2U << COMP_COMP1CSR_OUT_SEL_Pos) 
#define  COMP_COMP1CSR_OUT_SEL_Bit2               (0x4U << COMP_COMP1CSR_OUT_SEL_Pos) 
#define  COMP_COMP1CSR_OUT_SEL_Bit3               (0x8U << COMP_COMP1CSR_OUT_SEL_Pos) 
#define  COMP_COMP1CSR_POL_Pos                    (15)
#define  COMP_COMP1CSR_POL_Msk                    (0x1U << COMP_COMP1CSR_POL_Pos)                   /*!<Comparator x output polarity This bit is used to select the comparator x output polarity. 1: Output is inverted from the terminal 0: Output is not inverted from the terminal*/
#define  COMP_COMP1CSR_POL                        COMP_COMP1CSR_POL_Msk
#define  COMP_COMP1CSR_HYST_Pos                   (16)
#define  COMP_COMP1CSR_HYST_Msk                   (0x3U << COMP_COMP1CSR_HYST_Pos)                  /*!<Comparator x hysteresis These bits control the comparator x hysteresis level. 11: 30mV 10: 20mV 01: 10mV 00: 0mV*/
#define  COMP_COMP1CSR_HYST                       COMP_COMP1CSR_HYST_Msk
#define  COMP_COMP1CSR_HYST_Bit0                  (0x1U << COMP_COMP1CSR_HYST_Pos) 
#define  COMP_COMP1CSR_HYST_Bit1                  (0x2U << COMP_COMP1CSR_HYST_Pos) 
#define  COMP_COMP1CSR_OFLT_Pos                   (18)
#define  COMP_COMP1CSR_OFLT_Msk                   (0x7U << COMP_COMP1CSR_OFLT_Pos)                  /*!<Comparator x Output Filter Period These bits control the comparator x output filter period. When the comparator output signal is shorter than the filter period width, it is considered as invalid to be filtered out, otherwise it is considered as valid. n indicates the number of Polling Wait Cycle configured with COMPx_CSR -> PERIOD. 111: 128 * n clock cycles 110: 64 * n clock cycles 101: 32 * n clock cycles 100: 16 * n clock cycles 011: 8 * n clock cycles 010: 4 * n clock cycles 001: 2 * n clock cycles 000: no filter*/
#define  COMP_COMP1CSR_OFLT                       COMP_COMP1CSR_OFLT_Msk
#define  COMP_COMP1CSR_OFLT_Bit0                  (0x1U << COMP_COMP1CSR_OFLT_Pos) 
#define  COMP_COMP1CSR_OFLT_Bit1                  (0x2U << COMP_COMP1CSR_OFLT_Pos) 
#define  COMP_COMP1CSR_OFLT_Bit2                  (0x4U << COMP_COMP1CSR_OFLT_Pos) 
#define  COMP_COMP1CSR_OUT_ANA_SEL_Pos            (29)
#define  COMP_COMP1CSR_OUT_ANA_SEL_Msk            (0x1U << COMP_COMP1CSR_OUT_ANA_SEL_Pos)           /*!<Comparator x output source selection 1: Directly output analog compared resullt to the end 0: Transfer output analog compared resullt to the filtering module that can filter and synchronize*/
#define  COMP_COMP1CSR_OUT_ANA_SEL                COMP_COMP1CSR_OUT_ANA_SEL_Msk
#define  COMP_COMP1CSR_OUT_Pos                    (30)
#define  COMP_COMP1CSR_OUT_Msk                    (0x1U << COMP_COMP1CSR_OUT_Pos)                   /*!<Comparator x output This bit indicates the comparator x output state. 1: Output is high (Positive input is greater than negative input in voltage) 0: Output is low (Positive input is less than negative input in voltage)*/
#define  COMP_COMP1CSR_OUT                        COMP_COMP1CSR_OUT_Msk
#define  COMP_COMP1CSR_LOCK_Pos                   (31)
#define  COMP_COMP1CSR_LOCK_Msk                   (0x1U << COMP_COMP1CSR_LOCK_Pos)                  /*!<Comparator register lock This bit is write-once. It is set by software. It can be cleared by a system reset. Once set, it allows to have all control bits of comparator x as read-only. 1: COMPx_CSR is read-only 0: COMPx_CSR is read-write*/
#define  COMP_COMP1CSR_LOCK                       COMP_COMP1CSR_LOCK_Msk

/**
  * @brief COMP_CRV Register Bit Definition
  */
#define  COMP_CRV_CRV_SEL_Pos                     (0)
#define  COMP_CRV_CRV_SEL_Msk                     (0xFFU << COMP_CRV_CRV_SEL_Pos)                   /*!<*/
#define  COMP_CRV_CRV_SEL                         COMP_CRV_CRV_SEL_Msk
#define  COMP_CRV_CRV_SEL_Bit0                    (0x01U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit1                    (0x02U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit2                    (0x04U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit3                    (0x08U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit4                    (0x10U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit5                    (0x20U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit6                    (0x40U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SEL_Bit7                    (0x80U << COMP_CRV_CRV_SEL_Pos) 
#define  COMP_CRV_CRV_SRC_Pos                     (12)
#define  COMP_CRV_CRV_SRC_Msk                     (0x1U << COMP_CRV_CRV_SRC_Pos)                    /*!<*/
#define  COMP_CRV_CRV_SRC                         COMP_CRV_CRV_SRC_Msk
#define  COMP_CRV_CRV_EN_Pos                      (15)
#define  COMP_CRV_CRV_EN_Msk                      (0x1U << COMP_CRV_CRV_EN_Pos)                     /*!<*/
#define  COMP_CRV_CRV_EN                          COMP_CRV_CRV_EN_Msk

/**
  * @brief COMP_COMP1POLL Register Bit Definition
  */
#define  COMP_COMP1POLL_POLL_EN_Pos               (0)
#define  COMP_COMP1POLL_POLL_EN_Msk               (0x1U << COMP_COMP1POLL_POLL_EN_Pos)              /*!<Comparator Polling Enable*/
#define  COMP_COMP1POLL_POLL_EN                   COMP_COMP1POLL_POLL_EN_Msk
#define  COMP_COMP1POLL_POLL_CH_Pos               (1)
#define  COMP_COMP1POLL_POLL_CH_Msk               (0x1U << COMP_COMP1POLL_POLL_CH_Pos)              /*!<Comparator Polling Channel*/
#define  COMP_COMP1POLL_POLL_CH                   COMP_COMP1POLL_POLL_CH_Msk
#define  COMP_COMP1POLL_FIXN_Pos                  (2)
#define  COMP_COMP1POLL_FIXN_Msk                  (0x1U << COMP_COMP1POLL_FIXN_Pos)                 /*!<Polling Negative Input Fix*/
#define  COMP_COMP1POLL_FIXN                      COMP_COMP1POLL_FIXN_Msk
#define  COMP_COMP1POLL_PERIOD_Pos                (4)
#define  COMP_COMP1POLL_PERIOD_Msk                (0x7U << COMP_COMP1POLL_PERIOD_Pos)               /*!<Polling Wait Cycle Switch to the next polling channel every n PCLK2 cycles.*/
#define  COMP_COMP1POLL_PERIOD                    COMP_COMP1POLL_PERIOD_Msk
#define  COMP_COMP1POLL_PERIOD_Bit0               (0x1U << COMP_COMP1POLL_PERIOD_Pos) 
#define  COMP_COMP1POLL_PERIOD_Bit1               (0x2U << COMP_COMP1POLL_PERIOD_Pos) 
#define  COMP_COMP1POLL_PERIOD_Bit2               (0x4U << COMP_COMP1POLL_PERIOD_Pos) 
#define  COMP_COMP1POLL_POUT_Pos                  (8)
#define  COMP_COMP1POLL_POUT_Msk                  (0x7U << COMP_COMP1POLL_POUT_Pos)                 /*!<Polling Output This bit is read-only. It reflects the polling channel output state. POUT[0] corresponds to channel 1. POUT[1] corresponds to channel 2. POUT[2] corresponds to channel 3.*/
#define  COMP_COMP1POLL_POUT                      COMP_COMP1POLL_POUT_Msk
#define  COMP_COMP1POLL_POUT_Bit0                 (0x1U << COMP_COMP1POLL_POUT_Pos) 
#define  COMP_COMP1POLL_POUT_Bit1                 (0x2U << COMP_COMP1POLL_POUT_Pos) 
#define  COMP_COMP1POLL_POUT_Bit2                 (0x4U << COMP_COMP1POLL_POUT_Pos) 


#endif

