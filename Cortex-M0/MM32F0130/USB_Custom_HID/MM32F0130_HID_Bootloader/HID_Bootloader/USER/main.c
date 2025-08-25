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
#include "hw_config.h"
#include "usbio.h"
#include "usb_regs.h"
#include "usb_pwr.h"
#include "boot.h"
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{
extern uint8_t Receive_Buffer[BUFF_SIZE];
extern __IO uint8_t gTxDataCnt;
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
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
/// @brief  This function is main entrance.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    uint8_t flag[4];
    uint16_t len;

    FLASH_Read(flag, BootJumpFlagAddress, 4);

    if ((flag[0] == 0x55) && (flag[1] == 0xAA) && (flag[2] == 0xAA) && (flag[3] == 0x55)) // 如果用户程序有效，则跳转到用户程序执行用户程序。
    {
        // Reset_Periph();//跳转之前，需要关闭boot初始化过的外设，避免导致跳到APP里面后boot里面的外设仍然在工作
        __disable_irq();
        __set_MSP(*(u32 *)ApplicationAddress);                     // 设置SP.，堆栈栈顶地址
        ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))(); // 生成跳转函数.将复位中断向量地址做为函数指针
    }

    GPIO_Configuration();
    USB_NVIC_Config();
    USB_ClockConfig();
    USB_Init();

    while (1)
    {
        if (gTxDataCnt != 0)
        {
            boot_protocol(Receive_Buffer, gTxDataCnt);
            gTxDataCnt = 0;
        }
    }
}

/// @}

/// @}

/// @}
