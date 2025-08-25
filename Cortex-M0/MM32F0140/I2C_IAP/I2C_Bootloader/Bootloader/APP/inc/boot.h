////////////////////////////////////////////////////////////////////////////////
/// @file    boot.h
/// @author  AE TEAM
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FIRMWARE FUNCTIONS.
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
#ifndef _BOOT_H_
#define _BOOT_H_

// Files includes

#include "hal_device.h"
#include "hal_conf.h"
#include "stdio.h"

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Example_Layer
/// @brief MM32 Example Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_RESOURCE
/// @brief MM32 Examples resource modules
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Constants
/// @{

#define FLASH_SIZE 64                         // 单位Kb
#define RAM_SIZE 8                            // 单位Kb
#define BOOT_SIZE 4                           // 单位Kb
#define APP_SIZE (FLASH_SIZE - BOOT_SIZE - 1) // flash for app

#define AppInfoAreaAddress (0x8000000 + BOOT_SIZE * 1024) // APP信息区
#define ApplicationAddress (1024 + AppInfoAreaAddress)

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

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Enumeration
/// @{
typedef struct
{
    u32 BlockStartAddr;
    u32 BlockLength;
    u32 BlockCheckSum;
} FileData_Block;
////////////////////////////////////////////////////////////////////////////////
/// @brief XXXX enumerate definition.
/// @anchor XXXX
////////////////////////////////////////////////////////////////////////////////

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Variables
/// @{
#ifdef _BOOT_C_
#define GLOBAL

#else
#define GLOBAL extern

#endif

// GLOBAL app_info_structure appinfo;

#undef GLOBAL

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Functions
/// @{

void boot_protocol(void);
void FLASH_Read(u8 *buff, u32 addr, u32 readNumber);
uint32_t CRC_Caculation(uint32_t FlashStartAddr, uint32_t length);
uint32_t App_CheckSum(uint32_t FlashStartAddr, uint32_t length);
void eraseAppSpace(u8 *buff);
void clearAppFlag(u8 *buff);

/// @}

/// @}

/// @}

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
