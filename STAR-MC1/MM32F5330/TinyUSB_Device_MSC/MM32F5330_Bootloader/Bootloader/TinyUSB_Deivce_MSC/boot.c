/***********************************************************************************************************************
    @file    BOOT.c
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
#define _BOOT_C_

/* Files include */
#include <stdio.h>
#include "boot.h"

#define BOOT_VERSION "V:0.0.1"

void FLASH_Write(uint8_t *buff, uint32_t addr, uint32_t writeNumber)
{
    u32 temp;
    u32 WriteAddress;
    uint64_t DoubleWord;
    uint8_t remainder = 0;
    uint32_t integer  = 0;

    remainder = writeNumber % 8;
    integer   = writeNumber / 8;

    WriteAddress = addr;

    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    for (temp = 0; temp < (integer * 8); temp += 8)
    {
        DoubleWord = buff[temp];
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 1]) << 8);
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 2]) << 16);
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 3]) << 24);
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 4]) << 32);
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 5]) << 40);
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 6]) << 48);
        DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 7]) << 56);

        FLASH_ProgramDoubleWord(WriteAddress, DoubleWord);
        WriteAddress = WriteAddress + 8;
    }

    DoubleWord = 0;

    switch (remainder)
    {
        case 7:
            DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 6]) << 48);

        case 6:
            DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 5]) << 40);

        case 5:
            DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 4]) << 32);

        case 4:
            DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 3]) << 24);

        case 3:
            DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 2]) << 16);

        case 2:
            DoubleWord = DoubleWord | ((uint64_t)(buff[temp + 1]) << 8);

        case 1:
            DoubleWord = DoubleWord | ((uint64_t)buff[temp]);
            FLASH_ProgramDoubleWord(WriteAddress, DoubleWord);

        case 0:

            break;

        default:

            break;
    }

    FLASH_Lock();
}

void FLASH_Read(uint8_t *buff, uint32_t addr, uint32_t readNumber)
{
    uint32_t temp;
    uint32_t Address;
    uint16_t halfword;

    Address = addr;

    for (temp = 0; temp < readNumber; temp += 2)
    {
        halfword       = *((vu16 *)Address) & 0xFFFF;
        buff[temp]     = halfword & 0xFF;
        buff[temp + 1] = (halfword >> 8) & 0xFF;
        Address += 2;
    }
}

void eraseAppSpace(uint8_t Pagesize, uint32_t startaddress)
{
    uint16_t sum = 0;
    uint32_t Address;
    uint16_t index;
    uint8_t page_erase = Pagesize;

    Address = startaddress;
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    for (index = 0; index < page_erase; index++)
    {
        FLASH_ErasePage(Address);
        Address = Address + 0x400;
    }

    FLASH_Lock();
}

void clearAppInformationspace(void)
{
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    FLASH_ErasePage(BootJumpFlagAddress);

    FLASH_Lock();
}

void writeAppFlag(void)
{
    uint32_t calc_Information_crc_result;
    uint64_t DoubleWord;

    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    DoubleWord = Application_block.Application_state;
    DoubleWord = DoubleWord | ((uint64_t)(Application_block.Application_lenth) << 32);
    FLASH_ProgramDoubleWord(BootJumpFlagAddress, DoubleWord);

    DoubleWord = Application_block.Application_CRC32;
    DoubleWord = DoubleWord | ((uint64_t)(Application_block.Application_StartAddr) << 32);
    FLASH_ProgramDoubleWord(BootJumpFlagAddress + 8, DoubleWord);

    DoubleWord = Application_block.Application_version;
    DoubleWord = DoubleWord | ((uint64_t)(0xFFFFFFFF) << 32);
    FLASH_ProgramDoubleWord(BootJumpFlagAddress + 0x10, DoubleWord);

    calc_Information_crc_result = crc32_mpeg2_calculate((uint8_t *)BootJumpFlagAddress, 1024 - 4, CRC32_MPEG2_INIT); // 1K Information CRC 校验

    DoubleWord = 0xFFFFFFFF;
    DoubleWord = DoubleWord | ((uint64_t)(calc_Information_crc_result) << 32);
    FLASH_ProgramDoubleWord(ApplicationAddress - 0x08, DoubleWord);

    FLASH_Lock();
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/********************************************** (C) Copyright MindMotion **********************************************/

