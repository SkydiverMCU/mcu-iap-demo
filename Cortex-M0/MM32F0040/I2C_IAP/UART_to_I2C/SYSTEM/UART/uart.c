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
u8  UART1_RX_BUF[UART1_MAX_RECV_LEN]; 		//接收缓冲,最大USART3_MAX_RECV_LEN字节

vu16 UART1_RX_STA=0;
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup UART
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup UART_Exported_Functions
/// @{

#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE s32 __io_putchar(s32 ch)
#else
#define PUTCHAR_PROTOTYPE s32 fputc(s32 ch, FILE *f)

#endif

#ifdef USE_IAR
PUTCHAR_PROTOTYPE {
    while((UART1->CSR & UART_IT_TXIEN) == 0); //The loop is sent until it is finished
    UART1->TDR = (ch & (u16)0x00FF);
    return ch;
}

#else
void _sys_exit(s32 x)
{
    x = x;
}
//redefine fputcfunction
s32 fputc(s32 ch, FILE* f)
{
    while((UART1->CSR & UART_IT_TXIEN) == 0); //The loop is sent until it is finished
    UART1->TDR = (ch & (u16)0x00FF);
    return ch;
}

#endif

void UART_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//UART1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = UART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
}


void CONSOLE_Init(u32 baudrate)
{
    //GPIO port set
    GPIO_InitTypeDef GPIO_InitStruct;
    UART_InitTypeDef UART_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2ENR_UART1, ENABLE);   //enableUART1,GPIOAclock
    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);  //
    //UART initialset
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);


    UART_NVIC_Config();

    UART_StructInit(&UART_InitStruct);
    UART_InitStruct.UART_BaudRate = baudrate;
    UART_InitStruct.UART_WordLength = UART_WordLength_8b;
    UART_InitStruct.UART_StopBits = UART_StopBits_1;//one stopbit
    UART_InitStruct.UART_Parity = UART_Parity_No;//none odd-even  verify bit
    UART_InitStruct.UART_HardwareFlowControl = UART_HardwareFlowControl_None;//No hardware flow control
    UART_InitStruct.UART_Mode = UART_Mode_Rx | UART_Mode_Tx; // receive and sent  mode

    UART_Init(UART1, &UART_InitStruct); //initial uart 1
    UART_ClearITPendingBit(UART1,UART_IT_RXIEN|UART_IER_RXIDLE);	
	UART_ITConfig(UART1,UART_IT_RXIEN|UART_IER_RXIDLE,ENABLE);
    
    UART_Cmd(UART1, ENABLE);                    //enable uart 1

    //UART1_TX   GPIOB6
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    //UART1_RX    GPIOB7
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void Uart_sendbyte(u8 data)
{
		while((UART1->CSR&UART_IT_TXIEN)==0);//循环发送,直到发送完毕   
    UART1->TDR = data;
}
void UartSendGroup(u8 *data,u16 len)
{
		while(len--)
		{
				Uart_sendbyte(*data);
				data++;
		}
}

void UART1_IRQHandler(void)
{
	u8 Res;
	
	if(UART_GetITStatus(UART1, UART_IT_RXIEN)  != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		UART_ClearITPendingBit(UART1,UART_IT_RXIEN);
		Res =UART_ReceiveData(UART1);	//读取接收到的数据
		
		if((UART1_RX_STA&(1<<15))==0)//接收完的一批数据,还没有被处理,则不再接收其他数据
		{ 
			if(UART1_RX_STA<UART1_MAX_RECV_LEN)	//还可以接收数据
			{
				UART1_RX_BUF[UART1_RX_STA++]=Res;	//记录接收到的值	 
			}
			else 
			{
				UART1_RX_STA|=1<<15;				//强制标记接收完成
			} 
		}
	}
	if(UART_GetITStatus(UART1, UART_IER_RXIDLE)  != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		UART_ClearITPendingBit(UART1,UART_IER_RXIDLE);
		
		UART1_RX_STA|=1<<15;	//标记接收完成   
	}
}

/// @}

/// @}

/// @}
