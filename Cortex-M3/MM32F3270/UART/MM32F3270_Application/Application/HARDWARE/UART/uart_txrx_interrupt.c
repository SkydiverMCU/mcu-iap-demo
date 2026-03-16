////////////////////////////////////////////////////////////////////////////////
/// @file     uart_txrx_interrupt.c
/// @author   AE TEAM
/// @brief    uart's interrupt feature.
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
#include "uart_txrx_interrupt.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  Serial port initialization configuration
/// @note    It must be careful of the Chip Version.
/// @param  baudrate: Baud rate
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART1_NVIC_Init(uint32_t baudrate)
{
    UART_InitTypeDef UART_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2ENR_UART1, ENABLE);

    // UART1 NVIC
    NVIC_InitStruct.NVIC_IRQChannel = UART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    UART_DeInit(UART1);
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

    UART_Init(UART1, &UART_InitStruct);

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_7);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_7);

    // UART1_TX   GPIOA.9
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // UART1_RX    GPIOA.10
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    UART_ITConfig(UART1, UART_IER_RXIDLE | UART_IT_RXIEN, ENABLE);
    UART_Cmd(UART1, ENABLE);
}
////////////////////////////////////////////////////////////////////////////////
/// @brief  Serial port Interrupt Handler
/// @note
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART1_IRQHandler(void)
{

    // Send packet
    if (UART_GetITStatus(UART1, UART_IER_RXIDLE) != RESET)
    {
        UART_RX_STA |= 0x8000;
        UART_ClearITPendingBit(UART1, UART_IER_RXIDLE);
    }
    // Recv packet
    if (UART_GetITStatus(UART1, UART_ISR_RX) != RESET)
    {
        // recvbyte = UART_ReceiveData(UART1);
        if ((UART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
        {
            if (UART_RX_STA < REPORT_PACKET_SIZE) // 还可以接收数据
            {
                UART_RxBuff[UART_RX_STA++] = UART_ReceiveData(UART1); // 记录接收到的值
            }
            else
            {
                UART_RX_STA |= 0x8000; // 强制标记接收完成
            }
        }
        UART_ClearITPendingBit(UART1, UART_ISR_RX);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  UART send byte.
/// @note   None.
/// @param  dat(A byte data).
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART_SendGroup(uint8_t *pBuff, uint16_t length)
{
    while (length--)
    {
        UART_SendData(UART1, (uint8_t)*pBuff);

        while (!UART_GetFlagStatus(UART1, UART_FLAG_TXEPT))
            ;
        pBuff++;
    }
}

/// @}

/// @}

/// @}
