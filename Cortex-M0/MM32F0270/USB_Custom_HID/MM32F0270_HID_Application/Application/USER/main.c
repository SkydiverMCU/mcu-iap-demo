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
#include "hal_conf.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usbio.h"
#include "usb_regs.h"
#include "usb_pwr.h"
#include "string.h"
#include "app_protocol.h"
#include "delay.h"
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{
void USB_SendGroup(uint8_t *pBuff, uint16_t length)
{
    if (!(_GetUSB_CTRL1() & EP1_CTRL_TRANEN))
    {
        UserToPMABufferCopy(pBuff, ENDP1, length);
        _SetUSB_CTRL1(EP1_CTRL_TRANEN | length); // Loop IN transmission
    }
}
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
/*Please using an External 8MHz Crystal Oscillator*/
int main(void)
{
    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)(FLASH_BASE | APP_ADDRESS_OFFSET), VECTOR_SIZE);
    // Enable the SYSCFG Peripheral Clock
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG, ENABLE);
    // 将向量表映射到SRAM 0x20000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    DELAY_Init();

    // printf("MM32F0270 enter application \r\n");

    GPIO_Configuration();
    USB_NVIC_Config();
    USB_ClockConfig();
    USB_Init();

    while (1)
    {
        if (bDeviceState == CONFIGURED)
        {
            Receive_Protocol_Process(); // 添加HID，支持直接Application接收HID升级协议，跳转回Bootloader
        }
    }
}

/// @}

/// @}

/// @}
