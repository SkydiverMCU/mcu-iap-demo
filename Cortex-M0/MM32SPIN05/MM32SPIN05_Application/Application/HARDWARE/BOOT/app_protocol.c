/***********************************************************************************************************************
    @file    app_protocol.c
    @author  Skydiver
    @date    27-May-2025
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
#define _APP_PROTOCOL_C_

/* Files include */
#include <stdio.h>
#include "string.h"
#include "app_protocol.h"

/**
 * @addtogroup
 * @{
 */

/**
 * @addtogroup
 * @{
 */

/**
 * @addtogroup
 * @{
 */
#define APP_VERSION "V:0.1.1"
/* Private typedef ****************************************************************************************************/

/* Private define *****************************************************************************************************/

/* Private macro ******************************************************************************************************/

/* Private variables **************************************************************************************************/

/* Private functions **************************************************************************************************/

uint8_t Data_RxBuff[REPORT_PACKET_SIZE];

uint16_t UART_RX_STA = 0;
uint8_t UART_RxBuff[REPORT_PACKET_SIZE];

const uint8_t Report_Return_Err[REPORT_PACKET_SIZE] =
    {
        0xD5, 0x04, 0x00, 0x00, 0x59};

/**********Checksum*******************/

static uint16_t CheckSum(uint8_t *pdat, uint8_t count)
{
  register int sum = 0;

  while (count > 0)
  {
    sum = sum + *pdat;
    pdat++;
    count--;
  }

  return (sum);
}

static uint8_t Check_data(uint8_t *txrxCmd)
{
  // uint8_t Flag_check = 0;
  uint16_t tmp_Checksum = 0;
  uint8_t temp1, temp2;

  tmp_Checksum = CheckSum(txrxCmd, txrxCmd[1] - 2);

  temp1 = tmp_Checksum & 0x00FF;
  temp2 = (tmp_Checksum >> 8) & 0x00FF;

  if ((temp2 != txrxCmd[txrxCmd[1] - 2]) || (temp1 != txrxCmd[txrxCmd[1] - 1]))
  {
    return (1);
  }

  return (0);
}

void getVersion(uint8_t *buff)
{
  uint16_t sum = 0;

  memset(buff, 0, 0x40);
  buff[0] = GET_VERSION | RESPONSE_MASK;
  buff[1] = 16;
  buff[2] = 'A';
  strncpy((char *)(buff + 3), APP_VERSION, 7);
  sum = CheckSum(buff, buff[1] - 2);
  buff[buff[1] - 2] = (sum >> 8) & 0xFF;
  buff[buff[1] - 1] = sum & 0xFF;

  UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void eraseAppSpace(void)
{
  uint32_t Address;
  uint16_t index;

  Address = ApplicationAddress;
  FLASH_Unlock();
  FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

  for (index = 0; index < APP_SIZE; index++)
  {
    FLASH_ErasePage(Address);
    Address = Address + 0x400;
  }

  FLASH_Lock();
}

void resetMCU(uint8_t *buff)
{
  uint16_t sum = 0;

  buff[0] = SYSTEM_RESET | RESPONSE_MASK;
  buff[1] = 4;
  sum = CheckSum(buff, buff[1] - 2);
  buff[2] = (sum >> 8) & 0xFF;
  buff[3] = sum & 0xFF;
  UART_SendGroup(buff, REPORT_PACKET_SIZE);

  DELAY_Ms(5);
  __disable_irq();
  NVIC_SystemReset(); // 软复位
}

void clearAppFlag(uint8_t *buff)
{
  uint16_t sum = 0;

  FLASH_Unlock();
  FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

  FLASH_ErasePage(BootJumpFlagAddress);

  FLASH_Lock();

  memset(buff, 0, 0x40);
  buff[0] = CLEAR_FLAG | RESPONSE_MASK;
  buff[1] = 4;
  sum = CheckSum(buff, buff[1] - 2);
  buff[buff[1] - 2] = (sum >> 8) & 0xFF;
  buff[buff[1] - 1] = sum & 0xFF;
  UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void mcuInfo(uint8_t *buff)
{
  uint16_t sum = 0;

  buff[0] = MCU_INFO | RESPONSE_MASK;
  buff[1] = 12;
  buff[2] = (ApplicationAddress >> 24) & 0xFF;
  buff[3] = (ApplicationAddress >> 16) & 0xFF;
  buff[4] = (ApplicationAddress >> 8) & 0xFF;
  buff[5] = ApplicationAddress & 0xFF;

  buff[6] = ((APP_SIZE * 1024) >> 24) & 0xFF;
  buff[7] = ((APP_SIZE * 1024) >> 16) & 0xFF;
  buff[8] = ((APP_SIZE * 1024) >> 8) & 0xFF;
  buff[9] = (APP_SIZE * 1024) & 0xFF;

  sum = CheckSum(buff, buff[1] - 2);
  buff[buff[1] - 2] = (sum >> 8) & 0xFF;
  buff[buff[1] - 1] = sum & 0xFF;

  UART_SendGroup(buff, REPORT_PACKET_SIZE);
}

void Receive_Protocol_Process(void)
{
  uint8_t cmd;

  if (UART_RX_STA & 0x8000)
  {
    memcpy(Data_RxBuff, UART_RxBuff, sizeof(UART_RxBuff));
    if (Check_data(Data_RxBuff))
    {
      memcpy(Data_RxBuff, Report_Return_Err, 0x40);
      UART_SendGroup(Data_RxBuff, REPORT_PACKET_SIZE);
      return;
    }

    cmd = Data_RxBuff[0];

    switch (cmd)
    {
    case GET_VERSION:
      getVersion(Data_RxBuff);
      break;

    case SYSTEM_RESET:
      resetMCU(Data_RxBuff);
      break;

    case CLEAR_FLAG:
      clearAppFlag(Data_RxBuff);
      break;

    case MCU_INFO:
      mcuInfo(Data_RxBuff);
      break;

    default:
      break;
    }

    UART_RX_STA = 0;
  }
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
