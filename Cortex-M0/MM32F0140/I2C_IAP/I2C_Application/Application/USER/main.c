////////////////////////////////////////////////////////////////////////////////
/// @file    main.c
/// @author  AE TEAM
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
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
#include "led.h"
#include "delay.h"
#include "i2c.h"
#include "boot.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{
__IO uint32_t VectorTable[48] __attribute__((at(0x20000000)));
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

void setNVIC(void)
{
    u8 i;

    // 将APP的向量表转移到SRAM
    for (i = 0; i < 48; i++)
    {
        VectorTable[i] = *(__IO uint32_t *)(ApplicationAddress + (i << 2));
    }
    // Enable the SYSCFG Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFG, ENABLE);

    // Remap SRAM at 0x00000000 将SRAM中的向量表映射到0x0000000
    SYSCFG_MemoryRemapConfig(SYSCFG_MemoryRemap_SRAM);
    __enable_irq();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    uint32_t time = 0;

    setNVIC();
    DELAY_Init();
    LED_Init();
    I2C_Slave_Init(DEVICE_ADDR, 400000);

    while (1)
    {
        i2c_protocol();

        if ((gu32_timeBase - time) > 300)
        {
            time = gu32_timeBase;
            LED2_TOGGLE();
        }
    }
}

/// @}

/// @}

/// @}
