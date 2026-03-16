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
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_pwr.h"
#include "stdio.h"
#include "string.h"
#include "delay.h"
#include "app_protocol.h"
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

extern u8 Receive_Buffer[VIRTUAL_COM_PORT_DATA_SIZE];
extern u8 gUartBuffCnt;

extern u8 status_UsbUart;
extern __IO u8 bIntPackSOF;
extern u32 count_in;
extern u8 buffer_in[VIRTUAL_COM_PORT_DATA_SIZE];

char printBuf[128];

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
uint32_t loop_cnt = 0;
/*Please using an External 8MHz Crystal Oscillator*/
int main(void)
{
    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)(FLASH_BASE | APP_ADDRESS_OFFSET), VECTOR_SIZE);
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG, ENABLE);

    // 将向量表映射到SRAM 0x20000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    DELAY_Init();

    UART_GPIO_Config();
    USB_GPIO_Config();
    UART_NVIC_Config();
    UART_ConfigDefault(); // 115200bps

    printf("MM32F0270 enter application \r\n");

    USB_NVIC_Config();
    USB_Init();

    while (1)
    {
        if (bDeviceState == CONFIGURED)
        {
            Receive_Protocol_Process(); // 添加虚拟串口，支持直接Application接收虚拟串口升级协议，跳转回Bootloader。当MCU在APP软复位回到Boot后USB会重新枚举虚拟串口，上位机需要重新打开虚拟串口才能通讯
        }
    }
}

/// @}

/// @}

/// @}
