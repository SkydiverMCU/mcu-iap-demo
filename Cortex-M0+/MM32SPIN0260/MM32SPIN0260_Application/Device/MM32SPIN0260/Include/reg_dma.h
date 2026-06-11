/***********************************************************************************************************************
    @file     reg_dma.h
    @author   FD TEAM
    @brief    This flie contains all the DMA's register and its field definition.
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

#ifndef __REG_DMA_H
#define __REG_DMA_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_cm0plus.h"



/**
  * @brief DMA Base Address Definition
  */
#define  DMA_BASE                                  0x40020000                                       /*!<Base Address: 0x40020000*/
#define  DMA_Channel1_BASE                         (DMA_BASE     + 0x0008U)                         /*!<Base Address: (DMA_BASE     + 0x0008U)*/
#define  DMA_Channel2_BASE                         (DMA_BASE     + 0x001CU)                         /*!<Base Address: (DMA_BASE     + 0x001CU)*/
#define  DMA_Channel3_BASE                         (DMA_BASE     + 0x0030U)                         /*!<Base Address: (DMA_BASE     + 0x0030U)*/

/**
  * @brief DMA Register Structure Definition
  */
typedef struct
{
    __IO uint32_t ISR;                            /*!<DMA DMA interrupt status register              offset: 0x00       */
    __IO uint32_t IFCR;                           /*!<DMA DMA interrupt flag clear register          offset: 0x04       */
} DMA_TypeDef;

/**
  * @brief DMA_Channel Register Structure Definition
  */
typedef struct
{
    __IO uint32_t CCR;                            /*!<DMA DMA channel x configuration register       offset: 0x00       */
    __IO uint32_t CNDTR;                          /*!<DMA DMA channel x number of data register      offset: 0x04       */
    __IO uint32_t CPAR;                           /*!<DMA DMA channel x peripheral address register  offset: 0x08       */
    __IO uint32_t CMAR;                           /*!<DMA DMA channel x memory address register      offset: 0x0C       */
} DMA_Channel_TypeDef;

/**
  * @brief DMA type pointer Definition
  */
#define DMA                                       ((DMA_TypeDef *)DMA_BASE)
#define DMA_Channel1                              ((DMA_Channel_TypeDef *)DMA_Channel1_BASE)
#define DMA_Channel2                              ((DMA_Channel_TypeDef *)DMA_Channel2_BASE)
#define DMA_Channel3                              ((DMA_Channel_TypeDef *)DMA_Channel3_BASE)

/**
  * @brief DMA_ISR Register Bit Definition
  */
#define  DMA_ISR_GIF1_Pos                         (0)
#define  DMA_ISR_GIF1_Msk                         (0x1U << DMA_ISR_GIF1_Pos)                        /*!<Channel 1 global interrupt flag*/
#define  DMA_ISR_GIF1                             DMA_ISR_GIF1_Msk
#define  DMA_ISR_TCIF1_Pos                        (1)
#define  DMA_ISR_TCIF1_Msk                        (0x1U << DMA_ISR_TCIF1_Pos)                       /*!<Channel 1 transfer complete flag*/
#define  DMA_ISR_TCIF1                            DMA_ISR_TCIF1_Msk
#define  DMA_ISR_HTIF1_Pos                        (2)
#define  DMA_ISR_HTIF1_Msk                        (0x1U << DMA_ISR_HTIF1_Pos)                       /*!<Channel 1 half transfer flag*/
#define  DMA_ISR_HTIF1                            DMA_ISR_HTIF1_Msk
#define  DMA_ISR_TEIF1_Pos                        (3)
#define  DMA_ISR_TEIF1_Msk                        (0x1U << DMA_ISR_TEIF1_Pos)                       /*!<Channel 1 transfer error flag*/
#define  DMA_ISR_TEIF1                            DMA_ISR_TEIF1_Msk
#define  DMA_ISR_GIF2_Pos                         (4)
#define  DMA_ISR_GIF2_Msk                         (0x1U << DMA_ISR_GIF2_Pos)                        /*!<Channel 2 global interrupt flag*/
#define  DMA_ISR_GIF2                             DMA_ISR_GIF2_Msk
#define  DMA_ISR_TCIF2_Pos                        (5)
#define  DMA_ISR_TCIF2_Msk                        (0x1U << DMA_ISR_TCIF2_Pos)                       /*!<Channel 2 transfer complete flag*/
#define  DMA_ISR_TCIF2                            DMA_ISR_TCIF2_Msk
#define  DMA_ISR_HTIF2_Pos                        (6)
#define  DMA_ISR_HTIF2_Msk                        (0x1U << DMA_ISR_HTIF2_Pos)                       /*!<Channel 2 half transfer flag*/
#define  DMA_ISR_HTIF2                            DMA_ISR_HTIF2_Msk
#define  DMA_ISR_TEIF2_Pos                        (7)
#define  DMA_ISR_TEIF2_Msk                        (0x1U << DMA_ISR_TEIF2_Pos)                       /*!<Channel 2 transfer error flag*/
#define  DMA_ISR_TEIF2                            DMA_ISR_TEIF2_Msk
#define  DMA_ISR_GIF3_Pos                         (8)
#define  DMA_ISR_GIF3_Msk                         (0x1U << DMA_ISR_GIF3_Pos)                        /*!<Channel 3 global interrupt flag*/
#define  DMA_ISR_GIF3                             DMA_ISR_GIF3_Msk
#define  DMA_ISR_TCIF3_Pos                        (9)
#define  DMA_ISR_TCIF3_Msk                        (0x1U << DMA_ISR_TCIF3_Pos)                       /*!<Channel 3 transfer complete flag*/
#define  DMA_ISR_TCIF3                            DMA_ISR_TCIF3_Msk
#define  DMA_ISR_HTIF3_Pos                        (10)
#define  DMA_ISR_HTIF3_Msk                        (0x1U << DMA_ISR_HTIF3_Pos)                       /*!<Channel 3 half transfer flag*/
#define  DMA_ISR_HTIF3                            DMA_ISR_HTIF3_Msk
#define  DMA_ISR_TEIF3_Pos                        (11)
#define  DMA_ISR_TEIF3_Msk                        (0x1U << DMA_ISR_TEIF3_Pos)                       /*!<Channel 3 transfer error flag*/
#define  DMA_ISR_TEIF3                            DMA_ISR_TEIF3_Msk

/**
  * @brief DMA_IFCR Register Bit Definition
  */
#define  DMA_IFCR_CGIF1_Pos                       (0)
#define  DMA_IFCR_CGIF1_Msk                       (0x1U << DMA_IFCR_CGIF1_Pos)                      /*!<Channel 1 global interrupt clear*/
#define  DMA_IFCR_CGIF1                           DMA_IFCR_CGIF1_Msk
#define  DMA_IFCR_CTCIF1_Pos                      (1)
#define  DMA_IFCR_CTCIF1_Msk                      (0x1U << DMA_IFCR_CTCIF1_Pos)                     /*!<Channel 1 transfer complete clear*/
#define  DMA_IFCR_CTCIF1                          DMA_IFCR_CTCIF1_Msk
#define  DMA_IFCR_CHTIF1_Pos                      (2)
#define  DMA_IFCR_CHTIF1_Msk                      (0x1U << DMA_IFCR_CHTIF1_Pos)                     /*!<Channel 1 half transfer clear*/
#define  DMA_IFCR_CHTIF1                          DMA_IFCR_CHTIF1_Msk
#define  DMA_IFCR_CTEIF1_Pos                      (3)
#define  DMA_IFCR_CTEIF1_Msk                      (0x1U << DMA_IFCR_CTEIF1_Pos)                     /*!<Channel 1 transfer error clear*/
#define  DMA_IFCR_CTEIF1                          DMA_IFCR_CTEIF1_Msk
#define  DMA_IFCR_CGIF2_Pos                       (4)
#define  DMA_IFCR_CGIF2_Msk                       (0x1U << DMA_IFCR_CGIF2_Pos)                      /*!<Channel 2 global interrupt clear*/
#define  DMA_IFCR_CGIF2                           DMA_IFCR_CGIF2_Msk
#define  DMA_IFCR_CTCIF2_Pos                      (5)
#define  DMA_IFCR_CTCIF2_Msk                      (0x1U << DMA_IFCR_CTCIF2_Pos)                     /*!<Channel 2 transfer complete clear*/
#define  DMA_IFCR_CTCIF2                          DMA_IFCR_CTCIF2_Msk
#define  DMA_IFCR_CHTIF2_Pos                      (6)
#define  DMA_IFCR_CHTIF2_Msk                      (0x1U << DMA_IFCR_CHTIF2_Pos)                     /*!<Channel 2 half transfer clear*/
#define  DMA_IFCR_CHTIF2                          DMA_IFCR_CHTIF2_Msk
#define  DMA_IFCR_CTEIF2_Pos                      (7)
#define  DMA_IFCR_CTEIF2_Msk                      (0x1U << DMA_IFCR_CTEIF2_Pos)                     /*!<Channel 2 transfer error clear*/
#define  DMA_IFCR_CTEIF2                          DMA_IFCR_CTEIF2_Msk
#define  DMA_IFCR_CGIF3_Pos                       (8)
#define  DMA_IFCR_CGIF3_Msk                       (0x1U << DMA_IFCR_CGIF3_Pos)                      /*!<Channel 3 global interrupt clear*/
#define  DMA_IFCR_CGIF3                           DMA_IFCR_CGIF3_Msk
#define  DMA_IFCR_CTCIF3_Pos                      (9)
#define  DMA_IFCR_CTCIF3_Msk                      (0x1U << DMA_IFCR_CTCIF3_Pos)                     /*!<Channel 3 transfer complete clear*/
#define  DMA_IFCR_CTCIF3                          DMA_IFCR_CTCIF3_Msk
#define  DMA_IFCR_CHTIF3_Pos                      (10)
#define  DMA_IFCR_CHTIF3_Msk                      (0x1U << DMA_IFCR_CHTIF3_Pos)                     /*!<Channel 3 half transfer clear*/
#define  DMA_IFCR_CHTIF3                          DMA_IFCR_CHTIF3_Msk
#define  DMA_IFCR_CTEIF3_Pos                      (11)
#define  DMA_IFCR_CTEIF3_Msk                      (0x1U << DMA_IFCR_CTEIF3_Pos)                     /*!<Channel 3 transfer error clear*/
#define  DMA_IFCR_CTEIF3                          DMA_IFCR_CTEIF3_Msk

/**
  * @brief DMA_CCR Register Bit Definition
  */
#define  DMA_CCR_EN_Pos                           (0)
#define  DMA_CCR_EN_Msk                           (0x1U << DMA_CCR_EN_Pos)                          /*!<Channel enable*/
#define  DMA_CCR_EN                               DMA_CCR_EN_Msk
#define  DMA_CCR_TCIE_Pos                         (1)
#define  DMA_CCR_TCIE_Msk                         (0x1U << DMA_CCR_TCIE_Pos)                        /*!<Transfer complete interrupt enable*/
#define  DMA_CCR_TCIE                             DMA_CCR_TCIE_Msk
#define  DMA_CCR_HTIE_Pos                         (2)
#define  DMA_CCR_HTIE_Msk                         (0x1U << DMA_CCR_HTIE_Pos)                        /*!<Half transfer interrupt enable*/
#define  DMA_CCR_HTIE                             DMA_CCR_HTIE_Msk
#define  DMA_CCR_TEIE_Pos                         (3)
#define  DMA_CCR_TEIE_Msk                         (0x1U << DMA_CCR_TEIE_Pos)                        /*!<Transfer error interrupt enable*/
#define  DMA_CCR_TEIE                             DMA_CCR_TEIE_Msk
#define  DMA_CCR_DIR_Pos                          (4)
#define  DMA_CCR_DIR_Msk                          (0x1U << DMA_CCR_DIR_Pos)                         /*!<Data transfer direction*/
#define  DMA_CCR_DIR                              DMA_CCR_DIR_Msk
#define  DMA_CCR_CIRC_Pos                         (5)
#define  DMA_CCR_CIRC_Msk                         (0x1U << DMA_CCR_CIRC_Pos)                        /*!<Circular mode*/
#define  DMA_CCR_CIRC                             DMA_CCR_CIRC_Msk
#define  DMA_CCR_PINC_Pos                         (6)
#define  DMA_CCR_PINC_Msk                         (0x1U << DMA_CCR_PINC_Pos)                        /*!<Peripheral increment mode*/
#define  DMA_CCR_PINC                             DMA_CCR_PINC_Msk
#define  DMA_CCR_MINC_Pos                         (7)
#define  DMA_CCR_MINC_Msk                         (0x1U << DMA_CCR_MINC_Pos)                        /*!<Memory increment mode*/
#define  DMA_CCR_MINC                             DMA_CCR_MINC_Msk
#define  DMA_CCR_PSIZE_Pos                        (8)
#define  DMA_CCR_PSIZE_Msk                        (0x3U << DMA_CCR_PSIZE_Pos)                       /*!<Peripheral size*/
#define  DMA_CCR_PSIZE                            DMA_CCR_PSIZE_Msk
#define  DMA_CCR_PSIZE_Bit0                       (0x1U << DMA_CCR_PSIZE_Pos) 
#define  DMA_CCR_PSIZE_Bit1                       (0x2U << DMA_CCR_PSIZE_Pos) 
#define  DMA_CCR_MSIZE_Pos                        (10)
#define  DMA_CCR_MSIZE_Msk                        (0x3U << DMA_CCR_MSIZE_Pos)                       /*!<Memory size*/
#define  DMA_CCR_MSIZE                            DMA_CCR_MSIZE_Msk
#define  DMA_CCR_MSIZE_Bit0                       (0x1U << DMA_CCR_MSIZE_Pos) 
#define  DMA_CCR_MSIZE_Bit1                       (0x2U << DMA_CCR_MSIZE_Pos) 
#define  DMA_CCR_PL_Pos                           (12)
#define  DMA_CCR_PL_Msk                           (0x3U << DMA_CCR_PL_Pos)                          /*!<Channel priority level*/
#define  DMA_CCR_PL                               DMA_CCR_PL_Msk
#define  DMA_CCR_PL_Bit0                          (0x1U << DMA_CCR_PL_Pos) 
#define  DMA_CCR_PL_Bit1                          (0x2U << DMA_CCR_PL_Pos) 
#define  DMA_CCR_MEM2MEM_Pos                      (14)
#define  DMA_CCR_MEM2MEM_Msk                      (0x1U << DMA_CCR_MEM2MEM_Pos)                     /*!<Memory to memory mode*/
#define  DMA_CCR_MEM2MEM                          DMA_CCR_MEM2MEM_Msk
#define  DMA_CCR_ARE_Pos                          (15)
#define  DMA_CCR_ARE_Msk                          (0x1U << DMA_CCR_ARE_Pos)                         /*!<Auto reload*/
#define  DMA_CCR_ARE                              DMA_CCR_ARE_Msk

/**
  * @brief DMA_CNDTR Register Bit Definition
  */
#define  DMA_CNDTR_NDT_Pos                        (0)
#define  DMA_CNDTR_NDT_Msk                        (0xFFFFU << DMA_CNDTR_NDT_Pos)                    /*!<Number of data to transfer*/
#define  DMA_CNDTR_NDT                            DMA_CNDTR_NDT_Msk
#define  DMA_CNDTR_NDT_Bit0                       (0x0001U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit1                       (0x0002U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit2                       (0x0004U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit3                       (0x0008U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit4                       (0x0010U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit5                       (0x0020U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit6                       (0x0040U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit7                       (0x0080U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit8                       (0x0100U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit9                       (0x0200U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit10                      (0x0400U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit11                      (0x0800U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit12                      (0x1000U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit13                      (0x2000U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit14                      (0x4000U << DMA_CNDTR_NDT_Pos) 
#define  DMA_CNDTR_NDT_Bit15                      (0x8000U << DMA_CNDTR_NDT_Pos) 

/**
  * @brief DMA_CPAR Register Bit Definition
  */
#define  DMA_CPAR_PA_Pos                          (0)
#define  DMA_CPAR_PA_Msk                          (0xFFFFFFFFU << DMA_CPAR_PA_Pos)                  /*!<Peripheral address*/
#define  DMA_CPAR_PA                              DMA_CPAR_PA_Msk
#define  DMA_CPAR_PA_Bit0                         (0x00000001U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit1                         (0x00000002U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit2                         (0x00000004U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit3                         (0x00000008U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit4                         (0x00000010U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit5                         (0x00000020U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit6                         (0x00000040U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit7                         (0x00000080U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit8                         (0x00000100U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit9                         (0x00000200U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit10                        (0x00000400U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit11                        (0x00000800U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit12                        (0x00001000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit13                        (0x00002000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit14                        (0x00004000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit15                        (0x00008000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit16                        (0x00010000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit17                        (0x00020000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit18                        (0x00040000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit19                        (0x00080000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit20                        (0x00100000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit21                        (0x00200000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit22                        (0x00400000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit23                        (0x00800000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit24                        (0x01000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit25                        (0x02000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit26                        (0x04000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit27                        (0x08000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit28                        (0x10000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit29                        (0x20000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit30                        (0x40000000U << DMA_CPAR_PA_Pos) 
#define  DMA_CPAR_PA_Bit31                        (0x80000000U << DMA_CPAR_PA_Pos) 

/**
  * @brief DMA_CMAR Register Bit Definition
  */
#define  DMA_CMAR_MA_Pos                          (0)
#define  DMA_CMAR_MA_Msk                          (0xFFFFFFFFU << DMA_CMAR_MA_Pos)                  /*!<Memory address*/
#define  DMA_CMAR_MA                              DMA_CMAR_MA_Msk
#define  DMA_CMAR_MA_Bit0                         (0x00000001U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit1                         (0x00000002U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit2                         (0x00000004U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit3                         (0x00000008U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit4                         (0x00000010U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit5                         (0x00000020U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit6                         (0x00000040U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit7                         (0x00000080U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit8                         (0x00000100U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit9                         (0x00000200U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit10                        (0x00000400U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit11                        (0x00000800U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit12                        (0x00001000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit13                        (0x00002000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit14                        (0x00004000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit15                        (0x00008000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit16                        (0x00010000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit17                        (0x00020000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit18                        (0x00040000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit19                        (0x00080000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit20                        (0x00100000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit21                        (0x00200000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit22                        (0x00400000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit23                        (0x00800000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit24                        (0x01000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit25                        (0x02000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit26                        (0x04000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit27                        (0x08000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit28                        (0x10000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit29                        (0x20000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit30                        (0x40000000U << DMA_CMAR_MA_Pos) 
#define  DMA_CMAR_MA_Bit31                        (0x80000000U << DMA_CMAR_MA_Pos) 


#endif

