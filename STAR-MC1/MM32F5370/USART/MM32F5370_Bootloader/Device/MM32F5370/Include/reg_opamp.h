/***********************************************************************************************************************
    @file     reg_opamp.h
    @author   VV TEAM
    @brief    This flie contains all the OPAMP's register and its field definition.
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

#ifndef __REG_OPAMP_H
#define __REG_OPAMP_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief OPAMP Base Address Definition
  */
#define  OPAMP_BASE                                0x40010200                                       /*!<Base Address: 0x40010200*/

/**
  * @brief OPAMP Register Structure Definition
  */
typedef struct
{
    __IO uint32_t OPA1CR;                         /*!<                                               offset: 0x00       */
    __IO uint32_t OPA1CHSR;                       /*!<                                               offset: 0x04       */
    __IO uint32_t RESERVED0x08[2];                /*!<                                               offset: 0x08~0x0C  */
    __IO uint32_t OPA2CR;                         /*!<                                               offset: 0x10       */
    __IO uint32_t OPA2CHSR;                       /*!<                                               offset: 0x14       */
    __IO uint32_t RESERVED0x18[2];                /*!<                                               offset: 0x18~0x1C  */
    __IO uint32_t OPA3CR;                         /*!<                                               offset: 0x20       */
    __IO uint32_t OPA3CHSR;                       /*!<                                               offset: 0x24       */
    __IO uint32_t RESERVED0x28[2];                /*!<                                               offset: 0x28~0x2C  */
    __IO uint32_t OPA4CR;                         /*!<                                               offset: 0x30       */
    __IO uint32_t OPA4CHSR;                       /*!<                                               offset: 0x34       */
} OPAMP_TypeDef;

/**
  * @brief OPAMP type pointer Definition
  */
#define OPAMP                                     ((OPAMP_TypeDef *)OPAMP_BASE)

/**
  * @brief OPAMP_OPACR Register Bit Definition
  */
#define  OPAMP_OPACR_OPAEN_Pos                    (0)
#define  OPAMP_OPACR_OPAEN_Msk                    (0x1U << OPAMP_OPACR_OPAEN_Pos)                   /*!<*/
#define  OPAMP_OPACR_OPAEN                        OPAMP_OPACR_OPAEN_Msk
#define  OPAMP_OPACR_FLTEN_Pos                    (6)
#define  OPAMP_OPACR_FLTEN_Msk                    (0x1U << OPAMP_OPACR_FLTEN_Pos)                   /*!<*/
#define  OPAMP_OPACR_FLTEN                        OPAMP_OPACR_FLTEN_Msk
#define  OPAMP_OPACR_DPMUXSEL_Pos                 (12)
#define  OPAMP_OPACR_DPMUXSEL_Msk                 (0x1U << OPAMP_OPACR_DPMUXSEL_Pos)                /*!<*/
#define  OPAMP_OPACR_DPMUXSEL                     OPAMP_OPACR_DPMUXSEL_Msk
#define  OPAMP_OPACR_DMMUXSEL_Pos                 (14)
#define  OPAMP_OPACR_DMMUXSEL_Msk                 (0x3U << OPAMP_OPACR_DMMUXSEL_Pos)                /*!<*/
#define  OPAMP_OPACR_DMMUXSEL                     OPAMP_OPACR_DMMUXSEL_Msk
#define  OPAMP_OPACR_DMMUXSEL_Bit0                (0x1U << OPAMP_OPACR_DMMUXSEL_Pos) 
#define  OPAMP_OPACR_DMMUXSEL_Bit1                (0x2U << OPAMP_OPACR_DMMUXSEL_Pos) 
#define  OPAMP_OPACR_GAIN_Pos                     (16)
#define  OPAMP_OPACR_GAIN_Msk                     (0x7U << OPAMP_OPACR_GAIN_Pos)                    /*!<*/
#define  OPAMP_OPACR_GAIN                         OPAMP_OPACR_GAIN_Msk
#define  OPAMP_OPACR_GAIN_Bit0                    (0x1U << OPAMP_OPACR_GAIN_Pos) 
#define  OPAMP_OPACR_GAIN_Bit1                    (0x2U << OPAMP_OPACR_GAIN_Pos) 
#define  OPAMP_OPACR_GAIN_Bit2                    (0x4U << OPAMP_OPACR_GAIN_Pos) 
#define  OPAMP_OPACR_TIMCSEN_Pos                  (24)
#define  OPAMP_OPACR_TIMCSEN_Msk                  (0x3U << OPAMP_OPACR_TIMCSEN_Pos)                 /*!<*/
#define  OPAMP_OPACR_TIMCSEN                      OPAMP_OPACR_TIMCSEN_Msk
#define  OPAMP_OPACR_TIMCSEN_Bit0                 (0x1U << OPAMP_OPACR_TIMCSEN_Pos) 
#define  OPAMP_OPACR_TIMCSEN_Bit1                 (0x2U << OPAMP_OPACR_TIMCSEN_Pos) 
#define  OPAMP_OPACR_TIMCSEG_Pos                  (28)
#define  OPAMP_OPACR_TIMCSEG_Msk                  (0x1U << OPAMP_OPACR_TIMCSEG_Pos)                 /*!<*/
#define  OPAMP_OPACR_TIMCSEG                      OPAMP_OPACR_TIMCSEG_Msk

/**
  * @brief OPAMP_OPACHSR Register Bit Definition
  */
#define  OPAMP_OPACHSR_PSEL_Pos                   (0)
#define  OPAMP_OPACHSR_PSEL_Msk                   (0x7U << OPAMP_OPACHSR_PSEL_Pos)                  /*!<*/
#define  OPAMP_OPACHSR_PSEL                       OPAMP_OPACHSR_PSEL_Msk
#define  OPAMP_OPACHSR_PSEL_Bit0                  (0x1U << OPAMP_OPACHSR_PSEL_Pos) 
#define  OPAMP_OPACHSR_PSEL_Bit1                  (0x2U << OPAMP_OPACHSR_PSEL_Pos) 
#define  OPAMP_OPACHSR_PSEL_Bit2                  (0x4U << OPAMP_OPACHSR_PSEL_Pos) 
#define  OPAMP_OPACHSR_MSEL_Pos                   (8)
#define  OPAMP_OPACHSR_MSEL_Msk                   (0x7U << OPAMP_OPACHSR_MSEL_Pos)                  /*!<*/
#define  OPAMP_OPACHSR_MSEL                       OPAMP_OPACHSR_MSEL_Msk
#define  OPAMP_OPACHSR_MSEL_Bit0                  (0x1U << OPAMP_OPACHSR_MSEL_Pos) 
#define  OPAMP_OPACHSR_MSEL_Bit1                  (0x2U << OPAMP_OPACHSR_MSEL_Pos) 
#define  OPAMP_OPACHSR_MSEL_Bit2                  (0x4U << OPAMP_OPACHSR_MSEL_Pos) 
#define  OPAMP_OPACHSR_PSSEL_Pos                  (16)
#define  OPAMP_OPACHSR_PSSEL_Msk                  (0x7U << OPAMP_OPACHSR_PSSEL_Pos)                 /*!<*/
#define  OPAMP_OPACHSR_PSSEL                      OPAMP_OPACHSR_PSSEL_Msk
#define  OPAMP_OPACHSR_PSSEL_Bit0                 (0x1U << OPAMP_OPACHSR_PSSEL_Pos) 
#define  OPAMP_OPACHSR_PSSEL_Bit1                 (0x2U << OPAMP_OPACHSR_PSSEL_Pos) 
#define  OPAMP_OPACHSR_PSSEL_Bit2                 (0x4U << OPAMP_OPACHSR_PSSEL_Pos) 
#define  OPAMP_OPACHSR_MSSEL_Pos                  (24)
#define  OPAMP_OPACHSR_MSSEL_Msk                  (0x7U << OPAMP_OPACHSR_MSSEL_Pos)                 /*!<*/
#define  OPAMP_OPACHSR_MSSEL                      OPAMP_OPACHSR_MSSEL_Msk
#define  OPAMP_OPACHSR_MSSEL_Bit0                 (0x1U << OPAMP_OPACHSR_MSSEL_Pos) 
#define  OPAMP_OPACHSR_MSSEL_Bit1                 (0x2U << OPAMP_OPACHSR_MSSEL_Pos) 
#define  OPAMP_OPACHSR_MSSEL_Bit2                 (0x4U << OPAMP_OPACHSR_MSSEL_Pos) 


#endif

