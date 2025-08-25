////////////////////////////////////////////////////////////////////////////////
/// @file    i2c.h
/// @author  AE TEAM
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FIRMWARE FUNCTIONS.
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
#ifndef __I2C_H
#define __I2C_H

// Files includes

#include "hal_device.h"
#include "hal_conf.h"
#include "stdio.h"


////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Example_Layer
/// @brief MM32 Example Layer
/// @{
#define DEVICE_ADDR                     0x50
////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_RESOURCE
/// @brief MM32 Examples resource modules
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Constants
/// @{



//in eMiniBoard MB032 I2C1_SCL reused with PA5
#define I2C1_SCL_PORT                   GPIOA
#define I2C1_SCL_PIN                    GPIO_Pin_5
#define I2C1_SCL_BUSCLK                 RCC_AHBENR_GPIOA
#define I2C1_SCL_AFSOURCE               GPIO_PinSource5
#define I2C1_SCL_AFMODE                 GPIO_AF_3

//in eMiniBoard MB032 I2C1_SDA reused with LD1 and TXD2 PA4
#define I2C1_SDA_PORT                   GPIOA
#define I2C1_SDA_PIN                    GPIO_Pin_4
#define I2C1_SDA_BUSCLK                 RCC_AHBENR_GPIOA
#define I2C1_SDA_AFSOURCE               GPIO_PinSource4
#define I2C1_SDA_AFMODE                 GPIO_AF_3


/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Enumeration
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief XXXX enumerate definition.
/// @anchor XXXX
////////////////////////////////////////////////////////////////////////////////


/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Variables
/// @{
#ifdef _I2C_C_
#define GLOBAL







#else
#define GLOBAL extern






#endif



#undef GLOBAL

/// @}


////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Functions
/// @{

uint16_t I2C_Slave_GetRxAvailable(void);
uint16_t I2C_Slave_GetTxFinish(void);
void I2C_Slave_Init(uint8_t dev_addr, uint8_t *rx_buff, uint16_t rx_buff_size, uint8_t *tx_buff, uint16_t tx_buff_size);

uint16_t I2C_Master_Write(I2C_TypeDef *I2Cx, uint16_t dev_address, uint8_t *data_p, uint16_t size, uint32_t timeout);
uint16_t I2C_Master_Read(I2C_TypeDef *I2Cx, uint16_t dev_address, uint8_t *data_p, uint16_t size, uint32_t timeout);
void I2C_Master_Init(void);


/// @}


/// @}

/// @}


////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
