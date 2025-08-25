////////////////////////////////////////////////////////////////////////////////
/// @file    uart.c
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
#define _UART_C_

// Files includes
#include <stdio.h>
#include "uart.h"
#include "hal_conf.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup UART
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup UART_Exported_Functions
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  Retargets the C library printf function to the UARTx.
/// @param  ch: character to send
/// @param  f: pointer to file (not used)
/// @retval The character transmitted
////////////////////////////////////////////////////////////////////////////////

#if defined (__CC_ARM)
int fputc(int ch, FILE *f)
#elif defined (__ICCARM__)
int fputc(int ch, FILE *f)
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
int fputc(int ch, FILE *f)
#elif defined (__GNUC__)
void _sys_exit(s32 x)
{
    x = x;
}

// With GCC, small printf (option LD Linker->Libraries->Small printf
// set to 'Yes') calls __io_putchar()
int __io_putchar(int ch)
#else
  #warning Not supported compiler type
#endif
{
    // Place your implementation of fputc here
    // e.g. write a character to the COM and Loop until the end of transmission
    while (1)
    {
        if (UART_GetFlagStatus(UART2, UART_CSR_TXC) != RESET)
        {
            break;
        }
    }

    UART_SendData(UART2, (u16)ch);
    return (ch);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  CONSOLE initialize for the C library printf function with UART
/// @param  baudrate: baud rate of the UART
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void CONSOLE_Init(u32 baudrate)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    UART_InitTypeDef UART_InitStruct;

    RCC_UART_ClockCmd(UART2, ENABLE);  //enableUART2 clock
    RCC_GPIO_ClockCmd(GPIOA, ENABLE);  //enable GPIOA clock

    RCC_GPIO_ClockCmd(GPIOA, ENABLE);  //
    //GPIO initial
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

    //UART initial
    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.UART_BaudRate   = baudrate;
    UART_InitStruct.UART_WordLength = UART_WordLength_8b;
    UART_InitStruct.UART_StopBits   = UART_StopBits_1;                        //one stopbit
    UART_InitStruct.UART_Parity     = UART_Parity_No;                         //none odd-even  verify bit
    UART_InitStruct.UART_HardwareFlowControl = UART_HardwareFlowControl_None; //No hardware flow control
    UART_InitStruct.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;                  // receive and sent  mode

    UART_Init(UART2, &UART_InitStruct);                                       //initial uart 1
    UART_Cmd(UART2, ENABLE);                                                  //enable uart 1

    //UART2_TX   GPIOA.2
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    //UART2_RX    GPIOA.3
    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/// @}

/// @}

/// @}

