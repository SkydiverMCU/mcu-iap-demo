/***********************************************************************************************************************
    @file    boot.h
    @author  FAE Team
    @date    15-Mar-2023
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
#ifndef _BOOT_H_
#define _BOOT_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Files include */
#include "hal_conf.h"
#include "string.h"
#include "platform.h"
#include "tinyusb_device_hid_inout.h"

/* Exported types *****************************************************************************************************/

/* Exported constants *************************************************************************************************/
#define BOOT_SIZE 15
#define FLASH_SIZE 256 // 256K

#define BootJumpFlagAddress (BOOT_SIZE * 1024 + 0x8000000)
#define ApplicationAddress (BootJumpFlagAddress + 1024)

#define APP_SIZE (FLASH_SIZE - BOOT_SIZE - 1) // 240KB flash for app

/* Exported macro *****************************************************************************************************/
#define BLOCK_NUM 4 // 最多支持4段hex烧录

#define GET_VERSION 0x20
#define ERASE_APP 0x21
#define SYSTEM_RESET 0x22
#define WRITE_APP 0x23
#define VERIFY_APP 0x24
#define CLEAR_FLAG 0x25
#define WRITE_FLAG 0x26
#define SEG_STARTADDR 0x27 // 因支持hex文件多段下载，特需此指令
#define MCU_INFO 0x28      // 上位机获取MCU分给APP空间大小和APP存放的起始位置

  typedef struct
  {
    u32 BlockStartAddr;
    u32 BlockLength;
    u32 BlockCheckSum;
  } FileData_Block;
/* Exported variables *************************************************************************************************/
#undef EXTERN

#ifdef _BOOT_C_
#define EXTERN
#else
#define EXTERN extern
#endif

  EXTERN uint16_t USART_RX_STA;

#define UART_REC_LEN 64

  extern uint8_t UART_RxBuff[UART_REC_LEN];

  /* Exported functions *************************************************************************************************/

  void boot_protocol(u8 *buff, u16 len);
  void FLASH_Read(u8 *buff, u32 addr, u32 readNumber);

#ifdef __cplusplus
}
#endif

#endif /* _BOOT_H_ */

/********************************************** (C) Copyright MindMotion **********************************************/
