/***********************************************************************************************************************
    @file    tinyusb_device_hid_port.c
    @author  FD Team
    @date    15-March-2024
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
#define _TINYUSB_DEVICE_HID_COMP_C_

/* Files include */
#include <stdio.h>
#include "platform.h"

#include "bsp/board_api.h"
#include "tinyusb_device_hid_comp.h"
#include "usb_descriptors.h"

/**
 * @addtogroup MM32F5270_TinyUSB
 * @{
 */

/**
 * @addtogroup TinyUSB_Device
 * @{
 */

/**
 * @addtogroup TinyUSB_Device_HID_Comp
 * @{
 */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/
/* Blink pattern
 * - 250 ms  : device not mounted
 * - 1000 ms : device mounted
 * - 2500 ms : device is suspended
 */
enum
{
  BLINK_NOT_MOUNTED = 250,
  BLINK_MOUNTED = 1000,
  BLINK_SUSPENDED = 2500,
};
/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/
static uint32_t blink_interval_ms = BLINK_NOT_MOUNTED;
void led_blinking_task(void);
static void hid_task(void);
/* Private functions **************************************************************************************************/
/***********************************************************************************************************************
 * @brief  TinyUSB Device Configure
 * @note   none
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void TinyUSB_Device_Configure(void)
{
  USB_DeviceClockInit();

  // init device stack on configured roothub port
  tud_init(BOARD_TUD_RHPORT);
}

/***********************************************************************************************************************
 * @brief  tud mount cb.
 * @note   Invoked when device is mounted
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void tud_mount_cb(void)
{
  blink_interval_ms = BLINK_MOUNTED;
}

/***********************************************************************************************************************
 * @brief  tud umount cb.
 * @note   Invoked when device is unmounted
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void tud_umount_cb(void)
{
  blink_interval_ms = BLINK_NOT_MOUNTED;
}

/***********************************************************************************************************************
 * @brief  tud suspend cb.
 * @note   Invoked when usb bus is suspended
 * @param  remote_wakeup_en : if host allow us  to perform remote wakeup
 *         Within 7ms, device must draw an average of current less than 2.5 mA from bus
 * @retval none
 *********************************************************************************************************************/
void tud_suspend_cb(bool remote_wakeup_en)
{
  (void)remote_wakeup_en;
  blink_interval_ms = BLINK_SUSPENDED;
}

/***********************************************************************************************************************
 * @brief  tud resume cb.
 * @note   Invoked when usb bus is resumed
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void tud_resume_cb(void)
{
  blink_interval_ms = BLINK_MOUNTED;
}

/***********************************************************************************************************************
 * @brief  send_hid_report.
 * @note
 * @param  report_id
 * @param  btn
 * @retval none
 *********************************************************************************************************************/
static void send_hid_report(uint8_t report_id, uint32_t btn)
{
  // skip if hid is not ready yet
  if (!tud_hid_ready())
    return;

  switch (report_id)
  {
  case REPORT_ID_KEYBOARD:
  {
    // use to avoid send multiple consecutive zero report for keyboard
    static bool has_keyboard_key = false;

    if (btn)
    {
      uint8_t keycode[6] = {0};
      keycode[0] = HID_KEY_A;

      tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, keycode);
      has_keyboard_key = true;
    }
    else
    {
      // send empty key report if previously has key pressed
      if (has_keyboard_key)
        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, NULL);
      has_keyboard_key = false;
    }
  }
  break;

  case REPORT_ID_MOUSE:
  {
    int8_t const delta = 5;

    // no button, right + down, no scroll, no pan
    tud_hid_mouse_report(REPORT_ID_MOUSE, 0x00, delta, delta, 0, 0);
  }
  break;

  case REPORT_ID_CONSUMER_CONTROL:
  {
    // use to avoid send multiple consecutive zero report
    static bool has_consumer_key = false;

    if (btn)
    {
      // volume down
      uint16_t volume_down = HID_USAGE_CONSUMER_VOLUME_DECREMENT;
      tud_hid_report(REPORT_ID_CONSUMER_CONTROL, &volume_down, 2);
      has_consumer_key = true;
    }
    else
    {
      // send empty key report (release key) if previously has key pressed
      uint16_t empty_key = 0;
      if (has_consumer_key)
        tud_hid_report(REPORT_ID_CONSUMER_CONTROL, &empty_key, 2);
      has_consumer_key = false;
    }
  }
  break;

  case REPORT_ID_GAMEPAD:
  {
    // use to avoid send multiple consecutive zero report for keyboard
    static bool has_gamepad_key = false;

    hid_gamepad_report_t report =
        {
            .x = 0, .y = 0, .z = 0, .rz = 0, .rx = 0, .ry = 0, .hat = 0, .buttons = 0};

    if (btn)
    {
      report.hat = GAMEPAD_HAT_UP;
      report.buttons = GAMEPAD_BUTTON_A;
      tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));

      has_gamepad_key = true;
    }
    else
    {
      report.hat = GAMEPAD_HAT_CENTERED;
      report.buttons = 0;
      if (has_gamepad_key)
        tud_hid_report(REPORT_ID_GAMEPAD, &report, sizeof(report));
      has_gamepad_key = false;
    }
  }
  break;

  default:
    break;
  }
}

/***********************************************************************************************************************
 * @brief  hid task.
 * @note   Every 10ms, we will sent 1 report for each HID profile (keyboard, mouse etc ..)
 * @note   tud_hid_report_complete_cb() is used to send the next report after previous one is complete
 * @param  none
 * @retval none
 *********************************************************************************************************************/
void hid_task(void)
{
  // Poll every 10ms
  const uint32_t interval_ms = 10;
  static uint32_t start_ms = 0;

  if (board_millis() - start_ms < interval_ms)
    return; // not enough time
  start_ms += interval_ms;

  uint32_t const btn = board_button_read();

  // Remote wakeup
  if (tud_suspended() && btn)
  {
    // Wake up host if we are in suspend mode
    // and REMOTE_WAKEUP feature is enabled by host
    tud_remote_wakeup();
  }
  else
  {
    // Send the 1st of report chain, the rest will be sent by tud_hid_report_complete_cb()
    send_hid_report(REPORT_ID_KEYBOARD, btn);
  }
}

// Invoked when sent REPORT successfully to host
// Application can use this to send the next report
// Note: For composite reports, report[0] is report ID
void tud_hid_report_complete_cb(uint8_t instance, uint8_t const *report, uint16_t len)
{
  (void)instance;
  (void)len;

  uint8_t next_report_id = report[0] + 1u;

  if (next_report_id < REPORT_ID_COUNT)
  {
    send_hid_report(next_report_id, board_button_read());
  }
}

/***********************************************************************************************************************
 * @brief  tud hid get report callback.
 * @note   Invoked when received GET_REPORT control request
 * @note   Application must fill buffer report's content and return its length.
 * @param  itf
 * @param  report_id
 * @param  report_type
 * @param  reqlen
 * @retval 0.
 *********************************************************************************************************************/
uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen)
{
  // TODO not Implemented
  (void)itf;
  (void)report_id;
  (void)report_type;
  (void)buffer;
  (void)reqlen;
  USB_RxLen = reqlen;
  memcpy(USB_RxBuf, buffer, USB_RxLen);
  USB_RxFlag = 1;
  return (0);
}

/***********************************************************************************************************************
 * @brief  tud hid set report callback.
 * @note   Invoked when received SET_REPORT control request or
 * @note   received data on OUT endpoint ( Report ID = 0, Type = 0 )
 * @param  itf
 * @param  report_id
 * @param  report_type
 * @param  buffer
 * @param  bufsize
 * @retval none.
 *********************************************************************************************************************/
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize)
{
  (void)instance;

  if (report_type == HID_REPORT_TYPE_OUTPUT)
  {
    // Set keyboard LED e.g Capslock, Numlock etc...
    if (report_id == REPORT_ID_KEYBOARD)
    {
      // bufsize should be (at least) 1
      if (bufsize < 1)
        return;

      uint8_t const kbd_leds = buffer[0];

      if (kbd_leds & KEYBOARD_LED_CAPSLOCK)
      {
        // Capslock On: disable blink, turn led on
        blink_interval_ms = 0;
        board_led_write(true);
      }
      else
      {
        // Caplocks Off: back to normal blink
        board_led_write(false);
        blink_interval_ms = BLINK_MOUNTED;
      }
    }
  }
}

/***********************************************************************************************************************
 * @brief  tud hid report complete callback.
 * @note   Invoked when sent REPORT successfully to host
 * @note   Application can use this to send the next report
 * @note   For composite reports, report[0] is report ID
 * @param  instance
 * @param  report
 * @param  len
 * @retval none.
 *********************************************************************************************************************/
void led_blinking_task(void)
{
  static uint32_t start_ms = 0;
  static bool led_state = false;

  // blink is disabled
  if (!blink_interval_ms)
    return;

  // Blink every interval ms
  if (board_millis() - start_ms < blink_interval_ms)
    return; // not enough time
  start_ms += blink_interval_ms;

  board_led_write(led_state);
  led_state = 1 - led_state; // toggle
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
