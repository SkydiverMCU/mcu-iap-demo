////////////////////////////////////////////////////////////////////////////////
/// @file     hw_config.C
/// @author   AE TEAM
/// @brief    Hardware Configuration & Setup.
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

// Define to prevent recursive inclusion  --------------------------------------
#define _HW_CONFIG_C_

// Files includes  -------------------------------------------------------------
#include "mm32_device.h"
#include "platform_config.h"
#include "hw_config.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"
#include "hal_rcc.h"
#include "hal_misc.h"
#include "hal_exti.h"
#include "hal_gpio.h"
#include "hal_adc.h"
#include "hal_uart.h"
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup USB_HAL
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup USB_Exported_Functions
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  Configures Main system clocks & power.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void Set_System(void)
{
    // Configure the used GPIOs
    GPIO_Configuration();
}


//*******************************************************************
////////////////////////////////////////////////////////////////////////////////
/// @brief  Configures USB Clock input (48MHz)..
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void USB_ClockConfig(void)
{
    // Select USBCLK source
    RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_Div1);
    // Enable USB clock
    RCC_APB1PeriphClockCmd(RCC_APB1ENR_USB, ENABLE);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Power-off system clocks and power while entering suspend mode.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void Enter_LowPowerMode(void)
{
    // Set the device state to suspend
    bDeviceState = SUSPENDED;
}
////////////////////////////////////////////////////////////////////////////////
/// @brief  Restores system clocks and power while exiting suspend mode.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void Leave_LowPowerMode(void)
{
    DEVICE_INFO* pInfo = &Device_Info;

    // Set the device state to the correct state
    if (pInfo->Current_Configuration != 0) {
        // Device configured
        bDeviceState = CONFIGURED;
    }
    else {
        bDeviceState = ATTACHED;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Configures the USB interrupts.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void USB_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;

    NVIC_InitStruct.NVIC_IRQChannel = USB_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

}


////////////////////////////////////////////////////////////////////////////////
/// @brief  Software Connection/Disconnection of USB Cable.
/// @param  NewState: new state.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void USB_Cable_Config (FunctionalState NewState)
{
    if (NewState != DISABLE) {
        _SetUSB_TOP(USB_TOP_CONNECT);
    }
    else {
        _ClrUSB_TOP(USB_TOP_CONNECT);
        // (USB->TOP  &= 0x02);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Configures the different GPIO ports.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct);
    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIO_DISCONNECT, ENABLE);

    // USB_DISCONNECT used as USB pull-up
    GPIO_InitStruct.GPIO_Pin = USB_DISCONNECT_PIN;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(USB_DISCONNECT, &GPIO_InitStruct);

}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Create the serial number string descriptor.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void Get_SerialNum(void)
{
    u32 Device_Serial0, Device_Serial1, Device_Serial2;

    Device_Serial0 = *(u32*)(0x1FFFF7E8);
    Device_Serial1 = *(u32*)(0x1FFFF7EC);
    Device_Serial2 = *(u32*)(0x1FFFF7F0);

    if(Device_Serial0 != 0) {
        CustomHID_StringSerial[2] = (u8)(Device_Serial0 & 0x000000FF);
        CustomHID_StringSerial[4] = (u8)((Device_Serial0 & 0x0000FF00) >> 8);
        CustomHID_StringSerial[6] = (u8)((Device_Serial0 & 0x00FF0000) >> 16);
        CustomHID_StringSerial[8] = (u8)((Device_Serial0 & 0xFF000000) >> 24);

        CustomHID_StringSerial[10] = (u8)(Device_Serial1 & 0x000000FF);
        CustomHID_StringSerial[12] = (u8)((Device_Serial1 & 0x0000FF00) >> 8);
        CustomHID_StringSerial[14] = (u8)((Device_Serial1 & 0x00FF0000) >> 16);
        CustomHID_StringSerial[16] = (u8)((Device_Serial1 & 0xFF000000) >> 24);

        CustomHID_StringSerial[18] = (u8)(Device_Serial2 & 0x000000FF);
        CustomHID_StringSerial[20] = (u8)((Device_Serial2 & 0x0000FF00) >> 8);
        CustomHID_StringSerial[22] = (u8)((Device_Serial2 & 0x00FF0000) >> 16);
        CustomHID_StringSerial[24] = (u8)((Device_Serial2 & 0xFF000000) >> 24);
    }
}
/// @}

/// @}

/// @}
