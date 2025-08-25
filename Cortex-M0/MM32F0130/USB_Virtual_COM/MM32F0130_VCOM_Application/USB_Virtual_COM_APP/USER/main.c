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
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

#define APPLICATION_ADDRESS (uint32_t)(0x08003000) // APP START ADDRESS
#define VECTOR_SIZE 0xC0

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

extern __IO u32 gTxDataCnt;
extern u8 gTxData[VIRTUAL_COM_PORT_DATA_SIZE];
extern u8 gUartBuffCnt;

extern u8 status_UsbUart;
extern __IO u8 bIntPackSOF;
extern u32 count_in;
extern u8 buffer_in[VIRTUAL_COM_PORT_DATA_SIZE];

char printBuf[128];

/*You can directly use this interface to printf debug messages, which will then be transmitted to the PC via the USB-enumerated virtual COM port*/
void USB_UartPrintf(u8 *buf, u16 len)
{
    status_UsbUart |= 1 << 5;

    while (len--)
    {
        // Send the received data to the PC Host
        buffer_in[count_in] = *buf++;

        if (count_in < VIRTUAL_COM_PORT_DATA_SIZE)
        {
            count_in++;
        }
    }

    bIntPackSOF = 0;
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
    uint8_t i;
    
    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)APPLICATION_ADDRESS, VECTOR_SIZE);
    //Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
    
	//将向量表映射到SRAM 0x20000000
	SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
	__enable_irq();	
    UART_GPIO_Config();
    USB_GPIO_Config();
    UART_NVIC_Config();
    UART_ConfigDefault(); //115200bps
    
    printf("Enter application success...\r\n");
    
    USB_NVIC_Config();
    USB_Init();

    while (1)
    {
        if ((gTxDataCnt != 0) && (bDeviceState == CONFIGURED)) //UART1 to USB
        {
            USB_To_UART_Send_Data(gTxData, &gUartBuffCnt);
        }

        if (bDeviceState == CONFIGURED) //print to USB VCOM
        {
            loop_cnt++;

            if (loop_cnt == 70000)
            {
                loop_cnt = 0;
                USB_UartPrintf((u8 *)printBuf, sprintf(printBuf, "\r\n Printf test through USB to PC \r\n"));
            }
        }
    }
}

/// @}

/// @}

/// @}

