/***********************************************************************************************************************
    @file     reg_rtc.h
    @author   VV TEAM
    @brief    This flie contains all the RTC's register and its field definition.
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

#ifndef __REG_RTC_H
#define __REG_RTC_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief RTC Base Address Definition
  */
#define  RTC_BASE                                  0x40002800                                       /*!<Base Address: 0x40002800*/

/**
  * @brief RTC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t TR;                             /*!<RTC RTC time register                          offset: 0x00       */
    __IO uint32_t DR;                             /*!<RTC RTC date register                          offset: 0x04       */
    __IO uint32_t CR;                             /*!<RTC RTC control register                       offset: 0x08       */
    __IO uint32_t ISR;                            /*!<RTC RTC initial and status register            offset: 0x0C       */
    __IO uint32_t PRER;                           /*!<RTC RTC division register                      offset: 0x10       */
    __IO uint32_t WUTR;                           /*!<RTC RTC wake up register                       offset: 0x14       */
    __IO uint32_t LSE_CFG;                        /*!<RTC RTC LSE configuration register             offset: 0x18       */
    __IO uint32_t ALARMAR;                        /*!<RTC RTC alarm clock A register                 offset: 0x1C       */
    __IO uint32_t OR;                             /*!<RTC RTC output control register                offset: 0x20       */
    __IO uint32_t SSR;                            /*!<RTC RTC subsecond register                     offset: 0x24       */
    __IO uint32_t TSTR;                           /*!<RTC RTC timestamp time register                offset: 0x28       */
    __IO uint32_t TSDR;                           /*!<RTC RTC timestamp date register                offset: 0x2C       */
    __IO uint32_t TSSR;                           /*!<RTC RTC timestamp subsecond register           offset: 0x30       */
    __IO uint32_t CALR;                           /*!<RTC RTC calibration register                   offset: 0x34       */
    __IO uint32_t SHIFTR;                         /*!<RTC RTC shift control register                 offset: 0x38       */
    __IO uint32_t ALARMASSR;                      /*!<RTC RTC alarm clock A subsecond register       offset: 0x3C       */
    __IO uint32_t TAMPCR;                         /*!<RTC RTC tamper register                        offset: 0x40       */
    __IO uint32_t RESERVED0x44[3];                /*!<                                               offset: 0x44~0x4C  */
    __IO uint32_t BKP0R;                          /*!<RTC BKP backup register                        offset: 0x50       */
    __IO uint32_t BKP1R;                          /*!<RTC BKP backup register                        offset: 0x54       */
    __IO uint32_t BKP2R;                          /*!<RTC BKP backup register                        offset: 0x58       */
    __IO uint32_t BKP3R;                          /*!<RTC BKP backup register                        offset: 0x5C       */
    __IO uint32_t BKP4R;                          /*!<RTC BKP backup register                        offset: 0x60       */
} RTC_TypeDef;

/**
  * @brief RTC type pointer Definition
  */
#define RTC                                       ((RTC_TypeDef *)RTC_BASE)

/**
  * @brief RTC_TR Register Bit Definition
  */
#define  RTC_TR_SU_Pos                            (0)
#define  RTC_TR_SU_Msk                            (0xFU << RTC_TR_SU_Pos)                           /*!<Units of seconds*/
#define  RTC_TR_SU                                RTC_TR_SU_Msk
#define  RTC_TR_SU_0                              (0x1U << RTC_TR_SU_Pos) 
#define  RTC_TR_SU_1                              (0x2U << RTC_TR_SU_Pos) 
#define  RTC_TR_SU_2                              (0x4U << RTC_TR_SU_Pos) 
#define  RTC_TR_SU_3                              (0x8U << RTC_TR_SU_Pos) 
#define  RTC_TR_ST_Pos                            (4)
#define  RTC_TR_ST_Msk                            (0x7U << RTC_TR_ST_Pos)                           /*!<Tens of seconds*/
#define  RTC_TR_ST                                RTC_TR_ST_Msk
#define  RTC_TR_ST_0                              (0x1U << RTC_TR_ST_Pos) 
#define  RTC_TR_ST_1                              (0x2U << RTC_TR_ST_Pos) 
#define  RTC_TR_ST_2                              (0x4U << RTC_TR_ST_Pos) 
#define  RTC_TR_MNU_Pos                           (8)
#define  RTC_TR_MNU_Msk                           (0xFU << RTC_TR_MNU_Pos)                          /*!<Units of minutes*/
#define  RTC_TR_MNU                               RTC_TR_MNU_Msk
#define  RTC_TR_MNU_0                             (0x1U << RTC_TR_MNU_Pos) 
#define  RTC_TR_MNU_1                             (0x2U << RTC_TR_MNU_Pos) 
#define  RTC_TR_MNU_2                             (0x4U << RTC_TR_MNU_Pos) 
#define  RTC_TR_MNU_3                             (0x8U << RTC_TR_MNU_Pos) 
#define  RTC_TR_MNT_Pos                           (12)
#define  RTC_TR_MNT_Msk                           (0x7U << RTC_TR_MNT_Pos)                          /*!<Tens of minutes*/
#define  RTC_TR_MNT                               RTC_TR_MNT_Msk
#define  RTC_TR_MNT_0                             (0x1U << RTC_TR_MNT_Pos) 
#define  RTC_TR_MNT_1                             (0x2U << RTC_TR_MNT_Pos) 
#define  RTC_TR_MNT_2                             (0x4U << RTC_TR_MNT_Pos) 
#define  RTC_TR_HU_Pos                            (16)
#define  RTC_TR_HU_Msk                            (0xFU << RTC_TR_HU_Pos)                           /*!<Units of hours*/
#define  RTC_TR_HU                                RTC_TR_HU_Msk
#define  RTC_TR_HU_0                              (0x1U << RTC_TR_HU_Pos) 
#define  RTC_TR_HU_1                              (0x2U << RTC_TR_HU_Pos) 
#define  RTC_TR_HU_2                              (0x4U << RTC_TR_HU_Pos) 
#define  RTC_TR_HU_3                              (0x8U << RTC_TR_HU_Pos) 
#define  RTC_TR_HT_Pos                            (20)
#define  RTC_TR_HT_Msk                            (0x3U << RTC_TR_HT_Pos)                           /*!<Tens of hours*/
#define  RTC_TR_HT                                RTC_TR_HT_Msk
#define  RTC_TR_HT_0                              (0x1U << RTC_TR_HT_Pos) 
#define  RTC_TR_HT_1                              (0x2U << RTC_TR_HT_Pos) 
#define  RTC_TR_PM_Pos                            (22)
#define  RTC_TR_PM_Msk                            (0x1U << RTC_TR_PM_Pos)                           /*!<0:24 hour format*/
#define  RTC_TR_PM                                RTC_TR_PM_Msk

/**
  * @brief RTC_DR Register Bit Definition
  */
#define  RTC_DR_DU_Pos                            (0)
#define  RTC_DR_DU_Msk                            (0xFU << RTC_DR_DU_Pos)                           /*!<Units of dates*/
#define  RTC_DR_DU                                RTC_DR_DU_Msk
#define  RTC_DR_DU_0                              (0x1U << RTC_DR_DU_Pos) 
#define  RTC_DR_DU_1                              (0x2U << RTC_DR_DU_Pos) 
#define  RTC_DR_DU_2                              (0x4U << RTC_DR_DU_Pos) 
#define  RTC_DR_DU_3                              (0x8U << RTC_DR_DU_Pos) 
#define  RTC_DR_DT_Pos                            (4)
#define  RTC_DR_DT_Msk                            (0x3U << RTC_DR_DT_Pos)                           /*!<Tens of dates*/
#define  RTC_DR_DT                                RTC_DR_DT_Msk
#define  RTC_DR_DT_0                              (0x1U << RTC_DR_DT_Pos) 
#define  RTC_DR_DT_1                              (0x2U << RTC_DR_DT_Pos) 
#define  RTC_DR_MU_Pos                            (8)
#define  RTC_DR_MU_Msk                            (0xFU << RTC_DR_MU_Pos)                           /*!<Units of months*/
#define  RTC_DR_MU                                RTC_DR_MU_Msk
#define  RTC_DR_MU_0                              (0x1U << RTC_DR_MU_Pos) 
#define  RTC_DR_MU_1                              (0x2U << RTC_DR_MU_Pos) 
#define  RTC_DR_MU_2                              (0x4U << RTC_DR_MU_Pos) 
#define  RTC_DR_MU_3                              (0x8U << RTC_DR_MU_Pos) 
#define  RTC_DR_MT_Pos                            (12)
#define  RTC_DR_MT_Msk                            (0x1U << RTC_DR_MT_Pos)                           /*!<Tens of months*/
#define  RTC_DR_MT                                RTC_DR_MT_Msk
#define  RTC_DR_WDU_Pos                           (13)
#define  RTC_DR_WDU_Msk                           (0x7U << RTC_DR_WDU_Pos)                          /*!<Week day unit*/
#define  RTC_DR_WDU                               RTC_DR_WDU_Msk
#define  RTC_DR_WDU_0                             (0x1U << RTC_DR_WDU_Pos) 
#define  RTC_DR_WDU_1                             (0x2U << RTC_DR_WDU_Pos) 
#define  RTC_DR_WDU_2                             (0x4U << RTC_DR_WDU_Pos) 
#define  RTC_DR_YU_Pos                            (16)
#define  RTC_DR_YU_Msk                            (0xFU << RTC_DR_YU_Pos)                           /*!<Units of years*/
#define  RTC_DR_YU                                RTC_DR_YU_Msk
#define  RTC_DR_YU_0                              (0x1U << RTC_DR_YU_Pos) 
#define  RTC_DR_YU_1                              (0x2U << RTC_DR_YU_Pos) 
#define  RTC_DR_YU_2                              (0x4U << RTC_DR_YU_Pos) 
#define  RTC_DR_YU_3                              (0x8U << RTC_DR_YU_Pos) 
#define  RTC_DR_YT_Pos                            (20)
#define  RTC_DR_YT_Msk                            (0xFU << RTC_DR_YT_Pos)                           /*!<Tens of years*/
#define  RTC_DR_YT                                RTC_DR_YT_Msk
#define  RTC_DR_YT_0                              (0x1U << RTC_DR_YT_Pos) 
#define  RTC_DR_YT_1                              (0x2U << RTC_DR_YT_Pos) 
#define  RTC_DR_YT_2                              (0x4U << RTC_DR_YT_Pos) 
#define  RTC_DR_YT_3                              (0x8U << RTC_DR_YT_Pos) 

/**
  * @brief RTC_CR Register Bit Definition
  */
#define  RTC_CR_WUCKSEL_Pos                       (0)
#define  RTC_CR_WUCKSEL_Msk                       (0x7U << RTC_CR_WUCKSEL_Pos)                      /*!<Wake up clock selection*/
#define  RTC_CR_WUCKSEL                           RTC_CR_WUCKSEL_Msk
#define  RTC_CR_WUCKSEL_0                         (0x1U << RTC_CR_WUCKSEL_Pos) 
#define  RTC_CR_WUCKSEL_1                         (0x2U << RTC_CR_WUCKSEL_Pos) 
#define  RTC_CR_WUCKSEL_2                         (0x4U << RTC_CR_WUCKSEL_Pos) 
#define  RTC_CR_TSEDGE_Pos                        (4)
#define  RTC_CR_TSEDGE_Msk                        (0x1U << RTC_CR_TSEDGE_Pos)                       /*!<Active edge of timestamp event*/
#define  RTC_CR_TSEDGE                            RTC_CR_TSEDGE_Msk
#define  RTC_CR_BYPSHAD_Pos                       (5)
#define  RTC_CR_BYPSHAD_Msk                       (0x1U << RTC_CR_BYPSHAD_Pos)                      /*!<Bypass shadow register*/
#define  RTC_CR_BYPSHAD                           RTC_CR_BYPSHAD_Msk
#define  RTC_CR_FMT_Pos                           (6)
#define  RTC_CR_FMT_Msk                           (0x1U << RTC_CR_FMT_Pos)                          /*!<Hour format*/
#define  RTC_CR_FMT                               RTC_CR_FMT_Msk
#define  RTC_CR_ALRAE_Pos                         (7)
#define  RTC_CR_ALRAE_Msk                         (0x1U << RTC_CR_ALRAE_Pos)                        /*!<Alarm clock A enable*/
#define  RTC_CR_ALRAE                             RTC_CR_ALRAE_Msk
#define  RTC_CR_WUTE_Pos                          (10)
#define  RTC_CR_WUTE_Msk                          (0x1U << RTC_CR_WUTE_Pos)                         /*!<Wake up timer enable*/
#define  RTC_CR_WUTE                              RTC_CR_WUTE_Msk
#define  RTC_CR_TSE_Pos                           (11)
#define  RTC_CR_TSE_Msk                           (0x1U << RTC_CR_TSE_Pos)                          /*!<Timestamp enable*/
#define  RTC_CR_TSE                               RTC_CR_TSE_Msk
#define  RTC_CR_TSIE_Pos                          (12)
#define  RTC_CR_TSIE_Msk                          (0x1U << RTC_CR_TSIE_Pos)                         /*!<Timestamp interrupt enable*/
#define  RTC_CR_TSIE                              RTC_CR_TSIE_Msk
#define  RTC_CR_WUTIE_Pos                         (13)
#define  RTC_CR_WUTIE_Msk                         (0x1U << RTC_CR_WUTIE_Pos)                        /*!<Wake up timer interrupt enable*/
#define  RTC_CR_WUTIE                             RTC_CR_WUTIE_Msk
#define  RTC_CR_ALRAIE_Pos                        (14)
#define  RTC_CR_ALRAIE_Msk                        (0x1U << RTC_CR_ALRAIE_Pos)                       /*!<Alarm clock A interrupt enable*/
#define  RTC_CR_ALRAIE                            RTC_CR_ALRAIE_Msk
#define  RTC_CR_ADD1H_Pos                         (16)
#define  RTC_CR_ADD1H_Msk                         (0x1U << RTC_CR_ADD1H_Pos)                        /*!<0: This bit is inactive*/
#define  RTC_CR_ADD1H                             RTC_CR_ADD1H_Msk
#define  RTC_CR_SUB1H_Pos                         (17)
#define  RTC_CR_SUB1H_Msk                         (0x1U << RTC_CR_SUB1H_Pos)                        /*!<0: This bit is inactive*/
#define  RTC_CR_SUB1H                             RTC_CR_SUB1H_Msk
#define  RTC_CR_BKP_Pos                           (18)
#define  RTC_CR_BKP_Msk                           (0x1U << RTC_CR_BKP_Pos)                          /*!<BKP record summer time operation*/
#define  RTC_CR_BKP                               RTC_CR_BKP_Msk
#define  RTC_CR_OSEL_Pos                          (19)
#define  RTC_CR_OSEL_Msk                          (0x3U << RTC_CR_OSEL_Pos)                         /*!<Output flag selection*/
#define  RTC_CR_OSEL                              RTC_CR_OSEL_Msk
#define  RTC_CR_OSEL_0                            (0x1U << RTC_CR_OSEL_Pos) 
#define  RTC_CR_OSEL_1                            (0x2U << RTC_CR_OSEL_Pos) 
#define  RTC_CR_COSEL_Pos                         (21)
#define  RTC_CR_COSEL_Msk                         (0x1U << RTC_CR_COSEL_Pos)                        /*!<COSEL: Calibration output selection*/
#define  RTC_CR_COSEL                             RTC_CR_COSEL_Msk
#define  RTC_CR_COE_Pos                           (22)
#define  RTC_CR_COE_Msk                           (0x1U << RTC_CR_COE_Pos)                          /*!<COE: Calibration output enable*/
#define  RTC_CR_COE                               RTC_CR_COE_Msk
#define  RTC_CR_POL_Pos                           (23)
#define  RTC_CR_POL_Msk                           (0x1U << RTC_CR_POL_Pos)                          /*!<POL: Output polarity*/
#define  RTC_CR_POL                               RTC_CR_POL_Msk

/**
  * @brief RTC_ISR Register Bit Definition
  */
#define  RTC_ISR_ALRAWF_Pos                       (0)
#define  RTC_ISR_ALRAWF_Msk                       (0x1U << RTC_ISR_ALRAWF_Pos)                      /*!<Alarm clock A write flag*/
#define  RTC_ISR_ALRAWF                           RTC_ISR_ALRAWF_Msk
#define  RTC_ISR_WUTWF_Pos                        (2)
#define  RTC_ISR_WUTWF_Msk                        (0x1U << RTC_ISR_WUTWF_Pos)                       /*!<Wake up timer write flag*/
#define  RTC_ISR_WUTWF                            RTC_ISR_WUTWF_Msk
#define  RTC_ISR_SHPF_Pos                         (3)
#define  RTC_ISR_SHPF_Msk                         (0x1U << RTC_ISR_SHPF_Pos)                        /*!<Shift operation flag*/
#define  RTC_ISR_SHPF                             RTC_ISR_SHPF_Msk
#define  RTC_ISR_INITS_Pos                        (4)
#define  RTC_ISR_INITS_Msk                        (0x1U << RTC_ISR_INITS_Pos)                       /*!<Initializing status flag*/
#define  RTC_ISR_INITS                            RTC_ISR_INITS_Msk
#define  RTC_ISR_RSF_Pos                          (5)
#define  RTC_ISR_RSF_Msk                          (0x1U << RTC_ISR_RSF_Pos)                         /*!<Register synchronization flag*/
#define  RTC_ISR_RSF                              RTC_ISR_RSF_Msk
#define  RTC_ISR_INITF_Pos                        (6)
#define  RTC_ISR_INITF_Msk                        (0x1U << RTC_ISR_INITF_Pos)                       /*!<Initial flag*/
#define  RTC_ISR_INITF                            RTC_ISR_INITF_Msk
#define  RTC_ISR_INIT_Pos                         (7)
#define  RTC_ISR_INIT_Msk                         (0x1U << RTC_ISR_INIT_Pos)                        /*!<Initializing mode*/
#define  RTC_ISR_INIT                             RTC_ISR_INIT_Msk
#define  RTC_ISR_ALRAF_Pos                        (8)
#define  RTC_ISR_ALRAF_Msk                        (0x1U << RTC_ISR_ALRAF_Pos)                       /*!<Alarm clock occurrence flag*/
#define  RTC_ISR_ALRAF                            RTC_ISR_ALRAF_Msk
#define  RTC_ISR_WUTF_Pos                         (10)
#define  RTC_ISR_WUTF_Msk                         (0x1U << RTC_ISR_WUTF_Pos)                        /*!<Wake up unit flag*/
#define  RTC_ISR_WUTF                             RTC_ISR_WUTF_Msk
#define  RTC_ISR_TSF_Pos                          (11)
#define  RTC_ISR_TSF_Msk                          (0x1U << RTC_ISR_TSF_Pos)                         /*!<Timestamp event flag*/
#define  RTC_ISR_TSF                              RTC_ISR_TSF_Msk
#define  RTC_ISR_TSOVF_Pos                        (12)
#define  RTC_ISR_TSOVF_Msk                        (0x1U << RTC_ISR_TSOVF_Pos)                       /*!<Timestamp overflow flag*/
#define  RTC_ISR_TSOVF                            RTC_ISR_TSOVF_Msk

/**
  * @brief RTC_PRER Register Bit Definition
  */
#define  RTC_PRER_PREDIV_S_Pos                    (0)
#define  RTC_PRER_PREDIV_S_Msk                    (0x7FFFU << RTC_PRER_PREDIV_S_Pos)                /*!<Synchronous prescaler coefficient*/
#define  RTC_PRER_PREDIV_S                        RTC_PRER_PREDIV_S_Msk
#define  RTC_PRER_PREDIV_S_0                      (0x0001U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_1                      (0x0002U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_2                      (0x0004U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_3                      (0x0008U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_4                      (0x0010U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_5                      (0x0020U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_6                      (0x0040U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_7                      (0x0080U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_8                      (0x0100U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_9                      (0x0200U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_10                     (0x0400U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_11                     (0x0800U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_12                     (0x1000U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_13                     (0x2000U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_S_14                     (0x4000U << RTC_PRER_PREDIV_S_Pos) 
#define  RTC_PRER_PREDIV_A_Pos                    (16)
#define  RTC_PRER_PREDIV_A_Msk                    (0x7FU << RTC_PRER_PREDIV_A_Pos)                  /*!<Asynchronous prescaler coefficient*/
#define  RTC_PRER_PREDIV_A                        RTC_PRER_PREDIV_A_Msk
#define  RTC_PRER_PREDIV_A_0                      (0x01U << RTC_PRER_PREDIV_A_Pos) 
#define  RTC_PRER_PREDIV_A_1                      (0x02U << RTC_PRER_PREDIV_A_Pos) 
#define  RTC_PRER_PREDIV_A_2                      (0x04U << RTC_PRER_PREDIV_A_Pos) 
#define  RTC_PRER_PREDIV_A_3                      (0x08U << RTC_PRER_PREDIV_A_Pos) 
#define  RTC_PRER_PREDIV_A_4                      (0x10U << RTC_PRER_PREDIV_A_Pos) 
#define  RTC_PRER_PREDIV_A_5                      (0x20U << RTC_PRER_PREDIV_A_Pos) 
#define  RTC_PRER_PREDIV_A_6                      (0x40U << RTC_PRER_PREDIV_A_Pos) 

/**
  * @brief RTC_WUTR Register Bit Definition
  */
#define  RTC_WUTR_WUTRL_Pos                       (0)
#define  RTC_WUTR_WUTRL_Msk                       (0xFFFFU << RTC_WUTR_WUTRL_Pos)                   /*!<Wake up auto reload value bit*/
#define  RTC_WUTR_WUTRL                           RTC_WUTR_WUTRL_Msk
#define  RTC_WUTR_WUTRL_0                         (0x0001U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_1                         (0x0002U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_2                         (0x0004U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_3                         (0x0008U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_4                         (0x0010U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_5                         (0x0020U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_6                         (0x0040U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_7                         (0x0080U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_8                         (0x0100U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_9                         (0x0200U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_10                        (0x0400U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_11                        (0x0800U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_12                        (0x1000U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_13                        (0x2000U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_14                        (0x4000U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRL_15                        (0x8000U << RTC_WUTR_WUTRL_Pos) 
#define  RTC_WUTR_WUTRH_Pos                       (16)
#define  RTC_WUTR_WUTRH_Msk                       (0x1U << RTC_WUTR_WUTRH_Pos)                      /*!<Configure WUCKSEL[2] =1. This bit is always set. It's cleared under other*/
#define  RTC_WUTR_WUTRH                           RTC_WUTR_WUTRH_Msk

/**
  * @brief RTC_LSE_CFG Register Bit Definition
  */
#define  RTC_LSE_CFG_LSE_TC_Pos                   (0)
#define  RTC_LSE_CFG_LSE_TC_Msk                   (0x3U << RTC_LSE_CFG_LSE_TC_Pos)                  /*!<LSE high temperature leakage compensation mode*/
#define  RTC_LSE_CFG_LSE_TC                       RTC_LSE_CFG_LSE_TC_Msk
#define  RTC_LSE_CFG_LSE_TC_0                     (0x1U << RTC_LSE_CFG_LSE_TC_Pos) 
#define  RTC_LSE_CFG_LSE_TC_1                     (0x2U << RTC_LSE_CFG_LSE_TC_Pos) 
#define  RTC_LSE_CFG_LSE_OUTENH_Pos               (2)
#define  RTC_LSE_CFG_LSE_OUTENH_Msk               (0x1U << RTC_LSE_CFG_LSE_OUTENH_Pos)              /*!<0: Normal mode*/
#define  RTC_LSE_CFG_LSE_OUTENH                   RTC_LSE_CFG_LSE_OUTENH_Msk
#define  RTC_LSE_CFG_LSE_DR_Pos                   (4)
#define  RTC_LSE_CFG_LSE_DR_Msk                   (0x3U << RTC_LSE_CFG_LSE_DR_Pos)                  /*!<LSE_DR: LSE drive capacity selection*/
#define  RTC_LSE_CFG_LSE_DR                       RTC_LSE_CFG_LSE_DR_Msk
#define  RTC_LSE_CFG_LSE_DR_0                     (0x1U << RTC_LSE_CFG_LSE_DR_Pos) 
#define  RTC_LSE_CFG_LSE_DR_1                     (0x2U << RTC_LSE_CFG_LSE_DR_Pos) 
#define  RTC_LSE_CFG_LSE_RFB_SEL_Pos              (6)
#define  RTC_LSE_CFG_LSE_RFB_SEL_Msk              (0x3U << RTC_LSE_CFG_LSE_RFB_SEL_Pos)             /*!<LSE_RFB_SEL: LSE feedback resistance selection*/
#define  RTC_LSE_CFG_LSE_RFB_SEL                  RTC_LSE_CFG_LSE_RFB_SEL_Msk
#define  RTC_LSE_CFG_LSE_RFB_SEL_0                (0x1U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 
#define  RTC_LSE_CFG_LSE_RFB_SEL_1                (0x2U << RTC_LSE_CFG_LSE_RFB_SEL_Pos) 
#define  RTC_LSE_CFG_LSE_IB_Pos                   (8)
#define  RTC_LSE_CFG_LSE_IB_Msk                   (0x3U << RTC_LSE_CFG_LSE_IB_Pos)                  /*!<LSE_IB: LSE bias current regulation*/
#define  RTC_LSE_CFG_LSE_IB                       RTC_LSE_CFG_LSE_IB_Msk
#define  RTC_LSE_CFG_LSE_IB_0                     (0x1U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_IB_1                     (0x2U << RTC_LSE_CFG_LSE_IB_Pos) 
#define  RTC_LSE_CFG_LSE_AAC_Pos                  (10)
#define  RTC_LSE_CFG_LSE_AAC_Msk                  (0x1U << RTC_LSE_CFG_LSE_AAC_Pos)                 /*!<Auto gain regulation*/
#define  RTC_LSE_CFG_LSE_AAC                      RTC_LSE_CFG_LSE_AAC_Msk

/**
  * @brief RTC_ALARMAR Register Bit Definition
  */
#define  RTC_ALARMAR_SU_Pos                       (0)
#define  RTC_ALARMAR_SU_Msk                       (0xFU << RTC_ALARMAR_SU_Pos)                      /*!<Units of seconds*/
#define  RTC_ALARMAR_SU                           RTC_ALARMAR_SU_Msk
#define  RTC_ALARMAR_SU_0                         (0x1U << RTC_ALARMAR_SU_Pos) 
#define  RTC_ALARMAR_SU_1                         (0x2U << RTC_ALARMAR_SU_Pos) 
#define  RTC_ALARMAR_SU_2                         (0x4U << RTC_ALARMAR_SU_Pos) 
#define  RTC_ALARMAR_SU_3                         (0x8U << RTC_ALARMAR_SU_Pos) 
#define  RTC_ALARMAR_ST_Pos                       (4)
#define  RTC_ALARMAR_ST_Msk                       (0x7U << RTC_ALARMAR_ST_Pos)                      /*!<Tens of seconds*/
#define  RTC_ALARMAR_ST                           RTC_ALARMAR_ST_Msk
#define  RTC_ALARMAR_ST_0                         (0x1U << RTC_ALARMAR_ST_Pos) 
#define  RTC_ALARMAR_ST_1                         (0x2U << RTC_ALARMAR_ST_Pos) 
#define  RTC_ALARMAR_ST_2                         (0x4U << RTC_ALARMAR_ST_Pos) 
#define  RTC_ALARMAR_MSK1_Pos                     (7)
#define  RTC_ALARMAR_MSK1_Msk                     (0x1U << RTC_ALARMAR_MSK1_Pos)                    /*!<Alarm clock second mask bit*/
#define  RTC_ALARMAR_MSK1                         RTC_ALARMAR_MSK1_Msk
#define  RTC_ALARMAR_MNU_Pos                      (8)
#define  RTC_ALARMAR_MNU_Msk                      (0xFU << RTC_ALARMAR_MNU_Pos)                     /*!<Units of minutes*/
#define  RTC_ALARMAR_MNU                          RTC_ALARMAR_MNU_Msk
#define  RTC_ALARMAR_MNU_0                        (0x1U << RTC_ALARMAR_MNU_Pos) 
#define  RTC_ALARMAR_MNU_1                        (0x2U << RTC_ALARMAR_MNU_Pos) 
#define  RTC_ALARMAR_MNU_2                        (0x4U << RTC_ALARMAR_MNU_Pos) 
#define  RTC_ALARMAR_MNU_3                        (0x8U << RTC_ALARMAR_MNU_Pos) 
#define  RTC_ALARMAR_MNT_Pos                      (12)
#define  RTC_ALARMAR_MNT_Msk                      (0x7U << RTC_ALARMAR_MNT_Pos)                     /*!<Tens of minutes*/
#define  RTC_ALARMAR_MNT                          RTC_ALARMAR_MNT_Msk
#define  RTC_ALARMAR_MNT_0                        (0x1U << RTC_ALARMAR_MNT_Pos) 
#define  RTC_ALARMAR_MNT_1                        (0x2U << RTC_ALARMAR_MNT_Pos) 
#define  RTC_ALARMAR_MNT_2                        (0x4U << RTC_ALARMAR_MNT_Pos) 
#define  RTC_ALARMAR_MSK2_Pos                     (15)
#define  RTC_ALARMAR_MSK2_Msk                     (0x1U << RTC_ALARMAR_MSK2_Pos)                    /*!<Alarm clock minute mask bit*/
#define  RTC_ALARMAR_MSK2                         RTC_ALARMAR_MSK2_Msk
#define  RTC_ALARMAR_HU_Pos                       (16)
#define  RTC_ALARMAR_HU_Msk                       (0xFU << RTC_ALARMAR_HU_Pos)                      /*!<Units of hours*/
#define  RTC_ALARMAR_HU                           RTC_ALARMAR_HU_Msk
#define  RTC_ALARMAR_HU_0                         (0x1U << RTC_ALARMAR_HU_Pos) 
#define  RTC_ALARMAR_HU_1                         (0x2U << RTC_ALARMAR_HU_Pos) 
#define  RTC_ALARMAR_HU_2                         (0x4U << RTC_ALARMAR_HU_Pos) 
#define  RTC_ALARMAR_HU_3                         (0x8U << RTC_ALARMAR_HU_Pos) 
#define  RTC_ALARMAR_HT_Pos                       (20)
#define  RTC_ALARMAR_HT_Msk                       (0x3U << RTC_ALARMAR_HT_Pos)                      /*!<Tens of hours*/
#define  RTC_ALARMAR_HT                           RTC_ALARMAR_HT_Msk
#define  RTC_ALARMAR_HT_0                         (0x1U << RTC_ALARMAR_HT_Pos) 
#define  RTC_ALARMAR_HT_1                         (0x2U << RTC_ALARMAR_HT_Pos) 
#define  RTC_ALARMAR_PM_Pos                       (22)
#define  RTC_ALARMAR_PM_Msk                       (0x1U << RTC_ALARMAR_PM_Pos)                      /*!<0: 24 hour format*/
#define  RTC_ALARMAR_PM                           RTC_ALARMAR_PM_Msk
#define  RTC_ALARMAR_MSK3_Pos                     (23)
#define  RTC_ALARMAR_MSK3_Msk                     (0x1U << RTC_ALARMAR_MSK3_Pos)                    /*!<Alarm clock hour mask bit*/
#define  RTC_ALARMAR_MSK3                         RTC_ALARMAR_MSK3_Msk
#define  RTC_ALARMAR_DU_Pos                       (24)
#define  RTC_ALARMAR_DU_Msk                       (0xFU << RTC_ALARMAR_DU_Pos)                      /*!<Units of date*/
#define  RTC_ALARMAR_DU                           RTC_ALARMAR_DU_Msk
#define  RTC_ALARMAR_DU_0                         (0x1U << RTC_ALARMAR_DU_Pos) 
#define  RTC_ALARMAR_DU_1                         (0x2U << RTC_ALARMAR_DU_Pos) 
#define  RTC_ALARMAR_DU_2                         (0x4U << RTC_ALARMAR_DU_Pos) 
#define  RTC_ALARMAR_DU_3                         (0x8U << RTC_ALARMAR_DU_Pos) 
#define  RTC_ALARMAR_DT_Pos                       (28)
#define  RTC_ALARMAR_DT_Msk                       (0x3U << RTC_ALARMAR_DT_Pos)                      /*!<Tens of date*/
#define  RTC_ALARMAR_DT                           RTC_ALARMAR_DT_Msk
#define  RTC_ALARMAR_DT_0                         (0x1U << RTC_ALARMAR_DT_Pos) 
#define  RTC_ALARMAR_DT_1                         (0x2U << RTC_ALARMAR_DT_Pos) 
#define  RTC_ALARMAR_WDSEL_Pos                    (30)
#define  RTC_ALARMAR_WDSEL_Msk                    (0x1U << RTC_ALARMAR_WDSEL_Pos)                   /*!<Alarm clock date or week day selection bit*/
#define  RTC_ALARMAR_WDSEL                        RTC_ALARMAR_WDSEL_Msk
#define  RTC_ALARMAR_MSK4_Pos                     (31)
#define  RTC_ALARMAR_MSK4_Msk                     (0x1U << RTC_ALARMAR_MSK4_Pos)                    /*!<Alarm clock date or week day mask bit*/
#define  RTC_ALARMAR_MSK4                         RTC_ALARMAR_MSK4_Msk

/**
  * @brief RTC_OR Register Bit Definition
  */
#define  RTC_OR_REMAP_Pos                         (0)
#define  RTC_OR_REMAP_Msk                         (0x1U << RTC_OR_REMAP_Pos)                        /*!<remap=0*/
#define  RTC_OR_REMAP                             RTC_OR_REMAP_Msk

/**
  * @brief RTC_SSR Register Bit Definition
  */
#define  RTC_SSR_SS_Pos                           (0)
#define  RTC_SSR_SS_Msk                           (0x7FFFU << RTC_SSR_SS_Pos)                       /*!<SS is the value of synchronous prescaler counter. Subsecond calculation formula*/
#define  RTC_SSR_SS                               RTC_SSR_SS_Msk
#define  RTC_SSR_SS_0                             (0x0001U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_1                             (0x0002U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_2                             (0x0004U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_3                             (0x0008U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_4                             (0x0010U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_5                             (0x0020U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_6                             (0x0040U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_7                             (0x0080U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_8                             (0x0100U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_9                             (0x0200U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_10                            (0x0400U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_11                            (0x0800U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_12                            (0x1000U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_13                            (0x2000U << RTC_SSR_SS_Pos) 
#define  RTC_SSR_SS_14                            (0x4000U << RTC_SSR_SS_Pos) 

/**
  * @brief RTC_TSTR Register Bit Definition
  */
#define  RTC_TSTR_SU_Pos                          (0)
#define  RTC_TSTR_SU_Msk                          (0xFU << RTC_TSTR_SU_Pos)                         /*!<Units of seconds*/
#define  RTC_TSTR_SU                              RTC_TSTR_SU_Msk
#define  RTC_TSTR_SU_0                            (0x1U << RTC_TSTR_SU_Pos) 
#define  RTC_TSTR_SU_1                            (0x2U << RTC_TSTR_SU_Pos) 
#define  RTC_TSTR_SU_2                            (0x4U << RTC_TSTR_SU_Pos) 
#define  RTC_TSTR_SU_3                            (0x8U << RTC_TSTR_SU_Pos) 
#define  RTC_TSTR_ST_Pos                          (4)
#define  RTC_TSTR_ST_Msk                          (0x7U << RTC_TSTR_ST_Pos)                         /*!<Tens of seconds*/
#define  RTC_TSTR_ST                              RTC_TSTR_ST_Msk
#define  RTC_TSTR_ST_0                            (0x1U << RTC_TSTR_ST_Pos) 
#define  RTC_TSTR_ST_1                            (0x2U << RTC_TSTR_ST_Pos) 
#define  RTC_TSTR_ST_2                            (0x4U << RTC_TSTR_ST_Pos) 
#define  RTC_TSTR_MNU_Pos                         (8)
#define  RTC_TSTR_MNU_Msk                         (0xFU << RTC_TSTR_MNU_Pos)                        /*!<Units of minutes*/
#define  RTC_TSTR_MNU                             RTC_TSTR_MNU_Msk
#define  RTC_TSTR_MNU_0                           (0x1U << RTC_TSTR_MNU_Pos) 
#define  RTC_TSTR_MNU_1                           (0x2U << RTC_TSTR_MNU_Pos) 
#define  RTC_TSTR_MNU_2                           (0x4U << RTC_TSTR_MNU_Pos) 
#define  RTC_TSTR_MNU_3                           (0x8U << RTC_TSTR_MNU_Pos) 
#define  RTC_TSTR_MNT_Pos                         (12)
#define  RTC_TSTR_MNT_Msk                         (0x7U << RTC_TSTR_MNT_Pos)                        /*!<Tens of minutes*/
#define  RTC_TSTR_MNT                             RTC_TSTR_MNT_Msk
#define  RTC_TSTR_MNT_0                           (0x1U << RTC_TSTR_MNT_Pos) 
#define  RTC_TSTR_MNT_1                           (0x2U << RTC_TSTR_MNT_Pos) 
#define  RTC_TSTR_MNT_2                           (0x4U << RTC_TSTR_MNT_Pos) 
#define  RTC_TSTR_HU_Pos                          (16)
#define  RTC_TSTR_HU_Msk                          (0xFU << RTC_TSTR_HU_Pos)                         /*!<Units of hours*/
#define  RTC_TSTR_HU                              RTC_TSTR_HU_Msk
#define  RTC_TSTR_HU_0                            (0x1U << RTC_TSTR_HU_Pos) 
#define  RTC_TSTR_HU_1                            (0x2U << RTC_TSTR_HU_Pos) 
#define  RTC_TSTR_HU_2                            (0x4U << RTC_TSTR_HU_Pos) 
#define  RTC_TSTR_HU_3                            (0x8U << RTC_TSTR_HU_Pos) 
#define  RTC_TSTR_HT_Pos                          (20)
#define  RTC_TSTR_HT_Msk                          (0x3U << RTC_TSTR_HT_Pos)                         /*!<Tens of hours*/
#define  RTC_TSTR_HT                              RTC_TSTR_HT_Msk
#define  RTC_TSTR_HT_0                            (0x1U << RTC_TSTR_HT_Pos) 
#define  RTC_TSTR_HT_1                            (0x2U << RTC_TSTR_HT_Pos) 
#define  RTC_TSTR_PM_Pos                          (22)
#define  RTC_TSTR_PM_Msk                          (0x1U << RTC_TSTR_PM_Pos)                         /*!<0: 24 hour format*/
#define  RTC_TSTR_PM                              RTC_TSTR_PM_Msk

/**
  * @brief RTC_TSDR Register Bit Definition
  */
#define  RTC_TSDR_DU_Pos                          (0)
#define  RTC_TSDR_DU_Msk                          (0xFU << RTC_TSDR_DU_Pos)                         /*!<Units of date*/
#define  RTC_TSDR_DU                              RTC_TSDR_DU_Msk
#define  RTC_TSDR_DU_0                            (0x1U << RTC_TSDR_DU_Pos) 
#define  RTC_TSDR_DU_1                            (0x2U << RTC_TSDR_DU_Pos) 
#define  RTC_TSDR_DU_2                            (0x4U << RTC_TSDR_DU_Pos) 
#define  RTC_TSDR_DU_3                            (0x8U << RTC_TSDR_DU_Pos) 
#define  RTC_TSDR_DT_Pos                          (4)
#define  RTC_TSDR_DT_Msk                          (0x3U << RTC_TSDR_DT_Pos)                         /*!<Tens of date*/
#define  RTC_TSDR_DT                              RTC_TSDR_DT_Msk
#define  RTC_TSDR_DT_0                            (0x1U << RTC_TSDR_DT_Pos) 
#define  RTC_TSDR_DT_1                            (0x2U << RTC_TSDR_DT_Pos) 
#define  RTC_TSDR_MU_Pos                          (8)
#define  RTC_TSDR_MU_Msk                          (0xFU << RTC_TSDR_MU_Pos)                         /*!<Units of months*/
#define  RTC_TSDR_MU                              RTC_TSDR_MU_Msk
#define  RTC_TSDR_MU_0                            (0x1U << RTC_TSDR_MU_Pos) 
#define  RTC_TSDR_MU_1                            (0x2U << RTC_TSDR_MU_Pos) 
#define  RTC_TSDR_MU_2                            (0x4U << RTC_TSDR_MU_Pos) 
#define  RTC_TSDR_MU_3                            (0x8U << RTC_TSDR_MU_Pos) 
#define  RTC_TSDR_MT_Pos                          (12)
#define  RTC_TSDR_MT_Msk                          (0x1U << RTC_TSDR_MT_Pos)                         /*!<Tens of months*/
#define  RTC_TSDR_MT                              RTC_TSDR_MT_Msk
#define  RTC_TSDR_WDU_Pos                         (13)
#define  RTC_TSDR_WDU_Msk                         (0x7U << RTC_TSDR_WDU_Pos)                        /*!<Week day unit*/
#define  RTC_TSDR_WDU                             RTC_TSDR_WDU_Msk
#define  RTC_TSDR_WDU_0                           (0x1U << RTC_TSDR_WDU_Pos) 
#define  RTC_TSDR_WDU_1                           (0x2U << RTC_TSDR_WDU_Pos) 
#define  RTC_TSDR_WDU_2                           (0x4U << RTC_TSDR_WDU_Pos) 
#define  RTC_TSDR_YU_Pos                          (16)
#define  RTC_TSDR_YU_Msk                          (0xFU << RTC_TSDR_YU_Pos)                         /*!<Units of years*/
#define  RTC_TSDR_YU                              RTC_TSDR_YU_Msk
#define  RTC_TSDR_YU_0                            (0x1U << RTC_TSDR_YU_Pos) 
#define  RTC_TSDR_YU_1                            (0x2U << RTC_TSDR_YU_Pos) 
#define  RTC_TSDR_YU_2                            (0x4U << RTC_TSDR_YU_Pos) 
#define  RTC_TSDR_YU_3                            (0x8U << RTC_TSDR_YU_Pos) 
#define  RTC_TSDR_YT_Pos                          (20)
#define  RTC_TSDR_YT_Msk                          (0xFU << RTC_TSDR_YT_Pos)                         /*!<Tens of years*/
#define  RTC_TSDR_YT                              RTC_TSDR_YT_Msk
#define  RTC_TSDR_YT_0                            (0x1U << RTC_TSDR_YT_Pos) 
#define  RTC_TSDR_YT_1                            (0x2U << RTC_TSDR_YT_Pos) 
#define  RTC_TSDR_YT_2                            (0x4U << RTC_TSDR_YT_Pos) 
#define  RTC_TSDR_YT_3                            (0x8U << RTC_TSDR_YT_Pos) 

/**
  * @brief RTC_TSSR Register Bit Definition
  */
#define  RTC_TSSR_SS_Pos                          (0)
#define  RTC_TSSR_SS_Msk                          (0x7FFFU << RTC_TSSR_SS_Pos)                      /*!<Subsecond value*/
#define  RTC_TSSR_SS                              RTC_TSSR_SS_Msk
#define  RTC_TSSR_SS_0                            (0x0001U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_1                            (0x0002U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_2                            (0x0004U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_3                            (0x0008U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_4                            (0x0010U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_5                            (0x0020U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_6                            (0x0040U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_7                            (0x0080U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_8                            (0x0100U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_9                            (0x0200U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_10                           (0x0400U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_11                           (0x0800U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_12                           (0x1000U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_13                           (0x2000U << RTC_TSSR_SS_Pos) 
#define  RTC_TSSR_SS_14                           (0x4000U << RTC_TSSR_SS_Pos) 

/**
  * @brief RTC_CALR Register Bit Definition
  */
#define  RTC_CALR_CALM_Pos                        (0)
#define  RTC_CALR_CALM_Msk                        (0x1FFU << RTC_CALR_CALM_Pos)                     /*!<The number of pulse masked within 2 to the 20th power RTC clock pulse*/
#define  RTC_CALR_CALM                            RTC_CALR_CALM_Msk
#define  RTC_CALR_CALM_0                          (0x001U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_1                          (0x002U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_2                          (0x004U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_3                          (0x008U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_4                          (0x010U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_5                          (0x020U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_6                          (0x040U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_7                          (0x080U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALM_8                          (0x100U << RTC_CALR_CALM_Pos) 
#define  RTC_CALR_CALP_Pos                        (15)
#define  RTC_CALR_CALP_Msk                        (0x1U << RTC_CALR_CALP_Pos)                       /*!<Frequency increase 488.5 ppm*/
#define  RTC_CALR_CALP                            RTC_CALR_CALP_Msk

/**
  * @brief RTC_SHIFTR Register Bit Definition
  */
#define  RTC_SHIFTR_SUBFS_Pos                     (0)
#define  RTC_SHIFTR_SUBFS_Msk                     (0x7FFFU << RTC_SHIFTR_SUBFS_Pos)                 /*!<Reduce subsecond value*/
#define  RTC_SHIFTR_SUBFS                         RTC_SHIFTR_SUBFS_Msk
#define  RTC_SHIFTR_SUBFS_0                       (0x0001U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_1                       (0x0002U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_2                       (0x0004U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_3                       (0x0008U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_4                       (0x0010U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_5                       (0x0020U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_6                       (0x0040U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_7                       (0x0080U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_8                       (0x0100U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_9                       (0x0200U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_10                      (0x0400U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_11                      (0x0800U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_12                      (0x1000U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_13                      (0x2000U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_SUBFS_14                      (0x4000U << RTC_SHIFTR_SUBFS_Pos) 
#define  RTC_SHIFTR_ADD1S_Pos                     (16)
#define  RTC_SHIFTR_ADD1S_Msk                     (0x1U << RTC_SHIFTR_ADD1S_Pos)                    /*!<Increase 1s*/
#define  RTC_SHIFTR_ADD1S                         RTC_SHIFTR_ADD1S_Msk

/**
  * @brief RTC_ALARMASSR Register Bit Definition
  */
#define  RTC_ALARMASSR_SS_Pos                     (0)
#define  RTC_ALARMASSR_SS_Msk                     (0x7FFFU << RTC_ALARMASSR_SS_Pos)                 /*!<Alarm clock subsecond value, used for comparing with the synchronous prescaler counter*/
#define  RTC_ALARMASSR_SS                         RTC_ALARMASSR_SS_Msk
#define  RTC_ALARMASSR_SS_0                       (0x0001U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_1                       (0x0002U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_2                       (0x0004U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_3                       (0x0008U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_4                       (0x0010U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_5                       (0x0020U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_6                       (0x0040U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_7                       (0x0080U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_8                       (0x0100U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_9                       (0x0200U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_10                      (0x0400U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_11                      (0x0800U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_12                      (0x1000U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_13                      (0x2000U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_SS_14                      (0x4000U << RTC_ALARMASSR_SS_Pos) 
#define  RTC_ALARMASSR_MASKSS_Pos                 (16)
#define  RTC_ALARMASSR_MASKSS_Msk                 (0xFU << RTC_ALARMASSR_MASKSS_Pos)                /*!<Max. valid bit when the mask starts from this bit.*/
#define  RTC_ALARMASSR_MASKSS                     RTC_ALARMASSR_MASKSS_Msk
#define  RTC_ALARMASSR_MASKSS_0                   (0x1U << RTC_ALARMASSR_MASKSS_Pos) 
#define  RTC_ALARMASSR_MASKSS_1                   (0x2U << RTC_ALARMASSR_MASKSS_Pos) 
#define  RTC_ALARMASSR_MASKSS_2                   (0x4U << RTC_ALARMASSR_MASKSS_Pos) 
#define  RTC_ALARMASSR_MASKSS_3                   (0x8U << RTC_ALARMASSR_MASKSS_Pos) 

/**
  * @brief RTC_TAMPCR Register Bit Definition
  */
#define  RTC_TAMPCR_TAMP1E_Pos                    (0)
#define  RTC_TAMPCR_TAMP1E_Msk                    (0x1U << RTC_TAMPCR_TAMP1E_Pos)                   /*!<TAMP1 tamper enable*/
#define  RTC_TAMPCR_TAMP1E                        RTC_TAMPCR_TAMP1E_Msk
#define  RTC_TAMPCR_TAMP1IE_Pos                   (1)
#define  RTC_TAMPCR_TAMP1IE_Msk                   (0x1U << RTC_TAMPCR_TAMP1IE_Pos)                  /*!<TAMP1 tamper interrupt enable*/
#define  RTC_TAMPCR_TAMP1IE                       RTC_TAMPCR_TAMP1IE_Msk
#define  RTC_TAMPCR_TAMP1TRG_Pos                  (2)
#define  RTC_TAMPCR_TAMP1TRG_Msk                  (0x1U << RTC_TAMPCR_TAMP1TRG_Pos)                 /*!<TAMP1 tamper valid edge selection*/
#define  RTC_TAMPCR_TAMP1TRG                      RTC_TAMPCR_TAMP1TRG_Msk
#define  RTC_TAMPCR_TAMP1F_Pos                    (3)
#define  RTC_TAMPCR_TAMP1F_Msk                    (0x1U << RTC_TAMPCR_TAMP1F_Pos)                   /*!<TAMP1 tamper flag*/
#define  RTC_TAMPCR_TAMP1F                        RTC_TAMPCR_TAMP1F_Msk
#define  RTC_TAMPCR_TAMPTS_Pos                    (4)
#define  RTC_TAMPCR_TAMPTS_Msk                    (0x1U << RTC_TAMPCR_TAMPTS_Pos)                   /*!<Activate timestamp in case of tamper detection event*/
#define  RTC_TAMPCR_TAMPTS                        RTC_TAMPCR_TAMPTS_Msk
#define  RTC_TAMPCR_TAMP2E_Pos                    (5)
#define  RTC_TAMPCR_TAMP2E_Msk                    (0x1U << RTC_TAMPCR_TAMP2E_Pos)                   /*!<TAMP2 tamper enable*/
#define  RTC_TAMPCR_TAMP2E                        RTC_TAMPCR_TAMP2E_Msk
#define  RTC_TAMPCR_TAMP2IE_Pos                   (6)
#define  RTC_TAMPCR_TAMP2IE_Msk                   (0x1U << RTC_TAMPCR_TAMP2IE_Pos)                  /*!<TAMP2 tamper interrupt enable*/
#define  RTC_TAMPCR_TAMP2IE                       RTC_TAMPCR_TAMP2IE_Msk
#define  RTC_TAMPCR_TAMP2TRG_Pos                  (7)
#define  RTC_TAMPCR_TAMP2TRG_Msk                  (0x1U << RTC_TAMPCR_TAMP2TRG_Pos)                 /*!<TAMP2 tamper valid edge selection*/
#define  RTC_TAMPCR_TAMP2TRG                      RTC_TAMPCR_TAMP2TRG_Msk
#define  RTC_TAMPCR_TAMP2F_Pos                    (8)
#define  RTC_TAMPCR_TAMP2F_Msk                    (0x1U << RTC_TAMPCR_TAMP2F_Pos)                   /*!<TAMP2 tamper flag*/
#define  RTC_TAMPCR_TAMP2F                        RTC_TAMPCR_TAMP2F_Msk
#define  RTC_TAMPCR_TAMP1IF_Pos                   (9)
#define  RTC_TAMPCR_TAMP1IF_Msk                   (0x1U << RTC_TAMPCR_TAMP1IF_Pos)                  /*!<Tamper event 1 interrupt flag. The flag is set by hardware, and cleared by software.*/
#define  RTC_TAMPCR_TAMP1IF                       RTC_TAMPCR_TAMP1IF_Msk
#define  RTC_TAMPCR_TAMP2IF_Pos                   (10)
#define  RTC_TAMPCR_TAMP2IF_Msk                   (0x1U << RTC_TAMPCR_TAMP2IF_Pos)                  /*!<Tamper event 2 interrupt flag. The flag is set by hardware, and cleared by software.*/
#define  RTC_TAMPCR_TAMP2IF                       RTC_TAMPCR_TAMP2IF_Msk

/**
  * @brief RTC_BKPR Register Bit Definition
  */
#define  RTC_BKPR_BKP_Pos                         (0)
#define  RTC_BKPR_BKP_Msk                         (0xFFFFFFFFU << RTC_BKPR_BKP_Pos)                 /*!<When the device works in the low power mode, the content of these registers keeps active. In case of tamper detection event, the register will be reset. In case of TAMP1F=1 or TAMP2F=1, the register remains reset.*/
#define  RTC_BKPR_BKP                             RTC_BKPR_BKP_Msk
#define  RTC_BKPR_BKP_0                           (0x00000001U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_1                           (0x00000002U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_2                           (0x00000004U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_3                           (0x00000008U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_4                           (0x00000010U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_5                           (0x00000020U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_6                           (0x00000040U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_7                           (0x00000080U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_8                           (0x00000100U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_9                           (0x00000200U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_10                          (0x00000400U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_11                          (0x00000800U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_12                          (0x00001000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_13                          (0x00002000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_14                          (0x00004000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_15                          (0x00008000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_16                          (0x00010000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_17                          (0x00020000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_18                          (0x00040000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_19                          (0x00080000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_20                          (0x00100000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_21                          (0x00200000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_22                          (0x00400000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_23                          (0x00800000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_24                          (0x01000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_25                          (0x02000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_26                          (0x04000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_27                          (0x08000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_28                          (0x10000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_29                          (0x20000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_30                          (0x40000000U << RTC_BKPR_BKP_Pos) 
#define  RTC_BKPR_BKP_31                          (0x80000000U << RTC_BKPR_BKP_Pos) 

#endif

