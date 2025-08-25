/***********************************************************************************************************************
    @file     reg_usbfs.h
    @author   VV TEAM
    @brief    This flie contains all the USBFS's register and its field definition.
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

#ifndef __REG_USBFS_H
#define __REG_USBFS_H


/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "core_starmc1.h"



/**
  * @brief USBFS Base Address Definition
  */
#define  USBFS_BASE                                0x50000000                                       /*!<Base Address: 0x50000000*/

/**
  * @brief USBFS Register Structure Definition
  */
typedef struct
{
    __IO uint32_t RESERVED0x00[4];                /*!<                                               offset: 0x00~0x0C  */
    __IO uint32_t OTGISTAT;                       /*!<USBFS OTG Interrupt Status Register            offset: 0x10       */
    __IO uint32_t OTGICTRL;                       /*!<USBFS OTG Interrupt Control Register           offset: 0x14       */
    __IO uint32_t OTGSTAT;                        /*!<USBFS OTG Status Register                      offset: 0x18       */
    __IO uint32_t OTGCTRL;                        /*!<USBFS OTG Control Register                     offset: 0x1C       */
    __IO uint32_t RESERVED0x20[24];               /*!<                                               offset: 0x20~0x7C  */
    __IO uint32_t INTSTAT;                        /*!<USBFS Interrupt Status Register                offset: 0x80       */
    __IO uint32_t INTENB;                         /*!<USBFS Interrupt Enable Register                offset: 0x84       */
    __IO uint32_t ERRSTAT;                        /*!<USBFS Error Interrupt Status Register          offset: 0x88       */
    __IO uint32_t ERRENB;                         /*!<USBFS Error Interrupt Enable Register          offset: 0x8C       */
    __IO uint32_t STAT;                           /*!<USBFS Status Register                          offset: 0x90       */
    __IO uint32_t CTL;                            /*!<USBFS Control Register                         offset: 0x94       */
    __IO uint32_t ADDR;                           /*!<USBFS Address Register                         offset: 0x98       */
    __IO uint32_t BDTPAGE1;                       /*!<USBFS BDT Page Register 1                      offset: 0x9C       */
    __IO uint32_t FRMNUML;                        /*!<USBFS Low Frame Number Register                offset: 0xA0       */
    __IO uint32_t FRMNUMH;                        /*!<USBFS High Frame Number Register               offset: 0xA4       */
    __IO uint32_t TOKEN;                          /*!<USBFS Token Register                           offset: 0xA8       */
    __IO uint32_t SOFTHLD;                        /*!<USBFS SOF Threshold Register                   offset: 0xAC       */
    __IO uint32_t BDTPAGE2;                       /*!<USBFS BDT Page Register 2                      offset: 0xB0       */
    __IO uint32_t BDTPAGE3;                       /*!<USBFS BDT Page Register 3                      offset: 0xB4       */
    __IO uint32_t RESERVED0xB8[2];                /*!<                                               offset: 0xB8~0xBC  */
    __IO uint32_t EPCTL[16];                      /*!<USBFS Endpoint Control Register x              offset: 0xC0       */
    __IO uint32_t USBCTRL;                        /*!<USBFS USB Control Register                     offset: 0x100      */
} USBFS_TypeDef;

/**
  * @brief USBFS type pointer Definition
  */
#define USBFS                                     ((USBFS_TypeDef *)USBFS_BASE)

/**
  * @brief USBFS_OTGISTAT Register Bit Definition
  */
#define  USBFS_OTGISTAT_ID_CHG_Pos                (7)
#define  USBFS_OTGISTAT_ID_CHG_Msk                (0x1U << USBFS_OTGISTAT_ID_CHG_Pos)               /*!<In case of detection of USB ID PIN signal change, the bit is set.*/
#define  USBFS_OTGISTAT_ID_CHG                    USBFS_OTGISTAT_ID_CHG_Msk

/**
  * @brief USBFS_OTGICTRL Register Bit Definition
  */
#define  USBFS_OTGICTRL_ID_EN_Pos                 (7)
#define  USBFS_OTGICTRL_ID_EN_Msk                 (0x1U << USBFS_OTGICTRL_ID_EN_Pos)                /*!<0: Disable ID signal interrupt.*/
#define  USBFS_OTGICTRL_ID_EN                     USBFS_OTGICTRL_ID_EN_Msk

/**
  * @brief USBFS_OTGSTAT Register Bit Definition
  */
#define  USBFS_OTGSTAT_ID_Pos                     (7)
#define  USBFS_OTGSTAT_ID_Msk                     (0x1U << USBFS_OTGSTAT_ID_Pos)                    /*!<Indicate the current status of ID pin in the USB connector.*/
#define  USBFS_OTGSTAT_ID                         USBFS_OTGSTAT_ID_Msk

/**
  * @brief USBFS_OTGCTRL Register Bit Definition
  */
#define  USBFS_OTGCTRL_VBUS_ON_Pos                (3)
#define  USBFS_OTGCTRL_VBUS_ON_Msk                (0x1U << USBFS_OTGCTRL_VBUS_ON_Pos)               /*!<In case of setting, open VBUS power signal.*/
#define  USBFS_OTGCTRL_VBUS_ON                    USBFS_OTGCTRL_VBUS_ON_Msk

/**
  * @brief USBFS_INTSTAT Register Bit Definition
  */
#define  USBFS_INTSTAT_USB_RST_Pos                (0)
#define  USBFS_INTSTAT_USB_RST_Msk                (0x1U << USBFS_INTSTAT_USB_RST_Pos)               /*!<When USB_FS decodes the valid USB reset, the bit is set. It will inform the microprocessor to write 0x00 into the address register, and enable the End Point 0. Once detecting USB resetting of 2.5 ms, USB_RST will be reset. Before the USB reset condition is removed, it won't be reset again.*/
#define  USBFS_INTSTAT_USB_RST                    USBFS_INTSTAT_USB_RST_Msk
#define  USBFS_INTSTAT_ERROR_Pos                  (1)
#define  USBFS_INTSTAT_ERROR_Msk                  (0x1U << USBFS_INTSTAT_ERROR_Pos)                 /*!<In case of any error condition of ERRSTAT register, the bit is set. The microprocessor must read ERRSTAT register to determine the error source.*/
#define  USBFS_INTSTAT_ERROR                      USBFS_INTSTAT_ERROR_Msk
#define  USBFS_INTSTAT_SOF_TOK_Pos                (2)
#define  USBFS_INTSTAT_SOF_TOK_Msk                (0x1U << USBFS_INTSTAT_SOF_TOK_Pos)               /*!<In the device mode, if USB_FS receives SOF token, the bit is set.*/
#define  USBFS_INTSTAT_SOF_TOK                    USBFS_INTSTAT_SOF_TOK_Msk
#define  USBFS_INTSTAT_TOK_DNE_Pos                (3)
#define  USBFS_INTSTAT_TOK_DNE_Msk                (0x1U << USBFS_INTSTAT_TOK_DNE_Pos)               /*!<After the token processing, the bit is set. The microprocessor should immediately read STAT register to determine the relevant end End Point and BD.*/
#define  USBFS_INTSTAT_TOK_DNE                    USBFS_INTSTAT_TOK_DNE_Msk
#define  USBFS_INTSTAT_SLEEP_Pos                  (4)
#define  USBFS_INTSTAT_SLEEP_Msk                  (0x1U << USBFS_INTSTAT_SLEEP_Pos)                 /*!<When the USB_FS detects 3ms idle in the USB bus signal, the bit is set as '1'.*/
#define  USBFS_INTSTAT_SLEEP                      USBFS_INTSTAT_SLEEP_Msk
#define  USBFS_INTSTAT_RESUME_Pos                 (5)
#define  USBFS_INTSTAT_RESUME_Msk                 (0x1U << USBFS_INTSTAT_RESUME_Pos)                /*!<The host mode is used to detect the device RESUME signal.*/
#define  USBFS_INTSTAT_RESUME                     USBFS_INTSTAT_RESUME_Msk
#define  USBFS_INTSTAT_ATTACH_Pos                 (6)
#define  USBFS_INTSTAT_ATTACH_Msk                 (0x1U << USBFS_INTSTAT_ATTACH_Pos)                /*!<When USB_FS detects the USB peripheral connection, the bit is set. The signal is only valid in case of HOST_MODE_EN =1.*/
#define  USBFS_INTSTAT_ATTACH                     USBFS_INTSTAT_ATTACH_Msk
#define  USBFS_INTSTAT_STALL_Pos                  (7)
#define  USBFS_INTSTAT_STALL_Msk                  (0x1U << USBFS_INTSTAT_STALL_Pos)                 /*!<Set the bit as 1, and enable STALL interrupt.*/
#define  USBFS_INTSTAT_STALL                      USBFS_INTSTAT_STALL_Msk

/**
  * @brief USBFS_INTENB Register Bit Definition
  */
#define  USBFS_INTENB_USB_RST_Pos                 (0)
#define  USBFS_INTENB_USB_RST_Msk                 (0x1U << USBFS_INTENB_USB_RST_Pos)                /*!<Set the bit as 1, and enable ERROR interrupt.*/
#define  USBFS_INTENB_USB_RST                     USBFS_INTENB_USB_RST_Msk
#define  USBFS_INTENB_ERROR_Pos                   (1)
#define  USBFS_INTENB_ERROR_Msk                   (0x1U << USBFS_INTENB_ERROR_Pos)                  /*!<Set the bit as 1, and enable ERROR interrupt.*/
#define  USBFS_INTENB_ERROR                       USBFS_INTENB_ERROR_Msk
#define  USBFS_INTENB_SOF_TOK_Pos                 (2)
#define  USBFS_INTENB_SOF_TOK_Msk                 (0x1U << USBFS_INTENB_SOF_TOK_Pos)                /*!<Set the bit as 1, and enable SOF_TOK interrupt*/
#define  USBFS_INTENB_SOF_TOK                     USBFS_INTENB_SOF_TOK_Msk
#define  USBFS_INTENB_TOK_DNE_Pos                 (3)
#define  USBFS_INTENB_TOK_DNE_Msk                 (0x1U << USBFS_INTENB_TOK_DNE_Pos)                /*!<Set the bit as 1, and enable TOK_DNE interrupt.*/
#define  USBFS_INTENB_TOK_DNE                     USBFS_INTENB_TOK_DNE_Msk
#define  USBFS_INTENB_SLEEP_Pos                   (4)
#define  USBFS_INTENB_SLEEP_Msk                   (0x1U << USBFS_INTENB_SLEEP_Pos)                  /*!<Set the bit as 1, and enable SLEEP interrupt.*/
#define  USBFS_INTENB_SLEEP                       USBFS_INTENB_SLEEP_Msk
#define  USBFS_INTENB_RESUME_Pos                  (5)
#define  USBFS_INTENB_RESUME_Msk                  (0x1U << USBFS_INTENB_RESUME_Pos)                 /*!<Set the bit as 1, and enable RESUME interrupt.*/
#define  USBFS_INTENB_RESUME                      USBFS_INTENB_RESUME_Msk
#define  USBFS_INTENB_ATTACH_Pos                  (6)
#define  USBFS_INTENB_ATTACH_Msk                  (0x1U << USBFS_INTENB_ATTACH_Pos)                 /*!<Set the bit as 1, and enable ATTACH interrupt.*/
#define  USBFS_INTENB_ATTACH                      USBFS_INTENB_ATTACH_Msk
#define  USBFS_INTENB_STALL_Pos                   (7)
#define  USBFS_INTENB_STALL_Msk                   (0x1U << USBFS_INTENB_STALL_Pos)                  /*!<Set the bit as 1, and enable STALL interrupt.*/
#define  USBFS_INTENB_STALL                       USBFS_INTENB_STALL_Msk

/**
  * @brief USBFS_ERRSTAT Register Bit Definition
  */
#define  USBFS_ERRSTAT_PID_ERR_Pos                (0)
#define  USBFS_ERRSTAT_PID_ERR_Msk                (0x1U << USBFS_ERRSTAT_PID_ERR_Pos)               /*!<PID check field failure.*/
#define  USBFS_ERRSTAT_PID_ERR                    USBFS_ERRSTAT_PID_ERR_Msk
#define  USBFS_ERRSTAT_CRC5_EOF_Pos               (1)
#define  USBFS_ERRSTAT_CRC5_EOF_Msk               (0x1U << USBFS_ERRSTAT_CRC5_EOF_Pos)              /*!<The error interrupt has two functions.*/
#define  USBFS_ERRSTAT_CRC5_EOF                   USBFS_ERRSTAT_CRC5_EOF_Msk
#define  USBFS_ERRSTAT_CRC16_Pos                  (2)
#define  USBFS_ERRSTAT_CRC16_Msk                  (0x1U << USBFS_ERRSTAT_CRC16_Pos)                 /*!<CRC16 check error. If the data packet is refused because of CRC16 error, the bit is set.*/
#define  USBFS_ERRSTAT_CRC16                      USBFS_ERRSTAT_CRC16_Msk
#define  USBFS_ERRSTAT_DFN8_Pos                   (3)
#define  USBFS_ERRSTAT_DFN8_Msk                   (0x1U << USBFS_ERRSTAT_DFN8_Pos)                  /*!<The received data field is not 8 bits. If the data field is not the integer byte, the bit is set.*/
#define  USBFS_ERRSTAT_DFN8                       USBFS_ERRSTAT_DFN8_Msk
#define  USBFS_ERRSTAT_BTO_ERR_Pos                (4)
#define  USBFS_ERRSTAT_BTO_ERR_Msk                (0x1U << USBFS_ERRSTAT_BTO_ERR_Pos)               /*!<In case of bus turnover timeout error, this bit is set. The USB_FS uses the bus turnover timer to track the time between SETUP or OUT TOKEN and data phase or IN TOKEN data and handshake. If the previous EOP counting before IDLE changeover is greater than 16 bit, produce the bus turnover timeout error.*/
#define  USBFS_ERRSTAT_BTO_ERR                    USBFS_ERRSTAT_BTO_ERR_Msk
#define  USBFS_ERRSTAT_DMA_ERR_Pos                (5)
#define  USBFS_ERRSTAT_DMA_ERR_Msk                (0x1U << USBFS_ERRSTAT_DMA_ERR_Pos)               /*!<If USB_FS requests DMA access to read new BDT, and the bus is not given before USB_FS needs to receive or transmit data, the bit is set as '1'. In case of TX transmission processing, it leads to the transmission data underflow. Or in case of processing one Rx transmission, it will lead to one receipt data overflow.*/
#define  USBFS_ERRSTAT_DMA_ERR                    USBFS_ERRSTAT_DMA_ERR_Msk
#define  USBFS_ERRSTAT_BTS_ERR_Pos                (7)
#define  USBFS_ERRSTAT_BTS_ERR_Msk                (0x1U << USBFS_ERRSTAT_BTS_ERR_Pos)               /*!<Set in case of detection of bit stuff error. The corresponding data package is refused.*/
#define  USBFS_ERRSTAT_BTS_ERR                    USBFS_ERRSTAT_BTS_ERR_Msk

/**
  * @brief USBFS_ERRENB Register Bit Definition
  */
#define  USBFS_ERRENB_PID_ERR_Pos                 (0)
#define  USBFS_ERRENB_PID_ERR_Msk                 (0x1U << USBFS_ERRENB_PID_ERR_Pos)                /*!<Set the bit and enable PID_ERR interrupt.*/
#define  USBFS_ERRENB_PID_ERR                     USBFS_ERRENB_PID_ERR_Msk
#define  USBFS_ERRENB_CRC5_EOF_Pos                (1)
#define  USBFS_ERRENB_CRC5_EOF_Msk                (0x1U << USBFS_ERRENB_CRC5_EOF_Pos)               /*!<Set the bit as 1 and enable CRC5/EOF interrupt.*/
#define  USBFS_ERRENB_CRC5_EOF                    USBFS_ERRENB_CRC5_EOF_Msk
#define  USBFS_ERRENB_CRC16_Pos                   (2)
#define  USBFS_ERRENB_CRC16_Msk                   (0x1U << USBFS_ERRENB_CRC16_Pos)                  /*!<Set the bit as 1 and enable CRC16 interrupt.*/
#define  USBFS_ERRENB_CRC16                       USBFS_ERRENB_CRC16_Msk
#define  USBFS_ERRENB_DFN8_Pos                    (3)
#define  USBFS_ERRENB_DFN8_Msk                    (0x1U << USBFS_ERRENB_DFN8_Pos)                   /*!<Set the bit as 1 and enable DFN8 interrupt.*/
#define  USBFS_ERRENB_DFN8                        USBFS_ERRENB_DFN8_Msk
#define  USBFS_ERRENB_BTO_ERR_Pos                 (4)
#define  USBFS_ERRENB_BTO_ERR_Msk                 (0x1U << USBFS_ERRENB_BTO_ERR_Pos)                /*!<Set the bit as 1 and enable BTO_ERR interrupt.*/
#define  USBFS_ERRENB_BTO_ERR                     USBFS_ERRENB_BTO_ERR_Msk
#define  USBFS_ERRENB_DMA_ERR_Pos                 (5)
#define  USBFS_ERRENB_DMA_ERR_Msk                 (0x1U << USBFS_ERRENB_DMA_ERR_Pos)                /*!<Set the bit as 1 and enable DMA_ERR interrupt.*/
#define  USBFS_ERRENB_DMA_ERR                     USBFS_ERRENB_DMA_ERR_Msk
#define  USBFS_ERRENB_BTS_ERR_Pos                 (7)
#define  USBFS_ERRENB_BTS_ERR_Msk                 (0x1U << USBFS_ERRENB_BTS_ERR_Pos)                /*!<Set the bit as 1 and enable BTS_ERR interrupt.*/
#define  USBFS_ERRENB_BTS_ERR                     USBFS_ERRENB_BTS_ERR_Msk

/**
  * @brief USBFS_STAT Register Bit Definition
  */
#define  USBFS_STAT_ODD_Pos                       (2)
#define  USBFS_STAT_ODD_Msk                       (0x1U << USBFS_STAT_ODD_Pos)                      /*!<This bit indicates that the last buffer descriptor is located in the BDT odd number group. Please refer to the previous part to acquire more information generated by BDT address.*/
#define  USBFS_STAT_ODD                           USBFS_STAT_ODD_Msk
#define  USBFS_STAT_TX_Pos                        (3)
#define  USBFS_STAT_TX_Msk                        (0x1U << USBFS_STAT_TX_Pos)                       /*!<The bit indicates BDT transmission direction since the last refresh*/
#define  USBFS_STAT_TX                            USBFS_STAT_TX_Msk
#define  USBFS_STAT_ENDP_Pos                      (4)
#define  USBFS_STAT_ENDP_Msk                      (0xFU << USBFS_STAT_ENDP_Pos)                     /*!<Indicate the End Point address of the previous token. It allows the microprocessor to determine which BDT entry is finally refreshed by the ultimate USB affair.*/
#define  USBFS_STAT_ENDP                          USBFS_STAT_ENDP_Msk
#define  USBFS_STAT_ENDP_Bit0                     (0x1U << USBFS_STAT_ENDP_Pos) 
#define  USBFS_STAT_ENDP_Bit1                     (0x2U << USBFS_STAT_ENDP_Pos) 
#define  USBFS_STAT_ENDP_Bit2                     (0x4U << USBFS_STAT_ENDP_Pos) 
#define  USBFS_STAT_ENDP_Bit3                     (0x8U << USBFS_STAT_ENDP_Pos) 

/**
  * @brief USBFS_CTL Register Bit Definition
  */
#define  USBFS_CTL_USB_EN_Pos                     (0)
#define  USBFS_CTL_USB_EN_Msk                     (0x1U << USBFS_CTL_USB_EN_Pos)                    /*!<Set the bit as 1 and USB_FS works. Clearing it will disable USB_FS. Set the bit '1' will make SIE reinstate all odd bits as BDT. Therefore, setting the bit will reset the majority of logic in SIE. When the host mode is enabled, clearing the bit will make SIE stop transmission of SOF token.*/
#define  USBFS_CTL_USB_EN                         USBFS_CTL_USB_EN_Msk
#define  USBFS_CTL_ODD_RST_Pos                    (1)
#define  USBFS_CTL_ODD_RST_Msk                    (0x1U << USBFS_CTL_ODD_RST_Pos)                   /*!<Set the bit and reset all BDT ODD ping/pong bit as 0, and then specify the even number BDT.*/
#define  USBFS_CTL_ODD_RST                        USBFS_CTL_ODD_RST_Msk
#define  USBFS_CTL_RESUME_Pos                     (2)
#define  USBFS_CTL_RESUME_Msk                     (0x1U << USBFS_CTL_RESUME_Pos)                    /*!<Setting this bit will allow the USB-FS to execute resume signaling. This will allow the USB-FS to perform remote wake-up. Software must set RESUME to 1 for the required amount of time and then clear it to 0. If the HOST_MODE_EN bit is set the USB-FS will append a Low Speed End of Packet to the Resume signaling when the RESUME bit is cleared.*/
#define  USBFS_CTL_RESUME                         USBFS_CTL_RESUME_Msk
#define  USBFS_CTL_HOST_MODE_EN_Pos               (3)
#define  USBFS_CTL_HOST_MODE_EN_Msk               (0x1U << USBFS_CTL_HOST_MODE_EN_Pos)              /*!<Set the bit as 1 and USB_FS works in the host mode.*/
#define  USBFS_CTL_HOST_MODE_EN                   USBFS_CTL_HOST_MODE_EN_Msk
#define  USBFS_CTL_RESET_Pos                      (4)
#define  USBFS_CTL_RESET_Msk                      (0x1U << USBFS_CTL_RESET_Pos)                     /*!<Setting this bit will enable the USB-FS to generate USB reset signaling. This will allow the USB-FS to reset USB peripherals. This control signal is only valid in host mode, (i.e. HOST_MDOE_EN=1). Software must set RESET to 1 for the required amount of time and then clear it to 0 to end reset signaling. Refer to the USB reference protocol for details.*/
#define  USBFS_CTL_RESET                          USBFS_CTL_RESET_Msk
#define  USBFS_CTL_TxdSuspendTokenBusy_Pos        (5)
#define  USBFS_CTL_TxdSuspendTokenBusy_Msk        (0x1U << USBFS_CTL_TxdSuspendTokenBusy_Pos)       /*!<When USB_FS is in the slave mode, Txdsuspend; When USB_FS is the host mode, TokenBusy.*/
#define  USBFS_CTL_TxdSuspendTokenBusy            USBFS_CTL_TxdSuspendTokenBusy_Msk
#define  USBFS_CTL_SE0_Pos                        (6)
#define  USBFS_CTL_SE0_Msk                        (0x1U << USBFS_CTL_SE0_Pos)                       /*!<USB receives SE0 signal.*/
#define  USBFS_CTL_SE0                            USBFS_CTL_SE0_Msk
#define  USBFS_CTL_JSTATE_Pos                     (7)
#define  USBFS_CTL_JSTATE_Msk                     (0x1U << USBFS_CTL_JSTATE_Pos)                    /*!<USB differential receiver receives JSTATE signal.*/
#define  USBFS_CTL_JSTATE                         USBFS_CTL_JSTATE_Msk

/**
  * @brief USBFS_ADDR Register Bit Definition
  */
#define  USBFS_ADDR_ADDR_Pos                      (0)
#define  USBFS_ADDR_ADDR_Msk                      (0x7FU << USBFS_ADDR_ADDR_Pos)                    /*!<The USB address decoded by USB_FS in the device mode, and the transmission USB address in the host mode.*/
#define  USBFS_ADDR_ADDR                          USBFS_ADDR_ADDR_Msk
#define  USBFS_ADDR_ADDR_Bit0                     (0x01U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_ADDR_Bit1                     (0x02U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_ADDR_Bit2                     (0x04U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_ADDR_Bit3                     (0x08U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_ADDR_Bit4                     (0x10U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_ADDR_Bit5                     (0x20U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_ADDR_Bit6                     (0x40U << USBFS_ADDR_ADDR_Pos) 
#define  USBFS_ADDR_LS_EN_Pos                     (7)
#define  USBFS_ADDR_LS_EN_Msk                     (0x1U << USBFS_ADDR_LS_EN_Pos)                    /*!<Enabling the bit will inform USB_FS to write the next token command of the token register to be executed at low speed. It makes the USB_FS execute the low speed data transmission demand.*/
#define  USBFS_ADDR_LS_EN                         USBFS_ADDR_LS_EN_Msk

/**
  * @brief USBFS_BDTPAGE1 Register Bit Definition
  */
#define  USBFS_BDTPAGE1_BDT_BA_Pos                (1)
#define  USBFS_BDTPAGE1_BDT_BA_Msk                (0x7FU << USBFS_BDTPAGE1_BDT_BA_Pos)              /*!<This 7 bit value provides address bits 15 through 9 of the BDT base address, which defines where the Buffer Descriptor Table resides at in system memory. The 32 bit BDT base address is always aligned on 512 byte boundaries in memory.*/
#define  USBFS_BDTPAGE1_BDT_BA                    USBFS_BDTPAGE1_BDT_BA_Msk
#define  USBFS_BDTPAGE1_BDT_BA_Bit0               (0x01U << USBFS_BDTPAGE1_BDT_BA_Pos) 
#define  USBFS_BDTPAGE1_BDT_BA_Bit1               (0x02U << USBFS_BDTPAGE1_BDT_BA_Pos) 
#define  USBFS_BDTPAGE1_BDT_BA_Bit2               (0x04U << USBFS_BDTPAGE1_BDT_BA_Pos) 
#define  USBFS_BDTPAGE1_BDT_BA_Bit3               (0x08U << USBFS_BDTPAGE1_BDT_BA_Pos) 
#define  USBFS_BDTPAGE1_BDT_BA_Bit4               (0x10U << USBFS_BDTPAGE1_BDT_BA_Pos) 
#define  USBFS_BDTPAGE1_BDT_BA_Bit5               (0x20U << USBFS_BDTPAGE1_BDT_BA_Pos) 
#define  USBFS_BDTPAGE1_BDT_BA_Bit6               (0x40U << USBFS_BDTPAGE1_BDT_BA_Pos) 

/**
  * @brief USBFS_FRMNUML Register Bit Definition
  */
#define  USBFS_FRMNUML_FRM_Pos                    (0)
#define  USBFS_FRMNUML_FRM_Msk                    (0xFFU << USBFS_FRMNUML_FRM_Pos)                  /*!<These bits indicate the low 8 bits of the 11 bit frame.*/
#define  USBFS_FRMNUML_FRM                        USBFS_FRMNUML_FRM_Msk
#define  USBFS_FRMNUML_FRM_Bit0                   (0x01U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit1                   (0x02U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit2                   (0x04U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit3                   (0x08U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit4                   (0x10U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit5                   (0x20U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit6                   (0x40U << USBFS_FRMNUML_FRM_Pos) 
#define  USBFS_FRMNUML_FRM_Bit7                   (0x80U << USBFS_FRMNUML_FRM_Pos) 

/**
  * @brief USBFS_FRMNUMH Register Bit Definition
  */
#define  USBFS_FRMNUMH_FRM_Pos                    (0)
#define  USBFS_FRMNUMH_FRM_Msk                    (0x7U << USBFS_FRMNUMH_FRM_Pos)                   /*!<These bits indicate the high 3 bits of the 11 bit frame.*/
#define  USBFS_FRMNUMH_FRM                        USBFS_FRMNUMH_FRM_Msk
#define  USBFS_FRMNUMH_FRM_Bit0                   (0x1U << USBFS_FRMNUMH_FRM_Pos) 
#define  USBFS_FRMNUMH_FRM_Bit1                   (0x2U << USBFS_FRMNUMH_FRM_Pos) 
#define  USBFS_FRMNUMH_FRM_Bit2                   (0x4U << USBFS_FRMNUMH_FRM_Pos) 

/**
  * @brief USBFS_TOKEN Register Bit Definition
  */
#define  USBFS_TOKEN_TOKEN_ENDPT_Pos              (0)
#define  USBFS_TOKEN_TOKEN_ENDPT_Msk              (0xFU << USBFS_TOKEN_TOKEN_ENDPT_Pos)             /*!<Set the End Point of communication with the device.*/
#define  USBFS_TOKEN_TOKEN_ENDPT                  USBFS_TOKEN_TOKEN_ENDPT_Msk
#define  USBFS_TOKEN_TOKEN_ENDPT_Bit0             (0x1U << USBFS_TOKEN_TOKEN_ENDPT_Pos) 
#define  USBFS_TOKEN_TOKEN_ENDPT_Bit1             (0x2U << USBFS_TOKEN_TOKEN_ENDPT_Pos) 
#define  USBFS_TOKEN_TOKEN_ENDPT_Bit2             (0x4U << USBFS_TOKEN_TOKEN_ENDPT_Pos) 
#define  USBFS_TOKEN_TOKEN_ENDPT_Bit3             (0x8U << USBFS_TOKEN_TOKEN_ENDPT_Pos) 
#define  USBFS_TOKEN_TOKEN_PID_Pos                (4)
#define  USBFS_TOKEN_TOKEN_PID_Msk                (0xFU << USBFS_TOKEN_TOKEN_PID_Pos)               /*!<Set the executed token type, valid token*/
#define  USBFS_TOKEN_TOKEN_PID                    USBFS_TOKEN_TOKEN_PID_Msk
#define  USBFS_TOKEN_TOKEN_PID_Bit0               (0x1U << USBFS_TOKEN_TOKEN_PID_Pos) 
#define  USBFS_TOKEN_TOKEN_PID_Bit1               (0x2U << USBFS_TOKEN_TOKEN_PID_Pos) 
#define  USBFS_TOKEN_TOKEN_PID_Bit2               (0x4U << USBFS_TOKEN_TOKEN_PID_Pos) 
#define  USBFS_TOKEN_TOKEN_PID_Bit3               (0x8U << USBFS_TOKEN_TOKEN_PID_Pos) 

/**
  * @brief USBFS_SOFTHLD Register Bit Definition
  */
#define  USBFS_SOFTHLD_CNT_Pos                    (0)
#define  USBFS_SOFTHLD_CNT_Msk                    (0xFFU << USBFS_SOFTHLD_CNT_Pos)                  /*!<Set SOF count threshold.*/
#define  USBFS_SOFTHLD_CNT                        USBFS_SOFTHLD_CNT_Msk
#define  USBFS_SOFTHLD_CNT_Bit0                   (0x01U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit1                   (0x02U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit2                   (0x04U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit3                   (0x08U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit4                   (0x10U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit5                   (0x20U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit6                   (0x40U << USBFS_SOFTHLD_CNT_Pos) 
#define  USBFS_SOFTHLD_CNT_Bit7                   (0x80U << USBFS_SOFTHLD_CNT_Pos) 

/**
  * @brief USBFS_BDTPAGE2 Register Bit Definition
  */
#define  USBFS_BDTPAGE2_BDT_BA_Pos                (0)
#define  USBFS_BDTPAGE2_BDT_BA_Msk                (0xFFU << USBFS_BDTPAGE2_BDT_BA_Pos)              /*!<This 8 bit value provides address bits 23 through 16 of the BDT base address, which defines where the Buffer Descriptor Table resides at in system memory. The 32 bit BDT base address is always aligned on 512 byte boundaries in memory.*/
#define  USBFS_BDTPAGE2_BDT_BA                    USBFS_BDTPAGE2_BDT_BA_Msk
#define  USBFS_BDTPAGE2_BDT_BA_Bit0               (0x01U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit1               (0x02U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit2               (0x04U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit3               (0x08U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit4               (0x10U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit5               (0x20U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit6               (0x40U << USBFS_BDTPAGE2_BDT_BA_Pos) 
#define  USBFS_BDTPAGE2_BDT_BA_Bit7               (0x80U << USBFS_BDTPAGE2_BDT_BA_Pos) 

/**
  * @brief USBFS_BDTPAGE3 Register Bit Definition
  */
#define  USBFS_BDTPAGE3_BDT_BA_Pos                (0)
#define  USBFS_BDTPAGE3_BDT_BA_Msk                (0xFFU << USBFS_BDTPAGE3_BDT_BA_Pos)              /*!<This 8 bit value provides address bits 31 through 24 of the BDT base address, which defines where the Buffer Descriptor Table resides at in system memory. The 32 bit BDT base address is always aligned on 512 byte boundaries in memory.*/
#define  USBFS_BDTPAGE3_BDT_BA                    USBFS_BDTPAGE3_BDT_BA_Msk
#define  USBFS_BDTPAGE3_BDT_BA_Bit0               (0x01U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit1               (0x02U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit2               (0x04U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit3               (0x08U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit4               (0x10U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit5               (0x20U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit6               (0x40U << USBFS_BDTPAGE3_BDT_BA_Pos) 
#define  USBFS_BDTPAGE3_BDT_BA_Bit7               (0x80U << USBFS_BDTPAGE3_BDT_BA_Pos) 

/**
  * @brief USBFS_EPCTL Register Bit Definition
  */
#define  USBFS_EPCTL_EP_HSHK_Pos                  (0)
#define  USBFS_EPCTL_EP_HSHK_Msk                  (0x1U << USBFS_EPCTL_EP_HSHK_Pos)                 /*!<0: This End Point doesn't return handshake signal*/
#define  USBFS_EPCTL_EP_HSHK                      USBFS_EPCTL_EP_HSHK_Msk
#define  USBFS_EPCTL_EP_STALL_Pos                 (1)
#define  USBFS_EPCTL_EP_STALL_Msk                 (0x1U << USBFS_EPCTL_EP_STALL_Pos)                /*!<Superior to EP_HSHK bit setting, and only valid when the end point is not disabled.*/
#define  USBFS_EPCTL_EP_STALL                     USBFS_EPCTL_EP_STALL_Msk
#define  USBFS_EPCTL_EP_TX_EN_Pos                 (2)
#define  USBFS_EPCTL_EP_TX_EN_Msk                 (0x1U << USBFS_EPCTL_EP_TX_EN_Pos)                /*!<Endpoint send enable bit*/
#define  USBFS_EPCTL_EP_TX_EN                     USBFS_EPCTL_EP_TX_EN_Msk
#define  USBFS_EPCTL_EP_RX_EN_Pos                 (3)
#define  USBFS_EPCTL_EP_RX_EN_Msk                 (0x1U << USBFS_EPCTL_EP_RX_EN_Pos)                /*!<Endpoint receive enable bit*/
#define  USBFS_EPCTL_EP_RX_EN                     USBFS_EPCTL_EP_RX_EN_Msk
#define  USBFS_EPCTL_EP_CTL_DIS_Pos               (4)
#define  USBFS_EPCTL_EP_CTL_DIS_Msk               (0x1U << USBFS_EPCTL_EP_CTL_DIS_Pos)              /*!<Endpoint transmission direction bit*/
#define  USBFS_EPCTL_EP_CTL_DIS                   USBFS_EPCTL_EP_CTL_DIS_Msk
#define  USBFS_EPCTL_RETRY_DIS_Pos                (6)
#define  USBFS_EPCTL_RETRY_DIS_Msk                (0x1U << USBFS_EPCTL_RETRY_DIS_Pos)               /*!<This is a bit only used in the host mode, only existing in the End Point 1 control register.*/
#define  USBFS_EPCTL_RETRY_DIS                    USBFS_EPCTL_RETRY_DIS_Msk
#define  USBFS_EPCTL_HOST_WO_HUB_Pos              (7)
#define  USBFS_EPCTL_HOST_WO_HUB_Msk              (0x1U << USBFS_EPCTL_HOST_WO_HUB_Pos)             /*!<This is a bit only used in the host mode, only existing in the End Point x control register.*/
#define  USBFS_EPCTL_HOST_WO_HUB                  USBFS_EPCTL_HOST_WO_HUB_Msk

/**
  * @brief USBFS_USBCTRL Register Bit Definition
  */
#define  USBFS_USBCTRL_VBUSORV_Pos                (0)
#define  USBFS_USBCTRL_VBUSORV_Msk                (0x1U << USBFS_USBCTRL_VBUSORV_Pos)               /*!<VBUS value, only valid when VBUSORE=1*/
#define  USBFS_USBCTRL_VBUSORV                    USBFS_USBCTRL_VBUSORV_Msk
#define  USBFS_USBCTRL_VBUSORE_Pos                (1)
#define  USBFS_USBCTRL_VBUSORE_Msk                (0x1U << USBFS_USBCTRL_VBUSORE_Pos)               /*!<VBUS Override Enable. When VBUS is rewritten to 0, the DP pull-up will be automatically invalid, and if it is rewritten to 1, the DP pull-up resistor will be automatically valid*/
#define  USBFS_USBCTRL_VBUSORE                    USBFS_USBCTRL_VBUSORE_Msk
#define  USBFS_USBCTRL_SUSPE_Pos                  (7)
#define  USBFS_USBCTRL_SUSPE_Msk                  (0x1U << USBFS_USBCTRL_SUSPE_Pos)                 /*!<The on-chip USB PHY suspend state enable bit is used when the USB controller is in the suspend state. Setting this bit can make the on-chip PHY in the suspend state, further saving power consumption. Clearing this bit puts the on-chip USB PHY in normal operation. When SUSPE=1, the Resume or Remote Wakeup operation is allowed to wake the system from STOP mode.*/
#define  USBFS_USBCTRL_SUSPE                      USBFS_USBCTRL_SUSPE_Msk


#endif

