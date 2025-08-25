#ifndef _BOOT_H_
#define _BOOT_H_

/* Files include */
#include "hal_conf.h"

#define BOOT_SIZE   15
#define FLASH_SIZE  512  //128K

#define BootJumpFlagAddress (BOOT_SIZE * 1024 + 0x8000000)
#define ApplicationAddress (BootJumpFlagAddress + 1024)

#define APP_SIZE (FLASH_SIZE - BOOT_SIZE - 1) // 496KB flash for app

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

extern const u8 Valid_buf[4];

extern u8 USB_RxBuf[64];
extern u16 USB_RxLen;
extern u8 USB_RxFlag;

void boot_protocol(u8 *buff, u16 len);
void FLASH_Read(u8 *buff, u32 addr, u32 readNumber);

#endif
