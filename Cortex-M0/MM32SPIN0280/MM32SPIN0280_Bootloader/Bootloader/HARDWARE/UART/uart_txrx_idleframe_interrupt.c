////////////////////////////////////////////////////////////////////////////////
/// @file     uart_txrx_interrupt.c
/// @author   AE TEAM
/// @brief    PWM output.
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
#define _UART_TXRX_INTERRUPT_C_

// Files includes
#include "uart_txrx_idleframe_interrupt.h"
u8 gUartRxBuf[REPORT_PACKET_SIZE];
// Received status marker
u16 gUartRxSta = 0;

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MAIN
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  Serial port initialization configuration
/// @note    It must be careful of the Chip Version.
/// @param  baudrate: Baud rate
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART2_NVIC_Init(u32 baudrate)
{
    UART_InitTypeDef UART_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_UART_ClockCmd(UART2, ENABLE);

    // UART2 NVIC
    NVIC_InitStruct.NVIC_IRQChannel = UART2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    // Baud rate
    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.BaudRate = baudrate;
    // The word length is in 8-bit data format.
    UART_InitStruct.WordLength = UART_WordLength_8b;
    UART_InitStruct.StopBits = UART_StopBits_1;
    // No even check bit.
    UART_InitStruct.Parity = UART_Parity_No;
    // No hardware data flow control.
    UART_InitStruct.HWFlowControl = UART_HWFlowControl_None;
    UART_InitStruct.Mode = UART_Mode_Rx | UART_Mode_Tx;

    UART_Init(UART2, &UART_InitStruct);

    UART_ITConfig(UART2, UART_IT_RXIEN, ENABLE);
    UART_ITConfig(UART2, UART_IER_RXIDLE, ENABLE);

    UART_Cmd(UART2, ENABLE);
    RCC_GPIO_ClockCmd(GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

    // UART2_TX   GPIOA.2
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // UART2_RX    GPIOA.3
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Serial port Interrupt Handler
/// @note
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART2_IRQHandler(void)
{
    // Recv packet
    if (UART_GetITStatus(UART2, UART_ISR_RX) != RESET)
    {
        if ((UART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
        {
            if (UART_RX_STA < REPORT_PACKET_SIZE) // 还可以接收数据
            {
                UART_RxBuff[UART_RX_STA++] = UART_ReceiveData(UART2); // UART_ReceiveData(UART1); // 记录接收到的值
            }
            else
            {
                UART_RX_STA |= 0x8000; // 强制标记接收完成
            }
        }

        UART_ClearITPendingBit(UART2, UART_ICR_RX);
    }

    if (UART_GetITStatus(UART2, UART_ISR_RXIDLE) != RESET)
    {
        UART_RX_STA |= 0x8000;

        UART_ClearITPendingBit(UART2, UART_ICR_RXIDLE);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  UART send byte.
/// @note   None.
/// @param  buf:buffer address.
/// @param  len:data length.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART_SendGroup(u8 *buf, u16 len)
{
    while (len--)
    {
        UART_SendData(UART2, *buf++);

        while (!UART_GetFlagStatus(UART2, UART_FLAG_TXEPT))
        {
        }
    }
}

/// @}

/// @}

/// @}
