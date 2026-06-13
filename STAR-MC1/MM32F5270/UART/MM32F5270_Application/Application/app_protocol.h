/***********************************************************************************************************************
    @file    app_protocol.h
    @author  Skydiver
    @date    27-May-2025
    @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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

/* Define to prevent recursive inclusion */
#ifndef _APP_PROTOCOL_H_
#define _APP_PROTOCOL_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Files include */
#include "hal_conf.h"

  /* Exported types *****************************************************************************************************/

#define REPORT_PACKET_SIZE 64

  /* Exported constants *************************************************************************************************/

#define BOOT_SIZE 6
#define FLASH_SIZE 256 // 256K

#define APP_ADDRESS_OFFSET ((BOOT_SIZE + 1) * 1024)

#define BootJumpFlagAddress (BOOT_SIZE * 1024 + 0x8000000)
#define ApplicationAddress (BootJumpFlagAddress + 1024)

#define APP_SIZE (FLASH_SIZE - BOOT_SIZE - 1) // 249KB flash for app

#define BLOCK_NUM 4 // 最多支持4段hex烧录

#define RESPONSE_MASK 0xC0 // 回复MASK

#define GET_VERSION 0x20
#define ERASE_APP 0x21
#define SYSTEM_RESET 0x22
#define WRITE_APP 0x23
#define VERIFY_APP 0x24
#define CLEAR_FLAG 0x25
#define WRITE_FLAG 0x26
#define SEG_STARTADDR 0x27 // 因支持hex文件多段下载，特需此指令
#define MCU_INFO 0x28      // 上位机获取MCU分给APP空间大小和APP存放的起始位置

  /* Exported constants *************************************************************************************************/

  /* Exported macro *****************************************************************************************************/

  /* Exported variables *************************************************************************************************/

  extern uint16_t UART_RX_STA;
  extern uint8_t UART_RxBuff[REPORT_PACKET_SIZE];

  extern uint8_t Data_RxBuff[REPORT_PACKET_SIZE];
  extern void UART_SendGroup(uint8_t *pBuff, uint16_t length);
  void Receive_Protocol_Process(void);

#ifdef __cplusplus
}
#endif

#endif /* _APP_PROTOCOL_H_ */

/********************************************** (C) Copyright MindMotion **********************************************/
