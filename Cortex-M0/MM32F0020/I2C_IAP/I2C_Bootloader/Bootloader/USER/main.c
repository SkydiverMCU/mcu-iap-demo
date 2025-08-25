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
//#include "uart.h"
#include "i2c.h"
#include "boot.h"

//uint8_t tx_data[64] = {0x00};
//uint8_t rx_data[16] = {0x00};

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{
//特别是有中断的外设，跳转到APP之前一定要关闭，切记！！！
void Reset_Periph(void)
{
    //UART_DeInit(UART1);                             //复位UART1
    //NVIC_DisableIRQ(UART1_IRQn);                    //关闭UART1中断
    //NVIC_DisableIRQ(SysTick_IRQn);                  //关闭systick中断
    __disable_irq();                                 //跳转之前关闭总中断，防止意外中断导致死机
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
s32 main(void)
{
    uint16_t rx_data_len, tx_data_len;
    uint32_t i;

#if 0
    u8 flag[4];
    
    FLASH_Read(flag, BootJumpFlagAddress, 4);

    if (strncmp(flag, Valid_buf, 4) == 0)                          //如果用户程序有效，则跳转到用户程序执行用户程序。
    {
        Reset_Periph();                                            //跳转之前，需要关闭boot初始化过的外设，避免导致跳到APP里面后boot里面的外设仍然在工作
        __set_MSP(*(u32 *)ApplicationAddress);                     //设置SP.，堆栈栈顶地址
        ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))(); //生成跳转函数.将复位中断向量地址做为函数指针
    }
#endif

    I2C_Slave_Init(DEVICE_ADDR, I2C_RX_BUF, sizeof(I2C_RX_BUF), I2C_TX_BUF, sizeof(I2C_TX_BUF));

    while (1)
    {
        rx_data_len = I2C_Slave_GetRxAvailable();

        if (rx_data_len != 0)
        {
            /*********I2C SCL Stretching *********/
            GPIOA->AFRL |= 0x00F00000;
            I2C1_SCL_PORT->BRR = I2C1_SCL_PIN;

            boot_protocol(I2C_RX_BUF, rx_data_len);
        }
    }
}

void HardFault_Handler(void)
{
    while (1)
    {
    }
}

/// @}

/// @}

/// @}

