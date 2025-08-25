/***********************************************************************************************************************
    @file    platform.c
    @author  FD Team
    @date    12-Dec-2023
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
#define _PLATFORM_C_

/* Files include */
#include <stdio.h>
#include "platform.h"

/**
  * @addtogroup MM32F0120_LibSamples
  * @{
  */

/**
  * @addtogroup ADC
  * @{
  */

/**
  * @addtogroup ADC_AnalogWatchdog
  * @{
  */

/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/

/***********************************************************************************************************************
  * @brief  Initialize SysTick for delay function
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_InitDelay(void)
{
    RCC_ClocksTypeDef RCC_Clocks;

    RCC_GetClocksFreq(&RCC_Clocks);

    if (SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000))
    {
        while (1)
        {
        }
    }

    NVIC_SetPriority(SysTick_IRQn, 0x0);
}

/***********************************************************************************************************************
  * @brief  Millisecond delay
  * @note   none
  * @param  Millisecond: delay time unit
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_DelayMS(uint32_t Millisecond)
{
    PLATFORM_DelayTick = Millisecond;

    while (0 != PLATFORM_DelayTick)
    {
    }
}

/***********************************************************************************************************************
  * @brief  Initialize console for printf
  * @note   none
  * @param  Baudrate : UART1 communication baudrate
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_InitConsole(uint32_t Baudrate)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    USART_StructInit(&USART_InitStruct);
    USART_InitStruct.USART_BaudRate      = Baudrate;
    USART_InitStruct.USART_WordLength    = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits      = USART_StopBits_1;
    USART_InitStruct.USART_Parity        = USART_Parity_No;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode          = USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStruct);

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOB, ENABLE);

    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_0);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_6;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    USART_Cmd(USART1, ENABLE);
}

#if   defined (__ICCARM__)

#if   (__VER__ >= 9030001)

/* Files include */
#include <stddef.h>
#include <LowLevelIOInterface.h>

/***********************************************************************************************************************
  * @brief  redefine __write function
  * @note   for printf
  * @param  handle
  * @param  *buf
  * @param  bufSize
  * @retval nChars
  *********************************************************************************************************************/
size_t __write(int handle, const unsigned char *buf, size_t bufSize)
{
    size_t nChars = 0;

    /* Check for the command to flush all handles */
    if (-1 == handle)
    {
        return (0);
    }

    /* Check for stdout and stderr (only necessary if FILE descriptors are enabled.) */
    if ((_LLIO_STDOUT != handle) && (_LLIO_STDERR != handle))
    {
        return (-1);
    }

    for (/* Empty */; bufSize > 0; --bufSize)
    {
        USART_SendData(USART1, *buf);

        while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
        {
        }

        ++buf;
        ++nChars;
    }

    return (nChars);
}

#else

/***********************************************************************************************************************
  * @brief  Redefine fputc function
  * @note   For printf
  * @param  ch
  * @param  f
  * @retval ch
  *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (uint8_t)ch);

    while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
    {
    }

    return (ch);
}

#endif

#elif defined (__GNUC__)

/***********************************************************************************************************************
  * @brief  Redefine fputc function
  * @note   For printf
  * @param  ch
  * @param  f
  * @retval ch
  *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (uint8_t)ch);

    while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
    {
    }

    return (ch);
}

#else

/***********************************************************************************************************************
  * @brief  Redefine fputc function
  * @note   For printf
  * @param  ch
  * @param  f
  * @retval ch
  *********************************************************************************************************************/
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (uint8_t)ch);

    while (RESET == USART_GetFlagStatus(USART1, USART_FLAG_TC))
    {
    }

    return (ch);
}

#endif

/***********************************************************************************************************************
  * @brief  Initialize LED GPIO PIN
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_InitLED(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOB, ENABLE);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOC, ENABLE);

    PLATFORM_LED_Enable(LED1, ENABLE);
    PLATFORM_LED_Enable(LED2, ENABLE);
}

/***********************************************************************************************************************
  * @brief  LED on or off
  * @note   none
  * @param  LEDn : LED index
  * @arg    LED1, LED2
  * @param  State
  * @arg    ENABLE, DISABLE
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_LED_Enable(LEDn_TypeDef LEDn, FunctionalState State)
{
    switch (LEDn)
    {
        case LED1:
            GPIO_WriteBit(GPIOB, GPIO_Pin_15, (ENABLE == State) ? Bit_RESET : Bit_SET);
            break;

        case LED2:
            GPIO_WriteBit(GPIOB, GPIO_Pin_14, (ENABLE == State) ? Bit_RESET : Bit_SET);
            break;

        default:
            break;
    }
}

/***********************************************************************************************************************
  * @brief  LED toggle display
  * @note   none
  * @param  LEDn : LED index
  * @arg    LED1, LED2
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_LED_Toggle(LEDn_TypeDef LEDn)
{
    switch (LEDn)
    {
        case LED1:
            GPIO_WriteBit(GPIOB, GPIO_Pin_15, GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_15) ? Bit_RESET : Bit_SET);
            break;

        case LED2:
            GPIO_WriteBit(GPIOB, GPIO_Pin_14, GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_14) ? Bit_RESET : Bit_SET);
            break;

        default:
            break;
    }
}

/***********************************************************************************************************************
  * @brief  Print information
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_PrintInfo(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    uint8_t  divider = 0;

    printf("\r\nBOARD : Mini-F0121-OB");
    printf("\r\nMCU : MM32F0121C6P");

    printf("\r\n");

    switch (RCC->CFGR & RCC_CFGR_SWS_Msk)
    {
        case 0x00:
            printf("\r\nHSI8 used as system clock source");
            break;

        case 0x04:
            printf("\r\nHSE used as system clock source");
            break;

        case 0x08:
            divider = (uint8_t)((RCC->CR & RCC_CR_HSI144DIV_Msk) >> RCC_CR_HSI144DIV_Pos);
            if(divider == 0x01)
            {
                printf("\r\nHSI144/1.5 used as system clock source");
            }
            else 
            {
                printf("\r\nHSI144 used as system clock source");
            }
            break;
        case 0x0C:
            printf("\r\nLSI used as system clock source");
            break;

        default:
            break;
    }

    RCC_GetClocksFreq(&RCC_Clocks);

    printf("\r\n");
    printf("\r\nSYSCLK Frequency : %7.3f MHz", (double)RCC_Clocks.SYSCLK_Frequency / (double)1000000.0);
    printf("\r\nHCLK   Frequency : %7.3f MHz", (double)RCC_Clocks.HCLK_Frequency   / (double)1000000.0);
    printf("\r\nPCLK1  Frequency : %7.3f MHz", (double)RCC_Clocks.PCLK1_Frequency  / (double)1000000.0);
    printf("\r\nPCLK2  Frequency : %7.3f MHz", (double)RCC_Clocks.PCLK2_Frequency  / (double)1000000.0);
    printf("\r\n");
}

/***********************************************************************************************************************
  * @brief  Initialize platform
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
void PLATFORM_Init(void)
{
    PLATFORM_InitDelay();

    PLATFORM_InitConsole(115200);

    PLATFORM_InitLED();

    PLATFORM_PrintInfo();
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

