////////////////////////////////////////////////////////////////////////////////
/// @file    i2c.c
/// @author  AE TEAM
/// @brief    In window comparator mode,The transformation results are detected
///           Set the threshold value from 0 to 3V, and connect PB6 and PA0 with
///           jumper cap to see the effect.
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
#define _I2C_C_

// Files includes
#include "delay.h"
#include "i2c.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup I2C
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup I2C_Exported_Functions
/// @{

/**
 * Send a byte of data to the I2C bus
 *
 * @param I2Cx The I2C peripheral you're using.
 * @param data The data to be sent
 */
void I2CTXByte(I2C_TypeDef *I2Cx, uint8_t data)
{
	I2C_SendData(I2Cx, data);

	while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TX_EMPTY))
	{
	}
}

/**
 * Wait until the RX buffer is full, then read the data
 *
 * @param I2Cx The I2C peripheral you want to use.
 *
 * @return The data that was received.
 */
uint8_t I2CRXByte(I2C_TypeDef *I2Cx)
{
	uint8_t data;
    uint32_t time_out = 0xFFFFF;

	while ((!I2C_GetFlagStatus(I2Cx, I2C_FLAG_RX_FULL)) && (--time_out))
	{
	}

	data = I2C_ReceiveData(I2Cx);

	return data;
}

/**
 * I2C_Master_Write(I2Cx, dev_address, data_p, size)
 *
 * @param I2Cx I2C1
 * @param dev_address The address of the device you want to write to.
 * @param data_p pointer to the data to be written
 * @param size number of bytes to be written
 */
void I2C_Master_Write(I2C_TypeDef *I2Cx, uint16_t dev_address, uint8_t *data_p, uint16_t size)
{
	uint16_t idx;

	I2C_Cmd(I2Cx, DISABLE);
	I2C_Send7bitAddress(I2Cx, dev_address, I2C_Direction_Transmitter);
	I2C_Cmd(I2Cx, ENABLE);

	I2C_GenerateSTART(I2Cx, ENABLE);

	for (idx = 0; idx < size; idx++)
	{
		I2CTXByte(I2Cx, *data_p);
		data_p++;
	}

	I2C_GenerateSTOP(I2C1, ENABLE);

	while ((I2C_GetITStatus(I2C1, I2C_IT_STOP_DET)) == 0)
	{
	}
}

/**
 * I2C_Master_Read(I2Cx, dev_address, data_p, size)
 *
 * @param I2Cx I2C1
 * @param dev_address The address of the device you want to read.
 * @param data_p pointer to the data array to be filled
 * @param size number of bytes to be read
 */
void I2C_Master_Read(I2C_TypeDef *I2Cx, uint16_t dev_address, uint8_t *data_p, uint16_t size)
{
	uint16_t idx;

	I2C_Cmd(I2Cx, DISABLE);
	I2C_Send7bitAddress(I2Cx, dev_address, I2C_Direction_Receiver);
	I2C_Cmd(I2Cx, ENABLE);

	I2C_GenerateSTART(I2Cx, ENABLE);

	for (idx = 0; idx < size; idx++)
	{
		*data_p = I2CRXByte(I2Cx);
		data_p++;
	}

	I2C_GenerateSTOP(I2C1, ENABLE);

	while ((I2C_GetITStatus(I2C1, I2C_IT_STOP_DET)) == 0)
	{
	}
}

/**
 * I2C_Master_Init() initializes the I2C1 peripheral in master mode, with a clock speed of 100kHz
 */
void I2C_Master_Init(void)
{
	I2C_InitTypeDef I2C_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	I2C_InitStructure.I2C_Mode = I2C_Mode_MASTER;
	I2C_InitStructure.I2C_OwnAddress = 0x55;
	I2C_InitStructure.I2C_Speed = I2C_Speed_FAST;
	I2C_InitStructure.I2C_ClockSpeed = 400000;
    I2C_Init(I2C1, &I2C_InitStructure);
    
    I2C_Send7bitAddress(I2C1, DEVICE_ADDR, I2C_Direction_Receiver);
	
	I2C_Cmd(I2C1, ENABLE);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_3); //I2C1_SCL
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_3); //I2C1_SDA

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_20MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


/// @}

/// @}

/// @}
