////////////////////////////////////////////////////////////////////////////////
/// @file     main.c
/// @author   AE TEAM
/// @brief    Custom HID demo main file.
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
#define _MAIN_C_

// Files includes
#include "mm32_device.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_pwr.h"
#include "stdio.h"
#include "boot.h"
#include "uart.h"
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

extern __IO uint8_t gTxDataCnt;
extern u8 gTxData[VIRTUAL_COM_PORT_DATA_SIZE];
extern u8 gUartBuffCnt;

extern u8 status_UsbUart;
extern __IO u8 bIntPackSOF;
extern __IO uint8_t count_in;
extern u8 buffer_in[VIRTUAL_COM_PORT_DATA_SIZE];

void USB_SendGroup(uint8_t *pBuff, uint16_t length)
{
    UserToPMABufferCopy(pBuff, ENDP1, length);
    _SetUSB_CTRL1(EP1_CTRL_TRANEN | length);

    while ((_GetUSB_CTRL1() & EP1_CTRL_TRANEN) == EP1_CTRL_TRANEN)
    {
    }

    _SetUSB_CTRL1(EP1_CTRL_TRANEN | 0);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
/*Please using an External 8MHz Crystal Oscillator*/
int main(void)
{
  uint8_t flag[4];
  uint16_t len;
  uint32_t Read_address = 0x08000000;

  uint32_t Calculation_crc_result = 0;

  uint32_t Bootloader_crc_result = 0;
  uint32_t Information_crc_result = 0;
  uint32_t Application_crc_result = 0;
  uint32_t Application_lenth = 0;

  Bootloader_crc_result = *(volatile uint32_t *)(BootJumpFlagAddress - 4);
  Information_crc_result = *(volatile uint32_t *)(ApplicationAddress - 4);
  Application_crc_result = *(volatile uint32_t *)(BootJumpFlagAddress + 8);

  Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)Read_address, (BOOT_SIZE * 1024) - 4); // Bootloader CRC 校验
  if (Calculation_crc_result != Bootloader_crc_result)
  {
    // printf("Boot Error\r\n");
    while (1) // Bootloader CRC32校验失败
    {
    }
  }

  Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)BootJumpFlagAddress, 1024 - 4); // 1K Information CRC 校验
  if (Calculation_crc_result == Information_crc_result)
  {
    Application_lenth = *(volatile uint32_t *)(BootJumpFlagAddress + 4);
    if ((Application_lenth != 0xFFFFFFFF) && (Application_lenth <= (APP_SIZE * 1024))) // 获取 Application 程序区长度
    {
      Calculation_crc_result = crc32_mpeg2_calculate((uint8_t *)ApplicationAddress, Application_lenth); // Application CRC 校验
      if (Calculation_crc_result == Application_crc_result)
      {
        FLASH_Read(flag, BootJumpFlagAddress, 4);

        if ((flag[0] == 0x55) && (flag[1] == 0xAA) && (flag[2] == 0xAA) && (flag[3] == 0x55)) // 如果用户程序有效，则跳转到用户程序执行用户程序。
        {
          if (((*(__IO uint32_t *)ApplicationAddress) & SRAM_LEGAL_ADDRESS_MASK) == 0x20000000) // 检查栈顶地址是否SRAM合法
          {

            // Reset_Periph();//跳转之前，需要关闭boot初始化过的外设，避免导致跳到APP里面后boot里面的外设仍然在工作
            __disable_irq();
            __set_MSP(*(u32 *)ApplicationAddress);                     // 设置SP堆栈栈顶地址
            ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))(); // 生成跳转函数.将复位中断向量地址做为函数指针
          }
        }
      }
    }
  }

    DELAY_Init();
    CONSOLE_Init(115200);
    USB_GPIO_Config();
    USB_NVIC_Config();
    USB_Init();
  
    printf("MM32F0270 enter bootloader \r\n");

    while (1)
    {
        if (gTxDataCnt != 0)
        {
            boot_protocol(gTxData, gTxDataCnt);
            gTxDataCnt = 0;
        }
    }
}

/// @}

/// @}

/// @}

