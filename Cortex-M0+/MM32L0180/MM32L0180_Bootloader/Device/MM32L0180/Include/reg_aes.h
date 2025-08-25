/***********************************************************************************************************************
    @file     reg_aes.h
    @author   VV TEAM
    @brief    This flie contains all the AES's register and its field definition.
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

#ifndef __REG_AES_H
#define __REG_AES_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include <core_cm0plus.h>



/**
  * @brief AES Base Address Definition
  */
#define  AES_BASE                                  0x40015C00                                       /*!<Base Address: 0x40015C00*/

/**
  * @brief AES Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CNTRL;                          /*!<AES AES control register                       offset: 0x00       */
    __IO uint32_t STATUS;                         /*!<AES AES status register                        offset: 0x04       */
    __IO uint32_t DATA;                           /*!<AES AES data register                          offset: 0x08       */
} AES_TypeDef;

/**
  * @brief AES type pointer Definition
  */
#define AES                                       ((AES_TypeDef *)AES_BASE)

/**
  * @brief AES_CNTRL Register Bit Definition
  */
#define  AES_CNTRL_START_Pos                      (0)
#define  AES_CNTRL_START_Msk                      (0x1U << AES_CNTRL_START_Pos)                     /*!<enable START interrupt*/
#define  AES_CNTRL_START                          AES_CNTRL_START_Msk
#define  AES_CNTRL_ENCRYPT_Pos                    (1)
#define  AES_CNTRL_ENCRYPT_Msk                    (0x1U << AES_CNTRL_ENCRYPT_Pos)                   /*!<enable ENCRYPT interrupt*/
#define  AES_CNTRL_ENCRYPT                        AES_CNTRL_ENCRYPT_Msk
#define  AES_CNTRL_KEY_MODE_Pos                   (2)
#define  AES_CNTRL_KEY_MODE_Msk                   (0x1U << AES_CNTRL_KEY_MODE_Pos)                  /*!<enable KEY_MODE interrupt*/
#define  AES_CNTRL_KEY_MODE                       AES_CNTRL_KEY_MODE_Msk
#define  AES_CNTRL_MODE_Pos                       (3)
#define  AES_CNTRL_MODE_Msk                       (0x1U << AES_CNTRL_MODE_Pos)                      /*!<enable MODE interrupt*/
#define  AES_CNTRL_MODE                           AES_CNTRL_MODE_Msk
#define  AES_CNTRL_KEY256_Pos                     (4)
#define  AES_CNTRL_KEY256_Msk                     (0x1U << AES_CNTRL_KEY256_Pos)                    /*!<enable KEY256 interrupt*/
#define  AES_CNTRL_KEY256                         AES_CNTRL_KEY256_Msk
#define  AES_CNTRL_KEY_SEL_Pos                    (5)
#define  AES_CNTRL_KEY_SEL_Msk                    (0x1U << AES_CNTRL_KEY_SEL_Pos)                   /*!<enable KEY_SEL interrupt*/
#define  AES_CNTRL_KEY_SEL                        AES_CNTRL_KEY_SEL_Msk
#define  AES_CNTRL_IV_SEL_Pos                     (6)
#define  AES_CNTRL_IV_SEL_Msk                     (0x1U << AES_CNTRL_IV_SEL_Pos)                    /*!<enable IV_SEL interrupt*/
#define  AES_CNTRL_IV_SEL                         AES_CNTRL_IV_SEL_Msk
#define  AES_CNTRL_LASTBLOCK_Pos                  (7)
#define  AES_CNTRL_LASTBLOCK_Msk                  (0x1U << AES_CNTRL_LASTBLOCK_Pos)                 /*!<enable LASTBLOCK interrupt*/
#define  AES_CNTRL_LASTBLOCK                      AES_CNTRL_LASTBLOCK_Msk
#define  AES_CNTRL_DMA_EN_Pos                     (8)
#define  AES_CNTRL_DMA_EN_Msk                     (0x1U << AES_CNTRL_DMA_EN_Pos)                    /*!<enable DMA_EN interrupt*/
#define  AES_CNTRL_DMA_EN                         AES_CNTRL_DMA_EN_Msk
#define  AES_CNTRL_DOUT_INT_EN_Pos                (9)
#define  AES_CNTRL_DOUT_INT_EN_Msk                (0x1U << AES_CNTRL_DOUT_INT_EN_Pos)               /*!<enable DOUT_INT_EN interrupt*/
#define  AES_CNTRL_DOUT_INT_EN                    AES_CNTRL_DOUT_INT_EN_Msk
#define  AES_CNTRL_DIN_INT_EN_Pos                 (10)
#define  AES_CNTRL_DIN_INT_EN_Msk                 (0x1U << AES_CNTRL_DIN_INT_EN_Pos)                /*!<enable DIN_INT interrupt*/
#define  AES_CNTRL_DIN_INT_EN                     AES_CNTRL_DIN_INT_EN_Msk

/**
  * @brief AES_STATUS Register Bit Definition
  */
#define  AES_STATUS_DOUT_INT_Pos                  (0)
#define  AES_STATUS_DOUT_INT_Msk                  (0x1U << AES_STATUS_DOUT_INT_Pos)                 /*!<output data request*/
#define  AES_STATUS_DOUT_INT                      AES_STATUS_DOUT_INT_Msk
#define  AES_STATUS_DIN_INT_Pos                   (1)
#define  AES_STATUS_DIN_INT_Msk                   (0x1U << AES_STATUS_DIN_INT_Pos)                  /*!<input data request*/
#define  AES_STATUS_DIN_INT                       AES_STATUS_DIN_INT_Msk
#define  AES_STATUS_OPT_RDY_Pos                   (4)
#define  AES_STATUS_OPT_RDY_Msk                   (0x1U << AES_STATUS_OPT_RDY_Pos)                  /*!<*/
#define  AES_STATUS_OPT_RDY                       AES_STATUS_OPT_RDY_Msk

/**
  * @brief AES_DATA Register Bit Definition
  */
#define  AES_DATA_AES_DATA_Pos                    (0)
#define  AES_DATA_AES_DATA_Msk                    (0xFFFFFFFFU << AES_DATA_AES_DATA_Pos)            /*!<AES data register*/
#define  AES_DATA_AES_DATA                        AES_DATA_AES_DATA_Msk
#define  AES_DATA_AES_DATA_0                      (0x00000001U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_1                      (0x00000002U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_2                      (0x00000004U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_3                      (0x00000008U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_4                      (0x00000010U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_5                      (0x00000020U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_6                      (0x00000040U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_7                      (0x00000080U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_8                      (0x00000100U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_9                      (0x00000200U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_10                     (0x00000400U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_11                     (0x00000800U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_12                     (0x00001000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_13                     (0x00002000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_14                     (0x00004000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_15                     (0x00008000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_16                     (0x00010000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_17                     (0x00020000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_18                     (0x00040000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_19                     (0x00080000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_20                     (0x00100000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_21                     (0x00200000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_22                     (0x00400000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_23                     (0x00800000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_24                     (0x01000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_25                     (0x02000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_26                     (0x04000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_27                     (0x08000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_28                     (0x10000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_29                     (0x20000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_30                     (0x40000000U << AES_DATA_AES_DATA_Pos) 
#define  AES_DATA_AES_DATA_31                     (0x80000000U << AES_DATA_AES_DATA_Pos) 

#endif

