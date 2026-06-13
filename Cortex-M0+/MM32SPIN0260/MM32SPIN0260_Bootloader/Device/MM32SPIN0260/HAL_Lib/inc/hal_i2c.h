/***********************************************************************************************************************
    @file     hal_i2c.h
    @author   FD TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE I2C FIRMWARE LIBRARY.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef __HAL_I2C_H
#define __HAL_I2C_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C
  * @{
  */

/** @defgroup I2C_Exported_Types
  * @{
  */

/**
  * @brief  I2C Init structure definition
  */
typedef struct
{
    uint16_t I2C_Mode;                 /*!< Specifies the I2C mode. This parameter can be a value of I2C_mode. */
    uint16_t I2C_OwnAddress;           /*!< Specifies the first device own address. This parameter can be a 7-bit or 10-bit address. */
    uint32_t I2C_ClockSpeed;           /*!< Specifies the clock speed, with support for standard and fast modes. */
} I2C_InitTypeDef;
/**
  * @}
  */


/** @defgroup I2C_Exported_Constants
  * @{
  */
#define I2C_OWN_ADDRESS                                        0x80
                                                               
#define I2C_MODE_MASTER                                        0x00U
#define I2C_MODE_SLAVER                                        0x01U
                                                               
#define I2C_NACK                                               (0x00U << I2C_CON_AA_Pos)
#define I2C_ACK                                                (0x01U << I2C_CON_AA_Pos)
                                                               
#define I2C_STATUS_START_TRANSMITTED                           0x08
#define I2C_STATUS_REPEATED_START_TRANSMITTED                  0x10 
#define I2C_STATUS_SLA_W_TRANSMITTED_ACK_RECEIVED              0x18                                  
#define I2C_STATUS_SLA_W_TRANSMITTED_NACK_RECEIVED             0x20                                  
#define I2C_STATUS_DATA_TRANSMITTED_ACK_RECEIVED               0x28                                  
#define I2C_STATUS_DATA_TRANSMITTED                            0x30                                  
#define I2C_STATUS_ARBITRATION_LOST                            0x38                                  
#define I2C_STATUS_SLA_R_TRANSMITTED_ACK_RECEIVED              0x40                                  
#define I2C_STATUS_SLA_R_TRANSIMTTED_NACK_RECEIVED             0x48                                  
#define I2C_STATUS_DATA_RECEIVED_ACK_RETURNED                  0x50
#define I2C_STATUS_DATA_RECEIVED_NACK_RETURNED                 0x58
#define I2C_STATUS_OWN_SLA_W_RECEIVED_ACK_RETURNED             0x60
#define I2C_STATUS_ARBITRATION_LOST_OWN_SLA_W_RECEIVED         0x68
#define I2C_STATUS_GENERAL_CALL_RECEIVED_ACK_RETURNED          0x70
#define I2C_STATUS_ARBITRATION_LOST_GENERAL_CALL_RECEIVED      0x78
#define I2C_STATUS_PREVIOUSLY_ADDRESSED_DATA_RECEIVED_ACK      0x80
#define I2C_STATUS_PREVIOUSLY_ADDRESSED_DATA_RECEIVED_NACK     0x88
#define I2C_STATUS_PREVIOUSLY_GC_ADDRESSED_DATA_RECEIVED_ACK   0x90
#define I2C_STATUS_PREVIOUSLY_GC_ADDRESSED_DATA_RECEIVED_NACK  0x98
#define I2C_STATUS_STOP_OR_RESTART_RECEIVED                    0xA0
#define I2C_STATUS_OWN_SLA_R_RECEIVED_ACK_RETURNED             0xA8
#define I2C_STATUS_ARBITRATION_LOST_OWN_SLA_R_RECEIVED_ACK     0xB0
#define I2C_STATUS_DATA_TRANSMITTED_ACK_RECEIVED_SLAVE         0xB8               
#define I2C_STATUS_DATA_TRANSMITTED_NACK_RECEIVED              0xC0
#define I2C_STATUS_LAST_DATA_TRANSMITTED_ACK_RECEIVED          0xC8
#define I2C_STATUS_NO_RELEVANT_STATE_INFORMATION               0xF8
#define I2C_STATUS_BUS_ERROR                                   0x00


/**
  * @}
  */



  
/** @defgroup I2C_Exported_Functions
  * @{
  */
void I2C_DeInit(I2C_TypeDef *i2c);
void I2C_Init(I2C_TypeDef *i2c, I2C_InitTypeDef *init_struct);
void I2C_StructInit(I2C_InitTypeDef *init_struct);
void I2C_Cmd(I2C_TypeDef *i2c, FunctionalState state);
void I2C_GenerateSTART(I2C_TypeDef *i2c);
void I2C_ClearSTART(I2C_TypeDef *i2c);
void I2C_GenerateSTOP(I2C_TypeDef *i2c);
void I2C_GeneralCallCmd(I2C_TypeDef *i2c, FunctionalState state);
void I2C_SendData(I2C_TypeDef *i2c, uint8_t dat);
uint8_t I2C_ReceiveData(I2C_TypeDef *i2c);
void I2C_AckConfig(I2C_TypeDef *i2c, uint32_t ack);
ITStatus I2C_GetITStatus(I2C_TypeDef *i2c);
uint8_t I2C_GetITStateCode(I2C_TypeDef *i2c);
void I2C_ClearITPendingBit(I2C_TypeDef *i2c);
void I2C_SlaveAddressConfig(I2C_TypeDef *i2c, uint8_t addr);
uint8_t I2C_GetTxFifoLevel(I2C_TypeDef *i2c);
uint8_t I2C_GetRxFifoLevel(I2C_TypeDef *i2c);
void I2C_SetRxFifoThreshold(I2C_TypeDef *i2c,uint8_t tl);
void I2C_ClearFifo(I2C_TypeDef *i2c);
void I2C_FifoCmd(I2C_TypeDef *i2c, FunctionalState state);

#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

