/***********************************************************************************************************************
    @file     reg_exti.h
    @author   FD TEAM
    @brief    This flie contains all the EXTI's register and its field definition.
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

#ifndef __REG_EXTI_H
#define __REG_EXTI_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief EXTI Base Address Definition
  */
#define  EXTI_BASE                                 0x40010400                                       /*!<Base Address: 0x40010400*/

/**
  * @brief EXTI Register Structure Definition
  */
typedef struct
{
    __IO uint32_t IMR;                            /*!<EXTI Interrupt mask register                   offset: 0x00       */
    __IO uint32_t EMR;                            /*!<EXTI Event mask register                       offset: 0x04       */
    __IO uint32_t RTSR;                           /*!<EXTI Rising edge trigger selection register    offset: 0x08       */
    __IO uint32_t FTSR;                           /*!<EXTI Falling edge trigger selection register   offset: 0x0C       */
    __IO uint32_t SWIER;                          /*!<EXTI Software interrupt event register         offset: 0x10       */
    __IO uint32_t PR;                             /*!<EXTI Pending register                          offset: 0x14       */
    __IO uint32_t RESERVED0x18[2];                /*!<                                               offset: 0x18~0x1C  */
    __IO uint32_t DFLTEN;                         /*!<EXTI Filter enable register                    offset: 0x20       */
    __IO uint32_t DFLTW;                          /*!<EXTI Filter window select register             offset: 0x24       */
    __IO uint32_t DFLTMUX;                        /*!<EXTI Filter input source select register       offset: 0x28       */
} EXTI_TypeDef;

/**
  * @brief EXTI type pointer Definition
  */
#define EXTI                                      ((EXTI_TypeDef *)EXTI_BASE)

/**
  * @brief EXTI_IMR Register Bit Definition
  */
#define  EXTI_IMR_IMRx_Pos                        (0)
#define  EXTI_IMR_IMRx_Msk                        (0xFFFFFFFFU << EXTI_IMR_IMRx_Pos)                /*!<interrupt enable bit*/
#define  EXTI_IMR_IMRx                            EXTI_IMR_IMRx_Msk
#define  EXTI_IMR_IMRx_Bit0                       (0x00000001U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit1                       (0x00000002U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit2                       (0x00000004U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit3                       (0x00000008U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit4                       (0x00000010U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit5                       (0x00000020U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit6                       (0x00000040U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit7                       (0x00000080U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit8                       (0x00000100U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit9                       (0x00000200U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit10                      (0x00000400U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit11                      (0x00000800U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit12                      (0x00001000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit13                      (0x00002000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit14                      (0x00004000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit15                      (0x00008000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit16                      (0x00010000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit17                      (0x00020000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit18                      (0x00040000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit19                      (0x00080000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit20                      (0x00100000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit21                      (0x00200000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit22                      (0x00400000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit23                      (0x00800000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit24                      (0x01000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit25                      (0x02000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit26                      (0x04000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit27                      (0x08000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit28                      (0x10000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit29                      (0x20000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit30                      (0x40000000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_Bit31                      (0x80000000U << EXTI_IMR_IMRx_Pos) 

/**
  * @brief EXTI_EMR Register Bit Definition
  */
#define  EXTI_EMR_EMRx_Pos                        (0)
#define  EXTI_EMR_EMRx_Msk                        (0xFFFFFFFFU << EXTI_EMR_EMRx_Pos)                /*!<event enable bit*/
#define  EXTI_EMR_EMRx                            EXTI_EMR_EMRx_Msk
#define  EXTI_EMR_EMRx_Bit0                       (0x00000001U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit1                       (0x00000002U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit2                       (0x00000004U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit3                       (0x00000008U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit4                       (0x00000010U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit5                       (0x00000020U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit6                       (0x00000040U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit7                       (0x00000080U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit8                       (0x00000100U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit9                       (0x00000200U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit10                      (0x00000400U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit11                      (0x00000800U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit12                      (0x00001000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit13                      (0x00002000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit14                      (0x00004000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit15                      (0x00008000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit16                      (0x00010000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit17                      (0x00020000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit18                      (0x00040000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit19                      (0x00080000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit20                      (0x00100000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit21                      (0x00200000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit22                      (0x00400000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit23                      (0x00800000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit24                      (0x01000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit25                      (0x02000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit26                      (0x04000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit27                      (0x08000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit28                      (0x10000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit29                      (0x20000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit30                      (0x40000000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_Bit31                      (0x80000000U << EXTI_EMR_EMRx_Pos) 

/**
  * @brief EXTI_RTSR Register Bit Definition
  */
#define  EXTI_RTSR_TRx_Pos                        (0)
#define  EXTI_RTSR_TRx_Msk                        (0xFFFFFFFFU << EXTI_RTSR_TRx_Pos)                /*!<interrupt or event trigger polarity*/
#define  EXTI_RTSR_TRx                            EXTI_RTSR_TRx_Msk
#define  EXTI_RTSR_TRx_Bit0                       (0x00000001U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit1                       (0x00000002U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit2                       (0x00000004U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit3                       (0x00000008U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit4                       (0x00000010U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit5                       (0x00000020U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit6                       (0x00000040U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit7                       (0x00000080U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit8                       (0x00000100U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit9                       (0x00000200U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit10                      (0x00000400U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit11                      (0x00000800U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit12                      (0x00001000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit13                      (0x00002000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit14                      (0x00004000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit15                      (0x00008000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit16                      (0x00010000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit17                      (0x00020000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit18                      (0x00040000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit19                      (0x00080000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit20                      (0x00100000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit21                      (0x00200000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit22                      (0x00400000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit23                      (0x00800000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit24                      (0x01000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit25                      (0x02000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit26                      (0x04000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit27                      (0x08000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit28                      (0x10000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit29                      (0x20000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit30                      (0x40000000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_Bit31                      (0x80000000U << EXTI_RTSR_TRx_Pos) 

/**
  * @brief EXTI_FTSR Register Bit Definition
  */
#define  EXTI_FTSR_TRx_Pos                        (0)
#define  EXTI_FTSR_TRx_Msk                        (0xFFFFFFFFU << EXTI_FTSR_TRx_Pos)                /*!<event enable bit*/
#define  EXTI_FTSR_TRx                            EXTI_FTSR_TRx_Msk
#define  EXTI_FTSR_TRx_Bit0                       (0x00000001U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit1                       (0x00000002U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit2                       (0x00000004U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit3                       (0x00000008U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit4                       (0x00000010U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit5                       (0x00000020U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit6                       (0x00000040U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit7                       (0x00000080U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit8                       (0x00000100U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit9                       (0x00000200U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit10                      (0x00000400U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit11                      (0x00000800U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit12                      (0x00001000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit13                      (0x00002000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit14                      (0x00004000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit15                      (0x00008000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit16                      (0x00010000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit17                      (0x00020000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit18                      (0x00040000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit19                      (0x00080000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit20                      (0x00100000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit21                      (0x00200000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit22                      (0x00400000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit23                      (0x00800000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit24                      (0x01000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit25                      (0x02000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit26                      (0x04000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit27                      (0x08000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit28                      (0x10000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit29                      (0x20000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit30                      (0x40000000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_Bit31                      (0x80000000U << EXTI_FTSR_TRx_Pos) 

/**
  * @brief EXTI_SWIER Register Bit Definition
  */
#define  EXTI_SWIER_SWIERx_Pos                    (0)
#define  EXTI_SWIER_SWIERx_Msk                    (0xFFFFFFFFU << EXTI_SWIER_SWIERx_Pos)            /*!<software interrupt or event enable*/
#define  EXTI_SWIER_SWIERx                        EXTI_SWIER_SWIERx_Msk
#define  EXTI_SWIER_SWIERx_Bit0                   (0x00000001U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit1                   (0x00000002U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit2                   (0x00000004U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit3                   (0x00000008U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit4                   (0x00000010U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit5                   (0x00000020U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit6                   (0x00000040U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit7                   (0x00000080U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit8                   (0x00000100U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit9                   (0x00000200U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit10                  (0x00000400U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit11                  (0x00000800U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit12                  (0x00001000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit13                  (0x00002000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit14                  (0x00004000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit15                  (0x00008000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit16                  (0x00010000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit17                  (0x00020000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit18                  (0x00040000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit19                  (0x00080000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit20                  (0x00100000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit21                  (0x00200000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit22                  (0x00400000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit23                  (0x00800000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit24                  (0x01000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit25                  (0x02000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit26                  (0x04000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit27                  (0x08000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit28                  (0x10000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit29                  (0x20000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit30                  (0x40000000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_Bit31                  (0x80000000U << EXTI_SWIER_SWIERx_Pos) 

/**
  * @brief EXTI_PR Register Bit Definition
  */
#define  EXTI_PR_PRx_Pos                          (0)
#define  EXTI_PR_PRx_Msk                          (0xFFFFFFFFU << EXTI_PR_PRx_Pos)                  /*!<trigger pending bit*/
#define  EXTI_PR_PRx                              EXTI_PR_PRx_Msk
#define  EXTI_PR_PRx_Bit0                         (0x00000001U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit1                         (0x00000002U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit2                         (0x00000004U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit3                         (0x00000008U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit4                         (0x00000010U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit5                         (0x00000020U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit6                         (0x00000040U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit7                         (0x00000080U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit8                         (0x00000100U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit9                         (0x00000200U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit10                        (0x00000400U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit11                        (0x00000800U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit12                        (0x00001000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit13                        (0x00002000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit14                        (0x00004000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit15                        (0x00008000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit16                        (0x00010000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit17                        (0x00020000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit18                        (0x00040000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit19                        (0x00080000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit20                        (0x00100000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit21                        (0x00200000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit22                        (0x00400000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit23                        (0x00800000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit24                        (0x01000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit25                        (0x02000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit26                        (0x04000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit27                        (0x08000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit28                        (0x10000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit29                        (0x20000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit30                        (0x40000000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_Bit31                        (0x80000000U << EXTI_PR_PRx_Pos) 

/**
  * @brief EXTI_DFLTEN Register Bit Definition
  */
#define  EXTI_DFLTEN_FILTER0_EN_Pos               (0)
#define  EXTI_DFLTEN_FILTER0_EN_Msk               (0x1U << EXTI_DFLTEN_FILTER0_EN_Pos)              /*!<Built-in Filter Enable*/
#define  EXTI_DFLTEN_FILTER0_EN                   EXTI_DFLTEN_FILTER0_EN_Msk
#define  EXTI_DFLTEN_FILTER1_EN_Pos               (1)
#define  EXTI_DFLTEN_FILTER1_EN_Msk               (0x1U << EXTI_DFLTEN_FILTER1_EN_Pos)              /*!<Built-in Filter Enable*/
#define  EXTI_DFLTEN_FILTER1_EN                   EXTI_DFLTEN_FILTER1_EN_Msk
#define  EXTI_DFLTEN_FILTER_PRE_Pos               (16)
#define  EXTI_DFLTEN_FILTER_PRE_Msk               (0x7U << EXTI_DFLTEN_FILTER_PRE_Pos)              /*!<FILTER_PRE: EXTI Filter Clock Prescaler This setting controls the prescaler coefficient for the EXTI filter counter via software configuration.*/
#define  EXTI_DFLTEN_FILTER_PRE                   EXTI_DFLTEN_FILTER_PRE_Msk
#define  EXTI_DFLTEN_FILTER_PRE_Bit0              (0x1U << EXTI_DFLTEN_FILTER_PRE_Pos) 
#define  EXTI_DFLTEN_FILTER_PRE_Bit1              (0x2U << EXTI_DFLTEN_FILTER_PRE_Pos) 
#define  EXTI_DFLTEN_FILTER_PRE_Bit2              (0x4U << EXTI_DFLTEN_FILTER_PRE_Pos) 

/**
  * @brief EXTI_DFLTW Register Bit Definition
  */
#define  EXTI_DFLTW_FILTER0_SEL_Pos               (0)
#define  EXTI_DFLTW_FILTER0_SEL_Msk               (0x3U << EXTI_DFLTW_FILTER0_SEL_Pos)              /*!<FILTER0_Select: Built-in Filter Pulse Width:?*/
#define  EXTI_DFLTW_FILTER0_SEL                   EXTI_DFLTW_FILTER0_SEL_Msk
#define  EXTI_DFLTW_FILTER0_SEL_Bit0              (0x1U << EXTI_DFLTW_FILTER0_SEL_Pos) 
#define  EXTI_DFLTW_FILTER0_SEL_Bit1              (0x2U << EXTI_DFLTW_FILTER0_SEL_Pos) 
#define  EXTI_DFLTW_FILTER1_SEL_Pos               (2)
#define  EXTI_DFLTW_FILTER1_SEL_Msk               (0x3U << EXTI_DFLTW_FILTER1_SEL_Pos)              /*!<FILTER1_Select: Built-in Filter Pulse Width:?*/
#define  EXTI_DFLTW_FILTER1_SEL                   EXTI_DFLTW_FILTER1_SEL_Msk
#define  EXTI_DFLTW_FILTER1_SEL_Bit0              (0x1U << EXTI_DFLTW_FILTER1_SEL_Pos) 
#define  EXTI_DFLTW_FILTER1_SEL_Bit1              (0x2U << EXTI_DFLTW_FILTER1_SEL_Pos) 

/**
  * @brief EXTI_DFLTMUX Register Bit Definition
  */
#define  EXTI_DFLTMUX_FILTER0_MUX_Pos             (0)
#define  EXTI_DFLTMUX_FILTER0_MUX_Msk             (0xFU << EXTI_DFLTMUX_FILTER0_MUX_Pos)            /*!<FILTER0_MUX*/
#define  EXTI_DFLTMUX_FILTER0_MUX                 EXTI_DFLTMUX_FILTER0_MUX_Msk
#define  EXTI_DFLTMUX_FILTER0_MUX_Bit0            (0x1U << EXTI_DFLTMUX_FILTER0_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER0_MUX_Bit1            (0x2U << EXTI_DFLTMUX_FILTER0_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER0_MUX_Bit2            (0x4U << EXTI_DFLTMUX_FILTER0_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER0_MUX_Bit3            (0x8U << EXTI_DFLTMUX_FILTER0_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER1_MUX_Pos             (4)
#define  EXTI_DFLTMUX_FILTER1_MUX_Msk             (0xFU << EXTI_DFLTMUX_FILTER1_MUX_Pos)            /*!<FILTER1_MUX*/
#define  EXTI_DFLTMUX_FILTER1_MUX                 EXTI_DFLTMUX_FILTER1_MUX_Msk
#define  EXTI_DFLTMUX_FILTER1_MUX_Bit0            (0x1U << EXTI_DFLTMUX_FILTER1_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER1_MUX_Bit1            (0x2U << EXTI_DFLTMUX_FILTER1_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER1_MUX_Bit2            (0x4U << EXTI_DFLTMUX_FILTER1_MUX_Pos) 
#define  EXTI_DFLTMUX_FILTER1_MUX_Bit3            (0x8U << EXTI_DFLTMUX_FILTER1_MUX_Pos) 


#endif

