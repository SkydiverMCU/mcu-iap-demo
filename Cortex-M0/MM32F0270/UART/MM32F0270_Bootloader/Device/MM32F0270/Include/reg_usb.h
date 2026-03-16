////////////////////////////////////////////////////////////////////////////////
/// @file     reg_usb.h
/// @author   AE TEAM
/// @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
///           MM32 FIRMWARE LIBRARY.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion

#ifndef __REG_USB_H
#define __REG_USB_H

// Files includes

#include <stdint.h>
#include <stdbool.h>
#include "types.h"


#if defined ( __CC_ARM )
#pragma anon_unions
#endif


////////////////////////////////////////////////////////////////////////////////
/// @brief USB Base Address Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_BASE                        (APB1PERIPH_BASE + 0x5C00)              ///< Base Address: 0x40005C00


////////////////////////////////////////////////////////////////////////////////
/// @brief USB Register Structure Definition
////////////////////////////////////////////////////////////////////////////////
typedef struct 
{
    __IO uint32_t TOP;                                                               ///< Top Register                                   offset: 0x00
    __IO uint32_t INT_STATE;                                                         ///< Interrupt State Register                       offset: 0x04
    __IO uint32_t EP_INT_STATE;                                                      ///< Endpoint Interrupt State Register              offset: 0x08
    __IO uint32_t EP0_INT_STATE;                                                     ///< EP0 Interrupt State Register                   offset: 0x0C
    __IO uint32_t INT_EN;                                                            ///< Interrupt Enable Register                      offset: 0x10
    __IO uint32_t EP_INT_EN;                                                         ///< Endpoint Interrupt Enable Register             offset: 0x14
    __IO uint32_t EP0_INT_EN;                                                        ///< EP0 Interrupt Enable Register                  offset: 0x18

    __IO uint32_t RESERVED0;                                                         ///< Reserved                                       offset: 0x1C

    __IO uint32_t EPx_INT_STATE[4];                                                  ///< EP1 2 3 4 Interrupt State Register                   offset: 0x20

    __IO uint32_t RESERVED1[4];                                                      ///< Reserved                                       offset: 0x30

    __IO uint32_t EPx_INT_EN[4];                                                     ///< EP1 2 3 4 Interrupt Enable Register                  offset: 0x40

    __IO uint32_t RESERVED5[4];                                                      ///< Reserved                                       offset: 0x50

    __IO uint32_t ADDR;                                                              ///< USB Address Register                           offset: 0x60
    __IO uint32_t EP_EN;                                                             ///< Endpoint Enable Register                       offset: 0x64
    __IO uint32_t EP_DMA_DIR;                                                        ///< Endpoint DMA direction Register                offset: 0x68
    __IO uint32_t EP_TYPE;                                                           ///< Endpoint type Register                         offset: 0x6C
    __IO uint32_t EP_INDEX1_2;                                                       ///< Endpoint index Register                        offset: 0x70
    __IO uint32_t EP_INDEX3_4;                                                       ///< Endpoint index Register                        offset: 0x74

    __IO uint32_t TOG_CTRL1_4;                                                       ///< Toggle Control Register                        offset: 0x78

    __IO uint32_t TOG_STAT1_4;                                                       ///< Toggle status Register                         offset: 0x7C

    __IO uint32_t SETUPx[8];                                                         ///< SETUP Packet Byte 0 Register                   offset: 0x80
    __IO uint32_t PACKET_SIZEL;                                                      ///< Packet SIZE Register                           offset: 0xA0
    __IO uint32_t PACKET_SIZEH;                                                      ///< Packet SIZE Register                           offset: 0xA4

    __IO uint32_t RESERVED14[22];                                                    ///< Reserved                                       offset: 0xA8

    __IO uint32_t EPx_AVAIL[5];                                                      ///< EP0 1 2 3 4 Available Data Register                    offset: 0x100

    __IO uint32_t RESERVED36[3];                                                    ///< Reserved                                       offset: 0x114
    __IO uint32_t DMA_ADDR0;                                                        ///< USB endpoint 2 DMA address 0 register          offset: 0x120
    __IO uint32_t DMA_ADDR1;                                                        ///< USB endpoint 2 DMA address 1 register          offset: 0x124
    __IO uint32_t DMA_ADDR2;                                                        ///< USB endpoint 2 DMA address 2 register          offset: 0x128
    __IO uint32_t DMA_ADDR3;                                                        ///< USB endpoint 2 DMA address 3 register          offset: 0x12C
    __IO uint32_t DMA_NUML;                                                         ///< DMA data  Register                            offset: 0x130
    __IO uint32_t DMA_NUMH;                                                         ///< DMA data  Register                            offset: 0x134
    
    __IO uint32_t RESERVED138[2]; 
    
    __IO uint32_t EPx_CTRL[5];                                                       ///< EP0 1 2 3 4 5 Control Register                           offset: 0x140

    __IO uint32_t RESERVED47[3];                                                     ///< Reserved                                       offset: 0x154

    __IO uint32_t EPx_FIFO[5];                                                       ///< EP0 1 2 3 4 FIFO Register                              offset: 0x160

    __IO uint32_t RESERVED50[3];                                                     ///< Reserved                                       offset: 0x174
    __IO uint32_t EP_MEM;                                                            ///<  EP data Register                               offset: 0x180
    __IO uint32_t EP_DMA;                                                            ///<  EP DMA Enable Register                         offset: 0x184
    __IO uint32_t EP_HALT;                                                           ///< EP Halt Register                               offset: 0x188

    __IO uint32_t RESERVED54[13];                                                    ///< Reserved                                       offset: 0x18C

    __IO uint32_t POWER;                                                             ///< Power Register                                 offset: 0x1C0
    __IO uint32_t AHB_DMA;                                                           ///< AHB_DMA Register                               offset: 0x1C4
    __IO uint32_t AHB_RST;                                                           ///< AHB rest Register                              offset: 0x1C8

} USB_TypeDef;

////////////////////////////////////////////////////////////////////////////////
/// @brief USBD type pointer Definition
////////////////////////////////////////////////////////////////////////////////
#define USB                             ((USB_TypeDef*) USB_BASE )



////////////////////////////////////////////////////////////////////////////////
/// @brief USB_TOP Register Bit Definition
////////////////////////////////////////////////////////////////////////////////

#define USB_TOP_SPEED_Pos               (0)
#define USB_TOP_SPEED                   (0x01U << USB_TOP_SPEED_Pos)            ///< USB Speed
#define USB_TOP_CONNECT_Pos             (1)
#define USB_TOP_CONNECT                 (0x01U << USB_TOP_CONNECT_Pos)          ///< USB connection
#define USB_TOP_RESET_Pos               (3)
#define USB_TOP_RESET                   (0x01U << USB_TOP_RESET_Pos)            ///< Reset EP and FIFO in USB controller
#define USB_TOP_SUSPEND_Pos             (4)
#define USB_TOP_SUSPEND                 (0x01U << USB_TOP_SUSPEND_Pos)          ///< USB suspend state
#define USB_TOP_STATE_Pos               (5)
#define USB_TOP_STATE                   (0x03U << USB_TOP_STATE_Pos)            ///< Current USB DP/DM line state
#define USB_TOP_ACTIVE_Pos              (7)
#define USB_TOP_ACTIVE                  (0x01U << USB_TOP_ACTIVE_Pos)           ///< USB bus is active

////////////////////////////////////////////////////////////////////////////////
/// @brief USB_INT_STATE Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_INT_STATE_RSTF_Pos          (0)
#define USB_INT_STATE_RSTF              (0x01U << USB_INT_STATE_RSTF_Pos)       ///< BUS reset received
#define USB_INT_STATE_SUSPENDF_Pos      (1)
#define USB_INT_STATE_SUSPENDF          (0x01U << USB_INT_STATE_SUSPENDF_Pos)   ///< BUS suspend received
#define USB_INT_STATE_RESUMF_Pos        (2)
#define USB_INT_STATE_RESUMF            (0x01U << USB_INT_STATE_RESUMF_Pos)     ///< BUS resume received
#define USB_INT_STATE_SOFF_Pos          (3)
#define USB_INT_STATE_SOFF              (0x01U << USB_INT_STATE_SOFF_Pos)       ///< BUS SOF received
#define USB_INT_STATE_EPINTF_Pos        (4)
#define USB_INT_STATE_EPINTF            (0x01U << USB_INT_STATE_EPINTF_Pos)     ///< EP interrupt received

////////////////////////////////////////////////////////////////////////////////
/// @brief EP_INT_STATE Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_INT_STATE_EP0F_Pos           (0)
#define EP_INT_STATE_EP0F               (0x01U << EP_INT_STATE_EP0F_Pos)        ///< EP0 interrupt received
#define EP_INT_STATE_EP1F_Pos           (1)
#define EP_INT_STATE_EP1F               (0x01U << EP_INT_STATE_EP1F_Pos)        ///< EP1 interrupt received
#define EP_INT_STATE_EP2F_Pos           (2)
#define EP_INT_STATE_EP2F               (0x01U << EP_INT_STATE_EP2F_Pos)        ///< EP2 interrupt received
#define EP_INT_STATE_EP3F_Pos           (3)
#define EP_INT_STATE_EP3F               (0x01U << EP_INT_STATE_EP3F_Pos)        ///< EP3 interrupt received
#define EP_INT_STATE_EP4F_Pos           (4)
#define EP_INT_STATE_EP4F               (0x01U << EP_INT_STATE_EP4F_Pos)        ///< EP4 interrupt received

////////////////////////////////////////////////////////////////////////////////
/// @brief EPn_INT_STATE Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EPn_INT_STATE_SETUP_Pos         (0)
#define EPn_INT_STATE_SETUP             (0x01U << EPn_INT_STATE_SETUP_Pos)      ///< SETUP packet received
#define EPn_INT_STATE_END_Pos           (1)
#define EPn_INT_STATE_END               (0x01U << EPn_INT_STATE_END_Pos)        ///< Status stage finished
#define EPn_INT_STATE_INNACK_Pos        (2)
#define EPn_INT_STATE_INNACK            (0x01U << EPn_INT_STATE_INNACK_Pos)     ///< IN-NACK received
#define EPn_INT_STATE_INACK_Pos         (3)
#define EPn_INT_STATE_INACK             (0x01U << EPn_INT_STATE_INACK_Pos)      ///< IN-ACK received
#define EPn_INT_STATE_INSTALL_Pos       (4)
#define EPn_INT_STATE_INSTALL           (0x01U << EPn_INT_STATE_INSTALL_Pos)    ///< IN-STALL received
#define EPn_INT_STATE_OUTNACK_Pos       (5)
#define EPn_INT_STATE_OUTNACK           (0x01U << EPn_INT_STATE_OUTNACK_Pos)    ///< OUT-NACK received
#define EPn_INT_STATE_OUTACK_Pos        (6)
#define EPn_INT_STATE_OUTACK            (0x01U << EPn_INT_STATE_OUTACK_Pos)     ///< OUT-ACK received
#define EPn_INT_STATE_OUTSTALL_Pos      (7)
#define EPn_INT_STATE_OUTSTALL          (0x01U << EPn_INT_STATE_OUTSTALL_Pos)   ///< OUT-STALL received

////////////////////////////////////////////////////////////////////////////////
/// @brief USB_INT_EN Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_INT_EN_RSTIE_Pos            (0)
#define USB_INT_EN_RSTIE                (0x01U << USB_INT_EN_RSTIE_Pos)         ///< BUS reset interrupt enable
#define USB_INT_EN_SUSPENDIE_Pos        (1)
#define USB_INT_EN_SUSPENDIE            (0x01U << USB_INT_EN_SUSPENDIE_Pos)     ///< BUS suspend interrupt enable
#define USB_INT_EN_RESUMIE_Pos          (2)
#define USB_INT_EN_RESUMIE              (0x01U << USB_INT_EN_RESUMIE_Pos)       ///< BUS resume interrupt enable
#define USB_INT_EN_SOFIE_Pos            (3)
#define USB_INT_EN_SOFIE                (0x01U << USB_INT_EN_SOFIE_Pos)         ///< SOF interrupt enable
#define USB_INT_EN_EPIE_Pos             (4)
#define USB_INT_EN_EPIE                 (0x01U << USB_INT_EN_EPIE_Pos)          ///< EP interrupt enable
#define USB_INT_EN_INTMASK_Pos          (7)
#define USB_INT_EN_INTMASK              (0x01U << USB_INT_EN_INTMASK_Pos)       ///< interrupt mask
#define USB_INT_EN_EPINTIE              USB_INT_EN_EPIE

////////////////////////////////////////////////////////////////////////////////
/// @brief EP_INT_EN Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_INT_EN_EP0IE_Pos             (0)
#define EP_INT_EN_EP0IE                 (0x01U << EP_INT_EN_EP0IE_Pos)          ///< EP0 interrupt enable
#define EP_INT_EN_EP1IE_Pos             (1)
#define EP_INT_EN_EP1IE                 (0x01U << EP_INT_EN_EP1IE_Pos)          ///< EP1 interrupt enable
#define EP_INT_EN_EP2IE_Pos             (2)
#define EP_INT_EN_EP2IE                 (0x01U << EP_INT_EN_EP2IE_Pos)          ///< EP2 interrupt enable
#define EP_INT_EN_EP3IE_Pos             (3)
#define EP_INT_EN_EP3IE                 (0x01U << EP_INT_EN_EP3IE_Pos)          ///< EP3 interrupt enable
#define EP_INT_EN_EP4IE_Pos             (4)
#define EP_INT_EN_EP4IE                 (0x01U << EP_INT_EN_EP4IE_Pos)          ///< EP4 interrupt enable

////////////////////////////////////////////////////////////////////////////////
/// @brief EPn_INT_EN Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EPn_INT_EN_SETUPIE_Pos          (0)
#define EPn_INT_EN_SETUPIE              (0x01U << EPn_INT_EN_SETUPIE_Pos)       ///< SETUP packet interrupt enable
#define EPn_INT_EN_ENDIE_Pos            (1)
#define EPn_INT_EN_ENDIE                (0x01U << EPn_INT_EN_ENDIE_Pos)         ///< Status stage finished interrupt enable
#define EPn_INT_EN_INNACKIE_Pos         (2)
#define EPn_INT_EN_INNACKIE             (0x01U << EPn_INT_EN_INNACKIE_Pos)      ///< IN-NACK interrupt enable
#define EPn_INT_EN_INACKIE_Pos          (3)
#define EPn_INT_EN_INACKIE              (0x01U << EPn_INT_EN_INACKIE_Pos)       ///< IN-ACK interrupt enable
#define EPn_INT_EN_INSTALLIE_Pos        (4)
#define EPn_INT_EN_INSTALLIE            (0x01U << EPn_INT_EN_INSTALLIE_Pos)     ///< IN-STALL interrupt enable
#define EPn_INT_EN_OUTNACKIE_Pos        (5)
#define EPn_INT_EN_OUTNACKIE            (0x01U << EPn_INT_EN_OUTNACKIE_Pos)     ///< OUT-NACK interrupt enable
#define EPn_INT_EN_OUTACKIE_Pos         (6)
#define EPn_INT_EN_OUTACKIE             (0x01U << EPn_INT_EN_OUTACKIE_Pos)      ///< OUT-ACK interrupt enable
#define EPn_INT_EN_OUTSTALLIE_Pos       (7)
#define EPn_INT_EN_OUTSTALLIE           (0x01U << EPn_INT_EN_OUTSTALLIE_Pos)    ///< OUT-STALL interrupt enable


////////////////////////////////////////////////////////////////////////////////
/// @brief USB_ADDR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_ADDR_ADDR_Pos               (0)
#define USB_ADDR_ADDR                   (0x7FU << USB_ADDR_ADDR_Pos)            ///< USB address

////////////////////////////////////////////////////////////////////////////////
/// @brief EP_EN Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_EN_EP0EN_Pos                 (0)
#define EP_EN_EP0EN                     (0x01U << EP_EN_EP0EN_Pos)              ///< Enable EP0
#define EP_EN_EP1EN_Pos                 (1)
#define EP_EN_EP1EN                     (0x01U << EP_EN_EP1EN_Pos)              ///< Enable EP1
#define EP_EN_EP2EN_Pos                 (2)
#define EP_EN_EP2EN                     (0x01U << EP_EN_EP2EN_Pos)              ///< Enable EP2
#define EP_EN_EP3EN_Pos                 (3)
#define EP_EN_EP3EN                     (0x01U << EP_EN_EP3EN_Pos)              ///< Enable EP3
#define EP_EN_EP4EN_Pos                 (4)
#define EP_EN_EP4EN                     (0x01U << EP_EN_EP4EN_Pos)              ///< Enable EP4

////////////////////////////////////////////////////////////////////////////////
/// @brief EP_DMA_DIR Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_DMA_DIR1_Pos                 (0)
#define EP_DMA_DIR1                     (0x01U << EP_DMA_DIR1_Pos)              ///< Point 1 Dma Direction
#define EP_DMA_DIR2_Pos                 (1)
#define EP_DMA_DIR2                     (0x01U << EP_DMA_DIR2_Pos)              ///< Point 2 Dma Direction
#define EP_DMA_DIR3_Pos                 (2)
#define EP_DMA_DIR3                     (0x01U << EP_DMA_DIR3_Pos)              ///< Point 3 Dma Direction
#define EP_DMA_DIR4_Pos                 (3)
#define EP_DMA_DIR4                     (0x01U << EP_DMA_DIR4_Pos)              ///< Point 4 Dma Direction
////////////////////////////////////////////////////////////////////////////////
/// @brief EP_TYPE Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_TYPE1_Pos                    (0)
#define EP_TYPE1                        (0x01U << EP_TYPE1_Pos)                 ///< Point 1 type
#define EP_TYPE2_Pos                    (1)
#define EP_TYPE2                        (0x01U << EP_TYPE2_Pos)                 ///< Point 2 type
#define EP_TYPE3_Pos                    (2)
#define EP_TYPE3                        (0x01U << EP_TYPE3_Pos)                 ///< Point 3 type
#define EP_TYPE4_Pos                    (3)
#define EP_TYPE4                        (0x01U << EP_TYPE4_Pos)                 ///< Point 4 type


////////////////////////////////////////////////////////////////////////////////
/// @brief EP_INDEX1_2 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_INDEX1_Pos                   (0)
#define EP_INDEX1                       (0x0FU << EP_INDEX1_Pos)              ///< Point 1 index
#define EP_INDEX2_Pos                   (4)
#define EP_INDEX2                       (0x0FU << EP_INDEX2_Pos)              ///< Point 2 index
////////////////////////////////////////////////////////////////////////////////
/// @brief EP_INDEX3_4 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_INDEX3_Pos                   (0)
#define EP_INDEX3                       (0x0FU << EP_INDEX3_Pos)              ///< Point 3 index
#define EP_INDEX4_Pos                   (4)
#define EP_INDEX4                       (0x0FU << EP_INDEX4_Pos)              ///< Point 4 index

////////////////////////////////////////////////////////////////////////////////
/// @brief TOG_CTRL1_4 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define TOG_CTRL1_4_DTOG1_Pos           (0)
#define TOG_CTRL1_4_DTOG1               (0x01U << TOG_CTRL1_4_DTOG1_Pos)        ///< Set EP1 Toggle
#define TOG_CTRL1_4_DTOG1EN_Pos         (1)
#define TOG_CTRL1_4_DTOG1EN             (0x01U << TOG_CTRL1_4_DTOG1EN_Pos)      ///< Set EP1  Data Toggle Enable
#define TOG_CTRL1_4_DTOG2_Pos           (2)
#define TOG_CTRL1_4_DTOG2               (0x01U << TOG_CTRL1_4_DTOG2_Pos)        ///< Set EP2 Toggle
#define TOG_CTRL1_4_DTOG2EN_Pos         (3)
#define TOG_CTRL1_4_DTOG2EN             (0x01U << TOG_CTRL1_4_DTOG2EN_Pos)      ///< Set EP2  Data Toggle Enable
#define TOG_CTRL1_4_DTOG3_Pos           (4)
#define TOG_CTRL1_4_DTOG3               (0x01U << TOG_CTRL1_4_DTOG3_Pos)        ///< Set EP3 Toggle
#define TOG_CTRL1_4_DTOG3EN_Pos         (5)
#define TOG_CTRL1_4_DTOG3EN             (0x01U << TOG_CTRL1_4_DTOG3EN_Pos)      ///< Set EP3  Data Toggle Enable
#define TOG_CTRL1_4_DTOG4_Pos           (6)
#define TOG_CTRL1_4_DTOG4               (0x01U << TOG_CTRL1_4_DTOG4_Pos)        ///< Set EP4 Toggle
#define TOG_CTRL1_4_DTOG4EN_Pos         (7)
#define TOG_CTRL1_4_DTOG4EN             (0x01U << TOG_CTRL1_4_DTOG4EN_Pos)      ///< Set EP4  Data Toggle Enable
////////////////////////////////////////////////////////////////////////////////
/// @brief TOG_STAT1_4 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define TOG_STAT1_4_DTOG1_Pos           (0)
#define TOG_STAT1_4_DTOG1               (0x01U << TOG_STAT1_4_DTOG1_Pos)        ///< End Point 1 IN Toggle State
#define TOG_STAT1_4_DTOG1EN_Pos         (1)
#define TOG_STAT1_4_DTOG1EN             (0x01U << TOG_STAT1_4_DTOG1EN_Pos)      ///< End Point 1 OUT Toggle State
#define TOG_STAT1_4_DTOG2_Pos           (2)
#define TOG_STAT1_4_DTOG2               (0x01U << TOG_STAT1_4_DTOG2_Pos)        ///< End Point 2 IN Toggle State
#define TOG_STAT1_4_DTOG2EN_Pos         (3)
#define TOG_STAT1_4_DTOG2EN             (0x01U << TOG_STAT1_4_DTOG2EN_Pos)      ///< End Point 2 OUT Toggle State
#define TOG_STAT1_4_DTOG3_Pos           (4)
#define TOG_STAT1_4_DTOG3               (0x01U << TOG_STAT1_4_DTOG3_Pos)        ///< End Point 3 IN Toggle State
#define TOG_STAT1_4_DTOG3EN_Pos         (5)
#define TOG_STAT1_4_DTOG3EN             (0x01U << TOG_STAT1_4_DTOG3EN_Pos)      ///< End Point 3 OUT Toggle State
#define TOG_STAT1_4_DTOG4_Pos           (6)
#define TOG_STAT1_4_DTOG4               (0x01U << TOG_STAT1_4_DTOG4_Pos)        ///< End Point 4 IN Toggle State
#define TOG_STAT1_4_DTOG4EN_Pos         (7)
#define TOG_STAT1_4_DTOG4EN             (0x01U << TOG_STAT1_4_DTOG4EN_Pos)      ///< End Point 4 OUT Toggle State

////////////////////////////////////////////////////////////////////////////////
/// @brief SETUPn Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define SETUPn_Pos                      (0)
#define SETUPn                          (0xFFU << SETUPn_Pos)                   ///< Setup Data X
////////////////////////////////////////////////////////////////////////////////
/// @brief PACKET_SIZEL Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define PACKET_SIZEL_Pos                (0)
#define PACKET_SIZEL_Msk                (0xFFU << PACKET_SIZEL_Pos)                   ///< USB DMA Max Packet Size
////////////////////////////////////////////////////////////////////////////////
/// @brief PACKET_SIZEH Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define PACKET_SIZEH_Pos                (0)
#define PACKET_SIZEH_Msk                (0xFFU << PACKET_SIZEH_Pos)                   ///< USB DMA Max Packet Size

////////////////////////////////////////////////////////////////////////////////
/// @brief EPn_AVIL Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EPn_AVIL_EPXAVIL_Pos            (0)
#define EPn_AVIL_EPXAVIL                (0xFFU << EPn_AVIL_EPXAVIL_Pos)         ///< EPX FIFO available data number
////////////////////////////////////////////////////////////////////////////////
/// @brief DMA_ADDR0 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define DMA_ADDR0_Pos                   (0)
#define DMA_ADDR0                       (0xFFU << DMA_ADDR0_Pos)                ///< USB endpoint 2DMA endpoint transfer address
////////////////////////////////////////////////////////////////////////////////
/// @brief DMA_ADDR1 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define DMA_ADDR1_Pos                   (0)
#define DMA_ADDR1                       (0xFFU << DMA_ADDR1_Pos)                ///< USB endpoint 2DMA endpoint transfer address
////////////////////////////////////////////////////////////////////////////////
/// @brief DMA_ADDR2 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define DMA_ADDR2_Pos                   (0)
#define DMA_ADDR2                       (0xFFU << DMA_ADDR2_Pos)                ///< USB endpoint 2DMA endpoint transfer address
////////////////////////////////////////////////////////////////////////////////
/// @brief DMA_ADDR3 Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define DMA_ADDR3_Pos                   (0)
#define DMA_ADDR3                       (0xFFU << DMA_ADDR3_Pos)                ///< USB endpoint 2DMA endpoint transfer address

////////////////////////////////////////////////////////////////////////////////
/// @brief DMA_NUML Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define DMA_NUML_Pos                    (0)
#define DMA_NUML_Msk                    (0xFFU << DMA_NUML_Pos)                ///< EP2 DMA numbe(0-7)
////////////////////////////////////////////////////////////////////////////////
/// @brief DMA_NUMH Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define DMA_NUMH_Pos                   (0)
#define DMA_NUMH_Msk                   (0xFFU << DMA_NUMH_Pos)                ///< EP2 DMA numbe(8-15)

////////////////////////////////////////////////////////////////////////////////
/// @brief EPn_CTRL Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EPn_CTRL_TRANCOUNT_Pos          (0)
#define EPn_CTRL_TRANCOUNT              (0x7FU << EPn_CTRL_TRANCOUNT_Pos)       ///< EPX transfer counter
#define EPn_CTRL_TRANEN_Pos             (7)
#define EPn_CTRL_TRANEN                 (0x01U << EPn_CTRL_TRANEN_Pos)          ///< EPX transfer enable

////////////////////////////////////////////////////////////////////////////////
/// @brief EPn_FIFO Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EPn_FIFO_EPn_FIFO_Pos           (0)
#define EPn_FIFO_EPn_FIFO               (0xFFU << EPn_FIFO_EPn_FIFO_Pos)        ///< EPX FIFO port
////////////////////////////////////////////////////////////////////////////////
/// @brief EP_MEM Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_MEM_FIFO_Pos                 (0)
#define EP_MEM_FIFO_0                   (0x00U << EP_MEM_FIFO_Pos)                  ///< EP0 Data storage address
#define EP_MEM_FIFO_1                   (0x01U << EP_MEM_FIFO_Pos)                  ///< EP1 Data storage address
#define EP_MEM_FIFO_2                   (0x02U << EP_MEM_FIFO_Pos)                  ///< EP2 Data storage address
#define EP_MEM_FIFO_3                   (0x03U << EP_MEM_FIFO_Pos)                  ///< EP3 Data storage address
#define EP_MEM_FIFO_4                   (0x04U << EP_MEM_FIFO_Pos)                  ///< EP4 Data storage address
////////////////////////////////////////////////////////////////////////////////
/// @brief EP_DMA Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_DMA0EN_Pos                   (0)
#define EP_DMA0EN                       (0x01U << EP_DMA0EN_Pos)                ///< EP0 DMA enable
#define EP_DMA1EN_Pos                   (1)
#define EP_DMA1EN                       (0x01U << EP_DMA1EN_Pos)                ///< EP1 DMA enable
#define EP_DMA2EN_Pos                   (2)
#define EP_DMA2EN                       (0x01U << EP_DMA2EN_Pos)                ///< EP2 DMA enable
#define EP_DMA3EN_Pos                   (3)
#define EP_DMA3EN                       (0x01U << EP_DMA3EN_Pos)                ///< EP3 DMA enable
#define EP_DMA4EN_Pos                   (4)
#define EP_DMA4EN                       (0x01U << EP_DMA4EN_Pos)                ///< EP4 DMA enable
////////////////////////////////////////////////////////////////////////////////
/// @brief EP_HALT Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define EP_HALT_HALT0_Pos               (0)
#define EP_HALT_HALT0                   (0x01U << EP_HALT_HALT0_Pos)            ///< EP0 halt
#define EP_HALT_HALT1_Pos               (1)
#define EP_HALT_HALT1                   (0x01U << EP_HALT_HALT1_Pos)            ///< EP1 halt
#define EP_HALT_HALT2_Pos               (2)
#define EP_HALT_HALT2                   (0x01U << EP_HALT_HALT2_Pos)            ///< EP2 halt
#define EP_HALT_HALT3_Pos               (3)
#define EP_HALT_HALT3                   (0x01U << EP_HALT_HALT3_Pos)            //< EP3 halt
#define EP_HALT_HALT4_Pos               (4)
#define EP_HALT_HALT4                   (0x01U << EP_HALT_HALT4_Pos)            ///< EP4 halt

////////////////////////////////////////////////////////////////////////////////
/// @brief USB_POWER Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_POWER_SUSPEN_Pos            (0)
#define USB_POWER_SUSPEN                (0x01U << USB_POWER_SUSPEN_Pos)         ///< BUS suspend enable bit
#define USB_POWER_SUSP_Pos              (1)
#define USB_POWER_SUSP                  (0x01U << USB_POWER_SUSP_Pos)           ///< suspend status
#define USB_POWER_WKUP_Pos              (3)
#define USB_POWER_WKUP                  (0x01U << USB_POWER_WKUP_Pos)           ///< Enable controller wake up from suspend state
////////////////////////////////////////////////////////////////////////////////
/// @brief USB_AHB_DMA Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_AHB_DMA_CH0_BS_Pos          (0)
#define USB_AHB_DMA_CH0_BS              (0x03U << USB_AHB_DMA_CH0_BS_Pos)        ///< Channel 0 transmits 2 bytes at a time
#define USB_AHB_DMA_CH1_BS_Pos          (2)
#define USB_AHB_DMA_CH1_BS              (0x03U << USB_AHB_DMA_CH1_BS_Pos)        ///< Channel 1 transmits 2 bytes at a time
#define USB_AHB_DMA_CH2_BS_Pos          (4)
#define USB_AHB_DMA_CH2_BS              (0x03U << USB_AHB_DMA_CH2_BS_Pos)        ///< Channel 2 transmits 2 bytes at a time
#define USB_AHB_DMA_CH3_BS_Pos          (6)
#define USB_AHB_DMA_CH3_BS              (0x03U << USB_AHB_DMA_CH3_BS_Pos)        ///< Channel 3 transmits 2 bytes at a time
////////////////////////////////////////////////////////////////////////////////
/// @brief USB_AHB_RST Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define USB_AHB_RST_EP0_Pos             (0)
#define USB_AHB_RST_EP0                 (0x01U << USB_AHB_RST_EP0_Pos)        ///< point 0 rest
#define USB_AHB_RST_EP1_Pos             (1)
#define USB_AHB_RST_EP1                 (0x01U << USB_AHB_RST_EP1_Pos)        ///< point 1 rest
#define USB_AHB_RST_EP2_Pos             (2)
#define USB_AHB_RST_EP2                 (0x01U << USB_AHB_RST_EP2_Pos)        ///< point 2 rest
#define USB_AHB_RST_EP3_Pos             (3)
#define USB_AHB_RST_EP3                 (0x01U << USB_AHB_RST_EP3_Pos)        ///< point 3 rest
#define USB_AHB_RST_EP4_Pos             (4)
#define USB_AHB_RST_EP4                 (0x01U << USB_AHB_RST_EP4_Pos)        ///< point 4 rest



/// @}

/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
