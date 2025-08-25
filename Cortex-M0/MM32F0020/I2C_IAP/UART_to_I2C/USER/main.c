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
#include "uart.h"
#include "i2c.h"
#include "delay.h"



//uint8_t tx_data[64] = {0x00};
uint8_t rx_data[UART1_MAX_RECV_LEN] = {0x00};

/* Delay for N NOPs */
//void delay_loops(uint32_t loops)
//{
//    while(loops--)
//    {
//        __NOP();
//    }
//}


////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is main entrance.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
s32 main(void)
{
    uint16_t len;
//    uint32_t i;

    DELAY_Init();

    CONSOLE_Init(115200);
    //printf("I2C Master Example Started!\r\n");
	
    I2C_Master_Init();


    while(1)
    {
        if(UART1_RX_STA&0X8000)			//接收到一次数据了
		{
			len=UART1_RX_STA&0X7FFF;	//得到数据长度
            I2C_Master_Write(I2C1, DEVICE_ADDR, UART1_RX_BUF, len);
			UART1_RX_STA=0;
            DELAY_Ms(1);
            I2C_Master_Read(I2C1, DEVICE_ADDR, rx_data, sizeof(rx_data));
            UartSendGroup(rx_data,sizeof(rx_data));
		}
    }
}

void HardFault_Handler(void)
{
    while(1)
    {
    }
}

/// @}

/// @}

/// @}
