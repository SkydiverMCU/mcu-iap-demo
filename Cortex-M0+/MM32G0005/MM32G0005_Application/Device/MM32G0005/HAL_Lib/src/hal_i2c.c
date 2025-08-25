/***********************************************************************************************************************
    @file     hal_i2c.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE I2C FIRMWARE FUNCTIONS.
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

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_i2c.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/** @defgroup I2C_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the i2c peripheral registers to their default
  *         reset values.
  * @param  i2c1.
  * @retval None.
  */
void I2C_DeInit(I2C_TypeDef *i2c)
{
    if (i2c == I2C1)
    {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);
    }
}

/**
  * @brief  Initializes the i2c peripheral according to the specified
  *         parameters in the init_struct.
  * @param  i2c: select the I2C peripheral.
  * @param  init_struct: pointer to a I2C_InitTypeDef structure that
  *         contains the configuration information for the specified
  *         I2C peripheral.
  * @retval None.
  */
void I2C_Init(I2C_TypeDef *i2c, I2C_InitTypeDef *init_struct)
{
    uint32_t baud = 0, pclk1 = 0, div = 0;

    RCC_ClocksTypeDef RCC_ClocksStatus;

    if(init_struct->I2C_Mode == I2C_MODE_MASTER)
    {
        RCC_GetClocksFreq(&RCC_ClocksStatus);
        pclk1 = RCC_ClocksStatus.PCLK1_Frequency;

        baud = init_struct->I2C_ClockSpeed;

        /* Calculate I2C division factor */
        div = (pclk1 / (baud * 4)) - 1;

        MODIFY_REG(i2c->DIV, I2C_DIV_DIV_Msk, div);
    }
    
    I2C_SlaveAddressConfig(i2c, init_struct->I2C_OwnAddress);
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to an I2C_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void I2C_StructInit(I2C_InitTypeDef *init_struct)
{
    init_struct->I2C_Mode       = I2C_MODE_MASTER;
    init_struct->I2C_OwnAddress = I2C_OWN_ADDRESS;
    init_struct->I2C_ClockSpeed = 100000;
}

/**
  * @brief  Enables or disables the specified I2C peripheral.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the i2c peripheral. This parameter
  *         can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_Cmd(I2C_TypeDef *i2c, FunctionalState state)
{
    (state) ?                                             \
    (i2c->CON |= (0x01U << I2C_CON_ENS1_Pos)) : \
    (i2c->CON &= ~(0x01U << I2C_CON_ENS1_Pos));
}

/**
  * @brief  Generates i2c communication START condition.
  * @param  i2c: select the I2C peripheral.
  * @retval None.
  */
void I2C_GenerateSTART(I2C_TypeDef *i2c)
{
    if(i2c->CON & I2C_CON_STA_Msk)
    {
        i2c->CON &= ~(0x01U << I2C_CON_STA_Pos);
    }
    i2c->CON |= (0x01U << I2C_CON_STA_Pos);   
}

/**
  * @brief  clear i2c communication START condition.
  * @param  i2c: select the I2C peripheral.
  * @retval None.
  */
void I2C_ClearSTART(I2C_TypeDef *i2c)
{
    i2c->CON &= ~(0x01U << I2C_CON_STA_Pos);
}

/**
  * @brief  Generates i2c communication STOP condition.
  * @param  i2c: select the I2C peripheral.
  * @retval None.
  */
void I2C_GenerateSTOP(I2C_TypeDef *i2c)
{
    i2c->CON |= (0x01U << I2C_CON_STO_Pos);
}

/**
  * @brief  Enables or disables the I2C broadcast address identification.
  * @param  i2c: select the I2C peripheral.
  * @param  state: new state of the I2C broadcast address identification.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void I2C_GeneralCallCmd(I2C_TypeDef *i2c, FunctionalState state)
{
    (state) ?                                           \
    (i2c->ADR |= (0x01U << I2C_ADR_GC_Pos)) : \
    (i2c->ADR &= ~(0x01U << I2C_ADR_GC_Pos));
}

/**
  * @brief  Sends a data byte through the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @param  dat: Byte to be transmitted.
  * @retval None.
  */
void I2C_SendData(I2C_TypeDef *i2c, uint8_t dat)
{
    i2c->DAT = dat;
}

/**
  * @brief  Returns the most recent received data by the i2c peripheral.
  * @param  i2c: select the I2C peripheral.
  * @retval The value of the received data.
  */
uint8_t I2C_ReceiveData(I2C_TypeDef *i2c)
{
    return ((uint8_t)i2c->DAT);
}

/**
  * @brief  I2C Ack config After recive .
  * @param  i2c: select the I2C peripheral.
  * @param  ack: ack or nack
  * @arg   I2C_NACK
  * @arg   I2C_ACK
  * @retval None.
  */
void I2C_AckConfig(I2C_TypeDef *i2c, uint32_t ack)
{
     MODIFY_REG(i2c->CON, I2C_CON_AA_Msk, ack);
}

/**
  * @brief  Checks whether the I2C interrupt has occurred or not.
  * @param  i2c: select the I2C peripheral.
  * @retval The new state of I2C_IT (SET or RESET).
  */
ITStatus I2C_GetITStatus(I2C_TypeDef *i2c)
{
    return ((i2c->CON & I2C_CON_SI_Msk) ? SET : RESET);
}

/**
  * @brief  Gets the I2C interrupt state code.
  * @param  i2c: select the I2C peripheral.
  * @retval The I2C interrupt state code.
  */
uint8_t I2C_GetITStateCode(I2C_TypeDef *i2c)
{
    return (uint8_t)(i2c->STA & I2C_STA_STA_Msk);
}

/**
  * @brief  Clears the i2c interrupt flag.
  * @param  i2c: select the I2C peripheral.
  * @retval None.
  */
void I2C_ClearITPendingBit(I2C_TypeDef *i2c)
{
    i2c->CON &= ~I2C_CON_SI_Msk;
}

/**
  * @brief  Configures slave address.
  * @param  i2c: select the I2C peripheral.
  * @param  addr: specifies the 7-bit slave address which will be transmitted
  *   This parameter can be one of the following values
  * @retval None.
  */
void I2C_SlaveAddressConfig(I2C_TypeDef *i2c, uint8_t addr)
{
    MODIFY_REG(i2c->ADR, I2C_ADR_ADDR_Msk, (addr >> 1) << I2C_ADR_ADDR_Pos);
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

