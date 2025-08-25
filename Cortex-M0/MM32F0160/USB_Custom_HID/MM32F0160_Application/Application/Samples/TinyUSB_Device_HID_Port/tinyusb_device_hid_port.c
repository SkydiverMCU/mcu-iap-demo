/***********************************************************************************************************************
    @file    tinyusb_device_hid_port.c
    @author  FAE Team
    @date    23-Aug-2023
    @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Define to prevent recursive inclusion */
#define _TINYUSB_DEVICE_HID_PORT_C_

/* Files include */
#include <stdio.h>
#include "platform.h"
#include "tinyusb_device_hid_port.h"

/**
  * @addtogroup MM32F0160_LibSamples
  * @{
  */

/**
  * @addtogroup TinyUSB_Device
  * @{
  */

/**
  * @addtogroup TinyUSB_Device_HID_Port
  * @{
  */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/
uint8_t hid_upload_buff[64]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/
static void hid_task(void);
/* Private functions **************************************************************************************************/
void USB_DeviceClockInit(void)         //HSE 96M
{
    /* Select USBCLK source */
    RCC->CFGR &= ~(1 << 19);           //USB CLK SEL PLL1

    RCC->CFGR &= ~(0x03 << 22);
    RCC->CFGR |= 0x01 << 22;

    RCC_AHBPeriphClockCmd(RCC_AHBENR_USB, ENABLE);
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void TinyUSB_Device_Configure(void)
{
    USB_DeviceClockInit();             // board_init();

    // init device stack on configured roothub port
    tud_init(BOARD_TUD_RHPORT);   
}

/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void TinyUSB_Device_HID_Port_Sample(void)
{
    printf("\r\nTest %s", __FUNCTION__);

    TinyUSB_Device_Configure();

    while (1)
    {
        tud_task();                    // TinyUSB device task
        hid_task();
        PLATFORM_LED_Toggle(LED1);
        PLATFORM_LED_Toggle(LED2);
        PLATFORM_LED_Toggle(LED3);
        PLATFORM_LED_Toggle(LED4);
    }
}
// Every 10ms, we will sent 1 report for each HID profile (keyboard, mouse etc ..)
// tud_hid_report_complete_cb() is used to send the next report after previous one is complete
void hid_task(void)
{
  uint32_t const btn = 1u;

  // Remote wakeup
  if ( tud_suspended() && btn )
  {
    // Wake up host if we are in suspend mode
    // and REMOTE_WAKEUP feature is enabled by host
    tud_remote_wakeup();
  }else
  {
    // Send the 1st of report chain, the rest will be sent by tud_hid_report_complete_cb()
    tud_hid_n_report(0, 0x00, &hid_upload_buff, sizeof(hid_upload_buff)); //send_hid_report(REPORT_ID_MOUSE, btn);
  }
}
//--------------------------------------------------------------------+
// USB HID
//--------------------------------------------------------------------+

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen)
{
    // TODO not Implemented
    (void)itf;
    (void)report_id;
    (void)report_type;
    (void)buffer;
    (void)reqlen;

    return (0);
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize)
{
    // This example doesn't use multiple report and report ID
    (void)itf;
    (void)report_id;
    (void)report_type;

    // echo back anything we received from host
    tud_hid_report(0, buffer, bufsize);
}

// Invoked when sent REPORT successfully to host
// Application can use this to send the next report
// Note: For composite reports, report[0] is report ID
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const* report, uint16_t len) //void tud_hid_report_complete_cb(uint8_t itf, uint8_t const* report, uint8_t len)
{
  (void) instance;
  (void) report;
  (void) len;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/********************************************** (C) Copyright MindMotion **********************************************/

