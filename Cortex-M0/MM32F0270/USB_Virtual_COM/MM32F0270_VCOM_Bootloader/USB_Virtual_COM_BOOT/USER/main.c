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

    FLASH_Read(flag, BootJumpFlagAddress, 4);

    if ((flag[0] == 0x55) && (flag[1] == 0xAA) && (flag[2] == 0xAA) && (flag[3] == 0x55)) // 如果用户程序有效，则跳转到用户程序执行用户程序。
    {
        __disable_irq();
        __set_MSP(*(u32 *)ApplicationAddress);                                            // 设置SP.，堆栈栈顶地址
        ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))();                        // 生成跳转函数.将复位中断向量地址做为函数指针
    }

    DELAY_Init();
    CONSOLE_Init(115200);
    USB_GPIO_Config();
    USB_NVIC_Config();
    USB_Init();
    printf("Enter Bootloader...\r\n");

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

