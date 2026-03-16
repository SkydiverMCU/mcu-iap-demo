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
#include "uart_txrx_interrupt.h"

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
void UART1_NVIC_Init(u32 baudrate)
{
    UART_InitTypeDef UART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART1, ENABLE);

    // UART1 NVIC
    NVIC_InitStructure.NVIC_IRQChannel = UART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // Baud rate
    UART_StructInit(&UART_InitStructure);
    UART_InitStructure.BaudRate = baudrate;
    // The word length is in 8-bit data format.
    UART_InitStructure.WordLength = UART_WordLength_8b;
    UART_InitStructure.StopBits = UART_StopBits_1;
    // No even check bit.
    UART_InitStructure.Parity = UART_Parity_No;
    // No hardware data flow control.
    UART_InitStructure.HWFlowControl = UART_HWFlowControl_None;
    UART_InitStructure.Mode = UART_Mode_Rx | UART_Mode_Tx;

    UART_Init(UART1, &UART_InitStructure);
    UART_ITConfig(UART1, UART_IT_RXIEN, ENABLE);
    UART_Cmd(UART1, ENABLE);

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);

    // UART1_TX   GPIOA.9
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // UART1_RX    GPIOA.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
////////////////////////////////////////////////////////////////////////////////
/// @brief  Serial port Interrupt Handler
/// @note
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void UART1_IRQHandler(void)
{
    uint8_t recvbyte;

    // Recv packet
    if (UART_GetITStatus(UART1, UART_ISR_RX) != RESET)
    {
        recvbyte = UART_ReceiveData(UART1);

        if ((UART_RX_STA & 0x8000) == 0) // 接收完的一批数据,还没有被处理,则不再接收其他数据
        {
            if (UART_RX_STA == 0)
            {
                TIM_Cmd(TIM3, ENABLE);
            }
            if (UART_RX_STA < REPORT_PACKET_SIZE) // 还可以接收数据
            {
                UART_RxBuff[UART_RX_STA++] = recvbyte; // UART_ReceiveData(UART1); // 记录接收到的值
            }
            else
            {
                UART_RX_STA |= 0x8000; // 强制标记接收完成
            }

            ucTim1Flag = 0; // 清TIM3 中断计数器，用于接收空闲
        }
        UART_ClearITPendingBit(UART1, UART_ISR_RX);
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
        UART_SendData(UART1, *buf++);
        while (!UART_GetFlagStatus(UART1, UART_FLAG_TXEPT))
        {
        }
    }
}

/// @}

/// @}

/// @}
