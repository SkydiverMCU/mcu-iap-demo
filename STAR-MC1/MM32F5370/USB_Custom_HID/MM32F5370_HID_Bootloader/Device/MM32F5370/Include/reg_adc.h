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
#include "core_starmc1.h"



/**
  * @brief ADC Base Address Definition
  */
#define  ADC1_BASE                                 0x40012400                                       /*!<Base Address: 0x40012400*/
#define  ADC2_BASE                                 0x40012800                                       /*!<Base Address: 0x40012800*/
#define  ADC3_BASE                                 0x40014C00                                       /*!<Base Address: 0x40014C00*/

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
    __IO uint32_t ADDR9;                          /*!<ADC Channel Data Register                      offset: 0x3C       */
    __IO uint32_t ADDR10;                         /*!<ADC Channel Data Register                      offset: 0x40       */
    __IO uint32_t ADDR11;                         /*!<ADC Channel Data Register                      offset: 0x44       */
    __IO uint32_t ADDR12;                         /*!<ADC Channel Data Register                      offset: 0x48       */
    __IO uint32_t ADDR13;                         /*!<ADC Channel Data Register                      offset: 0x4C       */
    __IO uint32_t ADDR14;                         /*!<ADC Channel Data Register                      offset: 0x50       */
    __IO uint32_t ADDR15;                         /*!<ADC Channel Data Register                      offset: 0x54       */
    __IO uint32_t ADSTA_EXT;                      /*!<ADC Extended State Register                    offset: 0x58       */
    __IO uint32_t CHANY0;                         /*!<ADC Any Channel Selection Register 0           offset: 0x5C       */
    __IO uint32_t CHANY1;                         /*!<ADC Any Channel Selection Register 1           offset: 0x60       */
    __IO uint32_t ANY_CFG;                        /*!<ADC Any Channel Configuration Register         offset: 0x64       */
    __IO uint32_t ANY_CR;                         /*!<ADC Any Channel Control Register               offset: 0x68       */
    __IO uint32_t ADCFG2;                         /*!<ADC Configuration Register 2                   offset: 0x6C       */
    __IO uint32_t SMPR1;                          /*!<ADC Sample Configuration Register 1            offset: 0x70       */
    __IO uint32_t SMPR2;                          /*!<ADC Sample Configuration Register 2            offset: 0x74       */
    __IO uint32_t SMPR3;                          /*!<ADC Sample Configuration Register 3            offset: 0x78       */
    __IO uint32_t JOFR0;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x7C       */
    __IO uint32_t JOFR1;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x80       */
    __IO uint32_t JOFR2;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x84       */
    __IO uint32_t JOFR3;                          /*!<ADC Injected Channel Data Offset Register      offset: 0x88       */
    __IO uint32_t JSQR;                           /*!<ADC Injected Sequence Register                 offset: 0x8C       */
    __IO uint32_t JADDATA;                        /*!<ADC Injected Data Register                     offset: 0x90       */
    __IO uint32_t CORRS;                          /*!<                                               offset: 0x94       */
    __IO uint32_t CORRD;                          /*!<                                               offset: 0x98       */
    __IO uint32_t CORRP;                          /*!<                                               offset: 0x9C       */
    __IO uint32_t RESERVED0xA0[4];                /*!<                                               offset: 0xA0~0xAC  */
    __IO uint32_t JDR0;                           /*!<                                               offset: 0xB0       */
    __IO uint32_t JDR1;                           /*!<                                               offset: 0xB4       */
    __IO uint32_t JDR2;                           /*!<                                               offset: 0xB8       */
    __IO uint32_t JDR3;                           /*!<                                               offset: 0xBC       */
} ADC_TypeDef;

/**
  * @brief ADC type pointer Definition
  */
#define ADC1                                      ((ADC_TypeDef *)ADC1_BASE)
#define ADC2                                      ((ADC_TypeDef *)ADC2_BASE)
#define ADC3                                      ((ADC_TypeDef *)ADC3_BASE)

/**
  * @brief ADC_ADDATA Register Bit Definition
  */
#define  ADC_ADDATA_DATA_Pos                      (0)
#define  ADC_ADDATA_DATA_Msk                      (0xFFFFU << ADC_ADDATA_DATA_Pos)                  /*!<12-bit A/D conversion result from the current channel (Conversion Data)*/
#define  ADC_ADDATA_DATA                          ADC_ADDATA_DATA_Msk
#define  ADC_ADDATA_DATA_Bit0                     (0x0001U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit1                     (0x0002U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit2                     (0x0004U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit3                     (0x0008U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit4                     (0x0010U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit5                     (0x0020U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit6                     (0x0040U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit7                     (0x0080U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit8                     (0x0100U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit9                     (0x0200U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit10                    (0x0400U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit11                    (0x0800U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit12                    (0x1000U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit13                    (0x2000U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit14                    (0x4000U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_DATA_Bit15                    (0x8000U << ADC_ADDATA_DATA_Pos) 
#define  ADC_ADDATA_CHANNELSEL_Pos                (16)
#define  ADC_ADDATA_CHANNELSEL_Msk                (0xFU << ADC_ADDATA_CHANNELSEL_Pos)               /*!<Channel selection For Low Bits*/
#define  ADC_ADDATA_CHANNELSEL                    ADC_ADDATA_CHANNELSEL_Msk
#define  ADC_ADDATA_CHANNELSEL_Bit0               (0x1U << ADC_ADDATA_CHANNELSEL_Pos) 
#define  ADC_ADDATA_CHANNELSEL_Bit1               (0x2U << ADC_ADDATA_CHANNELSEL_Pos) 
#define  ADC_ADDATA_CHANNELSEL_Bit2               (0x4U << ADC_ADDATA_CHANNELSEL_Pos) 
#define  ADC_ADDATA_CHANNELSEL_Bit3               (0x8U << ADC_ADDATA_CHANNELSEL_Pos) 
#define  ADC_ADDATA_OVERRUN_Pos                   (20)
#define  ADC_ADDATA_OVERRUN_Msk                   (0x1U << ADC_ADDATA_OVERRUN_Pos)                  /*!<Data overrun flag (read-only)*/
#define  ADC_ADDATA_OVERRUN                       ADC_ADDATA_OVERRUN_Msk
#define  ADC_ADDATA_VALID_Pos                     (21)
#define  ADC_ADDATA_VALID_Msk                     (0x1U << ADC_ADDATA_VALID_Pos)                    /*!<Valid flag for data (read-only)*/
#define  ADC_ADDATA_VALID                         ADC_ADDATA_VALID_Msk
#define  ADC_ADDATA_CHANNELSELH_Pos               (22)
#define  ADC_ADDATA_CHANNELSELH_Msk               (0x1U << ADC_ADDATA_CHANNELSELH_Pos)              /*!<*/
#define  ADC_ADDATA_CHANNELSELH                   ADC_ADDATA_CHANNELSELH_Msk

/**
  * @brief ADC_ADCFG Register Bit Definition
  */
#define  ADC_ADCFG_ADEN_Pos                       (0)
#define  ADC_ADCFG_ADEN_Msk                       (0x1U << ADC_ADCFG_ADEN_Pos)                      /*!<A/D conversion enable (ADC enable)*/
#define  ADC_ADCFG_ADEN                           ADC_ADCFG_ADEN_Msk
#define  ADC_ADCFG_AWDEN_Pos                      (1)
#define  ADC_ADCFG_AWDEN_Msk                      (0x1U << ADC_ADCFG_AWDEN_Pos)                     /*!<Analog watchdog enable on non-injected channels*/
#define  ADC_ADCFG_AWDEN                          ADC_ADCFG_AWDEN_Msk
#define  ADC_ADCFG_TSEN_Pos                       (2)
#define  ADC_ADCFG_TSEN_Msk                       (0x1U << ADC_ADCFG_TSEN_Pos)                      /*!<Temperature Sensor Enable*/
#define  ADC_ADCFG_TSEN                           ADC_ADCFG_TSEN_Msk
#define  ADC_ADCFG_VSEN_Pos                       (3)
#define  ADC_ADCFG_VSEN_Msk                       (0x1U << ADC_ADCFG_VSEN_Pos)                      /*!<Internal reference voltage enable (Voltage Sensor enable)*/
#define  ADC_ADCFG_VSEN                           ADC_ADCFG_VSEN_Msk
#define  ADC_ADCFG_RSLTCTL_Pos                    (7)
#define  ADC_ADCFG_RSLTCTL_Msk                    (0x7U << ADC_ADCFG_RSLTCTL_Pos)                   /*!<ADC conversion data resolution selection Single Conversion and Differential Conversion*/
#define  ADC_ADCFG_RSLTCTL                        ADC_ADCFG_RSLTCTL_Msk
#define  ADC_ADCFG_RSLTCTL_Bit0                   (0x1U << ADC_ADCFG_RSLTCTL_Pos) 
#define  ADC_ADCFG_RSLTCTL_Bit1                   (0x2U << ADC_ADCFG_RSLTCTL_Pos) 
#define  ADC_ADCFG_RSLTCTL_Bit2                   (0x4U << ADC_ADCFG_RSLTCTL_Pos) 
#define  ADC_ADCFG_JAWDEN_Pos                     (16)
#define  ADC_ADCFG_JAWDEN_Msk                     (0x1U << ADC_ADCFG_JAWDEN_Pos)                    /*!<A/D Analog Watchdog Enable for Injected Channels*/
#define  ADC_ADCFG_JAWDEN                         ADC_ADCFG_JAWDEN_Msk

/**
  * @brief ADC_ADCR Register Bit Definition
  */
#define  ADC_ADCR_EOSIE_Pos                       (0)
#define  ADC_ADCR_EOSIE_Msk                       (0x1U << ADC_ADCR_EOSIE_Pos)                      /*!<Interrupt Enable for End of Sequence on non-injected channels*/
#define  ADC_ADCR_EOSIE                           ADC_ADCR_EOSIE_Msk
#define  ADC_ADCR_AWDIE_Pos                       (1)
#define  ADC_ADCR_AWDIE_Msk                       (0x1U << ADC_ADCR_AWDIE_Pos)                      /*!<Interrupt Enable of Analog Watchdog*/
#define  ADC_ADCR_AWDIE                           ADC_ADCR_AWDIE_Msk
#define  ADC_ADCR_TRGEN_Pos                       (2)
#define  ADC_ADCR_TRGEN_Msk                       (0x1U << ADC_ADCR_TRGEN_Pos)                      /*!<External Hardware Trigger Sources Enable*/
#define  ADC_ADCR_TRGEN                           ADC_ADCR_TRGEN_Msk
#define  ADC_ADCR_DMAEN_Pos                       (3)
#define  ADC_ADCR_DMAEN_Msk                       (0x1U << ADC_ADCR_DMAEN_Pos)                      /*!<Direct Memory Access Enable*/
#define  ADC_ADCR_DMAEN                           ADC_ADCR_DMAEN_Msk
#define  ADC_ADCR_ADST_Pos                        (8)
#define  ADC_ADCR_ADST_Msk                        (0x1U << ADC_ADCR_ADST_Pos)                       /*!<A/D conversion start*/
#define  ADC_ADCR_ADST                            ADC_ADCR_ADST_Msk
#define  ADC_ADCR_ADMD_Pos                        (9)
#define  ADC_ADCR_ADMD_Msk                        (0x3U << ADC_ADCR_ADMD_Pos)                       /*!<A/D conversion mode (ADC Mode)*/
#define  ADC_ADCR_ADMD                            ADC_ADCR_ADMD_Msk
#define  ADC_ADCR_ADMD_Bit0                       (0x1U << ADC_ADCR_ADMD_Pos) 
#define  ADC_ADCR_ADMD_Bit1                       (0x2U << ADC_ADCR_ADMD_Pos) 
#define  ADC_ADCR_ALIGN_Pos                       (11)
#define  ADC_ADCR_ALIGN_Msk                       (0x1U << ADC_ADCR_ALIGN_Pos)                      /*!<Data Alignment style*/
#define  ADC_ADCR_ALIGN                           ADC_ADCR_ALIGN_Msk
#define  ADC_ADCR_CMPCHL_Pos                      (12)
#define  ADC_ADCR_CMPCHL_Msk                      (0xFU << ADC_ADCR_CMPCHL_Pos)                     /*!<Compare Channel Selection For Analog Watchdog*/
#define  ADC_ADCR_CMPCHL                          ADC_ADCR_CMPCHL_Msk
#define  ADC_ADCR_CMPCHL_Bit0                     (0x1U << ADC_ADCR_CMPCHL_Pos) 
#define  ADC_ADCR_CMPCHL_Bit1                     (0x2U << ADC_ADCR_CMPCHL_Pos) 
#define  ADC_ADCR_CMPCHL_Bit2                     (0x4U << ADC_ADCR_CMPCHL_Pos) 
#define  ADC_ADCR_CMPCHL_Bit3                     (0x8U << ADC_ADCR_CMPCHL_Pos) 
#define  ADC_ADCR_SCANDIR_Pos                     (16)
#define  ADC_ADCR_SCANDIR_Msk                     (0x1U << ADC_ADCR_SCANDIR_Pos)                    /*!<ADC Channel Scan Direction Only valid for normal channel conversion*/
#define  ADC_ADCR_SCANDIR                         ADC_ADCR_SCANDIR_Msk
#define  ADC_ADCR_TRGSHIFT_Pos                    (19)
#define  ADC_ADCR_TRGSHIFT_Msk                    (0x7U << ADC_ADCR_TRGSHIFT_Pos)                   /*!<External Trigger Sources Shift For Sample After a trigger event is generated, the sampling starts after a delay of N PCLK2 clock cycles (N=1, 2, 3...).*/
#define  ADC_ADCR_TRGSHIFT                        ADC_ADCR_TRGSHIFT_Msk
#define  ADC_ADCR_TRGSHIFT_Bit0                   (0x1U << ADC_ADCR_TRGSHIFT_Pos) 
#define  ADC_ADCR_TRGSHIFT_Bit1                   (0x2U << ADC_ADCR_TRGSHIFT_Pos) 
#define  ADC_ADCR_TRGSHIFT_Bit2                   (0x4U << ADC_ADCR_TRGSHIFT_Pos) 
#define  ADC_ADCR_TRG_EDGE_Pos                    (24)
#define  ADC_ADCR_TRG_EDGE_Msk                    (0x3U << ADC_ADCR_TRG_EDGE_Pos)                   /*!<Trigger Sources Edge Selection*/
#define  ADC_ADCR_TRG_EDGE                        ADC_ADCR_TRG_EDGE_Msk
#define  ADC_ADCR_TRG_EDGE_Bit0                   (0x1U << ADC_ADCR_TRG_EDGE_Pos) 
#define  ADC_ADCR_TRG_EDGE_Bit1                   (0x2U << ADC_ADCR_TRG_EDGE_Pos) 
#define  ADC_ADCR_EOSMPIE_Pos                     (26)
#define  ADC_ADCR_EOSMPIE_Msk                     (0x1U << ADC_ADCR_EOSMPIE_Pos)                    /*!<Interrupt Enable for End of Sample*/
#define  ADC_ADCR_EOSMPIE                         ADC_ADCR_EOSMPIE_Msk
#define  ADC_ADCR_EOCIE_Pos                       (27)
#define  ADC_ADCR_EOCIE_Msk                       (0x1U << ADC_ADCR_EOCIE_Pos)                      /*!<Interrupt Enable for End of Conversion*/
#define  ADC_ADCR_EOCIE                           ADC_ADCR_EOCIE_Msk
#define  ADC_ADCR_CMPCHH_Pos                      (28)
#define  ADC_ADCR_CMPCHH_Msk                      (0x1U << ADC_ADCR_CMPCHH_Pos)                     /*!<*/
#define  ADC_ADCR_CMPCHH                          ADC_ADCR_CMPCHH_Msk

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
#define  ADC_ADCHS_CHEN8_Msk                      (0x1U << ADC_ADCHS_CHEN8_Pos)                     /*!<Analog Input Channel 8 Enable*/
#define  ADC_ADCHS_CHEN8                          ADC_ADCHS_CHEN8_Msk
#define  ADC_ADCHS_CHEN9_Pos                      (9)
#define  ADC_ADCHS_CHEN9_Msk                      (0x1U << ADC_ADCHS_CHEN9_Pos)                     /*!<Analog Input Channel 9 Enable*/
#define  ADC_ADCHS_CHEN9                          ADC_ADCHS_CHEN9_Msk
#define  ADC_ADCHS_CHEN10_Pos                     (10)
#define  ADC_ADCHS_CHEN10_Msk                     (0x1U << ADC_ADCHS_CHEN10_Pos)                    /*!<Analog Input Channel 10 Enable*/
#define  ADC_ADCHS_CHEN10                         ADC_ADCHS_CHEN10_Msk
#define  ADC_ADCHS_CHEN11_Pos                     (11)
#define  ADC_ADCHS_CHEN11_Msk                     (0x1U << ADC_ADCHS_CHEN11_Pos)                    /*!<Analog Input Channel 11 Enable*/
#define  ADC_ADCHS_CHEN11                         ADC_ADCHS_CHEN11_Msk
#define  ADC_ADCHS_CHEN12_Pos                     (12)
#define  ADC_ADCHS_CHEN12_Msk                     (0x1U << ADC_ADCHS_CHEN12_Pos)                    /*!<Analog Input Channel 12 Enable*/
#define  ADC_ADCHS_CHEN12                         ADC_ADCHS_CHEN12_Msk
#define  ADC_ADCHS_CHEN13_Pos                     (13)
#define  ADC_ADCHS_CHEN13_Msk                     (0x1U << ADC_ADCHS_CHEN13_Pos)                    /*!<Analog Input Channel 13 Enable*/
#define  ADC_ADCHS_CHEN13                         ADC_ADCHS_CHEN13_Msk
#define  ADC_ADCHS_CHEN14_Pos                     (14)
#define  ADC_ADCHS_CHEN14_Msk                     (0x1U << ADC_ADCHS_CHEN14_Pos)                    /*!<Analog Input Channel 14 Enable*/
#define  ADC_ADCHS_CHEN14                         ADC_ADCHS_CHEN14_Msk
#define  ADC_ADCHS_CHEN15_Pos                     (15)
#define  ADC_ADCHS_CHEN15_Msk                     (0x1U << ADC_ADCHS_CHEN15_Pos)                    /*!<Analog Input Channel 15 Enable*/
#define  ADC_ADCHS_CHEN15                         ADC_ADCHS_CHEN15_Msk

/**
  * @brief ADC_ADCMPR Register Bit Definition
  */
#define  ADC_ADCMPR_CMPLDATA_Pos                  (0)
#define  ADC_ADCMPR_CMPLDATA_Msk                  (0xFFFU << ADC_ADCMPR_CMPLDATA_Pos)               /*!<Compare Low Threshold Data For Analog Watchdog*/
#define  ADC_ADCMPR_CMPLDATA                      ADC_ADCMPR_CMPLDATA_Msk
#define  ADC_ADCMPR_CMPLDATA_Bit0                 (0x001U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit1                 (0x002U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit2                 (0x004U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit3                 (0x008U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit4                 (0x010U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit5                 (0x020U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit6                 (0x040U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit7                 (0x080U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit8                 (0x100U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit9                 (0x200U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit10                (0x400U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPLDATA_Bit11                (0x800U << ADC_ADCMPR_CMPLDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Pos                  (16)
#define  ADC_ADCMPR_CMPHDATA_Msk                  (0xFFFU << ADC_ADCMPR_CMPHDATA_Pos)               /*!<Compare High Threshold Data For Analog Watchdog*/
#define  ADC_ADCMPR_CMPHDATA                      ADC_ADCMPR_CMPHDATA_Msk
#define  ADC_ADCMPR_CMPHDATA_Bit0                 (0x001U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit1                 (0x002U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit2                 (0x004U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit3                 (0x008U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit4                 (0x010U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit5                 (0x020U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit6                 (0x040U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit7                 (0x080U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit8                 (0x100U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit9                 (0x200U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit10                (0x400U << ADC_ADCMPR_CMPHDATA_Pos) 
#define  ADC_ADCMPR_CMPHDATA_Bit11                (0x800U << ADC_ADCMPR_CMPHDATA_Pos) 

/**
  * @brief ADC_ADSTA Register Bit Definition
  */
#define  ADC_ADSTA_EOSIF_Pos                      (0)
#define  ADC_ADSTA_EOSIF_Msk                      (0x1U << ADC_ADSTA_EOSIF_Pos)                     /*!<End of Sequential Conversion*/
#define  ADC_ADSTA_EOSIF                          ADC_ADSTA_EOSIF_Msk
#define  ADC_ADSTA_AWDIF_Pos                      (1)
#define  ADC_ADSTA_AWDIF_Msk                      (0x1U << ADC_ADSTA_AWDIF_Pos)                     /*!<Analog Watchdog Flag*/
#define  ADC_ADSTA_AWDIF                          ADC_ADSTA_AWDIF_Msk
#define  ADC_ADSTA_BUSY_Pos                       (2)
#define  ADC_ADSTA_BUSY_Msk                       (0x1U << ADC_ADSTA_BUSY_Pos)                      /*!<Non-Injected Conversion Busy/Idle*/
#define  ADC_ADSTA_BUSY                           ADC_ADSTA_BUSY_Msk
#define  ADC_ADSTA_CHANNELH_Pos                   (3)
#define  ADC_ADSTA_CHANNELH_Msk                   (0x1U << ADC_ADSTA_CHANNELH_Pos)                  /*!<Current Convert Channel For High Bits*/
#define  ADC_ADSTA_CHANNELH                       ADC_ADSTA_CHANNELH_Msk
#define  ADC_ADSTA_CHANNELL_Pos                   (4)
#define  ADC_ADSTA_CHANNELL_Msk                   (0xFU << ADC_ADSTA_CHANNELL_Pos)                  /*!<Current Convert Channel For Low Bits*/
#define  ADC_ADSTA_CHANNELL                       ADC_ADSTA_CHANNELL_Msk
#define  ADC_ADSTA_CHANNELL_Bit0                  (0x1U << ADC_ADSTA_CHANNELL_Pos) 
#define  ADC_ADSTA_CHANNELL_Bit1                  (0x2U << ADC_ADSTA_CHANNELL_Pos) 
#define  ADC_ADSTA_CHANNELL_Bit2                  (0x4U << ADC_ADSTA_CHANNELL_Pos) 
#define  ADC_ADSTA_CHANNELL_Bit3                  (0x8U << ADC_ADSTA_CHANNELL_Pos) 
#define  ADC_ADSTA_VALID_Pos                      (8)
#define  ADC_ADSTA_VALID_Msk                      (0xFFFU << ADC_ADSTA_VALID_Pos)                   /*!<Valid flag for channel 0 to channel 11 (Valid Flag)*/
#define  ADC_ADSTA_VALID                          ADC_ADSTA_VALID_Msk
#define  ADC_ADSTA_VALID_Bit0                     (0x001U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit1                     (0x002U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit2                     (0x004U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit3                     (0x008U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit4                     (0x010U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit5                     (0x020U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit6                     (0x040U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit7                     (0x080U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit8                     (0x100U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit9                     (0x200U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit10                    (0x400U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_VALID_Bit11                    (0x800U << ADC_ADSTA_VALID_Pos) 
#define  ADC_ADSTA_OVERRUN_Pos                    (20)
#define  ADC_ADSTA_OVERRUN_Msk                    (0xFFFU << ADC_ADSTA_OVERRUN_Pos)                 /*!<Data overrun flag for channel 0 to channel 11 (Overrun Flag)*/
#define  ADC_ADSTA_OVERRUN                        ADC_ADSTA_OVERRUN_Msk
#define  ADC_ADSTA_OVERRUN_Bit0                   (0x001U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit1                   (0x002U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit2                   (0x004U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit3                   (0x008U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit4                   (0x010U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit5                   (0x020U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit6                   (0x040U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit7                   (0x080U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit8                   (0x100U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit9                   (0x200U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit10                  (0x400U << ADC_ADSTA_OVERRUN_Pos) 
#define  ADC_ADSTA_OVERRUN_Bit11                  (0x800U << ADC_ADSTA_OVERRUN_Pos) 

/**
  * @brief ADC_ADDR Register Bit Definition
  */
#define  ADC_ADDR_DATA_Pos                        (0)
#define  ADC_ADDR_DATA_Msk                        (0xFFFFU << ADC_ADDR_DATA_Pos)                    /*!<12-bit A/D conversion result from the channel n (Conversion Data) The alignment style is selected via software.*/
#define  ADC_ADDR_DATA                            ADC_ADDR_DATA_Msk
#define  ADC_ADDR_DATA_Bit0                       (0x0001U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit1                       (0x0002U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit2                       (0x0004U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit3                       (0x0008U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit4                       (0x0010U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit5                       (0x0020U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit6                       (0x0040U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit7                       (0x0080U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit8                       (0x0100U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit9                       (0x0200U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit10                      (0x0400U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit11                      (0x0800U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit12                      (0x1000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit13                      (0x2000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit14                      (0x4000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_DATA_Bit15                      (0x8000U << ADC_ADDR_DATA_Pos) 
#define  ADC_ADDR_OVERRUN_Pos                     (20)
#define  ADC_ADDR_OVERRUN_Msk                     (0x1U << ADC_ADDR_OVERRUN_Pos)                    /*!<Data overrun flag (read-only)*/
#define  ADC_ADDR_OVERRUN                         ADC_ADDR_OVERRUN_Msk
#define  ADC_ADDR_VALID_Pos                       (21)
#define  ADC_ADDR_VALID_Msk                       (0x1U << ADC_ADDR_VALID_Pos)                      /*!<Valid flag (read-only)*/
#define  ADC_ADDR_VALID                           ADC_ADDR_VALID_Msk

/**
  * @brief ADC_ADSTA_EXT Register Bit Definition
  */
#define  ADC_ADSTA_EXT_VALID_Pos                  (0)
#define  ADC_ADSTA_EXT_VALID_Msk                  (0xFU << ADC_ADSTA_EXT_VALID_Pos)                 /*!<Valid flag for channel (Valid Flag)*/
#define  ADC_ADSTA_EXT_VALID                      ADC_ADSTA_EXT_VALID_Msk
#define  ADC_ADSTA_EXT_VALID_Bit0                 (0x1U << ADC_ADSTA_EXT_VALID_Pos) 
#define  ADC_ADSTA_EXT_VALID_Bit1                 (0x2U << ADC_ADSTA_EXT_VALID_Pos) 
#define  ADC_ADSTA_EXT_VALID_Bit2                 (0x4U << ADC_ADSTA_EXT_VALID_Pos) 
#define  ADC_ADSTA_EXT_VALID_Bit3                 (0x8U << ADC_ADSTA_EXT_VALID_Pos) 
#define  ADC_ADSTA_EXT_OVERRUN_Pos                (4)
#define  ADC_ADSTA_EXT_OVERRUN_Msk                (0xFU << ADC_ADSTA_EXT_OVERRUN_Pos)               /*!<Data overrun flag for channel (Overrun Flag)*/
#define  ADC_ADSTA_EXT_OVERRUN                    ADC_ADSTA_EXT_OVERRUN_Msk
#define  ADC_ADSTA_EXT_OVERRUN_Bit0               (0x1U << ADC_ADSTA_EXT_OVERRUN_Pos) 
#define  ADC_ADSTA_EXT_OVERRUN_Bit1               (0x2U << ADC_ADSTA_EXT_OVERRUN_Pos) 
#define  ADC_ADSTA_EXT_OVERRUN_Bit2               (0x4U << ADC_ADSTA_EXT_OVERRUN_Pos) 
#define  ADC_ADSTA_EXT_OVERRUN_Bit3               (0x8U << ADC_ADSTA_EXT_OVERRUN_Pos) 
#define  ADC_ADSTA_EXT_EOSMPIF_Pos                (16)
#define  ADC_ADSTA_EXT_EOSMPIF_Msk                (0x1U << ADC_ADSTA_EXT_EOSMPIF_Pos)               /*!<End of Sample Flag This bit is set by hardware at the end of sampling, and cleared by software.*/
#define  ADC_ADSTA_EXT_EOSMPIF                    ADC_ADSTA_EXT_EOSMPIF_Msk
#define  ADC_ADSTA_EXT_EOCIF_Pos                  (17)
#define  ADC_ADSTA_EXT_EOCIF_Msk                  (0x1U << ADC_ADSTA_EXT_EOCIF_Pos)                 /*!<End of Conversion Flag This bit is set by hardware at the end of conversion, and cleared by software.*/
#define  ADC_ADSTA_EXT_EOCIF                      ADC_ADSTA_EXT_EOCIF_Msk
#define  ADC_ADSTA_EXT_JEOSMPIF_Pos               (18)
#define  ADC_ADSTA_EXT_JEOSMPIF_Msk               (0x1U << ADC_ADSTA_EXT_JEOSMPIF_Pos)              /*!<End of Injected Sample Flag This bit is set by hardware at the end of sampling, and cleared by software.*/
#define  ADC_ADSTA_EXT_JEOSMPIF                   ADC_ADSTA_EXT_JEOSMPIF_Msk
#define  ADC_ADSTA_EXT_JEOCIF_Pos                 (19)
#define  ADC_ADSTA_EXT_JEOCIF_Msk                 (0x1U << ADC_ADSTA_EXT_JEOCIF_Pos)                /*!<End of Injected Conversion Flag This bit is set by hardware at the end of conversion, and cleared by software.*/
#define  ADC_ADSTA_EXT_JEOCIF                     ADC_ADSTA_EXT_JEOCIF_Msk
#define  ADC_ADSTA_EXT_JEOSIF_Pos                 (20)
#define  ADC_ADSTA_EXT_JEOSIF_Msk                 (0x1U << ADC_ADSTA_EXT_JEOSIF_Pos)                /*!<End of Injected Sequence Flag This bit is set by hardware at the end of sequential conversion, and cleared by software.*/
#define  ADC_ADSTA_EXT_JEOSIF                     ADC_ADSTA_EXT_JEOSIF_Msk
#define  ADC_ADSTA_EXT_JBUSY_Pos                  (21)
#define  ADC_ADSTA_EXT_JBUSY_Msk                  (0x1U << ADC_ADSTA_EXT_JBUSY_Pos)                 /*!<Injected Conversion Busy/Idle Flag*/
#define  ADC_ADSTA_EXT_JBUSY                      ADC_ADSTA_EXT_JBUSY_Msk
#define  ADC_ADSTA_EXT_EOCALIF_Pos                (24)
#define  ADC_ADSTA_EXT_EOCALIF_Msk                (0x1U << ADC_ADSTA_EXT_EOCALIF_Pos)               /*!<End of calibration interrupt flag*/
#define  ADC_ADSTA_EXT_EOCALIF                    ADC_ADSTA_EXT_EOCALIF_Msk
#define  ADC_ADSTA_EXT_CALBUSY_Pos                (25)
#define  ADC_ADSTA_EXT_CALBUSY_Msk                (0x1U << ADC_ADSTA_EXT_CALBUSY_Pos)               /*!<CALBUSY: Calibration mode busy/idle (Busy)*/
#define  ADC_ADSTA_EXT_CALBUSY                    ADC_ADSTA_EXT_CALBUSY_Msk
#define  ADC_ADSTA_EXT_FREOCIF_Pos                (26)
#define  ADC_ADSTA_EXT_FREOCIF_Msk                (0x1U << ADC_ADSTA_EXT_FREOCIF_Pos)               /*!<Calibration factor read/write data register end flag*/
#define  ADC_ADSTA_EXT_FREOCIF                    ADC_ADSTA_EXT_FREOCIF_Msk

/**
  * @brief ADC_CHANY0 Register Bit Definition
  */
#define  ADC_CHANY0_CHANY_SELL0_Pos               (0)
#define  ADC_CHANY0_CHANY_SELL0_Msk               (0xFU << ADC_CHANY0_CHANY_SELL0_Pos)              /*!<0th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL0                   ADC_CHANY0_CHANY_SELL0_Msk
#define  ADC_CHANY0_CHANY_SELL0_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL0_Pos) 
#define  ADC_CHANY0_CHANY_SELL0_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL0_Pos) 
#define  ADC_CHANY0_CHANY_SELL0_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL0_Pos) 
#define  ADC_CHANY0_CHANY_SELL0_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL0_Pos) 
#define  ADC_CHANY0_CHANY_SELL1_Pos               (4)
#define  ADC_CHANY0_CHANY_SELL1_Msk               (0xFU << ADC_CHANY0_CHANY_SELL1_Pos)              /*!<1th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL1                   ADC_CHANY0_CHANY_SELL1_Msk
#define  ADC_CHANY0_CHANY_SELL1_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL1_Pos) 
#define  ADC_CHANY0_CHANY_SELL1_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL1_Pos) 
#define  ADC_CHANY0_CHANY_SELL1_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL1_Pos) 
#define  ADC_CHANY0_CHANY_SELL1_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL1_Pos) 
#define  ADC_CHANY0_CHANY_SELL2_Pos               (8)
#define  ADC_CHANY0_CHANY_SELL2_Msk               (0xFU << ADC_CHANY0_CHANY_SELL2_Pos)              /*!<2th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL2                   ADC_CHANY0_CHANY_SELL2_Msk
#define  ADC_CHANY0_CHANY_SELL2_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL2_Pos) 
#define  ADC_CHANY0_CHANY_SELL2_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL2_Pos) 
#define  ADC_CHANY0_CHANY_SELL2_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL2_Pos) 
#define  ADC_CHANY0_CHANY_SELL2_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL2_Pos) 
#define  ADC_CHANY0_CHANY_SELL3_Pos               (12)
#define  ADC_CHANY0_CHANY_SELL3_Msk               (0xFU << ADC_CHANY0_CHANY_SELL3_Pos)              /*!<3th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL3                   ADC_CHANY0_CHANY_SELL3_Msk
#define  ADC_CHANY0_CHANY_SELL3_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL3_Pos) 
#define  ADC_CHANY0_CHANY_SELL3_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL3_Pos) 
#define  ADC_CHANY0_CHANY_SELL3_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL3_Pos) 
#define  ADC_CHANY0_CHANY_SELL3_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL3_Pos) 
#define  ADC_CHANY0_CHANY_SELL4_Pos               (16)
#define  ADC_CHANY0_CHANY_SELL4_Msk               (0xFU << ADC_CHANY0_CHANY_SELL4_Pos)              /*!<4th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL4                   ADC_CHANY0_CHANY_SELL4_Msk
#define  ADC_CHANY0_CHANY_SELL4_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL4_Pos) 
#define  ADC_CHANY0_CHANY_SELL4_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL4_Pos) 
#define  ADC_CHANY0_CHANY_SELL4_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL4_Pos) 
#define  ADC_CHANY0_CHANY_SELL4_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL4_Pos) 
#define  ADC_CHANY0_CHANY_SELL5_Pos               (20)
#define  ADC_CHANY0_CHANY_SELL5_Msk               (0xFU << ADC_CHANY0_CHANY_SELL5_Pos)              /*!<5th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL5                   ADC_CHANY0_CHANY_SELL5_Msk
#define  ADC_CHANY0_CHANY_SELL5_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL5_Pos) 
#define  ADC_CHANY0_CHANY_SELL5_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL5_Pos) 
#define  ADC_CHANY0_CHANY_SELL5_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL5_Pos) 
#define  ADC_CHANY0_CHANY_SELL5_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL5_Pos) 
#define  ADC_CHANY0_CHANY_SELL6_Pos               (24)
#define  ADC_CHANY0_CHANY_SELL6_Msk               (0xFU << ADC_CHANY0_CHANY_SELL6_Pos)              /*!<6th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL6                   ADC_CHANY0_CHANY_SELL6_Msk
#define  ADC_CHANY0_CHANY_SELL6_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL6_Pos) 
#define  ADC_CHANY0_CHANY_SELL6_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL6_Pos) 
#define  ADC_CHANY0_CHANY_SELL6_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL6_Pos) 
#define  ADC_CHANY0_CHANY_SELL6_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL6_Pos) 
#define  ADC_CHANY0_CHANY_SELL7_Pos               (28)
#define  ADC_CHANY0_CHANY_SELL7_Msk               (0xFU << ADC_CHANY0_CHANY_SELL7_Pos)              /*!<7th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY0_CHANY_SELL7                   ADC_CHANY0_CHANY_SELL7_Msk
#define  ADC_CHANY0_CHANY_SELL7_Bit0              (0x1U << ADC_CHANY0_CHANY_SELL7_Pos) 
#define  ADC_CHANY0_CHANY_SELL7_Bit1              (0x2U << ADC_CHANY0_CHANY_SELL7_Pos) 
#define  ADC_CHANY0_CHANY_SELL7_Bit2              (0x4U << ADC_CHANY0_CHANY_SELL7_Pos) 
#define  ADC_CHANY0_CHANY_SELL7_Bit3              (0x8U << ADC_CHANY0_CHANY_SELL7_Pos) 

/**
  * @brief ADC_CHANY1 Register Bit Definition
  */
#define  ADC_CHANY1_CHANY_SELL8_Pos               (0)
#define  ADC_CHANY1_CHANY_SELL8_Msk               (0xFU << ADC_CHANY1_CHANY_SELL8_Pos)              /*!<8th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SELL8                   ADC_CHANY1_CHANY_SELL8_Msk
#define  ADC_CHANY1_CHANY_SELL8_Bit0              (0x1U << ADC_CHANY1_CHANY_SELL8_Pos) 
#define  ADC_CHANY1_CHANY_SELL8_Bit1              (0x2U << ADC_CHANY1_CHANY_SELL8_Pos) 
#define  ADC_CHANY1_CHANY_SELL8_Bit2              (0x4U << ADC_CHANY1_CHANY_SELL8_Pos) 
#define  ADC_CHANY1_CHANY_SELL8_Bit3              (0x8U << ADC_CHANY1_CHANY_SELL8_Pos) 
#define  ADC_CHANY1_CHANY_SELL9_Pos               (4)
#define  ADC_CHANY1_CHANY_SELL9_Msk               (0xFU << ADC_CHANY1_CHANY_SELL9_Pos)              /*!<9th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SELL9                   ADC_CHANY1_CHANY_SELL9_Msk
#define  ADC_CHANY1_CHANY_SELL9_Bit0              (0x1U << ADC_CHANY1_CHANY_SELL9_Pos) 
#define  ADC_CHANY1_CHANY_SELL9_Bit1              (0x2U << ADC_CHANY1_CHANY_SELL9_Pos) 
#define  ADC_CHANY1_CHANY_SELL9_Bit2              (0x4U << ADC_CHANY1_CHANY_SELL9_Pos) 
#define  ADC_CHANY1_CHANY_SELL9_Bit3              (0x8U << ADC_CHANY1_CHANY_SELL9_Pos) 
#define  ADC_CHANY1_CHANY_SELL10_Pos              (8)
#define  ADC_CHANY1_CHANY_SELL10_Msk              (0xFU << ADC_CHANY1_CHANY_SELL10_Pos)             /*!<10th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SELL10                  ADC_CHANY1_CHANY_SELL10_Msk
#define  ADC_CHANY1_CHANY_SELL10_Bit0             (0x1U << ADC_CHANY1_CHANY_SELL10_Pos) 
#define  ADC_CHANY1_CHANY_SELL10_Bit1             (0x2U << ADC_CHANY1_CHANY_SELL10_Pos) 
#define  ADC_CHANY1_CHANY_SELL10_Bit2             (0x4U << ADC_CHANY1_CHANY_SELL10_Pos) 
#define  ADC_CHANY1_CHANY_SELL10_Bit3             (0x8U << ADC_CHANY1_CHANY_SELL10_Pos) 
#define  ADC_CHANY1_CHANY_SELL11_Pos              (12)
#define  ADC_CHANY1_CHANY_SELL11_Msk              (0xFU << ADC_CHANY1_CHANY_SELL11_Pos)             /*!<11th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SELL11                  ADC_CHANY1_CHANY_SELL11_Msk
#define  ADC_CHANY1_CHANY_SELL11_Bit0             (0x1U << ADC_CHANY1_CHANY_SELL11_Pos) 
#define  ADC_CHANY1_CHANY_SELL11_Bit1             (0x2U << ADC_CHANY1_CHANY_SELL11_Pos) 
#define  ADC_CHANY1_CHANY_SELL11_Bit2             (0x4U << ADC_CHANY1_CHANY_SELL11_Pos) 
#define  ADC_CHANY1_CHANY_SELL11_Bit3             (0x8U << ADC_CHANY1_CHANY_SELL11_Pos) 
#define  ADC_CHANY1_CHANY_SELL12_Pos              (16)
#define  ADC_CHANY1_CHANY_SELL12_Msk              (0xFU << ADC_CHANY1_CHANY_SELL12_Pos)             /*!<12th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SELL12                  ADC_CHANY1_CHANY_SELL12_Msk
#define  ADC_CHANY1_CHANY_SELL12_Bit0             (0x1U << ADC_CHANY1_CHANY_SELL12_Pos) 
#define  ADC_CHANY1_CHANY_SELL12_Bit1             (0x2U << ADC_CHANY1_CHANY_SELL12_Pos) 
#define  ADC_CHANY1_CHANY_SELL12_Bit2             (0x4U << ADC_CHANY1_CHANY_SELL12_Pos) 
#define  ADC_CHANY1_CHANY_SELL12_Bit3             (0x8U << ADC_CHANY1_CHANY_SELL12_Pos) 
#define  ADC_CHANY1_CHANY_SELL13_Pos              (20)
#define  ADC_CHANY1_CHANY_SELL13_Msk              (0xFU << ADC_CHANY1_CHANY_SELL13_Pos)             /*!<13th Conversion Select for Any Channel sequence*/
#define  ADC_CHANY1_CHANY_SELL13                  ADC_CHANY1_CHANY_SELL13_Msk
#define  ADC_CHANY1_CHANY_SELL13_Bit0             (0x1U << ADC_CHANY1_CHANY_SELL13_Pos) 
#define  ADC_CHANY1_CHANY_SELL13_Bit1             (0x2U << ADC_CHANY1_CHANY_SELL13_Pos) 
#define  ADC_CHANY1_CHANY_SELL13_Bit2             (0x4U << ADC_CHANY1_CHANY_SELL13_Pos) 
#define  ADC_CHANY1_CHANY_SELL13_Bit3             (0x8U << ADC_CHANY1_CHANY_SELL13_Pos) 
#define  ADC_CHANY1_CHANY_SELL14_Pos              (24)
#define  ADC_CHANY1_CHANY_SELL14_Msk              (0xFU << ADC_CHANY1_CHANY_SELL14_Pos)             /*!<14th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY1_CHANY_SELL14                  ADC_CHANY1_CHANY_SELL14_Msk
#define  ADC_CHANY1_CHANY_SELL14_Bit0             (0x1U << ADC_CHANY1_CHANY_SELL14_Pos) 
#define  ADC_CHANY1_CHANY_SELL14_Bit1             (0x2U << ADC_CHANY1_CHANY_SELL14_Pos) 
#define  ADC_CHANY1_CHANY_SELL14_Bit2             (0x4U << ADC_CHANY1_CHANY_SELL14_Pos) 
#define  ADC_CHANY1_CHANY_SELL14_Bit3             (0x8U << ADC_CHANY1_CHANY_SELL14_Pos) 
#define  ADC_CHANY1_CHANY_SELL15_Pos              (28)
#define  ADC_CHANY1_CHANY_SELL15_Msk              (0xFU << ADC_CHANY1_CHANY_SELL15_Pos)             /*!<15th Conversion Select for Any Channel sequence For Low Bits*/
#define  ADC_CHANY1_CHANY_SELL15                  ADC_CHANY1_CHANY_SELL15_Msk
#define  ADC_CHANY1_CHANY_SELL15_Bit0             (0x1U << ADC_CHANY1_CHANY_SELL15_Pos) 
#define  ADC_CHANY1_CHANY_SELL15_Bit1             (0x2U << ADC_CHANY1_CHANY_SELL15_Pos) 
#define  ADC_CHANY1_CHANY_SELL15_Bit2             (0x4U << ADC_CHANY1_CHANY_SELL15_Pos) 
#define  ADC_CHANY1_CHANY_SELL15_Bit3             (0x8U << ADC_CHANY1_CHANY_SELL15_Pos) 

/**
  * @brief ADC_ANY_CFG Register Bit Definition
  */
#define  ADC_ANY_CFG_CHANY_NUM_Pos                (0)
#define  ADC_ANY_CFG_CHANY_NUM_Msk                (0xFU << ADC_ANY_CFG_CHANY_NUM_Pos)               /*!<Number of Any Channel Mode*/
#define  ADC_ANY_CFG_CHANY_NUM                    ADC_ANY_CFG_CHANY_NUM_Msk
#define  ADC_ANY_CFG_CHANY_NUM_Bit0               (0x1U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_NUM_Bit1               (0x2U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_NUM_Bit2               (0x4U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_NUM_Bit3               (0x8U << ADC_ANY_CFG_CHANY_NUM_Pos) 
#define  ADC_ANY_CFG_CHANY_SELH0_Pos              (8)
#define  ADC_ANY_CFG_CHANY_SELH0_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH0_Pos)             /*!<0th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH0                  ADC_ANY_CFG_CHANY_SELH0_Msk
#define  ADC_ANY_CFG_CHANY_SELH1_Pos              (9)
#define  ADC_ANY_CFG_CHANY_SELH1_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH1_Pos)             /*!<1th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH1                  ADC_ANY_CFG_CHANY_SELH1_Msk
#define  ADC_ANY_CFG_CHANY_SELH2_Pos              (10)
#define  ADC_ANY_CFG_CHANY_SELH2_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH2_Pos)             /*!<2th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH2                  ADC_ANY_CFG_CHANY_SELH2_Msk
#define  ADC_ANY_CFG_CHANY_SELH3_Pos              (11)
#define  ADC_ANY_CFG_CHANY_SELH3_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH3_Pos)             /*!<3th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH3                  ADC_ANY_CFG_CHANY_SELH3_Msk
#define  ADC_ANY_CFG_CHANY_SELH4_Pos              (12)
#define  ADC_ANY_CFG_CHANY_SELH4_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH4_Pos)             /*!<4th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH4                  ADC_ANY_CFG_CHANY_SELH4_Msk
#define  ADC_ANY_CFG_CHANY_SELH5_Pos              (13)
#define  ADC_ANY_CFG_CHANY_SELH5_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH5_Pos)             /*!<5th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH5                  ADC_ANY_CFG_CHANY_SELH5_Msk
#define  ADC_ANY_CFG_CHANY_SELH6_Pos              (14)
#define  ADC_ANY_CFG_CHANY_SELH6_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH6_Pos)             /*!<6th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH6                  ADC_ANY_CFG_CHANY_SELH6_Msk
#define  ADC_ANY_CFG_CHANY_SELH7_Pos              (15)
#define  ADC_ANY_CFG_CHANY_SELH7_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH7_Pos)             /*!<7th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH7                  ADC_ANY_CFG_CHANY_SELH7_Msk
#define  ADC_ANY_CFG_CHANY_SELH8_Pos              (16)
#define  ADC_ANY_CFG_CHANY_SELH8_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH8_Pos)             /*!<8th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH8                  ADC_ANY_CFG_CHANY_SELH8_Msk
#define  ADC_ANY_CFG_CHANY_SELH9_Pos              (17)
#define  ADC_ANY_CFG_CHANY_SELH9_Msk              (0x1U << ADC_ANY_CFG_CHANY_SELH9_Pos)             /*!<9th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH9                  ADC_ANY_CFG_CHANY_SELH9_Msk
#define  ADC_ANY_CFG_CHANY_SELH10_Pos             (18)
#define  ADC_ANY_CFG_CHANY_SELH10_Msk             (0x1U << ADC_ANY_CFG_CHANY_SELH10_Pos)            /*!<10th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH10                 ADC_ANY_CFG_CHANY_SELH10_Msk
#define  ADC_ANY_CFG_CHANY_SELH11_Pos             (19)
#define  ADC_ANY_CFG_CHANY_SELH11_Msk             (0x1U << ADC_ANY_CFG_CHANY_SELH11_Pos)            /*!<11th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH11                 ADC_ANY_CFG_CHANY_SELH11_Msk
#define  ADC_ANY_CFG_CHANY_SELH12_Pos             (20)
#define  ADC_ANY_CFG_CHANY_SELH12_Msk             (0x1U << ADC_ANY_CFG_CHANY_SELH12_Pos)            /*!<12th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH12                 ADC_ANY_CFG_CHANY_SELH12_Msk
#define  ADC_ANY_CFG_CHANY_SELH13_Pos             (21)
#define  ADC_ANY_CFG_CHANY_SELH13_Msk             (0x1U << ADC_ANY_CFG_CHANY_SELH13_Pos)            /*!<13th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH13                 ADC_ANY_CFG_CHANY_SELH13_Msk
#define  ADC_ANY_CFG_CHANY_SELH14_Pos             (22)
#define  ADC_ANY_CFG_CHANY_SELH14_Msk             (0x1U << ADC_ANY_CFG_CHANY_SELH14_Pos)            /*!<14th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH14                 ADC_ANY_CFG_CHANY_SELH14_Msk
#define  ADC_ANY_CFG_CHANY_SELH15_Pos             (23)
#define  ADC_ANY_CFG_CHANY_SELH15_Msk             (0x1U << ADC_ANY_CFG_CHANY_SELH15_Pos)            /*!<15th Conversion Select for Any Channel sequence For High Bits*/
#define  ADC_ANY_CFG_CHANY_SELH15                 ADC_ANY_CFG_CHANY_SELH15_Msk

/**
  * @brief ADC_ANY_CR Register Bit Definition
  */
#define  ADC_ANY_CR_CHANY_MDEN_Pos                (0)
#define  ADC_ANY_CR_CHANY_MDEN_Msk                (0x1U << ADC_ANY_CR_CHANY_MDEN_Pos)               /*!<Any Channel Mode Enable*/
#define  ADC_ANY_CR_CHANY_MDEN                    ADC_ANY_CR_CHANY_MDEN_Msk
#define  ADC_ANY_CR_JCEN_Pos                      (1)
#define  ADC_ANY_CR_JCEN_Msk                      (0x1U << ADC_ANY_CR_JCEN_Pos)                     /*!<Conversion Enable for Injected Channels*/
#define  ADC_ANY_CR_JCEN                          ADC_ANY_CR_JCEN_Msk
#define  ADC_ANY_CR_JEOSMPIE_Pos                  (2)
#define  ADC_ANY_CR_JEOSMPIE_Msk                  (0x1U << ADC_ANY_CR_JEOSMPIE_Pos)                 /*!<Interrupt Enable for JEOSAMP*/
#define  ADC_ANY_CR_JEOSMPIE                      ADC_ANY_CR_JEOSMPIE_Msk
#define  ADC_ANY_CR_JEOCIE_Pos                    (3)
#define  ADC_ANY_CR_JEOCIE_Msk                    (0x1U << ADC_ANY_CR_JEOCIE_Pos)                   /*!<Interrupt Enable for JEOC*/
#define  ADC_ANY_CR_JEOCIE                        ADC_ANY_CR_JEOCIE_Msk
#define  ADC_ANY_CR_JEOSIE_Pos                    (4)
#define  ADC_ANY_CR_JEOSIE_Msk                    (0x1U << ADC_ANY_CR_JEOSIE_Pos)                   /*!<Interrupt Enable for JEOS*/
#define  ADC_ANY_CR_JEOSIE                        ADC_ANY_CR_JEOSIE_Msk
#define  ADC_ANY_CR_JAUTO_Pos                     (5)
#define  ADC_ANY_CR_JAUTO_Msk                     (0x1U << ADC_ANY_CR_JAUTO_Pos)                    /*!<Automatic Injected Conversion*/
#define  ADC_ANY_CR_JAUTO                         ADC_ANY_CR_JAUTO_Msk
#define  ADC_ANY_CR_JADST_Pos                     (6)
#define  ADC_ANY_CR_JADST_Msk                     (0x1U << ADC_ANY_CR_JADST_Pos)                    /*!<ADC Start for Injected Channels: enable JCEN first*/
#define  ADC_ANY_CR_JADST                         ADC_ANY_CR_JADST_Msk
#define  ADC_ANY_CR_JTRGEN_Pos                    (7)
#define  ADC_ANY_CR_JTRGEN_Msk                    (0x1U << ADC_ANY_CR_JTRGEN_Pos)                   /*!<External Hardware Trigger Enable For Injected Channels*/
#define  ADC_ANY_CR_JTRGEN                        ADC_ANY_CR_JTRGEN_Msk
#define  ADC_ANY_CR_JTRGSHIFT_Pos                 (13)
#define  ADC_ANY_CR_JTRGSHIFT_Msk                 (0x7U << ADC_ANY_CR_JTRGSHIFT_Pos)                /*!<External Trigger Shift Sample for Injected Channels After a trigger signal is generated, the sampling starts after a delay of N PCLK2 clock cycles. In case of trigger scan, the sampling in the rest channels starts immediately after the last sampling is complete.*/
#define  ADC_ANY_CR_JTRGSHIFT                     ADC_ANY_CR_JTRGSHIFT_Msk
#define  ADC_ANY_CR_JTRGSHIFT_Bit0                (0x1U << ADC_ANY_CR_JTRGSHIFT_Pos) 
#define  ADC_ANY_CR_JTRGSHIFT_Bit1                (0x2U << ADC_ANY_CR_JTRGSHIFT_Pos) 
#define  ADC_ANY_CR_JTRGSHIFT_Bit2                (0x4U << ADC_ANY_CR_JTRGSHIFT_Pos) 
#define  ADC_ANY_CR_JTRG_EDGE_Pos                 (16)
#define  ADC_ANY_CR_JTRG_EDGE_Msk                 (0x3U << ADC_ANY_CR_JTRG_EDGE_Pos)                /*!<External Trigger sources Edge Selection for Injected Channels*/
#define  ADC_ANY_CR_JTRG_EDGE                     ADC_ANY_CR_JTRG_EDGE_Msk
#define  ADC_ANY_CR_JTRG_EDGE_Bit0                (0x1U << ADC_ANY_CR_JTRG_EDGE_Pos) 
#define  ADC_ANY_CR_JTRG_EDGE_Bit1                (0x2U << ADC_ANY_CR_JTRG_EDGE_Pos) 
#define  ADC_ANY_CR_ADCAL_Pos                     (20)
#define  ADC_ANY_CR_ADCAL_Msk                     (0x1U << ADC_ANY_CR_ADCAL_Pos)                    /*!<A/D Calibration Start*/
#define  ADC_ANY_CR_ADCAL                         ADC_ANY_CR_ADCAL_Msk
#define  ADC_ANY_CR_EOCALIE_Pos                   (21)
#define  ADC_ANY_CR_EOCALIE_Msk                   (0x1U << ADC_ANY_CR_EOCALIE_Pos)                  /*!<End of self-calibration interrupt enable*/
#define  ADC_ANY_CR_EOCALIE                       ADC_ANY_CR_EOCALIE_Msk

/**
  * @brief ADC_ADCFG2 Register Bit Definition
  */
#define  ADC_ADCFG2_CORREN_Pos                    (0)
#define  ADC_ADCFG2_CORREN_Msk                    (0x1U << ADC_ADCFG2_CORREN_Pos)                   /*!<Conversion correction enable*/
#define  ADC_ADCFG2_CORREN                        ADC_ADCFG2_CORREN_Msk
#define  ADC_ADCFG2_ADCCR_Pos                     (1)
#define  ADC_ADCFG2_ADCCR_Msk                     (0x1U << ADC_ADCFG2_ADCCR_Pos)                    /*!<ADC low-power control (ADC Control)*/
#define  ADC_ADCFG2_ADCCR                         ADC_ADCFG2_ADCCR_Msk
#define  ADC_ADCFG2_ADCSREF_Pos                   (2)
#define  ADC_ADCFG2_ADCSREF_Msk                   (0x1U << ADC_ADCFG2_ADCSREF_Pos)                  /*!<Reference Voltage Selection (ADC Select Reference Voltage)*/
#define  ADC_ADCFG2_ADCSREF                       ADC_ADCFG2_ADCSREF_Msk
#define  ADC_ADCFG2_CORRVSEL_Pos                  (3)
#define  ADC_ADCFG2_CORRVSEL_Msk                  (0x1U << ADC_ADCFG2_CORRVSEL_Pos)                 /*!<correct vref select*/
#define  ADC_ADCFG2_CORRVSEL                      ADC_ADCFG2_CORRVSEL_Msk
#define  ADC_ADCFG2_DC_Pos                        (4)
#define  ADC_ADCFG2_DC_Msk                        (0x1FU << ADC_ADCFG2_DC_Pos)                      /*!<Differential configuration selection (Differential Conversion)*/
#define  ADC_ADCFG2_DC                            ADC_ADCFG2_DC_Msk
#define  ADC_ADCFG2_DC_Bit0                       (0x01U << ADC_ADCFG2_DC_Pos) 
#define  ADC_ADCFG2_DC_Bit1                       (0x02U << ADC_ADCFG2_DC_Pos) 
#define  ADC_ADCFG2_DC_Bit2                       (0x04U << ADC_ADCFG2_DC_Pos) 
#define  ADC_ADCFG2_DC_Bit3                       (0x08U << ADC_ADCFG2_DC_Pos) 
#define  ADC_ADCFG2_DC_Bit4                       (0x10U << ADC_ADCFG2_DC_Pos) 
#define  ADC_ADCFG2_PSDC_Pos                      (10)
#define  ADC_ADCFG2_PSDC_Msk                      (0x1FU << ADC_ADCFG2_PSDC_Pos)                    /*!<Pseudo Differential Configuration Selection (Pseudo Differential Conversion)*/
#define  ADC_ADCFG2_PSDC                          ADC_ADCFG2_PSDC_Msk
#define  ADC_ADCFG2_PSDC_Bit0                     (0x01U << ADC_ADCFG2_PSDC_Pos) 
#define  ADC_ADCFG2_PSDC_Bit1                     (0x02U << ADC_ADCFG2_PSDC_Pos) 
#define  ADC_ADCFG2_PSDC_Bit2                     (0x04U << ADC_ADCFG2_PSDC_Pos) 
#define  ADC_ADCFG2_PSDC_Bit3                     (0x08U << ADC_ADCFG2_PSDC_Pos) 
#define  ADC_ADCFG2_PSDC_Bit4                     (0x10U << ADC_ADCFG2_PSDC_Pos) 
#define  ADC_ADCFG2_ROVSE_Pos                     (16)
#define  ADC_ADCFG2_ROVSE_Msk                     (0x1U << ADC_ADCFG2_ROVSE_Pos)                    /*!<Regular Oversampler Enable*/
#define  ADC_ADCFG2_ROVSE                         ADC_ADCFG2_ROVSE_Msk
#define  ADC_ADCFG2_JOVSE_Pos                     (17)
#define  ADC_ADCFG2_JOVSE_Msk                     (0x1U << ADC_ADCFG2_JOVSE_Pos)                    /*!<Injected Oversampler Enable*/
#define  ADC_ADCFG2_JOVSE                         ADC_ADCFG2_JOVSE_Msk
#define  ADC_ADCFG2_OVSR_Pos                      (18)
#define  ADC_ADCFG2_OVSR_Msk                      (0x7U << ADC_ADCFG2_OVSR_Pos)                     /*!<Oversampling Ratio*/
#define  ADC_ADCFG2_OVSR                          ADC_ADCFG2_OVSR_Msk
#define  ADC_ADCFG2_OVSR_Bit0                     (0x1U << ADC_ADCFG2_OVSR_Pos) 
#define  ADC_ADCFG2_OVSR_Bit1                     (0x2U << ADC_ADCFG2_OVSR_Pos) 
#define  ADC_ADCFG2_OVSR_Bit2                     (0x4U << ADC_ADCFG2_OVSR_Pos) 
#define  ADC_ADCFG2_OVSS_Pos                      (21)
#define  ADC_ADCFG2_OVSS_Msk                      (0xFU << ADC_ADCFG2_OVSS_Pos)                     /*!<Oversampling Shift Bits*/
#define  ADC_ADCFG2_OVSS                          ADC_ADCFG2_OVSS_Msk
#define  ADC_ADCFG2_OVSS_Bit0                     (0x1U << ADC_ADCFG2_OVSS_Pos) 
#define  ADC_ADCFG2_OVSS_Bit1                     (0x2U << ADC_ADCFG2_OVSS_Pos) 
#define  ADC_ADCFG2_OVSS_Bit2                     (0x4U << ADC_ADCFG2_OVSS_Pos) 
#define  ADC_ADCFG2_OVSS_Bit3                     (0x8U << ADC_ADCFG2_OVSS_Pos) 
#define  ADC_ADCFG2_TROVS_Pos                     (25)
#define  ADC_ADCFG2_TROVS_Msk                     (0x1U << ADC_ADCFG2_TROVS_Pos)                    /*!<Trigger Oversampling Select*/
#define  ADC_ADCFG2_TROVS                         ADC_ADCFG2_TROVS_Msk

/**
  * @brief ADC_SMPR1 Register Bit Definition
  */
#define  ADC_SMPR1_SAMP0_Pos                      (0)
#define  ADC_SMPR1_SAMP0_Msk                      (0xFU << ADC_SMPR1_SAMP0_Pos)                     /*!<Channel 0 Sample Time Selection*/
#define  ADC_SMPR1_SAMP0                          ADC_SMPR1_SAMP0_Msk
#define  ADC_SMPR1_SAMP0_Bit0                     (0x1U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP0_Bit1                     (0x2U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP0_Bit2                     (0x4U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP0_Bit3                     (0x8U << ADC_SMPR1_SAMP0_Pos) 
#define  ADC_SMPR1_SAMP1_Pos                      (4)
#define  ADC_SMPR1_SAMP1_Msk                      (0xFU << ADC_SMPR1_SAMP1_Pos)                     /*!<Channel 1 Sample Time Selection*/
#define  ADC_SMPR1_SAMP1                          ADC_SMPR1_SAMP1_Msk
#define  ADC_SMPR1_SAMP1_Bit0                     (0x1U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP1_Bit1                     (0x2U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP1_Bit2                     (0x4U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP1_Bit3                     (0x8U << ADC_SMPR1_SAMP1_Pos) 
#define  ADC_SMPR1_SAMP2_Pos                      (8)
#define  ADC_SMPR1_SAMP2_Msk                      (0xFU << ADC_SMPR1_SAMP2_Pos)                     /*!<Channel 2 Sample Time Selection*/
#define  ADC_SMPR1_SAMP2                          ADC_SMPR1_SAMP2_Msk
#define  ADC_SMPR1_SAMP2_Bit0                     (0x1U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP2_Bit1                     (0x2U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP2_Bit2                     (0x4U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP2_Bit3                     (0x8U << ADC_SMPR1_SAMP2_Pos) 
#define  ADC_SMPR1_SAMP3_Pos                      (12)
#define  ADC_SMPR1_SAMP3_Msk                      (0xFU << ADC_SMPR1_SAMP3_Pos)                     /*!<Channel 3 Sample Time Selection*/
#define  ADC_SMPR1_SAMP3                          ADC_SMPR1_SAMP3_Msk
#define  ADC_SMPR1_SAMP3_Bit0                     (0x1U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP3_Bit1                     (0x2U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP3_Bit2                     (0x4U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP3_Bit3                     (0x8U << ADC_SMPR1_SAMP3_Pos) 
#define  ADC_SMPR1_SAMP4_Pos                      (16)
#define  ADC_SMPR1_SAMP4_Msk                      (0xFU << ADC_SMPR1_SAMP4_Pos)                     /*!<Channel 4 Sample Time Selection*/
#define  ADC_SMPR1_SAMP4                          ADC_SMPR1_SAMP4_Msk
#define  ADC_SMPR1_SAMP4_Bit0                     (0x1U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP4_Bit1                     (0x2U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP4_Bit2                     (0x4U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP4_Bit3                     (0x8U << ADC_SMPR1_SAMP4_Pos) 
#define  ADC_SMPR1_SAMP5_Pos                      (20)
#define  ADC_SMPR1_SAMP5_Msk                      (0xFU << ADC_SMPR1_SAMP5_Pos)                     /*!<Channel 5 Sample Time Selection*/
#define  ADC_SMPR1_SAMP5                          ADC_SMPR1_SAMP5_Msk
#define  ADC_SMPR1_SAMP5_Bit0                     (0x1U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP5_Bit1                     (0x2U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP5_Bit2                     (0x4U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP5_Bit3                     (0x8U << ADC_SMPR1_SAMP5_Pos) 
#define  ADC_SMPR1_SAMP6_Pos                      (24)
#define  ADC_SMPR1_SAMP6_Msk                      (0xFU << ADC_SMPR1_SAMP6_Pos)                     /*!<Channel 6 Sample Time Selection*/
#define  ADC_SMPR1_SAMP6                          ADC_SMPR1_SAMP6_Msk
#define  ADC_SMPR1_SAMP6_Bit0                     (0x1U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP6_Bit1                     (0x2U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP6_Bit2                     (0x4U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP6_Bit3                     (0x8U << ADC_SMPR1_SAMP6_Pos) 
#define  ADC_SMPR1_SAMP7_Pos                      (28)
#define  ADC_SMPR1_SAMP7_Msk                      (0xFU << ADC_SMPR1_SAMP7_Pos)                     /*!<Channel 7 Sample Time Selection These bits are used to independently select the sample time of each channel. In a sample cycle, the channel selection bit should remain unchanged*/
#define  ADC_SMPR1_SAMP7                          ADC_SMPR1_SAMP7_Msk
#define  ADC_SMPR1_SAMP7_Bit0                     (0x1U << ADC_SMPR1_SAMP7_Pos) 
#define  ADC_SMPR1_SAMP7_Bit1                     (0x2U << ADC_SMPR1_SAMP7_Pos) 
#define  ADC_SMPR1_SAMP7_Bit2                     (0x4U << ADC_SMPR1_SAMP7_Pos) 
#define  ADC_SMPR1_SAMP7_Bit3                     (0x8U << ADC_SMPR1_SAMP7_Pos) 

/**
  * @brief ADC_SMPR2 Register Bit Definition
  */
#define  ADC_SMPR2_SAMP8_Pos                      (0)
#define  ADC_SMPR2_SAMP8_Msk                      (0xFU << ADC_SMPR2_SAMP8_Pos)                     /*!<Channel 8 Sample Time Selection*/
#define  ADC_SMPR2_SAMP8                          ADC_SMPR2_SAMP8_Msk
#define  ADC_SMPR2_SAMP8_Bit0                     (0x1U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP8_Bit1                     (0x2U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP8_Bit2                     (0x4U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP8_Bit3                     (0x8U << ADC_SMPR2_SAMP8_Pos) 
#define  ADC_SMPR2_SAMP9_Pos                      (4)
#define  ADC_SMPR2_SAMP9_Msk                      (0xFU << ADC_SMPR2_SAMP9_Pos)                     /*!<Channel 9 Sample Time Selection*/
#define  ADC_SMPR2_SAMP9                          ADC_SMPR2_SAMP9_Msk
#define  ADC_SMPR2_SAMP9_Bit0                     (0x1U << ADC_SMPR2_SAMP9_Pos) 
#define  ADC_SMPR2_SAMP9_Bit1                     (0x2U << ADC_SMPR2_SAMP9_Pos) 
#define  ADC_SMPR2_SAMP9_Bit2                     (0x4U << ADC_SMPR2_SAMP9_Pos) 
#define  ADC_SMPR2_SAMP9_Bit3                     (0x8U << ADC_SMPR2_SAMP9_Pos) 
#define  ADC_SMPR2_SAMP10_Pos                     (8)
#define  ADC_SMPR2_SAMP10_Msk                     (0xFU << ADC_SMPR2_SAMP10_Pos)                    /*!<Channel 10 Sample Time Selection*/
#define  ADC_SMPR2_SAMP10                         ADC_SMPR2_SAMP10_Msk
#define  ADC_SMPR2_SAMP10_Bit0                    (0x1U << ADC_SMPR2_SAMP10_Pos) 
#define  ADC_SMPR2_SAMP10_Bit1                    (0x2U << ADC_SMPR2_SAMP10_Pos) 
#define  ADC_SMPR2_SAMP10_Bit2                    (0x4U << ADC_SMPR2_SAMP10_Pos) 
#define  ADC_SMPR2_SAMP10_Bit3                    (0x8U << ADC_SMPR2_SAMP10_Pos) 
#define  ADC_SMPR2_SAMP11_Pos                     (12)
#define  ADC_SMPR2_SAMP11_Msk                     (0xFU << ADC_SMPR2_SAMP11_Pos)                    /*!<Channel 11 Sample Time Selection*/
#define  ADC_SMPR2_SAMP11                         ADC_SMPR2_SAMP11_Msk
#define  ADC_SMPR2_SAMP11_Bit0                    (0x1U << ADC_SMPR2_SAMP11_Pos) 
#define  ADC_SMPR2_SAMP11_Bit1                    (0x2U << ADC_SMPR2_SAMP11_Pos) 
#define  ADC_SMPR2_SAMP11_Bit2                    (0x4U << ADC_SMPR2_SAMP11_Pos) 
#define  ADC_SMPR2_SAMP11_Bit3                    (0x8U << ADC_SMPR2_SAMP11_Pos) 
#define  ADC_SMPR2_SAMP12_Pos                     (16)
#define  ADC_SMPR2_SAMP12_Msk                     (0xFU << ADC_SMPR2_SAMP12_Pos)                    /*!<Channel 12 Sample Time Selection*/
#define  ADC_SMPR2_SAMP12                         ADC_SMPR2_SAMP12_Msk
#define  ADC_SMPR2_SAMP12_Bit0                    (0x1U << ADC_SMPR2_SAMP12_Pos) 
#define  ADC_SMPR2_SAMP12_Bit1                    (0x2U << ADC_SMPR2_SAMP12_Pos) 
#define  ADC_SMPR2_SAMP12_Bit2                    (0x4U << ADC_SMPR2_SAMP12_Pos) 
#define  ADC_SMPR2_SAMP12_Bit3                    (0x8U << ADC_SMPR2_SAMP12_Pos) 
#define  ADC_SMPR2_SAMP13_Pos                     (20)
#define  ADC_SMPR2_SAMP13_Msk                     (0xFU << ADC_SMPR2_SAMP13_Pos)                    /*!<Channel 13 Sample Time Selection*/
#define  ADC_SMPR2_SAMP13                         ADC_SMPR2_SAMP13_Msk
#define  ADC_SMPR2_SAMP13_Bit0                    (0x1U << ADC_SMPR2_SAMP13_Pos) 
#define  ADC_SMPR2_SAMP13_Bit1                    (0x2U << ADC_SMPR2_SAMP13_Pos) 
#define  ADC_SMPR2_SAMP13_Bit2                    (0x4U << ADC_SMPR2_SAMP13_Pos) 
#define  ADC_SMPR2_SAMP13_Bit3                    (0x8U << ADC_SMPR2_SAMP13_Pos) 
#define  ADC_SMPR2_SAMP14_Pos                     (24)
#define  ADC_SMPR2_SAMP14_Msk                     (0xFU << ADC_SMPR2_SAMP14_Pos)                    /*!<Channel 14 Sample Time Selection*/
#define  ADC_SMPR2_SAMP14                         ADC_SMPR2_SAMP14_Msk
#define  ADC_SMPR2_SAMP14_Bit0                    (0x1U << ADC_SMPR2_SAMP14_Pos) 
#define  ADC_SMPR2_SAMP14_Bit1                    (0x2U << ADC_SMPR2_SAMP14_Pos) 
#define  ADC_SMPR2_SAMP14_Bit2                    (0x4U << ADC_SMPR2_SAMP14_Pos) 
#define  ADC_SMPR2_SAMP14_Bit3                    (0x8U << ADC_SMPR2_SAMP14_Pos) 
#define  ADC_SMPR2_SAMP15_Pos                     (28)
#define  ADC_SMPR2_SAMP15_Msk                     (0xFU << ADC_SMPR2_SAMP15_Pos)                    /*!<Channel 15 Sample Time Selection These bits are used to independently select the sample time of each channel. In a sample cycle, the channel selection bit should remain unchanged*/
#define  ADC_SMPR2_SAMP15                         ADC_SMPR2_SAMP15_Msk
#define  ADC_SMPR2_SAMP15_Bit0                    (0x1U << ADC_SMPR2_SAMP15_Pos) 
#define  ADC_SMPR2_SAMP15_Bit1                    (0x2U << ADC_SMPR2_SAMP15_Pos) 
#define  ADC_SMPR2_SAMP15_Bit2                    (0x4U << ADC_SMPR2_SAMP15_Pos) 
#define  ADC_SMPR2_SAMP15_Bit3                    (0x8U << ADC_SMPR2_SAMP15_Pos) 

/**
  * @brief ADC_SMPR3 Register Bit Definition
  */
#define  ADC_SMPR3_SAMP16_Pos                     (0)
#define  ADC_SMPR3_SAMP16_Msk                     (0xFU << ADC_SMPR3_SAMP16_Pos)                    /*!<Channel 16 Sample Time Selection*/
#define  ADC_SMPR3_SAMP16                         ADC_SMPR3_SAMP16_Msk
#define  ADC_SMPR3_SAMP16_Bit0                    (0x1U << ADC_SMPR3_SAMP16_Pos) 
#define  ADC_SMPR3_SAMP16_Bit1                    (0x2U << ADC_SMPR3_SAMP16_Pos) 
#define  ADC_SMPR3_SAMP16_Bit2                    (0x4U << ADC_SMPR3_SAMP16_Pos) 
#define  ADC_SMPR3_SAMP16_Bit3                    (0x8U << ADC_SMPR3_SAMP16_Pos) 
#define  ADC_SMPR3_SAMP17_Pos                     (4)
#define  ADC_SMPR3_SAMP17_Msk                     (0xFU << ADC_SMPR3_SAMP17_Pos)                    /*!<Channel 17 Sample Time Selection*/
#define  ADC_SMPR3_SAMP17                         ADC_SMPR3_SAMP17_Msk
#define  ADC_SMPR3_SAMP17_Bit0                    (0x1U << ADC_SMPR3_SAMP17_Pos) 
#define  ADC_SMPR3_SAMP17_Bit1                    (0x2U << ADC_SMPR3_SAMP17_Pos) 
#define  ADC_SMPR3_SAMP17_Bit2                    (0x4U << ADC_SMPR3_SAMP17_Pos) 
#define  ADC_SMPR3_SAMP17_Bit3                    (0x8U << ADC_SMPR3_SAMP17_Pos) 
#define  ADC_SMPR3_SAMP18_Pos                     (8)
#define  ADC_SMPR3_SAMP18_Msk                     (0xFU << ADC_SMPR3_SAMP18_Pos)                    /*!<Channel 18 Sample Time Selection These bits are used to independently select the sample time of each channel. In a sample cycle, the channel selection bit should remain unchanged*/
#define  ADC_SMPR3_SAMP18                         ADC_SMPR3_SAMP18_Msk
#define  ADC_SMPR3_SAMP18_Bit0                    (0x1U << ADC_SMPR3_SAMP18_Pos) 
#define  ADC_SMPR3_SAMP18_Bit1                    (0x2U << ADC_SMPR3_SAMP18_Pos) 
#define  ADC_SMPR3_SAMP18_Bit2                    (0x4U << ADC_SMPR3_SAMP18_Pos) 
#define  ADC_SMPR3_SAMP18_Bit3                    (0x8U << ADC_SMPR3_SAMP18_Pos) 

/**
  * @brief ADC_JOFR Register Bit Definition
  */
#define  ADC_JOFR_JOFFSET_Pos                     (0)
#define  ADC_JOFR_JOFFSET_Msk                     (0xFFFU << ADC_JOFR_JOFFSET_Pos)                  /*!<Data Offset Register for 12-bit AD Injected Channel n*/
#define  ADC_JOFR_JOFFSET                         ADC_JOFR_JOFFSET_Msk
#define  ADC_JOFR_JOFFSET_Bit0                    (0x001U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit1                    (0x002U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit2                    (0x004U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit3                    (0x008U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit4                    (0x010U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit5                    (0x020U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit6                    (0x040U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit7                    (0x080U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit8                    (0x100U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit9                    (0x200U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit10                   (0x400U << ADC_JOFR_JOFFSET_Pos) 
#define  ADC_JOFR_JOFFSET_Bit11                   (0x800U << ADC_JOFR_JOFFSET_Pos) 

/**
  * @brief ADC_JSQR Register Bit Definition
  */
#define  ADC_JSQR_JSQ0_Pos                        (0)
#define  ADC_JSQR_JSQ0_Msk                        (0x1FU << ADC_JSQR_JSQ0_Pos)                      /*!<0th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ0                            ADC_JSQR_JSQ0_Msk
#define  ADC_JSQR_JSQ0_Bit0                       (0x01U << ADC_JSQR_JSQ0_Pos) 
#define  ADC_JSQR_JSQ0_Bit1                       (0x02U << ADC_JSQR_JSQ0_Pos) 
#define  ADC_JSQR_JSQ0_Bit2                       (0x04U << ADC_JSQR_JSQ0_Pos) 
#define  ADC_JSQR_JSQ0_Bit3                       (0x08U << ADC_JSQR_JSQ0_Pos) 
#define  ADC_JSQR_JSQ0_Bit4                       (0x10U << ADC_JSQR_JSQ0_Pos) 
#define  ADC_JSQR_JSQ1_Pos                        (5)
#define  ADC_JSQR_JSQ1_Msk                        (0x1FU << ADC_JSQR_JSQ1_Pos)                      /*!<1th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ1                            ADC_JSQR_JSQ1_Msk
#define  ADC_JSQR_JSQ1_Bit0                       (0x01U << ADC_JSQR_JSQ1_Pos) 
#define  ADC_JSQR_JSQ1_Bit1                       (0x02U << ADC_JSQR_JSQ1_Pos) 
#define  ADC_JSQR_JSQ1_Bit2                       (0x04U << ADC_JSQR_JSQ1_Pos) 
#define  ADC_JSQR_JSQ1_Bit3                       (0x08U << ADC_JSQR_JSQ1_Pos) 
#define  ADC_JSQR_JSQ1_Bit4                       (0x10U << ADC_JSQR_JSQ1_Pos) 
#define  ADC_JSQR_JSQ2_Pos                        (10)
#define  ADC_JSQR_JSQ2_Msk                        (0x1FU << ADC_JSQR_JSQ2_Pos)                      /*!<2th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ2                            ADC_JSQR_JSQ2_Msk
#define  ADC_JSQR_JSQ2_Bit0                       (0x01U << ADC_JSQR_JSQ2_Pos) 
#define  ADC_JSQR_JSQ2_Bit1                       (0x02U << ADC_JSQR_JSQ2_Pos) 
#define  ADC_JSQR_JSQ2_Bit2                       (0x04U << ADC_JSQR_JSQ2_Pos) 
#define  ADC_JSQR_JSQ2_Bit3                       (0x08U << ADC_JSQR_JSQ2_Pos) 
#define  ADC_JSQR_JSQ2_Bit4                       (0x10U << ADC_JSQR_JSQ2_Pos) 
#define  ADC_JSQR_JSQ3_Pos                        (15)
#define  ADC_JSQR_JSQ3_Msk                        (0x1FU << ADC_JSQR_JSQ3_Pos)                      /*!<3th Conversion for Injected Sequence*/
#define  ADC_JSQR_JSQ3                            ADC_JSQR_JSQ3_Msk
#define  ADC_JSQR_JSQ3_Bit0                       (0x01U << ADC_JSQR_JSQ3_Pos) 
#define  ADC_JSQR_JSQ3_Bit1                       (0x02U << ADC_JSQR_JSQ3_Pos) 
#define  ADC_JSQR_JSQ3_Bit2                       (0x04U << ADC_JSQR_JSQ3_Pos) 
#define  ADC_JSQR_JSQ3_Bit3                       (0x08U << ADC_JSQR_JSQ3_Pos) 
#define  ADC_JSQR_JSQ3_Bit4                       (0x10U << ADC_JSQR_JSQ3_Pos) 
#define  ADC_JSQR_JNUM_Pos                        (20)
#define  ADC_JSQR_JNUM_Msk                        (0x3U << ADC_JSQR_JNUM_Pos)                       /*!<Channel Number for Injected Sequence*/
#define  ADC_JSQR_JNUM                            ADC_JSQR_JNUM_Msk
#define  ADC_JSQR_JNUM_Bit0                       (0x1U << ADC_JSQR_JNUM_Pos) 
#define  ADC_JSQR_JNUM_Bit1                       (0x2U << ADC_JSQR_JNUM_Pos) 

/**
  * @brief ADC_JADDATA Register Bit Definition
  */
#define  ADC_JADDATA_JDATA_Pos                    (0)
#define  ADC_JADDATA_JDATA_Msk                    (0xFFFFU << ADC_JADDATA_JDATA_Pos)                /*!<12-bit A/D conversion result of current injected channel. The alignment style is selected via software.*/
#define  ADC_JADDATA_JDATA                        ADC_JADDATA_JDATA_Msk
#define  ADC_JADDATA_JDATA_Bit0                   (0x0001U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit1                   (0x0002U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit2                   (0x0004U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit3                   (0x0008U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit4                   (0x0010U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit5                   (0x0020U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit6                   (0x0040U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit7                   (0x0080U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit8                   (0x0100U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit9                   (0x0200U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit10                  (0x0400U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit11                  (0x0800U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit12                  (0x1000U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit13                  (0x2000U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit14                  (0x4000U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JDATA_Bit15                  (0x8000U << ADC_JADDATA_JDATA_Pos) 
#define  ADC_JADDATA_JCHANNELSEL_Pos              (16)
#define  ADC_JADDATA_JCHANNELSEL_Msk              (0x1FU << ADC_JADDATA_JCHANNELSEL_Pos)            /*!<*/
#define  ADC_JADDATA_JCHANNELSEL                  ADC_JADDATA_JCHANNELSEL_Msk
#define  ADC_JADDATA_JCHANNELSEL_Bit0             (0x01U << ADC_JADDATA_JCHANNELSEL_Pos) 
#define  ADC_JADDATA_JCHANNELSEL_Bit1             (0x02U << ADC_JADDATA_JCHANNELSEL_Pos) 
#define  ADC_JADDATA_JCHANNELSEL_Bit2             (0x04U << ADC_JADDATA_JCHANNELSEL_Pos) 
#define  ADC_JADDATA_JCHANNELSEL_Bit3             (0x08U << ADC_JADDATA_JCHANNELSEL_Pos) 
#define  ADC_JADDATA_JCHANNELSEL_Bit4             (0x10U << ADC_JADDATA_JCHANNELSEL_Pos) 
#define  ADC_JADDATA_JOVERRUN_Pos                 (21)
#define  ADC_JADDATA_JOVERRUN_Msk                 (0x1U << ADC_JADDATA_JOVERRUN_Pos)                /*!<Overrun Flag for Injected Channels (read-only)*/
#define  ADC_JADDATA_JOVERRUN                     ADC_JADDATA_JOVERRUN_Msk
#define  ADC_JADDATA_JVALID_Pos                   (22)
#define  ADC_JADDATA_JVALID_Msk                   (0x1U << ADC_JADDATA_JVALID_Pos)                  /*!<Valid Flag for Injected Channels (read-only)*/
#define  ADC_JADDATA_JVALID                       ADC_JADDATA_JVALID_Msk

/**
  * @brief ADC_CORRS Register Bit Definition
  */
#define  ADC_CORRS_GAINCORR_Pos                   (0)
#define  ADC_CORRS_GAINCORR_Msk                   (0xFFFU << ADC_CORRS_GAINCORR_Pos)                /*!<The 12-bit gain correction parameter*/
#define  ADC_CORRS_GAINCORR                       ADC_CORRS_GAINCORR_Msk
#define  ADC_CORRS_GAINCORR_Bit0                  (0x001U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit1                  (0x002U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit2                  (0x004U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit3                  (0x008U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit4                  (0x010U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit5                  (0x020U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit6                  (0x040U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit7                  (0x080U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit8                  (0x100U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit9                  (0x200U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit10                 (0x400U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_GAINCORR_Bit11                 (0x800U << ADC_CORRS_GAINCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Pos                 (16)
#define  ADC_CORRS_OFFSETCORR_Msk                 (0xFFFU << ADC_CORRS_OFFSETCORR_Pos)              /*!<The 12-bit offset correction parameter*/
#define  ADC_CORRS_OFFSETCORR                     ADC_CORRS_OFFSETCORR_Msk
#define  ADC_CORRS_OFFSETCORR_Bit0                (0x001U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit1                (0x002U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit2                (0x004U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit3                (0x008U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit4                (0x010U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit5                (0x020U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit6                (0x040U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit7                (0x080U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit8                (0x100U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit9                (0x200U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit10               (0x400U << ADC_CORRS_OFFSETCORR_Pos) 
#define  ADC_CORRS_OFFSETCORR_Bit11               (0x800U << ADC_CORRS_OFFSETCORR_Pos) 

/**
  * @brief ADC_CORRD Register Bit Definition
  */
#define  ADC_CORRD_GAINCORR_Pos                   (0)
#define  ADC_CORRD_GAINCORR_Msk                   (0xFFFU << ADC_CORRD_GAINCORR_Pos)                /*!<The 12-bit gain correction parameters*/
#define  ADC_CORRD_GAINCORR                       ADC_CORRD_GAINCORR_Msk
#define  ADC_CORRD_GAINCORR_Bit0                  (0x001U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit1                  (0x002U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit2                  (0x004U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit3                  (0x008U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit4                  (0x010U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit5                  (0x020U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit6                  (0x040U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit7                  (0x080U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit8                  (0x100U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit9                  (0x200U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit10                 (0x400U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_GAINCORR_Bit11                 (0x800U << ADC_CORRD_GAINCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Pos                 (16)
#define  ADC_CORRD_OFFSETCORR_Msk                 (0xFFFU << ADC_CORRD_OFFSETCORR_Pos)              /*!<The 12-bit offset correction parameter*/
#define  ADC_CORRD_OFFSETCORR                     ADC_CORRD_OFFSETCORR_Msk
#define  ADC_CORRD_OFFSETCORR_Bit0                (0x001U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit1                (0x002U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit2                (0x004U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit3                (0x008U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit4                (0x010U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit5                (0x020U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit6                (0x040U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit7                (0x080U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit8                (0x100U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit9                (0x200U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit10               (0x400U << ADC_CORRD_OFFSETCORR_Pos) 
#define  ADC_CORRD_OFFSETCORR_Bit11               (0x800U << ADC_CORRD_OFFSETCORR_Pos) 

/**
  * @brief ADC_CORRP Register Bit Definition
  */
#define  ADC_CORRP_GAINCORR_Pos                   (0)
#define  ADC_CORRP_GAINCORR_Msk                   (0xFFFU << ADC_CORRP_GAINCORR_Pos)                /*!<The 12-bit gain correction parameters*/
#define  ADC_CORRP_GAINCORR                       ADC_CORRP_GAINCORR_Msk
#define  ADC_CORRP_GAINCORR_Bit0                  (0x001U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit1                  (0x002U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit2                  (0x004U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit3                  (0x008U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit4                  (0x010U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit5                  (0x020U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit6                  (0x040U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit7                  (0x080U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit8                  (0x100U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit9                  (0x200U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit10                 (0x400U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_GAINCORR_Bit11                 (0x800U << ADC_CORRP_GAINCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Pos                 (16)
#define  ADC_CORRP_OFFSETCORR_Msk                 (0xFFFU << ADC_CORRP_OFFSETCORR_Pos)              /*!<The 12-bit offset correction parameter*/
#define  ADC_CORRP_OFFSETCORR                     ADC_CORRP_OFFSETCORR_Msk
#define  ADC_CORRP_OFFSETCORR_Bit0                (0x001U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit1                (0x002U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit2                (0x004U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit3                (0x008U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit4                (0x010U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit5                (0x020U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit6                (0x040U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit7                (0x080U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit8                (0x100U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit9                (0x200U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit10               (0x400U << ADC_CORRP_OFFSETCORR_Pos) 
#define  ADC_CORRP_OFFSETCORR_Bit11               (0x800U << ADC_CORRP_OFFSETCORR_Pos) 

/**
  * @brief ADC_JDR Register Bit Definition
  */
#define  ADC_JDR_JDATA_Pos                        (0)
#define  ADC_JDR_JDATA_Msk                        (0xFFFFU << ADC_JDR_JDATA_Pos)                    /*!<Conversion result of A/D injected channel n (Transfer Data for Injected Channels)*/
#define  ADC_JDR_JDATA                            ADC_JDR_JDATA_Msk
#define  ADC_JDR_JDATA_Bit0                       (0x0001U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit1                       (0x0002U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit2                       (0x0004U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit3                       (0x0008U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit4                       (0x0010U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit5                       (0x0020U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit6                       (0x0040U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit7                       (0x0080U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit8                       (0x0100U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit9                       (0x0200U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit10                      (0x0400U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit11                      (0x0800U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit12                      (0x1000U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit13                      (0x2000U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit14                      (0x4000U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JDATA_Bit15                      (0x8000U << ADC_JDR_JDATA_Pos) 
#define  ADC_JDR_JOVERRUN_Pos                     (21)
#define  ADC_JDR_JOVERRUN_Msk                     (0x1U << ADC_JDR_JOVERRUN_Pos)                    /*!<Overrun Flag for Injected Channels*/
#define  ADC_JDR_JOVERRUN                         ADC_JDR_JOVERRUN_Msk
#define  ADC_JDR_JVALID_Pos                       (22)
#define  ADC_JDR_JVALID_Msk                       (0x1U << ADC_JDR_JVALID_Pos)                      /*!<Valid Flag for Injected Channels*/
#define  ADC_JDR_JVALID                           ADC_JDR_JVALID_Msk


#endif

