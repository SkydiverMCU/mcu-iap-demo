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
/* Files include */
  #include "hal_conf.h"
  #include "string.h"
  #include "crc32_algorithm.h"
  #include "platform.h"
/* Exported types *****************************************************************************************************/

/* Exported constants *************************************************************************************************/
  #define HEADER_VALUE   0x4D4D3332
  
  #define BOOT_SIZE               26
  #define FLASH_SIZE              128  // 128K

  #define BootJumpFlagAddress     (BOOT_SIZE * 1024 + 0x8000000)
  #define ApplicationAddress      (BootJumpFlagAddress + 1024)

  #define SRAM_LEGAL_ADDRESS_MASK 0x2FFFC000                   // SRAM合法地址范围  0x20000000 - 0x20003FFF 16KB  SRAM

  #define APP_SIZE                (FLASH_SIZE - BOOT_SIZE - 1) // 101KB flash for app
/* Exported macro *****************************************************************************************************/


/*

       MM32F0160 IAP 128K Flash空间划分

  |------------------------------------------------| --> 0x08000000
  |                                                |
  |                                                |
  |   Bootloader space (26K Byte)                  |
  |                                                |
  |                                                |
  |                                                |
  |------------------------------------------------| --> 0x08006800
  |                                                |
  |   Application  1K Information (1024 Byte)      |
  |                                                |
  |------------------------------------------------| --> 0x08006C00
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |     Application space(101K byte)               |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                | 
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                                |
  |                                |App crc32 value| 最后一个Word保存整个APP区间 103420 个byte的CRC32值
  |------------------------------------------------| --> 0x0801FFFF


*/
/* Exported macro *****************************************************************************************************/

typedef struct
{
    __IO uint32_t Application_state;
    __IO uint32_t Application_lenth;
    __IO uint32_t Application_CRC32;
    __IO uint32_t Application_StartAddr;
    __IO uint32_t Application_version;
    __IO uint32_t Information_CRC32;
} FileData_Block;

/* Exported variables *************************************************************************************************/
  #undef EXTERN

  #ifdef _BOOT_C_
    #define EXTERN
  #else
    #define EXTERN       extern
  #endif

extern FileData_Block Application_block;
extern uint32_t FileData_Block_buff[6];

/* Exported functions *************************************************************************************************/
void FLASH_Write(uint8_t *buff, uint32_t addr, uint32_t writeNumber);
void FLASH_Read(uint8_t *buff, uint32_t addr, uint32_t readNumber);

void eraseAppSpace(uint8_t Pagesize, uint32_t startaddress);
void clearAppInformationspace(void);
void writeAppFlag(void);

  #ifdef __cplusplus
}
  #endif

#endif /* _BOOT_H_ */

/********************************************** (C) Copyright MindMotion **********************************************/

