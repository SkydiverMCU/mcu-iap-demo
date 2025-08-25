/***********************************************************************************************************************
    @file     reg_cordic.h
    @author   VV TEAM
    @brief    This flie contains all the CORDIC's register and its field definition.
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

#ifndef __REG_CORDIC_H
#define __REG_CORDIC_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief CORDIC Base Address Definition
  */
#define  CORDIC_BASE                               0x4002A000                                       /*!<Base Address: 0x4002A000*/

/**
  * @brief CORDIC Register Structure Definition
  */
typedef struct
{
    __IO uint32_t DX;                             /*!<CORDIC CORDIC X Data Register                  offset: 0x00       */
    __IO uint32_t DY;                             /*!<CORDIC CORDIC Y Data Register                  offset: 0x04       */
    __IO uint32_t DZ;                             /*!<CORDIC CORDIC Z Data Register                  offset: 0x08       */
    __IO uint32_t RX;                             /*!<CORDIC CORDIC X Result Register                offset: 0x0C       */
    __IO uint32_t RY;                             /*!<CORDIC CORDIC Y Result Register                offset: 0x10       */
    __IO uint32_t RZ;                             /*!<CORDIC CORDIC Z Result Register                offset: 0x14       */
    __IO uint32_t CTRL;                           /*!<CORDIC CORDIC Control Register                 offset: 0x18       */
    __IO uint32_t STAT;                           /*!<CORDIC CORDIC Status Register                  offset: 0x1C       */
} CORDIC_TypeDef;

/**
  * @brief CORDIC type pointer Definition
  */
#define CORDIC                                    ((CORDIC_TypeDef *)CORDIC_BASE)

/**
  * @brief CORDIC_DX Register Bit Definition
  */
#define  CORDIC_DX_CORDIC_DX_Pos                  (0)
#define  CORDIC_DX_CORDIC_DX_Msk                  (0xFFFFFFU << CORDIC_DX_CORDIC_DX_Pos)            /*!<Initial X parameter data (initial X data value within the full range [-2^23, 2^23 -1])*/
#define  CORDIC_DX_CORDIC_DX                      CORDIC_DX_CORDIC_DX_Msk
#define  CORDIC_DX_CORDIC_DX_Bit0                 (0x000001U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit1                 (0x000002U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit2                 (0x000004U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit3                 (0x000008U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit4                 (0x000010U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit5                 (0x000020U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit6                 (0x000040U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit7                 (0x000080U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit8                 (0x000100U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit9                 (0x000200U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit10                (0x000400U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit11                (0x000800U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit12                (0x001000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit13                (0x002000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit14                (0x004000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit15                (0x008000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit16                (0x010000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit17                (0x020000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit18                (0x040000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit19                (0x080000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit20                (0x100000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit21                (0x200000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit22                (0x400000U << CORDIC_DX_CORDIC_DX_Pos) 
#define  CORDIC_DX_CORDIC_DX_Bit23                (0x800000U << CORDIC_DX_CORDIC_DX_Pos) 

/**
  * @brief CORDIC_DY Register Bit Definition
  */
#define  CORDIC_DY_CORDIC_DY_Pos                  (0)
#define  CORDIC_DY_CORDIC_DY_Msk                  (0xFFFFFFU << CORDIC_DY_CORDIC_DY_Pos)            /*!<Initial Y parameter data (initial Y data value within the full range [-2^23, 2^23 -1])*/
#define  CORDIC_DY_CORDIC_DY                      CORDIC_DY_CORDIC_DY_Msk
#define  CORDIC_DY_CORDIC_DY_Bit0                 (0x000001U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit1                 (0x000002U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit2                 (0x000004U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit3                 (0x000008U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit4                 (0x000010U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit5                 (0x000020U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit6                 (0x000040U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit7                 (0x000080U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit8                 (0x000100U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit9                 (0x000200U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit10                (0x000400U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit11                (0x000800U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit12                (0x001000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit13                (0x002000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit14                (0x004000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit15                (0x008000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit16                (0x010000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit17                (0x020000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit18                (0x040000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit19                (0x080000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit20                (0x100000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit21                (0x200000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit22                (0x400000U << CORDIC_DY_CORDIC_DY_Pos) 
#define  CORDIC_DY_CORDIC_DY_Bit23                (0x800000U << CORDIC_DY_CORDIC_DY_Pos) 

/**
  * @brief CORDIC_DZ Register Bit Definition
  */
#define  CORDIC_DZ_CORDIC_DZ_Pos                  (0)
#define  CORDIC_DZ_CORDIC_DZ_Msk                  (0xFFFFFFU << CORDIC_DZ_CORDIC_DZ_Pos)            /*!<Initial Z parameter data (initial Z data value within the full range [-2^23, 2^23 -1])*/
#define  CORDIC_DZ_CORDIC_DZ                      CORDIC_DZ_CORDIC_DZ_Msk
#define  CORDIC_DZ_CORDIC_DZ_Bit0                 (0x000001U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit1                 (0x000002U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit2                 (0x000004U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit3                 (0x000008U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit4                 (0x000010U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit5                 (0x000020U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit6                 (0x000040U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit7                 (0x000080U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit8                 (0x000100U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit9                 (0x000200U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit10                (0x000400U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit11                (0x000800U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit12                (0x001000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit13                (0x002000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit14                (0x004000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit15                (0x008000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit16                (0x010000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit17                (0x020000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit18                (0x040000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit19                (0x080000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit20                (0x100000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit21                (0x200000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit22                (0x400000U << CORDIC_DZ_CORDIC_DZ_Pos) 
#define  CORDIC_DZ_CORDIC_DZ_Bit23                (0x800000U << CORDIC_DZ_CORDIC_DZ_Pos) 

/**
  * @brief CORDIC_RX Register Bit Definition
  */
#define  CORDIC_RX_CORDIC_RX_Pos                  (0)
#define  CORDIC_RX_CORDIC_RX_Msk                  (0x1FFFFFFU << CORDIC_RX_CORDIC_RX_Pos)           /*!<X calculation result (cos calculation result)*/
#define  CORDIC_RX_CORDIC_RX                      CORDIC_RX_CORDIC_RX_Msk
#define  CORDIC_RX_CORDIC_RX_Bit0                 (0x0000001U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit1                 (0x0000002U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit2                 (0x0000004U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit3                 (0x0000008U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit4                 (0x0000010U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit5                 (0x0000020U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit6                 (0x0000040U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit7                 (0x0000080U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit8                 (0x0000100U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit9                 (0x0000200U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit10                (0x0000400U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit11                (0x0000800U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit12                (0x0001000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit13                (0x0002000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit14                (0x0004000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit15                (0x0008000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit16                (0x0010000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit17                (0x0020000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit18                (0x0040000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit19                (0x0080000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit20                (0x0100000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit21                (0x0200000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit22                (0x0400000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit23                (0x0800000U << CORDIC_RX_CORDIC_RX_Pos) 
#define  CORDIC_RX_CORDIC_RX_Bit24                (0x1000000U << CORDIC_RX_CORDIC_RX_Pos) 

/**
  * @brief CORDIC_RY Register Bit Definition
  */
#define  CORDIC_RY_CORDIC_RY_Pos                  (0)
#define  CORDIC_RY_CORDIC_RY_Msk                  (0x1FFFFFFU << CORDIC_RY_CORDIC_RY_Pos)           /*!<Y calculation result (sin calculation result)*/
#define  CORDIC_RY_CORDIC_RY                      CORDIC_RY_CORDIC_RY_Msk
#define  CORDIC_RY_CORDIC_RY_Bit0                 (0x0000001U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit1                 (0x0000002U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit2                 (0x0000004U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit3                 (0x0000008U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit4                 (0x0000010U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit5                 (0x0000020U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit6                 (0x0000040U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit7                 (0x0000080U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit8                 (0x0000100U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit9                 (0x0000200U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit10                (0x0000400U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit11                (0x0000800U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit12                (0x0001000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit13                (0x0002000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit14                (0x0004000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit15                (0x0008000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit16                (0x0010000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit17                (0x0020000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit18                (0x0040000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit19                (0x0080000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit20                (0x0100000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit21                (0x0200000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit22                (0x0400000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit23                (0x0800000U << CORDIC_RY_CORDIC_RY_Pos) 
#define  CORDIC_RY_CORDIC_RY_Bit24                (0x1000000U << CORDIC_RY_CORDIC_RY_Pos) 

/**
  * @brief CORDIC_RZ Register Bit Definition
  */
#define  CORDIC_RZ_CORDIC_RZ_Pos                  (0)
#define  CORDIC_RZ_CORDIC_RZ_Msk                  (0xFFFFFFU << CORDIC_RZ_CORDIC_RZ_Pos)            /*!<Z calculation result (atan angle calculation result)*/
#define  CORDIC_RZ_CORDIC_RZ                      CORDIC_RZ_CORDIC_RZ_Msk
#define  CORDIC_RZ_CORDIC_RZ_Bit0                 (0x000001U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit1                 (0x000002U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit2                 (0x000004U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit3                 (0x000008U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit4                 (0x000010U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit5                 (0x000020U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit6                 (0x000040U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit7                 (0x000080U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit8                 (0x000100U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit9                 (0x000200U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit10                (0x000400U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit11                (0x000800U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit12                (0x001000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit13                (0x002000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit14                (0x004000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit15                (0x008000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit16                (0x010000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit17                (0x020000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit18                (0x040000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit19                (0x080000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit20                (0x100000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit21                (0x200000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit22                (0x400000U << CORDIC_RZ_CORDIC_RZ_Pos) 
#define  CORDIC_RZ_CORDIC_RZ_Bit23                (0x800000U << CORDIC_RZ_CORDIC_RZ_Pos) 

/**
  * @brief CORDIC_CTRL Register Bit Definition
  */
#define  CORDIC_CTRL_START_Pos                    (0)
#define  CORDIC_CTRL_START_Msk                    (0x1U << CORDIC_CTRL_START_Pos)                   /*!<This register bit is valid when STARTMODE is set to '1'. At that time, it can be taken as one calculation when '1' is written and BSY bit is '0'. The hardware is auto cleared after completing the calculation.*/
#define  CORDIC_CTRL_START                        CORDIC_CTRL_START_Msk
#define  CORDIC_CTRL_WORK_MODE_Pos                (1)
#define  CORDIC_CTRL_WORK_MODE_Msk                (0x1U << CORDIC_CTRL_WORK_MODE_Pos)               /*!<Work mode selection for CORDIC calculation 0: Circle vector mode*/
#define  CORDIC_CTRL_WORK_MODE                    CORDIC_CTRL_WORK_MODE_Msk
#define  CORDIC_CTRL_START_MODE_Pos               (2)
#define  CORDIC_CTRL_START_MODE_Msk               (0x1U << CORDIC_CTRL_START_MODE_Pos)              /*!<Start mode selection 0: Calculation is started after the CORDIC_DX register's write operation is performed*/
#define  CORDIC_CTRL_START_MODE                   CORDIC_CTRL_START_MODE_Msk
#define  CORDIC_CTRL_ENABLE_Pos                   (3)
#define  CORDIC_CTRL_ENABLE_Msk                   (0x1U << CORDIC_CTRL_ENABLE_Pos)                  /*!<Module enable*/
#define  CORDIC_CTRL_ENABLE                       CORDIC_CTRL_ENABLE_Msk

/**
  * @brief CORDIC_STAT Register Bit Definition
  */
#define  CORDIC_STAT_BSY_Pos                      (0)
#define  CORDIC_STAT_BSY_Msk                      (0x1U << CORDIC_STAT_BSY_Pos)                     /*!<When this bit is '1', it means that the calculation is in progress. It is auto cleared by hardware after calculation is completed.*/
#define  CORDIC_STAT_BSY                          CORDIC_STAT_BSY_Msk


#endif

