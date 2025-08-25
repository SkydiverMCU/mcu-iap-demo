/***********************************************************************************************************************
    @file    main.c
    @author  FD Team
    @date    22-March-2024
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
#define _MAIN_C_

/* Files include */
#include "platform.h"
#include "tinyusb_device_hid_inout.h"
#include "main.h"
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

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/
/*请注意/Please note*/
/*修改 Bootloader 和 Application Flash空间大小分配，请到Options for Target -> Linker -> ..\..\..\..\Device\MM32F5270\Source\MM32F5270.sct  分散加载文件里面去修改*/
/*To modify the allocation of Bootloader and Application Flash space, please go to Options for Target -> Linker -> ..\..\..\..\Device\MM32F5270\Source\MM32F5270.sct in the scatter-loading file to make the changes.*/
#define APP_ADDRESS_OFFSET 0x4000
/***********************************************************************************************************************
  * @brief  This function is main entrance
  * @note   main
  * @param  none
  * @retval none
  *********************************************************************************************************************/
/*Please using an External 8MHz Crystal Oscillator*/
int main(void)
{
    SCB->VTOR = FLASH_START_ADDR | APP_ADDRESS_OFFSET; // STAR-MC1可以对中断向量进行偏移，这样app的中断可以直接跳到自己的中断服务函数
    __enable_irq();                              // 跳转之后要确保打开总中断
	
    PLATFORM_Init();

    TinyUSB_Device_Configure();

    while (1)
    {
		tud_task(); // TinyUSB device task
        hid_task();		
    }
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

