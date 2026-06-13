/***********************************************************************************************************************
    @file    main.c
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
#define _MAIN_C_

/* Files include */
#include "platform.h"
#include "uart_polling.h"
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "gpio_key_input.h"

/**
  * @addtogroup MM32F0160_LibSamples
  * @{
  */

/**
  * @addtogroup UART
  * @{
  */

/**
  * @addtogroup UART_Polling
  * @{
  */
/* Exported constants *************************************************************************************************/
#define BOOT_SIZE               26
#define FLASH_SIZE              128    // 128K

#define BootJumpFlagAddress     (BOOT_SIZE * 1024 + 0x8000000)
#define ApplicationAddress      (BootJumpFlagAddress + 1024)

#define SRAM_LEGAL_ADDRESS_MASK 0x2FFFC000                   // SRAM合法地址范围  0x20000000 - 0x20003FFF 16KB  SRAM

#define APP_SIZE                (FLASH_SIZE - BOOT_SIZE - 1) // 101KB flash for app

#define VECTOR_SIZE             0xC0

/* Exported macro *****************************************************************************************************/

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/
volatile uint8_t Flag_1ms_int = 0;
uint16_t Key_detect_buff = 0;

void clearAppInformationspace(void);   //如果想要重新进入Bootloader USB MSC升级，那就直接调用这个接口，擦除 1K Information 区间的数据,然后进入Bootloader 把新的Update.bin文件拖进去

/***********************************************************************************************************************
  * @brief  This function is main entrance
  * @note   main
  * @param  none
  * @retval none
  *********************************************************************************************************************/
int main(void)
{
    uint8_t Data = 0;

    // M0 要把APP的向量表转移到SRAM
    memcpy((void *)0x20000000, (void *)ApplicationAddress, VECTOR_SIZE);
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG, ENABLE);
    // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();

    PLATFORM_Init();

    printf("\r\n************************************************************\r\n");
    printf("MM32F0160 enter application \r\n");
    printf("Application Compiler timestamp:%s - %s\r\n", __DATE__, __TIME__);
    printf("Application version: V0.01 \r\n");
    printf("\r\n************************************************************\r\n");

    KEY_GPIO_Configure();

    UART_Polling_Sample();

    while (1)
    {
        if (SET == UART_GetFlagStatus(UART2, UART_FLAG_RXAVL))
        {
            Data = UART_ReceiveData(UART2);

            UART_SendData(UART2, Data);

            while (RESET == UART_GetFlagStatus(UART2, UART_FLAG_TXEPT))
            {
            }
        }

        if (Flag_1ms_int == 1)
        {
            Key_detect_buff = (Key_detect_buff << 1) | KEY_INPUT;  //PC12 接高电平则会重新进入Bootloader U盘升级

            if (Key_detect_buff == 0xFFFF)
            {
                printf("\r\nClear Information space and NVIC_SystemReset\r\n");
                clearAppInformationspace();
                NVIC_SystemReset();
            }

            Flag_1ms_int = 0;
        }
    }
}

/***********************************************************************************************************************
  * @brief  This function is main entrance
  * @note   main
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void clearAppInformationspace(void)
{
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    FLASH_ErasePage(BootJumpFlagAddress);

    FLASH_Lock();
}

void eraseAppSpace(uint8_t Pagesize, uint32_t startaddress)
{
    uint16_t sum = 0;
    uint32_t Address;
    uint16_t index;
    uint8_t page_erase = Pagesize;

    Address = startaddress;
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    for (index = 0; index < page_erase; index++)
    {
        FLASH_ErasePage(Address);
        Address = Address + 0x400;
    }

    FLASH_Lock();
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

