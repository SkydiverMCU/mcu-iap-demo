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


uint8_t *rx_data_p;
uint8_t *tx_data_p;

/**
 * I2C1_IRQHandler() is called when the I2C1 peripheral is enabled and the I2C1_IRQn interrupt is
 * triggered
 */
void I2C1_IRQHandler(void)
{
	uint16_t Raw_Int_Status;

	Raw_Int_Status = I2C1->IC_RAW_INTR_STAT;

	if (Raw_Int_Status & I2C_FLAG_START_DET)
	{
		I2C_ClearITPendingBit(I2C1, I2C_IT_START_DET);

		if (((rx_status & 0x80) != 0) || ((rx_status & 0x01) == 0))
		{
			rx_idx = 0;
			rx_status = 1 << 0;
		}

		if (((tx_status & 0x80) != 0 || (tx_status & 0x01) == 0))
		{
			tx_idx = 0;
			tx_status = 1 << 0;
		}
	}

	if (Raw_Int_Status & I2C_FLAG_RX_FULL)
	{
		if (rx_idx < rx_data_size)
		{
			rx_data_p[rx_idx] = I2C1->IC_DATA_CMD;
			rx_idx++;
			rx_status |= 1 << 1;
		}
		else
		{
			I2C1->IC_DATA_CMD;
			rx_status |= 1 << 2;
		}
	}

	if (Raw_Int_Status & I2C_FLAG_RD_REQ)
	{
		I2C_ClearITPendingBit(I2C1, I2C_IT_RD_REQ);

		if (tx_idx < tx_data_size)
		{
			I2C1->IC_DATA_CMD = tx_data_p[tx_idx];
			tx_idx++;
			tx_status |= 1 << 1;
		}
		else
		{
			I2C1->IC_DATA_CMD = 0xEE;
			tx_status |= 1 << 2;
		}
	}

	if (Raw_Int_Status & I2C_FLAG_TX_ABRT)
	{
		I2C_ClearITPendingBit(I2C1, I2C_IT_TX_ABRT);
		tx_status |= 1 << 3;
	}

	if (Raw_Int_Status & I2C_FLAG_RX_DONE)
	{
		I2C_ClearITPendingBit(I2C1, I2C_IT_RX_DONE);
		tx_status |= 1 << 4;
	}

	if (Raw_Int_Status & I2C_FLAG_STOP_DET)
	{
		I2C_ClearITPendingBit(I2C1, I2C_IT_STOP_DET);

		if (rx_status & 0xFE)
		{
			rx_status |= 1 << 7;
		}

		if (tx_status & 0xFE)
		{
			tx_status |= 1 << 7;
		}
	}
}

uint16_t I2C_Slave_GetRxAvailable(void)
{
	if (rx_status & 0x80)
	{
		rx_status = 0x00;
		return rx_idx;
	}
	else
	{
		return 0;
	}
}

uint16_t I2C_Slave_GetTxFinish(void)
{
	if (tx_status & 0x80)
	{
		tx_status = 0x00;
		return tx_idx;
	}
	else
	{
		return 0;
	}
}

/**
 * I2C_Slave_Init() initializes the I2C1 peripheral in slave mode
 */
void I2C_Slave_Init(uint8_t dev_addr, uint8_t *rx_buff, uint16_t rx_buff_size, uint8_t *tx_buff, uint16_t tx_buff_size)
{
	I2C_InitTypeDef I2C_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	I2C_InitStructure.I2C_Mode = I2C_Mode_SLAVE;
	I2C_InitStructure.I2C_OwnAddress = dev_addr;
	I2C_InitStructure.I2C_Speed = I2C_Speed_STANDARD;
	I2C_InitStructure.I2C_ClockSpeed = 100000;

	I2C_Init(I2C1, &I2C_InitStructure);

	I2C_SendSlaveAddress(I2C1, dev_addr);
	I2C_Cmd(I2C1, ENABLE);

//	GPIO_PinAFConfig(I2C1_SCL_PORT, I2C1_SCL_AFSOURCE, I2C1_SCL_AFMODE);
//	GPIO_PinAFConfig(I2C1_SDA_PORT, I2C1_SDA_AFSOURCE, I2C1_SDA_AFMODE);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_3); //I2C1_SCL
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_3); //I2C1_SDA

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_20MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    

	I2C_ClearITPendingBit(I2C1, I2C_IT_TX_ABRT);
	I2C_ClearITPendingBit(I2C1, I2C_IT_RD_REQ);
	I2C_ClearITPendingBit(I2C1, I2C_IT_RX_FULL);

	I2C_ClearITPendingBit(I2C1, I2C_IT_STOP_DET);
	I2C_ClearITPendingBit(I2C1, I2C_IT_START_DET);
	// I2C_ClearITPendingBit(I2C1, I2C_IT_ACTIVITY);

	//	I2C_ClearITPendingBit(I2C1, I2C_IT_RX_UNDER);
	//	I2C_ClearITPendingBit(I2C1, I2C_IT_TX_OVER);

	// I2C_ITConfig(I2C1, I2C_IT_TX_ABRT, ENABLE);
	I2C_ITConfig(I2C1, I2C_IT_RD_REQ, ENABLE);
	I2C_ITConfig(I2C1, I2C_IT_RX_FULL, ENABLE);

	I2C_ITConfig(I2C1, I2C_IT_STOP_DET, ENABLE);
	I2C_ITConfig(I2C1, I2C_IT_START_DET, ENABLE);
	//  I2C_ITConfig(I2C1, I2C_IT_ACTIVITY, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = I2C1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	rx_data_size = rx_buff_size;
	tx_data_size = tx_buff_size;

	rx_data_p = rx_buff;
	tx_data_p = tx_buff;

	rx_status = 0x00;
	tx_status = 0x00;
}

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

	while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_RX_FULL))
	{
	}

	data = I2C_ReceiveData(I2Cx);

	return data;
}

/// @}

/// @}

/// @}
