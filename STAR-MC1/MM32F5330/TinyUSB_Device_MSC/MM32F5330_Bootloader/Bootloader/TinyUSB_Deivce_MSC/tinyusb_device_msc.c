/***********************************************************************************************************************
    @file    tinyusb_device_msc.c
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
#define _TINYUSB_DEVICE_MSC_C_

/* Files include */
#include <stdio.h>
#include "platform.h"

#include "bsp/board_api.h"
#include "tinyusb_device_msc.h"
#include "usb_descriptors.h"
#include "spi_master_flash_polling.h"
#include "tim6_timebase.h"
#include "gpio_key_input.h"

#define KEY_INPUT  ((GPIOC->IDR & GPIO_Pin_4) >> GPIO_PinSource4)

/**
 * @addtogroup MM32F5330_TinyUSB
 * @{
 */

/**
 * @addtogroup TinyUSB_Device
 * @{
 */

/**
 * @addtogroup TinyUSB_Device_MSC
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
  //tud_init(BOARD_TUD_RHPORT);
  // init device stack on configured roothub port
    // init device stack on configured roothub port
  tud_init(BOARD_TUD_RHPORT);   
}

uint16_t MSC_Idle_count = 0;
uint8_t List_file_state = 0;

void TIM6_Update_callback(void)
{
    TIM6_UpdateFlag = 1;
    
    if(is_lun_busy == true)
    {
       MSC_Idle_count = 0;
       List_file_state = 0;        
    }
}
/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void TinyUSB_Mass_Storage_Sample(void)
{    
    SPI_Master_FLASH_Polling_Sample(); //25Q64

    TinyUSB_Device_Configure();
    
    TIM6_Configure();
    
    KEY_GPIO_Configure();

    while (1)
    {
        tud_task(); // tinyusb device task

        if (0 != TIM6_UpdateFlag)
        {
            TIM6_UpdateFlag = 0;

            if (KEY_INPUT == 0)        //当按键一直按下为高，则不读取U盘文件，等待拖入新的Update.bin文件
            {
                if (is_lun_busy == false)
                {
                    if (MSC_Idle_count > 1000)
                    {
                        if (List_file_state == 0)
                        {
                            USB_HostMsdFatfsUserReadWrite();
                            List_file_state = 1;
                        }
                    }
                    else
                    {
                        MSC_Idle_count++;
                    }
                }
            }
         }
        
     }
}

/*

指令代码	指令名称				指令说明

0x00	    Test Unit Ready			查询设备是否ready
0x03	    Request Sense			主机请求设备返回执行结果，及获取状态信息
0x12		Inquiry					获取设备信息
0x1A		Mode Sense(6)			向host传输参数
0x5A		Mode Sense(10)			向host传输参数
0x25		Read Capacity(10)		读取设备容量
0x28		Read(10)				Host从设备读取数据
0x2A		Write(10)				Host写数据到存储设备
0x23		Read Format Capacity	查询当前容量及可用空间
0x15		Mode Select(6)			允许Host对外部设备设置参数
0x55		Mode Select(10)			允许Host对外部设备设置参数
0x1E		Prevent/Allow Medium Removal	禁止/允许存储介质移动
0x1B		Start/Stop Uint			启动/停止存储单元电源( 写保护 )
0xA0		Report LUNs				索取设备的LUN数和LUN清单
0x2F		Verify					在存储中验证数据

*/

//--------------------------------------------------------------------+
// Device callbacks
//--------------------------------------------------------------------+

// Invoked when device is mounted
void tud_mount_cb(void) {
  blink_interval_ms = BLINK_MOUNTED;
}

// Invoked when device is unmounted
void tud_umount_cb(void) {
  blink_interval_ms = BLINK_NOT_MOUNTED;
}

// Invoked when usb bus is suspended
// remote_wakeup_en : if host allow us  to perform remote wakeup
// Within 7ms, device must draw an average of current less than 2.5 mA from bus
void tud_suspend_cb(bool remote_wakeup_en) {
  (void)remote_wakeup_en;
  blink_interval_ms = BLINK_SUSPENDED;
}

// Invoked when usb bus is resumed
void tud_resume_cb(void) {
  blink_interval_ms = tud_mounted() ? BLINK_MOUNTED : BLINK_NOT_MOUNTED;
}



//--------------------------------------------------------------------+
// BLINKING TASK
//--------------------------------------------------------------------+
void led_blinking_task(void)
{
//  static uint32_t start_ms = 0;
//  static bool led_state = false;

//  // Blink every interval ms
//  if (board_millis() - start_ms < blink_interval_ms)
//    return; // not enough time
//  start_ms += blink_interval_ms;

//  board_led_write(led_state);
//  led_state = 1 - led_state; // toggle
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
