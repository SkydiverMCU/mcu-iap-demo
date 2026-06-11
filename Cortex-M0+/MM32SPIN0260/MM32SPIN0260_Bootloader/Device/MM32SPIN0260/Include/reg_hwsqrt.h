/***********************************************************************************************************************
    @file     reg_hwsqrt.h
    @author   FD TEAM
    @brief    This flie contains all the HWSQRT's register and its field definition.
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

#ifndef __REG_HWSQRT_H
#define __REG_HWSQRT_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief HWSQRT Base Address Definition
  */
#define  HWSQRT_BASE                               0x40030400                                       /*!<Base Address: 0x40030400*/

/**
  * @brief HWSQRT Register Structure Definition
  */
typedef struct
{
    __IO uint32_t SQR;                            /*!<HWSQRT The prescribed data register            offset: 0x00       */
    __IO uint32_t RDR;                            /*!<HWSQRT Square root data register               offset: 0x04       */
} HWSQRT_TypeDef;

/**
  * @brief HWSQRT type pointer Definition
  */
#define HWSQRT                                    ((HWSQRT_TypeDef *)HWSQRT_BASE)

/**
  * @brief HWSQRT_SQR Register Bit Definition
  */
#define  HWSQRT_SQR_SQUARE_Pos                    (0)
#define  HWSQRT_SQR_SQUARE_Msk                    (0xFFFFFFFFU << HWSQRT_SQR_SQUARE_Pos)            /*!<Square data*/
#define  HWSQRT_SQR_SQUARE                        HWSQRT_SQR_SQUARE_Msk
#define  HWSQRT_SQR_SQUARE_Bit0                   (0x00000001U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit1                   (0x00000002U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit2                   (0x00000004U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit3                   (0x00000008U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit4                   (0x00000010U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit5                   (0x00000020U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit6                   (0x00000040U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit7                   (0x00000080U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit8                   (0x00000100U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit9                   (0x00000200U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit10                  (0x00000400U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit11                  (0x00000800U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit12                  (0x00001000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit13                  (0x00002000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit14                  (0x00004000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit15                  (0x00008000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit16                  (0x00010000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit17                  (0x00020000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit18                  (0x00040000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit19                  (0x00080000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit20                  (0x00100000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit21                  (0x00200000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit22                  (0x00400000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit23                  (0x00800000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit24                  (0x01000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit25                  (0x02000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit26                  (0x04000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit27                  (0x08000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit28                  (0x10000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit29                  (0x20000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit30                  (0x40000000U << HWSQRT_SQR_SQUARE_Pos) 
#define  HWSQRT_SQR_SQUARE_Bit31                  (0x80000000U << HWSQRT_SQR_SQUARE_Pos) 

/**
  * @brief HWSQRT_RDR Register Bit Definition
  */
#define  HWSQRT_RDR_ROOT_Pos                      (0)
#define  HWSQRT_RDR_ROOT_Msk                      (0xFFFFU << HWSQRT_RDR_ROOT_Pos)                  /*!<Root data*/
#define  HWSQRT_RDR_ROOT                          HWSQRT_RDR_ROOT_Msk
#define  HWSQRT_RDR_ROOT_Bit0                     (0x0001U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit1                     (0x0002U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit2                     (0x0004U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit3                     (0x0008U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit4                     (0x0010U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit5                     (0x0020U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit6                     (0x0040U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit7                     (0x0080U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit8                     (0x0100U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit9                     (0x0200U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit10                    (0x0400U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit11                    (0x0800U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit12                    (0x1000U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit13                    (0x2000U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit14                    (0x4000U << HWSQRT_RDR_ROOT_Pos) 
#define  HWSQRT_RDR_ROOT_Bit15                    (0x8000U << HWSQRT_RDR_ROOT_Pos) 


#endif

