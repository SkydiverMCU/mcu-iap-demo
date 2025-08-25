/***********************************************************************************************************************
    @file    main.c
    @author  FAE Team
    @date    18-Apr-2023
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
// #include "platform.h"
#include "main.h"
#include "i2c.h"
#include "boot.h"

/**
 * @addtogroup MM32G0001_LibSamples
 * @{
 */

/**
 * @addtogroup GPIO
 * @{
 */

/**
 * @addtogroup GPIO_LED_Toggle
 * @{
 */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/
// 特别是有中断的外设，跳转到APP之前一定要关闭，切记！！！
void Reset_Periph(void)
{
  // UART_DeInit(UART1);                             //复位UART1
  // NVIC_DisableIRQ(UART1_IRQn);                    //关闭UART1中断
  // NVIC_DisableIRQ(SysTick_IRQn);                  //关闭systick中断
  __disable_irq(); // 跳转之前关闭总中断，防止意外中断导致死机
}

/***********************************************************************************************************************
 * @brief  This function is main entrance
 * @note   main
 * @param  none
 * @retval none
 *********************************************************************************************************************/

// extern uint8_t i2c_rx_block;
int main(void)
{
  //    uint32_t checksum;
  uint8_t appflag[4];

  FLASH_Read(appflag, AppInfoAreaAddress, 4);

  if ((appflag[0] == 0x55) && (appflag[1] == 0xAA) && (appflag[2] == 0xAA) && (appflag[3] == 0x55))
  {
    // 跳转之前，需要关闭boot初始化过的外设，避免导致跳到APP里面后boot里面的外设仍然在工作
    Reset_Periph();
    __set_MSP(*(u32 *)ApplicationAddress);                     // 设置SP.，堆栈栈顶地址
    ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))(); // 生成跳转函数.将复位中断向量地址做为函数指针
  }

  I2C_Slave_Init(DEVICE_ADDR, 400000);

  while (1)
  {

    boot_protocol();
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
