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

/* Private typedef ****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

const uint8_t Report_Return_Err[REPORT_PACKET_SIZE] =
    {
        0xD5, 0x04, 0x00, 0x00, 0x59};
const uint8_t Valid_buf[4] =
    {
        0x55, 0xAA, 0xAA, 0x55};

FileData_Block appdata_block[BLOCK_NUM];

uint8_t code_buff[512];
uint8_t currentSegment = 0;
uint16_t code_CurrentLength;
uint32_t code_TotalLength;
uint16_t UART_RX_STA = 0;

uint8_t sendbuff[REPORT_PACKET_SIZE];

uint8_t UART_RxBuff[REPORT_PACKET_SIZE];

#define code_buff_size sizeof(code_buff)
/* Private functions **************************************************************************************************/

/*************Check calculation********************************/

static uint16_t CheckSum(uint8_t *pdat, uint8_t count)
{
    register int sum = 0;

    while (count > 0)
    {
        sum = sum + *pdat;
        pdat++;
        count--;
    }

    return (sum);
}

/**********Checksum*******************/

static uint8_t Check_data(uint8_t *txrxCmd)
{
    // uint8_t Flag_check = 0;
    uint16_t tmp_Checksum = 0;
    uint8_t temp1, temp2;

    tmp_Checksum = CheckSum(txrxCmd, txrxCmd[1] - 2);

    temp1 = tmp_Checksum & 0x00FF;
    temp2 = (tmp_Checksum >> 8) & 0x00FF;

    if ((temp2 != txrxCmd[txrxCmd[1] - 2]) || (temp1 != txrxCmd[txrxCmd[1] - 1]))
    {
        return (1);
    }

    return (0);
}

static void FLASH_Write(const uint8_t *buff, uint32_t addr, uint32_t writeNumber)
{
    uint32_t temp;
    uint32_t WriteAddress;
    uint16_t HalfWord;

    WriteAddress = addr;

    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
    for (temp = 0; temp < writeNumber; temp += 2)
    {
        HalfWord = buff[temp];
        HalfWord = HalfWord | (buff[temp + 1] << 8);
        FLASH_ProgramHalfWord(WriteAddress, HalfWord);
        WriteAddress = WriteAddress + 2;
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
        halfword = *((vu16 *)Address) & 0xFFFF;
        buff[temp] = halfword & 0xFF;
        buff[temp + 1] = (halfword >> 8) & 0xFF;
        Address += 2;
    }
}

void appVerify(uint8_t *buff)
{
    uint8_t j;
    uint32_t CRC32_check = 0;
    uint16_t sum = 0;

    for (j = 0; j < 4; j++)
    {
        if (appdata_block[j].BlockLength == 0)
        {
            break;
        }

        CRC32_check = crc32_mpeg2_calculate((uint8_t *)appdata_block[j].BlockStartAddr, appdata_block[j].BlockLength);

        // printf("CRC32 = 0x%x",CRC32_check);
        if (CRC32_check != appdata_block[j].BlockCheckSum)
        {
            memcpy(buff, Report_Return_Err, 0x40);
            UART_SendGroup(buff, REPORT_PACKET_SIZE);
            return;
        }
    }

    memset(buff, 0, 0x40);
    buff[0] = VERIFY_APP | RESPONSE_MASK;
    buff[1] = 4;
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;
    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void segmentInfo(uint8_t *buff)
{
    uint8_t i;
    uint32_t segmentLen;
    uint16_t sum = 0;

    for (i = 0; i < BLOCK_NUM; i++)
    {
        appdata_block[i].BlockLength = 0;
        appdata_block[i].BlockStartAddr = 0;
        appdata_block[i].BlockCheckSum = 0;
    }

    for (i = 0; i < BLOCK_NUM; i++)
    {
        segmentLen = (buff[i * 12 + 2] << 24) | (buff[i * 12 + 3] << 16) | (buff[i * 12 + 4] << 8) | buff[i * 12 + 5];

        if (segmentLen == 0)
        {
            break;
        }

        appdata_block[i].BlockLength = segmentLen;
        appdata_block[i].BlockStartAddr = (buff[i * 12 + 6] << 24) | (buff[i * 12 + 7] << 16) | (buff[i * 12 + 8] << 8) | buff[i * 12 + 9];
        appdata_block[i].BlockCheckSum = (buff[i * 12 + 10] << 24) | (buff[i * 12 + 11] << 16) | (buff[i * 12 + 12] << 8) | buff[i * 12 + 13];
    }

    buff[0] = SEG_STARTADDR | RESPONSE_MASK;
    buff[1] = 4;
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;
    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

static void Data_Recive(uint8_t *buff, uint32_t StartAddr, uint32_t SegmentLength)
{
    if (code_CurrentLength + 60 <= code_buff_size)
    {
        memcpy(&code_buff[code_CurrentLength], &buff[2], buff[1] - 4);
        code_CurrentLength += buff[1] - 4;
    }
    else
    {
        FLASH_Write(code_buff, StartAddr + code_TotalLength, code_CurrentLength);
        code_TotalLength += code_CurrentLength;

        memcpy(&code_buff, &buff[2], buff[1] - 4);
        code_CurrentLength = buff[1] - 4;
    }

    if ((code_TotalLength + code_CurrentLength) == SegmentLength)
    {
        FLASH_Write(code_buff, StartAddr + code_TotalLength, code_CurrentLength);

        code_CurrentLength = 0;
        code_TotalLength = 0;

        if (currentSegment < 3)
        {
            currentSegment++;
        }
    }
}

void appCodeDownload(uint8_t *buff)
{
    uint16_t sum = 0;

    Data_Recive(buff, appdata_block[currentSegment].BlockStartAddr, appdata_block[currentSegment].BlockLength);

    memset(buff, 0, 0x40);
    buff[0] = WRITE_APP | RESPONSE_MASK;
    buff[1] = 4;
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;
    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void resetMCU(uint8_t *buff)
{
    uint16_t sum = 0;

    buff[0] = SYSTEM_RESET | RESPONSE_MASK;
    buff[1] = 4;
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;
    UART_SendGroup(buff, REPORT_PACKET_SIZE);

    DELAY_Ms(5);
    NVIC_SystemReset(); // 软复位
}

void eraseAppSpace(uint8_t *buff)
{
    uint16_t sum = 0;

    uint32_t Address;
    uint16_t index;
    uint16_t page_erase = (buff[2] << 8) | buff[3];

    Address = ApplicationAddress;
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    for (index = 0; index < page_erase; index++)
    {
        FLASH_ErasePage(Address);
        Address = Address + 0x400;
    }

    FLASH_Lock();
    buff[0] = ERASE_APP | RESPONSE_MASK;
    buff[1] = 4;
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;
    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void getVersion(uint8_t *buff)
{
    uint16_t sum = 0;

    memset(buff, 0, 0x40);
    buff[0] = GET_VERSION | RESPONSE_MASK;
    buff[1] = 16;
    buff[2] = 'B'; // Bootloader
    strncpy((char *)(buff + 3), BOOT_VERSION, 7);
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;

    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void clearAppFlag(uint8_t *buff)
{
    uint16_t sum = 0;

    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    FLASH_ErasePage(BootJumpFlagAddress);

    FLASH_Lock();

    memset(buff, 0, 0x40);
    buff[0] = CLEAR_FLAG | RESPONSE_MASK;
    buff[1] = 4;
    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;
    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void writeAppFlag(uint8_t *buff)
{
    uint16_t sum = 0;

    uint8_t Write_buff[4] = {0};
    uint32_t Calculation_crc_result, Information_crc_result, Download_lenth, Download_CRC;

    Download_lenth = buff[5]; // 下发的APP长度
    Download_lenth |= (buff[4] << 8);
    Download_lenth |= (buff[3] << 16);
    Download_lenth |= (buff[2] << 24);

    Download_CRC = buff[9]; // 下发的CRC32值
    Download_CRC |= (buff[8] << 8);
    Download_CRC |= (buff[7] << 16);
    Download_CRC |= (buff[6] << 24);

    Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)ApplicationAddress, Download_lenth); // Application 校验
    if (Download_CRC == Calculation_crc_result)
    {

        Write_buff[0] = buff[5];
        Write_buff[1] = buff[4];
        Write_buff[2] = buff[3];
        Write_buff[3] = buff[2];

        FLASH_Write(Write_buff, BootJumpFlagAddress + 4, 4);

        Write_buff[0] = buff[9];
        Write_buff[1] = buff[8];
        Write_buff[2] = buff[7];
        Write_buff[3] = buff[6];

        FLASH_Write(Write_buff, BootJumpFlagAddress + 8, 4);

        FLASH_Write(Valid_buf, BootJumpFlagAddress, sizeof(Valid_buf));
        FLASH_Read(Write_buff, BootJumpFlagAddress, 4);

        if (memcmp(Write_buff, Valid_buf, 4) != 0)
        {
            memcpy(buff, Report_Return_Err, 0x40);
            UART_SendGroup(buff, REPORT_PACKET_SIZE);
        }
        else
        {
            Information_crc_result = crc32_mpeg2_calculate((uint8_t *)BootJumpFlagAddress, 1024 - 4); // 1K Information CRC 校验
            Write_buff[0] = Information_crc_result & 0xFF;
            Write_buff[1] = (Information_crc_result >> 8) & 0xFF;
            Write_buff[2] = (Information_crc_result >> 16) & 0xFF;
            Write_buff[3] = (Information_crc_result >> 24) & 0xFF;

            FLASH_Write(Write_buff, ApplicationAddress - 4, 4);

            Write_buff[0] = buff[9];
            Write_buff[1] = buff[8];
            Write_buff[2] = buff[7];
            Write_buff[3] = buff[6];

            memset(buff, 0, 0x40);
            buff[0] = WRITE_FLAG | RESPONSE_MASK;
            buff[1] = 4;
            sum = CheckSum(buff, buff[1] - 2);
            buff[buff[1] - 2] = (sum >> 8) & 0xFF;
            buff[buff[1] - 1] = sum & 0xFF;
            UART_SendGroup(buff, REPORT_PACKET_SIZE);
        }
    }
    else
    {
        memcpy(buff, Report_Return_Err, 0x40);
        UART_SendGroup(buff, REPORT_PACKET_SIZE);
    }
}

void mcuInfo(uint8_t *buff)
{
    uint16_t sum = 0;

    buff[0] = MCU_INFO | RESPONSE_MASK;
    buff[1] = 12;
    buff[2] = (ApplicationAddress >> 24) & 0xFF;
    buff[3] = (ApplicationAddress >> 16) & 0xFF;
    buff[4] = (ApplicationAddress >> 8) & 0xFF;
    buff[5] = ApplicationAddress & 0xFF;

    buff[6] = ((APP_SIZE * 1024) >> 24) & 0xFF;
    buff[7] = ((APP_SIZE * 1024) >> 16) & 0xFF;
    buff[8] = ((APP_SIZE * 1024) >> 8) & 0xFF;
    buff[9] = (APP_SIZE * 1024) & 0xFF;

    sum = CheckSum(buff, buff[1] - 2);
    buff[buff[1] - 2] = (sum >> 8) & 0xFF;
    buff[buff[1] - 1] = sum & 0xFF;

    UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void boot_protocol(uint8_t *buff, uint16_t len)
{
    uint8_t cmd;

    memcpy(sendbuff, buff, len);
    buff = sendbuff;

    if (Check_data(buff))
    {
        memcpy(buff, Report_Return_Err, 0x40);
        UART_SendGroup(buff, REPORT_PACKET_SIZE);
        return;
    }

    cmd = buff[0];

    switch (cmd)
    {
    case GET_VERSION:
        getVersion(buff);
        break;

    case ERASE_APP:
        eraseAppSpace(buff);
        break;

    case SYSTEM_RESET:
        resetMCU(buff);
        break;

    case WRITE_APP:
        appCodeDownload(buff);
        break;

    case VERIFY_APP:
        appVerify(buff);
        break;

    case CLEAR_FLAG:
        clearAppFlag(buff);
        break;

    case WRITE_FLAG:
        writeAppFlag(buff);
        break;

    case SEG_STARTADDR:
        segmentInfo(buff);
        break;

    case MCU_INFO:
        mcuInfo(buff);
        break;

    default:
        break;
    }
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
