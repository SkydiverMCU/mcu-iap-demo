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
#include "uart_txrx_idleframe_interrupt.h"
#include "boot.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN_Exported_Constants
/// @{

void Reset_Periph(void)
{
  UART_DeInit(UART2);
  NVIC_DisableIRQ(UART2_IRQn);
  NVIC_DisableIRQ(SysTick_IRQn);
  __disable_irq();
  //    __set_PRIMASK(1);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval  0.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
  uint8_t flag[4];
  uint16_t len;

  FLASH_Read(flag, BootJumpFlagAddress, 4);

  if ((flag[0] == 0x55) && (flag[1] == 0xAA) && (flag[2] == 0xAA) && (flag[3] == 0x55)) // 如果用户程序有效，则跳转到用户程序执行用户程序。
  {
    // Reset_Periph();//跳转之前，需要关闭boot初始化过的外设，避免导致跳到APP里面后boot里面的外设仍然在工作
    __disable_irq();
    __set_MSP(*(u32 *)ApplicationAddress);                     // 设置SP.，堆栈栈顶地址
    ((void (*)(void)) * (u32 *)(0x04 + ApplicationAddress))(); // 生成跳转函数.将复位中断向量地址做为函数指针
  }

  // SysTick timer init
  DELAY_Init();

  UART2_NVIC_Init(115200);

  while (1)
  {
    if (USART_RX_STA & 0x8000)
    {
      len = USART_RX_STA & 0x7FFF;
      boot_protocol(UART_RxBuff, len);
      USART_RX_STA = 0;
    }
  }
}

/// @}

/// @}

/// @}
