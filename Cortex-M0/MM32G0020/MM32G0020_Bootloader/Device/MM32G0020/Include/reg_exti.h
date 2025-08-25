
/***********************************************************************************************************************
    @file     reg_exti.h
    @author   VV TEAM
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
#include "core_cm0.h"

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
} EXTI_TypeDef;

/**
  * @brief EXTI type pointer Definition
  */
#define EXTI                                      ((EXTI_TypeDef *)EXTI_BASE)

/**
  * @brief EXTI_IMR Register Bit Definition
  */
#define  EXTI_IMR_IMRx_Pos                        (0)
#define  EXTI_IMR_IMRx_Msk                        (0x3FFFFU << EXTI_IMR_IMRx_Pos)                   /*!<Line x interrupt enable bit*/
#define  EXTI_IMR_IMRx                            EXTI_IMR_IMRx_Msk
#define  EXTI_IMR_IMRx_0                          (0x00001U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_1                          (0x00002U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_2                          (0x00004U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_3                          (0x00008U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_4                          (0x00010U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_5                          (0x00020U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_6                          (0x00040U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_7                          (0x00080U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_8                          (0x00100U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_9                          (0x00200U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_10                         (0x00400U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_11                         (0x00800U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_12                         (0x01000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_13                         (0x02000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_14                         (0x04000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_15                         (0x08000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_16                         (0x10000U << EXTI_IMR_IMRx_Pos) 
#define  EXTI_IMR_IMRx_17                         (0x20000U << EXTI_IMR_IMRx_Pos) 

/**
  * @brief EXTI_EMR Register Bit Definition
  */
#define  EXTI_EMR_EMRx_Pos                        (0)
#define  EXTI_EMR_EMRx_Msk                        (0x3FFFFU << EXTI_EMR_EMRx_Pos)                   /*!<Line x event enable bit*/
#define  EXTI_EMR_EMRx                            EXTI_EMR_EMRx_Msk
#define  EXTI_EMR_EMRx_0                          (0x00001U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_1                          (0x00002U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_2                          (0x00004U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_3                          (0x00008U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_4                          (0x00010U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_5                          (0x00020U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_6                          (0x00040U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_7                          (0x00080U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_8                          (0x00100U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_9                          (0x00200U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_10                         (0x00400U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_11                         (0x00800U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_12                         (0x01000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_13                         (0x02000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_14                         (0x04000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_15                         (0x08000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_16                         (0x10000U << EXTI_EMR_EMRx_Pos) 
#define  EXTI_EMR_EMRx_17                         (0x20000U << EXTI_EMR_EMRx_Pos) 

/**
  * @brief EXTI_RTSR Register Bit Definition
  */
#define  EXTI_RTSR_TRx_Pos                        (0)
#define  EXTI_RTSR_TRx_Msk                        (0x3FFFFU << EXTI_RTSR_TRx_Pos)                   /*!<Line x corresponding interrupt or event trigger polarity*/
#define  EXTI_RTSR_TRx                            EXTI_RTSR_TRx_Msk
#define  EXTI_RTSR_TRx_0                          (0x00001U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_1                          (0x00002U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_2                          (0x00004U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_3                          (0x00008U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_4                          (0x00010U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_5                          (0x00020U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_6                          (0x00040U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_7                          (0x00080U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_8                          (0x00100U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_9                          (0x00200U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_10                         (0x00400U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_11                         (0x00800U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_12                         (0x01000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_13                         (0x02000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_14                         (0x04000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_15                         (0x08000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_16                         (0x10000U << EXTI_RTSR_TRx_Pos) 
#define  EXTI_RTSR_TRx_17                         (0x20000U << EXTI_RTSR_TRx_Pos) 

/**
  * @brief EXTI_FTSR Register Bit Definition
  */
#define  EXTI_FTSR_TRx_Pos                        (0)
#define  EXTI_FTSR_TRx_Msk                        (0x3FFFFU << EXTI_FTSR_TRx_Pos)                   /*!<Line x corresponding interrupt or event trigger polarity*/
#define  EXTI_FTSR_TRx                            EXTI_FTSR_TRx_Msk
#define  EXTI_FTSR_TRx_0                          (0x00001U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_1                          (0x00002U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_2                          (0x00004U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_3                          (0x00008U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_4                          (0x00010U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_5                          (0x00020U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_6                          (0x00040U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_7                          (0x00080U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_8                          (0x00100U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_9                          (0x00200U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_10                         (0x00400U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_11                         (0x00800U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_12                         (0x01000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_13                         (0x02000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_14                         (0x04000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_15                         (0x08000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_16                         (0x10000U << EXTI_FTSR_TRx_Pos) 
#define  EXTI_FTSR_TRx_17                         (0x20000U << EXTI_FTSR_TRx_Pos) 

/**
  * @brief EXTI_SWIER Register Bit Definition
  */
#define  EXTI_SWIER_SWIERx_Pos                    (0)
#define  EXTI_SWIER_SWIERx_Msk                    (0x3FFFFU << EXTI_SWIER_SWIERx_Pos)               /*!<Line x software interrupt or event enable*/
#define  EXTI_SWIER_SWIERx                        EXTI_SWIER_SWIERx_Msk
#define  EXTI_SWIER_SWIERx_0                      (0x00001U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_1                      (0x00002U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_2                      (0x00004U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_3                      (0x00008U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_4                      (0x00010U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_5                      (0x00020U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_6                      (0x00040U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_7                      (0x00080U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_8                      (0x00100U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_9                      (0x00200U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_10                     (0x00400U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_11                     (0x00800U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_12                     (0x01000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_13                     (0x02000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_14                     (0x04000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_15                     (0x08000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_16                     (0x10000U << EXTI_SWIER_SWIERx_Pos) 
#define  EXTI_SWIER_SWIERx_17                     (0x20000U << EXTI_SWIER_SWIERx_Pos) 

/**
  * @brief EXTI_PR Register Bit Definition
  */
#define  EXTI_PR_PRx_Pos                          (0)
#define  EXTI_PR_PRx_Msk                          (0x3FFFFU << EXTI_PR_PRx_Pos)                     /*!<Line x trigger pending bit*/
#define  EXTI_PR_PRx                              EXTI_PR_PRx_Msk
#define  EXTI_PR_PRx_0                            (0x00001U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_1                            (0x00002U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_2                            (0x00004U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_3                            (0x00008U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_4                            (0x00010U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_5                            (0x00020U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_6                            (0x00040U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_7                            (0x00080U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_8                            (0x00100U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_9                            (0x00200U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_10                           (0x00400U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_11                           (0x00800U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_12                           (0x01000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_13                           (0x02000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_14                           (0x04000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_15                           (0x08000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_16                           (0x10000U << EXTI_PR_PRx_Pos) 
#define  EXTI_PR_PRx_17                           (0x20000U << EXTI_PR_PRx_Pos) 

/** ------------------------------------------------------------------------------------------------------------------*/
#endif
/** ------------------------------------------------------------------------------------------------------------------*/
