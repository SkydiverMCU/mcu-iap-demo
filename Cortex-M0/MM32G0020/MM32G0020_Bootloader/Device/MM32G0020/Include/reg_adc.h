
/***********************************************************************************************************************
    @file     reg_adc.h
    @author   VV TEAM
    @brief    This flie contains all the ADC's register and its field definition.
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
#ifndef __REG_ADC_H
#define __REG_ADC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0.h"

/**
  * @brief ADC Base Address Definition
  */
#define  ADC1_BASE                                 0x40012400                                       /*!<Base Address: 0x40012400*/

/**
  * @brief ADC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ADDATA;                         /*!<ADC Data Register                              offset: 0x00       */
    __IO uint32_t ADCFG;                          /*!<ADC Configuration Register                     offset: 0x04       */
    __IO uint32_t ADCR;                           /*!<ADC Control Register                           offset: 0x08       */
    __IO uint32_t ADCHS;                          /*!<ADC Channel Selection Register                 offset: 0x0C       */
    __IO uint32_t ADCMPR;                         /*!<ADC Analog Watchdog Compare Register           offset: 0x10       */
    __IO uint32_t ADSTA;                          /*!<ADC Status Register                            offset: 0x14       */
    __IO uint32_t ADDR0;                          /*!<ADC Channel Data Register                      offset: 0x18       */
    __IO uint32_t ADDR1;                          /*!<ADC Channel Data Register                      offset: 0x1C       */
    __IO uint32_t ADDR2;                          /*!<ADC Channel Data Register                      offset: 0x20       */
    __IO uint32_t ADDR3;                          /*!<ADC Channel Data Register                      offset: 0x24       */
    __IO uint32_t ADDR4;                          /*!<ADC Channel Data Register                      offset: 0x28       */
    __IO uint32_t ADDR5;                          /*!<ADC Channel Data Register                      offset: 0x2C       */
    __IO uint32_t ADDR6;                          /*!<ADC Channel Data Register                      offset: 0x30       */
    __IO uint32_t ADDR7;                          /*!<ADC Channel Data Register                      offset: 0x34       */
    __IO uint32_t ADDR8;                          /*!<ADC Channel Data Register                      offset: 0x38       */
    __IO uint32_t RESERVED0x3C[7];                /*!<                                               offset: 0x3C~0x54  */
    __IO uint32_t ADSTA_EXT;                      /*!<ADC Extended State Register                    offset: 0x58       */
    __IO uint32_t CHANY0;                         /*!<ADC Any Channel Selection Register 0           offset: 0x5C       */
    __IO uint32_t CHANY1;                         /*!<ADC Any Channel Selection Register 1           offset: 0x60       */
    __IO uint32_t ANY_CFG;                        /*!<ADC Any Channel Configuration Register         offset: 0x64       */
    __IO uint32_t ANY_CR;                         /*!<ADC Any Channel Control Register               offset: 0x68       */
    __IO uint32_t RESERVED0x6C[1];                /*!<                                               offset: 0x6C       */
    __IO uint32_t SMPR1;                          /*!<ADC Sample Configuration Register 1            offset: 0x70       */
    __IO uint32_t SMPR2;                          /*!<ADC Sample Configuration Register 2            offset: 0x74       */
} ADC_TypeDef;

/**
  * @brief ADC type pointer Definition
  */
#define ADC1                                      ((ADC_TypeDef *)ADC1_BASE)

/**
  * @brief ADC_ADDATA Register Bit Definition
  */
#define  ADC_ADDATA_DATA_Pos                      (0)
#define  ADC_ADDATA_DATA_Msk                      (0xFFFFU << ADC_ADDATA_DATA_Pos)                  /*!<12-bit A/D conversion result of the current channel (Conversion Data)*/
#define  ADC_ADDATA_DATA                          ADC_ADDATA_DATA_Msk
#define  ADC_ADDATA_DATA_0                        (0x0001U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_1                        (0x0002U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_2                        (0x0004U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_3                        (0x0008U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_4                        (0x0010U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_5                        (0x0020U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_6                        (0x0040U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_7                        (0x0080U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_8                        (0x0100U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_9                        (0x0200U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_10                       (0x0400U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_11                       (0x0800U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_12                       (0x1000U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_13                       (0x2000U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_14                       (0x4000U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_DATA_15                       (0x8000U << ADC_ADDATA_DATA_Pos)
#define  ADC_ADDATA_CHANNELSEL_Pos                (16)
#define  ADC_ADDATA_CHANNELSEL_Msk                (0xFU << ADC_ADDATA_CHANNELSEL_Pos)               /*!<4 bits show the channel corresponding to the data in the current data register (Channel Selection)*/
#define  ADC_ADDATA_CHANNELSEL                    ADC_ADDATA_CHANNELSEL_Msk
#define  ADC_ADDATA_CHANNELSEL_0                  (0x1U << ADC_ADDATA_CHANNELSEL_Pos)
#define  ADC_ADDATA_CHANNELSEL_1                  (0x2U << ADC_ADDATA_CHANNELSEL_Pos)
#define  ADC_ADDATA_CHANNELSEL_2                  (0x4U << ADC_ADDATA_CHANNELSEL_Pos)
#define  ADC_ADDATA_CHANNELSEL_3                  (0x8U << ADC_ADDATA_CHANNELSEL_Pos)
#define  ADC_ADDATA_OVERRUN_Pos                   (20)
#define  ADC_ADDATA_OVERRUN_Msk                   (0x1U << ADC_ADDATA_OVERRUN_Pos)                  /*!<Data overrun flag (read-only)*/
#define  ADC_ADDATA_OVERRUN                       ADC_ADDATA_OVERRUN_Msk
#define  ADC_ADDATA_VALID_Pos                     (21)
#define  ADC_ADDATA_VALID_Msk                     (0x1U << ADC_ADDATA_VALID_Pos)                    /*!<Valid flag for data (read-only)*/
#define  ADC_ADDATA_VALID                         ADC_ADDATA_VALID_Msk

/**
  * @brief ADC_ADCFG Register Bit Definition
  */
#define  ADC_ADCFG_ADEN_Pos                       (0)
#define  ADC_ADCFG_ADEN_Msk                       (0x1U << ADC_ADCFG_ADEN_Pos)                      /*!<A/D conversion enable (ADC enable)*/
#define  ADC_ADCFG_ADEN                           ADC_ADCFG_ADEN_Msk
#define  ADC_ADCFG_ADWEN_Pos                      (1)
#define  ADC_ADCFG_ADWEN_Msk                      (0x1U << ADC_ADCFG_ADWEN_Pos)                     /*!<Analog watchdog enable on non-injected channels*/
#define  ADC_ADCFG_ADWEN                          ADC_ADCFG_ADWEN_Msk
#define  ADC_ADCFG_VSEN_Pos                       (3)
#define  ADC_ADCFG_VSEN_Msk                       (0x1U << ADC_ADCFG_VSEN_Pos)                      /*!<Internal reference voltage and temperature sensor enable (Voltage Sensor and Temperature Sensor Enable)*/
#define  ADC_ADCFG_VSEN                           ADC_ADCFG_VSEN_Msk
#define  ADC_ADCFG_ADCPREH_Pos                    (4)
#define  ADC_ADCFG_ADCPREH_Msk                    (0x7U << ADC_ADCFG_ADCPREH_Pos)                   /*!<ADC Prescaler High Bits*/
#define  ADC_ADCFG_ADCPREH                        ADC_ADCFG_ADCPREH_Msk
#define  ADC_ADCFG_ADCPREH_0                      (0x1U << ADC_ADCFG_ADCPREH_Pos)
#define  ADC_ADCFG_ADCPREH_1                      (0x2U << ADC_ADCFG_ADCPREH_Pos)
#define  ADC_ADCFG_ADCPREH_2                      (0x4U << ADC_ADCFG_ADCPREH_Pos)
#define  ADC_ADCFG_RSLTCTL_Pos                    (7)
#define  ADC_ADCFG_RSLTCTL_Msk                    (0x7U << ADC_ADCFG_RSLTCTL_Pos)                   /*!<ADC conversion data resolution selection*/
#define  ADC_ADCFG_RSLTCTL                        ADC_ADCFG_RSLTCTL_Msk
#define  ADC_ADCFG_RSLTCTL_0                      (0x1U << ADC_ADCFG_RSLTCTL_Pos)
#define  ADC_ADCFG_RSLTCTL_1                      (0x2U << ADC_ADCFG_RSLTCTL_Pos)
#define  ADC_ADCFG_RSLTCTL_2                      (0x4U << ADC_ADCFG_RSLTCTL_Pos)
#define  ADC_ADCFG_ADCPREL_Pos                    (14)
#define  ADC_ADCFG_ADCPREL_Msk                    (0x1U << ADC_ADCFG_ADCPREL_Pos)                   /*!<ADC Prescaler Low Bits*/
#define  ADC_ADCFG_ADCPREL                        ADC_ADCFG_ADCPREL_Msk

/**
  * @brief ADC_ADCR Register Bit Definition
  */
#define  ADC_ADCR_EOSIE_Pos                       (0)
#define  ADC_ADCR_EOSIE_Msk                       (0x1U << ADC_ADCR_EOSIE_Pos)                      /*!<Interrupt Enable for End of Sequence*/
#define  ADC_ADCR_EOSIE                           ADC_ADCR_EOSIE_Msk
#define  ADC_ADCR_AWDIE_Pos                       (1)
#define  ADC_ADCR_AWDIE_Msk                       (0x1U << ADC_ADCR_AWDIE_Pos)                      /*!<Interrupt Enable of Analog Watchdog*/
#define  ADC_ADCR_AWDIE                           ADC_ADCR_AWDIE_Msk
#define  ADC_ADCR_TRGEN_Pos                       (2)
#define  ADC_ADCR_TRGEN_Msk                       (0x1U << ADC_ADCR_TRGEN_Pos)                      /*!<External Hardware Trigger Sources Enable*/
#define  ADC_ADCR_TRGEN                           ADC_ADCR_TRGEN_Msk
#define  ADC_ADCR_TRGSELL_Pos                     (4)
#define  ADC_ADCR_TRGSELL_Msk                     (0x7U << ADC_ADCR_TRGSELL_Pos)                    /*!<External Trigger sources Select for Low bits TRGSEL={TRGSELH,TRGSELL}*/
#define  ADC_ADCR_TRGSELL                         ADC_ADCR_TRGSELL_Msk
#define  ADC_ADCR_TRGSELL_0                       (0x1U << ADC_ADCR_TRGSELL_Pos) 
#define  ADC_ADCR_TRGSELL_1                       (0x2U << ADC_ADCR_TRGSELL_Pos) 
#define  ADC_ADCR_TRGSELL_2                       (0x4U << ADC_ADCR_TRGSELL_Pos) 
#define  ADC_ADCR_ADST_Pos                        (8)
#define  ADC_ADCR_ADST_Msk                        (0x1U << ADC_ADCR_ADST_Pos)                       /*!<A/D conversion start*/
#define  ADC_ADCR_ADST                            ADC_ADCR_ADST_Msk
#define  ADC_ADCR_ADMD_Pos                        (9)
#define  ADC_ADCR_ADMD_Msk                        (0x3U << ADC_ADCR_ADMD_Pos)                       /*!<A/D conversion mode (ADC Mode)*/
#define  ADC_ADCR_ADMD                            ADC_ADCR_ADMD_Msk
#define  ADC_ADCR_ADMD_0                          (0x1U << ADC_ADCR_ADMD_Pos) 
#define  ADC_ADCR_ADMD_1                          (0x2U << ADC_ADCR_ADMD_Pos) 
#define  ADC_ADCR_ALIGN_Pos                       (11)
#define  ADC_ADCR_ALIGN_Msk                       (0x1U << ADC_ADCR_ALIGN_Pos)                      /*!<Data Alignment*/
#define  ADC_ADCR_ALIGN                           ADC_ADCR_ALIGN_Msk
#define  ADC_ADCR_CMPCH_Pos                       (12)
#define  ADC_ADCR_CMPCH_Msk                       (0xFU << ADC_ADCR_CMPCH_Pos)                      /*!<Compare Channel Selection For Analog Watchdog*/
#define  ADC_ADCR_CMPCH                           ADC_ADCR_CMPCH_Msk
#define  ADC_ADCR_CMPCH_0                         (0x1U << ADC_ADCR_CMPCH_Pos) 
#define  ADC_ADCR_CMPCH_1                         (0x2U << ADC_ADCR_CMPCH_Pos) 
#define  ADC_ADCR_CMPCH_2                         (0x4U << ADC_ADCR_CMPCH_Pos) 
#define  ADC_ADCR_CMPCH_3                         (0x8U << ADC_ADCR_CMPCH_Pos) 
#define  ADC_ADCR_SCANDIR_Pos                     (16)
#define  ADC_ADCR_SCANDIR_Msk                     (0x1U << ADC_ADCR_SCANDIR_Pos)                    /*!<ADC Channel Scan Direction*/
#define  ADC_ADCR_SCANDIR                         ADC_ADCR_SCANDIR_Msk
#define  ADC_ADCR_TRGSELH_Pos                     (17)
#define  ADC_ADCR_TRGSELH_Msk                     (0x3U << ADC_ADCR_TRGSELH_Pos)                    /*!<External Trigger Sources Select For High Bits*/
#define  ADC_ADCR_TRGSELH                         ADC_ADCR_TRGSELH_Msk
#define  ADC_ADCR_TRGSELH_0                       (0x1U << ADC_ADCR_TRGSELH_Pos) 
#define  ADC_ADCR_TRGSELH_1                       (0x2U << ADC_ADCR_TRGSELH_Pos) 
#define  ADC_ADCR_TRGSHIFT_Pos                    (19)
#define  ADC_ADCR_TRGSHIFT_Msk                    (0x7U << ADC_ADCR_TRGSHIFT_Pos)                   /*!<External Trigger Sources Shift For Sample*/
#define  ADC_ADCR_TRGSHIFT                        ADC_ADCR_TRGSHIFT_Msk
#define  ADC_ADCR_TRGSHIFT_0                      (0x1U << ADC_ADCR_TRGSHIFT_Pos) 
#define  ADC_ADCR_TRGSHIFT_1                      (0x2U << ADC_ADCR_TRGSHIFT_Pos) 
#define  ADC_ADCR_TRGSHIFT_2                      (0x4U << ADC_ADCR_TRGSHIFT_Pos) 
#define  ADC_ADCR_TRG_EDGE_Pos                    (24)
#define  ADC_ADCR_TRG_EDGE_Msk                    (0x3U << ADC_ADCR_TRG_EDGE_Pos)                   /*!<Trigger Sources Edge Selection*/
#define  ADC_ADCR_TRG_EDGE                        ADC_ADCR_TRG_EDGE_Msk
#define  ADC_ADCR_TRG_EDGE_0                      (0x1U << ADC_ADCR_TRG_EDGE_Pos) 
#define  ADC_ADCR_TRG_EDGE_1                      (0x2U << ADC_ADCR_TRG_EDGE_Pos) 
#define  ADC_ADCR_EOSMPIE_Pos                     (26)
#define  ADC_ADCR_EOSMPIE_Msk                     (0x1U << ADC_ADCR_EOSMPIE_Pos)                    /*!<Interrupt Enable for End of Sample*/
#define  ADC_ADCR_EOSMPIE                         ADC_ADCR_EOSMPIE_Msk
#define  ADC_ADCR_EOCIE_Pos                       (27)
#define  ADC_ADCR_EOCIE_Msk                       (0x1U << ADC_ADCR_EOCIE_Pos)                      /*!<Interrupt Enable for End of Conversion*/
#define  ADC_ADCR_EOCIE                           ADC_ADCR_EOCIE_Msk

/**
  * @brief ADC_ADCHS Register Bit Definition
  */
#define  ADC_ADCHS_CHEN0_Pos                      (0)
#define  ADC_ADCHS_CHEN0_Msk                      (0x1U << ADC_ADCHS_CHEN0_Pos)                     /*!<Analog Input Channel 0 Enable*/
#define  ADC_ADCHS_CHEN0                          ADC_ADCHS_CHEN0_Msk
#define  ADC_ADCHS_CHEN1_Pos                      (1)
#define  ADC_ADCHS_CHEN1_Msk                      (0x1U << ADC_ADCHS_CHEN1_Pos)                     /*!<Analog Input Channel 1 Enable*/
#define  ADC_ADCHS_CHEN1                          ADC_ADCHS_CHEN1_Msk
#define  ADC_ADCHS_CHEN2_Pos                      (2)
#define  ADC_ADCHS_CHEN2_Msk                      (0x1U << ADC_ADCHS_CHEN2_Pos)                     /*!<Analog Input Channel 2 Enable*/
#define  ADC_ADCHS_CHEN2                          ADC_ADCHS_CHEN2_Msk
#define  ADC_ADCHS_CHEN3_Pos                      (3)
#define  ADC_ADCHS_CHEN3_Msk                      (0x1U << ADC_ADCHS_CHEN3_Pos)                     /*!<Analog Input Channel 3 Enable*/
#define  ADC_ADCHS_CHEN3                          ADC_ADCHS_CHEN3_Msk
#define  ADC_ADCHS_CHEN4_Pos                      (4)
#define  ADC_ADCHS_CHEN4_Msk                      (0x1U << ADC_ADCHS_CHEN4_Pos)                     /*!<Analog Input Channel 4 Enable*/
#define  ADC_ADCHS_CHEN4                          ADC_ADCHS_CHEN4_Msk
#define  ADC_ADCHS_CHEN5_Pos                      (5)
#define  ADC_ADCHS_CHEN5_Msk                      (0x1U << ADC_ADCHS_CHEN5_Pos)                     /*!<Analog Input Channel 5 Enable*/
#define  ADC_ADCHS_CHEN5                          ADC_ADCHS_CHEN5_Msk
#define  ADC_ADCHS_CHEN6_Pos                      (6)
#define  ADC_ADCHS_CHEN6_Msk                      (0x1U << ADC_ADCHS_CHEN6_Pos)                     /*!<Analog Input Channel 6 Enable*/
#define  ADC_ADCHS_CHEN6                          ADC_ADCHS_CHEN6_Msk
#define  ADC_ADCHS_CHEN7_Pos                      (7)
#define  ADC_ADCHS_CHEN7_Msk                      (0x1U << ADC_ADCHS_CHEN7_Pos)                     /*!<Analog Input Channel 7 Enable*/
#define  ADC_ADCHS_CHEN7                          ADC_ADCHS_CHEN7_Msk
#define  ADC_ADCHS_CHEN8_Pos                      (8)
#define  ADC_ADCHS_CHEN8_Msk                      (0x1U << ADC_ADCHS_CHEN8_Pos)                     /*!<ADC: Voltage Sensor Enable*/
#define  ADC_ADCHS_CHEN8                          ADC_ADCHS_CHEN8_Msk

/**
  * @brief ADC_ADCMPR Register Bit Definition
  */
#define  ADC_ADCMPR_CMPLDATA_Pos                  (0)
#define  ADC_ADCMPR_CMPLDATA_Msk                  (0xFFFU << ADC_ADCMPR_CMPLDATA_Pos)               /*!<Compare Low Threshold Data For Analog Watchdog*/
#define  ADC_ADCMPR_CMPLDATA                      ADC_ADCMPR_CMPLDATA_Msk
#define  ADC_ADCMPR_CMPLDATA_0                    (0x001U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_1                    (0x002U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_2                    (0x004U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_3                    (0x008U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_4                    (0x010U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_5                    (0x020U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_6                    (0x040U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_7                    (0x080U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_8                    (0x100U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_9                    (0x200U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_10                   (0x400U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_11                   (0x800U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Pos                  (16)
#define  ADC_ADCMPR_CMPHDATA_Msk                  (0xFFFU << ADC_ADCMPR_CMPHDATA_Pos)               /*!<Compare High Threshold Data For Analog Watchdog*/
#define  ADC_ADCMPR_CMPHDATA                      ADC_ADCMPR_CMPHDATA_Msk
#define  ADC_ADCMPR_CMPHDATA_0                    (0x001U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_1                    (0x002U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_2                    (0x004U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_3                    (0x008U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_4                    (0x010U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_5                    (0x020U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_6                    (0x040U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_7                    (0x080U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_8                    (0x100U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_9                    (0x200U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_10                   (0x400U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_11                   (0x800U << ADC_ADCMPR_CMPHDATA_Pos) 

/**
  * @brief ADC_ADSTA Register Bit Definition
  */
#define  ADC_ADSTA_EOSIF_Pos                      (0)
#define  ADC_ADSTA_EOSIF_Msk                      (0x1U << ADC_ADSTA_EOSIF_Pos)                     /*!<End of Sequential Conversion Flag*/
#define  ADC_ADSTA_EOSIF                          ADC_ADSTA_EOSIF_Msk
#define  ADC_ADSTA_AWDIF_Pos                      (1)
#define  ADC_ADSTA_AWDIF_Msk                      (0x1U << ADC_ADSTA_AWDIF_Pos)                     /*!<Analog Watchdog Flag*/
#define  ADC_ADSTA_AWDIF                          ADC_ADSTA_AWDIF_Msk
#define  ADC_ADSTA_BUSY_Pos                       (2)
#define  ADC_ADSTA_BUSY_Msk                       (0x1U << ADC_ADSTA_BUSY_Pos)                      /*!<Non-Injected Conversion Busy/Idle*/
#define  ADC_ADSTA_BUSY                           ADC_ADSTA_BUSY_Msk
#define  ADC_ADSTA_CHANNEL_Pos                    (4)
#define  ADC_ADSTA_CHANNEL_Msk                    (0xFU << ADC_ADSTA_CHANNEL_Pos)                   /*!<Current Convert Channel*/
#define  ADC_ADSTA_CHANNEL                        ADC_ADSTA_CHANNEL_Msk
#define  ADC_ADSTA_CHANNEL_0                      (0x1U << ADC_ADSTA_CHANNEL_Pos) 
#define  ADC_ADSTA_CHANNEL_1                      (0x2U << ADC_ADSTA_CHANNEL_Pos) 
#define  ADC_ADSTA_CHANNEL_2                      (0x4U << ADC_ADSTA_CHANNEL_Pos) 
#define  ADC_ADSTA_CHANNEL_3                      (0x8U << ADC_ADSTA_CHANNEL_Pos) 
#define  ADC_ADSTA_VALID_Pos                      (8)
#define  ADC_ADSTA_VALID_Msk                      (0x1FFU << ADC_ADSTA_VALID_Pos)                   /*!<Valid flag for channel 0 to channel 8*/
#define  ADC_ADSTA_VALID                          ADC_ADSTA_VALID_Msk
#define  ADC_ADSTA_VALID_0                        (0x001U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_1                        (0x002U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_2                        (0x004U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_3                        (0x008U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_4                        (0x010U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_5                        (0x020U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_6                        (0x040U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_7                        (0x080U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_8                        (0x100U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_OVERRUN_Pos                    (20)
#define  ADC_ADSTA_OVERRUN_Msk                    (0x1FFU << ADC_ADSTA_OVERRUN_Pos)                 /*!<Data overrun flag for channel 0 to channel 8*/
#define  ADC_ADSTA_OVERRUN                        ADC_ADSTA_OVERRUN_Msk
#define  ADC_ADSTA_OVERRUN_0                      (0x001U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_1                      (0x002U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_2                      (0x004U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_3                      (0x008U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_4                      (0x010U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_5                      (0x020U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_6                      (0x040U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_7                      (0x080U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_8                      (0x100U << ADC_ADSTA_OVERRUN_Pos) 

/**
  * @brief ADC_ADDR Register Bit Definition
  */
#define  ADC_ADDR_DATA_Pos                        (0)
#define  ADC_ADDR_DATA_Msk                        (0xFFFFU << ADC_ADDR_DATA_Pos)                    /*!<12-bit A/D conversion result from the channel n (Conversion Data)*/
#define  ADC_ADDR_DATA                            ADC_ADDR_DATA_Msk
#define  ADC_ADDR_DATA_0                          (0x0001U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_1                          (0x0002U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_2                          (0x0004U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_3                          (0x0008U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_4                          (0x0010U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_5                          (0x0020U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_6                          (0x0040U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_7                          (0x0080U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_8                          (0x0100U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_9                          (0x0200U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_10                         (0x0400U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_11                         (0x0800U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_12                         (0x1000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_13                         (0x2000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_14                         (0x4000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_15                         (0x8000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_OVERRUN_Pos                     (20)
#define  ADC_ADDR_OVERRUN_Msk                     (0x1U << ADC_ADDR_OVERRUN_Pos)                    /*!<Data overrun flag (read-only)*/
#define  ADC_ADDR_OVERRUN                         ADC_ADDR_OVERRUN_Msk
#define  ADC_ADDR_VALID_Pos                       (21)
#define  ADC_ADDR_VALID_Msk                       (0x1U << ADC_ADDR_VALID_Pos)                      /*!<Valid flag (read-only)*/
#define  ADC_ADDR_VALID                           ADC_ADDR_VALID_Msk

/**
  * @brief ADC_ADSTA_EXT Register Bit Definition
  */
#define  ADC_ADSTA_EXT_EOSMPIF_Pos                (16)
#define  ADC_ADSTA_EXT_EOSMPIF_Msk                (0x1U << ADC_ADSTA_EXT_EOSMPIF_Pos)               /*!<End of Sample Flag*/
#define  ADC_ADSTA_EXT_EOSMPIF                    ADC_ADSTA_EXT_EOSMPIF_Msk
#define  ADC_ADSTA_EXT_EOCIF_Pos                  (17)
#define  ADC_ADSTA_EXT_EOCIF_Msk                  (0x1U << ADC_ADSTA_EXT_EOCIF_Pos)                 /*!<End of Conversion Flag*/
#define  ADC_ADSTA_EXT_EOCIF                      ADC_ADSTA_EXT_EOCIF_Msk

/**
  * @brief ADC_CHANY0 Register Bit Definition
  */
#define  ADC_CHANY0_CHANY_SEL0_Pos                (0)
#define  ADC_CHANY0_CHANY_SEL0_Msk                (0xFU << ADC_CHANY0_CHANY_SEL0_Pos)               /*!<0th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL0                    ADC_CHANY0_CHANY_SEL0_Msk
#define  ADC_CHANY0_CHANY_SEL0_0                  (0x1U << ADC_CHANY0_CHANY_SEL0_Pos) 
#define  ADC_CHANY0_CHANY_SEL0_1                  (0x2U << ADC_CHANY0_CHANY_SEL0_Pos) 
#define  ADC_CHANY0_CHANY_SEL0_2                  (0x4U << ADC_CHANY0_CHANY_SEL0_Pos) 
#define  ADC_CHANY0_CHANY_SEL0_3                  (0x8U << ADC_CHANY0_CHANY_SEL0_Pos) 
#define  ADC_CHANY0_CHANY_SEL1_Pos                (4)
#define  ADC_CHANY0_CHANY_SEL1_Msk                (0xFU << ADC_CHANY0_CHANY_SEL1_Pos)               /*!<1th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL1                    ADC_CHANY0_CHANY_SEL1_Msk
#define  ADC_CHANY0_CHANY_SEL1_0                  (0x1U << ADC_CHANY0_CHANY_SEL1_Pos) 
#define  ADC_CHANY0_CHANY_SEL1_1                  (0x2U << ADC_CHANY0_CHANY_SEL1_Pos) 
#define  ADC_CHANY0_CHANY_SEL1_2                  (0x4U << ADC_CHANY0_CHANY_SEL1_Pos) 
#define  ADC_CHANY0_CHANY_SEL1_3                  (0x8U << ADC_CHANY0_CHANY_SEL1_Pos) 
#define  ADC_CHANY0_CHANY_SEL2_Pos                (8)
#define  ADC_CHANY0_CHANY_SEL2_Msk                (0xFU << ADC_CHANY0_CHANY_SEL2_Pos)               /*!<2th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL2                    ADC_CHANY0_CHANY_SEL2_Msk
#define  ADC_CHANY0_CHANY_SEL2_0                  (0x1U << ADC_CHANY0_CHANY_SEL2_Pos) 
#define  ADC_CHANY0_CHANY_SEL2_1                  (0x2U << ADC_CHANY0_CHANY_SEL2_Pos) 
#define  ADC_CHANY0_CHANY_SEL2_2                  (0x4U << ADC_CHANY0_CHANY_SEL2_Pos) 
#define  ADC_CHANY0_CHANY_SEL2_3                  (0x8U << ADC_CHANY0_CHANY_SEL2_Pos) 
#define  ADC_CHANY0_CHANY_SEL3_Pos                (12)
#define  ADC_CHANY0_CHANY_SEL3_Msk                (0xFU << ADC_CHANY0_CHANY_SEL3_Pos)               /*!<3th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL3                    ADC_CHANY0_CHANY_SEL3_Msk
#define  ADC_CHANY0_CHANY_SEL3_0                  (0x1U << ADC_CHANY0_CHANY_SEL3_Pos) 
#define  ADC_CHANY0_CHANY_SEL3_1                  (0x2U << ADC_CHANY0_CHANY_SEL3_Pos) 
#define  ADC_CHANY0_CHANY_SEL3_2                  (0x4U << ADC_CHANY0_CHANY_SEL3_Pos) 
#define  ADC_CHANY0_CHANY_SEL3_3                  (0x8U << ADC_CHANY0_CHANY_SEL3_Pos) 
#define  ADC_CHANY0_CHANY_SEL4_Pos                (16)
#define  ADC_CHANY0_CHANY_SEL4_Msk                (0xFU << ADC_CHANY0_CHANY_SEL4_Pos)               /*!<4th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL4                    ADC_CHANY0_CHANY_SEL4_Msk
#define  ADC_CHANY0_CHANY_SEL4_0                  (0x1U << ADC_CHANY0_CHANY_SEL4_Pos) 
#define  ADC_CHANY0_CHANY_SEL4_1                  (0x2U << ADC_CHANY0_CHANY_SEL4_Pos) 
#define  ADC_CHANY0_CHANY_SEL4_2                  (0x4U << ADC_CHANY0_CHANY_SEL4_Pos) 
#define  ADC_CHANY0_CHANY_SEL4_3                  (0x8U << ADC_CHANY0_CHANY_SEL4_Pos) 
#define  ADC_CHANY0_CHANY_SEL5_Pos                (20)
#define  ADC_CHANY0_CHANY_SEL5_Msk                (0xFU << ADC_CHANY0_CHANY_SEL5_Pos)               /*!<5th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL5                    ADC_CHANY0_CHANY_SEL5_Msk
#define  ADC_CHANY0_CHANY_SEL5_0                  (0x1U << ADC_CHANY0_CHANY_SEL5_Pos) 
#define  ADC_CHANY0_CHANY_SEL5_1                  (0x2U << ADC_CHANY0_CHANY_SEL5_Pos) 
#define  ADC_CHANY0_CHANY_SEL5_2                  (0x4U << ADC_CHANY0_CHANY_SEL5_Pos) 
#define  ADC_CHANY0_CHANY_SEL5_3                  (0x8U << ADC_CHANY0_CHANY_SEL5_Pos) 
#define  ADC_CHANY0_CHANY_SEL6_Pos                (24)
#define  ADC_CHANY0_CHANY_SEL6_Msk                (0xFU << ADC_CHANY0_CHANY_SEL6_Pos)               /*!<6th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL6                    ADC_CHANY0_CHANY_SEL6_Msk
#define  ADC_CHANY0_CHANY_SEL6_0                  (0x1U << ADC_CHANY0_CHANY_SEL6_Pos) 
#define  ADC_CHANY0_CHANY_SEL6_1                  (0x2U << ADC_CHANY0_CHANY_SEL6_Pos) 
#define  ADC_CHANY0_CHANY_SEL6_2                  (0x4U << ADC_CHANY0_CHANY_SEL6_Pos) 
#define  ADC_CHANY0_CHANY_SEL6_3                  (0x8U << ADC_CHANY0_CHANY_SEL6_Pos) 
#define  ADC_CHANY0_CHANY_SEL7_Pos                (28)
#define  ADC_CHANY0_CHANY_SEL7_Msk                (0xFU << ADC_CHANY0_CHANY_SEL7_Pos)               /*!<7th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY0_CHANY_SEL7                    ADC_CHANY0_CHANY_SEL7_Msk
#define  ADC_CHANY0_CHANY_SEL7_0                  (0x1U << ADC_CHANY0_CHANY_SEL7_Pos) 
#define  ADC_CHANY0_CHANY_SEL7_1                  (0x2U << ADC_CHANY0_CHANY_SEL7_Pos) 
#define  ADC_CHANY0_CHANY_SEL7_2                  (0x4U << ADC_CHANY0_CHANY_SEL7_Pos) 
#define  ADC_CHANY0_CHANY_SEL7_3                  (0x8U << ADC_CHANY0_CHANY_SEL7_Pos) 

/**
  * @brief ADC_CHANY1 Register Bit Definition
  */
#define  ADC_CHANY1_CHANY_SEL8_Pos                (0)
#define  ADC_CHANY1_CHANY_SEL8_Msk                (0xFU << ADC_CHANY1_CHANY_SEL8_Pos)               /*!<8th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL8                    ADC_CHANY1_CHANY_SEL8_Msk
#define  ADC_CHANY1_CHANY_SEL8_0                  (0x1U << ADC_CHANY1_CHANY_SEL8_Pos) 
#define  ADC_CHANY1_CHANY_SEL8_1                  (0x2U << ADC_CHANY1_CHANY_SEL8_Pos) 
#define  ADC_CHANY1_CHANY_SEL8_2                  (0x4U << ADC_CHANY1_CHANY_SEL8_Pos) 
#define  ADC_CHANY1_CHANY_SEL8_3                  (0x8U << ADC_CHANY1_CHANY_SEL8_Pos) 
#define  ADC_CHANY1_CHANY_SEL9_Pos                (4)
#define  ADC_CHANY1_CHANY_SEL9_Msk                (0xFU << ADC_CHANY1_CHANY_SEL9_Pos)               /*!<9th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL9                    ADC_CHANY1_CHANY_SEL9_Msk
#define  ADC_CHANY1_CHANY_SEL9_0                  (0x1U << ADC_CHANY1_CHANY_SEL9_Pos) 
#define  ADC_CHANY1_CHANY_SEL9_1                  (0x2U << ADC_CHANY1_CHANY_SEL9_Pos) 
#define  ADC_CHANY1_CHANY_SEL9_2                  (0x4U << ADC_CHANY1_CHANY_SEL9_Pos) 
#define  ADC_CHANY1_CHANY_SEL9_3                  (0x8U << ADC_CHANY1_CHANY_SEL9_Pos) 
#define  ADC_CHANY1_CHANY_SEL10_Pos               (8)
#define  ADC_CHANY1_CHANY_SEL10_Msk               (0xFU << ADC_CHANY1_CHANY_SEL10_Pos)              /*!<10th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL10                   ADC_CHANY1_CHANY_SEL10_Msk
#define  ADC_CHANY1_CHANY_SEL10_0                 (0x1U << ADC_CHANY1_CHANY_SEL10_Pos) 
#define  ADC_CHANY1_CHANY_SEL10_1                 (0x2U << ADC_CHANY1_CHANY_SEL10_Pos) 
#define  ADC_CHANY1_CHANY_SEL10_2                 (0x4U << ADC_CHANY1_CHANY_SEL10_Pos) 
#define  ADC_CHANY1_CHANY_SEL10_3                 (0x8U << ADC_CHANY1_CHANY_SEL10_Pos) 
#define  ADC_CHANY1_CHANY_SEL11_Pos               (12)
#define  ADC_CHANY1_CHANY_SEL11_Msk               (0xFU << ADC_CHANY1_CHANY_SEL11_Pos)              /*!<11th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL11                   ADC_CHANY1_CHANY_SEL11_Msk
#define  ADC_CHANY1_CHANY_SEL11_0                 (0x1U << ADC_CHANY1_CHANY_SEL11_Pos) 
#define  ADC_CHANY1_CHANY_SEL11_1                 (0x2U << ADC_CHANY1_CHANY_SEL11_Pos) 
#define  ADC_CHANY1_CHANY_SEL11_2                 (0x4U << ADC_CHANY1_CHANY_SEL11_Pos) 
#define  ADC_CHANY1_CHANY_SEL11_3                 (0x8U << ADC_CHANY1_CHANY_SEL11_Pos) 
#define  ADC_CHANY1_CHANY_SEL12_Pos               (16)
#define  ADC_CHANY1_CHANY_SEL12_Msk               (0xFU << ADC_CHANY1_CHANY_SEL12_Pos)              /*!<12th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL12                   ADC_CHANY1_CHANY_SEL12_Msk
#define  ADC_CHANY1_CHANY_SEL12_0                 (0x1U << ADC_CHANY1_CHANY_SEL12_Pos) 
#define  ADC_CHANY1_CHANY_SEL12_1                 (0x2U << ADC_CHANY1_CHANY_SEL12_Pos) 
#define  ADC_CHANY1_CHANY_SEL12_2                 (0x4U << ADC_CHANY1_CHANY_SEL12_Pos) 
#define  ADC_CHANY1_CHANY_SEL12_3                 (0x8U << ADC_CHANY1_CHANY_SEL12_Pos) 
#define  ADC_CHANY1_CHANY_SEL13_Pos               (20)
#define  ADC_CHANY1_CHANY_SEL13_Msk               (0xFU << ADC_CHANY1_CHANY_SEL13_Pos)              /*!<13th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL13                   ADC_CHANY1_CHANY_SEL13_Msk
#define  ADC_CHANY1_CHANY_SEL13_0                 (0x1U << ADC_CHANY1_CHANY_SEL13_Pos) 
#define  ADC_CHANY1_CHANY_SEL13_1                 (0x2U << ADC_CHANY1_CHANY_SEL13_Pos) 
#define  ADC_CHANY1_CHANY_SEL13_2                 (0x4U << ADC_CHANY1_CHANY_SEL13_Pos) 
#define  ADC_CHANY1_CHANY_SEL13_3                 (0x8U << ADC_CHANY1_CHANY_SEL13_Pos) 
#define  ADC_CHANY1_CHANY_SEL14_Pos               (24)
#define  ADC_CHANY1_CHANY_SEL14_Msk               (0xFU << ADC_CHANY1_CHANY_SEL14_Pos)              /*!<14th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL14                   ADC_CHANY1_CHANY_SEL14_Msk
#define  ADC_CHANY1_CHANY_SEL14_0                 (0x1U << ADC_CHANY1_CHANY_SEL14_Pos) 
#define  ADC_CHANY1_CHANY_SEL14_1                 (0x2U << ADC_CHANY1_CHANY_SEL14_Pos) 
#define  ADC_CHANY1_CHANY_SEL14_2                 (0x4U << ADC_CHANY1_CHANY_SEL14_Pos) 
#define  ADC_CHANY1_CHANY_SEL14_3                 (0x8U << ADC_CHANY1_CHANY_SEL14_Pos) 
#define  ADC_CHANY1_CHANY_SEL15_Pos               (28)
#define  ADC_CHANY1_CHANY_SEL15_Msk               (0xFU << ADC_CHANY1_CHANY_SEL15_Pos)              /*!<15th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SEL15                   ADC_CHANY1_CHANY_SEL15_Msk
#define  ADC_CHANY1_CHANY_SEL15_0                 (0x1U << ADC_CHANY1_CHANY_SEL15_Pos) 
#define  ADC_CHANY1_CHANY_SEL15_1                 (0x2U << ADC_CHANY1_CHANY_SEL15_Pos) 
#define  ADC_CHANY1_CHANY_SEL15_2                 (0x4U << ADC_CHANY1_CHANY_SEL15_Pos) 
#define  ADC_CHANY1_CHANY_SEL15_3                 (0x8U << ADC_CHANY1_CHANY_SEL15_Pos) 

/**
  * @brief ADC_ANY_CFG Register Bit Definition
  */
#define  ADC_ANY_CFG_CHANY_NUM_Pos                (0)
#define  ADC_ANY_CFG_CHANY_NUM_Msk                (0xFU << ADC_ANY_CFG_CHANY_NUM_Pos)               /*!<Number of Any Channel Mode*/
#define  ADC_ANY_CFG_CHANY_NUM                    ADC_ANY_CFG_CHANY_NUM_Msk
#define  ADC_ANY_CFG_CHANY_NUM_0                  (0x1U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_NUM_1                  (0x2U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_NUM_2                  (0x4U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_NUM_3                  (0x8U << ADC_ANY_CFG_CHANY_NUM_Pos) 

/**
  * @brief ADC_ANY_CR Register Bit Definition
  */
#define  ADC_ANY_CR_CHANY_MDEN_Pos                (0)
#define  ADC_ANY_CR_CHANY_MDEN_Msk                (0x1U << ADC_ANY_CR_CHANY_MDEN_Pos)               /*!<Any Channel Mode Enable*/
#define  ADC_ANY_CR_CHANY_MDEN                    ADC_ANY_CR_CHANY_MDEN_Msk

/**
  * @brief ADC_SMPR1 Register Bit Definition
  */
#define  ADC_SMPR1_SAMP0_Pos                      (0)
#define  ADC_SMPR1_SAMP0_Msk                      (0xFU << ADC_SMPR1_SAMP0_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP0                          ADC_SMPR1_SAMP0_Msk
#define  ADC_SMPR1_SAMP0_0                        (0x1U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP0_1                        (0x2U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP0_2                        (0x4U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP0_3                        (0x8U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP1_Pos                      (4)
#define  ADC_SMPR1_SAMP1_Msk                      (0xFU << ADC_SMPR1_SAMP1_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP1                          ADC_SMPR1_SAMP1_Msk
#define  ADC_SMPR1_SAMP1_0                        (0x1U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP1_1                        (0x2U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP1_2                        (0x4U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP1_3                        (0x8U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP2_Pos                      (8)
#define  ADC_SMPR1_SAMP2_Msk                      (0xFU << ADC_SMPR1_SAMP2_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP2                          ADC_SMPR1_SAMP2_Msk
#define  ADC_SMPR1_SAMP2_0                        (0x1U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP2_1                        (0x2U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP2_2                        (0x4U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP2_3                        (0x8U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP3_Pos                      (12)
#define  ADC_SMPR1_SAMP3_Msk                      (0xFU << ADC_SMPR1_SAMP3_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP3                          ADC_SMPR1_SAMP3_Msk
#define  ADC_SMPR1_SAMP3_0                        (0x1U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP3_1                        (0x2U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP3_2                        (0x4U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP3_3                        (0x8U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP4_Pos                      (16)
#define  ADC_SMPR1_SAMP4_Msk                      (0xFU << ADC_SMPR1_SAMP4_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP4                          ADC_SMPR1_SAMP4_Msk
#define  ADC_SMPR1_SAMP4_0                        (0x1U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP4_1                        (0x2U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP4_2                        (0x4U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP4_3                        (0x8U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP5_Pos                      (20)
#define  ADC_SMPR1_SAMP5_Msk                      (0xFU << ADC_SMPR1_SAMP5_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP5                          ADC_SMPR1_SAMP5_Msk
#define  ADC_SMPR1_SAMP5_0                        (0x1U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP5_1                        (0x2U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP5_2                        (0x4U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP5_3                        (0x8U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP6_Pos                      (24)
#define  ADC_SMPR1_SAMP6_Msk                      (0xFU << ADC_SMPR1_SAMP6_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP6                          ADC_SMPR1_SAMP6_Msk
#define  ADC_SMPR1_SAMP6_0                        (0x1U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP6_1                        (0x2U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP6_2                        (0x4U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP6_3                        (0x8U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP7_Pos                      (28)
#define  ADC_SMPR1_SAMP7_Msk                      (0xFU << ADC_SMPR1_SAMP7_Pos)                     /*!<Channel 0~7 Sample Time Selection*/
#define  ADC_SMPR1_SAMP7                          ADC_SMPR1_SAMP7_Msk
#define  ADC_SMPR1_SAMP7_0                        (0x1U << ADC_SMPR1_SAMP7_Pos) 
#define  ADC_SMPR1_SAMP7_1                        (0x2U << ADC_SMPR1_SAMP7_Pos) 
#define  ADC_SMPR1_SAMP7_2                        (0x4U << ADC_SMPR1_SAMP7_Pos) 
#define  ADC_SMPR1_SAMP7_3                        (0x8U << ADC_SMPR1_SAMP7_Pos) 

/**
  * @brief ADC_SMPR2 Register Bit Definition
  */
#define  ADC_SMPR2_SAMP8_Pos                      (0)
#define  ADC_SMPR2_SAMP8_Msk                      (0xFU << ADC_SMPR2_SAMP8_Pos)                     /*!<Channel 8 Sample Time Selection*/
#define  ADC_SMPR2_SAMP8                          ADC_SMPR2_SAMP8_Msk
#define  ADC_SMPR2_SAMP8_0                        (0x1U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP8_1                        (0x2U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP8_2                        (0x4U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP8_3                        (0x8U << ADC_SMPR2_SAMP8_Pos) 

/** ------------------------------------------------------------------------------------------------------------------*/
#endif
/** ------------------------------------------------------------------------------------------------------------------*/
