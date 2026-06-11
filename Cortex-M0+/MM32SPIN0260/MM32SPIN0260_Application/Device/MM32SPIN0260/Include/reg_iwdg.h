/***********************************************************************************************************************
    @file     reg_iwdg.h
    @author   FD TEAM
    @brief    This flie contains all the IWDG's register and its field definition.
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

#ifndef __REG_IWDG_H
#define __REG_IWDG_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief IWDG Base Address Definition
  */
#define  IWDG_BASE                                 0x40003000                                       /*!<Base Address: 0x40003000*/

/**
  * @brief IWDG Register Structure Definition
  */
typedef struct
{
    __IO uint32_t KR;                             /*!<IWDG Key register                              offset: 0x00       */
    __IO uint32_t PR;                             /*!<IWDG Prescaler register                        offset: 0x04       */
    __IO uint32_t RLR;                            /*!<IWDG Reload register                           offset: 0x08       */
    __IO uint32_t SR;                             /*!<IWDG Status register                           offset: 0x0C       */
    __IO uint32_t CR;                             /*!<IWDG Control register                          offset: 0x10       */
    __IO uint32_t IGEN;                           /*!<IWDG Interrupt generate register               offset: 0x14       */
    __IO uint32_t CNT;                            /*!<IWDG Counter register                          offset: 0x18       */
    __IO uint32_t PS;                             /*!<IWDG Divider counter register                  offset: 0x1C       */
    __IO uint32_t MODE;                           /*!<IWDG Mode register                             offset: 0x20       */
} IWDG_TypeDef;

/**
  * @brief IWDG type pointer Definition
  */
#define IWDG                                      ((IWDG_TypeDef *)IWDG_BASE)

/**
  * @brief IWDG_KR Register Bit Definition
  */
#define  IWDG_KR_KEY_Pos                          (0)
#define  IWDG_KR_KEY_Msk                          (0xFFFFU << IWDG_KR_KEY_Pos)                      /*!<Key value (write-only register)*/
#define  IWDG_KR_KEY                              IWDG_KR_KEY_Msk
#define  IWDG_KR_KEY_Bit0                         (0x0001U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit1                         (0x0002U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit2                         (0x0004U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit3                         (0x0008U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit4                         (0x0010U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit5                         (0x0020U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit6                         (0x0040U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit7                         (0x0080U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit8                         (0x0100U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit9                         (0x0200U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit10                        (0x0400U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit11                        (0x0800U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit12                        (0x1000U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit13                        (0x2000U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit14                        (0x4000U << IWDG_KR_KEY_Pos) 
#define  IWDG_KR_KEY_Bit15                        (0x8000U << IWDG_KR_KEY_Pos) 

/**
  * @brief IWDG_PR Register Bit Definition
  */
#define  IWDG_PR_PR_Pos                           (0)
#define  IWDG_PR_PR_Msk                           (0x7U << IWDG_PR_PR_Pos)                          /*!<Prescaler divider*/
#define  IWDG_PR_PR                               IWDG_PR_PR_Msk
#define  IWDG_PR_PR_Bit0                          (0x1U << IWDG_PR_PR_Pos) 
#define  IWDG_PR_PR_Bit1                          (0x2U << IWDG_PR_PR_Pos) 
#define  IWDG_PR_PR_Bit2                          (0x4U << IWDG_PR_PR_Pos) 

/**
  * @brief IWDG_RLR Register Bit Definition
  */
#define  IWDG_RLR_RL_Pos                          (0)
#define  IWDG_RLR_RL_Msk                          (0xFFFU << IWDG_RLR_RL_Pos)                       /*!<Watchdog counter reload value*/
#define  IWDG_RLR_RL                              IWDG_RLR_RL_Msk
#define  IWDG_RLR_RL_Bit0                         (0x001U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit1                         (0x002U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit2                         (0x004U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit3                         (0x008U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit4                         (0x010U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit5                         (0x020U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit6                         (0x040U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit7                         (0x080U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit8                         (0x100U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit9                         (0x200U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit10                        (0x400U << IWDG_RLR_RL_Pos) 
#define  IWDG_RLR_RL_Bit11                        (0x800U << IWDG_RLR_RL_Pos) 

/**
  * @brief IWDG_SR Register Bit Definition
  */
#define  IWDG_SR_PVU_Pos                          (0)
#define  IWDG_SR_PVU_Msk                          (0x1U << IWDG_SR_PVU_Pos)                         /*!<Watchdog prescaler value update*/
#define  IWDG_SR_PVU                              IWDG_SR_PVU_Msk
#define  IWDG_SR_RVU_Pos                          (1)
#define  IWDG_SR_RVU_Msk                          (0x1U << IWDG_SR_RVU_Pos)                         /*!<Watchdog counter reload value update*/
#define  IWDG_SR_RVU                              IWDG_SR_RVU_Msk
#define  IWDG_SR_IVU_Pos                          (2)
#define  IWDG_SR_IVU_Msk                          (0x1U << IWDG_SR_IVU_Pos)                         /*!<Watchdog Interrupt Generate value update*/
#define  IWDG_SR_IVU                              IWDG_SR_IVU_Msk
#define  IWDG_SR_UPDATE_Pos                       (3)
#define  IWDG_SR_UPDATE_Msk                       (0x1U << IWDG_SR_UPDATE_Pos)                      /*!<Watchdog reload value update flag*/
#define  IWDG_SR_UPDATE                           IWDG_SR_UPDATE_Msk
#define  IWDG_SR_CVU_Pos                          (4)
#define  IWDG_SR_CVU_Msk                          (0x1U << IWDG_SR_CVU_Pos)                         /*!<Watchdog config value update flag*/
#define  IWDG_SR_CVU                              IWDG_SR_CVU_Msk
#define  IWDG_SR_MVU_Pos                          (5)
#define  IWDG_SR_MVU_Msk                          (0x1U << IWDG_SR_MVU_Pos)                         /*!<Watchdog mode value update flag*/
#define  IWDG_SR_MVU                              IWDG_SR_MVU_Msk

/**
  * @brief IWDG_CR Register Bit Definition
  */
#define  IWDG_CR_IRQ_EN_Pos                       (0)
#define  IWDG_CR_IRQ_EN_Msk                       (0x1U << IWDG_CR_IRQ_EN_Pos)                      /*!<IWDG interrupt enable*/
#define  IWDG_CR_IRQ_EN                           IWDG_CR_IRQ_EN_Msk
#define  IWDG_CR_IRQ_CLR_Pos                      (1)
#define  IWDG_CR_IRQ_CLR_Msk                      (0x1U << IWDG_CR_IRQ_CLR_Pos)                     /*!<IWDG interrupt clear*/
#define  IWDG_CR_IRQ_CLR                          IWDG_CR_IRQ_CLR_Msk

/**
  * @brief IWDG_IGEN Register Bit Definition
  */
#define  IWDG_IGEN_IGEN_Pos                       (0)
#define  IWDG_IGEN_IGEN_Msk                       (0xFFFU << IWDG_IGEN_IGEN_Pos)                    /*!<IWDG Interrupt Generate value*/
#define  IWDG_IGEN_IGEN                           IWDG_IGEN_IGEN_Msk
#define  IWDG_IGEN_IGEN_Bit0                      (0x001U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit1                      (0x002U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit2                      (0x004U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit3                      (0x008U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit4                      (0x010U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit5                      (0x020U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit6                      (0x040U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit7                      (0x080U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit8                      (0x100U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit9                      (0x200U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit10                     (0x400U << IWDG_IGEN_IGEN_Pos) 
#define  IWDG_IGEN_IGEN_Bit11                     (0x800U << IWDG_IGEN_IGEN_Pos) 

/**
  * @brief IWDG_CNT Register Bit Definition
  */
#define  IWDG_CNT_IWDG_CNT_Pos                    (0)
#define  IWDG_CNT_IWDG_CNT_Msk                    (0xFFFU << IWDG_CNT_IWDG_CNT_Pos)                 /*!<IWDG counter value*/
#define  IWDG_CNT_IWDG_CNT                        IWDG_CNT_IWDG_CNT_Msk
#define  IWDG_CNT_IWDG_CNT_Bit0                   (0x001U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit1                   (0x002U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit2                   (0x004U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit3                   (0x008U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit4                   (0x010U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit5                   (0x020U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit6                   (0x040U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit7                   (0x080U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit8                   (0x100U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit9                   (0x200U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit10                  (0x400U << IWDG_CNT_IWDG_CNT_Pos) 
#define  IWDG_CNT_IWDG_CNT_Bit11                  (0x800U << IWDG_CNT_IWDG_CNT_Pos) 

/**
  * @brief IWDG_PS Register Bit Definition
  */
#define  IWDG_PS_IWDG_PS_Pos                      (0)
#define  IWDG_PS_IWDG_PS_Msk                      (0xFFU << IWDG_PS_IWDG_PS_Pos)                    /*!<*/
#define  IWDG_PS_IWDG_PS                          IWDG_PS_IWDG_PS_Msk
#define  IWDG_PS_IWDG_PS_Bit0                     (0x01U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit1                     (0x02U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit2                     (0x04U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit3                     (0x08U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit4                     (0x10U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit5                     (0x20U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit6                     (0x40U << IWDG_PS_IWDG_PS_Pos) 
#define  IWDG_PS_IWDG_PS_Bit7                     (0x80U << IWDG_PS_IWDG_PS_Pos) 

/**
  * @brief IWDG_MODE Register Bit Definition
  */
#define  IWDG_MODE_TIM_MODE_Pos                   (0)
#define  IWDG_MODE_TIM_MODE_Msk                   (0x1U << IWDG_MODE_TIM_MODE_Pos)                  /*!<Timer mode*/
#define  IWDG_MODE_TIM_MODE                       IWDG_MODE_TIM_MODE_Msk
#define  IWDG_MODE_STOP_FZ_MODE_Pos               (1)
#define  IWDG_MODE_STOP_FZ_MODE_Msk               (0x1U << IWDG_MODE_STOP_FZ_MODE_Pos)              /*!<Freeze mode in stop mode*/
#define  IWDG_MODE_STOP_FZ_MODE                   IWDG_MODE_STOP_FZ_MODE_Msk

#endif

