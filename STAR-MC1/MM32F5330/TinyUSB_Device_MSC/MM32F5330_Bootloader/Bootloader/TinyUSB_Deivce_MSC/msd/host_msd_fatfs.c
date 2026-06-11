/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016, 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "host_msd_fatfs.h"
#include "ff.h"
#include "diskio.h"
//#include "fsl_device_registers.h"

#include "hal_conf.h"
#include "string.h"
#include "crc32_algorithm.h"
#include "boot.h"

#define WRITE_BUFF_SIZE 0x400

/*******************************************************************************
  * IAP Definitions
  ******************************************************************************/

uint8_t Temp_read_buff[WRITE_BUFF_SIZE] =
{
    0
};
uint8_t Temp_write_buff[WRITE_BUFF_SIZE] =
{
    0
};

uint32_t Packet_Total_lenth = 0;
uint16_t Updatepacketsize   = 0;
uint32_t Remaining_size     = 0;
uint32_t Operation_address  = 0;
uint32_t Calculation_crc_result;
uint32_t Loop_count = 0;
uint32_t FileData_Block_buff[6];

FileData_Block Application_block;

/*******************************************************************************
  * Definitions
  ******************************************************************************/
static FATFS fatfs;
/*******************************************************************************
  * Prototypes
  ******************************************************************************/

/*!
  * @brief host msd control transfer callback.
  *
  * This function is used as callback function for control transfer .
  *
  * @param param      the host msd fatfs instance pointer.
  * @param data       data buffer pointer.
  * @param dataLength data length.
  * @status           transfer result status.
  */
static void USB_HostMsdFatfsTestDone(void)
{
    printf("\r\n............................file operation done......................\r\n");
}

static void USB_HostMsdFatfsDisplayFileInfo(FILINFO *fileInfo)
{
    char *fileName;

    fileName = fileInfo->fname;

    /* note: if this file/directory don't have one attribute, '_' replace the attribute letter ('R' - readonly, 'H' - hide, 'S' - system) */
    printf("    %s - %c%c%c - %s - %dBytes - %d-%d-%d %d:%d:%d\r\n",
           (fileInfo->fattrib & AM_DIR) ? "dir" : "fil",
           (fileInfo->fattrib & AM_RDO) ? 'R' : '_',
           (fileInfo->fattrib & AM_HID) ? 'H' : '_',
           (fileInfo->fattrib & AM_SYS) ? 'S' : '_',
           fileName,
           (fileInfo->fsize),
           (uint32_t)((fileInfo->fdate >> 9) + 1980) /* year */,
           (uint32_t)((fileInfo->fdate >> 5) & 0x000Fu) /* month */,
           (uint32_t)(fileInfo->fdate & 0x001Fu) /* day */,
           (uint32_t)((fileInfo->ftime >> 11) & 0x0000001Fu) /* hour */,
           (uint32_t)((fileInfo->ftime >> 5) & 0x0000003Fu) /* minute */,
           (uint32_t)(fileInfo->ftime & 0x0000001Fu) /* second */
           );
}

static FRESULT USB_HostMsdFatfsListDirectory(const TCHAR *path)
{
    FRESULT fatfsCode = FR_OK;
    FILINFO fileInfo;
    DIR dir;
    uint8_t outputLabel = 0;

#if _USE_LFN
    static uint8_t fileNameBuffer[_MAX_LFN];
    fileInfo.lfname = fileNameBuffer;
    fileInfo.lfsize = _MAX_LFN;
#endif /* _USE_LFN */

    fatfsCode = f_opendir(&dir, path);

    if (fatfsCode)
    {
        return (fatfsCode);
    }

    while (1)
    {
        fatfsCode = f_readdir(&dir, &fileInfo);

        if ((fatfsCode) || (!fileInfo.fname[0]))
        {
            break;
        }

        outputLabel = 1;
        USB_HostMsdFatfsDisplayFileInfo(&fileInfo);
    }

    if (!outputLabel)
    {
        printf("\r\n");
    }

    return (fatfsCode);
}

//=============================================================================================
// User Read write File
void USB_HostMsdFatfsUserReadWrite(void)
{
    FRESULT fatfsCode;
    FATFS *fs;
    FIL file;
    FILINFO fileInfo;
    uint32_t freeClusterNumber;
    uint32_t index;
    uint32_t resultSize;
    char *testString;
    uint8_t driverNumberBuffer[3];
    uint32_t application_save_crc_value = 0;
    uint32_t CRC32_check = 0;

    /* time delay */
    for (freeClusterNumber = 0; freeClusterNumber < 10000; ++freeClusterNumber)
    {
        __NOP();                       //__NOP();
    }

    printf("\r\n............................fatfs Start Read Write file.....................\r\n");

    printf("fatfs mount as logiacal driver %d......", USBDISK);
    sprintf((char *)&driverNumberBuffer[0], "%c:", USBDISK + '0');
    fatfsCode = f_mount(&fatfs, (char const *)&driverNumberBuffer[0], 0);

    if (fatfsCode)
    {
        printf("error\r\n");
        USB_HostMsdFatfsTestDone();
        return;
    }

    printf("success\r\n");

    printf("f_getfree:\r\n");
    fatfsCode = f_getfree((char const *)&driverNumberBuffer[0], (DWORD *)&freeClusterNumber, &fs);

    if (fatfsCode)
    {
        printf("error\r\n");
        USB_HostMsdFatfsTestDone();
        return;
    }

    if (fs->fs_type == FS_FAT12)
    {
        printf("    FAT type = FAT12\r\n");
    }
    else if (fs->fs_type == FS_FAT16)
    {
        printf("    FAT type = FAT16\r\n");
    }
    else
    {
        printf("    FAT type = FAT32\r\n");
    }

    printf("    bytes per cluster = %d; number of clusters=%lu \r\n", fs->csize * 512, fs->n_fatent - 2);
    printf("    The free size: %dKB, the total size:%dKB\r\n", (freeClusterNumber * (fs->csize) / 2), ((fs->n_fatent - 2) * (fs->csize) / 2));

    printf("list root directory:\r\n");
    fatfsCode = USB_HostMsdFatfsListDirectory((char const *)&driverNumberBuffer[0]);

    if (fatfsCode)
    {
        USB_HostMsdFatfsTestDone();
        return;
    }

    //-------------------------------------------------------------
    // IAP Read Checksum

    printf("IAP Read file operation:\r\n");

    //#define FF_USE_LFN        0
    //短文件名 (SFN) 模式：长度严格限制在 8.3 格式
    //
    fatfsCode = f_open(&file, _T("1:/Update.bin"), FA_READ); // FA_WRITE | FA_READ   //短文件名 (SFN) 模式：长度严格限制在 8.3 格式

    if (fatfsCode)
    {
        if (fatfsCode == FR_EXIST)
        {
            printf("file exist\r\n");
        }
        else
        {
            printf("error\r\n");
            USB_HostMsdFatfsTestDone();
            return;
        }
    }
    else
    {
        printf("success\r\n");
    }

    printf("get file \"Update.bin\" information:\r\n");
    fatfsCode = f_stat(_T("1:/Update.bin"), &fileInfo);

    if (fatfsCode)
    {
        printf("error\r\n");
        USB_HostMsdFatfsTestDone();
        return;
    }

    USB_HostMsdFatfsDisplayFileInfo(&fileInfo);

    Remaining_size     = fileInfo.fsize;
    Packet_Total_lenth = fileInfo.fsize;

    printf("get file \"Update.bin\" length = %d \r\n", Packet_Total_lenth);

    Loop_count = 0;

    printf("Start iap file f_seek......");
    fatfsCode = f_lseek(&file, 0);

    if (fatfsCode)
    {
        printf("error\r\n");
        f_close(&file);
        USB_HostMsdFatfsTestDone();
        return;
    }

    Calculation_crc_result = CRC32_MPEG2_INIT;

    while (Remaining_size)             // lopp calculation checksum
    {
        if (Remaining_size >= WRITE_BUFF_SIZE)
        {
            Remaining_size   = Remaining_size - WRITE_BUFF_SIZE;
            Updatepacketsize = WRITE_BUFF_SIZE;
        }
        else
        {
            Updatepacketsize = Remaining_size;
            Remaining_size   = 0;
        }

        Loop_count++;

        fatfsCode = f_read(&file, Temp_read_buff, Updatepacketsize, (UINT *)&resultSize);

        if (fatfsCode)
        {
            printf("error\r\n");
            f_close(&file);
            USB_HostMsdFatfsTestDone();
            return;
        }

        printf("file f_read success\r\n");

        if (Remaining_size > 0)
        {
            Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)Temp_read_buff, Updatepacketsize, Calculation_crc_result);
        }
        else
        {
            Calculation_crc_result     = crc32_mpeg2_calculate((uint8_t *)Temp_read_buff, Updatepacketsize - 4, Calculation_crc_result);
            application_save_crc_value = Temp_read_buff[Updatepacketsize - 1];
            application_save_crc_value = application_save_crc_value << 8 | Temp_read_buff[Updatepacketsize - 2];
            application_save_crc_value = application_save_crc_value << 8 | Temp_read_buff[Updatepacketsize - 3];
            application_save_crc_value = application_save_crc_value << 8 | Temp_read_buff[Updatepacketsize - 4];
        }

        fatfsCode = f_lseek(&file, (Packet_Total_lenth - Remaining_size));

        if (fatfsCode)
        {
            printf("error\r\n");
            f_close(&file);
            USB_HostMsdFatfsTestDone();
            return;
        }

        printf("file f_seek success\r\n");
    }

    printf("file Read calculation CRC32= 0x%08x \r\n", Calculation_crc_result);
    printf("bin file Read CRC32= 0x%08x \r\n", application_save_crc_value);

    if (Calculation_crc_result != application_save_crc_value)
    {
        printf("Exception occurred while reading the file\r\n");
        USB_HostMsdFatfsTestDone();
        return;
    }

    //这段信息保存在1K Information 区间
    Application_block.Application_state = HEADER_VALUE;           //0x08006800
    Application_block.Application_lenth = Packet_Total_lenth - 4; //0x08006804
    Application_block.Application_CRC32 = Calculation_crc_result; //0x08006808

    Application_block.Application_StartAddr = ApplicationAddress; //0x0800680C
    Application_block.Application_version   = 0;                  //0x08006810

    Application_block.Information_CRC32 = 0;                      //0x08006BFC

    FileData_Block_buff[0] = *(volatile uint32_t *)(BootJumpFlagAddress);
    FileData_Block_buff[1] = *(volatile uint32_t *)(BootJumpFlagAddress + 4);
    FileData_Block_buff[2] = *(volatile uint32_t *)(BootJumpFlagAddress + 8);
    FileData_Block_buff[3] = *(volatile uint32_t *)(BootJumpFlagAddress + 0x0c);
    FileData_Block_buff[4] = *(volatile uint32_t *)(BootJumpFlagAddress + 0x10);
    FileData_Block_buff[5] = *(volatile uint32_t *)(ApplicationAddress - 4);

    printf("Read Information Space : %08x %08x %08x %08x %08x %08x\r\n",
           FileData_Block_buff[0],
           FileData_Block_buff[1],
           FileData_Block_buff[2],
           FileData_Block_buff[3],
           FileData_Block_buff[4],
           FileData_Block_buff[5]);

    if (FileData_Block_buff[2] != Application_block.Application_CRC32)
    {
        printf("Start Erase application\r\n");

        eraseAppSpace(APP_SIZE, ApplicationAddress);

        printf("Erase success\r\n");

        printf("Start Erase Information\r\n");

        clearAppInformationspace();

        printf("Erase success\r\n");

        // Write flash
        Remaining_size     = fileInfo.fsize;
        Packet_Total_lenth = fileInfo.fsize;

        printf("iap get file \"Update.bin\" length = %d \r\n", Packet_Total_lenth);

        Loop_count = 0;
        Operation_address = ApplicationAddress;

        fatfsCode = f_lseek(&file, 0);

        if (fatfsCode)
        {
            printf("error\r\n");
            f_close(&file);
            USB_HostMsdFatfsTestDone();
            return;
        }

        while (Remaining_size)         // lopp calculation checksum
        {
            if (Remaining_size >= WRITE_BUFF_SIZE)
            {
                Remaining_size   = Remaining_size - WRITE_BUFF_SIZE;
                Updatepacketsize = WRITE_BUFF_SIZE;
            }
            else
            {
                Updatepacketsize = Remaining_size;
                Remaining_size   = 0;
            }

            Loop_count++;

            fatfsCode = f_read(&file, Temp_read_buff, Updatepacketsize, (UINT *)&resultSize);

            if (fatfsCode)
            {
                printf("error\r\n");
                f_close(&file);
                USB_HostMsdFatfsTestDone();
                return;
            }

            printf("file f_read success\r\n");

            FLASH_Write(Temp_read_buff, Operation_address, Updatepacketsize);
            Operation_address = Operation_address + Updatepacketsize;

            printf("Flash write one packet success\r\n");

            fatfsCode = f_lseek(&file, (Packet_Total_lenth - Remaining_size));

            if (fatfsCode)
            {
                printf("error\r\n");
                f_close(&file);
                USB_HostMsdFatfsTestDone();
                return;
            }

            printf("file f_lseek success\r\n");
        }

        FLASH_Lock();

        //------------------------------------------------
        // Verify flash
        CRC32_check = crc32_mpeg2_calculate((uint8_t *)ApplicationAddress, Packet_Total_lenth - 4, CRC32_MPEG2_INIT);

        printf("CRC32 = 0x%x\r\n", CRC32_check);

        if (CRC32_check != application_save_crc_value)
        {
            USB_HostMsdFatfsTestDone();
            return;
        }

        printf("Start write information space\r\n");

        writeAppFlag();

        printf("Update success\r\n");

        printf("NVIC_SystemReset\r\n");

        NVIC_SystemReset();
    }
    else
    {
        printf("The upgrade files are identical, no update is required.\r\n");
    }

    printf("End of iap process\r\n");

    USB_HostMsdFatfsTestDone();
}

