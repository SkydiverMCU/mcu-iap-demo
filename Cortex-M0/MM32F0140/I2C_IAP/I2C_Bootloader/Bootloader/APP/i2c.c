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
#include "platform.h"
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

// uint8_t *rx_data_p;
// uint8_t *tx_data_p;

// extern uint8_t i2c_clockblock;

/**
 * I2C1_IRQHandler() is called when the I2C1 peripheral is enabled and the I2C1_IRQn interrupt is
 * triggered
 */

// uint8_t i2c_rx_block;
// void I2C1_IRQHandler(void)
//{
//	uint16_t Raw_Int_Status;
//

//	Raw_Int_Status = I2C1->IC_RAW_INTR_STAT;

//	if (Raw_Int_Status & I2C_FLAG_START_DET)
//	{
//		//I2C_ClearITPendingBit(I2C1, I2C_IT_START_DET);
//        I2C1->IC_CLR_START_DET;

//		if (((rx_status & RX_STA_STOP) != 0) || ((rx_status & RX_STA_START) == 0))
//		{
//			rx_idx = 0;
//			rx_status = RX_STA_START;
//		}

//		if (((tx_status & 0x80) != 0 || (tx_status & 0x01) == 0))
//		{
//			tx_idx = 0;
//			tx_status = 1 << 0;
//		}
//	}

//	if ((Raw_Int_Status & I2C_FLAG_RX_FULL) && (I2C1->IC_INTR_MASK & I2C_IT_RX_FULL))
//	{
//        //if(I2C1->IC_INTR_MASK & I2C_IT_RX_FULL)
//
//		{
//            if (rx_idx < I2C_MAX_RECV_LEN)
//            {
//                rx_data_p[rx_idx] = I2C1->IC_DATA_CMD;
//                rx_idx++;
//
//                //rx_status |= RX_STA_BUFF_NOFULL;
//                if(rx_idx == I2C_MAX_RECV_LEN)
//                {
//                    //I2C1->ENR &= ~I2C_ENR_ENABLE;
//                    //I2C1->CR &= ~I2C_CR_SLAVEDIS;
//
//                    rx_status |= RX_STA_BUFF_FULL;
//                }

//            }
//            else
//            {
//                //I2C_SCL_STRETCH;
//                //I2C1->IC_DATA_CMD; //jiai 不读DATA寄存器会自动产生时钟延展？
//                //I2C1->IC_INTR_MASK &= ~I2C_IT_RX_FULL;//jiai 禁止接收中断，拉低SCL
//
//
//                I2C1->ENR &= ~I2C_ENR_ENABLE;
//                I2C1->CR &= ~I2C_CR_SLAVEDIS;
//
//                //i2c_rx_block = 1;
//                rx_status |= RX_STA_BUFF_OVER;
//                //rx_status &= ~RX_STA_BUFF_NOFULL;
//            }
//        }
//	}

//	if ((Raw_Int_Status & I2C_FLAG_RD_REQ) && (I2C1->IC_INTR_MASK & I2C_FLAG_RD_REQ))
//	{
//        //if(I2C1->IC_INTR_MASK & I2C_FLAG_RD_REQ)
//        {
//            //I2C_ClearITPendingBit(I2C1, I2C_IT_RD_REQ);
//            I2C1->IC_CLR_RD_REQ;

//            if (tx_idx < tx_data_size)
//            {
//                I2C1->IC_DATA_CMD = tx_data_p[tx_idx];
//                tx_idx++;
//                tx_status |= 1 << 1;
//            }
//            else
//            {
//                I2C1->IC_DATA_CMD = 0xEE;
//                tx_status |= 1 << 2;
//            }

//        }
//	}

//	if (Raw_Int_Status & I2C_FLAG_TX_ABRT)
//	{
//		//I2C_ClearITPendingBit(I2C1, I2C_IT_TX_ABRT);
//        I2C1->IC_CLR_TX_ABRT;
//		tx_status |= 1 << 3;
//	}

//	if (Raw_Int_Status & I2C_FLAG_RX_DONE)
//	{
//		//I2C_ClearITPendingBit(I2C1, I2C_IT_RX_DONE);
//        I2C1->IC_CLR_RX_DONE;
//		tx_status |= 1 << 4;
//	}

//	if (Raw_Int_Status & I2C_FLAG_STOP_DET)
//	{
//		//I2C_ClearITPendingBit(I2C1, I2C_IT_STOP_DET);
//        I2C1->IC_CLR_STOP_DET;
//
//		if (rx_status & 0xFE)
//		{
//			rx_status |= 1 << 7;
//		}

//		if (tx_status & 0xFE)
//		{
//			tx_status |= 1 << 7;
//		}
//	}
//}

// uint16_t I2C_Slave_GetRxAvailable(void)
//{
//	if ((rx_status&RX_STA_STOP)|| (rx_status&RX_STA_BUFF_OVER))
//	{
//		//rx_status = 0x00; //jiai
//		return rx_idx;
//	}
//	else
//	{
//		return 0;
//	}
// }

// uint16_t I2C_Slave_GetTxFinish(void)
//{
//	if (tx_status & 0x80)
//	{
//		tx_status = 0x00;
//		return tx_idx;
//	}
//	else
//	{
//		return 0;
//	}
// }

void I2C_GPIO_Config(void)
{
    //    GPIO_InitTypeDef GPIO_InitStructure;
    //
    //    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);
    //
    //    GPIO_PinAFConfig(I2C1_SCL_PORT, I2C1_SCL_AFSOURCE, I2C1_SCL_AFMODE); //I2C1_SCL
    //	GPIO_PinAFConfig(I2C1_SDA_PORT, I2C1_SDA_AFSOURCE, I2C1_SDA_AFMODE); //I2C1_SDA

    //	GPIO_InitStructure.GPIO_Pin = I2C1_SCL_PIN;
    //	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_20MHz;
    //	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    //	GPIO_Init(I2C1_SCL_PORT, &GPIO_InitStructure);
    //
    //    GPIO_InitStructure.GPIO_Pin = I2C1_SDA_PIN;
    //	GPIO_Init(I2C1_SDA_PORT, &GPIO_InitStructure);

    RCC->AHBENR |= RCC_AHBENR_GPIOA;

    GPIOA->AFRL &= 0xFF00FFFF;
    GPIOA->AFRL |= 0x00550000;

    GPIOA->CRL &= 0xFFFFFF0F; // 复用开漏输出
    GPIOA->CRL |= 0x00DD0000;
}

/**
 * I2C_Slave_Init() initializes the I2C1 peripheral in slave mode
 */
// void I2C_Slave_Init(uint8_t dev_addr, uint8_t *rx_buff, uint16_t rx_buff_size, uint8_t *tx_buff, uint16_t tx_buff_size)
void I2C_Slave_Init(uint8_t dev_addr, uint32_t i2c_speed)
{
#if 0
	I2C_InitTypeDef I2C_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
    
    u32 i2c_speed     = 100000;

	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_I2C1, ENABLE);

	I2C_InitStructure.I2C_Mode = I2C_Mode_SLAVE;
	I2C_InitStructure.I2C_OwnAddress = dev_addr;	
	I2C_InitStructure.I2C_ClockSpeed = i2c_speed;    
    if(i2c_speed<=100000)
        I2C_InitStructure.I2C_Speed = I2C_Speed_STANDARD;
    else
        I2C_InitStructure.I2C_Speed = I2C_Speed_FAST;

	I2C_Init(I2C1, &I2C_InitStructure);

	I2C_SendSlaveAddress(I2C1, dev_addr);
	I2C_Cmd(I2C1, ENABLE);


    GPIO_PinAFConfig(I2C1_SCL_PORT, I2C1_SCL_AFSOURCE, I2C1_SCL_AFMODE); //I2C1_SCL
	GPIO_PinAFConfig(I2C1_SDA_PORT, I2C1_SDA_AFSOURCE, I2C1_SDA_AFMODE); //I2C1_SDA

	GPIO_InitStructure.GPIO_Pin = I2C1_SCL_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_20MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_Init(I2C1_SCL_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = I2C1_SDA_PIN;
	GPIO_Init(I2C1_SDA_PORT, &GPIO_InitStructure);
   

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
#else

    //    I2C_InitTypeDef I2C_InitStruct;

    I2C_GPIO_Config();

    //    I2C_StructInit(&I2C_InitStruct);

    //	RCC_APB1PeriphClockCmd(RCC_APB1ENR_I2C1, ENABLE);
    RCC->APB1ENR |= RCC_APB1ENR_I2C1;
    //    I2C_DeInit(I2C1);
    //    I2C_InitStruct. Mode = (I2C_CR_MASTER >> 1); //Slave mode
    //    I2C_InitStruct. OwnAddress = 0;
    //    I2C_InitStruct. Speed = I2C_CR_FAST;
    //    I2C_InitStruct. ClockSpeed = 400000;
    //    I2C_Init(I2C1, &I2C_InitStruct);
    // I2C1->CR = 0x9A4;
    I2C1->CR = I2C_CR_SLV_TX_DIS | I2C_CR_EMPINT | I2C_CR_STOPINT | I2C_CR_REPEN | I2C_CR_FAST;
    // I2C_SendSlaveAddress(I2C1, dev_addr);
    I2C1->IC_SAR = (dev_addr >> 1);

    // I2C_Cmd(I2C1, ENABLE);
    I2C1->IC_ENABLE |= I2C_ENR_ENABLE;

#endif

    //	rx_data_size = rx_buff_size;
    //	tx_data_size = tx_buff_size;

    //	rx_data_p = rx_buff;
    //	tx_data_p = tx_buff;

    //	rx_status = 0x00;
    //	tx_status = 0x00;
}

/**
 * Send a byte of data to the I2C bus
 *
 * @param I2Cx The I2C peripheral you're using.
 * @param data The data to be sent
 */
// void I2CTXByte(I2C_TypeDef *I2Cx, uint8_t data)
//{
//	I2C_SendData(I2Cx, data);

//	while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_TX_EMPTY))
//	{
//	}
//}

/**
 * Wait until the RX buffer is full, then read the data
 *
 * @param I2Cx The I2C peripheral you want to use.
 *
 * @return The data that was received.
 */
// uint8_t I2CRXByte(I2C_TypeDef *I2Cx)
//{
//	uint8_t data;
//

//	while (!I2C_GetFlagStatus(I2Cx, I2C_FLAG_RX_FULL))
//	{
//	}

//	data = I2C_ReceiveData(I2Cx);

//	return data;
//}

I2C_Status_t I2C_Slave_Transfer(I2C_TypeDef *i2c_device,
                                uint8_t *transmit_buff, uint32_t transmit_len,
                                uint8_t *receive_buff, uint32_t receive_len,
                                uint32_t *actual_transmitted_p,
                                uint32_t *actual_received_p,
                                uint32_t timeout)
{
    I2C_Status_t status = I2C_STATUS_SUCCESS;
    uint32_t flags;

    *actual_transmitted_p = 0;
    *actual_received_p = 0;

    I2C_ClearFlag(i2c_device, I2C_IT_START_DET);
    I2C_ClearFlag(i2c_device, I2C_IT_STOP_DET);

    while (!I2C_GetFlagStatus(i2c_device, I2C_ISR_RX_REQ) && !I2C_GetFlagStatus(i2c_device, I2C_ISR_RX_FULL) && timeout)
    {
        if ((timeout != TIMEOUT_INFINITY) && (timeout > 0))
        {
            timeout--;
        }
    }

    while (timeout > 0)
    {
        flags = i2c_device->IC_RAW_INTR_STAT;

        // if(I2C_GetFlagStatus(i2c_device, I2C_STATUS_FLAG_RFNE))
        // if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_RX_FULL))
        if (flags & I2C_ISR_RX_FULL)
        {
            if (receive_len > 0)
            {
                *receive_buff = I2C_ReceiveData(i2c_device);
                // printf("I: %02X\n", *receive_buff);

                receive_buff++;
                receive_len--;
                *actual_received_p += 1;
            }
            else
            {
                status = I2C_STATUS_ERR_RX_PENDING;
            }

            // if(receive_len == 0)
            if ((receive_len == 0) && (transmit_len == 0))
            {
                // printf("Out from REC!\n");
                break;
            }
        }

        // else if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_TX_ABRT))
        else if (flags & I2C_ISR_TX_ABRT)
        {
            I2C_ClearFlag(i2c_device, I2C_ISR_TX_ABRT);
        }

        // else if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_RX_REQ))
        else if (flags & I2C_ISR_RX_REQ)
        {
            // if(I2C_GetFlagStatus(i2c_device, I2C_STATUS_FLAG_TFE))
            // if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_TX_EMPTY))
            if (flags & I2C_ISR_TX_EMPTY)
            {
                if (transmit_len > 0)
                {
                    I2C_ClearFlag(i2c_device, I2C_ISR_RX_REQ);
                    I2C_SendData(i2c_device, *transmit_buff);

                    // printf("O: %02X\n", *transmit_buff);
                    transmit_buff++;
                    transmit_len--;
                    *actual_transmitted_p += 1;
                }
                else
                {
                    status = I2C_STATUS_ERR_TX_PENDING;
                }

                // if(transmit_len == 0)
                if ((receive_len == 0) && (transmit_len == 0))
                {
                    while (!I2C_GetFlagStatus(i2c_device, I2C_ISR_TX_EMPTY))
                    {
                    }
                    // printf("Out from TRANS!\n");
                    break;
                }
            }
        }

        //        //else if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_TX_ABRT))
        //        else if(flags & I2C_ISR_TX_ABRT)
        //        {
        //            I2C_ClearFlag(i2c_device, I2C_ISR_TX_ABRT);
        //        }

        // else if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_START_DET))
        else if (flags & I2C_ISR_START)
        {
            I2C_ClearFlag(i2c_device, I2C_ISR_START);
            // break;
        }

        // else if(I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_STOP_DET))
        else if (flags & I2C_ISR_STOP)
        {
            // if(!I2C_GetFlagStatus(i2c_device, I2C_STATUS_FLAG_RFNE) && I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_TX_EMPTY))
            // if((!I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_RX_FULL)) && I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_TX_EMPTY))
            // if((!(flags & I2C_INTR_STAT_RX_FULL)) && (flags & I2C_INTR_STAT_TX_EMPTY))
            {
                I2C_ClearFlag(i2c_device, I2C_ISR_STOP);
                // printf("Out from STOP!\n");
                // break;
                status = I2C_STATUS_SUCCESS;

                break;
            }
        }

        // if(receive_len == 0)
        // {
        //     break;
        // }

        // if(transmit_len == 0)
        // {
        //     while(!I2C_GetFlagStatus(i2c_device, I2C_INTR_STAT_TX_EMPTY))
        //     {

        //     }

        //     break;
        // }

        if ((timeout != TIMEOUT_INFINITY) && (timeout > 0))
        {
            timeout--;
        }
    }
    //    while (timeout > 0);

    if (timeout == 0)
    {
        status = I2C_STATUS_ERR_TIMEOUT;
    }

    return status;
}

/// @}

/// @}

/// @}
