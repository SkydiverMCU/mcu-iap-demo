/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ffconf.h"
/* This fatfs subcomponent is disabled by default
  * To enable it, define following macro in ffconf.h */
#ifdef USB_DISK_ENABLE

  #include "fsl_usb_disk.h"            /* FatFs lower layer API */

  #include "spi_master_flash_polling.h"
  #include "stdio.h"
  #include "string.h"
/*******************************************************************************
  * Definitons
  ******************************************************************************/
uint8_t USB_HostMsdRead10(uint8_t                           classHandle,
                          uint8_t                           logicalUnit,
                          uint32_t                          blockAddress,
                          uint8_t                          *buffer,
                          uint32_t                          bufferLength,
                          uint32_t                          blockNumber,
                          uint8_t                           nall,
                          void                             *callbackParam)
{
    // 忽略 USB 主机相关的参数 (classHandle, logicalUnit 等)
    (void)classHandle;
    (void)logicalUnit;

    // 计算 Flash 物理地址 (假设 blockAddress 为 LBA，每个块 512 字节)
    uint32_t flash_addr     = blockAddress * FLASH_BLOCK_SIZE;
    uint32_t total_len      = bufferLength; // 总期望读取字节数
    uint32_t blocks_to_read = blockNumber;  // 要读取的块数（一般 blockNumber * 512 = bufferLength）

    // 可选：校验长度一致性
    if ((blocks_to_read * FLASH_BLOCK_SIZE) != total_len)
    {
        // 长度不匹配，根据实际情况处理，这里假设上层保证正确
    }

    // 调用 SPI Flash 读取函数（同步读取）
    // 注意：SPI_FLASH_FastRead 需要实现为从 flash_addr 读取 total_len 字节到 buffer
    SPI_FLASH_FastRead(flash_addr, buffer, total_len);

    return (0);
}

uint8_t USB_HostMsdWrite10(uint8_t                            classHandle,
                           uint8_t                            logicalUnit,
                           uint32_t                           blockAddress,
                           uint8_t                           *buffer,
                           uint32_t                           bufferLength,
                           uint32_t                           blockNumber,
                           uint8_t                            nall,
                           void                              *callbackParam)
{
    (void)classHandle;
    (void)logicalUnit;

    // 计算写入的起始物理地址和总长度
    uint32_t start_addr = blockAddress * FLASH_BLOCK_SIZE;
    uint32_t total_len  = bufferLength; // 一般等于 blockNumber * FLASH_BLOCK_SIZE

    // 缓存扇区（使用静态或全局 buffer，注意重入问题）
    static uint8_t sector_buf[FLASH_SECTOR_SIZE];

    // 处理可能跨越多个 4K 扇区的写入
    uint32_t remain_len = total_len;
    uint32_t cur_addr   = start_addr;
    uint8_t *cur_data   = buffer;

    while (remain_len > 0)
    {
        // 1. 确定当前地址所在的 4K 扇区
        uint32_t sector_start     = cur_addr & ~(FLASH_SECTOR_SIZE - 1);
        uint32_t offset_in_sector = cur_addr - sector_start;
        uint32_t write_len = FLASH_SECTOR_SIZE - offset_in_sector;

        if (write_len > remain_len)
        {
            write_len = remain_len;
        }

        // 2. 读取整个 4K 扇区到缓存
        SPI_FLASH_FastRead(sector_start, sector_buf, FLASH_SECTOR_SIZE);

        // 3. 擦除整个 4K 扇区
        SPI_FLASH_SectorErase(sector_start);

        // 4. 修改缓存中的数据
        memcpy(sector_buf + offset_in_sector, cur_data, write_len);

        // 5. 将 4K 缓存按 256 字节一页写入 Flash
        uint32_t w_addr = sector_start;
        uint8_t *p_buf  = sector_buf;

        for (int Cycle = 0; Cycle < (FLASH_SECTOR_SIZE / FLASH_PAGE_SIZE); Cycle++)
        {
            SPI_FLASH_PageProgram(w_addr, p_buf, FLASH_PAGE_SIZE);
            w_addr += FLASH_PAGE_SIZE;
            p_buf  += FLASH_PAGE_SIZE;
        }

        // 更新剩余长度和指针
        remain_len -= write_len;
        cur_addr   += write_len;
        cur_data   += write_len;
    }

    return (0);
}

/*******************************************************************************
  * Prototypes
  ******************************************************************************/

/*!
  * @brief host msd ufi command callback.
  *
  * This function is used as callback function for ufi command .
  *
  * @param param      NULL.
  * @param data       data buffer pointer.
  * @param dataLength data length.
  * @status           transfer result status.
  */
static volatile uint8_t ufiIng;
static uint32_t s_FatfsSectorSize;

/*******************************************************************************
  * Variables
  ******************************************************************************/

/*******************************************************************************
  * Code
  ******************************************************************************/
DSTATUS USB_HostMsdInitializeDisk(BYTE pdrv)
{
    s_FatfsSectorSize = 512;
    return (0x00);
}

DSTATUS USB_HostMsdGetDiskStatus(BYTE pdrv)
{
    return (0x00);
}

DRESULT USB_HostMsdReadDisk(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)
{
    DRESULT fatfs_code = RES_ERROR;
    //usb_status_t status = kStatus_USB_Success;
    uint32_t retry = USB_HOST_FATFS_RW_RETRY_TIMES;
    uint8_t *transferBuf;
    uint32_t sectorCount;
    uint32_t sectorIndex;

    if (!count)
    {
        return (RES_PARERR);
    }

    transferBuf = buff;
    sectorCount = count;
    sectorIndex = sector;

    retry = USB_HOST_FATFS_RW_RETRY_TIMES;

    while (retry--)
    {
        ufiIng = 1;

        USB_HostMsdRead10(0, 0, sectorIndex, (uint8_t *)transferBuf, (uint32_t)(s_FatfsSectorSize * sectorCount), sectorCount, 0, 0);
        fatfs_code = RES_OK;
        break;
    }

    return (fatfs_code);
}

DRESULT USB_HostMsdWriteDisk(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)
{
    DRESULT fatfs_code = RES_ERROR;
    //usb_status_t status = kStatus_USB_Success;
    uint32_t retry = USB_HOST_FATFS_RW_RETRY_TIMES;
    const uint8_t *transferBuf;
    uint32_t sectorCount;
    uint32_t sectorIndex;

    if (!count)
    {
        return (RES_PARERR);
    }

    transferBuf = buff;
    sectorCount = count;
    sectorIndex = sector;

    retry = USB_HOST_FATFS_RW_RETRY_TIMES;

    while (retry--)
    {
        ufiIng = 1;

        USB_HostMsdWrite10(0, 0, sectorIndex, (uint8_t *)transferBuf, (uint32_t)(s_FatfsSectorSize * sectorCount), sectorCount, 0, 0);
    }

    fatfs_code = RES_OK;
    return (fatfs_code);
}

DRESULT USB_HostMsdIoctlDisk(BYTE pdrv, BYTE cmd, void *buff)
{
    (void)pdrv;                        // 未使用，避免警告

    DRESULT fatfs_code = RES_OK;
    uint32_t value;

    switch (cmd)
    {
        case GET_SECTOR_COUNT:         // 返回总扇区数（DWORD）

            if (!buff)
            {
                return (RES_ERROR);
            }

            value = DISK_BLOCK_NUM;
            // 以小端字节序填充（FatFS 通常需要小端，此处按原代码风格保持与之前一致）
            ((uint8_t *)buff)[0] = (uint8_t)(value >> 0);
            ((uint8_t *)buff)[1] = (uint8_t)(value >> 8);
            ((uint8_t *)buff)[2] = (uint8_t)(value >> 16);
            ((uint8_t *)buff)[3] = (uint8_t)(value >> 24);
            fatfs_code = RES_OK;
            break;

        case GET_SECTOR_SIZE:          // 返回扇区大小（字节）

            if (!buff)
            {
                return (RES_ERROR);
            }

            value = DISK_BLOCK_SIZE;   // 通常为 512
            ((uint8_t *)buff)[0] = (uint8_t)(value >> 0);
            ((uint8_t *)buff)[1] = (uint8_t)(value >> 8);
            ((uint8_t *)buff)[2] = (uint8_t)(value >> 16);
            ((uint8_t *)buff)[3] = (uint8_t)(value >> 24);
            fatfs_code = RES_OK;
            break;

        case GET_BLOCK_SIZE:           // 返回擦除块大小（通常与扇区相同或 1）

            if (!buff)
            {
                return (RES_ERROR);
            }

            *(uint32_t *)buff = 1;     // 或 DISK_BLOCK_SIZE，取决于 FatFS 配置
            fatfs_code = RES_OK;
            break;

        case CTRL_SYNC:                // 同步缓存（Flash 通常无需额外操作）
            fatfs_code = RES_OK;
            break;

        default:
            fatfs_code = RES_PARERR;
            break;
    }

    return (fatfs_code);
}

#endif /* USB_DISK_ENABLE */

